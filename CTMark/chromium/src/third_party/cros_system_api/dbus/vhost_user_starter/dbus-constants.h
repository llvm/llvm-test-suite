// Copyright 2024 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SYSTEM_API_DBUS_VHOST_USER_STARTER_DBUS_CONSTANTS_H_
#define SYSTEM_API_DBUS_VHOST_USER_STARTER_DBUS_CONSTANTS_H_

namespace vm_tools::vhost_user_starter {

inline const char kVhostUserStarterInterface[] =
    "org.chromium.VhostUserStarter";
inline const char kVhostUserStarterPath[] = "/org/chromium/VhostUserStarter";
inline const char kVhostUserStarterName[] = "org.chromium.VhostUserStarter";

inline const char kStartVhostUserFsMethod[] = "StartVhostUserFs";

}  // namespace vm_tools::vhost_user_starter

#endif  // SYSTEM_API_DBUS_VHOST_USER_STARTER_DBUS_CONSTANTS_H_
