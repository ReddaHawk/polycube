/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


// TODO: Modify these methods with your own implementation


#include "Ports.h"
#include "K8sdispatcher.h"


Ports::Ports(polycube::service::Cube<Ports> &parent,
    std::shared_ptr<polycube::service::PortIface> port,
    const PortsJsonObject &conf)
    : PortsBase(parent, port) {
  port_type_ = conf.getType();
}

Ports::~Ports() {}

void Ports::update(const PortsJsonObject &conf) {
  // This method updates all the object/parameter in Ports object specified in
  // the conf JsonObject.
  // You can modify this implementation.
  Port::set_conf(conf.getBase());

  if (conf.typeIsSet()) {
    setType(conf.getType());
  }
}

PortsJsonObject Ports::toJsonObject() {
  PortsJsonObject conf;
  conf.setBase(Port::to_json());

  conf.setType(getType());

  return conf;
}

PortsTypeEnum Ports::getType() {
  return port_type_;
}

void Ports::setType(const PortsTypeEnum &value) {
  throw std::runtime_error("Ports::setType: Method not implemented");
}


