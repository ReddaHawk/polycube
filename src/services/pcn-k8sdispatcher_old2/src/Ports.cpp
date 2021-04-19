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
  logger()->info("Port constructor");
  port_type_ = conf.getType();
  if(port_type_==polycube::service::model::PortsTypeEnum::FRONTEND){
    // lambda function to align IP and Netmask between Port and ExtIface
    ParameterEventCallback f_ip;
    f_ip = [&](const std::string param_name, const std::string new_ip) {
      try {
        logger()->info("callback ip with {0}",new_ip);
        if (!new_ip.empty()) {
          if (ip_ == new_ip)
            return;

          // set the ip address of the netdev on the port
          logger()->debug("Align ip of the port {0} with IP {1}", name(),new_ip);
          ip_=new_ip;
          parent_.doSetExternalIp(new_ip);
        }
      } catch (std::exception &e) {
        logger()->trace("iface_ip_notification - False ip notification: {0}",
                        e.what());
      }
    };

    // lambda function to align MAC between Port and ExtIface
    ParameterEventCallback f_mac;
    f_mac = [&](const std::string param_name, const std::string new_mac) {
      try {
        logger()->info("callback mac with {0}",new_mac);
        if (mac_ == new_mac)
          return;

        // set the mac address of the netdev on the port
        logger()->debug("Align mac of port {0} with mac {1}", name(),mac_);
        mac_=new_mac;
        parent_.doSetExternalMac(mac_);
      } catch (std::exception &e) {
        logger()->trace("iface_mac_notification - False mac notification: {0}",
                        e.what());
      }
    };
    /* Register the new port to IP and MAC notifications arriving from ExtIface
     * do not use define because strings are easier to manipulate
     * for future extensions */
    subscribe_peer_parameter("IP", f_ip);
    subscribe_peer_parameter("MAC", f_mac);
  }

}

Ports::~Ports() {
  if(port_type_==polycube::service::model::PortsTypeEnum::FRONTEND){
    unsubscribe_peer_parameter("IP");
    unsubscribe_peer_parameter("MAC");
  }
}

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


