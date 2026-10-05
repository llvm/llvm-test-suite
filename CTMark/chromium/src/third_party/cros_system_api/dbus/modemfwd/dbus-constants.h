// Copyright 2022 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SYSTEM_API_DBUS_MODEMFWD_DBUS_CONSTANTS_H_
#define SYSTEM_API_DBUS_MODEMFWD_DBUS_CONSTANTS_H_

namespace modemfwd {

const char kModemfwdInterface[] = "org.chromium.Modemfwd";
const char kModemfwdServicePath[] = "/org/chromium/Modemfwd";
const char kModemfwdServiceName[] = "org.chromium.Modemfwd";

// Methods.
const char kSetDebugMode[] = "SetDebugMode";

// Properties.
const char kInProgressTasksProperty[] = "InProgressTasks";
// keys used in InProgressTasks
const char kTaskName[] = "name";
const char kTaskType[] = "type";
const char kTaskTypeHeartbeat[] = "heartbeat";
const char kTaskTypeFlash[] = "flash";
const char kTaskStartedAt[] = "started-at";
const char kFlashTaskForceFlash[] = "force-flash";
const char kFlashTaskCarrierOverride[] = "carrier-override";
const char kFlashTaskDeviceId[] = "device-id";
const char kFlashTaskFlashOngoing[] = "flash-ongoing";

// error result codes.
const char kErrorResultFailure[] = "org.chromium.Modemfwd.Error.Failure";
const char kErrorResultInitFailure[] =
    "org.chromium.Modemfwd.Error.InitFailure";
const char kErrorResultInitFailureNonLteSku[] =
    "org.chromium.Modemfwd.Error.InitFailureNonLteSku";
const char kErrorResultInitManifestFailure[] =
    "org.chromium.Modemfwd.Error.InitManifestFailure";
const char kErrorResultInitJournalFailure[] =
    "org.chromium.Modemfwd.Error.InitJournalFailure";
const char kErrorResultFailedToPrepareFirmwareFile[] =
    "org.chromium.Modemfwd.Error.FailedToPrepareFirmwareFile";
const char kErrorResultFailureReturnedByHelper[] =
    "org.chromium.Modemfwd.Error.FailureReturnedByHelper";
const char kErrorResultFailureReturnedByHelperModemNeverSeen[] =
    "org.chromium.Modemfwd.Error.FailureReturnedByHelperModemNeverSeen";
const char kErrorResultFlashFailure[] =
    "org.chromium.Modemfwd.Error.FlashFailure";

}  // namespace modemfwd

#endif  // SYSTEM_API_DBUS_MODEMFWD_DBUS_CONSTANTS_H_
