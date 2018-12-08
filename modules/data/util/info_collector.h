/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include <memory>
#include <string>

#include "cyber/common/macros.h"
#include "cyber/cyber.h"
#include "modules/data/proto/static_info.pb.h"

/**
 * @namespace apollo::data
 * @brief apollo::data
 */
namespace apollo {
namespace data {

class InfoCollector {
 public:
  static void Init(const std::shared_ptr<apollo::cyber::Node>& node);
  // Get task information.
  static const StaticInfo &GetStaticInfo();

  // Get specific information.
  // Listening topics: ChassisDetail.
  static const VehicleInfo &GetVehicleInfo();
  static const EnvironmentInfo &GetEnvironmentInfo();
  static const HardwareInfo &GetHardwareInfo();
  static const SoftwareInfo &GetSoftwareInfo();
  static const UserInfo &GetUserInfo();

 private:
  StaticInfo static_info_;
  StaticInfoConf config_;
  std::shared_ptr<cyber::Reader<apollo::routing::RoutingRequest>>
      routing_request_reader_;

  DECLARE_SINGLETON(InfoCollector)
};

}  // namespace data
}  // namespace apollo
