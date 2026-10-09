// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/css/templates/css_value_id_mappings_generated.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/core/css/css_value_keywords.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5


#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_CSS_CSS_VALUE_ID_MAPPINGS_GENERATED_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_CSS_CSS_VALUE_ID_MAPPINGS_GENERATED_H_

#include "base/notreached.h"
#include "base/check_op.h"
#include "third_party/blink/renderer/core/css_value_keywords.h"
#include "third_party/blink/renderer/core/style/computed_style_base_constants.h"
#include "cc/input/scroll_snap_data.h"
#include "third_party/blink/public/common/css/page_orientation.h"
#include "third_party/blink/public/mojom/frame/color_scheme.mojom-blink.h"
#include "third_party/blink/public/mojom/scroll/scroll_enums.mojom-blink.h"
#include "third_party/blink/renderer/core/animation/effect_model.h"
#include "third_party/blink/renderer/core/animation/timeline_inset.h"
#include "third_party/blink/renderer/core/css/style_auto_color.h"
#include "third_party/blink/renderer/core/css/style_caret_color.h"
#include "third_party/blink/renderer/core/css/style_color.h"
#include "third_party/blink/renderer/core/css/white_space.h"
#include "third_party/blink/renderer/core/css_value_keywords.h"
#include "third_party/blink/renderer/core/keywords.h"
#include "third_party/blink/renderer/core/layout/grid_lanes/grid_lanes_direction.h"
#include "third_party/blink/renderer/core/layout/layout_theme.h"
#include "third_party/blink/renderer/core/style/basic_shapes.h"
#include "third_party/blink/renderer/core/style/clip_path_operation.h"
#include "third_party/blink/renderer/core/style/computed_grid_template_areas.h"
#include "third_party/blink/renderer/core/style/computed_grid_track_list.h"
#include "third_party/blink/renderer/core/style/content_data.h"
#include "third_party/blink/renderer/core/style/filter_operations.h"
#include "third_party/blink/renderer/core/style/flow_tolerance.h"
#include "third_party/blink/renderer/core/style/gap_data_list.h"
#include "third_party/blink/renderer/core/style/grid_position.h"
#include "third_party/blink/renderer/core/style/grid_track_list.h"
#include "third_party/blink/renderer/core/style/list_style_type_data.h"
#include "third_party/blink/renderer/core/style/offset_path_operation.h"
#include "third_party/blink/renderer/core/style/position_area.h"
#include "third_party/blink/renderer/core/style/position_try_fallbacks.h"
#include "third_party/blink/renderer/core/style/scoped_css_name.h"
#include "third_party/blink/renderer/core/style/scroll_marker_group.h"
#include "third_party/blink/renderer/core/style/shadow_list.h"
#include "third_party/blink/renderer/core/style/shape_value.h"
#include "third_party/blink/renderer/core/style/style_anchor_scope.h"
#include "third_party/blink/renderer/core/style/style_aspect_ratio.h"
#include "third_party/blink/renderer/core/style/style_border_shape.h"
#include "third_party/blink/renderer/core/style/style_content_alignment_data.h"
#include "third_party/blink/renderer/core/style/style_flex_wrap_data.h"
#include "third_party/blink/renderer/core/style/style_hyphenate_limit_chars.h"
#include "third_party/blink/renderer/core/style/style_image.h"
#include "third_party/blink/renderer/core/style/style_initial_letter.h"
#include "third_party/blink/renderer/core/style/style_interest_delay.h"
#include "third_party/blink/renderer/core/style/style_intrinsic_length.h"
#include "third_party/blink/renderer/core/style/style_offset_rotation.h"
#include "third_party/blink/renderer/core/style/style_overflow_clip_margin.h"
#include "third_party/blink/renderer/core/style/style_path.h"
#include "third_party/blink/renderer/core/style/style_position_anchor.h"
#include "third_party/blink/renderer/core/style/style_reflection.h"
#include "third_party/blink/renderer/core/style/style_scrollbar_color.h"
#include "third_party/blink/renderer/core/style/style_self_alignment_data.h"
#include "third_party/blink/renderer/core/style/style_svg_resource.h"
#include "third_party/blink/renderer/core/style/style_timeline_scope.h"
#include "third_party/blink/renderer/core/style/style_trigger_scope.h"
#include "third_party/blink/renderer/core/style/style_view_transition_group.h"
#include "third_party/blink/renderer/core/style/style_view_transition_name.h"
#include "third_party/blink/renderer/core/style/style_will_change_data.h"
#include "third_party/blink/renderer/core/style/superellipse.h"
#include "third_party/blink/renderer/core/style/svg_dash_array.h"
#include "third_party/blink/renderer/core/style/svg_paint.h"
#include "third_party/blink/renderer/core/style/text_box_edge.h"
#include "third_party/blink/renderer/core/style/text_decoration_inset.h"
#include "third_party/blink/renderer/core/style/text_decoration_skip_spaces.h"
#include "third_party/blink/renderer/core/style/text_decoration_thickness.h"
#include "third_party/blink/renderer/core/style/text_fit.h"
#include "third_party/blink/renderer/core/style/text_overflow_data.h"
#include "third_party/blink/renderer/core/style/text_size_adjust.h"
#include "third_party/blink/renderer/core/style/transform_origin.h"
#include "third_party/blink/renderer/core/style/unzoomed_length.h"
#include "third_party/blink/renderer/platform/fonts/shaping/text_spacing_trim.h"
#include "third_party/blink/renderer/platform/geometry/length.h"
#include "third_party/blink/renderer/platform/geometry/length_box.h"
#include "third_party/blink/renderer/platform/geometry/length_point.h"
#include "third_party/blink/renderer/platform/geometry/length_size.h"
#include "third_party/blink/renderer/platform/geometry/path_types.h"
#include "third_party/blink/renderer/platform/graphics/blend_mode.h"
#include "third_party/blink/renderer/platform/graphics/graphics_context_types.h"
#include "third_party/blink/renderer/platform/graphics/image_node_animation_info.h"
#include "third_party/blink/renderer/platform/graphics/image_orientation.h"
#include "third_party/blink/renderer/platform/graphics/touch_action.h"
#include "third_party/blink/renderer/platform/text/hanging_punctuation.h"
#include "third_party/blink/renderer/platform/text/quotes_data.h"
#include "third_party/blink/renderer/platform/text/tab_size.h"
#include "third_party/blink/renderer/platform/text/text_direction.h"
#include "third_party/blink/renderer/platform/text/text_justify.h"
#include "third_party/blink/renderer/platform/text/unicode_bidi.h"
#include "third_party/blink/renderer/platform/text/writing_mode.h"
#include "third_party/blink/renderer/platform/theme_types.h"
#include "third_party/blink/renderer/platform/transforms/rotate_transform_operation.h"
#include "third_party/blink/renderer/platform/transforms/scale_transform_operation.h"
#include "third_party/blink/renderer/platform/transforms/transform_operations.h"
#include "third_party/blink/renderer/platform/transforms/translate_transform_operation.h"
#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"

namespace blink {

// Do not use these functions directly, use the non-generated versions
// in CSSValueMappings.h

namespace detail {

template <class T>
T cssValueIDToPlatformEnumGenerated(CSSValueID);


template <>
inline EForcedColorAdjust cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EForcedColorAdjust::kAuto;
    case CSSValueID::kPreserveParentColor:
      return EForcedColorAdjust::kPreserveParentColor;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EForcedColorAdjust>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EForcedColorAdjust::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EForcedColorAdjust v) {
  switch (v) {
    case EForcedColorAdjust::kAuto:
      return CSSValueID::kAuto;
    case EForcedColorAdjust::kPreserveParentColor:
      return CSSValueID::kPreserveParentColor;
    default:
      DCHECK_GE(v, EForcedColorAdjust::kNone);
      DCHECK_LE(v, EForcedColorAdjust::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EForcedColorAdjust::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EPosition cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kFixed:
      return EPosition::kFixed;
    case CSSValueID::kRelative:
      return EPosition::kRelative;
    case CSSValueID::kStatic:
      return EPosition::kStatic;
    case CSSValueID::kSticky:
      return EPosition::kSticky;
    default:
      DCHECK_GE(v, CSSValueID::kAbsolute);
      DCHECK_LE(v, CSSValueID::kAbsolute);
      return static_cast<EPosition>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAbsolute) + static_cast<int>(EPosition::kAbsolute));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EPosition v) {
  switch (v) {
    case EPosition::kFixed:
      return CSSValueID::kFixed;
    case EPosition::kRelative:
      return CSSValueID::kRelative;
    case EPosition::kStatic:
      return CSSValueID::kStatic;
    case EPosition::kSticky:
      return CSSValueID::kSticky;
    default:
      DCHECK_GE(v, EPosition::kAbsolute);
      DCHECK_LE(v, EPosition::kAbsolute);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EPosition::kAbsolute) + static_cast<int>(CSSValueID::kAbsolute));
  }
}


template <>
inline TextDirection cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kLtr);
  DCHECK_LE(v, CSSValueID::kRtl);
  return static_cast<TextDirection>(static_cast<int>(v) - static_cast<int>(CSSValueID::kLtr) + static_cast<int>(TextDirection::kLtr));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(TextDirection v) {
  DCHECK_GE(v, TextDirection::kLtr);
  DCHECK_LE(v, TextDirection::kRtl);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(TextDirection::kLtr) + static_cast<int>(CSSValueID::kLtr));
}


template <>
inline ETextOrientation cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kMixed);
  DCHECK_LE(v, CSSValueID::kUpright);
  return static_cast<ETextOrientation>(static_cast<int>(v) - static_cast<int>(CSSValueID::kMixed) + static_cast<int>(ETextOrientation::kMixed));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ETextOrientation v) {
  DCHECK_GE(v, ETextOrientation::kMixed);
  DCHECK_LE(v, ETextOrientation::kUpright);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ETextOrientation::kMixed) + static_cast<int>(CSSValueID::kMixed));
}


template <>
inline WritingMode cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kHorizontalTb);
  DCHECK_LE(v, CSSValueID::kSidewaysLr);
  return static_cast<WritingMode>(static_cast<int>(v) - static_cast<int>(CSSValueID::kHorizontalTb) + static_cast<int>(WritingMode::kHorizontalTb));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(WritingMode v) {
  DCHECK_GE(v, WritingMode::kHorizontalTb);
  DCHECK_LE(v, WritingMode::kSidewaysLr);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(WritingMode::kHorizontalTb) + static_cast<int>(CSSValueID::kHorizontalTb));
}


template <>
inline EAlignmentBaseline cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kBaseline:
      return EAlignmentBaseline::kBaseline;
    case CSSValueID::kMiddle:
      return EAlignmentBaseline::kMiddle;
    case CSSValueID::kAuto:
      return EAlignmentBaseline::kAuto;
    case CSSValueID::kAlphabetic:
      return EAlignmentBaseline::kAlphabetic;
    default:
      DCHECK_GE(v, CSSValueID::kBeforeEdge);
      DCHECK_LE(v, CSSValueID::kMathematical);
      return static_cast<EAlignmentBaseline>(static_cast<int>(v) - static_cast<int>(CSSValueID::kBeforeEdge) + static_cast<int>(EAlignmentBaseline::kBeforeEdge));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EAlignmentBaseline v) {
  switch (v) {
    case EAlignmentBaseline::kBaseline:
      return CSSValueID::kBaseline;
    case EAlignmentBaseline::kMiddle:
      return CSSValueID::kMiddle;
    case EAlignmentBaseline::kAuto:
      return CSSValueID::kAuto;
    case EAlignmentBaseline::kAlphabetic:
      return CSSValueID::kAlphabetic;
    default:
      DCHECK_GE(v, EAlignmentBaseline::kBeforeEdge);
      DCHECK_LE(v, EAlignmentBaseline::kMathematical);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EAlignmentBaseline::kBeforeEdge) + static_cast<int>(CSSValueID::kBeforeEdge));
  }
}


template <>
inline EBackfaceVisibility cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kVisible:
      return EBackfaceVisibility::kVisible;
    default:
      DCHECK_GE(v, CSSValueID::kHidden);
      DCHECK_LE(v, CSSValueID::kHidden);
      return static_cast<EBackfaceVisibility>(static_cast<int>(v) - static_cast<int>(CSSValueID::kHidden) + static_cast<int>(EBackfaceVisibility::kHidden));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EBackfaceVisibility v) {
  switch (v) {
    case EBackfaceVisibility::kVisible:
      return CSSValueID::kVisible;
    default:
      DCHECK_GE(v, EBackfaceVisibility::kHidden);
      DCHECK_LE(v, EBackfaceVisibility::kHidden);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EBackfaceVisibility::kHidden) + static_cast<int>(CSSValueID::kHidden));
  }
}


template <>
inline EBaselineSource cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EBaselineSource::kAuto;
    default:
      DCHECK_GE(v, CSSValueID::kFirst);
      DCHECK_LE(v, CSSValueID::kLast);
      return static_cast<EBaselineSource>(static_cast<int>(v) - static_cast<int>(CSSValueID::kFirst) + static_cast<int>(EBaselineSource::kFirst));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EBaselineSource v) {
  switch (v) {
    case EBaselineSource::kAuto:
      return CSSValueID::kAuto;
    default:
      DCHECK_GE(v, EBaselineSource::kFirst);
      DCHECK_LE(v, EBaselineSource::kLast);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EBaselineSource::kFirst) + static_cast<int>(CSSValueID::kFirst));
  }
}


template <>
inline EBlockEllipsis cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNoEllipsis:
      return EBlockEllipsis::kNoEllipsis;
    default:
      DCHECK_GE(v, CSSValueID::kEllipsis);
      DCHECK_LE(v, CSSValueID::kEllipsis);
      return static_cast<EBlockEllipsis>(static_cast<int>(v) - static_cast<int>(CSSValueID::kEllipsis) + static_cast<int>(EBlockEllipsis::kEllipsis));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EBlockEllipsis v) {
  switch (v) {
    case EBlockEllipsis::kNoEllipsis:
      return CSSValueID::kNoEllipsis;
    default:
      DCHECK_GE(v, EBlockEllipsis::kEllipsis);
      DCHECK_LE(v, EBlockEllipsis::kEllipsis);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EBlockEllipsis::kEllipsis) + static_cast<int>(CSSValueID::kEllipsis));
  }
}


template <>
inline EBorderStyle cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kNone);
  DCHECK_LE(v, CSSValueID::kDouble);
  return static_cast<EBorderStyle>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EBorderStyle::kNone));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EBorderStyle v) {
  DCHECK_GE(v, EBorderStyle::kNone);
  DCHECK_LE(v, EBorderStyle::kDouble);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EBorderStyle::kNone) + static_cast<int>(CSSValueID::kNone));
}


template <>
inline EBorderCollapse cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kSeparate:
      return EBorderCollapse::kSeparate;
    default:
      DCHECK_GE(v, CSSValueID::kCollapse);
      DCHECK_LE(v, CSSValueID::kCollapse);
      return static_cast<EBorderCollapse>(static_cast<int>(v) - static_cast<int>(CSSValueID::kCollapse) + static_cast<int>(EBorderCollapse::kCollapse));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EBorderCollapse v) {
  switch (v) {
    case EBorderCollapse::kSeparate:
      return CSSValueID::kSeparate;
    default:
      DCHECK_GE(v, EBorderCollapse::kCollapse);
      DCHECK_LE(v, EBorderCollapse::kCollapse);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EBorderCollapse::kCollapse) + static_cast<int>(CSSValueID::kCollapse));
  }
}


template <>
inline EBoxDecorationBreak cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kClone);
  DCHECK_LE(v, CSSValueID::kSlice);
  return static_cast<EBoxDecorationBreak>(static_cast<int>(v) - static_cast<int>(CSSValueID::kClone) + static_cast<int>(EBoxDecorationBreak::kClone));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EBoxDecorationBreak v) {
  DCHECK_GE(v, EBoxDecorationBreak::kClone);
  DCHECK_LE(v, EBoxDecorationBreak::kSlice);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EBoxDecorationBreak::kClone) + static_cast<int>(CSSValueID::kClone));
}


template <>
inline EBoxSizing cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kContentBox:
      return EBoxSizing::kContentBox;
    default:
      DCHECK_GE(v, CSSValueID::kBorderBox);
      DCHECK_LE(v, CSSValueID::kBorderBox);
      return static_cast<EBoxSizing>(static_cast<int>(v) - static_cast<int>(CSSValueID::kBorderBox) + static_cast<int>(EBoxSizing::kBorderBox));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EBoxSizing v) {
  switch (v) {
    case EBoxSizing::kContentBox:
      return CSSValueID::kContentBox;
    default:
      DCHECK_GE(v, EBoxSizing::kBorderBox);
      DCHECK_LE(v, EBoxSizing::kBorderBox);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EBoxSizing::kBorderBox) + static_cast<int>(CSSValueID::kBorderBox));
  }
}


template <>
inline EBreakBetween cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kLeft:
      return EBreakBetween::kLeft;
    case CSSValueID::kRight:
      return EBreakBetween::kRight;
    case CSSValueID::kAuto:
      return EBreakBetween::kAuto;
    case CSSValueID::kAvoid:
      return EBreakBetween::kAvoid;
    case CSSValueID::kColumn:
      return EBreakBetween::kColumn;
    default:
      DCHECK_GE(v, CSSValueID::kAvoidPage);
      DCHECK_LE(v, CSSValueID::kAvoidColumn);
      return static_cast<EBreakBetween>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAvoidPage) + static_cast<int>(EBreakBetween::kAvoidPage));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EBreakBetween v) {
  switch (v) {
    case EBreakBetween::kLeft:
      return CSSValueID::kLeft;
    case EBreakBetween::kRight:
      return CSSValueID::kRight;
    case EBreakBetween::kAuto:
      return CSSValueID::kAuto;
    case EBreakBetween::kAvoid:
      return CSSValueID::kAvoid;
    case EBreakBetween::kColumn:
      return CSSValueID::kColumn;
    default:
      DCHECK_GE(v, EBreakBetween::kAvoidPage);
      DCHECK_LE(v, EBreakBetween::kAvoidColumn);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EBreakBetween::kAvoidPage) + static_cast<int>(CSSValueID::kAvoidPage));
  }
}


template <>
inline EBreakInside cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAvoid:
      return EBreakInside::kAvoid;
    case CSSValueID::kAvoidPage:
      return EBreakInside::kAvoidPage;
    case CSSValueID::kAvoidColumn:
      return EBreakInside::kAvoidColumn;
    default:
      DCHECK_GE(v, CSSValueID::kAuto);
      DCHECK_LE(v, CSSValueID::kAuto);
      return static_cast<EBreakInside>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAuto) + static_cast<int>(EBreakInside::kAuto));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EBreakInside v) {
  switch (v) {
    case EBreakInside::kAvoid:
      return CSSValueID::kAvoid;
    case EBreakInside::kAvoidPage:
      return CSSValueID::kAvoidPage;
    case EBreakInside::kAvoidColumn:
      return CSSValueID::kAvoidColumn;
    default:
      DCHECK_GE(v, EBreakInside::kAuto);
      DCHECK_LE(v, EBreakInside::kAuto);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EBreakInside::kAuto) + static_cast<int>(CSSValueID::kAuto));
  }
}


template <>
inline EBufferedRendering cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kStatic:
      return EBufferedRendering::kStatic;
    case CSSValueID::kDynamic:
      return EBufferedRendering::kDynamic;
    default:
      DCHECK_GE(v, CSSValueID::kAuto);
      DCHECK_LE(v, CSSValueID::kAuto);
      return static_cast<EBufferedRendering>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAuto) + static_cast<int>(EBufferedRendering::kAuto));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EBufferedRendering v) {
  switch (v) {
    case EBufferedRendering::kStatic:
      return CSSValueID::kStatic;
    case EBufferedRendering::kDynamic:
      return CSSValueID::kDynamic;
    default:
      DCHECK_GE(v, EBufferedRendering::kAuto);
      DCHECK_LE(v, EBufferedRendering::kAuto);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EBufferedRendering::kAuto) + static_cast<int>(CSSValueID::kAuto));
  }
}


template <>
inline ECaptionSide cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kTop);
  DCHECK_LE(v, CSSValueID::kBottom);
  return static_cast<ECaptionSide>(static_cast<int>(v) - static_cast<int>(CSSValueID::kTop) + static_cast<int>(ECaptionSide::kTop));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ECaptionSide v) {
  DCHECK_GE(v, ECaptionSide::kTop);
  DCHECK_LE(v, ECaptionSide::kBottom);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ECaptionSide::kTop) + static_cast<int>(CSSValueID::kTop));
}


template <>
inline ECaretAnimation cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kManual:
      return ECaretAnimation::kManual;
    default:
      DCHECK_GE(v, CSSValueID::kAuto);
      DCHECK_LE(v, CSSValueID::kAuto);
      return static_cast<ECaretAnimation>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAuto) + static_cast<int>(ECaretAnimation::kAuto));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ECaretAnimation v) {
  switch (v) {
    case ECaretAnimation::kManual:
      return CSSValueID::kManual;
    default:
      DCHECK_GE(v, ECaretAnimation::kAuto);
      DCHECK_LE(v, ECaretAnimation::kAuto);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ECaretAnimation::kAuto) + static_cast<int>(CSSValueID::kAuto));
  }
}


template <>
inline ECaretShape cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kBlock:
      return ECaretShape::kBlock;
    case CSSValueID::kAuto:
      return ECaretShape::kAuto;
    default:
      DCHECK_GE(v, CSSValueID::kBar);
      DCHECK_LE(v, CSSValueID::kUnderscore);
      return static_cast<ECaretShape>(static_cast<int>(v) - static_cast<int>(CSSValueID::kBar) + static_cast<int>(ECaretShape::kBar));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ECaretShape v) {
  switch (v) {
    case ECaretShape::kBlock:
      return CSSValueID::kBlock;
    case ECaretShape::kAuto:
      return CSSValueID::kAuto;
    default:
      DCHECK_GE(v, ECaretShape::kBar);
      DCHECK_LE(v, ECaretShape::kUnderscore);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ECaretShape::kBar) + static_cast<int>(CSSValueID::kBar));
  }
}


template <>
inline EClear cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNone:
      return EClear::kNone;
    case CSSValueID::kInlineStart:
      return EClear::kInlineStart;
    case CSSValueID::kInlineEnd:
      return EClear::kInlineEnd;
    case CSSValueID::kBoth:
      return EClear::kBoth;
    default:
      DCHECK_GE(v, CSSValueID::kLeft);
      DCHECK_LE(v, CSSValueID::kRight);
      return static_cast<EClear>(static_cast<int>(v) - static_cast<int>(CSSValueID::kLeft) + static_cast<int>(EClear::kLeft));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EClear v) {
  switch (v) {
    case EClear::kNone:
      return CSSValueID::kNone;
    case EClear::kInlineStart:
      return CSSValueID::kInlineStart;
    case EClear::kInlineEnd:
      return CSSValueID::kInlineEnd;
    case EClear::kBoth:
      return CSSValueID::kBoth;
    default:
      DCHECK_GE(v, EClear::kLeft);
      DCHECK_LE(v, EClear::kRight);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EClear::kLeft) + static_cast<int>(CSSValueID::kLeft));
  }
}


template <>
inline EColorInterpolation cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EColorInterpolation::kAuto;
    default:
      DCHECK_GE(v, CSSValueID::kSRGB);
      DCHECK_LE(v, CSSValueID::kLinearrgb);
      return static_cast<EColorInterpolation>(static_cast<int>(v) - static_cast<int>(CSSValueID::kSRGB) + static_cast<int>(EColorInterpolation::kSRGB));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EColorInterpolation v) {
  switch (v) {
    case EColorInterpolation::kAuto:
      return CSSValueID::kAuto;
    default:
      DCHECK_GE(v, EColorInterpolation::kSRGB);
      DCHECK_LE(v, EColorInterpolation::kLinearrgb);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EColorInterpolation::kSRGB) + static_cast<int>(CSSValueID::kSRGB));
  }
}


template <>
inline EColorRendering cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kOptimizespeed:
      return EColorRendering::kOptimizespeed;
    case CSSValueID::kOptimizequality:
      return EColorRendering::kOptimizequality;
    default:
      DCHECK_GE(v, CSSValueID::kAuto);
      DCHECK_LE(v, CSSValueID::kAuto);
      return static_cast<EColorRendering>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAuto) + static_cast<int>(EColorRendering::kAuto));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EColorRendering v) {
  switch (v) {
    case EColorRendering::kOptimizespeed:
      return CSSValueID::kOptimizespeed;
    case EColorRendering::kOptimizequality:
      return CSSValueID::kOptimizequality;
    default:
      DCHECK_GE(v, EColorRendering::kAuto);
      DCHECK_LE(v, EColorRendering::kAuto);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EColorRendering::kAuto) + static_cast<int>(CSSValueID::kAuto));
  }
}


template <>
inline EColumnFill cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kBalance:
      return EColumnFill::kBalance;
    default:
      DCHECK_GE(v, CSSValueID::kAuto);
      DCHECK_LE(v, CSSValueID::kAuto);
      return static_cast<EColumnFill>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAuto) + static_cast<int>(EColumnFill::kAuto));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EColumnFill v) {
  switch (v) {
    case EColumnFill::kBalance:
      return CSSValueID::kBalance;
    default:
      DCHECK_GE(v, EColumnFill::kAuto);
      DCHECK_LE(v, EColumnFill::kAuto);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EColumnFill::kAuto) + static_cast<int>(CSSValueID::kAuto));
  }
}


template <>
inline RuleBreak cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNormal:
      return RuleBreak::kNormal;
    case CSSValueID::kIntersection:
      return RuleBreak::kIntersection;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<RuleBreak>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(RuleBreak::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(RuleBreak v) {
  switch (v) {
    case RuleBreak::kNormal:
      return CSSValueID::kNormal;
    case RuleBreak::kIntersection:
      return CSSValueID::kIntersection;
    default:
      DCHECK_GE(v, RuleBreak::kNone);
      DCHECK_LE(v, RuleBreak::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(RuleBreak::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline RuleVisibilityItems cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAll:
      return RuleVisibilityItems::kAll;
    case CSSValueID::kNormal:
      return RuleVisibilityItems::kNormal;
    default:
      DCHECK_GE(v, CSSValueID::kAround);
      DCHECK_LE(v, CSSValueID::kBetween);
      return static_cast<RuleVisibilityItems>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAround) + static_cast<int>(RuleVisibilityItems::kAround));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(RuleVisibilityItems v) {
  switch (v) {
    case RuleVisibilityItems::kAll:
      return CSSValueID::kAll;
    case RuleVisibilityItems::kNormal:
      return CSSValueID::kNormal;
    default:
      DCHECK_GE(v, RuleVisibilityItems::kAround);
      DCHECK_LE(v, RuleVisibilityItems::kBetween);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(RuleVisibilityItems::kAround) + static_cast<int>(CSSValueID::kAround));
  }
}


template <>
inline EColumnSpan cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAll:
      return EColumnSpan::kAll;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EColumnSpan>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EColumnSpan::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EColumnSpan v) {
  switch (v) {
    case EColumnSpan::kAll:
      return CSSValueID::kAll;
    default:
      DCHECK_GE(v, EColumnSpan::kNone);
      DCHECK_LE(v, EColumnSpan::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EColumnSpan::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EColumnWrap cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNowrap:
      return EColumnWrap::kNowrap;
    case CSSValueID::kWrap:
      return EColumnWrap::kWrap;
    default:
      DCHECK_GE(v, CSSValueID::kAuto);
      DCHECK_LE(v, CSSValueID::kAuto);
      return static_cast<EColumnWrap>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAuto) + static_cast<int>(EColumnWrap::kAuto));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EColumnWrap v) {
  switch (v) {
    case EColumnWrap::kNowrap:
      return CSSValueID::kNowrap;
    case EColumnWrap::kWrap:
      return CSSValueID::kWrap;
    default:
      DCHECK_GE(v, EColumnWrap::kAuto);
      DCHECK_LE(v, EColumnWrap::kAuto);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EColumnWrap::kAuto) + static_cast<int>(CSSValueID::kAuto));
  }
}


template <>
inline EContentVisibility cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EContentVisibility::kAuto;
    case CSSValueID::kVisible:
      return EContentVisibility::kVisible;
    default:
      DCHECK_GE(v, CSSValueID::kHidden);
      DCHECK_LE(v, CSSValueID::kHidden);
      return static_cast<EContentVisibility>(static_cast<int>(v) - static_cast<int>(CSSValueID::kHidden) + static_cast<int>(EContentVisibility::kHidden));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EContentVisibility v) {
  switch (v) {
    case EContentVisibility::kAuto:
      return CSSValueID::kAuto;
    case EContentVisibility::kVisible:
      return CSSValueID::kVisible;
    default:
      DCHECK_GE(v, EContentVisibility::kHidden);
      DCHECK_LE(v, EContentVisibility::kHidden);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EContentVisibility::kHidden) + static_cast<int>(CSSValueID::kHidden));
  }
}


template <>
inline ECursor cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNone:
      return ECursor::kNone;
    case CSSValueID::kCopy:
      return ECursor::kCopy;
    default:
      DCHECK_GE(v, CSSValueID::kAuto);
      DCHECK_LE(v, CSSValueID::kGrabbing);
      return static_cast<ECursor>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAuto) + static_cast<int>(ECursor::kAuto));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ECursor v) {
  switch (v) {
    case ECursor::kNone:
      return CSSValueID::kNone;
    case ECursor::kCopy:
      return CSSValueID::kCopy;
    default:
      DCHECK_GE(v, ECursor::kAuto);
      DCHECK_LE(v, ECursor::kGrabbing);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ECursor::kAuto) + static_cast<int>(CSSValueID::kAuto));
  }
}


template <>
inline EDominantBaseline cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kMiddle:
      return EDominantBaseline::kMiddle;
    case CSSValueID::kAuto:
      return EDominantBaseline::kAuto;
    case CSSValueID::kAlphabetic:
      return EDominantBaseline::kAlphabetic;
    case CSSValueID::kUseScript:
      return EDominantBaseline::kUseScript;
    case CSSValueID::kNoChange:
      return EDominantBaseline::kNoChange;
    case CSSValueID::kResetSize:
      return EDominantBaseline::kResetSize;
    default:
      DCHECK_GE(v, CSSValueID::kCentral);
      DCHECK_LE(v, CSSValueID::kMathematical);
      return static_cast<EDominantBaseline>(static_cast<int>(v) - static_cast<int>(CSSValueID::kCentral) + static_cast<int>(EDominantBaseline::kCentral));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EDominantBaseline v) {
  switch (v) {
    case EDominantBaseline::kMiddle:
      return CSSValueID::kMiddle;
    case EDominantBaseline::kAuto:
      return CSSValueID::kAuto;
    case EDominantBaseline::kAlphabetic:
      return CSSValueID::kAlphabetic;
    case EDominantBaseline::kUseScript:
      return CSSValueID::kUseScript;
    case EDominantBaseline::kNoChange:
      return CSSValueID::kNoChange;
    case EDominantBaseline::kResetSize:
      return CSSValueID::kResetSize;
    default:
      DCHECK_GE(v, EDominantBaseline::kCentral);
      DCHECK_LE(v, EDominantBaseline::kMathematical);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EDominantBaseline::kCentral) + static_cast<int>(CSSValueID::kCentral));
  }
}


template <>
inline EEmptyCells cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kShow:
      return EEmptyCells::kShow;
    default:
      DCHECK_GE(v, CSSValueID::kHide);
      DCHECK_LE(v, CSSValueID::kHide);
      return static_cast<EEmptyCells>(static_cast<int>(v) - static_cast<int>(CSSValueID::kHide) + static_cast<int>(EEmptyCells::kHide));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EEmptyCells v) {
  switch (v) {
    case EEmptyCells::kShow:
      return CSSValueID::kShow;
    default:
      DCHECK_GE(v, EEmptyCells::kHide);
      DCHECK_LE(v, EEmptyCells::kHide);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EEmptyCells::kHide) + static_cast<int>(CSSValueID::kHide));
  }
}


template <>
inline EFieldSizing cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kContent:
      return EFieldSizing::kContent;
    default:
      DCHECK_GE(v, CSSValueID::kFixed);
      DCHECK_LE(v, CSSValueID::kFixed);
      return static_cast<EFieldSizing>(static_cast<int>(v) - static_cast<int>(CSSValueID::kFixed) + static_cast<int>(EFieldSizing::kFixed));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EFieldSizing v) {
  switch (v) {
    case EFieldSizing::kContent:
      return CSSValueID::kContent;
    default:
      DCHECK_GE(v, EFieldSizing::kFixed);
      DCHECK_LE(v, EFieldSizing::kFixed);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EFieldSizing::kFixed) + static_cast<int>(CSSValueID::kFixed));
  }
}


template <>
inline EFlexDirection cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kRow);
  DCHECK_LE(v, CSSValueID::kColumnReverse);
  return static_cast<EFlexDirection>(static_cast<int>(v) - static_cast<int>(CSSValueID::kRow) + static_cast<int>(EFlexDirection::kRow));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EFlexDirection v) {
  DCHECK_GE(v, EFlexDirection::kRow);
  DCHECK_LE(v, EFlexDirection::kColumnReverse);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EFlexDirection::kRow) + static_cast<int>(CSSValueID::kRow));
}


template <>
inline EFloat cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNone:
      return EFloat::kNone;
    case CSSValueID::kInlineStart:
      return EFloat::kInlineStart;
    case CSSValueID::kInlineEnd:
      return EFloat::kInlineEnd;
    default:
      DCHECK_GE(v, CSSValueID::kLeft);
      DCHECK_LE(v, CSSValueID::kRight);
      return static_cast<EFloat>(static_cast<int>(v) - static_cast<int>(CSSValueID::kLeft) + static_cast<int>(EFloat::kLeft));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EFloat v) {
  switch (v) {
    case EFloat::kNone:
      return CSSValueID::kNone;
    case EFloat::kInlineStart:
      return CSSValueID::kInlineStart;
    case EFloat::kInlineEnd:
      return CSSValueID::kInlineEnd;
    default:
      DCHECK_GE(v, EFloat::kLeft);
      DCHECK_LE(v, EFloat::kRight);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EFloat::kLeft) + static_cast<int>(CSSValueID::kLeft));
  }
}


template <>
inline EFrameSizing cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EFrameSizing::kAuto;
    default:
      DCHECK_GE(v, CSSValueID::kContentWidth);
      DCHECK_LE(v, CSSValueID::kContentInlineSize);
      return static_cast<EFrameSizing>(static_cast<int>(v) - static_cast<int>(CSSValueID::kContentWidth) + static_cast<int>(EFrameSizing::kContentWidth));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EFrameSizing v) {
  switch (v) {
    case EFrameSizing::kAuto:
      return CSSValueID::kAuto;
    default:
      DCHECK_GE(v, EFrameSizing::kContentWidth);
      DCHECK_LE(v, EFrameSizing::kContentInlineSize);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EFrameSizing::kContentWidth) + static_cast<int>(CSSValueID::kContentWidth));
  }
}


template <>
inline EGridLanesPack cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kDense:
      return EGridLanesPack::kDense;
    default:
      DCHECK_GE(v, CSSValueID::kNormal);
      DCHECK_LE(v, CSSValueID::kNormal);
      return static_cast<EGridLanesPack>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNormal) + static_cast<int>(EGridLanesPack::kNormal));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EGridLanesPack v) {
  switch (v) {
    case EGridLanesPack::kDense:
      return CSSValueID::kDense;
    default:
      DCHECK_GE(v, EGridLanesPack::kNormal);
      DCHECK_LE(v, EGridLanesPack::kNormal);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EGridLanesPack::kNormal) + static_cast<int>(CSSValueID::kNormal));
  }
}

template <>
inline HangingPunctuation cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNone:
      return HangingPunctuation::kNone;
    case CSSValueID::kFirst:
      return HangingPunctuation::kFirst;
    case CSSValueID::kLast:
      return HangingPunctuation::kLast;
    case CSSValueID::kAllowEnd:
      return HangingPunctuation::kAllowEnd;
    default:
      NOTREACHED();
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(HangingPunctuation v) {
  switch (v) {
    case HangingPunctuation::kNone:
      return CSSValueID::kNone;
    case HangingPunctuation::kFirst:
      return CSSValueID::kFirst;
    case HangingPunctuation::kLast:
      return CSSValueID::kLast;
    case HangingPunctuation::kAllowEnd:
      return CSSValueID::kAllowEnd;
    default:
      NOTREACHED();
  }
}

template <>
inline Hyphens cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return Hyphens::kAuto;
    case CSSValueID::kManual:
      return Hyphens::kManual;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<Hyphens>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(Hyphens::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(Hyphens v) {
  switch (v) {
    case Hyphens::kAuto:
      return CSSValueID::kAuto;
    case Hyphens::kManual:
      return CSSValueID::kManual;
    default:
      DCHECK_GE(v, Hyphens::kNone);
      DCHECK_LE(v, Hyphens::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(Hyphens::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline ImageAnimationEnum cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNormal:
      return ImageAnimationEnum::kNormal;
    default:
      DCHECK_GE(v, CSSValueID::kRunning);
      DCHECK_LE(v, CSSValueID::kStopped);
      return static_cast<ImageAnimationEnum>(static_cast<int>(v) - static_cast<int>(CSSValueID::kRunning) + static_cast<int>(ImageAnimationEnum::kRunning));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ImageAnimationEnum v) {
  switch (v) {
    case ImageAnimationEnum::kNormal:
      return CSSValueID::kNormal;
    default:
      DCHECK_GE(v, ImageAnimationEnum::kRunning);
      DCHECK_LE(v, ImageAnimationEnum::kStopped);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ImageAnimationEnum::kRunning) + static_cast<int>(CSSValueID::kRunning));
  }
}


template <>
inline EImageRendering cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EImageRendering::kAuto;
    default:
      DCHECK_GE(v, CSSValueID::kPixelated);
      DCHECK_LE(v, CSSValueID::kWebkitOptimizeContrast);
      return static_cast<EImageRendering>(static_cast<int>(v) - static_cast<int>(CSSValueID::kPixelated) + static_cast<int>(EImageRendering::kPixelated));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EImageRendering v) {
  switch (v) {
    case EImageRendering::kAuto:
      return CSSValueID::kAuto;
    default:
      DCHECK_GE(v, EImageRendering::kPixelated);
      DCHECK_LE(v, EImageRendering::kWebkitOptimizeContrast);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EImageRendering::kPixelated) + static_cast<int>(CSSValueID::kPixelated));
  }
}


template <>
inline EInteractivity cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kInert:
      return EInteractivity::kInert;
    default:
      DCHECK_GE(v, CSSValueID::kAuto);
      DCHECK_LE(v, CSSValueID::kAuto);
      return static_cast<EInteractivity>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAuto) + static_cast<int>(EInteractivity::kAuto));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EInteractivity v) {
  switch (v) {
    case EInteractivity::kInert:
      return CSSValueID::kInert;
    default:
      DCHECK_GE(v, EInteractivity::kAuto);
      DCHECK_LE(v, EInteractivity::kAuto);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EInteractivity::kAuto) + static_cast<int>(CSSValueID::kAuto));
  }
}


template <>
inline EInternalOverscrollContainer cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EInternalOverscrollContainer::kAuto;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EInternalOverscrollContainer>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EInternalOverscrollContainer::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EInternalOverscrollContainer v) {
  switch (v) {
    case EInternalOverscrollContainer::kAuto:
      return CSSValueID::kAuto;
    default:
      DCHECK_GE(v, EInternalOverscrollContainer::kNone);
      DCHECK_LE(v, EInternalOverscrollContainer::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EInternalOverscrollContainer::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EInternalOverscrollPosition cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EInternalOverscrollPosition::kAuto;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EInternalOverscrollPosition>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EInternalOverscrollPosition::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EInternalOverscrollPosition v) {
  switch (v) {
    case EInternalOverscrollPosition::kAuto:
      return CSSValueID::kAuto;
    default:
      DCHECK_GE(v, EInternalOverscrollPosition::kNone);
      DCHECK_LE(v, EInternalOverscrollPosition::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EInternalOverscrollPosition::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EInternalUnbounded cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kActive:
      return EInternalUnbounded::kActive;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EInternalUnbounded>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EInternalUnbounded::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EInternalUnbounded v) {
  switch (v) {
    case EInternalUnbounded::kActive:
      return CSSValueID::kActive;
    default:
      DCHECK_GE(v, EInternalUnbounded::kNone);
      DCHECK_LE(v, EInternalUnbounded::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EInternalUnbounded::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EInterpolateSize cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kNumericOnly);
  DCHECK_LE(v, CSSValueID::kAllowKeywords);
  return static_cast<EInterpolateSize>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNumericOnly) + static_cast<int>(EInterpolateSize::kNumericOnly));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EInterpolateSize v) {
  DCHECK_GE(v, EInterpolateSize::kNumericOnly);
  DCHECK_LE(v, EInterpolateSize::kAllowKeywords);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EInterpolateSize::kNumericOnly) + static_cast<int>(CSSValueID::kNumericOnly));
}


template <>
inline EIsolation cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kIsolate:
      return EIsolation::kIsolate;
    default:
      DCHECK_GE(v, CSSValueID::kAuto);
      DCHECK_LE(v, CSSValueID::kAuto);
      return static_cast<EIsolation>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAuto) + static_cast<int>(EIsolation::kAuto));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EIsolation v) {
  switch (v) {
    case EIsolation::kIsolate:
      return CSSValueID::kIsolate;
    default:
      DCHECK_GE(v, EIsolation::kAuto);
      DCHECK_LE(v, EIsolation::kAuto);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EIsolation::kAuto) + static_cast<int>(CSSValueID::kAuto));
  }
}


template <>
inline LineBreak cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNormal:
      return LineBreak::kNormal;
    case CSSValueID::kAuto:
      return LineBreak::kAuto;
    default:
      DCHECK_GE(v, CSSValueID::kLoose);
      DCHECK_LE(v, CSSValueID::kAnywhere);
      return static_cast<LineBreak>(static_cast<int>(v) - static_cast<int>(CSSValueID::kLoose) + static_cast<int>(LineBreak::kLoose));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(LineBreak v) {
  switch (v) {
    case LineBreak::kNormal:
      return CSSValueID::kNormal;
    case LineBreak::kAuto:
      return CSSValueID::kAuto;
    default:
      DCHECK_GE(v, LineBreak::kLoose);
      DCHECK_LE(v, LineBreak::kAnywhere);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(LineBreak::kLoose) + static_cast<int>(CSSValueID::kLoose));
  }
}


template <>
inline EListStylePosition cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kOutside);
  DCHECK_LE(v, CSSValueID::kInside);
  return static_cast<EListStylePosition>(static_cast<int>(v) - static_cast<int>(CSSValueID::kOutside) + static_cast<int>(EListStylePosition::kOutside));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EListStylePosition v) {
  DCHECK_GE(v, EListStylePosition::kOutside);
  DCHECK_LE(v, EListStylePosition::kInside);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EListStylePosition::kOutside) + static_cast<int>(CSSValueID::kOutside));
}


template <>
inline EMaskType cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kAlpha);
  DCHECK_LE(v, CSSValueID::kLuminance);
  return static_cast<EMaskType>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAlpha) + static_cast<int>(EMaskType::kAlpha));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EMaskType v) {
  DCHECK_GE(v, EMaskType::kAlpha);
  DCHECK_LE(v, EMaskType::kLuminance);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EMaskType::kAlpha) + static_cast<int>(CSSValueID::kAlpha));
}


template <>
inline EMathShift cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kCompact:
      return EMathShift::kCompact;
    default:
      DCHECK_GE(v, CSSValueID::kNormal);
      DCHECK_LE(v, CSSValueID::kNormal);
      return static_cast<EMathShift>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNormal) + static_cast<int>(EMathShift::kNormal));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EMathShift v) {
  switch (v) {
    case EMathShift::kCompact:
      return CSSValueID::kCompact;
    default:
      DCHECK_GE(v, EMathShift::kNormal);
      DCHECK_LE(v, EMathShift::kNormal);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EMathShift::kNormal) + static_cast<int>(CSSValueID::kNormal));
  }
}


template <>
inline EMathStyle cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kCompact:
      return EMathStyle::kCompact;
    default:
      DCHECK_GE(v, CSSValueID::kNormal);
      DCHECK_LE(v, CSSValueID::kNormal);
      return static_cast<EMathStyle>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNormal) + static_cast<int>(EMathStyle::kNormal));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EMathStyle v) {
  switch (v) {
    case EMathStyle::kCompact:
      return CSSValueID::kCompact;
    default:
      DCHECK_GE(v, EMathStyle::kNormal);
      DCHECK_LE(v, EMathStyle::kNormal);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EMathStyle::kNormal) + static_cast<int>(CSSValueID::kNormal));
  }
}


template <>
inline EMaxContentSizing cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kShrinkToFit:
      return EMaxContentSizing::kShrinkToFit;
    default:
      DCHECK_GE(v, CSSValueID::kAuto);
      DCHECK_LE(v, CSSValueID::kAuto);
      return static_cast<EMaxContentSizing>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAuto) + static_cast<int>(EMaxContentSizing::kAuto));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EMaxContentSizing v) {
  switch (v) {
    case EMaxContentSizing::kShrinkToFit:
      return CSSValueID::kShrinkToFit;
    default:
      DCHECK_GE(v, EMaxContentSizing::kAuto);
      DCHECK_LE(v, EMaxContentSizing::kAuto);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EMaxContentSizing::kAuto) + static_cast<int>(CSSValueID::kAuto));
  }
}


template <>
inline BlendMode cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNormal:
      return BlendMode::kNormal;
    case CSSValueID::kPlusLighter:
      return BlendMode::kPlusLighter;
    case CSSValueID::kOverlay:
      return BlendMode::kOverlay;
    case CSSValueID::kMultiply:
      return BlendMode::kMultiply;
    case CSSValueID::kScreen:
      return BlendMode::kScreen;
    default:
      DCHECK_GE(v, CSSValueID::kDarken);
      DCHECK_LE(v, CSSValueID::kLuminosity);
      return static_cast<BlendMode>(static_cast<int>(v) - static_cast<int>(CSSValueID::kDarken) + static_cast<int>(BlendMode::kDarken));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(BlendMode v) {
  switch (v) {
    case BlendMode::kNormal:
      return CSSValueID::kNormal;
    case BlendMode::kPlusLighter:
      return CSSValueID::kPlusLighter;
    case BlendMode::kOverlay:
      return CSSValueID::kOverlay;
    case BlendMode::kMultiply:
      return CSSValueID::kMultiply;
    case BlendMode::kScreen:
      return CSSValueID::kScreen;
    default:
      DCHECK_GE(v, BlendMode::kDarken);
      DCHECK_LE(v, BlendMode::kLuminosity);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(BlendMode::kDarken) + static_cast<int>(CSSValueID::kDarken));
  }
}


template <>
inline EObjectFit cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNone:
      return EObjectFit::kNone;
    case CSSValueID::kFill:
      return EObjectFit::kFill;
    case CSSValueID::kScaleDown:
      return EObjectFit::kScaleDown;
    default:
      DCHECK_GE(v, CSSValueID::kContain);
      DCHECK_LE(v, CSSValueID::kCover);
      return static_cast<EObjectFit>(static_cast<int>(v) - static_cast<int>(CSSValueID::kContain) + static_cast<int>(EObjectFit::kContain));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EObjectFit v) {
  switch (v) {
    case EObjectFit::kNone:
      return CSSValueID::kNone;
    case EObjectFit::kFill:
      return CSSValueID::kFill;
    case EObjectFit::kScaleDown:
      return CSSValueID::kScaleDown;
    default:
      DCHECK_GE(v, EObjectFit::kContain);
      DCHECK_LE(v, EObjectFit::kCover);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EObjectFit::kContain) + static_cast<int>(CSSValueID::kContain));
  }
}


template <>
inline EOriginTrialTestProperty cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNormal:
      return EOriginTrialTestProperty::kNormal;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EOriginTrialTestProperty>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EOriginTrialTestProperty::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EOriginTrialTestProperty v) {
  switch (v) {
    case EOriginTrialTestProperty::kNormal:
      return CSSValueID::kNormal;
    default:
      DCHECK_GE(v, EOriginTrialTestProperty::kNone);
      DCHECK_LE(v, EOriginTrialTestProperty::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EOriginTrialTestProperty::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EOverflowAnchor cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EOverflowAnchor::kAuto;
    case CSSValueID::kVisible:
      return EOverflowAnchor::kVisible;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EOverflowAnchor>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EOverflowAnchor::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EOverflowAnchor v) {
  switch (v) {
    case EOverflowAnchor::kAuto:
      return CSSValueID::kAuto;
    case EOverflowAnchor::kVisible:
      return CSSValueID::kVisible;
    default:
      DCHECK_GE(v, EOverflowAnchor::kNone);
      DCHECK_LE(v, EOverflowAnchor::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EOverflowAnchor::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EOverflowWrap cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kBreakWord:
      return EOverflowWrap::kBreakWord;
    case CSSValueID::kAnywhere:
      return EOverflowWrap::kAnywhere;
    default:
      DCHECK_GE(v, CSSValueID::kNormal);
      DCHECK_LE(v, CSSValueID::kNormal);
      return static_cast<EOverflowWrap>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNormal) + static_cast<int>(EOverflowWrap::kNormal));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EOverflowWrap v) {
  switch (v) {
    case EOverflowWrap::kBreakWord:
      return CSSValueID::kBreakWord;
    case EOverflowWrap::kAnywhere:
      return CSSValueID::kAnywhere;
    default:
      DCHECK_GE(v, EOverflowWrap::kNormal);
      DCHECK_LE(v, EOverflowWrap::kNormal);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EOverflowWrap::kNormal) + static_cast<int>(CSSValueID::kNormal));
  }
}


template <>
inline EOverflow cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EOverflow::kAuto;
    case CSSValueID::kVisible:
      return EOverflow::kVisible;
    case CSSValueID::kOverlay:
      return EOverflow::kOverlay;
    case CSSValueID::kScroll:
      return EOverflow::kScroll;
    case CSSValueID::kClip:
      return EOverflow::kClip;
    default:
      DCHECK_GE(v, CSSValueID::kHidden);
      DCHECK_LE(v, CSSValueID::kHidden);
      return static_cast<EOverflow>(static_cast<int>(v) - static_cast<int>(CSSValueID::kHidden) + static_cast<int>(EOverflow::kHidden));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EOverflow v) {
  switch (v) {
    case EOverflow::kAuto:
      return CSSValueID::kAuto;
    case EOverflow::kVisible:
      return CSSValueID::kVisible;
    case EOverflow::kOverlay:
      return CSSValueID::kOverlay;
    case EOverflow::kScroll:
      return CSSValueID::kScroll;
    case EOverflow::kClip:
      return CSSValueID::kClip;
    default:
      DCHECK_GE(v, EOverflow::kHidden);
      DCHECK_LE(v, EOverflow::kHidden);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EOverflow::kHidden) + static_cast<int>(CSSValueID::kHidden));
  }
}


template <>
inline EOverlay cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EOverlay::kAuto;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EOverlay>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EOverlay::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EOverlay v) {
  switch (v) {
    case EOverlay::kAuto:
      return CSSValueID::kAuto;
    default:
      DCHECK_GE(v, EOverlay::kNone);
      DCHECK_LE(v, EOverlay::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EOverlay::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EOverscrollBehavior cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EOverscrollBehavior::kAuto;
    case CSSValueID::kContain:
      return EOverscrollBehavior::kContain;
    case CSSValueID::kChain:
      return EOverscrollBehavior::kChain;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EOverscrollBehavior>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EOverscrollBehavior::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EOverscrollBehavior v) {
  switch (v) {
    case EOverscrollBehavior::kAuto:
      return CSSValueID::kAuto;
    case EOverscrollBehavior::kContain:
      return CSSValueID::kContain;
    case EOverscrollBehavior::kChain:
      return CSSValueID::kChain;
    default:
      DCHECK_GE(v, EOverscrollBehavior::kNone);
      DCHECK_LE(v, EOverscrollBehavior::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EOverscrollBehavior::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EOverscrollContainerType cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EOverscrollContainerType::kAuto;
    case CSSValueID::kOverlay:
      return EOverscrollContainerType::kOverlay;
    case CSSValueID::kPush:
      return EOverscrollContainerType::kPush;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EOverscrollContainerType>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EOverscrollContainerType::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EOverscrollContainerType v) {
  switch (v) {
    case EOverscrollContainerType::kAuto:
      return CSSValueID::kAuto;
    case EOverscrollContainerType::kOverlay:
      return CSSValueID::kOverlay;
    case EOverscrollContainerType::kPush:
      return CSSValueID::kPush;
    default:
      DCHECK_GE(v, EOverscrollContainerType::kNone);
      DCHECK_LE(v, EOverscrollContainerType::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EOverscrollContainerType::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EPageMarginSafety cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kClamp:
      return EPageMarginSafety::kClamp;
    case CSSValueID::kAdd:
      return EPageMarginSafety::kAdd;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EPageMarginSafety>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EPageMarginSafety::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EPageMarginSafety v) {
  switch (v) {
    case EPageMarginSafety::kClamp:
      return CSSValueID::kClamp;
    case EPageMarginSafety::kAdd:
      return CSSValueID::kAdd;
    default:
      DCHECK_GE(v, EPageMarginSafety::kNone);
      DCHECK_LE(v, EPageMarginSafety::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EPageMarginSafety::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EPointerEvents cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNone:
      return EPointerEvents::kNone;
    case CSSValueID::kAll:
      return EPointerEvents::kAll;
    case CSSValueID::kAuto:
      return EPointerEvents::kAuto;
    case CSSValueID::kVisible:
      return EPointerEvents::kVisible;
    default:
      DCHECK_GE(v, CSSValueID::kVisiblepainted);
      DCHECK_LE(v, CSSValueID::kBoundingBox);
      return static_cast<EPointerEvents>(static_cast<int>(v) - static_cast<int>(CSSValueID::kVisiblepainted) + static_cast<int>(EPointerEvents::kVisiblepainted));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EPointerEvents v) {
  switch (v) {
    case EPointerEvents::kNone:
      return CSSValueID::kNone;
    case EPointerEvents::kAll:
      return CSSValueID::kAll;
    case EPointerEvents::kAuto:
      return CSSValueID::kAuto;
    case EPointerEvents::kVisible:
      return CSSValueID::kVisible;
    default:
      DCHECK_GE(v, EPointerEvents::kVisiblepainted);
      DCHECK_LE(v, EPointerEvents::kBoundingBox);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EPointerEvents::kVisiblepainted) + static_cast<int>(CSSValueID::kVisiblepainted));
  }
}


template <>
inline EPositionTryOrder cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNormal:
      return EPositionTryOrder::kNormal;
    default:
      DCHECK_GE(v, CSSValueID::kMostWidth);
      DCHECK_LE(v, CSSValueID::kMostInlineSize);
      return static_cast<EPositionTryOrder>(static_cast<int>(v) - static_cast<int>(CSSValueID::kMostWidth) + static_cast<int>(EPositionTryOrder::kMostWidth));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EPositionTryOrder v) {
  switch (v) {
    case EPositionTryOrder::kNormal:
      return CSSValueID::kNormal;
    default:
      DCHECK_GE(v, EPositionTryOrder::kMostWidth);
      DCHECK_LE(v, EPositionTryOrder::kMostInlineSize);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EPositionTryOrder::kMostWidth) + static_cast<int>(CSSValueID::kMostWidth));
  }
}


template <>
inline EPrintColorAdjust cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kEconomy);
  DCHECK_LE(v, CSSValueID::kExact);
  return static_cast<EPrintColorAdjust>(static_cast<int>(v) - static_cast<int>(CSSValueID::kEconomy) + static_cast<int>(EPrintColorAdjust::kEconomy));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EPrintColorAdjust v) {
  DCHECK_GE(v, EPrintColorAdjust::kEconomy);
  DCHECK_LE(v, EPrintColorAdjust::kExact);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EPrintColorAdjust::kEconomy) + static_cast<int>(CSSValueID::kEconomy));
}


template <>
inline EReadingFlow cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNormal:
      return EReadingFlow::kNormal;
    default:
      DCHECK_GE(v, CSSValueID::kFlexVisual);
      DCHECK_LE(v, CSSValueID::kSourceOrder);
      return static_cast<EReadingFlow>(static_cast<int>(v) - static_cast<int>(CSSValueID::kFlexVisual) + static_cast<int>(EReadingFlow::kFlexVisual));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EReadingFlow v) {
  switch (v) {
    case EReadingFlow::kNormal:
      return CSSValueID::kNormal;
    default:
      DCHECK_GE(v, EReadingFlow::kFlexVisual);
      DCHECK_LE(v, EReadingFlow::kSourceOrder);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EReadingFlow::kFlexVisual) + static_cast<int>(CSSValueID::kFlexVisual));
  }
}


template <>
inline EResize cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNone:
      return EResize::kNone;
    case CSSValueID::kBoth:
      return EResize::kBoth;
    case CSSValueID::kHorizontal:
      return EResize::kHorizontal;
    case CSSValueID::kVertical:
      return EResize::kVertical;
    default:
      DCHECK_GE(v, CSSValueID::kInline);
      DCHECK_LE(v, CSSValueID::kBlock);
      return static_cast<EResize>(static_cast<int>(v) - static_cast<int>(CSSValueID::kInline) + static_cast<int>(EResize::kInline));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EResize v) {
  switch (v) {
    case EResize::kNone:
      return CSSValueID::kNone;
    case EResize::kBoth:
      return CSSValueID::kBoth;
    case EResize::kHorizontal:
      return CSSValueID::kHorizontal;
    case EResize::kVertical:
      return CSSValueID::kVertical;
    default:
      DCHECK_GE(v, EResize::kInline);
      DCHECK_LE(v, EResize::kBlock);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EResize::kInline) + static_cast<int>(CSSValueID::kInline));
  }
}


template <>
inline ERubyAlign cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kCenter:
      return ERubyAlign::kCenter;
    case CSSValueID::kStart:
      return ERubyAlign::kStart;
    default:
      DCHECK_GE(v, CSSValueID::kSpaceBetween);
      DCHECK_LE(v, CSSValueID::kSpaceAround);
      return static_cast<ERubyAlign>(static_cast<int>(v) - static_cast<int>(CSSValueID::kSpaceBetween) + static_cast<int>(ERubyAlign::kSpaceBetween));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ERubyAlign v) {
  switch (v) {
    case ERubyAlign::kCenter:
      return CSSValueID::kCenter;
    case ERubyAlign::kStart:
      return CSSValueID::kStart;
    default:
      DCHECK_GE(v, ERubyAlign::kSpaceBetween);
      DCHECK_LE(v, ERubyAlign::kSpaceAround);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ERubyAlign::kSpaceBetween) + static_cast<int>(CSSValueID::kSpaceBetween));
  }
}


template <>
inline ERubyOverhang cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return ERubyOverhang::kAuto;
    case CSSValueID::kSpaces:
      return ERubyOverhang::kSpaces;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<ERubyOverhang>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(ERubyOverhang::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ERubyOverhang v) {
  switch (v) {
    case ERubyOverhang::kAuto:
      return CSSValueID::kAuto;
    case ERubyOverhang::kSpaces:
      return CSSValueID::kSpaces;
    default:
      DCHECK_GE(v, ERubyOverhang::kNone);
      DCHECK_LE(v, ERubyOverhang::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ERubyOverhang::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline RubyPosition cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kOver);
  DCHECK_LE(v, CSSValueID::kUnder);
  return static_cast<RubyPosition>(static_cast<int>(v) - static_cast<int>(CSSValueID::kOver) + static_cast<int>(RubyPosition::kOver));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(RubyPosition v) {
  DCHECK_GE(v, RubyPosition::kOver);
  DCHECK_LE(v, RubyPosition::kUnder);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(RubyPosition::kOver) + static_cast<int>(CSSValueID::kOver));
}


template <>
inline ERuleOverlap cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kRowOverColumn);
  DCHECK_LE(v, CSSValueID::kColumnOverRow);
  return static_cast<ERuleOverlap>(static_cast<int>(v) - static_cast<int>(CSSValueID::kRowOverColumn) + static_cast<int>(ERuleOverlap::kRowOverColumn));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ERuleOverlap v) {
  DCHECK_GE(v, ERuleOverlap::kRowOverColumn);
  DCHECK_LE(v, ERuleOverlap::kColumnOverRow);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ERuleOverlap::kRowOverColumn) + static_cast<int>(CSSValueID::kRowOverColumn));
}


template <>
inline EScrollAxisLock cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EScrollAxisLock::kAuto;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EScrollAxisLock>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EScrollAxisLock::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EScrollAxisLock v) {
  switch (v) {
    case EScrollAxisLock::kAuto:
      return CSSValueID::kAuto;
    default:
      DCHECK_GE(v, EScrollAxisLock::kNone);
      DCHECK_LE(v, EScrollAxisLock::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EScrollAxisLock::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EScrollInitialTarget cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNearest:
      return EScrollInitialTarget::kNearest;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EScrollInitialTarget>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EScrollInitialTarget::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EScrollInitialTarget v) {
  switch (v) {
    case EScrollInitialTarget::kNearest:
      return CSSValueID::kNearest;
    default:
      DCHECK_GE(v, EScrollInitialTarget::kNone);
      DCHECK_LE(v, EScrollInitialTarget::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EScrollInitialTarget::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EScrollSnapStop cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAlways:
      return EScrollSnapStop::kAlways;
    case CSSValueID::kBefore:
      return EScrollSnapStop::kBefore;
    default:
      DCHECK_GE(v, CSSValueID::kNormal);
      DCHECK_LE(v, CSSValueID::kNormal);
      return static_cast<EScrollSnapStop>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNormal) + static_cast<int>(EScrollSnapStop::kNormal));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EScrollSnapStop v) {
  switch (v) {
    case EScrollSnapStop::kAlways:
      return CSSValueID::kAlways;
    case EScrollSnapStop::kBefore:
      return CSSValueID::kBefore;
    default:
      DCHECK_GE(v, EScrollSnapStop::kNormal);
      DCHECK_LE(v, EScrollSnapStop::kNormal);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EScrollSnapStop::kNormal) + static_cast<int>(CSSValueID::kNormal));
  }
}


template <>
inline EScrollTargetGroup cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EScrollTargetGroup::kAuto;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EScrollTargetGroup>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EScrollTargetGroup::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EScrollTargetGroup v) {
  switch (v) {
    case EScrollTargetGroup::kAuto:
      return CSSValueID::kAuto;
    default:
      DCHECK_GE(v, EScrollTargetGroup::kNone);
      DCHECK_LE(v, EScrollTargetGroup::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EScrollTargetGroup::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EScrollbarWidth cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EScrollbarWidth::kAuto;
    case CSSValueID::kThin:
      return EScrollbarWidth::kThin;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EScrollbarWidth>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EScrollbarWidth::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EScrollbarWidth v) {
  switch (v) {
    case EScrollbarWidth::kAuto:
      return CSSValueID::kAuto;
    case EScrollbarWidth::kThin:
      return CSSValueID::kThin;
    default:
      DCHECK_GE(v, EScrollbarWidth::kNone);
      DCHECK_LE(v, EScrollbarWidth::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EScrollbarWidth::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EShapeRendering cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EShapeRendering::kAuto;
    case CSSValueID::kOptimizespeed:
      return EShapeRendering::kOptimizespeed;
    default:
      DCHECK_GE(v, CSSValueID::kGeometricprecision);
      DCHECK_LE(v, CSSValueID::kCrispedges);
      return static_cast<EShapeRendering>(static_cast<int>(v) - static_cast<int>(CSSValueID::kGeometricprecision) + static_cast<int>(EShapeRendering::kGeometricprecision));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EShapeRendering v) {
  switch (v) {
    case EShapeRendering::kAuto:
      return CSSValueID::kAuto;
    case EShapeRendering::kOptimizespeed:
      return CSSValueID::kOptimizespeed;
    default:
      DCHECK_GE(v, EShapeRendering::kGeometricprecision);
      DCHECK_LE(v, EShapeRendering::kCrispedges);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EShapeRendering::kGeometricprecision) + static_cast<int>(CSSValueID::kGeometricprecision));
  }
}


template <>
inline ESpeak cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNone:
      return ESpeak::kNone;
    case CSSValueID::kNormal:
      return ESpeak::kNormal;
    default:
      DCHECK_GE(v, CSSValueID::kSpellOut);
      DCHECK_LE(v, CSSValueID::kNoPunctuation);
      return static_cast<ESpeak>(static_cast<int>(v) - static_cast<int>(CSSValueID::kSpellOut) + static_cast<int>(ESpeak::kSpellOut));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ESpeak v) {
  switch (v) {
    case ESpeak::kNone:
      return CSSValueID::kNone;
    case ESpeak::kNormal:
      return CSSValueID::kNormal;
    default:
      DCHECK_GE(v, ESpeak::kSpellOut);
      DCHECK_LE(v, ESpeak::kNoPunctuation);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ESpeak::kSpellOut) + static_cast<int>(CSSValueID::kSpellOut));
  }
}


template <>
inline ETableLayout cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kFixed:
      return ETableLayout::kFixed;
    default:
      DCHECK_GE(v, CSSValueID::kAuto);
      DCHECK_LE(v, CSSValueID::kAuto);
      return static_cast<ETableLayout>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAuto) + static_cast<int>(ETableLayout::kAuto));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ETableLayout v) {
  switch (v) {
    case ETableLayout::kFixed:
      return CSSValueID::kFixed;
    default:
      DCHECK_GE(v, ETableLayout::kAuto);
      DCHECK_LE(v, ETableLayout::kAuto);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ETableLayout::kAuto) + static_cast<int>(CSSValueID::kAuto));
  }
}


template <>
inline ETextAlign cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kStart:
      return ETextAlign::kStart;
    case CSSValueID::kEnd:
      return ETextAlign::kEnd;
    default:
      DCHECK_GE(v, CSSValueID::kLeft);
      DCHECK_LE(v, CSSValueID::kWebkitCenter);
      return static_cast<ETextAlign>(static_cast<int>(v) - static_cast<int>(CSSValueID::kLeft) + static_cast<int>(ETextAlign::kLeft));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ETextAlign v) {
  switch (v) {
    case ETextAlign::kStart:
      return CSSValueID::kStart;
    case ETextAlign::kEnd:
      return CSSValueID::kEnd;
    default:
      DCHECK_GE(v, ETextAlign::kLeft);
      DCHECK_LE(v, ETextAlign::kWebkitCenter);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ETextAlign::kLeft) + static_cast<int>(CSSValueID::kLeft));
  }
}


template <>
inline ETextAlignLast cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return ETextAlignLast::kAuto;
    case CSSValueID::kStart:
      return ETextAlignLast::kStart;
    case CSSValueID::kEnd:
      return ETextAlignLast::kEnd;
    default:
      DCHECK_GE(v, CSSValueID::kLeft);
      DCHECK_LE(v, CSSValueID::kMatchParent);
      return static_cast<ETextAlignLast>(static_cast<int>(v) - static_cast<int>(CSSValueID::kLeft) + static_cast<int>(ETextAlignLast::kLeft));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ETextAlignLast v) {
  switch (v) {
    case ETextAlignLast::kAuto:
      return CSSValueID::kAuto;
    case ETextAlignLast::kStart:
      return CSSValueID::kStart;
    case ETextAlignLast::kEnd:
      return CSSValueID::kEnd;
    default:
      DCHECK_GE(v, ETextAlignLast::kLeft);
      DCHECK_LE(v, ETextAlignLast::kMatchParent);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ETextAlignLast::kLeft) + static_cast<int>(CSSValueID::kLeft));
  }
}


template <>
inline ETextAnchor cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kMiddle:
      return ETextAnchor::kMiddle;
    default:
      DCHECK_GE(v, CSSValueID::kStart);
      DCHECK_LE(v, CSSValueID::kEnd);
      return static_cast<ETextAnchor>(static_cast<int>(v) - static_cast<int>(CSSValueID::kStart) + static_cast<int>(ETextAnchor::kStart));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ETextAnchor v) {
  switch (v) {
    case ETextAnchor::kMiddle:
      return CSSValueID::kMiddle;
    default:
      DCHECK_GE(v, ETextAnchor::kStart);
      DCHECK_LE(v, ETextAnchor::kEnd);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ETextAnchor::kStart) + static_cast<int>(CSSValueID::kStart));
  }
}


template <>
inline ETextAutospace cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNoAutospace:
      return ETextAutospace::kNoAutospace;
    default:
      DCHECK_GE(v, CSSValueID::kNormal);
      DCHECK_LE(v, CSSValueID::kNormal);
      return static_cast<ETextAutospace>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNormal) + static_cast<int>(ETextAutospace::kNormal));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ETextAutospace v) {
  switch (v) {
    case ETextAutospace::kNoAutospace:
      return CSSValueID::kNoAutospace;
    default:
      DCHECK_GE(v, ETextAutospace::kNormal);
      DCHECK_LE(v, ETextAutospace::kNormal);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ETextAutospace::kNormal) + static_cast<int>(CSSValueID::kNormal));
  }
}


template <>
inline ETextBoxTrim cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNone:
      return ETextBoxTrim::kNone;
    default:
      DCHECK_GE(v, CSSValueID::kTrimBoth);
      DCHECK_LE(v, CSSValueID::kTrimStart);
      return static_cast<ETextBoxTrim>(static_cast<int>(v) - static_cast<int>(CSSValueID::kTrimBoth) + static_cast<int>(ETextBoxTrim::kTrimBoth));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ETextBoxTrim v) {
  switch (v) {
    case ETextBoxTrim::kNone:
      return CSSValueID::kNone;
    default:
      DCHECK_GE(v, ETextBoxTrim::kTrimBoth);
      DCHECK_LE(v, ETextBoxTrim::kTrimStart);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ETextBoxTrim::kTrimBoth) + static_cast<int>(CSSValueID::kTrimBoth));
  }
}


template <>
inline ETextCombine cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAll:
      return ETextCombine::kAll;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<ETextCombine>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(ETextCombine::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ETextCombine v) {
  switch (v) {
    case ETextCombine::kAll:
      return CSSValueID::kAll;
    default:
      DCHECK_GE(v, ETextCombine::kNone);
      DCHECK_LE(v, ETextCombine::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ETextCombine::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}

template <>
inline TextDecorationLine cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNone:
      return TextDecorationLine::kNone;
    case CSSValueID::kUnderline:
      return TextDecorationLine::kUnderline;
    case CSSValueID::kOverline:
      return TextDecorationLine::kOverline;
    case CSSValueID::kLineThrough:
      return TextDecorationLine::kLineThrough;
    case CSSValueID::kBlink:
      return TextDecorationLine::kBlink;
    case CSSValueID::kSpellingError:
      return TextDecorationLine::kSpellingError;
    case CSSValueID::kGrammarError:
      return TextDecorationLine::kGrammarError;
    default:
      NOTREACHED();
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(TextDecorationLine v) {
  switch (v) {
    case TextDecorationLine::kNone:
      return CSSValueID::kNone;
    case TextDecorationLine::kUnderline:
      return CSSValueID::kUnderline;
    case TextDecorationLine::kOverline:
      return CSSValueID::kOverline;
    case TextDecorationLine::kLineThrough:
      return CSSValueID::kLineThrough;
    case TextDecorationLine::kBlink:
      return CSSValueID::kBlink;
    case TextDecorationLine::kSpellingError:
      return CSSValueID::kSpellingError;
    case TextDecorationLine::kGrammarError:
      return CSSValueID::kGrammarError;
    default:
      NOTREACHED();
  }
}

template <>
inline ETextDecorationSkipInk cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAll:
      return ETextDecorationSkipInk::kAll;
    case CSSValueID::kAuto:
      return ETextDecorationSkipInk::kAuto;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<ETextDecorationSkipInk>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(ETextDecorationSkipInk::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ETextDecorationSkipInk v) {
  switch (v) {
    case ETextDecorationSkipInk::kAll:
      return CSSValueID::kAll;
    case ETextDecorationSkipInk::kAuto:
      return CSSValueID::kAuto;
    default:
      DCHECK_GE(v, ETextDecorationSkipInk::kNone);
      DCHECK_LE(v, ETextDecorationSkipInk::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ETextDecorationSkipInk::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}

template <>
inline TextDecorationSkipSpaces cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNone:
      return TextDecorationSkipSpaces::kNone;
    case CSSValueID::kStart:
      return TextDecorationSkipSpaces::kStart;
    case CSSValueID::kEnd:
      return TextDecorationSkipSpaces::kEnd;
    case CSSValueID::kAll:
      return TextDecorationSkipSpaces::kAll;
    default:
      NOTREACHED();
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(TextDecorationSkipSpaces v) {
  switch (v) {
    case TextDecorationSkipSpaces::kNone:
      return CSSValueID::kNone;
    case TextDecorationSkipSpaces::kStart:
      return CSSValueID::kStart;
    case TextDecorationSkipSpaces::kEnd:
      return CSSValueID::kEnd;
    case TextDecorationSkipSpaces::kAll:
      return CSSValueID::kAll;
    default:
      NOTREACHED();
  }
}

template <>
inline ETextDecorationStyle cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kWavy:
      return ETextDecorationStyle::kWavy;
    default:
      DCHECK_GE(v, CSSValueID::kDotted);
      DCHECK_LE(v, CSSValueID::kDouble);
      return static_cast<ETextDecorationStyle>(static_cast<int>(v) - static_cast<int>(CSSValueID::kDotted) + static_cast<int>(ETextDecorationStyle::kDotted));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ETextDecorationStyle v) {
  switch (v) {
    case ETextDecorationStyle::kWavy:
      return CSSValueID::kWavy;
    default:
      DCHECK_GE(v, ETextDecorationStyle::kDotted);
      DCHECK_LE(v, ETextDecorationStyle::kDouble);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ETextDecorationStyle::kDotted) + static_cast<int>(CSSValueID::kDotted));
  }
}

template <>
inline ETextTransform cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNone:
      return ETextTransform::kNone;
    case CSSValueID::kCapitalize:
      return ETextTransform::kCapitalize;
    case CSSValueID::kUppercase:
      return ETextTransform::kUppercase;
    case CSSValueID::kLowercase:
      return ETextTransform::kLowercase;
    case CSSValueID::kFullWidth:
      return ETextTransform::kFullWidth;
    case CSSValueID::kFullSizeKana:
      return ETextTransform::kFullSizeKana;
    case CSSValueID::kMathAuto:
      return ETextTransform::kMathAuto;
    default:
      NOTREACHED();
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ETextTransform v) {
  switch (v) {
    case ETextTransform::kNone:
      return CSSValueID::kNone;
    case ETextTransform::kCapitalize:
      return CSSValueID::kCapitalize;
    case ETextTransform::kUppercase:
      return CSSValueID::kUppercase;
    case ETextTransform::kLowercase:
      return CSSValueID::kLowercase;
    case ETextTransform::kFullWidth:
      return CSSValueID::kFullWidth;
    case ETextTransform::kFullSizeKana:
      return CSSValueID::kFullSizeKana;
    case ETextTransform::kMathAuto:
      return CSSValueID::kMathAuto;
    default:
      NOTREACHED();
  }
}

template <>
inline TextWrapMode cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kWrap:
      return TextWrapMode::kWrap;
    default:
      DCHECK_GE(v, CSSValueID::kNowrap);
      DCHECK_LE(v, CSSValueID::kNowrap);
      return static_cast<TextWrapMode>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNowrap) + static_cast<int>(TextWrapMode::kNowrap));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(TextWrapMode v) {
  switch (v) {
    case TextWrapMode::kWrap:
      return CSSValueID::kWrap;
    default:
      DCHECK_GE(v, TextWrapMode::kNowrap);
      DCHECK_LE(v, TextWrapMode::kNowrap);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(TextWrapMode::kNowrap) + static_cast<int>(CSSValueID::kNowrap));
  }
}


template <>
inline TextWrapStyle cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kPretty:
      return TextWrapStyle::kPretty;
    case CSSValueID::kBalance:
      return TextWrapStyle::kBalance;
    case CSSValueID::kStable:
      return TextWrapStyle::kStable;
    default:
      DCHECK_GE(v, CSSValueID::kAuto);
      DCHECK_LE(v, CSSValueID::kAuto);
      return static_cast<TextWrapStyle>(static_cast<int>(v) - static_cast<int>(CSSValueID::kAuto) + static_cast<int>(TextWrapStyle::kAuto));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(TextWrapStyle v) {
  switch (v) {
    case TextWrapStyle::kPretty:
      return CSSValueID::kPretty;
    case TextWrapStyle::kBalance:
      return CSSValueID::kBalance;
    case TextWrapStyle::kStable:
      return CSSValueID::kStable;
    default:
      DCHECK_GE(v, TextWrapStyle::kAuto);
      DCHECK_LE(v, TextWrapStyle::kAuto);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(TextWrapStyle::kAuto) + static_cast<int>(CSSValueID::kAuto));
  }
}


template <>
inline ETransformBox cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kBorderBox:
      return ETransformBox::kBorderBox;
    case CSSValueID::kContentBox:
      return ETransformBox::kContentBox;
    case CSSValueID::kStrokeBox:
      return ETransformBox::kStrokeBox;
    default:
      DCHECK_GE(v, CSSValueID::kFillBox);
      DCHECK_LE(v, CSSValueID::kViewBox);
      return static_cast<ETransformBox>(static_cast<int>(v) - static_cast<int>(CSSValueID::kFillBox) + static_cast<int>(ETransformBox::kFillBox));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ETransformBox v) {
  switch (v) {
    case ETransformBox::kBorderBox:
      return CSSValueID::kBorderBox;
    case ETransformBox::kContentBox:
      return CSSValueID::kContentBox;
    case ETransformBox::kStrokeBox:
      return CSSValueID::kStrokeBox;
    default:
      DCHECK_GE(v, ETransformBox::kFillBox);
      DCHECK_LE(v, ETransformBox::kViewBox);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ETransformBox::kFillBox) + static_cast<int>(CSSValueID::kFillBox));
  }
}


template <>
inline ETransformStyle3D cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kFlat);
  DCHECK_LE(v, CSSValueID::kPreserve3d);
  return static_cast<ETransformStyle3D>(static_cast<int>(v) - static_cast<int>(CSSValueID::kFlat) + static_cast<int>(ETransformStyle3D::kFlat));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ETransformStyle3D v) {
  DCHECK_GE(v, ETransformStyle3D::kFlat);
  DCHECK_LE(v, ETransformStyle3D::kPreserve3d);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ETransformStyle3D::kFlat) + static_cast<int>(CSSValueID::kFlat));
}


template <>
inline UnicodeBidi cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kBidiOverride:
      return UnicodeBidi::kBidiOverride;
    case CSSValueID::kEmbed:
      return UnicodeBidi::kEmbed;
    case CSSValueID::kIsolate:
      return UnicodeBidi::kIsolate;
    case CSSValueID::kIsolateOverride:
      return UnicodeBidi::kIsolateOverride;
    case CSSValueID::kPlaintext:
      return UnicodeBidi::kPlaintext;
    default:
      DCHECK_GE(v, CSSValueID::kNormal);
      DCHECK_LE(v, CSSValueID::kNormal);
      return static_cast<UnicodeBidi>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNormal) + static_cast<int>(UnicodeBidi::kNormal));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(UnicodeBidi v) {
  switch (v) {
    case UnicodeBidi::kBidiOverride:
      return CSSValueID::kBidiOverride;
    case UnicodeBidi::kEmbed:
      return CSSValueID::kEmbed;
    case UnicodeBidi::kIsolate:
      return CSSValueID::kIsolate;
    case UnicodeBidi::kIsolateOverride:
      return CSSValueID::kIsolateOverride;
    case UnicodeBidi::kPlaintext:
      return CSSValueID::kPlaintext;
    default:
      DCHECK_GE(v, UnicodeBidi::kNormal);
      DCHECK_LE(v, UnicodeBidi::kNormal);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(UnicodeBidi::kNormal) + static_cast<int>(CSSValueID::kNormal));
  }
}


template <>
inline EUserSelect cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAll:
      return EUserSelect::kAll;
    case CSSValueID::kAuto:
      return EUserSelect::kAuto;
    case CSSValueID::kText:
      return EUserSelect::kText;
    case CSSValueID::kContain:
      return EUserSelect::kContain;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EUserSelect>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EUserSelect::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EUserSelect v) {
  switch (v) {
    case EUserSelect::kAll:
      return CSSValueID::kAll;
    case EUserSelect::kAuto:
      return CSSValueID::kAuto;
    case EUserSelect::kText:
      return CSSValueID::kText;
    case EUserSelect::kContain:
      return CSSValueID::kContain;
    default:
      DCHECK_GE(v, EUserSelect::kNone);
      DCHECK_LE(v, EUserSelect::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EUserSelect::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EVectorEffect cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNonScalingStroke:
      return EVectorEffect::kNonScalingStroke;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EVectorEffect>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EVectorEffect::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EVectorEffect v) {
  switch (v) {
    case EVectorEffect::kNonScalingStroke:
      return CSSValueID::kNonScalingStroke;
    default:
      DCHECK_GE(v, EVectorEffect::kNone);
      DCHECK_LE(v, EVectorEffect::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EVectorEffect::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EViewTransitionScope cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAll:
      return EViewTransitionScope::kAll;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EViewTransitionScope>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EViewTransitionScope::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EViewTransitionScope v) {
  switch (v) {
    case EViewTransitionScope::kAll:
      return CSSValueID::kAll;
    default:
      DCHECK_GE(v, EViewTransitionScope::kNone);
      DCHECK_LE(v, EViewTransitionScope::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EViewTransitionScope::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EVisibility cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kHidden:
      return EVisibility::kHidden;
    default:
      DCHECK_GE(v, CSSValueID::kVisible);
      DCHECK_LE(v, CSSValueID::kCollapse);
      return static_cast<EVisibility>(static_cast<int>(v) - static_cast<int>(CSSValueID::kVisible) + static_cast<int>(EVisibility::kVisible));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EVisibility v) {
  switch (v) {
    case EVisibility::kHidden:
      return CSSValueID::kHidden;
    default:
      DCHECK_GE(v, EVisibility::kVisible);
      DCHECK_LE(v, EVisibility::kCollapse);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EVisibility::kVisible) + static_cast<int>(CSSValueID::kVisible));
  }
}


template <>
inline EBoxAlignment cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kBaseline:
      return EBoxAlignment::kBaseline;
    case CSSValueID::kCenter:
      return EBoxAlignment::kCenter;
    default:
      DCHECK_GE(v, CSSValueID::kStretch);
      DCHECK_LE(v, CSSValueID::kEnd);
      return static_cast<EBoxAlignment>(static_cast<int>(v) - static_cast<int>(CSSValueID::kStretch) + static_cast<int>(EBoxAlignment::kStretch));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EBoxAlignment v) {
  switch (v) {
    case EBoxAlignment::kBaseline:
      return CSSValueID::kBaseline;
    case EBoxAlignment::kCenter:
      return CSSValueID::kCenter;
    default:
      DCHECK_GE(v, EBoxAlignment::kStretch);
      DCHECK_LE(v, EBoxAlignment::kEnd);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EBoxAlignment::kStretch) + static_cast<int>(CSSValueID::kStretch));
  }
}


template <>
inline EBoxDirection cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kReverse:
      return EBoxDirection::kReverse;
    default:
      DCHECK_GE(v, CSSValueID::kNormal);
      DCHECK_LE(v, CSSValueID::kNormal);
      return static_cast<EBoxDirection>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNormal) + static_cast<int>(EBoxDirection::kNormal));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EBoxDirection v) {
  switch (v) {
    case EBoxDirection::kReverse:
      return CSSValueID::kReverse;
    default:
      DCHECK_GE(v, EBoxDirection::kNormal);
      DCHECK_LE(v, EBoxDirection::kNormal);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EBoxDirection::kNormal) + static_cast<int>(CSSValueID::kNormal));
  }
}


template <>
inline EBoxOrient cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kHorizontal);
  DCHECK_LE(v, CSSValueID::kVertical);
  return static_cast<EBoxOrient>(static_cast<int>(v) - static_cast<int>(CSSValueID::kHorizontal) + static_cast<int>(EBoxOrient::kHorizontal));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EBoxOrient v) {
  DCHECK_GE(v, EBoxOrient::kHorizontal);
  DCHECK_LE(v, EBoxOrient::kVertical);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EBoxOrient::kHorizontal) + static_cast<int>(CSSValueID::kHorizontal));
}


template <>
inline EBoxPack cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kStart:
      return EBoxPack::kStart;
    case CSSValueID::kEnd:
      return EBoxPack::kEnd;
    default:
      DCHECK_GE(v, CSSValueID::kCenter);
      DCHECK_LE(v, CSSValueID::kJustify);
      return static_cast<EBoxPack>(static_cast<int>(v) - static_cast<int>(CSSValueID::kCenter) + static_cast<int>(EBoxPack::kCenter));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EBoxPack v) {
  switch (v) {
    case EBoxPack::kStart:
      return CSSValueID::kStart;
    case EBoxPack::kEnd:
      return CSSValueID::kEnd;
    default:
      DCHECK_GE(v, EBoxPack::kCenter);
      DCHECK_LE(v, EBoxPack::kJustify);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EBoxPack::kCenter) + static_cast<int>(CSSValueID::kCenter));
  }
}


template <>
inline EOrder cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kLogical);
  DCHECK_LE(v, CSSValueID::kVisual);
  return static_cast<EOrder>(static_cast<int>(v) - static_cast<int>(CSSValueID::kLogical) + static_cast<int>(EOrder::kLogical));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EOrder v) {
  DCHECK_GE(v, EOrder::kLogical);
  DCHECK_LE(v, EOrder::kVisual);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EOrder::kLogical) + static_cast<int>(CSSValueID::kLogical));
}


template <>
inline ETextSecurity cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNone:
      return ETextSecurity::kNone;
    default:
      DCHECK_GE(v, CSSValueID::kDisc);
      DCHECK_LE(v, CSSValueID::kSquare);
      return static_cast<ETextSecurity>(static_cast<int>(v) - static_cast<int>(CSSValueID::kDisc) + static_cast<int>(ETextSecurity::kDisc));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(ETextSecurity v) {
  switch (v) {
    case ETextSecurity::kNone:
      return CSSValueID::kNone;
    default:
      DCHECK_GE(v, ETextSecurity::kDisc);
      DCHECK_LE(v, ETextSecurity::kSquare);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(ETextSecurity::kDisc) + static_cast<int>(CSSValueID::kDisc));
  }
}


template <>
inline EUserDrag cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kAuto:
      return EUserDrag::kAuto;
    case CSSValueID::kElement:
      return EUserDrag::kElement;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EUserDrag>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EUserDrag::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EUserDrag v) {
  switch (v) {
    case EUserDrag::kAuto:
      return CSSValueID::kAuto;
    case EUserDrag::kElement:
      return CSSValueID::kElement;
    default:
      DCHECK_GE(v, EUserDrag::kNone);
      DCHECK_LE(v, EUserDrag::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EUserDrag::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EUserModify cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  DCHECK_GE(v, CSSValueID::kReadOnly);
  DCHECK_LE(v, CSSValueID::kReadWritePlaintextOnly);
  return static_cast<EUserModify>(static_cast<int>(v) - static_cast<int>(CSSValueID::kReadOnly) + static_cast<int>(EUserModify::kReadOnly));
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EUserModify v) {
  DCHECK_GE(v, EUserModify::kReadOnly);
  DCHECK_LE(v, EUserModify::kReadWritePlaintextOnly);
  return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EUserModify::kReadOnly) + static_cast<int>(CSSValueID::kReadOnly));
}


template <>
inline EDraggableRegionMode cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kMove:
      return EDraggableRegionMode::kMove;
    case CSSValueID::kNoDrag:
      return EDraggableRegionMode::kNoDrag;
    default:
      DCHECK_GE(v, CSSValueID::kNone);
      DCHECK_LE(v, CSSValueID::kNone);
      return static_cast<EDraggableRegionMode>(static_cast<int>(v) - static_cast<int>(CSSValueID::kNone) + static_cast<int>(EDraggableRegionMode::kNone));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EDraggableRegionMode v) {
  switch (v) {
    case EDraggableRegionMode::kMove:
      return CSSValueID::kMove;
    case EDraggableRegionMode::kNoDrag:
      return CSSValueID::kNoDrag;
    default:
      DCHECK_GE(v, EDraggableRegionMode::kNone);
      DCHECK_LE(v, EDraggableRegionMode::kNone);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EDraggableRegionMode::kNone) + static_cast<int>(CSSValueID::kNone));
  }
}


template <>
inline EWordBreak cssValueIDToPlatformEnumGenerated(CSSValueID v) {
  switch (v) {
    case CSSValueID::kNormal:
      return EWordBreak::kNormal;
    case CSSValueID::kAutoPhrase:
      return EWordBreak::kAutoPhrase;
    case CSSValueID::kBreakWord:
      return EWordBreak::kBreakWord;
    default:
      DCHECK_GE(v, CSSValueID::kBreakAll);
      DCHECK_LE(v, CSSValueID::kKeepAll);
      return static_cast<EWordBreak>(static_cast<int>(v) - static_cast<int>(CSSValueID::kBreakAll) + static_cast<int>(EWordBreak::kBreakAll));
  }
}

inline CSSValueID platformEnumToCSSValueIDGenerated(EWordBreak v) {
  switch (v) {
    case EWordBreak::kNormal:
      return CSSValueID::kNormal;
    case EWordBreak::kAutoPhrase:
      return CSSValueID::kAutoPhrase;
    case EWordBreak::kBreakWord:
      return CSSValueID::kBreakWord;
    default:
      DCHECK_GE(v, EWordBreak::kBreakAll);
      DCHECK_LE(v, EWordBreak::kKeepAll);
      return static_cast<CSSValueID>(static_cast<int>(v) - static_cast<int>(EWordBreak::kBreakAll) + static_cast<int>(CSSValueID::kBreakAll));
  }
}

}  // namespace detail

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_CSS_CSS_VALUE_ID_MAPPINGS_GENERATED_H_
