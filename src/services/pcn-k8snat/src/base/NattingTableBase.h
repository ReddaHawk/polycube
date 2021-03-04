/**
* k8snat API generated from k8snat.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */

/*
* NattingTableBase.h
*
*
*/

#pragma once

#include "../serializer/NattingTableJsonObject.h"






#include <spdlog/spdlog.h>

using namespace polycube::service::model;

class K8snat;

class NattingTableBase {
 public:
  
  NattingTableBase(K8snat &parent);
  
  virtual ~NattingTableBase();
  virtual void update(const NattingTableJsonObject &conf);
  virtual NattingTableJsonObject toJsonObject();

  /// <summary>
  /// Source IP address
  /// </summary>
  virtual std::string getInternalSrc() = 0;

  /// <summary>
  /// Destination IP address
  /// </summary>
  virtual std::string getInternalDst() = 0;

  /// <summary>
  /// Source L4 port number
  /// </summary>
  virtual uint16_t getInternalSport() = 0;

  /// <summary>
  /// Destination L4 port number
  /// </summary>
  virtual uint16_t getInternalDport() = 0;

  /// <summary>
  /// L4 protocol
  /// </summary>
  virtual std::string getProto() = 0;

  /// <summary>
  /// The set of rules that created this mapping
  /// </summary>
  virtual NattingTableOriginatingRuleEnum getOriginatingRule() = 0;
  virtual void setOriginatingRule(const NattingTableOriginatingRuleEnum &value) = 0;

  /// <summary>
  /// Translated IP address
  /// </summary>
  virtual std::string getExternalIp() = 0;
  virtual void setExternalIp(const std::string &value) = 0;

  /// <summary>
  /// Translated L4 port number
  /// </summary>
  virtual uint16_t getExternalPort() = 0;
  virtual void setExternalPort(const uint16_t &value) = 0;

  std::shared_ptr<spdlog::logger> logger();
 protected:
  K8snat &parent_;
};
