// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/events/event_target_names.json5


#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_EVENT_TARGET_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_EVENT_TARGET_NAMES_H_

#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/core/core_export.h"

namespace blink {
namespace event_target_names {

CORE_EXPORT extern const AtomicString& kAbortSignal;
CORE_EXPORT extern const AtomicString& kAnimation;
CORE_EXPORT extern const AtomicString& kApplicationCache;
CORE_EXPORT extern const AtomicString& kAudioTrackList;
CORE_EXPORT extern const AtomicString& kBroadcastChannel;
CORE_EXPORT extern const AtomicString& kClipboard;
CORE_EXPORT extern const AtomicString& kCloseWatcher;
CORE_EXPORT extern const AtomicString& kContainerQueryList;
CORE_EXPORT extern const AtomicString& kDedicatedWorkerGlobalScope;
CORE_EXPORT extern const AtomicString& kEditContext;
CORE_EXPORT extern const AtomicString& kEventSource;
CORE_EXPORT extern const AtomicString& kEventTargetImpl;
CORE_EXPORT extern const AtomicString& kFileReader;
CORE_EXPORT extern const AtomicString& kFontFaceSet;
CORE_EXPORT extern const AtomicString& kInputMethodContext;
CORE_EXPORT extern const AtomicString& kMediaQueryList;
CORE_EXPORT extern const AtomicString& kMessagePort;
CORE_EXPORT extern const AtomicString& kMojoInterfaceInterceptor;
CORE_EXPORT extern const AtomicString& kNavigation;
CORE_EXPORT extern const AtomicString& kNavigationHistoryEntry;
CORE_EXPORT extern const AtomicString& kNode;
CORE_EXPORT extern const AtomicString& kOffscreenCanvas;
CORE_EXPORT extern const AtomicString& kPerformance;
CORE_EXPORT extern const AtomicString& kPreferenceObject;
CORE_EXPORT extern const AtomicString& kProfiler;
CORE_EXPORT extern const AtomicString& kScreen;
CORE_EXPORT extern const AtomicString& kShadowRealmGlobalScope;
CORE_EXPORT extern const AtomicString& kSharedWorker;
CORE_EXPORT extern const AtomicString& kSharedWorkerGlobalScope;
CORE_EXPORT extern const AtomicString& kTextTrack;
CORE_EXPORT extern const AtomicString& kTextTrackCue;
CORE_EXPORT extern const AtomicString& kTextTrackList;
CORE_EXPORT extern const AtomicString& kTrustedTypePolicyFactory;
CORE_EXPORT extern const AtomicString& kVideoTrackList;
CORE_EXPORT extern const AtomicString& kVisualViewport;
CORE_EXPORT extern const AtomicString& kWebPrintJob;
CORE_EXPORT extern const AtomicString& kWindow;
CORE_EXPORT extern const AtomicString& kWorker;
CORE_EXPORT extern const AtomicString& kXMLHttpRequest;
CORE_EXPORT extern const AtomicString& kXMLHttpRequestUpload;

constexpr unsigned kNamesCount = 40;

CORE_EXPORT void Init();

}  // namespace event_target_names
}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_EVENT_TARGET_NAMES_H_
