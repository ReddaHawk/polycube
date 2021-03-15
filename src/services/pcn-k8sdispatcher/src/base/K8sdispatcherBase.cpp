/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */


#include "K8sdispatcherBase.h"

K8sdispatcherBase::K8sdispatcherBase(const std::string name) {
  logger()->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [K8sdispatcher] [%n] [%l] %v");
}



K8sdispatcherBase::~K8sdispatcherBase() {}

void K8sdispatcherBase::update(const K8sdispatcherJsonObject &conf) {
  set_conf(conf.getBase());

  if (conf.portsIsSet()) {
    for (auto &i : conf.getPorts()) {
      auto name = i.getName();
      auto m = getPorts(name);
      m->update(i);
    }
  }
  if (conf.clusterIpSubnetIsSet()) {
    setClusterIpSubnet(conf.getClusterIpSubnet());
  }
  if (conf.clientSubnetIsSet()) {
    setClientSubnet(conf.getClientSubnet());
  }
  if (conf.virtualClientSubnetIsSet()) {
    setVirtualClientSubnet(conf.getVirtualClientSubnet());
  }
  if (conf.nattingTableIsSet()) {
    for (auto &i : conf.getNattingTable()) {
      auto internalSrc = i.getInternalSrc();
      auto internalDst = i.getInternalDst();
      auto internalSport = i.getInternalSport();
      auto internalDport = i.getInternalDport();
      auto proto = i.getProto();
      auto m = getNattingTable(internalSrc, internalDst, internalSport, internalDport, proto);
      m->update(i);
    }
  }
  if (conf.nodeportRangeIsSet()) {
    setNodeportRange(conf.getNodeportRange());
  }
}

K8sdispatcherJsonObject K8sdispatcherBase::toJsonObject() {
  K8sdispatcherJsonObject conf;
  conf.setBase(to_json());

  conf.setName(getName());
  for (auto &i : getPortsList()) {
    conf.addPorts(i->toJsonObject());
  }
  conf.setClusterIpSubnet(getClusterIpSubnet());
  conf.setClientSubnet(getClientSubnet());
  conf.setVirtualClientSubnet(getVirtualClientSubnet());
  for(auto &i : getNattingTableList()) {
    conf.addNattingTable(i->toJsonObject());
  }
  conf.setNodeportRange(getNodeportRange());

  return conf;
}
void K8sdispatcherBase::addPortsList(const std::vector<PortsJsonObject> &conf) {
  for (auto &i : conf) {
    std::string name_ = i.getName();
    addPorts(name_, i);
  }
}

void K8sdispatcherBase::replacePorts(const std::string &name, const PortsJsonObject &conf) {
  delPorts(name);
  std::string name_ = conf.getName();
  addPorts(name_, conf);
}

void K8sdispatcherBase::delPortsList() {
  auto elements = getPortsList();
  for (auto &i : elements) {
    std::string name_ = i->getName();
    delPorts(name_);
  }
}

void K8sdispatcherBase::addPorts(const std::string &name, const PortsJsonObject &conf) {
  add_port<PortsJsonObject>(name, conf);
}

void K8sdispatcherBase::delPorts(const std::string &name) {
  remove_port(name);
}

std::shared_ptr<Ports> K8sdispatcherBase::getPorts(const std::string &name) {
  return get_port(name);
}

std::vector<std::shared_ptr<Ports>> K8sdispatcherBase::getPortsList() {
  return get_ports();
}
void K8sdispatcherBase::addNattingTableList(const std::vector<NattingTableJsonObject> &conf) {
  for (auto &i : conf) {
    std::string internalSrc_ = i.getInternalSrc();
    std::string internalDst_ = i.getInternalDst();
    uint16_t internalSport_ = i.getInternalSport();
    uint16_t internalDport_ = i.getInternalDport();
    std::string proto_ = i.getProto();
    addNattingTable(internalSrc_, internalDst_, internalSport_, internalDport_, proto_, i);
  }
}

void K8sdispatcherBase::replaceNattingTable(const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto, const NattingTableJsonObject &conf) {
  delNattingTable(internalSrc, internalDst, internalSport, internalDport, proto);
  std::string internalSrc_ = conf.getInternalSrc();
  std::string internalDst_ = conf.getInternalDst();
  uint16_t internalSport_ = conf.getInternalSport();
  uint16_t internalDport_ = conf.getInternalDport();
  std::string proto_ = conf.getProto();
  addNattingTable(internalSrc_, internalDst_, internalSport_, internalDport_, proto_, conf);
}

void K8sdispatcherBase::delNattingTableList() {
  auto elements = getNattingTableList();
  for (auto &i : elements) {
    std::string internalSrc_ = i->getInternalSrc();
    std::string internalDst_ = i->getInternalDst();
    uint16_t internalSport_ = i->getInternalSport();
    uint16_t internalDport_ = i->getInternalDport();
    std::string proto_ = i->getProto();
    delNattingTable(internalSrc_, internalDst_, internalSport_, internalDport_, proto_);
  }
}


