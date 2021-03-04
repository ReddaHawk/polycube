/**
* k8snat API generated from k8snat.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */



#include "RulePortForwardingAppendInputJsonObject.h"
#include <regex>

namespace polycube {
namespace service {
namespace model {

RulePortForwardingAppendInputJsonObject::RulePortForwardingAppendInputJsonObject() {
  m_externalIpIsSet = false;
  m_externalPortIsSet = false;
  m_protoIsSet = false;
  m_internalIpIsSet = false;
  m_internalPortIsSet = false;
}

RulePortForwardingAppendInputJsonObject::RulePortForwardingAppendInputJsonObject(const nlohmann::json &val) :
  JsonObjectBase(val) {
  m_externalIpIsSet = false;
  m_externalPortIsSet = false;
  m_protoIsSet = false;
  m_internalIpIsSet = false;
  m_internalPortIsSet = false;


  if (val.count("external-ip")) {
    setExternalIp(val.at("external-ip").get<std::string>());
  }

  if (val.count("external-port")) {
    setExternalPort(val.at("external-port").get<uint16_t>());
  }

  if (val.count("proto")) {
    setProto(val.at("proto").get<std::string>());
  }

  if (val.count("internal-ip")) {
    setInternalIp(val.at("internal-ip").get<std::string>());
  }

  if (val.count("internal-port")) {
    setInternalPort(val.at("internal-port").get<uint16_t>());
  }
}

nlohmann::json RulePortForwardingAppendInputJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();
  if (!getBase().is_null()) {
    val.update(getBase());
  }

  if (m_externalIpIsSet) {
    val["external-ip"] = m_externalIp;
  }

  if (m_externalPortIsSet) {
    val["external-port"] = m_externalPort;
  }

  if (m_protoIsSet) {
    val["proto"] = m_proto;
  }

  if (m_internalIpIsSet) {
    val["internal-ip"] = m_internalIp;
  }

  if (m_internalPortIsSet) {
    val["internal-port"] = m_internalPort;
  }

  return val;
}

std::string RulePortForwardingAppendInputJsonObject::getExternalIp() const {
  return m_externalIp;
}

void RulePortForwardingAppendInputJsonObject::setExternalIp(std::string value) {
  m_externalIp = value;
  m_externalIpIsSet = true;
}

bool RulePortForwardingAppendInputJsonObject::externalIpIsSet() const {
  return m_externalIpIsSet;
}



uint16_t RulePortForwardingAppendInputJsonObject::getExternalPort() const {
  return m_externalPort;
}

void RulePortForwardingAppendInputJsonObject::setExternalPort(uint16_t value) {
  m_externalPort = value;
  m_externalPortIsSet = true;
}

bool RulePortForwardingAppendInputJsonObject::externalPortIsSet() const {
  return m_externalPortIsSet;
}



std::string RulePortForwardingAppendInputJsonObject::getProto() const {
  return m_proto;
}

void RulePortForwardingAppendInputJsonObject::setProto(std::string value) {
  m_proto = value;
  m_protoIsSet = true;
}

bool RulePortForwardingAppendInputJsonObject::protoIsSet() const {
  return m_protoIsSet;
}

void RulePortForwardingAppendInputJsonObject::unsetProto() {
  m_protoIsSet = false;
}

std::string RulePortForwardingAppendInputJsonObject::getInternalIp() const {
  return m_internalIp;
}

void RulePortForwardingAppendInputJsonObject::setInternalIp(std::string value) {
  m_internalIp = value;
  m_internalIpIsSet = true;
}

bool RulePortForwardingAppendInputJsonObject::internalIpIsSet() const {
  return m_internalIpIsSet;
}



uint16_t RulePortForwardingAppendInputJsonObject::getInternalPort() const {
  return m_internalPort;
}

void RulePortForwardingAppendInputJsonObject::setInternalPort(uint16_t value) {
  m_internalPort = value;
  m_internalPortIsSet = true;
}

bool RulePortForwardingAppendInputJsonObject::internalPortIsSet() const {
  return m_internalPortIsSet;
}




}
}
}

