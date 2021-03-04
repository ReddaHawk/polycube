/**
* k8snat API generated from k8snat.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */

/*
* RuleDnatEntryBase.h
*
*
*/

#pragma once

#include "../serializer/RuleDnatEntryJsonObject.h"






#include <spdlog/spdlog.h>

using namespace polycube::service::model;

class RuleDnat;

class RuleDnatEntryBase {
 public:
  
  RuleDnatEntryBase(RuleDnat &parent);
  
  virtual ~RuleDnatEntryBase();
  virtual void update(const RuleDnatEntryJsonObject &conf);
  virtual RuleDnatEntryJsonObject toJsonObject();

  /// <summary>
  /// Rule identifier
  /// </summary>
  virtual uint32_t getId() = 0;

  /// <summary>
  /// External destination IP address
  /// </summary>
  virtual std::string getExternalIp() = 0;
  virtual void setExternalIp(const std::string &value) = 0;

  /// <summary>
  /// Internal destination IP address
  /// </summary>
  virtual std::string getInternalIp() = 0;
  virtual void setInternalIp(const std::string &value) = 0;

  std::shared_ptr<spdlog::logger> logger();
 protected:
  RuleDnat &parent_;
};
