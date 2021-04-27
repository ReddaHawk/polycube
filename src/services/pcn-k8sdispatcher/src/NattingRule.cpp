/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


// TODO: Modify these methods with your own implementation


#include "NattingRule.h"
#include "K8sdispatcher.h"


NattingRule::NattingRule(K8sdispatcher &parent, const NattingRuleJsonObject &conf)
    : NattingRuleBase(parent) {
  if (conf.externalIpIsSet()) {
    setExternalIp(conf.getExternalIp());
  }

  if (conf.externalPortIsSet()) {
    setExternalPort(conf.getExternalPort());
  }

}

NattingRule::NattingRule(K8sdispatcher &parent, const std::string srcIp,
                           const std::string dstIp, const uint16_t srcPort,
                           const uint16_t dstPort, const uint8_t proto,
                           const std::string newIp, const uint16_t newPort
)
    : NattingRuleBase(parent) {
  this->srcIp = srcIp;
  this->dstIp = dstIp;
  this->srcPort = srcPort;
  this->dstPort = dstPort;
  this->newIp = newIp;
  this->newPort = newPort;
  this->proto = parent.proto_from_int_to_string(proto);
}


NattingRule::~NattingRule() {}

void NattingRule::update(const NattingRuleJsonObject &conf) {
  // This method updates all the object/parameter in NattingTable object
  // specified in the conf JsonObject.
  // You can modify this implementation.

  if (conf.externalIpIsSet()) {
    setExternalIp(conf.getExternalIp());
  }
  if (conf.externalPortIsSet()) {
    setExternalPort(conf.getExternalPort());
  }
}

NattingRuleJsonObject NattingRule::toJsonObject() {
  NattingRuleJsonObject conf;
  conf.setInternalSrc(getInternalSrc());
  conf.setInternalDst(getInternalDst());
  conf.setInternalSport(getInternalSport());
  conf.setInternalDport(getInternalDport());
  conf.setProto(getProto());
  conf.setExternalIp(getExternalIp());
  conf.setExternalPort(getExternalPort());

  return conf;
}

std::string NattingRule::getInternalSrc() {
  // This method retrieves the internalSrc value.
  return srcIp;
}

std::string NattingRule::getInternalDst() {
  // This method retrieves the internalDst value.
  return dstIp;
}

uint16_t NattingRule::getInternalSport() {
  // This method retrieves the internalSport value.
  return srcPort;
}

uint16_t NattingRule::getInternalDport() {
  // This method retrieves the internalDport value.
  return dstPort;
}

std::string NattingRule::getProto() {
  // This method retrieves the proto value.
  return proto;
}

std::string NattingRule::getExternalIp() {
  // This method retrieves the externalIp value.
  return newIp;
}

void NattingRule::setExternalIp(const std::string &value) {
  // This method set the externalIp value.
  throw std::runtime_error("Cannot modify a natting table entry");
}

uint16_t NattingRule::getExternalPort() {
  // This method retrieves the externalPort value.
  return newPort;
}

void NattingRule::setExternalPort(const uint16_t &value) {
  // This method set the externalPort value.
  throw std::runtime_error("Cannot modify a natting table entry");
}

