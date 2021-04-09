/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */


#include "K8sdispatcherApiImpl.h"

namespace polycube {
namespace service {
namespace api {

using namespace polycube::service::model;

namespace K8sdispatcherApiImpl {
namespace {
std::unordered_map<std::string, std::shared_ptr<K8sdispatcher>> cubes;
std::mutex cubes_mutex;

std::shared_ptr<K8sdispatcher> get_cube(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  auto iter = cubes.find(name);
  if (iter == cubes.end()) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }

  return iter->second;
}

}

void create_k8sdispatcher_by_id(const std::string &name, const K8sdispatcherJsonObject &jsonObject) {
  {
    // check if name is valid before creating it
    std::lock_guard<std::mutex> guard(cubes_mutex);
    if (cubes.count(name) != 0) {
      throw std::runtime_error("There is already a cube with name " + name);
    }
  }
  auto ptr = std::make_shared<K8sdispatcher>(name, jsonObject);
  std::unordered_map<std::string, std::shared_ptr<K8sdispatcher>>::iterator iter;
  bool inserted;

  std::lock_guard<std::mutex> guard(cubes_mutex);
  std::tie(iter, inserted) = cubes.emplace(name, std::move(ptr));

  if (!inserted) {
    throw std::runtime_error("There is already a cube with name " + name);
  }
}

void replace_k8sdispatcher_by_id(const std::string &name, const K8sdispatcherJsonObject &bridge){
  throw std::runtime_error("Method not supported!");
}

void delete_k8sdispatcher_by_id(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  if (cubes.count(name) == 0) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }
  cubes.erase(name);
}

std::vector<K8sdispatcherJsonObject> read_k8sdispatcher_list_by_id() {
  std::vector<K8sdispatcherJsonObject> jsonObject_vect;
  for(auto &i : cubes) {
    auto m = get_cube(i.first);
    jsonObject_vect.push_back(m->toJsonObject());
  }
  return jsonObject_vect;
}

std::vector<nlohmann::fifo_map<std::string, std::string>> read_k8sdispatcher_list_by_id_get_list() {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  for (auto &x : cubes) {
    nlohmann::fifo_map<std::string, std::string> m;
    m["name"] = x.first;
    r.push_back(std::move(m));
  }
  return r;
}

/**
* @brief   Create natting-table by ID
*
* Create operation of resource: natting-table*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
* @param[in] value natting-tablebody object
*
* Responses:
*
*/
void
create_k8sdispatcher_natting_table_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto, const NattingTableJsonObject &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->addNattingTable(internalSrc, internalDst, internalSport, internalDport, proto, value);
}

/**
* @brief   Create natting-table by ID
*
* Create operation of resource: natting-table*
*
* @param[in] name ID of name
* @param[in] value natting-tablebody object
*
* Responses:
*
*/
void
create_k8sdispatcher_natting_table_list_by_id(const std::string &name, const std::vector<NattingTableJsonObject> &value) {
  auto k8sdispatcher = get_cube(name);
  k8sdispatcher->addNattingTableList(value);
}

/**
* @brief   Create ports by ID
*
* Create operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
create_k8sdispatcher_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->addPorts(portsName, value);
}

/**
* @brief   Create ports by ID
*
* Create operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
create_k8sdispatcher_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value) {
  auto k8sdispatcher = get_cube(name);
  k8sdispatcher->addPortsList(value);
}

/**
* @brief   Delete natting-table by ID
*
* Delete operation of resource: natting-table*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
*
* Responses:
*
*/
void
delete_k8sdispatcher_natting_table_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->delNattingTable(internalSrc, internalDst, internalSport, internalDport, proto);
}

/**
* @brief   Delete natting-table by ID
*
* Delete operation of resource: natting-table*
*
* @param[in] name ID of name
*
* Responses:
*
*/
void
delete_k8sdispatcher_natting_table_list_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  k8sdispatcher->delNattingTableList();
}

/**
* @brief   Delete ports by ID
*
* Delete operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
*
* Responses:
*
*/
void
delete_k8sdispatcher_ports_by_id(const std::string &name, const std::string &portsName) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->delPorts(portsName);
}

/**
* @brief   Delete ports by ID
*
* Delete operation of resource: ports*
*
* @param[in] name ID of name
*
* Responses:
*
*/
void
delete_k8sdispatcher_ports_list_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  k8sdispatcher->delPortsList();
}

/**
* @brief   Read k8sdispatcher by ID
*
* Read operation of resource: k8sdispatcher*
*
* @param[in] name ID of name
*
* Responses:
* K8sdispatcherJsonObject
*/
K8sdispatcherJsonObject
read_k8sdispatcher_by_id(const std::string &name) {
  return get_cube(name)->toJsonObject();

}

/**
* @brief   Read client-subnet by ID
*
* Read operation of resource: client-subnet*
*
* @param[in] name ID of name
*
* Responses:
* std::string
*/
std::string
read_k8sdispatcher_client_subnet_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  return k8sdispatcher->getClientSubnet();

}

/**
* @brief   Read cluster-ip-subnet by ID
*
* Read operation of resource: cluster-ip-subnet*
*
* @param[in] name ID of name
*
* Responses:
* std::string
*/
std::string
read_k8sdispatcher_cluster_ip_subnet_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  return k8sdispatcher->getClusterIpSubnet();

}

/**
* @brief   Read natting-table by ID
*
* Read operation of resource: natting-table*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
*
* Responses:
* NattingTableJsonObject
*/
NattingTableJsonObject
read_k8sdispatcher_natting_table_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto) {
  auto k8sdispatcher = get_cube(name);
  return k8sdispatcher->getNattingTable(internalSrc, internalDst, internalSport, internalDport, proto)->toJsonObject();

}

/**
* @brief   Read external-ip by ID
*
* Read operation of resource: external-ip*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
*
* Responses:
* std::string
*/
std::string
read_k8sdispatcher_natting_table_external_ip_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto) {
  auto k8sdispatcher = get_cube(name);
  auto nattingTable = k8sdispatcher->getNattingTable(internalSrc, internalDst, internalSport, internalDport, proto);
  return nattingTable->getExternalIp();

}

/**
* @brief   Read external-port by ID
*
* Read operation of resource: external-port*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
*
* Responses:
* uint16_t
*/
uint16_t
read_k8sdispatcher_natting_table_external_port_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto) {
  auto k8sdispatcher = get_cube(name);
  auto nattingTable = k8sdispatcher->getNattingTable(internalSrc, internalDst, internalSport, internalDport, proto);
  return nattingTable->getExternalPort();

}

/**
* @brief   Read natting-table by ID
*
* Read operation of resource: natting-table*
*
* @param[in] name ID of name
*
* Responses:
* std::vector<NattingTableJsonObject>
*/
std::vector<NattingTableJsonObject>
read_k8sdispatcher_natting_table_list_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  auto &&nattingTable = k8sdispatcher->getNattingTableList();
  std::vector<NattingTableJsonObject> m;
  for(auto &i : nattingTable)
    m.push_back(i->toJsonObject());
  return m;
}

/**
* @brief   Read nodeport-range by ID
*
* Read operation of resource: nodeport-range*
*
* @param[in] name ID of name
*
* Responses:
* std::string
*/
std::string
read_k8sdispatcher_nodeport_range_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  return k8sdispatcher->getNodeportRange();

}

/**
* @brief   Read ports by ID
*
* Read operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
*
* Responses:
* PortsJsonObject
*/
PortsJsonObject
read_k8sdispatcher_ports_by_id(const std::string &name, const std::string &portsName) {
  auto k8sdispatcher = get_cube(name);
  return k8sdispatcher->getPorts(portsName)->toJsonObject();

}

/**
* @brief   Read ports by ID
*
* Read operation of resource: ports*
*
* @param[in] name ID of name
*
* Responses:
* std::vector<PortsJsonObject>
*/
std::vector<PortsJsonObject>
read_k8sdispatcher_ports_list_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  auto &&ports = k8sdispatcher->getPortsList();
  std::vector<PortsJsonObject> m;
  for(auto &i : ports)
    m.push_back(i->toJsonObject());
  return m;
}

/**
* @brief   Read type by ID
*
* Read operation of resource: type*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
*
* Responses:
* PortsTypeEnum
*/
PortsTypeEnum
read_k8sdispatcher_ports_type_by_id(const std::string &name, const std::string &portsName) {
  auto k8sdispatcher = get_cube(name);
  auto ports = k8sdispatcher->getPorts(portsName);
  return ports->getType();

}

/**
* @brief   Read virtual-client-subnet by ID
*
* Read operation of resource: virtual-client-subnet*
*
* @param[in] name ID of name
*
* Responses:
* std::string
*/
std::string
read_k8sdispatcher_virtual_client_subnet_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  return k8sdispatcher->getVirtualClientSubnet();

}

/**
* @brief   Replace natting-table by ID
*
* Replace operation of resource: natting-table*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
* @param[in] value natting-tablebody object
*
* Responses:
*
*/
void
replace_k8sdispatcher_natting_table_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto, const NattingTableJsonObject &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->replaceNattingTable(internalSrc, internalDst, internalSport, internalDport, proto, value);
}

/**
* @brief   Replace natting-table by ID
*
* Replace operation of resource: natting-table*
*
* @param[in] name ID of name
* @param[in] value natting-tablebody object
*
* Responses:
*
*/
void
replace_k8sdispatcher_natting_table_list_by_id(const std::string &name, const std::vector<NattingTableJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Replace ports by ID
*
* Replace operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
replace_k8sdispatcher_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->replacePorts(portsName, value);
}

/**
* @brief   Replace ports by ID
*
* Replace operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
replace_k8sdispatcher_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update k8sdispatcher by ID
*
* Update operation of resource: k8sdispatcher*
*
* @param[in] name ID of name
* @param[in] value k8sdispatcherbody object
*
* Responses:
*
*/
void
update_k8sdispatcher_by_id(const std::string &name, const K8sdispatcherJsonObject &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->update(value);
}

/**
* @brief   Update client-subnet by ID
*
* Update operation of resource: client-subnet*
*
* @param[in] name ID of name
* @param[in] value Range of IPs of pods in this node
*
* Responses:
*
*/
void
update_k8sdispatcher_client_subnet_by_id(const std::string &name, const std::string &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->setClientSubnet(value);
}

/**
* @brief   Update cluster-ip-subnet by ID
*
* Update operation of resource: cluster-ip-subnet*
*
* @param[in] name ID of name
* @param[in] value Range of VIPs where clusterIP services are exposed
*
* Responses:
*
*/
void
update_k8sdispatcher_cluster_ip_subnet_by_id(const std::string &name, const std::string &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->setClusterIpSubnet(value);
}

/**
* @brief   Update k8sdispatcher by ID
*
* Update operation of resource: k8sdispatcher*
*
* @param[in] value k8sdispatcherbody object
*
* Responses:
*
*/
void
update_k8sdispatcher_list_by_id(const std::vector<K8sdispatcherJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update natting-table by ID
*
* Update operation of resource: natting-table*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
* @param[in] value natting-tablebody object
*
* Responses:
*
*/
void
update_k8sdispatcher_natting_table_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto, const NattingTableJsonObject &value) {
  auto k8sdispatcher = get_cube(name);
  auto nattingTable = k8sdispatcher->getNattingTable(internalSrc, internalDst, internalSport, internalDport, proto);

  return nattingTable->update(value);
}

/**
* @brief   Update external-ip by ID
*
* Update operation of resource: external-ip*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
* @param[in] value Translated IP address
*
* Responses:
*
*/
void
update_k8sdispatcher_natting_table_external_ip_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto, const std::string &value) {
  auto k8sdispatcher = get_cube(name);
  auto nattingTable = k8sdispatcher->getNattingTable(internalSrc, internalDst, internalSport, internalDport, proto);

  return nattingTable->setExternalIp(value);
}

/**
* @brief   Update external-port by ID
*
* Update operation of resource: external-port*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
* @param[in] value Translated L4 port number
*
* Responses:
*
*/
void
update_k8sdispatcher_natting_table_external_port_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto, const uint16_t &value) {
  auto k8sdispatcher = get_cube(name);
  auto nattingTable = k8sdispatcher->getNattingTable(internalSrc, internalDst, internalSport, internalDport, proto);

  return nattingTable->setExternalPort(value);
}

/**
* @brief   Update natting-table by ID
*
* Update operation of resource: natting-table*
*
* @param[in] name ID of name
* @param[in] value natting-tablebody object
*
* Responses:
*
*/
void
update_k8sdispatcher_natting_table_list_by_id(const std::string &name, const std::vector<NattingTableJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update nodeport-range by ID
*
* Update operation of resource: nodeport-range*
*
* @param[in] name ID of name
* @param[in] value Port range used for NodePort services
*
* Responses:
*
*/
void
update_k8sdispatcher_nodeport_range_by_id(const std::string &name, const std::string &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->setNodeportRange(value);
}

/**
* @brief   Update ports by ID
*
* Update operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
update_k8sdispatcher_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value) {
  auto k8sdispatcher = get_cube(name);
  auto ports = k8sdispatcher->getPorts(portsName);

  return ports->update(value);
}

/**
* @brief   Update ports by ID
*
* Update operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
update_k8sdispatcher_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update type by ID
*
* Update operation of resource: type*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value Type of the k8sdispatcher port (e.g. BACKEND or FRONTEND)
*
* Responses:
*
*/
void
update_k8sdispatcher_ports_type_by_id(const std::string &name, const std::string &portsName, const PortsTypeEnum &value) {
  auto k8sdispatcher = get_cube(name);
  auto ports = k8sdispatcher->getPorts(portsName);

  return ports->setType(value);
}

/**
* @brief   Update virtual-client-subnet by ID
*
* Update operation of resource: virtual-client-subnet*
*
* @param[in] name ID of name
* @param[in] value Range where client&#39;s IPs are mapped into
*
* Responses:
*
*/
void
update_k8sdispatcher_virtual_client_subnet_by_id(const std::string &name, const std::string &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->setVirtualClientSubnet(value);
}



/*
 * help related
 */

std::vector<nlohmann::fifo_map<std::string, std::string>> read_k8sdispatcher_natting_table_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&k8sdispatcher = get_cube(name);

  auto &&nattingTable = k8sdispatcher->getNattingTableList();
  for(auto &i : nattingTable) {
    nlohmann::fifo_map<std::string, std::string> keys;

    keys["internalSrc"] = i->getInternalSrc();
    keys["internalDst"] = i->getInternalDst();
    keys["internalSport"] = std::to_string(i->getInternalSport());
    keys["internalDport"] = std::to_string(i->getInternalDport());
    keys["proto"] = i->getProto();

    r.push_back(keys);
  }
  return r;
}

std::vector<nlohmann::fifo_map<std::string, std::string>> read_k8sdispatcher_ports_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&k8sdispatcher = get_cube(name);

  auto &&ports = k8sdispatcher->getPortsList();
  for(auto &i : ports) {
    nlohmann::fifo_map<std::string, std::string> keys;

    keys["name"] = i->getName();

    r.push_back(keys);
  }
  return r;
}


}

}
}
}

