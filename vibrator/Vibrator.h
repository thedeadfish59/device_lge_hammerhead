/*
 * Copyright (C) 2019 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_HARDWARE_VIBRATOR_V1_1_VIBRATOR_H
#define ANDROID_HARDWARE_VIBRATOR_V1_1_VIBRATOR_H

#include <android/hardware/vibrator/1.1/IVibrator.h>
#include <hidl/Status.h>

#include <fstream>

namespace android {
namespace hardware {
namespace vibrator {
namespace V1_1 {
namespace implementation {

using Status = ::android::hardware::vibrator::V1_0::Status;
using EffectStrength = ::android::hardware::vibrator::V1_0::EffectStrength;

class Vibrator : public IVibrator {
public:
  Vibrator(std::ofstream&& enable, std::ofstream&& amplitude);

  // Methods from ::android::hardware::vibrator::V1_0::IVibrator follow.
  Return<Status> on(uint32_t timeoutMs)  override;
  Return<Status> off()  override;
  Return<bool> supportsAmplitudeControl() override;
  Return<Status> setAmplitude(uint8_t amplitude) override;

  Return<void> perform(V1_0::Effect effect, EffectStrength strength, perform_cb _hidl_cb) override;
  Return<void> perform_1_1(V1_1::Effect_1_1 effect, EffectStrength strength, perform_cb _hidl_cb) override;

private:
  std::ofstream mEnable;
  std::ofstream mAmplitude;
};

}  // namespace implementation
}  // namespace V1_1
}  // namespace vibrator
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_VIBRATOR_V1_1_VIBRATOR_H
