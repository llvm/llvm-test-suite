// Copyright 2021 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SYSTEM_API_DBUS_RESOURCE_MANAGER_DBUS_CONSTANTS_H_
#define SYSTEM_API_DBUS_RESOURCE_MANAGER_DBUS_CONSTANTS_H_

namespace resource_manager {

const char kResourceManagerInterface[] = "org.chromium.ResourceManager";
const char kResourceManagerServicePath[] = "/org/chromium/ResourceManager";
const char kResourceManagerServiceName[] = "org.chromium.ResourceManager";

// Values.
enum GameMode {
  // Game mode is off.
  OFF = 0,
  // Game mode is on, borealis is the foreground subsystem.
  BOREALIS = 1,
};

enum PressureLevelChrome {
  // There is enough memory to use.
  NONE = 0,
  // Chrome is advised to free buffers that are cheap to re-allocate and not
  // immediately needed.
  MODERATE = 1,
  // Chrome is advised to free all possible memory.
  CRITICAL = 2,
};

enum DiscardType {
  // Only unprotected pages can be discarded.
  UNPROTECTED = 0,
  // Both unprotected and protected pages can be discarded.
  PROTECTED = 1,
};

enum class PressureLevelArcContainer {
  // There is enough memory to use.
  NONE = 0,
  // ARC container is advised to kill cached processes to free memory.
  CACHED = 1,
  // ARC container is advised to kill perceptible processes to free memory.
  PERCEPTIBLE = 2,
  // ARC container is advised to kill foreground processes to free memory.
  FOREGROUND = 3,
};

enum class ProcessState {
  // The process is normal.
  kNormal = 0,
  // The process is background.
  kBackground = 1,
};

enum class ThreadState {
  kUrgentBursty = 0,
  kUrgent = 1,
  kBalanced = 2,
  kEco = 3,
  kUtility = 4,
  kBackground = 5,
  kUrgentBurstyServer = 6,
  kUrgentBurstyClient = 7,
};

// Methods.
const char kGetAvailableMemoryKBMethod[] = "GetAvailableMemoryKB";
const char kGetForegroundAvailableMemoryKBMethod[] =
    "GetForegroundAvailableMemoryKB";
const char kGetMemoryMarginsKBMethod[] = "GetMemoryMarginsKB";
const char kGetComponentMemoryMarginsKBMethod[] = "GetComponentMemoryMarginsKB";
const char kGetGameModeMethod[] = "GetGameMode";
const char kSetGameModeMethod[] = "SetGameMode";
const char kSetGameModeWithTimeoutMethod[] = "SetGameModeWithTimeout";
const char kSetMemoryMarginsMethod[] = "SetMemoryMargins";
// TODO(vovoy): remove method SetMemoryMarginsBps.
const char kSetMemoryMarginsBps[] = "SetMemoryMarginsBps";
const char kSetFullscreenVideoWithTimeout[] = "SetFullscreenVideoWithTimeout";
const char kSetVmBootModeWithTimeoutMethod[] = "SetVmBootModeWithTimeout";
const char kReportBrowserProcessesMethod[] = "ReportBrowserProcesses";
const char kSetProcessStateMethod[] = "SetProcessState";
const char kSetThreadStateMethod[] = "SetThreadState";

// Signals.

// MemoryPressureChrome signal contains 4 arguments:
//   1. pressure_level, BYTE, see also enum PressureLevelChrome.
//   2. reclaim_target_kb, UINT64, memory amount to free in KB to leave the
//   current pressure level.
//   3. Origin time, to avoid discard due to out-of-dated signals.
//   4. discard_type, BYTE, see also enum DiscardType.
//   E.g., argument (PressureLevelChrome::CRITICAL, 10000, origin_time,
//   DiscardType::UNPROTECTED): Chrome should free 10000 KB to leave the
//   critical memory pressure level (to moderate pressure level), only
//   unprotected pages can be discarded.
const char kMemoryPressureChrome[] = "MemoryPressureChrome";

// MemoryPressureArcContainer signal contains 3 arguments:
//   1. pressure_level, BYTE, see also enum PressureLevelArcContainer.
//   2. delta, UINT64, memory amount to free in KB to leave the current
//   pressure level.
//   3. Origin time.
//   E.g. argument (PressureLevelArcContainer::FOREGROUND, 10000, origin_time):
//   ARC container should free 10000 KB to leave the foreground memory pressure
//   level (to perceptible pressure level).
const char kMemoryPressureArcContainer[] = "MemoryPressureArcContainer";

}  // namespace resource_manager

#endif  // SYSTEM_API_DBUS_RESOURCE_MANAGER_DBUS_CONSTANTS_H_
