/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */

/*
* K8sdispatcherJsonObject.h
*
*
*/

#pragma once


#include "JsonObjectBase.h"

#include "NodeportRuleJsonObject.h"
#include "NattingRuleJsonObject.h"
#include "PortsJsonObject.h"
#include <vector>
#include "polycube/services/cube.h"

namespace polycube {
namespace service {
namespace model {


/// <summary>
///
/// </summary>
class  K8sdispatcherJsonObject : public JsonObjectBase {
public:
  K8sdispatcherJsonObject();
  K8sdispatcherJsonObject(const nlohmann::json &json);
  ~K8sdispatcherJsonObject() final = default;
  nlohmann::json toJson() const final;


  /// <summary>
  /// Name of the k8sdispatcher service
  /// </summary>
  std::string getName() const;
  void setName(std::string value);
  bool nameIsSet() const;

  /// <summary>
  /// Entry of the ports table
  /// </summary>
  const std::vector<PortsJsonObject>& getPorts() const;
  void addPorts(PortsJsonObject value);
  bool portsIsSet() const;
  void unsetPorts();

  /// <summary>
  /// Range of VIPs where clusterIP services are exposed
  /// </summary>
  std::string getClusterIpSubnet() const;
  void setClusterIpSubnet(std::string value);
  bool clusterIpSubnetIsSet() const;
  void unsetClusterIpSubnet();

  /// <summary>
  /// Range of IPs of pods in this node
  /// </summary>
  std::string getClientSubnet() const;
  void setClientSubnet(std::string value);
  bool clientSubnetIsSet() const;
  void unsetClientSubnet();

  /// <summary>
  /// Internal src ip used for services with externaltrafficpolicy&#x3D;cluster
  /// </summary>
  std::string getInternalSrcIp() const;
  void setInternalSrcIp(std::string value);
  bool internalSrcIpIsSet() const;

  /// <summary>
  ///
  /// </summary>
  const std::vector<NattingRuleJsonObject>& getNattingRule() const;
  void addNattingRule(NattingRuleJsonObject value);
  bool nattingRuleIsSet() const;
  void unsetNattingRule();

  /// <summary>
  ///
  /// </summary>
  const std::vector<NodeportRuleJsonObject>& getNodeportRule() const;
  void addNodeportRule(NodeportRuleJsonObject value);
  bool nodeportRuleIsSet() const;
  void unsetNodeportRule();

  /// <summary>
  /// Port range used for NodePort services
  /// </summary>
  std::string getNodeportRange() const;
  void setNodeportRange(std::string value);
  bool nodeportRangeIsSet() const;
  void unsetNodeportRange();

private:
  std::string m_name;
  bool m_nameIsSet;
  std::vector<PortsJsonObject> m_ports;
  bool m_portsIsSet;
  std::string m_clusterIpSubnet;
  bool m_clusterIpSubnetIsSet;
  std::string m_clientSubnet;
  bool m_clientSubnetIsSet;
  std::string m_internalSrcIp;
  bool m_internalSrcIpIsSet;
  std::vector<NattingRuleJsonObject> m_nattingRule;
  bool m_nattingRuleIsSet;
  std::vector<NodeportRuleJsonObject> m_nodeportRule;
  bool m_nodeportRuleIsSet;
  std::string m_nodeportRange;
  bool m_nodeportRangeIsSet;
};

}
}
}

