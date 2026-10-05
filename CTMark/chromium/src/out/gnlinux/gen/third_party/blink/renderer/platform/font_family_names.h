// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/fonts/font_family_names.json5


#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONT_FAMILY_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONT_FAMILY_NAMES_H_

#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/platform/platform_export.h"

namespace blink {
namespace font_family_names {

PLATFORM_EXPORT extern const AtomicString& kArial;
PLATFORM_EXPORT extern const AtomicString& kBlinkMacSystemFont;
PLATFORM_EXPORT extern const AtomicString& kCalibri;
PLATFORM_EXPORT extern const AtomicString& kCourier;
PLATFORM_EXPORT extern const AtomicString& kCourierNew;
PLATFORM_EXPORT extern const AtomicString& kCursive;
PLATFORM_EXPORT extern const AtomicString& kFantasy;
PLATFORM_EXPORT extern const AtomicString& kHelvetica;
PLATFORM_EXPORT extern const AtomicString& kHelveticaNeue;
PLATFORM_EXPORT extern const AtomicString& kLucidaGrande;
PLATFORM_EXPORT extern const AtomicString& kMSSansSerif;
PLATFORM_EXPORT extern const AtomicString& kMSSerif;
PLATFORM_EXPORT extern const AtomicString& kMSUIGothic;
PLATFORM_EXPORT extern const AtomicString& kMath;
PLATFORM_EXPORT extern const AtomicString& kMicrosoftSansSerif;
PLATFORM_EXPORT extern const AtomicString& kMonospace;
PLATFORM_EXPORT extern const AtomicString& kRoboto;
PLATFORM_EXPORT extern const AtomicString& kSans;
PLATFORM_EXPORT extern const AtomicString& kSansSerif;
PLATFORM_EXPORT extern const AtomicString& kSegoeUI;
PLATFORM_EXPORT extern const AtomicString& kSerif;
PLATFORM_EXPORT extern const AtomicString& kSystemUi;
PLATFORM_EXPORT extern const AtomicString& kTimes;
PLATFORM_EXPORT extern const AtomicString& kTimesNewRoman;
PLATFORM_EXPORT extern const AtomicString& kWebkitStandard;

constexpr unsigned kNamesCount = 25;

PLATFORM_EXPORT void Init();

}  // namespace font_family_names
}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONT_FAMILY_NAMES_H_
