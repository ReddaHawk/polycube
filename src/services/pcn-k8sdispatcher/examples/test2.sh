#!/bin/bash
# ATTENTION: Before launching this script, have a look at the lines after the
# other 'ATTENTION' comments and perform the correct substitions.
function cleanup {
    set +e
    polycubectl del br1ns
    polycubectl del r1
    polycubectl del k1
    for i in `seq 1 2`; do
    sudo ip link del veth${i}root
    sudo ip netns del ns${i}
    #sudo ip link del pc_veth_pc
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
polycubectl lbrp add lb2 loglevel=TRACE
polycubectl lbrp lb2 ports add port1 type=FRONTEND
polycubectl lbrp lb2 ports add port2 type=BACKEND
polycubectl lbrp add lb3 loglevel=TRACE
polycubectl lbrp lb3 ports add port1 type=FRONTEND
polycubectl lbrp lb3 ports add port2 type=BACKEND
# Create and connect port 1
polycubectl br1ns ports add toveth1
polycubectl connect lb2:port1 veth1root
polycubectl connect lb2:port2 br1ns:toveth1
# Create and connect port 2
polycubectl br1ns ports add toveth2
polycubectl connect lb3:port1 veth2root
polycubectl connect lb3:port2 br1ns:toveth2
# Create and connect bridge port to router
polycubectl br1ns ports add to_router
# Create router
polycubectl router add r1 #loglevel=TRACE
# Create router port to bridge
polycubectl r1 ports add to_br1ns ip=10.10.7.254/24
# Create router port to physical interface
polycubectl r1 ports add to_internet mac=a0:8c:fd:ce:cb:01 ip=192.168.0.92/23
# Connect bridge and router (ATTENTION: you have to change 'enp1s0' with
# the right physical interface name)
polycubectl connect r1:to_br1ns br1ns:to_router
#polycubectl connect r1:to_internet wlp1s0
# Add route to Internet (ATTENTION: you have to change '192.168.1.1' with
# the current default gateway)
# (You can look for the default gateway by using 'ip route' and searching
# for the 'default' route)
polycubectl lbrp add lb1 loglevel=TRACE
polycubectl lbrp lb1 ports add port1 type=FRONTEND
polycubectl lbrp lb1 ports add port2 type=BACKEND

# Create NAT
polycubectl k8sdispatcher k1 internal-src-ip=3.3.3.1 #loglevel=TRACE
polycubectl k1 ports add to_int type=FRONTEND
polycubectl k1 ports add to_router type=BACKEND
# (EXTRA) To connect PC to Internet too, as of December 2019:
# Create new veth to connect root namespace to br1ns
polycubectl connect r1:to_internet lb1:port2
polycubectl connect lb1:port1 k1:to_router
polycubectl connect k1:to_int eno1
polycubectl r1 route add 0.0.0.0/0 192.168.0.254
#polycubectl r1 address address=192.168.0.254 mac=00:62:ec:7d:72:71 interface=to_internet
polycubectl r1 arp-table add 192.168.0.254 mac=00:62:ec:7d:72:71 interface=to_internet

polycubectl lbrp lb1 service add 192.168.0.92 30000 ALL name=servicego

polycubectl lbrp lb1 service 192.168.0.92 30000 TCP backend add 10.10.7.1 port=30000 name=B1 weight=10
#sudo ip link add pc_veth_pc type veth peer name pc_veth_r1
# Add port to br1ns
#polycubectl br1ns ports add to_pc
# Enable both virtual interfaces
#sudo ip link set pc_veth_pc up
#sudo ip link set pc_veth_r1 up
# Connect pc_veth_r1 (Polycube end of the newly created veth)
#polycubectl connect br1ns:to_pc pc_veth_r1
# Give an IP address to the root namespace veth in the same subnet of ns1 and ns2
#sudo ip addr add 10.10.7.100/24 dev pc_veth_pc
# Add r1 as default gateway
#sudo ip route add default via 10.10.7.254
read -p "Press ENTER to delete current configuration..."
