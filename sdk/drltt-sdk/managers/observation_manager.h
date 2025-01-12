#pragma once

#include <iostream>
#include "common/geometry.h"
#include "drltt-sdk/dynamics_models/base_dynamics_model.h"
#include "drltt_proto/dynamics_model/state.pb.h"
#include "drltt_proto/trajectory/trajectory.pb.h"

namespace drltt {

class ObservationManager {
 public:
  ObservationManager() = default;
  ~ObservationManager() {};
  bool reset(drltt_proto::ReferenceLine* reference_line_ptr,
             BaseDynamicsModel* dynamics_model_ptr);
  // TODO: remove index and window
  bool get_observation(const drltt_proto::BodyState& body_state,
                       int start_index, int n_observation_steps,
                       std::vector<float>* observation);

 private:
  bool get_reference_line_observation(const drltt_proto::BodyState& body_state,
                                      int start_index, int n_observation_steps,
                                      std::vector<float>* observation);
  const drltt_proto::ReferenceLine* _reference_line_ptr;
  const BaseDynamicsModel* _dynamics_model_ptr;
};

}  // namespace drltt
