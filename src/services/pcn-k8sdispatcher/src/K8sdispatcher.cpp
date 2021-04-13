/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


// TODO: Modify these methods with your own implementation


#include "K8sdispatcher.h"
#include "K8sdispatcher_dp.h"
using namespace std;
K8sdispatcher::K8sdispatcher(const std::string name, const K8sdispatcherJsonObject &conf)
  : Cube(conf.getBase(), {}, {}),
    K8sdispatcherBase(name) {
  logger()->info("Creating K8sdispatcher instance");
  // call do... functions to avoid reloading code so many times
  doSetClusterIpSubnet(conf.getClusterIpSubnet());
  doSetClientSubnet(conf.getClientSubnet());
  doSetVirtualClientSubnet(conf.getVirtualClientSubnet());
  doSetNodeportRange(conf.getNodeportRange());
  if (conf.clusterIpSubnetIsSet()) {
    doSetClusterIpSubnet(conf.getClusterIpSubnet());
  }

  if (conf.clientSubnetIsSet()) {
    doSetClientSubnet(conf.getClientSubnet());
  }

  if (conf.virtualClientSubnetIsSet()) {
    doSetVirtualClientSubnet(conf.getVirtualClientSubnet());
  }
  if (conf.nodeportRangeIsSet())
  {
    doSetNodeportRange(conf.getNodeportRange());
  }

  //addNattingRuleList(conf.getNattingRule());
  addNodeportRuleList(conf.getNodeportRule());
  //setNodeportRange(conf.getNodeportRange());


  addPortsList(conf.getPorts());

  add_program(getFlags() + k8sdispatcher_code, 0);

}

K8sdispatcherJsonObject K8sdispatcher::toJsonObject() {
  K8sdispatcherJsonObject conf;
  conf.setBase(Cube::to_json());

  for (auto &i : getNattingRuleList()) {
    conf.addNattingRule(i->toJsonObject());
  }

  for (auto &i : getPortsList()) {
    conf.addPorts(i->toJsonObject());
  }

  conf.setClusterIpSubnet(getClusterIpSubnet());
  conf.setClientSubnet(getClientSubnet());
  conf.setVirtualClientSubnet(getVirtualClientSubnet());
  conf.setNodeportRange(getNodeportRange());

  //  Remove comments when you implement all sub-methods
  // for(auto &i : getFwdTableList()){
  //  conf.addFwdTable(i->toJsonObject());
  //}
  return conf;
}

void K8sdispatcher::reloadConfig() {
  std::string flags;

  // ports
  uint16_t frontend = 0;
  uint16_t backend = 0;
  for (auto &it : get_ports()) {
    switch (it->getType()) {
    case PortsTypeEnum::FRONTEND:
      frontend = it->index();
      break;
    case PortsTypeEnum::BACKEND:
      backend = it->index();
      break;
    }
  }
  flags += "#define FRONTEND_PORT " + std::to_string(frontend) + "\n";
  flags += "#define BACKEND_PORT " + std::to_string(backend) + "\n";
  flags += "#define NODEPORT_RANGE_LOW " + std::to_string(nodeport_range_low_) +
           "\n";
  flags += "#define NODEPORT_RANGE_HIGH " +
           std::to_string(nodeport_range_high_) + "\n";
  flags += "#define CLUSTER_IP_SUBNET " +
           std::to_string(htonl(cluster_ip_subnet_)) + "\n";
  flags += "#define CLUSTER_IP_MASK " +
           std::to_string(htonl(cluster_ip_mask_)) + "\n";
  flags += "#define CLIENT_SUBNET_MASK " + std::to_string(htonl(client_mask_)) +
           "\n";
  flags +=
      "#define CLIENT_SUBNET " + std::to_string(htonl(client_subnet_)) + "\n";
  flags += "#define VIRTUAL_CLIENT_SUBNET " +
           std::to_string(htonl(virtual_client_subnet_)) + "\n";
  flags += "#define EXTERNAL_IP " +
           std::to_string(htonl(external_ip_))+ "\n";
  flags += "#define EXTERNAL_MAC " +
           std::to_string(external_mac_)+ "\n";

  logger()->debug("flags is {}", flags);
  logger()->debug("Reloading code with flags port: {}", flags);

  reload(flags + k8sdispatcher_code);

  logger()->trace("New K8sNat code loaded");
}

void K8sdispatcher::update(const K8sdispatcherJsonObject &conf) {
  Cube::set_conf(conf.getBase());

  if(conf.clientSubnetIsSet()){
    auto clientSubnet = conf.getClientSubnet();
    setClientSubnet(clientSubnet);
  }

  if(conf.virtualClientSubnetIsSet()){
    auto virtualClientSubnet = conf.getVirtualClientSubnet();
    setVirtualClientSubnet(virtualClientSubnet);
  }

  if(conf.clusterIpSubnetIsSet()){
    auto clusterIpSubnet = conf.getClusterIpSubnet();
    setClusterIpSubnet(clusterIpSubnet);
  }

  if(conf.nodeportRangeIsSet()){
    auto nodeport = conf.getNodeportRange();
    setNodeportRange(nodeport);
  }

  if (conf.portsIsSet()) {
    for (auto &i : conf.getPorts()) {
      auto name = i.getName();
      auto m = getPorts(name);
      m->update(i);
    }
  }
}

K8sdispatcher::~K8sdispatcher() {
  logger()->info("Destroying K8sdispatcher instance");
}

void K8sdispatcher::doSetExternalIp(const std::string &value){
  uint32_t external_ip_subnet;
  external_ip_string_ = value;
  parse_cidr(value, &external_ip_, &external_ip_subnet);
  reloadConfig();
}

void K8sdispatcher::doSetExternalMac(const std::string &value){
  external_mac_string_=value;
  external_mac_ = mac_string_to_nbo_uint(value);
  reloadConfig();
}
void K8sdispatcher::doSetClusterIpSubnet(const std::string &value) {
  parse_cidr(value, &cluster_ip_subnet_, &cluster_ip_mask_);
  cluster_ip_cidr_ = value;
}

void K8sdispatcher::doSetClientSubnet(const std::string &value) {
  parse_cidr(value, &client_subnet_, &client_mask_);
  client_cidr_ = value;
}

void K8sdispatcher::doSetVirtualClientSubnet(const std::string &value) {
  parse_cidr(value, &virtual_client_subnet_, &virtual_client_mask_);
  virtual_client_cidr_ = value;
}

void K8sdispatcher::doSetNodeportRange(const std::string &value) {
  uint16_t low;
  uint16_t high;
  int ret = std::sscanf(value.c_str(), "%" SCNu16 "-%" SCNu16, &low, &high);
  if (ret != 2) {
    logger()->error("value {} is not valid for node port range", value);
    throw std::runtime_error("Invalid node port range");
  }

  if (low >= high) {
    throw std::runtime_error("Invalid node port range");
  }

  nodeport_range_low_ = low;
  nodeport_range_high_ = high;

  nodeport_range_ = value;
}

void K8sdispatcher::parse_cidr(const std::string &cidr, uint32_t *subnet,
                               uint32_t *netmask) {
  std::string net_str = cidr.substr(0, cidr.find("/"));
  std::string mask_len = cidr.substr(cidr.find("/") + 1, std::string::npos);

  *subnet = ip_to_dec(net_str);
  *netmask = 0xFFFFFFFF;
  *netmask <<= 32 - std::stoi(mask_len);
}

uint32_t K8sdispatcher::ip_to_dec(const std::string &ip) {
  // TODO: use uint8_t
  unsigned short a, b, c, d;

  std::sscanf(ip.c_str(), "%hu.%hu.%hu.%hu", &a, &b, &c, &d);
  return (a << 24) + (b << 16) + (c << 8) + d;
}

void K8sdispatcher::packet_in(Ports &port,
    polycube::service::PacketInMetadata &md,
    const std::vector<uint8_t> &packet) {
  logger()->debug("Packet received from port {0}", port.name());
}

std::string K8sdispatcher::getFlags() {
  std::string flags;
  // ports
  uint16_t frontend = -1;
  uint16_t backend = -1;
  for (auto &it : get_ports()) {
    logger()->info("Dentro for");
    switch (it->getType()) {
    case PortsTypeEnum::FRONTEND:
      frontend = it->index();
      break;
    case PortsTypeEnum::BACKEND:
      backend = it->index();
      break;
    }
  }

  flags += "#define FRONTEND_PORT " + std::to_string(frontend) + "\n";
  flags += "#define BACKEND_PORT " + std::to_string(backend) + "\n";
  flags += "#define NODEPORT_RANGE_LOW " + std::to_string(nodeport_range_low_) +
           "\n";
  flags += "#define NODEPORT_RANGE_HIGH " +
           std::to_string(nodeport_range_high_) + "\n";
  flags += "#define CLUSTER_IP_SUBNET " +
           std::to_string(htonl(cluster_ip_subnet_)) + "\n";
  flags += "#define CLUSTER_IP_MASK " +
           std::to_string(htonl(cluster_ip_mask_)) + "\n";
  flags += "#define CLIENT_SUBNET_MASK " + std::to_string(htonl(client_mask_)) +
           "\n";
  flags +=
      "#define CLIENT_SUBNET " + std::to_string(htonl(client_subnet_)) + "\n";
  flags += "#define VIRTUAL_CLIENT_SUBNET " +
           std::to_string(htonl(virtual_client_subnet_)) + "\n";
  flags += "#define EXTERNAL_IP " +
           std::to_string(htonl(external_ip_))+ "\n";
  flags += "#define EXTERNAL_MAC " +
           std::to_string(htonl(external_mac_))+ "\n";

  return flags;
}


// Basic default implementation, place your extension here (if needed)
std::shared_ptr<Ports> K8sdispatcher::getPorts(const std::string &name) {
  // call default implementation in base class
  return K8sdispatcherBase::getPorts(name);
}

// Basic default implementation, place your extension here (if needed)
std::vector<std::shared_ptr<Ports>> K8sdispatcher::getPortsList() {
  // call default implementation in base class
  return K8sdispatcherBase::getPortsList();
}

// Basic default implementation, place your extension here (if needed)
void K8sdispatcher::addPorts(const std::string &name, const PortsJsonObject &conf) {
  logger()->info("add ports");
  if (get_ports().size() == 2) {
    logger()->warn("Reached maximum number of ports");
    throw std::runtime_error("Reached maximum number of ports");
  }

  try {
    switch (conf.getType()) {
    case PortsTypeEnum::FRONTEND:
      if (getFrontendPort() != nullptr) {
        logger()->warn("There is already a FRONTEND port");
        throw std::runtime_error("There is already a FRONTEND port");
      }
      break;
    case PortsTypeEnum::BACKEND:
      if (getBackendPort() != nullptr) {
        logger()->warn("There is already a BACKEND port");
        throw std::runtime_error("There is already a BACKEND port");
      }
      break;

    }
  } catch (std::runtime_error &e) {
    logger()->warn("Error when adding the port {0}", name);
    logger()->warn("Error message: {0}", e.what());
    throw;
  }
  add_port<PortsJsonObject>(name, conf);
  if (get_ports().size() ==2) {
    logger()->info("Reloading code because of the new port");
    reloadConfig();
  }

  logger()->info("New port created with name {0}", name);
}

// Basic default implementation, place your extension here (if needed)
void K8sdispatcher::addPortsList(const std::vector<PortsJsonObject> &conf) {
  for (auto &i : conf) {
    std::string name_ = i.getName();
    addPorts(name_, i);
  }
}

// Basic default implementation, place your extension here (if needed)
void K8sdispatcher::replacePorts(const std::string &name, const PortsJsonObject &conf) {
  delPorts(name);
  std::string name_ = conf.getName();
  addPorts(name_, conf);
}

// Basic default implementation, place your extension here (if needed)
void K8sdispatcher::delPorts(const std::string &name) {
  // call default implementation in base class
  K8sdispatcherBase::delPorts(name);
}

// Basic default implementation, place your extension here (if needed)
void K8sdispatcher::delPortsList() {
  // call default implementation in base class
  K8sdispatcherBase::delPortsList();
}

std::string K8sdispatcher::getClusterIpSubnet() {
  return cluster_ip_cidr_;
}

void K8sdispatcher::setClusterIpSubnet(const std::string &value) {
  doSetClusterIpSubnet(value);
  reloadConfig();
}

std::string K8sdispatcher::getClientSubnet() {
  return client_cidr_;
}

void K8sdispatcher::setClientSubnet(const std::string &value) {
  doSetClientSubnet(value);
  reloadConfig();
}

std::string K8sdispatcher::getVirtualClientSubnet() {
  return virtual_client_cidr_;
}

void K8sdispatcher::setVirtualClientSubnet(const std::string &value) {
  doSetVirtualClientSubnet(value);
  reloadConfig();
}

uint8_t K8sdispatcher::proto_from_string_to_int(const std::string &proto) {
  if (proto == "icmp" || proto == "ICMP") {
    return IPPROTO_ICMP;
  }
  if (proto == "tcp" || proto == "TCP") {
    return IPPROTO_TCP;
  }
  if (proto == "udp" || proto == "UDP") {
    return IPPROTO_UDP;
  }
  return -1;
}

uint64_t K8sdispatcher::mac_string_to_nbo_uint(const std::string &mac) {
  uint8_t a[6];
  int last = -1;
  int rc = sscanf(mac.c_str(), "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx%n", a + 0, a + 1,
                  a + 2, a + 3, a + 4, a + 5, &last);
  if (rc != 6 || mac.size() != last) {
    throw std::runtime_error("invalid mac address format " + mac);
  }
  return uint64_t(a[5]) << 40 | uint64_t(a[4]) << 32 | uint64_t(a[3]) << 24 |
         uint64_t(a[2]) << 16 | uint64_t(a[1]) << 8 | uint64_t(a[0]);
}

std::shared_ptr<NattingRule> K8sdispatcher::getNattingRule(const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto) {
  try {
    auto table = get_hash_table<st_k, st_v>("egress_session_table");
    st_k map_key{
        .src_ip = polycube::service::utils::ip_string_to_nbo_uint(internalSrc),
        .dst_ip = polycube::service::utils::ip_string_to_nbo_uint(internalDst),
        .src_port = htons(internalSport),
        .dst_port = htons(internalDport),
        .proto = uint8_t(std::stol(proto)),
    };

    st_v value = table.get(map_key);

    std::string newIp = polycube::service::utils::nbo_uint_to_ip_string(value.new_ip);
    uint16_t newPort = value.new_port;
    uint8_t originatingRule = value.originating_rule_type;
    ;
    auto entry = std::make_shared<NattingRule>(
        *this, internalSrc, internalDst, internalSport, internalDport,
        proto_from_string_to_int(proto), newIp, newPort);
    return entry;
  } catch (std::exception &e) {
    throw std::runtime_error("Natting table entry not found");
  }
}

std::vector<std::shared_ptr<NattingRule>> K8sdispatcher::getNattingRuleList() {
  logger()->debug("getNattingTable");
  std::vector<std::shared_ptr<NattingRule>> entries;
  try {
    auto table = get_hash_table<st_k, st_v>("egress_session_table");
    auto map_entries = table.get_all();
    for (auto &pair : map_entries) {
      auto key = pair.first;
      auto value = pair.second;

      auto entry = std::make_shared<NattingRule>(
          *this, polycube::service::utils::nbo_uint_to_ip_string(key.src_ip),
          polycube::service::utils::nbo_uint_to_ip_string(key.dst_ip), ntohs(key.src_port),
          ntohs(key.dst_port), key.proto,
          polycube::service::utils::nbo_uint_to_ip_string(value.new_ip), ntohs(value.new_port));

      entries.push_back(entry);
    }
  } catch (std::exception &e) {
    throw std::runtime_error("Unable to get the natting table");
  }
  return entries;
}

void K8sdispatcher::addNattingRule(const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto, const NattingRuleJsonObject &conf) {
  throw std::runtime_error("K8sdispatcher::addNattingRule: Method not implemented");
}

// Basic default implementation, place your extension here (if needed)
void K8sdispatcher::addNattingRuleList(const std::vector<NattingRuleJsonObject> &conf) {
  // call default implementation in base class
  K8sdispatcherBase::addNattingRuleList(conf);
}

// Basic default implementation, place your extension here (if needed)
void K8sdispatcher::replaceNattingRule(const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto, const NattingRuleJsonObject &conf) {
  // call default implementation in base class
  K8sdispatcherBase::replaceNattingRule(internalSrc, internalDst, internalSport, internalDport, proto, conf);
}

void K8sdispatcher::delNattingRule(const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto) {
  throw std::runtime_error("K8sdispatcher::delNattingRule: Method not implemented");
}

// Basic default implementation, place your extension here (if needed)
void K8sdispatcher::delNattingRuleList() {
  auto egress_table = get_hash_table<st_k, st_v>("egress_session_table");
  egress_table.remove_all();
  auto ingress_table = get_hash_table<st_k, st_v>("ingress_session_table");
  ingress_table.remove_all();

  logger()->info("Flushed natting tables");
}
std::shared_ptr<NodeportRule> K8sdispatcher::getNodeportRule(const uint16_t &nodeportPort, const std::string &proto) {
  throw std::runtime_error("K8sdispatcher::getEntry: Method not implemented");
}

std::vector<std::shared_ptr<NodeportRule>> K8sdispatcher::getNodeportRuleList() {
  throw std::runtime_error("K8sdispatcher::getNodeportRuleList: Method not implemented");
}

void K8sdispatcher::addNodeportRule(const uint16_t &nodeportPort, const std::string &proto, const NodeportRuleJsonObject &conf) {
  logger()->info("add nodeportRule");
  NodeportKey key = NodeportKey(proto,nodeportPort);
  //nodeport_map_.count(key);

  if(nodeport_map_.count(key) == 1){
    logger()->error("This nodeport rule already exists");
    throw std::runtime_error("This nodeport rule already exists");
  }

  NodeportRule rule = NodeportRule(*this,conf);
  nodeport_map_.insert(std::make_pair(key,rule));

  auto dp_rules =get_hash_table<dp_k, dp_v>(
      "dp_rules", 0, ProgramType::INGRESS);
  //logger()->info("%I",
  dp_k key_rule{
      .mask = 56, .external_ip = htonl(external_ip_), .external_port = htons(nodeportPort), .proto = proto_from_string_to_int(proto),
  };
  dp_v value{
      .internal_ip = htonl(ip_to_dec(rule.getInternalSrc())),
      .internal_port = htons(nodeportPort),
      .entry_type = 0,
  };

  dp_rules.set(key_rule, value);
}

// Basic default implementation, place your extension here (if needed)
void K8sdispatcher::addNodeportRuleList(const std::vector<NodeportRuleJsonObject> &conf) {
  // call default implementation in base class
  logger()->info("add nodeport rule");
  K8sdispatcherBase::addNodeportRuleList(conf);
}

// Basic default implementation, place your extension here (if needed)
void K8sdispatcher::replaceNodeportRule(const uint16_t &nodeportPort, const std::string &proto, const NodeportRuleJsonObject &conf) {
  // call default implementation in base class
  K8sdispatcherBase::replaceNodeportRule(nodeportPort, proto, conf);
}

void K8sdispatcher::delNodeportRule(const uint16_t &nodeportPort, const std::string &proto) {
  throw std::runtime_error("K8sdispatcher::delNodeportRule: Method not implemented");
}

// Basic default implementation, place your extension here (if needed)
void K8sdispatcher::delNodeportRuleList() {
  throw std::runtime_error("K8sdispatcher::delNodeportRuleList: Method not implemented");
}

std::string K8sdispatcher::getNodeportRange() {
  return nodeport_range_;
}

void K8sdispatcher::setNodeportRange(const std::string &value) {
  doSetNodeportRange(value);
  reloadConfig();
}
std::string K8sdispatcher::proto_from_int_to_string(const uint8_t proto) {
  switch (proto) {
  case IPPROTO_ICMP:
    return "icmp";
  case IPPROTO_TCP:
    return "tcp";
  case IPPROTO_UDP:
    return "udp";
  default:
    // Never happens
    return "unknown";
  }
}

std::shared_ptr<Ports> K8sdispatcher::getFrontendPort() {
  for (auto &it : get_ports()) {
    if (it->getType() == PortsTypeEnum::FRONTEND) {
      return it;
    }
  }
  return nullptr;
}

std::shared_ptr<Ports> K8sdispatcher::getBackendPort() {
  for (auto &it : get_ports()) {
    if (it->getType() == PortsTypeEnum::BACKEND) {
      return it;
    }
  }
  return nullptr;
}


