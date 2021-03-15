/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */



#include "K8sdispatcherJsonObject.h"
#include <regex>

namespace polycube {
namespace service {
namespace model {

K8sdispatcherJsonObject::K8sdispatcherJsonObject() {
  m_nameIsSet = false;
  m_portsIsSet = false;
  m_clusterIpSubnetIsSet = false;
  m_clientSubnetIsSet = false;
  m_virtualClientSubnetIsSet = false;
  m_nattingTableIsSet = false;
  m_nodeportRange = "30000-32767";
  m_nodeportRangeIsSet = true;
}

K8sdispatcherJsonObject::K8sdispatcherJsonObject(const nlohmann::json &val) :
  JsonObjectBase(val) {
  m_nameIsSet = false;
  m_portsIsSet = false;
  m_clusterIpSubnetIsSet = false;
  m_clientSubnetIsSet = false;
  m_virtualClientSubnetIsSet = false;
  m_nattingTableIsSet = false;
  m_nodeportRangeIsSet = false;


  if (val.count("name")) {
    setName(val.at("name").get<std::string>());
  }

  if (val.count("ports")) {
    for (auto& item : val["ports"]) {
      PortsJsonObject newItem{ item };
      m_ports.push_back(newItem);
    }

    m_portsIsSet = true;
  }

  if (val.count("cluster-ip-subnet")) {
    setClusterIpSubnet(val.at("cluster-ip-subnet").get<std::string>());
  }

  if (val.count("client-subnet")) {
    setClientSubnet(val.at("client-subnet").get<std::string>());
  }

  if (val.count("virtual-client-subnet")) {
    setVirtualClientSubnet(val.at("virtual-client-subnet").get<std::string>());
  }

  if (val.count("natting-table")) {
    for (auto& item : val["natting-table"]) {
      NattingTableJsonObject newItem{ item };
      m_nattingTable.push_back(newItem);
    }

    m_nattingTableIsSet = true;
  }

  if (val.count("nodeport-range")) {
    setNodeportRange(val.at("nodeport-range").get<std::string>());
  }
}

nlohmann::json K8sdispatcherJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();
  if (!getBase().is_null()) {
    val.update(getBase());
  }

  if (m_nameIsSet) {
    val["name"] = m_name;
  }

  {
    nlohmann::json jsonArray;
    for (auto& item : m_ports) {
      jsonArray.push_back(JsonObjectBase::toJson(item));
    }

    if (jsonArray.size() > 0) {
      val["ports"] = jsonArray;
    }
  }

  if (m_clusterIpSubnetIsSet) {
    val["cluster-ip-subnet"] = m_clusterIpSubnet;
  }

  if (m_clientSubnetIsSet) {
    val["client-subnet"] = m_clientSubnet;
  }

  if (m_virtualClientSubnetIsSet) {
    val["virtual-client-subnet"] = m_virtualClientSubnet;
  }

  {
    nlohmann::json jsonArray;
    for (auto& item : m_nattingTable) {
      jsonArray.push_back(JsonObjectBase::toJson(item));
    }

    if (jsonArray.size() > 0) {
      val["natting-table"] = jsonArray;
    }
  }

  if (m_nodeportRangeIsSet) {
    val["nodeport-range"] = m_nodeportRange;
  }

  return val;
}

std::string K8sdispatcherJsonObject::getName() const {
  return m_name;
}

void K8sdispatcherJsonObject::setName(std::string value) {
  m_name = value;
  m_nameIsSet = true;
}

bool K8sdispatcherJsonObject::nameIsSet() const {
  return m_nameIsSet;
}



const std::vector<PortsJsonObject>& K8sdispatcherJsonObject::getPorts() const{
  return m_ports;
}

void K8sdispatcherJsonObject::addPorts(PortsJsonObject value) {
  m_ports.push_back(value);
  m_portsIsSet = true;
}


bool K8sdispatcherJsonObject::portsIsSet() const {
  return m_portsIsSet;
}

void K8sdispatcherJsonObject::unsetPorts() {
  m_portsIsSet = false;
}

std::string K8sdispatcherJsonObject::getClusterIpSubnet() const {
  return m_clusterIpSubnet;
}

void K8sdispatcherJsonObject::setClusterIpSubnet(std::string value) {
  m_clusterIpSubnet = value;
  m_clusterIpSubnetIsSet = true;
}

bool K8sdispatcherJsonObject::clusterIpSubnetIsSet() const {
  return m_clusterIpSubnetIsSet;
}



std::string K8sdispatcherJsonObject::getClientSubnet() const {
  return m_clientSubnet;
}

void K8sdispatcherJsonObject::setClientSubnet(std::string value) {
  m_clientSubnet = value;
  m_clientSubnetIsSet = true;
}

bool K8sdispatcherJsonObject::clientSubnetIsSet() const {
  return m_clientSubnetIsSet;
}



std::string K8sdispatcherJsonObject::getVirtualClientSubnet() const {
  return m_virtualClientSubnet;
}

void K8sdispatcherJsonObject::setVirtualClientSubnet(std::string value) {
  m_virtualClientSubnet = value;
  m_virtualClientSubnetIsSet = true;
}

bool K8sdispatcherJsonObject::virtualClientSubnetIsSet() const {
  return m_virtualClientSubnetIsSet;
}



const std::vector<NattingTableJsonObject>& K8sdispatcherJsonObject::getNattingTable() const{
  return m_nattingTable;
}

void K8sdispatcherJsonObject::addNattingTable(NattingTableJsonObject value) {
  m_nattingTable.push_back(value);
  m_nattingTableIsSet = true;
}


bool K8sdispatcherJsonObject::nattingTableIsSet() const {
  return m_nattingTableIsSet;
}

void K8sdispatcherJsonObject::unsetNattingTable() {
  m_nattingTableIsSet = false;
}

std::string K8sdispatcherJsonObject::getNodeportRange() const {
  return m_nodeportRange;
}

void K8sdispatcherJsonObject::setNodeportRange(std::string value) {
  m_nodeportRange = value;
  m_nodeportRangeIsSet = true;
}

bool K8sdispatcherJsonObject::nodeportRangeIsSet() const {
  return m_nodeportRangeIsSet;
}

void K8sdispatcherJsonObject::unsetNodeportRange() {
  m_nodeportRangeIsSet = false;
}


}
}
}

