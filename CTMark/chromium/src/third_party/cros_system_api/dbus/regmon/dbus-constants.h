// Copyright 2024 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SYSTEM_API_DBUS_REGMON_DBUS_CONSTANTS_H_
#define SYSTEM_API_DBUS_REGMON_DBUS_CONSTANTS_H_

namespace regmon {

constexpr char kRegmonServiceInterface[] = "org.chromium.Regmond";
constexpr char kRegmonServicePath[] = "/org/chromium/Regmond";
constexpr char kRegmonServiceName[] = "org.chromium.Regmond";

// Methods exported by regmond.
constexpr char kRecordPolicyViolation[] = "RecordPolicyViolation";

}  // namespace regmon

#endif  // SYSTEM_API_DBUS_REGMON_DBUS_CONSTANTS_H_
