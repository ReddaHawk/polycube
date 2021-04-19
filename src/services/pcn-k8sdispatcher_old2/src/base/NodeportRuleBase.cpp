/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */


#include "NodeportRuleBase.h"
#include "../K8sdispatcher.h"


NodeportRuleBase::NodeportRuleBase(K8sdispatcher &parent)
    : parent_(parent) {}

NodeportRuleBase::~NodeportRuleBase() {}

void NodeportRuleBase::update(const NodeportRuleJsonObject &conf) {

  if (conf.internalSrcIsSet()) {
    setInternalSrc(conf.getInternalSrc());
  }
}

NodeportRuleJsonObject NodeportRuleBase::toJsonObject() {
  NodeportRuleJsonObject conf;

  conf.setInternalSrc(getInternalSrc());
  conf.setNodeportPort(getNodeportPort());
  conf.setProto(getProto());

  return conf;
}

std::shared_ptr<spdlog::logger> NodeportRuleBase::logger() {
  return parent_.logger();
}

