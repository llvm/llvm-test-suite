// Copyright 2015 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SYSTEM_API_DBUS_VM_CONCIERGE_DBUS_CONSTANTS_H_
#define SYSTEM_API_DBUS_VM_CONCIERGE_DBUS_CONSTANTS_H_

namespace vm_tools {
namespace concierge {

const char kVmConciergeInterface[] = "org.chromium.VmConcierge";
const char kVmConciergeServicePath[] = "/org/chromium/VmConcierge";
const char kVmConciergeServiceName[] = "org.chromium.VmConcierge";

// LINT.IfChange
// keep-sorted start
const char kAddGroupPermissionMesaMethod[] = "AddGroupPermissionMesa";
const char kAdjustVmMethod[] = "AdjustVm";
const char kAggressiveBalloonMethod[] = "AggressiveBalloon";
const char kArcVmCompleteBootMethod[] = "ArcVmCompleteBoot";
const char kAttachKeyMethod[] = "AttachKey";
const char kAttachNetDeviceMethod[] = "AttachNetDevice";
const char kAttachUsbDeviceMethod[] = "AttachUsbDevice";
const char kCancelDiskImageMethod[] = "CancelDiskImageOperation";
const char kCreateDiskImageMethod[] = "CreateDiskImage";
const char kDestroyDiskImageMethod[] = "DestroyDiskImage";
const char kDetachNetDeviceMethod[] = "DetachNetDevice";
const char kDetachUsbDeviceMethod[] = "DetachUsbDevice";
const char kDiskImageStatusMethod[] = "DiskImageStatus";
const char kExportDiskImageMethod[] = "ExportDiskImage";
const char kGetBaguetteImageUrlMethod[] = "GetBaguetteImageUrl";
const char kGetBalloonInfoMethod[] = "GetBalloonInfo";
const char kGetDnsSettingsMethod[] = "GetDnsSettings";
const char kGetVmEnterpriseReportingInfoMethod[] =
    "GetVmEnterpriseReportingInfo";
const char kGetVmGpuCachePathMethod[] = "GetVmGpuCachePath";
const char kGetVmInfoMethod[] = "GetVmInfo";
const char kGetVmLaunchAllowedMethod[] = "GetVmLaunchAllowed";
const char kGetVmLogsMethod[] = "GetVmLogs";
const char kGetVmMemoryManagementKillsConnectionMethod[] =
    "GetVmMemoryManagementKillsConnection";
const char kImportDiskImageMethod[] = "ImportDiskImage";
const char kInstallPflashMethod[] = "InstallPflash";
const char kListUsbDeviceMethod[] = "ListUsbDevices";
const char kListVmDisksMethod[] = "ListVmDisks";
const char kListVmsMethod[] = "ListVms";
const char kModifyFakePowerConfigMethod[] = "ModifyFakePowerConfig";
const char kMuteVmAudioMethod[] = "MuteVmAudio";
const char kReclaimVmMemoryMethod[] = "ReclaimVmMemory";
const char kResizeDiskImageMethod[] = "ResizeDiskImage";
const char kResumeVmMethod[] = "ResumeVm";
const char kSetBalloonTimerMethod[] = "SetBalloonTimer";
const char kSetCrostiniVmTypeMethod[] = "SetCrostiniVmType";
const char kSetUpVmUserMethod[] = "SetUpVmUser";
const char kSetVmCpuRestrictionMethod[] = "SetVmCpuRestriction";
const char kStartArcVmMethod[] = "StartArcVm";
const char kStartPluginVmMethod[] = "StartPluginVm";
const char kStartVmMethod[] = "StartVm";
const char kStopAllVmsMethod[] = "StopAllVms";
const char kStopVmMethod[] = "StopVm";
const char kStopVmWithoutOwnerIdMethod[] = "StopVmWithoutOwnerId";
const char kSuspendVmMethod[] = "SuspendVm";
const char kSwapVmMethod[] = "SwapVm";
const char kSyncVmTimesMethod[] = "SyncVmTimes";
// keep-sorted end

// keep-sorted start
const char kDiskImageProgressSignal[] = "DiskImageProgress";
const char kDnsSettingsChangedSignal[] = "DnsSettingsChanged";
const char kVmGuestUserlandReadySignal[] = "VmGuestUserlandReadySignal";
const char kVmInstallStateSignal[] = "VmInstallStateSignal";
const char kVmStartedSignal[] = "VmStartedSignal";
const char kVmStartingUpSignal[] = "VmStartingUpSignal";
const char kVmStoppedSignal[] = "VmStoppedSignal";
const char kVmStoppingSignal[] = "VmStoppingSignal";
const char kVmSwappingSignal[] = "VmSwappingSignal";
// keep-sorted end
// LINT.ThenChange(vm_tools/dbus_bindings/org.chromium.VmConcierge.xml)

const char kArcVmName[] = "arcvm";

}  // namespace concierge
}  // namespace vm_tools

#endif  // SYSTEM_API_DBUS_VM_CONCIERGE_DBUS_CONSTANTS_H_
