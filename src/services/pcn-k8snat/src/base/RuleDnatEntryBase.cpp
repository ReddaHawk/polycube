/**
* k8snat API generated from k8snat.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */


#include "RuleDnatEntryBase.h"
#include "../K8snat.h"


RuleDnatEntryBase::RuleDnatEntryBase(RuleDnat &parent)
    : parent_(parent) {}

RuleDnatEntryBase::~RuleDnatEntryBase() {}

void RuleDnatEntryBase::update(const RuleDnatEntryJsonObject &conf) {

  if (conf.externalIpIsSet()) {
    setExternalIp(conf.getExternalIp());
  }
  if (conf.internalIpIsSet()) {
    setInternalIp(conf.getInternalIp());
  }
}

RuleDnatEntryJsonObject RuleDnatEntryBase::toJsonObject() {
  RuleDnatEntryJsonObject conf;

  conf.setId(getId());
  conf.setExternalIp(getExternalIp());
  conf.setInternalIp(getInternalIp());

  return conf;
}

std::shared_ptr<spdlog::logger> RuleDnatEntryBase::logger() {
  return parent_.logger();
}

