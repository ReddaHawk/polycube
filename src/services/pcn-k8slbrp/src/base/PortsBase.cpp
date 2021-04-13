/**
* k8slbrp API generated from k8slbrp.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */


#include "PortsBase.h"
#include "../K8slbrp.h"

PortsBase::PortsBase(polycube::service::Cube<Ports> &parent,
    std::shared_ptr<polycube::service::PortIface> port)
    : Port(port), parent_(dynamic_cast<K8slbrp &>(parent)) {}


PortsBase::~PortsBase() {}

void PortsBase::update(const PortsJsonObject &conf) {
  set_conf(conf.getBase());

  if (conf.typeIsSet()) {
    setType(conf.getType());
  }
}

PortsJsonObject PortsBase::toJsonObject() {
  PortsJsonObject conf;
  conf.setBase(to_json());

  conf.setName(getName());
  conf.setType(getType());

  return conf;
}

std::shared_ptr<spdlog::logger> PortsBase::logger() {
  return parent_.logger();
}

