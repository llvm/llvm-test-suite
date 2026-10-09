// Copyright 2018 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SYSTEM_API_DBUS_VM_CICERONE_DBUS_CONSTANTS_H_
#define SYSTEM_API_DBUS_VM_CICERONE_DBUS_CONSTANTS_H_

namespace vm_tools {
namespace cicerone {

const char kVmCiceroneInterface[] = "org.chromium.VmCicerone";
const char kVmCiceroneServicePath[] = "/org/chromium/VmCicerone";
const char kVmCiceroneServiceName[] = "org.chromium.VmCicerone";

// LINT.IfChange
// Methods to be called from vm_concierge.
// keep-sorted start
const char kGetContainerTokenMethod[] = "GetContainerToken";
const char kNotifyVmStartedMethod[] = "NotifyVmStarted";
const char kNotifyVmStoppedMethod[] = "NotifyVmStopped";
const char kNotifyVmStoppingMethod[] = "NotifyVmStopping";
// keep-sorted end

// Methods to be called from Chrome.
// keep-sorted start
const char kAddFileWatchMethod[] = "AddFileWatch";
const char kApplyAnsiblePlaybookMethod[] = "ApplyAnsiblePlaybook";
const char kAttachUsbToContainerMethod[] = "AttachUsbToContainer";
const char kCancelExportLxdContainerMethod[] = "CancelExportLxdContainer";
const char kCancelImportLxdContainerMethod[] = "CancelImportLxdContainer";
const char kConfigureForArcSideloadMethod[] = "ConfigureForArcSideload";
const char kCreateLxdContainerMethod[] = "CreateLxdContainer";
const char kDeleteLxdContainerMethod[] = "DeleteLxdContainer";
const char kDetachUsbFromContainerMethod[] = "DetachUsbFromContainer";
const char kExportLxdContainerMethod[] = "ExportLxdContainer";
const char kFileSelectedMethod[] = "FileSelected";
const char kGetContainerAppIconMethod[] = "GetContainerAppIcon";
const char kGetGarconSessionInfoMethod[] = "GetGarconSessionInfo";
const char kGetLinuxPackageInfoMethod[] = "GetLinuxPackageInfo";
const char kGetLxdContainerUsernameMethod[] = "GetLxdContainerUsername";
const char kGetVshSessionMethod[] = "GetVshSession";
const char kImportLxdContainerMethod[] = "ImportLxdContainer";
const char kInstallLinuxPackageMethod[] = "InstallLinuxPackage";
const char kLaunchContainerApplicationMethod[] = "LaunchContainerApplication";
const char kLaunchVshdMethod[] = "LaunchVshd";
const char kListRunningContainersMethod[] = "ListRunningContainers";
const char kRegisterVshSessionMethod[] = "RegisterVshSession";
const char kRemoveFileWatchMethod[] = "RemoveFileWatch";
const char kSetTimezoneMethod[] = "SetTimezone";
const char kSetUpLxdContainerUserMethod[] = "SetUpLxdContainerUser";
const char kStartLxdContainerMethod[] = "StartLxdContainer";
const char kStartLxdMethod[] = "StartLxd";
const char kStopLxdContainerMethod[] = "StopLxdContainer";
const char kUninstallPackageOwningFileMethod[] = "UninstallPackageOwningFile";
const char kUpdateContainerDevicesMethod[] = "UpdateContainerDevices";
// keep-sorted end

// Methods to be called from chunneld.
const char kConnectChunnelMethod[] = "ConnectChunnel";

// Methods to be called from debugd.
const char kGetDebugInformationMethod[] = "GetDebugInformation";

// Signals.
// keep-sorted start
const char kApplyAnsiblePlaybookProgressSignal[] =
    "ApplyAnsiblePlaybookProgress";
const char kContainerShutdownSignal[] = "ContainerShutdown";
const char kContainerStartedSignal[] = "ContainerStarted";
const char kExportLxdContainerProgressSignal[] = "ExportLxdContainerProgress";
const char kFileWatchTriggeredSignal[] = "FileWatchTriggered";
const char kImportLxdContainerProgressSignal[] = "ImportLxdContainerProgress";
const char kInhibitScreensaverSignal[] = "InhibitScreensaver";
const char kInstallLinuxPackageProgressSignal[] = "InstallLinuxPackageProgress";
const char kLowDiskSpaceTriggeredSignal[] = "LowDiskSpaceTriggered";
const char kLxdContainerCreatedSignal[] = "LxdContainerCreated";
const char kLxdContainerDeletedSignal[] = "LxdContainerDeleted";
const char kLxdContainerDownloadingSignal[] = "LxdContainerDownloading";
const char kLxdContainerStartingSignal[] = "LxdContainerStarting";
const char kLxdContainerStoppingSignal[] = "LxdContainerStopping";
const char kPendingAppListUpdatesSignal[] = "PendingAppListUpdates";
const char kStartLxdProgressSignal[] = "StartLxdProgress";
const char kTremplinStartedSignal[] = "TremplinStarted";
const char kUninhibitScreensaverSignal[] = "UninhibitScreensaver";
const char kUninstallPackageProgressSignal[] = "UninstallPackageProgress";
// keep-sorted end
// LINT.ThenChange(/vm_tools/dbus_bindings/org.chromium.VmCicerone.xml)

}  // namespace cicerone
}  // namespace vm_tools

#endif  // SYSTEM_API_DBUS_VM_CICERONE_DBUS_CONSTANTS_H_
