// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PARSER_AT_RULE_DESCRIPTORS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PARSER_AT_RULE_DESCRIPTORS_H_

#include "base/notreached.h"
#include "third_party/blink/renderer/core/css/css_property_names.h"
#include "third_party/blink/renderer/platform/wtf/text/string_view.h"
#include <string.h>

namespace blink {

enum class AtRuleDescriptorID {
  Invalid = 0,
  Variable = 1,
  AdditiveSymbols = 2,
  AscentOverride = 3,
  BasePalette = 4,
  BaseUrl = 5,
  DescentOverride = 6,
  Fallback = 7,
  FontDisplay = 8,
  FontFamily = 9,
  FontFeatureSettings = 10,
  FontStretch = 11,
  FontStyle = 12,
  FontVariant = 13,
  FontVariationSettings = 14,
  FontWeight = 15,
  Hash = 16,
  Hostname = 17,
  Inherits = 18,
  InitialValue = 19,
  LineGapOverride = 20,
  Navigation = 21,
  Negative = 22,
  OverrideColors = 23,
  Pad = 24,
  Pathname = 25,
  Pattern = 26,
  Port = 27,
  Prefix = 28,
  Protocol = 29,
  Range = 30,
  Result = 31,
  Search = 32,
  SizeAdjust = 33,
  SpeakAs = 34,
  Src = 35,
  Suffix = 36,
  Symbols = 37,
  Syntax = 38,
  System = 39,
  Types = 40,
  UnicodeRange = 41,
};

const int numAtRuleDescriptors = 42;

const char* getValueName(AtRuleDescriptorID);

AtRuleDescriptorID AsAtRuleDescriptorID(StringView string);

CSSPropertyID AtRuleDescriptorIDAsCSSPropertyID(AtRuleDescriptorID);
AtRuleDescriptorID CSSPropertyIDAsAtRuleDescriptor(CSSPropertyID id);

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PARSER_AT_RULE_DESCRIPTORS_H_
