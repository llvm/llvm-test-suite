// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/forms/input_type_names.json5


#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_INPUT_TYPE_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_INPUT_TYPE_NAMES_H_

#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/core/core_export.h"

namespace blink {
namespace input_type_names {

CORE_EXPORT extern const AtomicString& kButton;
CORE_EXPORT extern const AtomicString& kCheckbox;
CORE_EXPORT extern const AtomicString& kColor;
CORE_EXPORT extern const AtomicString& kDate;
CORE_EXPORT extern const AtomicString& kDatetime;
CORE_EXPORT extern const AtomicString& kDatetimeLocal;
CORE_EXPORT extern const AtomicString& kEmail;
CORE_EXPORT extern const AtomicString& kFile;
CORE_EXPORT extern const AtomicString& kHidden;
CORE_EXPORT extern const AtomicString& kImage;
CORE_EXPORT extern const AtomicString& kMonth;
CORE_EXPORT extern const AtomicString& kNumber;
CORE_EXPORT extern const AtomicString& kPassword;
CORE_EXPORT extern const AtomicString& kRadio;
CORE_EXPORT extern const AtomicString& kRange;
CORE_EXPORT extern const AtomicString& kReset;
CORE_EXPORT extern const AtomicString& kSearch;
CORE_EXPORT extern const AtomicString& kSubmit;
CORE_EXPORT extern const AtomicString& kTel;
CORE_EXPORT extern const AtomicString& kText;
CORE_EXPORT extern const AtomicString& kTime;
CORE_EXPORT extern const AtomicString& kUrl;
CORE_EXPORT extern const AtomicString& kWeek;

constexpr unsigned kNamesCount = 23;

CORE_EXPORT void Init();

}  // namespace input_type_names
}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_INPUT_TYPE_NAMES_H_
