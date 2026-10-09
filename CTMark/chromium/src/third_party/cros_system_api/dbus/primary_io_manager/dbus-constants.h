// Copyright 2024 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SYSTEM_API_DBUS_PRIMARY_IO_MANAGER_DBUS_CONSTANTS_H_
#define SYSTEM_API_DBUS_PRIMARY_IO_MANAGER_DBUS_CONSTANTS_H_

namespace primary_io_manager {
const char kPrimaryIoManagerInterface[] = "org.chromium.PrimaryIoManager";
const char kPrimaryIoManagerServicePath[] = "/org/chromium/PrimaryIoManager";
const char kPrimaryIoManagerServiceName[] = "org.chromium.PrimaryIoManager";

// Methods
const char kGetIoDevices[] = "GetIoDevices";
const char kUnsetPrimaryKeyboard[] = "UnsetPrimaryKeyboard";
const char kUnsetPrimaryMouse[] = "UnsetPrimaryMouse";
const char kIsPrimaryIoDevice[] = "IsPrimaryIoDevice";
}  // namespace primary_io_manager

#endif  // SYSTEM_API_DBUS_PRIMARY_IO_MANAGER_DBUS_CONSTANTS_H_
