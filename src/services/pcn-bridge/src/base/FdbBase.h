/**
 * bridge API generated from bridge.yang
 *
 * NOTE: This file is auto generated by polycube-codegen
 * https://github.com/polycube-network/polycube-codegen
 */

/* Do not edit this file manually */

/*
 * FdbBase.h
 *
 *
 */

#pragma once

#include "../serializer/FdbJsonObject.h"

#include "../FdbEntry.h"

#include <spdlog/spdlog.h>

using namespace polycube::service::model;

class Bridge;

class FdbBase {
 public:
  FdbBase(Bridge &parent);

  virtual ~FdbBase();
  virtual void update(const FdbJsonObject &conf);
  virtual FdbJsonObject toJsonObject();

  /// <summary>
  /// Aging time of the filtering database (in seconds)
  /// </summary>
  virtual uint32_t getAgingTime() = 0;
  virtual void setAgingTime(const uint32_t &value) = 0;

  /// <summary>
  /// Entry associated with the filtering database
  /// </summary>
  virtual std::shared_ptr<FdbEntry> getEntry(const uint16_t &vlan,
                                             const std::string &mac) = 0;
  virtual std::vector<std::shared_ptr<FdbEntry>> getEntryList() = 0;
  virtual void addEntry(const uint16_t &vlan, const std::string &mac,
                        const FdbEntryJsonObject &conf) = 0;
  virtual void addEntryList(const std::vector<FdbEntryJsonObject> &conf);
  virtual void replaceEntry(const uint16_t &vlan, const std::string &mac,
                            const FdbEntryJsonObject &conf);
  virtual void delEntry(const uint16_t &vlan, const std::string &mac) = 0;
  virtual void delEntryList();
  virtual void flush() = 0;

  std::shared_ptr<spdlog::logger> logger();

 protected:
  Bridge &parent_;
};
