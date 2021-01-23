#!/bin/bash
function cleanup {
set +e
polycubectl del br1ns
polycubectl del r1
polycubectl del nat1
# Deleting 3 namespaces (10.10.7.1, 10.10.7.2 and 10.20.30.40 for the remote lab)
for i in `seq 1 3`; do
    sudo ip link del veth${i}root
    sudo ip netns del ns${i}
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
# (Remote lab only additional operation) Create a third namespace with IP 10.20.30.40
sudo ip netns add ns3
sudo ip link add veth3root type veth peer name veth3ns
sudo ip link set veth3ns netns ns3
sudo ip netns exec ns3 ip link set dev veth3ns up
sudo ip link set dev veth3root up
sudo ip netns exec ns3 ip addr add 10.20.30.40/24 dev veth3ns
sudo ip netns exec ns3 ip route add default via 10.20.30.2 dev veth3ns
echo "Created ns3 and veth3 with IP 10.20.30.40/24 and DG 10.20.30.2"
# Simple bridge br1ns
polycubectl simplebridge add br1ns
# Create and connect port 1
polycubectl br1ns ports add toveth1
polycubectl connect br1ns:toveth1 veth1root
# Create and connect port 2
polycubectl br1ns ports add toveth2
polycubectl connect br1ns:toveth2 veth2root
# Create and connect port to router
polycubectl br1ns ports add to_router
# Create router
polycubectl router add r1 loglevel=TRACE
# Create router port to bridge
polycubectl r1 ports add to_br1ns ip=10.10.7.254/24
# (Remote lab only) Create router port to the third namespace
polycubectl r1 ports add to_internet ip=10.20.30.2/24
# Connect bridge and router and router to third namespace
polycubectl connect r1:to_br1ns br1ns:to_router
polycubectl connect r1:to_internet veth3root
# Add route to Internet (in the remote lab this is not needed, as we are accessing a
# third namespace instead of the Internet)
# polycubectl r1 route add 0.0.0.0/0 10.20.30.2
# Create NAT
polycubectl nat add nat1 loglevel=TRACE
polycubectl attach nat1 r1:to_internet
polycubectl nat1 rule masquerade enable
read -p "Press ENTER to delete current configuration..."