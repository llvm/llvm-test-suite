// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/style/templates/computed_style_base_constants.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_group_config.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/core/css/css_value_keywords.json5
//   ../../third_party/blink/renderer/core/style/computed_style_extra_fields.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5


#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_BASE_CONSTANTS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_BASE_CONSTANTS_H_

#include <stdint.h>

#include <iosfwd>

#include "base/dcheck_is_on.h"
#include "third_party/blink/renderer/core/core_export.h"

namespace blink {

// TODO(sashab): Move these enums to their own namespace, or add a CSS prefix,
// for consistency and to prevent name conflicts.

enum class EAlignmentBaseline : uint8_t {
  kBaseline,
  kMiddle,
  kAuto,
  kAlphabetic,
  kBeforeEdge,
  kAfterEdge,
  kCentral,
  kTextBeforeEdge,
  kTextAfterEdge,
  kIdeographic,
  kHanging,
  kMathematical,
  kMaxEnumValue = kMathematical,
};

enum class EBackfaceVisibility : uint8_t {
  kHidden,
  kVisible,
  kMaxEnumValue = kVisible,
};

enum class EBaselineSource : uint8_t {
  kAuto,
  kFirst,
  kLast,
  kMaxEnumValue = kLast,
};

enum class EBlockEllipsis : uint8_t {
  kEllipsis,
  kNoEllipsis,
  kMaxEnumValue = kNoEllipsis,
};

enum class EBorderCollapse : uint8_t {
  kCollapse,
  kSeparate,
  kMaxEnumValue = kSeparate,
};

enum class EBorderStyle : uint8_t {
  kNone,
  kHidden,
  kInset,
  kGroove,
  kOutset,
  kRidge,
  kDotted,
  kDashed,
  kSolid,
  kDouble,
  kMaxEnumValue = kDouble,
};

enum class EBoxAlignment : uint8_t {
  kBaseline,
  kCenter,
  kStretch,
  kStart,
  kEnd,
  kMaxEnumValue = kEnd,
};

enum class EBoxDecorationBreak : uint8_t {
  kClone,
  kSlice,
  kMaxEnumValue = kSlice,
};

enum class EBoxDirection : uint8_t {
  kNormal,
  kReverse,
  kMaxEnumValue = kReverse,
};

enum class EBoxOrient : uint8_t {
  kHorizontal,
  kVertical,
  kMaxEnumValue = kVertical,
};

enum class EBoxPack : uint8_t {
  kCenter,
  kJustify,
  kStart,
  kEnd,
  kMaxEnumValue = kEnd,
};

enum class EBoxSizing : uint8_t {
  kBorderBox,
  kContentBox,
  kMaxEnumValue = kContentBox,
};

enum class EBreakBetween : uint8_t {
  kLeft,
  kRight,
  kAuto,
  kAvoid,
  kColumn,
  kAvoidPage,
  kPage,
  kRecto,
  kVerso,
  kAvoidColumn,
  kMaxEnumValue = kAvoidColumn,
};

enum class EBreakInside : uint8_t {
  kAuto,
  kAvoid,
  kAvoidPage,
  kAvoidColumn,
  kMaxEnumValue = kAvoidColumn,
};

enum class EBufferedRendering : uint8_t {
  kAuto,
  kStatic,
  kDynamic,
  kMaxEnumValue = kDynamic,
};

enum class ECaptionSide : uint8_t {
  kTop,
  kBottom,
  kMaxEnumValue = kBottom,
};

enum class ECaretAnimation : uint8_t {
  kAuto,
  kManual,
  kMaxEnumValue = kManual,
};

enum class ECaretShape : uint8_t {
  kBlock,
  kAuto,
  kBar,
  kUnderscore,
  kMaxEnumValue = kUnderscore,
};

enum class EClear : uint8_t {
  kNone,
  kLeft,
  kRight,
  kInlineStart,
  kInlineEnd,
  kBoth,
  kMaxEnumValue = kBoth,
};

enum class EColorInterpolation : uint8_t {
  kAuto,
  kSRGB,
  kLinearrgb,
  kMaxEnumValue = kLinearrgb,
};

enum class EColorRendering : uint8_t {
  kAuto,
  kOptimizespeed,
  kOptimizequality,
  kMaxEnumValue = kOptimizequality,
};

enum class EColumnFill : uint8_t {
  kAuto,
  kBalance,
  kMaxEnumValue = kBalance,
};

enum class EColumnSpan : uint8_t {
  kNone,
  kAll,
  kMaxEnumValue = kAll,
};

enum class EColumnWrap : uint8_t {
  kAuto,
  kNowrap,
  kWrap,
  kMaxEnumValue = kWrap,
};

enum class EContentVisibility : uint8_t {
  kHidden,
  kAuto,
  kVisible,
  kMaxEnumValue = kVisible,
};

enum class EContinue : uint8_t {
  kNormal,
  kCollapse,
  kWebkitLegacy,
  kMaxEnumValue = kWebkitLegacy,
};

enum class ECursor : uint8_t {
  kNone,
  kCopy,
  kAuto,
  kCrosshair,
  kDefault,
  kPointer,
  kMove,
  kVerticalText,
  kCell,
  kContextMenu,
  kAlias,
  kProgress,
  kNoDrop,
  kNotAllowed,
  kZoomIn,
  kZoomOut,
  kEResize,
  kNeResize,
  kNwResize,
  kNResize,
  kSeResize,
  kSwResize,
  kSResize,
  kWResize,
  kEwResize,
  kNsResize,
  kNeswResize,
  kNwseResize,
  kColResize,
  kRowResize,
  kText,
  kWait,
  kHelp,
  kAllScroll,
  kGrab,
  kGrabbing,
  kMaxEnumValue = kGrabbing,
};

enum class EDisplay : uint8_t {
  kInline,
  kBlock,
  kListItem,
  kInlineBlock,
  kTable,
  kInlineTable,
  kTableRowGroup,
  kTableHeaderGroup,
  kTableFooterGroup,
  kTableRow,
  kTableColumnGroup,
  kTableColumn,
  kTableCell,
  kTableCaption,
  kWebkitBox,
  kWebkitInlineBox,
  kFlex,
  kInlineFlex,
  kGrid,
  kInlineGrid,
  kContents,
  kFlowRoot,
  kNone,
  kLayoutCustom,
  kInlineLayoutCustom,
  kMath,
  kBlockMath,
  kInlineListItem,
  kFlowRootListItem,
  kInlineFlowRootListItem,
  kRuby,
  kBlockRuby,
  kRubyText,
  kGridLanes,
  kInlineGridLanes,
  kMaxEnumValue = kInlineGridLanes,
};

enum class EDominantBaseline : uint8_t {
  kMiddle,
  kAuto,
  kAlphabetic,
  kCentral,
  kTextBeforeEdge,
  kTextAfterEdge,
  kIdeographic,
  kHanging,
  kMathematical,
  kUseScript,
  kNoChange,
  kResetSize,
  kMaxEnumValue = kResetSize,
};

enum class EDraggableRegionMode : uint8_t {
  kNone,
  kMove,
  kNoDrag,
  kMaxEnumValue = kNoDrag,
};

enum class EEmptyCells : uint8_t {
  kHide,
  kShow,
  kMaxEnumValue = kShow,
};

enum class EFieldSizing : uint8_t {
  kFixed,
  kContent,
  kMaxEnumValue = kContent,
};

enum class EFlexDirection : uint8_t {
  kRow,
  kRowReverse,
  kColumn,
  kColumnReverse,
  kMaxEnumValue = kColumnReverse,
};

enum class EFloat : uint8_t {
  kNone,
  kLeft,
  kRight,
  kInlineStart,
  kInlineEnd,
  kMaxEnumValue = kInlineEnd,
};

enum class EForcedColorAdjust : uint8_t {
  kNone,
  kAuto,
  kPreserveParentColor,
  kMaxEnumValue = kPreserveParentColor,
};

enum class EFrameSizing : uint8_t {
  kAuto,
  kContentWidth,
  kContentHeight,
  kContentBlockSize,
  kContentInlineSize,
  kMaxEnumValue = kContentInlineSize,
};

enum class EGridLanesPack : uint8_t {
  kNormal,
  kDense,
  kMaxEnumValue = kDense,
};

enum class EImageRendering : uint8_t {
  kAuto,
  kPixelated,
  kCrispEdges,
  kWebkitOptimizeContrast,
  kMaxEnumValue = kWebkitOptimizeContrast,
};

enum class EInlineBlockBaselineEdge : uint8_t {
  kMarginBox,
  kBorderBox,
  kContentBox,
  kMaxEnumValue = kContentBox,
};

enum class EInsideLink : uint8_t {
  kNotInsideLink,
  kInsideUnvisitedLink,
  kInsideVisitedLink,
  kMaxEnumValue = kInsideVisitedLink,
};

enum class EInteractivity : uint8_t {
  kAuto,
  kInert,
  kMaxEnumValue = kInert,
};

enum class EInternalOverscrollContainer : uint8_t {
  kNone,
  kAuto,
  kMaxEnumValue = kAuto,
};

enum class EInternalOverscrollPosition : uint8_t {
  kNone,
  kAuto,
  kMaxEnumValue = kAuto,
};

enum class EInternalUnbounded : uint8_t {
  kNone,
  kActive,
  kMaxEnumValue = kActive,
};

enum class EInterpolateSize : uint8_t {
  kNumericOnly,
  kAllowKeywords,
  kMaxEnumValue = kAllowKeywords,
};

enum class EIsolation : uint8_t {
  kAuto,
  kIsolate,
  kMaxEnumValue = kIsolate,
};

enum class EListStylePosition : uint8_t {
  kOutside,
  kInside,
  kMaxEnumValue = kInside,
};

enum class EMaskType : uint8_t {
  kAlpha,
  kLuminance,
  kMaxEnumValue = kLuminance,
};

enum class EMathShift : uint8_t {
  kNormal,
  kCompact,
  kMaxEnumValue = kCompact,
};

enum class EMathStyle : uint8_t {
  kNormal,
  kCompact,
  kMaxEnumValue = kCompact,
};

enum class EMaxContentSizing : uint8_t {
  kAuto,
  kShrinkToFit,
  kMaxEnumValue = kShrinkToFit,
};

enum class EObjectFit : uint8_t {
  kNone,
  kContain,
  kCover,
  kFill,
  kScaleDown,
  kMaxEnumValue = kScaleDown,
};

enum class EOrder : uint8_t {
  kLogical,
  kVisual,
  kMaxEnumValue = kVisual,
};

enum class EOriginTrialTestProperty : uint8_t {
  kNone,
  kNormal,
  kMaxEnumValue = kNormal,
};

enum class EOverflow : uint8_t {
  kHidden,
  kAuto,
  kVisible,
  kOverlay,
  kScroll,
  kClip,
  kMaxEnumValue = kClip,
};

enum class EOverflowAnchor : uint8_t {
  kNone,
  kAuto,
  kVisible,
  kMaxEnumValue = kVisible,
};

enum class EOverflowWrap : uint8_t {
  kNormal,
  kBreakWord,
  kAnywhere,
  kMaxEnumValue = kAnywhere,
};

enum class EOverlay : uint8_t {
  kNone,
  kAuto,
  kMaxEnumValue = kAuto,
};

enum class EOverscrollBehavior : uint8_t {
  kNone,
  kAuto,
  kContain,
  kChain,
  kMaxEnumValue = kChain,
};

enum class EOverscrollContainerType : uint8_t {
  kNone,
  kAuto,
  kOverlay,
  kPush,
  kMaxEnumValue = kPush,
};

enum class EPageMarginSafety : uint8_t {
  kNone,
  kClamp,
  kAdd,
  kMaxEnumValue = kAdd,
};

enum class EPointerEvents : uint8_t {
  kNone,
  kAll,
  kAuto,
  kVisible,
  kVisiblepainted,
  kVisiblefill,
  kVisiblestroke,
  kPainted,
  kFill,
  kStroke,
  kBoundingBox,
  kMaxEnumValue = kBoundingBox,
};

enum class EPosition : uint8_t {
  kAbsolute,
  kFixed,
  kRelative,
  kStatic,
  kSticky,
  kMaxEnumValue = kSticky,
};

enum class EPositionTryOrder : uint8_t {
  kNormal,
  kMostWidth,
  kMostHeight,
  kMostBlockSize,
  kMostInlineSize,
  kMaxEnumValue = kMostInlineSize,
};

enum class EPrintColorAdjust : uint8_t {
  kEconomy,
  kExact,
  kMaxEnumValue = kExact,
};

enum class EReadingFlow : uint8_t {
  kNormal,
  kFlexVisual,
  kFlexFlow,
  kGridRows,
  kGridColumns,
  kGridOrder,
  kSourceOrder,
  kMaxEnumValue = kSourceOrder,
};

enum class EResize : uint8_t {
  kNone,
  kInline,
  kBlock,
  kBoth,
  kHorizontal,
  kVertical,
  kMaxEnumValue = kVertical,
};

enum class ERubyAlign : uint8_t {
  kCenter,
  kStart,
  kSpaceBetween,
  kSpaceAround,
  kMaxEnumValue = kSpaceAround,
};

enum class ERubyOverhang : uint8_t {
  kNone,
  kAuto,
  kSpaces,
  kMaxEnumValue = kSpaces,
};

enum class ERuleOverlap : uint8_t {
  kRowOverColumn,
  kColumnOverRow,
  kMaxEnumValue = kColumnOverRow,
};

enum class EScrollAxisLock : uint8_t {
  kNone,
  kAuto,
  kMaxEnumValue = kAuto,
};

enum class EScrollInitialTarget : uint8_t {
  kNone,
  kNearest,
  kMaxEnumValue = kNearest,
};

enum class EScrollSnapStop : uint8_t {
  kNormal,
  kAlways,
  kBefore,
  kMaxEnumValue = kBefore,
};

enum class EScrollTargetGroup : uint8_t {
  kNone,
  kAuto,
  kMaxEnumValue = kAuto,
};

enum class EScrollbarWidth : uint8_t {
  kNone,
  kAuto,
  kThin,
  kMaxEnumValue = kThin,
};

enum class EShapeRendering : uint8_t {
  kAuto,
  kOptimizespeed,
  kGeometricprecision,
  kCrispedges,
  kMaxEnumValue = kCrispedges,
};

enum class ESpeak : uint8_t {
  kNone,
  kNormal,
  kSpellOut,
  kDigits,
  kLiteralPunctuation,
  kNoPunctuation,
  kMaxEnumValue = kNoPunctuation,
};

enum class ETableLayout : uint8_t {
  kAuto,
  kFixed,
  kMaxEnumValue = kFixed,
};

enum class ETextAlign : uint8_t {
  kLeft,
  kRight,
  kCenter,
  kJustify,
  kMatchParent,
  kWebkitLeft,
  kWebkitRight,
  kWebkitCenter,
  kStart,
  kEnd,
  kMaxEnumValue = kEnd,
};

enum class ETextAlignLast : uint8_t {
  kLeft,
  kRight,
  kCenter,
  kJustify,
  kMatchParent,
  kAuto,
  kStart,
  kEnd,
  kMaxEnumValue = kEnd,
};

enum class ETextAnchor : uint8_t {
  kMiddle,
  kStart,
  kEnd,
  kMaxEnumValue = kEnd,
};

enum class ETextAutospace : uint8_t {
  kNormal,
  kNoAutospace,
  kMaxEnumValue = kNoAutospace,
};

enum class ETextBoxTrim : uint8_t {
  kNone,
  kTrimBoth,
  kTrimEnd,
  kTrimStart,
  kMaxEnumValue = kTrimStart,
};

enum class ETextCombine : uint8_t {
  kNone,
  kAll,
  kMaxEnumValue = kAll,
};

enum class ETextDecorationSkipInk : uint8_t {
  kNone,
  kAll,
  kAuto,
  kMaxEnumValue = kAuto,
};

enum class ETextDecorationStyle : uint8_t {
  kDotted,
  kDashed,
  kSolid,
  kDouble,
  kWavy,
  kMaxEnumValue = kWavy,
};

enum class ETextOrientation : uint8_t {
  kMixed,
  kSideways,
  kSidewaysRight,
  kUpright,
  kMaxEnumValue = kUpright,
};

enum class ETextSecurity : uint8_t {
  kNone,
  kDisc,
  kCircle,
  kSquare,
  kMaxEnumValue = kSquare,
};

enum class ETextTransform : unsigned {
  kNone = 0,
  kCapitalize = 1,
  kUppercase = 2,
  kLowercase = 4,
  kFullWidth = 8,
  kFullSizeKana = 16,
  kMathAuto = 32,
};

static const int kETextTransformBits = 6;

inline ETextTransform operator|(ETextTransform a, ETextTransform b) {
  return static_cast<ETextTransform>(
    static_cast<unsigned>(a) | static_cast<unsigned>(b)
  );
}
inline ETextTransform& operator|=(ETextTransform& a, ETextTransform b) {
  return a = a | b;
}

inline ETextTransform operator^(ETextTransform a, ETextTransform b) {
  return static_cast<ETextTransform>(
    static_cast<unsigned>(a) ^ static_cast<unsigned>(b)
  );
}
inline ETextTransform& operator^=(ETextTransform& a, ETextTransform b) {
  return a = a ^ b;
}

inline ETextTransform operator&(ETextTransform a, ETextTransform b) {
  return static_cast<ETextTransform>(
    static_cast<unsigned>(a) & static_cast<unsigned>(b)
  );
}
inline ETextTransform& operator&=(ETextTransform& a, ETextTransform b) {
  return a = a & b;
}

inline ETextTransform operator~(ETextTransform x) {
  return static_cast<ETextTransform>(~static_cast<unsigned>(x));
}

enum class ETransformBox : uint8_t {
  kBorderBox,
  kContentBox,
  kFillBox,
  kViewBox,
  kStrokeBox,
  kMaxEnumValue = kStrokeBox,
};

enum class ETransformStyle3D : uint8_t {
  kFlat,
  kPreserve3d,
  kMaxEnumValue = kPreserve3d,
};

enum class EUserDrag : uint8_t {
  kNone,
  kAuto,
  kElement,
  kMaxEnumValue = kElement,
};

enum class EUserModify : uint8_t {
  kReadOnly,
  kReadWrite,
  kReadWritePlaintextOnly,
  kMaxEnumValue = kReadWritePlaintextOnly,
};

enum class EUserSelect : uint8_t {
  kNone,
  kAll,
  kAuto,
  kText,
  kContain,
  kMaxEnumValue = kContain,
};

enum class EVectorEffect : uint8_t {
  kNone,
  kNonScalingStroke,
  kMaxEnumValue = kNonScalingStroke,
};

enum class EViewTransitionScope : uint8_t {
  kNone,
  kAll,
  kMaxEnumValue = kAll,
};

enum class EVisibility : uint8_t {
  kHidden,
  kVisible,
  kCollapse,
  kMaxEnumValue = kCollapse,
};

enum class EWordBreak : uint8_t {
  kNormal,
  kBreakAll,
  kKeepAll,
  kAutoPhrase,
  kBreakWord,
  kMaxEnumValue = kBreakWord,
};

enum class Hyphens : uint8_t {
  kNone,
  kAuto,
  kManual,
  kMaxEnumValue = kManual,
};

enum class LineBreak : uint8_t {
  kNormal,
  kAuto,
  kLoose,
  kStrict,
  kAfterWhiteSpace,
  kAnywhere,
  kMaxEnumValue = kAnywhere,
};

enum class RubyPosition : uint8_t {
  kOver,
  kUnder,
  kMaxEnumValue = kUnder,
};

enum class RuleBreak : uint8_t {
  kNone,
  kNormal,
  kIntersection,
  kMaxEnumValue = kIntersection,
};

enum class RuleVisibilityItems : uint8_t {
  kAll,
  kNormal,
  kAround,
  kBetween,
  kMaxEnumValue = kBetween,
};

enum class TextDecorationLine : unsigned {
  kNone = 0,
  kUnderline = 1,
  kOverline = 2,
  kLineThrough = 4,
  kBlink = 8,
  kSpellingError = 16,
  kGrammarError = 32,
};

static const int kTextDecorationLineBits = 6;

inline TextDecorationLine operator|(TextDecorationLine a, TextDecorationLine b) {
  return static_cast<TextDecorationLine>(
    static_cast<unsigned>(a) | static_cast<unsigned>(b)
  );
}
inline TextDecorationLine& operator|=(TextDecorationLine& a, TextDecorationLine b) {
  return a = a | b;
}

inline TextDecorationLine operator^(TextDecorationLine a, TextDecorationLine b) {
  return static_cast<TextDecorationLine>(
    static_cast<unsigned>(a) ^ static_cast<unsigned>(b)
  );
}
inline TextDecorationLine& operator^=(TextDecorationLine& a, TextDecorationLine b) {
  return a = a ^ b;
}

inline TextDecorationLine operator&(TextDecorationLine a, TextDecorationLine b) {
  return static_cast<TextDecorationLine>(
    static_cast<unsigned>(a) & static_cast<unsigned>(b)
  );
}
inline TextDecorationLine& operator&=(TextDecorationLine& a, TextDecorationLine b) {
  return a = a & b;
}

inline TextDecorationLine operator~(TextDecorationLine x) {
  return static_cast<TextDecorationLine>(~static_cast<unsigned>(x));
}

enum class TextEmphasisFill : uint8_t {
  kFilled,
  kOpen,
  kMaxEnumValue = kOpen,
};

enum class TextEmphasisMark : uint8_t {
  kNone,
  kAuto,
  kDot,
  kCircle,
  kDoubleCircle,
  kTriangle,
  kSesame,
  kCustom,
  kMaxEnumValue = kCustom,
};

enum class TextWrapMode : uint8_t {
  kNowrap,
  kWrap,
  kMaxEnumValue = kWrap,
};

enum class TextWrapStyle : uint8_t {
  kAuto,
  kPretty,
  kBalance,
  kStable,
  kMaxEnumValue = kStable,
};


#if DCHECK_IS_ON() || defined(FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION)
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EAlignmentBaseline);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EBackfaceVisibility);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EBaselineSource);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EBlockEllipsis);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EBorderCollapse);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EBorderStyle);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EBoxAlignment);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EBoxDecorationBreak);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EBoxDirection);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EBoxOrient);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EBoxPack);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EBoxSizing);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EBreakBetween);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EBreakInside);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EBufferedRendering);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ECaptionSide);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ECaretAnimation);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ECaretShape);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EClear);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EColorInterpolation);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EColorRendering);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EColumnFill);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EColumnSpan);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EColumnWrap);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EContentVisibility);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EContinue);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ECursor);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EDisplay);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EDominantBaseline);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EDraggableRegionMode);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EEmptyCells);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EFieldSizing);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EFlexDirection);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EFloat);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EForcedColorAdjust);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EFrameSizing);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EGridLanesPack);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EImageRendering);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EInlineBlockBaselineEdge);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EInsideLink);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EInteractivity);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EInternalOverscrollContainer);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EInternalOverscrollPosition);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EInternalUnbounded);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EInterpolateSize);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EIsolation);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EListStylePosition);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EMaskType);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EMathShift);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EMathStyle);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EMaxContentSizing);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EObjectFit);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EOrder);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EOriginTrialTestProperty);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EOverflow);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EOverflowAnchor);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EOverflowWrap);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EOverlay);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EOverscrollBehavior);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EOverscrollContainerType);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EPageMarginSafety);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EPointerEvents);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EPosition);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EPositionTryOrder);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EPrintColorAdjust);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EReadingFlow);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EResize);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ERubyAlign);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ERubyOverhang);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ERuleOverlap);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EScrollAxisLock);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EScrollInitialTarget);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EScrollSnapStop);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EScrollTargetGroup);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EScrollbarWidth);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EShapeRendering);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ESpeak);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ETableLayout);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ETextAlign);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ETextAlignLast);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ETextAnchor);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ETextAutospace);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ETextBoxTrim);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ETextCombine);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ETextDecorationSkipInk);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ETextDecorationStyle);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ETextOrientation);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ETextSecurity);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ETextTransform);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ETransformBox);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const ETransformStyle3D);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EUserDrag);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EUserModify);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EUserSelect);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EVectorEffect);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EViewTransitionScope);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EVisibility);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const EWordBreak);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const Hyphens);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const LineBreak);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const RubyPosition);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const RuleBreak);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const RuleVisibilityItems);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const TextDecorationLine);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const TextEmphasisFill);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const TextEmphasisMark);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const TextWrapMode);
CORE_EXPORT std::ostream& operator<<(std::ostream&, const TextWrapStyle);
#endif

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_BASE_CONSTANTS_H_
