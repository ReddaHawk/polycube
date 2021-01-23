#!/bin/bash
#polycubectl k8sfilter add k8sfilter loglevel=TRACE
#polycubectl k8sfilter k1 ports add port_public type=PUBLIC
#sudo ip netns add ns1
#sudo ip link add veth1root type veth peer name veth1ns
function cleanup() {
  set +e
  polycubectl del br0
  polycubectl del r1

  for i in $(seq 1 2); do
    sudo ip link del veth${i}root
    sudo ip netns del ns${i}
  done

  #sudo ip route del 10.10.7.0/24 via 10.10.8.254
  #sudo ip route del 10.11.11.0/24 via 10.10.8.254
  #sudo ip link del veth_srv_root
}
trap cleanup EXIT
set -x
set -e
# Create 2 namespaces as clients (root namespace will run the server)
for i in $(seq 1 2); do
  # Create new namespace
  sudo ip netns add ns${i}
  # Add new veth interface with one end called veth1root and other veth1ns
  sudo ip link add veth${i}root type veth peer name veth${i}ns
  #Assign the “veth1ns” virtual interface to the “ns1” network namespace. The other end of the
  #“wire” will be assigned to the root namespace:
  sudo ip link set veth${i}ns netns ns${i}
  # Enable veth on both root and newly created namespace
  sudo ip netns exec ns${i} ip link set dev veth${i}ns up
  sudo ip link set dev veth${i}root up
  # Set IP address to the namespace's end of the virtual interface
  sudo ip netns exec ns${i} ip addr add 10.10.7.${i}/24 dev veth${i}ns
  sudo ip netns exec ns${i} ip route add default via 10.10.7.254 dev veth${i}ns
  echo "Created ns${i} and veth${i} with IP 10.10.7.${i}/24"
done
# Create an additional veth between router and root namespace
#sudo ip link add veth_srv_root type veth peer name veth_srv_router
#sudo ip link set dev veth_srv_root up
#sudo ip link set dev veth_srv_router up
#sudo ip addr add 10.10.8.1/24 dev veth_srv_root
#sudo ip route add 10.10.7.0/24 via 10.10.8.254
#sudo ip route add 10.11.11.0/24 via 10.10.8.254
# -------------------------------------------------------
# Simple bridge br0
polycubectl simplebridge add br0 loglevel=TRACE #type=XDP_SKB
# Create and connect port to client 1
polycubectl br0 ports add to_client1
polycubectl connect br0:to_client1 veth1root
# Create and connect port to client 2
polycubectl br0 ports add to_client2
polycubectl connect br0:to_client2 veth2root
# Create port to LB NodePort
polycubectl br0 ports add to_lbnodeport
# -------------------------------------------------------
# Create lbrp
polycubectl lbrp add lb1 loglevel=TRACE
polycubectl lbrp lb1 ports add port1 type=FRONTEND
polycubectl lbrp lb1 ports add port2 type=BACKEND

# -------------------------------------------------------
# Create router

polycubectl router add r1 loglevel=TRACE #type=XDP_SKB
# Create router ports to lb nodec and something else
polycubectl r1 ports add to_br0 ip=10.10.7.254/24
polycubectl r1 ports add to_internet ip=10.10.8.254/24
# Connect router to lb
polycubectl connect r1:to_br0 lb1:port2
polycubectl connect lb1:port1 br0:to_lbnodeport
# Connect router to server in the root namespace
#polycubectl connect r1:to_br0 br0:to_lbnodeport
polycubectl connect r1:to_internet wlp1s0
polycubectl r1 route add 0.0.0.0/0 192.168.1.1

# -------------------------------------------------------
#create NAT
polycubectl nat add nat1 loglevel=TRACE #type=XDP_SKB
polycubectl attach nat1 r1:to_internet
polycubectl nat1 rule masquerade enable
read -p "Press ENTER to delete current configuration..."

#connect ports
