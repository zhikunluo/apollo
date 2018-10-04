/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
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

/**
 * @file
 **/

#include "modules/planning/toolkits/optimizers/proceed_with_caution_speed/proceed_with_caution_speed_generator.h"

#include <algorithm>
#include <string>
#include <utility>
#include <vector>

#include "modules/common/proto/pnc_point.pb.h"

#include "modules/common/configs/vehicle_config_helper.h"
#include "modules/common/util/file.h"
#include "modules/common/vehicle_state/vehicle_state_provider.h"
#include "modules/planning/common/planning_gflags.h"

namespace apollo {
namespace planning {

using apollo::common::ErrorCode;
using apollo::common::Status;
using apollo::common::TrajectoryPoint;
using apollo::planning_internal::STGraphDebug;

ProceedWithCautionSpeedGenerator::ProceedWithCautionSpeedGenerator()
    : SpeedOptimizer("ProceedWithCautionSpeedGenerator") {}

bool ProceedWithCautionSpeedGenerator::Init(
    const ScenarioConfig::ScenarioTaskConfig& config) {
  if (is_init_) {
    AERROR << "Duplicated Init.";
    return false;
  }
  is_init_ = true;
  // TODO(All): Init here
  return true;
}

Status ProceedWithCautionSpeedGenerator::Process(
    const SLBoundary& adc_sl_boundary, const PathData& path_data,
    const TrajectoryPoint& init_point, const ReferenceLine& reference_line,
    const SpeedData& reference_speed_data, PathDecision* const path_decision,
    SpeedData* const speed_data) {
  if (!is_init_) {
    AERROR << "Please call Init() before Process.";
    return Status(ErrorCode::PLANNING_ERROR, "Not init.");
  }

  if (path_data.discretized_path().NumOfPoints() == 0) {
    std::string msg("Empty path data");
    AERROR << msg;
    return Status(ErrorCode::PLANNING_ERROR, msg);
  }

  // TODO(All): implement here.
  return Status::OK();
}

}  // namespace planning
}  // namespace apollo
