// Copyright 2015 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SYSTEM_API_DBUS_SHILL_DBUS_CONSTANTS_H_
#define SYSTEM_API_DBUS_SHILL_DBUS_CONSTANTS_H_

// TODO(benchan): Reorganize shill constants and remove deprecated ones.
namespace shill {
// Flimflam D-Bus service identifiers.
constexpr char kFlimflamManagerInterface[] = "org.chromium.flimflam.Manager";
constexpr char kFlimflamServiceName[] = "org.chromium.flimflam";
constexpr char kFlimflamServicePath[] = "/";  // crosbug.com/20135
constexpr char kFlimflamServiceInterface[] = "org.chromium.flimflam.Service";
constexpr char kFlimflamIPConfigInterface[] = "org.chromium.flimflam.IPConfig";
constexpr char kFlimflamDeviceInterface[] = "org.chromium.flimflam.Device";
constexpr char kFlimflamProfileInterface[] = "org.chromium.flimflam.Profile";
constexpr char kFlimflamThirdPartyVpnInterface[] =
    "org.chromium.flimflam.ThirdPartyVpn";

// Common function names.
constexpr char kGetPropertiesFunction[] = "GetProperties";
constexpr char kSetPropertyFunction[] = "SetProperty";
constexpr char kClearPropertyFunction[] = "ClearProperty";

// Manager function names.
constexpr char kConfigureServiceFunction[] = "ConfigureService";
constexpr char kConfigureServiceForProfileFunction[] =
    "ConfigureServiceForProfile";
constexpr char kScanAndConnectToBestServicesFunction[] =
    "ScanAndConnectToBestServices";
constexpr char kCreateConnectivityReportFunction[] = "CreateConnectivityReport";
constexpr char kDisableTechnologyFunction[] = "DisableTechnology";
constexpr char kEnableTechnologyFunction[] = "EnableTechnology";
constexpr char kFindMatchingServiceFunction[] = "FindMatchingService";
constexpr char kGetNetworksForGeolocation[] = "GetNetworksForGeolocation";
constexpr char kGetCellularNetworksForGeolocation[] =
    "GetCellularNetworksForGeolocation";
constexpr char kGetWiFiNetworksForGeolocation[] =
    "GetWiFiNetworksForGeolocation";
constexpr char kGetServiceFunction[] = "GetService";
constexpr char kSetLOHSEnabledFunction[] = "SetLOHSEnabled";
constexpr char kRequestScanFunction[] = "RequestScan";
constexpr char kSetNetworkThrottlingFunction[] = "SetNetworkThrottlingStatus";
constexpr char kSetDNSProxyDOHProvidersFunction[] = "SetDNSProxyDOHProviders";
constexpr char kAddPasspointCredentialsFunction[] = "AddPasspointCredentials";
constexpr char kRemovePasspointCredentialsFunction[] =
    "RemovePasspointCredentials";
constexpr char kSetTetheringEnabledFunction[] = "SetTetheringEnabled";
constexpr char kEnableTetheringFunction[] = "EnableTethering";
constexpr char kDisableTetheringFunction[] = "DisableTethering";
constexpr char kCheckTetheringReadinessFunction[] = "CheckTetheringReadiness";
constexpr char kConnectToP2PGroupFunction[] = "ConnectToP2PGroup";
constexpr char kDisconnectFromP2PGroupFunction[] = "DisconnectFromP2PGroup";
constexpr char kCreateP2PGroupFunction[] = "CreateP2PGroup";
constexpr char kDestroyP2PGroupFunction[] = "DestroyP2PGroup";
constexpr char kTestHostsConnectivityFunction[] = "TestHostsConnectivity";

// TestHostsConnectivity option keys
constexpr char kTestHostsConnectivityProxyKey[] = "proxy";
constexpr char kTestHostsConnectivityTimeoutKey[] = "timeout";
constexpr char kTestHostsConnectivityMaxErrorsKey[] = "max_errors";
// TestHostsConnectivity proxy option values
constexpr char kTestHostsConnectivityProxyDirect[] = "direct";
constexpr char kTestHostsConnectivityProxyDirectUrl[] = "direct://";
constexpr char kTestHostsConnectivityProxySystem[] = "system";

// Service function names.
constexpr char kClearPropertiesFunction[] = "ClearProperties";
constexpr char kCompleteCellularActivationFunction[] =
    "CompleteCellularActivation";
constexpr char kConnectFunction[] = "Connect";
constexpr char kDisconnectFunction[] = "Disconnect";
constexpr char kGetLoadableProfileEntriesFunction[] =
    "GetLoadableProfileEntries";
constexpr char kGetWiFiPassphraseFunction[] = "GetWiFiPassphrase";
constexpr char kGetEapPassphraseFunction[] = "GetEapPassphrase";
constexpr char kRemoveServiceFunction[] = "Remove";
constexpr char kRequestPortalDetectionFunction[] = "RequestPortalDetection";
constexpr char kRequestTrafficCountersFunction[] = "RequestTrafficCounters";
constexpr char kResetTrafficCountersFunction[] = "ResetTrafficCounters";
constexpr char kSetPropertiesFunction[] = "SetProperties";

// IPConfig function names.
constexpr char kRemoveConfigFunction[] = "Remove";

// Device function names.
constexpr char kChangePinFunction[] = "ChangePin";
constexpr char kEnterPinFunction[] = "EnterPin";
constexpr char kRegisterFunction[] = "Register";
constexpr char kRequirePinFunction[] = "RequirePin";
constexpr char kResetFunction[] = "Reset";
constexpr char kSetUsbEthernetMacAddressSourceFunction[] =
    "SetUsbEthernetMacAddressSource";
constexpr char kUnblockPinFunction[] = "UnblockPin";

// Profile function names.
constexpr char kDeleteEntryFunction[] = "DeleteEntry";
constexpr char kGetEntryFunction[] = "GetEntry";

// ThirdPartyVpn function names.
constexpr char kOnPacketReceivedFunction[] = "OnPacketReceived";
constexpr char kOnPlatformMessageFunction[] = "OnPlatformMessage";
constexpr char kSetParametersFunction[] = "SetParameters";
constexpr char kSendPacketFunction[] = "SendPacket";
constexpr char kUpdateConnectionStateFunction[] = "UpdateConnectionState";

// WiFi interface priority function name.
constexpr char kSetWiFiInterfacePriorityFunction[] = "SetWiFiInterfacePriority";

// Manager property names.
constexpr char kActiveProfileProperty[] = "ActiveProfile";
constexpr char kAlwaysOnVpnPackageProperty[] = "AlwaysOnVpnPackage";
constexpr char kAvailableTechnologiesProperty[] = "AvailableTechnologies";
constexpr char kClaimedDevicesProperty[] = "ClaimedDevices";
constexpr char kConnectedTechnologiesProperty[] = "ConnectedTechnologies";
constexpr char kConnectionStateProperty[] = "ConnectionState";
constexpr char kDefaultServiceProperty[] = "DefaultService";
constexpr char kDefaultTechnologyProperty[] = "DefaultTechnology";
constexpr char kDevicesProperty[] = "Devices";
constexpr char kDhcpPropertyHostnameProperty[] = "DHCPProperty.Hostname";
constexpr char kDisableWiFiVHTProperty[] = "DisableWiFiVHT";
constexpr char kDisconnectWiFiOnEthernetProperty[] = "DisconnectWiFiOnEthernet";
constexpr char kDNSProxyDOHProvidersProperty[] = "DNSProxyDOHProviders";
constexpr char kDOHExcludedDomainsProperty[] = "DOHExcludedDomains";
constexpr char kDOHIncludedDomainsProperty[] = "DOHIncludedDomains";
constexpr char kEnabledTechnologiesProperty[] = "EnabledTechnologies";
constexpr char kEnableDHCPQoSProperty[] = "EnableDHCPQoS";
constexpr char kEnableRFC8925Property[] = "EnableRFC8925";
constexpr char kEnableSingleCACertVerificationPhase1Property[] =
    "EnableSingleCACertVerificationPhase1";
constexpr char kEnableSingleCACertVerificationPhase2Property[] =
    "EnableSingleCACertVerificationPhase2";
constexpr char kExperimentalTetheringFunctionality[] =
    "ExperimentalTetheringFunctionality";
constexpr char kLOHSConfigProperty[] = "LOHSConfig";
constexpr char kP2PAllowedProperty[] = "P2PAllowed";
constexpr char kP2PCapabilitiesProperty[] = "P2PCapabilities";
constexpr char kP2PGroupInfosProperty[] = "P2PGroupInfos";
constexpr char kP2PClientInfosProperty[] = "P2PClientInfos";
constexpr char kPortalFallbackHttpUrlsProperty[] = "PortalFallbackHttpUrls";
constexpr char kPortalFallbackHttpsUrlsProperty[] = "PortalFallbackHttpsUrls";
constexpr char kPortalHttpUrlProperty[] = "PortalHttpUrl";
constexpr char kPortalHttpsUrlProperty[] = "PortalHttpsUrl";
constexpr char kProfilesProperty[] = "Profiles";
constexpr char kServiceCompleteListProperty[] = "ServiceCompleteList";
constexpr char kServicesProperty[] = "Services";  // Also used for Profile.
constexpr char kSupportedVPNTypesProperty[] = "SupportedVPNTypes";
constexpr char kTetheringCapabilitiesProperty[] = "TetheringCapabilities";
constexpr char kTetheringConfigProperty[] = "TetheringConfig";
constexpr char kTetheringStatusProperty[] = "TetheringStatus";
constexpr char kUninitializedTechnologiesProperty[] =
    "UninitializedTechnologies";
constexpr char kUseLegacyDHCPCDProperty[] = "UseLegacyDHCPCD";
constexpr char kWakeOnLanEnabledProperty[] = "WakeOnLanEnabled";
constexpr char kWifiGlobalFTEnabledProperty[] = "WiFi.GlobalFTEnabled";
constexpr char kWifiScanAllowRoamProperty[] = "WiFi.ScanAllowRoam";
constexpr char kWifiRequestScanTypeProperty[] = "WiFi.RequestScanType";
constexpr char kWiFiInterfacePrioritiesProperty[] = "WiFiInterfacePriorities";
// Valid values of DisconnectWiFiOnEthernet
constexpr char kDisconnectWiFiOnEthernetOff[] = "off";
constexpr char kDisconnectWiFiOnEthernetConnected[] = "connected";
constexpr char kDisconnectWiFiOnEthernetOnline[] = "online";

// Manager and DefaultProfile property names (the Manager properties that are
// persisted by a DefaultProfile; these are always read-only for
// DefaultProfile).
constexpr char kArpGatewayProperty[] = "ArpGateway";
constexpr char kCheckPortalListProperty[] = "CheckPortalList";
constexpr char kNoAutoConnectTechnologiesProperty[] =
    "NoAutoConnectTechnologies";
constexpr char kProhibitedTechnologiesProperty[] = "ProhibitedTechnologies";

// Base Service property names.
constexpr char kAutoConnectProperty[] = "AutoConnect";
constexpr char kCheckPortalProperty[] = "CheckPortal";
constexpr char kConnectableProperty[] = "Connectable";
constexpr char kDeviceProperty[] = "Device";
constexpr char kDiagnosticsDisconnectsProperty[] = "Diagnostics.Disconnects";
constexpr char kDiagnosticsMisconnectsProperty[] = "Diagnostics.Misconnects";
constexpr char kDnsAutoFallbackProperty[] = "DNSAutoFallback";
constexpr char kEapRemoteCertificationProperty[] = "EAP.RemoteCertification";
constexpr char kErrorDetailsProperty[] = "ErrorDetails";
constexpr char kErrorProperty[] = "Error";
constexpr char kGuidProperty[] = "GUID";
constexpr char kIPConfigProperty[] = "IPConfig";
constexpr char kIsConnectedProperty[] = "IsConnected";
// The LinkMonitorDisable should only used for testing purposes.
constexpr char kLinkMonitorDisableProperty[] = "LinkMonitorDisable";
constexpr char kManagedCredentialsProperty[] = "ManagedCredentials";
constexpr char kMeteredProperty[] = "Metered";
constexpr char kLogNameProperty[] = "LogName";
constexpr char kNameProperty[] = "Name";  // Also used for Device and Profile.
constexpr char kPassphraseRequiredProperty[] = "PassphraseRequired";
constexpr char kPreviousErrorProperty[] = "PreviousError";
constexpr char kPreviousErrorSerialNumberProperty[] =
    "PreviousErrorSerialNumber";
constexpr char kPriorityProperty[] = "Priority";
constexpr char kProbeUrlProperty[] = "ProbeUrl";
constexpr char kProfileProperty[] = "Profile";
constexpr char kProxyConfigProperty[] = "ProxyConfig";
constexpr char kSaveCredentialsProperty[] = "SaveCredentials";
constexpr char kSavedIPConfigProperty[] = "SavedIPConfig";
constexpr char kSignalStrengthProperty[] = "Strength";
constexpr char kStateProperty[] = "State";
constexpr char kStaticIPConfigProperty[] = "StaticIPConfig";
constexpr char kTrafficCounterResetTimeProperty[] = "TrafficCounterResetTime";
constexpr char kTypeProperty[] = "Type";
constexpr char kUIDataProperty[] = "UIData";
constexpr char kVisibleProperty[] = "Visible";
constexpr char kONCSourceProperty[] = "ONCSource";
constexpr char kUplinkSpeedPropertyKbps[] = "UplinkSpeedKbps";
constexpr char kDownlinkSpeedPropertyKbps[] = "DownlinkSpeedKbps";
constexpr char kLastManualConnectAttemptProperty[] = "LastManualConnectAttempt";
constexpr char kLastConnectedProperty[] = "LastConnected";
constexpr char kLastOnlineProperty[] = "LastOnline";
constexpr char kStartTimeProperty[] = "StartTime";
constexpr char kNetworkIDProperty[] = "NetworkID";
constexpr char kNetworkConfigProperty[] = "NetworkConfig";

// Property names in the NetworkConfig dict.
constexpr char kNetworkConfigSessionIDProperty[] = "SessionID";
constexpr char kNetworkConfigIPv4AddressProperty[] = "IPv4Address";
constexpr char kNetworkConfigIPv4GatewayProperty[] = "IPv4Gateway";
constexpr char kNetworkConfigIPv6AddressesProperty[] = "IPv6Addresses";
constexpr char kNetworkConfigIPv6GatewayProperty[] = "IPv6Gateway";
constexpr char kNetworkConfigNameServersProperty[] = "NameServers";
constexpr char kNetworkConfigSearchDomainsProperty[] = "SearchDomains";
constexpr char kNetworkConfigMTUProperty[] = "MTU";
constexpr char kNetworkConfigIncludedRoutesProperty[] = "IncludedRoutes";
constexpr char kNetworkConfigExcludedRoutesProperty[] = "ExcludedRoutes";
constexpr char kNetworkConfigPref64Property[] = "Pref64";

// Cellular Service property names.
constexpr char kActivationStateProperty[] = "Cellular.ActivationState";
constexpr char kActivationTypeProperty[] = "Cellular.ActivationType";
constexpr char kCellularAllowRoamingProperty[] = "Cellular.AllowRoaming";
constexpr char kCellularApnProperty[] = "Cellular.APN";
constexpr char kCellularLastConnectedDefaultApnProperty[] =
    "Cellular.LastConnectedDefaultApnProperty";
constexpr char kCellularLastConnectedAttachApnProperty[] =
    "Cellular.LastConnectedAttachApnProperty";
constexpr char kCellularLastGoodApnProperty[] = "Cellular.LastGoodAPN";
constexpr char kCellularLastAttachApnProperty[] = "Cellular.LastAttachAPN";
constexpr char kCellularPPPPasswordProperty[] = "Cellular.PPP.Password";
constexpr char kCellularPPPUsernameProperty[] = "Cellular.PPP.Username";
// TODO(b/271332404): Remove kCellularUserApnListProperty when is no longer used
// in Chrome.
constexpr char kCellularUserApnListProperty[] = "Cellular.UserAPNList";
constexpr char kCellularCustomApnListProperty[] = "Cellular.CustomAPNList";
constexpr char kNetworkTechnologyProperty[] = "Cellular.NetworkTechnology";
constexpr char kOutOfCreditsProperty[] = "Cellular.OutOfCredits";
constexpr char kPaymentPortalProperty[] = "Cellular.Olp";
constexpr char kRoamingStateProperty[] = "Cellular.RoamingState";
constexpr char kServingOperatorProperty[] = "Cellular.ServingOperator";
constexpr char kTechnologyFamilyProperty[] = "Cellular.Family";
constexpr char kUsageURLProperty[] = "Cellular.UsageUrl";

// EAP Service/Passpoint credentials property names.
constexpr char kEapAnonymousIdentityProperty[] = "EAP.AnonymousIdentity";
constexpr char kEapCaCertIdProperty[] = "EAP.CACertID";
constexpr char kEapCaCertPemProperty[] = "EAP.CACertPEM";
constexpr char kEapCaCertProperty[] = "EAP.CACert";
constexpr char kEapCertIdProperty[] = "EAP.CertID";
constexpr char kEapDomainSuffixMatchProperty[] = "EAP.DomainSuffixMatch";
constexpr char kEapIdentityProperty[] = "EAP.Identity";
constexpr char kEapKeyIdProperty[] = "EAP.KeyID";
constexpr char kEapKeyMgmtProperty[] = "EAP.KeyMgmt";
constexpr char kEapMethodProperty[] = "EAP.EAP";
constexpr char kEapPasswordProperty[] = "EAP.Password";
constexpr char kEapPhase2AuthProperty[] = "EAP.InnerEAP";
constexpr char kEapPinProperty[] = "EAP.PIN";
constexpr char kEapSubjectAlternativeNameMatchProperty[] =
    "EAP.SubjectAlternativeNameMatch";
constexpr char kEapSubjectMatchProperty[] = "EAP.SubjectMatch";
constexpr char kEapTLSVersionMaxProperty[] = "EAP.TLSVersionMax";
constexpr char kEapUseLoginPasswordProperty[] = "EAP.UseLoginPassword";
constexpr char kEapUseProactiveKeyCachingProperty[] =
    "EAP.UseProactiveKeyCaching";
constexpr char kEapUseSystemCasProperty[] = "EAP.UseSystemCAs";
constexpr char kEapSubjectAlternativeNameMatchTypeProperty[] = "Type";
constexpr char kEapSubjectAlternativeNameMatchValueProperty[] = "Value";
constexpr char kPasspointFQDNProperty[] = "Passpoint.FQDN";
constexpr char kPasspointProvisioningSourceProperty[] =
    "Passpoint.ProvisioningSource";
constexpr char kPasspointMatchTypeProperty[] = "Passpoint.MatchType";
constexpr char kPasspointIDProperty[] = "Passpoint.ID";

// WiFi Service property names.
constexpr char kCountryProperty[] = "Country";
constexpr char kModeProperty[] = "Mode";
constexpr char kPassphraseProperty[] = "Passphrase";
constexpr char kSecurityClassProperty[] = "SecurityClass";
constexpr char kSecurityProperty[] = "Security";
constexpr char kSSIDProperty[] = "SSID";
constexpr char kWifiBSsid[] = "WiFi.BSSID";
constexpr char kWifiFrequencyListProperty[] = "WiFi.FrequencyList";
constexpr char kWifiFrequency[] = "WiFi.Frequency";
constexpr char kWifiHexSsid[] = "WiFi.HexSSID";
constexpr char kWifiHiddenSsid[] = "WiFi.HiddenSSID";
constexpr char kWifiPhyMode[] = "WiFi.PhyMode";
static constexpr char kWifiRandomMACPolicy[] = "WiFi.RandomMACPolicy";
constexpr char kWifiRekeyInProgressProperty[] = "WiFi.RekeyInProgress";
constexpr char kWifiRoamStateProperty[] = "WiFi.RoamState";
constexpr char kWifiVendorInformationProperty[] = "WiFi.VendorInformation";
constexpr char kWifiSignalStrengthRssiProperty[] = "WiFi.SignalStrengthRssi";
constexpr char kWifiBSSIDAllowlist[] = "WiFi.BSSIDAllowlist";
constexpr char kWifiBSSIDRequested[] = "WiFi.BSSIDRequested";

// Base VPN Service property names.
constexpr char kHostProperty[] = "Host";
constexpr char kPhysicalTechnologyProperty[] = "PhysicalTechnology";
constexpr char kProviderProperty[] = "Provider";
constexpr char kProviderHostProperty[] = "Provider.Host";
constexpr char kProviderTypeProperty[] = "Provider.Type";

// IKEv2 VPN Service property names.
constexpr char kIKEv2AuthenticationTypeProperty[] = "IKEv2.AuthenticationType";
constexpr char kIKEv2CaCertPemProperty[] = "IKEv2.CACertPEM";
constexpr char kIKEv2ClientCertIdProperty[] = "IKEv2.ClientCertID";
constexpr char kIKEv2ClientCertSlotProperty[] = "IKEv2.ClientCertSlot";
constexpr char kIKEv2LocalIdentityProperty[] = "IKEv2.LocalIdentity";
constexpr char kIKEv2PskProperty[] = "IKEv2.PSK";
constexpr char kIKEv2RemoteIdentityProperty[] = "IKEv2.RemoteIdentity";

// Values used in IKEv2.AuthenticationType.
constexpr char kIKEv2AuthenticationTypePSK[] = "PSK";
constexpr char kIKEv2AuthenticationTypeEAP[] = "EAP";
constexpr char kIKEv2AuthenticationTypeCert[] = "Cert";

// L2TPIPsec Service property names.
constexpr char kL2TPIPsecCaCertPemProperty[] = "L2TPIPsec.CACertPEM";
constexpr char kL2TPIPsecClientCertIdProperty[] = "L2TPIPsec.ClientCertID";
constexpr char kL2TPIPsecClientCertSlotProperty[] = "L2TPIPsec.ClientCertSlot";
constexpr char kL2TPIPsecLcpEchoDisabledProperty[] =
    "L2TPIPsec.LCPEchoDisabled";
constexpr char kL2TPIPsecPasswordProperty[] = "L2TPIPsec.Password";
constexpr char kL2TPIPsecPinProperty[] = "L2TPIPsec.PIN";
constexpr char kL2TPIPsecPskProperty[] = "L2TPIPsec.PSK";
constexpr char kL2TPIPsecPskRequiredProperty[] = "L2TPIPsec.PSKRequired";
constexpr char kL2TPIPsecTunnelGroupProperty[] = "L2TPIPsec.TunnelGroup";
constexpr char kL2TPIPsecUseLoginPasswordProperty[] =
    "L2TPIPsec.UseLoginPassword";
constexpr char kL2TPIPsecUserProperty[] = "L2TPIPsec.User";
constexpr char kL2TPIPsecXauthPasswordProperty[] = "L2TPIPsec.XauthPassword";
constexpr char kL2TPIPsecXauthUserProperty[] = "L2TPIPsec.XauthUser";

// OpenVPN Service property names.
constexpr char kOpenVPNAuthNoCacheProperty[] = "OpenVPN.AuthNoCache";
constexpr char kOpenVPNAuthProperty[] = "OpenVPN.Auth";
constexpr char kOpenVPNAuthRetryProperty[] = "OpenVPN.AuthRetry";
constexpr char kOpenVPNAuthUserPassProperty[] = "OpenVPN.AuthUserPass";
constexpr char kOpenVPNCaCertPemProperty[] = "OpenVPN.CACertPEM";
constexpr char kOpenVPNCipherProperty[] = "OpenVPN.Cipher";
constexpr char kOpenVPNClientCertIdProperty[] = "OpenVPN.Pkcs11.ID";
constexpr char kOpenVPNCompLZOProperty[] = "OpenVPN.CompLZO";
constexpr char kOpenVPNCompNoAdaptProperty[] = "OpenVPN.CompNoAdapt";
constexpr char kOpenVPNCompressProperty[] = "OpenVPN.Compress";
constexpr char kOpenVPNExtraCertPemProperty[] = "OpenVPN.ExtraCertPEM";
constexpr char kOpenVPNExtraHostsProperty[] = "OpenVPN.ExtraHosts";
constexpr char kOpenVPNIgnoreDefaultRouteProperty[] =
    "OpenVPN.IgnoreDefaultRoute";
constexpr char kOpenVPNKeyDirectionProperty[] = "OpenVPN.KeyDirection";
constexpr char kOpenVPNNsCertTypeProperty[] = "OpenVPN.NsCertType";
constexpr char kOpenVPNOTPProperty[] = "OpenVPN.OTP";
constexpr char kOpenVPNPasswordProperty[] = "OpenVPN.Password";
constexpr char kOpenVPNPinProperty[] = "OpenVPN.Pkcs11.PIN";
constexpr char kOpenVPNPingExitProperty[] = "OpenVPN.PingExit";
constexpr char kOpenVPNPingProperty[] = "OpenVPN.Ping";
constexpr char kOpenVPNPingRestartProperty[] = "OpenVPN.PingRestart";
constexpr char kOpenVPNPortProperty[] = "OpenVPN.Port";
constexpr char kOpenVPNProtoProperty[] = "OpenVPN.Proto";
constexpr char kOpenVPNPushPeerInfoProperty[] = "OpenVPN.PushPeerInfo";
constexpr char kOpenVPNRemoteCertEKUProperty[] = "OpenVPN.RemoteCertEKU";
constexpr char kOpenVPNRemoteCertKUProperty[] = "OpenVPN.RemoteCertKU";
constexpr char kOpenVPNRemoteCertTLSProperty[] = "OpenVPN.RemoteCertTLS";
constexpr char kOpenVPNRenegSecProperty[] = "OpenVPN.RenegSec";
constexpr char kOpenVPNServerPollTimeoutProperty[] =
    "OpenVPN.ServerPollTimeout";
constexpr char kOpenVPNShaperProperty[] = "OpenVPN.Shaper";
constexpr char kOpenVPNStaticChallengeProperty[] = "OpenVPN.StaticChallenge";
constexpr char kOpenVPNTLSAuthContentsProperty[] = "OpenVPN.TLSAuthContents";
constexpr char kOpenVPNTLSAuthProperty[] = "OpenVPN.TLSAuth";
constexpr char kOpenVPNTLSRemoteProperty[] = "OpenVPN.TLSRemote";
constexpr char kOpenVPNTLSVersionMinProperty[] = "OpenVPN.TLSVersionMin";
constexpr char kOpenVPNTokenProperty[] = "OpenVPN.Token";
constexpr char kOpenVPNUserProperty[] = "OpenVPN.User";
constexpr char kOpenVPNVerbProperty[] = "OpenVPN.Verb";
constexpr char kOpenVPNVerifyHashProperty[] = "OpenVPN.VerifyHash";
constexpr char kOpenVPNVerifyX509NameProperty[] = "OpenVPN.VerifyX509Name";
constexpr char kOpenVPNVerifyX509TypeProperty[] = "OpenVPN.VerifyX509Type";
constexpr char kVPNMTUProperty[] = "VPN.MTU";

// ThirdPartyVpn Service property names.
constexpr char kConfigurationNameProperty[] = "ConfigurationName";
constexpr char kExtensionNameProperty[] = "ExtensionName";
constexpr char kObjectPathSuffixProperty[] = "ObjectPathSuffix";

// WireGuard Service property names.
constexpr char kWireGuardIPAddress[] = "WireGuard.IPAddress";
constexpr char kWireGuardPrivateKey[] = "WireGuard.PrivateKey";
constexpr char kWireGuardPublicKey[] = "WireGuard.PublicKey";
constexpr char kWireGuardPeers[] = "WireGuard.Peers";
constexpr char kWireGuardLastReadLinkStatusTime[] =
    "WireGuard.LastReadLinkStatusTime";
// Property names of a peer in "WireGuard.Peers"
constexpr char kWireGuardPeerPublicKey[] = "PublicKey";
constexpr char kWireGuardPeerPresharedKey[] = "PresharedKey";
constexpr char kWireGuardPeerEndpoint[] = "Endpoint";
constexpr char kWireGuardPeerAllowedIPs[] = "AllowedIPs";
constexpr char kWireGuardPeerPersistentKeepalive[] = "PersistentKeepalive";
constexpr char kWireGuardPeerLatestHandshake[] = "LatestHandshake";
constexpr char kWireGuardPeerRxBytes[] = "RxBytes";
constexpr char kWireGuardPeerTxBytes[] = "TxBytes";

// IPConfig property names.
// kAddressProperty: Defined below for Device.
constexpr char kExcludedRoutesProperty[] = "ExcludedRoutes";
constexpr char kGatewayProperty[] = "Gateway";
constexpr char kIncludedRoutesProperty[] = "IncludedRoutes";
constexpr char kMethodProperty[] = "Method";
constexpr char kMtuProperty[] = "Mtu";
constexpr char kNameServersProperty[] = "NameServers";
constexpr char kPrefixlenProperty[] = "Prefixlen";
constexpr char kSearchDomainsProperty[] = "SearchDomains";
constexpr char kWebProxyAutoDiscoveryUrlProperty[] = "WebProxyAutoDiscoveryUrl";

// Passpoint credentials property names.
// EAP properties are defined above for EAP service.
constexpr char kPasspointCredentialsFQDNProperty[] = "FQDN";
constexpr char kPasspointCredentialsDomainsProperty[] = "Domains";
constexpr char kPasspointCredentialsRealmProperty[] = "Realm";
constexpr char kPasspointCredentialsHomeOIsProperty[] = "HomeOIs";
constexpr char kPasspointCredentialsRequiredHomeOIsProperty[] =
    "RequiredHomeOIs";
constexpr char kPasspointCredentialsRoamingConsortiaProperty[] =
    "RoamingConsortia";
constexpr char kPasspointCredentialsMeteredOverrideProperty[] =
    "MeteredOverride";
constexpr char kPasspointCredentialsAndroidPackageNameProperty[] =
    "AndroidPackageName";
constexpr char kPasspointCredentialsFriendlyNameProperty[] = "FriendlyName";
constexpr char kPasspointCredentialsExpirationTimeMillisecondsProperty[] =
    "ExpirationTimeMilliseconds";

// Base Device property names.
constexpr char kAddressProperty[] = "Address";  // Also used for IPConfig.
constexpr char kInhibitedProperty[] = "Inhibited";
constexpr char kIPConfigsProperty[] = "IPConfigs";
constexpr char kIPv6DisabledProperty[] = "IPv6Disabled";
constexpr char kInterfaceProperty[] = "Interface";  // Network interface name.
// kNameProperty: Defined above for Service. DEPRECATED (crbug.com/1011136).
constexpr char kPoweredProperty[] = "Powered";
constexpr char kScanIntervalProperty[] =
    "ScanInterval";                               // For both Cellular and WiFi.
constexpr char kScanningProperty[] = "Scanning";  // For both Cellular and WiFi.
constexpr char kSelectedServiceProperty[] = "SelectedService";

// Property names common to Cellular Device and Cellular Service.
constexpr char kEidProperty[] = "Cellular.EID";
constexpr char kIccidProperty[] = "Cellular.ICCID";
constexpr char kImsiProperty[] = "Cellular.IMSI";

// kIccidProperty value when SIM card exists but ICCID is not available.
constexpr char kUnknownIccid[] = "unknown-iccid";

// Cellular Device property names.
constexpr char kCellularApnListProperty[] = "Cellular.APNList";
constexpr char kCellularPolicyAllowRoamingProperty[] =
    "Cellular.PolicyAllowRoaming";
constexpr char kDeviceIdProperty[] = "Cellular.DeviceID";
constexpr char kEquipmentIdProperty[] = "Cellular.EquipmentID";
constexpr char kEsnProperty[] = "Cellular.ESN";
constexpr char kFirmwareRevisionProperty[] = "Cellular.FirmwareRevision";
constexpr char kFoundNetworksProperty[] = "Cellular.FoundNetworks";
constexpr char kHardwareRevisionProperty[] = "Cellular.HardwareRevision";
constexpr char kHomeProviderProperty[] = "Cellular.HomeProvider";
constexpr char kImeiProperty[] = "Cellular.IMEI";
constexpr char kManufacturerProperty[] = "Cellular.Manufacturer";
constexpr char kMdnProperty[] = "Cellular.MDN";
constexpr char kMeidProperty[] = "Cellular.MEID";
constexpr char kModelIdProperty[] = "Cellular.ModelID";
constexpr char kMinProperty[] = "Cellular.MIN";
constexpr char kProviderRequiresRoamingProperty[] =
    "Cellular.ProviderRequiresRoaming";
constexpr char kSelectedNetworkProperty[] = "Cellular.SelectedNetwork";
constexpr char kSIMPresentProperty[] = "Cellular.SIMPresent";
constexpr char kSIMSlotInfoProperty[] = "Cellular.SIMSlotInfo";
constexpr char kSupportNetworkScanProperty[] = "Cellular.SupportNetworkScan";
constexpr char kPrimaryMultiplexedInterfaceProperty[] =
    "Cellular.PrimaryMultiplexedInterface";
constexpr char kFlashingProperty[] = "Cellular.Flashing";
constexpr char kInitializingProperty[] = "Cellular.Initializing";

constexpr char kDBusObjectProperty[] = "DBus.Object";
constexpr char kDBusServiceProperty[] = "DBus.Service";

// Ethernet Device property names.
constexpr char kEapAuthenticationCompletedProperty[] =
    "EapAuthenticationCompleted";
constexpr char kEapAuthenticatorDetectedProperty[] = "EapAuthenticatorDetected";
constexpr char kDeviceBusTypeProperty[] = "Ethernet.DeviceBusType";
constexpr char kLinkUpProperty[] = "Ethernet.LinkUp";
constexpr char kUsbEthernetMacAddressSourceProperty[] =
    "Ethernet.UsbEthernetMacAddressSource";

// WiFi Device property names.
constexpr char kBgscanMethodProperty[] = "BgscanMethod";
constexpr char kBgscanShortIntervalProperty[] = "BgscanShortInterval";
constexpr char kBgscanSignalThresholdProperty[] = "BgscanSignalThreshold";
constexpr char kForceWakeToScanTimerProperty[] = "ForceWakeToScanTimer";
constexpr char kLastWakeReasonProperty[] = "LastWakeReason";
constexpr char kLinkStatisticsProperty[] = "LinkStatistics";
constexpr char kMacAddressRandomizationEnabledProperty[] =
    "MACAddressRandomizationEnabled";
constexpr char kMacAddressRandomizationSupportedProperty[] =
    "MACAddressRandomizationSupported";
constexpr char kNetDetectScanPeriodSecondsProperty[] =
    "NetDetectScanPeriodSeconds";
constexpr char kWakeOnWiFiSupportedProperty[] = "WakeOnWiFiSupported";
constexpr char kWakeOnWiFiAllowedProperty[] = "WakeOnWiFiAllowed";
constexpr char kWakeOnWiFiFeaturesEnabledProperty[] =
    "WakeOnWiFiFeaturesEnabled";
constexpr char kWakeToScanPeriodSecondsProperty[] = "WakeToScanPeriodSeconds";

// Profile property names.
constexpr char kEntriesProperty[] = "Entries";
// kNameProperty: Defined above for Service.
// kServicesProperty: Defined above for Manager.
constexpr char kUserHashProperty[] = "UserHash";
constexpr char kAlwaysOnVpnModeProperty[] = "AlwaysOnVpnMode";
constexpr char kAlwaysOnVpnServiceProperty[] = "AlwaysOnVpnService";

// WiFi Service VendorInformation dictionary keys.
constexpr char kVendorOUIListProperty[] = "OUIList";
constexpr char kVendorWPSDeviceNameProperty[] = "DeviceName";
constexpr char kVendorWPSManufacturerProperty[] = "Manufacturer";
constexpr char kVendorWPSModelNameProperty[] = "ModelName";
constexpr char kVendorWPSModelNumberProperty[] = "ModelNumber";

// Flimflam state options.
constexpr char kStateIdle[] = "idle";
constexpr char kStateAssociation[] = "association";
constexpr char kStateConfiguration[] = "configuration";
constexpr char kStateReady[] = "ready";
constexpr char kStateNoConnectivity[] = "no-connectivity";
constexpr char kStateRedirectFound[] = "redirect-found";
constexpr char kStateOnline[] = "online";
constexpr char kStateDisconnecting[] = "disconnecting";
constexpr char kStateFailure[] = "failure";
// Deprecated. TODO(b/333634158): Remove after all usage in Chrome has been
// removed.
constexpr char kStatePortalSuspected[] = "portal-suspected";

// Shill CheckPortal property values.
constexpr char kCheckPortalTrue[] = "true";
constexpr char kCheckPortalAuto[] = "auto";
constexpr char kCheckPortalFalse[] = "false";
constexpr char kCheckPortalHTTPOnly[] = "http-only";

// Shill WiFi roam state options.
constexpr char kRoamStateIdle[] = "idle";
constexpr char kRoamStateAssociation[] = "association";
constexpr char kRoamStateConfiguration[] = "configuration";
constexpr char kRoamStateReady[] = "ready";

// Shill Passpoint match type options.
constexpr char kPasspointMatchTypeHome[] = "home";
constexpr char kPasspointMatchTypeRoaming[] = "roaming";
constexpr char kPasspointMatchTypeUnknown[] = "unknown";

// Flimflam property names for SIMLock status.
// kSIMLockStatusProperty is a Cellular Device property.
constexpr char kSIMLockStatusProperty[] = "Cellular.SIMLockStatus";
constexpr char kSIMLockTypeProperty[] = "LockType";
constexpr char kSIMLockRetriesLeftProperty[] = "RetriesLeft";
constexpr char kSIMLockEnabledProperty[] = "LockEnabled";

// Shill SIMSlotInfo properties.
constexpr char kSIMSlotInfoEID[] = "EID";
constexpr char kSIMSlotInfoICCID[] = "ICCID";
constexpr char kSIMSlotInfoPrimary[] = "Primary";

// Flimflam property names for Cellular.FoundNetworks.
constexpr char kLongNameProperty[] = "long_name";
constexpr char kStatusProperty[] = "status";
constexpr char kShortNameProperty[] = "short_name";
constexpr char kTechnologyProperty[] = "technology";
constexpr char kNetworkIdProperty[] = "network_id";

// Flimflam SIMLock status types.
constexpr char kSIMLockPin[] = "sim-pin";
constexpr char kSIMLockPuk[] = "sim-puk";
constexpr char kSIMLockNetworkPin[] = "network-pin";
constexpr int kUnknownLockRetriesLeft = 999;

// APN info property names.
constexpr char kApnProperty[] = "apn";
constexpr char kApnNetworkIdProperty[] = "network_id";
constexpr char kApnUsernameProperty[] = "username";
constexpr char kApnPasswordProperty[] = "password";
constexpr char kApnNameProperty[] = "name";
constexpr char kApnLocalizedNameProperty[] = "localized_name";
constexpr char kApnLanguageProperty[] = "language";
constexpr char kApnAuthenticationProperty[] = "authentication";
constexpr char kApnIsRequiredByCarrierSpecProperty[] =
    "is_required_by_carrier_spec";
// TODO(b/251551314): Remove kApnAttachProperty after 2025Q2
constexpr char kApnAttachProperty[] = "attach";
constexpr char kApnIpTypeProperty[] = "ip_type";
constexpr char kApnRoamingIpTypeProperty[] = "roaming_ip_type";
constexpr char kApnTypesProperty[] = "apn_types";
constexpr char kApnIdProperty[] = "id";
constexpr char kApnSourceProperty[] = "apn_source";
// The Profile ID property will be ignored if sent by Chrome or
// otherwise set in a custom APN.
constexpr char kApnProfileIdProperty[] = "profile_id";

// APN authentication property values (as expected by ModemManager).
constexpr char kApnAuthenticationPap[] = "pap";
constexpr char kApnAuthenticationChap[] = "chap";

// IP type property values.
constexpr char kApnIpTypeV4[] = "ipv4";
constexpr char kApnIpTypeV6[] = "ipv6";
constexpr char kApnIpTypeV4V6[] = "ipv4v6";

// APN type property values.
constexpr char kApnTypeDefault[] = "DEFAULT";
constexpr char kApnTypeIA[] = "IA";
constexpr char kApnTypeDun[] = "DUN";

// APN source property values.
constexpr char kApnSourceAdmin[] = "admin";
constexpr char kApnSourceUi[] = "ui";
constexpr char kApnSourceMoDb[] = "modb";
constexpr char kApnSourceModem[] = "modem";

// APN IsRequiredByCarrierSpec values.
constexpr char kApnIsRequiredByCarrierSpecTrue[] = "1";
constexpr char kApnIsRequiredByCarrierSpecFalse[] = "0";

// Payment Portal property names.
constexpr char kPaymentPortalURL[] = "url";
constexpr char kPaymentPortalMethod[] = "method";
constexpr char kPaymentPortalPostData[] = "postdata";

// Operator info property names.
constexpr char kOperatorNameKey[] = "name";
constexpr char kOperatorCodeKey[] = "code";
constexpr char kOperatorCountryKey[] = "country";
constexpr char kOperatorUuidKey[] = "uuid";

// Flimflam network technology options.
constexpr char kNetworkTechnology1Xrtt[] = "1xRTT";
constexpr char kNetworkTechnologyEvdo[] = "EVDO";
constexpr char kNetworkTechnologyGsm[] = "GSM";
constexpr char kNetworkTechnologyGprs[] = "GPRS";
constexpr char kNetworkTechnologyEdge[] = "EDGE";
constexpr char kNetworkTechnologyUmts[] = "UMTS";
constexpr char kNetworkTechnologyHspa[] = "HSPA";
constexpr char kNetworkTechnologyHspaPlus[] = "HSPA+";
constexpr char kNetworkTechnologyLte[] = "LTE";
constexpr char kNetworkTechnologyLteAdvanced[] = "LTE Advanced";
constexpr char kNetworkTechnology5gNr[] = "5GNR";

// Flimflam roaming state options
constexpr char kRoamingStateHome[] = "home";
constexpr char kRoamingStateRoaming[] = "roaming";
constexpr char kRoamingStateUnknown[] = "unknown";

// Flimflam activation state options
constexpr char kActivationStateActivated[] = "activated";
constexpr char kActivationStateActivating[] = "activating";
constexpr char kActivationStateNotActivated[] = "not-activated";
constexpr char kActivationStatePartiallyActivated[] = "partially-activated";
constexpr char kActivationStateUnknown[] = "unknown";

// Flimflam EAP method options.
constexpr char kEapMethodPEAP[] = "PEAP";
constexpr char kEapMethodTLS[] = "TLS";
constexpr char kEapMethodTTLS[] = "TTLS";
constexpr char kEapMethodLEAP[] = "LEAP";
constexpr char kEapMethodMSCHAPV2[] = "MSCHAPV2";

// Flimflam EAP phase 2 auth options.
constexpr char kEapPhase2AuthPEAPMD5[] = "auth=MD5";
constexpr char kEapPhase2AuthPEAPMSCHAPV2[] = "auth=MSCHAPV2";
constexpr char kEapPhase2AuthPEAPGTC[] = "auth=GTC";
constexpr char kEapPhase2AuthTTLSMD5[] = "autheap=MD5";  // crosbug/26822
constexpr char kEapPhase2AuthTTLSEAPMD5[] = "autheap=MD5";
constexpr char kEapPhase2AuthTTLSEAPMSCHAPV2[] = "autheap=MSCHAPV2";
constexpr char kEapPhase2AuthTTLSMSCHAPV2[] = "auth=MSCHAPV2";
constexpr char kEapPhase2AuthTTLSMSCHAP[] = "auth=MSCHAP";
constexpr char kEapPhase2AuthTTLSPAP[] = "auth=PAP";
constexpr char kEapPhase2AuthTTLSCHAP[] = "auth=CHAP";
constexpr char kEapPhase2AuthTTLSGTC[] = "auth=GTC";
constexpr char kEapPhase2AuthTTLSEAPGTC[] = "autheap=GTC";

// Flimflam EAP TLS versions.
constexpr char kEapTLSVersion1p0[] = "1.0";
constexpr char kEapTLSVersion1p1[] = "1.1";
constexpr char kEapTLSVersion1p2[] = "1.2";

// Flimflam VPN provider types.
constexpr char kProviderArcVpn[] = "arcvpn";
constexpr char kProviderIKEv2[] = "ikev2";
constexpr char kProviderL2tpIpsec[] = "l2tpipsec";
constexpr char kProviderOpenVpn[] = "openvpn";
constexpr char kProviderThirdPartyVpn[] = "thirdpartyvpn";
constexpr char kProviderWireGuard[] = "wireguard";

// Flimflam monitored properties
constexpr char kMonitorPropertyChanged[] = "PropertyChanged";

// Flimflam type options.
constexpr char kTypeEthernet[] = "ethernet";
constexpr char kTypeWifi[] = "wifi";
constexpr char kTypeCellular[] = "cellular";
constexpr char kTypeVPN[] = "vpn";

// Flimflam mode options.
constexpr char kModeManaged[] = "managed";

// WiFi SecurityClass options.
constexpr char kSecurityClassNone[] = "none";
constexpr char kSecurityClassWep[] = "wep";
constexpr char kSecurityClassPsk[] = "psk";
constexpr char kSecurityClass8021x[] = "802_1x";
// These two are deprecated.  Use kSecurityClass* equivalents above.
// TODO(b/226138492) Remove this once references in Chrome and Shill are
// removed.
constexpr char kSecurityPsk[] = "psk";
constexpr char kSecurity8021x[] = "802_1x";

// WiFi Security options.
constexpr char kSecurityNone[] = "none";
constexpr char kSecurityTransOwe[] = "trans-owe";
constexpr char kSecurityOwe[] = "owe";
constexpr char kSecurityWep[] = "wep";
constexpr char kSecurityWpa[] = "wpa";
constexpr char kSecurityWpaWpa2[] = "wpa+wpa2";
constexpr char kSecurityWpaAll[] = "wpa-all";
// Deprecated.  Use kSecurityWpa2 instead.
// TODO(b/226138492) Remove this once references in Chrome and Shill are
// removed.
constexpr char kSecurityRsn[] = "rsn";
constexpr char kSecurityWpa2[] = "wpa2";
constexpr char kSecurityWpa2Wpa3[] = "wpa2+wpa3";
constexpr char kSecurityWpa3[] = "wpa3";
constexpr char kSecurityWpaEnterprise[] = "wpa-ent";
constexpr char kSecurityWpaWpa2Enterprise[] = "wpa+wpa2-ent";
constexpr char kSecurityWpaAllEnterprise[] = "wpa-all-ent";
constexpr char kSecurityWpa2Enterprise[] = "wpa2-ent";
constexpr char kSecurityWpa2Wpa3Enterprise[] = "wpa2+wpa3-ent";
constexpr char kSecurityWpa3Enterprise[] = "wpa3-ent";

// WiFi Band options.
constexpr char kBand2GHz[] = "2.4GHz";
constexpr char kBand5GHz[] = "5GHz";
constexpr char kBandAll[] = "all-bands";
constexpr char kBandUnknown[] = "unknown";

// Compress option values as expected by OpenVPN.
constexpr char kOpenVPNCompressFramingOnly[] = "";
constexpr char kOpenVPNCompressLz4[] = "lz4";
constexpr char kOpenVPNCompressLz4V2[] = "lz4-v2";
constexpr char kOpenVPNCompressLzo[] = "lzo";

// FlimFlam technology family options
constexpr char kTechnologyFamilyCdma[] = "CDMA";
constexpr char kTechnologyFamilyGsm[] = "GSM";

// IPConfig type options.
constexpr char kTypeIPv4[] = "ipv4";
constexpr char kTypeIPv6[] = "ipv6";
constexpr char kTypeDHCP[] = "dhcp";
constexpr char kTypeBOOTP[] = "bootp";
constexpr char kTypeZeroConf[] = "zeroconf";
constexpr char kTypeDHCP6[] = "dhcp6";
constexpr char kTypeSLAAC[] = "slaac";
// kTypeVPN[] = "vpn" is defined above in device type session.

// Flimflam error options.
constexpr char kErrorAaaFailed[] = "aaa-failed";
constexpr char kErrorActivationFailed[] = "activation-failed";
constexpr char kErrorBadPassphrase[] = "bad-passphrase";
constexpr char kErrorBadWEPKey[] = "bad-wepkey";
constexpr char kErrorConnectFailed[] = "connect-failed";
constexpr char kErrorDNSLookupFailed[] = "dns-lookup-failed";
constexpr char kErrorDhcpFailed[] = "dhcp-failed";
constexpr char kErrorHTTPGetFailed[] = "http-get-failed";
constexpr char kErrorInternal[] = "internal-error";
constexpr char kErrorInvalidFailure[] = "invalid-failure";
constexpr char kErrorInvalidAPN[] = "invalid-apn";
constexpr char kErrorIpsecCertAuthFailed[] = "ipsec-cert-auth-failed";
constexpr char kErrorIpsecPskAuthFailed[] = "ipsec-psk-auth-failed";
constexpr char kErrorNeedEvdo[] = "need-evdo";
constexpr char kErrorNeedHomeNetwork[] = "need-home-network";
constexpr char kErrorNoFailure[] = "no-failure";
constexpr char kErrorNotAssociated[] = "not-associated";
constexpr char kErrorNotAuthenticated[] = "not-authenticated";
constexpr char kErrorOtaspFailed[] = "otasp-failed";
constexpr char kErrorOutOfRange[] = "out-of-range";
constexpr char kErrorPinMissing[] = "pin-missing";
constexpr char kErrorPppAuthFailed[] = "ppp-auth-failed";
constexpr char kErrorSimLocked[] = "sim-locked";
constexpr char kErrorSimCarrierLocked[] = "sim-carrier-locked";
constexpr char kErrorNotRegistered[] = "not-registered";
constexpr char kErrorTooManySTAs[] = "too-many-stas";
constexpr char kErrorDisconnect[] = "disconnect-failure";
constexpr char kErrorDelayedConnectSetup[] = "delayed-connect-setup-failure";
constexpr char kErrorSuspectInactiveSim[] = "suspect-inactive-sim";
constexpr char kErrorSuspectSubscriptionError[] = "suspect-subscription-error";
constexpr char kErrorSuspectModemDisallowed[] = "suspect-modem-disallowed";
constexpr char kErrorUnknownFailure[] = "unknown-failure";

// Flimflam error result codes.
constexpr char kErrorResultSuccess[] = "org.chromium.flimflam.Error.Success";
constexpr char kErrorResultFailure[] = "org.chromium.flimflam.Error.Failure";
constexpr char kErrorResultAlreadyConnected[] =
    "org.chromium.flimflam.Error.AlreadyConnected";
constexpr char kErrorResultAlreadyExists[] =
    "org.chromium.flimflam.Error.AlreadyExists";
constexpr char kErrorResultIllegalOperation[] =
    "org.chromium.flimflam.Error.IllegalOperation";
constexpr char kErrorResultIncorrectPin[] =
    "org.chromium.flimflam.Error.IncorrectPin";
constexpr char kErrorResultInProgress[] =
    "org.chromium.flimflam.Error.InProgress";
constexpr char kErrorResultInternalError[] =
    "org.chromium.flimflam.Error.InternalError";
constexpr char kErrorResultInvalidApn[] =
    "org.chromium.flimflam.Error.InvalidApn";
constexpr char kErrorResultInvalidArguments[] =
    "org.chromium.flimflam.Error.InvalidArguments";
constexpr char kErrorResultInvalidNetworkName[] =
    "org.chromium.flimflam.Error.InvalidNetworkName";
constexpr char kErrorResultInvalidPassphrase[] =
    "org.chromium.flimflam.Error.InvalidPassphrase";
constexpr char kErrorResultInvalidProperty[] =
    "org.chromium.flimflam.Error.InvalidProperty";
constexpr char kErrorResultNoCarrier[] =
    "org.chromium.flimflam.Error.NoCarrier";
constexpr char kErrorResultNotConnected[] =
    "org.chromium.flimflam.Error.NotConnected";
constexpr char kErrorResultNotFound[] = "org.chromium.flimflam.Error.NotFound";
constexpr char kErrorResultNotImplemented[] =
    "org.chromium.flimflam.Error.NotImplemented";
constexpr char kErrorResultNotOnHomeNetwork[] =
    "org.chromium.flimflam.Error.NotOnHomeNetwork";
constexpr char kErrorResultNotRegistered[] =
    "org.chromium.flimflam.Error.NotRegistered";
constexpr char kErrorResultNotSupported[] =
    "org.chromium.flimflam.Error.NotSupported";
constexpr char kErrorResultOperationAborted[] =
    "org.chromium.flimflam.Error.OperationAborted";
constexpr char kErrorResultOperationInitiated[] =
    "org.chromium.flimflam.Error.OperationInitiated";
constexpr char kErrorResultOperationTimeout[] =
    "org.chromium.flimflam.Error.OperationTimeout";
constexpr char kErrorResultPassphraseRequired[] =
    "org.chromium.flimflam.Error.PassphraseRequired";
constexpr char kErrorResultPermissionDenied[] =
    "org.chromium.flimflam.Error.PermissionDenied";
constexpr char kErrorResultPinBlocked[] =
    "org.chromium.flimflam.Error.PinBlocked";
constexpr char kErrorResultPinRequired[] =
    "org.chromium.flimflam.Error.PinRequired";
constexpr char kErrorResultTechnologyNotAvailable[] =
    "org.chromium.flimflam.Error.TechnologyNotAvailable";
constexpr char kErrorResultThrottled[] =
    "org.chromium.flimflam.Error.Throttled";
constexpr char kErrorResultWepNotSupported[] =
    "org.chromium.flimflam.Error.WepNotSupported";
constexpr char kErrorResultWrongState[] =
    "org.chromium.flimflam.Error.WrongState";
constexpr char kErrorResultSuspectInactiveSim[] =
    "org.chromium.flimflam.error.SuspectInactiveSim";
constexpr char kErrorResultSuspectSubscriptionIssue[] =
    "org.chromium.flimflam.error.SuspectSubscriptionIssue";
constexpr char kErrorResultSuspectModemDisallowed[] =
    "org.chromium.flimflam.error.SuspectModemDisallowed";

constexpr char kUnknownString[] = "UNKNOWN";

// Device bus types.
constexpr char kDeviceBusTypePci[] = "pci";
constexpr char kDeviceBusTypeUsb[] = "usb";

// Technology types (augments "Flimflam type options" above).
constexpr char kTypeEthernetEap[] = "etherneteap";
constexpr char kTypeTunnel[] = "tunnel";
constexpr char kTypeLoopback[] = "loopback";
constexpr char kTypePPP[] = "ppp";
constexpr char kTypeGuestInterface[] = "guest_interface";
constexpr char kTypeUnknown[] = "unknown";

// Error strings.
constexpr char kErrorEapAuthenticationFailed[] = "eap-authentication-failed";
constexpr char kErrorEapLocalTlsFailed[] = "eap-local-tls-failed";
constexpr char kErrorEapRemoteTlsFailed[] = "eap-remote-tls-failed";

// Subject alternative name match type property values as expected by
// wpa_supplicant.
constexpr char kEapSubjectAlternativeNameMatchTypeEmail[] = "EMAIL";
constexpr char kEapSubjectAlternativeNameMatchTypeDNS[] = "DNS";
constexpr char kEapSubjectAlternativeNameMatchTypeURI[] = "URI";

// WiFi Device kLinkStatisticsProperty sub-property names.
constexpr char kAverageReceiveSignalDbmProperty[] = "AverageReceiveSignalDbm";
constexpr char kByteReceiveSuccessesProperty[] = "ByteReceiveSuccesses";
constexpr char kByteTransmitSuccessesProperty[] = "ByteTransmitSuccesses";
constexpr char kInactiveTimeMillisecondsProperty[] = "InactiveTimeMilliseconds";
constexpr char kLastReceiveSignalDbmProperty[] = "LastReceiveSignalDbm";
constexpr char kPacketReceiveDropProperty[] = "PacketReceiveDrops";
constexpr char kPacketReceiveSuccessesProperty[] = "PacketReceiveSuccesses";
constexpr char kPacketTransmitFailuresProperty[] = "PacketTransmitFailures";
constexpr char kPacketTransmitSuccessesProperty[] = "PacketTransmitSuccesses";
constexpr char kReceiveBitrateProperty[] = "ReceiveBitrate";
constexpr char kTransmitBitrateProperty[] = "TransmitBitrate";
constexpr char kTransmitRetriesProperty[] = "TransmitRetries";

// Wake on WiFi features.
constexpr char kWakeOnWiFiFeaturesEnabledDarkConnect[] = "darkconnect";
constexpr char kWakeOnWiFiFeaturesEnabledNone[] = "none";

// Wake on WiFi wake reasons.
// These (except Unknown) will also be sent to powerd via
// RecordDarkResumeWakeReason, to tell it the reason of the current dark
// resume.
constexpr char kWakeOnWiFiReasonDisconnect[] = "WiFi.Disconnect";
constexpr char kWakeOnWiFiReasonPattern[] = "WiFi.Pattern";
constexpr char kWakeOnWiFiReasonSSID[] = "WiFi.SSID";
constexpr char kWakeOnWiFiReasonUnknown[] = "Unknown";

// kEapKeyMgmtProperty values.
constexpr char kKeyManagementIEEE8021X[] = "IEEE8021X";

// Wake on WiFi Packet Type Constants.
constexpr char kWakeOnTCP[] = "TCP";
constexpr char kWakeOnUDP[] = "UDP";
constexpr char kWakeOnIDP[] = "IDP";
constexpr char kWakeOnIPIP[] = "IPIP";
constexpr char kWakeOnIGMP[] = "IGMP";
constexpr char kWakeOnICMP[] = "ICMP";
constexpr char kWakeOnIP[] = "IP";

// ONC Source constants.
static constexpr char kONCSourceUnknown[] = "Unknown";
static constexpr char kONCSourceNone[] = "None";
static constexpr char kONCSourceUserImport[] = "UserImport";
static constexpr char kONCSourceDevicePolicy[] = "DevicePolicy";
static constexpr char kONCSourceUserPolicy[] = "UserPolicy";

// MAC Randomization constants
static constexpr char kWifiRandomMacPolicyHardware[] = "Hardware";
static constexpr char kWifiRandomMacPolicyFullRandom[] = "FullRandom";
static constexpr char kWifiRandomMacPolicyOUIRandom[] = "OUIRandom";
static constexpr char kWifiRandomMacPolicyPersistentRandom[] =
    "PersistentRandom";
static constexpr char kWifiRandomMacPolicyNonPersistentRandom[] =
    "NonPersistentRandom";

// Cellular activation types.
constexpr char kActivationTypeNonCellular[] = "NonCellular";  // For future use
constexpr char kActivationTypeOMADM[] = "OMADM";              // For future use
constexpr char kActivationTypeOTA[] = "OTA";
constexpr char kActivationTypeOTASP[] = "OTASP";

// USB Ethernet MAC address sources.
constexpr char kUsbEthernetMacAddressSourceDesignatedDockMac[] =
    "designated_dock_mac";
constexpr char kUsbEthernetMacAddressSourceBuiltinAdapterMac[] =
    "builtin_adapter_mac";
constexpr char kUsbEthernetMacAddressSourceUsbAdapterMac[] = "usb_adapter_mac";

// Geolocation property field names.
// Reference:
//    https://devsite.googleplex.com/maps/documentation/business/geolocation/
// Top level properties for a Geolocation request.
constexpr char kGeoHomeMobileCountryCodeProperty[] = "homeMobileCountryCode";
constexpr char kGeoHomeMobileNetworkCodeProperty[] = "homeMobileNetworkCode";
constexpr char kGeoRadioTypePropertyProperty[] = "radioType";
constexpr char kGeoCellTowersProperty[] = "cellTowers";
constexpr char kGeoWifiAccessPointsProperty[] = "wifiAccessPoints";
// Cell tower object property names.
constexpr char kGeoCellIdProperty[] = "cellId";
constexpr char kGeoLocationAreaCodeProperty[] = "locationAreaCode";
constexpr char kGeoMobileCountryCodeProperty[] = "mobileCountryCode";
constexpr char kGeoMobileNetworkCodeProperty[] = "mobileNetworkCode";
constexpr char kGeoTimingAdvanceProperty[] = "timingAdvance";
// WiFi access point property names.
constexpr char kGeoMacAddressProperty[] = "macAddress";
constexpr char kGeoChannelProperty[] = "channel";
constexpr char kGeoSignalToNoiseRatioProperty[] = "signalToNoiseRatio";
// Common property names for geolocation objects.
constexpr char kGeoAgeProperty[] = "age";
constexpr char kGeoSignalStrengthProperty[] = "signalStrength";
// ThirdPartyVpn parameters and constants.
constexpr char kAddressParameterThirdPartyVpn[] = "address";
constexpr char kBroadcastAddressParameterThirdPartyVpn[] = "broadcast_address";
constexpr char kGatewayParameterThirdPartyVpn[] = "gateway";
constexpr char kBypassTunnelForIpParameterThirdPartyVpn[] =
    "bypass_tunnel_for_ip";
constexpr char kSubnetPrefixParameterThirdPartyVpn[] = "subnet_prefix";
constexpr char kMtuParameterThirdPartyVpn[] = "mtu";
constexpr char kDomainSearchParameterThirdPartyVpn[] = "domain_search";
constexpr char kDnsServersParameterThirdPartyVpn[] = "dns_servers";
constexpr char kInclusionListParameterThirdPartyVpn[] = "inclusion_list";
constexpr char kExclusionListParameterThirdPartyVpn[] = "exclusion_list";
constexpr char kReconnectParameterThirdPartyVpn[] = "reconnect";
constexpr char kObjectPathBase[] = "/thirdpartyvpn/";
constexpr char kNonIPDelimiter = ':';
constexpr char kIPDelimiter = ' ';

// Always-on VPN modes for the kAlwaysOnVpnModeProperty Profile property.
constexpr char kAlwaysOnVpnModeOff[] = "off";
constexpr char kAlwaysOnVpnModeBestEffort[] = "best-effort";
constexpr char kAlwaysOnVpnModeStrict[] = "strict";

// Possible traffic sources. Note that these sources should be kept in sync with
// the sources defined in TrafficCounter::Source at:
// src/platform2/system_api/dbus/patchpanel/patchpanel_service.proto
constexpr char kTrafficCounterSourceUnknown[] = "UNKNOWN";
constexpr char kTrafficCounterSourceChrome[] = "CHROME";
constexpr char kTrafficCounterSourceUser[] = "USER";
constexpr char kTrafficCounterSourceUpdateEngine[] = "UPDATE_ENGINE";
constexpr char kTrafficCounterSourceSystem[] = "SYSTEM";
constexpr char kTrafficCounterSourceVpn[] = "VPN";
constexpr char kTrafficCounterSourceArc[] = "ARC";
constexpr char kTrafficCounterSourceBorealisVM[] = "BOREALIS_VM";
constexpr char kTrafficCounterSourceBruschettaVM[] = "BRUSCHETTA_VM";
constexpr char kTrafficCounterSourceCrostiniVM[] = "CROSTINI_VM";
constexpr char kTrafficCounterSourceParallelsVM[] = "PARALLELS_VM";
constexpr char kTrafficCounterSourceTethering[] = "TETHERING";
constexpr char kTrafficCounterSourceWiFiDirect[] = "WIFI_DIRECT";
constexpr char kTrafficCounterSourceWiFiLOHS[] = "WIFI_LOHS";
// Deprecated
constexpr char kTrafficCounterSourceCrosvm[] = "crosvm";
constexpr char kTrafficCounterSourcePluginvm[] = "pluginvm";

// Manager kTetheringConfigProperty dictionary key names.
constexpr char kTetheringConfAutoDisableProperty[] = "auto_disable";
constexpr char kTetheringConfBandProperty[] = "band";
constexpr char kTetheringConfMARProperty[] = "randomize_mac_address";
constexpr char kTetheringConfPassphraseProperty[] = "passphrase";
constexpr char kTetheringConfSecurityProperty[] = "security";
constexpr char kTetheringConfSSIDProperty[] = "ssid";
constexpr char kTetheringConfUpstreamTechProperty[] = "upstream_technology";
constexpr char kTetheringConfDownstreamDeviceForTestProperty[] =
    "downstream_device_for_test";
constexpr char kTetheringConfDownstreamPhyIndexForTestProperty[] =
    "downstream_phy_index_for_test";

// Manager kTetheringCapabilitiesProperty dictionary key names.
constexpr char kTetheringCapDownstreamProperty[] = "downstream_technologies";
constexpr char kTetheringCapSecurityProperty[] = "wifi_security_modes";
constexpr char kTetheringCapUpstreamProperty[] = "upstream_technologies";

// Manager kTetheringStatusProperty dictionary key names.
constexpr char kTetheringStatusClientHostnameProperty[] = "hostname";
constexpr char kTetheringStatusClientIPv4Property[] = "IPv4";
constexpr char kTetheringStatusClientIPv6Property[] = "IPv6";
constexpr char kTetheringStatusClientMACProperty[] = "MAC";
constexpr char kTetheringStatusClientsProperty[] = "active_clients";
constexpr char kTetheringStatusDownstreamTechProperty[] =
    "downstream_technology";
constexpr char kTetheringStatusIdleReasonProperty[] = "idle_reason";
constexpr char kTetheringStatusStateProperty[] = "state";
constexpr char kTetheringStatusUpstreamTechProperty[] = "upstream_technology";
constexpr char kTetheringStatusUpstreamServiceProperty[] = "upstream_service";

// kTetheringStatusIdleReasonProperty values
constexpr char kTetheringIdleReasonClientStop[] = "client_stop";
constexpr char kTetheringIdleReasonConfigChange[] = "config_change";
constexpr char kTetheringIdleReasonDownstreamLinkDisconnect[] =
    "downstream_link_disconnect";
constexpr char kTetheringIdleReasonDownstreamNetworkDisconnect[] =
    "downstream_network_disconnect";
constexpr char kTetheringIdleReasonError[] = "error";
constexpr char kTetheringIdleReasonInactive[] = "inactive";
constexpr char kTetheringIdleReasonInitialState[] = "initial_state";
constexpr char kTetheringIdleReasonResourceBusy[] = "resource_busy";
constexpr char kTetheringIdleReasonStartTimeout[] = "start_timeout";
constexpr char kTetheringIdleReasonSuspend[] = "suspend";
constexpr char kTetheringIdleReasonUpstreamDisconnect[] = "upstream_disconnect";
constexpr char kTetheringIdleReasonUpstreamNoInternet[] =
    "upstream_no_internet";
constexpr char kTetheringIdleReasonUpstreamNotAvailable[] =
    "upstream_not_available";
constexpr char kTetheringIdleReasonUserExit[] = "user_exit";

// kTetheringStatusStateProperty values
constexpr char kTetheringStateActive[] = "active";
constexpr char kTetheringStateIdle[] = "idle";
constexpr char kTetheringStateRestarting[] = "restarting";
constexpr char kTetheringStateStarting[] = "starting";
constexpr char kTetheringStateStopping[] = "stopping";

// SetTetheringEnabled and {Enable,Disable}Tethering result values
constexpr char kTetheringEnableResultAbort[] = "abort";
constexpr char kTetheringEnableResultBusy[] = "busy";
constexpr char kTetheringEnableResultConcurrencyNotSupported[] =
    "concurrency_not_supported";
constexpr char kTetheringEnableResultDownstreamWiFiFailure[] =
    "downstream_wifi_failure";
constexpr char kTetheringEnableResultFailure[] = "failure";
constexpr char kTetheringEnableResultInvalidProperties[] = "invalid_properties";
constexpr char kTetheringEnableResultNetworkSetupFailure[] =
    "network_setup_failure";
constexpr char kTetheringEnableResultNotAllowed[] = "not_allowed";
constexpr char kTetheringEnableResultSuccess[] = "success";
constexpr char kTetheringEnableResultUpstreamFailure[] = "upstream_failure";
constexpr char kTetheringEnableResultUpstreamNotAvailable[] =
    "upstream_not_available";
constexpr char kTetheringEnableResultWrongState[] = "wrong_state";
// Deprecated in crrev/c/5082857
constexpr char kTetheringEnableResultUpstreamWithoutInternet[] =
    "upstream_network_without_Internet";

// kCheckTetheringReadinessFunction return status
constexpr char kTetheringReadinessNotAllowed[] = "not_allowed";
constexpr char kTetheringReadinessNotAllowedByCarrier[] =
    "not_allowed_by_carrier";
constexpr char kTetheringReadinessNotAllowedOnFw[] = "not_allowed_on_fw";
constexpr char kTetheringReadinessNotAllowedOnVariant[] =
    "not_allowed_on_variant";
constexpr char kTetheringReadinessNotAllowedUserNotEntitled[] =
    "not_allowed_user_not_entitled";
constexpr char kTetheringReadinessReady[] = "ready";
constexpr char kTetheringReadinessUpstreamNetworkNotAvailable[] =
    "upstream_network_not_available";

// WiFi RequestScan types
constexpr char kWiFiRequestScanTypeActive[] = "active";
constexpr char kWiFiRequestScanTypeDefault[] = "default";
constexpr char kWiFiRequestScanTypePassive[] = "passive";

// P2P device state values
constexpr char kP2PDeviceStateUninitialized[] = "uninitialized";
constexpr char kP2PDeviceStateReady[] = "ready";
constexpr char kP2PDeviceStateClientAssociating[] = "client_associating";
constexpr char kP2PDeviceStateClientConfiguring[] = "client_configuring";
constexpr char kP2PDeviceStateClientConnected[] = "client_connected";
constexpr char kP2PDeviceStateClientDisconnecting[] = "client_disconnecting";
constexpr char kP2PDeviceStateGOStarting[] = "go_starting";
constexpr char kP2PDeviceStateGOConfiguring[] = "go_configuring";
constexpr char kP2PDeviceStateGOActive[] = "go_active";
constexpr char kP2PDeviceStateGOStopping[] = "go_stopping";

// Manager kP2PCapabilitiesProperty dictionary key names.
constexpr char kP2PCapabilitiesP2PSupportedProperty[] = "P2PSupported";
constexpr char kP2PCapabilitiesGroupReadinessProperty[] = "GroupReadiness";
constexpr char kP2PCapabilitiesClientReadinessProperty[] = "ClientReadiness";
constexpr char kP2PCapabilitiesSupportedChannelsProperty[] =
    "SupportedChannels";
constexpr char kP2PCapabilitiesPreferredChannelsProperty[] =
    "PreferredChannels";

// kP2PCapabilitiesGroupReadinessProperty values
constexpr char kP2PCapabilitiesGroupReadinessReady[] = "ready";
constexpr char kP2PCapabilitiesGroupReadinessNotReady[] = "not_ready";

// kP2PCapabilitiesClientReadinessProperty values
constexpr char kP2PCapabilitiesClientReadinessReady[] = "ready";
constexpr char kP2PCapabilitiesClientReadinessNotReady[] = "not_ready";

// Manager kP2PGroupInfosProperty dictionary key names.
constexpr char kP2PGroupInfoInterfaceProperty[] = "interface";
constexpr char kP2PGroupInfoShillIDProperty[] = "shill_id";
constexpr char kP2PGroupInfoStateProperty[] = "state";
constexpr char kP2PGroupInfoSSIDProperty[] = "ssid";
constexpr char kP2PGroupInfoPassphraseProperty[] = "passphrase";
constexpr char kP2PGroupInfoBSSIDProperty[] = "bssid";
constexpr char kP2PGroupInfoIPv4AddressProperty[] = "ipv4_address";
constexpr char kP2PGroupInfoIPv6AddressProperty[] = "ipv6_address";
constexpr char kP2PGroupInfoMACAddressProperty[] = "mac_address";
constexpr char kP2PGroupInfoNetworkIDProperty[] = "network_id";
constexpr char kP2PGroupInfoFrequencyProperty[] = "frequency";
constexpr char kP2PGroupInfoClientsProperty[] = "clients";

// kP2PGroupInfoStateProperty values
constexpr char kP2PGroupInfoStateIdle[] = "idle";
constexpr char kP2PGroupInfoStateStarting[] = "starting";
constexpr char kP2PGroupInfoStateConfiguring[] = "configuring";
constexpr char kP2PGroupInfoStateActive[] = "active";
constexpr char kP2PGroupInfoStateStopping[] = "stopping";

// Manager kP2PGroupInfoClientsProperty dictionary key names
constexpr char kP2PGroupInfoClientMACAddressProperty[] = "mac_address";
constexpr char kP2PGroupInfoClientIPv4AddressProperty[] = "ipv4_address";
constexpr char kP2PGroupInfoClientIPv6AddressProperty[] = "ipv6_address";
constexpr char kP2PGroupInfoClientHostnameProperty[] = "hostname";
constexpr char kP2PGroupInfoClientVendorClassProperty[] = "vendor_class";

// Manager kP2PClientInfoProperty dictionary key names.
constexpr char kP2PClientInfoInterfaceProperty[] = "interface";
constexpr char kP2PClientInfoShillIDProperty[] = "shill_id";
constexpr char kP2PClientInfoStateProperty[] = "state";
constexpr char kP2PClientInfoSSIDProperty[] = "ssid";
constexpr char kP2PClientInfoPassphraseProperty[] = "passphrase";
constexpr char kP2PClientInfoGroupBSSIDProperty[] = "group_bssid";
constexpr char kP2PClientInfoIPv4AddressProperty[] = "ipv4_address";
constexpr char kP2PClientInfoIPv6AddressProperty[] = "ipv6_address";
constexpr char kP2PClientInfoMACAddressProperty[] = "mac_address";
constexpr char kP2PClientInfoNetworkIDProperty[] = "network_id";
constexpr char kP2PClientInfoFrequencyProperty[] = "frequency";
constexpr char kP2PClientInfoGroupOwnerProperty[] = "group_owner";

// kP2PClientInfoStateProperty values
constexpr char kP2PClientInfoStateIdle[] = "idle";
constexpr char kP2PClientInfoStateAssociating[] = "associating";
constexpr char kP2PClientInfoStateConfiguring[] = "configuring";
constexpr char kP2PClientInfoStateConnected[] = "connected";
constexpr char kP2PClientInfoStateDisconnecting[] = "disconnecting";

// Manager kP2PClientInfoGroupOwnerProperty dictionary key names
constexpr char kP2PClientInfoGroupOwnerMACAddressProperty[] = "mac_address";
constexpr char kP2PClientInfoGroupOwnerIPv4AddressProperty[] = "ipv4_address";
constexpr char kP2PClientInfoGroupOwnerIPv6AddressProperty[] = "ipv6_address";
constexpr char kP2PClientInfoGroupOwnerHostnameProperty[] = "hostname";
constexpr char kP2PClientInfoGroupOwnerVendorClassProperty[] = "vendor_class";

// Manager CreateP2PGroup and ConnectToP2PGroup dictionary argument key names
constexpr char kP2PDeviceSSID[] = "ssid";
constexpr char kP2PDevicePassphrase[] = "passphrase";
constexpr char kP2PDeviceFrequency[] = "frequency";
constexpr char kP2PDeviceBSSID[] = "bssid";
constexpr char kP2PDevicePriority[] = "priority";

// P2P result dictionary key names
constexpr char kP2PDeviceShillID[] = "shill_id";
constexpr char kP2PResultCode[] = "result_code";

// Manager kWiFiInterfacePriorites key names
constexpr char kWiFiInterfacePrioritesNameProperty[] = "name";
constexpr char kWiFiInterfacePrioritiesPriorityProperty[] = "priority";
// Manager CreateP2PGroup result values
constexpr char kCreateP2PGroupResultSuccess[] = "success";
constexpr char kCreateP2PGroupResultNotAllowed[] = "not_allowed";
constexpr char kCreateP2PGroupResultNotSupported[] = "not_supported";
constexpr char kCreateP2PGroupResultConcurrencyNotSupported[] =
    "concurrency_not_supported";
constexpr char kCreateP2PGroupResultTimeout[] = "timeout";
constexpr char kCreateP2PGroupResultFrequencyNotSupported[] =
    "frequency_not_supported";
constexpr char kCreateP2PGroupResultBadSSID[] = "bad_ssid";
constexpr char kCreateP2PGroupResultInvalidArguments[] = "invalid_arguments";
constexpr char kCreateP2PGroupResultOperationInProgress[] =
    "operation_in_progress";
constexpr char kCreateP2PGroupResultOperationFailed[] = "operation_failed";

// Manager ConnectToP2PGroup result values
constexpr char kConnectToP2PGroupResultSuccess[] = "success";
constexpr char kConnectToP2PGroupResultNotAllowed[] = "not_allowed";
constexpr char kConnectToP2PGroupResultNotSupported[] = "not_supported";
constexpr char kConnectToP2PGroupResultConcurrencyNotSupported[] =
    "concurrency_not_supported";
constexpr char kConnectToP2PGroupResultTimeout[] = "timeout";
constexpr char kConnectToP2PGroupResultAuthFailure[] = "auth_failure";
constexpr char kConnectToP2PGroupResultFrequencyNotSupported[] =
    "frequency_not_supported";
constexpr char kConnectToP2PGroupResultGroupNotFound[] = "group_not_found";
constexpr char kConnectToP2PGroupResultAlreadyConnected[] = "already_connected";
constexpr char kConnectToP2PGroupResultInvalidArguments[] = "invalid_arguments";
constexpr char kConnectToP2PGroupResultOperationInProgress[] =
    "operation_in_progress";
constexpr char kConnectToP2PGroupResultOperationFailed[] = "operation_failed";

// Manager DestroyP2PGroup result values
constexpr char kDestroyP2PGroupResultSuccess[] = "success";
constexpr char kDestroyP2PGroupResultNotAllowed[] = "not_allowed";
constexpr char kDestroyP2PGroupResultNotSupported[] = "not_supported";
constexpr char kDestroyP2PGroupResultTimeout[] = "timeout";
constexpr char kDestroyP2PGroupResultNoGroup[] = "no_group";
constexpr char kDestroyP2PGroupResultOperationInProgress[] =
    "operation_in_progress";
constexpr char kDestroyP2PGroupResultOperationFailed[] = "operation_failed";

// Manager DisconnectFromP2PGroup result values
constexpr char kDisconnectFromP2PGroupResultSuccess[] = "success";
constexpr char kDisconnectFromP2PGroupResultNotAllowed[] = "not_allowed";
constexpr char kDisconnectFromP2PGroupResultNotSupported[] = "not_supported";
constexpr char kDisconnectFromP2PGroupResultTimeout[] = "timeout";
constexpr char kDisconnectFromP2PGroupResultNotConnected[] = "not_connected";
constexpr char kDisconnectFromP2PGroupResultOperationInProgress[] =
    "operation_in_progress";
constexpr char kDisconnectFromP2PGroupResultOperationFailed[] =
    "operation_failed";

// Manager DNSProxyDOHProviders wildcard IP address value.
constexpr char kDNSProxyDOHProvidersMatchAnyIPAddress[] = "*";

// Default cellular interface name which may appear in the kInterfaceProperty of
// Device. This value means that the Cellular Device is not active.
constexpr char kCellularDefaultInterfaceName[] = "cell_iface";

// Represents the priority level of a Wi-Fi interface. When a new interface is
// requested, existing interfaces of lower priority may be destroyed to make
// room for the new interfaces.
enum class WiFiInterfacePriority {
  // Opportunistic requests with minimum priority; nice-to-have but don’t
  // directly impact the user.
  OPPORTUNISTIC = 0,
  // Background requests; not triggered by direct user input.
  BACKGROUND,
  // Foreground requests with potential fallback media.
  FOREGROUND_WITH_FALLBACK,
  // Foreground requests without any fallback media.
  FOREGROUND_WITHOUT_FALLBACK,
  // Requests from OS-native applications like network settings that directly
  // enable user use-cases.
  OS_REQUEST,
  // User-initiated requests in which the user has been explicitly informed that
  // some Wi-Fi functionality may stop working, and agreed to start the
  // interface anyway. Treated with maximum priority.
  USER_ASSERTED,

  NUM_PRIORITIES,
};

}  // namespace shill

#endif  // SYSTEM_API_DBUS_SHILL_DBUS_CONSTANTS_H_
