// Copyright 2019 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SYSTEM_API_DBUS_PATCHPANEL_DBUS_CONSTANTS_H_
#define SYSTEM_API_DBUS_PATCHPANEL_DBUS_CONSTANTS_H_

namespace patchpanel {

// Patchpanel main D-Bus service constants.
constexpr char kPatchPanelInterface[] = "org.chromium.PatchPanel";
constexpr char kPatchPanelServicePath[] = "/org/chromium/PatchPanel";
constexpr char kPatchPanelServiceName[] = "org.chromium.PatchPanel";

// Exported methods.
constexpr char kArcShutdownMethod[] = "ArcShutdown";
constexpr char kArcStartupMethod[] = "ArcStartup";
constexpr char kArcVmShutdownMethod[] = "ArcVmShutdown";
constexpr char kArcVmStartupMethod[] = "ArcVmStartup";
constexpr char kConnectNamespaceMethod[] = "ConnectNamespace";
constexpr char kCreateLocalOnlyNetworkMethod[] = "CreateLocalOnlyNetwork";
constexpr char kCreateTetheredNetworkMethod[] = "CreateTetheredNetwork";
constexpr char kConfigureNetworkMethod[] = "ConfigureNetwork";
constexpr char kGetDevicesMethod[] = "GetDevices";
constexpr char kGetDownstreamNetworkInfoMethod[] = "GetDownstreamNetworkInfo";
constexpr char kGetTrafficCountersMethod[] = "GetTrafficCounters";
constexpr char kModifyPortRuleMethod[] = "ModifyPortRule";
constexpr char kParallelsVmShutdownMethod[] = "ParallelsVmShutdown";
constexpr char kParallelsVmStartupMethod[] = "ParallelsVmStartup";
constexpr char kNotifyAndroidInteractiveStateMethod[] =
    "NotifyAndroidInteractiveState";
constexpr char kNotifyAndroidWifiMulticastLockChangeMethod[] =
    "NotifyAndroidWifiMulticastLockChange";
constexpr char kNotifySocketConnectionEventMethod[] =
    "NotifySocketConnectionEvent";
constexpr char kNotifyARCVPNSocketConnectionEventMethod[] =
    "NotifyARCVPNSocketConnectionEvent";
constexpr char kSetDnsRedirectionRuleMethod[] = "SetDnsRedirectionRule";
constexpr char kSetFeatureFlagMethod[] = "SetFeatureFlag";
constexpr char kSetVpnLockdown[] = "SetVpnLockdown";
constexpr char kTagSocketMethod[] = "TagSocket";
constexpr char kTerminaVmShutdownMethod[] = "TerminaVmShutdown";
constexpr char kTerminaVmStartupMethod[] = "TerminaVmStartup";

// Signals.
constexpr char kNetworkDeviceChangedSignal[] = "NetworkDeviceChanged";
constexpr char kNetworkConfigurationChangedSignal[] =
    "NetworkConfigurationChanged";
constexpr char kNeighborReachabilityEventSignal[] = "NeighborReachabilityEvent";

// Socket service, secondary D-Bus service constants.
constexpr char kSocketServiceInterface[] = "org.chromium.SocketService";
constexpr char kSocketServicePath[] = "/org/chromium/SocketService";
constexpr char kSocketServiceName[] = "org.chromium.SocketService";
}  // namespace patchpanel

#endif  // SYSTEM_API_DBUS_PATCHPANEL_DBUS_CONSTANTS_H_
