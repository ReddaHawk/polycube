/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


#pragma once


#include "../base/K8sdispatcherBase.h"
#include <cinttypes>

#include "NattingTable.h"
#include "Ports.h"

using namespace polycube::service::model;

using namespace polycube::service;
/* definitions copied from datapath */
struct dp_k {
  uint32_t mask;
  uint32_t external_ip;
  uint16_t external_port;
  uint8_t proto;
} __attribute__((packed));

struct dp_v {
  uint32_t internal_ip;
  uint16_t internal_port;
  uint8_t entry_type;
} __attribute__((packed));

struct sm_k {
  uint32_t internal_netmask_len;
  uint32_t internal_ip;
} __attribute__((packed));

struct sm_v {
  uint32_t external_ip;
  uint8_t entry_type;
} __attribute__((packed));

class K8sdispatcher : public K8sdispatcherBase {
 public:
  K8sdispatcher(const std::string name, const K8sdispatcherJsonObject &conf);
  virtual ~K8sdispatcher();

  void packet_in(Ports &port,
                 polycube::service::PacketInMetadata &md,
                 const std::vector<uint8_t> &packet) override;

  /// <summary>
  /// Entry of the ports table
  /// </summary>
  std::shared_ptr<Ports> getPorts(const std::string &name) override;
  std::vector<std::shared_ptr<Ports>> getPortsList() override;
  void addPorts(const std::string &name, const PortsJsonObject &conf) override;
  void addPortsList(const std::vector<PortsJsonObject> &conf) override;
  void replacePorts(const std::string &name, const PortsJsonObject &conf) override;
  void delPorts(const std::string &name) override;
  void delPortsList() override;

  /// <summary>
  /// Range of VIPs where clusterIP services are exposed
  /// </summary>
  std::string getClusterIpSubnet() override;
  void setClusterIpSubnet(const std::string &value) override;

  /// <summary>
  /// Range of IPs of pods in this node
  /// </summary>
  std::string getClientSubnet() override;
  void setClientSubnet(const std::string &value) override;

  /// <summary>
  /// Range where client&#39;s IPs are mapped into
  /// </summary>
  std::string getVirtualClientSubnet() override;
  void setVirtualClientSubnet(const std::string &value) override;

  /// <summary>
  ///
  /// </summary>
  std::shared_ptr<NattingTable> getNattingTable(const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto) override;
  std::vector<std::shared_ptr<NattingTable>> getNattingTableList() override;
  void addNattingTable(const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto, const NattingTableJsonObject &conf) override;
  void addNattingTableList(const std::vector<NattingTableJsonObject> &conf) override;
  void replaceNattingTable(const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto, const NattingTableJsonObject &conf) override;
  void delNattingTable(const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto) override;
  void delNattingTableList() override;

  /// <summary>
  /// Port range used for NodePort services
  /// </summary>
  std::string getNodeportRange() override;
  void setNodeportRange(const std::string &value) override;
  void update(const K8sdispatcherJsonObject &conf);
  K8sdispatcherJsonObject toJsonObject();
  void doSetClusterIpSubnet(const std::string &value);
  void doSetClientSubnet(const std::string &value);
  void doSetVirtualClientSubnet(const std::string &value);
  void doSetNodeportRange(const std::string &value);
  void doSetExternalIp(const std::string &value);
  void doSetExternalMac(const std::string &value);
  uint8_t proto_from_string_to_int(const std::string &proto);
  std::string proto_from_int_to_string(const uint8_t proto);


 private:
  std::string nodeport_range_;
  uint16_t nodeport_range_low_;
  uint16_t nodeport_range_high_;

  std::string cluster_ip_cidr_;
  std::string client_cidr_;
  std::string virtual_client_cidr_;

  uint32_t client_subnet_;
  uint32_t client_mask_;

  uint32_t virtual_client_subnet_;
  uint32_t virtual_client_mask_;

  uint32_t cluster_ip_subnet_;
  uint32_t cluster_ip_mask_;

  uint32_t ip_to_dec(const std::string &ip);
  void parse_cidr(const std::string &cidr, uint32_t *subnet, uint32_t *netmask);
  void reloadConfig();
  std::string external_ip_string_;
  uint32_t external_ip_;
  std::string external_mac_string_;
  uint64_t external_mac_ : 48;
  std::string getFlags();
  std::shared_ptr<Ports> getFrontendPort();
  std::shared_ptr<Ports> getBackendPort();

  uint64_t mac_string_to_nbo_uint(const std::string &mac);
};
