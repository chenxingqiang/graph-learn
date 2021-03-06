/* Copyright 2020 Alibaba Group Holding Limited. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include <float.h>
#include "graphlearn/core/operator/aggregator/aggregator.h"

namespace graphlearn {
namespace op {

class MaxAggregator : public Aggregator {
public:
  virtual ~MaxAggregator() {}

  void InitFunc(std::vector<float>* value, int32_t size) override {
    value->assign(size, FLT_MIN_10_EXP);
  }

  void AggFunc(std::vector<float>* left,
               const std::vector<float>& right) override {
    for (int32_t i = 0; i < left->size(); ++i) {
      left->at(i) = std::max(left->at(i), right[i]);
    }
  }
};

REGISTER_OPERATOR("MaxAggregator", MaxAggregator);

}  // namespace op
}  // namespace graphlearn
