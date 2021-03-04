/**
* k8snat API generated from k8snat.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */

/*
* RuleMasqueradeJsonObject.h
*
*
*/

#pragma once


#include "JsonObjectBase.h"


namespace polycube {
namespace service {
namespace model {


/// <summary>
///
/// </summary>
class  RuleMasqueradeJsonObject : public JsonObjectBase {
public:
  RuleMasqueradeJsonObject();
  RuleMasqueradeJsonObject(const nlohmann::json &json);
  ~RuleMasqueradeJsonObject() final = default;
  nlohmann::json toJson() const final;


  /// <summary>
  ///
  /// </summary>
  bool getEnabled() const;
  void setEnabled(bool value);
  bool enabledIsSet() const;
  void unsetEnabled();

private:
  bool m_enabled;
  bool m_enabledIsSet;
};

}
}
}

