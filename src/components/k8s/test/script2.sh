#!/bin/bash
# ATTENTION: Before launching this script, have a look at the lines after the
# other 'ATTENTION' comments and perform the correct substitions.
function cleanup {
    set +e
    polycubectl del br1ns
    polycubectl del r1
    polycubectl del nat1
    for i in `seq 1 2`; do
    sudo ip link del veth${i}root
    sudo ip netns del ns${i}
    sudo ip link del pc_veth_pc
    done
}
trap cleanup EXIT
set -x
set -e
# Create 2 namespaces and the related veth
for i in `seq 1 2`; do
    # Create new namespace
    sudo ip netns add ns${i}
    # Add new veth interface
    sudo ip link add veth${i}root type veth peer name veth${i}ns
    sudo ip link set veth${i}ns netns ns${i}
    # Enable veth on both root and newly created namespace
    sudo ip netns exec ns${i} ip link set dev veth${i}ns up
    sudo ip link set dev veth${i}root up
    # Set IP address to the namespace's end of the virtual interface
    sudo ip netns exec ns${i} ip addr add 10.10.7.${i}/24 dev veth${i}ns
    sudo ip netns exec ns${i} ip route add default via 10.10.7.254 dev veth${i}ns
    echo "Created ns${i} and veth${i} with IP 10.10.7.${i}/24"
done
# Create simple bridge br1ns
polycubectl simplebridge add br1ns
# Create and connect port 1
polycubectl br1ns ports add toveth1
polycubectl connect br1ns:toveth1 veth1root
# Create and connect port 2
polycubectl br1ns ports add toveth2
polycubectl connect br1ns:toveth2 veth2root
# Create and connect bridge port to router
polycubectl br1ns ports add to_router
# Create router
polycubectl router add r1 #loglevel=TRACE
# Create router port to bridge
polycubectl r1 ports add to_br1ns ip=10.10.7.254/24
# Create router port to physical interface
polycubectl r1 ports add to_internet
# Connect bridge and router (ATTENTION: you have to change 'enp1s0' with
# the right physical interface name)
polycubectl connect r1:to_br1ns br1ns:to_router
polycubectl connect r1:to_internet wlp1s0
# Add route to Internet (ATTENTION: you have to change '192.168.1.1' with
# the current default gateway)
# (You can look for the default gateway by using 'ip route' and searching
# for the 'default' route)
polycubectl r1 route add 0.0.0.0/0 192.168.43.1
# Create NAT
polycubectl nat add nat1 #loglevel=TRACE
polycubectl attach nat1 r1:to_internet
polycubectl nat1 rule masquerade enable
# (EXTRA) To connect PC to Internet too, as of December 2019:
# Create new veth to connect root namespace to br1ns
sudo ip link add pc_veth_pc type veth peer name pc_veth_r1
# Add port to br1ns
polycubectl br1ns ports add to_pc
# Enable both virtual interfaces
sudo ip link set pc_veth_pc up
sudo ip link set pc_veth_r1 up
# Connect pc_veth_r1 (Polycube end of the newly created veth)
polycubectl connect br1ns:to_pc pc_veth_r1
# Give an IP address to the root namespace veth in the same subnet of ns1 and ns2
sudo ip addr add 10.10.7.100/24 dev pc_veth_pc
# Add r1 as default gateway
sudo ip route add default via 10.10.7.254
read -p "Press ENTER to delete current configuration..."