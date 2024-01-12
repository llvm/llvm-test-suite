#pragma once
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include "hipUtils.h"
#include <vector>

template <typename T> class DeviceArray {
public:
  // Default constructor
  DeviceArray() : DeviceData(nullptr) {}

  // Constructor to initialize both host and device data
  DeviceArray(size_t N) : HostData(N), DeviceData(nullptr) {
    checkHIP(hipMalloc((void **)&DeviceData, N * sizeof(T)),
             "Unable to allocate device memory");
  }

  // Destructor to free device memory
  ~DeviceArray() { (void)hipFree(DeviceData); }

  // Copy data from host to device
  void toDevice() {
    checkHIP(hipMemcpy(DeviceData, HostData.data(), HostData.size() * sizeof(T),
                       hipMemcpyHostToDevice),
             "Unable to copy data from host to device");
  }

  // Copy data from device to host
  void toHost() {
    checkHIP(hipMemcpy(HostData.data(), DeviceData, HostData.size() * sizeof(T),
                       hipMemcpyDeviceToHost),
             "Unable to copy data from device to host");
  }

  // Resize the array
  void resize(size_t N) {
    size_t oldSize = HostData.size();
    HostData.resize(N);

    T *newDeviceData;
    checkHIP(hipMalloc((void **)&newDeviceData, N * sizeof(T)),
             "Unable to allocate new device memory during resize");

    if (DeviceData && oldSize > 0) {
      size_t copySize = std::min(oldSize, N) * sizeof(T);
      checkHIP(hipMemcpy(newDeviceData, DeviceData, copySize,
                         hipMemcpyDeviceToDevice),
               "Unable to copy data within device during resize");
      hipFree(DeviceData);
    }

    DeviceData = newDeviceData;
  }

  // Get pointer to host data
  T *getHostPtr() { return HostData.data(); }

  // Get pointer to device data
  T *getDevicePtr() { return DeviceData; }

private:
  std::vector<T> HostData; // Host data
  T *DeviceData;           // Pointer to device data
};
