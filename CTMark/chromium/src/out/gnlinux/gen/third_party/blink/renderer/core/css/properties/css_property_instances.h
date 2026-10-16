// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// clang-format off

// NOTE: Since all the getters declared in this file are returning forward-declared
// types, you will need to include the right one of these (usually longhands.h)
// if you wish the compiler to see that they inherit from CSSProperty:
//
// #include "third_party/blink/renderer/core/css/properties/longhands.h"
// #include "third_party/blink/renderer/core/css/properties/shorthands.h"

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PROPERTY_INSTANCES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PROPERTY_INSTANCES_H_

#include "third_party/blink/renderer/core/css/css_property_names.h"

namespace blink {
namespace css_longhand { class ColorScheme; }
namespace css_longhand { class ForcedColorAdjust; }
namespace css_longhand { class MathDepth; }
namespace css_longhand { class Position; }
namespace css_longhand { class PositionAnchor; }
namespace css_longhand { class TextSizeAdjust; }
namespace css_longhand { class InternalVisitedColor; }
namespace css_longhand { class Appearance; }
namespace css_longhand { class Color; }
namespace css_longhand { class Direction; }
namespace css_longhand { class FontFamily; }
namespace css_longhand { class FontFeatureSettings; }
namespace css_longhand { class FontKerning; }
namespace css_longhand { class FontLanguageOverride; }
namespace css_longhand { class FontOpticalSizing; }
namespace css_longhand { class FontPalette; }
namespace css_longhand { class FontSize; }
namespace css_longhand { class FontSizeAdjust; }
namespace css_longhand { class FontStretch; }
namespace css_longhand { class FontStyle; }
namespace css_longhand { class FontSynthesisSmallCaps; }
namespace css_longhand { class FontSynthesisStyle; }
namespace css_longhand { class FontSynthesisWeight; }
namespace css_longhand { class FontVariantAlternates; }
namespace css_longhand { class FontVariantCaps; }
namespace css_longhand { class FontVariantEastAsian; }
namespace css_longhand { class FontVariantEmoji; }
namespace css_longhand { class FontVariantLigatures; }
namespace css_longhand { class FontVariantNumeric; }
namespace css_longhand { class FontVariantPosition; }
namespace css_longhand { class FontVariationSettings; }
namespace css_longhand { class FontWeight; }
namespace css_longhand { class PositionArea; }
namespace css_longhand { class TextOrientation; }
namespace css_longhand { class TextRendering; }
namespace css_longhand { class TextSpacingTrim; }
namespace css_longhand { class WebkitFontSmoothing; }
namespace css_longhand { class WebkitLocale; }
namespace css_longhand { class WebkitTextOrientation; }
namespace css_longhand { class WebkitWritingMode; }
namespace css_longhand { class WritingMode; }
namespace css_longhand { class Zoom; }
namespace css_longhand { class InternalForcedVisitedColor; }
namespace css_longhand { class InternalVisitedBackgroundColor; }
namespace css_longhand { class InternalVisitedBorderBlockEndColor; }
namespace css_longhand { class InternalVisitedBorderBlockStartColor; }
namespace css_longhand { class InternalVisitedBorderBottomColor; }
namespace css_longhand { class InternalVisitedBorderInlineEndColor; }
namespace css_longhand { class InternalVisitedBorderInlineStartColor; }
namespace css_longhand { class InternalVisitedBorderLeftColor; }
namespace css_longhand { class InternalVisitedBorderRightColor; }
namespace css_longhand { class InternalVisitedBorderTopColor; }
namespace css_longhand { class InternalVisitedCaretColor; }
namespace css_longhand { class InternalVisitedColumnRuleColor; }
namespace css_longhand { class InternalVisitedFill; }
namespace css_longhand { class InternalVisitedOutlineColor; }
namespace css_longhand { class InternalVisitedStroke; }
namespace css_longhand { class InternalVisitedTextDecorationColor; }
namespace css_longhand { class InternalVisitedTextEmphasisColor; }
namespace css_longhand { class InternalVisitedTextFillColor; }
namespace css_longhand { class InternalVisitedTextStrokeColor; }
namespace css_longhand { class AccentColor; }
namespace css_longhand { class AdditiveSymbols; }
namespace css_longhand { class AlignContent; }
namespace css_longhand { class AlignItems; }
namespace css_longhand { class AlignSelf; }
namespace css_longhand { class AlignmentBaseline; }
namespace css_longhand { class All; }
namespace css_longhand { class AlternativeWebkitLineClampLonghand; }
namespace css_longhand { class AnchorName; }
namespace css_longhand { class AnchorScope; }
namespace css_longhand { class AnimationComposition; }
namespace css_longhand { class AnimationDelay; }
namespace css_longhand { class AnimationDirection; }
namespace css_longhand { class AnimationDuration; }
namespace css_longhand { class AnimationFillMode; }
namespace css_longhand { class AnimationIterationCount; }
namespace css_longhand { class AnimationName; }
namespace css_longhand { class AnimationPlayState; }
namespace css_longhand { class AnimationRangeEnd; }
namespace css_longhand { class AnimationRangeStart; }
namespace css_longhand { class AnimationTimeline; }
namespace css_longhand { class AnimationTimingFunction; }
namespace css_longhand { class AnimationTrigger; }
namespace css_longhand { class AppRegion; }
namespace css_longhand { class AscentOverride; }
namespace css_longhand { class AspectRatio; }
namespace css_longhand { class BackdropFilter; }
namespace css_longhand { class BackfaceVisibility; }
namespace css_longhand { class BackgroundAttachment; }
namespace css_longhand { class BackgroundBlendMode; }
namespace css_longhand { class BackgroundClip; }
namespace css_longhand { class BackgroundColor; }
namespace css_longhand { class BackgroundImage; }
namespace css_longhand { class BackgroundOrigin; }
namespace css_longhand { class BackgroundPositionX; }
namespace css_longhand { class BackgroundPositionY; }
namespace css_longhand { class BackgroundRepeat; }
namespace css_longhand { class BackgroundSize; }
namespace css_longhand { class BasePalette; }
namespace css_longhand { class BaseUrl; }
namespace css_longhand { class BaselineShift; }
namespace css_longhand { class BaselineSource; }
namespace css_longhand { class BlockEllipsis; }
namespace css_longhand { class BlockSize; }
namespace css_longhand { class BorderBlockEndColor; }
namespace css_longhand { class BorderBlockEndStyle; }
namespace css_longhand { class BorderBlockEndWidth; }
namespace css_longhand { class BorderBlockStartColor; }
namespace css_longhand { class BorderBlockStartStyle; }
namespace css_longhand { class BorderBlockStartWidth; }
namespace css_longhand { class BorderBottomColor; }
namespace css_longhand { class BorderBottomLeftRadius; }
namespace css_longhand { class BorderBottomRightRadius; }
namespace css_longhand { class BorderBottomStyle; }
namespace css_longhand { class BorderBottomWidth; }
namespace css_longhand { class BorderCollapse; }
namespace css_longhand { class BorderEndEndRadius; }
namespace css_longhand { class BorderEndStartRadius; }
namespace css_longhand { class BorderImageOutset; }
namespace css_longhand { class BorderImageRepeat; }
namespace css_longhand { class BorderImageSlice; }
namespace css_longhand { class BorderImageSource; }
namespace css_longhand { class BorderImageWidth; }
namespace css_longhand { class BorderInlineEndColor; }
namespace css_longhand { class BorderInlineEndStyle; }
namespace css_longhand { class BorderInlineEndWidth; }
namespace css_longhand { class BorderInlineStartColor; }
namespace css_longhand { class BorderInlineStartStyle; }
namespace css_longhand { class BorderInlineStartWidth; }
namespace css_longhand { class BorderLeftColor; }
namespace css_longhand { class BorderLeftStyle; }
namespace css_longhand { class BorderLeftWidth; }
namespace css_longhand { class BorderRightColor; }
namespace css_longhand { class BorderRightStyle; }
namespace css_longhand { class BorderRightWidth; }
namespace css_longhand { class BorderShape; }
namespace css_longhand { class BorderStartEndRadius; }
namespace css_longhand { class BorderStartStartRadius; }
namespace css_longhand { class BorderTopColor; }
namespace css_longhand { class BorderTopLeftRadius; }
namespace css_longhand { class BorderTopRightRadius; }
namespace css_longhand { class BorderTopStyle; }
namespace css_longhand { class BorderTopWidth; }
namespace css_longhand { class Bottom; }
namespace css_longhand { class BoxDecorationBreak; }
namespace css_longhand { class BoxShadow; }
namespace css_longhand { class BoxSizing; }
namespace css_longhand { class BreakAfter; }
namespace css_longhand { class BreakBefore; }
namespace css_longhand { class BreakInside; }
namespace css_longhand { class BufferedRendering; }
namespace css_longhand { class CaptionSide; }
namespace css_longhand { class CaretAnimation; }
namespace css_longhand { class CaretColor; }
namespace css_longhand { class CaretShape; }
namespace css_longhand { class Clear; }
namespace css_longhand { class Clip; }
namespace css_longhand { class ClipPath; }
namespace css_longhand { class ClipRule; }
namespace css_longhand { class ColorInterpolation; }
namespace css_longhand { class ColorInterpolationFilters; }
namespace css_longhand { class ColorRendering; }
namespace css_longhand { class ColumnCount; }
namespace css_longhand { class ColumnFill; }
namespace css_longhand { class ColumnGap; }
namespace css_longhand { class ColumnHeight; }
namespace css_longhand { class ColumnRuleBreak; }
namespace css_longhand { class ColumnRuleColor; }
namespace css_longhand { class ColumnRuleInsetCapEnd; }
namespace css_longhand { class ColumnRuleInsetCapStart; }
namespace css_longhand { class ColumnRuleInsetJunctionEnd; }
namespace css_longhand { class ColumnRuleInsetJunctionStart; }
namespace css_longhand { class ColumnRuleStyle; }
namespace css_longhand { class ColumnRuleVisibilityItems; }
namespace css_longhand { class ColumnRuleWidth; }
namespace css_longhand { class ColumnSpan; }
namespace css_longhand { class ColumnWidth; }
namespace css_longhand { class ColumnWrap; }
namespace css_longhand { class Contain; }
namespace css_longhand { class ContainIntrinsicBlockSize; }
namespace css_longhand { class ContainIntrinsicHeight; }
namespace css_longhand { class ContainIntrinsicInlineSize; }
namespace css_longhand { class ContainIntrinsicWidth; }
namespace css_longhand { class ContainerName; }
namespace css_longhand { class ContainerType; }
namespace css_longhand { class Content; }
namespace css_longhand { class ContentVisibility; }
namespace css_longhand { class Continue; }
namespace css_longhand { class CornerBottomLeftShape; }
namespace css_longhand { class CornerBottomRightShape; }
namespace css_longhand { class CornerEndEndShape; }
namespace css_longhand { class CornerEndStartShape; }
namespace css_longhand { class CornerStartEndShape; }
namespace css_longhand { class CornerStartStartShape; }
namespace css_longhand { class CornerTopLeftShape; }
namespace css_longhand { class CornerTopRightShape; }
namespace css_longhand { class CounterIncrement; }
namespace css_longhand { class CounterReset; }
namespace css_longhand { class CounterSet; }
namespace css_longhand { class Cursor; }
namespace css_longhand { class Cx; }
namespace css_longhand { class Cy; }
namespace css_longhand { class D; }
namespace css_longhand { class DescentOverride; }
namespace css_longhand { class Display; }
namespace css_longhand { class DominantBaseline; }
namespace css_longhand { class DynamicRangeLimit; }
namespace css_longhand { class EmptyCells; }
namespace css_longhand { class Fallback; }
namespace css_longhand { class FieldSizing; }
namespace css_longhand { class Fill; }
namespace css_longhand { class FillOpacity; }
namespace css_longhand { class FillRule; }
namespace css_longhand { class Filter; }
namespace css_longhand { class FlexBasis; }
namespace css_longhand { class FlexDirection; }
namespace css_longhand { class FlexGrow; }
namespace css_longhand { class FlexLineCount; }
namespace css_longhand { class FlexShrink; }
namespace css_longhand { class FlexWrap; }
namespace css_longhand { class Float; }
namespace css_longhand { class FloodColor; }
namespace css_longhand { class FloodOpacity; }
namespace css_longhand { class FlowTolerance; }
namespace css_longhand { class FontDisplay; }
namespace css_longhand { class FrameSizing; }
namespace css_longhand { class GridAutoColumns; }
namespace css_longhand { class GridAutoFlow; }
namespace css_longhand { class GridAutoRows; }
namespace css_longhand { class GridColumnEnd; }
namespace css_longhand { class GridColumnStart; }
namespace css_longhand { class GridLanesDirection; }
namespace css_longhand { class GridLanesPack; }
namespace css_longhand { class GridRowEnd; }
namespace css_longhand { class GridRowStart; }
namespace css_longhand { class GridTemplateAreas; }
namespace css_longhand { class GridTemplateColumns; }
namespace css_longhand { class GridTemplateRows; }
namespace css_longhand { class HangingPunctuation; }
namespace css_longhand { class Hash; }
namespace css_longhand { class Height; }
namespace css_longhand { class Hostname; }
namespace css_longhand { class HyphenateCharacter; }
namespace css_longhand { class HyphenateLimitChars; }
namespace css_longhand { class Hyphens; }
namespace css_longhand { class ImageAnimation; }
namespace css_longhand { class ImageOrientation; }
namespace css_longhand { class ImageRendering; }
namespace css_longhand { class Inherits; }
namespace css_longhand { class InitialLetter; }
namespace css_longhand { class InitialValue; }
namespace css_longhand { class InlineSize; }
namespace css_longhand { class InsetBlockEnd; }
namespace css_longhand { class InsetBlockStart; }
namespace css_longhand { class InsetInlineEnd; }
namespace css_longhand { class InsetInlineStart; }
namespace css_longhand { class Interactivity; }
namespace css_longhand { class InterestDelayEnd; }
namespace css_longhand { class InterestDelayStart; }
namespace css_longhand { class InternalAlignContentBlock; }
namespace css_longhand { class InternalEmptyLineHeight; }
namespace css_longhand { class InternalFontSizeDelta; }
namespace css_longhand { class InternalForcedBackgroundColor; }
namespace css_longhand { class InternalForcedBorderColor; }
namespace css_longhand { class InternalForcedColor; }
namespace css_longhand { class InternalForcedOutlineColor; }
namespace css_longhand { class InternalOverscrollContainer; }
namespace css_longhand { class InternalOverscrollPosition; }
namespace css_longhand { class InternalUnbounded; }
namespace css_longhand { class InterpolateSize; }
namespace css_longhand { class Isolation; }
namespace css_longhand { class JustifyContent; }
namespace css_longhand { class JustifyItems; }
namespace css_longhand { class JustifySelf; }
namespace css_longhand { class Left; }
namespace css_longhand { class LetterSpacing; }
namespace css_longhand { class LightingColor; }
namespace css_longhand { class LineBreak; }
namespace css_longhand { class LineClamp; }
namespace css_longhand { class LineGapOverride; }
namespace css_longhand { class LineHeight; }
namespace css_longhand { class ListStyleImage; }
namespace css_longhand { class ListStylePosition; }
namespace css_longhand { class ListStyleType; }
namespace css_longhand { class MarginBlockEnd; }
namespace css_longhand { class MarginBlockStart; }
namespace css_longhand { class MarginBottom; }
namespace css_longhand { class MarginInlineEnd; }
namespace css_longhand { class MarginInlineStart; }
namespace css_longhand { class MarginLeft; }
namespace css_longhand { class MarginRight; }
namespace css_longhand { class MarginTop; }
namespace css_longhand { class MarginTrim; }
namespace css_longhand { class MarkerEnd; }
namespace css_longhand { class MarkerMid; }
namespace css_longhand { class MarkerStart; }
namespace css_longhand { class MaskClip; }
namespace css_longhand { class MaskImage; }
namespace css_longhand { class MaskMode; }
namespace css_longhand { class MaskOrigin; }
namespace css_longhand { class MaskRepeat; }
namespace css_longhand { class MaskSize; }
namespace css_longhand { class MaskType; }
namespace css_longhand { class MathShift; }
namespace css_longhand { class MathStyle; }
namespace css_longhand { class MaxBlockSize; }
namespace css_longhand { class MaxContentSizing; }
namespace css_longhand { class MaxHeight; }
namespace css_longhand { class MaxInlineSize; }
namespace css_longhand { class MaxLines; }
namespace css_longhand { class MaxWidth; }
namespace css_longhand { class MinBlockSize; }
namespace css_longhand { class MinHeight; }
namespace css_longhand { class MinInlineSize; }
namespace css_longhand { class MinWidth; }
namespace css_longhand { class MixBlendMode; }
namespace css_longhand { class Navigation; }
namespace css_longhand { class Negative; }
namespace css_longhand { class ObjectFit; }
namespace css_longhand { class ObjectPosition; }
namespace css_longhand { class ObjectViewBox; }
namespace css_longhand { class OffsetAnchor; }
namespace css_longhand { class OffsetDistance; }
namespace css_longhand { class OffsetPath; }
namespace css_longhand { class OffsetPosition; }
namespace css_longhand { class OffsetRotate; }
namespace css_longhand { class Opacity; }
namespace css_longhand { class Order; }
namespace css_longhand { class OriginTrialTestProperty; }
namespace css_longhand { class Orphans; }
namespace css_longhand { class OutlineColor; }
namespace css_longhand { class OutlineOffset; }
namespace css_longhand { class OutlineStyle; }
namespace css_longhand { class OutlineWidth; }
namespace css_longhand { class OverflowAnchor; }
namespace css_longhand { class OverflowBlock; }
namespace css_longhand { class OverflowClipMargin; }
namespace css_longhand { class OverflowInline; }
namespace css_longhand { class OverflowWrap; }
namespace css_longhand { class OverflowX; }
namespace css_longhand { class OverflowY; }
namespace css_longhand { class Overlay; }
namespace css_longhand { class OverrideColors; }
namespace css_longhand { class OverscrollBehaviorBlock; }
namespace css_longhand { class OverscrollBehaviorInline; }
namespace css_longhand { class OverscrollBehaviorX; }
namespace css_longhand { class OverscrollBehaviorY; }
namespace css_longhand { class OverscrollContainerType; }
namespace css_longhand { class Pad; }
namespace css_longhand { class PaddingBlockEnd; }
namespace css_longhand { class PaddingBlockStart; }
namespace css_longhand { class PaddingBottom; }
namespace css_longhand { class PaddingInlineEnd; }
namespace css_longhand { class PaddingInlineStart; }
namespace css_longhand { class PaddingLeft; }
namespace css_longhand { class PaddingRight; }
namespace css_longhand { class PaddingTop; }
namespace css_longhand { class Page; }
namespace css_longhand { class PageMarginSafety; }
namespace css_longhand { class PageOrientation; }
namespace css_longhand { class PaintOrder; }
namespace css_longhand { class PathLength; }
namespace css_longhand { class Pathname; }
namespace css_longhand { class Pattern; }
namespace css_longhand { class Perspective; }
namespace css_longhand { class PerspectiveOrigin; }
namespace css_longhand { class PointerEvents; }
namespace css_longhand { class Port; }
namespace css_longhand { class PositionTryFallbacks; }
namespace css_longhand { class PositionTryOrder; }
namespace css_longhand { class PositionVisibility; }
namespace css_longhand { class Prefix; }
namespace css_longhand { class PrintColorAdjust; }
namespace css_longhand { class Protocol; }
namespace css_longhand { class Quotes; }
namespace css_longhand { class R; }
namespace css_longhand { class Range; }
namespace css_longhand { class ReadingFlow; }
namespace css_longhand { class ReadingOrder; }
namespace css_longhand { class Resize; }
namespace css_longhand { class Result; }
namespace css_longhand { class Right; }
namespace css_longhand { class Rotate; }
namespace css_longhand { class RowGap; }
namespace css_longhand { class RowRuleBreak; }
namespace css_longhand { class RowRuleColor; }
namespace css_longhand { class RowRuleInsetCapEnd; }
namespace css_longhand { class RowRuleInsetCapStart; }
namespace css_longhand { class RowRuleInsetJunctionEnd; }
namespace css_longhand { class RowRuleInsetJunctionStart; }
namespace css_longhand { class RowRuleStyle; }
namespace css_longhand { class RowRuleVisibilityItems; }
namespace css_longhand { class RowRuleWidth; }
namespace css_longhand { class RubyAlign; }
namespace css_longhand { class RubyOverhang; }
namespace css_longhand { class RubyPosition; }
namespace css_longhand { class RuleOverlap; }
namespace css_longhand { class Rx; }
namespace css_longhand { class Ry; }
namespace css_longhand { class Scale; }
namespace css_longhand { class ScrollAxisLock; }
namespace css_longhand { class ScrollBehavior; }
namespace css_longhand { class ScrollInitialTarget; }
namespace css_longhand { class ScrollMarginBlockEnd; }
namespace css_longhand { class ScrollMarginBlockStart; }
namespace css_longhand { class ScrollMarginBottom; }
namespace css_longhand { class ScrollMarginInlineEnd; }
namespace css_longhand { class ScrollMarginInlineStart; }
namespace css_longhand { class ScrollMarginLeft; }
namespace css_longhand { class ScrollMarginRight; }
namespace css_longhand { class ScrollMarginTop; }
namespace css_longhand { class ScrollMarkerGroup; }
namespace css_longhand { class ScrollPaddingBlockEnd; }
namespace css_longhand { class ScrollPaddingBlockStart; }
namespace css_longhand { class ScrollPaddingBottom; }
namespace css_longhand { class ScrollPaddingInlineEnd; }
namespace css_longhand { class ScrollPaddingInlineStart; }
namespace css_longhand { class ScrollPaddingLeft; }
namespace css_longhand { class ScrollPaddingRight; }
namespace css_longhand { class ScrollPaddingTop; }
namespace css_longhand { class ScrollSnapAlign; }
namespace css_longhand { class ScrollSnapStop; }
namespace css_longhand { class ScrollSnapType; }
namespace css_longhand { class ScrollTargetGroup; }
namespace css_longhand { class ScrollTimelineAxis; }
namespace css_longhand { class ScrollTimelineName; }
namespace css_longhand { class ScrollbarColor; }
namespace css_longhand { class ScrollbarGutter; }
namespace css_longhand { class ScrollbarWidth; }
namespace css_longhand { class Search; }
namespace css_longhand { class ShapeImageThreshold; }
namespace css_longhand { class ShapeMargin; }
namespace css_longhand { class ShapeOutside; }
namespace css_longhand { class ShapeRendering; }
namespace css_longhand { class Size; }
namespace css_longhand { class SizeAdjust; }
namespace css_longhand { class Speak; }
namespace css_longhand { class SpeakAs; }
namespace css_longhand { class Src; }
namespace css_longhand { class StopColor; }
namespace css_longhand { class StopOpacity; }
namespace css_longhand { class Stroke; }
namespace css_longhand { class StrokeDasharray; }
namespace css_longhand { class StrokeDashoffset; }
namespace css_longhand { class StrokeLinecap; }
namespace css_longhand { class StrokeLinejoin; }
namespace css_longhand { class StrokeMiterlimit; }
namespace css_longhand { class StrokeOpacity; }
namespace css_longhand { class StrokeWidth; }
namespace css_longhand { class Suffix; }
namespace css_longhand { class Symbols; }
namespace css_longhand { class Syntax; }
namespace css_longhand { class System; }
namespace css_longhand { class TabSize; }
namespace css_longhand { class TableLayout; }
namespace css_longhand { class TextAlign; }
namespace css_longhand { class TextAlignLast; }
namespace css_longhand { class TextAnchor; }
namespace css_longhand { class TextAutospace; }
namespace css_longhand { class TextBoxEdge; }
namespace css_longhand { class TextBoxTrim; }
namespace css_longhand { class TextCombineUpright; }
namespace css_longhand { class TextDecorationColor; }
namespace css_longhand { class TextDecorationInset; }
namespace css_longhand { class TextDecorationLine; }
namespace css_longhand { class TextDecorationSkipInk; }
namespace css_longhand { class TextDecorationSkipSpaces; }
namespace css_longhand { class TextDecorationStyle; }
namespace css_longhand { class TextDecorationThickness; }
namespace css_longhand { class TextEmphasisColor; }
namespace css_longhand { class TextEmphasisPosition; }
namespace css_longhand { class TextEmphasisStyle; }
namespace css_longhand { class TextFit; }
namespace css_longhand { class TextIndent; }
namespace css_longhand { class TextJustify; }
namespace css_longhand { class TextOverflow; }
namespace css_longhand { class TextShadow; }
namespace css_longhand { class TextTransform; }
namespace css_longhand { class TextUnderlineOffset; }
namespace css_longhand { class TextUnderlinePosition; }
namespace css_longhand { class TextWrapMode; }
namespace css_longhand { class TextWrapStyle; }
namespace css_longhand { class TimelineScope; }
namespace css_longhand { class TimelineTriggerActivationRangeEnd; }
namespace css_longhand { class TimelineTriggerActivationRangeStart; }
namespace css_longhand { class TimelineTriggerActiveRangeEnd; }
namespace css_longhand { class TimelineTriggerActiveRangeStart; }
namespace css_longhand { class TimelineTriggerName; }
namespace css_longhand { class TimelineTriggerSource; }
namespace css_longhand { class Top; }
namespace css_longhand { class TouchAction; }
namespace css_longhand { class Transform; }
namespace css_longhand { class TransformBox; }
namespace css_longhand { class TransformOrigin; }
namespace css_longhand { class TransformStyle; }
namespace css_longhand { class TransitionBehavior; }
namespace css_longhand { class TransitionDelay; }
namespace css_longhand { class TransitionDuration; }
namespace css_longhand { class TransitionProperty; }
namespace css_longhand { class TransitionTimingFunction; }
namespace css_longhand { class Translate; }
namespace css_longhand { class TriggerScope; }
namespace css_longhand { class Types; }
namespace css_longhand { class UnicodeBidi; }
namespace css_longhand { class UnicodeRange; }
namespace css_longhand { class UserSelect; }
namespace css_longhand { class VectorEffect; }
namespace css_longhand { class VerticalAlign; }
namespace css_longhand { class ViewTimelineAxis; }
namespace css_longhand { class ViewTimelineInset; }
namespace css_longhand { class ViewTimelineName; }
namespace css_longhand { class ViewTransitionClass; }
namespace css_longhand { class ViewTransitionGroup; }
namespace css_longhand { class ViewTransitionName; }
namespace css_longhand { class ViewTransitionScope; }
namespace css_longhand { class Visibility; }
namespace css_longhand { class WebkitBorderHorizontalSpacing; }
namespace css_longhand { class WebkitBorderImage; }
namespace css_longhand { class WebkitBorderVerticalSpacing; }
namespace css_longhand { class WebkitBoxAlign; }
namespace css_longhand { class WebkitBoxDecorationBreak; }
namespace css_longhand { class WebkitBoxDirection; }
namespace css_longhand { class WebkitBoxFlex; }
namespace css_longhand { class WebkitBoxOrdinalGroup; }
namespace css_longhand { class WebkitBoxOrient; }
namespace css_longhand { class WebkitBoxPack; }
namespace css_longhand { class WebkitBoxReflect; }
namespace css_longhand { class WebkitLineBreak; }
namespace css_longhand { class WebkitLineClamp; }
namespace css_longhand { class WebkitMaskBoxImageOutset; }
namespace css_longhand { class WebkitMaskBoxImageRepeat; }
namespace css_longhand { class WebkitMaskBoxImageSlice; }
namespace css_longhand { class WebkitMaskBoxImageSource; }
namespace css_longhand { class WebkitMaskBoxImageWidth; }
namespace css_longhand { class WebkitMaskPositionX; }
namespace css_longhand { class WebkitMaskPositionY; }
namespace css_longhand { class WebkitPerspectiveOriginX; }
namespace css_longhand { class WebkitPerspectiveOriginY; }
namespace css_longhand { class WebkitRtlOrdering; }
namespace css_longhand { class WebkitRubyPosition; }
namespace css_longhand { class WebkitTapHighlightColor; }
namespace css_longhand { class WebkitTextCombine; }
namespace css_longhand { class WebkitTextDecorationsInEffect; }
namespace css_longhand { class WebkitTextFillColor; }
namespace css_longhand { class WebkitTextSecurity; }
namespace css_longhand { class WebkitTextStrokeColor; }
namespace css_longhand { class WebkitTextStrokeWidth; }
namespace css_longhand { class WebkitTransformOriginX; }
namespace css_longhand { class WebkitTransformOriginY; }
namespace css_longhand { class WebkitTransformOriginZ; }
namespace css_longhand { class WebkitUserDrag; }
namespace css_longhand { class WebkitUserModify; }
namespace css_longhand { class WhiteSpaceCollapse; }
namespace css_longhand { class Widows; }
namespace css_longhand { class Width; }
namespace css_longhand { class WillChange; }
namespace css_longhand { class WindowDrag; }
namespace css_longhand { class WordBreak; }
namespace css_longhand { class WordSpacing; }
namespace css_longhand { class X; }
namespace css_longhand { class Y; }
namespace css_longhand { class ZIndex; }
namespace css_longhand { class MaskComposite; }
namespace css_shorthand { class AlternativeLineClampShorthand; }
namespace css_shorthand { class AlternativeWebkitLineClampShorthand; }
namespace css_shorthand { class Animation; }
namespace css_shorthand { class AnimationRange; }
namespace css_shorthand { class Background; }
namespace css_shorthand { class BackgroundPosition; }
namespace css_shorthand { class Border; }
namespace css_shorthand { class BorderBlock; }
namespace css_shorthand { class BorderBlockColor; }
namespace css_shorthand { class BorderBlockEnd; }
namespace css_shorthand { class BorderBlockStart; }
namespace css_shorthand { class BorderBlockStyle; }
namespace css_shorthand { class BorderBlockWidth; }
namespace css_shorthand { class BorderBottom; }
namespace css_shorthand { class BorderColor; }
namespace css_shorthand { class BorderImage; }
namespace css_shorthand { class BorderInline; }
namespace css_shorthand { class BorderInlineColor; }
namespace css_shorthand { class BorderInlineEnd; }
namespace css_shorthand { class BorderInlineStart; }
namespace css_shorthand { class BorderInlineStyle; }
namespace css_shorthand { class BorderInlineWidth; }
namespace css_shorthand { class BorderLeft; }
namespace css_shorthand { class BorderRadius; }
namespace css_shorthand { class BorderRight; }
namespace css_shorthand { class BorderSpacing; }
namespace css_shorthand { class BorderStyle; }
namespace css_shorthand { class BorderTop; }
namespace css_shorthand { class BorderWidth; }
namespace css_shorthand { class ColumnRule; }
namespace css_shorthand { class ColumnRuleInset; }
namespace css_shorthand { class ColumnRuleInsetCap; }
namespace css_shorthand { class ColumnRuleInsetEnd; }
namespace css_shorthand { class ColumnRuleInsetJunction; }
namespace css_shorthand { class ColumnRuleInsetStart; }
namespace css_shorthand { class Columns; }
namespace css_shorthand { class ContainIntrinsicSize; }
namespace css_shorthand { class Container; }
namespace css_shorthand { class Corner; }
namespace css_shorthand { class CornerBlockEnd; }
namespace css_shorthand { class CornerBlockEndShape; }
namespace css_shorthand { class CornerBlockStart; }
namespace css_shorthand { class CornerBlockStartShape; }
namespace css_shorthand { class CornerBottom; }
namespace css_shorthand { class CornerBottomLeft; }
namespace css_shorthand { class CornerBottomRight; }
namespace css_shorthand { class CornerBottomShape; }
namespace css_shorthand { class CornerEndEnd; }
namespace css_shorthand { class CornerEndStart; }
namespace css_shorthand { class CornerInlineEnd; }
namespace css_shorthand { class CornerInlineEndShape; }
namespace css_shorthand { class CornerInlineStart; }
namespace css_shorthand { class CornerInlineStartShape; }
namespace css_shorthand { class CornerLeft; }
namespace css_shorthand { class CornerLeftShape; }
namespace css_shorthand { class CornerRight; }
namespace css_shorthand { class CornerRightShape; }
namespace css_shorthand { class CornerShape; }
namespace css_shorthand { class CornerStartEnd; }
namespace css_shorthand { class CornerStartStart; }
namespace css_shorthand { class CornerTop; }
namespace css_shorthand { class CornerTopLeft; }
namespace css_shorthand { class CornerTopRight; }
namespace css_shorthand { class CornerTopShape; }
namespace css_shorthand { class Flex; }
namespace css_shorthand { class FlexFlow; }
namespace css_shorthand { class Font; }
namespace css_shorthand { class FontSynthesis; }
namespace css_shorthand { class FontVariant; }
namespace css_shorthand { class Gap; }
namespace css_shorthand { class Grid; }
namespace css_shorthand { class GridArea; }
namespace css_shorthand { class GridColumn; }
namespace css_shorthand { class GridLanes; }
namespace css_shorthand { class GridRow; }
namespace css_shorthand { class GridTemplate; }
namespace css_shorthand { class Inset; }
namespace css_shorthand { class InsetBlock; }
namespace css_shorthand { class InsetInline; }
namespace css_shorthand { class InterestDelay; }
namespace css_shorthand { class ListStyle; }
namespace css_shorthand { class Margin; }
namespace css_shorthand { class MarginBlock; }
namespace css_shorthand { class MarginInline; }
namespace css_shorthand { class Marker; }
namespace css_shorthand { class Mask; }
namespace css_shorthand { class MaskPosition; }
namespace css_shorthand { class Offset; }
namespace css_shorthand { class Outline; }
namespace css_shorthand { class Overflow; }
namespace css_shorthand { class OverscrollBehavior; }
namespace css_shorthand { class Padding; }
namespace css_shorthand { class PaddingBlock; }
namespace css_shorthand { class PaddingInline; }
namespace css_shorthand { class PageBreakAfter; }
namespace css_shorthand { class PageBreakBefore; }
namespace css_shorthand { class PageBreakInside; }
namespace css_shorthand { class PlaceContent; }
namespace css_shorthand { class PlaceItems; }
namespace css_shorthand { class PlaceSelf; }
namespace css_shorthand { class PositionTry; }
namespace css_shorthand { class RowRule; }
namespace css_shorthand { class RowRuleInset; }
namespace css_shorthand { class RowRuleInsetCap; }
namespace css_shorthand { class RowRuleInsetEnd; }
namespace css_shorthand { class RowRuleInsetJunction; }
namespace css_shorthand { class RowRuleInsetStart; }
namespace css_shorthand { class Rule; }
namespace css_shorthand { class RuleBreak; }
namespace css_shorthand { class RuleColor; }
namespace css_shorthand { class RuleInset; }
namespace css_shorthand { class RuleInsetCap; }
namespace css_shorthand { class RuleInsetEnd; }
namespace css_shorthand { class RuleInsetJunction; }
namespace css_shorthand { class RuleInsetStart; }
namespace css_shorthand { class RuleStyle; }
namespace css_shorthand { class RuleVisibilityItems; }
namespace css_shorthand { class RuleWidth; }
namespace css_shorthand { class ScrollMargin; }
namespace css_shorthand { class ScrollMarginBlock; }
namespace css_shorthand { class ScrollMarginInline; }
namespace css_shorthand { class ScrollPadding; }
namespace css_shorthand { class ScrollPaddingBlock; }
namespace css_shorthand { class ScrollPaddingInline; }
namespace css_shorthand { class ScrollTimeline; }
namespace css_shorthand { class TextBox; }
namespace css_shorthand { class TextDecoration; }
namespace css_shorthand { class TextEmphasis; }
namespace css_shorthand { class TextSpacing; }
namespace css_shorthand { class TextWrap; }
namespace css_shorthand { class TimelineTrigger; }
namespace css_shorthand { class TimelineTriggerActivationRange; }
namespace css_shorthand { class TimelineTriggerActiveRange; }
namespace css_shorthand { class Transition; }
namespace css_shorthand { class ViewTimeline; }
namespace css_shorthand { class WebkitColumnBreakAfter; }
namespace css_shorthand { class WebkitColumnBreakBefore; }
namespace css_shorthand { class WebkitColumnBreakInside; }
namespace css_shorthand { class WebkitMaskBoxImage; }
namespace css_shorthand { class WebkitTextStroke; }
namespace css_shorthand { class WhiteSpace; }
namespace css_longhand { class WebkitAppearance; }
namespace css_longhand { class WebkitAppRegion; }
namespace css_longhand { class WebkitMaskClip; }
namespace css_longhand { class WebkitMaskComposite; }
namespace css_longhand { class WebkitMaskImage; }
namespace css_longhand { class WebkitMaskOrigin; }
namespace css_longhand { class WebkitMaskRepeat; }
namespace css_longhand { class WebkitMaskSize; }
namespace css_longhand { class WebkitBorderEndColor; }
namespace css_longhand { class WebkitBorderEndStyle; }
namespace css_longhand { class WebkitBorderEndWidth; }
namespace css_longhand { class WebkitBorderStartColor; }
namespace css_longhand { class WebkitBorderStartStyle; }
namespace css_longhand { class WebkitBorderStartWidth; }
namespace css_longhand { class WebkitBorderBeforeColor; }
namespace css_longhand { class WebkitBorderBeforeStyle; }
namespace css_longhand { class WebkitBorderBeforeWidth; }
namespace css_longhand { class WebkitBorderAfterColor; }
namespace css_longhand { class WebkitBorderAfterStyle; }
namespace css_longhand { class WebkitBorderAfterWidth; }
namespace css_longhand { class WebkitMarginEnd; }
namespace css_longhand { class WebkitMarginStart; }
namespace css_longhand { class WebkitMarginBefore; }
namespace css_longhand { class WebkitMarginAfter; }
namespace css_longhand { class WebkitPaddingEnd; }
namespace css_longhand { class WebkitPaddingStart; }
namespace css_longhand { class WebkitPaddingBefore; }
namespace css_longhand { class WebkitPaddingAfter; }
namespace css_longhand { class WebkitLogicalWidth; }
namespace css_longhand { class WebkitLogicalHeight; }
namespace css_longhand { class WebkitMinLogicalWidth; }
namespace css_longhand { class WebkitMinLogicalHeight; }
namespace css_longhand { class WebkitMaxLogicalWidth; }
namespace css_longhand { class WebkitMaxLogicalHeight; }
namespace css_longhand { class WebkitPrintColorAdjust; }
namespace css_shorthand { class WebkitBorderAfter; }
namespace css_shorthand { class WebkitBorderBefore; }
namespace css_shorthand { class WebkitBorderEnd; }
namespace css_shorthand { class WebkitBorderStart; }
namespace css_shorthand { class WebkitMask; }
namespace css_shorthand { class WebkitMaskPosition; }
namespace css_longhand { class EpubCaptionSide; }
namespace css_longhand { class EpubTextCombine; }
namespace css_shorthand { class EpubTextEmphasis; }
namespace css_longhand { class EpubTextEmphasisColor; }
namespace css_longhand { class EpubTextEmphasisStyle; }
namespace css_longhand { class EpubTextOrientation; }
namespace css_longhand { class EpubTextTransform; }
namespace css_longhand { class EpubWordBreak; }
namespace css_longhand { class EpubWritingMode; }
namespace css_longhand { class WebkitAlignContent; }
namespace css_longhand { class WebkitAlignItems; }
namespace css_longhand { class WebkitAlignSelf; }
namespace css_shorthand { class WebkitAnimation; }
namespace css_longhand { class WebkitAnimationDelay; }
namespace css_longhand { class WebkitAnimationDirection; }
namespace css_longhand { class WebkitAnimationDuration; }
namespace css_longhand { class WebkitAnimationFillMode; }
namespace css_longhand { class WebkitAnimationIterationCount; }
namespace css_longhand { class WebkitAnimationName; }
namespace css_longhand { class WebkitAnimationPlayState; }
namespace css_longhand { class WebkitAnimationTimingFunction; }
namespace css_longhand { class WebkitBackfaceVisibility; }
namespace css_longhand { class WebkitBackgroundClip; }
namespace css_longhand { class WebkitBackgroundOrigin; }
namespace css_longhand { class WebkitBackgroundSize; }
namespace css_longhand { class WebkitBorderBottomLeftRadius; }
namespace css_longhand { class WebkitBorderBottomRightRadius; }
namespace css_shorthand { class WebkitBorderRadius; }
namespace css_longhand { class WebkitBorderTopLeftRadius; }
namespace css_longhand { class WebkitBorderTopRightRadius; }
namespace css_longhand { class WebkitBoxShadow; }
namespace css_longhand { class WebkitBoxSizing; }
namespace css_longhand { class WebkitClipPath; }
namespace css_longhand { class WebkitColumnCount; }
namespace css_longhand { class WebkitColumnGap; }
namespace css_shorthand { class WebkitColumnRule; }
namespace css_longhand { class WebkitColumnRuleColor; }
namespace css_longhand { class WebkitColumnRuleStyle; }
namespace css_longhand { class WebkitColumnRuleWidth; }
namespace css_longhand { class WebkitColumnSpan; }
namespace css_longhand { class WebkitColumnWidth; }
namespace css_shorthand { class WebkitColumns; }
namespace css_longhand { class WebkitFilter; }
namespace css_shorthand { class WebkitFlex; }
namespace css_longhand { class WebkitFlexBasis; }
namespace css_longhand { class WebkitFlexDirection; }
namespace css_shorthand { class WebkitFlexFlow; }
namespace css_longhand { class WebkitFlexGrow; }
namespace css_longhand { class WebkitFlexShrink; }
namespace css_longhand { class WebkitFlexWrap; }
namespace css_longhand { class WebkitFontFeatureSettings; }
namespace css_longhand { class WebkitHyphenateCharacter; }
namespace css_longhand { class WebkitJustifyContent; }
namespace css_longhand { class WebkitOpacity; }
namespace css_longhand { class WebkitOrder; }
namespace css_longhand { class WebkitPerspective; }
namespace css_longhand { class WebkitPerspectiveOrigin; }
namespace css_longhand { class WebkitShapeImageThreshold; }
namespace css_longhand { class WebkitShapeMargin; }
namespace css_longhand { class WebkitShapeOutside; }
namespace css_shorthand { class WebkitTextEmphasis; }
namespace css_longhand { class WebkitTextEmphasisColor; }
namespace css_longhand { class WebkitTextEmphasisPosition; }
namespace css_longhand { class WebkitTextEmphasisStyle; }
namespace css_longhand { class WebkitTextSizeAdjust; }
namespace css_longhand { class WebkitTransform; }
namespace css_longhand { class WebkitTransformOrigin; }
namespace css_longhand { class WebkitTransformStyle; }
namespace css_shorthand { class WebkitTransition; }
namespace css_longhand { class WebkitTransitionDelay; }
namespace css_longhand { class WebkitTransitionDuration; }
namespace css_longhand { class WebkitTransitionProperty; }
namespace css_longhand { class WebkitTransitionTimingFunction; }
namespace css_longhand { class WebkitUserSelect; }
namespace css_longhand { class WordWrap; }
namespace css_longhand { class GridColumnGap; }
namespace css_longhand { class GridRowGap; }
namespace css_shorthand { class GridGap; }

// We predeclare the size of the union here, so that we can inline
// GetPropertyInternal() without #including every single CSSProperty
// out there (which would be nearly impossible wrt. circular includes).
// We static_assert that it's correct in the .cc file.
// See crbug.com/1450215.
static constexpr size_t kCSSPropertyUnionBytes = 16;

union alignas(kCSSPropertyUnionBytes) CSSPropertyUnion;

// Static instances of every single CSSProperty and CSSUnresolvedProperty,
// indexed by CSSPropertyID.
extern CORE_EXPORT const CSSPropertyUnion kCssProperties[];

class CSSUnresolvedProperty;
inline const CSSUnresolvedProperty* GetPropertyInternal(CSSPropertyID id) {
  return reinterpret_cast<const CSSUnresolvedProperty *>(
      reinterpret_cast<const char *>(kCssProperties) +
          kCSSPropertyUnionBytes * static_cast<unsigned>(id));
}

inline const css_longhand::ColorScheme&
GetCSSPropertyColorScheme() {
  return *reinterpret_cast<const css_longhand::ColorScheme *>(
      GetPropertyInternal(CSSPropertyID::kColorScheme));
}
inline const css_longhand::ForcedColorAdjust&
GetCSSPropertyForcedColorAdjust() {
  return *reinterpret_cast<const css_longhand::ForcedColorAdjust *>(
      GetPropertyInternal(CSSPropertyID::kForcedColorAdjust));
}
inline const css_longhand::MathDepth&
GetCSSPropertyMathDepth() {
  return *reinterpret_cast<const css_longhand::MathDepth *>(
      GetPropertyInternal(CSSPropertyID::kMathDepth));
}
inline const css_longhand::Position&
GetCSSPropertyPosition() {
  return *reinterpret_cast<const css_longhand::Position *>(
      GetPropertyInternal(CSSPropertyID::kPosition));
}
inline const css_longhand::PositionAnchor&
GetCSSPropertyPositionAnchor() {
  return *reinterpret_cast<const css_longhand::PositionAnchor *>(
      GetPropertyInternal(CSSPropertyID::kPositionAnchor));
}
inline const css_longhand::TextSizeAdjust&
GetCSSPropertyTextSizeAdjust() {
  return *reinterpret_cast<const css_longhand::TextSizeAdjust *>(
      GetPropertyInternal(CSSPropertyID::kTextSizeAdjust));
}
inline const css_longhand::InternalVisitedColor&
GetCSSPropertyInternalVisitedColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedColor));
}
inline const css_longhand::Appearance&
GetCSSPropertyAppearance() {
  return *reinterpret_cast<const css_longhand::Appearance *>(
      GetPropertyInternal(CSSPropertyID::kAppearance));
}
inline const css_longhand::Color&
GetCSSPropertyColor() {
  return *reinterpret_cast<const css_longhand::Color *>(
      GetPropertyInternal(CSSPropertyID::kColor));
}
inline const css_longhand::Direction&
GetCSSPropertyDirection() {
  return *reinterpret_cast<const css_longhand::Direction *>(
      GetPropertyInternal(CSSPropertyID::kDirection));
}
inline const css_longhand::FontFamily&
GetCSSPropertyFontFamily() {
  return *reinterpret_cast<const css_longhand::FontFamily *>(
      GetPropertyInternal(CSSPropertyID::kFontFamily));
}
inline const css_longhand::FontFeatureSettings&
GetCSSPropertyFontFeatureSettings() {
  return *reinterpret_cast<const css_longhand::FontFeatureSettings *>(
      GetPropertyInternal(CSSPropertyID::kFontFeatureSettings));
}
inline const css_longhand::FontKerning&
GetCSSPropertyFontKerning() {
  return *reinterpret_cast<const css_longhand::FontKerning *>(
      GetPropertyInternal(CSSPropertyID::kFontKerning));
}
inline const css_longhand::FontLanguageOverride&
GetCSSPropertyFontLanguageOverride() {
  return *reinterpret_cast<const css_longhand::FontLanguageOverride *>(
      GetPropertyInternal(CSSPropertyID::kFontLanguageOverride));
}
inline const css_longhand::FontOpticalSizing&
GetCSSPropertyFontOpticalSizing() {
  return *reinterpret_cast<const css_longhand::FontOpticalSizing *>(
      GetPropertyInternal(CSSPropertyID::kFontOpticalSizing));
}
inline const css_longhand::FontPalette&
GetCSSPropertyFontPalette() {
  return *reinterpret_cast<const css_longhand::FontPalette *>(
      GetPropertyInternal(CSSPropertyID::kFontPalette));
}
inline const css_longhand::FontSize&
GetCSSPropertyFontSize() {
  return *reinterpret_cast<const css_longhand::FontSize *>(
      GetPropertyInternal(CSSPropertyID::kFontSize));
}
inline const css_longhand::FontSizeAdjust&
GetCSSPropertyFontSizeAdjust() {
  return *reinterpret_cast<const css_longhand::FontSizeAdjust *>(
      GetPropertyInternal(CSSPropertyID::kFontSizeAdjust));
}
inline const css_longhand::FontStretch&
GetCSSPropertyFontStretch() {
  return *reinterpret_cast<const css_longhand::FontStretch *>(
      GetPropertyInternal(CSSPropertyID::kFontStretch));
}
inline const css_longhand::FontStyle&
GetCSSPropertyFontStyle() {
  return *reinterpret_cast<const css_longhand::FontStyle *>(
      GetPropertyInternal(CSSPropertyID::kFontStyle));
}
inline const css_longhand::FontSynthesisSmallCaps&
GetCSSPropertyFontSynthesisSmallCaps() {
  return *reinterpret_cast<const css_longhand::FontSynthesisSmallCaps *>(
      GetPropertyInternal(CSSPropertyID::kFontSynthesisSmallCaps));
}
inline const css_longhand::FontSynthesisStyle&
GetCSSPropertyFontSynthesisStyle() {
  return *reinterpret_cast<const css_longhand::FontSynthesisStyle *>(
      GetPropertyInternal(CSSPropertyID::kFontSynthesisStyle));
}
inline const css_longhand::FontSynthesisWeight&
GetCSSPropertyFontSynthesisWeight() {
  return *reinterpret_cast<const css_longhand::FontSynthesisWeight *>(
      GetPropertyInternal(CSSPropertyID::kFontSynthesisWeight));
}
inline const css_longhand::FontVariantAlternates&
GetCSSPropertyFontVariantAlternates() {
  return *reinterpret_cast<const css_longhand::FontVariantAlternates *>(
      GetPropertyInternal(CSSPropertyID::kFontVariantAlternates));
}
inline const css_longhand::FontVariantCaps&
GetCSSPropertyFontVariantCaps() {
  return *reinterpret_cast<const css_longhand::FontVariantCaps *>(
      GetPropertyInternal(CSSPropertyID::kFontVariantCaps));
}
inline const css_longhand::FontVariantEastAsian&
GetCSSPropertyFontVariantEastAsian() {
  return *reinterpret_cast<const css_longhand::FontVariantEastAsian *>(
      GetPropertyInternal(CSSPropertyID::kFontVariantEastAsian));
}
inline const css_longhand::FontVariantEmoji&
GetCSSPropertyFontVariantEmoji() {
  return *reinterpret_cast<const css_longhand::FontVariantEmoji *>(
      GetPropertyInternal(CSSPropertyID::kFontVariantEmoji));
}
inline const css_longhand::FontVariantLigatures&
GetCSSPropertyFontVariantLigatures() {
  return *reinterpret_cast<const css_longhand::FontVariantLigatures *>(
      GetPropertyInternal(CSSPropertyID::kFontVariantLigatures));
}
inline const css_longhand::FontVariantNumeric&
GetCSSPropertyFontVariantNumeric() {
  return *reinterpret_cast<const css_longhand::FontVariantNumeric *>(
      GetPropertyInternal(CSSPropertyID::kFontVariantNumeric));
}
inline const css_longhand::FontVariantPosition&
GetCSSPropertyFontVariantPosition() {
  return *reinterpret_cast<const css_longhand::FontVariantPosition *>(
      GetPropertyInternal(CSSPropertyID::kFontVariantPosition));
}
inline const css_longhand::FontVariationSettings&
GetCSSPropertyFontVariationSettings() {
  return *reinterpret_cast<const css_longhand::FontVariationSettings *>(
      GetPropertyInternal(CSSPropertyID::kFontVariationSettings));
}
inline const css_longhand::FontWeight&
GetCSSPropertyFontWeight() {
  return *reinterpret_cast<const css_longhand::FontWeight *>(
      GetPropertyInternal(CSSPropertyID::kFontWeight));
}
inline const css_longhand::PositionArea&
GetCSSPropertyPositionArea() {
  return *reinterpret_cast<const css_longhand::PositionArea *>(
      GetPropertyInternal(CSSPropertyID::kPositionArea));
}
inline const css_longhand::TextOrientation&
GetCSSPropertyTextOrientation() {
  return *reinterpret_cast<const css_longhand::TextOrientation *>(
      GetPropertyInternal(CSSPropertyID::kTextOrientation));
}
inline const css_longhand::TextRendering&
GetCSSPropertyTextRendering() {
  return *reinterpret_cast<const css_longhand::TextRendering *>(
      GetPropertyInternal(CSSPropertyID::kTextRendering));
}
inline const css_longhand::TextSpacingTrim&
GetCSSPropertyTextSpacingTrim() {
  return *reinterpret_cast<const css_longhand::TextSpacingTrim *>(
      GetPropertyInternal(CSSPropertyID::kTextSpacingTrim));
}
inline const css_longhand::WebkitFontSmoothing&
GetCSSPropertyWebkitFontSmoothing() {
  return *reinterpret_cast<const css_longhand::WebkitFontSmoothing *>(
      GetPropertyInternal(CSSPropertyID::kWebkitFontSmoothing));
}
inline const css_longhand::WebkitLocale&
GetCSSPropertyWebkitLocale() {
  return *reinterpret_cast<const css_longhand::WebkitLocale *>(
      GetPropertyInternal(CSSPropertyID::kWebkitLocale));
}
inline const css_longhand::WebkitTextOrientation&
GetCSSPropertyWebkitTextOrientation() {
  return *reinterpret_cast<const css_longhand::WebkitTextOrientation *>(
      GetPropertyInternal(CSSPropertyID::kWebkitTextOrientation));
}
inline const css_longhand::WebkitWritingMode&
GetCSSPropertyWebkitWritingMode() {
  return *reinterpret_cast<const css_longhand::WebkitWritingMode *>(
      GetPropertyInternal(CSSPropertyID::kWebkitWritingMode));
}
inline const css_longhand::WritingMode&
GetCSSPropertyWritingMode() {
  return *reinterpret_cast<const css_longhand::WritingMode *>(
      GetPropertyInternal(CSSPropertyID::kWritingMode));
}
inline const css_longhand::Zoom&
GetCSSPropertyZoom() {
  return *reinterpret_cast<const css_longhand::Zoom *>(
      GetPropertyInternal(CSSPropertyID::kZoom));
}
inline const css_longhand::InternalForcedVisitedColor&
GetCSSPropertyInternalForcedVisitedColor() {
  return *reinterpret_cast<const css_longhand::InternalForcedVisitedColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalForcedVisitedColor));
}
inline const css_longhand::InternalVisitedBackgroundColor&
GetCSSPropertyInternalVisitedBackgroundColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedBackgroundColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedBackgroundColor));
}
inline const css_longhand::InternalVisitedBorderBlockEndColor&
GetCSSPropertyInternalVisitedBorderBlockEndColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedBorderBlockEndColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedBorderBlockEndColor));
}
inline const css_longhand::InternalVisitedBorderBlockStartColor&
GetCSSPropertyInternalVisitedBorderBlockStartColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedBorderBlockStartColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedBorderBlockStartColor));
}
inline const css_longhand::InternalVisitedBorderBottomColor&
GetCSSPropertyInternalVisitedBorderBottomColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedBorderBottomColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedBorderBottomColor));
}
inline const css_longhand::InternalVisitedBorderInlineEndColor&
GetCSSPropertyInternalVisitedBorderInlineEndColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedBorderInlineEndColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedBorderInlineEndColor));
}
inline const css_longhand::InternalVisitedBorderInlineStartColor&
GetCSSPropertyInternalVisitedBorderInlineStartColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedBorderInlineStartColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedBorderInlineStartColor));
}
inline const css_longhand::InternalVisitedBorderLeftColor&
GetCSSPropertyInternalVisitedBorderLeftColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedBorderLeftColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedBorderLeftColor));
}
inline const css_longhand::InternalVisitedBorderRightColor&
GetCSSPropertyInternalVisitedBorderRightColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedBorderRightColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedBorderRightColor));
}
inline const css_longhand::InternalVisitedBorderTopColor&
GetCSSPropertyInternalVisitedBorderTopColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedBorderTopColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedBorderTopColor));
}
inline const css_longhand::InternalVisitedCaretColor&
GetCSSPropertyInternalVisitedCaretColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedCaretColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedCaretColor));
}
inline const css_longhand::InternalVisitedColumnRuleColor&
GetCSSPropertyInternalVisitedColumnRuleColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedColumnRuleColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedColumnRuleColor));
}
inline const css_longhand::InternalVisitedFill&
GetCSSPropertyInternalVisitedFill() {
  return *reinterpret_cast<const css_longhand::InternalVisitedFill *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedFill));
}
inline const css_longhand::InternalVisitedOutlineColor&
GetCSSPropertyInternalVisitedOutlineColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedOutlineColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedOutlineColor));
}
inline const css_longhand::InternalVisitedStroke&
GetCSSPropertyInternalVisitedStroke() {
  return *reinterpret_cast<const css_longhand::InternalVisitedStroke *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedStroke));
}
inline const css_longhand::InternalVisitedTextDecorationColor&
GetCSSPropertyInternalVisitedTextDecorationColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedTextDecorationColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedTextDecorationColor));
}
inline const css_longhand::InternalVisitedTextEmphasisColor&
GetCSSPropertyInternalVisitedTextEmphasisColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedTextEmphasisColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedTextEmphasisColor));
}
inline const css_longhand::InternalVisitedTextFillColor&
GetCSSPropertyInternalVisitedTextFillColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedTextFillColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedTextFillColor));
}
inline const css_longhand::InternalVisitedTextStrokeColor&
GetCSSPropertyInternalVisitedTextStrokeColor() {
  return *reinterpret_cast<const css_longhand::InternalVisitedTextStrokeColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalVisitedTextStrokeColor));
}
inline const css_longhand::AccentColor&
GetCSSPropertyAccentColor() {
  return *reinterpret_cast<const css_longhand::AccentColor *>(
      GetPropertyInternal(CSSPropertyID::kAccentColor));
}
inline const css_longhand::AdditiveSymbols&
GetCSSPropertyAdditiveSymbols() {
  return *reinterpret_cast<const css_longhand::AdditiveSymbols *>(
      GetPropertyInternal(CSSPropertyID::kAdditiveSymbols));
}
inline const css_longhand::AlignContent&
GetCSSPropertyAlignContent() {
  return *reinterpret_cast<const css_longhand::AlignContent *>(
      GetPropertyInternal(CSSPropertyID::kAlignContent));
}
inline const css_longhand::AlignItems&
GetCSSPropertyAlignItems() {
  return *reinterpret_cast<const css_longhand::AlignItems *>(
      GetPropertyInternal(CSSPropertyID::kAlignItems));
}
inline const css_longhand::AlignSelf&
GetCSSPropertyAlignSelf() {
  return *reinterpret_cast<const css_longhand::AlignSelf *>(
      GetPropertyInternal(CSSPropertyID::kAlignSelf));
}
inline const css_longhand::AlignmentBaseline&
GetCSSPropertyAlignmentBaseline() {
  return *reinterpret_cast<const css_longhand::AlignmentBaseline *>(
      GetPropertyInternal(CSSPropertyID::kAlignmentBaseline));
}
inline const css_longhand::All&
GetCSSPropertyAll() {
  return *reinterpret_cast<const css_longhand::All *>(
      GetPropertyInternal(CSSPropertyID::kAll));
}
inline const css_longhand::AlternativeWebkitLineClampLonghand&
GetCSSPropertyAlternativeWebkitLineClampLonghand() {
  return *reinterpret_cast<const css_longhand::AlternativeWebkitLineClampLonghand *>(
      GetPropertyInternal(CSSPropertyID::kAlternativeWebkitLineClampLonghand));
}
inline const css_longhand::AnchorName&
GetCSSPropertyAnchorName() {
  return *reinterpret_cast<const css_longhand::AnchorName *>(
      GetPropertyInternal(CSSPropertyID::kAnchorName));
}
inline const css_longhand::AnchorScope&
GetCSSPropertyAnchorScope() {
  return *reinterpret_cast<const css_longhand::AnchorScope *>(
      GetPropertyInternal(CSSPropertyID::kAnchorScope));
}
inline const css_longhand::AnimationComposition&
GetCSSPropertyAnimationComposition() {
  return *reinterpret_cast<const css_longhand::AnimationComposition *>(
      GetPropertyInternal(CSSPropertyID::kAnimationComposition));
}
inline const css_longhand::AnimationDelay&
GetCSSPropertyAnimationDelay() {
  return *reinterpret_cast<const css_longhand::AnimationDelay *>(
      GetPropertyInternal(CSSPropertyID::kAnimationDelay));
}
inline const css_longhand::AnimationDirection&
GetCSSPropertyAnimationDirection() {
  return *reinterpret_cast<const css_longhand::AnimationDirection *>(
      GetPropertyInternal(CSSPropertyID::kAnimationDirection));
}
inline const css_longhand::AnimationDuration&
GetCSSPropertyAnimationDuration() {
  return *reinterpret_cast<const css_longhand::AnimationDuration *>(
      GetPropertyInternal(CSSPropertyID::kAnimationDuration));
}
inline const css_longhand::AnimationFillMode&
GetCSSPropertyAnimationFillMode() {
  return *reinterpret_cast<const css_longhand::AnimationFillMode *>(
      GetPropertyInternal(CSSPropertyID::kAnimationFillMode));
}
inline const css_longhand::AnimationIterationCount&
GetCSSPropertyAnimationIterationCount() {
  return *reinterpret_cast<const css_longhand::AnimationIterationCount *>(
      GetPropertyInternal(CSSPropertyID::kAnimationIterationCount));
}
inline const css_longhand::AnimationName&
GetCSSPropertyAnimationName() {
  return *reinterpret_cast<const css_longhand::AnimationName *>(
      GetPropertyInternal(CSSPropertyID::kAnimationName));
}
inline const css_longhand::AnimationPlayState&
GetCSSPropertyAnimationPlayState() {
  return *reinterpret_cast<const css_longhand::AnimationPlayState *>(
      GetPropertyInternal(CSSPropertyID::kAnimationPlayState));
}
inline const css_longhand::AnimationRangeEnd&
GetCSSPropertyAnimationRangeEnd() {
  return *reinterpret_cast<const css_longhand::AnimationRangeEnd *>(
      GetPropertyInternal(CSSPropertyID::kAnimationRangeEnd));
}
inline const css_longhand::AnimationRangeStart&
GetCSSPropertyAnimationRangeStart() {
  return *reinterpret_cast<const css_longhand::AnimationRangeStart *>(
      GetPropertyInternal(CSSPropertyID::kAnimationRangeStart));
}
inline const css_longhand::AnimationTimeline&
GetCSSPropertyAnimationTimeline() {
  return *reinterpret_cast<const css_longhand::AnimationTimeline *>(
      GetPropertyInternal(CSSPropertyID::kAnimationTimeline));
}
inline const css_longhand::AnimationTimingFunction&
GetCSSPropertyAnimationTimingFunction() {
  return *reinterpret_cast<const css_longhand::AnimationTimingFunction *>(
      GetPropertyInternal(CSSPropertyID::kAnimationTimingFunction));
}
inline const css_longhand::AnimationTrigger&
GetCSSPropertyAnimationTrigger() {
  return *reinterpret_cast<const css_longhand::AnimationTrigger *>(
      GetPropertyInternal(CSSPropertyID::kAnimationTrigger));
}
inline const css_longhand::AppRegion&
GetCSSPropertyAppRegion() {
  return *reinterpret_cast<const css_longhand::AppRegion *>(
      GetPropertyInternal(CSSPropertyID::kAppRegion));
}
inline const css_longhand::AscentOverride&
GetCSSPropertyAscentOverride() {
  return *reinterpret_cast<const css_longhand::AscentOverride *>(
      GetPropertyInternal(CSSPropertyID::kAscentOverride));
}
inline const css_longhand::AspectRatio&
GetCSSPropertyAspectRatio() {
  return *reinterpret_cast<const css_longhand::AspectRatio *>(
      GetPropertyInternal(CSSPropertyID::kAspectRatio));
}
inline const css_longhand::BackdropFilter&
GetCSSPropertyBackdropFilter() {
  return *reinterpret_cast<const css_longhand::BackdropFilter *>(
      GetPropertyInternal(CSSPropertyID::kBackdropFilter));
}
inline const css_longhand::BackfaceVisibility&
GetCSSPropertyBackfaceVisibility() {
  return *reinterpret_cast<const css_longhand::BackfaceVisibility *>(
      GetPropertyInternal(CSSPropertyID::kBackfaceVisibility));
}
inline const css_longhand::BackgroundAttachment&
GetCSSPropertyBackgroundAttachment() {
  return *reinterpret_cast<const css_longhand::BackgroundAttachment *>(
      GetPropertyInternal(CSSPropertyID::kBackgroundAttachment));
}
inline const css_longhand::BackgroundBlendMode&
GetCSSPropertyBackgroundBlendMode() {
  return *reinterpret_cast<const css_longhand::BackgroundBlendMode *>(
      GetPropertyInternal(CSSPropertyID::kBackgroundBlendMode));
}
inline const css_longhand::BackgroundClip&
GetCSSPropertyBackgroundClip() {
  return *reinterpret_cast<const css_longhand::BackgroundClip *>(
      GetPropertyInternal(CSSPropertyID::kBackgroundClip));
}
inline const css_longhand::BackgroundColor&
GetCSSPropertyBackgroundColor() {
  return *reinterpret_cast<const css_longhand::BackgroundColor *>(
      GetPropertyInternal(CSSPropertyID::kBackgroundColor));
}
inline const css_longhand::BackgroundImage&
GetCSSPropertyBackgroundImage() {
  return *reinterpret_cast<const css_longhand::BackgroundImage *>(
      GetPropertyInternal(CSSPropertyID::kBackgroundImage));
}
inline const css_longhand::BackgroundOrigin&
GetCSSPropertyBackgroundOrigin() {
  return *reinterpret_cast<const css_longhand::BackgroundOrigin *>(
      GetPropertyInternal(CSSPropertyID::kBackgroundOrigin));
}
inline const css_longhand::BackgroundPositionX&
GetCSSPropertyBackgroundPositionX() {
  return *reinterpret_cast<const css_longhand::BackgroundPositionX *>(
      GetPropertyInternal(CSSPropertyID::kBackgroundPositionX));
}
inline const css_longhand::BackgroundPositionY&
GetCSSPropertyBackgroundPositionY() {
  return *reinterpret_cast<const css_longhand::BackgroundPositionY *>(
      GetPropertyInternal(CSSPropertyID::kBackgroundPositionY));
}
inline const css_longhand::BackgroundRepeat&
GetCSSPropertyBackgroundRepeat() {
  return *reinterpret_cast<const css_longhand::BackgroundRepeat *>(
      GetPropertyInternal(CSSPropertyID::kBackgroundRepeat));
}
inline const css_longhand::BackgroundSize&
GetCSSPropertyBackgroundSize() {
  return *reinterpret_cast<const css_longhand::BackgroundSize *>(
      GetPropertyInternal(CSSPropertyID::kBackgroundSize));
}
inline const css_longhand::BasePalette&
GetCSSPropertyBasePalette() {
  return *reinterpret_cast<const css_longhand::BasePalette *>(
      GetPropertyInternal(CSSPropertyID::kBasePalette));
}
inline const css_longhand::BaseUrl&
GetCSSPropertyBaseUrl() {
  return *reinterpret_cast<const css_longhand::BaseUrl *>(
      GetPropertyInternal(CSSPropertyID::kBaseUrl));
}
inline const css_longhand::BaselineShift&
GetCSSPropertyBaselineShift() {
  return *reinterpret_cast<const css_longhand::BaselineShift *>(
      GetPropertyInternal(CSSPropertyID::kBaselineShift));
}
inline const css_longhand::BaselineSource&
GetCSSPropertyBaselineSource() {
  return *reinterpret_cast<const css_longhand::BaselineSource *>(
      GetPropertyInternal(CSSPropertyID::kBaselineSource));
}
inline const css_longhand::BlockEllipsis&
GetCSSPropertyBlockEllipsis() {
  return *reinterpret_cast<const css_longhand::BlockEllipsis *>(
      GetPropertyInternal(CSSPropertyID::kBlockEllipsis));
}
inline const css_longhand::BlockSize&
GetCSSPropertyBlockSize() {
  return *reinterpret_cast<const css_longhand::BlockSize *>(
      GetPropertyInternal(CSSPropertyID::kBlockSize));
}
inline const css_longhand::BorderBlockEndColor&
GetCSSPropertyBorderBlockEndColor() {
  return *reinterpret_cast<const css_longhand::BorderBlockEndColor *>(
      GetPropertyInternal(CSSPropertyID::kBorderBlockEndColor));
}
inline const css_longhand::BorderBlockEndStyle&
GetCSSPropertyBorderBlockEndStyle() {
  return *reinterpret_cast<const css_longhand::BorderBlockEndStyle *>(
      GetPropertyInternal(CSSPropertyID::kBorderBlockEndStyle));
}
inline const css_longhand::BorderBlockEndWidth&
GetCSSPropertyBorderBlockEndWidth() {
  return *reinterpret_cast<const css_longhand::BorderBlockEndWidth *>(
      GetPropertyInternal(CSSPropertyID::kBorderBlockEndWidth));
}
inline const css_longhand::BorderBlockStartColor&
GetCSSPropertyBorderBlockStartColor() {
  return *reinterpret_cast<const css_longhand::BorderBlockStartColor *>(
      GetPropertyInternal(CSSPropertyID::kBorderBlockStartColor));
}
inline const css_longhand::BorderBlockStartStyle&
GetCSSPropertyBorderBlockStartStyle() {
  return *reinterpret_cast<const css_longhand::BorderBlockStartStyle *>(
      GetPropertyInternal(CSSPropertyID::kBorderBlockStartStyle));
}
inline const css_longhand::BorderBlockStartWidth&
GetCSSPropertyBorderBlockStartWidth() {
  return *reinterpret_cast<const css_longhand::BorderBlockStartWidth *>(
      GetPropertyInternal(CSSPropertyID::kBorderBlockStartWidth));
}
inline const css_longhand::BorderBottomColor&
GetCSSPropertyBorderBottomColor() {
  return *reinterpret_cast<const css_longhand::BorderBottomColor *>(
      GetPropertyInternal(CSSPropertyID::kBorderBottomColor));
}
inline const css_longhand::BorderBottomLeftRadius&
GetCSSPropertyBorderBottomLeftRadius() {
  return *reinterpret_cast<const css_longhand::BorderBottomLeftRadius *>(
      GetPropertyInternal(CSSPropertyID::kBorderBottomLeftRadius));
}
inline const css_longhand::BorderBottomRightRadius&
GetCSSPropertyBorderBottomRightRadius() {
  return *reinterpret_cast<const css_longhand::BorderBottomRightRadius *>(
      GetPropertyInternal(CSSPropertyID::kBorderBottomRightRadius));
}
inline const css_longhand::BorderBottomStyle&
GetCSSPropertyBorderBottomStyle() {
  return *reinterpret_cast<const css_longhand::BorderBottomStyle *>(
      GetPropertyInternal(CSSPropertyID::kBorderBottomStyle));
}
inline const css_longhand::BorderBottomWidth&
GetCSSPropertyBorderBottomWidth() {
  return *reinterpret_cast<const css_longhand::BorderBottomWidth *>(
      GetPropertyInternal(CSSPropertyID::kBorderBottomWidth));
}
inline const css_longhand::BorderCollapse&
GetCSSPropertyBorderCollapse() {
  return *reinterpret_cast<const css_longhand::BorderCollapse *>(
      GetPropertyInternal(CSSPropertyID::kBorderCollapse));
}
inline const css_longhand::BorderEndEndRadius&
GetCSSPropertyBorderEndEndRadius() {
  return *reinterpret_cast<const css_longhand::BorderEndEndRadius *>(
      GetPropertyInternal(CSSPropertyID::kBorderEndEndRadius));
}
inline const css_longhand::BorderEndStartRadius&
GetCSSPropertyBorderEndStartRadius() {
  return *reinterpret_cast<const css_longhand::BorderEndStartRadius *>(
      GetPropertyInternal(CSSPropertyID::kBorderEndStartRadius));
}
inline const css_longhand::BorderImageOutset&
GetCSSPropertyBorderImageOutset() {
  return *reinterpret_cast<const css_longhand::BorderImageOutset *>(
      GetPropertyInternal(CSSPropertyID::kBorderImageOutset));
}
inline const css_longhand::BorderImageRepeat&
GetCSSPropertyBorderImageRepeat() {
  return *reinterpret_cast<const css_longhand::BorderImageRepeat *>(
      GetPropertyInternal(CSSPropertyID::kBorderImageRepeat));
}
inline const css_longhand::BorderImageSlice&
GetCSSPropertyBorderImageSlice() {
  return *reinterpret_cast<const css_longhand::BorderImageSlice *>(
      GetPropertyInternal(CSSPropertyID::kBorderImageSlice));
}
inline const css_longhand::BorderImageSource&
GetCSSPropertyBorderImageSource() {
  return *reinterpret_cast<const css_longhand::BorderImageSource *>(
      GetPropertyInternal(CSSPropertyID::kBorderImageSource));
}
inline const css_longhand::BorderImageWidth&
GetCSSPropertyBorderImageWidth() {
  return *reinterpret_cast<const css_longhand::BorderImageWidth *>(
      GetPropertyInternal(CSSPropertyID::kBorderImageWidth));
}
inline const css_longhand::BorderInlineEndColor&
GetCSSPropertyBorderInlineEndColor() {
  return *reinterpret_cast<const css_longhand::BorderInlineEndColor *>(
      GetPropertyInternal(CSSPropertyID::kBorderInlineEndColor));
}
inline const css_longhand::BorderInlineEndStyle&
GetCSSPropertyBorderInlineEndStyle() {
  return *reinterpret_cast<const css_longhand::BorderInlineEndStyle *>(
      GetPropertyInternal(CSSPropertyID::kBorderInlineEndStyle));
}
inline const css_longhand::BorderInlineEndWidth&
GetCSSPropertyBorderInlineEndWidth() {
  return *reinterpret_cast<const css_longhand::BorderInlineEndWidth *>(
      GetPropertyInternal(CSSPropertyID::kBorderInlineEndWidth));
}
inline const css_longhand::BorderInlineStartColor&
GetCSSPropertyBorderInlineStartColor() {
  return *reinterpret_cast<const css_longhand::BorderInlineStartColor *>(
      GetPropertyInternal(CSSPropertyID::kBorderInlineStartColor));
}
inline const css_longhand::BorderInlineStartStyle&
GetCSSPropertyBorderInlineStartStyle() {
  return *reinterpret_cast<const css_longhand::BorderInlineStartStyle *>(
      GetPropertyInternal(CSSPropertyID::kBorderInlineStartStyle));
}
inline const css_longhand::BorderInlineStartWidth&
GetCSSPropertyBorderInlineStartWidth() {
  return *reinterpret_cast<const css_longhand::BorderInlineStartWidth *>(
      GetPropertyInternal(CSSPropertyID::kBorderInlineStartWidth));
}
inline const css_longhand::BorderLeftColor&
GetCSSPropertyBorderLeftColor() {
  return *reinterpret_cast<const css_longhand::BorderLeftColor *>(
      GetPropertyInternal(CSSPropertyID::kBorderLeftColor));
}
inline const css_longhand::BorderLeftStyle&
GetCSSPropertyBorderLeftStyle() {
  return *reinterpret_cast<const css_longhand::BorderLeftStyle *>(
      GetPropertyInternal(CSSPropertyID::kBorderLeftStyle));
}
inline const css_longhand::BorderLeftWidth&
GetCSSPropertyBorderLeftWidth() {
  return *reinterpret_cast<const css_longhand::BorderLeftWidth *>(
      GetPropertyInternal(CSSPropertyID::kBorderLeftWidth));
}
inline const css_longhand::BorderRightColor&
GetCSSPropertyBorderRightColor() {
  return *reinterpret_cast<const css_longhand::BorderRightColor *>(
      GetPropertyInternal(CSSPropertyID::kBorderRightColor));
}
inline const css_longhand::BorderRightStyle&
GetCSSPropertyBorderRightStyle() {
  return *reinterpret_cast<const css_longhand::BorderRightStyle *>(
      GetPropertyInternal(CSSPropertyID::kBorderRightStyle));
}
inline const css_longhand::BorderRightWidth&
GetCSSPropertyBorderRightWidth() {
  return *reinterpret_cast<const css_longhand::BorderRightWidth *>(
      GetPropertyInternal(CSSPropertyID::kBorderRightWidth));
}
inline const css_longhand::BorderShape&
GetCSSPropertyBorderShape() {
  return *reinterpret_cast<const css_longhand::BorderShape *>(
      GetPropertyInternal(CSSPropertyID::kBorderShape));
}
inline const css_longhand::BorderStartEndRadius&
GetCSSPropertyBorderStartEndRadius() {
  return *reinterpret_cast<const css_longhand::BorderStartEndRadius *>(
      GetPropertyInternal(CSSPropertyID::kBorderStartEndRadius));
}
inline const css_longhand::BorderStartStartRadius&
GetCSSPropertyBorderStartStartRadius() {
  return *reinterpret_cast<const css_longhand::BorderStartStartRadius *>(
      GetPropertyInternal(CSSPropertyID::kBorderStartStartRadius));
}
inline const css_longhand::BorderTopColor&
GetCSSPropertyBorderTopColor() {
  return *reinterpret_cast<const css_longhand::BorderTopColor *>(
      GetPropertyInternal(CSSPropertyID::kBorderTopColor));
}
inline const css_longhand::BorderTopLeftRadius&
GetCSSPropertyBorderTopLeftRadius() {
  return *reinterpret_cast<const css_longhand::BorderTopLeftRadius *>(
      GetPropertyInternal(CSSPropertyID::kBorderTopLeftRadius));
}
inline const css_longhand::BorderTopRightRadius&
GetCSSPropertyBorderTopRightRadius() {
  return *reinterpret_cast<const css_longhand::BorderTopRightRadius *>(
      GetPropertyInternal(CSSPropertyID::kBorderTopRightRadius));
}
inline const css_longhand::BorderTopStyle&
GetCSSPropertyBorderTopStyle() {
  return *reinterpret_cast<const css_longhand::BorderTopStyle *>(
      GetPropertyInternal(CSSPropertyID::kBorderTopStyle));
}
inline const css_longhand::BorderTopWidth&
GetCSSPropertyBorderTopWidth() {
  return *reinterpret_cast<const css_longhand::BorderTopWidth *>(
      GetPropertyInternal(CSSPropertyID::kBorderTopWidth));
}
inline const css_longhand::Bottom&
GetCSSPropertyBottom() {
  return *reinterpret_cast<const css_longhand::Bottom *>(
      GetPropertyInternal(CSSPropertyID::kBottom));
}
inline const css_longhand::BoxDecorationBreak&
GetCSSPropertyBoxDecorationBreak() {
  return *reinterpret_cast<const css_longhand::BoxDecorationBreak *>(
      GetPropertyInternal(CSSPropertyID::kBoxDecorationBreak));
}
inline const css_longhand::BoxShadow&
GetCSSPropertyBoxShadow() {
  return *reinterpret_cast<const css_longhand::BoxShadow *>(
      GetPropertyInternal(CSSPropertyID::kBoxShadow));
}
inline const css_longhand::BoxSizing&
GetCSSPropertyBoxSizing() {
  return *reinterpret_cast<const css_longhand::BoxSizing *>(
      GetPropertyInternal(CSSPropertyID::kBoxSizing));
}
inline const css_longhand::BreakAfter&
GetCSSPropertyBreakAfter() {
  return *reinterpret_cast<const css_longhand::BreakAfter *>(
      GetPropertyInternal(CSSPropertyID::kBreakAfter));
}
inline const css_longhand::BreakBefore&
GetCSSPropertyBreakBefore() {
  return *reinterpret_cast<const css_longhand::BreakBefore *>(
      GetPropertyInternal(CSSPropertyID::kBreakBefore));
}
inline const css_longhand::BreakInside&
GetCSSPropertyBreakInside() {
  return *reinterpret_cast<const css_longhand::BreakInside *>(
      GetPropertyInternal(CSSPropertyID::kBreakInside));
}
inline const css_longhand::BufferedRendering&
GetCSSPropertyBufferedRendering() {
  return *reinterpret_cast<const css_longhand::BufferedRendering *>(
      GetPropertyInternal(CSSPropertyID::kBufferedRendering));
}
inline const css_longhand::CaptionSide&
GetCSSPropertyCaptionSide() {
  return *reinterpret_cast<const css_longhand::CaptionSide *>(
      GetPropertyInternal(CSSPropertyID::kCaptionSide));
}
inline const css_longhand::CaretAnimation&
GetCSSPropertyCaretAnimation() {
  return *reinterpret_cast<const css_longhand::CaretAnimation *>(
      GetPropertyInternal(CSSPropertyID::kCaretAnimation));
}
inline const css_longhand::CaretColor&
GetCSSPropertyCaretColor() {
  return *reinterpret_cast<const css_longhand::CaretColor *>(
      GetPropertyInternal(CSSPropertyID::kCaretColor));
}
inline const css_longhand::CaretShape&
GetCSSPropertyCaretShape() {
  return *reinterpret_cast<const css_longhand::CaretShape *>(
      GetPropertyInternal(CSSPropertyID::kCaretShape));
}
inline const css_longhand::Clear&
GetCSSPropertyClear() {
  return *reinterpret_cast<const css_longhand::Clear *>(
      GetPropertyInternal(CSSPropertyID::kClear));
}
inline const css_longhand::Clip&
GetCSSPropertyClip() {
  return *reinterpret_cast<const css_longhand::Clip *>(
      GetPropertyInternal(CSSPropertyID::kClip));
}
inline const css_longhand::ClipPath&
GetCSSPropertyClipPath() {
  return *reinterpret_cast<const css_longhand::ClipPath *>(
      GetPropertyInternal(CSSPropertyID::kClipPath));
}
inline const css_longhand::ClipRule&
GetCSSPropertyClipRule() {
  return *reinterpret_cast<const css_longhand::ClipRule *>(
      GetPropertyInternal(CSSPropertyID::kClipRule));
}
inline const css_longhand::ColorInterpolation&
GetCSSPropertyColorInterpolation() {
  return *reinterpret_cast<const css_longhand::ColorInterpolation *>(
      GetPropertyInternal(CSSPropertyID::kColorInterpolation));
}
inline const css_longhand::ColorInterpolationFilters&
GetCSSPropertyColorInterpolationFilters() {
  return *reinterpret_cast<const css_longhand::ColorInterpolationFilters *>(
      GetPropertyInternal(CSSPropertyID::kColorInterpolationFilters));
}
inline const css_longhand::ColorRendering&
GetCSSPropertyColorRendering() {
  return *reinterpret_cast<const css_longhand::ColorRendering *>(
      GetPropertyInternal(CSSPropertyID::kColorRendering));
}
inline const css_longhand::ColumnCount&
GetCSSPropertyColumnCount() {
  return *reinterpret_cast<const css_longhand::ColumnCount *>(
      GetPropertyInternal(CSSPropertyID::kColumnCount));
}
inline const css_longhand::ColumnFill&
GetCSSPropertyColumnFill() {
  return *reinterpret_cast<const css_longhand::ColumnFill *>(
      GetPropertyInternal(CSSPropertyID::kColumnFill));
}
inline const css_longhand::ColumnGap&
GetCSSPropertyColumnGap() {
  return *reinterpret_cast<const css_longhand::ColumnGap *>(
      GetPropertyInternal(CSSPropertyID::kColumnGap));
}
inline const css_longhand::ColumnHeight&
GetCSSPropertyColumnHeight() {
  return *reinterpret_cast<const css_longhand::ColumnHeight *>(
      GetPropertyInternal(CSSPropertyID::kColumnHeight));
}
inline const css_longhand::ColumnRuleBreak&
GetCSSPropertyColumnRuleBreak() {
  return *reinterpret_cast<const css_longhand::ColumnRuleBreak *>(
      GetPropertyInternal(CSSPropertyID::kColumnRuleBreak));
}
inline const css_longhand::ColumnRuleColor&
GetCSSPropertyColumnRuleColor() {
  return *reinterpret_cast<const css_longhand::ColumnRuleColor *>(
      GetPropertyInternal(CSSPropertyID::kColumnRuleColor));
}
inline const css_longhand::ColumnRuleInsetCapEnd&
GetCSSPropertyColumnRuleInsetCapEnd() {
  return *reinterpret_cast<const css_longhand::ColumnRuleInsetCapEnd *>(
      GetPropertyInternal(CSSPropertyID::kColumnRuleInsetCapEnd));
}
inline const css_longhand::ColumnRuleInsetCapStart&
GetCSSPropertyColumnRuleInsetCapStart() {
  return *reinterpret_cast<const css_longhand::ColumnRuleInsetCapStart *>(
      GetPropertyInternal(CSSPropertyID::kColumnRuleInsetCapStart));
}
inline const css_longhand::ColumnRuleInsetJunctionEnd&
GetCSSPropertyColumnRuleInsetJunctionEnd() {
  return *reinterpret_cast<const css_longhand::ColumnRuleInsetJunctionEnd *>(
      GetPropertyInternal(CSSPropertyID::kColumnRuleInsetJunctionEnd));
}
inline const css_longhand::ColumnRuleInsetJunctionStart&
GetCSSPropertyColumnRuleInsetJunctionStart() {
  return *reinterpret_cast<const css_longhand::ColumnRuleInsetJunctionStart *>(
      GetPropertyInternal(CSSPropertyID::kColumnRuleInsetJunctionStart));
}
inline const css_longhand::ColumnRuleStyle&
GetCSSPropertyColumnRuleStyle() {
  return *reinterpret_cast<const css_longhand::ColumnRuleStyle *>(
      GetPropertyInternal(CSSPropertyID::kColumnRuleStyle));
}
inline const css_longhand::ColumnRuleVisibilityItems&
GetCSSPropertyColumnRuleVisibilityItems() {
  return *reinterpret_cast<const css_longhand::ColumnRuleVisibilityItems *>(
      GetPropertyInternal(CSSPropertyID::kColumnRuleVisibilityItems));
}
inline const css_longhand::ColumnRuleWidth&
GetCSSPropertyColumnRuleWidth() {
  return *reinterpret_cast<const css_longhand::ColumnRuleWidth *>(
      GetPropertyInternal(CSSPropertyID::kColumnRuleWidth));
}
inline const css_longhand::ColumnSpan&
GetCSSPropertyColumnSpan() {
  return *reinterpret_cast<const css_longhand::ColumnSpan *>(
      GetPropertyInternal(CSSPropertyID::kColumnSpan));
}
inline const css_longhand::ColumnWidth&
GetCSSPropertyColumnWidth() {
  return *reinterpret_cast<const css_longhand::ColumnWidth *>(
      GetPropertyInternal(CSSPropertyID::kColumnWidth));
}
inline const css_longhand::ColumnWrap&
GetCSSPropertyColumnWrap() {
  return *reinterpret_cast<const css_longhand::ColumnWrap *>(
      GetPropertyInternal(CSSPropertyID::kColumnWrap));
}
inline const css_longhand::Contain&
GetCSSPropertyContain() {
  return *reinterpret_cast<const css_longhand::Contain *>(
      GetPropertyInternal(CSSPropertyID::kContain));
}
inline const css_longhand::ContainIntrinsicBlockSize&
GetCSSPropertyContainIntrinsicBlockSize() {
  return *reinterpret_cast<const css_longhand::ContainIntrinsicBlockSize *>(
      GetPropertyInternal(CSSPropertyID::kContainIntrinsicBlockSize));
}
inline const css_longhand::ContainIntrinsicHeight&
GetCSSPropertyContainIntrinsicHeight() {
  return *reinterpret_cast<const css_longhand::ContainIntrinsicHeight *>(
      GetPropertyInternal(CSSPropertyID::kContainIntrinsicHeight));
}
inline const css_longhand::ContainIntrinsicInlineSize&
GetCSSPropertyContainIntrinsicInlineSize() {
  return *reinterpret_cast<const css_longhand::ContainIntrinsicInlineSize *>(
      GetPropertyInternal(CSSPropertyID::kContainIntrinsicInlineSize));
}
inline const css_longhand::ContainIntrinsicWidth&
GetCSSPropertyContainIntrinsicWidth() {
  return *reinterpret_cast<const css_longhand::ContainIntrinsicWidth *>(
      GetPropertyInternal(CSSPropertyID::kContainIntrinsicWidth));
}
inline const css_longhand::ContainerName&
GetCSSPropertyContainerName() {
  return *reinterpret_cast<const css_longhand::ContainerName *>(
      GetPropertyInternal(CSSPropertyID::kContainerName));
}
inline const css_longhand::ContainerType&
GetCSSPropertyContainerType() {
  return *reinterpret_cast<const css_longhand::ContainerType *>(
      GetPropertyInternal(CSSPropertyID::kContainerType));
}
inline const css_longhand::Content&
GetCSSPropertyContent() {
  return *reinterpret_cast<const css_longhand::Content *>(
      GetPropertyInternal(CSSPropertyID::kContent));
}
inline const css_longhand::ContentVisibility&
GetCSSPropertyContentVisibility() {
  return *reinterpret_cast<const css_longhand::ContentVisibility *>(
      GetPropertyInternal(CSSPropertyID::kContentVisibility));
}
inline const css_longhand::Continue&
GetCSSPropertyContinue() {
  return *reinterpret_cast<const css_longhand::Continue *>(
      GetPropertyInternal(CSSPropertyID::kContinue));
}
inline const css_longhand::CornerBottomLeftShape&
GetCSSPropertyCornerBottomLeftShape() {
  return *reinterpret_cast<const css_longhand::CornerBottomLeftShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerBottomLeftShape));
}
inline const css_longhand::CornerBottomRightShape&
GetCSSPropertyCornerBottomRightShape() {
  return *reinterpret_cast<const css_longhand::CornerBottomRightShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerBottomRightShape));
}
inline const css_longhand::CornerEndEndShape&
GetCSSPropertyCornerEndEndShape() {
  return *reinterpret_cast<const css_longhand::CornerEndEndShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerEndEndShape));
}
inline const css_longhand::CornerEndStartShape&
GetCSSPropertyCornerEndStartShape() {
  return *reinterpret_cast<const css_longhand::CornerEndStartShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerEndStartShape));
}
inline const css_longhand::CornerStartEndShape&
GetCSSPropertyCornerStartEndShape() {
  return *reinterpret_cast<const css_longhand::CornerStartEndShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerStartEndShape));
}
inline const css_longhand::CornerStartStartShape&
GetCSSPropertyCornerStartStartShape() {
  return *reinterpret_cast<const css_longhand::CornerStartStartShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerStartStartShape));
}
inline const css_longhand::CornerTopLeftShape&
GetCSSPropertyCornerTopLeftShape() {
  return *reinterpret_cast<const css_longhand::CornerTopLeftShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerTopLeftShape));
}
inline const css_longhand::CornerTopRightShape&
GetCSSPropertyCornerTopRightShape() {
  return *reinterpret_cast<const css_longhand::CornerTopRightShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerTopRightShape));
}
inline const css_longhand::CounterIncrement&
GetCSSPropertyCounterIncrement() {
  return *reinterpret_cast<const css_longhand::CounterIncrement *>(
      GetPropertyInternal(CSSPropertyID::kCounterIncrement));
}
inline const css_longhand::CounterReset&
GetCSSPropertyCounterReset() {
  return *reinterpret_cast<const css_longhand::CounterReset *>(
      GetPropertyInternal(CSSPropertyID::kCounterReset));
}
inline const css_longhand::CounterSet&
GetCSSPropertyCounterSet() {
  return *reinterpret_cast<const css_longhand::CounterSet *>(
      GetPropertyInternal(CSSPropertyID::kCounterSet));
}
inline const css_longhand::Cursor&
GetCSSPropertyCursor() {
  return *reinterpret_cast<const css_longhand::Cursor *>(
      GetPropertyInternal(CSSPropertyID::kCursor));
}
inline const css_longhand::Cx&
GetCSSPropertyCx() {
  return *reinterpret_cast<const css_longhand::Cx *>(
      GetPropertyInternal(CSSPropertyID::kCx));
}
inline const css_longhand::Cy&
GetCSSPropertyCy() {
  return *reinterpret_cast<const css_longhand::Cy *>(
      GetPropertyInternal(CSSPropertyID::kCy));
}
inline const css_longhand::D&
GetCSSPropertyD() {
  return *reinterpret_cast<const css_longhand::D *>(
      GetPropertyInternal(CSSPropertyID::kD));
}
inline const css_longhand::DescentOverride&
GetCSSPropertyDescentOverride() {
  return *reinterpret_cast<const css_longhand::DescentOverride *>(
      GetPropertyInternal(CSSPropertyID::kDescentOverride));
}
inline const css_longhand::Display&
GetCSSPropertyDisplay() {
  return *reinterpret_cast<const css_longhand::Display *>(
      GetPropertyInternal(CSSPropertyID::kDisplay));
}
inline const css_longhand::DominantBaseline&
GetCSSPropertyDominantBaseline() {
  return *reinterpret_cast<const css_longhand::DominantBaseline *>(
      GetPropertyInternal(CSSPropertyID::kDominantBaseline));
}
inline const css_longhand::DynamicRangeLimit&
GetCSSPropertyDynamicRangeLimit() {
  return *reinterpret_cast<const css_longhand::DynamicRangeLimit *>(
      GetPropertyInternal(CSSPropertyID::kDynamicRangeLimit));
}
inline const css_longhand::EmptyCells&
GetCSSPropertyEmptyCells() {
  return *reinterpret_cast<const css_longhand::EmptyCells *>(
      GetPropertyInternal(CSSPropertyID::kEmptyCells));
}
inline const css_longhand::Fallback&
GetCSSPropertyFallback() {
  return *reinterpret_cast<const css_longhand::Fallback *>(
      GetPropertyInternal(CSSPropertyID::kFallback));
}
inline const css_longhand::FieldSizing&
GetCSSPropertyFieldSizing() {
  return *reinterpret_cast<const css_longhand::FieldSizing *>(
      GetPropertyInternal(CSSPropertyID::kFieldSizing));
}
inline const css_longhand::Fill&
GetCSSPropertyFill() {
  return *reinterpret_cast<const css_longhand::Fill *>(
      GetPropertyInternal(CSSPropertyID::kFill));
}
inline const css_longhand::FillOpacity&
GetCSSPropertyFillOpacity() {
  return *reinterpret_cast<const css_longhand::FillOpacity *>(
      GetPropertyInternal(CSSPropertyID::kFillOpacity));
}
inline const css_longhand::FillRule&
GetCSSPropertyFillRule() {
  return *reinterpret_cast<const css_longhand::FillRule *>(
      GetPropertyInternal(CSSPropertyID::kFillRule));
}
inline const css_longhand::Filter&
GetCSSPropertyFilter() {
  return *reinterpret_cast<const css_longhand::Filter *>(
      GetPropertyInternal(CSSPropertyID::kFilter));
}
inline const css_longhand::FlexBasis&
GetCSSPropertyFlexBasis() {
  return *reinterpret_cast<const css_longhand::FlexBasis *>(
      GetPropertyInternal(CSSPropertyID::kFlexBasis));
}
inline const css_longhand::FlexDirection&
GetCSSPropertyFlexDirection() {
  return *reinterpret_cast<const css_longhand::FlexDirection *>(
      GetPropertyInternal(CSSPropertyID::kFlexDirection));
}
inline const css_longhand::FlexGrow&
GetCSSPropertyFlexGrow() {
  return *reinterpret_cast<const css_longhand::FlexGrow *>(
      GetPropertyInternal(CSSPropertyID::kFlexGrow));
}
inline const css_longhand::FlexLineCount&
GetCSSPropertyFlexLineCount() {
  return *reinterpret_cast<const css_longhand::FlexLineCount *>(
      GetPropertyInternal(CSSPropertyID::kFlexLineCount));
}
inline const css_longhand::FlexShrink&
GetCSSPropertyFlexShrink() {
  return *reinterpret_cast<const css_longhand::FlexShrink *>(
      GetPropertyInternal(CSSPropertyID::kFlexShrink));
}
inline const css_longhand::FlexWrap&
GetCSSPropertyFlexWrap() {
  return *reinterpret_cast<const css_longhand::FlexWrap *>(
      GetPropertyInternal(CSSPropertyID::kFlexWrap));
}
inline const css_longhand::Float&
GetCSSPropertyFloat() {
  return *reinterpret_cast<const css_longhand::Float *>(
      GetPropertyInternal(CSSPropertyID::kFloat));
}
inline const css_longhand::FloodColor&
GetCSSPropertyFloodColor() {
  return *reinterpret_cast<const css_longhand::FloodColor *>(
      GetPropertyInternal(CSSPropertyID::kFloodColor));
}
inline const css_longhand::FloodOpacity&
GetCSSPropertyFloodOpacity() {
  return *reinterpret_cast<const css_longhand::FloodOpacity *>(
      GetPropertyInternal(CSSPropertyID::kFloodOpacity));
}
inline const css_longhand::FlowTolerance&
GetCSSPropertyFlowTolerance() {
  return *reinterpret_cast<const css_longhand::FlowTolerance *>(
      GetPropertyInternal(CSSPropertyID::kFlowTolerance));
}
inline const css_longhand::FontDisplay&
GetCSSPropertyFontDisplay() {
  return *reinterpret_cast<const css_longhand::FontDisplay *>(
      GetPropertyInternal(CSSPropertyID::kFontDisplay));
}
inline const css_longhand::FrameSizing&
GetCSSPropertyFrameSizing() {
  return *reinterpret_cast<const css_longhand::FrameSizing *>(
      GetPropertyInternal(CSSPropertyID::kFrameSizing));
}
inline const css_longhand::GridAutoColumns&
GetCSSPropertyGridAutoColumns() {
  return *reinterpret_cast<const css_longhand::GridAutoColumns *>(
      GetPropertyInternal(CSSPropertyID::kGridAutoColumns));
}
inline const css_longhand::GridAutoFlow&
GetCSSPropertyGridAutoFlow() {
  return *reinterpret_cast<const css_longhand::GridAutoFlow *>(
      GetPropertyInternal(CSSPropertyID::kGridAutoFlow));
}
inline const css_longhand::GridAutoRows&
GetCSSPropertyGridAutoRows() {
  return *reinterpret_cast<const css_longhand::GridAutoRows *>(
      GetPropertyInternal(CSSPropertyID::kGridAutoRows));
}
inline const css_longhand::GridColumnEnd&
GetCSSPropertyGridColumnEnd() {
  return *reinterpret_cast<const css_longhand::GridColumnEnd *>(
      GetPropertyInternal(CSSPropertyID::kGridColumnEnd));
}
inline const css_longhand::GridColumnStart&
GetCSSPropertyGridColumnStart() {
  return *reinterpret_cast<const css_longhand::GridColumnStart *>(
      GetPropertyInternal(CSSPropertyID::kGridColumnStart));
}
inline const css_longhand::GridLanesDirection&
GetCSSPropertyGridLanesDirection() {
  return *reinterpret_cast<const css_longhand::GridLanesDirection *>(
      GetPropertyInternal(CSSPropertyID::kGridLanesDirection));
}
inline const css_longhand::GridLanesPack&
GetCSSPropertyGridLanesPack() {
  return *reinterpret_cast<const css_longhand::GridLanesPack *>(
      GetPropertyInternal(CSSPropertyID::kGridLanesPack));
}
inline const css_longhand::GridRowEnd&
GetCSSPropertyGridRowEnd() {
  return *reinterpret_cast<const css_longhand::GridRowEnd *>(
      GetPropertyInternal(CSSPropertyID::kGridRowEnd));
}
inline const css_longhand::GridRowStart&
GetCSSPropertyGridRowStart() {
  return *reinterpret_cast<const css_longhand::GridRowStart *>(
      GetPropertyInternal(CSSPropertyID::kGridRowStart));
}
inline const css_longhand::GridTemplateAreas&
GetCSSPropertyGridTemplateAreas() {
  return *reinterpret_cast<const css_longhand::GridTemplateAreas *>(
      GetPropertyInternal(CSSPropertyID::kGridTemplateAreas));
}
inline const css_longhand::GridTemplateColumns&
GetCSSPropertyGridTemplateColumns() {
  return *reinterpret_cast<const css_longhand::GridTemplateColumns *>(
      GetPropertyInternal(CSSPropertyID::kGridTemplateColumns));
}
inline const css_longhand::GridTemplateRows&
GetCSSPropertyGridTemplateRows() {
  return *reinterpret_cast<const css_longhand::GridTemplateRows *>(
      GetPropertyInternal(CSSPropertyID::kGridTemplateRows));
}
inline const css_longhand::HangingPunctuation&
GetCSSPropertyHangingPunctuation() {
  return *reinterpret_cast<const css_longhand::HangingPunctuation *>(
      GetPropertyInternal(CSSPropertyID::kHangingPunctuation));
}
inline const css_longhand::Hash&
GetCSSPropertyHash() {
  return *reinterpret_cast<const css_longhand::Hash *>(
      GetPropertyInternal(CSSPropertyID::kHash));
}
inline const css_longhand::Height&
GetCSSPropertyHeight() {
  return *reinterpret_cast<const css_longhand::Height *>(
      GetPropertyInternal(CSSPropertyID::kHeight));
}
inline const css_longhand::Hostname&
GetCSSPropertyHostname() {
  return *reinterpret_cast<const css_longhand::Hostname *>(
      GetPropertyInternal(CSSPropertyID::kHostname));
}
inline const css_longhand::HyphenateCharacter&
GetCSSPropertyHyphenateCharacter() {
  return *reinterpret_cast<const css_longhand::HyphenateCharacter *>(
      GetPropertyInternal(CSSPropertyID::kHyphenateCharacter));
}
inline const css_longhand::HyphenateLimitChars&
GetCSSPropertyHyphenateLimitChars() {
  return *reinterpret_cast<const css_longhand::HyphenateLimitChars *>(
      GetPropertyInternal(CSSPropertyID::kHyphenateLimitChars));
}
inline const css_longhand::Hyphens&
GetCSSPropertyHyphens() {
  return *reinterpret_cast<const css_longhand::Hyphens *>(
      GetPropertyInternal(CSSPropertyID::kHyphens));
}
inline const css_longhand::ImageAnimation&
GetCSSPropertyImageAnimation() {
  return *reinterpret_cast<const css_longhand::ImageAnimation *>(
      GetPropertyInternal(CSSPropertyID::kImageAnimation));
}
inline const css_longhand::ImageOrientation&
GetCSSPropertyImageOrientation() {
  return *reinterpret_cast<const css_longhand::ImageOrientation *>(
      GetPropertyInternal(CSSPropertyID::kImageOrientation));
}
inline const css_longhand::ImageRendering&
GetCSSPropertyImageRendering() {
  return *reinterpret_cast<const css_longhand::ImageRendering *>(
      GetPropertyInternal(CSSPropertyID::kImageRendering));
}
inline const css_longhand::Inherits&
GetCSSPropertyInherits() {
  return *reinterpret_cast<const css_longhand::Inherits *>(
      GetPropertyInternal(CSSPropertyID::kInherits));
}
inline const css_longhand::InitialLetter&
GetCSSPropertyInitialLetter() {
  return *reinterpret_cast<const css_longhand::InitialLetter *>(
      GetPropertyInternal(CSSPropertyID::kInitialLetter));
}
inline const css_longhand::InitialValue&
GetCSSPropertyInitialValue() {
  return *reinterpret_cast<const css_longhand::InitialValue *>(
      GetPropertyInternal(CSSPropertyID::kInitialValue));
}
inline const css_longhand::InlineSize&
GetCSSPropertyInlineSize() {
  return *reinterpret_cast<const css_longhand::InlineSize *>(
      GetPropertyInternal(CSSPropertyID::kInlineSize));
}
inline const css_longhand::InsetBlockEnd&
GetCSSPropertyInsetBlockEnd() {
  return *reinterpret_cast<const css_longhand::InsetBlockEnd *>(
      GetPropertyInternal(CSSPropertyID::kInsetBlockEnd));
}
inline const css_longhand::InsetBlockStart&
GetCSSPropertyInsetBlockStart() {
  return *reinterpret_cast<const css_longhand::InsetBlockStart *>(
      GetPropertyInternal(CSSPropertyID::kInsetBlockStart));
}
inline const css_longhand::InsetInlineEnd&
GetCSSPropertyInsetInlineEnd() {
  return *reinterpret_cast<const css_longhand::InsetInlineEnd *>(
      GetPropertyInternal(CSSPropertyID::kInsetInlineEnd));
}
inline const css_longhand::InsetInlineStart&
GetCSSPropertyInsetInlineStart() {
  return *reinterpret_cast<const css_longhand::InsetInlineStart *>(
      GetPropertyInternal(CSSPropertyID::kInsetInlineStart));
}
inline const css_longhand::Interactivity&
GetCSSPropertyInteractivity() {
  return *reinterpret_cast<const css_longhand::Interactivity *>(
      GetPropertyInternal(CSSPropertyID::kInteractivity));
}
inline const css_longhand::InterestDelayEnd&
GetCSSPropertyInterestDelayEnd() {
  return *reinterpret_cast<const css_longhand::InterestDelayEnd *>(
      GetPropertyInternal(CSSPropertyID::kInterestDelayEnd));
}
inline const css_longhand::InterestDelayStart&
GetCSSPropertyInterestDelayStart() {
  return *reinterpret_cast<const css_longhand::InterestDelayStart *>(
      GetPropertyInternal(CSSPropertyID::kInterestDelayStart));
}
inline const css_longhand::InternalAlignContentBlock&
GetCSSPropertyInternalAlignContentBlock() {
  return *reinterpret_cast<const css_longhand::InternalAlignContentBlock *>(
      GetPropertyInternal(CSSPropertyID::kInternalAlignContentBlock));
}
inline const css_longhand::InternalEmptyLineHeight&
GetCSSPropertyInternalEmptyLineHeight() {
  return *reinterpret_cast<const css_longhand::InternalEmptyLineHeight *>(
      GetPropertyInternal(CSSPropertyID::kInternalEmptyLineHeight));
}
inline const css_longhand::InternalFontSizeDelta&
GetCSSPropertyInternalFontSizeDelta() {
  return *reinterpret_cast<const css_longhand::InternalFontSizeDelta *>(
      GetPropertyInternal(CSSPropertyID::kInternalFontSizeDelta));
}
inline const css_longhand::InternalForcedBackgroundColor&
GetCSSPropertyInternalForcedBackgroundColor() {
  return *reinterpret_cast<const css_longhand::InternalForcedBackgroundColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalForcedBackgroundColor));
}
inline const css_longhand::InternalForcedBorderColor&
GetCSSPropertyInternalForcedBorderColor() {
  return *reinterpret_cast<const css_longhand::InternalForcedBorderColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalForcedBorderColor));
}
inline const css_longhand::InternalForcedColor&
GetCSSPropertyInternalForcedColor() {
  return *reinterpret_cast<const css_longhand::InternalForcedColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalForcedColor));
}
inline const css_longhand::InternalForcedOutlineColor&
GetCSSPropertyInternalForcedOutlineColor() {
  return *reinterpret_cast<const css_longhand::InternalForcedOutlineColor *>(
      GetPropertyInternal(CSSPropertyID::kInternalForcedOutlineColor));
}
inline const css_longhand::InternalOverscrollContainer&
GetCSSPropertyInternalOverscrollContainer() {
  return *reinterpret_cast<const css_longhand::InternalOverscrollContainer *>(
      GetPropertyInternal(CSSPropertyID::kInternalOverscrollContainer));
}
inline const css_longhand::InternalOverscrollPosition&
GetCSSPropertyInternalOverscrollPosition() {
  return *reinterpret_cast<const css_longhand::InternalOverscrollPosition *>(
      GetPropertyInternal(CSSPropertyID::kInternalOverscrollPosition));
}
inline const css_longhand::InternalUnbounded&
GetCSSPropertyInternalUnbounded() {
  return *reinterpret_cast<const css_longhand::InternalUnbounded *>(
      GetPropertyInternal(CSSPropertyID::kInternalUnbounded));
}
inline const css_longhand::InterpolateSize&
GetCSSPropertyInterpolateSize() {
  return *reinterpret_cast<const css_longhand::InterpolateSize *>(
      GetPropertyInternal(CSSPropertyID::kInterpolateSize));
}
inline const css_longhand::Isolation&
GetCSSPropertyIsolation() {
  return *reinterpret_cast<const css_longhand::Isolation *>(
      GetPropertyInternal(CSSPropertyID::kIsolation));
}
inline const css_longhand::JustifyContent&
GetCSSPropertyJustifyContent() {
  return *reinterpret_cast<const css_longhand::JustifyContent *>(
      GetPropertyInternal(CSSPropertyID::kJustifyContent));
}
inline const css_longhand::JustifyItems&
GetCSSPropertyJustifyItems() {
  return *reinterpret_cast<const css_longhand::JustifyItems *>(
      GetPropertyInternal(CSSPropertyID::kJustifyItems));
}
inline const css_longhand::JustifySelf&
GetCSSPropertyJustifySelf() {
  return *reinterpret_cast<const css_longhand::JustifySelf *>(
      GetPropertyInternal(CSSPropertyID::kJustifySelf));
}
inline const css_longhand::Left&
GetCSSPropertyLeft() {
  return *reinterpret_cast<const css_longhand::Left *>(
      GetPropertyInternal(CSSPropertyID::kLeft));
}
inline const css_longhand::LetterSpacing&
GetCSSPropertyLetterSpacing() {
  return *reinterpret_cast<const css_longhand::LetterSpacing *>(
      GetPropertyInternal(CSSPropertyID::kLetterSpacing));
}
inline const css_longhand::LightingColor&
GetCSSPropertyLightingColor() {
  return *reinterpret_cast<const css_longhand::LightingColor *>(
      GetPropertyInternal(CSSPropertyID::kLightingColor));
}
inline const css_longhand::LineBreak&
GetCSSPropertyLineBreak() {
  return *reinterpret_cast<const css_longhand::LineBreak *>(
      GetPropertyInternal(CSSPropertyID::kLineBreak));
}
inline const css_longhand::LineClamp&
GetCSSPropertyLineClamp() {
  return *reinterpret_cast<const css_longhand::LineClamp *>(
      GetPropertyInternal(CSSPropertyID::kLineClamp));
}
inline const css_longhand::LineGapOverride&
GetCSSPropertyLineGapOverride() {
  return *reinterpret_cast<const css_longhand::LineGapOverride *>(
      GetPropertyInternal(CSSPropertyID::kLineGapOverride));
}
inline const css_longhand::LineHeight&
GetCSSPropertyLineHeight() {
  return *reinterpret_cast<const css_longhand::LineHeight *>(
      GetPropertyInternal(CSSPropertyID::kLineHeight));
}
inline const css_longhand::ListStyleImage&
GetCSSPropertyListStyleImage() {
  return *reinterpret_cast<const css_longhand::ListStyleImage *>(
      GetPropertyInternal(CSSPropertyID::kListStyleImage));
}
inline const css_longhand::ListStylePosition&
GetCSSPropertyListStylePosition() {
  return *reinterpret_cast<const css_longhand::ListStylePosition *>(
      GetPropertyInternal(CSSPropertyID::kListStylePosition));
}
inline const css_longhand::ListStyleType&
GetCSSPropertyListStyleType() {
  return *reinterpret_cast<const css_longhand::ListStyleType *>(
      GetPropertyInternal(CSSPropertyID::kListStyleType));
}
inline const css_longhand::MarginBlockEnd&
GetCSSPropertyMarginBlockEnd() {
  return *reinterpret_cast<const css_longhand::MarginBlockEnd *>(
      GetPropertyInternal(CSSPropertyID::kMarginBlockEnd));
}
inline const css_longhand::MarginBlockStart&
GetCSSPropertyMarginBlockStart() {
  return *reinterpret_cast<const css_longhand::MarginBlockStart *>(
      GetPropertyInternal(CSSPropertyID::kMarginBlockStart));
}
inline const css_longhand::MarginBottom&
GetCSSPropertyMarginBottom() {
  return *reinterpret_cast<const css_longhand::MarginBottom *>(
      GetPropertyInternal(CSSPropertyID::kMarginBottom));
}
inline const css_longhand::MarginInlineEnd&
GetCSSPropertyMarginInlineEnd() {
  return *reinterpret_cast<const css_longhand::MarginInlineEnd *>(
      GetPropertyInternal(CSSPropertyID::kMarginInlineEnd));
}
inline const css_longhand::MarginInlineStart&
GetCSSPropertyMarginInlineStart() {
  return *reinterpret_cast<const css_longhand::MarginInlineStart *>(
      GetPropertyInternal(CSSPropertyID::kMarginInlineStart));
}
inline const css_longhand::MarginLeft&
GetCSSPropertyMarginLeft() {
  return *reinterpret_cast<const css_longhand::MarginLeft *>(
      GetPropertyInternal(CSSPropertyID::kMarginLeft));
}
inline const css_longhand::MarginRight&
GetCSSPropertyMarginRight() {
  return *reinterpret_cast<const css_longhand::MarginRight *>(
      GetPropertyInternal(CSSPropertyID::kMarginRight));
}
inline const css_longhand::MarginTop&
GetCSSPropertyMarginTop() {
  return *reinterpret_cast<const css_longhand::MarginTop *>(
      GetPropertyInternal(CSSPropertyID::kMarginTop));
}
inline const css_longhand::MarginTrim&
GetCSSPropertyMarginTrim() {
  return *reinterpret_cast<const css_longhand::MarginTrim *>(
      GetPropertyInternal(CSSPropertyID::kMarginTrim));
}
inline const css_longhand::MarkerEnd&
GetCSSPropertyMarkerEnd() {
  return *reinterpret_cast<const css_longhand::MarkerEnd *>(
      GetPropertyInternal(CSSPropertyID::kMarkerEnd));
}
inline const css_longhand::MarkerMid&
GetCSSPropertyMarkerMid() {
  return *reinterpret_cast<const css_longhand::MarkerMid *>(
      GetPropertyInternal(CSSPropertyID::kMarkerMid));
}
inline const css_longhand::MarkerStart&
GetCSSPropertyMarkerStart() {
  return *reinterpret_cast<const css_longhand::MarkerStart *>(
      GetPropertyInternal(CSSPropertyID::kMarkerStart));
}
inline const css_longhand::MaskClip&
GetCSSPropertyMaskClip() {
  return *reinterpret_cast<const css_longhand::MaskClip *>(
      GetPropertyInternal(CSSPropertyID::kMaskClip));
}
inline const css_longhand::MaskImage&
GetCSSPropertyMaskImage() {
  return *reinterpret_cast<const css_longhand::MaskImage *>(
      GetPropertyInternal(CSSPropertyID::kMaskImage));
}
inline const css_longhand::MaskMode&
GetCSSPropertyMaskMode() {
  return *reinterpret_cast<const css_longhand::MaskMode *>(
      GetPropertyInternal(CSSPropertyID::kMaskMode));
}
inline const css_longhand::MaskOrigin&
GetCSSPropertyMaskOrigin() {
  return *reinterpret_cast<const css_longhand::MaskOrigin *>(
      GetPropertyInternal(CSSPropertyID::kMaskOrigin));
}
inline const css_longhand::MaskRepeat&
GetCSSPropertyMaskRepeat() {
  return *reinterpret_cast<const css_longhand::MaskRepeat *>(
      GetPropertyInternal(CSSPropertyID::kMaskRepeat));
}
inline const css_longhand::MaskSize&
GetCSSPropertyMaskSize() {
  return *reinterpret_cast<const css_longhand::MaskSize *>(
      GetPropertyInternal(CSSPropertyID::kMaskSize));
}
inline const css_longhand::MaskType&
GetCSSPropertyMaskType() {
  return *reinterpret_cast<const css_longhand::MaskType *>(
      GetPropertyInternal(CSSPropertyID::kMaskType));
}
inline const css_longhand::MathShift&
GetCSSPropertyMathShift() {
  return *reinterpret_cast<const css_longhand::MathShift *>(
      GetPropertyInternal(CSSPropertyID::kMathShift));
}
inline const css_longhand::MathStyle&
GetCSSPropertyMathStyle() {
  return *reinterpret_cast<const css_longhand::MathStyle *>(
      GetPropertyInternal(CSSPropertyID::kMathStyle));
}
inline const css_longhand::MaxBlockSize&
GetCSSPropertyMaxBlockSize() {
  return *reinterpret_cast<const css_longhand::MaxBlockSize *>(
      GetPropertyInternal(CSSPropertyID::kMaxBlockSize));
}
inline const css_longhand::MaxContentSizing&
GetCSSPropertyMaxContentSizing() {
  return *reinterpret_cast<const css_longhand::MaxContentSizing *>(
      GetPropertyInternal(CSSPropertyID::kMaxContentSizing));
}
inline const css_longhand::MaxHeight&
GetCSSPropertyMaxHeight() {
  return *reinterpret_cast<const css_longhand::MaxHeight *>(
      GetPropertyInternal(CSSPropertyID::kMaxHeight));
}
inline const css_longhand::MaxInlineSize&
GetCSSPropertyMaxInlineSize() {
  return *reinterpret_cast<const css_longhand::MaxInlineSize *>(
      GetPropertyInternal(CSSPropertyID::kMaxInlineSize));
}
inline const css_longhand::MaxLines&
GetCSSPropertyMaxLines() {
  return *reinterpret_cast<const css_longhand::MaxLines *>(
      GetPropertyInternal(CSSPropertyID::kMaxLines));
}
inline const css_longhand::MaxWidth&
GetCSSPropertyMaxWidth() {
  return *reinterpret_cast<const css_longhand::MaxWidth *>(
      GetPropertyInternal(CSSPropertyID::kMaxWidth));
}
inline const css_longhand::MinBlockSize&
GetCSSPropertyMinBlockSize() {
  return *reinterpret_cast<const css_longhand::MinBlockSize *>(
      GetPropertyInternal(CSSPropertyID::kMinBlockSize));
}
inline const css_longhand::MinHeight&
GetCSSPropertyMinHeight() {
  return *reinterpret_cast<const css_longhand::MinHeight *>(
      GetPropertyInternal(CSSPropertyID::kMinHeight));
}
inline const css_longhand::MinInlineSize&
GetCSSPropertyMinInlineSize() {
  return *reinterpret_cast<const css_longhand::MinInlineSize *>(
      GetPropertyInternal(CSSPropertyID::kMinInlineSize));
}
inline const css_longhand::MinWidth&
GetCSSPropertyMinWidth() {
  return *reinterpret_cast<const css_longhand::MinWidth *>(
      GetPropertyInternal(CSSPropertyID::kMinWidth));
}
inline const css_longhand::MixBlendMode&
GetCSSPropertyMixBlendMode() {
  return *reinterpret_cast<const css_longhand::MixBlendMode *>(
      GetPropertyInternal(CSSPropertyID::kMixBlendMode));
}
inline const css_longhand::Navigation&
GetCSSPropertyNavigation() {
  return *reinterpret_cast<const css_longhand::Navigation *>(
      GetPropertyInternal(CSSPropertyID::kNavigation));
}
inline const css_longhand::Negative&
GetCSSPropertyNegative() {
  return *reinterpret_cast<const css_longhand::Negative *>(
      GetPropertyInternal(CSSPropertyID::kNegative));
}
inline const css_longhand::ObjectFit&
GetCSSPropertyObjectFit() {
  return *reinterpret_cast<const css_longhand::ObjectFit *>(
      GetPropertyInternal(CSSPropertyID::kObjectFit));
}
inline const css_longhand::ObjectPosition&
GetCSSPropertyObjectPosition() {
  return *reinterpret_cast<const css_longhand::ObjectPosition *>(
      GetPropertyInternal(CSSPropertyID::kObjectPosition));
}
inline const css_longhand::ObjectViewBox&
GetCSSPropertyObjectViewBox() {
  return *reinterpret_cast<const css_longhand::ObjectViewBox *>(
      GetPropertyInternal(CSSPropertyID::kObjectViewBox));
}
inline const css_longhand::OffsetAnchor&
GetCSSPropertyOffsetAnchor() {
  return *reinterpret_cast<const css_longhand::OffsetAnchor *>(
      GetPropertyInternal(CSSPropertyID::kOffsetAnchor));
}
inline const css_longhand::OffsetDistance&
GetCSSPropertyOffsetDistance() {
  return *reinterpret_cast<const css_longhand::OffsetDistance *>(
      GetPropertyInternal(CSSPropertyID::kOffsetDistance));
}
inline const css_longhand::OffsetPath&
GetCSSPropertyOffsetPath() {
  return *reinterpret_cast<const css_longhand::OffsetPath *>(
      GetPropertyInternal(CSSPropertyID::kOffsetPath));
}
inline const css_longhand::OffsetPosition&
GetCSSPropertyOffsetPosition() {
  return *reinterpret_cast<const css_longhand::OffsetPosition *>(
      GetPropertyInternal(CSSPropertyID::kOffsetPosition));
}
inline const css_longhand::OffsetRotate&
GetCSSPropertyOffsetRotate() {
  return *reinterpret_cast<const css_longhand::OffsetRotate *>(
      GetPropertyInternal(CSSPropertyID::kOffsetRotate));
}
inline const css_longhand::Opacity&
GetCSSPropertyOpacity() {
  return *reinterpret_cast<const css_longhand::Opacity *>(
      GetPropertyInternal(CSSPropertyID::kOpacity));
}
inline const css_longhand::Order&
GetCSSPropertyOrder() {
  return *reinterpret_cast<const css_longhand::Order *>(
      GetPropertyInternal(CSSPropertyID::kOrder));
}
inline const css_longhand::OriginTrialTestProperty&
GetCSSPropertyOriginTrialTestProperty() {
  return *reinterpret_cast<const css_longhand::OriginTrialTestProperty *>(
      GetPropertyInternal(CSSPropertyID::kOriginTrialTestProperty));
}
inline const css_longhand::Orphans&
GetCSSPropertyOrphans() {
  return *reinterpret_cast<const css_longhand::Orphans *>(
      GetPropertyInternal(CSSPropertyID::kOrphans));
}
inline const css_longhand::OutlineColor&
GetCSSPropertyOutlineColor() {
  return *reinterpret_cast<const css_longhand::OutlineColor *>(
      GetPropertyInternal(CSSPropertyID::kOutlineColor));
}
inline const css_longhand::OutlineOffset&
GetCSSPropertyOutlineOffset() {
  return *reinterpret_cast<const css_longhand::OutlineOffset *>(
      GetPropertyInternal(CSSPropertyID::kOutlineOffset));
}
inline const css_longhand::OutlineStyle&
GetCSSPropertyOutlineStyle() {
  return *reinterpret_cast<const css_longhand::OutlineStyle *>(
      GetPropertyInternal(CSSPropertyID::kOutlineStyle));
}
inline const css_longhand::OutlineWidth&
GetCSSPropertyOutlineWidth() {
  return *reinterpret_cast<const css_longhand::OutlineWidth *>(
      GetPropertyInternal(CSSPropertyID::kOutlineWidth));
}
inline const css_longhand::OverflowAnchor&
GetCSSPropertyOverflowAnchor() {
  return *reinterpret_cast<const css_longhand::OverflowAnchor *>(
      GetPropertyInternal(CSSPropertyID::kOverflowAnchor));
}
inline const css_longhand::OverflowBlock&
GetCSSPropertyOverflowBlock() {
  return *reinterpret_cast<const css_longhand::OverflowBlock *>(
      GetPropertyInternal(CSSPropertyID::kOverflowBlock));
}
inline const css_longhand::OverflowClipMargin&
GetCSSPropertyOverflowClipMargin() {
  return *reinterpret_cast<const css_longhand::OverflowClipMargin *>(
      GetPropertyInternal(CSSPropertyID::kOverflowClipMargin));
}
inline const css_longhand::OverflowInline&
GetCSSPropertyOverflowInline() {
  return *reinterpret_cast<const css_longhand::OverflowInline *>(
      GetPropertyInternal(CSSPropertyID::kOverflowInline));
}
inline const css_longhand::OverflowWrap&
GetCSSPropertyOverflowWrap() {
  return *reinterpret_cast<const css_longhand::OverflowWrap *>(
      GetPropertyInternal(CSSPropertyID::kOverflowWrap));
}
inline const css_longhand::OverflowX&
GetCSSPropertyOverflowX() {
  return *reinterpret_cast<const css_longhand::OverflowX *>(
      GetPropertyInternal(CSSPropertyID::kOverflowX));
}
inline const css_longhand::OverflowY&
GetCSSPropertyOverflowY() {
  return *reinterpret_cast<const css_longhand::OverflowY *>(
      GetPropertyInternal(CSSPropertyID::kOverflowY));
}
inline const css_longhand::Overlay&
GetCSSPropertyOverlay() {
  return *reinterpret_cast<const css_longhand::Overlay *>(
      GetPropertyInternal(CSSPropertyID::kOverlay));
}
inline const css_longhand::OverrideColors&
GetCSSPropertyOverrideColors() {
  return *reinterpret_cast<const css_longhand::OverrideColors *>(
      GetPropertyInternal(CSSPropertyID::kOverrideColors));
}
inline const css_longhand::OverscrollBehaviorBlock&
GetCSSPropertyOverscrollBehaviorBlock() {
  return *reinterpret_cast<const css_longhand::OverscrollBehaviorBlock *>(
      GetPropertyInternal(CSSPropertyID::kOverscrollBehaviorBlock));
}
inline const css_longhand::OverscrollBehaviorInline&
GetCSSPropertyOverscrollBehaviorInline() {
  return *reinterpret_cast<const css_longhand::OverscrollBehaviorInline *>(
      GetPropertyInternal(CSSPropertyID::kOverscrollBehaviorInline));
}
inline const css_longhand::OverscrollBehaviorX&
GetCSSPropertyOverscrollBehaviorX() {
  return *reinterpret_cast<const css_longhand::OverscrollBehaviorX *>(
      GetPropertyInternal(CSSPropertyID::kOverscrollBehaviorX));
}
inline const css_longhand::OverscrollBehaviorY&
GetCSSPropertyOverscrollBehaviorY() {
  return *reinterpret_cast<const css_longhand::OverscrollBehaviorY *>(
      GetPropertyInternal(CSSPropertyID::kOverscrollBehaviorY));
}
inline const css_longhand::OverscrollContainerType&
GetCSSPropertyOverscrollContainerType() {
  return *reinterpret_cast<const css_longhand::OverscrollContainerType *>(
      GetPropertyInternal(CSSPropertyID::kOverscrollContainerType));
}
inline const css_longhand::Pad&
GetCSSPropertyPad() {
  return *reinterpret_cast<const css_longhand::Pad *>(
      GetPropertyInternal(CSSPropertyID::kPad));
}
inline const css_longhand::PaddingBlockEnd&
GetCSSPropertyPaddingBlockEnd() {
  return *reinterpret_cast<const css_longhand::PaddingBlockEnd *>(
      GetPropertyInternal(CSSPropertyID::kPaddingBlockEnd));
}
inline const css_longhand::PaddingBlockStart&
GetCSSPropertyPaddingBlockStart() {
  return *reinterpret_cast<const css_longhand::PaddingBlockStart *>(
      GetPropertyInternal(CSSPropertyID::kPaddingBlockStart));
}
inline const css_longhand::PaddingBottom&
GetCSSPropertyPaddingBottom() {
  return *reinterpret_cast<const css_longhand::PaddingBottom *>(
      GetPropertyInternal(CSSPropertyID::kPaddingBottom));
}
inline const css_longhand::PaddingInlineEnd&
GetCSSPropertyPaddingInlineEnd() {
  return *reinterpret_cast<const css_longhand::PaddingInlineEnd *>(
      GetPropertyInternal(CSSPropertyID::kPaddingInlineEnd));
}
inline const css_longhand::PaddingInlineStart&
GetCSSPropertyPaddingInlineStart() {
  return *reinterpret_cast<const css_longhand::PaddingInlineStart *>(
      GetPropertyInternal(CSSPropertyID::kPaddingInlineStart));
}
inline const css_longhand::PaddingLeft&
GetCSSPropertyPaddingLeft() {
  return *reinterpret_cast<const css_longhand::PaddingLeft *>(
      GetPropertyInternal(CSSPropertyID::kPaddingLeft));
}
inline const css_longhand::PaddingRight&
GetCSSPropertyPaddingRight() {
  return *reinterpret_cast<const css_longhand::PaddingRight *>(
      GetPropertyInternal(CSSPropertyID::kPaddingRight));
}
inline const css_longhand::PaddingTop&
GetCSSPropertyPaddingTop() {
  return *reinterpret_cast<const css_longhand::PaddingTop *>(
      GetPropertyInternal(CSSPropertyID::kPaddingTop));
}
inline const css_longhand::Page&
GetCSSPropertyPage() {
  return *reinterpret_cast<const css_longhand::Page *>(
      GetPropertyInternal(CSSPropertyID::kPage));
}
inline const css_longhand::PageMarginSafety&
GetCSSPropertyPageMarginSafety() {
  return *reinterpret_cast<const css_longhand::PageMarginSafety *>(
      GetPropertyInternal(CSSPropertyID::kPageMarginSafety));
}
inline const css_longhand::PageOrientation&
GetCSSPropertyPageOrientation() {
  return *reinterpret_cast<const css_longhand::PageOrientation *>(
      GetPropertyInternal(CSSPropertyID::kPageOrientation));
}
inline const css_longhand::PaintOrder&
GetCSSPropertyPaintOrder() {
  return *reinterpret_cast<const css_longhand::PaintOrder *>(
      GetPropertyInternal(CSSPropertyID::kPaintOrder));
}
inline const css_longhand::PathLength&
GetCSSPropertyPathLength() {
  return *reinterpret_cast<const css_longhand::PathLength *>(
      GetPropertyInternal(CSSPropertyID::kPathLength));
}
inline const css_longhand::Pathname&
GetCSSPropertyPathname() {
  return *reinterpret_cast<const css_longhand::Pathname *>(
      GetPropertyInternal(CSSPropertyID::kPathname));
}
inline const css_longhand::Pattern&
GetCSSPropertyPattern() {
  return *reinterpret_cast<const css_longhand::Pattern *>(
      GetPropertyInternal(CSSPropertyID::kPattern));
}
inline const css_longhand::Perspective&
GetCSSPropertyPerspective() {
  return *reinterpret_cast<const css_longhand::Perspective *>(
      GetPropertyInternal(CSSPropertyID::kPerspective));
}
inline const css_longhand::PerspectiveOrigin&
GetCSSPropertyPerspectiveOrigin() {
  return *reinterpret_cast<const css_longhand::PerspectiveOrigin *>(
      GetPropertyInternal(CSSPropertyID::kPerspectiveOrigin));
}
inline const css_longhand::PointerEvents&
GetCSSPropertyPointerEvents() {
  return *reinterpret_cast<const css_longhand::PointerEvents *>(
      GetPropertyInternal(CSSPropertyID::kPointerEvents));
}
inline const css_longhand::Port&
GetCSSPropertyPort() {
  return *reinterpret_cast<const css_longhand::Port *>(
      GetPropertyInternal(CSSPropertyID::kPort));
}
inline const css_longhand::PositionTryFallbacks&
GetCSSPropertyPositionTryFallbacks() {
  return *reinterpret_cast<const css_longhand::PositionTryFallbacks *>(
      GetPropertyInternal(CSSPropertyID::kPositionTryFallbacks));
}
inline const css_longhand::PositionTryOrder&
GetCSSPropertyPositionTryOrder() {
  return *reinterpret_cast<const css_longhand::PositionTryOrder *>(
      GetPropertyInternal(CSSPropertyID::kPositionTryOrder));
}
inline const css_longhand::PositionVisibility&
GetCSSPropertyPositionVisibility() {
  return *reinterpret_cast<const css_longhand::PositionVisibility *>(
      GetPropertyInternal(CSSPropertyID::kPositionVisibility));
}
inline const css_longhand::Prefix&
GetCSSPropertyPrefix() {
  return *reinterpret_cast<const css_longhand::Prefix *>(
      GetPropertyInternal(CSSPropertyID::kPrefix));
}
inline const css_longhand::PrintColorAdjust&
GetCSSPropertyPrintColorAdjust() {
  return *reinterpret_cast<const css_longhand::PrintColorAdjust *>(
      GetPropertyInternal(CSSPropertyID::kPrintColorAdjust));
}
inline const css_longhand::Protocol&
GetCSSPropertyProtocol() {
  return *reinterpret_cast<const css_longhand::Protocol *>(
      GetPropertyInternal(CSSPropertyID::kProtocol));
}
inline const css_longhand::Quotes&
GetCSSPropertyQuotes() {
  return *reinterpret_cast<const css_longhand::Quotes *>(
      GetPropertyInternal(CSSPropertyID::kQuotes));
}
inline const css_longhand::R&
GetCSSPropertyR() {
  return *reinterpret_cast<const css_longhand::R *>(
      GetPropertyInternal(CSSPropertyID::kR));
}
inline const css_longhand::Range&
GetCSSPropertyRange() {
  return *reinterpret_cast<const css_longhand::Range *>(
      GetPropertyInternal(CSSPropertyID::kRange));
}
inline const css_longhand::ReadingFlow&
GetCSSPropertyReadingFlow() {
  return *reinterpret_cast<const css_longhand::ReadingFlow *>(
      GetPropertyInternal(CSSPropertyID::kReadingFlow));
}
inline const css_longhand::ReadingOrder&
GetCSSPropertyReadingOrder() {
  return *reinterpret_cast<const css_longhand::ReadingOrder *>(
      GetPropertyInternal(CSSPropertyID::kReadingOrder));
}
inline const css_longhand::Resize&
GetCSSPropertyResize() {
  return *reinterpret_cast<const css_longhand::Resize *>(
      GetPropertyInternal(CSSPropertyID::kResize));
}
inline const css_longhand::Result&
GetCSSPropertyResult() {
  return *reinterpret_cast<const css_longhand::Result *>(
      GetPropertyInternal(CSSPropertyID::kResult));
}
inline const css_longhand::Right&
GetCSSPropertyRight() {
  return *reinterpret_cast<const css_longhand::Right *>(
      GetPropertyInternal(CSSPropertyID::kRight));
}
inline const css_longhand::Rotate&
GetCSSPropertyRotate() {
  return *reinterpret_cast<const css_longhand::Rotate *>(
      GetPropertyInternal(CSSPropertyID::kRotate));
}
inline const css_longhand::RowGap&
GetCSSPropertyRowGap() {
  return *reinterpret_cast<const css_longhand::RowGap *>(
      GetPropertyInternal(CSSPropertyID::kRowGap));
}
inline const css_longhand::RowRuleBreak&
GetCSSPropertyRowRuleBreak() {
  return *reinterpret_cast<const css_longhand::RowRuleBreak *>(
      GetPropertyInternal(CSSPropertyID::kRowRuleBreak));
}
inline const css_longhand::RowRuleColor&
GetCSSPropertyRowRuleColor() {
  return *reinterpret_cast<const css_longhand::RowRuleColor *>(
      GetPropertyInternal(CSSPropertyID::kRowRuleColor));
}
inline const css_longhand::RowRuleInsetCapEnd&
GetCSSPropertyRowRuleInsetCapEnd() {
  return *reinterpret_cast<const css_longhand::RowRuleInsetCapEnd *>(
      GetPropertyInternal(CSSPropertyID::kRowRuleInsetCapEnd));
}
inline const css_longhand::RowRuleInsetCapStart&
GetCSSPropertyRowRuleInsetCapStart() {
  return *reinterpret_cast<const css_longhand::RowRuleInsetCapStart *>(
      GetPropertyInternal(CSSPropertyID::kRowRuleInsetCapStart));
}
inline const css_longhand::RowRuleInsetJunctionEnd&
GetCSSPropertyRowRuleInsetJunctionEnd() {
  return *reinterpret_cast<const css_longhand::RowRuleInsetJunctionEnd *>(
      GetPropertyInternal(CSSPropertyID::kRowRuleInsetJunctionEnd));
}
inline const css_longhand::RowRuleInsetJunctionStart&
GetCSSPropertyRowRuleInsetJunctionStart() {
  return *reinterpret_cast<const css_longhand::RowRuleInsetJunctionStart *>(
      GetPropertyInternal(CSSPropertyID::kRowRuleInsetJunctionStart));
}
inline const css_longhand::RowRuleStyle&
GetCSSPropertyRowRuleStyle() {
  return *reinterpret_cast<const css_longhand::RowRuleStyle *>(
      GetPropertyInternal(CSSPropertyID::kRowRuleStyle));
}
inline const css_longhand::RowRuleVisibilityItems&
GetCSSPropertyRowRuleVisibilityItems() {
  return *reinterpret_cast<const css_longhand::RowRuleVisibilityItems *>(
      GetPropertyInternal(CSSPropertyID::kRowRuleVisibilityItems));
}
inline const css_longhand::RowRuleWidth&
GetCSSPropertyRowRuleWidth() {
  return *reinterpret_cast<const css_longhand::RowRuleWidth *>(
      GetPropertyInternal(CSSPropertyID::kRowRuleWidth));
}
inline const css_longhand::RubyAlign&
GetCSSPropertyRubyAlign() {
  return *reinterpret_cast<const css_longhand::RubyAlign *>(
      GetPropertyInternal(CSSPropertyID::kRubyAlign));
}
inline const css_longhand::RubyOverhang&
GetCSSPropertyRubyOverhang() {
  return *reinterpret_cast<const css_longhand::RubyOverhang *>(
      GetPropertyInternal(CSSPropertyID::kRubyOverhang));
}
inline const css_longhand::RubyPosition&
GetCSSPropertyRubyPosition() {
  return *reinterpret_cast<const css_longhand::RubyPosition *>(
      GetPropertyInternal(CSSPropertyID::kRubyPosition));
}
inline const css_longhand::RuleOverlap&
GetCSSPropertyRuleOverlap() {
  return *reinterpret_cast<const css_longhand::RuleOverlap *>(
      GetPropertyInternal(CSSPropertyID::kRuleOverlap));
}
inline const css_longhand::Rx&
GetCSSPropertyRx() {
  return *reinterpret_cast<const css_longhand::Rx *>(
      GetPropertyInternal(CSSPropertyID::kRx));
}
inline const css_longhand::Ry&
GetCSSPropertyRy() {
  return *reinterpret_cast<const css_longhand::Ry *>(
      GetPropertyInternal(CSSPropertyID::kRy));
}
inline const css_longhand::Scale&
GetCSSPropertyScale() {
  return *reinterpret_cast<const css_longhand::Scale *>(
      GetPropertyInternal(CSSPropertyID::kScale));
}
inline const css_longhand::ScrollAxisLock&
GetCSSPropertyScrollAxisLock() {
  return *reinterpret_cast<const css_longhand::ScrollAxisLock *>(
      GetPropertyInternal(CSSPropertyID::kScrollAxisLock));
}
inline const css_longhand::ScrollBehavior&
GetCSSPropertyScrollBehavior() {
  return *reinterpret_cast<const css_longhand::ScrollBehavior *>(
      GetPropertyInternal(CSSPropertyID::kScrollBehavior));
}
inline const css_longhand::ScrollInitialTarget&
GetCSSPropertyScrollInitialTarget() {
  return *reinterpret_cast<const css_longhand::ScrollInitialTarget *>(
      GetPropertyInternal(CSSPropertyID::kScrollInitialTarget));
}
inline const css_longhand::ScrollMarginBlockEnd&
GetCSSPropertyScrollMarginBlockEnd() {
  return *reinterpret_cast<const css_longhand::ScrollMarginBlockEnd *>(
      GetPropertyInternal(CSSPropertyID::kScrollMarginBlockEnd));
}
inline const css_longhand::ScrollMarginBlockStart&
GetCSSPropertyScrollMarginBlockStart() {
  return *reinterpret_cast<const css_longhand::ScrollMarginBlockStart *>(
      GetPropertyInternal(CSSPropertyID::kScrollMarginBlockStart));
}
inline const css_longhand::ScrollMarginBottom&
GetCSSPropertyScrollMarginBottom() {
  return *reinterpret_cast<const css_longhand::ScrollMarginBottom *>(
      GetPropertyInternal(CSSPropertyID::kScrollMarginBottom));
}
inline const css_longhand::ScrollMarginInlineEnd&
GetCSSPropertyScrollMarginInlineEnd() {
  return *reinterpret_cast<const css_longhand::ScrollMarginInlineEnd *>(
      GetPropertyInternal(CSSPropertyID::kScrollMarginInlineEnd));
}
inline const css_longhand::ScrollMarginInlineStart&
GetCSSPropertyScrollMarginInlineStart() {
  return *reinterpret_cast<const css_longhand::ScrollMarginInlineStart *>(
      GetPropertyInternal(CSSPropertyID::kScrollMarginInlineStart));
}
inline const css_longhand::ScrollMarginLeft&
GetCSSPropertyScrollMarginLeft() {
  return *reinterpret_cast<const css_longhand::ScrollMarginLeft *>(
      GetPropertyInternal(CSSPropertyID::kScrollMarginLeft));
}
inline const css_longhand::ScrollMarginRight&
GetCSSPropertyScrollMarginRight() {
  return *reinterpret_cast<const css_longhand::ScrollMarginRight *>(
      GetPropertyInternal(CSSPropertyID::kScrollMarginRight));
}
inline const css_longhand::ScrollMarginTop&
GetCSSPropertyScrollMarginTop() {
  return *reinterpret_cast<const css_longhand::ScrollMarginTop *>(
      GetPropertyInternal(CSSPropertyID::kScrollMarginTop));
}
inline const css_longhand::ScrollMarkerGroup&
GetCSSPropertyScrollMarkerGroup() {
  return *reinterpret_cast<const css_longhand::ScrollMarkerGroup *>(
      GetPropertyInternal(CSSPropertyID::kScrollMarkerGroup));
}
inline const css_longhand::ScrollPaddingBlockEnd&
GetCSSPropertyScrollPaddingBlockEnd() {
  return *reinterpret_cast<const css_longhand::ScrollPaddingBlockEnd *>(
      GetPropertyInternal(CSSPropertyID::kScrollPaddingBlockEnd));
}
inline const css_longhand::ScrollPaddingBlockStart&
GetCSSPropertyScrollPaddingBlockStart() {
  return *reinterpret_cast<const css_longhand::ScrollPaddingBlockStart *>(
      GetPropertyInternal(CSSPropertyID::kScrollPaddingBlockStart));
}
inline const css_longhand::ScrollPaddingBottom&
GetCSSPropertyScrollPaddingBottom() {
  return *reinterpret_cast<const css_longhand::ScrollPaddingBottom *>(
      GetPropertyInternal(CSSPropertyID::kScrollPaddingBottom));
}
inline const css_longhand::ScrollPaddingInlineEnd&
GetCSSPropertyScrollPaddingInlineEnd() {
  return *reinterpret_cast<const css_longhand::ScrollPaddingInlineEnd *>(
      GetPropertyInternal(CSSPropertyID::kScrollPaddingInlineEnd));
}
inline const css_longhand::ScrollPaddingInlineStart&
GetCSSPropertyScrollPaddingInlineStart() {
  return *reinterpret_cast<const css_longhand::ScrollPaddingInlineStart *>(
      GetPropertyInternal(CSSPropertyID::kScrollPaddingInlineStart));
}
inline const css_longhand::ScrollPaddingLeft&
GetCSSPropertyScrollPaddingLeft() {
  return *reinterpret_cast<const css_longhand::ScrollPaddingLeft *>(
      GetPropertyInternal(CSSPropertyID::kScrollPaddingLeft));
}
inline const css_longhand::ScrollPaddingRight&
GetCSSPropertyScrollPaddingRight() {
  return *reinterpret_cast<const css_longhand::ScrollPaddingRight *>(
      GetPropertyInternal(CSSPropertyID::kScrollPaddingRight));
}
inline const css_longhand::ScrollPaddingTop&
GetCSSPropertyScrollPaddingTop() {
  return *reinterpret_cast<const css_longhand::ScrollPaddingTop *>(
      GetPropertyInternal(CSSPropertyID::kScrollPaddingTop));
}
inline const css_longhand::ScrollSnapAlign&
GetCSSPropertyScrollSnapAlign() {
  return *reinterpret_cast<const css_longhand::ScrollSnapAlign *>(
      GetPropertyInternal(CSSPropertyID::kScrollSnapAlign));
}
inline const css_longhand::ScrollSnapStop&
GetCSSPropertyScrollSnapStop() {
  return *reinterpret_cast<const css_longhand::ScrollSnapStop *>(
      GetPropertyInternal(CSSPropertyID::kScrollSnapStop));
}
inline const css_longhand::ScrollSnapType&
GetCSSPropertyScrollSnapType() {
  return *reinterpret_cast<const css_longhand::ScrollSnapType *>(
      GetPropertyInternal(CSSPropertyID::kScrollSnapType));
}
inline const css_longhand::ScrollTargetGroup&
GetCSSPropertyScrollTargetGroup() {
  return *reinterpret_cast<const css_longhand::ScrollTargetGroup *>(
      GetPropertyInternal(CSSPropertyID::kScrollTargetGroup));
}
inline const css_longhand::ScrollTimelineAxis&
GetCSSPropertyScrollTimelineAxis() {
  return *reinterpret_cast<const css_longhand::ScrollTimelineAxis *>(
      GetPropertyInternal(CSSPropertyID::kScrollTimelineAxis));
}
inline const css_longhand::ScrollTimelineName&
GetCSSPropertyScrollTimelineName() {
  return *reinterpret_cast<const css_longhand::ScrollTimelineName *>(
      GetPropertyInternal(CSSPropertyID::kScrollTimelineName));
}
inline const css_longhand::ScrollbarColor&
GetCSSPropertyScrollbarColor() {
  return *reinterpret_cast<const css_longhand::ScrollbarColor *>(
      GetPropertyInternal(CSSPropertyID::kScrollbarColor));
}
inline const css_longhand::ScrollbarGutter&
GetCSSPropertyScrollbarGutter() {
  return *reinterpret_cast<const css_longhand::ScrollbarGutter *>(
      GetPropertyInternal(CSSPropertyID::kScrollbarGutter));
}
inline const css_longhand::ScrollbarWidth&
GetCSSPropertyScrollbarWidth() {
  return *reinterpret_cast<const css_longhand::ScrollbarWidth *>(
      GetPropertyInternal(CSSPropertyID::kScrollbarWidth));
}
inline const css_longhand::Search&
GetCSSPropertySearch() {
  return *reinterpret_cast<const css_longhand::Search *>(
      GetPropertyInternal(CSSPropertyID::kSearch));
}
inline const css_longhand::ShapeImageThreshold&
GetCSSPropertyShapeImageThreshold() {
  return *reinterpret_cast<const css_longhand::ShapeImageThreshold *>(
      GetPropertyInternal(CSSPropertyID::kShapeImageThreshold));
}
inline const css_longhand::ShapeMargin&
GetCSSPropertyShapeMargin() {
  return *reinterpret_cast<const css_longhand::ShapeMargin *>(
      GetPropertyInternal(CSSPropertyID::kShapeMargin));
}
inline const css_longhand::ShapeOutside&
GetCSSPropertyShapeOutside() {
  return *reinterpret_cast<const css_longhand::ShapeOutside *>(
      GetPropertyInternal(CSSPropertyID::kShapeOutside));
}
inline const css_longhand::ShapeRendering&
GetCSSPropertyShapeRendering() {
  return *reinterpret_cast<const css_longhand::ShapeRendering *>(
      GetPropertyInternal(CSSPropertyID::kShapeRendering));
}
inline const css_longhand::Size&
GetCSSPropertySize() {
  return *reinterpret_cast<const css_longhand::Size *>(
      GetPropertyInternal(CSSPropertyID::kSize));
}
inline const css_longhand::SizeAdjust&
GetCSSPropertySizeAdjust() {
  return *reinterpret_cast<const css_longhand::SizeAdjust *>(
      GetPropertyInternal(CSSPropertyID::kSizeAdjust));
}
inline const css_longhand::Speak&
GetCSSPropertySpeak() {
  return *reinterpret_cast<const css_longhand::Speak *>(
      GetPropertyInternal(CSSPropertyID::kSpeak));
}
inline const css_longhand::SpeakAs&
GetCSSPropertySpeakAs() {
  return *reinterpret_cast<const css_longhand::SpeakAs *>(
      GetPropertyInternal(CSSPropertyID::kSpeakAs));
}
inline const css_longhand::Src&
GetCSSPropertySrc() {
  return *reinterpret_cast<const css_longhand::Src *>(
      GetPropertyInternal(CSSPropertyID::kSrc));
}
inline const css_longhand::StopColor&
GetCSSPropertyStopColor() {
  return *reinterpret_cast<const css_longhand::StopColor *>(
      GetPropertyInternal(CSSPropertyID::kStopColor));
}
inline const css_longhand::StopOpacity&
GetCSSPropertyStopOpacity() {
  return *reinterpret_cast<const css_longhand::StopOpacity *>(
      GetPropertyInternal(CSSPropertyID::kStopOpacity));
}
inline const css_longhand::Stroke&
GetCSSPropertyStroke() {
  return *reinterpret_cast<const css_longhand::Stroke *>(
      GetPropertyInternal(CSSPropertyID::kStroke));
}
inline const css_longhand::StrokeDasharray&
GetCSSPropertyStrokeDasharray() {
  return *reinterpret_cast<const css_longhand::StrokeDasharray *>(
      GetPropertyInternal(CSSPropertyID::kStrokeDasharray));
}
inline const css_longhand::StrokeDashoffset&
GetCSSPropertyStrokeDashoffset() {
  return *reinterpret_cast<const css_longhand::StrokeDashoffset *>(
      GetPropertyInternal(CSSPropertyID::kStrokeDashoffset));
}
inline const css_longhand::StrokeLinecap&
GetCSSPropertyStrokeLinecap() {
  return *reinterpret_cast<const css_longhand::StrokeLinecap *>(
      GetPropertyInternal(CSSPropertyID::kStrokeLinecap));
}
inline const css_longhand::StrokeLinejoin&
GetCSSPropertyStrokeLinejoin() {
  return *reinterpret_cast<const css_longhand::StrokeLinejoin *>(
      GetPropertyInternal(CSSPropertyID::kStrokeLinejoin));
}
inline const css_longhand::StrokeMiterlimit&
GetCSSPropertyStrokeMiterlimit() {
  return *reinterpret_cast<const css_longhand::StrokeMiterlimit *>(
      GetPropertyInternal(CSSPropertyID::kStrokeMiterlimit));
}
inline const css_longhand::StrokeOpacity&
GetCSSPropertyStrokeOpacity() {
  return *reinterpret_cast<const css_longhand::StrokeOpacity *>(
      GetPropertyInternal(CSSPropertyID::kStrokeOpacity));
}
inline const css_longhand::StrokeWidth&
GetCSSPropertyStrokeWidth() {
  return *reinterpret_cast<const css_longhand::StrokeWidth *>(
      GetPropertyInternal(CSSPropertyID::kStrokeWidth));
}
inline const css_longhand::Suffix&
GetCSSPropertySuffix() {
  return *reinterpret_cast<const css_longhand::Suffix *>(
      GetPropertyInternal(CSSPropertyID::kSuffix));
}
inline const css_longhand::Symbols&
GetCSSPropertySymbols() {
  return *reinterpret_cast<const css_longhand::Symbols *>(
      GetPropertyInternal(CSSPropertyID::kSymbols));
}
inline const css_longhand::Syntax&
GetCSSPropertySyntax() {
  return *reinterpret_cast<const css_longhand::Syntax *>(
      GetPropertyInternal(CSSPropertyID::kSyntax));
}
inline const css_longhand::System&
GetCSSPropertySystem() {
  return *reinterpret_cast<const css_longhand::System *>(
      GetPropertyInternal(CSSPropertyID::kSystem));
}
inline const css_longhand::TabSize&
GetCSSPropertyTabSize() {
  return *reinterpret_cast<const css_longhand::TabSize *>(
      GetPropertyInternal(CSSPropertyID::kTabSize));
}
inline const css_longhand::TableLayout&
GetCSSPropertyTableLayout() {
  return *reinterpret_cast<const css_longhand::TableLayout *>(
      GetPropertyInternal(CSSPropertyID::kTableLayout));
}
inline const css_longhand::TextAlign&
GetCSSPropertyTextAlign() {
  return *reinterpret_cast<const css_longhand::TextAlign *>(
      GetPropertyInternal(CSSPropertyID::kTextAlign));
}
inline const css_longhand::TextAlignLast&
GetCSSPropertyTextAlignLast() {
  return *reinterpret_cast<const css_longhand::TextAlignLast *>(
      GetPropertyInternal(CSSPropertyID::kTextAlignLast));
}
inline const css_longhand::TextAnchor&
GetCSSPropertyTextAnchor() {
  return *reinterpret_cast<const css_longhand::TextAnchor *>(
      GetPropertyInternal(CSSPropertyID::kTextAnchor));
}
inline const css_longhand::TextAutospace&
GetCSSPropertyTextAutospace() {
  return *reinterpret_cast<const css_longhand::TextAutospace *>(
      GetPropertyInternal(CSSPropertyID::kTextAutospace));
}
inline const css_longhand::TextBoxEdge&
GetCSSPropertyTextBoxEdge() {
  return *reinterpret_cast<const css_longhand::TextBoxEdge *>(
      GetPropertyInternal(CSSPropertyID::kTextBoxEdge));
}
inline const css_longhand::TextBoxTrim&
GetCSSPropertyTextBoxTrim() {
  return *reinterpret_cast<const css_longhand::TextBoxTrim *>(
      GetPropertyInternal(CSSPropertyID::kTextBoxTrim));
}
inline const css_longhand::TextCombineUpright&
GetCSSPropertyTextCombineUpright() {
  return *reinterpret_cast<const css_longhand::TextCombineUpright *>(
      GetPropertyInternal(CSSPropertyID::kTextCombineUpright));
}
inline const css_longhand::TextDecorationColor&
GetCSSPropertyTextDecorationColor() {
  return *reinterpret_cast<const css_longhand::TextDecorationColor *>(
      GetPropertyInternal(CSSPropertyID::kTextDecorationColor));
}
inline const css_longhand::TextDecorationInset&
GetCSSPropertyTextDecorationInset() {
  return *reinterpret_cast<const css_longhand::TextDecorationInset *>(
      GetPropertyInternal(CSSPropertyID::kTextDecorationInset));
}
inline const css_longhand::TextDecorationLine&
GetCSSPropertyTextDecorationLine() {
  return *reinterpret_cast<const css_longhand::TextDecorationLine *>(
      GetPropertyInternal(CSSPropertyID::kTextDecorationLine));
}
inline const css_longhand::TextDecorationSkipInk&
GetCSSPropertyTextDecorationSkipInk() {
  return *reinterpret_cast<const css_longhand::TextDecorationSkipInk *>(
      GetPropertyInternal(CSSPropertyID::kTextDecorationSkipInk));
}
inline const css_longhand::TextDecorationSkipSpaces&
GetCSSPropertyTextDecorationSkipSpaces() {
  return *reinterpret_cast<const css_longhand::TextDecorationSkipSpaces *>(
      GetPropertyInternal(CSSPropertyID::kTextDecorationSkipSpaces));
}
inline const css_longhand::TextDecorationStyle&
GetCSSPropertyTextDecorationStyle() {
  return *reinterpret_cast<const css_longhand::TextDecorationStyle *>(
      GetPropertyInternal(CSSPropertyID::kTextDecorationStyle));
}
inline const css_longhand::TextDecorationThickness&
GetCSSPropertyTextDecorationThickness() {
  return *reinterpret_cast<const css_longhand::TextDecorationThickness *>(
      GetPropertyInternal(CSSPropertyID::kTextDecorationThickness));
}
inline const css_longhand::TextEmphasisColor&
GetCSSPropertyTextEmphasisColor() {
  return *reinterpret_cast<const css_longhand::TextEmphasisColor *>(
      GetPropertyInternal(CSSPropertyID::kTextEmphasisColor));
}
inline const css_longhand::TextEmphasisPosition&
GetCSSPropertyTextEmphasisPosition() {
  return *reinterpret_cast<const css_longhand::TextEmphasisPosition *>(
      GetPropertyInternal(CSSPropertyID::kTextEmphasisPosition));
}
inline const css_longhand::TextEmphasisStyle&
GetCSSPropertyTextEmphasisStyle() {
  return *reinterpret_cast<const css_longhand::TextEmphasisStyle *>(
      GetPropertyInternal(CSSPropertyID::kTextEmphasisStyle));
}
inline const css_longhand::TextFit&
GetCSSPropertyTextFit() {
  return *reinterpret_cast<const css_longhand::TextFit *>(
      GetPropertyInternal(CSSPropertyID::kTextFit));
}
inline const css_longhand::TextIndent&
GetCSSPropertyTextIndent() {
  return *reinterpret_cast<const css_longhand::TextIndent *>(
      GetPropertyInternal(CSSPropertyID::kTextIndent));
}
inline const css_longhand::TextJustify&
GetCSSPropertyTextJustify() {
  return *reinterpret_cast<const css_longhand::TextJustify *>(
      GetPropertyInternal(CSSPropertyID::kTextJustify));
}
inline const css_longhand::TextOverflow&
GetCSSPropertyTextOverflow() {
  return *reinterpret_cast<const css_longhand::TextOverflow *>(
      GetPropertyInternal(CSSPropertyID::kTextOverflow));
}
inline const css_longhand::TextShadow&
GetCSSPropertyTextShadow() {
  return *reinterpret_cast<const css_longhand::TextShadow *>(
      GetPropertyInternal(CSSPropertyID::kTextShadow));
}
inline const css_longhand::TextTransform&
GetCSSPropertyTextTransform() {
  return *reinterpret_cast<const css_longhand::TextTransform *>(
      GetPropertyInternal(CSSPropertyID::kTextTransform));
}
inline const css_longhand::TextUnderlineOffset&
GetCSSPropertyTextUnderlineOffset() {
  return *reinterpret_cast<const css_longhand::TextUnderlineOffset *>(
      GetPropertyInternal(CSSPropertyID::kTextUnderlineOffset));
}
inline const css_longhand::TextUnderlinePosition&
GetCSSPropertyTextUnderlinePosition() {
  return *reinterpret_cast<const css_longhand::TextUnderlinePosition *>(
      GetPropertyInternal(CSSPropertyID::kTextUnderlinePosition));
}
inline const css_longhand::TextWrapMode&
GetCSSPropertyTextWrapMode() {
  return *reinterpret_cast<const css_longhand::TextWrapMode *>(
      GetPropertyInternal(CSSPropertyID::kTextWrapMode));
}
inline const css_longhand::TextWrapStyle&
GetCSSPropertyTextWrapStyle() {
  return *reinterpret_cast<const css_longhand::TextWrapStyle *>(
      GetPropertyInternal(CSSPropertyID::kTextWrapStyle));
}
inline const css_longhand::TimelineScope&
GetCSSPropertyTimelineScope() {
  return *reinterpret_cast<const css_longhand::TimelineScope *>(
      GetPropertyInternal(CSSPropertyID::kTimelineScope));
}
inline const css_longhand::TimelineTriggerActivationRangeEnd&
GetCSSPropertyTimelineTriggerActivationRangeEnd() {
  return *reinterpret_cast<const css_longhand::TimelineTriggerActivationRangeEnd *>(
      GetPropertyInternal(CSSPropertyID::kTimelineTriggerActivationRangeEnd));
}
inline const css_longhand::TimelineTriggerActivationRangeStart&
GetCSSPropertyTimelineTriggerActivationRangeStart() {
  return *reinterpret_cast<const css_longhand::TimelineTriggerActivationRangeStart *>(
      GetPropertyInternal(CSSPropertyID::kTimelineTriggerActivationRangeStart));
}
inline const css_longhand::TimelineTriggerActiveRangeEnd&
GetCSSPropertyTimelineTriggerActiveRangeEnd() {
  return *reinterpret_cast<const css_longhand::TimelineTriggerActiveRangeEnd *>(
      GetPropertyInternal(CSSPropertyID::kTimelineTriggerActiveRangeEnd));
}
inline const css_longhand::TimelineTriggerActiveRangeStart&
GetCSSPropertyTimelineTriggerActiveRangeStart() {
  return *reinterpret_cast<const css_longhand::TimelineTriggerActiveRangeStart *>(
      GetPropertyInternal(CSSPropertyID::kTimelineTriggerActiveRangeStart));
}
inline const css_longhand::TimelineTriggerName&
GetCSSPropertyTimelineTriggerName() {
  return *reinterpret_cast<const css_longhand::TimelineTriggerName *>(
      GetPropertyInternal(CSSPropertyID::kTimelineTriggerName));
}
inline const css_longhand::TimelineTriggerSource&
GetCSSPropertyTimelineTriggerSource() {
  return *reinterpret_cast<const css_longhand::TimelineTriggerSource *>(
      GetPropertyInternal(CSSPropertyID::kTimelineTriggerSource));
}
inline const css_longhand::Top&
GetCSSPropertyTop() {
  return *reinterpret_cast<const css_longhand::Top *>(
      GetPropertyInternal(CSSPropertyID::kTop));
}
inline const css_longhand::TouchAction&
GetCSSPropertyTouchAction() {
  return *reinterpret_cast<const css_longhand::TouchAction *>(
      GetPropertyInternal(CSSPropertyID::kTouchAction));
}
inline const css_longhand::Transform&
GetCSSPropertyTransform() {
  return *reinterpret_cast<const css_longhand::Transform *>(
      GetPropertyInternal(CSSPropertyID::kTransform));
}
inline const css_longhand::TransformBox&
GetCSSPropertyTransformBox() {
  return *reinterpret_cast<const css_longhand::TransformBox *>(
      GetPropertyInternal(CSSPropertyID::kTransformBox));
}
inline const css_longhand::TransformOrigin&
GetCSSPropertyTransformOrigin() {
  return *reinterpret_cast<const css_longhand::TransformOrigin *>(
      GetPropertyInternal(CSSPropertyID::kTransformOrigin));
}
inline const css_longhand::TransformStyle&
GetCSSPropertyTransformStyle() {
  return *reinterpret_cast<const css_longhand::TransformStyle *>(
      GetPropertyInternal(CSSPropertyID::kTransformStyle));
}
inline const css_longhand::TransitionBehavior&
GetCSSPropertyTransitionBehavior() {
  return *reinterpret_cast<const css_longhand::TransitionBehavior *>(
      GetPropertyInternal(CSSPropertyID::kTransitionBehavior));
}
inline const css_longhand::TransitionDelay&
GetCSSPropertyTransitionDelay() {
  return *reinterpret_cast<const css_longhand::TransitionDelay *>(
      GetPropertyInternal(CSSPropertyID::kTransitionDelay));
}
inline const css_longhand::TransitionDuration&
GetCSSPropertyTransitionDuration() {
  return *reinterpret_cast<const css_longhand::TransitionDuration *>(
      GetPropertyInternal(CSSPropertyID::kTransitionDuration));
}
inline const css_longhand::TransitionProperty&
GetCSSPropertyTransitionProperty() {
  return *reinterpret_cast<const css_longhand::TransitionProperty *>(
      GetPropertyInternal(CSSPropertyID::kTransitionProperty));
}
inline const css_longhand::TransitionTimingFunction&
GetCSSPropertyTransitionTimingFunction() {
  return *reinterpret_cast<const css_longhand::TransitionTimingFunction *>(
      GetPropertyInternal(CSSPropertyID::kTransitionTimingFunction));
}
inline const css_longhand::Translate&
GetCSSPropertyTranslate() {
  return *reinterpret_cast<const css_longhand::Translate *>(
      GetPropertyInternal(CSSPropertyID::kTranslate));
}
inline const css_longhand::TriggerScope&
GetCSSPropertyTriggerScope() {
  return *reinterpret_cast<const css_longhand::TriggerScope *>(
      GetPropertyInternal(CSSPropertyID::kTriggerScope));
}
inline const css_longhand::Types&
GetCSSPropertyTypes() {
  return *reinterpret_cast<const css_longhand::Types *>(
      GetPropertyInternal(CSSPropertyID::kTypes));
}
inline const css_longhand::UnicodeBidi&
GetCSSPropertyUnicodeBidi() {
  return *reinterpret_cast<const css_longhand::UnicodeBidi *>(
      GetPropertyInternal(CSSPropertyID::kUnicodeBidi));
}
inline const css_longhand::UnicodeRange&
GetCSSPropertyUnicodeRange() {
  return *reinterpret_cast<const css_longhand::UnicodeRange *>(
      GetPropertyInternal(CSSPropertyID::kUnicodeRange));
}
inline const css_longhand::UserSelect&
GetCSSPropertyUserSelect() {
  return *reinterpret_cast<const css_longhand::UserSelect *>(
      GetPropertyInternal(CSSPropertyID::kUserSelect));
}
inline const css_longhand::VectorEffect&
GetCSSPropertyVectorEffect() {
  return *reinterpret_cast<const css_longhand::VectorEffect *>(
      GetPropertyInternal(CSSPropertyID::kVectorEffect));
}
inline const css_longhand::VerticalAlign&
GetCSSPropertyVerticalAlign() {
  return *reinterpret_cast<const css_longhand::VerticalAlign *>(
      GetPropertyInternal(CSSPropertyID::kVerticalAlign));
}
inline const css_longhand::ViewTimelineAxis&
GetCSSPropertyViewTimelineAxis() {
  return *reinterpret_cast<const css_longhand::ViewTimelineAxis *>(
      GetPropertyInternal(CSSPropertyID::kViewTimelineAxis));
}
inline const css_longhand::ViewTimelineInset&
GetCSSPropertyViewTimelineInset() {
  return *reinterpret_cast<const css_longhand::ViewTimelineInset *>(
      GetPropertyInternal(CSSPropertyID::kViewTimelineInset));
}
inline const css_longhand::ViewTimelineName&
GetCSSPropertyViewTimelineName() {
  return *reinterpret_cast<const css_longhand::ViewTimelineName *>(
      GetPropertyInternal(CSSPropertyID::kViewTimelineName));
}
inline const css_longhand::ViewTransitionClass&
GetCSSPropertyViewTransitionClass() {
  return *reinterpret_cast<const css_longhand::ViewTransitionClass *>(
      GetPropertyInternal(CSSPropertyID::kViewTransitionClass));
}
inline const css_longhand::ViewTransitionGroup&
GetCSSPropertyViewTransitionGroup() {
  return *reinterpret_cast<const css_longhand::ViewTransitionGroup *>(
      GetPropertyInternal(CSSPropertyID::kViewTransitionGroup));
}
inline const css_longhand::ViewTransitionName&
GetCSSPropertyViewTransitionName() {
  return *reinterpret_cast<const css_longhand::ViewTransitionName *>(
      GetPropertyInternal(CSSPropertyID::kViewTransitionName));
}
inline const css_longhand::ViewTransitionScope&
GetCSSPropertyViewTransitionScope() {
  return *reinterpret_cast<const css_longhand::ViewTransitionScope *>(
      GetPropertyInternal(CSSPropertyID::kViewTransitionScope));
}
inline const css_longhand::Visibility&
GetCSSPropertyVisibility() {
  return *reinterpret_cast<const css_longhand::Visibility *>(
      GetPropertyInternal(CSSPropertyID::kVisibility));
}
inline const css_longhand::WebkitBorderHorizontalSpacing&
GetCSSPropertyWebkitBorderHorizontalSpacing() {
  return *reinterpret_cast<const css_longhand::WebkitBorderHorizontalSpacing *>(
      GetPropertyInternal(CSSPropertyID::kWebkitBorderHorizontalSpacing));
}
inline const css_longhand::WebkitBorderImage&
GetCSSPropertyWebkitBorderImage() {
  return *reinterpret_cast<const css_longhand::WebkitBorderImage *>(
      GetPropertyInternal(CSSPropertyID::kWebkitBorderImage));
}
inline const css_longhand::WebkitBorderVerticalSpacing&
GetCSSPropertyWebkitBorderVerticalSpacing() {
  return *reinterpret_cast<const css_longhand::WebkitBorderVerticalSpacing *>(
      GetPropertyInternal(CSSPropertyID::kWebkitBorderVerticalSpacing));
}
inline const css_longhand::WebkitBoxAlign&
GetCSSPropertyWebkitBoxAlign() {
  return *reinterpret_cast<const css_longhand::WebkitBoxAlign *>(
      GetPropertyInternal(CSSPropertyID::kWebkitBoxAlign));
}
inline const css_longhand::WebkitBoxDecorationBreak&
GetCSSPropertyWebkitBoxDecorationBreak() {
  return *reinterpret_cast<const css_longhand::WebkitBoxDecorationBreak *>(
      GetPropertyInternal(CSSPropertyID::kWebkitBoxDecorationBreak));
}
inline const css_longhand::WebkitBoxDirection&
GetCSSPropertyWebkitBoxDirection() {
  return *reinterpret_cast<const css_longhand::WebkitBoxDirection *>(
      GetPropertyInternal(CSSPropertyID::kWebkitBoxDirection));
}
inline const css_longhand::WebkitBoxFlex&
GetCSSPropertyWebkitBoxFlex() {
  return *reinterpret_cast<const css_longhand::WebkitBoxFlex *>(
      GetPropertyInternal(CSSPropertyID::kWebkitBoxFlex));
}
inline const css_longhand::WebkitBoxOrdinalGroup&
GetCSSPropertyWebkitBoxOrdinalGroup() {
  return *reinterpret_cast<const css_longhand::WebkitBoxOrdinalGroup *>(
      GetPropertyInternal(CSSPropertyID::kWebkitBoxOrdinalGroup));
}
inline const css_longhand::WebkitBoxOrient&
GetCSSPropertyWebkitBoxOrient() {
  return *reinterpret_cast<const css_longhand::WebkitBoxOrient *>(
      GetPropertyInternal(CSSPropertyID::kWebkitBoxOrient));
}
inline const css_longhand::WebkitBoxPack&
GetCSSPropertyWebkitBoxPack() {
  return *reinterpret_cast<const css_longhand::WebkitBoxPack *>(
      GetPropertyInternal(CSSPropertyID::kWebkitBoxPack));
}
inline const css_longhand::WebkitBoxReflect&
GetCSSPropertyWebkitBoxReflect() {
  return *reinterpret_cast<const css_longhand::WebkitBoxReflect *>(
      GetPropertyInternal(CSSPropertyID::kWebkitBoxReflect));
}
inline const css_longhand::WebkitLineBreak&
GetCSSPropertyWebkitLineBreak() {
  return *reinterpret_cast<const css_longhand::WebkitLineBreak *>(
      GetPropertyInternal(CSSPropertyID::kWebkitLineBreak));
}
inline const css_longhand::WebkitLineClamp&
GetCSSPropertyWebkitLineClamp() {
  return *reinterpret_cast<const css_longhand::WebkitLineClamp *>(
      GetPropertyInternal(CSSPropertyID::kWebkitLineClamp));
}
inline const css_longhand::WebkitMaskBoxImageOutset&
GetCSSPropertyWebkitMaskBoxImageOutset() {
  return *reinterpret_cast<const css_longhand::WebkitMaskBoxImageOutset *>(
      GetPropertyInternal(CSSPropertyID::kWebkitMaskBoxImageOutset));
}
inline const css_longhand::WebkitMaskBoxImageRepeat&
GetCSSPropertyWebkitMaskBoxImageRepeat() {
  return *reinterpret_cast<const css_longhand::WebkitMaskBoxImageRepeat *>(
      GetPropertyInternal(CSSPropertyID::kWebkitMaskBoxImageRepeat));
}
inline const css_longhand::WebkitMaskBoxImageSlice&
GetCSSPropertyWebkitMaskBoxImageSlice() {
  return *reinterpret_cast<const css_longhand::WebkitMaskBoxImageSlice *>(
      GetPropertyInternal(CSSPropertyID::kWebkitMaskBoxImageSlice));
}
inline const css_longhand::WebkitMaskBoxImageSource&
GetCSSPropertyWebkitMaskBoxImageSource() {
  return *reinterpret_cast<const css_longhand::WebkitMaskBoxImageSource *>(
      GetPropertyInternal(CSSPropertyID::kWebkitMaskBoxImageSource));
}
inline const css_longhand::WebkitMaskBoxImageWidth&
GetCSSPropertyWebkitMaskBoxImageWidth() {
  return *reinterpret_cast<const css_longhand::WebkitMaskBoxImageWidth *>(
      GetPropertyInternal(CSSPropertyID::kWebkitMaskBoxImageWidth));
}
inline const css_longhand::WebkitMaskPositionX&
GetCSSPropertyWebkitMaskPositionX() {
  return *reinterpret_cast<const css_longhand::WebkitMaskPositionX *>(
      GetPropertyInternal(CSSPropertyID::kWebkitMaskPositionX));
}
inline const css_longhand::WebkitMaskPositionY&
GetCSSPropertyWebkitMaskPositionY() {
  return *reinterpret_cast<const css_longhand::WebkitMaskPositionY *>(
      GetPropertyInternal(CSSPropertyID::kWebkitMaskPositionY));
}
inline const css_longhand::WebkitPerspectiveOriginX&
GetCSSPropertyWebkitPerspectiveOriginX() {
  return *reinterpret_cast<const css_longhand::WebkitPerspectiveOriginX *>(
      GetPropertyInternal(CSSPropertyID::kWebkitPerspectiveOriginX));
}
inline const css_longhand::WebkitPerspectiveOriginY&
GetCSSPropertyWebkitPerspectiveOriginY() {
  return *reinterpret_cast<const css_longhand::WebkitPerspectiveOriginY *>(
      GetPropertyInternal(CSSPropertyID::kWebkitPerspectiveOriginY));
}
inline const css_longhand::WebkitRtlOrdering&
GetCSSPropertyWebkitRtlOrdering() {
  return *reinterpret_cast<const css_longhand::WebkitRtlOrdering *>(
      GetPropertyInternal(CSSPropertyID::kWebkitRtlOrdering));
}
inline const css_longhand::WebkitRubyPosition&
GetCSSPropertyWebkitRubyPosition() {
  return *reinterpret_cast<const css_longhand::WebkitRubyPosition *>(
      GetPropertyInternal(CSSPropertyID::kWebkitRubyPosition));
}
inline const css_longhand::WebkitTapHighlightColor&
GetCSSPropertyWebkitTapHighlightColor() {
  return *reinterpret_cast<const css_longhand::WebkitTapHighlightColor *>(
      GetPropertyInternal(CSSPropertyID::kWebkitTapHighlightColor));
}
inline const css_longhand::WebkitTextCombine&
GetCSSPropertyWebkitTextCombine() {
  return *reinterpret_cast<const css_longhand::WebkitTextCombine *>(
      GetPropertyInternal(CSSPropertyID::kWebkitTextCombine));
}
inline const css_longhand::WebkitTextDecorationsInEffect&
GetCSSPropertyWebkitTextDecorationsInEffect() {
  return *reinterpret_cast<const css_longhand::WebkitTextDecorationsInEffect *>(
      GetPropertyInternal(CSSPropertyID::kWebkitTextDecorationsInEffect));
}
inline const css_longhand::WebkitTextFillColor&
GetCSSPropertyWebkitTextFillColor() {
  return *reinterpret_cast<const css_longhand::WebkitTextFillColor *>(
      GetPropertyInternal(CSSPropertyID::kWebkitTextFillColor));
}
inline const css_longhand::WebkitTextSecurity&
GetCSSPropertyWebkitTextSecurity() {
  return *reinterpret_cast<const css_longhand::WebkitTextSecurity *>(
      GetPropertyInternal(CSSPropertyID::kWebkitTextSecurity));
}
inline const css_longhand::WebkitTextStrokeColor&
GetCSSPropertyWebkitTextStrokeColor() {
  return *reinterpret_cast<const css_longhand::WebkitTextStrokeColor *>(
      GetPropertyInternal(CSSPropertyID::kWebkitTextStrokeColor));
}
inline const css_longhand::WebkitTextStrokeWidth&
GetCSSPropertyWebkitTextStrokeWidth() {
  return *reinterpret_cast<const css_longhand::WebkitTextStrokeWidth *>(
      GetPropertyInternal(CSSPropertyID::kWebkitTextStrokeWidth));
}
inline const css_longhand::WebkitTransformOriginX&
GetCSSPropertyWebkitTransformOriginX() {
  return *reinterpret_cast<const css_longhand::WebkitTransformOriginX *>(
      GetPropertyInternal(CSSPropertyID::kWebkitTransformOriginX));
}
inline const css_longhand::WebkitTransformOriginY&
GetCSSPropertyWebkitTransformOriginY() {
  return *reinterpret_cast<const css_longhand::WebkitTransformOriginY *>(
      GetPropertyInternal(CSSPropertyID::kWebkitTransformOriginY));
}
inline const css_longhand::WebkitTransformOriginZ&
GetCSSPropertyWebkitTransformOriginZ() {
  return *reinterpret_cast<const css_longhand::WebkitTransformOriginZ *>(
      GetPropertyInternal(CSSPropertyID::kWebkitTransformOriginZ));
}
inline const css_longhand::WebkitUserDrag&
GetCSSPropertyWebkitUserDrag() {
  return *reinterpret_cast<const css_longhand::WebkitUserDrag *>(
      GetPropertyInternal(CSSPropertyID::kWebkitUserDrag));
}
inline const css_longhand::WebkitUserModify&
GetCSSPropertyWebkitUserModify() {
  return *reinterpret_cast<const css_longhand::WebkitUserModify *>(
      GetPropertyInternal(CSSPropertyID::kWebkitUserModify));
}
inline const css_longhand::WhiteSpaceCollapse&
GetCSSPropertyWhiteSpaceCollapse() {
  return *reinterpret_cast<const css_longhand::WhiteSpaceCollapse *>(
      GetPropertyInternal(CSSPropertyID::kWhiteSpaceCollapse));
}
inline const css_longhand::Widows&
GetCSSPropertyWidows() {
  return *reinterpret_cast<const css_longhand::Widows *>(
      GetPropertyInternal(CSSPropertyID::kWidows));
}
inline const css_longhand::Width&
GetCSSPropertyWidth() {
  return *reinterpret_cast<const css_longhand::Width *>(
      GetPropertyInternal(CSSPropertyID::kWidth));
}
inline const css_longhand::WillChange&
GetCSSPropertyWillChange() {
  return *reinterpret_cast<const css_longhand::WillChange *>(
      GetPropertyInternal(CSSPropertyID::kWillChange));
}
inline const css_longhand::WindowDrag&
GetCSSPropertyWindowDrag() {
  return *reinterpret_cast<const css_longhand::WindowDrag *>(
      GetPropertyInternal(CSSPropertyID::kWindowDrag));
}
inline const css_longhand::WordBreak&
GetCSSPropertyWordBreak() {
  return *reinterpret_cast<const css_longhand::WordBreak *>(
      GetPropertyInternal(CSSPropertyID::kWordBreak));
}
inline const css_longhand::WordSpacing&
GetCSSPropertyWordSpacing() {
  return *reinterpret_cast<const css_longhand::WordSpacing *>(
      GetPropertyInternal(CSSPropertyID::kWordSpacing));
}
inline const css_longhand::X&
GetCSSPropertyX() {
  return *reinterpret_cast<const css_longhand::X *>(
      GetPropertyInternal(CSSPropertyID::kX));
}
inline const css_longhand::Y&
GetCSSPropertyY() {
  return *reinterpret_cast<const css_longhand::Y *>(
      GetPropertyInternal(CSSPropertyID::kY));
}
inline const css_longhand::ZIndex&
GetCSSPropertyZIndex() {
  return *reinterpret_cast<const css_longhand::ZIndex *>(
      GetPropertyInternal(CSSPropertyID::kZIndex));
}
inline const css_longhand::MaskComposite&
GetCSSPropertyMaskComposite() {
  return *reinterpret_cast<const css_longhand::MaskComposite *>(
      GetPropertyInternal(CSSPropertyID::kMaskComposite));
}
inline const css_shorthand::AlternativeLineClampShorthand&
GetCSSPropertyAlternativeLineClampShorthand() {
  return *reinterpret_cast<const css_shorthand::AlternativeLineClampShorthand *>(
      GetPropertyInternal(CSSPropertyID::kAlternativeLineClampShorthand));
}
inline const css_shorthand::AlternativeWebkitLineClampShorthand&
GetCSSPropertyAlternativeWebkitLineClampShorthand() {
  return *reinterpret_cast<const css_shorthand::AlternativeWebkitLineClampShorthand *>(
      GetPropertyInternal(CSSPropertyID::kAlternativeWebkitLineClampShorthand));
}
inline const css_shorthand::Animation&
GetCSSPropertyAnimation() {
  return *reinterpret_cast<const css_shorthand::Animation *>(
      GetPropertyInternal(CSSPropertyID::kAnimation));
}
inline const css_shorthand::AnimationRange&
GetCSSPropertyAnimationRange() {
  return *reinterpret_cast<const css_shorthand::AnimationRange *>(
      GetPropertyInternal(CSSPropertyID::kAnimationRange));
}
inline const css_shorthand::Background&
GetCSSPropertyBackground() {
  return *reinterpret_cast<const css_shorthand::Background *>(
      GetPropertyInternal(CSSPropertyID::kBackground));
}
inline const css_shorthand::BackgroundPosition&
GetCSSPropertyBackgroundPosition() {
  return *reinterpret_cast<const css_shorthand::BackgroundPosition *>(
      GetPropertyInternal(CSSPropertyID::kBackgroundPosition));
}
inline const css_shorthand::Border&
GetCSSPropertyBorder() {
  return *reinterpret_cast<const css_shorthand::Border *>(
      GetPropertyInternal(CSSPropertyID::kBorder));
}
inline const css_shorthand::BorderBlock&
GetCSSPropertyBorderBlock() {
  return *reinterpret_cast<const css_shorthand::BorderBlock *>(
      GetPropertyInternal(CSSPropertyID::kBorderBlock));
}
inline const css_shorthand::BorderBlockColor&
GetCSSPropertyBorderBlockColor() {
  return *reinterpret_cast<const css_shorthand::BorderBlockColor *>(
      GetPropertyInternal(CSSPropertyID::kBorderBlockColor));
}
inline const css_shorthand::BorderBlockEnd&
GetCSSPropertyBorderBlockEnd() {
  return *reinterpret_cast<const css_shorthand::BorderBlockEnd *>(
      GetPropertyInternal(CSSPropertyID::kBorderBlockEnd));
}
inline const css_shorthand::BorderBlockStart&
GetCSSPropertyBorderBlockStart() {
  return *reinterpret_cast<const css_shorthand::BorderBlockStart *>(
      GetPropertyInternal(CSSPropertyID::kBorderBlockStart));
}
inline const css_shorthand::BorderBlockStyle&
GetCSSPropertyBorderBlockStyle() {
  return *reinterpret_cast<const css_shorthand::BorderBlockStyle *>(
      GetPropertyInternal(CSSPropertyID::kBorderBlockStyle));
}
inline const css_shorthand::BorderBlockWidth&
GetCSSPropertyBorderBlockWidth() {
  return *reinterpret_cast<const css_shorthand::BorderBlockWidth *>(
      GetPropertyInternal(CSSPropertyID::kBorderBlockWidth));
}
inline const css_shorthand::BorderBottom&
GetCSSPropertyBorderBottom() {
  return *reinterpret_cast<const css_shorthand::BorderBottom *>(
      GetPropertyInternal(CSSPropertyID::kBorderBottom));
}
inline const css_shorthand::BorderColor&
GetCSSPropertyBorderColor() {
  return *reinterpret_cast<const css_shorthand::BorderColor *>(
      GetPropertyInternal(CSSPropertyID::kBorderColor));
}
inline const css_shorthand::BorderImage&
GetCSSPropertyBorderImage() {
  return *reinterpret_cast<const css_shorthand::BorderImage *>(
      GetPropertyInternal(CSSPropertyID::kBorderImage));
}
inline const css_shorthand::BorderInline&
GetCSSPropertyBorderInline() {
  return *reinterpret_cast<const css_shorthand::BorderInline *>(
      GetPropertyInternal(CSSPropertyID::kBorderInline));
}
inline const css_shorthand::BorderInlineColor&
GetCSSPropertyBorderInlineColor() {
  return *reinterpret_cast<const css_shorthand::BorderInlineColor *>(
      GetPropertyInternal(CSSPropertyID::kBorderInlineColor));
}
inline const css_shorthand::BorderInlineEnd&
GetCSSPropertyBorderInlineEnd() {
  return *reinterpret_cast<const css_shorthand::BorderInlineEnd *>(
      GetPropertyInternal(CSSPropertyID::kBorderInlineEnd));
}
inline const css_shorthand::BorderInlineStart&
GetCSSPropertyBorderInlineStart() {
  return *reinterpret_cast<const css_shorthand::BorderInlineStart *>(
      GetPropertyInternal(CSSPropertyID::kBorderInlineStart));
}
inline const css_shorthand::BorderInlineStyle&
GetCSSPropertyBorderInlineStyle() {
  return *reinterpret_cast<const css_shorthand::BorderInlineStyle *>(
      GetPropertyInternal(CSSPropertyID::kBorderInlineStyle));
}
inline const css_shorthand::BorderInlineWidth&
GetCSSPropertyBorderInlineWidth() {
  return *reinterpret_cast<const css_shorthand::BorderInlineWidth *>(
      GetPropertyInternal(CSSPropertyID::kBorderInlineWidth));
}
inline const css_shorthand::BorderLeft&
GetCSSPropertyBorderLeft() {
  return *reinterpret_cast<const css_shorthand::BorderLeft *>(
      GetPropertyInternal(CSSPropertyID::kBorderLeft));
}
inline const css_shorthand::BorderRadius&
GetCSSPropertyBorderRadius() {
  return *reinterpret_cast<const css_shorthand::BorderRadius *>(
      GetPropertyInternal(CSSPropertyID::kBorderRadius));
}
inline const css_shorthand::BorderRight&
GetCSSPropertyBorderRight() {
  return *reinterpret_cast<const css_shorthand::BorderRight *>(
      GetPropertyInternal(CSSPropertyID::kBorderRight));
}
inline const css_shorthand::BorderSpacing&
GetCSSPropertyBorderSpacing() {
  return *reinterpret_cast<const css_shorthand::BorderSpacing *>(
      GetPropertyInternal(CSSPropertyID::kBorderSpacing));
}
inline const css_shorthand::BorderStyle&
GetCSSPropertyBorderStyle() {
  return *reinterpret_cast<const css_shorthand::BorderStyle *>(
      GetPropertyInternal(CSSPropertyID::kBorderStyle));
}
inline const css_shorthand::BorderTop&
GetCSSPropertyBorderTop() {
  return *reinterpret_cast<const css_shorthand::BorderTop *>(
      GetPropertyInternal(CSSPropertyID::kBorderTop));
}
inline const css_shorthand::BorderWidth&
GetCSSPropertyBorderWidth() {
  return *reinterpret_cast<const css_shorthand::BorderWidth *>(
      GetPropertyInternal(CSSPropertyID::kBorderWidth));
}
inline const css_shorthand::ColumnRule&
GetCSSPropertyColumnRule() {
  return *reinterpret_cast<const css_shorthand::ColumnRule *>(
      GetPropertyInternal(CSSPropertyID::kColumnRule));
}
inline const css_shorthand::ColumnRuleInset&
GetCSSPropertyColumnRuleInset() {
  return *reinterpret_cast<const css_shorthand::ColumnRuleInset *>(
      GetPropertyInternal(CSSPropertyID::kColumnRuleInset));
}
inline const css_shorthand::ColumnRuleInsetCap&
GetCSSPropertyColumnRuleInsetCap() {
  return *reinterpret_cast<const css_shorthand::ColumnRuleInsetCap *>(
      GetPropertyInternal(CSSPropertyID::kColumnRuleInsetCap));
}
inline const css_shorthand::ColumnRuleInsetEnd&
GetCSSPropertyColumnRuleInsetEnd() {
  return *reinterpret_cast<const css_shorthand::ColumnRuleInsetEnd *>(
      GetPropertyInternal(CSSPropertyID::kColumnRuleInsetEnd));
}
inline const css_shorthand::ColumnRuleInsetJunction&
GetCSSPropertyColumnRuleInsetJunction() {
  return *reinterpret_cast<const css_shorthand::ColumnRuleInsetJunction *>(
      GetPropertyInternal(CSSPropertyID::kColumnRuleInsetJunction));
}
inline const css_shorthand::ColumnRuleInsetStart&
GetCSSPropertyColumnRuleInsetStart() {
  return *reinterpret_cast<const css_shorthand::ColumnRuleInsetStart *>(
      GetPropertyInternal(CSSPropertyID::kColumnRuleInsetStart));
}
inline const css_shorthand::Columns&
GetCSSPropertyColumns() {
  return *reinterpret_cast<const css_shorthand::Columns *>(
      GetPropertyInternal(CSSPropertyID::kColumns));
}
inline const css_shorthand::ContainIntrinsicSize&
GetCSSPropertyContainIntrinsicSize() {
  return *reinterpret_cast<const css_shorthand::ContainIntrinsicSize *>(
      GetPropertyInternal(CSSPropertyID::kContainIntrinsicSize));
}
inline const css_shorthand::Container&
GetCSSPropertyContainer() {
  return *reinterpret_cast<const css_shorthand::Container *>(
      GetPropertyInternal(CSSPropertyID::kContainer));
}
inline const css_shorthand::Corner&
GetCSSPropertyCorner() {
  return *reinterpret_cast<const css_shorthand::Corner *>(
      GetPropertyInternal(CSSPropertyID::kCorner));
}
inline const css_shorthand::CornerBlockEnd&
GetCSSPropertyCornerBlockEnd() {
  return *reinterpret_cast<const css_shorthand::CornerBlockEnd *>(
      GetPropertyInternal(CSSPropertyID::kCornerBlockEnd));
}
inline const css_shorthand::CornerBlockEndShape&
GetCSSPropertyCornerBlockEndShape() {
  return *reinterpret_cast<const css_shorthand::CornerBlockEndShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerBlockEndShape));
}
inline const css_shorthand::CornerBlockStart&
GetCSSPropertyCornerBlockStart() {
  return *reinterpret_cast<const css_shorthand::CornerBlockStart *>(
      GetPropertyInternal(CSSPropertyID::kCornerBlockStart));
}
inline const css_shorthand::CornerBlockStartShape&
GetCSSPropertyCornerBlockStartShape() {
  return *reinterpret_cast<const css_shorthand::CornerBlockStartShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerBlockStartShape));
}
inline const css_shorthand::CornerBottom&
GetCSSPropertyCornerBottom() {
  return *reinterpret_cast<const css_shorthand::CornerBottom *>(
      GetPropertyInternal(CSSPropertyID::kCornerBottom));
}
inline const css_shorthand::CornerBottomLeft&
GetCSSPropertyCornerBottomLeft() {
  return *reinterpret_cast<const css_shorthand::CornerBottomLeft *>(
      GetPropertyInternal(CSSPropertyID::kCornerBottomLeft));
}
inline const css_shorthand::CornerBottomRight&
GetCSSPropertyCornerBottomRight() {
  return *reinterpret_cast<const css_shorthand::CornerBottomRight *>(
      GetPropertyInternal(CSSPropertyID::kCornerBottomRight));
}
inline const css_shorthand::CornerBottomShape&
GetCSSPropertyCornerBottomShape() {
  return *reinterpret_cast<const css_shorthand::CornerBottomShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerBottomShape));
}
inline const css_shorthand::CornerEndEnd&
GetCSSPropertyCornerEndEnd() {
  return *reinterpret_cast<const css_shorthand::CornerEndEnd *>(
      GetPropertyInternal(CSSPropertyID::kCornerEndEnd));
}
inline const css_shorthand::CornerEndStart&
GetCSSPropertyCornerEndStart() {
  return *reinterpret_cast<const css_shorthand::CornerEndStart *>(
      GetPropertyInternal(CSSPropertyID::kCornerEndStart));
}
inline const css_shorthand::CornerInlineEnd&
GetCSSPropertyCornerInlineEnd() {
  return *reinterpret_cast<const css_shorthand::CornerInlineEnd *>(
      GetPropertyInternal(CSSPropertyID::kCornerInlineEnd));
}
inline const css_shorthand::CornerInlineEndShape&
GetCSSPropertyCornerInlineEndShape() {
  return *reinterpret_cast<const css_shorthand::CornerInlineEndShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerInlineEndShape));
}
inline const css_shorthand::CornerInlineStart&
GetCSSPropertyCornerInlineStart() {
  return *reinterpret_cast<const css_shorthand::CornerInlineStart *>(
      GetPropertyInternal(CSSPropertyID::kCornerInlineStart));
}
inline const css_shorthand::CornerInlineStartShape&
GetCSSPropertyCornerInlineStartShape() {
  return *reinterpret_cast<const css_shorthand::CornerInlineStartShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerInlineStartShape));
}
inline const css_shorthand::CornerLeft&
GetCSSPropertyCornerLeft() {
  return *reinterpret_cast<const css_shorthand::CornerLeft *>(
      GetPropertyInternal(CSSPropertyID::kCornerLeft));
}
inline const css_shorthand::CornerLeftShape&
GetCSSPropertyCornerLeftShape() {
  return *reinterpret_cast<const css_shorthand::CornerLeftShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerLeftShape));
}
inline const css_shorthand::CornerRight&
GetCSSPropertyCornerRight() {
  return *reinterpret_cast<const css_shorthand::CornerRight *>(
      GetPropertyInternal(CSSPropertyID::kCornerRight));
}
inline const css_shorthand::CornerRightShape&
GetCSSPropertyCornerRightShape() {
  return *reinterpret_cast<const css_shorthand::CornerRightShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerRightShape));
}
inline const css_shorthand::CornerShape&
GetCSSPropertyCornerShape() {
  return *reinterpret_cast<const css_shorthand::CornerShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerShape));
}
inline const css_shorthand::CornerStartEnd&
GetCSSPropertyCornerStartEnd() {
  return *reinterpret_cast<const css_shorthand::CornerStartEnd *>(
      GetPropertyInternal(CSSPropertyID::kCornerStartEnd));
}
inline const css_shorthand::CornerStartStart&
GetCSSPropertyCornerStartStart() {
  return *reinterpret_cast<const css_shorthand::CornerStartStart *>(
      GetPropertyInternal(CSSPropertyID::kCornerStartStart));
}
inline const css_shorthand::CornerTop&
GetCSSPropertyCornerTop() {
  return *reinterpret_cast<const css_shorthand::CornerTop *>(
      GetPropertyInternal(CSSPropertyID::kCornerTop));
}
inline const css_shorthand::CornerTopLeft&
GetCSSPropertyCornerTopLeft() {
  return *reinterpret_cast<const css_shorthand::CornerTopLeft *>(
      GetPropertyInternal(CSSPropertyID::kCornerTopLeft));
}
inline const css_shorthand::CornerTopRight&
GetCSSPropertyCornerTopRight() {
  return *reinterpret_cast<const css_shorthand::CornerTopRight *>(
      GetPropertyInternal(CSSPropertyID::kCornerTopRight));
}
inline const css_shorthand::CornerTopShape&
GetCSSPropertyCornerTopShape() {
  return *reinterpret_cast<const css_shorthand::CornerTopShape *>(
      GetPropertyInternal(CSSPropertyID::kCornerTopShape));
}
inline const css_shorthand::Flex&
GetCSSPropertyFlex() {
  return *reinterpret_cast<const css_shorthand::Flex *>(
      GetPropertyInternal(CSSPropertyID::kFlex));
}
inline const css_shorthand::FlexFlow&
GetCSSPropertyFlexFlow() {
  return *reinterpret_cast<const css_shorthand::FlexFlow *>(
      GetPropertyInternal(CSSPropertyID::kFlexFlow));
}
inline const css_shorthand::Font&
GetCSSPropertyFont() {
  return *reinterpret_cast<const css_shorthand::Font *>(
      GetPropertyInternal(CSSPropertyID::kFont));
}
inline const css_shorthand::FontSynthesis&
GetCSSPropertyFontSynthesis() {
  return *reinterpret_cast<const css_shorthand::FontSynthesis *>(
      GetPropertyInternal(CSSPropertyID::kFontSynthesis));
}
inline const css_shorthand::FontVariant&
GetCSSPropertyFontVariant() {
  return *reinterpret_cast<const css_shorthand::FontVariant *>(
      GetPropertyInternal(CSSPropertyID::kFontVariant));
}
inline const css_shorthand::Gap&
GetCSSPropertyGap() {
  return *reinterpret_cast<const css_shorthand::Gap *>(
      GetPropertyInternal(CSSPropertyID::kGap));
}
inline const css_shorthand::Grid&
GetCSSPropertyGrid() {
  return *reinterpret_cast<const css_shorthand::Grid *>(
      GetPropertyInternal(CSSPropertyID::kGrid));
}
inline const css_shorthand::GridArea&
GetCSSPropertyGridArea() {
  return *reinterpret_cast<const css_shorthand::GridArea *>(
      GetPropertyInternal(CSSPropertyID::kGridArea));
}
inline const css_shorthand::GridColumn&
GetCSSPropertyGridColumn() {
  return *reinterpret_cast<const css_shorthand::GridColumn *>(
      GetPropertyInternal(CSSPropertyID::kGridColumn));
}
inline const css_shorthand::GridLanes&
GetCSSPropertyGridLanes() {
  return *reinterpret_cast<const css_shorthand::GridLanes *>(
      GetPropertyInternal(CSSPropertyID::kGridLanes));
}
inline const css_shorthand::GridRow&
GetCSSPropertyGridRow() {
  return *reinterpret_cast<const css_shorthand::GridRow *>(
      GetPropertyInternal(CSSPropertyID::kGridRow));
}
inline const css_shorthand::GridTemplate&
GetCSSPropertyGridTemplate() {
  return *reinterpret_cast<const css_shorthand::GridTemplate *>(
      GetPropertyInternal(CSSPropertyID::kGridTemplate));
}
inline const css_shorthand::Inset&
GetCSSPropertyInset() {
  return *reinterpret_cast<const css_shorthand::Inset *>(
      GetPropertyInternal(CSSPropertyID::kInset));
}
inline const css_shorthand::InsetBlock&
GetCSSPropertyInsetBlock() {
  return *reinterpret_cast<const css_shorthand::InsetBlock *>(
      GetPropertyInternal(CSSPropertyID::kInsetBlock));
}
inline const css_shorthand::InsetInline&
GetCSSPropertyInsetInline() {
  return *reinterpret_cast<const css_shorthand::InsetInline *>(
      GetPropertyInternal(CSSPropertyID::kInsetInline));
}
inline const css_shorthand::InterestDelay&
GetCSSPropertyInterestDelay() {
  return *reinterpret_cast<const css_shorthand::InterestDelay *>(
      GetPropertyInternal(CSSPropertyID::kInterestDelay));
}
inline const css_shorthand::ListStyle&
GetCSSPropertyListStyle() {
  return *reinterpret_cast<const css_shorthand::ListStyle *>(
      GetPropertyInternal(CSSPropertyID::kListStyle));
}
inline const css_shorthand::Margin&
GetCSSPropertyMargin() {
  return *reinterpret_cast<const css_shorthand::Margin *>(
      GetPropertyInternal(CSSPropertyID::kMargin));
}
inline const css_shorthand::MarginBlock&
GetCSSPropertyMarginBlock() {
  return *reinterpret_cast<const css_shorthand::MarginBlock *>(
      GetPropertyInternal(CSSPropertyID::kMarginBlock));
}
inline const css_shorthand::MarginInline&
GetCSSPropertyMarginInline() {
  return *reinterpret_cast<const css_shorthand::MarginInline *>(
      GetPropertyInternal(CSSPropertyID::kMarginInline));
}
inline const css_shorthand::Marker&
GetCSSPropertyMarker() {
  return *reinterpret_cast<const css_shorthand::Marker *>(
      GetPropertyInternal(CSSPropertyID::kMarker));
}
inline const css_shorthand::Mask&
GetCSSPropertyMask() {
  return *reinterpret_cast<const css_shorthand::Mask *>(
      GetPropertyInternal(CSSPropertyID::kMask));
}
inline const css_shorthand::MaskPosition&
GetCSSPropertyMaskPosition() {
  return *reinterpret_cast<const css_shorthand::MaskPosition *>(
      GetPropertyInternal(CSSPropertyID::kMaskPosition));
}
inline const css_shorthand::Offset&
GetCSSPropertyOffset() {
  return *reinterpret_cast<const css_shorthand::Offset *>(
      GetPropertyInternal(CSSPropertyID::kOffset));
}
inline const css_shorthand::Outline&
GetCSSPropertyOutline() {
  return *reinterpret_cast<const css_shorthand::Outline *>(
      GetPropertyInternal(CSSPropertyID::kOutline));
}
inline const css_shorthand::Overflow&
GetCSSPropertyOverflow() {
  return *reinterpret_cast<const css_shorthand::Overflow *>(
      GetPropertyInternal(CSSPropertyID::kOverflow));
}
inline const css_shorthand::OverscrollBehavior&
GetCSSPropertyOverscrollBehavior() {
  return *reinterpret_cast<const css_shorthand::OverscrollBehavior *>(
      GetPropertyInternal(CSSPropertyID::kOverscrollBehavior));
}
inline const css_shorthand::Padding&
GetCSSPropertyPadding() {
  return *reinterpret_cast<const css_shorthand::Padding *>(
      GetPropertyInternal(CSSPropertyID::kPadding));
}
inline const css_shorthand::PaddingBlock&
GetCSSPropertyPaddingBlock() {
  return *reinterpret_cast<const css_shorthand::PaddingBlock *>(
      GetPropertyInternal(CSSPropertyID::kPaddingBlock));
}
inline const css_shorthand::PaddingInline&
GetCSSPropertyPaddingInline() {
  return *reinterpret_cast<const css_shorthand::PaddingInline *>(
      GetPropertyInternal(CSSPropertyID::kPaddingInline));
}
inline const css_shorthand::PageBreakAfter&
GetCSSPropertyPageBreakAfter() {
  return *reinterpret_cast<const css_shorthand::PageBreakAfter *>(
      GetPropertyInternal(CSSPropertyID::kPageBreakAfter));
}
inline const css_shorthand::PageBreakBefore&
GetCSSPropertyPageBreakBefore() {
  return *reinterpret_cast<const css_shorthand::PageBreakBefore *>(
      GetPropertyInternal(CSSPropertyID::kPageBreakBefore));
}
inline const css_shorthand::PageBreakInside&
GetCSSPropertyPageBreakInside() {
  return *reinterpret_cast<const css_shorthand::PageBreakInside *>(
      GetPropertyInternal(CSSPropertyID::kPageBreakInside));
}
inline const css_shorthand::PlaceContent&
GetCSSPropertyPlaceContent() {
  return *reinterpret_cast<const css_shorthand::PlaceContent *>(
      GetPropertyInternal(CSSPropertyID::kPlaceContent));
}
inline const css_shorthand::PlaceItems&
GetCSSPropertyPlaceItems() {
  return *reinterpret_cast<const css_shorthand::PlaceItems *>(
      GetPropertyInternal(CSSPropertyID::kPlaceItems));
}
inline const css_shorthand::PlaceSelf&
GetCSSPropertyPlaceSelf() {
  return *reinterpret_cast<const css_shorthand::PlaceSelf *>(
      GetPropertyInternal(CSSPropertyID::kPlaceSelf));
}
inline const css_shorthand::PositionTry&
GetCSSPropertyPositionTry() {
  return *reinterpret_cast<const css_shorthand::PositionTry *>(
      GetPropertyInternal(CSSPropertyID::kPositionTry));
}
inline const css_shorthand::RowRule&
GetCSSPropertyRowRule() {
  return *reinterpret_cast<const css_shorthand::RowRule *>(
      GetPropertyInternal(CSSPropertyID::kRowRule));
}
inline const css_shorthand::RowRuleInset&
GetCSSPropertyRowRuleInset() {
  return *reinterpret_cast<const css_shorthand::RowRuleInset *>(
      GetPropertyInternal(CSSPropertyID::kRowRuleInset));
}
inline const css_shorthand::RowRuleInsetCap&
GetCSSPropertyRowRuleInsetCap() {
  return *reinterpret_cast<const css_shorthand::RowRuleInsetCap *>(
      GetPropertyInternal(CSSPropertyID::kRowRuleInsetCap));
}
inline const css_shorthand::RowRuleInsetEnd&
GetCSSPropertyRowRuleInsetEnd() {
  return *reinterpret_cast<const css_shorthand::RowRuleInsetEnd *>(
      GetPropertyInternal(CSSPropertyID::kRowRuleInsetEnd));
}
inline const css_shorthand::RowRuleInsetJunction&
GetCSSPropertyRowRuleInsetJunction() {
  return *reinterpret_cast<const css_shorthand::RowRuleInsetJunction *>(
      GetPropertyInternal(CSSPropertyID::kRowRuleInsetJunction));
}
inline const css_shorthand::RowRuleInsetStart&
GetCSSPropertyRowRuleInsetStart() {
  return *reinterpret_cast<const css_shorthand::RowRuleInsetStart *>(
      GetPropertyInternal(CSSPropertyID::kRowRuleInsetStart));
}
inline const css_shorthand::Rule&
GetCSSPropertyRule() {
  return *reinterpret_cast<const css_shorthand::Rule *>(
      GetPropertyInternal(CSSPropertyID::kRule));
}
inline const css_shorthand::RuleBreak&
GetCSSPropertyRuleBreak() {
  return *reinterpret_cast<const css_shorthand::RuleBreak *>(
      GetPropertyInternal(CSSPropertyID::kRuleBreak));
}
inline const css_shorthand::RuleColor&
GetCSSPropertyRuleColor() {
  return *reinterpret_cast<const css_shorthand::RuleColor *>(
      GetPropertyInternal(CSSPropertyID::kRuleColor));
}
inline const css_shorthand::RuleInset&
GetCSSPropertyRuleInset() {
  return *reinterpret_cast<const css_shorthand::RuleInset *>(
      GetPropertyInternal(CSSPropertyID::kRuleInset));
}
inline const css_shorthand::RuleInsetCap&
GetCSSPropertyRuleInsetCap() {
  return *reinterpret_cast<const css_shorthand::RuleInsetCap *>(
      GetPropertyInternal(CSSPropertyID::kRuleInsetCap));
}
inline const css_shorthand::RuleInsetEnd&
GetCSSPropertyRuleInsetEnd() {
  return *reinterpret_cast<const css_shorthand::RuleInsetEnd *>(
      GetPropertyInternal(CSSPropertyID::kRuleInsetEnd));
}
inline const css_shorthand::RuleInsetJunction&
GetCSSPropertyRuleInsetJunction() {
  return *reinterpret_cast<const css_shorthand::RuleInsetJunction *>(
      GetPropertyInternal(CSSPropertyID::kRuleInsetJunction));
}
inline const css_shorthand::RuleInsetStart&
GetCSSPropertyRuleInsetStart() {
  return *reinterpret_cast<const css_shorthand::RuleInsetStart *>(
      GetPropertyInternal(CSSPropertyID::kRuleInsetStart));
}
inline const css_shorthand::RuleStyle&
GetCSSPropertyRuleStyle() {
  return *reinterpret_cast<const css_shorthand::RuleStyle *>(
      GetPropertyInternal(CSSPropertyID::kRuleStyle));
}
inline const css_shorthand::RuleVisibilityItems&
GetCSSPropertyRuleVisibilityItems() {
  return *reinterpret_cast<const css_shorthand::RuleVisibilityItems *>(
      GetPropertyInternal(CSSPropertyID::kRuleVisibilityItems));
}
inline const css_shorthand::RuleWidth&
GetCSSPropertyRuleWidth() {
  return *reinterpret_cast<const css_shorthand::RuleWidth *>(
      GetPropertyInternal(CSSPropertyID::kRuleWidth));
}
inline const css_shorthand::ScrollMargin&
GetCSSPropertyScrollMargin() {
  return *reinterpret_cast<const css_shorthand::ScrollMargin *>(
      GetPropertyInternal(CSSPropertyID::kScrollMargin));
}
inline const css_shorthand::ScrollMarginBlock&
GetCSSPropertyScrollMarginBlock() {
  return *reinterpret_cast<const css_shorthand::ScrollMarginBlock *>(
      GetPropertyInternal(CSSPropertyID::kScrollMarginBlock));
}
inline const css_shorthand::ScrollMarginInline&
GetCSSPropertyScrollMarginInline() {
  return *reinterpret_cast<const css_shorthand::ScrollMarginInline *>(
      GetPropertyInternal(CSSPropertyID::kScrollMarginInline));
}
inline const css_shorthand::ScrollPadding&
GetCSSPropertyScrollPadding() {
  return *reinterpret_cast<const css_shorthand::ScrollPadding *>(
      GetPropertyInternal(CSSPropertyID::kScrollPadding));
}
inline const css_shorthand::ScrollPaddingBlock&
GetCSSPropertyScrollPaddingBlock() {
  return *reinterpret_cast<const css_shorthand::ScrollPaddingBlock *>(
      GetPropertyInternal(CSSPropertyID::kScrollPaddingBlock));
}
inline const css_shorthand::ScrollPaddingInline&
GetCSSPropertyScrollPaddingInline() {
  return *reinterpret_cast<const css_shorthand::ScrollPaddingInline *>(
      GetPropertyInternal(CSSPropertyID::kScrollPaddingInline));
}
inline const css_shorthand::ScrollTimeline&
GetCSSPropertyScrollTimeline() {
  return *reinterpret_cast<const css_shorthand::ScrollTimeline *>(
      GetPropertyInternal(CSSPropertyID::kScrollTimeline));
}
inline const css_shorthand::TextBox&
GetCSSPropertyTextBox() {
  return *reinterpret_cast<const css_shorthand::TextBox *>(
      GetPropertyInternal(CSSPropertyID::kTextBox));
}
inline const css_shorthand::TextDecoration&
GetCSSPropertyTextDecoration() {
  return *reinterpret_cast<const css_shorthand::TextDecoration *>(
      GetPropertyInternal(CSSPropertyID::kTextDecoration));
}
inline const css_shorthand::TextEmphasis&
GetCSSPropertyTextEmphasis() {
  return *reinterpret_cast<const css_shorthand::TextEmphasis *>(
      GetPropertyInternal(CSSPropertyID::kTextEmphasis));
}
inline const css_shorthand::TextSpacing&
GetCSSPropertyTextSpacing() {
  return *reinterpret_cast<const css_shorthand::TextSpacing *>(
      GetPropertyInternal(CSSPropertyID::kTextSpacing));
}
inline const css_shorthand::TextWrap&
GetCSSPropertyTextWrap() {
  return *reinterpret_cast<const css_shorthand::TextWrap *>(
      GetPropertyInternal(CSSPropertyID::kTextWrap));
}
inline const css_shorthand::TimelineTrigger&
GetCSSPropertyTimelineTrigger() {
  return *reinterpret_cast<const css_shorthand::TimelineTrigger *>(
      GetPropertyInternal(CSSPropertyID::kTimelineTrigger));
}
inline const css_shorthand::TimelineTriggerActivationRange&
GetCSSPropertyTimelineTriggerActivationRange() {
  return *reinterpret_cast<const css_shorthand::TimelineTriggerActivationRange *>(
      GetPropertyInternal(CSSPropertyID::kTimelineTriggerActivationRange));
}
inline const css_shorthand::TimelineTriggerActiveRange&
GetCSSPropertyTimelineTriggerActiveRange() {
  return *reinterpret_cast<const css_shorthand::TimelineTriggerActiveRange *>(
      GetPropertyInternal(CSSPropertyID::kTimelineTriggerActiveRange));
}
inline const css_shorthand::Transition&
GetCSSPropertyTransition() {
  return *reinterpret_cast<const css_shorthand::Transition *>(
      GetPropertyInternal(CSSPropertyID::kTransition));
}
inline const css_shorthand::ViewTimeline&
GetCSSPropertyViewTimeline() {
  return *reinterpret_cast<const css_shorthand::ViewTimeline *>(
      GetPropertyInternal(CSSPropertyID::kViewTimeline));
}
inline const css_shorthand::WebkitColumnBreakAfter&
GetCSSPropertyWebkitColumnBreakAfter() {
  return *reinterpret_cast<const css_shorthand::WebkitColumnBreakAfter *>(
      GetPropertyInternal(CSSPropertyID::kWebkitColumnBreakAfter));
}
inline const css_shorthand::WebkitColumnBreakBefore&
GetCSSPropertyWebkitColumnBreakBefore() {
  return *reinterpret_cast<const css_shorthand::WebkitColumnBreakBefore *>(
      GetPropertyInternal(CSSPropertyID::kWebkitColumnBreakBefore));
}
inline const css_shorthand::WebkitColumnBreakInside&
GetCSSPropertyWebkitColumnBreakInside() {
  return *reinterpret_cast<const css_shorthand::WebkitColumnBreakInside *>(
      GetPropertyInternal(CSSPropertyID::kWebkitColumnBreakInside));
}
inline const css_shorthand::WebkitMaskBoxImage&
GetCSSPropertyWebkitMaskBoxImage() {
  return *reinterpret_cast<const css_shorthand::WebkitMaskBoxImage *>(
      GetPropertyInternal(CSSPropertyID::kWebkitMaskBoxImage));
}
inline const css_shorthand::WebkitTextStroke&
GetCSSPropertyWebkitTextStroke() {
  return *reinterpret_cast<const css_shorthand::WebkitTextStroke *>(
      GetPropertyInternal(CSSPropertyID::kWebkitTextStroke));
}
inline const css_shorthand::WhiteSpace&
GetCSSPropertyWhiteSpace() {
  return *reinterpret_cast<const css_shorthand::WhiteSpace *>(
      GetPropertyInternal(CSSPropertyID::kWhiteSpace));
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PROPERTY_INSTANCES_H_
