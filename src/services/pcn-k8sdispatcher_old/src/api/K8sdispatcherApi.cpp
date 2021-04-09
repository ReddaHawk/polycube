/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */


#include "K8sdispatcherApi.h"
#include "K8sdispatcherApiImpl.h"

using namespace polycube::service::model;
using namespace polycube::service::api::K8sdispatcherApiImpl;

#ifdef __cplusplus
extern "C" {
#endif

Response create_k8sdispatcher_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    K8sdispatcherJsonObject unique_value { request_body };

    unique_value.setName(unique_name);
    create_k8sdispatcher_by_id(unique_name, unique_value);
    return { kCreated, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response create_k8sdispatcher_natting_table_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_internalSrc;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-src")) {
      unique_internalSrc = std::string { keys[i].value.string };
      break;
    }
  }

  std::string unique_internalDst;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dst")) {
      unique_internalDst = std::string { keys[i].value.string };
      break;
    }
  }

  uint16_t unique_internalSport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-sport")) {
      unique_internalSport = keys[i].value.uint16;
      break;
    }
  }

  uint16_t unique_internalDport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dport")) {
      unique_internalDport = keys[i].value.uint16;
      break;
    }
  }

  std::string unique_proto;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "proto")) {
      unique_proto = std::string { keys[i].value.string };
      break;
    }
  }


  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    NattingTableJsonObject unique_value { request_body };

    unique_value.setInternalSrc(unique_internalSrc);
    unique_value.setInternalDst(unique_internalDst);
    unique_value.setInternalSport(unique_internalSport);
    unique_value.setInternalDport(unique_internalDport);
    unique_value.setProto(unique_proto);
    create_k8sdispatcher_natting_table_by_id(unique_name, unique_internalSrc, unique_internalDst, unique_internalSport, unique_internalDport, unique_proto, unique_value);
    return { kCreated, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response create_k8sdispatcher_natting_table_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  // Getting the body param
  std::vector<NattingTableJsonObject> unique_value;

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    std::vector<NattingTableJsonObject> unique_value;
    for (auto &j : request_body) {
      NattingTableJsonObject a { j };
      unique_value.push_back(a);
    }
    create_k8sdispatcher_natting_table_list_by_id(unique_name, unique_value);
    return { kCreated, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response create_k8sdispatcher_ports_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_portsName;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "ports_name")) {
      unique_portsName = std::string { keys[i].value.string };
      break;
    }
  }


  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    PortsJsonObject unique_value { request_body };

    unique_value.setName(unique_portsName);
    create_k8sdispatcher_ports_by_id(unique_name, unique_portsName, unique_value);
    return { kCreated, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response create_k8sdispatcher_ports_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  // Getting the body param
  std::vector<PortsJsonObject> unique_value;

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    std::vector<PortsJsonObject> unique_value;
    for (auto &j : request_body) {
      PortsJsonObject a { j };
      unique_value.push_back(a);
    }
    create_k8sdispatcher_ports_list_by_id(unique_name, unique_value);
    return { kCreated, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response delete_k8sdispatcher_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {
    delete_k8sdispatcher_by_id(unique_name);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response delete_k8sdispatcher_natting_table_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_internalSrc;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-src")) {
      unique_internalSrc = std::string { keys[i].value.string };
      break;
    }
  }

  std::string unique_internalDst;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dst")) {
      unique_internalDst = std::string { keys[i].value.string };
      break;
    }
  }

  uint16_t unique_internalSport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-sport")) {
      unique_internalSport = keys[i].value.uint16;
      break;
    }
  }

  uint16_t unique_internalDport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dport")) {
      unique_internalDport = keys[i].value.uint16;
      break;
    }
  }

  std::string unique_proto;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "proto")) {
      unique_proto = std::string { keys[i].value.string };
      break;
    }
  }


  try {
    delete_k8sdispatcher_natting_table_by_id(unique_name, unique_internalSrc, unique_internalDst, unique_internalSport, unique_internalDport, unique_proto);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response delete_k8sdispatcher_natting_table_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {
    delete_k8sdispatcher_natting_table_list_by_id(unique_name);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response delete_k8sdispatcher_ports_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_portsName;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "ports_name")) {
      unique_portsName = std::string { keys[i].value.string };
      break;
    }
  }


  try {
    delete_k8sdispatcher_ports_by_id(unique_name, unique_portsName);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response delete_k8sdispatcher_ports_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {
    delete_k8sdispatcher_ports_list_by_id(unique_name);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_k8sdispatcher_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {

    auto x = read_k8sdispatcher_by_id(unique_name);
    nlohmann::json response_body;
    response_body = x.toJson();
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_k8sdispatcher_client_subnet_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {

    auto x = read_k8sdispatcher_client_subnet_by_id(unique_name);
    nlohmann::json response_body;
    response_body = x;
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_k8sdispatcher_cluster_ip_subnet_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {

    auto x = read_k8sdispatcher_cluster_ip_subnet_by_id(unique_name);
    nlohmann::json response_body;
    response_body = x;
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_k8sdispatcher_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {


  try {

    auto x = read_k8sdispatcher_list_by_id();
    nlohmann::json response_body;
    for (auto &i : x) {
      response_body += i.toJson();
    }
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_k8sdispatcher_natting_table_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_internalSrc;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-src")) {
      unique_internalSrc = std::string { keys[i].value.string };
      break;
    }
  }

  std::string unique_internalDst;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dst")) {
      unique_internalDst = std::string { keys[i].value.string };
      break;
    }
  }

  uint16_t unique_internalSport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-sport")) {
      unique_internalSport = keys[i].value.uint16;
      break;
    }
  }

  uint16_t unique_internalDport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dport")) {
      unique_internalDport = keys[i].value.uint16;
      break;
    }
  }

  std::string unique_proto;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "proto")) {
      unique_proto = std::string { keys[i].value.string };
      break;
    }
  }


  try {

    auto x = read_k8sdispatcher_natting_table_by_id(unique_name, unique_internalSrc, unique_internalDst, unique_internalSport, unique_internalDport, unique_proto);
    nlohmann::json response_body;
    response_body = x.toJson();
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_k8sdispatcher_natting_table_external_ip_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_internalSrc;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-src")) {
      unique_internalSrc = std::string { keys[i].value.string };
      break;
    }
  }

  std::string unique_internalDst;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dst")) {
      unique_internalDst = std::string { keys[i].value.string };
      break;
    }
  }

  uint16_t unique_internalSport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-sport")) {
      unique_internalSport = keys[i].value.uint16;
      break;
    }
  }

  uint16_t unique_internalDport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dport")) {
      unique_internalDport = keys[i].value.uint16;
      break;
    }
  }

  std::string unique_proto;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "proto")) {
      unique_proto = std::string { keys[i].value.string };
      break;
    }
  }


  try {

    auto x = read_k8sdispatcher_natting_table_external_ip_by_id(unique_name, unique_internalSrc, unique_internalDst, unique_internalSport, unique_internalDport, unique_proto);
    nlohmann::json response_body;
    response_body = x;
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_k8sdispatcher_natting_table_external_port_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_internalSrc;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-src")) {
      unique_internalSrc = std::string { keys[i].value.string };
      break;
    }
  }

  std::string unique_internalDst;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dst")) {
      unique_internalDst = std::string { keys[i].value.string };
      break;
    }
  }

  uint16_t unique_internalSport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-sport")) {
      unique_internalSport = keys[i].value.uint16;
      break;
    }
  }

  uint16_t unique_internalDport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dport")) {
      unique_internalDport = keys[i].value.uint16;
      break;
    }
  }

  std::string unique_proto;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "proto")) {
      unique_proto = std::string { keys[i].value.string };
      break;
    }
  }


  try {

    auto x = read_k8sdispatcher_natting_table_external_port_by_id(unique_name, unique_internalSrc, unique_internalDst, unique_internalSport, unique_internalDport, unique_proto);
    nlohmann::json response_body;
    response_body = x;
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_k8sdispatcher_natting_table_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {

    auto x = read_k8sdispatcher_natting_table_list_by_id(unique_name);
    nlohmann::json response_body;
    for (auto &i : x) {
      response_body += i.toJson();
    }
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_k8sdispatcher_nodeport_range_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {

    auto x = read_k8sdispatcher_nodeport_range_by_id(unique_name);
    nlohmann::json response_body;
    response_body = x;
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_k8sdispatcher_ports_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_portsName;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "ports_name")) {
      unique_portsName = std::string { keys[i].value.string };
      break;
    }
  }


  try {

    auto x = read_k8sdispatcher_ports_by_id(unique_name, unique_portsName);
    nlohmann::json response_body;
    response_body = x.toJson();
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_k8sdispatcher_ports_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {

    auto x = read_k8sdispatcher_ports_list_by_id(unique_name);
    nlohmann::json response_body;
    for (auto &i : x) {
      response_body += i.toJson();
    }
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_k8sdispatcher_ports_type_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_portsName;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "ports_name")) {
      unique_portsName = std::string { keys[i].value.string };
      break;
    }
  }


  try {

    auto x = read_k8sdispatcher_ports_type_by_id(unique_name, unique_portsName);
    nlohmann::json response_body;
    response_body = PortsJsonObject::PortsTypeEnum_to_string(x);
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_k8sdispatcher_virtual_client_subnet_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {

    auto x = read_k8sdispatcher_virtual_client_subnet_by_id(unique_name);
    nlohmann::json response_body;
    response_body = x;
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response replace_k8sdispatcher_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    K8sdispatcherJsonObject unique_value { request_body };

    unique_value.setName(unique_name);
    replace_k8sdispatcher_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response replace_k8sdispatcher_natting_table_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_internalSrc;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-src")) {
      unique_internalSrc = std::string { keys[i].value.string };
      break;
    }
  }

  std::string unique_internalDst;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dst")) {
      unique_internalDst = std::string { keys[i].value.string };
      break;
    }
  }

  uint16_t unique_internalSport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-sport")) {
      unique_internalSport = keys[i].value.uint16;
      break;
    }
  }

  uint16_t unique_internalDport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dport")) {
      unique_internalDport = keys[i].value.uint16;
      break;
    }
  }

  std::string unique_proto;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "proto")) {
      unique_proto = std::string { keys[i].value.string };
      break;
    }
  }


  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    NattingTableJsonObject unique_value { request_body };

    unique_value.setInternalSrc(unique_internalSrc);
    unique_value.setInternalDst(unique_internalDst);
    unique_value.setInternalSport(unique_internalSport);
    unique_value.setInternalDport(unique_internalDport);
    unique_value.setProto(unique_proto);
    replace_k8sdispatcher_natting_table_by_id(unique_name, unique_internalSrc, unique_internalDst, unique_internalSport, unique_internalDport, unique_proto, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response replace_k8sdispatcher_natting_table_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  // Getting the body param
  std::vector<NattingTableJsonObject> unique_value;

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    std::vector<NattingTableJsonObject> unique_value;
    for (auto &j : request_body) {
      NattingTableJsonObject a { j };
      unique_value.push_back(a);
    }
    replace_k8sdispatcher_natting_table_list_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response replace_k8sdispatcher_ports_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_portsName;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "ports_name")) {
      unique_portsName = std::string { keys[i].value.string };
      break;
    }
  }


  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    PortsJsonObject unique_value { request_body };

    unique_value.setName(unique_portsName);
    replace_k8sdispatcher_ports_by_id(unique_name, unique_portsName, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response replace_k8sdispatcher_ports_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  // Getting the body param
  std::vector<PortsJsonObject> unique_value;

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    std::vector<PortsJsonObject> unique_value;
    for (auto &j : request_body) {
      PortsJsonObject a { j };
      unique_value.push_back(a);
    }
    replace_k8sdispatcher_ports_list_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_k8sdispatcher_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    K8sdispatcherJsonObject unique_value { request_body };

    unique_value.setName(unique_name);
    update_k8sdispatcher_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_k8sdispatcher_client_subnet_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // The conversion is done automatically by the json library
    std::string unique_value = request_body;
    update_k8sdispatcher_client_subnet_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_k8sdispatcher_cluster_ip_subnet_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // The conversion is done automatically by the json library
    std::string unique_value = request_body;
    update_k8sdispatcher_cluster_ip_subnet_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_k8sdispatcher_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {

  // Getting the body param
  std::vector<K8sdispatcherJsonObject> unique_value;

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    std::vector<K8sdispatcherJsonObject> unique_value;
    for (auto &j : request_body) {
      K8sdispatcherJsonObject a { j };
      unique_value.push_back(a);
    }
    update_k8sdispatcher_list_by_id(unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_k8sdispatcher_natting_table_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_internalSrc;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-src")) {
      unique_internalSrc = std::string { keys[i].value.string };
      break;
    }
  }

  std::string unique_internalDst;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dst")) {
      unique_internalDst = std::string { keys[i].value.string };
      break;
    }
  }

  uint16_t unique_internalSport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-sport")) {
      unique_internalSport = keys[i].value.uint16;
      break;
    }
  }

  uint16_t unique_internalDport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dport")) {
      unique_internalDport = keys[i].value.uint16;
      break;
    }
  }

  std::string unique_proto;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "proto")) {
      unique_proto = std::string { keys[i].value.string };
      break;
    }
  }


  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    NattingTableJsonObject unique_value { request_body };

    unique_value.setInternalSrc(unique_internalSrc);
    unique_value.setInternalDst(unique_internalDst);
    unique_value.setInternalSport(unique_internalSport);
    unique_value.setInternalDport(unique_internalDport);
    unique_value.setProto(unique_proto);
    update_k8sdispatcher_natting_table_by_id(unique_name, unique_internalSrc, unique_internalDst, unique_internalSport, unique_internalDport, unique_proto, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_k8sdispatcher_natting_table_external_ip_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_internalSrc;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-src")) {
      unique_internalSrc = std::string { keys[i].value.string };
      break;
    }
  }

  std::string unique_internalDst;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dst")) {
      unique_internalDst = std::string { keys[i].value.string };
      break;
    }
  }

  uint16_t unique_internalSport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-sport")) {
      unique_internalSport = keys[i].value.uint16;
      break;
    }
  }

  uint16_t unique_internalDport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dport")) {
      unique_internalDport = keys[i].value.uint16;
      break;
    }
  }

  std::string unique_proto;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "proto")) {
      unique_proto = std::string { keys[i].value.string };
      break;
    }
  }


  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // The conversion is done automatically by the json library
    std::string unique_value = request_body;
    update_k8sdispatcher_natting_table_external_ip_by_id(unique_name, unique_internalSrc, unique_internalDst, unique_internalSport, unique_internalDport, unique_proto, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_k8sdispatcher_natting_table_external_port_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_internalSrc;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-src")) {
      unique_internalSrc = std::string { keys[i].value.string };
      break;
    }
  }

  std::string unique_internalDst;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dst")) {
      unique_internalDst = std::string { keys[i].value.string };
      break;
    }
  }

  uint16_t unique_internalSport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-sport")) {
      unique_internalSport = keys[i].value.uint16;
      break;
    }
  }

  uint16_t unique_internalDport;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "internal-dport")) {
      unique_internalDport = keys[i].value.uint16;
      break;
    }
  }

  std::string unique_proto;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "proto")) {
      unique_proto = std::string { keys[i].value.string };
      break;
    }
  }


  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // The conversion is done automatically by the json library
    uint16_t unique_value = request_body;
    update_k8sdispatcher_natting_table_external_port_by_id(unique_name, unique_internalSrc, unique_internalDst, unique_internalSport, unique_internalDport, unique_proto, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_k8sdispatcher_natting_table_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  // Getting the body param
  std::vector<NattingTableJsonObject> unique_value;

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    std::vector<NattingTableJsonObject> unique_value;
    for (auto &j : request_body) {
      NattingTableJsonObject a { j };
      unique_value.push_back(a);
    }
    update_k8sdispatcher_natting_table_list_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_k8sdispatcher_nodeport_range_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // The conversion is done automatically by the json library
    std::string unique_value = request_body;
    update_k8sdispatcher_nodeport_range_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_k8sdispatcher_ports_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_portsName;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "ports_name")) {
      unique_portsName = std::string { keys[i].value.string };
      break;
    }
  }


  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    PortsJsonObject unique_value { request_body };

    unique_value.setName(unique_portsName);
    update_k8sdispatcher_ports_by_id(unique_name, unique_portsName, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_k8sdispatcher_ports_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  // Getting the body param
  std::vector<PortsJsonObject> unique_value;

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    std::vector<PortsJsonObject> unique_value;
    for (auto &j : request_body) {
      PortsJsonObject a { j };
      unique_value.push_back(a);
    }
    update_k8sdispatcher_ports_list_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_k8sdispatcher_ports_type_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_portsName;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "ports_name")) {
      unique_portsName = std::string { keys[i].value.string };
      break;
    }
  }


  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    PortsTypeEnum unique_value_ = PortsJsonObject::string_to_PortsTypeEnum(request_body);
    update_k8sdispatcher_ports_type_by_id(unique_name, unique_portsName, unique_value_);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_k8sdispatcher_virtual_client_subnet_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // The conversion is done automatically by the json library
    std::string unique_value = request_body;
    update_k8sdispatcher_virtual_client_subnet_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}


Response k8sdispatcher_list_by_id_help(
  const char *name, const Key *keys, size_t num_keys) {

  nlohmann::json val = read_k8sdispatcher_list_by_id_get_list();

  return { kOk, ::strdup(val.dump().c_str()) };
}

Response k8sdispatcher_natting_table_list_by_id_help(
  const char *name, const Key *keys, size_t num_keys) {
  // Getting the path params
  std::string unique_name { name };
  nlohmann::json val = read_k8sdispatcher_natting_table_list_by_id_get_list(unique_name);

  return { kOk, ::strdup(val.dump().c_str()) };
}

Response k8sdispatcher_ports_list_by_id_help(
  const char *name, const Key *keys, size_t num_keys) {
  // Getting the path params
  std::string unique_name { name };
  nlohmann::json val = read_k8sdispatcher_ports_list_by_id_get_list(unique_name);

  return { kOk, ::strdup(val.dump().c_str()) };
}

#ifdef __cplusplus
}
#endif

