// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/style/templates/computed_style_base.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_group_config.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/core/css/css_value_keywords.json5
//   ../../third_party/blink/renderer/core/style/computed_style_extra_fields.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5


#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_BASE_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_BASE_H_

#include <optional>

#include "base/memory/values_equivalent.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/style/computed_style_constants.h"
#include "third_party/blink/renderer/core/style/member_copy.h"
#include "third_party/blink/renderer/core/style/computed_style_initial_values.h"
#include "third_party/blink/renderer/core/style/style_cached_data.h"
#include "cc/input/scroll_snap_data.h"
#include "third_party/blink/public/common/css/page_orientation.h"
#include "third_party/blink/public/common/css/page_size_type.h"
#include "third_party/blink/public/mojom/frame/color_scheme.mojom-blink.h"
#include "third_party/blink/public/mojom/scroll/scroll_enums.mojom-blink.h"
#include "third_party/blink/renderer/core/animation/css/css_animation_data.h"
#include "third_party/blink/renderer/core/animation/css/css_transition_data.h"
#include "third_party/blink/renderer/core/animation/effect_model.h"
#include "third_party/blink/renderer/core/animation/timeline_inset.h"
#include "third_party/blink/renderer/core/css/style_auto_color.h"
#include "third_party/blink/renderer/core/css/style_caret_color.h"
#include "third_party/blink/renderer/core/css/style_color.h"
#include "third_party/blink/renderer/core/css/style_rule.h"
#include "third_party/blink/renderer/core/css/white_space.h"
#include "third_party/blink/renderer/core/css_value_keywords.h"
#include "third_party/blink/renderer/core/keywords.h"
#include "third_party/blink/renderer/core/layout/grid_lanes/grid_lanes_direction.h"
#include "third_party/blink/renderer/core/layout/layout_theme.h"
#include "third_party/blink/renderer/core/style/applied_text_decoration.h"
#include "third_party/blink/renderer/core/style/basic_shapes.h"
#include "third_party/blink/renderer/core/style/clip_path_operation.h"
#include "third_party/blink/renderer/core/style/computed_grid_template_areas.h"
#include "third_party/blink/renderer/core/style/computed_grid_track_list.h"
#include "third_party/blink/renderer/core/style/content_data.h"
#include "third_party/blink/renderer/core/style/counter_directives.h"
#include "third_party/blink/renderer/core/style/cursor_list.h"
#include "third_party/blink/renderer/core/style/fill_layer.h"
#include "third_party/blink/renderer/core/style/filter_operations.h"
#include "third_party/blink/renderer/core/style/flow_tolerance.h"
#include "third_party/blink/renderer/core/style/gap_data_list.h"
#include "third_party/blink/renderer/core/style/grid_position.h"
#include "third_party/blink/renderer/core/style/grid_track_list.h"
#include "third_party/blink/renderer/core/style/list_style_type_data.h"
#include "third_party/blink/renderer/core/style/max_lines_data.h"
#include "third_party/blink/renderer/core/style/nine_piece_image.h"
#include "third_party/blink/renderer/core/style/offset_path_operation.h"
#include "third_party/blink/renderer/core/style/paint_images.h"
#include "third_party/blink/renderer/core/style/position_area.h"
#include "third_party/blink/renderer/core/style/position_try_fallbacks.h"
#include "third_party/blink/renderer/core/style/scoped_css_name.h"
#include "third_party/blink/renderer/core/style/scroll_marker_group.h"
#include "third_party/blink/renderer/core/style/shadow_list.h"
#include "third_party/blink/renderer/core/style/shape_value.h"
#include "third_party/blink/renderer/core/style/style_anchor_scope.h"
#include "third_party/blink/renderer/core/style/style_aspect_ratio.h"
#include "third_party/blink/renderer/core/style/style_base_data.h"
#include "third_party/blink/renderer/core/style/style_border_shape.h"
#include "third_party/blink/renderer/core/style/style_content_alignment_data.h"
#include "third_party/blink/renderer/core/style/style_flex_wrap_data.h"
#include "third_party/blink/renderer/core/style/style_highlight_data.h"
#include "third_party/blink/renderer/core/style/style_hyphenate_limit_chars.h"
#include "third_party/blink/renderer/core/style/style_image.h"
#include "third_party/blink/renderer/core/style/style_inherited_variables.h"
#include "third_party/blink/renderer/core/style/style_initial_data.h"
#include "third_party/blink/renderer/core/style/style_initial_letter.h"
#include "third_party/blink/renderer/core/style/style_interest_delay.h"
#include "third_party/blink/renderer/core/style/style_intrinsic_length.h"
#include "third_party/blink/renderer/core/style/style_non_inherited_variables.h"
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
#include "third_party/blink/renderer/core/style/style_ua_shadow_host_data.h"
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
#include "third_party/blink/renderer/core/style/text_indent_flags.h"
#include "third_party/blink/renderer/core/style/text_overflow_data.h"
#include "third_party/blink/renderer/core/style/text_size_adjust.h"
#include "third_party/blink/renderer/core/style/transform_origin.h"
#include "third_party/blink/renderer/core/style/unzoomed_length.h"
#include "third_party/blink/renderer/platform/fonts/font.h"
#include "third_party/blink/renderer/platform/fonts/shaping/text_spacing_trim.h"
#include "third_party/blink/renderer/platform/geometry/length.h"
#include "third_party/blink/renderer/platform/geometry/length_box.h"
#include "third_party/blink/renderer/platform/geometry/length_point.h"
#include "third_party/blink/renderer/platform/geometry/length_size.h"
#include "third_party/blink/renderer/platform/geometry/path_types.h"
#include "third_party/blink/renderer/platform/geometry/physical_offset.h"
#include "third_party/blink/renderer/platform/graphics/blend_mode.h"
#include "third_party/blink/renderer/platform/graphics/graphics_context_types.h"
#include "third_party/blink/renderer/platform/graphics/image_node_animation_info.h"
#include "third_party/blink/renderer/platform/graphics/image_orientation.h"
#include "third_party/blink/renderer/platform/graphics/touch_action.h"
#include "third_party/blink/renderer/platform/heap/collection_support/heap_hash_set.h"
#include "third_party/blink/renderer/platform/heap/member.h"
#include "third_party/blink/renderer/platform/heap/persistent.h"
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
#include "third_party/blink/renderer/platform/wtf/hash_set.h"
#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/size_f.h"


namespace blink {

// Forward declaration for diff functions.
class ComputedStyle;

// Forward declaration for constructor.
class ComputedStyleBuilderBase;

// Forward declaration of friends:
namespace css_longhand { class Position; }
namespace css_longhand { class InternalVisitedColor; }
namespace css_longhand { class Appearance; }
namespace css_longhand { class Color; }
namespace css_longhand { class InternalForcedVisitedColor; }
namespace css_longhand { class InternalVisitedBackgroundColor; }
namespace css_longhand { class InternalVisitedBorderBottomColor; }
namespace css_longhand { class InternalVisitedBorderLeftColor; }
namespace css_longhand { class InternalVisitedBorderRightColor; }
namespace css_longhand { class InternalVisitedBorderTopColor; }
namespace css_longhand { class InternalVisitedCaretColor; }
namespace css_longhand { class InternalVisitedOutlineColor; }
namespace css_longhand { class InternalVisitedTextDecorationColor; }
namespace css_longhand { class InternalVisitedTextEmphasisColor; }
namespace css_longhand { class InternalVisitedTextFillColor; }
namespace css_longhand { class InternalVisitedTextStrokeColor; }
namespace css_longhand { class AccentColor; }
namespace css_longhand { class BackdropFilter; }
namespace css_longhand { class BackgroundColor; }
namespace css_longhand { class BorderBottomColor; }
namespace css_longhand { class BorderLeftColor; }
namespace css_longhand { class BorderRightColor; }
namespace css_longhand { class BorderTopColor; }
namespace css_longhand { class CaretColor; }
namespace css_longhand { class Clear; }
namespace css_longhand { class Clip; }
namespace css_longhand { class ClipPath; }
namespace css_longhand { class ColumnCount; }
namespace css_longhand { class ColumnHeight; }
namespace css_longhand { class ColumnRuleColor; }
namespace css_longhand { class ColumnRuleStyle; }
namespace css_longhand { class ColumnRuleWidth; }
namespace css_longhand { class ColumnWidth; }
namespace css_longhand { class Content; }
namespace css_longhand { class Filter; }
namespace css_longhand { class Float; }
namespace css_longhand { class GridAutoFlow; }
namespace css_longhand { class InternalForcedBackgroundColor; }
namespace css_longhand { class InternalForcedBorderColor; }
namespace css_longhand { class InternalForcedColor; }
namespace css_longhand { class InternalForcedOutlineColor; }
namespace css_longhand { class LetterSpacing; }
namespace css_longhand { class MarginBottom; }
namespace css_longhand { class MarginLeft; }
namespace css_longhand { class MarginRight; }
namespace css_longhand { class MarginTop; }
namespace css_longhand { class Opacity; }
namespace css_longhand { class Orphans; }
namespace css_longhand { class OutlineColor; }
namespace css_longhand { class PaddingBottom; }
namespace css_longhand { class PaddingLeft; }
namespace css_longhand { class PaddingRight; }
namespace css_longhand { class PaddingTop; }
namespace css_longhand { class PageMarginSafety; }
namespace css_longhand { class PointerEvents; }
namespace css_longhand { class Resize; }
namespace css_longhand { class RowRuleColor; }
namespace css_longhand { class RowRuleStyle; }
namespace css_longhand { class RowRuleWidth; }
namespace css_longhand { class ShapeImageThreshold; }
namespace css_longhand { class ShapeOutside; }
namespace css_longhand { class StopColor; }
namespace css_longhand { class TabSize; }
namespace css_longhand { class TextDecorationColor; }
namespace css_longhand { class TextEmphasisColor; }
namespace css_longhand { class TextEmphasisPosition; }
namespace css_longhand { class UserSelect; }
namespace css_longhand { class WebkitBoxDirection; }
namespace css_longhand { class WebkitBoxOrdinalGroup; }
namespace css_longhand { class WebkitTextFillColor; }
namespace css_longhand { class WebkitTextStrokeColor; }
namespace css_longhand { class WebkitUserModify; }
namespace css_longhand { class Widows; }
namespace css_longhand { class WordSpacing; }
namespace css_longhand { class ZIndex; }

// The generated portion of ComputedStyle. For more info, see the header comment
// in computed_style.h.
//
// ComputedStyleBase is a generated class that stores data members or 'fields'
// used in ComputedStyle. These fields can represent CSS properties or internal
// style information.
//
// STORAGE:
//
// Fields are organised in a tree structure, where a node (called a 'group')
// stores a set of fields and a set of pointers to child nodes (called
// 'subgroups'). We can visualise the tree structure with ComputedStyleBase as
// the root node:
//
// ComputedStyleBase (fields: display, vertical-align, ...)
//  |- StyleSurroundData (fields: border-color, left/right/top/bottom, ...)
//  |- StyleBoxData (fields: width, height, padding, ...)
//  |- ...
//  |- StyleRareNonInheritedData (fields: box-shadow, text-overflow, ...)
//      |- StyleFlexibleBoxData (fields: flex-direction, flex-wrap, ...)
//      |- ...
//
// This design saves memory by allowing multiple ComputedStyleBases to share the
// same instance of a subgroup. For example, if a page never uses flex box
// properties, then every ComputedStyleBase can share the same instance of
// StyleFlexibleBoxData. Without this sharing, we would need to allocate a copy
// of all the flex box fields for every ComputedStyleBase. Similarly, when an
// element inherits from its parent, its ComputedStyleBase can simply share all
// of its subgroups with the parent's.
//
// Most of these groupings are done manually, although there have been some
// adjustments based on statistics.
//
// INTERFACE:
//
// The functions generated for a field is determined by its 'template'. For
// example, a field with the 'keyword' template has only one setter, whereas an
// 'external' field has an extra setter that takes an rvalue reference. A list
// of the available templates can be found in css_properties.json5.
class ComputedStyleBase : public GarbageCollected<ComputedStyleBase> {
  // Properties with protected accessors must be friends because
  // Longhand::Apply* functions typically need the "raw" computed value:
  friend class css_longhand::Position;
  friend class css_longhand::InternalVisitedColor;
  friend class css_longhand::Appearance;
  friend class css_longhand::Color;
  friend class css_longhand::InternalForcedVisitedColor;
  friend class css_longhand::InternalVisitedBackgroundColor;
  friend class css_longhand::InternalVisitedBorderBottomColor;
  friend class css_longhand::InternalVisitedBorderLeftColor;
  friend class css_longhand::InternalVisitedBorderRightColor;
  friend class css_longhand::InternalVisitedBorderTopColor;
  friend class css_longhand::InternalVisitedCaretColor;
  friend class css_longhand::InternalVisitedOutlineColor;
  friend class css_longhand::InternalVisitedTextDecorationColor;
  friend class css_longhand::InternalVisitedTextEmphasisColor;
  friend class css_longhand::InternalVisitedTextFillColor;
  friend class css_longhand::InternalVisitedTextStrokeColor;
  friend class css_longhand::AccentColor;
  friend class css_longhand::BackdropFilter;
  friend class css_longhand::BackgroundColor;
  friend class css_longhand::BorderBottomColor;
  friend class css_longhand::BorderLeftColor;
  friend class css_longhand::BorderRightColor;
  friend class css_longhand::BorderTopColor;
  friend class css_longhand::CaretColor;
  friend class css_longhand::Clear;
  friend class css_longhand::Clip;
  friend class css_longhand::ClipPath;
  friend class css_longhand::ColumnCount;
  friend class css_longhand::ColumnHeight;
  friend class css_longhand::ColumnRuleColor;
  friend class css_longhand::ColumnRuleStyle;
  friend class css_longhand::ColumnRuleWidth;
  friend class css_longhand::ColumnWidth;
  friend class css_longhand::Content;
  friend class css_longhand::Filter;
  friend class css_longhand::Float;
  friend class css_longhand::GridAutoFlow;
  friend class css_longhand::InternalForcedBackgroundColor;
  friend class css_longhand::InternalForcedBorderColor;
  friend class css_longhand::InternalForcedColor;
  friend class css_longhand::InternalForcedOutlineColor;
  friend class css_longhand::LetterSpacing;
  friend class css_longhand::MarginBottom;
  friend class css_longhand::MarginLeft;
  friend class css_longhand::MarginRight;
  friend class css_longhand::MarginTop;
  friend class css_longhand::Opacity;
  friend class css_longhand::Orphans;
  friend class css_longhand::OutlineColor;
  friend class css_longhand::PaddingBottom;
  friend class css_longhand::PaddingLeft;
  friend class css_longhand::PaddingRight;
  friend class css_longhand::PaddingTop;
  friend class css_longhand::PageMarginSafety;
  friend class css_longhand::PointerEvents;
  friend class css_longhand::Resize;
  friend class css_longhand::RowRuleColor;
  friend class css_longhand::RowRuleStyle;
  friend class css_longhand::RowRuleWidth;
  friend class css_longhand::ShapeImageThreshold;
  friend class css_longhand::ShapeOutside;
  friend class css_longhand::StopColor;
  friend class css_longhand::TabSize;
  friend class css_longhand::TextDecorationColor;
  friend class css_longhand::TextEmphasisColor;
  friend class css_longhand::TextEmphasisPosition;
  friend class css_longhand::UserSelect;
  friend class css_longhand::WebkitBoxDirection;
  friend class css_longhand::WebkitBoxOrdinalGroup;
  friend class css_longhand::WebkitTextFillColor;
  friend class css_longhand::WebkitTextStrokeColor;
  friend class css_longhand::WebkitUserModify;
  friend class css_longhand::Widows;
  friend class css_longhand::WordSpacing;
  friend class css_longhand::ZIndex;

  template <typename T>
  friend CSSVariableData* GetVariableDataInternal(
    const T& style_or_builder,
    const AtomicString& name,
    std::optional<bool> inherited_hint);

 public:
  enum class InheritedPropertyHash : uint32_t {
    kNone = 0,
    kaccent_color_ = 2962878423U,
    kblock_ellipsis_ = 4243344384U,
    kborder_collapse_ = 2623694426U,
    kcap_style_ = 1944760524U,
    kcaption_side_ = 2612129665U,
    kcaret_animation_ = 2089882348U,
    kcaret_color_ = 2030650613U,
    kcaret_shape_ = 2839130128U,
    kclip_rule_ = 3089453321U,
    kcolor_ = 3040347559U,
    kcolor_interpolation_ = 1906970439U,
    kcolor_interpolation_filters_ = 3411647895U,
    kcolor_is_current_color_ = 2817984160U,
    kcolor_rendering_ = 3665670691U,
    kcolor_scheme_ = 2363872784U,
    kcolor_scheme_flags_is_normal_ = 1483529882U,
    kcolor_scheme_forced_ = 2647614072U,
    kcontainer_font_ = 2082715608U,
    kcss_dominant_baseline_ = 4001870058U,
    kcursor_ = 666528105U,
    kcursor_data_ = 2770884510U,
    kdark_color_scheme_ = 3170455047U,
    kdirection_ = 3268075785U,
    kdominant_baseline_ = 148634920U,
    kdraggable_region_mode_ = 1047526405U,
    kdynamic_range_limit_ = 3281144113U,
    keffective_touch_action_ = 1022763925U,
    keffective_zoom_ = 1453627707U,
    kempty_cells_ = 783505393U,
    kfill_opacity_ = 3946989500U,
    kfill_paint_ = 2675470129U,
    kfill_rule_ = 1026261882U,
    kfont_ = 3651366370U,
    kforced_color_adjust_ = 1461558919U,
    khanging_punctuation_ = 801100037U,
    khas_line_if_empty_ = 1123946255U,
    khighlight_data_ = 1195902423U,
    khorizontal_border_spacing_ = 3262831787U,
    khyphenate_limit_chars_ = 4169109866U,
    khyphenation_string_ = 3048587987U,
    khyphens_ = 2935570134U,
    kimage_animation_ = 3384798630U,
    kimage_orientation_ = 562102313U,
    kimage_rendering_ = 2579459256U,
    kin_base_appearance_ = 659719545U,
    kin_forced_colors_mode_ = 2821978513U,
    kinherited_variables_ = 2990732481U,
    kinitial_data_ = 669448816U,
    kinside_link_ = 2221526342U,
    kinteractivity_ = 2782607772U,
    kinternal_forced_color_ = 1461650440U,
    kinternal_forced_visited_color_ = 3168709842U,
    kinternal_visited_caret_color_ = 2994742351U,
    kinternal_visited_color_ = 3903646436U,
    kinternal_visited_color_is_current_color_ = 1060896383U,
    kinternal_visited_fill_paint_ = 3854028784U,
    kinternal_visited_stroke_paint_ = 1068584940U,
    kinternal_visited_text_emphasis_color_ = 3355704822U,
    kinternal_visited_text_fill_color_ = 1919687854U,
    kinternal_visited_text_stroke_color_ = 1325623460U,
    kinterpolate_size_ = 2604344385U,
    kis_css_inert_ = 3199783366U,
    kis_html_inert_ = 264596311U,
    kis_in_shrink_to_fit_subtree_ = 1867746663U,
    kjoin_style_ = 2074660229U,
    kletter_spacing_ = 662121088U,
    kline_break_ = 1731943183U,
    kline_height_ = 3227657057U,
    klist_style_image_ = 1313261956U,
    klist_style_position_ = 4134566688U,
    klist_style_type_ = 4206944198U,
    kmarker_end_resource_ = 2643166581U,
    kmarker_mid_resource_ = 1928514943U,
    kmarker_start_resource_ = 3677167038U,
    kmath_depth_ = 270315170U,
    kmath_shift_ = 514441536U,
    kmath_style_ = 2608262864U,
    korphans_ = 810519810U,
    koverflow_wrap_ = 2429775623U,
    kpaint_order_ = 934176135U,
    kpointer_events_ = 815504280U,
    kprefers_default_scrollbar_styles_ = 2946893271U,
    kprint_color_adjust_ = 1433954654U,
    kquotes_ = 1638297042U,
    krtl_ordering_ = 1171560086U,
    kruby_align_ = 1911421806U,
    kruby_overhang_ = 2353897667U,
    kruby_position_ = 3338752816U,
    kscrollbar_color_ = 484785421U,
    kshape_rendering_ = 493859897U,
    kspeak_ = 2156852899U,
    kstroke_dash_array_ = 1663529026U,
    kstroke_dash_offset_ = 2206972645U,
    kstroke_miter_limit_ = 3747748501U,
    kstroke_opacity_ = 1870394598U,
    kstroke_paint_ = 1098407570U,
    kstroke_width_ = 2644783625U,
    ksubtree_is_sticky_ = 2127620294U,
    ksubtree_will_change_contents_ = 626800325U,
    ktab_size_ = 2015354236U,
    ktap_highlight_color_ = 1837199243U,
    ktext_align_ = 3841162676U,
    ktext_align_last_ = 1478269615U,
    ktext_anchor_ = 2608878167U,
    ktext_autospace_ = 3818310910U,
    ktext_box_edge_ = 872211698U,
    ktext_combine_ = 2892302588U,
    ktext_decoration_skip_ink_ = 2687493349U,
    ktext_decoration_skip_spaces_ = 541598176U,
    ktext_emphasis_color_ = 3004431937U,
    ktext_emphasis_custom_mark_ = 3476872884U,
    ktext_emphasis_fill_ = 4280118191U,
    ktext_emphasis_mark_ = 2626343704U,
    ktext_emphasis_position_ = 2051363289U,
    ktext_fill_color_ = 1189368997U,
    ktext_fit_ = 1860375027U,
    ktext_indent_ = 2736211914U,
    ktext_indent_flags_ = 2287390757U,
    ktext_justify_ = 16641381U,
    ktext_orientation_ = 2198359206U,
    ktext_security_ = 89444177U,
    ktext_shadow_ = 2376790629U,
    ktext_size_adjust_ = 2225260365U,
    ktext_stroke_color_ = 1231620328U,
    ktext_stroke_width_ = 3404121639U,
    ktext_transform_ = 3141011549U,
    ktext_underline_offset_ = 2052743516U,
    ktext_underline_position_ = 3742147099U,
    ktext_wrap_mode_ = 4241247093U,
    ktext_wrap_style_ = 3788084565U,
    kua_shadow_host_data_ = 3828651918U,
    kuser_modify_ = 634032622U,
    kuser_select_ = 2600011227U,
    kvertical_border_spacing_ = 2480875690U,
    kvisibility_ = 2238127936U,
    kwhite_space_collapse_ = 3423985241U,
    kwidows_ = 3113642015U,
    kword_break_ = 424775526U,
    kword_spacing_ = 3099461322U,
    kwriting_mode_ = 119866457U,
    kfill_data_ = 3089475749U,
    khighlight_data_data_ = 1662751441U,
    kinherited_data_ = 2007678354U,
    kinherited_forced_colors_data_ = 1356956565U,
    kinherited_visited_data_ = 3018391537U,
    kmisc_inherited_1_data_ = 1184986U,
    kmisc_inherited_2_data_ = 4045261171U,
    kmisc_inherited_data_ = 3782462945U,
    kresources_data_ = 2336385197U,
    kstroke_data_ = 513892810U,
    ksvginherited_data_ = 1336720493U,
  };

  inline bool IndependentInheritedEqual(const ComputedStyleBase& o) const {
    return (
        (misc_inherited_data_.Get() == o.misc_inherited_data_.Get()
        || (misc_inherited_data_->empty_cells_ == o.misc_inherited_data_->empty_cells_
        && misc_inherited_data_->interactivity_ == o.misc_inherited_data_->interactivity_
        ))
        && (inherited_data_.Get() == o.inherited_data_.Get()
        || (inherited_data_->color_ == o.inherited_data_->color_
        && inherited_data_->cursor_ == o.inherited_data_->cursor_
        && inherited_data_->text_transform_ == o.inherited_data_->text_transform_
        ))
        && data_.pointer_events_ == o.data_.pointer_events_
        && data_.visibility_ == o.data_.visibility_
        && data_.border_collapse_ == o.data_.border_collapse_
        && data_.caption_side_ == o.data_.caption_side_
        && data_.is_css_inert_ == o.data_.is_css_inert_
        && data_.is_html_inert_ == o.data_.is_html_inert_
        && data_.list_style_position_ == o.data_.list_style_position_
        && data_.rtl_ordering_ == o.data_.rtl_ordering_

    );
  }

  inline bool NonIndependentInheritedEqual(const ComputedStyleBase& o) const {
    return (
        (misc_inherited_data_.Get() == o.misc_inherited_data_.Get()
        || (base::ValuesEquivalent(misc_inherited_data_->misc_inherited_1_data_, o.misc_inherited_data_->misc_inherited_1_data_)
        && base::ValuesEquivalent(misc_inherited_data_->misc_inherited_2_data_, o.misc_inherited_data_->misc_inherited_2_data_)
        && misc_inherited_data_->text_box_edge_ == o.misc_inherited_data_->text_box_edge_
        && misc_inherited_data_->text_underline_position_ == o.misc_inherited_data_->text_underline_position_
        && misc_inherited_data_->hanging_punctuation_ == o.misc_inherited_data_->hanging_punctuation_
        && misc_inherited_data_->line_break_ == o.misc_inherited_data_->line_break_
        && misc_inherited_data_->speak_ == o.misc_inherited_data_->speak_
        && misc_inherited_data_->text_align_last_ == o.misc_inherited_data_->text_align_last_
        && misc_inherited_data_->text_decoration_skip_spaces_ == o.misc_inherited_data_->text_decoration_skip_spaces_
        && misc_inherited_data_->text_emphasis_mark_ == o.misc_inherited_data_->text_emphasis_mark_
        && misc_inherited_data_->text_emphasis_position_ == o.misc_inherited_data_->text_emphasis_position_
        && misc_inherited_data_->block_ellipsis_ == o.misc_inherited_data_->block_ellipsis_
        && misc_inherited_data_->user_select_ == o.misc_inherited_data_->user_select_
        && misc_inherited_data_->word_break_ == o.misc_inherited_data_->word_break_
        && misc_inherited_data_->draggable_region_mode_ == o.misc_inherited_data_->draggable_region_mode_
        && misc_inherited_data_->forced_color_adjust_ == o.misc_inherited_data_->forced_color_adjust_
        && misc_inherited_data_->hyphens_ == o.misc_inherited_data_->hyphens_
        && misc_inherited_data_->image_animation_ == o.misc_inherited_data_->image_animation_
        && misc_inherited_data_->image_rendering_ == o.misc_inherited_data_->image_rendering_
        && misc_inherited_data_->overflow_wrap_ == o.misc_inherited_data_->overflow_wrap_
        && misc_inherited_data_->ruby_align_ == o.misc_inherited_data_->ruby_align_
        && misc_inherited_data_->ruby_overhang_ == o.misc_inherited_data_->ruby_overhang_
        && misc_inherited_data_->text_decoration_skip_ink_ == o.misc_inherited_data_->text_decoration_skip_ink_
        && misc_inherited_data_->text_indent_flags_ == o.misc_inherited_data_->text_indent_flags_
        && misc_inherited_data_->text_justify_ == o.misc_inherited_data_->text_justify_
        && misc_inherited_data_->text_orientation_ == o.misc_inherited_data_->text_orientation_
        && misc_inherited_data_->text_security_ == o.misc_inherited_data_->text_security_
        && misc_inherited_data_->user_modify_ == o.misc_inherited_data_->user_modify_
        && misc_inherited_data_->has_line_if_empty_ == o.misc_inherited_data_->has_line_if_empty_
        && misc_inherited_data_->image_orientation_ == o.misc_inherited_data_->image_orientation_
        && misc_inherited_data_->in_base_appearance_ == o.misc_inherited_data_->in_base_appearance_
        && misc_inherited_data_->interpolate_size_ == o.misc_inherited_data_->interpolate_size_
        && misc_inherited_data_->is_in_shrink_to_fit_subtree_ == o.misc_inherited_data_->is_in_shrink_to_fit_subtree_
        && misc_inherited_data_->math_shift_ == o.misc_inherited_data_->math_shift_
        && misc_inherited_data_->math_style_ == o.misc_inherited_data_->math_style_
        && misc_inherited_data_->ruby_position_ == o.misc_inherited_data_->ruby_position_
        && misc_inherited_data_->subtree_is_sticky_ == o.misc_inherited_data_->subtree_is_sticky_
        && misc_inherited_data_->subtree_will_change_contents_ == o.misc_inherited_data_->subtree_will_change_contents_
        && misc_inherited_data_->text_autospace_ == o.misc_inherited_data_->text_autospace_
        && misc_inherited_data_->text_combine_ == o.misc_inherited_data_->text_combine_
        && misc_inherited_data_->text_emphasis_fill_ == o.misc_inherited_data_->text_emphasis_fill_
        ))
        && (inherited_data_.Get() == o.inherited_data_.Get()
        || (base::ValuesEquivalent(inherited_data_->inherited_forced_colors_data_, o.inherited_data_->inherited_forced_colors_data_)
        && base::ValuesEquivalent(inherited_data_->inherited_visited_data_, o.inherited_data_->inherited_visited_data_)
        && base::ValuesEquivalent(inherited_data_->highlight_data_data_, o.inherited_data_->highlight_data_data_)
        && base::ValuesEquivalent(inherited_data_->font_, o.inherited_data_->font_)
        && base::ValuesEquivalent(inherited_data_->container_font_, o.inherited_data_->container_font_)
        && inherited_data_->letter_spacing_ == o.inherited_data_->letter_spacing_
        && inherited_data_->line_height_ == o.inherited_data_->line_height_
        && inherited_data_->word_spacing_ == o.inherited_data_->word_spacing_
        && inherited_data_->internal_visited_color_ == o.inherited_data_->internal_visited_color_
        && inherited_data_->horizontal_border_spacing_ == o.inherited_data_->horizontal_border_spacing_
        && inherited_data_->vertical_border_spacing_ == o.inherited_data_->vertical_border_spacing_
        && inherited_data_->color_is_current_color_ == o.inherited_data_->color_is_current_color_
        && inherited_data_->in_forced_colors_mode_ == o.inherited_data_->in_forced_colors_mode_
        && inherited_data_->internal_visited_color_is_current_color_ == o.inherited_data_->internal_visited_color_is_current_color_
        ))
        && base::ValuesEquivalent(svginherited_data_, o.svginherited_data_)
        && data_.text_align_ == o.data_.text_align_
        && data_.writing_mode_ == o.data_.writing_mode_
        && data_.caret_shape_ == o.data_.caret_shape_
        && data_.inside_link_ == o.data_.inside_link_
        && data_.text_wrap_style_ == o.data_.text_wrap_style_
        && data_.white_space_collapse_ == o.data_.white_space_collapse_
        && data_.caret_animation_ == o.data_.caret_animation_
        && data_.direction_ == o.data_.direction_
        && data_.prefers_default_scrollbar_styles_ == o.data_.prefers_default_scrollbar_styles_
        && data_.print_color_adjust_ == o.data_.print_color_adjust_
        && data_.text_wrap_mode_ == o.data_.text_wrap_mode_

    );
  }

  inline bool InheritedVariablesEqual(const ComputedStyleBase& o) const {
    return (
        (inherited_data_.Get() == o.inherited_data_.Get()
        || (inherited_data_->inherited_variables_ == o.inherited_data_->inherited_variables_
        ))

    );
  }

  inline bool InheritedEqual(const ComputedStyleBase& o) const {
    return IndependentInheritedEqual(o) && NonIndependentInheritedEqual(o);
  }

  inline bool NonInheritedEqual(const ComputedStyleBase& o) const {
    return (
        base::ValuesEquivalent(misc_data_, o.misc_data_)
        && base::ValuesEquivalent(visual_data_, o.visual_data_)
        && base::ValuesEquivalent(box_data_, o.box_data_)
        && base::ValuesEquivalent(svg_data_, o.svg_data_)
        && base::ValuesEquivalent(surround_data_, o.surround_data_)
        && base::ValuesEquivalent(background_data_, o.background_data_)
        && data_.display_ == o.data_.display_
        && data_.vertical_align_ == o.data_.vertical_align_
        && data_.clear_ == o.data_.clear_
        && data_.floating_ == o.data_.floating_
        && data_.overflow_x_ == o.data_.overflow_x_
        && data_.overflow_y_ == o.data_.overflow_y_
        && data_.position_ == o.data_.position_
        && data_.transform_box_ == o.data_.transform_box_
        && data_.unicode_bidi_ == o.data_.unicode_bidi_
        && data_.content_visibility_ == o.data_.content_visibility_
        && data_.inline_block_baseline_edge_ == o.data_.inline_block_baseline_edge_
        && IsStackingContextWithoutContainment() == o.IsStackingContextWithoutContainment()
        && data_.overflow_anchor_ == o.data_.overflow_anchor_
        && data_.scroll_snap_stop_ == o.data_.scroll_snap_stop_
        && data_.viewport_unit_flags_ == o.data_.viewport_unit_flags_
        && data_.allows_z_index_ == o.data_.allows_z_index_
        && data_.box_direction_ == o.data_.box_direction_
        && data_.box_sizing_ == o.data_.box_sizing_
        && data_.forces_stacking_context_ == o.data_.forces_stacking_context_
        && data_.has_author_background_ == o.data_.has_author_background_
        && data_.has_author_border_ == o.data_.has_author_border_
        && data_.has_author_border_radius_ == o.data_.has_author_border_radius_
        && data_.has_author_highlight_colors_ == o.data_.has_author_highlight_colors_
        && data_.has_explicit_inheritance_ == o.data_.has_explicit_inheritance_
        && data_.is_original_display_inline_type_ == o.data_.is_original_display_inline_type_
        && data_.is_page_margin_box_ == o.data_.is_page_margin_box_
        && data_.origin_trial_test_property_ == o.data_.origin_trial_test_property_
        && data_.should_ignore_overflow_property_for_inline_block_baseline_ == o.data_.should_ignore_overflow_property_for_inline_block_baseline_
        && data_.skips_contents_ == o.data_.skips_contents_
        && data_.table_layout_ == o.data_.table_layout_

    );
  }

  inline bool HighlightOriginatingElementDataEqual(const ComputedStyleBase& o) const {
    return (
        (misc_inherited_data_.Get() == o.misc_inherited_data_.Get()
        || (misc_inherited_data_->forced_color_adjust_ == o.misc_inherited_data_->forced_color_adjust_
        ))
        && (misc_data_.Get() == o.misc_data_.Get()
        || ((misc_data_->misc_8_data_.Get() == o.misc_data_->misc_8_data_.Get()
        || (misc_data_->misc_8_data_->non_inherited_variables_ == o.misc_data_->misc_8_data_->non_inherited_variables_
        ))
        ))
        && (inherited_data_.Get() == o.inherited_data_.Get()
        || (base::ValuesEquivalent(inherited_data_->font_, o.inherited_data_->font_)
        && inherited_data_->inherited_variables_ == o.inherited_data_->inherited_variables_
        && inherited_data_->line_height_ == o.inherited_data_->line_height_
        && inherited_data_->in_forced_colors_mode_ == o.inherited_data_->in_forced_colors_mode_
        ))
        && data_.writing_mode_ == o.data_.writing_mode_

    );
  }

  inline bool NonHighlightOriginatingElementDataEqual(const ComputedStyleBase& o) const {
    return (
        (misc_inherited_data_.Get() == o.misc_inherited_data_.Get()
        || (base::ValuesEquivalent(misc_inherited_data_->misc_inherited_1_data_, o.misc_inherited_data_->misc_inherited_1_data_)
        && base::ValuesEquivalent(misc_inherited_data_->misc_inherited_2_data_, o.misc_inherited_data_->misc_inherited_2_data_)
        && misc_inherited_data_->text_box_edge_ == o.misc_inherited_data_->text_box_edge_
        && misc_inherited_data_->text_underline_position_ == o.misc_inherited_data_->text_underline_position_
        && misc_inherited_data_->hanging_punctuation_ == o.misc_inherited_data_->hanging_punctuation_
        && misc_inherited_data_->line_break_ == o.misc_inherited_data_->line_break_
        && misc_inherited_data_->speak_ == o.misc_inherited_data_->speak_
        && misc_inherited_data_->text_align_last_ == o.misc_inherited_data_->text_align_last_
        && misc_inherited_data_->text_decoration_skip_spaces_ == o.misc_inherited_data_->text_decoration_skip_spaces_
        && misc_inherited_data_->text_emphasis_mark_ == o.misc_inherited_data_->text_emphasis_mark_
        && misc_inherited_data_->text_emphasis_position_ == o.misc_inherited_data_->text_emphasis_position_
        && misc_inherited_data_->block_ellipsis_ == o.misc_inherited_data_->block_ellipsis_
        && misc_inherited_data_->user_select_ == o.misc_inherited_data_->user_select_
        && misc_inherited_data_->word_break_ == o.misc_inherited_data_->word_break_
        && misc_inherited_data_->draggable_region_mode_ == o.misc_inherited_data_->draggable_region_mode_
        && misc_inherited_data_->hyphens_ == o.misc_inherited_data_->hyphens_
        && misc_inherited_data_->image_animation_ == o.misc_inherited_data_->image_animation_
        && misc_inherited_data_->image_rendering_ == o.misc_inherited_data_->image_rendering_
        && misc_inherited_data_->overflow_wrap_ == o.misc_inherited_data_->overflow_wrap_
        && misc_inherited_data_->ruby_align_ == o.misc_inherited_data_->ruby_align_
        && misc_inherited_data_->ruby_overhang_ == o.misc_inherited_data_->ruby_overhang_
        && misc_inherited_data_->text_decoration_skip_ink_ == o.misc_inherited_data_->text_decoration_skip_ink_
        && misc_inherited_data_->text_indent_flags_ == o.misc_inherited_data_->text_indent_flags_
        && misc_inherited_data_->text_justify_ == o.misc_inherited_data_->text_justify_
        && misc_inherited_data_->text_orientation_ == o.misc_inherited_data_->text_orientation_
        && misc_inherited_data_->text_security_ == o.misc_inherited_data_->text_security_
        && misc_inherited_data_->user_modify_ == o.misc_inherited_data_->user_modify_
        && misc_inherited_data_->empty_cells_ == o.misc_inherited_data_->empty_cells_
        && misc_inherited_data_->has_line_if_empty_ == o.misc_inherited_data_->has_line_if_empty_
        && misc_inherited_data_->image_orientation_ == o.misc_inherited_data_->image_orientation_
        && misc_inherited_data_->in_base_appearance_ == o.misc_inherited_data_->in_base_appearance_
        && misc_inherited_data_->interactivity_ == o.misc_inherited_data_->interactivity_
        && misc_inherited_data_->interpolate_size_ == o.misc_inherited_data_->interpolate_size_
        && misc_inherited_data_->is_in_shrink_to_fit_subtree_ == o.misc_inherited_data_->is_in_shrink_to_fit_subtree_
        && misc_inherited_data_->math_shift_ == o.misc_inherited_data_->math_shift_
        && misc_inherited_data_->math_style_ == o.misc_inherited_data_->math_style_
        && misc_inherited_data_->ruby_position_ == o.misc_inherited_data_->ruby_position_
        && misc_inherited_data_->subtree_is_sticky_ == o.misc_inherited_data_->subtree_is_sticky_
        && misc_inherited_data_->subtree_will_change_contents_ == o.misc_inherited_data_->subtree_will_change_contents_
        && misc_inherited_data_->text_autospace_ == o.misc_inherited_data_->text_autospace_
        && misc_inherited_data_->text_combine_ == o.misc_inherited_data_->text_combine_
        && misc_inherited_data_->text_emphasis_fill_ == o.misc_inherited_data_->text_emphasis_fill_
        ))
        && (misc_data_.Get() == o.misc_data_.Get()
        || (base::ValuesEquivalent(misc_data_->misc_1_data_, o.misc_data_->misc_1_data_)
        && base::ValuesEquivalent(misc_data_->visited_data_, o.misc_data_->visited_data_)
        && base::ValuesEquivalent(misc_data_->misc_2_data_, o.misc_data_->misc_2_data_)
        && base::ValuesEquivalent(misc_data_->misc_3_data_, o.misc_data_->misc_3_data_)
        && base::ValuesEquivalent(misc_data_->forced_colors_data_, o.misc_data_->forced_colors_data_)
        && base::ValuesEquivalent(misc_data_->misc_4_data_, o.misc_data_->misc_4_data_)
        && base::ValuesEquivalent(misc_data_->misc_5_data_, o.misc_data_->misc_5_data_)
        && base::ValuesEquivalent(misc_data_->misc_6_data_, o.misc_data_->misc_6_data_)
        && base::ValuesEquivalent(misc_data_->timeline_data_, o.misc_data_->timeline_data_)
        && base::ValuesEquivalent(misc_data_->misc_7_data_, o.misc_data_->misc_7_data_)
        && (misc_data_->misc_8_data_.Get() == o.misc_data_->misc_8_data_.Get()
        || (misc_data_->misc_8_data_->callback_selectors_ == o.misc_data_->misc_8_data_->callback_selectors_
        && base::ValuesEquivalent(misc_data_->misc_8_data_->document_rules_selectors_, o.misc_data_->misc_8_data_->document_rules_selectors_)
        && misc_data_->misc_8_data_->max_lines_ == o.misc_data_->misc_8_data_->max_lines_
        ))
        && base::ValuesEquivalent(misc_data_->math_data_, o.misc_data_->math_data_)
        && base::ValuesEquivalent(misc_data_->will_change_, o.misc_data_->will_change_)
        && misc_data_->appearance_ == o.misc_data_->appearance_
        && misc_data_->blend_mode_ == o.misc_data_->blend_mode_
        && misc_data_->contain_ == o.misc_data_->contain_
        && misc_data_->effective_appearance_ == o.misc_data_->effective_appearance_
        && misc_data_->break_after_ == o.misc_data_->break_after_
        && misc_data_->break_before_ == o.misc_data_->break_before_
        && misc_data_->container_type_ == o.misc_data_->container_type_
        && misc_data_->grid_auto_flow_ == o.misc_data_->grid_auto_flow_
        && misc_data_->margin_trim_ == o.misc_data_->margin_trim_
        && misc_data_->outline_style_ == o.misc_data_->outline_style_
        && misc_data_->scrollbar_gutter_ == o.misc_data_->scrollbar_gutter_
        && misc_data_->box_align_ == o.misc_data_->box_align_
        && misc_data_->object_fit_ == o.misc_data_->object_fit_
        && misc_data_->position_try_order_ == o.misc_data_->position_try_order_
        && misc_data_->position_visibility_ == o.misc_data_->position_visibility_
        && misc_data_->reading_flow_ == o.misc_data_->reading_flow_
        && misc_data_->affected_by_css_function_ == o.misc_data_->affected_by_css_function_
        && misc_data_->resize_ == o.misc_data_->resize_
        && misc_data_->text_decoration_style_ == o.misc_data_->text_decoration_style_
        && misc_data_->box_pack_ == o.misc_data_->box_pack_
        && misc_data_->break_inside_ == o.misc_data_->break_inside_
        && misc_data_->column_rule_break_ == o.misc_data_->column_rule_break_
        && misc_data_->column_rule_visibility_items_ == o.misc_data_->column_rule_visibility_items_
        && misc_data_->column_wrap_ == o.misc_data_->column_wrap_
        && misc_data_->continue_ == o.misc_data_->continue_
        && misc_data_->flex_direction_ == o.misc_data_->flex_direction_
        && misc_data_->overscroll_behavior_x_ == o.misc_data_->overscroll_behavior_x_
        && misc_data_->overscroll_behavior_y_ == o.misc_data_->overscroll_behavior_y_
        && misc_data_->overscroll_container_type_ == o.misc_data_->overscroll_container_type_
        && misc_data_->page_margin_safety_ == o.misc_data_->page_margin_safety_
        && misc_data_->page_orientation_ == o.misc_data_->page_orientation_
        && misc_data_->page_size_type_ == o.misc_data_->page_size_type_
        && misc_data_->row_rule_break_ == o.misc_data_->row_rule_break_
        && misc_data_->row_rule_visibility_items_ == o.misc_data_->row_rule_visibility_items_
        && misc_data_->scroll_behavior_ == o.misc_data_->scroll_behavior_
        && misc_data_->scrollbar_width_ == o.misc_data_->scrollbar_width_
        && misc_data_->user_drag_ == o.misc_data_->user_drag_
        && misc_data_->affected_by_functional_media_ == o.misc_data_->affected_by_functional_media_
        && misc_data_->affected_by_functional_navigation_ == o.misc_data_->affected_by_functional_navigation_
        && misc_data_->align_content_block_center_ == o.misc_data_->align_content_block_center_
        && misc_data_->backface_visibility_ == o.misc_data_->backface_visibility_
        && misc_data_->box_orient_ == o.misc_data_->box_orient_
        && misc_data_->can_affect_animations_ == o.misc_data_->can_affect_animations_
        && misc_data_->column_fill_ == o.misc_data_->column_fill_
        && misc_data_->column_span_ == o.misc_data_->column_span_
        && misc_data_->depends_on_anchored_container_queries_ == o.misc_data_->depends_on_anchored_container_queries_
        && misc_data_->depends_on_scroll_state_container_queries_ == o.misc_data_->depends_on_scroll_state_container_queries_
        && misc_data_->depends_on_size_container_queries_ == o.misc_data_->depends_on_size_container_queries_
        && misc_data_->depends_on_style_container_queries_ == o.misc_data_->depends_on_style_container_queries_
        && misc_data_->element_is_view_transition_participant_ == o.misc_data_->element_is_view_transition_participant_
        && misc_data_->first_line_depends_on_size_container_queries_ == o.misc_data_->first_line_depends_on_size_container_queries_
        && misc_data_->forces_blockifies_children_ == o.misc_data_->forces_blockifies_children_
        && misc_data_->grid_lanes_pack_ == o.misc_data_->grid_lanes_pack_
        && misc_data_->has_auto_column_count_ == o.misc_data_->has_auto_column_count_
        && misc_data_->has_auto_column_height_ == o.misc_data_->has_auto_column_height_
        && misc_data_->has_auto_column_width_ == o.misc_data_->has_auto_column_width_
        && misc_data_->has_current_backdrop_filter_animation_ == o.misc_data_->has_current_backdrop_filter_animation_
        && misc_data_->has_current_background_color_animation_ == o.misc_data_->has_current_background_color_animation_
        && misc_data_->has_current_clip_path_animation_ == o.misc_data_->has_current_clip_path_animation_
        && misc_data_->has_current_filter_animation_ == o.misc_data_->has_current_filter_animation_
        && misc_data_->has_current_opacity_animation_ == o.misc_data_->has_current_opacity_animation_
        && misc_data_->has_current_rotate_animation_ == o.misc_data_->has_current_rotate_animation_
        && misc_data_->has_current_scale_animation_ == o.misc_data_->has_current_scale_animation_
        && misc_data_->has_current_transform_animation_ == o.misc_data_->has_current_transform_animation_
        && misc_data_->has_current_translate_animation_ == o.misc_data_->has_current_translate_animation_
        && misc_data_->has_explicit_overflow_x_visible_ == o.misc_data_->has_explicit_overflow_x_visible_
        && misc_data_->has_explicit_overflow_y_visible_ == o.misc_data_->has_explicit_overflow_y_visible_
        && misc_data_->has_layout_containment_for_view_transition_scope_ == o.misc_data_->has_layout_containment_for_view_transition_scope_
        && misc_data_->has_size_containment_for_view_transition_scope_ == o.misc_data_->has_size_containment_for_view_transition_scope_
        && misc_data_->internal_overscroll_container_ == o.misc_data_->internal_overscroll_container_
        && misc_data_->internal_overscroll_position_ == o.misc_data_->internal_overscroll_position_
        && misc_data_->internal_unbounded_ == o.misc_data_->internal_unbounded_
        && misc_data_->is_bottom_relative_to_safe_area_inset_ == o.misc_data_->is_bottom_relative_to_safe_area_inset_
        && misc_data_->is_running_rotate_animation_on_compositor_ == o.misc_data_->is_running_rotate_animation_on_compositor_
        && misc_data_->is_running_scale_animation_on_compositor_ == o.misc_data_->is_running_scale_animation_on_compositor_
        && misc_data_->is_running_transform_animation_on_compositor_ == o.misc_data_->is_running_transform_animation_on_compositor_
        && misc_data_->is_running_translate_animation_on_compositor_ == o.misc_data_->is_running_translate_animation_on_compositor_
        && misc_data_->is_secondary_body_element_ == o.misc_data_->is_secondary_body_element_
        && misc_data_->is_specified_display_webkit_box_ == o.misc_data_->is_specified_display_webkit_box_
        && misc_data_->is_starting_style_ == o.misc_data_->is_starting_style_
        && misc_data_->isolation_ == o.misc_data_->isolation_
        && misc_data_->line_clamp_internal_block_ellipsis_ == o.misc_data_->line_clamp_internal_block_ellipsis_
        && misc_data_->max_content_sizing_ == o.misc_data_->max_content_sizing_
        && misc_data_->outline_style_is_auto_ == o.misc_data_->outline_style_is_auto_
        && misc_data_->overlay_ == o.misc_data_->overlay_
        && misc_data_->requires_accelerated_compositing_for_external_reasons_ == o.misc_data_->requires_accelerated_compositing_for_external_reasons_
        && misc_data_->rule_overlap_ == o.misc_data_->rule_overlap_
        && misc_data_->scroll_axis_lock_ == o.misc_data_->scroll_axis_lock_
        && misc_data_->scroll_initial_target_ == o.misc_data_->scroll_initial_target_
        && misc_data_->scroll_target_group_ == o.misc_data_->scroll_target_group_
        && misc_data_->transform_style_3d_ == o.misc_data_->transform_style_3d_
        && misc_data_->view_transition_scope_ == o.misc_data_->view_transition_scope_
        ))
        && (inherited_data_.Get() == o.inherited_data_.Get()
        || (base::ValuesEquivalent(inherited_data_->inherited_forced_colors_data_, o.inherited_data_->inherited_forced_colors_data_)
        && base::ValuesEquivalent(inherited_data_->inherited_visited_data_, o.inherited_data_->inherited_visited_data_)
        && base::ValuesEquivalent(inherited_data_->highlight_data_data_, o.inherited_data_->highlight_data_data_)
        && base::ValuesEquivalent(inherited_data_->container_font_, o.inherited_data_->container_font_)
        && inherited_data_->letter_spacing_ == o.inherited_data_->letter_spacing_
        && inherited_data_->word_spacing_ == o.inherited_data_->word_spacing_
        && inherited_data_->internal_visited_color_ == o.inherited_data_->internal_visited_color_
        && inherited_data_->color_ == o.inherited_data_->color_
        && inherited_data_->horizontal_border_spacing_ == o.inherited_data_->horizontal_border_spacing_
        && inherited_data_->vertical_border_spacing_ == o.inherited_data_->vertical_border_spacing_
        && inherited_data_->cursor_ == o.inherited_data_->cursor_
        && inherited_data_->text_transform_ == o.inherited_data_->text_transform_
        && inherited_data_->color_is_current_color_ == o.inherited_data_->color_is_current_color_
        && inherited_data_->internal_visited_color_is_current_color_ == o.inherited_data_->internal_visited_color_is_current_color_
        ))
        && base::ValuesEquivalent(visual_data_, o.visual_data_)
        && base::ValuesEquivalent(svginherited_data_, o.svginherited_data_)
        && base::ValuesEquivalent(box_data_, o.box_data_)
        && base::ValuesEquivalent(svg_data_, o.svg_data_)
        && base::ValuesEquivalent(surround_data_, o.surround_data_)
        && base::ValuesEquivalent(background_data_, o.background_data_)
        && data_.display_ == o.data_.display_
        && data_.vertical_align_ == o.data_.vertical_align_
        && data_.clear_ == o.data_.clear_
        && data_.floating_ == o.data_.floating_
        && data_.overflow_x_ == o.data_.overflow_x_
        && data_.overflow_y_ == o.data_.overflow_y_
        && data_.position_ == o.data_.position_
        && data_.transform_box_ == o.data_.transform_box_
        && data_.unicode_bidi_ == o.data_.unicode_bidi_
        && data_.content_visibility_ == o.data_.content_visibility_
        && data_.inline_block_baseline_edge_ == o.data_.inline_block_baseline_edge_
        && IsStackingContextWithoutContainment() == o.IsStackingContextWithoutContainment()
        && data_.overflow_anchor_ == o.data_.overflow_anchor_
        && data_.scroll_snap_stop_ == o.data_.scroll_snap_stop_
        && data_.viewport_unit_flags_ == o.data_.viewport_unit_flags_
        && data_.allows_z_index_ == o.data_.allows_z_index_
        && data_.box_direction_ == o.data_.box_direction_
        && data_.box_sizing_ == o.data_.box_sizing_
        && data_.forces_stacking_context_ == o.data_.forces_stacking_context_
        && data_.has_author_background_ == o.data_.has_author_background_
        && data_.has_author_border_ == o.data_.has_author_border_
        && data_.has_author_border_radius_ == o.data_.has_author_border_radius_
        && data_.has_author_highlight_colors_ == o.data_.has_author_highlight_colors_
        && data_.has_explicit_inheritance_ == o.data_.has_explicit_inheritance_
        && data_.is_original_display_inline_type_ == o.data_.is_original_display_inline_type_
        && data_.is_page_margin_box_ == o.data_.is_page_margin_box_
        && data_.origin_trial_test_property_ == o.data_.origin_trial_test_property_
        && data_.should_ignore_overflow_property_for_inline_block_baseline_ == o.data_.should_ignore_overflow_property_for_inline_block_baseline_
        && data_.skips_contents_ == o.data_.skips_contents_
        && data_.table_layout_ == o.data_.table_layout_
        && data_.pointer_events_ == o.data_.pointer_events_
        && data_.text_align_ == o.data_.text_align_
        && data_.caret_shape_ == o.data_.caret_shape_
        && data_.inside_link_ == o.data_.inside_link_
        && data_.text_wrap_style_ == o.data_.text_wrap_style_
        && data_.visibility_ == o.data_.visibility_
        && data_.white_space_collapse_ == o.data_.white_space_collapse_
        && data_.border_collapse_ == o.data_.border_collapse_
        && data_.caption_side_ == o.data_.caption_side_
        && data_.caret_animation_ == o.data_.caret_animation_
        && data_.direction_ == o.data_.direction_
        && data_.is_css_inert_ == o.data_.is_css_inert_
        && data_.is_html_inert_ == o.data_.is_html_inert_
        && data_.list_style_position_ == o.data_.list_style_position_
        && data_.prefers_default_scrollbar_styles_ == o.data_.prefers_default_scrollbar_styles_
        && data_.print_color_adjust_ == o.data_.print_color_adjust_
        && data_.rtl_ordering_ == o.data_.rtl_ordering_
        && data_.text_wrap_mode_ == o.data_.text_wrap_mode_

    );
  }

  // Equivalent to InheritedEqual() && InheritedVariablesEqual(),
  // but in one call and a bit faster.
  inline bool InheritedEqualIncludingInheritedVariables(const ComputedStyleBase& o) const {
    return (
        base::ValuesEquivalent(misc_inherited_data_, o.misc_inherited_data_)
        && base::ValuesEquivalent(inherited_data_, o.inherited_data_)
        && base::ValuesEquivalent(svginherited_data_, o.svginherited_data_)
        && data_.pointer_events_ == o.data_.pointer_events_
        && data_.text_align_ == o.data_.text_align_
        && data_.writing_mode_ == o.data_.writing_mode_
        && data_.caret_shape_ == o.data_.caret_shape_
        && data_.inside_link_ == o.data_.inside_link_
        && data_.text_wrap_style_ == o.data_.text_wrap_style_
        && data_.visibility_ == o.data_.visibility_
        && data_.white_space_collapse_ == o.data_.white_space_collapse_
        && data_.border_collapse_ == o.data_.border_collapse_
        && data_.caption_side_ == o.data_.caption_side_
        && data_.caret_animation_ == o.data_.caret_animation_
        && data_.direction_ == o.data_.direction_
        && data_.is_css_inert_ == o.data_.is_css_inert_
        && data_.is_html_inert_ == o.data_.is_html_inert_
        && data_.list_style_position_ == o.data_.list_style_position_
        && data_.prefers_default_scrollbar_styles_ == o.data_.prefers_default_scrollbar_styles_
        && data_.print_color_adjust_ == o.data_.print_color_adjust_
        && data_.rtl_ordering_ == o.data_.rtl_ordering_
        && data_.text_wrap_mode_ == o.data_.text_wrap_mode_

    );
  }

  inline InheritedPropertyHash FirstDifferingInheritedProperty(const ComputedStyleBase& o) const {
    if (misc_inherited_data_.Get() != o.misc_inherited_data_.Get()) {
          if (!misc_inherited_data_ || !o.misc_inherited_data_) {
            return InheritedPropertyHash::kmisc_inherited_data_;
          }
          if (misc_inherited_data_->misc_inherited_1_data_.Get() != o.misc_inherited_data_->misc_inherited_1_data_.Get()) {
                if (!misc_inherited_data_->misc_inherited_1_data_ || !o.misc_inherited_data_->misc_inherited_1_data_) {
                  return InheritedPropertyHash::kmisc_inherited_1_data_;
                }
                if (!(misc_inherited_data_->misc_inherited_1_data_->hyphenation_string_ == o.misc_inherited_data_->misc_inherited_1_data_->hyphenation_string_)) {
                    return InheritedPropertyHash::khyphenation_string_;
                  }
                if (!(misc_inherited_data_->misc_inherited_1_data_->color_scheme_ == o.misc_inherited_data_->misc_inherited_1_data_->color_scheme_)) {
                    return InheritedPropertyHash::kcolor_scheme_;
                  }
                if (!(base::ValuesEquivalent(misc_inherited_data_->misc_inherited_1_data_->quotes_, o.misc_inherited_data_->misc_inherited_1_data_->quotes_))) {
                    return InheritedPropertyHash::kquotes_;
                  }
                if (!(base::ValuesEquivalent(misc_inherited_data_->misc_inherited_1_data_->list_style_image_, o.misc_inherited_data_->misc_inherited_1_data_->list_style_image_))) {
                    return InheritedPropertyHash::klist_style_image_;
                  }
                if (!(base::ValuesEquivalent(misc_inherited_data_->misc_inherited_1_data_->list_style_type_, o.misc_inherited_data_->misc_inherited_1_data_->list_style_type_))) {
                    return InheritedPropertyHash::klist_style_type_;
                  }
                if (!(base::ValuesEquivalent(misc_inherited_data_->misc_inherited_1_data_->scrollbar_color_, o.misc_inherited_data_->misc_inherited_1_data_->scrollbar_color_))) {
                    return InheritedPropertyHash::kscrollbar_color_;
                  }
                if (!(misc_inherited_data_->misc_inherited_1_data_->dynamic_range_limit_ == o.misc_inherited_data_->misc_inherited_1_data_->dynamic_range_limit_)) {
                    return InheritedPropertyHash::kdynamic_range_limit_;
                  }
                if (!(misc_inherited_data_->misc_inherited_1_data_->tab_size_ == o.misc_inherited_data_->misc_inherited_1_data_->tab_size_)) {
                    return InheritedPropertyHash::ktab_size_;
                  }
                if (!(misc_inherited_data_->misc_inherited_1_data_->text_fit_ == o.misc_inherited_data_->misc_inherited_1_data_->text_fit_)) {
                    return InheritedPropertyHash::ktext_fit_;
                  }
                if (!(misc_inherited_data_->misc_inherited_1_data_->text_size_adjust_ == o.misc_inherited_data_->misc_inherited_1_data_->text_size_adjust_)) {
                    return InheritedPropertyHash::ktext_size_adjust_;
                  }
                if (!(misc_inherited_data_->misc_inherited_1_data_->accent_color_ == o.misc_inherited_data_->misc_inherited_1_data_->accent_color_)) {
                    return InheritedPropertyHash::kaccent_color_;
                  }
                if (!(misc_inherited_data_->misc_inherited_1_data_->caret_color_ == o.misc_inherited_data_->misc_inherited_1_data_->caret_color_)) {
                    return InheritedPropertyHash::kcaret_color_;
                  }
                if (!(misc_inherited_data_->misc_inherited_1_data_->text_emphasis_color_ == o.misc_inherited_data_->misc_inherited_1_data_->text_emphasis_color_)) {
                    return InheritedPropertyHash::ktext_emphasis_color_;
                  }
                if (!(misc_inherited_data_->misc_inherited_1_data_->math_depth_ == o.misc_inherited_data_->misc_inherited_1_data_->math_depth_)) {
                    return InheritedPropertyHash::kmath_depth_;
                  }
                if (!(misc_inherited_data_->misc_inherited_1_data_->orphans_ == o.misc_inherited_data_->misc_inherited_1_data_->orphans_)) {
                    return InheritedPropertyHash::korphans_;
                  }
                if (!(misc_inherited_data_->misc_inherited_1_data_->hyphenate_limit_chars_ == o.misc_inherited_data_->misc_inherited_1_data_->hyphenate_limit_chars_)) {
                    return InheritedPropertyHash::khyphenate_limit_chars_;
                  }

              }
          if (misc_inherited_data_->misc_inherited_2_data_.Get() != o.misc_inherited_data_->misc_inherited_2_data_.Get()) {
                if (!misc_inherited_data_->misc_inherited_2_data_ || !o.misc_inherited_data_->misc_inherited_2_data_) {
                  return InheritedPropertyHash::kmisc_inherited_2_data_;
                }
                if (!(misc_inherited_data_->misc_inherited_2_data_->text_emphasis_custom_mark_ == o.misc_inherited_data_->misc_inherited_2_data_->text_emphasis_custom_mark_)) {
                    return InheritedPropertyHash::ktext_emphasis_custom_mark_;
                  }
                if (!(base::ValuesEquivalent(misc_inherited_data_->misc_inherited_2_data_->ua_shadow_host_data_, o.misc_inherited_data_->misc_inherited_2_data_->ua_shadow_host_data_))) {
                    return InheritedPropertyHash::kua_shadow_host_data_;
                  }
                if (!(base::ValuesEquivalent(misc_inherited_data_->misc_inherited_2_data_->text_shadow_, o.misc_inherited_data_->misc_inherited_2_data_->text_shadow_))) {
                    return InheritedPropertyHash::ktext_shadow_;
                  }
                if (!(base::ValuesEquivalent(misc_inherited_data_->misc_inherited_2_data_->cursor_data_, o.misc_inherited_data_->misc_inherited_2_data_->cursor_data_))) {
                    return InheritedPropertyHash::kcursor_data_;
                  }
                if (!(base::ValuesEquivalent(misc_inherited_data_->misc_inherited_2_data_->initial_data_, o.misc_inherited_data_->misc_inherited_2_data_->initial_data_))) {
                    return InheritedPropertyHash::kinitial_data_;
                  }
                if (!(misc_inherited_data_->misc_inherited_2_data_->text_indent_ == o.misc_inherited_data_->misc_inherited_2_data_->text_indent_)) {
                    return InheritedPropertyHash::ktext_indent_;
                  }
                if (!(misc_inherited_data_->misc_inherited_2_data_->text_underline_offset_ == o.misc_inherited_data_->misc_inherited_2_data_->text_underline_offset_)) {
                    return InheritedPropertyHash::ktext_underline_offset_;
                  }
                if (!(misc_inherited_data_->misc_inherited_2_data_->text_stroke_width_ == o.misc_inherited_data_->misc_inherited_2_data_->text_stroke_width_)) {
                    return InheritedPropertyHash::ktext_stroke_width_;
                  }
                if (!(misc_inherited_data_->misc_inherited_2_data_->effective_zoom_ == o.misc_inherited_data_->misc_inherited_2_data_->effective_zoom_)) {
                    return InheritedPropertyHash::keffective_zoom_;
                  }
                if (!(misc_inherited_data_->misc_inherited_2_data_->tap_highlight_color_ == o.misc_inherited_data_->misc_inherited_2_data_->tap_highlight_color_)) {
                    return InheritedPropertyHash::ktap_highlight_color_;
                  }
                if (!(misc_inherited_data_->misc_inherited_2_data_->text_fill_color_ == o.misc_inherited_data_->misc_inherited_2_data_->text_fill_color_)) {
                    return InheritedPropertyHash::ktext_fill_color_;
                  }
                if (!(misc_inherited_data_->misc_inherited_2_data_->text_stroke_color_ == o.misc_inherited_data_->misc_inherited_2_data_->text_stroke_color_)) {
                    return InheritedPropertyHash::ktext_stroke_color_;
                  }
                if (!(misc_inherited_data_->misc_inherited_2_data_->widows_ == o.misc_inherited_data_->misc_inherited_2_data_->widows_)) {
                    return InheritedPropertyHash::kwidows_;
                  }
                if (!(misc_inherited_data_->misc_inherited_2_data_->effective_touch_action_ == o.misc_inherited_data_->misc_inherited_2_data_->effective_touch_action_)) {
                    return InheritedPropertyHash::keffective_touch_action_;
                  }

              }
          if (!(misc_inherited_data_->text_box_edge_ == o.misc_inherited_data_->text_box_edge_)) {
              return InheritedPropertyHash::ktext_box_edge_;
            }
          if (!(misc_inherited_data_->text_underline_position_ == o.misc_inherited_data_->text_underline_position_)) {
              return InheritedPropertyHash::ktext_underline_position_;
            }
          if (!(misc_inherited_data_->hanging_punctuation_ == o.misc_inherited_data_->hanging_punctuation_)) {
              return InheritedPropertyHash::khanging_punctuation_;
            }
          if (!(misc_inherited_data_->line_break_ == o.misc_inherited_data_->line_break_)) {
              return InheritedPropertyHash::kline_break_;
            }
          if (!(misc_inherited_data_->speak_ == o.misc_inherited_data_->speak_)) {
              return InheritedPropertyHash::kspeak_;
            }
          if (!(misc_inherited_data_->text_align_last_ == o.misc_inherited_data_->text_align_last_)) {
              return InheritedPropertyHash::ktext_align_last_;
            }
          if (!(misc_inherited_data_->text_decoration_skip_spaces_ == o.misc_inherited_data_->text_decoration_skip_spaces_)) {
              return InheritedPropertyHash::ktext_decoration_skip_spaces_;
            }
          if (!(misc_inherited_data_->text_emphasis_mark_ == o.misc_inherited_data_->text_emphasis_mark_)) {
              return InheritedPropertyHash::ktext_emphasis_mark_;
            }
          if (!(misc_inherited_data_->text_emphasis_position_ == o.misc_inherited_data_->text_emphasis_position_)) {
              return InheritedPropertyHash::ktext_emphasis_position_;
            }
          if (!(misc_inherited_data_->block_ellipsis_ == o.misc_inherited_data_->block_ellipsis_)) {
              return InheritedPropertyHash::kblock_ellipsis_;
            }
          if (!(misc_inherited_data_->user_select_ == o.misc_inherited_data_->user_select_)) {
              return InheritedPropertyHash::kuser_select_;
            }
          if (!(misc_inherited_data_->word_break_ == o.misc_inherited_data_->word_break_)) {
              return InheritedPropertyHash::kword_break_;
            }
          if (!(misc_inherited_data_->draggable_region_mode_ == o.misc_inherited_data_->draggable_region_mode_)) {
              return InheritedPropertyHash::kdraggable_region_mode_;
            }
          if (!(misc_inherited_data_->forced_color_adjust_ == o.misc_inherited_data_->forced_color_adjust_)) {
              return InheritedPropertyHash::kforced_color_adjust_;
            }
          if (!(misc_inherited_data_->hyphens_ == o.misc_inherited_data_->hyphens_)) {
              return InheritedPropertyHash::khyphens_;
            }
          if (!(misc_inherited_data_->image_animation_ == o.misc_inherited_data_->image_animation_)) {
              return InheritedPropertyHash::kimage_animation_;
            }
          if (!(misc_inherited_data_->image_rendering_ == o.misc_inherited_data_->image_rendering_)) {
              return InheritedPropertyHash::kimage_rendering_;
            }
          if (!(misc_inherited_data_->overflow_wrap_ == o.misc_inherited_data_->overflow_wrap_)) {
              return InheritedPropertyHash::koverflow_wrap_;
            }
          if (!(misc_inherited_data_->ruby_align_ == o.misc_inherited_data_->ruby_align_)) {
              return InheritedPropertyHash::kruby_align_;
            }
          if (!(misc_inherited_data_->ruby_overhang_ == o.misc_inherited_data_->ruby_overhang_)) {
              return InheritedPropertyHash::kruby_overhang_;
            }
          if (!(misc_inherited_data_->text_decoration_skip_ink_ == o.misc_inherited_data_->text_decoration_skip_ink_)) {
              return InheritedPropertyHash::ktext_decoration_skip_ink_;
            }
          if (!(misc_inherited_data_->text_indent_flags_ == o.misc_inherited_data_->text_indent_flags_)) {
              return InheritedPropertyHash::ktext_indent_flags_;
            }
          if (!(misc_inherited_data_->text_justify_ == o.misc_inherited_data_->text_justify_)) {
              return InheritedPropertyHash::ktext_justify_;
            }
          if (!(misc_inherited_data_->text_orientation_ == o.misc_inherited_data_->text_orientation_)) {
              return InheritedPropertyHash::ktext_orientation_;
            }
          if (!(misc_inherited_data_->text_security_ == o.misc_inherited_data_->text_security_)) {
              return InheritedPropertyHash::ktext_security_;
            }
          if (!(misc_inherited_data_->user_modify_ == o.misc_inherited_data_->user_modify_)) {
              return InheritedPropertyHash::kuser_modify_;
            }
          if (!(misc_inherited_data_->empty_cells_ == o.misc_inherited_data_->empty_cells_)) {
              return InheritedPropertyHash::kempty_cells_;
            }
          if (!(misc_inherited_data_->has_line_if_empty_ == o.misc_inherited_data_->has_line_if_empty_)) {
              return InheritedPropertyHash::khas_line_if_empty_;
            }
          if (!(misc_inherited_data_->image_orientation_ == o.misc_inherited_data_->image_orientation_)) {
              return InheritedPropertyHash::kimage_orientation_;
            }
          if (!(misc_inherited_data_->in_base_appearance_ == o.misc_inherited_data_->in_base_appearance_)) {
              return InheritedPropertyHash::kin_base_appearance_;
            }
          if (!(misc_inherited_data_->interactivity_ == o.misc_inherited_data_->interactivity_)) {
              return InheritedPropertyHash::kinteractivity_;
            }
          if (!(misc_inherited_data_->interpolate_size_ == o.misc_inherited_data_->interpolate_size_)) {
              return InheritedPropertyHash::kinterpolate_size_;
            }
          if (!(misc_inherited_data_->is_in_shrink_to_fit_subtree_ == o.misc_inherited_data_->is_in_shrink_to_fit_subtree_)) {
              return InheritedPropertyHash::kis_in_shrink_to_fit_subtree_;
            }
          if (!(misc_inherited_data_->math_shift_ == o.misc_inherited_data_->math_shift_)) {
              return InheritedPropertyHash::kmath_shift_;
            }
          if (!(misc_inherited_data_->math_style_ == o.misc_inherited_data_->math_style_)) {
              return InheritedPropertyHash::kmath_style_;
            }
          if (!(misc_inherited_data_->ruby_position_ == o.misc_inherited_data_->ruby_position_)) {
              return InheritedPropertyHash::kruby_position_;
            }
          if (!(misc_inherited_data_->subtree_is_sticky_ == o.misc_inherited_data_->subtree_is_sticky_)) {
              return InheritedPropertyHash::ksubtree_is_sticky_;
            }
          if (!(misc_inherited_data_->subtree_will_change_contents_ == o.misc_inherited_data_->subtree_will_change_contents_)) {
              return InheritedPropertyHash::ksubtree_will_change_contents_;
            }
          if (!(misc_inherited_data_->text_autospace_ == o.misc_inherited_data_->text_autospace_)) {
              return InheritedPropertyHash::ktext_autospace_;
            }
          if (!(misc_inherited_data_->text_combine_ == o.misc_inherited_data_->text_combine_)) {
              return InheritedPropertyHash::ktext_combine_;
            }
          if (!(misc_inherited_data_->text_emphasis_fill_ == o.misc_inherited_data_->text_emphasis_fill_)) {
              return InheritedPropertyHash::ktext_emphasis_fill_;
            }

        }
    if (inherited_data_.Get() != o.inherited_data_.Get()) {
          if (!inherited_data_ || !o.inherited_data_) {
            return InheritedPropertyHash::kinherited_data_;
          }
          if (inherited_data_->inherited_forced_colors_data_.Get() != o.inherited_data_->inherited_forced_colors_data_.Get()) {
                if (!inherited_data_->inherited_forced_colors_data_ || !o.inherited_data_->inherited_forced_colors_data_) {
                  return InheritedPropertyHash::kinherited_forced_colors_data_;
                }
                if (!(inherited_data_->inherited_forced_colors_data_->internal_forced_visited_color_ == o.inherited_data_->inherited_forced_colors_data_->internal_forced_visited_color_)) {
                    return InheritedPropertyHash::kinternal_forced_visited_color_;
                  }
                if (!(inherited_data_->inherited_forced_colors_data_->internal_forced_color_ == o.inherited_data_->inherited_forced_colors_data_->internal_forced_color_)) {
                    return InheritedPropertyHash::kinternal_forced_color_;
                  }

              }
          if (inherited_data_->inherited_visited_data_.Get() != o.inherited_data_->inherited_visited_data_.Get()) {
                if (!inherited_data_->inherited_visited_data_ || !o.inherited_data_->inherited_visited_data_) {
                  return InheritedPropertyHash::kinherited_visited_data_;
                }
                if (!(inherited_data_->inherited_visited_data_->internal_visited_caret_color_ == o.inherited_data_->inherited_visited_data_->internal_visited_caret_color_)) {
                    return InheritedPropertyHash::kinternal_visited_caret_color_;
                  }
                if (!(inherited_data_->inherited_visited_data_->internal_visited_text_emphasis_color_ == o.inherited_data_->inherited_visited_data_->internal_visited_text_emphasis_color_)) {
                    return InheritedPropertyHash::kinternal_visited_text_emphasis_color_;
                  }
                if (!(inherited_data_->inherited_visited_data_->internal_visited_text_fill_color_ == o.inherited_data_->inherited_visited_data_->internal_visited_text_fill_color_)) {
                    return InheritedPropertyHash::kinternal_visited_text_fill_color_;
                  }
                if (!(inherited_data_->inherited_visited_data_->internal_visited_text_stroke_color_ == o.inherited_data_->inherited_visited_data_->internal_visited_text_stroke_color_)) {
                    return InheritedPropertyHash::kinternal_visited_text_stroke_color_;
                  }

              }
          if (inherited_data_->highlight_data_data_.Get() != o.inherited_data_->highlight_data_data_.Get()) {
                if (!inherited_data_->highlight_data_data_ || !o.inherited_data_->highlight_data_data_) {
                  return InheritedPropertyHash::khighlight_data_data_;
                }
                if (!(inherited_data_->highlight_data_data_->highlight_data_ == o.inherited_data_->highlight_data_data_->highlight_data_)) {
                    return InheritedPropertyHash::khighlight_data_;
                  }

              }
          if (!(base::ValuesEquivalent(inherited_data_->font_, o.inherited_data_->font_))) {
              return InheritedPropertyHash::kfont_;
            }
          if (!(base::ValuesEquivalent(inherited_data_->container_font_, o.inherited_data_->container_font_))) {
              return InheritedPropertyHash::kcontainer_font_;
            }
          if (!(inherited_data_->inherited_variables_ == o.inherited_data_->inherited_variables_)) {
              return InheritedPropertyHash::kinherited_variables_;
            }
          if (!(inherited_data_->letter_spacing_ == o.inherited_data_->letter_spacing_)) {
              return InheritedPropertyHash::kletter_spacing_;
            }
          if (!(inherited_data_->line_height_ == o.inherited_data_->line_height_)) {
              return InheritedPropertyHash::kline_height_;
            }
          if (!(inherited_data_->word_spacing_ == o.inherited_data_->word_spacing_)) {
              return InheritedPropertyHash::kword_spacing_;
            }
          if (!(inherited_data_->internal_visited_color_ == o.inherited_data_->internal_visited_color_)) {
              return InheritedPropertyHash::kinternal_visited_color_;
            }
          if (!(inherited_data_->color_ == o.inherited_data_->color_)) {
              return InheritedPropertyHash::kcolor_;
            }
          if (!(inherited_data_->horizontal_border_spacing_ == o.inherited_data_->horizontal_border_spacing_)) {
              return InheritedPropertyHash::khorizontal_border_spacing_;
            }
          if (!(inherited_data_->vertical_border_spacing_ == o.inherited_data_->vertical_border_spacing_)) {
              return InheritedPropertyHash::kvertical_border_spacing_;
            }
          if (!(inherited_data_->cursor_ == o.inherited_data_->cursor_)) {
              return InheritedPropertyHash::kcursor_;
            }
          if (!(inherited_data_->text_transform_ == o.inherited_data_->text_transform_)) {
              return InheritedPropertyHash::ktext_transform_;
            }
          if (!(inherited_data_->color_is_current_color_ == o.inherited_data_->color_is_current_color_)) {
              return InheritedPropertyHash::kcolor_is_current_color_;
            }
          if (!(inherited_data_->in_forced_colors_mode_ == o.inherited_data_->in_forced_colors_mode_)) {
              return InheritedPropertyHash::kin_forced_colors_mode_;
            }
          if (!(inherited_data_->internal_visited_color_is_current_color_ == o.inherited_data_->internal_visited_color_is_current_color_)) {
              return InheritedPropertyHash::kinternal_visited_color_is_current_color_;
            }

        }
    if (svginherited_data_.Get() != o.svginherited_data_.Get()) {
          if (!svginherited_data_ || !o.svginherited_data_) {
            return InheritedPropertyHash::ksvginherited_data_;
          }
          if (svginherited_data_->fill_data_.Get() != o.svginherited_data_->fill_data_.Get()) {
                if (!svginherited_data_->fill_data_ || !o.svginherited_data_->fill_data_) {
                  return InheritedPropertyHash::kfill_data_;
                }
                if (!(svginherited_data_->fill_data_->internal_visited_fill_paint_ == o.svginherited_data_->fill_data_->internal_visited_fill_paint_)) {
                    return InheritedPropertyHash::kinternal_visited_fill_paint_;
                  }
                if (!(svginherited_data_->fill_data_->fill_paint_ == o.svginherited_data_->fill_data_->fill_paint_)) {
                    return InheritedPropertyHash::kfill_paint_;
                  }
                if (!(svginherited_data_->fill_data_->fill_opacity_ == o.svginherited_data_->fill_data_->fill_opacity_)) {
                    return InheritedPropertyHash::kfill_opacity_;
                  }

              }
          if (svginherited_data_->stroke_data_.Get() != o.svginherited_data_->stroke_data_.Get()) {
                if (!svginherited_data_->stroke_data_ || !o.svginherited_data_->stroke_data_) {
                  return InheritedPropertyHash::kstroke_data_;
                }
                if (!(base::ValuesEquivalent(svginherited_data_->stroke_data_->stroke_dash_array_, o.svginherited_data_->stroke_data_->stroke_dash_array_))) {
                    return InheritedPropertyHash::kstroke_dash_array_;
                  }
                if (!(svginherited_data_->stroke_data_->internal_visited_stroke_paint_ == o.svginherited_data_->stroke_data_->internal_visited_stroke_paint_)) {
                    return InheritedPropertyHash::kinternal_visited_stroke_paint_;
                  }
                if (!(svginherited_data_->stroke_data_->stroke_paint_ == o.svginherited_data_->stroke_data_->stroke_paint_)) {
                    return InheritedPropertyHash::kstroke_paint_;
                  }
                if (!(svginherited_data_->stroke_data_->stroke_dash_offset_ == o.svginherited_data_->stroke_data_->stroke_dash_offset_)) {
                    return InheritedPropertyHash::kstroke_dash_offset_;
                  }
                if (!(svginherited_data_->stroke_data_->stroke_width_ == o.svginherited_data_->stroke_data_->stroke_width_)) {
                    return InheritedPropertyHash::kstroke_width_;
                  }
                if (!(svginherited_data_->stroke_data_->stroke_miter_limit_ == o.svginherited_data_->stroke_data_->stroke_miter_limit_)) {
                    return InheritedPropertyHash::kstroke_miter_limit_;
                  }
                if (!(svginherited_data_->stroke_data_->stroke_opacity_ == o.svginherited_data_->stroke_data_->stroke_opacity_)) {
                    return InheritedPropertyHash::kstroke_opacity_;
                  }
                if (!(svginherited_data_->stroke_data_->cap_style_ == o.svginherited_data_->stroke_data_->cap_style_)) {
                    return InheritedPropertyHash::kcap_style_;
                  }
                if (!(svginherited_data_->stroke_data_->join_style_ == o.svginherited_data_->stroke_data_->join_style_)) {
                    return InheritedPropertyHash::kjoin_style_;
                  }

              }
          if (svginherited_data_->resources_data_.Get() != o.svginherited_data_->resources_data_.Get()) {
                if (!svginherited_data_->resources_data_ || !o.svginherited_data_->resources_data_) {
                  return InheritedPropertyHash::kresources_data_;
                }
                if (!(base::ValuesEquivalent(svginherited_data_->resources_data_->marker_end_resource_, o.svginherited_data_->resources_data_->marker_end_resource_))) {
                    return InheritedPropertyHash::kmarker_end_resource_;
                  }
                if (!(base::ValuesEquivalent(svginherited_data_->resources_data_->marker_mid_resource_, o.svginherited_data_->resources_data_->marker_mid_resource_))) {
                    return InheritedPropertyHash::kmarker_mid_resource_;
                  }
                if (!(base::ValuesEquivalent(svginherited_data_->resources_data_->marker_start_resource_, o.svginherited_data_->resources_data_->marker_start_resource_))) {
                    return InheritedPropertyHash::kmarker_start_resource_;
                  }

              }
          if (!(svginherited_data_->css_dominant_baseline_ == o.svginherited_data_->css_dominant_baseline_)) {
              return InheritedPropertyHash::kcss_dominant_baseline_;
            }
          if (!(svginherited_data_->dominant_baseline_ == o.svginherited_data_->dominant_baseline_)) {
              return InheritedPropertyHash::kdominant_baseline_;
            }
          if (!(svginherited_data_->paint_order_ == o.svginherited_data_->paint_order_)) {
              return InheritedPropertyHash::kpaint_order_;
            }
          if (!(svginherited_data_->color_interpolation_ == o.svginherited_data_->color_interpolation_)) {
              return InheritedPropertyHash::kcolor_interpolation_;
            }
          if (!(svginherited_data_->color_interpolation_filters_ == o.svginherited_data_->color_interpolation_filters_)) {
              return InheritedPropertyHash::kcolor_interpolation_filters_;
            }
          if (!(svginherited_data_->color_rendering_ == o.svginherited_data_->color_rendering_)) {
              return InheritedPropertyHash::kcolor_rendering_;
            }
          if (!(svginherited_data_->shape_rendering_ == o.svginherited_data_->shape_rendering_)) {
              return InheritedPropertyHash::kshape_rendering_;
            }
          if (!(svginherited_data_->text_anchor_ == o.svginherited_data_->text_anchor_)) {
              return InheritedPropertyHash::ktext_anchor_;
            }
          if (!(svginherited_data_->clip_rule_ == o.svginherited_data_->clip_rule_)) {
              return InheritedPropertyHash::kclip_rule_;
            }
          if (!(svginherited_data_->fill_rule_ == o.svginherited_data_->fill_rule_)) {
              return InheritedPropertyHash::kfill_rule_;
            }

        }
    if (!(data_.pointer_events_ == o.data_.pointer_events_)) {
        return InheritedPropertyHash::kpointer_events_;
      }
    if (!(data_.text_align_ == o.data_.text_align_)) {
        return InheritedPropertyHash::ktext_align_;
      }
    if (!(data_.writing_mode_ == o.data_.writing_mode_)) {
        return InheritedPropertyHash::kwriting_mode_;
      }
    if (!(data_.caret_shape_ == o.data_.caret_shape_)) {
        return InheritedPropertyHash::kcaret_shape_;
      }
    if (!(data_.inside_link_ == o.data_.inside_link_)) {
        return InheritedPropertyHash::kinside_link_;
      }
    if (!(data_.text_wrap_style_ == o.data_.text_wrap_style_)) {
        return InheritedPropertyHash::ktext_wrap_style_;
      }
    if (!(data_.visibility_ == o.data_.visibility_)) {
        return InheritedPropertyHash::kvisibility_;
      }
    if (!(data_.white_space_collapse_ == o.data_.white_space_collapse_)) {
        return InheritedPropertyHash::kwhite_space_collapse_;
      }
    if (!(data_.border_collapse_ == o.data_.border_collapse_)) {
        return InheritedPropertyHash::kborder_collapse_;
      }
    if (!(data_.caption_side_ == o.data_.caption_side_)) {
        return InheritedPropertyHash::kcaption_side_;
      }
    if (!(data_.caret_animation_ == o.data_.caret_animation_)) {
        return InheritedPropertyHash::kcaret_animation_;
      }
    if (!(data_.direction_ == o.data_.direction_)) {
        return InheritedPropertyHash::kdirection_;
      }
    if (!(data_.is_css_inert_ == o.data_.is_css_inert_)) {
        return InheritedPropertyHash::kis_css_inert_;
      }
    if (!(data_.is_html_inert_ == o.data_.is_html_inert_)) {
        return InheritedPropertyHash::kis_html_inert_;
      }
    if (!(data_.list_style_position_ == o.data_.list_style_position_)) {
        return InheritedPropertyHash::klist_style_position_;
      }
    if (!(data_.prefers_default_scrollbar_styles_ == o.data_.prefers_default_scrollbar_styles_)) {
        return InheritedPropertyHash::kprefers_default_scrollbar_styles_;
      }
    if (!(data_.print_color_adjust_ == o.data_.print_color_adjust_)) {
        return InheritedPropertyHash::kprint_color_adjust_;
      }
    if (!(data_.rtl_ordering_ == o.data_.rtl_ordering_)) {
        return InheritedPropertyHash::krtl_ordering_;
      }
    if (!(data_.text_wrap_mode_ == o.data_.text_wrap_mode_)) {
        return InheritedPropertyHash::ktext_wrap_mode_;
      }

    return InheritedPropertyHash::kNone;
  }

  enum class NonInheritedPropertyHash : uint32_t {
    kNone = 0,
    kaffected_by_active_ = 3574343237U,
    kaffected_by_css_function_ = 3835502139U,
    kaffected_by_drag_ = 1127064150U,
    kaffected_by_focus_within_ = 1139448113U,
    kaffected_by_functional_media_ = 978793577U,
    kaffected_by_functional_navigation_ = 3153964381U,
    kaffected_by_hover_ = 4155318339U,
    kalign_content_ = 3453532761U,
    kalign_content_block_center_ = 3836860988U,
    kalign_items_ = 911876920U,
    kalign_self_ = 2052937692U,
    kalignment_baseline_ = 2594912250U,
    kallows_z_index_ = 2515860087U,
    kanchor_center_offset_ = 921098048U,
    kanchor_name_ = 1491193076U,
    kanchor_scope_ = 2550157682U,
    kanimations_ = 2937413235U,
    kappearance_ = 515650571U,
    kaspect_ratio_ = 3688435693U,
    kbackdrop_filter_ = 3406512082U,
    kbackface_visibility_ = 2075711349U,
    kbackground_ = 530765477U,
    kbackground_color_ = 3621896036U,
    kbase_data_ = 4092177705U,
    kbase_text_decoration_data_ = 442039487U,
    kbaseline_shift_ = 3303567014U,
    kbaseline_shift_type_ = 2460468551U,
    kbaseline_source_ = 2501914421U,
    kblend_mode_ = 2369914759U,
    kborder_bottom_color_ = 697362673U,
    kborder_bottom_left_radius_ = 235163635U,
    kborder_bottom_right_radius_ = 880448753U,
    kborder_bottom_style_ = 1003223998U,
    kborder_bottom_width_ = 1695235033U,
    kborder_collapse_is_inherited_ = 214731865U,
    kborder_image_ = 2903943576U,
    kborder_left_color_ = 1644675385U,
    kborder_left_style_ = 1279317217U,
    kborder_left_width_ = 2371347637U,
    kborder_right_color_ = 720749962U,
    kborder_right_style_ = 1119077224U,
    kborder_right_width_ = 950816335U,
    kborder_shape_ = 675299774U,
    kborder_top_color_ = 2114794659U,
    kborder_top_left_radius_ = 2421115270U,
    kborder_top_right_radius_ = 3985477859U,
    kborder_top_style_ = 1685767600U,
    kborder_top_width_ = 2973765445U,
    kbottom_ = 3438885078U,
    kbox_align_ = 2053801947U,
    kbox_decoration_break_ = 908869853U,
    kbox_direction_ = 1241368436U,
    kbox_flex_ = 53055017U,
    kbox_ordinal_group_ = 3175085771U,
    kbox_orient_ = 4256915373U,
    kbox_pack_ = 3560223669U,
    kbox_reflect_ = 1969704002U,
    kbox_shadow_ = 2286613619U,
    kbox_sizing_ = 4144391502U,
    kbreak_after_ = 3002698822U,
    kbreak_before_ = 375062601U,
    kbreak_inside_ = 101721760U,
    kbuffered_rendering_ = 3056402191U,
    kcallback_selectors_ = 821490707U,
    kcan_affect_animations_ = 1669154997U,
    kcaption_side_is_inherited_ = 752577107U,
    kchild_has_explicit_inheritance_ = 4117192798U,
    kclear_ = 1411485445U,
    kclip_ = 2024630592U,
    kclip_path_ = 3164227289U,
    kcolor_is_inherited_ = 2260247225U,
    kcolumn_count_ = 195683193U,
    kcolumn_fill_ = 3196545390U,
    kcolumn_gap_ = 3629781850U,
    kcolumn_height_ = 144001588U,
    kcolumn_rule_break_ = 2570380959U,
    kcolumn_rule_color_ = 783600996U,
    kcolumn_rule_inset_cap_end_ = 1522512822U,
    kcolumn_rule_inset_cap_start_ = 3562306400U,
    kcolumn_rule_inset_junction_end_ = 3887393515U,
    kcolumn_rule_inset_junction_start_ = 4066005030U,
    kcolumn_rule_style_ = 2466988093U,
    kcolumn_rule_visibility_items_ = 2660421045U,
    kcolumn_rule_width_ = 3719087772U,
    kcolumn_span_ = 1199195739U,
    kcolumn_width_ = 1725364885U,
    kcolumn_wrap_ = 1045552771U,
    kcontain_ = 277536184U,
    kcontain_intrinsic_height_ = 148864535U,
    kcontain_intrinsic_width_ = 1025923997U,
    kcontainer_name_ = 2552605297U,
    kcontainer_type_ = 1323394843U,
    kcontent_ = 1037033359U,
    kcontent_visibility_ = 3197225919U,
    kcontinue_ = 1531184210U,
    kcorner_bottom_left_shape_ = 266830896U,
    kcorner_bottom_right_shape_ = 1645313972U,
    kcorner_top_left_shape_ = 1147898826U,
    kcorner_top_right_shape_ = 1181604648U,
    kcounter_directives_ = 1179045564U,
    kcounter_increment_list_ = 775335500U,
    kcounter_reset_list_ = 2532917354U,
    kcounter_set_list_ = 1558776186U,
    kcursor_is_inherited_ = 2568774152U,
    kcustom_highlight_names_ = 3237167648U,
    kcustom_style_callback_depends_on_font_ = 2591830377U,
    kcx_ = 1914986604U,
    kcy_ = 530784488U,
    kd_ = 851523555U,
    kdepends_on_anchored_container_queries_ = 545891997U,
    kdepends_on_scroll_state_container_queries_ = 2194313694U,
    kdepends_on_size_container_queries_ = 3063130108U,
    kdepends_on_style_container_queries_ = 3330165248U,
    kdisplay_ = 2129579036U,
    kdisplay_layout_custom_name_ = 419288214U,
    kdisplay_layout_custom_parent_name_ = 3859634078U,
    kdocument_rules_selectors_ = 1318476616U,
    keffective_appearance_ = 4105932541U,
    kelement_is_view_transition_participant_ = 3845601109U,
    kempty_cells_is_inherited_ = 2358538661U,
    kfield_sizing_ = 2740703066U,
    kfilter_ = 3354899196U,
    kfirst_line_depends_on_size_container_queries_ = 1780329101U,
    kflex_basis_ = 895120114U,
    kflex_direction_ = 3736478246U,
    kflex_grow_ = 3963324779U,
    kflex_line_count_ = 632072125U,
    kflex_shrink_ = 2563970271U,
    kflex_wrap_ = 1122201539U,
    kfloating_ = 1244228930U,
    kflood_color_ = 2552019598U,
    kflood_opacity_ = 3258491522U,
    kflow_tolerance_ = 4213523004U,
    kforces_blockifies_children_ = 2132036586U,
    kforces_stacking_context_ = 3692190629U,
    kframe_sizing_ = 4044554931U,
    kgrid_auto_columns_ = 692485817U,
    kgrid_auto_flow_ = 3837228623U,
    kgrid_auto_rows_ = 609753064U,
    kgrid_column_end_ = 3058275963U,
    kgrid_column_start_ = 421963030U,
    kgrid_lanes_direction_ = 1301487857U,
    kgrid_lanes_pack_ = 4256465760U,
    kgrid_row_end_ = 1526489931U,
    kgrid_row_start_ = 3379981740U,
    kgrid_template_areas_ = 3968443053U,
    kgrid_template_columns_ = 342307283U,
    kgrid_template_rows_ = 3025373518U,
    khas_anchor_evaluator_ = 2711247887U,
    khas_anchor_functions_ = 3876827547U,
    khas_attr_function_ = 598638653U,
    khas_author_background_ = 2092328878U,
    khas_author_border_ = 3316023764U,
    khas_author_border_radius_ = 915203887U,
    khas_author_highlight_colors_ = 2605855035U,
    khas_auto_clip_ = 188580789U,
    khas_auto_column_count_ = 3568402130U,
    khas_auto_column_height_ = 1151261614U,
    khas_auto_column_width_ = 3958521506U,
    khas_auto_z_index_ = 4242609681U,
    khas_clip_path_ = 3995646622U,
    khas_container_relative_value_ = 2209140579U,
    khas_current_backdrop_filter_animation_ = 2914377012U,
    khas_current_background_color_animation_ = 214963764U,
    khas_current_clip_path_animation_ = 2817709527U,
    khas_current_filter_animation_ = 616615742U,
    khas_current_opacity_animation_ = 4106453575U,
    khas_current_rotate_animation_ = 125973364U,
    khas_current_scale_animation_ = 285903644U,
    khas_current_transform_animation_ = 3540441334U,
    khas_current_translate_animation_ = 2384860093U,
    khas_custom_highlight_universal_selector_ = 3077996186U,
    khas_element_dependent_random_functions_ = 3525178907U,
    khas_em_units_ = 975665659U,
    khas_env_ = 3334334524U,
    khas_env_safe_area_inset_bottom_ = 3015558321U,
    khas_explicit_inheritance_ = 2913631969U,
    khas_explicit_overflow_x_visible_ = 332345874U,
    khas_explicit_overflow_y_visible_ = 3879607816U,
    khas_glyph_relative_units_ = 2916043893U,
    khas_layout_containment_for_view_transition_scope_ = 1659621421U,
    khas_line_height_relative_units_ = 2240439189U,
    khas_logical_direction_relative_units_ = 2592720823U,
    khas_non_ua_highlight_pseudo_styles_ = 2869586580U,
    khas_non_universal_highlight_pseudo_styles_ = 2177492217U,
    khas_root_relative_units_ = 3175848810U,
    khas_sibling_functions_ = 1276024319U,
    khas_size_containment_for_view_transition_scope_ = 1227427765U,
    khas_variable_declaration_ = 3236103627U,
    khas_variable_reference_ = 1770695014U,
    kheight_ = 1813875928U,
    khighlights_depend_on_size_container_queries_ = 1636444772U,
    kinitial_letter_ = 2425328035U,
    kinline_block_baseline_edge_ = 1954298257U,
    kinline_style_lost_cascade_ = 3256599953U,
    kinteractivity_is_inherited_ = 4276188073U,
    kinterest_delay_end_ = 2387349410U,
    kinterest_delay_start_ = 1473802872U,
    kinternal_forced_background_color_ = 261694834U,
    kinternal_forced_border_color_ = 1432240920U,
    kinternal_forced_outline_color_ = 1796427030U,
    kinternal_overscroll_container_ = 1853760329U,
    kinternal_overscroll_position_ = 4133110455U,
    kinternal_unbounded_ = 1328172712U,
    kinternal_visited_background_color_ = 2249142916U,
    kinternal_visited_border_bottom_color_ = 3841098114U,
    kinternal_visited_border_left_color_ = 4155573939U,
    kinternal_visited_border_right_color_ = 31362190U,
    kinternal_visited_border_top_color_ = 4083152208U,
    kinternal_visited_column_rule_color_ = 2625013900U,
    kinternal_visited_outline_color_ = 1216192377U,
    kinternal_visited_text_decoration_color_ = 946906494U,
    kis_bottom_relative_to_safe_area_inset_ = 1663433323U,
    kis_css_inert_is_inherited_ = 725838375U,
    kis_ensured_in_display_none_ = 2043692260U,
    kis_flex_or_grid_or_custom_item_ = 2783528042U,
    kis_html_inert_is_inherited_ = 2486351254U,
    kis_in_blockifying_display_ = 3676578544U,
    kis_in_inlinifying_display_ = 3139844157U,
    kis_inside_display_ignoring_floating_children_ = 1975899920U,
    kis_link_ = 3295185791U,
    kis_original_display_inline_type_ = 2912292806U,
    kis_page_margin_box_ = 1128991864U,
    kis_running_backdrop_filter_animation_on_compositor_ = 513051118U,
    kis_running_filter_animation_on_compositor_ = 950367208U,
    kis_running_opacity_animation_on_compositor_ = 2079117467U,
    kis_running_rotate_animation_on_compositor_ = 1817829234U,
    kis_running_scale_animation_on_compositor_ = 3878587213U,
    kis_running_transform_animation_on_compositor_ = 1371430494U,
    kis_running_translate_animation_on_compositor_ = 2575318062U,
    kis_secondary_body_element_ = 1756692033U,
    kis_specified_display_webkit_box_ = 1993207932U,
    kis_stacking_context_without_containment_ = 1050463346U,
    kis_starting_style_ = 2064570092U,
    kisolation_ = 1711843169U,
    kjustify_content_ = 3665011069U,
    kjustify_items_ = 1848524724U,
    kjustify_self_ = 2031603052U,
    kleft_ = 1739692751U,
    klighting_color_ = 166232673U,
    kline_clamp_internal_block_ellipsis_ = 917548796U,
    klist_style_position_is_inherited_ = 37588774U,
    kmargin_bottom_ = 2398224398U,
    kmargin_left_ = 4282437547U,
    kmargin_right_ = 554168694U,
    kmargin_top_ = 3456246375U,
    kmargin_trim_ = 1293102748U,
    kmask_ = 2511434833U,
    kmask_box_image_ = 2536026774U,
    kmask_type_ = 971936931U,
    kmath_baseline_ = 2662085847U,
    kmath_fraction_bar_thickness_ = 1161388957U,
    kmath_l_space_ = 1024045569U,
    kmath_max_size_ = 1491979218U,
    kmath_min_size_ = 1822700186U,
    kmath_padded_depth_ = 3116359771U,
    kmath_padded_v_offset_ = 262947084U,
    kmath_r_space_ = 3158365869U,
    kmax_content_sizing_ = 885180766U,
    kmax_height_ = 1897070808U,
    kmax_lines_ = 2233241732U,
    kmax_width_ = 3010681936U,
    kmay_have_margin_ = 460055359U,
    kmay_have_padding_ = 2285617541U,
    kmaybe_has_gap_decorations_ = 775611911U,
    kmin_height_ = 4213458274U,
    kmin_width_ = 3349282655U,
    knon_inherited_variables_ = 1379490171U,
    kobject_fit_ = 4283923688U,
    kobject_position_ = 3802753009U,
    kobject_view_box_ = 1416958841U,
    koffset_anchor_ = 987861891U,
    koffset_distance_ = 3517087554U,
    koffset_path_ = 453483404U,
    koffset_position_ = 1797461175U,
    koffset_rotate_ = 1508151602U,
    kopacity_ = 1424387189U,
    korder_ = 1503356515U,
    korigin_trial_test_property_ = 1318358419U,
    koutline_color_ = 2510398998U,
    koutline_offset_ = 997651086U,
    koutline_style_ = 1480582017U,
    koutline_style_is_auto_ = 3627227854U,
    koutline_width_ = 570362523U,
    koverflow_anchor_ = 2790775231U,
    koverflow_clip_margin_ = 1020348618U,
    koverflow_x_ = 1490128448U,
    koverflow_y_ = 2537854611U,
    koverlay_ = 626474726U,
    koverscroll_behavior_x_ = 1891124426U,
    koverscroll_behavior_y_ = 1857320855U,
    koverscroll_container_type_ = 2251105690U,
    kpadding_bottom_ = 2199746909U,
    kpadding_left_ = 1222507212U,
    kpadding_right_ = 882874405U,
    kpadding_top_ = 2450872800U,
    kpage_ = 3441628854U,
    kpage_margin_safety_ = 3171400883U,
    kpage_orientation_ = 2593467880U,
    kpage_size_ = 56889893U,
    kpage_size_type_ = 615577662U,
    kpaint_images_ = 293556374U,
    kpath_length_ = 4167093748U,
    kperspective_ = 4208083201U,
    kperspective_origin_ = 1025867244U,
    kpointer_events_is_inherited_ = 3821291145U,
    kposition_ = 1865884555U,
    kposition_anchor_ = 3886267664U,
    kposition_area_ = 258806854U,
    kposition_area_offsets_ = 1740784084U,
    kposition_try_fallbacks_ = 558214215U,
    kposition_try_order_ = 1921010923U,
    kposition_visibility_ = 617645253U,
    kpseudo_element_styles_ = 3344868970U,
    kr_ = 1937069607U,
    kreading_flow_ = 2688457706U,
    kreading_order_ = 1331061740U,
    krequires_accelerated_compositing_for_external_reasons_ = 3426936359U,
    kresize_ = 2910231568U,
    kright_ = 2892989158U,
    krotate_ = 994698476U,
    krow_gap_ = 3439436492U,
    krow_rule_break_ = 4126634558U,
    krow_rule_color_ = 3278305974U,
    krow_rule_inset_cap_end_ = 2012615001U,
    krow_rule_inset_cap_start_ = 3293591479U,
    krow_rule_inset_junction_end_ = 3939541569U,
    krow_rule_inset_junction_start_ = 1717650684U,
    krow_rule_style_ = 2287038128U,
    krow_rule_visibility_items_ = 2018432864U,
    krow_rule_width_ = 1544106214U,
    krtl_ordering_is_inherited_ = 1478439922U,
    krule_overlap_ = 1086587486U,
    krx_ = 525399443U,
    kry_ = 484042124U,
    kscale_ = 3781931662U,
    kscroll_axis_lock_ = 2885440407U,
    kscroll_behavior_ = 2620272095U,
    kscroll_initial_target_ = 4115199529U,
    kscroll_margin_bottom_ = 1594765232U,
    kscroll_margin_left_ = 3120117979U,
    kscroll_margin_right_ = 1810837502U,
    kscroll_margin_top_ = 3944701951U,
    kscroll_marker_group_ = 2497803700U,
    kscroll_padding_bottom_ = 2981415144U,
    kscroll_padding_left_ = 3140900495U,
    kscroll_padding_right_ = 2752134329U,
    kscroll_padding_top_ = 701175541U,
    kscroll_snap_align_ = 3091475622U,
    kscroll_snap_stop_ = 606591463U,
    kscroll_snap_type_ = 2329393505U,
    kscroll_target_group_ = 945125060U,
    kscroll_timeline_axis_ = 697494669U,
    kscroll_timeline_name_ = 2599906953U,
    kscrollbar_gutter_ = 1345535784U,
    kscrollbar_width_ = 3788893989U,
    kshape_image_threshold_ = 583615484U,
    kshape_margin_ = 3413019744U,
    kshape_outside_ = 2940976444U,
    kshould_ignore_overflow_property_for_inline_block_baseline_ = 813964573U,
    kskips_contents_ = 2332233388U,
    kstop_color_ = 1205772591U,
    kstop_opacity_ = 3419239107U,
    kstyle_type_ = 515334678U,
    ktable_layout_ = 2466438656U,
    ktext_box_trim_ = 2255726419U,
    ktext_decoration_color_ = 214246447U,
    ktext_decoration_inset_ = 3501775137U,
    ktext_decoration_line_ = 14411126U,
    ktext_decoration_style_ = 1387864823U,
    ktext_decoration_thickness_ = 2670978567U,
    ktext_overflow_ = 1954264587U,
    ktext_transform_is_inherited_ = 1527477689U,
    ktimeline_scope_ = 3206744043U,
    ktop_ = 1799586762U,
    ktouch_action_ = 1841971519U,
    ktransform_ = 2766768702U,
    ktransform_box_ = 3704763368U,
    ktransform_origin_ = 4033913906U,
    ktransform_style_3d_ = 542120803U,
    ktransitions_ = 3916638172U,
    ktranslate_ = 1062296977U,
    ktrigger_scope_ = 1691754638U,
    kunconditional_scrollbar_size_ = 1120453245U,
    kunicode_bidi_ = 3996393211U,
    kuser_drag_ = 876454796U,
    kvector_effect_ = 2375754768U,
    kvertical_align_ = 1348881999U,
    kvertical_align_length_ = 1088445062U,
    kview_timeline_axis_ = 3751037852U,
    kview_timeline_inset_ = 1180050321U,
    kview_timeline_name_ = 3162851169U,
    kview_transition_class_ = 1081848179U,
    kview_transition_group_ = 3198257065U,
    kview_transition_name_ = 3455859741U,
    kview_transition_scope_ = 3297814172U,
    kviewport_unit_flags_ = 216676030U,
    kvisibility_is_inherited_ = 560093215U,
    kwebkit_line_clamp_ = 1256630313U,
    kwidth_ = 3137463587U,
    kwill_change_ = 1367264137U,
    kx_ = 572282666U,
    ky_ = 4279274390U,
    kz_index_ = 973262078U,
    kzoom_ = 2405674702U,
    kbackground_data_ = 2074002097U,
    kbox_data_ = 3749559929U,
    kforced_colors_data_ = 3753013371U,
    kgeometry_data_ = 155314946U,
    kmath_data_ = 2965545576U,
    kmisc_1_data_ = 3254553773U,
    kmisc_2_data_ = 1742085262U,
    kmisc_3_data_ = 3427295374U,
    kmisc_4_data_ = 940509316U,
    kmisc_5_data_ = 3481948396U,
    kmisc_6_data_ = 4081492992U,
    kmisc_7_data_ = 1804582572U,
    kmisc_8_data_ = 2494860911U,
    kmisc_data_ = 2302216836U,
    kstop_data_ = 1475874383U,
    ksurround_data_ = 907542964U,
    ksvg_data_ = 1332187567U,
    ksvgmisc_data_ = 1515914469U,
    ktimeline_data_ = 559239412U,
    kvisited_data_ = 4016297011U,
    kvisual_data_ = 3996524067U,
  };

  inline NonInheritedPropertyHash FirstDifferingNonInheritedProperty(const ComputedStyleBase& o) const {
    if (misc_data_.Get() != o.misc_data_.Get()) {
          if (!misc_data_ || !o.misc_data_) {
            return NonInheritedPropertyHash::kmisc_data_;
          }
          if (misc_data_->misc_1_data_.Get() != o.misc_data_->misc_1_data_.Get()) {
                if (!misc_data_->misc_1_data_ || !o.misc_data_->misc_1_data_) {
                  return NonInheritedPropertyHash::kmisc_1_data_;
                }
                if (!(misc_data_->misc_1_data_->backdrop_filter_ == o.misc_data_->misc_1_data_->backdrop_filter_)) {
                    return NonInheritedPropertyHash::kbackdrop_filter_;
                  }
                if (!(misc_data_->misc_1_data_->column_rule_color_ == o.misc_data_->misc_1_data_->column_rule_color_)) {
                    return NonInheritedPropertyHash::kcolumn_rule_color_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_1_data_->anchor_name_, o.misc_data_->misc_1_data_->anchor_name_))) {
                    return NonInheritedPropertyHash::kanchor_name_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_1_data_->border_shape_, o.misc_data_->misc_1_data_->border_shape_))) {
                    return NonInheritedPropertyHash::kborder_shape_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_1_data_->box_shadow_, o.misc_data_->misc_1_data_->box_shadow_))) {
                    return NonInheritedPropertyHash::kbox_shadow_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_1_data_->clip_path_, o.misc_data_->misc_1_data_->clip_path_))) {
                    return NonInheritedPropertyHash::kclip_path_;
                  }
                if (!(misc_data_->misc_1_data_->anchor_scope_ == o.misc_data_->misc_1_data_->anchor_scope_)) {
                    return NonInheritedPropertyHash::kanchor_scope_;
                  }
                if (!(misc_data_->misc_1_data_->column_rule_inset_cap_end_ == o.misc_data_->misc_1_data_->column_rule_inset_cap_end_)) {
                    return NonInheritedPropertyHash::kcolumn_rule_inset_cap_end_;
                  }
                if (!(misc_data_->misc_1_data_->column_rule_inset_cap_start_ == o.misc_data_->misc_1_data_->column_rule_inset_cap_start_)) {
                    return NonInheritedPropertyHash::kcolumn_rule_inset_cap_start_;
                  }
                if (!(misc_data_->misc_1_data_->position_anchor_ == o.misc_data_->misc_1_data_->position_anchor_)) {
                    return NonInheritedPropertyHash::kposition_anchor_;
                  }
                if (!(misc_data_->misc_1_data_->column_height_ == o.misc_data_->misc_1_data_->column_height_)) {
                    return NonInheritedPropertyHash::kcolumn_height_;
                  }
                if (!(misc_data_->misc_1_data_->column_gap_ == o.misc_data_->misc_1_data_->column_gap_)) {
                    return NonInheritedPropertyHash::kcolumn_gap_;
                  }
                if (!(misc_data_->misc_1_data_->align_content_ == o.misc_data_->misc_1_data_->align_content_)) {
                    return NonInheritedPropertyHash::kalign_content_;
                  }
                if (!(misc_data_->misc_1_data_->align_self_ == o.misc_data_->misc_1_data_->align_self_)) {
                    return NonInheritedPropertyHash::kalign_self_;
                  }
                if (!(misc_data_->misc_1_data_->column_count_ == o.misc_data_->misc_1_data_->column_count_)) {
                    return NonInheritedPropertyHash::kcolumn_count_;
                  }
                if (!(misc_data_->misc_1_data_->position_area_ == o.misc_data_->misc_1_data_->position_area_)) {
                    return NonInheritedPropertyHash::kposition_area_;
                  }

              }
          if (misc_data_->visited_data_.Get() != o.misc_data_->visited_data_.Get()) {
                if (!misc_data_->visited_data_ || !o.misc_data_->visited_data_) {
                  return NonInheritedPropertyHash::kvisited_data_;
                }
                if (!(misc_data_->visited_data_->internal_visited_column_rule_color_ == o.misc_data_->visited_data_->internal_visited_column_rule_color_)) {
                    return NonInheritedPropertyHash::kinternal_visited_column_rule_color_;
                  }
                if (!(misc_data_->visited_data_->internal_visited_background_color_ == o.misc_data_->visited_data_->internal_visited_background_color_)) {
                    return NonInheritedPropertyHash::kinternal_visited_background_color_;
                  }
                if (!(misc_data_->visited_data_->internal_visited_border_bottom_color_ == o.misc_data_->visited_data_->internal_visited_border_bottom_color_)) {
                    return NonInheritedPropertyHash::kinternal_visited_border_bottom_color_;
                  }
                if (!(misc_data_->visited_data_->internal_visited_border_left_color_ == o.misc_data_->visited_data_->internal_visited_border_left_color_)) {
                    return NonInheritedPropertyHash::kinternal_visited_border_left_color_;
                  }
                if (!(misc_data_->visited_data_->internal_visited_border_right_color_ == o.misc_data_->visited_data_->internal_visited_border_right_color_)) {
                    return NonInheritedPropertyHash::kinternal_visited_border_right_color_;
                  }
                if (!(misc_data_->visited_data_->internal_visited_border_top_color_ == o.misc_data_->visited_data_->internal_visited_border_top_color_)) {
                    return NonInheritedPropertyHash::kinternal_visited_border_top_color_;
                  }
                if (!(misc_data_->visited_data_->internal_visited_outline_color_ == o.misc_data_->visited_data_->internal_visited_outline_color_)) {
                    return NonInheritedPropertyHash::kinternal_visited_outline_color_;
                  }
                if (!(misc_data_->visited_data_->internal_visited_text_decoration_color_ == o.misc_data_->visited_data_->internal_visited_text_decoration_color_)) {
                    return NonInheritedPropertyHash::kinternal_visited_text_decoration_color_;
                  }

              }
          if (misc_data_->misc_2_data_.Get() != o.misc_data_->misc_2_data_.Get()) {
                if (!misc_data_->misc_2_data_ || !o.misc_data_->misc_2_data_) {
                  return NonInheritedPropertyHash::kmisc_2_data_;
                }
                if (!(misc_data_->misc_2_data_->filter_ == o.misc_data_->misc_2_data_->filter_)) {
                    return NonInheritedPropertyHash::kfilter_;
                  }
                if (!(misc_data_->misc_2_data_->column_rule_style_ == o.misc_data_->misc_2_data_->column_rule_style_)) {
                    return NonInheritedPropertyHash::kcolumn_rule_style_;
                  }
                if (!(misc_data_->misc_2_data_->column_rule_width_ == o.misc_data_->misc_2_data_->column_rule_width_)) {
                    return NonInheritedPropertyHash::kcolumn_rule_width_;
                  }
                if (!(misc_data_->misc_2_data_->grid_auto_columns_ == o.misc_data_->misc_2_data_->grid_auto_columns_)) {
                    return NonInheritedPropertyHash::kgrid_auto_columns_;
                  }
                if (!(misc_data_->misc_2_data_->grid_auto_rows_ == o.misc_data_->misc_2_data_->grid_auto_rows_)) {
                    return NonInheritedPropertyHash::kgrid_auto_rows_;
                  }
                if (!(misc_data_->misc_2_data_->container_name_ == o.misc_data_->misc_2_data_->container_name_)) {
                    return NonInheritedPropertyHash::kcontainer_name_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_2_data_->content_, o.misc_data_->misc_2_data_->content_))) {
                    return NonInheritedPropertyHash::kcontent_;
                  }
                if (!(misc_data_->misc_2_data_->flow_tolerance_ == o.misc_data_->misc_2_data_->flow_tolerance_)) {
                    return NonInheritedPropertyHash::kflow_tolerance_;
                  }
                if (!(misc_data_->misc_2_data_->column_rule_inset_junction_end_ == o.misc_data_->misc_2_data_->column_rule_inset_junction_end_)) {
                    return NonInheritedPropertyHash::kcolumn_rule_inset_junction_end_;
                  }
                if (!(misc_data_->misc_2_data_->column_rule_inset_junction_start_ == o.misc_data_->misc_2_data_->column_rule_inset_junction_start_)) {
                    return NonInheritedPropertyHash::kcolumn_rule_inset_junction_start_;
                  }
                if (!(misc_data_->misc_2_data_->flex_basis_ == o.misc_data_->misc_2_data_->flex_basis_)) {
                    return NonInheritedPropertyHash::kflex_basis_;
                  }
                if (!(misc_data_->misc_2_data_->column_width_ == o.misc_data_->misc_2_data_->column_width_)) {
                    return NonInheritedPropertyHash::kcolumn_width_;
                  }
                if (!(misc_data_->misc_2_data_->flex_grow_ == o.misc_data_->misc_2_data_->flex_grow_)) {
                    return NonInheritedPropertyHash::kflex_grow_;
                  }
                if (!(misc_data_->misc_2_data_->flex_shrink_ == o.misc_data_->misc_2_data_->flex_shrink_)) {
                    return NonInheritedPropertyHash::kflex_shrink_;
                  }
                if (!(misc_data_->misc_2_data_->flex_line_count_ == o.misc_data_->misc_2_data_->flex_line_count_)) {
                    return NonInheritedPropertyHash::kflex_line_count_;
                  }
                if (!(misc_data_->misc_2_data_->flex_wrap_ == o.misc_data_->misc_2_data_->flex_wrap_)) {
                    return NonInheritedPropertyHash::kflex_wrap_;
                  }

              }
          if (misc_data_->misc_3_data_.Get() != o.misc_data_->misc_3_data_.Get()) {
                if (!misc_data_->misc_3_data_ || !o.misc_data_->misc_3_data_) {
                  return NonInheritedPropertyHash::kmisc_3_data_;
                }
                if (!(misc_data_->misc_3_data_->interest_delay_end_ == o.misc_data_->misc_3_data_->interest_delay_end_)) {
                    return NonInheritedPropertyHash::kinterest_delay_end_;
                  }
                if (!(misc_data_->misc_3_data_->interest_delay_start_ == o.misc_data_->misc_3_data_->interest_delay_start_)) {
                    return NonInheritedPropertyHash::kinterest_delay_start_;
                  }
                if (!(misc_data_->misc_3_data_->grid_column_end_ == o.misc_data_->misc_3_data_->grid_column_end_)) {
                    return NonInheritedPropertyHash::kgrid_column_end_;
                  }
                if (!(misc_data_->misc_3_data_->grid_column_start_ == o.misc_data_->misc_3_data_->grid_column_start_)) {
                    return NonInheritedPropertyHash::kgrid_column_start_;
                  }
                if (!(misc_data_->misc_3_data_->grid_row_end_ == o.misc_data_->misc_3_data_->grid_row_end_)) {
                    return NonInheritedPropertyHash::kgrid_row_end_;
                  }
                if (!(misc_data_->misc_3_data_->grid_row_start_ == o.misc_data_->misc_3_data_->grid_row_start_)) {
                    return NonInheritedPropertyHash::kgrid_row_start_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_3_data_->grid_template_areas_, o.misc_data_->misc_3_data_->grid_template_areas_))) {
                    return NonInheritedPropertyHash::kgrid_template_areas_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_3_data_->grid_template_columns_, o.misc_data_->misc_3_data_->grid_template_columns_))) {
                    return NonInheritedPropertyHash::kgrid_template_columns_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_3_data_->grid_template_rows_, o.misc_data_->misc_3_data_->grid_template_rows_))) {
                    return NonInheritedPropertyHash::kgrid_template_rows_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_3_data_->object_view_box_, o.misc_data_->misc_3_data_->object_view_box_))) {
                    return NonInheritedPropertyHash::kobject_view_box_;
                  }
                if (!(misc_data_->misc_3_data_->object_position_ == o.misc_data_->misc_3_data_->object_position_)) {
                    return NonInheritedPropertyHash::kobject_position_;
                  }
                if (!(misc_data_->misc_3_data_->offset_anchor_ == o.misc_data_->misc_3_data_->offset_anchor_)) {
                    return NonInheritedPropertyHash::koffset_anchor_;
                  }
                if (!(misc_data_->misc_3_data_->initial_letter_ == o.misc_data_->misc_3_data_->initial_letter_)) {
                    return NonInheritedPropertyHash::kinitial_letter_;
                  }
                if (!(misc_data_->misc_3_data_->grid_lanes_direction_ == o.misc_data_->misc_3_data_->grid_lanes_direction_)) {
                    return NonInheritedPropertyHash::kgrid_lanes_direction_;
                  }
                if (!(misc_data_->misc_3_data_->justify_items_ == o.misc_data_->misc_3_data_->justify_items_)) {
                    return NonInheritedPropertyHash::kjustify_items_;
                  }
                if (!(misc_data_->misc_3_data_->justify_self_ == o.misc_data_->misc_3_data_->justify_self_)) {
                    return NonInheritedPropertyHash::kjustify_self_;
                  }

              }
          if (misc_data_->forced_colors_data_.Get() != o.misc_data_->forced_colors_data_.Get()) {
                if (!misc_data_->forced_colors_data_ || !o.misc_data_->forced_colors_data_) {
                  return NonInheritedPropertyHash::kforced_colors_data_;
                }
                if (!(misc_data_->forced_colors_data_->internal_forced_background_color_ == o.misc_data_->forced_colors_data_->internal_forced_background_color_)) {
                    return NonInheritedPropertyHash::kinternal_forced_background_color_;
                  }
                if (!(misc_data_->forced_colors_data_->internal_forced_border_color_ == o.misc_data_->forced_colors_data_->internal_forced_border_color_)) {
                    return NonInheritedPropertyHash::kinternal_forced_border_color_;
                  }
                if (!(misc_data_->forced_colors_data_->internal_forced_outline_color_ == o.misc_data_->forced_colors_data_->internal_forced_outline_color_)) {
                    return NonInheritedPropertyHash::kinternal_forced_outline_color_;
                  }

              }
          if (misc_data_->misc_4_data_.Get() != o.misc_data_->misc_4_data_.Get()) {
                if (!misc_data_->misc_4_data_ || !o.misc_data_->misc_4_data_) {
                  return NonInheritedPropertyHash::kmisc_4_data_;
                }
                if (!(misc_data_->misc_4_data_->page_ == o.misc_data_->misc_4_data_->page_)) {
                    return NonInheritedPropertyHash::kpage_;
                  }
                if (!(misc_data_->misc_4_data_->row_rule_color_ == o.misc_data_->misc_4_data_->row_rule_color_)) {
                    return NonInheritedPropertyHash::krow_rule_color_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_4_data_->offset_path_, o.misc_data_->misc_4_data_->offset_path_))) {
                    return NonInheritedPropertyHash::koffset_path_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_4_data_->position_try_fallbacks_, o.misc_data_->misc_4_data_->position_try_fallbacks_))) {
                    return NonInheritedPropertyHash::kposition_try_fallbacks_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_4_data_->rotate_, o.misc_data_->misc_4_data_->rotate_))) {
                    return NonInheritedPropertyHash::krotate_;
                  }
                if (!(misc_data_->misc_4_data_->offset_distance_ == o.misc_data_->misc_4_data_->offset_distance_)) {
                    return NonInheritedPropertyHash::koffset_distance_;
                  }
                if (!(misc_data_->misc_4_data_->offset_position_ == o.misc_data_->misc_4_data_->offset_position_)) {
                    return NonInheritedPropertyHash::koffset_position_;
                  }
                if (!(misc_data_->misc_4_data_->perspective_origin_ == o.misc_data_->misc_4_data_->perspective_origin_)) {
                    return NonInheritedPropertyHash::kperspective_origin_;
                  }
                if (!(misc_data_->misc_4_data_->offset_rotate_ == o.misc_data_->misc_4_data_->offset_rotate_)) {
                    return NonInheritedPropertyHash::koffset_rotate_;
                  }
                if (!(misc_data_->misc_4_data_->perspective_ == o.misc_data_->misc_4_data_->perspective_)) {
                    return NonInheritedPropertyHash::kperspective_;
                  }
                if (!(misc_data_->misc_4_data_->row_gap_ == o.misc_data_->misc_4_data_->row_gap_)) {
                    return NonInheritedPropertyHash::krow_gap_;
                  }
                if (!(misc_data_->misc_4_data_->outline_color_ == o.misc_data_->misc_4_data_->outline_color_)) {
                    return NonInheritedPropertyHash::koutline_color_;
                  }
                if (!(misc_data_->misc_4_data_->order_ == o.misc_data_->misc_4_data_->order_)) {
                    return NonInheritedPropertyHash::korder_;
                  }
                if (!(misc_data_->misc_4_data_->outline_offset_ == o.misc_data_->misc_4_data_->outline_offset_)) {
                    return NonInheritedPropertyHash::koutline_offset_;
                  }
                if (!(misc_data_->misc_4_data_->outline_width_ == o.misc_data_->misc_4_data_->outline_width_)) {
                    return NonInheritedPropertyHash::koutline_width_;
                  }
                if (!(misc_data_->misc_4_data_->reading_order_ == o.misc_data_->misc_4_data_->reading_order_)) {
                    return NonInheritedPropertyHash::kreading_order_;
                  }

              }
          if (misc_data_->misc_5_data_.Get() != o.misc_data_->misc_5_data_.Get()) {
                if (!misc_data_->misc_5_data_ || !o.misc_data_->misc_5_data_) {
                  return NonInheritedPropertyHash::kmisc_5_data_;
                }
                if (!(misc_data_->misc_5_data_->row_rule_style_ == o.misc_data_->misc_5_data_->row_rule_style_)) {
                    return NonInheritedPropertyHash::krow_rule_style_;
                  }
                if (!(misc_data_->misc_5_data_->row_rule_width_ == o.misc_data_->misc_5_data_->row_rule_width_)) {
                    return NonInheritedPropertyHash::krow_rule_width_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_5_data_->scale_, o.misc_data_->misc_5_data_->scale_))) {
                    return NonInheritedPropertyHash::kscale_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_5_data_->scroll_marker_group_, o.misc_data_->misc_5_data_->scroll_marker_group_))) {
                    return NonInheritedPropertyHash::kscroll_marker_group_;
                  }
                if (!(misc_data_->misc_5_data_->row_rule_inset_cap_end_ == o.misc_data_->misc_5_data_->row_rule_inset_cap_end_)) {
                    return NonInheritedPropertyHash::krow_rule_inset_cap_end_;
                  }
                if (!(misc_data_->misc_5_data_->row_rule_inset_cap_start_ == o.misc_data_->misc_5_data_->row_rule_inset_cap_start_)) {
                    return NonInheritedPropertyHash::krow_rule_inset_cap_start_;
                  }
                if (!(misc_data_->misc_5_data_->row_rule_inset_junction_end_ == o.misc_data_->misc_5_data_->row_rule_inset_junction_end_)) {
                    return NonInheritedPropertyHash::krow_rule_inset_junction_end_;
                  }
                if (!(misc_data_->misc_5_data_->row_rule_inset_junction_start_ == o.misc_data_->misc_5_data_->row_rule_inset_junction_start_)) {
                    return NonInheritedPropertyHash::krow_rule_inset_junction_start_;
                  }
                if (!(misc_data_->misc_5_data_->scroll_padding_bottom_ == o.misc_data_->misc_5_data_->scroll_padding_bottom_)) {
                    return NonInheritedPropertyHash::kscroll_padding_bottom_;
                  }
                if (!(misc_data_->misc_5_data_->scroll_padding_left_ == o.misc_data_->misc_5_data_->scroll_padding_left_)) {
                    return NonInheritedPropertyHash::kscroll_padding_left_;
                  }
                if (!(misc_data_->misc_5_data_->scroll_padding_right_ == o.misc_data_->misc_5_data_->scroll_padding_right_)) {
                    return NonInheritedPropertyHash::kscroll_padding_right_;
                  }
                if (!(misc_data_->misc_5_data_->scroll_padding_top_ == o.misc_data_->misc_5_data_->scroll_padding_top_)) {
                    return NonInheritedPropertyHash::kscroll_padding_top_;
                  }
                if (!(misc_data_->misc_5_data_->scroll_margin_bottom_ == o.misc_data_->misc_5_data_->scroll_margin_bottom_)) {
                    return NonInheritedPropertyHash::kscroll_margin_bottom_;
                  }
                if (!(misc_data_->misc_5_data_->scroll_margin_left_ == o.misc_data_->misc_5_data_->scroll_margin_left_)) {
                    return NonInheritedPropertyHash::kscroll_margin_left_;
                  }
                if (!(misc_data_->misc_5_data_->scroll_margin_right_ == o.misc_data_->misc_5_data_->scroll_margin_right_)) {
                    return NonInheritedPropertyHash::kscroll_margin_right_;
                  }
                if (!(misc_data_->misc_5_data_->scroll_margin_top_ == o.misc_data_->misc_5_data_->scroll_margin_top_)) {
                    return NonInheritedPropertyHash::kscroll_margin_top_;
                  }

              }
          if (misc_data_->misc_6_data_.Get() != o.misc_data_->misc_6_data_.Get()) {
                if (!misc_data_->misc_6_data_ || !o.misc_data_->misc_6_data_) {
                  return NonInheritedPropertyHash::kmisc_6_data_;
                }
                if (!(misc_data_->misc_6_data_->view_transition_group_ == o.misc_data_->misc_6_data_->view_transition_group_)) {
                    return NonInheritedPropertyHash::kview_transition_group_;
                  }
                if (!(misc_data_->misc_6_data_->text_overflow_ == o.misc_data_->misc_6_data_->text_overflow_)) {
                    return NonInheritedPropertyHash::ktext_overflow_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_6_data_->shape_outside_, o.misc_data_->misc_6_data_->shape_outside_))) {
                    return NonInheritedPropertyHash::kshape_outside_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_6_data_->translate_, o.misc_data_->misc_6_data_->translate_))) {
                    return NonInheritedPropertyHash::ktranslate_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_6_data_->view_transition_class_, o.misc_data_->misc_6_data_->view_transition_class_))) {
                    return NonInheritedPropertyHash::kview_transition_class_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_6_data_->view_transition_name_, o.misc_data_->misc_6_data_->view_transition_name_))) {
                    return NonInheritedPropertyHash::kview_transition_name_;
                  }
                if (!(misc_data_->misc_6_data_->trigger_scope_ == o.misc_data_->misc_6_data_->trigger_scope_)) {
                    return NonInheritedPropertyHash::ktrigger_scope_;
                  }
                if (!(misc_data_->misc_6_data_->shape_margin_ == o.misc_data_->misc_6_data_->shape_margin_)) {
                    return NonInheritedPropertyHash::kshape_margin_;
                  }
                if (!(misc_data_->misc_6_data_->text_decoration_inset_ == o.misc_data_->misc_6_data_->text_decoration_inset_)) {
                    return NonInheritedPropertyHash::ktext_decoration_inset_;
                  }
                if (!(misc_data_->misc_6_data_->text_decoration_thickness_ == o.misc_data_->misc_6_data_->text_decoration_thickness_)) {
                    return NonInheritedPropertyHash::ktext_decoration_thickness_;
                  }
                if (!(misc_data_->misc_6_data_->shape_image_threshold_ == o.misc_data_->misc_6_data_->shape_image_threshold_)) {
                    return NonInheritedPropertyHash::kshape_image_threshold_;
                  }
                if (!(misc_data_->misc_6_data_->box_flex_ == o.misc_data_->misc_6_data_->box_flex_)) {
                    return NonInheritedPropertyHash::kbox_flex_;
                  }
                if (!(misc_data_->misc_6_data_->text_decoration_color_ == o.misc_data_->misc_6_data_->text_decoration_color_)) {
                    return NonInheritedPropertyHash::ktext_decoration_color_;
                  }
                if (!(misc_data_->misc_6_data_->scroll_snap_align_ == o.misc_data_->misc_6_data_->scroll_snap_align_)) {
                    return NonInheritedPropertyHash::kscroll_snap_align_;
                  }
                if (!(misc_data_->misc_6_data_->scroll_snap_type_ == o.misc_data_->misc_6_data_->scroll_snap_type_)) {
                    return NonInheritedPropertyHash::kscroll_snap_type_;
                  }
                if (!(misc_data_->misc_6_data_->touch_action_ == o.misc_data_->misc_6_data_->touch_action_)) {
                    return NonInheritedPropertyHash::ktouch_action_;
                  }

              }
          if (misc_data_->timeline_data_.Get() != o.misc_data_->timeline_data_.Get()) {
                if (!misc_data_->timeline_data_ || !o.misc_data_->timeline_data_) {
                  return NonInheritedPropertyHash::ktimeline_data_;
                }
                if (!(misc_data_->timeline_data_->timeline_scope_ == o.misc_data_->timeline_data_->timeline_scope_)) {
                    return NonInheritedPropertyHash::ktimeline_scope_;
                  }
                if (!(misc_data_->timeline_data_->scroll_timeline_name_ == o.misc_data_->timeline_data_->scroll_timeline_name_)) {
                    return NonInheritedPropertyHash::kscroll_timeline_name_;
                  }
                if (!(misc_data_->timeline_data_->view_timeline_name_ == o.misc_data_->timeline_data_->view_timeline_name_)) {
                    return NonInheritedPropertyHash::kview_timeline_name_;
                  }
                if (!(misc_data_->timeline_data_->scroll_timeline_axis_ == o.misc_data_->timeline_data_->scroll_timeline_axis_)) {
                    return NonInheritedPropertyHash::kscroll_timeline_axis_;
                  }
                if (!(misc_data_->timeline_data_->view_timeline_axis_ == o.misc_data_->timeline_data_->view_timeline_axis_)) {
                    return NonInheritedPropertyHash::kview_timeline_axis_;
                  }
                if (!(misc_data_->timeline_data_->view_timeline_inset_ == o.misc_data_->timeline_data_->view_timeline_inset_)) {
                    return NonInheritedPropertyHash::kview_timeline_inset_;
                  }

              }
          if (misc_data_->misc_7_data_.Get() != o.misc_data_->misc_7_data_.Get()) {
                if (!misc_data_->misc_7_data_ || !o.misc_data_->misc_7_data_) {
                  return NonInheritedPropertyHash::kmisc_7_data_;
                }
                if (!(misc_data_->misc_7_data_->display_layout_custom_name_ == o.misc_data_->misc_7_data_->display_layout_custom_name_)) {
                    return NonInheritedPropertyHash::kdisplay_layout_custom_name_;
                  }
                if (!(misc_data_->misc_7_data_->display_layout_custom_parent_name_ == o.misc_data_->misc_7_data_->display_layout_custom_parent_name_)) {
                    return NonInheritedPropertyHash::kdisplay_layout_custom_parent_name_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_7_data_->custom_highlight_names_, o.misc_data_->misc_7_data_->custom_highlight_names_))) {
                    return NonInheritedPropertyHash::kcustom_highlight_names_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_7_data_->counter_directives_, o.misc_data_->misc_7_data_->counter_directives_))) {
                    return NonInheritedPropertyHash::kcounter_directives_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_7_data_->counter_increment_list_, o.misc_data_->misc_7_data_->counter_increment_list_))) {
                    return NonInheritedPropertyHash::kcounter_increment_list_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_7_data_->counter_reset_list_, o.misc_data_->misc_7_data_->counter_reset_list_))) {
                    return NonInheritedPropertyHash::kcounter_reset_list_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_7_data_->counter_set_list_, o.misc_data_->misc_7_data_->counter_set_list_))) {
                    return NonInheritedPropertyHash::kcounter_set_list_;
                  }
                if (!(misc_data_->misc_7_data_->mask_ == o.misc_data_->misc_7_data_->mask_)) {
                    return NonInheritedPropertyHash::kmask_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_7_data_->box_reflect_, o.misc_data_->misc_7_data_->box_reflect_))) {
                    return NonInheritedPropertyHash::kbox_reflect_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_7_data_->animations_, o.misc_data_->misc_7_data_->animations_))) {
                    return NonInheritedPropertyHash::kanimations_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_7_data_->transitions_, o.misc_data_->misc_7_data_->transitions_))) {
                    return NonInheritedPropertyHash::ktransitions_;
                  }
                if (!(misc_data_->misc_7_data_->mask_box_image_ == o.misc_data_->misc_7_data_->mask_box_image_)) {
                    return NonInheritedPropertyHash::kmask_box_image_;
                  }
                if (!(misc_data_->misc_7_data_->page_size_ == o.misc_data_->misc_7_data_->page_size_)) {
                    return NonInheritedPropertyHash::kpage_size_;
                  }
                if (!(misc_data_->misc_7_data_->unconditional_scrollbar_size_ == o.misc_data_->misc_7_data_->unconditional_scrollbar_size_)) {
                    return NonInheritedPropertyHash::kunconditional_scrollbar_size_;
                  }
                if (!(misc_data_->misc_7_data_->webkit_line_clamp_ == o.misc_data_->misc_7_data_->webkit_line_clamp_)) {
                    return NonInheritedPropertyHash::kwebkit_line_clamp_;
                  }
                if (!(misc_data_->misc_7_data_->box_ordinal_group_ == o.misc_data_->misc_7_data_->box_ordinal_group_)) {
                    return NonInheritedPropertyHash::kbox_ordinal_group_;
                  }

              }
          if (misc_data_->misc_8_data_.Get() != o.misc_data_->misc_8_data_.Get()) {
                if (!misc_data_->misc_8_data_ || !o.misc_data_->misc_8_data_) {
                  return NonInheritedPropertyHash::kmisc_8_data_;
                }
                if (!(misc_data_->misc_8_data_->callback_selectors_ == o.misc_data_->misc_8_data_->callback_selectors_)) {
                    return NonInheritedPropertyHash::kcallback_selectors_;
                  }
                if (!(base::ValuesEquivalent(misc_data_->misc_8_data_->document_rules_selectors_, o.misc_data_->misc_8_data_->document_rules_selectors_))) {
                    return NonInheritedPropertyHash::kdocument_rules_selectors_;
                  }
                if (!(misc_data_->misc_8_data_->non_inherited_variables_ == o.misc_data_->misc_8_data_->non_inherited_variables_)) {
                    return NonInheritedPropertyHash::knon_inherited_variables_;
                  }
                if (!(misc_data_->misc_8_data_->max_lines_ == o.misc_data_->misc_8_data_->max_lines_)) {
                    return NonInheritedPropertyHash::kmax_lines_;
                  }

              }
          if (misc_data_->math_data_.Get() != o.misc_data_->math_data_.Get()) {
                if (!misc_data_->math_data_ || !o.misc_data_->math_data_) {
                  return NonInheritedPropertyHash::kmath_data_;
                }
                if (!(misc_data_->math_data_->math_baseline_ == o.misc_data_->math_data_->math_baseline_)) {
                    return NonInheritedPropertyHash::kmath_baseline_;
                  }
                if (!(misc_data_->math_data_->math_fraction_bar_thickness_ == o.misc_data_->math_data_->math_fraction_bar_thickness_)) {
                    return NonInheritedPropertyHash::kmath_fraction_bar_thickness_;
                  }
                if (!(misc_data_->math_data_->math_l_space_ == o.misc_data_->math_data_->math_l_space_)) {
                    return NonInheritedPropertyHash::kmath_l_space_;
                  }
                if (!(misc_data_->math_data_->math_r_space_ == o.misc_data_->math_data_->math_r_space_)) {
                    return NonInheritedPropertyHash::kmath_r_space_;
                  }
                if (!(misc_data_->math_data_->math_padded_v_offset_ == o.misc_data_->math_data_->math_padded_v_offset_)) {
                    return NonInheritedPropertyHash::kmath_padded_v_offset_;
                  }
                if (!(misc_data_->math_data_->math_padded_depth_ == o.misc_data_->math_data_->math_padded_depth_)) {
                    return NonInheritedPropertyHash::kmath_padded_depth_;
                  }
                if (!(misc_data_->math_data_->math_min_size_ == o.misc_data_->math_data_->math_min_size_)) {
                    return NonInheritedPropertyHash::kmath_min_size_;
                  }
                if (!(misc_data_->math_data_->math_max_size_ == o.misc_data_->math_data_->math_max_size_)) {
                    return NonInheritedPropertyHash::kmath_max_size_;
                  }

              }
          if (!(base::ValuesEquivalent(misc_data_->will_change_, o.misc_data_->will_change_))) {
              return NonInheritedPropertyHash::kwill_change_;
            }
          if (!(misc_data_->appearance_ == o.misc_data_->appearance_)) {
              return NonInheritedPropertyHash::kappearance_;
            }
          if (!(misc_data_->blend_mode_ == o.misc_data_->blend_mode_)) {
              return NonInheritedPropertyHash::kblend_mode_;
            }
          if (!(misc_data_->contain_ == o.misc_data_->contain_)) {
              return NonInheritedPropertyHash::kcontain_;
            }
          if (!(misc_data_->effective_appearance_ == o.misc_data_->effective_appearance_)) {
              return NonInheritedPropertyHash::keffective_appearance_;
            }
          if (!(misc_data_->break_after_ == o.misc_data_->break_after_)) {
              return NonInheritedPropertyHash::kbreak_after_;
            }
          if (!(misc_data_->break_before_ == o.misc_data_->break_before_)) {
              return NonInheritedPropertyHash::kbreak_before_;
            }
          if (!(misc_data_->container_type_ == o.misc_data_->container_type_)) {
              return NonInheritedPropertyHash::kcontainer_type_;
            }
          if (!(misc_data_->grid_auto_flow_ == o.misc_data_->grid_auto_flow_)) {
              return NonInheritedPropertyHash::kgrid_auto_flow_;
            }
          if (!(misc_data_->margin_trim_ == o.misc_data_->margin_trim_)) {
              return NonInheritedPropertyHash::kmargin_trim_;
            }
          if (!(misc_data_->outline_style_ == o.misc_data_->outline_style_)) {
              return NonInheritedPropertyHash::koutline_style_;
            }
          if (!(misc_data_->scrollbar_gutter_ == o.misc_data_->scrollbar_gutter_)) {
              return NonInheritedPropertyHash::kscrollbar_gutter_;
            }
          if (!(misc_data_->box_align_ == o.misc_data_->box_align_)) {
              return NonInheritedPropertyHash::kbox_align_;
            }
          if (!(misc_data_->object_fit_ == o.misc_data_->object_fit_)) {
              return NonInheritedPropertyHash::kobject_fit_;
            }
          if (!(misc_data_->position_try_order_ == o.misc_data_->position_try_order_)) {
              return NonInheritedPropertyHash::kposition_try_order_;
            }
          if (!(misc_data_->position_visibility_ == o.misc_data_->position_visibility_)) {
              return NonInheritedPropertyHash::kposition_visibility_;
            }
          if (!(misc_data_->reading_flow_ == o.misc_data_->reading_flow_)) {
              return NonInheritedPropertyHash::kreading_flow_;
            }
          if (!(misc_data_->affected_by_css_function_ == o.misc_data_->affected_by_css_function_)) {
              return NonInheritedPropertyHash::kaffected_by_css_function_;
            }
          if (!(misc_data_->resize_ == o.misc_data_->resize_)) {
              return NonInheritedPropertyHash::kresize_;
            }
          if (!(misc_data_->text_decoration_style_ == o.misc_data_->text_decoration_style_)) {
              return NonInheritedPropertyHash::ktext_decoration_style_;
            }
          if (!(misc_data_->box_pack_ == o.misc_data_->box_pack_)) {
              return NonInheritedPropertyHash::kbox_pack_;
            }
          if (!(misc_data_->break_inside_ == o.misc_data_->break_inside_)) {
              return NonInheritedPropertyHash::kbreak_inside_;
            }
          if (!(misc_data_->column_rule_break_ == o.misc_data_->column_rule_break_)) {
              return NonInheritedPropertyHash::kcolumn_rule_break_;
            }
          if (!(misc_data_->column_rule_visibility_items_ == o.misc_data_->column_rule_visibility_items_)) {
              return NonInheritedPropertyHash::kcolumn_rule_visibility_items_;
            }
          if (!(misc_data_->column_wrap_ == o.misc_data_->column_wrap_)) {
              return NonInheritedPropertyHash::kcolumn_wrap_;
            }
          if (!(misc_data_->continue_ == o.misc_data_->continue_)) {
              return NonInheritedPropertyHash::kcontinue_;
            }
          if (!(misc_data_->flex_direction_ == o.misc_data_->flex_direction_)) {
              return NonInheritedPropertyHash::kflex_direction_;
            }
          if (!(misc_data_->overscroll_behavior_x_ == o.misc_data_->overscroll_behavior_x_)) {
              return NonInheritedPropertyHash::koverscroll_behavior_x_;
            }
          if (!(misc_data_->overscroll_behavior_y_ == o.misc_data_->overscroll_behavior_y_)) {
              return NonInheritedPropertyHash::koverscroll_behavior_y_;
            }
          if (!(misc_data_->overscroll_container_type_ == o.misc_data_->overscroll_container_type_)) {
              return NonInheritedPropertyHash::koverscroll_container_type_;
            }
          if (!(misc_data_->page_margin_safety_ == o.misc_data_->page_margin_safety_)) {
              return NonInheritedPropertyHash::kpage_margin_safety_;
            }
          if (!(misc_data_->page_orientation_ == o.misc_data_->page_orientation_)) {
              return NonInheritedPropertyHash::kpage_orientation_;
            }
          if (!(misc_data_->page_size_type_ == o.misc_data_->page_size_type_)) {
              return NonInheritedPropertyHash::kpage_size_type_;
            }
          if (!(misc_data_->row_rule_break_ == o.misc_data_->row_rule_break_)) {
              return NonInheritedPropertyHash::krow_rule_break_;
            }
          if (!(misc_data_->row_rule_visibility_items_ == o.misc_data_->row_rule_visibility_items_)) {
              return NonInheritedPropertyHash::krow_rule_visibility_items_;
            }
          if (!(misc_data_->scroll_behavior_ == o.misc_data_->scroll_behavior_)) {
              return NonInheritedPropertyHash::kscroll_behavior_;
            }
          if (!(misc_data_->scrollbar_width_ == o.misc_data_->scrollbar_width_)) {
              return NonInheritedPropertyHash::kscrollbar_width_;
            }
          if (!(misc_data_->user_drag_ == o.misc_data_->user_drag_)) {
              return NonInheritedPropertyHash::kuser_drag_;
            }
          if (!(misc_data_->affected_by_functional_media_ == o.misc_data_->affected_by_functional_media_)) {
              return NonInheritedPropertyHash::kaffected_by_functional_media_;
            }
          if (!(misc_data_->affected_by_functional_navigation_ == o.misc_data_->affected_by_functional_navigation_)) {
              return NonInheritedPropertyHash::kaffected_by_functional_navigation_;
            }
          if (!(misc_data_->align_content_block_center_ == o.misc_data_->align_content_block_center_)) {
              return NonInheritedPropertyHash::kalign_content_block_center_;
            }
          if (!(misc_data_->backface_visibility_ == o.misc_data_->backface_visibility_)) {
              return NonInheritedPropertyHash::kbackface_visibility_;
            }
          if (!(misc_data_->box_orient_ == o.misc_data_->box_orient_)) {
              return NonInheritedPropertyHash::kbox_orient_;
            }
          if (!(misc_data_->can_affect_animations_ == o.misc_data_->can_affect_animations_)) {
              return NonInheritedPropertyHash::kcan_affect_animations_;
            }
          if (!(misc_data_->column_fill_ == o.misc_data_->column_fill_)) {
              return NonInheritedPropertyHash::kcolumn_fill_;
            }
          if (!(misc_data_->column_span_ == o.misc_data_->column_span_)) {
              return NonInheritedPropertyHash::kcolumn_span_;
            }
          if (!(misc_data_->depends_on_anchored_container_queries_ == o.misc_data_->depends_on_anchored_container_queries_)) {
              return NonInheritedPropertyHash::kdepends_on_anchored_container_queries_;
            }
          if (!(misc_data_->depends_on_scroll_state_container_queries_ == o.misc_data_->depends_on_scroll_state_container_queries_)) {
              return NonInheritedPropertyHash::kdepends_on_scroll_state_container_queries_;
            }
          if (!(misc_data_->depends_on_size_container_queries_ == o.misc_data_->depends_on_size_container_queries_)) {
              return NonInheritedPropertyHash::kdepends_on_size_container_queries_;
            }
          if (!(misc_data_->depends_on_style_container_queries_ == o.misc_data_->depends_on_style_container_queries_)) {
              return NonInheritedPropertyHash::kdepends_on_style_container_queries_;
            }
          if (!(misc_data_->element_is_view_transition_participant_ == o.misc_data_->element_is_view_transition_participant_)) {
              return NonInheritedPropertyHash::kelement_is_view_transition_participant_;
            }
          if (!(misc_data_->first_line_depends_on_size_container_queries_ == o.misc_data_->first_line_depends_on_size_container_queries_)) {
              return NonInheritedPropertyHash::kfirst_line_depends_on_size_container_queries_;
            }
          if (!(misc_data_->forces_blockifies_children_ == o.misc_data_->forces_blockifies_children_)) {
              return NonInheritedPropertyHash::kforces_blockifies_children_;
            }
          if (!(misc_data_->grid_lanes_pack_ == o.misc_data_->grid_lanes_pack_)) {
              return NonInheritedPropertyHash::kgrid_lanes_pack_;
            }
          if (!(misc_data_->has_auto_column_count_ == o.misc_data_->has_auto_column_count_)) {
              return NonInheritedPropertyHash::khas_auto_column_count_;
            }
          if (!(misc_data_->has_auto_column_height_ == o.misc_data_->has_auto_column_height_)) {
              return NonInheritedPropertyHash::khas_auto_column_height_;
            }
          if (!(misc_data_->has_auto_column_width_ == o.misc_data_->has_auto_column_width_)) {
              return NonInheritedPropertyHash::khas_auto_column_width_;
            }
          if (!(misc_data_->has_current_backdrop_filter_animation_ == o.misc_data_->has_current_backdrop_filter_animation_)) {
              return NonInheritedPropertyHash::khas_current_backdrop_filter_animation_;
            }
          if (!(misc_data_->has_current_background_color_animation_ == o.misc_data_->has_current_background_color_animation_)) {
              return NonInheritedPropertyHash::khas_current_background_color_animation_;
            }
          if (!(misc_data_->has_current_clip_path_animation_ == o.misc_data_->has_current_clip_path_animation_)) {
              return NonInheritedPropertyHash::khas_current_clip_path_animation_;
            }
          if (!(misc_data_->has_current_filter_animation_ == o.misc_data_->has_current_filter_animation_)) {
              return NonInheritedPropertyHash::khas_current_filter_animation_;
            }
          if (!(misc_data_->has_current_opacity_animation_ == o.misc_data_->has_current_opacity_animation_)) {
              return NonInheritedPropertyHash::khas_current_opacity_animation_;
            }
          if (!(misc_data_->has_current_rotate_animation_ == o.misc_data_->has_current_rotate_animation_)) {
              return NonInheritedPropertyHash::khas_current_rotate_animation_;
            }
          if (!(misc_data_->has_current_scale_animation_ == o.misc_data_->has_current_scale_animation_)) {
              return NonInheritedPropertyHash::khas_current_scale_animation_;
            }
          if (!(misc_data_->has_current_transform_animation_ == o.misc_data_->has_current_transform_animation_)) {
              return NonInheritedPropertyHash::khas_current_transform_animation_;
            }
          if (!(misc_data_->has_current_translate_animation_ == o.misc_data_->has_current_translate_animation_)) {
              return NonInheritedPropertyHash::khas_current_translate_animation_;
            }
          if (!(misc_data_->has_explicit_overflow_x_visible_ == o.misc_data_->has_explicit_overflow_x_visible_)) {
              return NonInheritedPropertyHash::khas_explicit_overflow_x_visible_;
            }
          if (!(misc_data_->has_explicit_overflow_y_visible_ == o.misc_data_->has_explicit_overflow_y_visible_)) {
              return NonInheritedPropertyHash::khas_explicit_overflow_y_visible_;
            }
          if (!(misc_data_->has_layout_containment_for_view_transition_scope_ == o.misc_data_->has_layout_containment_for_view_transition_scope_)) {
              return NonInheritedPropertyHash::khas_layout_containment_for_view_transition_scope_;
            }
          if (!(misc_data_->has_size_containment_for_view_transition_scope_ == o.misc_data_->has_size_containment_for_view_transition_scope_)) {
              return NonInheritedPropertyHash::khas_size_containment_for_view_transition_scope_;
            }
          if (!(misc_data_->internal_overscroll_container_ == o.misc_data_->internal_overscroll_container_)) {
              return NonInheritedPropertyHash::kinternal_overscroll_container_;
            }
          if (!(misc_data_->internal_overscroll_position_ == o.misc_data_->internal_overscroll_position_)) {
              return NonInheritedPropertyHash::kinternal_overscroll_position_;
            }
          if (!(misc_data_->internal_unbounded_ == o.misc_data_->internal_unbounded_)) {
              return NonInheritedPropertyHash::kinternal_unbounded_;
            }
          if (!(misc_data_->is_bottom_relative_to_safe_area_inset_ == o.misc_data_->is_bottom_relative_to_safe_area_inset_)) {
              return NonInheritedPropertyHash::kis_bottom_relative_to_safe_area_inset_;
            }
          if (!(misc_data_->is_running_rotate_animation_on_compositor_ == o.misc_data_->is_running_rotate_animation_on_compositor_)) {
              return NonInheritedPropertyHash::kis_running_rotate_animation_on_compositor_;
            }
          if (!(misc_data_->is_running_scale_animation_on_compositor_ == o.misc_data_->is_running_scale_animation_on_compositor_)) {
              return NonInheritedPropertyHash::kis_running_scale_animation_on_compositor_;
            }
          if (!(misc_data_->is_running_transform_animation_on_compositor_ == o.misc_data_->is_running_transform_animation_on_compositor_)) {
              return NonInheritedPropertyHash::kis_running_transform_animation_on_compositor_;
            }
          if (!(misc_data_->is_running_translate_animation_on_compositor_ == o.misc_data_->is_running_translate_animation_on_compositor_)) {
              return NonInheritedPropertyHash::kis_running_translate_animation_on_compositor_;
            }
          if (!(misc_data_->is_secondary_body_element_ == o.misc_data_->is_secondary_body_element_)) {
              return NonInheritedPropertyHash::kis_secondary_body_element_;
            }
          if (!(misc_data_->is_specified_display_webkit_box_ == o.misc_data_->is_specified_display_webkit_box_)) {
              return NonInheritedPropertyHash::kis_specified_display_webkit_box_;
            }
          if (!(misc_data_->is_starting_style_ == o.misc_data_->is_starting_style_)) {
              return NonInheritedPropertyHash::kis_starting_style_;
            }
          if (!(misc_data_->isolation_ == o.misc_data_->isolation_)) {
              return NonInheritedPropertyHash::kisolation_;
            }
          if (!(misc_data_->line_clamp_internal_block_ellipsis_ == o.misc_data_->line_clamp_internal_block_ellipsis_)) {
              return NonInheritedPropertyHash::kline_clamp_internal_block_ellipsis_;
            }
          if (!(misc_data_->max_content_sizing_ == o.misc_data_->max_content_sizing_)) {
              return NonInheritedPropertyHash::kmax_content_sizing_;
            }
          if (!(misc_data_->outline_style_is_auto_ == o.misc_data_->outline_style_is_auto_)) {
              return NonInheritedPropertyHash::koutline_style_is_auto_;
            }
          if (!(misc_data_->overlay_ == o.misc_data_->overlay_)) {
              return NonInheritedPropertyHash::koverlay_;
            }
          if (!(misc_data_->requires_accelerated_compositing_for_external_reasons_ == o.misc_data_->requires_accelerated_compositing_for_external_reasons_)) {
              return NonInheritedPropertyHash::krequires_accelerated_compositing_for_external_reasons_;
            }
          if (!(misc_data_->rule_overlap_ == o.misc_data_->rule_overlap_)) {
              return NonInheritedPropertyHash::krule_overlap_;
            }
          if (!(misc_data_->scroll_axis_lock_ == o.misc_data_->scroll_axis_lock_)) {
              return NonInheritedPropertyHash::kscroll_axis_lock_;
            }
          if (!(misc_data_->scroll_initial_target_ == o.misc_data_->scroll_initial_target_)) {
              return NonInheritedPropertyHash::kscroll_initial_target_;
            }
          if (!(misc_data_->scroll_target_group_ == o.misc_data_->scroll_target_group_)) {
              return NonInheritedPropertyHash::kscroll_target_group_;
            }
          if (!(misc_data_->transform_style_3d_ == o.misc_data_->transform_style_3d_)) {
              return NonInheritedPropertyHash::ktransform_style_3d_;
            }
          if (!(misc_data_->view_transition_scope_ == o.misc_data_->view_transition_scope_)) {
              return NonInheritedPropertyHash::kview_transition_scope_;
            }

        }
    if (visual_data_.Get() != o.visual_data_.Get()) {
          if (!visual_data_ || !o.visual_data_) {
            return NonInheritedPropertyHash::kvisual_data_;
          }
          if (!(base::ValuesEquivalent(visual_data_->base_text_decoration_data_, o.visual_data_->base_text_decoration_data_))) {
              return NonInheritedPropertyHash::kbase_text_decoration_data_;
            }
          if (!(visual_data_->clip_ == o.visual_data_->clip_)) {
              return NonInheritedPropertyHash::kclip_;
            }
          if (!(visual_data_->zoom_ == o.visual_data_->zoom_)) {
              return NonInheritedPropertyHash::kzoom_;
            }
          if (!(visual_data_->text_decoration_line_ == o.visual_data_->text_decoration_line_)) {
              return NonInheritedPropertyHash::ktext_decoration_line_;
            }
          if (!(visual_data_->field_sizing_ == o.visual_data_->field_sizing_)) {
              return NonInheritedPropertyHash::kfield_sizing_;
            }
          if (!(visual_data_->has_auto_clip_ == o.visual_data_->has_auto_clip_)) {
              return NonInheritedPropertyHash::khas_auto_clip_;
            }
          if (!(visual_data_->has_clip_path_ == o.visual_data_->has_clip_path_)) {
              return NonInheritedPropertyHash::khas_clip_path_;
            }
          if (!(visual_data_->maybe_has_gap_decorations_ == o.visual_data_->maybe_has_gap_decorations_)) {
              return NonInheritedPropertyHash::kmaybe_has_gap_decorations_;
            }

        }
    if (box_data_.Get() != o.box_data_.Get()) {
          if (!box_data_ || !o.box_data_) {
            return NonInheritedPropertyHash::kbox_data_;
          }
          if (!(box_data_->height_ == o.box_data_->height_)) {
              return NonInheritedPropertyHash::kheight_;
            }
          if (!(box_data_->margin_bottom_ == o.box_data_->margin_bottom_)) {
              return NonInheritedPropertyHash::kmargin_bottom_;
            }
          if (!(box_data_->margin_left_ == o.box_data_->margin_left_)) {
              return NonInheritedPropertyHash::kmargin_left_;
            }
          if (!(box_data_->margin_right_ == o.box_data_->margin_right_)) {
              return NonInheritedPropertyHash::kmargin_right_;
            }
          if (!(box_data_->margin_top_ == o.box_data_->margin_top_)) {
              return NonInheritedPropertyHash::kmargin_top_;
            }
          if (!(box_data_->max_height_ == o.box_data_->max_height_)) {
              return NonInheritedPropertyHash::kmax_height_;
            }
          if (!(box_data_->max_width_ == o.box_data_->max_width_)) {
              return NonInheritedPropertyHash::kmax_width_;
            }
          if (!(box_data_->min_height_ == o.box_data_->min_height_)) {
              return NonInheritedPropertyHash::kmin_height_;
            }
          if (!(box_data_->min_width_ == o.box_data_->min_width_)) {
              return NonInheritedPropertyHash::kmin_width_;
            }
          if (!(box_data_->padding_bottom_ == o.box_data_->padding_bottom_)) {
              return NonInheritedPropertyHash::kpadding_bottom_;
            }
          if (!(box_data_->padding_left_ == o.box_data_->padding_left_)) {
              return NonInheritedPropertyHash::kpadding_left_;
            }
          if (!(box_data_->padding_right_ == o.box_data_->padding_right_)) {
              return NonInheritedPropertyHash::kpadding_right_;
            }
          if (!(box_data_->padding_top_ == o.box_data_->padding_top_)) {
              return NonInheritedPropertyHash::kpadding_top_;
            }
          if (!(box_data_->width_ == o.box_data_->width_)) {
              return NonInheritedPropertyHash::kwidth_;
            }
          if (!(box_data_->vertical_align_length_ == o.box_data_->vertical_align_length_)) {
              return NonInheritedPropertyHash::kvertical_align_length_;
            }
          if (!(box_data_->justify_content_ == o.box_data_->justify_content_)) {
              return NonInheritedPropertyHash::kjustify_content_;
            }
          if (!(box_data_->align_items_ == o.box_data_->align_items_)) {
              return NonInheritedPropertyHash::kalign_items_;
            }
          if (!(box_data_->border_bottom_width_ == o.box_data_->border_bottom_width_)) {
              return NonInheritedPropertyHash::kborder_bottom_width_;
            }
          if (!(box_data_->border_left_width_ == o.box_data_->border_left_width_)) {
              return NonInheritedPropertyHash::kborder_left_width_;
            }
          if (!(box_data_->border_right_width_ == o.box_data_->border_right_width_)) {
              return NonInheritedPropertyHash::kborder_right_width_;
            }
          if (!(box_data_->border_top_width_ == o.box_data_->border_top_width_)) {
              return NonInheritedPropertyHash::kborder_top_width_;
            }
          if (!(box_data_->z_index_ == o.box_data_->z_index_)) {
              return NonInheritedPropertyHash::kz_index_;
            }
          if (!(box_data_->overflow_clip_margin_ == o.box_data_->overflow_clip_margin_)) {
              return NonInheritedPropertyHash::koverflow_clip_margin_;
            }
          if (!(box_data_->border_bottom_style_ == o.box_data_->border_bottom_style_)) {
              return NonInheritedPropertyHash::kborder_bottom_style_;
            }
          if (!(box_data_->border_left_style_ == o.box_data_->border_left_style_)) {
              return NonInheritedPropertyHash::kborder_left_style_;
            }
          if (!(box_data_->border_right_style_ == o.box_data_->border_right_style_)) {
              return NonInheritedPropertyHash::kborder_right_style_;
            }
          if (!(box_data_->border_top_style_ == o.box_data_->border_top_style_)) {
              return NonInheritedPropertyHash::kborder_top_style_;
            }
          if (!(box_data_->baseline_source_ == o.box_data_->baseline_source_)) {
              return NonInheritedPropertyHash::kbaseline_source_;
            }
          if (!(box_data_->text_box_trim_ == o.box_data_->text_box_trim_)) {
              return NonInheritedPropertyHash::ktext_box_trim_;
            }
          if (!(box_data_->box_decoration_break_ == o.box_data_->box_decoration_break_)) {
              return NonInheritedPropertyHash::kbox_decoration_break_;
            }
          if (!(box_data_->has_auto_z_index_ == o.box_data_->has_auto_z_index_)) {
              return NonInheritedPropertyHash::khas_auto_z_index_;
            }

        }
    if (svg_data_.Get() != o.svg_data_.Get()) {
          if (!svg_data_ || !o.svg_data_) {
            return NonInheritedPropertyHash::ksvg_data_;
          }
          if (svg_data_->svgmisc_data_.Get() != o.svg_data_->svgmisc_data_.Get()) {
                if (!svg_data_->svgmisc_data_ || !o.svg_data_->svgmisc_data_) {
                  return NonInheritedPropertyHash::ksvgmisc_data_;
                }
                if (!(svg_data_->svgmisc_data_->baseline_shift_ == o.svg_data_->svgmisc_data_->baseline_shift_)) {
                    return NonInheritedPropertyHash::kbaseline_shift_;
                  }
                if (!(svg_data_->svgmisc_data_->flood_opacity_ == o.svg_data_->svgmisc_data_->flood_opacity_)) {
                    return NonInheritedPropertyHash::kflood_opacity_;
                  }
                if (!(svg_data_->svgmisc_data_->flood_color_ == o.svg_data_->svgmisc_data_->flood_color_)) {
                    return NonInheritedPropertyHash::kflood_color_;
                  }
                if (!(svg_data_->svgmisc_data_->lighting_color_ == o.svg_data_->svgmisc_data_->lighting_color_)) {
                    return NonInheritedPropertyHash::klighting_color_;
                  }
                if (!(svg_data_->svgmisc_data_->baseline_shift_type_ == o.svg_data_->svgmisc_data_->baseline_shift_type_)) {
                    return NonInheritedPropertyHash::kbaseline_shift_type_;
                  }

              }
          if (svg_data_->geometry_data_.Get() != o.svg_data_->geometry_data_.Get()) {
                if (!svg_data_->geometry_data_ || !o.svg_data_->geometry_data_) {
                  return NonInheritedPropertyHash::kgeometry_data_;
                }
                if (!(base::ValuesEquivalent(svg_data_->geometry_data_->d_, o.svg_data_->geometry_data_->d_))) {
                    return NonInheritedPropertyHash::kd_;
                  }
                if (!(svg_data_->geometry_data_->cx_ == o.svg_data_->geometry_data_->cx_)) {
                    return NonInheritedPropertyHash::kcx_;
                  }
                if (!(svg_data_->geometry_data_->cy_ == o.svg_data_->geometry_data_->cy_)) {
                    return NonInheritedPropertyHash::kcy_;
                  }
                if (!(svg_data_->geometry_data_->path_length_ == o.svg_data_->geometry_data_->path_length_)) {
                    return NonInheritedPropertyHash::kpath_length_;
                  }
                if (!(svg_data_->geometry_data_->r_ == o.svg_data_->geometry_data_->r_)) {
                    return NonInheritedPropertyHash::kr_;
                  }
                if (!(svg_data_->geometry_data_->rx_ == o.svg_data_->geometry_data_->rx_)) {
                    return NonInheritedPropertyHash::krx_;
                  }
                if (!(svg_data_->geometry_data_->ry_ == o.svg_data_->geometry_data_->ry_)) {
                    return NonInheritedPropertyHash::kry_;
                  }
                if (!(svg_data_->geometry_data_->x_ == o.svg_data_->geometry_data_->x_)) {
                    return NonInheritedPropertyHash::kx_;
                  }
                if (!(svg_data_->geometry_data_->y_ == o.svg_data_->geometry_data_->y_)) {
                    return NonInheritedPropertyHash::ky_;
                  }

              }
          if (svg_data_->stop_data_.Get() != o.svg_data_->stop_data_.Get()) {
                if (!svg_data_->stop_data_ || !o.svg_data_->stop_data_) {
                  return NonInheritedPropertyHash::kstop_data_;
                }
                if (!(svg_data_->stop_data_->stop_opacity_ == o.svg_data_->stop_data_->stop_opacity_)) {
                    return NonInheritedPropertyHash::kstop_opacity_;
                  }
                if (!(svg_data_->stop_data_->stop_color_ == o.svg_data_->stop_data_->stop_color_)) {
                    return NonInheritedPropertyHash::kstop_color_;
                  }

              }
          if (!(svg_data_->transform_ == o.svg_data_->transform_)) {
              return NonInheritedPropertyHash::ktransform_;
            }
          if (!(svg_data_->transform_origin_ == o.svg_data_->transform_origin_)) {
              return NonInheritedPropertyHash::ktransform_origin_;
            }
          if (!(svg_data_->opacity_ == o.svg_data_->opacity_)) {
              return NonInheritedPropertyHash::kopacity_;
            }
          if (!(svg_data_->alignment_baseline_ == o.svg_data_->alignment_baseline_)) {
              return NonInheritedPropertyHash::kalignment_baseline_;
            }
          if (!(svg_data_->buffered_rendering_ == o.svg_data_->buffered_rendering_)) {
              return NonInheritedPropertyHash::kbuffered_rendering_;
            }
          if (!(svg_data_->mask_type_ == o.svg_data_->mask_type_)) {
              return NonInheritedPropertyHash::kmask_type_;
            }
          if (!(svg_data_->vector_effect_ == o.svg_data_->vector_effect_)) {
              return NonInheritedPropertyHash::kvector_effect_;
            }

        }
    if (surround_data_.Get() != o.surround_data_.Get()) {
          if (!surround_data_ || !o.surround_data_) {
            return NonInheritedPropertyHash::ksurround_data_;
          }
          if (!(surround_data_->corner_bottom_left_shape_ == o.surround_data_->corner_bottom_left_shape_)) {
              return NonInheritedPropertyHash::kcorner_bottom_left_shape_;
            }
          if (!(surround_data_->corner_bottom_right_shape_ == o.surround_data_->corner_bottom_right_shape_)) {
              return NonInheritedPropertyHash::kcorner_bottom_right_shape_;
            }
          if (!(surround_data_->corner_top_left_shape_ == o.surround_data_->corner_top_left_shape_)) {
              return NonInheritedPropertyHash::kcorner_top_left_shape_;
            }
          if (!(surround_data_->corner_top_right_shape_ == o.surround_data_->corner_top_right_shape_)) {
              return NonInheritedPropertyHash::kcorner_top_right_shape_;
            }
          if (!(surround_data_->border_image_ == o.surround_data_->border_image_)) {
              return NonInheritedPropertyHash::kborder_image_;
            }
          if (!(surround_data_->bottom_ == o.surround_data_->bottom_)) {
              return NonInheritedPropertyHash::kbottom_;
            }
          if (!(surround_data_->left_ == o.surround_data_->left_)) {
              return NonInheritedPropertyHash::kleft_;
            }
          if (!(surround_data_->right_ == o.surround_data_->right_)) {
              return NonInheritedPropertyHash::kright_;
            }
          if (!(surround_data_->top_ == o.surround_data_->top_)) {
              return NonInheritedPropertyHash::ktop_;
            }
          if (!(surround_data_->border_bottom_left_radius_ == o.surround_data_->border_bottom_left_radius_)) {
              return NonInheritedPropertyHash::kborder_bottom_left_radius_;
            }
          if (!(surround_data_->border_bottom_right_radius_ == o.surround_data_->border_bottom_right_radius_)) {
              return NonInheritedPropertyHash::kborder_bottom_right_radius_;
            }
          if (!(surround_data_->border_top_left_radius_ == o.surround_data_->border_top_left_radius_)) {
              return NonInheritedPropertyHash::kborder_top_left_radius_;
            }
          if (!(surround_data_->border_top_right_radius_ == o.surround_data_->border_top_right_radius_)) {
              return NonInheritedPropertyHash::kborder_top_right_radius_;
            }
          if (!(surround_data_->aspect_ratio_ == o.surround_data_->aspect_ratio_)) {
              return NonInheritedPropertyHash::kaspect_ratio_;
            }
          if (!(surround_data_->contain_intrinsic_height_ == o.surround_data_->contain_intrinsic_height_)) {
              return NonInheritedPropertyHash::kcontain_intrinsic_height_;
            }
          if (!(surround_data_->contain_intrinsic_width_ == o.surround_data_->contain_intrinsic_width_)) {
              return NonInheritedPropertyHash::kcontain_intrinsic_width_;
            }
          if (!(surround_data_->border_bottom_color_ == o.surround_data_->border_bottom_color_)) {
              return NonInheritedPropertyHash::kborder_bottom_color_;
            }
          if (!(surround_data_->border_left_color_ == o.surround_data_->border_left_color_)) {
              return NonInheritedPropertyHash::kborder_left_color_;
            }
          if (!(surround_data_->border_right_color_ == o.surround_data_->border_right_color_)) {
              return NonInheritedPropertyHash::kborder_right_color_;
            }
          if (!(surround_data_->border_top_color_ == o.surround_data_->border_top_color_)) {
              return NonInheritedPropertyHash::kborder_top_color_;
            }
          if (!(surround_data_->frame_sizing_ == o.surround_data_->frame_sizing_)) {
              return NonInheritedPropertyHash::kframe_sizing_;
            }

        }
    if (background_data_.Get() != o.background_data_.Get()) {
          if (!background_data_ || !o.background_data_) {
            return NonInheritedPropertyHash::kbackground_data_;
          }
          if (!(background_data_->background_ == o.background_data_->background_)) {
              return NonInheritedPropertyHash::kbackground_;
            }
          if (!(background_data_->background_color_ == o.background_data_->background_color_)) {
              return NonInheritedPropertyHash::kbackground_color_;
            }

        }
    if (!(data_.display_ == o.data_.display_)) {
        return NonInheritedPropertyHash::kdisplay_;
      }
    if (!(data_.vertical_align_ == o.data_.vertical_align_)) {
        return NonInheritedPropertyHash::kvertical_align_;
      }
    if (!(data_.clear_ == o.data_.clear_)) {
        return NonInheritedPropertyHash::kclear_;
      }
    if (!(data_.floating_ == o.data_.floating_)) {
        return NonInheritedPropertyHash::kfloating_;
      }
    if (!(data_.overflow_x_ == o.data_.overflow_x_)) {
        return NonInheritedPropertyHash::koverflow_x_;
      }
    if (!(data_.overflow_y_ == o.data_.overflow_y_)) {
        return NonInheritedPropertyHash::koverflow_y_;
      }
    if (!(data_.position_ == o.data_.position_)) {
        return NonInheritedPropertyHash::kposition_;
      }
    if (!(data_.transform_box_ == o.data_.transform_box_)) {
        return NonInheritedPropertyHash::ktransform_box_;
      }
    if (!(data_.unicode_bidi_ == o.data_.unicode_bidi_)) {
        return NonInheritedPropertyHash::kunicode_bidi_;
      }
    if (!(data_.content_visibility_ == o.data_.content_visibility_)) {
        return NonInheritedPropertyHash::kcontent_visibility_;
      }
    if (!(data_.inline_block_baseline_edge_ == o.data_.inline_block_baseline_edge_)) {
        return NonInheritedPropertyHash::kinline_block_baseline_edge_;
      }
    if (!(IsStackingContextWithoutContainment() == o.IsStackingContextWithoutContainment())) {
        return NonInheritedPropertyHash::kis_stacking_context_without_containment_;
      }
    if (!(data_.overflow_anchor_ == o.data_.overflow_anchor_)) {
        return NonInheritedPropertyHash::koverflow_anchor_;
      }
    if (!(data_.scroll_snap_stop_ == o.data_.scroll_snap_stop_)) {
        return NonInheritedPropertyHash::kscroll_snap_stop_;
      }
    if (!(data_.viewport_unit_flags_ == o.data_.viewport_unit_flags_)) {
        return NonInheritedPropertyHash::kviewport_unit_flags_;
      }
    if (!(data_.allows_z_index_ == o.data_.allows_z_index_)) {
        return NonInheritedPropertyHash::kallows_z_index_;
      }
    if (!(data_.box_direction_ == o.data_.box_direction_)) {
        return NonInheritedPropertyHash::kbox_direction_;
      }
    if (!(data_.box_sizing_ == o.data_.box_sizing_)) {
        return NonInheritedPropertyHash::kbox_sizing_;
      }
    if (!(data_.forces_stacking_context_ == o.data_.forces_stacking_context_)) {
        return NonInheritedPropertyHash::kforces_stacking_context_;
      }
    if (!(data_.has_author_background_ == o.data_.has_author_background_)) {
        return NonInheritedPropertyHash::khas_author_background_;
      }
    if (!(data_.has_author_border_ == o.data_.has_author_border_)) {
        return NonInheritedPropertyHash::khas_author_border_;
      }
    if (!(data_.has_author_border_radius_ == o.data_.has_author_border_radius_)) {
        return NonInheritedPropertyHash::khas_author_border_radius_;
      }
    if (!(data_.has_author_highlight_colors_ == o.data_.has_author_highlight_colors_)) {
        return NonInheritedPropertyHash::khas_author_highlight_colors_;
      }
    if (!(data_.has_explicit_inheritance_ == o.data_.has_explicit_inheritance_)) {
        return NonInheritedPropertyHash::khas_explicit_inheritance_;
      }
    if (!(data_.is_original_display_inline_type_ == o.data_.is_original_display_inline_type_)) {
        return NonInheritedPropertyHash::kis_original_display_inline_type_;
      }
    if (!(data_.is_page_margin_box_ == o.data_.is_page_margin_box_)) {
        return NonInheritedPropertyHash::kis_page_margin_box_;
      }
    if (!(data_.origin_trial_test_property_ == o.data_.origin_trial_test_property_)) {
        return NonInheritedPropertyHash::korigin_trial_test_property_;
      }
    if (!(data_.should_ignore_overflow_property_for_inline_block_baseline_ == o.data_.should_ignore_overflow_property_for_inline_block_baseline_)) {
        return NonInheritedPropertyHash::kshould_ignore_overflow_property_for_inline_block_baseline_;
      }
    if (!(data_.skips_contents_ == o.data_.skips_contents_)) {
        return NonInheritedPropertyHash::kskips_contents_;
      }
    if (!(data_.table_layout_ == o.data_.table_layout_)) {
        return NonInheritedPropertyHash::ktable_layout_;
      }

    return NonInheritedPropertyHash::kNone;
  }

  // Fields.
  // TODO(sashab): Remove initialFoo() static methods and update callers to
  // use resetFoo(), which can be more efficient.

  // accent-color
  





  // AffectedByActive
  bool AffectedByActive() const {
    return static_cast<bool>(data_.affected_by_active_);
  }



  // AffectedByCSSFunction
  bool AffectedByCSSFunction() const {
    return static_cast<bool>(misc_data_->affected_by_css_function_);
  }



  // AffectedByDrag
  bool AffectedByDrag() const {
    return static_cast<bool>(data_.affected_by_drag_);
  }



  // AffectedByFocusWithin
  bool AffectedByFocusWithin() const {
    return static_cast<bool>(data_.affected_by_focus_within_);
  }



  // AffectedByFunctionalMedia
  bool AffectedByFunctionalMedia() const {
    return static_cast<bool>(misc_data_->affected_by_functional_media_);
  }



  // AffectedByFunctionalNavigation
  bool AffectedByFunctionalNavigation() const {
    return static_cast<bool>(misc_data_->affected_by_functional_navigation_);
  }



  // AffectedByHover
  bool AffectedByHover() const {
    return static_cast<bool>(data_.affected_by_hover_);
  }



  // align-content
  const StyleContentAlignmentData& AlignContent() const {
    return misc_data_->misc_1_data_->align_content_;
  }






  // -internal-align-content-block
  bool AlignContentBlockCenter() const {
    return static_cast<bool>(misc_data_->align_content_block_center_);
  }




  // align-items
  const StyleSelfAlignmentData& AlignItems() const {
    return box_data_->align_items_;
  }






  // align-self
  const StyleSelfAlignmentData& AlignSelf() const {
    return misc_data_->misc_1_data_->align_self_;
  }






  // alignment-baseline
  EAlignmentBaseline AlignmentBaseline() const {
    return static_cast<EAlignmentBaseline>(svg_data_->alignment_baseline_);
  }




  // AllowsZIndex
  bool AllowsZIndex() const {
    return static_cast<bool>(data_.allows_z_index_);
  }




  // AnchorCenterOffset
  const std::optional<PhysicalOffset>& AnchorCenterOffset() const {
    return misc_data_->misc_8_data_->anchor_center_offset_;
  }






  // anchor-name
  const Member<ScopedCSSNameList>& AnchorName() const {
    return misc_data_->misc_1_data_->anchor_name_;
  }






  // anchor-scope
  const StyleAnchorScope& AnchorScope() const {
    return misc_data_->misc_1_data_->anchor_scope_;
  }






  // Animations
  const Member<CSSAnimationData>& Animations() const {
    return misc_data_->misc_7_data_->animations_;
  }






  // appearance
  



  // aspect-ratio
  const StyleAspectRatio& AspectRatio() const {
    return surround_data_->aspect_ratio_;
  }






  // backdrop-filter
  const FilterOperations& BackdropFilter() const {
    return misc_data_->misc_1_data_->backdrop_filter_;
  }






  // backface-visibility
  EBackfaceVisibility BackfaceVisibility() const {
    return static_cast<EBackfaceVisibility>(misc_data_->backface_visibility_);
  }




  // Background
  





  // background-color
  





  // BaseData
  StyleBaseData* BaseData() const {
    return base_data_.Get();
  }



  // BaseTextDecorationData
  AppliedTextDecorationVector* BaseTextDecorationData() const {
    return visual_data_->base_text_decoration_data_.Get();
  }



  // baseline-shift
  const Length& BaselineShift() const {
    return svg_data_->svgmisc_data_->baseline_shift_;
  }






  // BaselineShiftType
  EBaselineShiftType BaselineShiftType() const {
    return static_cast<EBaselineShiftType>(svg_data_->svgmisc_data_->baseline_shift_type_);
  }




  // baseline-source
  EBaselineSource BaselineSource() const {
    return static_cast<EBaselineSource>(box_data_->baseline_source_);
  }




  // mix-blend-mode
  BlendMode GetBlendMode() const {
    return static_cast<BlendMode>(misc_data_->blend_mode_);
  }




  // block-ellipsis
  EBlockEllipsis BlockEllipsis() const {
    return static_cast<EBlockEllipsis>(misc_inherited_data_->block_ellipsis_);
  }




  // border-bottom-color
  





  // border-bottom-left-radius
  const LengthSize& BorderBottomLeftRadius() const {
    return surround_data_->border_bottom_left_radius_;
  }






  // border-bottom-right-radius
  const LengthSize& BorderBottomRightRadius() const {
    return surround_data_->border_bottom_right_radius_;
  }






  // border-bottom-style
  EBorderStyle BorderBottomStyle() const {
    return static_cast<EBorderStyle>(box_data_->border_bottom_style_);
  }




  // border-bottom-width
  const int& SpecifiedBorderBottomWidth() const {
    return box_data_->border_bottom_width_;
  }






  // border-collapse
  EBorderCollapse BorderCollapse() const {
    return static_cast<EBorderCollapse>(data_.border_collapse_);
  }




  // border-collapse
  bool BorderCollapseIsInherited() const {
    return static_cast<bool>(data_.border_collapse_is_inherited_);
  }




  // border-image
  const NinePieceImage& BorderImage() const {
    return surround_data_->border_image_;
  }






  // border-left-color
  





  // border-left-style
  EBorderStyle BorderLeftStyle() const {
    return static_cast<EBorderStyle>(box_data_->border_left_style_);
  }




  // border-left-width
  const int& SpecifiedBorderLeftWidth() const {
    return box_data_->border_left_width_;
  }






  // border-right-color
  





  // border-right-style
  EBorderStyle BorderRightStyle() const {
    return static_cast<EBorderStyle>(box_data_->border_right_style_);
  }




  // border-right-width
  const int& SpecifiedBorderRightWidth() const {
    return box_data_->border_right_width_;
  }






  // border-shape
  const Member<StyleBorderShape>& BorderShape() const {
    return misc_data_->misc_1_data_->border_shape_;
  }






  // border-top-color
  





  // border-top-left-radius
  const LengthSize& BorderTopLeftRadius() const {
    return surround_data_->border_top_left_radius_;
  }






  // border-top-right-radius
  const LengthSize& BorderTopRightRadius() const {
    return surround_data_->border_top_right_radius_;
  }






  // border-top-style
  EBorderStyle BorderTopStyle() const {
    return static_cast<EBorderStyle>(box_data_->border_top_style_);
  }




  // border-top-width
  const int& SpecifiedBorderTopWidth() const {
    return box_data_->border_top_width_;
  }






  // bottom
  const Length& Bottom() const {
    return surround_data_->bottom_;
  }






  // -webkit-box-align
  EBoxAlignment BoxAlign() const {
    return static_cast<EBoxAlignment>(misc_data_->box_align_);
  }




  // box-decoration-break
  EBoxDecorationBreak BoxDecorationBreak() const {
    return static_cast<EBoxDecorationBreak>(box_data_->box_decoration_break_);
  }




  // -webkit-box-direction
  



  // -webkit-box-flex
  float BoxFlex() const {
    return misc_data_->misc_6_data_->box_flex_;
  }




  // -webkit-box-ordinal-group
  unsigned BoxOrdinalGroup() const {
    return misc_data_->misc_7_data_->box_ordinal_group_;
  }




  // -webkit-box-orient
  EBoxOrient BoxOrient() const {
    return static_cast<EBoxOrient>(misc_data_->box_orient_);
  }




  // -webkit-box-pack
  EBoxPack BoxPack() const {
    return static_cast<EBoxPack>(misc_data_->box_pack_);
  }




  // -webkit-box-reflect
  StyleReflection* BoxReflect() const {
    return misc_data_->misc_7_data_->box_reflect_.Get();
  }



  // box-shadow
  ShadowList* BoxShadow() const {
    return misc_data_->misc_1_data_->box_shadow_.Get();
  }



  // box-sizing
  EBoxSizing BoxSizing() const {
    return static_cast<EBoxSizing>(data_.box_sizing_);
  }




  // break-after
  EBreakBetween BreakAfter() const {
    return static_cast<EBreakBetween>(misc_data_->break_after_);
  }




  // break-before
  EBreakBetween BreakBefore() const {
    return static_cast<EBreakBetween>(misc_data_->break_before_);
  }




  // break-inside
  EBreakInside BreakInside() const {
    return static_cast<EBreakInside>(misc_data_->break_inside_);
  }




  // buffered-rendering
  EBufferedRendering BufferedRendering() const {
    return static_cast<EBufferedRendering>(svg_data_->buffered_rendering_);
  }




  // CallbackSelectors
  const Vector<String>& CallbackSelectors() const {
    return misc_data_->misc_8_data_->callback_selectors_;
  }






  // CanAffectAnimations
  bool CanAffectAnimations() const {
    return static_cast<bool>(misc_data_->can_affect_animations_);
  }



  // stroke-linecap
  LineCap CapStyle() const {
    return static_cast<LineCap>(svginherited_data_->stroke_data_->cap_style_);
  }




  // caption-side
  ECaptionSide CaptionSide() const {
    return static_cast<ECaptionSide>(data_.caption_side_);
  }




  // caption-side
  bool CaptionSideIsInherited() const {
    return static_cast<bool>(data_.caption_side_is_inherited_);
  }




  // caret-animation
  ECaretAnimation CaretAnimation() const {
    return static_cast<ECaretAnimation>(data_.caret_animation_);
  }




  // caret-color
  





  // caret-shape
  ECaretShape CaretShape() const {
    return static_cast<ECaretShape>(data_.caret_shape_);
  }




  // ChildHasExplicitInheritance
  bool ChildHasExplicitInheritance() const {
    return static_cast<bool>(data_.child_has_explicit_inheritance_);
  }

  void SetChildHasExplicitInheritance() const {
    data_.child_has_explicit_inheritance_ = static_cast<unsigned>(true);
  }


  // clear
  



  // clip
  const LengthBox& Clip() const {
    return visual_data_->clip_;
  }






  // clip-path
  





  // clip-rule
  WindRule ClipRule() const {
    return static_cast<WindRule>(svginherited_data_->clip_rule_);
  }




  // color
  





  // color-interpolation
  EColorInterpolation ColorInterpolation() const {
    return static_cast<EColorInterpolation>(svginherited_data_->color_interpolation_);
  }




  // color-interpolation-filters
  EColorInterpolation ColorInterpolationFilters() const {
    return static_cast<EColorInterpolation>(svginherited_data_->color_interpolation_filters_);
  }




  // ColorIsCurrentColor
  



  // color
  



  // color-rendering
  EColorRendering ColorRendering() const {
    return static_cast<EColorRendering>(svginherited_data_->color_rendering_);
  }




  // color-scheme
  const Vector<AtomicString>& ColorScheme() const {
    return misc_inherited_data_->misc_inherited_1_data_->color_scheme_;
  }






  // ColorSchemeFlagsIsNormal
  bool ColorSchemeFlagsIsNormal() const {
    return static_cast<bool>(data_.color_scheme_flags_is_normal_);
  }




  // ColorSchemeForced
  bool ColorSchemeForced() const {
    return static_cast<bool>(data_.color_scheme_forced_);
  }




  // column-count
  unsigned short ColumnCount() const {
    return misc_data_->misc_1_data_->column_count_;
  }




  // column-fill
  EColumnFill GetColumnFill() const {
    return static_cast<EColumnFill>(misc_data_->column_fill_);
  }




  // column-gap
  const std::optional<Length>& ColumnGap() const {
    return misc_data_->misc_1_data_->column_gap_;
  }






  // column-height
  float ColumnHeight() const {
    return misc_data_->misc_1_data_->column_height_;
  }




  // column-rule-break
  RuleBreak ColumnRuleBreak() const {
    return static_cast<RuleBreak>(misc_data_->column_rule_break_);
  }




  // column-rule-color
  const GapDataList<StyleColor>& ColumnRuleColor() const {
    return misc_data_->misc_1_data_->column_rule_color_;
  }






  // column-rule-inset-cap-end
  const Length& ColumnRuleInsetCapEnd() const {
    return misc_data_->misc_1_data_->column_rule_inset_cap_end_;
  }






  // column-rule-inset-cap-start
  const Length& ColumnRuleInsetCapStart() const {
    return misc_data_->misc_1_data_->column_rule_inset_cap_start_;
  }






  // column-rule-inset-junction-end
  const Length& ColumnRuleInsetJunctionEnd() const {
    return misc_data_->misc_2_data_->column_rule_inset_junction_end_;
  }






  // column-rule-inset-junction-start
  const Length& ColumnRuleInsetJunctionStart() const {
    return misc_data_->misc_2_data_->column_rule_inset_junction_start_;
  }






  // column-rule-style
  const GapDataList<EBorderStyle>& ColumnRuleStyle() const {
    return misc_data_->misc_2_data_->column_rule_style_;
  }






  // column-rule-visibility-items
  RuleVisibilityItems ColumnRuleVisibilityItems() const {
    return static_cast<RuleVisibilityItems>(misc_data_->column_rule_visibility_items_);
  }




  // column-rule-width
  const GapDataList<int>& ColumnRuleWidth() const {
    return misc_data_->misc_2_data_->column_rule_width_;
  }






  // column-span
  EColumnSpan GetColumnSpan() const {
    return static_cast<EColumnSpan>(misc_data_->column_span_);
  }




  // column-width
  float ColumnWidth() const {
    return misc_data_->misc_2_data_->column_width_;
  }




  // column-wrap
  EColumnWrap ColumnWrap() const {
    return static_cast<EColumnWrap>(misc_data_->column_wrap_);
  }




  // contain
  unsigned Contain() const {
    return static_cast<unsigned>(misc_data_->contain_);
  }




  // contain-intrinsic-height
  const StyleIntrinsicLength& ContainIntrinsicHeight() const {
    return surround_data_->contain_intrinsic_height_;
  }






  // contain-intrinsic-width
  const StyleIntrinsicLength& ContainIntrinsicWidth() const {
    return surround_data_->contain_intrinsic_width_;
  }






  // ContainerFont
  Font* ContainerFont() const {
    return inherited_data_->container_font_.Get();
  }



  // container-name
  const Vector<AtomicString>& ContainerName() const {
    return misc_data_->misc_2_data_->container_name_;
  }






  // container-type
  unsigned ContainerType() const {
    return static_cast<unsigned>(misc_data_->container_type_);
  }




  // content
  





  // content-visibility
  EContentVisibility ContentVisibility() const {
    return static_cast<EContentVisibility>(data_.content_visibility_);
  }




  // Continue
  EContinue Continue() const {
    return static_cast<EContinue>(misc_data_->continue_);
  }




  // corner-bottom-left-shape
  const Superellipse& CornerBottomLeftShape() const {
    return surround_data_->corner_bottom_left_shape_;
  }






  // corner-bottom-right-shape
  const Superellipse& CornerBottomRightShape() const {
    return surround_data_->corner_bottom_right_shape_;
  }






  // corner-top-left-shape
  const Superellipse& CornerTopLeftShape() const {
    return surround_data_->corner_top_left_shape_;
  }






  // corner-top-right-shape
  const Superellipse& CornerTopRightShape() const {
    return surround_data_->corner_top_right_shape_;
  }






  // CounterDirectives
  





  // CounterIncrementList
  CounterPropertyList* CounterIncrementList() const {
    return misc_data_->misc_7_data_->counter_increment_list_.get();
  }



  // CounterResetList
  CounterPropertyList* CounterResetList() const {
    return misc_data_->misc_7_data_->counter_reset_list_.get();
  }



  // CounterSetList
  CounterPropertyList* CounterSetList() const {
    return misc_data_->misc_7_data_->counter_set_list_.get();
  }



  // CssDominantBaseline
  EDominantBaseline CssDominantBaseline() const {
    return static_cast<EDominantBaseline>(svginherited_data_->css_dominant_baseline_);
  }




  // cursor
  ECursor Cursor() const {
    return static_cast<ECursor>(inherited_data_->cursor_);
  }




  // CursorData
  





  // cursor
  bool CursorIsInherited() const {
    return static_cast<bool>(data_.cursor_is_inherited_);
  }




  // CustomHighlightNames
  





  // CustomStyleCallbackDependsOnFont
  bool CustomStyleCallbackDependsOnFont() const {
    return static_cast<bool>(data_.custom_style_callback_depends_on_font_);
  }



  // cx
  const Length& Cx() const {
    return svg_data_->geometry_data_->cx_;
  }






  // cy
  const Length& Cy() const {
    return svg_data_->geometry_data_->cy_;
  }






  // d
  StylePath* D() const {
    return svg_data_->geometry_data_->d_.Get();
  }



  // DarkColorScheme
  bool DarkColorScheme() const {
    return static_cast<bool>(data_.dark_color_scheme_);
  }




  // DependsOnAnchoredContainerQueries
  bool DependsOnAnchoredContainerQueries() const {
    return static_cast<bool>(misc_data_->depends_on_anchored_container_queries_);
  }




  // DependsOnScrollStateContainerQueries
  bool DependsOnScrollStateContainerQueries() const {
    return static_cast<bool>(misc_data_->depends_on_scroll_state_container_queries_);
  }




  // DependsOnSizeContainerQueries
  bool DependsOnSizeContainerQueries() const {
    return static_cast<bool>(misc_data_->depends_on_size_container_queries_);
  }




  // DependsOnStyleContainerQueries
  bool DependsOnStyleContainerQueries() const {
    return static_cast<bool>(misc_data_->depends_on_style_container_queries_);
  }




  // direction
  TextDirection Direction() const {
    return static_cast<TextDirection>(data_.direction_);
  }




  // Display
  EDisplay Display() const {
    return static_cast<EDisplay>(data_.display_);
  }




  // DisplayLayoutCustomName
  const AtomicString& DisplayLayoutCustomName() const {
    return misc_data_->misc_7_data_->display_layout_custom_name_;
  }






  // DisplayLayoutCustomParentName
  const AtomicString& DisplayLayoutCustomParentName() const {
    return misc_data_->misc_7_data_->display_layout_custom_parent_name_;
  }






  // DocumentRulesSelectors
  const Member<GCedHeapHashSet<WeakMember<StyleRule>>>& DocumentRulesSelectors() const {
    return misc_data_->misc_8_data_->document_rules_selectors_;
  }






  // dominant-baseline
  EDominantBaseline DominantBaseline() const {
    return static_cast<EDominantBaseline>(svginherited_data_->dominant_baseline_);
  }




  // window-drag
  EDraggableRegionMode DraggableRegionMode() const {
    return static_cast<EDraggableRegionMode>(misc_inherited_data_->draggable_region_mode_);
  }




  // dynamic-range-limit
  const DynamicRangeLimit& GetDynamicRangeLimit() const {
    return misc_inherited_data_->misc_inherited_1_data_->dynamic_range_limit_;
  }






  // EffectiveAppearance
  AppearanceValue EffectiveAppearance() const {
    return static_cast<AppearanceValue>(misc_data_->effective_appearance_);
  }




  // EffectiveTouchAction
  TouchAction EffectiveTouchAction() const {
    return static_cast<TouchAction>(misc_inherited_data_->misc_inherited_2_data_->effective_touch_action_);
  }




  // EffectiveZoom
  float EffectiveZoom() const {
    return misc_inherited_data_->misc_inherited_2_data_->effective_zoom_;
  }




  // ElementIsViewTransitionParticipant
  bool ElementIsViewTransitionParticipant() const {
    return static_cast<bool>(misc_data_->element_is_view_transition_participant_);
  }



  // empty-cells
  EEmptyCells EmptyCells() const {
    return static_cast<EEmptyCells>(misc_inherited_data_->empty_cells_);
  }




  // empty-cells
  bool EmptyCellsIsInherited() const {
    return static_cast<bool>(data_.empty_cells_is_inherited_);
  }




  // field-sizing
  EFieldSizing FieldSizing() const {
    return static_cast<EFieldSizing>(visual_data_->field_sizing_);
  }




  // fill-opacity
  float FillOpacity() const {
    return svginherited_data_->fill_data_->fill_opacity_;
  }




  // fill
  const SVGPaint& FillPaint() const {
    return svginherited_data_->fill_data_->fill_paint_;
  }






  // fill-rule
  WindRule FillRule() const {
    return static_cast<WindRule>(svginherited_data_->fill_rule_);
  }




  // filter
  const FilterOperations& Filter() const {
    return misc_data_->misc_2_data_->filter_;
  }






  // FirstLineDependsOnSizeContainerQueries
  bool FirstLineDependsOnSizeContainerQueries() const {
    return static_cast<bool>(misc_data_->first_line_depends_on_size_container_queries_);
  }




  // flex-basis
  const Length& FlexBasis() const {
    return misc_data_->misc_2_data_->flex_basis_;
  }






  // flex-direction
  EFlexDirection FlexDirection() const {
    return static_cast<EFlexDirection>(misc_data_->flex_direction_);
  }




  // flex-grow
  float FlexGrow() const {
    return misc_data_->misc_2_data_->flex_grow_;
  }




  // flex-line-count
  uint16_t FlexLineCount() const {
    return misc_data_->misc_2_data_->flex_line_count_;
  }




  // flex-shrink
  float FlexShrink() const {
    return misc_data_->misc_2_data_->flex_shrink_;
  }




  // flex-wrap
  const StyleFlexWrapData& FlexWrap() const {
    return misc_data_->misc_2_data_->flex_wrap_;
  }






  // float
  



  // flood-color
  const StyleColor& FloodColor() const {
    return svg_data_->svgmisc_data_->flood_color_;
  }






  // flood-opacity
  float FloodOpacity() const {
    return svg_data_->svgmisc_data_->flood_opacity_;
  }




  // flow-tolerance
  const FlowTolerance& GetFlowTolerance() const {
    return misc_data_->misc_2_data_->flow_tolerance_;
  }






  // font
  Font* GetFont() const {
    return inherited_data_->font_.Get();
  }



  // forced-color-adjust
  EForcedColorAdjust ForcedColorAdjust() const {
    return static_cast<EForcedColorAdjust>(misc_inherited_data_->forced_color_adjust_);
  }




  // ForcesBlockifiesChildren
  bool ForcesBlockifiesChildren() const {
    return static_cast<bool>(misc_data_->forces_blockifies_children_);
  }



  // ForcesStackingContext
  bool ForcesStackingContext() const {
    return static_cast<bool>(data_.forces_stacking_context_);
  }




  // frame-sizing
  EFrameSizing FrameSizing() const {
    return static_cast<EFrameSizing>(surround_data_->frame_sizing_);
  }




  // grid-auto-columns
  const GridTrackList& GridAutoColumns() const {
    return misc_data_->misc_2_data_->grid_auto_columns_;
  }






  // grid-auto-flow
  



  // grid-auto-rows
  const GridTrackList& GridAutoRows() const {
    return misc_data_->misc_2_data_->grid_auto_rows_;
  }






  // grid-column-end
  const GridPosition& GridColumnEnd() const {
    return misc_data_->misc_3_data_->grid_column_end_;
  }






  // grid-column-start
  const GridPosition& GridColumnStart() const {
    return misc_data_->misc_3_data_->grid_column_start_;
  }






  // grid-lanes-direction
  const GridLanesDirection& GetGridLanesDirection() const {
    return misc_data_->misc_3_data_->grid_lanes_direction_;
  }






  // grid-lanes-pack
  EGridLanesPack GridLanesPack() const {
    return static_cast<EGridLanesPack>(misc_data_->grid_lanes_pack_);
  }




  // grid-row-end
  const GridPosition& GridRowEnd() const {
    return misc_data_->misc_3_data_->grid_row_end_;
  }






  // grid-row-start
  const GridPosition& GridRowStart() const {
    return misc_data_->misc_3_data_->grid_row_start_;
  }






  // grid-template-areas
  const Member<ComputedGridTemplateAreas>& GridTemplateAreas() const {
    return misc_data_->misc_3_data_->grid_template_areas_;
  }






  // grid-template-columns
  const Member<ComputedGridTrackList>& SpecifiedGridTemplateColumns() const {
    return misc_data_->misc_3_data_->grid_template_columns_;
  }






  // grid-template-rows
  const Member<ComputedGridTrackList>& SpecifiedGridTemplateRows() const {
    return misc_data_->misc_3_data_->grid_template_rows_;
  }






  // hanging-punctuation
  HangingPunctuation GetHangingPunctuation() const {
    return static_cast<HangingPunctuation>(misc_inherited_data_->hanging_punctuation_);
  }




  // HasAnchorEvaluator
  bool HasAnchorEvaluator() const {
    return static_cast<bool>(surround_data_->has_anchor_evaluator_);
  }



  // HasAnchorFunctions
  bool HasAnchorFunctions() const {
    return static_cast<bool>(surround_data_->has_anchor_functions_);
  }



  // HasAttrFunction
  bool HasAttrFunction() const {
    return static_cast<bool>(data_.has_attr_function_);
  }



  // HasAuthorBackground
  bool HasAuthorBackground() const {
    return static_cast<bool>(data_.has_author_background_);
  }



  // HasAuthorBorder
  bool HasAuthorBorder() const {
    return static_cast<bool>(data_.has_author_border_);
  }



  // HasAuthorBorderRadius
  bool HasAuthorBorderRadius() const {
    return static_cast<bool>(data_.has_author_border_radius_);
  }



  // HasAuthorHighlightColors
  bool HasAuthorHighlightColors() const {
    return static_cast<bool>(data_.has_author_highlight_colors_);
  }



  // HasAutoClip
  bool HasAutoClip() const {
    return static_cast<bool>(visual_data_->has_auto_clip_);
  }




  // HasAutoColumnCount
  bool HasAutoColumnCount() const {
    return static_cast<bool>(misc_data_->has_auto_column_count_);
  }




  // HasAutoColumnHeight
  bool HasAutoColumnHeight() const {
    return static_cast<bool>(misc_data_->has_auto_column_height_);
  }




  // HasAutoColumnWidth
  bool HasAutoColumnWidth() const {
    return static_cast<bool>(misc_data_->has_auto_column_width_);
  }




  // HasAutoZIndex
  bool HasAutoZIndex() const {
    return static_cast<bool>(box_data_->has_auto_z_index_);
  }




  // HasClipPath
  bool HasClipPath() const {
    return static_cast<bool>(visual_data_->has_clip_path_);
  }




  // HasContainerRelativeValue
  bool HasContainerRelativeValue() const {
    return static_cast<bool>(data_.has_container_relative_value_);
  }



  // HasCurrentBackdropFilterAnimation
  bool HasCurrentBackdropFilterAnimation() const {
    return static_cast<bool>(misc_data_->has_current_backdrop_filter_animation_);
  }




  // HasCurrentBackgroundColorAnimation
  bool HasCurrentBackgroundColorAnimation() const {
    return static_cast<bool>(misc_data_->has_current_background_color_animation_);
  }




  // HasCurrentClipPathAnimation
  bool HasCurrentClipPathAnimation() const {
    return static_cast<bool>(misc_data_->has_current_clip_path_animation_);
  }




  // HasCurrentFilterAnimation
  bool HasCurrentFilterAnimation() const {
    return static_cast<bool>(misc_data_->has_current_filter_animation_);
  }




  // HasCurrentOpacityAnimation
  bool HasCurrentOpacityAnimation() const {
    return static_cast<bool>(misc_data_->has_current_opacity_animation_);
  }




  // HasCurrentRotateAnimation
  bool HasCurrentRotateAnimation() const {
    return static_cast<bool>(misc_data_->has_current_rotate_animation_);
  }




  // HasCurrentScaleAnimation
  bool HasCurrentScaleAnimation() const {
    return static_cast<bool>(misc_data_->has_current_scale_animation_);
  }




  // HasCurrentTransformAnimation
  bool HasCurrentTransformAnimation() const {
    return static_cast<bool>(misc_data_->has_current_transform_animation_);
  }




  // HasCurrentTranslateAnimation
  bool HasCurrentTranslateAnimation() const {
    return static_cast<bool>(misc_data_->has_current_translate_animation_);
  }




  // HasCustomHighlightUniversalSelector
  bool HasCustomHighlightUniversalSelector() const {
    return static_cast<bool>(misc_data_->has_custom_highlight_universal_selector_);
  }




  // HasElementDependentRandomFunctions
  bool HasElementDependentRandomFunctions() const {
    return static_cast<bool>(misc_data_->has_element_dependent_random_functions_);
  }



  // HasEmUnits
  bool HasEmUnits() const {
    return static_cast<bool>(data_.has_em_units_);
  }



  // HasEnv
  bool HasEnv() const {
    return static_cast<bool>(data_.has_env_);
  }



  // HasEnvSafeAreaInsetBottom
  bool HasEnvSafeAreaInsetBottom() const {
    return static_cast<bool>(misc_data_->has_env_safe_area_inset_bottom_);
  }



  // HasExplicitInheritance
  bool HasExplicitInheritance() const {
    return static_cast<bool>(data_.has_explicit_inheritance_);
  }



  // HasExplicitOverflowXVisible
  bool HasExplicitOverflowXVisible() const {
    return static_cast<bool>(misc_data_->has_explicit_overflow_x_visible_);
  }



  // HasExplicitOverflowYVisible
  bool HasExplicitOverflowYVisible() const {
    return static_cast<bool>(misc_data_->has_explicit_overflow_y_visible_);
  }



  // HasGlyphRelativeUnits
  bool HasGlyphRelativeUnits() const {
    return static_cast<bool>(data_.has_glyph_relative_units_);
  }



  // HasLayoutContainmentForViewTransitionScope
  bool HasLayoutContainmentForViewTransitionScope() const {
    return static_cast<bool>(misc_data_->has_layout_containment_for_view_transition_scope_);
  }




  // HasLineHeightRelativeUnits
  bool HasLineHeightRelativeUnits() const {
    return static_cast<bool>(misc_data_->has_line_height_relative_units_);
  }



  // -internal-empty-line-height
  bool HasLineIfEmpty() const {
    return static_cast<bool>(misc_inherited_data_->has_line_if_empty_);
  }




  // HasLogicalDirectionRelativeUnits
  bool HasLogicalDirectionRelativeUnits() const {
    return static_cast<bool>(data_.has_logical_direction_relative_units_);
  }



  // HasNonUaHighlightPseudoStyles
  bool HasNonUaHighlightPseudoStyles() const {
    return static_cast<bool>(misc_data_->has_non_ua_highlight_pseudo_styles_);
  }




  // HasNonUniversalHighlightPseudoStyles
  bool HasNonUniversalHighlightPseudoStyles() const {
    return static_cast<bool>(misc_data_->has_non_universal_highlight_pseudo_styles_);
  }




  // HasRootRelativeUnits
  bool HasRootRelativeUnits() const {
    return static_cast<bool>(data_.has_root_relative_units_);
  }



  // HasSiblingFunctions
  bool HasSiblingFunctions() const {
    return static_cast<bool>(misc_data_->has_sibling_functions_);
  }



  // HasSizeContainmentForViewTransitionScope
  bool HasSizeContainmentForViewTransitionScope() const {
    return static_cast<bool>(misc_data_->has_size_containment_for_view_transition_scope_);
  }




  // HasVariableDeclaration
  bool HasVariableDeclaration() const {
    return static_cast<bool>(data_.has_variable_declaration_);
  }



  // HasVariableReference
  bool HasVariableReference() const {
    return static_cast<bool>(data_.has_variable_reference_);
  }



  // height
  const Length& Height() const {
    return box_data_->height_;
  }






  // HighlightData
  const StyleHighlightData& HighlightData() const {
    return inherited_data_->highlight_data_data_->highlight_data_;
  }






  // HighlightsDependOnSizeContainerQueries
  bool HighlightsDependOnSizeContainerQueries() const {
    return static_cast<bool>(misc_data_->highlights_depend_on_size_container_queries_);
  }




  // -webkit-border-horizontal-spacing
  short HorizontalBorderSpacing() const {
    return inherited_data_->horizontal_border_spacing_;
  }




  // hyphenate-limit-chars
  const StyleHyphenateLimitChars& HyphenateLimitChars() const {
    return misc_inherited_data_->misc_inherited_1_data_->hyphenate_limit_chars_;
  }






  // hyphenate-character
  const AtomicString& HyphenationString() const {
    return misc_inherited_data_->misc_inherited_1_data_->hyphenation_string_;
  }






  // hyphens
  Hyphens GetHyphens() const {
    return static_cast<Hyphens>(misc_inherited_data_->hyphens_);
  }




  // image-animation
  ImageAnimationEnum ImageAnimation() const {
    return static_cast<ImageAnimationEnum>(misc_inherited_data_->image_animation_);
  }




  // image-orientation
  RespectImageOrientationEnum ImageOrientation() const {
    return static_cast<RespectImageOrientationEnum>(misc_inherited_data_->image_orientation_);
  }




  // image-rendering
  EImageRendering ImageRendering() const {
    return static_cast<EImageRendering>(misc_inherited_data_->image_rendering_);
  }




  // InBaseAppearance
  bool InBaseAppearance() const {
    return static_cast<bool>(misc_inherited_data_->in_base_appearance_);
  }




  // InForcedColorsMode
  bool InForcedColorsMode() const {
    return static_cast<bool>(inherited_data_->in_forced_colors_mode_);
  }




  // InheritedVariables
  





  // InitialData
  StyleInitialData* InitialData() const {
    return misc_inherited_data_->misc_inherited_2_data_->initial_data_.Get();
  }



  // initial-letter
  const StyleInitialLetter& InitialLetter() const {
    return misc_data_->misc_3_data_->initial_letter_;
  }






  // InlineBlockBaselineEdge
  EInlineBlockBaselineEdge InlineBlockBaselineEdge() const {
    return static_cast<EInlineBlockBaselineEdge>(data_.inline_block_baseline_edge_);
  }




  // InlineStyleLostCascade
  bool InlineStyleLostCascade() const {
    return static_cast<bool>(misc_data_->inline_style_lost_cascade_);
  }




  // InsideLink
  EInsideLink InsideLink() const {
    return static_cast<EInsideLink>(data_.inside_link_);
  }




  // interactivity
  EInteractivity Interactivity() const {
    return static_cast<EInteractivity>(misc_inherited_data_->interactivity_);
  }




  // interactivity
  bool InteractivityIsInherited() const {
    return static_cast<bool>(data_.interactivity_is_inherited_);
  }




  // interest-delay-end
  const StyleInterestDelay& InterestDelayEnd() const {
    return misc_data_->misc_3_data_->interest_delay_end_;
  }






  // interest-delay-start
  const StyleInterestDelay& InterestDelayStart() const {
    return misc_data_->misc_3_data_->interest_delay_start_;
  }






  // -internal-forced-background-color
  





  // -internal-forced-border-color
  





  // -internal-forced-color
  





  // -internal-forced-outline-color
  





  // -internal-forced-visited-color
  





  // -internal-overscroll-container
  EInternalOverscrollContainer InternalOverscrollContainer() const {
    return static_cast<EInternalOverscrollContainer>(misc_data_->internal_overscroll_container_);
  }




  // -internal-overscroll-position
  EInternalOverscrollPosition InternalOverscrollPosition() const {
    return static_cast<EInternalOverscrollPosition>(misc_data_->internal_overscroll_position_);
  }




  // -internal-unbounded
  EInternalUnbounded InternalUnbounded() const {
    return static_cast<EInternalUnbounded>(misc_data_->internal_unbounded_);
  }




  // -internal-visited-background-color
  





  // -internal-visited-border-bottom-color
  





  // -internal-visited-border-left-color
  





  // -internal-visited-border-right-color
  





  // -internal-visited-border-top-color
  





  // -internal-visited-caret-color
  





  // -internal-visited-color
  





  // InternalVisitedColorIsCurrentColor
  



  // -internal-visited-column-rule-color
  const GapDataList<StyleColor>& InternalVisitedColumnRuleColor() const {
    return misc_data_->visited_data_->internal_visited_column_rule_color_;
  }






  // -internal-visited-fill
  const SVGPaint& InternalVisitedFillPaint() const {
    return svginherited_data_->fill_data_->internal_visited_fill_paint_;
  }






  // -internal-visited-outline-color
  





  // -internal-visited-stroke
  const SVGPaint& InternalVisitedStrokePaint() const {
    return svginherited_data_->stroke_data_->internal_visited_stroke_paint_;
  }






  // -internal-visited-text-decoration-color
  





  // -internal-visited-text-emphasis-color
  





  // -internal-visited-text-fill-color
  





  // -internal-visited-text-stroke-color
  





  // interpolate-size
  EInterpolateSize InterpolateSize() const {
    return static_cast<EInterpolateSize>(misc_inherited_data_->interpolate_size_);
  }




  // IsBottomRelativeToSafeAreaInset
  bool IsBottomRelativeToSafeAreaInset() const {
    return static_cast<bool>(misc_data_->is_bottom_relative_to_safe_area_inset_);
  }




  // IsCSSInert
  bool IsCSSInert() const {
    return static_cast<bool>(data_.is_css_inert_);
  }




  // IsCSSInert
  bool IsCSSInertIsInherited() const {
    return static_cast<bool>(data_.is_css_inert_is_inherited_);
  }




  // IsEnsuredInDisplayNone
  bool IsEnsuredInDisplayNone() const {
    return static_cast<bool>(data_.is_ensured_in_display_none_);
  }



  // IsFlexOrGridOrCustomItem
  bool IsFlexOrGridOrCustomItem() const {
    return static_cast<bool>(data_.is_flex_or_grid_or_custom_item_);
  }



  // IsHTMLInert
  bool IsHTMLInert() const {
    return static_cast<bool>(data_.is_html_inert_);
  }




  // IsHTMLInert
  bool IsHTMLInertIsInherited() const {
    return static_cast<bool>(data_.is_html_inert_is_inherited_);
  }




  // IsInBlockifyingDisplay
  bool IsInBlockifyingDisplay() const {
    return static_cast<bool>(data_.is_in_blockifying_display_);
  }



  // IsInInlinifyingDisplay
  bool IsInInlinifyingDisplay() const {
    return static_cast<bool>(data_.is_in_inlinifying_display_);
  }



  // IsInShrinkToFitSubtree
  bool IsInShrinkToFitSubtree() const {
    return static_cast<bool>(misc_inherited_data_->is_in_shrink_to_fit_subtree_);
  }




  // IsInsideDisplayIgnoringFloatingChildren
  bool IsInsideDisplayIgnoringFloatingChildren() const {
    return static_cast<bool>(data_.is_inside_display_ignoring_floating_children_);
  }



  // IsLink
  bool IsLink() const {
    return static_cast<bool>(data_.is_link_);
  }



  // IsOriginalDisplayInlineType
  bool IsOriginalDisplayInlineType() const {
    return static_cast<bool>(data_.is_original_display_inline_type_);
  }




  // IsPageMarginBox
  bool IsPageMarginBox() const {
    return static_cast<bool>(data_.is_page_margin_box_);
  }




  // IsRunningBackdropFilterAnimationOnCompositor
  bool IsRunningBackdropFilterAnimationOnCompositor() const {
    return static_cast<bool>(misc_data_->is_running_backdrop_filter_animation_on_compositor_);
  }




  // IsRunningFilterAnimationOnCompositor
  bool IsRunningFilterAnimationOnCompositor() const {
    return static_cast<bool>(misc_data_->is_running_filter_animation_on_compositor_);
  }




  // IsRunningOpacityAnimationOnCompositor
  bool IsRunningOpacityAnimationOnCompositor() const {
    return static_cast<bool>(misc_data_->is_running_opacity_animation_on_compositor_);
  }




  // IsRunningRotateAnimationOnCompositor
  bool IsRunningRotateAnimationOnCompositor() const {
    return static_cast<bool>(misc_data_->is_running_rotate_animation_on_compositor_);
  }




  // IsRunningScaleAnimationOnCompositor
  bool IsRunningScaleAnimationOnCompositor() const {
    return static_cast<bool>(misc_data_->is_running_scale_animation_on_compositor_);
  }




  // IsRunningTransformAnimationOnCompositor
  bool IsRunningTransformAnimationOnCompositor() const {
    return static_cast<bool>(misc_data_->is_running_transform_animation_on_compositor_);
  }




  // IsRunningTranslateAnimationOnCompositor
  bool IsRunningTranslateAnimationOnCompositor() const {
    return static_cast<bool>(misc_data_->is_running_translate_animation_on_compositor_);
  }




  // IsSecondaryBodyElement
  bool IsSecondaryBodyElement() const {
    return static_cast<bool>(misc_data_->is_secondary_body_element_);
  }



  // IsSpecifiedDisplayWebkitBox
  bool IsSpecifiedDisplayWebkitBox() const {
    return static_cast<bool>(misc_data_->is_specified_display_webkit_box_);
  }



  // IsStackingContextWithoutContainment
  bool CORE_EXPORT IsStackingContextWithoutContainment() const;


  // IsStartingStyle
  bool IsStartingStyle() const {
    return static_cast<bool>(misc_data_->is_starting_style_);
  }



  // isolation
  EIsolation Isolation() const {
    return static_cast<EIsolation>(misc_data_->isolation_);
  }




  // stroke-linejoin
  LineJoin JoinStyle() const {
    return static_cast<LineJoin>(svginherited_data_->stroke_data_->join_style_);
  }




  // justify-content
  const StyleContentAlignmentData& JustifyContent() const {
    return box_data_->justify_content_;
  }






  // justify-items
  const StyleSelfAlignmentData& JustifyItems() const {
    return misc_data_->misc_3_data_->justify_items_;
  }






  // justify-self
  const StyleSelfAlignmentData& JustifySelf() const {
    return misc_data_->misc_3_data_->justify_self_;
  }






  // left
  const Length& Left() const {
    return surround_data_->left_;
  }






  // letter-spacing
  





  // lighting-color
  const StyleColor& LightingColor() const {
    return svg_data_->svgmisc_data_->lighting_color_;
  }






  // line-break
  LineBreak GetLineBreak() const {
    return static_cast<LineBreak>(misc_inherited_data_->line_break_);
  }




  // LineClampInternalBlockEllipsis
  EBlockEllipsis LineClampInternalBlockEllipsis() const {
    return static_cast<EBlockEllipsis>(misc_data_->line_clamp_internal_block_ellipsis_);
  }




  // line-height
  const Length& LineHeight() const {
    return inherited_data_->line_height_;
  }






  // list-style-image
  const Member<StyleImage>& ListStyleImage() const {
    return misc_inherited_data_->misc_inherited_1_data_->list_style_image_;
  }






  // list-style-position
  EListStylePosition ListStylePosition() const {
    return static_cast<EListStylePosition>(data_.list_style_position_);
  }




  // list-style-position
  bool ListStylePositionIsInherited() const {
    return static_cast<bool>(data_.list_style_position_is_inherited_);
  }




  // list-style-type
  const Member<ListStyleTypeData>& ListStyleType() const {
    return misc_inherited_data_->misc_inherited_1_data_->list_style_type_;
  }






  // margin-bottom
  const Length& MarginBottom() const {
    return box_data_->margin_bottom_;
  }






  // margin-left
  const Length& MarginLeft() const {
    return box_data_->margin_left_;
  }






  // margin-right
  const Length& MarginRight() const {
    return box_data_->margin_right_;
  }






  // margin-top
  const Length& MarginTop() const {
    return box_data_->margin_top_;
  }






  // margin-trim
  unsigned MarginTrim() const {
    return static_cast<unsigned>(misc_data_->margin_trim_);
  }




  // marker-end
  StyleSVGResource* MarkerEndResource() const {
    return svginherited_data_->resources_data_->marker_end_resource_.Get();
  }



  // marker-mid
  StyleSVGResource* MarkerMidResource() const {
    return svginherited_data_->resources_data_->marker_mid_resource_.Get();
  }



  // marker-start
  StyleSVGResource* MarkerStartResource() const {
    return svginherited_data_->resources_data_->marker_start_resource_.Get();
  }



  // Mask
  





  // MaskBoxImage
  





  // mask-type
  EMaskType MaskType() const {
    return static_cast<EMaskType>(svg_data_->mask_type_);
  }




  // MathBaseline
  const Length& GetMathBaseline() const {
    return misc_data_->math_data_->math_baseline_;
  }






  // math-depth
  short MathDepth() const {
    return misc_inherited_data_->misc_inherited_1_data_->math_depth_;
  }




  // MathFractionBarThickness
  const Length& GetMathFractionBarThickness() const {
    return misc_data_->math_data_->math_fraction_bar_thickness_;
  }






  // MathLSpace
  const Length& GetMathLSpace() const {
    return misc_data_->math_data_->math_l_space_;
  }






  // MathMaxSize
  const Length& GetMathMaxSize() const {
    return misc_data_->math_data_->math_max_size_;
  }






  // MathMinSize
  const Length& GetMathMinSize() const {
    return misc_data_->math_data_->math_min_size_;
  }






  // MathPaddedDepth
  const Length& GetMathPaddedDepth() const {
    return misc_data_->math_data_->math_padded_depth_;
  }






  // MathPaddedVOffset
  const Length& GetMathPaddedVOffset() const {
    return misc_data_->math_data_->math_padded_v_offset_;
  }






  // MathRSpace
  const Length& GetMathRSpace() const {
    return misc_data_->math_data_->math_r_space_;
  }






  // math-shift
  EMathShift MathShift() const {
    return static_cast<EMathShift>(misc_inherited_data_->math_shift_);
  }




  // math-style
  EMathStyle MathStyle() const {
    return static_cast<EMathStyle>(misc_inherited_data_->math_style_);
  }




  // max-content-sizing
  EMaxContentSizing MaxContentSizing() const {
    return static_cast<EMaxContentSizing>(misc_data_->max_content_sizing_);
  }




  // max-height
  const Length& MaxHeight() const {
    return box_data_->max_height_;
  }






  // MaxLines
  const MaxLinesData& MaxLines() const {
    return misc_data_->misc_8_data_->max_lines_;
  }






  // max-width
  const Length& MaxWidth() const {
    return box_data_->max_width_;
  }






  // MayHaveMargin
  bool MayHaveMargin() const {
    return static_cast<bool>(surround_data_->may_have_margin_);
  }



  // MayHavePadding
  bool MayHavePadding() const {
    return static_cast<bool>(surround_data_->may_have_padding_);
  }



  // MaybeHasGapDecorations
  bool MaybeHasGapDecorations() const {
    return static_cast<bool>(visual_data_->maybe_has_gap_decorations_);
  }



  // min-height
  const Length& MinHeight() const {
    return box_data_->min_height_;
  }






  // min-width
  const Length& MinWidth() const {
    return box_data_->min_width_;
  }






  // NonInheritedVariables
  





  // object-fit
  EObjectFit GetObjectFit() const {
    return static_cast<EObjectFit>(misc_data_->object_fit_);
  }




  // object-position
  const LengthPoint& ObjectPosition() const {
    return misc_data_->misc_3_data_->object_position_;
  }






  // object-view-box
  BasicShape* ObjectViewBox() const {
    return misc_data_->misc_3_data_->object_view_box_.Get();
  }



  // offset-anchor
  const LengthPoint& OffsetAnchor() const {
    return misc_data_->misc_3_data_->offset_anchor_;
  }






  // offset-distance
  const Length& OffsetDistance() const {
    return misc_data_->misc_4_data_->offset_distance_;
  }






  // offset-path
  OffsetPathOperation* OffsetPath() const {
    return misc_data_->misc_4_data_->offset_path_.Get();
  }



  // offset-position
  const LengthPoint& OffsetPosition() const {
    return misc_data_->misc_4_data_->offset_position_;
  }






  // offset-rotate
  const StyleOffsetRotation& OffsetRotate() const {
    return misc_data_->misc_4_data_->offset_rotate_;
  }






  // opacity
  float Opacity() const {
    return svg_data_->opacity_;
  }




  // order
  int Order() const {
    return misc_data_->misc_4_data_->order_;
  }




  // origin-trial-test-property
  EOriginTrialTestProperty OriginTrialTestProperty() const {
    return static_cast<EOriginTrialTestProperty>(data_.origin_trial_test_property_);
  }




  // orphans
  short Orphans() const {
    return misc_inherited_data_->misc_inherited_1_data_->orphans_;
  }




  // outline-color
  





  // outline-offset
  const int& OutlineOffset() const {
    return misc_data_->misc_4_data_->outline_offset_;
  }






  // outline-style
  EBorderStyle OutlineStyle() const {
    return static_cast<EBorderStyle>(misc_data_->outline_style_);
  }




  // OutlineStyleIsAuto
  bool OutlineStyleIsAuto() const {
    return static_cast<bool>(misc_data_->outline_style_is_auto_);
  }




  // outline-width
  const int& OutlineWidth() const {
    return misc_data_->misc_4_data_->outline_width_;
  }






  // overflow-anchor
  EOverflowAnchor OverflowAnchor() const {
    return static_cast<EOverflowAnchor>(data_.overflow_anchor_);
  }




  // overflow-clip-margin
  const std::optional<StyleOverflowClipMargin>& OverflowClipMargin() const {
    return box_data_->overflow_clip_margin_;
  }






  // overflow-wrap
  EOverflowWrap OverflowWrap() const {
    return static_cast<EOverflowWrap>(misc_inherited_data_->overflow_wrap_);
  }




  // overflow-x
  EOverflow OverflowX() const {
    return static_cast<EOverflow>(data_.overflow_x_);
  }




  // overflow-y
  EOverflow OverflowY() const {
    return static_cast<EOverflow>(data_.overflow_y_);
  }




  // overlay
  EOverlay Overlay() const {
    return static_cast<EOverlay>(misc_data_->overlay_);
  }




  // overscroll-behavior-x
  EOverscrollBehavior OverscrollBehaviorX() const {
    return static_cast<EOverscrollBehavior>(misc_data_->overscroll_behavior_x_);
  }




  // overscroll-behavior-y
  EOverscrollBehavior OverscrollBehaviorY() const {
    return static_cast<EOverscrollBehavior>(misc_data_->overscroll_behavior_y_);
  }




  // overscroll-container-type
  EOverscrollContainerType OverscrollContainerType() const {
    return static_cast<EOverscrollContainerType>(misc_data_->overscroll_container_type_);
  }




  // padding-bottom
  const Length& PaddingBottom() const {
    return box_data_->padding_bottom_;
  }






  // padding-left
  const Length& PaddingLeft() const {
    return box_data_->padding_left_;
  }






  // padding-right
  const Length& PaddingRight() const {
    return box_data_->padding_right_;
  }






  // padding-top
  const Length& PaddingTop() const {
    return box_data_->padding_top_;
  }






  // page
  const AtomicString& Page() const {
    return misc_data_->misc_4_data_->page_;
  }






  // page-margin-safety
  EPageMarginSafety GetPageMarginSafety() const {
    return static_cast<EPageMarginSafety>(misc_data_->page_margin_safety_);
  }




  // page-orientation
  PageOrientation GetPageOrientation() const {
    return static_cast<PageOrientation>(misc_data_->page_orientation_);
  }




  // PageSize
  const gfx::SizeF& PageSize() const {
    return misc_data_->misc_7_data_->page_size_;
  }






  // PageSizeType
  PageSizeType GetPageSizeType() const {
    return static_cast<PageSizeType>(misc_data_->page_size_type_);
  }




  // PaintImages
  





  // paint-order
  EPaintOrder PaintOrder() const {
    return static_cast<EPaintOrder>(svginherited_data_->paint_order_);
  }




  // path-length
  const Length& PathLength() const {
    return svg_data_->geometry_data_->path_length_;
  }






  // perspective
  float Perspective() const {
    return misc_data_->misc_4_data_->perspective_;
  }




  // perspective-origin
  const LengthPoint& PerspectiveOrigin() const {
    return misc_data_->misc_4_data_->perspective_origin_;
  }






  // pointer-events
  



  // pointer-events
  



  // position
  



  // position-anchor
  const StylePositionAnchor& PositionAnchor() const {
    return misc_data_->misc_1_data_->position_anchor_;
  }






  // position-area
  const PositionArea& GetPositionArea() const {
    return misc_data_->misc_1_data_->position_area_;
  }






  // PositionAreaOffsets
  const std::optional<blink::PositionAreaOffsets>& PositionAreaOffsets() const {
    return misc_data_->misc_8_data_->position_area_offsets_;
  }






  // position-try-fallbacks
  const Member<PositionTryFallbacks>& GetPositionTryFallbacks() const {
    return misc_data_->misc_4_data_->position_try_fallbacks_;
  }






  // position-try-order
  EPositionTryOrder PositionTryOrder() const {
    return static_cast<EPositionTryOrder>(misc_data_->position_try_order_);
  }




  // position-visibility
  PositionVisibility GetPositionVisibility() const {
    return static_cast<PositionVisibility>(misc_data_->position_visibility_);
  }




  // PrefersDefaultScrollbarStyles
  bool PrefersDefaultScrollbarStyles() const {
    return static_cast<bool>(data_.prefers_default_scrollbar_styles_);
  }




  // print-color-adjust
  EPrintColorAdjust PrintColorAdjust() const {
    return static_cast<EPrintColorAdjust>(data_.print_color_adjust_);
  }




  // PseudoElementStyles
  



  // quotes
  QuotesData* Quotes() const {
    return misc_inherited_data_->misc_inherited_1_data_->quotes_.get();
  }



  // r
  const Length& R() const {
    return svg_data_->geometry_data_->r_;
  }






  // reading-flow
  EReadingFlow ReadingFlow() const {
    return static_cast<EReadingFlow>(misc_data_->reading_flow_);
  }




  // reading-order
  int ReadingOrder() const {
    return misc_data_->misc_4_data_->reading_order_;
  }




  // RequiresAcceleratedCompositingForExternalReasons
  bool RequiresAcceleratedCompositingForExternalReasons() const {
    return static_cast<bool>(misc_data_->requires_accelerated_compositing_for_external_reasons_);
  }




  // resize
  



  // right
  const Length& Right() const {
    return surround_data_->right_;
  }






  // rotate
  RotateTransformOperation* Rotate() const {
    return misc_data_->misc_4_data_->rotate_.Get();
  }



  // row-gap
  const std::optional<Length>& RowGap() const {
    return misc_data_->misc_4_data_->row_gap_;
  }






  // row-rule-break
  RuleBreak RowRuleBreak() const {
    return static_cast<RuleBreak>(misc_data_->row_rule_break_);
  }




  // row-rule-color
  const GapDataList<StyleColor>& RowRuleColor() const {
    return misc_data_->misc_4_data_->row_rule_color_;
  }






  // row-rule-inset-cap-end
  const Length& RowRuleInsetCapEnd() const {
    return misc_data_->misc_5_data_->row_rule_inset_cap_end_;
  }






  // row-rule-inset-cap-start
  const Length& RowRuleInsetCapStart() const {
    return misc_data_->misc_5_data_->row_rule_inset_cap_start_;
  }






  // row-rule-inset-junction-end
  const Length& RowRuleInsetJunctionEnd() const {
    return misc_data_->misc_5_data_->row_rule_inset_junction_end_;
  }






  // row-rule-inset-junction-start
  const Length& RowRuleInsetJunctionStart() const {
    return misc_data_->misc_5_data_->row_rule_inset_junction_start_;
  }






  // row-rule-style
  const GapDataList<EBorderStyle>& RowRuleStyle() const {
    return misc_data_->misc_5_data_->row_rule_style_;
  }






  // row-rule-visibility-items
  RuleVisibilityItems RowRuleVisibilityItems() const {
    return static_cast<RuleVisibilityItems>(misc_data_->row_rule_visibility_items_);
  }




  // row-rule-width
  const GapDataList<int>& RowRuleWidth() const {
    return misc_data_->misc_5_data_->row_rule_width_;
  }






  // -webkit-rtl-ordering
  EOrder RtlOrdering() const {
    return static_cast<EOrder>(data_.rtl_ordering_);
  }




  // -webkit-rtl-ordering
  bool RtlOrderingIsInherited() const {
    return static_cast<bool>(data_.rtl_ordering_is_inherited_);
  }




  // ruby-align
  ERubyAlign RubyAlign() const {
    return static_cast<ERubyAlign>(misc_inherited_data_->ruby_align_);
  }




  // ruby-overhang
  ERubyOverhang RubyOverhang() const {
    return static_cast<ERubyOverhang>(misc_inherited_data_->ruby_overhang_);
  }




  // ruby-position
  RubyPosition GetRubyPosition() const {
    return static_cast<RubyPosition>(misc_inherited_data_->ruby_position_);
  }




  // rule-overlap
  ERuleOverlap RuleOverlap() const {
    return static_cast<ERuleOverlap>(misc_data_->rule_overlap_);
  }




  // rx
  const Length& Rx() const {
    return svg_data_->geometry_data_->rx_;
  }






  // ry
  const Length& Ry() const {
    return svg_data_->geometry_data_->ry_;
  }






  // scale
  ScaleTransformOperation* Scale() const {
    return misc_data_->misc_5_data_->scale_.Get();
  }



  // scroll-axis-lock
  EScrollAxisLock ScrollAxisLock() const {
    return static_cast<EScrollAxisLock>(misc_data_->scroll_axis_lock_);
  }




  // scroll-behavior
  mojom::blink::ScrollBehavior GetScrollBehavior() const {
    return static_cast<mojom::blink::ScrollBehavior>(misc_data_->scroll_behavior_);
  }




  // scroll-initial-target
  EScrollInitialTarget ScrollInitialTarget() const {
    return static_cast<EScrollInitialTarget>(misc_data_->scroll_initial_target_);
  }




  // scroll-margin-bottom
  float ScrollMarginBottom() const {
    return misc_data_->misc_5_data_->scroll_margin_bottom_;
  }




  // scroll-margin-left
  float ScrollMarginLeft() const {
    return misc_data_->misc_5_data_->scroll_margin_left_;
  }




  // scroll-margin-right
  float ScrollMarginRight() const {
    return misc_data_->misc_5_data_->scroll_margin_right_;
  }




  // scroll-margin-top
  float ScrollMarginTop() const {
    return misc_data_->misc_5_data_->scroll_margin_top_;
  }




  // scroll-marker-group
  ScrollMarkerGroup* GetScrollMarkerGroup() const {
    return misc_data_->misc_5_data_->scroll_marker_group_.Get();
  }



  // scroll-padding-bottom
  const Length& ScrollPaddingBottom() const {
    return misc_data_->misc_5_data_->scroll_padding_bottom_;
  }






  // scroll-padding-left
  const Length& ScrollPaddingLeft() const {
    return misc_data_->misc_5_data_->scroll_padding_left_;
  }






  // scroll-padding-right
  const Length& ScrollPaddingRight() const {
    return misc_data_->misc_5_data_->scroll_padding_right_;
  }






  // scroll-padding-top
  const Length& ScrollPaddingTop() const {
    return misc_data_->misc_5_data_->scroll_padding_top_;
  }






  // scroll-snap-align
  const cc::ScrollSnapAlign& GetScrollSnapAlign() const {
    return misc_data_->misc_6_data_->scroll_snap_align_;
  }






  // scroll-snap-stop
  EScrollSnapStop ScrollSnapStop() const {
    return static_cast<EScrollSnapStop>(data_.scroll_snap_stop_);
  }




  // scroll-snap-type
  const cc::ScrollSnapType& GetScrollSnapType() const {
    return misc_data_->misc_6_data_->scroll_snap_type_;
  }






  // scroll-target-group
  EScrollTargetGroup ScrollTargetGroup() const {
    return static_cast<EScrollTargetGroup>(misc_data_->scroll_target_group_);
  }




  // scroll-timeline-axis
  const Vector<TimelineAxis>& ScrollTimelineAxis() const {
    return misc_data_->timeline_data_->scroll_timeline_axis_;
  }






  // scroll-timeline-name
  const Vector<AtomicString>& ScrollTimelineName() const {
    return misc_data_->timeline_data_->scroll_timeline_name_;
  }






  // scrollbar-color
  StyleScrollbarColor* ScrollbarColor() const {
    return misc_inherited_data_->misc_inherited_1_data_->scrollbar_color_.Get();
  }



  // scrollbar-gutter
  unsigned ScrollbarGutter() const {
    return static_cast<unsigned>(misc_data_->scrollbar_gutter_);
  }




  // scrollbar-width
  EScrollbarWidth ScrollbarWidth() const {
    return static_cast<EScrollbarWidth>(misc_data_->scrollbar_width_);
  }




  // shape-image-threshold
  float ShapeImageThreshold() const {
    return misc_data_->misc_6_data_->shape_image_threshold_;
  }




  // shape-margin
  const Length& ShapeMargin() const {
    return misc_data_->misc_6_data_->shape_margin_;
  }






  // shape-outside
  





  // shape-rendering
  EShapeRendering ShapeRendering() const {
    return static_cast<EShapeRendering>(svginherited_data_->shape_rendering_);
  }




  // ShouldIgnoreOverflowPropertyForInlineBlockBaseline
  bool ShouldIgnoreOverflowPropertyForInlineBlockBaseline() const {
    return static_cast<bool>(data_.should_ignore_overflow_property_for_inline_block_baseline_);
  }



  // SkipsContents
  bool SkipsContents() const {
    return static_cast<bool>(data_.skips_contents_);
  }




  // speak
  ESpeak Speak() const {
    return static_cast<ESpeak>(misc_inherited_data_->speak_);
  }




  // stop-color
  





  // stop-opacity
  float StopOpacity() const {
    return svg_data_->stop_data_->stop_opacity_;
  }




  // stroke-dasharray
  SVGDashArray* StrokeDashArray() const {
    return svginherited_data_->stroke_data_->stroke_dash_array_.Get();
  }



  // stroke-dashoffset
  const Length& StrokeDashOffset() const {
    return svginherited_data_->stroke_data_->stroke_dash_offset_;
  }






  // stroke-miterlimit
  float StrokeMiterLimit() const {
    return svginherited_data_->stroke_data_->stroke_miter_limit_;
  }




  // stroke-opacity
  float StrokeOpacity() const {
    return svginherited_data_->stroke_data_->stroke_opacity_;
  }




  // stroke
  const SVGPaint& StrokePaint() const {
    return svginherited_data_->stroke_data_->stroke_paint_;
  }






  // stroke-width
  const UnzoomedLength& StrokeWidth() const {
    return svginherited_data_->stroke_data_->stroke_width_;
  }






  // StyleType
  PseudoId StyleType() const {
    return static_cast<PseudoId>(data_.style_type_);
  }




  // SubtreeIsSticky
  bool SubtreeIsSticky() const {
    return static_cast<bool>(misc_inherited_data_->subtree_is_sticky_);
  }




  // SubtreeWillChangeContents
  bool SubtreeWillChangeContents() const {
    return static_cast<bool>(misc_inherited_data_->subtree_will_change_contents_);
  }




  // tab-size
  const TabSize& GetTabSize() const {
    return misc_inherited_data_->misc_inherited_1_data_->tab_size_;
  }






  // table-layout
  ETableLayout TableLayout() const {
    return static_cast<ETableLayout>(data_.table_layout_);
  }




  // -webkit-tap-highlight-color
  const StyleColor& TapHighlightColor() const {
    return misc_inherited_data_->misc_inherited_2_data_->tap_highlight_color_;
  }






  // text-align
  ETextAlign GetTextAlign() const {
    return static_cast<ETextAlign>(data_.text_align_);
  }




  // text-align-last
  ETextAlignLast TextAlignLast() const {
    return static_cast<ETextAlignLast>(misc_inherited_data_->text_align_last_);
  }




  // text-anchor
  ETextAnchor TextAnchor() const {
    return static_cast<ETextAnchor>(svginherited_data_->text_anchor_);
  }




  // text-autospace
  ETextAutospace TextAutospace() const {
    return static_cast<ETextAutospace>(misc_inherited_data_->text_autospace_);
  }




  // text-box-edge
  TextBoxEdge GetTextBoxEdge() const {
    return static_cast<TextBoxEdge>(misc_inherited_data_->text_box_edge_);
  }




  // text-box-trim
  ETextBoxTrim TextBoxTrim() const {
    return static_cast<ETextBoxTrim>(box_data_->text_box_trim_);
  }




  // text-combine-upright
  ETextCombine TextCombine() const {
    return static_cast<ETextCombine>(misc_inherited_data_->text_combine_);
  }




  // text-decoration-color
  





  // text-decoration-inset
  const TextDecorationInset& GetTextDecorationInset() const {
    return misc_data_->misc_6_data_->text_decoration_inset_;
  }






  // text-decoration-line
  TextDecorationLine GetTextDecorationLine() const {
    return static_cast<TextDecorationLine>(visual_data_->text_decoration_line_);
  }




  // text-decoration-skip-ink
  ETextDecorationSkipInk TextDecorationSkipInk() const {
    return static_cast<ETextDecorationSkipInk>(misc_inherited_data_->text_decoration_skip_ink_);
  }




  // text-decoration-skip-spaces
  TextDecorationSkipSpaces GetTextDecorationSkipSpaces() const {
    return static_cast<TextDecorationSkipSpaces>(misc_inherited_data_->text_decoration_skip_spaces_);
  }




  // text-decoration-style
  ETextDecorationStyle TextDecorationStyle() const {
    return static_cast<ETextDecorationStyle>(misc_data_->text_decoration_style_);
  }




  // text-decoration-thickness
  const TextDecorationThickness& GetTextDecorationThickness() const {
    return misc_data_->misc_6_data_->text_decoration_thickness_;
  }






  // text-emphasis-color
  





  // TextEmphasisCustomMark
  const AtomicString& TextEmphasisCustomMark() const {
    return misc_inherited_data_->misc_inherited_2_data_->text_emphasis_custom_mark_;
  }






  // TextEmphasisFill
  TextEmphasisFill GetTextEmphasisFill() const {
    return static_cast<TextEmphasisFill>(misc_inherited_data_->text_emphasis_fill_);
  }




  // TextEmphasisMark
  



  // text-emphasis-position
  TextEmphasisPosition GetTextEmphasisPosition() const {
    return static_cast<TextEmphasisPosition>(misc_inherited_data_->text_emphasis_position_);
  }




  // -webkit-text-fill-color
  





  // text-fit
  const TextFit& GetTextFit() const {
    return misc_inherited_data_->misc_inherited_1_data_->text_fit_;
  }






  // text-indent
  const Length& TextIndent() const {
    return misc_inherited_data_->misc_inherited_2_data_->text_indent_;
  }






  // TextIndentFlags
  TextIndentFlags GetTextIndentFlags() const {
    return static_cast<TextIndentFlags>(misc_inherited_data_->text_indent_flags_);
  }




  // text-justify
  TextJustify GetTextJustify() const {
    return static_cast<TextJustify>(misc_inherited_data_->text_justify_);
  }




  // text-orientation
  ETextOrientation GetTextOrientation() const {
    return static_cast<ETextOrientation>(misc_inherited_data_->text_orientation_);
  }




  // text-overflow
  const TextOverflowData& TextOverflow() const {
    return misc_data_->misc_6_data_->text_overflow_;
  }






  // -webkit-text-security
  ETextSecurity TextSecurity() const {
    return static_cast<ETextSecurity>(misc_inherited_data_->text_security_);
  }




  // text-shadow
  ShadowList* TextShadow() const {
    return misc_inherited_data_->misc_inherited_2_data_->text_shadow_.Get();
  }



  // text-size-adjust
  const TextSizeAdjust& GetTextSizeAdjust() const {
    return misc_inherited_data_->misc_inherited_1_data_->text_size_adjust_;
  }






  // -webkit-text-stroke-color
  





  // -webkit-text-stroke-width
  float TextStrokeWidth() const {
    return misc_inherited_data_->misc_inherited_2_data_->text_stroke_width_;
  }




  // text-transform
  ETextTransform TextTransform() const {
    return static_cast<ETextTransform>(inherited_data_->text_transform_);
  }




  // text-transform
  bool TextTransformIsInherited() const {
    return static_cast<bool>(data_.text_transform_is_inherited_);
  }




  // text-underline-offset
  const Length& TextUnderlineOffset() const {
    return misc_inherited_data_->misc_inherited_2_data_->text_underline_offset_;
  }






  // text-underline-position
  TextUnderlinePosition GetTextUnderlinePosition() const {
    return static_cast<TextUnderlinePosition>(misc_inherited_data_->text_underline_position_);
  }




  // text-wrap-mode
  TextWrapMode GetTextWrapMode() const {
    return static_cast<TextWrapMode>(data_.text_wrap_mode_);
  }




  // text-wrap-style
  TextWrapStyle GetTextWrapStyle() const {
    return static_cast<TextWrapStyle>(data_.text_wrap_style_);
  }




  // timeline-scope
  const StyleTimelineScope& TimelineScope() const {
    return misc_data_->timeline_data_->timeline_scope_;
  }






  // top
  const Length& Top() const {
    return surround_data_->top_;
  }






  // touch-action
  TouchAction GetTouchAction() const {
    return static_cast<TouchAction>(misc_data_->misc_6_data_->touch_action_);
  }




  // transform
  const TransformOperations& Transform() const {
    return svg_data_->transform_;
  }






  // transform-box
  ETransformBox TransformBox() const {
    return static_cast<ETransformBox>(data_.transform_box_);
  }




  // transform-origin
  const TransformOrigin& GetTransformOrigin() const {
    return svg_data_->transform_origin_;
  }






  // transform-style
  ETransformStyle3D TransformStyle3D() const {
    return static_cast<ETransformStyle3D>(misc_data_->transform_style_3d_);
  }




  // Transitions
  const Member<CSSTransitionData>& Transitions() const {
    return misc_data_->misc_7_data_->transitions_;
  }






  // translate
  TranslateTransformOperation* Translate() const {
    return misc_data_->misc_6_data_->translate_.Get();
  }



  // trigger-scope
  const StyleTriggerScope& TriggerScope() const {
    return misc_data_->misc_6_data_->trigger_scope_;
  }






  // UAShadowHostData
  StyleUAShadowHostData* UAShadowHostData() const {
    return misc_inherited_data_->misc_inherited_2_data_->ua_shadow_host_data_.get();
  }



  // UnconditionalScrollbarSize
  const gfx::Size& UnconditionalScrollbarSize() const {
    return misc_data_->misc_7_data_->unconditional_scrollbar_size_;
  }






  // unicode-bidi
  UnicodeBidi GetUnicodeBidi() const {
    return static_cast<UnicodeBidi>(data_.unicode_bidi_);
  }




  // -webkit-user-drag
  EUserDrag UserDrag() const {
    return static_cast<EUserDrag>(misc_data_->user_drag_);
  }




  // -webkit-user-modify
  



  // user-select
  



  // vector-effect
  EVectorEffect VectorEffect() const {
    return static_cast<EVectorEffect>(svg_data_->vector_effect_);
  }




  // VerticalAlign
  



  // VerticalAlignLength
  const Length& GetVerticalAlignLength() const {
    return box_data_->vertical_align_length_;
  }






  // -webkit-border-vertical-spacing
  short VerticalBorderSpacing() const {
    return inherited_data_->vertical_border_spacing_;
  }




  // view-timeline-axis
  const Vector<TimelineAxis>& ViewTimelineAxis() const {
    return misc_data_->timeline_data_->view_timeline_axis_;
  }






  // view-timeline-inset
  const Vector<TimelineInset>& ViewTimelineInset() const {
    return misc_data_->timeline_data_->view_timeline_inset_;
  }






  // view-timeline-name
  const Vector<AtomicString>& ViewTimelineName() const {
    return misc_data_->timeline_data_->view_timeline_name_;
  }






  // view-transition-class
  const Member<ScopedCSSNameList>& ViewTransitionClass() const {
    return misc_data_->misc_6_data_->view_transition_class_;
  }






  // view-transition-group
  const StyleViewTransitionGroup& ViewTransitionGroup() const {
    return misc_data_->misc_6_data_->view_transition_group_;
  }






  // view-transition-name
  const Member<StyleViewTransitionName>& ViewTransitionName() const {
    return misc_data_->misc_6_data_->view_transition_name_;
  }






  // view-transition-scope
  EViewTransitionScope ViewTransitionScope() const {
    return static_cast<EViewTransitionScope>(misc_data_->view_transition_scope_);
  }




  // ViewportUnitFlags
  unsigned ViewportUnitFlags() const {
    return static_cast<unsigned>(data_.viewport_unit_flags_);
  }




  // visibility
  EVisibility Visibility() const {
    return static_cast<EVisibility>(data_.visibility_);
  }




  // visibility
  bool VisibilityIsInherited() const {
    return static_cast<bool>(data_.visibility_is_inherited_);
  }




  // -webkit-line-clamp
  int WebkitLineClamp() const {
    return misc_data_->misc_7_data_->webkit_line_clamp_;
  }




  // white-space-collapse
  WhiteSpaceCollapse GetWhiteSpaceCollapse() const {
    return static_cast<WhiteSpaceCollapse>(data_.white_space_collapse_);
  }




  // widows
  short Widows() const {
    return misc_inherited_data_->misc_inherited_2_data_->widows_;
  }




  // width
  const Length& Width() const {
    return box_data_->width_;
  }






  // will-change
  StyleWillChangeData* WillChange() const {
    return misc_data_->will_change_.Get();
  }



  // word-break
  EWordBreak WordBreak() const {
    return static_cast<EWordBreak>(misc_inherited_data_->word_break_);
  }




  // word-spacing
  





  // writing-mode
  WritingMode GetWritingMode() const {
    return static_cast<WritingMode>(data_.writing_mode_);
  }




  // x
  const Length& X() const {
    return svg_data_->geometry_data_->x_;
  }






  // y
  const Length& Y() const {
    return svg_data_->geometry_data_->y_;
  }






  // z-index
  int ZIndex() const {
    return box_data_->z_index_;
  }




  // zoom
  float Zoom() const {
    return visual_data_->zoom_;
  }





  // Computes a bitset of which properties may be unequal between the two ComputedStyles.
  // Only cares about properties that may be relevant for “transition: all” (with or
  // without discrete values depending on which function you are calling).
  //
  // Note that this set may be overbroad (return properties not in PropertiesForTransitionAll());
  // in particular, it does not filter out runtime properties that are not web-exposed.
  // So you'll need to use it as an extra filter on top of the property list, not as the
  // single source of truth for which properties are relevant for “all”.
  //
  // Similarly, this is based on a simple equality check of the fields only, without much regard
  // for _property_ equality. E.g., if the background field contains different objects between
  // the two, most background properties will be marked as diffed. PropertyEquality will yield
  // the true answer.
  static CSSBitset TransitionAllDiff(const ComputedStyle& a, const ComputedStyle& b);
  static CSSBitset TransitionAllWithDiscreteDiff(const ComputedStyle& a, const ComputedStyle& b);

#if DCHECK_IS_ON()
  enum class DebugField {
    accent_color_,
    affected_by_active_,
    affected_by_css_function_,
    affected_by_drag_,
    affected_by_focus_within_,
    affected_by_functional_media_,
    affected_by_functional_navigation_,
    affected_by_hover_,
    align_content_,
    align_content_block_center_,
    align_items_,
    align_self_,
    alignment_baseline_,
    allows_z_index_,
    anchor_center_offset_,
    anchor_name_,
    anchor_scope_,
    animations_,
    appearance_,
    aspect_ratio_,
    backdrop_filter_,
    backface_visibility_,
    background_,
    background_color_,
    base_data_,
    base_text_decoration_data_,
    baseline_shift_,
    baseline_shift_type_,
    baseline_source_,
    blend_mode_,
    block_ellipsis_,
    border_bottom_color_,
    border_bottom_left_radius_,
    border_bottom_right_radius_,
    border_bottom_style_,
    border_bottom_width_,
    border_collapse_,
    border_collapse_is_inherited_,
    border_image_,
    border_left_color_,
    border_left_style_,
    border_left_width_,
    border_right_color_,
    border_right_style_,
    border_right_width_,
    border_shape_,
    border_top_color_,
    border_top_left_radius_,
    border_top_right_radius_,
    border_top_style_,
    border_top_width_,
    bottom_,
    box_align_,
    box_decoration_break_,
    box_direction_,
    box_flex_,
    box_ordinal_group_,
    box_orient_,
    box_pack_,
    box_reflect_,
    box_shadow_,
    box_sizing_,
    break_after_,
    break_before_,
    break_inside_,
    buffered_rendering_,
    callback_selectors_,
    can_affect_animations_,
    cap_style_,
    caption_side_,
    caption_side_is_inherited_,
    caret_animation_,
    caret_color_,
    caret_shape_,
    child_has_explicit_inheritance_,
    clear_,
    clip_,
    clip_path_,
    clip_rule_,
    color_,
    color_interpolation_,
    color_interpolation_filters_,
    color_is_current_color_,
    color_is_inherited_,
    color_rendering_,
    color_scheme_,
    color_scheme_flags_is_normal_,
    color_scheme_forced_,
    column_count_,
    column_fill_,
    column_gap_,
    column_height_,
    column_rule_break_,
    column_rule_color_,
    column_rule_inset_cap_end_,
    column_rule_inset_cap_start_,
    column_rule_inset_junction_end_,
    column_rule_inset_junction_start_,
    column_rule_style_,
    column_rule_visibility_items_,
    column_rule_width_,
    column_span_,
    column_width_,
    column_wrap_,
    contain_,
    contain_intrinsic_height_,
    contain_intrinsic_width_,
    container_font_,
    container_name_,
    container_type_,
    content_,
    content_visibility_,
    continue_,
    corner_bottom_left_shape_,
    corner_bottom_right_shape_,
    corner_top_left_shape_,
    corner_top_right_shape_,
    counter_directives_,
    counter_increment_list_,
    counter_reset_list_,
    counter_set_list_,
    css_dominant_baseline_,
    cursor_,
    cursor_data_,
    cursor_is_inherited_,
    custom_highlight_names_,
    custom_style_callback_depends_on_font_,
    cx_,
    cy_,
    d_,
    dark_color_scheme_,
    depends_on_anchored_container_queries_,
    depends_on_scroll_state_container_queries_,
    depends_on_size_container_queries_,
    depends_on_style_container_queries_,
    direction_,
    display_,
    display_layout_custom_name_,
    display_layout_custom_parent_name_,
    document_rules_selectors_,
    dominant_baseline_,
    draggable_region_mode_,
    dynamic_range_limit_,
    effective_appearance_,
    effective_touch_action_,
    effective_zoom_,
    element_is_view_transition_participant_,
    empty_cells_,
    empty_cells_is_inherited_,
    field_sizing_,
    fill_opacity_,
    fill_paint_,
    fill_rule_,
    filter_,
    first_line_depends_on_size_container_queries_,
    flex_basis_,
    flex_direction_,
    flex_grow_,
    flex_line_count_,
    flex_shrink_,
    flex_wrap_,
    floating_,
    flood_color_,
    flood_opacity_,
    flow_tolerance_,
    font_,
    forced_color_adjust_,
    forces_blockifies_children_,
    forces_stacking_context_,
    frame_sizing_,
    grid_auto_columns_,
    grid_auto_flow_,
    grid_auto_rows_,
    grid_column_end_,
    grid_column_start_,
    grid_lanes_direction_,
    grid_lanes_pack_,
    grid_row_end_,
    grid_row_start_,
    grid_template_areas_,
    grid_template_columns_,
    grid_template_rows_,
    hanging_punctuation_,
    has_anchor_evaluator_,
    has_anchor_functions_,
    has_attr_function_,
    has_author_background_,
    has_author_border_,
    has_author_border_radius_,
    has_author_highlight_colors_,
    has_auto_clip_,
    has_auto_column_count_,
    has_auto_column_height_,
    has_auto_column_width_,
    has_auto_z_index_,
    has_clip_path_,
    has_container_relative_value_,
    has_current_backdrop_filter_animation_,
    has_current_background_color_animation_,
    has_current_clip_path_animation_,
    has_current_filter_animation_,
    has_current_opacity_animation_,
    has_current_rotate_animation_,
    has_current_scale_animation_,
    has_current_transform_animation_,
    has_current_translate_animation_,
    has_custom_highlight_universal_selector_,
    has_element_dependent_random_functions_,
    has_em_units_,
    has_env_,
    has_env_safe_area_inset_bottom_,
    has_explicit_inheritance_,
    has_explicit_overflow_x_visible_,
    has_explicit_overflow_y_visible_,
    has_glyph_relative_units_,
    has_layout_containment_for_view_transition_scope_,
    has_line_height_relative_units_,
    has_line_if_empty_,
    has_logical_direction_relative_units_,
    has_non_ua_highlight_pseudo_styles_,
    has_non_universal_highlight_pseudo_styles_,
    has_root_relative_units_,
    has_sibling_functions_,
    has_size_containment_for_view_transition_scope_,
    has_variable_declaration_,
    has_variable_reference_,
    height_,
    highlight_data_,
    highlights_depend_on_size_container_queries_,
    horizontal_border_spacing_,
    hyphenate_limit_chars_,
    hyphenation_string_,
    hyphens_,
    image_animation_,
    image_orientation_,
    image_rendering_,
    in_base_appearance_,
    in_forced_colors_mode_,
    inherited_variables_,
    initial_data_,
    initial_letter_,
    inline_block_baseline_edge_,
    inline_style_lost_cascade_,
    inside_link_,
    interactivity_,
    interactivity_is_inherited_,
    interest_delay_end_,
    interest_delay_start_,
    internal_forced_background_color_,
    internal_forced_border_color_,
    internal_forced_color_,
    internal_forced_outline_color_,
    internal_forced_visited_color_,
    internal_overscroll_container_,
    internal_overscroll_position_,
    internal_unbounded_,
    internal_visited_background_color_,
    internal_visited_border_bottom_color_,
    internal_visited_border_left_color_,
    internal_visited_border_right_color_,
    internal_visited_border_top_color_,
    internal_visited_caret_color_,
    internal_visited_color_,
    internal_visited_color_is_current_color_,
    internal_visited_column_rule_color_,
    internal_visited_fill_paint_,
    internal_visited_outline_color_,
    internal_visited_stroke_paint_,
    internal_visited_text_decoration_color_,
    internal_visited_text_emphasis_color_,
    internal_visited_text_fill_color_,
    internal_visited_text_stroke_color_,
    interpolate_size_,
    is_bottom_relative_to_safe_area_inset_,
    is_css_inert_,
    is_css_inert_is_inherited_,
    is_ensured_in_display_none_,
    is_flex_or_grid_or_custom_item_,
    is_html_inert_,
    is_html_inert_is_inherited_,
    is_in_blockifying_display_,
    is_in_inlinifying_display_,
    is_in_shrink_to_fit_subtree_,
    is_inside_display_ignoring_floating_children_,
    is_link_,
    is_original_display_inline_type_,
    is_page_margin_box_,
    is_running_backdrop_filter_animation_on_compositor_,
    is_running_filter_animation_on_compositor_,
    is_running_opacity_animation_on_compositor_,
    is_running_rotate_animation_on_compositor_,
    is_running_scale_animation_on_compositor_,
    is_running_transform_animation_on_compositor_,
    is_running_translate_animation_on_compositor_,
    is_secondary_body_element_,
    is_specified_display_webkit_box_,
    is_stacking_context_without_containment_,
    is_starting_style_,
    isolation_,
    join_style_,
    justify_content_,
    justify_items_,
    justify_self_,
    left_,
    letter_spacing_,
    lighting_color_,
    line_break_,
    line_clamp_internal_block_ellipsis_,
    line_height_,
    list_style_image_,
    list_style_position_,
    list_style_position_is_inherited_,
    list_style_type_,
    margin_bottom_,
    margin_left_,
    margin_right_,
    margin_top_,
    margin_trim_,
    marker_end_resource_,
    marker_mid_resource_,
    marker_start_resource_,
    mask_,
    mask_box_image_,
    mask_type_,
    math_baseline_,
    math_depth_,
    math_fraction_bar_thickness_,
    math_l_space_,
    math_max_size_,
    math_min_size_,
    math_padded_depth_,
    math_padded_v_offset_,
    math_r_space_,
    math_shift_,
    math_style_,
    max_content_sizing_,
    max_height_,
    max_lines_,
    max_width_,
    may_have_margin_,
    may_have_padding_,
    maybe_has_gap_decorations_,
    min_height_,
    min_width_,
    non_inherited_variables_,
    object_fit_,
    object_position_,
    object_view_box_,
    offset_anchor_,
    offset_distance_,
    offset_path_,
    offset_position_,
    offset_rotate_,
    opacity_,
    order_,
    origin_trial_test_property_,
    orphans_,
    outline_color_,
    outline_offset_,
    outline_style_,
    outline_style_is_auto_,
    outline_width_,
    overflow_anchor_,
    overflow_clip_margin_,
    overflow_wrap_,
    overflow_x_,
    overflow_y_,
    overlay_,
    overscroll_behavior_x_,
    overscroll_behavior_y_,
    overscroll_container_type_,
    padding_bottom_,
    padding_left_,
    padding_right_,
    padding_top_,
    page_,
    page_margin_safety_,
    page_orientation_,
    page_size_,
    page_size_type_,
    paint_images_,
    paint_order_,
    path_length_,
    perspective_,
    perspective_origin_,
    pointer_events_,
    pointer_events_is_inherited_,
    position_,
    position_anchor_,
    position_area_,
    position_area_offsets_,
    position_try_fallbacks_,
    position_try_order_,
    position_visibility_,
    prefers_default_scrollbar_styles_,
    print_color_adjust_,
    pseudo_element_styles_,
    quotes_,
    r_,
    reading_flow_,
    reading_order_,
    requires_accelerated_compositing_for_external_reasons_,
    resize_,
    right_,
    rotate_,
    row_gap_,
    row_rule_break_,
    row_rule_color_,
    row_rule_inset_cap_end_,
    row_rule_inset_cap_start_,
    row_rule_inset_junction_end_,
    row_rule_inset_junction_start_,
    row_rule_style_,
    row_rule_visibility_items_,
    row_rule_width_,
    rtl_ordering_,
    rtl_ordering_is_inherited_,
    ruby_align_,
    ruby_overhang_,
    ruby_position_,
    rule_overlap_,
    rx_,
    ry_,
    scale_,
    scroll_axis_lock_,
    scroll_behavior_,
    scroll_initial_target_,
    scroll_margin_bottom_,
    scroll_margin_left_,
    scroll_margin_right_,
    scroll_margin_top_,
    scroll_marker_group_,
    scroll_padding_bottom_,
    scroll_padding_left_,
    scroll_padding_right_,
    scroll_padding_top_,
    scroll_snap_align_,
    scroll_snap_stop_,
    scroll_snap_type_,
    scroll_target_group_,
    scroll_timeline_axis_,
    scroll_timeline_name_,
    scrollbar_color_,
    scrollbar_gutter_,
    scrollbar_width_,
    shape_image_threshold_,
    shape_margin_,
    shape_outside_,
    shape_rendering_,
    should_ignore_overflow_property_for_inline_block_baseline_,
    skips_contents_,
    speak_,
    stop_color_,
    stop_opacity_,
    stroke_dash_array_,
    stroke_dash_offset_,
    stroke_miter_limit_,
    stroke_opacity_,
    stroke_paint_,
    stroke_width_,
    style_type_,
    subtree_is_sticky_,
    subtree_will_change_contents_,
    tab_size_,
    table_layout_,
    tap_highlight_color_,
    text_align_,
    text_align_last_,
    text_anchor_,
    text_autospace_,
    text_box_edge_,
    text_box_trim_,
    text_combine_,
    text_decoration_color_,
    text_decoration_inset_,
    text_decoration_line_,
    text_decoration_skip_ink_,
    text_decoration_skip_spaces_,
    text_decoration_style_,
    text_decoration_thickness_,
    text_emphasis_color_,
    text_emphasis_custom_mark_,
    text_emphasis_fill_,
    text_emphasis_mark_,
    text_emphasis_position_,
    text_fill_color_,
    text_fit_,
    text_indent_,
    text_indent_flags_,
    text_justify_,
    text_orientation_,
    text_overflow_,
    text_security_,
    text_shadow_,
    text_size_adjust_,
    text_stroke_color_,
    text_stroke_width_,
    text_transform_,
    text_transform_is_inherited_,
    text_underline_offset_,
    text_underline_position_,
    text_wrap_mode_,
    text_wrap_style_,
    timeline_scope_,
    top_,
    touch_action_,
    transform_,
    transform_box_,
    transform_origin_,
    transform_style_3d_,
    transitions_,
    translate_,
    trigger_scope_,
    ua_shadow_host_data_,
    unconditional_scrollbar_size_,
    unicode_bidi_,
    user_drag_,
    user_modify_,
    user_select_,
    vector_effect_,
    vertical_align_,
    vertical_align_length_,
    vertical_border_spacing_,
    view_timeline_axis_,
    view_timeline_inset_,
    view_timeline_name_,
    view_transition_class_,
    view_transition_group_,
    view_transition_name_,
    view_transition_scope_,
    viewport_unit_flags_,
    visibility_,
    visibility_is_inherited_,
    webkit_line_clamp_,
    white_space_collapse_,
    widows_,
    width_,
    will_change_,
    word_break_,
    word_spacing_,
    writing_mode_,
    x_,
    y_,
    z_index_,
    zoom_,
  };
  struct DebugDiff {
    DebugField field;
    std::string correct;
    std::string actual;
  };

  CORE_EXPORT static String DebugFieldToString(DebugField);

  // Returns a list of all fields that differ between |this| and |o|.
  CORE_EXPORT Vector<DebugDiff> DebugDiffFields(const ComputedStyleBase& o) const;
#endif // DCHECK_IS_ON()

  // Find a list of which subgroups listed have changed between this and the
  // other ComputedStyle(Base); output a list of the changed groups and their
  // sizes in bytes. This is meant for more precise memory tracking than just
  // looking at the Oilpan statistics, or for finding out (empirically)
  // which groups are affected by setting a specific property. It is used
  // only in the style perftest, not in the normal rendering engine.
  //
  // Note that if you change something deep in a subgroup like e.g. a->b->c,
  // both a->b and a will also be recorded, as they must be modified to get
  // the pointer in place. The fixed 4- or 8-byte Oilpan header overhead
  // is not included.
  Vector<std::pair<String, size_t>>
  FindChangedGroups(const ComputedStyleBase &other_style) const;

  CORE_EXPORT void Trace(Visitor* visitor) const;
  void TraceAfterDispatch(Visitor* visitor) const {
    visitor->Trace(misc_inherited_data_);
    visitor->Trace(misc_data_);
    visitor->Trace(inherited_data_);
    visitor->Trace(visual_data_);
    visitor->Trace(svginherited_data_);
    visitor->Trace(box_data_);
    visitor->Trace(svg_data_);
    visitor->Trace(surround_data_);
    visitor->Trace(background_data_);
    visitor->Trace(base_data_);
  }

 private:
  class StyleMiscInherited1Data : public GarbageCollected<StyleMiscInherited1Data> {
   public:
    explicit StyleMiscInherited1Data();
    CORE_EXPORT StyleMiscInherited1Data(const StyleMiscInherited1Data&);

    static StyleMiscInherited1Data* Create() {
      return MakeGarbageCollected<StyleMiscInherited1Data>();
    }
    StyleMiscInherited1Data* Copy() const {
      return MakeGarbageCollected<StyleMiscInherited1Data>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<AtomicString>::Trace(visitor, hyphenation_string_);
      TraceIfNeeded<Vector<AtomicString>>::Trace(visitor, color_scheme_);
      visitor->Trace(list_style_image_);
      visitor->Trace(list_style_type_);
      visitor->Trace(scrollbar_color_);
      TraceIfNeeded<DynamicRangeLimit>::Trace(visitor, dynamic_range_limit_);
      TraceIfNeeded<TabSize>::Trace(visitor, tab_size_);
      TraceIfNeeded<TextFit>::Trace(visitor, text_fit_);
      TraceIfNeeded<TextSizeAdjust>::Trace(visitor, text_size_adjust_);
      TraceIfNeeded<StyleAutoColor>::Trace(visitor, accent_color_);
      TraceIfNeeded<StyleCaretColor>::Trace(visitor, caret_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, text_emphasis_color_);
      TraceIfNeeded<short>::Trace(visitor, math_depth_);
      TraceIfNeeded<short>::Trace(visitor, orphans_);
      TraceIfNeeded<StyleHyphenateLimitChars>::Trace(visitor, hyphenate_limit_chars_);
    }

    bool operator==(const StyleMiscInherited1Data& other) const {
      return (true
        && hyphenation_string_ == other.hyphenation_string_
        && color_scheme_ == other.color_scheme_
        && base::ValuesEquivalent(quotes_, other.quotes_)
        && base::ValuesEquivalent(list_style_image_, other.list_style_image_)
        && base::ValuesEquivalent(list_style_type_, other.list_style_type_)
        && base::ValuesEquivalent(scrollbar_color_, other.scrollbar_color_)
        && dynamic_range_limit_ == other.dynamic_range_limit_
        && tab_size_ == other.tab_size_
        && text_fit_ == other.text_fit_
        && text_size_adjust_ == other.text_size_adjust_
        && accent_color_ == other.accent_color_
        && caret_color_ == other.caret_color_
        && text_emphasis_color_ == other.text_emphasis_color_
        && math_depth_ == other.math_depth_
        && orphans_ == other.orphans_
        && hyphenate_limit_chars_ == other.hyphenate_limit_chars_
      );
    }

    AtomicString hyphenation_string_;
    Vector<AtomicString> color_scheme_;
    scoped_refptr<QuotesData> quotes_;
    Member<StyleImage> list_style_image_;
    Member<ListStyleTypeData> list_style_type_;
    Member<StyleScrollbarColor> scrollbar_color_;
    DynamicRangeLimit dynamic_range_limit_;
    TabSize tab_size_;
    TextFit text_fit_;
    TextSizeAdjust text_size_adjust_;
    StyleAutoColor accent_color_;
    StyleCaretColor caret_color_;
    StyleColor text_emphasis_color_;
    short math_depth_;
    short orphans_;
    StyleHyphenateLimitChars hyphenate_limit_chars_;
  };

  class StyleMiscInherited2Data : public GarbageCollected<StyleMiscInherited2Data> {
   public:
    explicit StyleMiscInherited2Data();
    CORE_EXPORT StyleMiscInherited2Data(const StyleMiscInherited2Data&);

    static StyleMiscInherited2Data* Create() {
      return MakeGarbageCollected<StyleMiscInherited2Data>();
    }
    StyleMiscInherited2Data* Copy() const {
      return MakeGarbageCollected<StyleMiscInherited2Data>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<AtomicString>::Trace(visitor, text_emphasis_custom_mark_);
      visitor->Trace(text_shadow_);
      visitor->Trace(cursor_data_);
      visitor->Trace(initial_data_);
      TraceIfNeeded<Length>::Trace(visitor, text_indent_);
      TraceIfNeeded<Length>::Trace(visitor, text_underline_offset_);
      TraceIfNeeded<float>::Trace(visitor, text_stroke_width_);
      TraceIfNeeded<float>::Trace(visitor, effective_zoom_);
      TraceIfNeeded<StyleColor>::Trace(visitor, tap_highlight_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, text_fill_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, text_stroke_color_);
      TraceIfNeeded<short>::Trace(visitor, widows_);
    }

    bool operator==(const StyleMiscInherited2Data& other) const {
      return (true
        && text_emphasis_custom_mark_ == other.text_emphasis_custom_mark_
        && base::ValuesEquivalent(ua_shadow_host_data_, other.ua_shadow_host_data_)
        && base::ValuesEquivalent(text_shadow_, other.text_shadow_)
        && base::ValuesEquivalent(cursor_data_, other.cursor_data_)
        && base::ValuesEquivalent(initial_data_, other.initial_data_)
        && text_indent_ == other.text_indent_
        && text_underline_offset_ == other.text_underline_offset_
        && text_stroke_width_ == other.text_stroke_width_
        && effective_zoom_ == other.effective_zoom_
        && tap_highlight_color_ == other.tap_highlight_color_
        && text_fill_color_ == other.text_fill_color_
        && text_stroke_color_ == other.text_stroke_color_
        && widows_ == other.widows_
        && effective_touch_action_ == other.effective_touch_action_
      );
    }

    AtomicString text_emphasis_custom_mark_;
    std::unique_ptr<StyleUAShadowHostData> ua_shadow_host_data_;
    Member<ShadowList> text_shadow_;
    Member<CursorList> cursor_data_;
    Member<StyleInitialData> initial_data_;
    Length text_indent_;
    Length text_underline_offset_;
    float text_stroke_width_;
    float effective_zoom_;
    StyleColor tap_highlight_color_;
    StyleColor text_fill_color_;
    StyleColor text_stroke_color_;
    short widows_;
    unsigned effective_touch_action_ : 8; // TouchAction
  };

  class StyleMiscInheritedData : public GarbageCollected<StyleMiscInheritedData> {
   public:
    explicit StyleMiscInheritedData();
    CORE_EXPORT StyleMiscInheritedData(const StyleMiscInheritedData&);

    static StyleMiscInheritedData* Create() {
      return MakeGarbageCollected<StyleMiscInheritedData>();
    }
    StyleMiscInheritedData* Copy() const {
      return MakeGarbageCollected<StyleMiscInheritedData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      visitor->Trace(misc_inherited_1_data_);
      visitor->Trace(misc_inherited_2_data_);
    }

    bool operator==(const StyleMiscInheritedData& other) const {
      return (true
        && base::ValuesEquivalent(misc_inherited_1_data_, other.misc_inherited_1_data_)
        && base::ValuesEquivalent(misc_inherited_2_data_, other.misc_inherited_2_data_)
        && text_box_edge_ == other.text_box_edge_
        && text_underline_position_ == other.text_underline_position_
        && hanging_punctuation_ == other.hanging_punctuation_
        && line_break_ == other.line_break_
        && speak_ == other.speak_
        && text_align_last_ == other.text_align_last_
        && text_decoration_skip_spaces_ == other.text_decoration_skip_spaces_
        && text_emphasis_mark_ == other.text_emphasis_mark_
        && text_emphasis_position_ == other.text_emphasis_position_
        && block_ellipsis_ == other.block_ellipsis_
        && user_select_ == other.user_select_
        && word_break_ == other.word_break_
        && draggable_region_mode_ == other.draggable_region_mode_
        && forced_color_adjust_ == other.forced_color_adjust_
        && hyphens_ == other.hyphens_
        && image_animation_ == other.image_animation_
        && image_rendering_ == other.image_rendering_
        && overflow_wrap_ == other.overflow_wrap_
        && ruby_align_ == other.ruby_align_
        && ruby_overhang_ == other.ruby_overhang_
        && text_decoration_skip_ink_ == other.text_decoration_skip_ink_
        && text_indent_flags_ == other.text_indent_flags_
        && text_justify_ == other.text_justify_
        && text_orientation_ == other.text_orientation_
        && text_security_ == other.text_security_
        && user_modify_ == other.user_modify_
        && empty_cells_ == other.empty_cells_
        && has_line_if_empty_ == other.has_line_if_empty_
        && image_orientation_ == other.image_orientation_
        && in_base_appearance_ == other.in_base_appearance_
        && interactivity_ == other.interactivity_
        && interpolate_size_ == other.interpolate_size_
        && is_in_shrink_to_fit_subtree_ == other.is_in_shrink_to_fit_subtree_
        && math_shift_ == other.math_shift_
        && math_style_ == other.math_style_
        && ruby_position_ == other.ruby_position_
        && subtree_is_sticky_ == other.subtree_is_sticky_
        && subtree_will_change_contents_ == other.subtree_will_change_contents_
        && text_autospace_ == other.text_autospace_
        && text_combine_ == other.text_combine_
        && text_emphasis_fill_ == other.text_emphasis_fill_
      );
    }

    Member<StyleMiscInherited1Data> misc_inherited_1_data_;
    Member<StyleMiscInherited2Data> misc_inherited_2_data_;
    unsigned text_box_edge_ : 6; // TextBoxEdge
    unsigned text_underline_position_ : 4; // TextUnderlinePosition
    unsigned hanging_punctuation_ : 3; // HangingPunctuation
    unsigned line_break_ : 3; // LineBreak
    unsigned speak_ : 3; // ESpeak
    unsigned text_align_last_ : 3; // ETextAlignLast
    unsigned text_decoration_skip_spaces_ : 3; // TextDecorationSkipSpaces
    unsigned text_emphasis_mark_ : 3; // TextEmphasisMark
    unsigned text_emphasis_position_ : 3; // TextEmphasisPosition
    unsigned block_ellipsis_ : 1; // EBlockEllipsis
    unsigned user_select_ : 3; // EUserSelect
    unsigned word_break_ : 3; // EWordBreak
    unsigned draggable_region_mode_ : 2; // EDraggableRegionMode
    unsigned forced_color_adjust_ : 2; // EForcedColorAdjust
    unsigned hyphens_ : 2; // Hyphens
    unsigned image_animation_ : 2; // ImageAnimationEnum
    unsigned image_rendering_ : 2; // EImageRendering
    unsigned overflow_wrap_ : 2; // EOverflowWrap
    unsigned ruby_align_ : 2; // ERubyAlign
    unsigned ruby_overhang_ : 2; // ERubyOverhang
    unsigned text_decoration_skip_ink_ : 2; // ETextDecorationSkipInk
    unsigned text_indent_flags_ : 2; // TextIndentFlags
    unsigned text_justify_ : 2; // TextJustify
    unsigned text_orientation_ : 2; // ETextOrientation
    unsigned text_security_ : 2; // ETextSecurity
    unsigned user_modify_ : 2; // EUserModify
    unsigned empty_cells_ : 1; // EEmptyCells
    unsigned has_line_if_empty_ : 1; // bool
    unsigned image_orientation_ : 1; // RespectImageOrientationEnum
    unsigned in_base_appearance_ : 1; // bool
    unsigned interactivity_ : 1; // EInteractivity
    unsigned interpolate_size_ : 1; // EInterpolateSize
    unsigned is_in_shrink_to_fit_subtree_ : 1; // bool
    unsigned math_shift_ : 1; // EMathShift
    unsigned math_style_ : 1; // EMathStyle
    unsigned ruby_position_ : 1; // RubyPosition
    unsigned subtree_is_sticky_ : 1; // bool
    unsigned subtree_will_change_contents_ : 1; // bool
    unsigned text_autospace_ : 1; // ETextAutospace
    unsigned text_combine_ : 1; // ETextCombine
    unsigned text_emphasis_fill_ : 1; // TextEmphasisFill
  };

  class StyleMisc1Data : public GarbageCollected<StyleMisc1Data> {
   public:
    explicit StyleMisc1Data();
    CORE_EXPORT StyleMisc1Data(const StyleMisc1Data&);

    static StyleMisc1Data* Create() {
      return MakeGarbageCollected<StyleMisc1Data>();
    }
    StyleMisc1Data* Copy() const {
      return MakeGarbageCollected<StyleMisc1Data>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<FilterOperations>::Trace(visitor, backdrop_filter_);
      TraceIfNeeded<GapDataList<StyleColor>>::Trace(visitor, column_rule_color_);
      visitor->Trace(anchor_name_);
      visitor->Trace(border_shape_);
      visitor->Trace(box_shadow_);
      visitor->Trace(clip_path_);
      TraceIfNeeded<StyleAnchorScope>::Trace(visitor, anchor_scope_);
      TraceIfNeeded<Length>::Trace(visitor, column_rule_inset_cap_end_);
      TraceIfNeeded<Length>::Trace(visitor, column_rule_inset_cap_start_);
      TraceIfNeeded<StylePositionAnchor>::Trace(visitor, position_anchor_);
      TraceIfNeeded<float>::Trace(visitor, column_height_);
      TraceIfNeeded<std::optional<Length>>::Trace(visitor, column_gap_);
      TraceIfNeeded<StyleContentAlignmentData>::Trace(visitor, align_content_);
      TraceIfNeeded<StyleSelfAlignmentData>::Trace(visitor, align_self_);
      TraceIfNeeded<unsigned short>::Trace(visitor, column_count_);
      TraceIfNeeded<PositionArea>::Trace(visitor, position_area_);
    }

    bool operator==(const StyleMisc1Data& other) const {
      return (true
        && backdrop_filter_ == other.backdrop_filter_
        && column_rule_color_ == other.column_rule_color_
        && base::ValuesEquivalent(anchor_name_, other.anchor_name_)
        && base::ValuesEquivalent(border_shape_, other.border_shape_)
        && base::ValuesEquivalent(box_shadow_, other.box_shadow_)
        && base::ValuesEquivalent(clip_path_, other.clip_path_)
        && anchor_scope_ == other.anchor_scope_
        && column_rule_inset_cap_end_ == other.column_rule_inset_cap_end_
        && column_rule_inset_cap_start_ == other.column_rule_inset_cap_start_
        && position_anchor_ == other.position_anchor_
        && column_height_ == other.column_height_
        && column_gap_ == other.column_gap_
        && align_content_ == other.align_content_
        && align_self_ == other.align_self_
        && column_count_ == other.column_count_
        && position_area_ == other.position_area_
      );
    }

    FilterOperations backdrop_filter_;
    GapDataList<StyleColor> column_rule_color_;
    Member<ScopedCSSNameList> anchor_name_;
    Member<StyleBorderShape> border_shape_;
    Member<ShadowList> box_shadow_;
    Member<ClipPathOperation> clip_path_;
    StyleAnchorScope anchor_scope_;
    Length column_rule_inset_cap_end_;
    Length column_rule_inset_cap_start_;
    StylePositionAnchor position_anchor_;
    float column_height_;
    std::optional<Length> column_gap_;
    StyleContentAlignmentData align_content_;
    StyleSelfAlignmentData align_self_;
    unsigned short column_count_;
    PositionArea position_area_;
  };

  class StyleVisitedData : public GarbageCollected<StyleVisitedData> {
   public:
    explicit StyleVisitedData();
    CORE_EXPORT StyleVisitedData(const StyleVisitedData&);

    static StyleVisitedData* Create() {
      return MakeGarbageCollected<StyleVisitedData>();
    }
    StyleVisitedData* Copy() const {
      return MakeGarbageCollected<StyleVisitedData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<GapDataList<StyleColor>>::Trace(visitor, internal_visited_column_rule_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_background_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_border_bottom_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_border_left_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_border_right_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_border_top_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_outline_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_text_decoration_color_);
    }

    bool operator==(const StyleVisitedData& other) const {
      return (true
        && internal_visited_column_rule_color_ == other.internal_visited_column_rule_color_
        && internal_visited_background_color_ == other.internal_visited_background_color_
        && internal_visited_border_bottom_color_ == other.internal_visited_border_bottom_color_
        && internal_visited_border_left_color_ == other.internal_visited_border_left_color_
        && internal_visited_border_right_color_ == other.internal_visited_border_right_color_
        && internal_visited_border_top_color_ == other.internal_visited_border_top_color_
        && internal_visited_outline_color_ == other.internal_visited_outline_color_
        && internal_visited_text_decoration_color_ == other.internal_visited_text_decoration_color_
      );
    }

    GapDataList<StyleColor> internal_visited_column_rule_color_;
    StyleColor internal_visited_background_color_;
    StyleColor internal_visited_border_bottom_color_;
    StyleColor internal_visited_border_left_color_;
    StyleColor internal_visited_border_right_color_;
    StyleColor internal_visited_border_top_color_;
    StyleColor internal_visited_outline_color_;
    StyleColor internal_visited_text_decoration_color_;
  };

  class StyleMisc2Data : public GarbageCollected<StyleMisc2Data> {
   public:
    explicit StyleMisc2Data();
    CORE_EXPORT StyleMisc2Data(const StyleMisc2Data&);

    static StyleMisc2Data* Create() {
      return MakeGarbageCollected<StyleMisc2Data>();
    }
    StyleMisc2Data* Copy() const {
      return MakeGarbageCollected<StyleMisc2Data>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<FilterOperations>::Trace(visitor, filter_);
      TraceIfNeeded<GapDataList<EBorderStyle>>::Trace(visitor, column_rule_style_);
      TraceIfNeeded<GapDataList<int>>::Trace(visitor, column_rule_width_);
      TraceIfNeeded<GridTrackList>::Trace(visitor, grid_auto_columns_);
      TraceIfNeeded<GridTrackList>::Trace(visitor, grid_auto_rows_);
      TraceIfNeeded<Vector<AtomicString>>::Trace(visitor, container_name_);
      visitor->Trace(content_);
      TraceIfNeeded<FlowTolerance>::Trace(visitor, flow_tolerance_);
      TraceIfNeeded<Length>::Trace(visitor, column_rule_inset_junction_end_);
      TraceIfNeeded<Length>::Trace(visitor, column_rule_inset_junction_start_);
      TraceIfNeeded<Length>::Trace(visitor, flex_basis_);
      TraceIfNeeded<float>::Trace(visitor, column_width_);
      TraceIfNeeded<float>::Trace(visitor, flex_grow_);
      TraceIfNeeded<float>::Trace(visitor, flex_shrink_);
      TraceIfNeeded<uint16_t>::Trace(visitor, flex_line_count_);
      TraceIfNeeded<StyleFlexWrapData>::Trace(visitor, flex_wrap_);
    }

    bool operator==(const StyleMisc2Data& other) const {
      return (true
        && filter_ == other.filter_
        && column_rule_style_ == other.column_rule_style_
        && column_rule_width_ == other.column_rule_width_
        && grid_auto_columns_ == other.grid_auto_columns_
        && grid_auto_rows_ == other.grid_auto_rows_
        && container_name_ == other.container_name_
        && base::ValuesEquivalent(content_, other.content_)
        && flow_tolerance_ == other.flow_tolerance_
        && column_rule_inset_junction_end_ == other.column_rule_inset_junction_end_
        && column_rule_inset_junction_start_ == other.column_rule_inset_junction_start_
        && flex_basis_ == other.flex_basis_
        && column_width_ == other.column_width_
        && flex_grow_ == other.flex_grow_
        && flex_shrink_ == other.flex_shrink_
        && flex_line_count_ == other.flex_line_count_
        && flex_wrap_ == other.flex_wrap_
      );
    }

    FilterOperations filter_;
    GapDataList<EBorderStyle> column_rule_style_;
    GapDataList<int> column_rule_width_;
    GridTrackList grid_auto_columns_;
    GridTrackList grid_auto_rows_;
    Vector<AtomicString> container_name_;
    Member<ContentData> content_;
    FlowTolerance flow_tolerance_;
    Length column_rule_inset_junction_end_;
    Length column_rule_inset_junction_start_;
    Length flex_basis_;
    float column_width_;
    float flex_grow_;
    float flex_shrink_;
    uint16_t flex_line_count_;
    StyleFlexWrapData flex_wrap_;
  };

  class StyleMisc3Data : public GarbageCollected<StyleMisc3Data> {
   public:
    explicit StyleMisc3Data();
    CORE_EXPORT StyleMisc3Data(const StyleMisc3Data&);

    static StyleMisc3Data* Create() {
      return MakeGarbageCollected<StyleMisc3Data>();
    }
    StyleMisc3Data* Copy() const {
      return MakeGarbageCollected<StyleMisc3Data>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<StyleInterestDelay>::Trace(visitor, interest_delay_end_);
      TraceIfNeeded<StyleInterestDelay>::Trace(visitor, interest_delay_start_);
      TraceIfNeeded<GridPosition>::Trace(visitor, grid_column_end_);
      TraceIfNeeded<GridPosition>::Trace(visitor, grid_column_start_);
      TraceIfNeeded<GridPosition>::Trace(visitor, grid_row_end_);
      TraceIfNeeded<GridPosition>::Trace(visitor, grid_row_start_);
      visitor->Trace(grid_template_areas_);
      visitor->Trace(grid_template_columns_);
      visitor->Trace(grid_template_rows_);
      visitor->Trace(object_view_box_);
      TraceIfNeeded<LengthPoint>::Trace(visitor, object_position_);
      TraceIfNeeded<LengthPoint>::Trace(visitor, offset_anchor_);
      TraceIfNeeded<StyleInitialLetter>::Trace(visitor, initial_letter_);
      TraceIfNeeded<GridLanesDirection>::Trace(visitor, grid_lanes_direction_);
      TraceIfNeeded<StyleSelfAlignmentData>::Trace(visitor, justify_items_);
      TraceIfNeeded<StyleSelfAlignmentData>::Trace(visitor, justify_self_);
    }

    bool operator==(const StyleMisc3Data& other) const {
      return (true
        && interest_delay_end_ == other.interest_delay_end_
        && interest_delay_start_ == other.interest_delay_start_
        && grid_column_end_ == other.grid_column_end_
        && grid_column_start_ == other.grid_column_start_
        && grid_row_end_ == other.grid_row_end_
        && grid_row_start_ == other.grid_row_start_
        && base::ValuesEquivalent(grid_template_areas_, other.grid_template_areas_)
        && base::ValuesEquivalent(grid_template_columns_, other.grid_template_columns_)
        && base::ValuesEquivalent(grid_template_rows_, other.grid_template_rows_)
        && base::ValuesEquivalent(object_view_box_, other.object_view_box_)
        && object_position_ == other.object_position_
        && offset_anchor_ == other.offset_anchor_
        && initial_letter_ == other.initial_letter_
        && grid_lanes_direction_ == other.grid_lanes_direction_
        && justify_items_ == other.justify_items_
        && justify_self_ == other.justify_self_
      );
    }

    StyleInterestDelay interest_delay_end_;
    StyleInterestDelay interest_delay_start_;
    GridPosition grid_column_end_;
    GridPosition grid_column_start_;
    GridPosition grid_row_end_;
    GridPosition grid_row_start_;
    Member<ComputedGridTemplateAreas> grid_template_areas_;
    Member<ComputedGridTrackList> grid_template_columns_;
    Member<ComputedGridTrackList> grid_template_rows_;
    Member<BasicShape> object_view_box_;
    LengthPoint object_position_;
    LengthPoint offset_anchor_;
    StyleInitialLetter initial_letter_;
    GridLanesDirection grid_lanes_direction_;
    StyleSelfAlignmentData justify_items_;
    StyleSelfAlignmentData justify_self_;
  };

  class StyleForcedColorsData : public GarbageCollected<StyleForcedColorsData> {
   public:
    explicit StyleForcedColorsData();
    CORE_EXPORT StyleForcedColorsData(const StyleForcedColorsData&);

    static StyleForcedColorsData* Create() {
      return MakeGarbageCollected<StyleForcedColorsData>();
    }
    StyleForcedColorsData* Copy() const {
      return MakeGarbageCollected<StyleForcedColorsData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_forced_background_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_forced_border_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_forced_outline_color_);
    }

    bool operator==(const StyleForcedColorsData& other) const {
      return (true
        && internal_forced_background_color_ == other.internal_forced_background_color_
        && internal_forced_border_color_ == other.internal_forced_border_color_
        && internal_forced_outline_color_ == other.internal_forced_outline_color_
      );
    }

    StyleColor internal_forced_background_color_;
    StyleColor internal_forced_border_color_;
    StyleColor internal_forced_outline_color_;
  };

  class StyleMisc4Data : public GarbageCollected<StyleMisc4Data> {
   public:
    explicit StyleMisc4Data();
    CORE_EXPORT StyleMisc4Data(const StyleMisc4Data&);

    static StyleMisc4Data* Create() {
      return MakeGarbageCollected<StyleMisc4Data>();
    }
    StyleMisc4Data* Copy() const {
      return MakeGarbageCollected<StyleMisc4Data>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<AtomicString>::Trace(visitor, page_);
      TraceIfNeeded<GapDataList<StyleColor>>::Trace(visitor, row_rule_color_);
      visitor->Trace(offset_path_);
      visitor->Trace(position_try_fallbacks_);
      visitor->Trace(rotate_);
      TraceIfNeeded<Length>::Trace(visitor, offset_distance_);
      TraceIfNeeded<LengthPoint>::Trace(visitor, offset_position_);
      TraceIfNeeded<LengthPoint>::Trace(visitor, perspective_origin_);
      TraceIfNeeded<StyleOffsetRotation>::Trace(visitor, offset_rotate_);
      TraceIfNeeded<float>::Trace(visitor, perspective_);
      TraceIfNeeded<std::optional<Length>>::Trace(visitor, row_gap_);
      TraceIfNeeded<StyleColor>::Trace(visitor, outline_color_);
      TraceIfNeeded<int>::Trace(visitor, order_);
      TraceIfNeeded<int>::Trace(visitor, outline_offset_);
      TraceIfNeeded<int>::Trace(visitor, outline_width_);
      TraceIfNeeded<int>::Trace(visitor, reading_order_);
    }

    bool operator==(const StyleMisc4Data& other) const {
      return (true
        && page_ == other.page_
        && row_rule_color_ == other.row_rule_color_
        && base::ValuesEquivalent(offset_path_, other.offset_path_)
        && base::ValuesEquivalent(position_try_fallbacks_, other.position_try_fallbacks_)
        && base::ValuesEquivalent(rotate_, other.rotate_)
        && offset_distance_ == other.offset_distance_
        && offset_position_ == other.offset_position_
        && perspective_origin_ == other.perspective_origin_
        && offset_rotate_ == other.offset_rotate_
        && perspective_ == other.perspective_
        && row_gap_ == other.row_gap_
        && outline_color_ == other.outline_color_
        && order_ == other.order_
        && outline_offset_ == other.outline_offset_
        && outline_width_ == other.outline_width_
        && reading_order_ == other.reading_order_
      );
    }

    AtomicString page_;
    GapDataList<StyleColor> row_rule_color_;
    Member<OffsetPathOperation> offset_path_;
    Member<PositionTryFallbacks> position_try_fallbacks_;
    Member<RotateTransformOperation> rotate_;
    Length offset_distance_;
    LengthPoint offset_position_;
    LengthPoint perspective_origin_;
    StyleOffsetRotation offset_rotate_;
    float perspective_;
    std::optional<Length> row_gap_;
    StyleColor outline_color_;
    int order_;
    int outline_offset_;
    int outline_width_;
    int reading_order_;
  };

  class StyleMisc5Data : public GarbageCollected<StyleMisc5Data> {
   public:
    explicit StyleMisc5Data();
    CORE_EXPORT StyleMisc5Data(const StyleMisc5Data&);

    static StyleMisc5Data* Create() {
      return MakeGarbageCollected<StyleMisc5Data>();
    }
    StyleMisc5Data* Copy() const {
      return MakeGarbageCollected<StyleMisc5Data>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<GapDataList<EBorderStyle>>::Trace(visitor, row_rule_style_);
      TraceIfNeeded<GapDataList<int>>::Trace(visitor, row_rule_width_);
      visitor->Trace(scale_);
      visitor->Trace(scroll_marker_group_);
      TraceIfNeeded<Length>::Trace(visitor, row_rule_inset_cap_end_);
      TraceIfNeeded<Length>::Trace(visitor, row_rule_inset_cap_start_);
      TraceIfNeeded<Length>::Trace(visitor, row_rule_inset_junction_end_);
      TraceIfNeeded<Length>::Trace(visitor, row_rule_inset_junction_start_);
      TraceIfNeeded<Length>::Trace(visitor, scroll_padding_bottom_);
      TraceIfNeeded<Length>::Trace(visitor, scroll_padding_left_);
      TraceIfNeeded<Length>::Trace(visitor, scroll_padding_right_);
      TraceIfNeeded<Length>::Trace(visitor, scroll_padding_top_);
      TraceIfNeeded<float>::Trace(visitor, scroll_margin_bottom_);
      TraceIfNeeded<float>::Trace(visitor, scroll_margin_left_);
      TraceIfNeeded<float>::Trace(visitor, scroll_margin_right_);
      TraceIfNeeded<float>::Trace(visitor, scroll_margin_top_);
    }

    bool operator==(const StyleMisc5Data& other) const {
      return (true
        && row_rule_style_ == other.row_rule_style_
        && row_rule_width_ == other.row_rule_width_
        && base::ValuesEquivalent(scale_, other.scale_)
        && base::ValuesEquivalent(scroll_marker_group_, other.scroll_marker_group_)
        && row_rule_inset_cap_end_ == other.row_rule_inset_cap_end_
        && row_rule_inset_cap_start_ == other.row_rule_inset_cap_start_
        && row_rule_inset_junction_end_ == other.row_rule_inset_junction_end_
        && row_rule_inset_junction_start_ == other.row_rule_inset_junction_start_
        && scroll_padding_bottom_ == other.scroll_padding_bottom_
        && scroll_padding_left_ == other.scroll_padding_left_
        && scroll_padding_right_ == other.scroll_padding_right_
        && scroll_padding_top_ == other.scroll_padding_top_
        && scroll_margin_bottom_ == other.scroll_margin_bottom_
        && scroll_margin_left_ == other.scroll_margin_left_
        && scroll_margin_right_ == other.scroll_margin_right_
        && scroll_margin_top_ == other.scroll_margin_top_
      );
    }

    GapDataList<EBorderStyle> row_rule_style_;
    GapDataList<int> row_rule_width_;
    Member<ScaleTransformOperation> scale_;
    Member<ScrollMarkerGroup> scroll_marker_group_;
    Length row_rule_inset_cap_end_;
    Length row_rule_inset_cap_start_;
    Length row_rule_inset_junction_end_;
    Length row_rule_inset_junction_start_;
    Length scroll_padding_bottom_;
    Length scroll_padding_left_;
    Length scroll_padding_right_;
    Length scroll_padding_top_;
    float scroll_margin_bottom_;
    float scroll_margin_left_;
    float scroll_margin_right_;
    float scroll_margin_top_;
  };

  class StyleMisc6Data : public GarbageCollected<StyleMisc6Data> {
   public:
    explicit StyleMisc6Data();
    CORE_EXPORT StyleMisc6Data(const StyleMisc6Data&);

    static StyleMisc6Data* Create() {
      return MakeGarbageCollected<StyleMisc6Data>();
    }
    StyleMisc6Data* Copy() const {
      return MakeGarbageCollected<StyleMisc6Data>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<StyleViewTransitionGroup>::Trace(visitor, view_transition_group_);
      TraceIfNeeded<TextOverflowData>::Trace(visitor, text_overflow_);
      visitor->Trace(shape_outside_);
      visitor->Trace(translate_);
      visitor->Trace(view_transition_class_);
      visitor->Trace(view_transition_name_);
      TraceIfNeeded<StyleTriggerScope>::Trace(visitor, trigger_scope_);
      TraceIfNeeded<Length>::Trace(visitor, shape_margin_);
      TraceIfNeeded<TextDecorationInset>::Trace(visitor, text_decoration_inset_);
      TraceIfNeeded<TextDecorationThickness>::Trace(visitor, text_decoration_thickness_);
      TraceIfNeeded<float>::Trace(visitor, shape_image_threshold_);
      TraceIfNeeded<float>::Trace(visitor, box_flex_);
      TraceIfNeeded<StyleColor>::Trace(visitor, text_decoration_color_);
      TraceIfNeeded<cc::ScrollSnapAlign>::Trace(visitor, scroll_snap_align_);
      TraceIfNeeded<cc::ScrollSnapType>::Trace(visitor, scroll_snap_type_);
    }

    bool operator==(const StyleMisc6Data& other) const {
      return (true
        && view_transition_group_ == other.view_transition_group_
        && text_overflow_ == other.text_overflow_
        && base::ValuesEquivalent(shape_outside_, other.shape_outside_)
        && base::ValuesEquivalent(translate_, other.translate_)
        && base::ValuesEquivalent(view_transition_class_, other.view_transition_class_)
        && base::ValuesEquivalent(view_transition_name_, other.view_transition_name_)
        && trigger_scope_ == other.trigger_scope_
        && shape_margin_ == other.shape_margin_
        && text_decoration_inset_ == other.text_decoration_inset_
        && text_decoration_thickness_ == other.text_decoration_thickness_
        && shape_image_threshold_ == other.shape_image_threshold_
        && box_flex_ == other.box_flex_
        && text_decoration_color_ == other.text_decoration_color_
        && scroll_snap_align_ == other.scroll_snap_align_
        && scroll_snap_type_ == other.scroll_snap_type_
        && touch_action_ == other.touch_action_
      );
    }

    StyleViewTransitionGroup view_transition_group_;
    TextOverflowData text_overflow_;
    Member<ShapeValue> shape_outside_;
    Member<TranslateTransformOperation> translate_;
    Member<ScopedCSSNameList> view_transition_class_;
    Member<StyleViewTransitionName> view_transition_name_;
    StyleTriggerScope trigger_scope_;
    Length shape_margin_;
    TextDecorationInset text_decoration_inset_;
    TextDecorationThickness text_decoration_thickness_;
    float shape_image_threshold_;
    float box_flex_;
    StyleColor text_decoration_color_;
    cc::ScrollSnapAlign scroll_snap_align_;
    cc::ScrollSnapType scroll_snap_type_;
    unsigned touch_action_ : 8; // TouchAction
  };

  class StyleTimelineData : public GarbageCollected<StyleTimelineData> {
   public:
    explicit StyleTimelineData();
    CORE_EXPORT StyleTimelineData(const StyleTimelineData&);

    static StyleTimelineData* Create() {
      return MakeGarbageCollected<StyleTimelineData>();
    }
    StyleTimelineData* Copy() const {
      return MakeGarbageCollected<StyleTimelineData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<StyleTimelineScope>::Trace(visitor, timeline_scope_);
      TraceIfNeeded<Vector<AtomicString>>::Trace(visitor, scroll_timeline_name_);
      TraceIfNeeded<Vector<AtomicString>>::Trace(visitor, view_timeline_name_);
      TraceIfNeeded<Vector<TimelineAxis>>::Trace(visitor, scroll_timeline_axis_);
      TraceIfNeeded<Vector<TimelineAxis>>::Trace(visitor, view_timeline_axis_);
      TraceIfNeeded<Vector<TimelineInset>>::Trace(visitor, view_timeline_inset_);
    }

    bool operator==(const StyleTimelineData& other) const {
      return (true
        && timeline_scope_ == other.timeline_scope_
        && scroll_timeline_name_ == other.scroll_timeline_name_
        && view_timeline_name_ == other.view_timeline_name_
        && scroll_timeline_axis_ == other.scroll_timeline_axis_
        && view_timeline_axis_ == other.view_timeline_axis_
        && view_timeline_inset_ == other.view_timeline_inset_
      );
    }

    StyleTimelineScope timeline_scope_;
    Vector<AtomicString> scroll_timeline_name_;
    Vector<AtomicString> view_timeline_name_;
    Vector<TimelineAxis> scroll_timeline_axis_;
    Vector<TimelineAxis> view_timeline_axis_;
    Vector<TimelineInset> view_timeline_inset_;
  };

  class StyleMisc7Data : public GarbageCollected<StyleMisc7Data> {
   public:
    explicit StyleMisc7Data();
    CORE_EXPORT StyleMisc7Data(const StyleMisc7Data&);

    static StyleMisc7Data* Create() {
      return MakeGarbageCollected<StyleMisc7Data>();
    }
    StyleMisc7Data* Copy() const {
      return MakeGarbageCollected<StyleMisc7Data>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<AtomicString>::Trace(visitor, display_layout_custom_name_);
      TraceIfNeeded<AtomicString>::Trace(visitor, display_layout_custom_parent_name_);
      TraceIfNeeded<FillLayer>::Trace(visitor, mask_);
      visitor->Trace(box_reflect_);
      visitor->Trace(animations_);
      visitor->Trace(transitions_);
      TraceIfNeeded<NinePieceImage>::Trace(visitor, mask_box_image_);
      TraceIfNeeded<gfx::SizeF>::Trace(visitor, page_size_);
      TraceIfNeeded<gfx::Size>::Trace(visitor, unconditional_scrollbar_size_);
      TraceIfNeeded<int>::Trace(visitor, webkit_line_clamp_);
      TraceIfNeeded<unsigned>::Trace(visitor, box_ordinal_group_);
    }

    bool operator==(const StyleMisc7Data& other) const {
      return (true
        && display_layout_custom_name_ == other.display_layout_custom_name_
        && display_layout_custom_parent_name_ == other.display_layout_custom_parent_name_
        && base::ValuesEquivalent(custom_highlight_names_, other.custom_highlight_names_)
        && base::ValuesEquivalent(counter_directives_, other.counter_directives_)
        && base::ValuesEquivalent(counter_increment_list_, other.counter_increment_list_)
        && base::ValuesEquivalent(counter_reset_list_, other.counter_reset_list_)
        && base::ValuesEquivalent(counter_set_list_, other.counter_set_list_)
        && mask_ == other.mask_
        && base::ValuesEquivalent(box_reflect_, other.box_reflect_)
        && base::ValuesEquivalent(animations_, other.animations_)
        && base::ValuesEquivalent(transitions_, other.transitions_)
        && mask_box_image_ == other.mask_box_image_
        && page_size_ == other.page_size_
        && unconditional_scrollbar_size_ == other.unconditional_scrollbar_size_
        && webkit_line_clamp_ == other.webkit_line_clamp_
        && box_ordinal_group_ == other.box_ordinal_group_
      );
    }

    AtomicString display_layout_custom_name_;
    AtomicString display_layout_custom_parent_name_;
    std::unique_ptr<HashSet<AtomicString>> custom_highlight_names_;
    std::unique_ptr<CounterDirectiveMap> counter_directives_;
    std::unique_ptr<CounterPropertyList> counter_increment_list_;
    std::unique_ptr<CounterPropertyList> counter_reset_list_;
    std::unique_ptr<CounterPropertyList> counter_set_list_;
    FillLayer mask_;
    Member<StyleReflection> box_reflect_;
    Member<CSSAnimationData> animations_;
    Member<CSSTransitionData> transitions_;
    NinePieceImage mask_box_image_;
    gfx::SizeF page_size_;
    gfx::Size unconditional_scrollbar_size_;
    int webkit_line_clamp_;
    unsigned box_ordinal_group_;
  };

  class StyleMisc8Data : public GarbageCollected<StyleMisc8Data> {
   public:
    explicit StyleMisc8Data();
    CORE_EXPORT StyleMisc8Data(const StyleMisc8Data&);

    static StyleMisc8Data* Create() {
      return MakeGarbageCollected<StyleMisc8Data>();
    }
    StyleMisc8Data* Copy() const {
      return MakeGarbageCollected<StyleMisc8Data>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<Vector<String>>::Trace(visitor, callback_selectors_);
      visitor->Trace(document_rules_selectors_);
      visitor->Trace(paint_images_);
      TraceIfNeeded<StyleNonInheritedVariables>::Trace(visitor, non_inherited_variables_);
      TraceIfNeeded<std::optional<PhysicalOffset>>::Trace(visitor, anchor_center_offset_);
      TraceIfNeeded<std::optional<blink::PositionAreaOffsets>>::Trace(visitor, position_area_offsets_);
      TraceIfNeeded<MaxLinesData>::Trace(visitor, max_lines_);
    }

    bool operator==(const StyleMisc8Data& other) const {
      return (true
        && callback_selectors_ == other.callback_selectors_
        && base::ValuesEquivalent(document_rules_selectors_, other.document_rules_selectors_)
        && non_inherited_variables_ == other.non_inherited_variables_
        && max_lines_ == other.max_lines_
      );
    }

    Vector<String> callback_selectors_;
    Member<GCedHeapHashSet<WeakMember<StyleRule>>> document_rules_selectors_;
    Member<PaintImages> paint_images_;
    StyleNonInheritedVariables non_inherited_variables_;
    std::optional<PhysicalOffset> anchor_center_offset_;
    std::optional<blink::PositionAreaOffsets> position_area_offsets_;
    MaxLinesData max_lines_;
  };

  class StyleMathData : public GarbageCollected<StyleMathData> {
   public:
    explicit StyleMathData();
    CORE_EXPORT StyleMathData(const StyleMathData&);

    static StyleMathData* Create() {
      return MakeGarbageCollected<StyleMathData>();
    }
    StyleMathData* Copy() const {
      return MakeGarbageCollected<StyleMathData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<Length>::Trace(visitor, math_baseline_);
      TraceIfNeeded<Length>::Trace(visitor, math_fraction_bar_thickness_);
      TraceIfNeeded<Length>::Trace(visitor, math_l_space_);
      TraceIfNeeded<Length>::Trace(visitor, math_r_space_);
      TraceIfNeeded<Length>::Trace(visitor, math_padded_v_offset_);
      TraceIfNeeded<Length>::Trace(visitor, math_padded_depth_);
      TraceIfNeeded<Length>::Trace(visitor, math_min_size_);
      TraceIfNeeded<Length>::Trace(visitor, math_max_size_);
    }

    bool operator==(const StyleMathData& other) const {
      return (true
        && math_baseline_ == other.math_baseline_
        && math_fraction_bar_thickness_ == other.math_fraction_bar_thickness_
        && math_l_space_ == other.math_l_space_
        && math_r_space_ == other.math_r_space_
        && math_padded_v_offset_ == other.math_padded_v_offset_
        && math_padded_depth_ == other.math_padded_depth_
        && math_min_size_ == other.math_min_size_
        && math_max_size_ == other.math_max_size_
      );
    }

    Length math_baseline_;
    Length math_fraction_bar_thickness_;
    Length math_l_space_;
    Length math_r_space_;
    Length math_padded_v_offset_;
    Length math_padded_depth_;
    Length math_min_size_;
    Length math_max_size_;
  };

  class StyleMiscData : public GarbageCollected<StyleMiscData> {
   public:
    explicit StyleMiscData();
    CORE_EXPORT StyleMiscData(const StyleMiscData&);

    static StyleMiscData* Create() {
      return MakeGarbageCollected<StyleMiscData>();
    }
    StyleMiscData* Copy() const {
      return MakeGarbageCollected<StyleMiscData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      visitor->Trace(misc_1_data_);
      visitor->Trace(visited_data_);
      visitor->Trace(misc_2_data_);
      visitor->Trace(misc_3_data_);
      visitor->Trace(forced_colors_data_);
      visitor->Trace(misc_4_data_);
      visitor->Trace(misc_5_data_);
      visitor->Trace(misc_6_data_);
      visitor->Trace(timeline_data_);
      visitor->Trace(misc_7_data_);
      visitor->Trace(misc_8_data_);
      visitor->Trace(math_data_);
      visitor->Trace(will_change_);
    }

    bool operator==(const StyleMiscData& other) const {
      return (true
        && base::ValuesEquivalent(misc_1_data_, other.misc_1_data_)
        && base::ValuesEquivalent(visited_data_, other.visited_data_)
        && base::ValuesEquivalent(misc_2_data_, other.misc_2_data_)
        && base::ValuesEquivalent(misc_3_data_, other.misc_3_data_)
        && base::ValuesEquivalent(forced_colors_data_, other.forced_colors_data_)
        && base::ValuesEquivalent(misc_4_data_, other.misc_4_data_)
        && base::ValuesEquivalent(misc_5_data_, other.misc_5_data_)
        && base::ValuesEquivalent(misc_6_data_, other.misc_6_data_)
        && base::ValuesEquivalent(timeline_data_, other.timeline_data_)
        && base::ValuesEquivalent(misc_7_data_, other.misc_7_data_)
        && base::ValuesEquivalent(misc_8_data_, other.misc_8_data_)
        && base::ValuesEquivalent(math_data_, other.math_data_)
        && base::ValuesEquivalent(will_change_, other.will_change_)
        && appearance_ == other.appearance_
        && blend_mode_ == other.blend_mode_
        && contain_ == other.contain_
        && effective_appearance_ == other.effective_appearance_
        && break_after_ == other.break_after_
        && break_before_ == other.break_before_
        && container_type_ == other.container_type_
        && grid_auto_flow_ == other.grid_auto_flow_
        && margin_trim_ == other.margin_trim_
        && outline_style_ == other.outline_style_
        && scrollbar_gutter_ == other.scrollbar_gutter_
        && box_align_ == other.box_align_
        && object_fit_ == other.object_fit_
        && position_try_order_ == other.position_try_order_
        && position_visibility_ == other.position_visibility_
        && reading_flow_ == other.reading_flow_
        && affected_by_css_function_ == other.affected_by_css_function_
        && resize_ == other.resize_
        && text_decoration_style_ == other.text_decoration_style_
        && box_pack_ == other.box_pack_
        && break_inside_ == other.break_inside_
        && column_rule_break_ == other.column_rule_break_
        && column_rule_visibility_items_ == other.column_rule_visibility_items_
        && column_wrap_ == other.column_wrap_
        && continue_ == other.continue_
        && flex_direction_ == other.flex_direction_
        && overscroll_behavior_x_ == other.overscroll_behavior_x_
        && overscroll_behavior_y_ == other.overscroll_behavior_y_
        && overscroll_container_type_ == other.overscroll_container_type_
        && page_margin_safety_ == other.page_margin_safety_
        && page_orientation_ == other.page_orientation_
        && page_size_type_ == other.page_size_type_
        && row_rule_break_ == other.row_rule_break_
        && row_rule_visibility_items_ == other.row_rule_visibility_items_
        && scroll_behavior_ == other.scroll_behavior_
        && scrollbar_width_ == other.scrollbar_width_
        && user_drag_ == other.user_drag_
        && affected_by_functional_media_ == other.affected_by_functional_media_
        && affected_by_functional_navigation_ == other.affected_by_functional_navigation_
        && align_content_block_center_ == other.align_content_block_center_
        && backface_visibility_ == other.backface_visibility_
        && box_orient_ == other.box_orient_
        && can_affect_animations_ == other.can_affect_animations_
        && column_fill_ == other.column_fill_
        && column_span_ == other.column_span_
        && depends_on_anchored_container_queries_ == other.depends_on_anchored_container_queries_
        && depends_on_scroll_state_container_queries_ == other.depends_on_scroll_state_container_queries_
        && depends_on_size_container_queries_ == other.depends_on_size_container_queries_
        && depends_on_style_container_queries_ == other.depends_on_style_container_queries_
        && element_is_view_transition_participant_ == other.element_is_view_transition_participant_
        && first_line_depends_on_size_container_queries_ == other.first_line_depends_on_size_container_queries_
        && forces_blockifies_children_ == other.forces_blockifies_children_
        && grid_lanes_pack_ == other.grid_lanes_pack_
        && has_auto_column_count_ == other.has_auto_column_count_
        && has_auto_column_height_ == other.has_auto_column_height_
        && has_auto_column_width_ == other.has_auto_column_width_
        && has_current_backdrop_filter_animation_ == other.has_current_backdrop_filter_animation_
        && has_current_background_color_animation_ == other.has_current_background_color_animation_
        && has_current_clip_path_animation_ == other.has_current_clip_path_animation_
        && has_current_filter_animation_ == other.has_current_filter_animation_
        && has_current_opacity_animation_ == other.has_current_opacity_animation_
        && has_current_rotate_animation_ == other.has_current_rotate_animation_
        && has_current_scale_animation_ == other.has_current_scale_animation_
        && has_current_transform_animation_ == other.has_current_transform_animation_
        && has_current_translate_animation_ == other.has_current_translate_animation_
        && has_explicit_overflow_x_visible_ == other.has_explicit_overflow_x_visible_
        && has_explicit_overflow_y_visible_ == other.has_explicit_overflow_y_visible_
        && has_layout_containment_for_view_transition_scope_ == other.has_layout_containment_for_view_transition_scope_
        && has_size_containment_for_view_transition_scope_ == other.has_size_containment_for_view_transition_scope_
        && internal_overscroll_container_ == other.internal_overscroll_container_
        && internal_overscroll_position_ == other.internal_overscroll_position_
        && internal_unbounded_ == other.internal_unbounded_
        && is_bottom_relative_to_safe_area_inset_ == other.is_bottom_relative_to_safe_area_inset_
        && is_running_rotate_animation_on_compositor_ == other.is_running_rotate_animation_on_compositor_
        && is_running_scale_animation_on_compositor_ == other.is_running_scale_animation_on_compositor_
        && is_running_transform_animation_on_compositor_ == other.is_running_transform_animation_on_compositor_
        && is_running_translate_animation_on_compositor_ == other.is_running_translate_animation_on_compositor_
        && is_secondary_body_element_ == other.is_secondary_body_element_
        && is_specified_display_webkit_box_ == other.is_specified_display_webkit_box_
        && is_starting_style_ == other.is_starting_style_
        && isolation_ == other.isolation_
        && line_clamp_internal_block_ellipsis_ == other.line_clamp_internal_block_ellipsis_
        && max_content_sizing_ == other.max_content_sizing_
        && outline_style_is_auto_ == other.outline_style_is_auto_
        && overlay_ == other.overlay_
        && requires_accelerated_compositing_for_external_reasons_ == other.requires_accelerated_compositing_for_external_reasons_
        && rule_overlap_ == other.rule_overlap_
        && scroll_axis_lock_ == other.scroll_axis_lock_
        && scroll_initial_target_ == other.scroll_initial_target_
        && scroll_target_group_ == other.scroll_target_group_
        && transform_style_3d_ == other.transform_style_3d_
        && view_transition_scope_ == other.view_transition_scope_
      );
    }

    Member<StyleMisc1Data> misc_1_data_;
    Member<StyleVisitedData> visited_data_;
    Member<StyleMisc2Data> misc_2_data_;
    Member<StyleMisc3Data> misc_3_data_;
    Member<StyleForcedColorsData> forced_colors_data_;
    Member<StyleMisc4Data> misc_4_data_;
    Member<StyleMisc5Data> misc_5_data_;
    Member<StyleMisc6Data> misc_6_data_;
    Member<StyleTimelineData> timeline_data_;
    Member<StyleMisc7Data> misc_7_data_;
    Member<StyleMisc8Data> misc_8_data_;
    Member<StyleMathData> math_data_;
    Member<StyleWillChangeData> will_change_;
    unsigned appearance_ : 5; // AppearanceValue
    unsigned blend_mode_ : 5; // BlendMode
    unsigned contain_ : 5; // unsigned
    unsigned effective_appearance_ : 5; // AppearanceValue
    unsigned break_after_ : 4; // EBreakBetween
    unsigned break_before_ : 4; // EBreakBetween
    unsigned container_type_ : 4; // unsigned
    unsigned grid_auto_flow_ : 4; // GridAutoFlow
    unsigned margin_trim_ : 4; // unsigned
    unsigned outline_style_ : 4; // EBorderStyle
    unsigned scrollbar_gutter_ : 4; // unsigned
    unsigned box_align_ : 3; // EBoxAlignment
    unsigned object_fit_ : 3; // EObjectFit
    unsigned position_try_order_ : 3; // EPositionTryOrder
    unsigned position_visibility_ : 3; // PositionVisibility
    unsigned reading_flow_ : 3; // EReadingFlow
    unsigned affected_by_css_function_ : 1; // bool
    unsigned resize_ : 3; // EResize
    unsigned text_decoration_style_ : 3; // ETextDecorationStyle
    unsigned box_pack_ : 2; // EBoxPack
    unsigned break_inside_ : 2; // EBreakInside
    unsigned column_rule_break_ : 2; // RuleBreak
    unsigned column_rule_visibility_items_ : 2; // RuleVisibilityItems
    unsigned column_wrap_ : 2; // EColumnWrap
    unsigned continue_ : 2; // EContinue
    unsigned flex_direction_ : 2; // EFlexDirection
    unsigned overscroll_behavior_x_ : 2; // EOverscrollBehavior
    unsigned overscroll_behavior_y_ : 2; // EOverscrollBehavior
    unsigned overscroll_container_type_ : 2; // EOverscrollContainerType
    unsigned page_margin_safety_ : 2; // EPageMarginSafety
    unsigned page_orientation_ : 2; // PageOrientation
    unsigned page_size_type_ : 2; // PageSizeType
    unsigned row_rule_break_ : 2; // RuleBreak
    unsigned row_rule_visibility_items_ : 2; // RuleVisibilityItems
    unsigned scroll_behavior_ : 2; // mojom::blink::ScrollBehavior
    unsigned scrollbar_width_ : 2; // EScrollbarWidth
    unsigned user_drag_ : 2; // EUserDrag
    unsigned affected_by_functional_media_ : 1; // bool
    unsigned affected_by_functional_navigation_ : 1; // bool
    unsigned align_content_block_center_ : 1; // bool
    unsigned backface_visibility_ : 1; // EBackfaceVisibility
    unsigned box_orient_ : 1; // EBoxOrient
    unsigned can_affect_animations_ : 1; // bool
    unsigned column_fill_ : 1; // EColumnFill
    unsigned column_span_ : 1; // EColumnSpan
    unsigned depends_on_anchored_container_queries_ : 1; // bool
    unsigned depends_on_scroll_state_container_queries_ : 1; // bool
    unsigned depends_on_size_container_queries_ : 1; // bool
    unsigned depends_on_style_container_queries_ : 1; // bool
    unsigned element_is_view_transition_participant_ : 1; // bool
    unsigned first_line_depends_on_size_container_queries_ : 1; // bool
    unsigned forces_blockifies_children_ : 1; // bool
    unsigned grid_lanes_pack_ : 1; // EGridLanesPack
    unsigned has_auto_column_count_ : 1; // bool
    unsigned has_auto_column_height_ : 1; // bool
    unsigned has_auto_column_width_ : 1; // bool
    unsigned has_current_backdrop_filter_animation_ : 1; // bool
    unsigned has_current_background_color_animation_ : 1; // bool
    unsigned has_current_clip_path_animation_ : 1; // bool
    unsigned has_current_filter_animation_ : 1; // bool
    unsigned has_current_opacity_animation_ : 1; // bool
    unsigned has_current_rotate_animation_ : 1; // bool
    unsigned has_current_scale_animation_ : 1; // bool
    unsigned has_current_transform_animation_ : 1; // bool
    unsigned has_current_translate_animation_ : 1; // bool
    unsigned has_custom_highlight_universal_selector_ : 1; // bool
    unsigned has_element_dependent_random_functions_ : 1; // bool
    unsigned has_env_safe_area_inset_bottom_ : 1; // bool
    unsigned has_explicit_overflow_x_visible_ : 1; // bool
    unsigned has_explicit_overflow_y_visible_ : 1; // bool
    unsigned has_layout_containment_for_view_transition_scope_ : 1; // bool
    unsigned has_line_height_relative_units_ : 1; // bool
    unsigned has_non_ua_highlight_pseudo_styles_ : 1; // bool
    unsigned has_non_universal_highlight_pseudo_styles_ : 1; // bool
    unsigned has_sibling_functions_ : 1; // bool
    unsigned has_size_containment_for_view_transition_scope_ : 1; // bool
    unsigned highlights_depend_on_size_container_queries_ : 1; // bool
    unsigned inline_style_lost_cascade_ : 1; // bool
    unsigned internal_overscroll_container_ : 1; // EInternalOverscrollContainer
    unsigned internal_overscroll_position_ : 1; // EInternalOverscrollPosition
    unsigned internal_unbounded_ : 1; // EInternalUnbounded
    unsigned is_bottom_relative_to_safe_area_inset_ : 1; // bool
    unsigned is_running_backdrop_filter_animation_on_compositor_ : 1; // bool
    unsigned is_running_filter_animation_on_compositor_ : 1; // bool
    unsigned is_running_opacity_animation_on_compositor_ : 1; // bool
    unsigned is_running_rotate_animation_on_compositor_ : 1; // bool
    unsigned is_running_scale_animation_on_compositor_ : 1; // bool
    unsigned is_running_transform_animation_on_compositor_ : 1; // bool
    unsigned is_running_translate_animation_on_compositor_ : 1; // bool
    unsigned is_secondary_body_element_ : 1; // bool
    unsigned is_specified_display_webkit_box_ : 1; // bool
    unsigned is_starting_style_ : 1; // bool
    unsigned isolation_ : 1; // EIsolation
    unsigned line_clamp_internal_block_ellipsis_ : 1; // EBlockEllipsis
    unsigned max_content_sizing_ : 1; // EMaxContentSizing
    unsigned outline_style_is_auto_ : 1; // bool
    unsigned overlay_ : 1; // EOverlay
    unsigned requires_accelerated_compositing_for_external_reasons_ : 1; // bool
    unsigned rule_overlap_ : 1; // ERuleOverlap
    unsigned scroll_axis_lock_ : 1; // EScrollAxisLock
    unsigned scroll_initial_target_ : 1; // EScrollInitialTarget
    unsigned scroll_target_group_ : 1; // EScrollTargetGroup
    unsigned transform_style_3d_ : 1; // ETransformStyle3D
    unsigned view_transition_scope_ : 1; // EViewTransitionScope
  };

  class StyleInheritedForcedColorsData : public GarbageCollected<StyleInheritedForcedColorsData> {
   public:
    explicit StyleInheritedForcedColorsData();
    CORE_EXPORT StyleInheritedForcedColorsData(const StyleInheritedForcedColorsData&);

    static StyleInheritedForcedColorsData* Create() {
      return MakeGarbageCollected<StyleInheritedForcedColorsData>();
    }
    StyleInheritedForcedColorsData* Copy() const {
      return MakeGarbageCollected<StyleInheritedForcedColorsData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_forced_visited_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_forced_color_);
    }

    bool operator==(const StyleInheritedForcedColorsData& other) const {
      return (true
        && internal_forced_visited_color_ == other.internal_forced_visited_color_
        && internal_forced_color_ == other.internal_forced_color_
      );
    }

    StyleColor internal_forced_visited_color_;
    StyleColor internal_forced_color_;
  };

  class StyleInheritedVisitedData : public GarbageCollected<StyleInheritedVisitedData> {
   public:
    explicit StyleInheritedVisitedData();
    CORE_EXPORT StyleInheritedVisitedData(const StyleInheritedVisitedData&);

    static StyleInheritedVisitedData* Create() {
      return MakeGarbageCollected<StyleInheritedVisitedData>();
    }
    StyleInheritedVisitedData* Copy() const {
      return MakeGarbageCollected<StyleInheritedVisitedData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<StyleCaretColor>::Trace(visitor, internal_visited_caret_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_text_emphasis_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_text_fill_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_text_stroke_color_);
    }

    bool operator==(const StyleInheritedVisitedData& other) const {
      return (true
        && internal_visited_caret_color_ == other.internal_visited_caret_color_
        && internal_visited_text_emphasis_color_ == other.internal_visited_text_emphasis_color_
        && internal_visited_text_fill_color_ == other.internal_visited_text_fill_color_
        && internal_visited_text_stroke_color_ == other.internal_visited_text_stroke_color_
      );
    }

    StyleCaretColor internal_visited_caret_color_;
    StyleColor internal_visited_text_emphasis_color_;
    StyleColor internal_visited_text_fill_color_;
    StyleColor internal_visited_text_stroke_color_;
  };

  class StyleHighlightDataData : public GarbageCollected<StyleHighlightDataData> {
   public:
    explicit StyleHighlightDataData();
    CORE_EXPORT StyleHighlightDataData(const StyleHighlightDataData&);

    static StyleHighlightDataData* Create() {
      return MakeGarbageCollected<StyleHighlightDataData>();
    }
    StyleHighlightDataData* Copy() const {
      return MakeGarbageCollected<StyleHighlightDataData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<StyleHighlightData>::Trace(visitor, highlight_data_);
    }

    bool operator==(const StyleHighlightDataData& other) const {
      return (true
        && highlight_data_ == other.highlight_data_
      );
    }

    StyleHighlightData highlight_data_;
  };

  class StyleInheritedData : public GarbageCollected<StyleInheritedData> {
   public:
    explicit StyleInheritedData();
    CORE_EXPORT StyleInheritedData(const StyleInheritedData&);

    static StyleInheritedData* Create() {
      return MakeGarbageCollected<StyleInheritedData>();
    }
    StyleInheritedData* Copy() const {
      return MakeGarbageCollected<StyleInheritedData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      visitor->Trace(inherited_forced_colors_data_);
      visitor->Trace(inherited_visited_data_);
      visitor->Trace(highlight_data_data_);
      visitor->Trace(font_);
      visitor->Trace(container_font_);
      TraceIfNeeded<StyleInheritedVariables>::Trace(visitor, inherited_variables_);
      TraceIfNeeded<Length>::Trace(visitor, letter_spacing_);
      TraceIfNeeded<Length>::Trace(visitor, line_height_);
      TraceIfNeeded<Length>::Trace(visitor, word_spacing_);
      TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, color_);
      TraceIfNeeded<short>::Trace(visitor, horizontal_border_spacing_);
      TraceIfNeeded<short>::Trace(visitor, vertical_border_spacing_);
    }

    bool operator==(const StyleInheritedData& other) const {
      return (true
        && base::ValuesEquivalent(inherited_forced_colors_data_, other.inherited_forced_colors_data_)
        && base::ValuesEquivalent(inherited_visited_data_, other.inherited_visited_data_)
        && base::ValuesEquivalent(highlight_data_data_, other.highlight_data_data_)
        && base::ValuesEquivalent(font_, other.font_)
        && base::ValuesEquivalent(container_font_, other.container_font_)
        && inherited_variables_ == other.inherited_variables_
        && letter_spacing_ == other.letter_spacing_
        && line_height_ == other.line_height_
        && word_spacing_ == other.word_spacing_
        && internal_visited_color_ == other.internal_visited_color_
        && color_ == other.color_
        && horizontal_border_spacing_ == other.horizontal_border_spacing_
        && vertical_border_spacing_ == other.vertical_border_spacing_
        && cursor_ == other.cursor_
        && text_transform_ == other.text_transform_
        && color_is_current_color_ == other.color_is_current_color_
        && in_forced_colors_mode_ == other.in_forced_colors_mode_
        && internal_visited_color_is_current_color_ == other.internal_visited_color_is_current_color_
      );
    }

    Member<StyleInheritedForcedColorsData> inherited_forced_colors_data_;
    Member<StyleInheritedVisitedData> inherited_visited_data_;
    Member<StyleHighlightDataData> highlight_data_data_;
    Member<Font> font_;
    Member<Font> container_font_;
    StyleInheritedVariables inherited_variables_;
    Length letter_spacing_;
    Length line_height_;
    Length word_spacing_;
    StyleColor internal_visited_color_;
    StyleColor color_;
    short horizontal_border_spacing_;
    short vertical_border_spacing_;
    unsigned cursor_ : 6; // ECursor
    unsigned text_transform_ : 6; // ETextTransform
    unsigned color_is_current_color_ : 1; // bool
    unsigned in_forced_colors_mode_ : 1; // bool
    unsigned internal_visited_color_is_current_color_ : 1; // bool
  };

  class StyleVisualData : public GarbageCollected<StyleVisualData> {
   public:
    explicit StyleVisualData();
    CORE_EXPORT StyleVisualData(const StyleVisualData&);

    static StyleVisualData* Create() {
      return MakeGarbageCollected<StyleVisualData>();
    }
    StyleVisualData* Copy() const {
      return MakeGarbageCollected<StyleVisualData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      visitor->Trace(base_text_decoration_data_);
      TraceIfNeeded<LengthBox>::Trace(visitor, clip_);
      TraceIfNeeded<float>::Trace(visitor, zoom_);
    }

    bool operator==(const StyleVisualData& other) const {
      return (true
        && base::ValuesEquivalent(base_text_decoration_data_, other.base_text_decoration_data_)
        && clip_ == other.clip_
        && zoom_ == other.zoom_
        && text_decoration_line_ == other.text_decoration_line_
        && field_sizing_ == other.field_sizing_
        && has_auto_clip_ == other.has_auto_clip_
        && has_clip_path_ == other.has_clip_path_
        && maybe_has_gap_decorations_ == other.maybe_has_gap_decorations_
      );
    }

    Member<AppliedTextDecorationVector> base_text_decoration_data_;
    LengthBox clip_;
    float zoom_;
    unsigned text_decoration_line_ : 6; // TextDecorationLine
    unsigned field_sizing_ : 1; // EFieldSizing
    unsigned has_auto_clip_ : 1; // bool
    unsigned has_clip_path_ : 1; // bool
    unsigned maybe_has_gap_decorations_ : 1; // bool
  };

  class StyleFillData : public GarbageCollected<StyleFillData> {
   public:
    explicit StyleFillData();
    CORE_EXPORT StyleFillData(const StyleFillData&);

    static StyleFillData* Create() {
      return MakeGarbageCollected<StyleFillData>();
    }
    StyleFillData* Copy() const {
      return MakeGarbageCollected<StyleFillData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<SVGPaint>::Trace(visitor, internal_visited_fill_paint_);
      TraceIfNeeded<SVGPaint>::Trace(visitor, fill_paint_);
      TraceIfNeeded<float>::Trace(visitor, fill_opacity_);
    }

    bool operator==(const StyleFillData& other) const {
      return (true
        && internal_visited_fill_paint_ == other.internal_visited_fill_paint_
        && fill_paint_ == other.fill_paint_
        && fill_opacity_ == other.fill_opacity_
      );
    }

    SVGPaint internal_visited_fill_paint_;
    SVGPaint fill_paint_;
    float fill_opacity_;
  };

  class StyleStrokeData : public GarbageCollected<StyleStrokeData> {
   public:
    explicit StyleStrokeData();
    CORE_EXPORT StyleStrokeData(const StyleStrokeData&);

    static StyleStrokeData* Create() {
      return MakeGarbageCollected<StyleStrokeData>();
    }
    StyleStrokeData* Copy() const {
      return MakeGarbageCollected<StyleStrokeData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      visitor->Trace(stroke_dash_array_);
      TraceIfNeeded<SVGPaint>::Trace(visitor, internal_visited_stroke_paint_);
      TraceIfNeeded<SVGPaint>::Trace(visitor, stroke_paint_);
      TraceIfNeeded<Length>::Trace(visitor, stroke_dash_offset_);
      TraceIfNeeded<UnzoomedLength>::Trace(visitor, stroke_width_);
      TraceIfNeeded<float>::Trace(visitor, stroke_miter_limit_);
      TraceIfNeeded<float>::Trace(visitor, stroke_opacity_);
    }

    bool operator==(const StyleStrokeData& other) const {
      return (true
        && base::ValuesEquivalent(stroke_dash_array_, other.stroke_dash_array_)
        && internal_visited_stroke_paint_ == other.internal_visited_stroke_paint_
        && stroke_paint_ == other.stroke_paint_
        && stroke_dash_offset_ == other.stroke_dash_offset_
        && stroke_width_ == other.stroke_width_
        && stroke_miter_limit_ == other.stroke_miter_limit_
        && stroke_opacity_ == other.stroke_opacity_
        && cap_style_ == other.cap_style_
        && join_style_ == other.join_style_
      );
    }

    Member<SVGDashArray> stroke_dash_array_;
    SVGPaint internal_visited_stroke_paint_;
    SVGPaint stroke_paint_;
    Length stroke_dash_offset_;
    UnzoomedLength stroke_width_;
    float stroke_miter_limit_;
    float stroke_opacity_;
    unsigned cap_style_ : 2; // LineCap
    unsigned join_style_ : 2; // LineJoin
  };

  class StyleResourcesData : public GarbageCollected<StyleResourcesData> {
   public:
    explicit StyleResourcesData();
    CORE_EXPORT StyleResourcesData(const StyleResourcesData&);

    static StyleResourcesData* Create() {
      return MakeGarbageCollected<StyleResourcesData>();
    }
    StyleResourcesData* Copy() const {
      return MakeGarbageCollected<StyleResourcesData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      visitor->Trace(marker_end_resource_);
      visitor->Trace(marker_mid_resource_);
      visitor->Trace(marker_start_resource_);
    }

    bool operator==(const StyleResourcesData& other) const {
      return (true
        && base::ValuesEquivalent(marker_end_resource_, other.marker_end_resource_)
        && base::ValuesEquivalent(marker_mid_resource_, other.marker_mid_resource_)
        && base::ValuesEquivalent(marker_start_resource_, other.marker_start_resource_)
      );
    }

    Member<StyleSVGResource> marker_end_resource_;
    Member<StyleSVGResource> marker_mid_resource_;
    Member<StyleSVGResource> marker_start_resource_;
  };

  class StyleSvginheritedData : public GarbageCollected<StyleSvginheritedData> {
   public:
    explicit StyleSvginheritedData();
    CORE_EXPORT StyleSvginheritedData(const StyleSvginheritedData&);

    static StyleSvginheritedData* Create() {
      return MakeGarbageCollected<StyleSvginheritedData>();
    }
    StyleSvginheritedData* Copy() const {
      return MakeGarbageCollected<StyleSvginheritedData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      visitor->Trace(fill_data_);
      visitor->Trace(stroke_data_);
      visitor->Trace(resources_data_);
    }

    bool operator==(const StyleSvginheritedData& other) const {
      return (true
        && base::ValuesEquivalent(fill_data_, other.fill_data_)
        && base::ValuesEquivalent(stroke_data_, other.stroke_data_)
        && base::ValuesEquivalent(resources_data_, other.resources_data_)
        && css_dominant_baseline_ == other.css_dominant_baseline_
        && dominant_baseline_ == other.dominant_baseline_
        && paint_order_ == other.paint_order_
        && color_interpolation_ == other.color_interpolation_
        && color_interpolation_filters_ == other.color_interpolation_filters_
        && color_rendering_ == other.color_rendering_
        && shape_rendering_ == other.shape_rendering_
        && text_anchor_ == other.text_anchor_
        && clip_rule_ == other.clip_rule_
        && fill_rule_ == other.fill_rule_
      );
    }

    Member<StyleFillData> fill_data_;
    Member<StyleStrokeData> stroke_data_;
    Member<StyleResourcesData> resources_data_;
    unsigned css_dominant_baseline_ : 4; // EDominantBaseline
    unsigned dominant_baseline_ : 4; // EDominantBaseline
    unsigned paint_order_ : 3; // EPaintOrder
    unsigned color_interpolation_ : 2; // EColorInterpolation
    unsigned color_interpolation_filters_ : 2; // EColorInterpolation
    unsigned color_rendering_ : 2; // EColorRendering
    unsigned shape_rendering_ : 2; // EShapeRendering
    unsigned text_anchor_ : 2; // ETextAnchor
    unsigned clip_rule_ : 1; // WindRule
    unsigned fill_rule_ : 1; // WindRule
  };

  class StyleBoxData : public GarbageCollected<StyleBoxData> {
   public:
    explicit StyleBoxData();
    CORE_EXPORT StyleBoxData(const StyleBoxData&);

    static StyleBoxData* Create() {
      return MakeGarbageCollected<StyleBoxData>();
    }
    StyleBoxData* Copy() const {
      return MakeGarbageCollected<StyleBoxData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<Length>::Trace(visitor, height_);
      TraceIfNeeded<Length>::Trace(visitor, margin_bottom_);
      TraceIfNeeded<Length>::Trace(visitor, margin_left_);
      TraceIfNeeded<Length>::Trace(visitor, margin_right_);
      TraceIfNeeded<Length>::Trace(visitor, margin_top_);
      TraceIfNeeded<Length>::Trace(visitor, max_height_);
      TraceIfNeeded<Length>::Trace(visitor, max_width_);
      TraceIfNeeded<Length>::Trace(visitor, min_height_);
      TraceIfNeeded<Length>::Trace(visitor, min_width_);
      TraceIfNeeded<Length>::Trace(visitor, padding_bottom_);
      TraceIfNeeded<Length>::Trace(visitor, padding_left_);
      TraceIfNeeded<Length>::Trace(visitor, padding_right_);
      TraceIfNeeded<Length>::Trace(visitor, padding_top_);
      TraceIfNeeded<Length>::Trace(visitor, width_);
      TraceIfNeeded<Length>::Trace(visitor, vertical_align_length_);
      TraceIfNeeded<StyleContentAlignmentData>::Trace(visitor, justify_content_);
      TraceIfNeeded<StyleSelfAlignmentData>::Trace(visitor, align_items_);
      TraceIfNeeded<int>::Trace(visitor, border_bottom_width_);
      TraceIfNeeded<int>::Trace(visitor, border_left_width_);
      TraceIfNeeded<int>::Trace(visitor, border_right_width_);
      TraceIfNeeded<int>::Trace(visitor, border_top_width_);
      TraceIfNeeded<int>::Trace(visitor, z_index_);
      TraceIfNeeded<std::optional<StyleOverflowClipMargin>>::Trace(visitor, overflow_clip_margin_);
    }

    bool operator==(const StyleBoxData& other) const {
      return (true
        && height_ == other.height_
        && margin_bottom_ == other.margin_bottom_
        && margin_left_ == other.margin_left_
        && margin_right_ == other.margin_right_
        && margin_top_ == other.margin_top_
        && max_height_ == other.max_height_
        && max_width_ == other.max_width_
        && min_height_ == other.min_height_
        && min_width_ == other.min_width_
        && padding_bottom_ == other.padding_bottom_
        && padding_left_ == other.padding_left_
        && padding_right_ == other.padding_right_
        && padding_top_ == other.padding_top_
        && width_ == other.width_
        && vertical_align_length_ == other.vertical_align_length_
        && justify_content_ == other.justify_content_
        && align_items_ == other.align_items_
        && border_bottom_width_ == other.border_bottom_width_
        && border_left_width_ == other.border_left_width_
        && border_right_width_ == other.border_right_width_
        && border_top_width_ == other.border_top_width_
        && z_index_ == other.z_index_
        && overflow_clip_margin_ == other.overflow_clip_margin_
        && border_bottom_style_ == other.border_bottom_style_
        && border_left_style_ == other.border_left_style_
        && border_right_style_ == other.border_right_style_
        && border_top_style_ == other.border_top_style_
        && baseline_source_ == other.baseline_source_
        && text_box_trim_ == other.text_box_trim_
        && box_decoration_break_ == other.box_decoration_break_
        && has_auto_z_index_ == other.has_auto_z_index_
      );
    }

    Length height_;
    Length margin_bottom_;
    Length margin_left_;
    Length margin_right_;
    Length margin_top_;
    Length max_height_;
    Length max_width_;
    Length min_height_;
    Length min_width_;
    Length padding_bottom_;
    Length padding_left_;
    Length padding_right_;
    Length padding_top_;
    Length width_;
    Length vertical_align_length_;
    StyleContentAlignmentData justify_content_;
    StyleSelfAlignmentData align_items_;
    int border_bottom_width_;
    int border_left_width_;
    int border_right_width_;
    int border_top_width_;
    int z_index_;
    std::optional<StyleOverflowClipMargin> overflow_clip_margin_;
    unsigned border_bottom_style_ : 4; // EBorderStyle
    unsigned border_left_style_ : 4; // EBorderStyle
    unsigned border_right_style_ : 4; // EBorderStyle
    unsigned border_top_style_ : 4; // EBorderStyle
    unsigned baseline_source_ : 2; // EBaselineSource
    unsigned text_box_trim_ : 2; // ETextBoxTrim
    unsigned box_decoration_break_ : 1; // EBoxDecorationBreak
    unsigned has_auto_z_index_ : 1; // bool
  };

  class StyleSvgmiscData : public GarbageCollected<StyleSvgmiscData> {
   public:
    explicit StyleSvgmiscData();
    CORE_EXPORT StyleSvgmiscData(const StyleSvgmiscData&);

    static StyleSvgmiscData* Create() {
      return MakeGarbageCollected<StyleSvgmiscData>();
    }
    StyleSvgmiscData* Copy() const {
      return MakeGarbageCollected<StyleSvgmiscData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<Length>::Trace(visitor, baseline_shift_);
      TraceIfNeeded<float>::Trace(visitor, flood_opacity_);
      TraceIfNeeded<StyleColor>::Trace(visitor, flood_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, lighting_color_);
    }

    bool operator==(const StyleSvgmiscData& other) const {
      return (true
        && baseline_shift_ == other.baseline_shift_
        && flood_opacity_ == other.flood_opacity_
        && flood_color_ == other.flood_color_
        && lighting_color_ == other.lighting_color_
        && baseline_shift_type_ == other.baseline_shift_type_
      );
    }

    Length baseline_shift_;
    float flood_opacity_;
    StyleColor flood_color_;
    StyleColor lighting_color_;
    unsigned baseline_shift_type_ : 2; // EBaselineShiftType
  };

  class StyleGeometryData : public GarbageCollected<StyleGeometryData> {
   public:
    explicit StyleGeometryData();
    CORE_EXPORT StyleGeometryData(const StyleGeometryData&);

    static StyleGeometryData* Create() {
      return MakeGarbageCollected<StyleGeometryData>();
    }
    StyleGeometryData* Copy() const {
      return MakeGarbageCollected<StyleGeometryData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      visitor->Trace(d_);
      TraceIfNeeded<Length>::Trace(visitor, cx_);
      TraceIfNeeded<Length>::Trace(visitor, cy_);
      TraceIfNeeded<Length>::Trace(visitor, path_length_);
      TraceIfNeeded<Length>::Trace(visitor, r_);
      TraceIfNeeded<Length>::Trace(visitor, rx_);
      TraceIfNeeded<Length>::Trace(visitor, ry_);
      TraceIfNeeded<Length>::Trace(visitor, x_);
      TraceIfNeeded<Length>::Trace(visitor, y_);
    }

    bool operator==(const StyleGeometryData& other) const {
      return (true
        && base::ValuesEquivalent(d_, other.d_)
        && cx_ == other.cx_
        && cy_ == other.cy_
        && path_length_ == other.path_length_
        && r_ == other.r_
        && rx_ == other.rx_
        && ry_ == other.ry_
        && x_ == other.x_
        && y_ == other.y_
      );
    }

    Member<StylePath> d_;
    Length cx_;
    Length cy_;
    Length path_length_;
    Length r_;
    Length rx_;
    Length ry_;
    Length x_;
    Length y_;
  };

  class StyleStopData : public GarbageCollected<StyleStopData> {
   public:
    explicit StyleStopData();
    CORE_EXPORT StyleStopData(const StyleStopData&);

    static StyleStopData* Create() {
      return MakeGarbageCollected<StyleStopData>();
    }
    StyleStopData* Copy() const {
      return MakeGarbageCollected<StyleStopData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<float>::Trace(visitor, stop_opacity_);
      TraceIfNeeded<StyleColor>::Trace(visitor, stop_color_);
    }

    bool operator==(const StyleStopData& other) const {
      return (true
        && stop_opacity_ == other.stop_opacity_
        && stop_color_ == other.stop_color_
      );
    }

    float stop_opacity_;
    StyleColor stop_color_;
  };

  class StyleSVGData : public GarbageCollected<StyleSVGData> {
   public:
    explicit StyleSVGData();
    CORE_EXPORT StyleSVGData(const StyleSVGData&);

    static StyleSVGData* Create() {
      return MakeGarbageCollected<StyleSVGData>();
    }
    StyleSVGData* Copy() const {
      return MakeGarbageCollected<StyleSVGData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      visitor->Trace(svgmisc_data_);
      visitor->Trace(geometry_data_);
      visitor->Trace(stop_data_);
      TraceIfNeeded<TransformOperations>::Trace(visitor, transform_);
      TraceIfNeeded<TransformOrigin>::Trace(visitor, transform_origin_);
      TraceIfNeeded<float>::Trace(visitor, opacity_);
    }

    bool operator==(const StyleSVGData& other) const {
      return (true
        && base::ValuesEquivalent(svgmisc_data_, other.svgmisc_data_)
        && base::ValuesEquivalent(geometry_data_, other.geometry_data_)
        && base::ValuesEquivalent(stop_data_, other.stop_data_)
        && transform_ == other.transform_
        && transform_origin_ == other.transform_origin_
        && opacity_ == other.opacity_
        && alignment_baseline_ == other.alignment_baseline_
        && buffered_rendering_ == other.buffered_rendering_
        && mask_type_ == other.mask_type_
        && vector_effect_ == other.vector_effect_
      );
    }

    Member<StyleSvgmiscData> svgmisc_data_;
    Member<StyleGeometryData> geometry_data_;
    Member<StyleStopData> stop_data_;
    TransformOperations transform_;
    TransformOrigin transform_origin_;
    float opacity_;
    unsigned alignment_baseline_ : 4; // EAlignmentBaseline
    unsigned buffered_rendering_ : 2; // EBufferedRendering
    unsigned mask_type_ : 1; // EMaskType
    unsigned vector_effect_ : 1; // EVectorEffect
  };

  class StyleSurroundData : public GarbageCollected<StyleSurroundData> {
   public:
    explicit StyleSurroundData();
    CORE_EXPORT StyleSurroundData(const StyleSurroundData&);

    static StyleSurroundData* Create() {
      return MakeGarbageCollected<StyleSurroundData>();
    }
    StyleSurroundData* Copy() const {
      return MakeGarbageCollected<StyleSurroundData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<Superellipse>::Trace(visitor, corner_bottom_left_shape_);
      TraceIfNeeded<Superellipse>::Trace(visitor, corner_bottom_right_shape_);
      TraceIfNeeded<Superellipse>::Trace(visitor, corner_top_left_shape_);
      TraceIfNeeded<Superellipse>::Trace(visitor, corner_top_right_shape_);
      TraceIfNeeded<NinePieceImage>::Trace(visitor, border_image_);
      TraceIfNeeded<Length>::Trace(visitor, bottom_);
      TraceIfNeeded<Length>::Trace(visitor, left_);
      TraceIfNeeded<Length>::Trace(visitor, right_);
      TraceIfNeeded<Length>::Trace(visitor, top_);
      TraceIfNeeded<LengthSize>::Trace(visitor, border_bottom_left_radius_);
      TraceIfNeeded<LengthSize>::Trace(visitor, border_bottom_right_radius_);
      TraceIfNeeded<LengthSize>::Trace(visitor, border_top_left_radius_);
      TraceIfNeeded<LengthSize>::Trace(visitor, border_top_right_radius_);
      TraceIfNeeded<StyleAspectRatio>::Trace(visitor, aspect_ratio_);
      TraceIfNeeded<StyleIntrinsicLength>::Trace(visitor, contain_intrinsic_height_);
      TraceIfNeeded<StyleIntrinsicLength>::Trace(visitor, contain_intrinsic_width_);
      TraceIfNeeded<StyleColor>::Trace(visitor, border_bottom_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, border_left_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, border_right_color_);
      TraceIfNeeded<StyleColor>::Trace(visitor, border_top_color_);
    }

    bool operator==(const StyleSurroundData& other) const {
      return (true
        && corner_bottom_left_shape_ == other.corner_bottom_left_shape_
        && corner_bottom_right_shape_ == other.corner_bottom_right_shape_
        && corner_top_left_shape_ == other.corner_top_left_shape_
        && corner_top_right_shape_ == other.corner_top_right_shape_
        && border_image_ == other.border_image_
        && bottom_ == other.bottom_
        && left_ == other.left_
        && right_ == other.right_
        && top_ == other.top_
        && border_bottom_left_radius_ == other.border_bottom_left_radius_
        && border_bottom_right_radius_ == other.border_bottom_right_radius_
        && border_top_left_radius_ == other.border_top_left_radius_
        && border_top_right_radius_ == other.border_top_right_radius_
        && aspect_ratio_ == other.aspect_ratio_
        && contain_intrinsic_height_ == other.contain_intrinsic_height_
        && contain_intrinsic_width_ == other.contain_intrinsic_width_
        && border_bottom_color_ == other.border_bottom_color_
        && border_left_color_ == other.border_left_color_
        && border_right_color_ == other.border_right_color_
        && border_top_color_ == other.border_top_color_
        && frame_sizing_ == other.frame_sizing_
      );
    }

    Superellipse corner_bottom_left_shape_;
    Superellipse corner_bottom_right_shape_;
    Superellipse corner_top_left_shape_;
    Superellipse corner_top_right_shape_;
    NinePieceImage border_image_;
    Length bottom_;
    Length left_;
    Length right_;
    Length top_;
    LengthSize border_bottom_left_radius_;
    LengthSize border_bottom_right_radius_;
    LengthSize border_top_left_radius_;
    LengthSize border_top_right_radius_;
    StyleAspectRatio aspect_ratio_;
    StyleIntrinsicLength contain_intrinsic_height_;
    StyleIntrinsicLength contain_intrinsic_width_;
    StyleColor border_bottom_color_;
    StyleColor border_left_color_;
    StyleColor border_right_color_;
    StyleColor border_top_color_;
    unsigned frame_sizing_ : 3; // EFrameSizing
    unsigned has_anchor_evaluator_ : 1; // bool
    unsigned has_anchor_functions_ : 1; // bool
    unsigned may_have_margin_ : 1; // bool
    unsigned may_have_padding_ : 1; // bool
  };

  class StyleBackgroundData : public GarbageCollected<StyleBackgroundData> {
   public:
    explicit StyleBackgroundData();
    CORE_EXPORT StyleBackgroundData(const StyleBackgroundData&);

    static StyleBackgroundData* Create() {
      return MakeGarbageCollected<StyleBackgroundData>();
    }
    StyleBackgroundData* Copy() const {
      return MakeGarbageCollected<StyleBackgroundData>(*this);
    }


    CORE_EXPORT void Trace(Visitor* visitor) const {
      TraceIfNeeded<FillLayer>::Trace(visitor, background_);
      TraceIfNeeded<StyleColor>::Trace(visitor, background_color_);
    }

    bool operator==(const StyleBackgroundData& other) const {
      return (true
        && background_ == other.background_
        && background_color_ == other.background_color_
      );
    }

    FillLayer background_;
    StyleColor background_color_;
  };


 public:
  inline unsigned HashInheritedBitFields() const {
    // TODO(sesse): It is possible that rapidhash is overkill for hashing
    // what amounts to ~40 bits of data.
    Data inherited_data;
    memset(&inherited_data, 0, sizeof(inherited_data));
      inherited_data.pointer_events_ = data_.pointer_events_;
      inherited_data.text_align_ = data_.text_align_;
      inherited_data.writing_mode_ = data_.writing_mode_;
      inherited_data.caret_shape_ = data_.caret_shape_;
      inherited_data.inside_link_ = data_.inside_link_;
      inherited_data.text_wrap_style_ = data_.text_wrap_style_;
      inherited_data.visibility_ = data_.visibility_;
      inherited_data.white_space_collapse_ = data_.white_space_collapse_;
      inherited_data.border_collapse_ = data_.border_collapse_;
      inherited_data.caption_side_ = data_.caption_side_;
      inherited_data.caret_animation_ = data_.caret_animation_;
      inherited_data.color_scheme_flags_is_normal_ = data_.color_scheme_flags_is_normal_;
      inherited_data.color_scheme_forced_ = data_.color_scheme_forced_;
      inherited_data.dark_color_scheme_ = data_.dark_color_scheme_;
      inherited_data.direction_ = data_.direction_;
      inherited_data.is_css_inert_ = data_.is_css_inert_;
      inherited_data.is_html_inert_ = data_.is_html_inert_;
      inherited_data.list_style_position_ = data_.list_style_position_;
      inherited_data.prefers_default_scrollbar_styles_ = data_.prefers_default_scrollbar_styles_;
      inherited_data.print_color_adjust_ = data_.print_color_adjust_;
      inherited_data.rtl_ordering_ = data_.rtl_ordering_;
      inherited_data.text_wrap_mode_ = data_.text_wrap_mode_;
    return static_cast<unsigned>(rapidhash(
        reinterpret_cast<uint8_t*>(&inherited_data), sizeof(inherited_data)));
  }

 protected:
  // Constructor and destructor are protected so that only the parent class ComputedStyle
  // can instantiate this class.
  ComputedStyleBase();
  ComputedStyleBase(const ComputedStyleBase &initial_style) = default;
  explicit ComputedStyleBase(const ComputedStyleBuilderBase&);

  // accent-color
  const StyleAutoColor& AccentColor() const {
    return misc_inherited_data_->misc_inherited_1_data_->accent_color_;
  }






  // AffectedByActive
  

  // AffectedByCSSFunction
  

  // AffectedByDrag
  

  // AffectedByFocusWithin
  

  // AffectedByFunctionalMedia
  

  // AffectedByFunctionalNavigation
  

  // AffectedByHover
  

  // align-content
  





  // -internal-align-content-block
  




  // align-items
  





  // align-self
  





  // alignment-baseline
  




  // AllowsZIndex
  




  // AnchorCenterOffset
  





  // anchor-name
  




  // anchor-scope
  





  // Animations
  




  // appearance
  AppearanceValue Appearance() const {
    return static_cast<AppearanceValue>(misc_data_->appearance_);
  }





  // aspect-ratio
  





  // backdrop-filter
  





  // backface-visibility
  




  // Background
  const FillLayer& BackgroundInternal() const {
    return background_data_->background_;
  }






  // background-color
  const StyleColor& BackgroundColor() const {
    return background_data_->background_color_;
  }






  // baseline-shift
  





  // BaselineShiftType
  




  // baseline-source
  




  // mix-blend-mode
  




  // block-ellipsis
  




  // border-bottom-color
  const StyleColor& BorderBottomColor() const {
    return surround_data_->border_bottom_color_;
  }






  // border-bottom-left-radius
  





  // border-bottom-right-radius
  





  // border-bottom-style
  




  // border-bottom-width
  





  // border-collapse
  




  // border-collapse
  




  // border-image
  





  // border-left-color
  const StyleColor& BorderLeftColor() const {
    return surround_data_->border_left_color_;
  }






  // border-left-style
  




  // border-left-width
  





  // border-right-color
  const StyleColor& BorderRightColor() const {
    return surround_data_->border_right_color_;
  }






  // border-right-style
  




  // border-right-width
  





  // border-shape
  




  // border-top-color
  const StyleColor& BorderTopColor() const {
    return surround_data_->border_top_color_;
  }






  // border-top-left-radius
  





  // border-top-right-radius
  





  // border-top-style
  




  // border-top-width
  





  // bottom
  





  // -webkit-box-align
  




  // box-decoration-break
  




  // -webkit-box-direction
  EBoxDirection BoxDirection() const {
    return static_cast<EBoxDirection>(data_.box_direction_);
  }





  // -webkit-box-flex
  




  // -webkit-box-ordinal-group
  




  // -webkit-box-orient
  




  // -webkit-box-pack
  




  // box-sizing
  




  // break-after
  




  // break-before
  




  // break-inside
  




  // buffered-rendering
  




  // CallbackSelectors
  





  // CanAffectAnimations
  

  // stroke-linecap
  




  // caption-side
  




  // caption-side
  




  // caret-animation
  




  // caret-color
  const StyleCaretColor& CaretColor() const {
    return misc_inherited_data_->misc_inherited_1_data_->caret_color_;
  }






  // caret-shape
  




  // ChildHasExplicitInheritance
  

  // clear
  EClear Clear() const {
    return static_cast<EClear>(data_.clear_);
  }





  // clip
  





  // clip-path
  const Member<ClipPathOperation>& ClipPathInternal() const {
    return misc_data_->misc_1_data_->clip_path_;
  }





  // clip-rule
  




  // color
  const StyleColor& Color() const {
    return inherited_data_->color_;
  }






  // color-interpolation
  




  // color-interpolation-filters
  




  // ColorIsCurrentColor
  bool ColorIsCurrentColor() const {
    return static_cast<bool>(inherited_data_->color_is_current_color_);
  }





  // color
  bool ColorIsInherited() const {
    return static_cast<bool>(data_.color_is_inherited_);
  }





  // color-rendering
  




  // color-scheme
  





  // ColorSchemeFlagsIsNormal
  




  // ColorSchemeForced
  




  // column-count
  




  // column-fill
  




  // column-gap
  





  // column-height
  




  // column-rule-break
  




  // column-rule-color
  





  // column-rule-inset-cap-end
  





  // column-rule-inset-cap-start
  





  // column-rule-inset-junction-end
  





  // column-rule-inset-junction-start
  





  // column-rule-style
  





  // column-rule-visibility-items
  




  // column-rule-width
  





  // column-span
  




  // column-width
  




  // column-wrap
  




  // contain
  




  // contain-intrinsic-height
  





  // contain-intrinsic-width
  





  // container-name
  





  // container-type
  




  // content
  const Member<ContentData>& ContentInternal() const {
    return misc_data_->misc_2_data_->content_;
  }





  // content-visibility
  




  // Continue
  




  // corner-bottom-left-shape
  





  // corner-bottom-right-shape
  





  // corner-top-left-shape
  





  // corner-top-right-shape
  





  // CounterDirectives
  const std::unique_ptr<CounterDirectiveMap>& CounterDirectivesInternal() const {
    return misc_data_->misc_7_data_->counter_directives_;
  }





  // CssDominantBaseline
  




  // cursor
  




  // CursorData
  const Member<CursorList>& CursorDataInternal() const {
    return misc_inherited_data_->misc_inherited_2_data_->cursor_data_;
  }





  // cursor
  




  // CustomHighlightNames
  const std::unique_ptr<HashSet<AtomicString>>& CustomHighlightNamesInternal() const {
    return misc_data_->misc_7_data_->custom_highlight_names_;
  }





  // CustomStyleCallbackDependsOnFont
  

  // cx
  





  // cy
  





  // DarkColorScheme
  




  // DependsOnAnchoredContainerQueries
  




  // DependsOnScrollStateContainerQueries
  




  // DependsOnSizeContainerQueries
  




  // DependsOnStyleContainerQueries
  




  // direction
  




  // Display
  




  // DisplayLayoutCustomName
  





  // DisplayLayoutCustomParentName
  





  // DocumentRulesSelectors
  




  // dominant-baseline
  




  // window-drag
  




  // dynamic-range-limit
  





  // EffectiveAppearance
  




  // EffectiveTouchAction
  




  // EffectiveZoom
  




  // ElementIsViewTransitionParticipant
  

  // empty-cells
  




  // empty-cells
  




  // field-sizing
  




  // fill-opacity
  




  // fill
  





  // fill-rule
  




  // filter
  





  // FirstLineDependsOnSizeContainerQueries
  




  // flex-basis
  





  // flex-direction
  




  // flex-grow
  




  // flex-line-count
  




  // flex-shrink
  




  // flex-wrap
  





  // float
  EFloat Floating() const {
    return static_cast<EFloat>(data_.floating_);
  }





  // flood-color
  





  // flood-opacity
  




  // flow-tolerance
  





  // forced-color-adjust
  




  // ForcesBlockifiesChildren
  

  // ForcesStackingContext
  




  // frame-sizing
  




  // grid-auto-columns
  





  // grid-auto-flow
  GridAutoFlow GridAutoFlowInternal() const {
    return static_cast<GridAutoFlow>(misc_data_->grid_auto_flow_);
  }





  // grid-auto-rows
  





  // grid-column-end
  





  // grid-column-start
  





  // grid-lanes-direction
  





  // grid-lanes-pack
  




  // grid-row-end
  





  // grid-row-start
  





  // grid-template-areas
  




  // grid-template-columns
  




  // grid-template-rows
  




  // hanging-punctuation
  

  // HasAnchorEvaluator
  

  // HasAnchorFunctions
  

  // HasAttrFunction
  

  // HasAuthorBackground
  

  // HasAuthorBorder
  

  // HasAuthorBorderRadius
  

  // HasAuthorHighlightColors
  

  // HasAutoClip
  




  // HasAutoColumnCount
  




  // HasAutoColumnHeight
  




  // HasAutoColumnWidth
  




  // HasAutoZIndex
  




  // HasClipPath
  




  // HasContainerRelativeValue
  

  // HasCurrentBackdropFilterAnimation
  




  // HasCurrentBackgroundColorAnimation
  




  // HasCurrentClipPathAnimation
  




  // HasCurrentFilterAnimation
  




  // HasCurrentOpacityAnimation
  




  // HasCurrentRotateAnimation
  




  // HasCurrentScaleAnimation
  




  // HasCurrentTransformAnimation
  




  // HasCurrentTranslateAnimation
  




  // HasCustomHighlightUniversalSelector
  




  // HasElementDependentRandomFunctions
  

  // HasEmUnits
  

  // HasEnv
  

  // HasEnvSafeAreaInsetBottom
  

  // HasExplicitInheritance
  

  // HasExplicitOverflowXVisible
  

  // HasExplicitOverflowYVisible
  

  // HasGlyphRelativeUnits
  

  // HasLayoutContainmentForViewTransitionScope
  




  // HasLineHeightRelativeUnits
  

  // -internal-empty-line-height
  




  // HasLogicalDirectionRelativeUnits
  

  // HasNonUaHighlightPseudoStyles
  




  // HasNonUniversalHighlightPseudoStyles
  




  // HasRootRelativeUnits
  

  // HasSiblingFunctions
  

  // HasSizeContainmentForViewTransitionScope
  




  // HasVariableDeclaration
  

  // HasVariableReference
  

  // height
  





  // HighlightData
  





  // HighlightsDependOnSizeContainerQueries
  




  // -webkit-border-horizontal-spacing
  




  // hyphenate-limit-chars
  





  // hyphenate-character
  





  // hyphens
  




  // image-animation
  




  // image-orientation
  




  // image-rendering
  




  // InBaseAppearance
  




  // InForcedColorsMode
  




  // InheritedVariables
  const StyleInheritedVariables& InheritedVariablesInternal() const {
    return inherited_data_->inherited_variables_;
  }






  // initial-letter
  





  // InlineBlockBaselineEdge
  




  // InlineStyleLostCascade
  




  // InsideLink
  




  // interactivity
  




  // interactivity
  




  // interest-delay-end
  





  // interest-delay-start
  





  // -internal-forced-background-color
  const StyleColor& InternalForcedBackgroundColor() const {
    return misc_data_->forced_colors_data_->internal_forced_background_color_;
  }






  // -internal-forced-border-color
  const StyleColor& InternalForcedBorderColor() const {
    return misc_data_->forced_colors_data_->internal_forced_border_color_;
  }






  // -internal-forced-color
  const StyleColor& InternalForcedColor() const {
    return inherited_data_->inherited_forced_colors_data_->internal_forced_color_;
  }






  // -internal-forced-outline-color
  const StyleColor& InternalForcedOutlineColor() const {
    return misc_data_->forced_colors_data_->internal_forced_outline_color_;
  }






  // -internal-forced-visited-color
  const StyleColor& InternalForcedVisitedColor() const {
    return inherited_data_->inherited_forced_colors_data_->internal_forced_visited_color_;
  }






  // -internal-overscroll-container
  




  // -internal-overscroll-position
  




  // -internal-unbounded
  




  // -internal-visited-background-color
  const StyleColor& InternalVisitedBackgroundColor() const {
    return misc_data_->visited_data_->internal_visited_background_color_;
  }






  // -internal-visited-border-bottom-color
  const StyleColor& InternalVisitedBorderBottomColor() const {
    return misc_data_->visited_data_->internal_visited_border_bottom_color_;
  }






  // -internal-visited-border-left-color
  const StyleColor& InternalVisitedBorderLeftColor() const {
    return misc_data_->visited_data_->internal_visited_border_left_color_;
  }






  // -internal-visited-border-right-color
  const StyleColor& InternalVisitedBorderRightColor() const {
    return misc_data_->visited_data_->internal_visited_border_right_color_;
  }






  // -internal-visited-border-top-color
  const StyleColor& InternalVisitedBorderTopColor() const {
    return misc_data_->visited_data_->internal_visited_border_top_color_;
  }






  // -internal-visited-caret-color
  const StyleCaretColor& InternalVisitedCaretColor() const {
    return inherited_data_->inherited_visited_data_->internal_visited_caret_color_;
  }






  // -internal-visited-color
  const StyleColor& InternalVisitedColor() const {
    return inherited_data_->internal_visited_color_;
  }






  // InternalVisitedColorIsCurrentColor
  bool InternalVisitedColorIsCurrentColor() const {
    return static_cast<bool>(inherited_data_->internal_visited_color_is_current_color_);
  }





  // -internal-visited-column-rule-color
  





  // -internal-visited-fill
  





  // -internal-visited-outline-color
  const StyleColor& InternalVisitedOutlineColor() const {
    return misc_data_->visited_data_->internal_visited_outline_color_;
  }






  // -internal-visited-stroke
  





  // -internal-visited-text-decoration-color
  const StyleColor& InternalVisitedTextDecorationColor() const {
    return misc_data_->visited_data_->internal_visited_text_decoration_color_;
  }






  // -internal-visited-text-emphasis-color
  const StyleColor& InternalVisitedTextEmphasisColor() const {
    return inherited_data_->inherited_visited_data_->internal_visited_text_emphasis_color_;
  }






  // -internal-visited-text-fill-color
  const StyleColor& InternalVisitedTextFillColor() const {
    return inherited_data_->inherited_visited_data_->internal_visited_text_fill_color_;
  }






  // -internal-visited-text-stroke-color
  const StyleColor& InternalVisitedTextStrokeColor() const {
    return inherited_data_->inherited_visited_data_->internal_visited_text_stroke_color_;
  }






  // interpolate-size
  




  // IsBottomRelativeToSafeAreaInset
  




  // IsCSSInert
  




  // IsCSSInert
  




  // IsEnsuredInDisplayNone
  

  // IsFlexOrGridOrCustomItem
  

  // IsHTMLInert
  




  // IsHTMLInert
  




  // IsInBlockifyingDisplay
  

  // IsInInlinifyingDisplay
  

  // IsInShrinkToFitSubtree
  




  // IsInsideDisplayIgnoringFloatingChildren
  

  // IsLink
  

  // IsOriginalDisplayInlineType
  




  // IsPageMarginBox
  




  // IsRunningBackdropFilterAnimationOnCompositor
  




  // IsRunningFilterAnimationOnCompositor
  




  // IsRunningOpacityAnimationOnCompositor
  




  // IsRunningRotateAnimationOnCompositor
  




  // IsRunningScaleAnimationOnCompositor
  




  // IsRunningTransformAnimationOnCompositor
  




  // IsRunningTranslateAnimationOnCompositor
  




  // IsSecondaryBodyElement
  

  // IsSpecifiedDisplayWebkitBox
  

  // IsStackingContextWithoutContainment
  

  // IsStartingStyle
  

  // isolation
  




  // stroke-linejoin
  




  // justify-content
  





  // justify-items
  





  // justify-self
  





  // left
  





  // letter-spacing
  const Length& LetterSpacingInternal() const {
    return inherited_data_->letter_spacing_;
  }






  // lighting-color
  





  // line-break
  




  // LineClampInternalBlockEllipsis
  




  // line-height
  





  // list-style-image
  




  // list-style-position
  




  // list-style-position
  




  // list-style-type
  




  // margin-bottom
  





  // margin-left
  





  // margin-right
  





  // margin-top
  





  // margin-trim
  




  // Mask
  const FillLayer& MaskInternal() const {
    return misc_data_->misc_7_data_->mask_;
  }






  // MaskBoxImage
  const NinePieceImage& MaskBoxImageInternal() const {
    return misc_data_->misc_7_data_->mask_box_image_;
  }






  // mask-type
  




  // MathBaseline
  





  // math-depth
  




  // MathFractionBarThickness
  





  // MathLSpace
  





  // MathMaxSize
  





  // MathMinSize
  





  // MathPaddedDepth
  





  // MathPaddedVOffset
  





  // MathRSpace
  





  // math-shift
  




  // math-style
  




  // max-content-sizing
  




  // max-height
  





  // MaxLines
  





  // max-width
  





  // MayHaveMargin
  

  // MayHavePadding
  

  // MaybeHasGapDecorations
  

  // min-height
  





  // min-width
  





  // NonInheritedVariables
  const StyleNonInheritedVariables& NonInheritedVariablesInternal() const {
    return misc_data_->misc_8_data_->non_inherited_variables_;
  }






  // object-fit
  




  // object-position
  





  // offset-anchor
  





  // offset-distance
  





  // offset-position
  





  // offset-rotate
  





  // opacity
  




  // order
  




  // origin-trial-test-property
  




  // orphans
  




  // outline-color
  const StyleColor& OutlineColor() const {
    return misc_data_->misc_4_data_->outline_color_;
  }






  // outline-offset
  





  // outline-style
  




  // OutlineStyleIsAuto
  




  // outline-width
  





  // overflow-anchor
  




  // overflow-clip-margin
  





  // overflow-wrap
  




  // overflow-x
  




  // overflow-y
  




  // overlay
  




  // overscroll-behavior-x
  




  // overscroll-behavior-y
  




  // overscroll-container-type
  




  // padding-bottom
  





  // padding-left
  





  // padding-right
  





  // padding-top
  





  // page
  





  // page-margin-safety
  




  // page-orientation
  




  // PageSize
  





  // PageSizeType
  




  // PaintImages
  const Member<PaintImages>& PaintImagesInternal() const {
    return misc_data_->misc_8_data_->paint_images_;
  }





  // paint-order
  




  // path-length
  





  // perspective
  




  // perspective-origin
  





  // pointer-events
  EPointerEvents PointerEvents() const {
    return static_cast<EPointerEvents>(data_.pointer_events_);
  }





  // pointer-events
  bool PointerEventsIsInherited() const {
    return static_cast<bool>(data_.pointer_events_is_inherited_);
  }





  // position
  EPosition PositionInternal() const {
    return static_cast<EPosition>(data_.position_);
  }





  // position-anchor
  





  // position-area
  





  // PositionAreaOffsets
  





  // position-try-fallbacks
  




  // position-try-order
  




  // position-visibility
  




  // PrefersDefaultScrollbarStyles
  




  // print-color-adjust
  




  // PseudoElementStyles
  unsigned PseudoElementStylesInternal() const {
    return static_cast<unsigned>(data_.pseudo_element_styles_);
  }





  // r
  





  // reading-flow
  




  // reading-order
  




  // RequiresAcceleratedCompositingForExternalReasons
  




  // resize
  EResize Resize() const {
    return static_cast<EResize>(misc_data_->resize_);
  }





  // right
  





  // row-gap
  





  // row-rule-break
  




  // row-rule-color
  





  // row-rule-inset-cap-end
  





  // row-rule-inset-cap-start
  





  // row-rule-inset-junction-end
  





  // row-rule-inset-junction-start
  





  // row-rule-style
  





  // row-rule-visibility-items
  




  // row-rule-width
  





  // -webkit-rtl-ordering
  




  // -webkit-rtl-ordering
  




  // ruby-align
  




  // ruby-overhang
  




  // ruby-position
  




  // rule-overlap
  




  // rx
  





  // ry
  





  // scroll-axis-lock
  




  // scroll-behavior
  




  // scroll-initial-target
  




  // scroll-margin-bottom
  




  // scroll-margin-left
  




  // scroll-margin-right
  




  // scroll-margin-top
  




  // scroll-padding-bottom
  





  // scroll-padding-left
  





  // scroll-padding-right
  





  // scroll-padding-top
  





  // scroll-snap-align
  





  // scroll-snap-stop
  




  // scroll-snap-type
  





  // scroll-target-group
  




  // scroll-timeline-axis
  





  // scroll-timeline-name
  





  // scrollbar-gutter
  




  // scrollbar-width
  




  // shape-image-threshold
  




  // shape-margin
  





  // shape-outside
  const Member<ShapeValue>& ShapeOutsideInternal() const {
    return misc_data_->misc_6_data_->shape_outside_;
  }





  // shape-rendering
  




  // ShouldIgnoreOverflowPropertyForInlineBlockBaseline
  

  // SkipsContents
  




  // speak
  




  // stop-color
  const StyleColor& StopColor() const {
    return svg_data_->stop_data_->stop_color_;
  }






  // stop-opacity
  




  // stroke-dashoffset
  





  // stroke-miterlimit
  




  // stroke-opacity
  




  // stroke
  





  // stroke-width
  





  // StyleType
  




  // SubtreeIsSticky
  




  // SubtreeWillChangeContents
  




  // tab-size
  





  // table-layout
  




  // -webkit-tap-highlight-color
  





  // text-align
  




  // text-align-last
  




  // text-anchor
  




  // text-autospace
  




  // text-box-edge
  




  // text-box-trim
  




  // text-combine-upright
  




  // text-decoration-color
  const StyleColor& TextDecorationColor() const {
    return misc_data_->misc_6_data_->text_decoration_color_;
  }






  // text-decoration-inset
  





  // text-decoration-line
  

  // text-decoration-skip-ink
  




  // text-decoration-skip-spaces
  

  // text-decoration-style
  




  // text-decoration-thickness
  





  // text-emphasis-color
  const StyleColor& TextEmphasisColor() const {
    return misc_inherited_data_->misc_inherited_1_data_->text_emphasis_color_;
  }






  // TextEmphasisCustomMark
  





  // TextEmphasisFill
  




  // TextEmphasisMark
  TextEmphasisMark TextEmphasisMarkInternal() const {
    return static_cast<TextEmphasisMark>(misc_inherited_data_->text_emphasis_mark_);
  }





  // text-emphasis-position
  




  // -webkit-text-fill-color
  const StyleColor& TextFillColor() const {
    return misc_inherited_data_->misc_inherited_2_data_->text_fill_color_;
  }






  // text-fit
  





  // text-indent
  





  // TextIndentFlags
  




  // text-justify
  




  // text-orientation
  




  // text-overflow
  





  // -webkit-text-security
  




  // text-size-adjust
  





  // -webkit-text-stroke-color
  const StyleColor& TextStrokeColor() const {
    return misc_inherited_data_->misc_inherited_2_data_->text_stroke_color_;
  }






  // -webkit-text-stroke-width
  




  // text-transform
  

  // text-transform
  




  // text-underline-offset
  





  // text-underline-position
  




  // text-wrap-mode
  




  // text-wrap-style
  




  // timeline-scope
  





  // top
  





  // touch-action
  




  // transform
  





  // transform-box
  




  // transform-origin
  





  // transform-style
  




  // Transitions
  




  // trigger-scope
  





  // UnconditionalScrollbarSize
  





  // unicode-bidi
  




  // -webkit-user-drag
  




  // -webkit-user-modify
  EUserModify UserModify() const {
    return static_cast<EUserModify>(misc_inherited_data_->user_modify_);
  }





  // user-select
  EUserSelect UserSelect() const {
    return static_cast<EUserSelect>(misc_inherited_data_->user_select_);
  }





  // vector-effect
  




  // VerticalAlign
  unsigned VerticalAlignInternal() const {
    return static_cast<unsigned>(data_.vertical_align_);
  }





  // VerticalAlignLength
  





  // -webkit-border-vertical-spacing
  




  // view-timeline-axis
  





  // view-timeline-inset
  





  // view-timeline-name
  





  // view-transition-class
  




  // view-transition-group
  





  // view-transition-name
  




  // view-transition-scope
  




  // ViewportUnitFlags
  




  // visibility
  




  // visibility
  




  // -webkit-line-clamp
  




  // white-space-collapse
  




  // widows
  




  // width
  





  // word-break
  




  // word-spacing
  const Length& WordSpacingInternal() const {
    return inherited_data_->word_spacing_;
  }






  // writing-mode
  




  // x
  





  // y
  





  // z-index
  




  // zoom
  





  struct Data {
    unsigned pseudo_element_styles_ : 26; // unsigned
    unsigned display_ : 6; // EDisplay
    unsigned style_type_ : 6; // PseudoId
    unsigned vertical_align_ : 4; // unsigned
    unsigned clear_ : 3; // EClear
    unsigned floating_ : 3; // EFloat
    unsigned overflow_x_ : 3; // EOverflow
    unsigned overflow_y_ : 3; // EOverflow
    unsigned position_ : 3; // EPosition
    unsigned transform_box_ : 3; // ETransformBox
    unsigned unicode_bidi_ : 3; // UnicodeBidi
    unsigned affected_by_active_ : 1; // bool
    unsigned content_visibility_ : 2; // EContentVisibility
    unsigned inline_block_baseline_edge_ : 2; // EInlineBlockBaselineEdge
    mutable unsigned is_stacking_context_without_containment_ : 2; // unsigned
    unsigned overflow_anchor_ : 2; // EOverflowAnchor
    unsigned scroll_snap_stop_ : 2; // EScrollSnapStop
    unsigned viewport_unit_flags_ : 2; // unsigned
    unsigned affected_by_drag_ : 1; // bool
    unsigned affected_by_focus_within_ : 1; // bool
    unsigned affected_by_hover_ : 1; // bool
    unsigned allows_z_index_ : 1; // bool
    unsigned border_collapse_is_inherited_ : 1; // bool
    unsigned box_direction_ : 1; // EBoxDirection
    unsigned box_sizing_ : 1; // EBoxSizing
    unsigned caption_side_is_inherited_ : 1; // bool
    mutable unsigned child_has_explicit_inheritance_ : 1; // bool
    unsigned color_is_inherited_ : 1; // bool
    unsigned cursor_is_inherited_ : 1; // bool
    unsigned custom_style_callback_depends_on_font_ : 1; // bool
    unsigned empty_cells_is_inherited_ : 1; // bool
    unsigned forces_stacking_context_ : 1; // bool
    unsigned has_attr_function_ : 1; // bool
    unsigned has_author_background_ : 1; // bool
    unsigned has_author_border_ : 1; // bool
    unsigned has_author_border_radius_ : 1; // bool
    unsigned has_author_highlight_colors_ : 1; // bool
    unsigned has_container_relative_value_ : 1; // bool
    unsigned has_em_units_ : 1; // bool
    unsigned has_env_ : 1; // bool
    unsigned has_explicit_inheritance_ : 1; // bool
    unsigned has_glyph_relative_units_ : 1; // bool
    unsigned has_logical_direction_relative_units_ : 1; // bool
    unsigned has_root_relative_units_ : 1; // bool
    unsigned has_variable_declaration_ : 1; // bool
    unsigned has_variable_reference_ : 1; // bool
    unsigned interactivity_is_inherited_ : 1; // bool
    unsigned is_css_inert_is_inherited_ : 1; // bool
    unsigned is_ensured_in_display_none_ : 1; // bool
    unsigned is_flex_or_grid_or_custom_item_ : 1; // bool
    unsigned is_html_inert_is_inherited_ : 1; // bool
    unsigned is_in_blockifying_display_ : 1; // bool
    unsigned is_in_inlinifying_display_ : 1; // bool
    unsigned is_inside_display_ignoring_floating_children_ : 1; // bool
    unsigned is_link_ : 1; // bool
    unsigned is_original_display_inline_type_ : 1; // bool
    unsigned is_page_margin_box_ : 1; // bool
    unsigned list_style_position_is_inherited_ : 1; // bool
    unsigned origin_trial_test_property_ : 1; // EOriginTrialTestProperty
    unsigned pointer_events_is_inherited_ : 1; // bool
    unsigned rtl_ordering_is_inherited_ : 1; // bool
    unsigned should_ignore_overflow_property_for_inline_block_baseline_ : 1; // bool
    unsigned skips_contents_ : 1; // bool
    unsigned table_layout_ : 1; // ETableLayout
    unsigned text_transform_is_inherited_ : 1; // bool
    unsigned visibility_is_inherited_ : 1; // bool
    unsigned pointer_events_ : 4; // EPointerEvents
    unsigned text_align_ : 4; // ETextAlign
    unsigned writing_mode_ : 3; // WritingMode
    unsigned caret_shape_ : 2; // ECaretShape
    unsigned inside_link_ : 2; // EInsideLink
    unsigned text_wrap_style_ : 2; // TextWrapStyle
    unsigned visibility_ : 2; // EVisibility
    unsigned white_space_collapse_ : 2; // WhiteSpaceCollapse
    unsigned border_collapse_ : 1; // EBorderCollapse
    unsigned caption_side_ : 1; // ECaptionSide
    unsigned caret_animation_ : 1; // ECaretAnimation
    unsigned color_scheme_flags_is_normal_ : 1; // bool
    unsigned color_scheme_forced_ : 1; // bool
    unsigned dark_color_scheme_ : 1; // bool
    unsigned direction_ : 1; // TextDirection
    unsigned is_css_inert_ : 1; // bool
    unsigned is_html_inert_ : 1; // bool
    unsigned list_style_position_ : 1; // EListStylePosition
    unsigned prefers_default_scrollbar_styles_ : 1; // bool
    unsigned print_color_adjust_ : 1; // EPrintColorAdjust
    unsigned rtl_ordering_ : 1; // EOrder
    unsigned text_wrap_mode_ : 1; // TextWrapMode
  };

  enum FieldDifference : uint64_t {
    kAccentColor = static_cast<uint64_t>(1) << 0,
    kAXStyle = static_cast<uint64_t>(1) << 1,
    kBackground = static_cast<uint64_t>(1) << 2,
    kBackgroundColor = static_cast<uint64_t>(1) << 3,
    kBlendMode = static_cast<uint64_t>(1) << 4,
    kBorderImage = static_cast<uint64_t>(1) << 5,
    kBorderOutlineVisitedColor = static_cast<uint64_t>(1) << 6,
    kBorderRadius = static_cast<uint64_t>(1) << 7,
    kBorderShape = static_cast<uint64_t>(1) << 8,
    kBorderVisual = static_cast<uint64_t>(1) << 9,
    kBorderWidth = static_cast<uint64_t>(1) << 10,
    kBoxPaintProperty = static_cast<uint64_t>(1) << 11,
    kClip = static_cast<uint64_t>(1) << 12,
    kClipPath = static_cast<uint64_t>(1) << 13,
    kColor = static_cast<uint64_t>(1) << 14,
    kCompositing = static_cast<uint64_t>(1) << 15,
    kCornerShape = static_cast<uint64_t>(1) << 16,
    kCurrentcolor = static_cast<uint64_t>(1) << 17,
    kFilterData = static_cast<uint64_t>(1) << 18,
    kGapDecorations = static_cast<uint64_t>(1) << 19,
    kHasTransform = static_cast<uint64_t>(1) << 20,
    kInert = static_cast<uint64_t>(1) << 21,
    kInset = static_cast<uint64_t>(1) << 22,
    kLayout = static_cast<uint64_t>(1) << 23,
    kMask = static_cast<uint64_t>(1) << 24,
    kOpacity = static_cast<uint64_t>(1) << 25,
    kOutline = static_cast<uint64_t>(1) << 26,
    kPaint = static_cast<uint64_t>(1) << 27,
    kReshape = static_cast<uint64_t>(1) << 28,
    kScrollAnchor = static_cast<uint64_t>(1) << 29,
    kScrollbarColor = static_cast<uint64_t>(1) << 30,
    kScrollbarStyle = static_cast<uint64_t>(1) << 31,
    kStroke = static_cast<uint64_t>(1) << 32,
    kTextDecoration = static_cast<uint64_t>(1) << 33,
    kTransformData = static_cast<uint64_t>(1) << 34,
    kTransformOther = static_cast<uint64_t>(1) << 35,
    kTransformProperty = static_cast<uint64_t>(1) << 36,
    kVisibility = static_cast<uint64_t>(1) << 37,
    kVisualOverflow = static_cast<uint64_t>(1) << 38,
    kZIndex = static_cast<uint64_t>(1) << 39,
  };

  static uint64_t FieldInvalidationDiff(const ComputedStyle& a, const ComputedStyle& b);

 private:
  friend class ComputedStyleBuilder;
  friend class ComputedStyleBuilderBase;

  // Storage.
  Member<StyleMiscInheritedData> misc_inherited_data_;
  Member<StyleMiscData> misc_data_;
  Member<StyleInheritedData> inherited_data_;
  Member<StyleVisualData> visual_data_;
  Member<StyleSvginheritedData> svginherited_data_;
  Member<StyleBoxData> box_data_;
  Member<StyleSVGData> svg_data_;
  Member<StyleSurroundData> surround_data_;
  Member<StyleBackgroundData> background_data_;

  Member<StyleBaseData> base_data_;

  Data data_;
};

class ComputedStyleBuilderBase {
  STACK_ALLOCATED();
 public:
  template <typename T>
  friend CSSVariableData* GetVariableDataInternal(
    const T& style_or_builder,
    const AtomicString& name,
    std::optional<bool> inherited_hint);

  enum IsAtShadowBoundary {
    kAtShadowBoundary,
    kNotAtShadowBoundary,
  };

  // accent-color
  
  void SetAccentColor(const StyleAutoColor& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->accent_color_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->accent_color_ = v;
  }

  void SetAccentColor(StyleAutoColor&& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->accent_color_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->accent_color_ = std::move(v);
  }

  inline void ResetAccentColor() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->accent_color_ = StyleAutoColor::AutoColor();
  }



  // AffectedByActive
  bool AffectedByActive() const {
    return static_cast<bool>(data_.affected_by_active_);
  }

  void SetAffectedByActive() {
    data_.affected_by_active_ = static_cast<unsigned>(true);
  }


  // AffectedByCSSFunction
  bool AffectedByCSSFunction() const {
    return static_cast<bool>(misc_data_->affected_by_css_function_);
  }

  void SetAffectedByCSSFunction() {
    if (!(misc_data_->affected_by_css_function_ == static_cast<unsigned>(true)))
      Access(misc_data_, access_.misc_data_)->affected_by_css_function_ = static_cast<unsigned>(true);
  }


  // AffectedByDrag
  bool AffectedByDrag() const {
    return static_cast<bool>(data_.affected_by_drag_);
  }

  void SetAffectedByDrag() {
    data_.affected_by_drag_ = static_cast<unsigned>(true);
  }


  // AffectedByFocusWithin
  bool AffectedByFocusWithin() const {
    return static_cast<bool>(data_.affected_by_focus_within_);
  }

  void SetAffectedByFocusWithin() {
    data_.affected_by_focus_within_ = static_cast<unsigned>(true);
  }


  // AffectedByFunctionalMedia
  bool AffectedByFunctionalMedia() const {
    return static_cast<bool>(misc_data_->affected_by_functional_media_);
  }

  void SetAffectedByFunctionalMedia() {
    if (!(misc_data_->affected_by_functional_media_ == static_cast<unsigned>(true)))
      Access(misc_data_, access_.misc_data_)->affected_by_functional_media_ = static_cast<unsigned>(true);
  }


  // AffectedByFunctionalNavigation
  bool AffectedByFunctionalNavigation() const {
    return static_cast<bool>(misc_data_->affected_by_functional_navigation_);
  }

  void SetAffectedByFunctionalNavigation() {
    if (!(misc_data_->affected_by_functional_navigation_ == static_cast<unsigned>(true)))
      Access(misc_data_, access_.misc_data_)->affected_by_functional_navigation_ = static_cast<unsigned>(true);
  }


  // AffectedByHover
  bool AffectedByHover() const {
    return static_cast<bool>(data_.affected_by_hover_);
  }

  void SetAffectedByHover() {
    data_.affected_by_hover_ = static_cast<unsigned>(true);
  }


  // align-content
  const StyleContentAlignmentData& AlignContent() const {
    return misc_data_->misc_1_data_->align_content_;
  }

  void SetAlignContent(const StyleContentAlignmentData& v) {
    if (!(misc_data_->misc_1_data_->align_content_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->align_content_ = v;
  }

  void SetAlignContent(StyleContentAlignmentData&& v) {
    if (!(misc_data_->misc_1_data_->align_content_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->align_content_ = std::move(v);
  }

  inline void ResetAlignContent() {
    Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->align_content_ = StyleContentAlignmentData(ContentPosition::kNormal, ContentDistributionType::kDefault, OverflowAlignment::kDefault);
  }



  // -internal-align-content-block
  bool AlignContentBlockCenter() const {
    return static_cast<bool>(misc_data_->align_content_block_center_);
  }

  void SetAlignContentBlockCenter(bool v) {
    if (!(misc_data_->align_content_block_center_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->align_content_block_center_ = static_cast<unsigned>(v);
  }

  inline void ResetAlignContentBlockCenter() {
    Access(misc_data_, access_.misc_data_)->align_content_block_center_ = static_cast<unsigned>(false);
  }


  // align-items
  const StyleSelfAlignmentData& AlignItems() const {
    return box_data_->align_items_;
  }

  void SetAlignItems(const StyleSelfAlignmentData& v) {
    if (!(box_data_->align_items_ == v))
      Access(box_data_, access_.box_data_)->align_items_ = v;
  }

  void SetAlignItems(StyleSelfAlignmentData&& v) {
    if (!(box_data_->align_items_ == v))
      Access(box_data_, access_.box_data_)->align_items_ = std::move(v);
  }

  inline void ResetAlignItems() {
    Access(box_data_, access_.box_data_)->align_items_ = StyleSelfAlignmentData(ItemPosition::kNormal, OverflowAlignment::kDefault);
  }



  // align-self
  const StyleSelfAlignmentData& AlignSelf() const {
    return misc_data_->misc_1_data_->align_self_;
  }

  void SetAlignSelf(const StyleSelfAlignmentData& v) {
    if (!(misc_data_->misc_1_data_->align_self_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->align_self_ = v;
  }

  void SetAlignSelf(StyleSelfAlignmentData&& v) {
    if (!(misc_data_->misc_1_data_->align_self_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->align_self_ = std::move(v);
  }

  inline void ResetAlignSelf() {
    Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->align_self_ = StyleSelfAlignmentData(ItemPosition::kAuto, OverflowAlignment::kDefault);
  }



  // alignment-baseline
  EAlignmentBaseline AlignmentBaseline() const {
    return static_cast<EAlignmentBaseline>(svg_data_->alignment_baseline_);
  }

  void SetAlignmentBaseline(EAlignmentBaseline v) {
    if (!(svg_data_->alignment_baseline_ == static_cast<unsigned>(v)))
      Access(svg_data_, access_.svg_data_)->alignment_baseline_ = static_cast<unsigned>(v);
  }

  inline void ResetAlignmentBaseline() {
    Access(svg_data_, access_.svg_data_)->alignment_baseline_ = static_cast<unsigned>(EAlignmentBaseline::kAuto);
  }


  // AllowsZIndex
  bool AllowsZIndex() const {
    return static_cast<bool>(data_.allows_z_index_);
  }

  void SetAllowsZIndex(bool v) {
    data_.allows_z_index_ = static_cast<unsigned>(v);
  }

  inline void ResetAllowsZIndex() {
    data_.allows_z_index_ = static_cast<unsigned>(false);
  }


  // AnchorCenterOffset
  const std::optional<PhysicalOffset>& AnchorCenterOffset() const {
    return misc_data_->misc_8_data_->anchor_center_offset_;
  }

  void SetAnchorCenterOffset(const std::optional<PhysicalOffset>& v) {
    if (!(misc_data_->misc_8_data_->anchor_center_offset_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->anchor_center_offset_ = v;
  }

  void SetAnchorCenterOffset(std::optional<PhysicalOffset>&& v) {
    if (!(misc_data_->misc_8_data_->anchor_center_offset_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->anchor_center_offset_ = std::move(v);
  }

  inline void ResetAnchorCenterOffset() {
    Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->anchor_center_offset_ = std::nullopt;
  }



  // anchor-name
  const Member<ScopedCSSNameList>& AnchorName() const {
    return misc_data_->misc_1_data_->anchor_name_;
  }

  void SetAnchorName(const Member<ScopedCSSNameList>& v) {
    if (!(misc_data_->misc_1_data_->anchor_name_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->anchor_name_ = v;
  }

  void SetAnchorName(Member<ScopedCSSNameList>&& v) {
    if (!(misc_data_->misc_1_data_->anchor_name_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->anchor_name_ = std::move(v);
  }

  inline void ResetAnchorName() {
    Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->anchor_name_ = nullptr;
  }



  // anchor-scope
  const StyleAnchorScope& AnchorScope() const {
    return misc_data_->misc_1_data_->anchor_scope_;
  }

  void SetAnchorScope(const StyleAnchorScope& v) {
    if (!(misc_data_->misc_1_data_->anchor_scope_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->anchor_scope_ = v;
  }

  void SetAnchorScope(StyleAnchorScope&& v) {
    if (!(misc_data_->misc_1_data_->anchor_scope_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->anchor_scope_ = std::move(v);
  }

  inline void ResetAnchorScope() {
    Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->anchor_scope_ = StyleAnchorScope();
  }



  // Animations
  const Member<CSSAnimationData>& Animations() const {
    return misc_data_->misc_7_data_->animations_;
  }



  inline void ResetAnimations() {
    Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->animations_ = nullptr;
  }



  // appearance
  
  void SetAppearance(AppearanceValue v) {
    if (!(misc_data_->appearance_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->appearance_ = static_cast<unsigned>(v);
  }

  inline void ResetAppearance() {
    Access(misc_data_, access_.misc_data_)->appearance_ = static_cast<unsigned>(AppearanceValue::kNone);
  }


  // aspect-ratio
  const StyleAspectRatio& AspectRatio() const {
    return surround_data_->aspect_ratio_;
  }

  void SetAspectRatio(const StyleAspectRatio& v) {
    if (!(surround_data_->aspect_ratio_ == v))
      Access(surround_data_, access_.surround_data_)->aspect_ratio_ = v;
  }

  void SetAspectRatio(StyleAspectRatio&& v) {
    if (!(surround_data_->aspect_ratio_ == v))
      Access(surround_data_, access_.surround_data_)->aspect_ratio_ = std::move(v);
  }

  inline void ResetAspectRatio() {
    Access(surround_data_, access_.surround_data_)->aspect_ratio_ = StyleAspectRatio(EAspectRatioType::kAuto, gfx::SizeF());
  }



  // backdrop-filter
  const FilterOperations& BackdropFilter() const {
    return misc_data_->misc_1_data_->backdrop_filter_;
  }

  void SetBackdropFilter(const FilterOperations& v) {
    if (!(misc_data_->misc_1_data_->backdrop_filter_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->backdrop_filter_ = v;
  }

  void SetBackdropFilter(FilterOperations&& v) {
    if (!(misc_data_->misc_1_data_->backdrop_filter_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->backdrop_filter_ = std::move(v);
  }

  inline void ResetBackdropFilter() {
    Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->backdrop_filter_ = FilterOperations();
  }



  // backface-visibility
  EBackfaceVisibility BackfaceVisibility() const {
    return static_cast<EBackfaceVisibility>(misc_data_->backface_visibility_);
  }

  void SetBackfaceVisibility(EBackfaceVisibility v) {
    if (!(misc_data_->backface_visibility_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->backface_visibility_ = static_cast<unsigned>(v);
  }

  inline void ResetBackfaceVisibility() {
    Access(misc_data_, access_.misc_data_)->backface_visibility_ = static_cast<unsigned>(EBackfaceVisibility::kVisible);
  }


  // Background
  


  inline void ResetBackground() {
    Access(background_data_, access_.background_data_)->background_ = FillLayer(EFillLayerType::kBackground, true);
  }



  // background-color
  
  void SetBackgroundColor(const StyleColor& v) {
    if (!(background_data_->background_color_ == v))
      Access(background_data_, access_.background_data_)->background_color_ = v;
  }

  void SetBackgroundColor(StyleColor&& v) {
    if (!(background_data_->background_color_ == v))
      Access(background_data_, access_.background_data_)->background_color_ = std::move(v);
  }

  inline void ResetBackgroundColor() {
    Access(background_data_, access_.background_data_)->background_color_ = StyleColor(Color::kTransparent);
  }



  // BaseData
  StyleBaseData* BaseData() const {
    return base_data_;
  }

  void SetBaseData(StyleBaseData* v) {
    base_data_ = std::move(v);
  }


  // BaseTextDecorationData
  AppliedTextDecorationVector* BaseTextDecorationData() const {
    return visual_data_->base_text_decoration_data_.Get();
  }

  void SetBaseTextDecorationData(Member<AppliedTextDecorationVector> v) {
    if (!(visual_data_->base_text_decoration_data_ == v))
      Access(visual_data_, access_.visual_data_)->base_text_decoration_data_ = std::move(v);
  }


  // baseline-shift
  const Length& BaselineShift() const {
    return svg_data_->svgmisc_data_->baseline_shift_;
  }

  void SetBaselineShift(const Length& v) {
    if (!(svg_data_->svgmisc_data_->baseline_shift_ == v))
      Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->baseline_shift_ = v;
  }

  void SetBaselineShift(Length&& v) {
    if (!(svg_data_->svgmisc_data_->baseline_shift_ == v))
      Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->baseline_shift_ = std::move(v);
  }

  inline void ResetBaselineShift() {
    Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->baseline_shift_ = Length::Fixed();
  }



  // BaselineShiftType
  EBaselineShiftType BaselineShiftType() const {
    return static_cast<EBaselineShiftType>(svg_data_->svgmisc_data_->baseline_shift_type_);
  }

  void SetBaselineShiftType(EBaselineShiftType v) {
    if (!(svg_data_->svgmisc_data_->baseline_shift_type_ == static_cast<unsigned>(v)))
      Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->baseline_shift_type_ = static_cast<unsigned>(v);
  }

  inline void ResetBaselineShiftType() {
    Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->baseline_shift_type_ = static_cast<unsigned>(EBaselineShiftType::kLength);
  }


  // baseline-source
  EBaselineSource BaselineSource() const {
    return static_cast<EBaselineSource>(box_data_->baseline_source_);
  }

  void SetBaselineSource(EBaselineSource v) {
    if (!(box_data_->baseline_source_ == static_cast<unsigned>(v)))
      Access(box_data_, access_.box_data_)->baseline_source_ = static_cast<unsigned>(v);
  }

  inline void ResetBaselineSource() {
    Access(box_data_, access_.box_data_)->baseline_source_ = static_cast<unsigned>(EBaselineSource::kAuto);
  }


  // mix-blend-mode
  BlendMode GetBlendMode() const {
    return static_cast<BlendMode>(misc_data_->blend_mode_);
  }

  void SetBlendMode(BlendMode v) {
    if (!(misc_data_->blend_mode_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->blend_mode_ = static_cast<unsigned>(v);
  }

  inline void ResetBlendMode() {
    Access(misc_data_, access_.misc_data_)->blend_mode_ = static_cast<unsigned>(BlendMode::kNormal);
  }


  // block-ellipsis
  EBlockEllipsis BlockEllipsis() const {
    return static_cast<EBlockEllipsis>(misc_inherited_data_->block_ellipsis_);
  }

  void SetBlockEllipsis(EBlockEllipsis v) {
    if (!(misc_inherited_data_->block_ellipsis_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->block_ellipsis_ = static_cast<unsigned>(v);
  }

  inline void ResetBlockEllipsis() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->block_ellipsis_ = static_cast<unsigned>(EBlockEllipsis::kNoEllipsis);
  }


  // border-bottom-color
  
  void SetBorderBottomColor(const StyleColor& v) {
    if (!(surround_data_->border_bottom_color_ == v))
      Access(surround_data_, access_.surround_data_)->border_bottom_color_ = v;
  }

  void SetBorderBottomColor(StyleColor&& v) {
    if (!(surround_data_->border_bottom_color_ == v))
      Access(surround_data_, access_.surround_data_)->border_bottom_color_ = std::move(v);
  }

  inline void ResetBorderBottomColor() {
    Access(surround_data_, access_.surround_data_)->border_bottom_color_ = StyleColor::CurrentColor();
  }



  // border-bottom-left-radius
  const LengthSize& BorderBottomLeftRadius() const {
    return surround_data_->border_bottom_left_radius_;
  }

  void SetBorderBottomLeftRadius(const LengthSize& v) {
    if (!(surround_data_->border_bottom_left_radius_ == v))
      Access(surround_data_, access_.surround_data_)->border_bottom_left_radius_ = v;
  }

  void SetBorderBottomLeftRadius(LengthSize&& v) {
    if (!(surround_data_->border_bottom_left_radius_ == v))
      Access(surround_data_, access_.surround_data_)->border_bottom_left_radius_ = std::move(v);
  }

  inline void ResetBorderBottomLeftRadius() {
    Access(surround_data_, access_.surround_data_)->border_bottom_left_radius_ = LengthSize(Length::Fixed(0), Length::Fixed(0));
  }



  // border-bottom-right-radius
  const LengthSize& BorderBottomRightRadius() const {
    return surround_data_->border_bottom_right_radius_;
  }

  void SetBorderBottomRightRadius(const LengthSize& v) {
    if (!(surround_data_->border_bottom_right_radius_ == v))
      Access(surround_data_, access_.surround_data_)->border_bottom_right_radius_ = v;
  }

  void SetBorderBottomRightRadius(LengthSize&& v) {
    if (!(surround_data_->border_bottom_right_radius_ == v))
      Access(surround_data_, access_.surround_data_)->border_bottom_right_radius_ = std::move(v);
  }

  inline void ResetBorderBottomRightRadius() {
    Access(surround_data_, access_.surround_data_)->border_bottom_right_radius_ = LengthSize(Length::Fixed(0), Length::Fixed(0));
  }



  // border-bottom-style
  EBorderStyle BorderBottomStyle() const {
    return static_cast<EBorderStyle>(box_data_->border_bottom_style_);
  }

  void SetBorderBottomStyle(EBorderStyle v) {
    if (!(box_data_->border_bottom_style_ == static_cast<unsigned>(v)))
      Access(box_data_, access_.box_data_)->border_bottom_style_ = static_cast<unsigned>(v);
  }

  inline void ResetBorderBottomStyle() {
    Access(box_data_, access_.box_data_)->border_bottom_style_ = static_cast<unsigned>(EBorderStyle::kNone);
  }


  // border-bottom-width
  const int& SpecifiedBorderBottomWidth() const {
    return box_data_->border_bottom_width_;
  }

  void SetBorderBottomWidth(const int& v) {
    if (!(box_data_->border_bottom_width_ == v))
      Access(box_data_, access_.box_data_)->border_bottom_width_ = v;
  }

  void SetBorderBottomWidth(int&& v) {
    if (!(box_data_->border_bottom_width_ == v))
      Access(box_data_, access_.box_data_)->border_bottom_width_ = std::move(v);
  }

  inline void ResetBorderBottomWidth() {
    Access(box_data_, access_.box_data_)->border_bottom_width_ = 3;
  }



  // border-collapse
  EBorderCollapse BorderCollapse() const {
    return static_cast<EBorderCollapse>(data_.border_collapse_);
  }

  void SetBorderCollapse(EBorderCollapse v) {
    data_.border_collapse_ = static_cast<unsigned>(v);
  }

  inline void ResetBorderCollapse() {
    data_.border_collapse_ = static_cast<unsigned>(EBorderCollapse::kSeparate);
  }


  // border-collapse
  bool BorderCollapseIsInherited() const {
    return static_cast<bool>(data_.border_collapse_is_inherited_);
  }

  void SetBorderCollapseIsInherited(bool v) {
    data_.border_collapse_is_inherited_ = static_cast<unsigned>(v);
  }

  inline void ResetBorderCollapseIsInherited() {
    data_.border_collapse_is_inherited_ = static_cast<unsigned>(true);
  }


  // border-image
  const NinePieceImage& BorderImage() const {
    return surround_data_->border_image_;
  }

  void SetBorderImage(const NinePieceImage& v) {
    if (!(surround_data_->border_image_ == v))
      Access(surround_data_, access_.surround_data_)->border_image_ = v;
  }

  void SetBorderImage(NinePieceImage&& v) {
    if (!(surround_data_->border_image_ == v))
      Access(surround_data_, access_.surround_data_)->border_image_ = std::move(v);
  }

  inline void ResetBorderImage() {
    Access(surround_data_, access_.surround_data_)->border_image_ = NinePieceImage();
  }



  // border-left-color
  
  void SetBorderLeftColor(const StyleColor& v) {
    if (!(surround_data_->border_left_color_ == v))
      Access(surround_data_, access_.surround_data_)->border_left_color_ = v;
  }

  void SetBorderLeftColor(StyleColor&& v) {
    if (!(surround_data_->border_left_color_ == v))
      Access(surround_data_, access_.surround_data_)->border_left_color_ = std::move(v);
  }

  inline void ResetBorderLeftColor() {
    Access(surround_data_, access_.surround_data_)->border_left_color_ = StyleColor::CurrentColor();
  }



  // border-left-style
  EBorderStyle BorderLeftStyle() const {
    return static_cast<EBorderStyle>(box_data_->border_left_style_);
  }

  void SetBorderLeftStyle(EBorderStyle v) {
    if (!(box_data_->border_left_style_ == static_cast<unsigned>(v)))
      Access(box_data_, access_.box_data_)->border_left_style_ = static_cast<unsigned>(v);
  }

  inline void ResetBorderLeftStyle() {
    Access(box_data_, access_.box_data_)->border_left_style_ = static_cast<unsigned>(EBorderStyle::kNone);
  }


  // border-left-width
  const int& SpecifiedBorderLeftWidth() const {
    return box_data_->border_left_width_;
  }

  void SetBorderLeftWidth(const int& v) {
    if (!(box_data_->border_left_width_ == v))
      Access(box_data_, access_.box_data_)->border_left_width_ = v;
  }

  void SetBorderLeftWidth(int&& v) {
    if (!(box_data_->border_left_width_ == v))
      Access(box_data_, access_.box_data_)->border_left_width_ = std::move(v);
  }

  inline void ResetBorderLeftWidth() {
    Access(box_data_, access_.box_data_)->border_left_width_ = 3;
  }



  // border-right-color
  
  void SetBorderRightColor(const StyleColor& v) {
    if (!(surround_data_->border_right_color_ == v))
      Access(surround_data_, access_.surround_data_)->border_right_color_ = v;
  }

  void SetBorderRightColor(StyleColor&& v) {
    if (!(surround_data_->border_right_color_ == v))
      Access(surround_data_, access_.surround_data_)->border_right_color_ = std::move(v);
  }

  inline void ResetBorderRightColor() {
    Access(surround_data_, access_.surround_data_)->border_right_color_ = StyleColor::CurrentColor();
  }



  // border-right-style
  EBorderStyle BorderRightStyle() const {
    return static_cast<EBorderStyle>(box_data_->border_right_style_);
  }

  void SetBorderRightStyle(EBorderStyle v) {
    if (!(box_data_->border_right_style_ == static_cast<unsigned>(v)))
      Access(box_data_, access_.box_data_)->border_right_style_ = static_cast<unsigned>(v);
  }

  inline void ResetBorderRightStyle() {
    Access(box_data_, access_.box_data_)->border_right_style_ = static_cast<unsigned>(EBorderStyle::kNone);
  }


  // border-right-width
  const int& SpecifiedBorderRightWidth() const {
    return box_data_->border_right_width_;
  }

  void SetBorderRightWidth(const int& v) {
    if (!(box_data_->border_right_width_ == v))
      Access(box_data_, access_.box_data_)->border_right_width_ = v;
  }

  void SetBorderRightWidth(int&& v) {
    if (!(box_data_->border_right_width_ == v))
      Access(box_data_, access_.box_data_)->border_right_width_ = std::move(v);
  }

  inline void ResetBorderRightWidth() {
    Access(box_data_, access_.box_data_)->border_right_width_ = 3;
  }



  // border-shape
  const Member<StyleBorderShape>& BorderShape() const {
    return misc_data_->misc_1_data_->border_shape_;
  }

  void SetBorderShape(const Member<StyleBorderShape>& v) {
    if (!(misc_data_->misc_1_data_->border_shape_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->border_shape_ = v;
  }

  void SetBorderShape(Member<StyleBorderShape>&& v) {
    if (!(misc_data_->misc_1_data_->border_shape_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->border_shape_ = std::move(v);
  }

  inline void ResetBorderShape() {
    Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->border_shape_ = nullptr;
  }



  // border-top-color
  
  void SetBorderTopColor(const StyleColor& v) {
    if (!(surround_data_->border_top_color_ == v))
      Access(surround_data_, access_.surround_data_)->border_top_color_ = v;
  }

  void SetBorderTopColor(StyleColor&& v) {
    if (!(surround_data_->border_top_color_ == v))
      Access(surround_data_, access_.surround_data_)->border_top_color_ = std::move(v);
  }

  inline void ResetBorderTopColor() {
    Access(surround_data_, access_.surround_data_)->border_top_color_ = StyleColor::CurrentColor();
  }



  // border-top-left-radius
  const LengthSize& BorderTopLeftRadius() const {
    return surround_data_->border_top_left_radius_;
  }

  void SetBorderTopLeftRadius(const LengthSize& v) {
    if (!(surround_data_->border_top_left_radius_ == v))
      Access(surround_data_, access_.surround_data_)->border_top_left_radius_ = v;
  }

  void SetBorderTopLeftRadius(LengthSize&& v) {
    if (!(surround_data_->border_top_left_radius_ == v))
      Access(surround_data_, access_.surround_data_)->border_top_left_radius_ = std::move(v);
  }

  inline void ResetBorderTopLeftRadius() {
    Access(surround_data_, access_.surround_data_)->border_top_left_radius_ = LengthSize(Length::Fixed(0), Length::Fixed(0));
  }



  // border-top-right-radius
  const LengthSize& BorderTopRightRadius() const {
    return surround_data_->border_top_right_radius_;
  }

  void SetBorderTopRightRadius(const LengthSize& v) {
    if (!(surround_data_->border_top_right_radius_ == v))
      Access(surround_data_, access_.surround_data_)->border_top_right_radius_ = v;
  }

  void SetBorderTopRightRadius(LengthSize&& v) {
    if (!(surround_data_->border_top_right_radius_ == v))
      Access(surround_data_, access_.surround_data_)->border_top_right_radius_ = std::move(v);
  }

  inline void ResetBorderTopRightRadius() {
    Access(surround_data_, access_.surround_data_)->border_top_right_radius_ = LengthSize(Length::Fixed(0), Length::Fixed(0));
  }



  // border-top-style
  EBorderStyle BorderTopStyle() const {
    return static_cast<EBorderStyle>(box_data_->border_top_style_);
  }

  void SetBorderTopStyle(EBorderStyle v) {
    if (!(box_data_->border_top_style_ == static_cast<unsigned>(v)))
      Access(box_data_, access_.box_data_)->border_top_style_ = static_cast<unsigned>(v);
  }

  inline void ResetBorderTopStyle() {
    Access(box_data_, access_.box_data_)->border_top_style_ = static_cast<unsigned>(EBorderStyle::kNone);
  }


  // border-top-width
  const int& SpecifiedBorderTopWidth() const {
    return box_data_->border_top_width_;
  }

  void SetBorderTopWidth(const int& v) {
    if (!(box_data_->border_top_width_ == v))
      Access(box_data_, access_.box_data_)->border_top_width_ = v;
  }

  void SetBorderTopWidth(int&& v) {
    if (!(box_data_->border_top_width_ == v))
      Access(box_data_, access_.box_data_)->border_top_width_ = std::move(v);
  }

  inline void ResetBorderTopWidth() {
    Access(box_data_, access_.box_data_)->border_top_width_ = 3;
  }



  // bottom
  const Length& Bottom() const {
    return surround_data_->bottom_;
  }

  void SetBottom(const Length& v) {
    if (!(surround_data_->bottom_ == v))
      Access(surround_data_, access_.surround_data_)->bottom_ = v;
  }

  void SetBottom(Length&& v) {
    if (!(surround_data_->bottom_ == v))
      Access(surround_data_, access_.surround_data_)->bottom_ = std::move(v);
  }

  inline void ResetBottom() {
    Access(surround_data_, access_.surround_data_)->bottom_ = Length();
  }



  // -webkit-box-align
  EBoxAlignment BoxAlign() const {
    return static_cast<EBoxAlignment>(misc_data_->box_align_);
  }

  void SetBoxAlign(EBoxAlignment v) {
    if (!(misc_data_->box_align_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->box_align_ = static_cast<unsigned>(v);
  }

  inline void ResetBoxAlign() {
    Access(misc_data_, access_.misc_data_)->box_align_ = static_cast<unsigned>(EBoxAlignment::kStretch);
  }


  // box-decoration-break
  EBoxDecorationBreak BoxDecorationBreak() const {
    return static_cast<EBoxDecorationBreak>(box_data_->box_decoration_break_);
  }

  void SetBoxDecorationBreak(EBoxDecorationBreak v) {
    if (!(box_data_->box_decoration_break_ == static_cast<unsigned>(v)))
      Access(box_data_, access_.box_data_)->box_decoration_break_ = static_cast<unsigned>(v);
  }

  inline void ResetBoxDecorationBreak() {
    Access(box_data_, access_.box_data_)->box_decoration_break_ = static_cast<unsigned>(EBoxDecorationBreak::kSlice);
  }


  // -webkit-box-direction
  
  void SetBoxDirection(EBoxDirection v) {
    data_.box_direction_ = static_cast<unsigned>(v);
  }

  inline void ResetBoxDirection() {
    data_.box_direction_ = static_cast<unsigned>(EBoxDirection::kNormal);
  }


  // -webkit-box-flex
  float BoxFlex() const {
    return misc_data_->misc_6_data_->box_flex_;
  }

  void SetBoxFlex(float v) {
    if (!(misc_data_->misc_6_data_->box_flex_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->box_flex_ = v;
  }

  inline void ResetBoxFlex() {
    Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->box_flex_ = 0.0f;
  }


  // -webkit-box-ordinal-group
  unsigned BoxOrdinalGroup() const {
    return misc_data_->misc_7_data_->box_ordinal_group_;
  }


  inline void ResetBoxOrdinalGroup() {
    Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->box_ordinal_group_ = 1;
  }


  // -webkit-box-orient
  EBoxOrient BoxOrient() const {
    return static_cast<EBoxOrient>(misc_data_->box_orient_);
  }

  void SetBoxOrient(EBoxOrient v) {
    if (!(misc_data_->box_orient_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->box_orient_ = static_cast<unsigned>(v);
  }

  inline void ResetBoxOrient() {
    Access(misc_data_, access_.misc_data_)->box_orient_ = static_cast<unsigned>(EBoxOrient::kHorizontal);
  }


  // -webkit-box-pack
  EBoxPack BoxPack() const {
    return static_cast<EBoxPack>(misc_data_->box_pack_);
  }

  void SetBoxPack(EBoxPack v) {
    if (!(misc_data_->box_pack_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->box_pack_ = static_cast<unsigned>(v);
  }

  inline void ResetBoxPack() {
    Access(misc_data_, access_.misc_data_)->box_pack_ = static_cast<unsigned>(EBoxPack::kStart);
  }


  // -webkit-box-reflect
  StyleReflection* BoxReflect() const {
    return misc_data_->misc_7_data_->box_reflect_.Get();
  }

  void SetBoxReflect(Member<StyleReflection> v) {
    if (!(misc_data_->misc_7_data_->box_reflect_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->box_reflect_ = std::move(v);
  }


  // box-shadow
  ShadowList* BoxShadow() const {
    return misc_data_->misc_1_data_->box_shadow_.Get();
  }

  void SetBoxShadow(Member<ShadowList> v) {
    if (!(misc_data_->misc_1_data_->box_shadow_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->box_shadow_ = std::move(v);
  }


  // box-sizing
  EBoxSizing BoxSizing() const {
    return static_cast<EBoxSizing>(data_.box_sizing_);
  }

  void SetBoxSizing(EBoxSizing v) {
    data_.box_sizing_ = static_cast<unsigned>(v);
  }

  inline void ResetBoxSizing() {
    data_.box_sizing_ = static_cast<unsigned>(EBoxSizing::kContentBox);
  }


  // break-after
  EBreakBetween BreakAfter() const {
    return static_cast<EBreakBetween>(misc_data_->break_after_);
  }

  void SetBreakAfter(EBreakBetween v) {
    if (!(misc_data_->break_after_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->break_after_ = static_cast<unsigned>(v);
  }

  inline void ResetBreakAfter() {
    Access(misc_data_, access_.misc_data_)->break_after_ = static_cast<unsigned>(EBreakBetween::kAuto);
  }


  // break-before
  EBreakBetween BreakBefore() const {
    return static_cast<EBreakBetween>(misc_data_->break_before_);
  }

  void SetBreakBefore(EBreakBetween v) {
    if (!(misc_data_->break_before_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->break_before_ = static_cast<unsigned>(v);
  }

  inline void ResetBreakBefore() {
    Access(misc_data_, access_.misc_data_)->break_before_ = static_cast<unsigned>(EBreakBetween::kAuto);
  }


  // break-inside
  EBreakInside BreakInside() const {
    return static_cast<EBreakInside>(misc_data_->break_inside_);
  }

  void SetBreakInside(EBreakInside v) {
    if (!(misc_data_->break_inside_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->break_inside_ = static_cast<unsigned>(v);
  }

  inline void ResetBreakInside() {
    Access(misc_data_, access_.misc_data_)->break_inside_ = static_cast<unsigned>(EBreakInside::kAuto);
  }


  // buffered-rendering
  EBufferedRendering BufferedRendering() const {
    return static_cast<EBufferedRendering>(svg_data_->buffered_rendering_);
  }

  void SetBufferedRendering(EBufferedRendering v) {
    if (!(svg_data_->buffered_rendering_ == static_cast<unsigned>(v)))
      Access(svg_data_, access_.svg_data_)->buffered_rendering_ = static_cast<unsigned>(v);
  }

  inline void ResetBufferedRendering() {
    Access(svg_data_, access_.svg_data_)->buffered_rendering_ = static_cast<unsigned>(EBufferedRendering::kAuto);
  }


  // CallbackSelectors
  const Vector<String>& CallbackSelectors() const {
    return misc_data_->misc_8_data_->callback_selectors_;
  }



  inline void ResetCallbackSelectors() {
    Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->callback_selectors_ = Vector<String>();
  }



  // CanAffectAnimations
  bool CanAffectAnimations() const {
    return static_cast<bool>(misc_data_->can_affect_animations_);
  }

  void SetCanAffectAnimations() {
    if (!(misc_data_->can_affect_animations_ == static_cast<unsigned>(true)))
      Access(misc_data_, access_.misc_data_)->can_affect_animations_ = static_cast<unsigned>(true);
  }


  // stroke-linecap
  LineCap CapStyle() const {
    return static_cast<LineCap>(svginherited_data_->stroke_data_->cap_style_);
  }

  void SetCapStyle(LineCap v) {
    if (!(svginherited_data_->stroke_data_->cap_style_ == static_cast<unsigned>(v)))
      Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->cap_style_ = static_cast<unsigned>(v);
  }

  inline void ResetCapStyle() {
    Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->cap_style_ = static_cast<unsigned>(kButtCap);
  }


  // caption-side
  ECaptionSide CaptionSide() const {
    return static_cast<ECaptionSide>(data_.caption_side_);
  }

  void SetCaptionSide(ECaptionSide v) {
    data_.caption_side_ = static_cast<unsigned>(v);
  }

  inline void ResetCaptionSide() {
    data_.caption_side_ = static_cast<unsigned>(ECaptionSide::kTop);
  }


  // caption-side
  bool CaptionSideIsInherited() const {
    return static_cast<bool>(data_.caption_side_is_inherited_);
  }

  void SetCaptionSideIsInherited(bool v) {
    data_.caption_side_is_inherited_ = static_cast<unsigned>(v);
  }

  inline void ResetCaptionSideIsInherited() {
    data_.caption_side_is_inherited_ = static_cast<unsigned>(true);
  }


  // caret-animation
  ECaretAnimation CaretAnimation() const {
    return static_cast<ECaretAnimation>(data_.caret_animation_);
  }

  void SetCaretAnimation(ECaretAnimation v) {
    data_.caret_animation_ = static_cast<unsigned>(v);
  }

  inline void ResetCaretAnimation() {
    data_.caret_animation_ = static_cast<unsigned>(ECaretAnimation::kAuto);
  }


  // caret-color
  
  void SetCaretColor(const StyleCaretColor& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->caret_color_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->caret_color_ = v;
  }

  void SetCaretColor(StyleCaretColor&& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->caret_color_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->caret_color_ = std::move(v);
  }

  inline void ResetCaretColor() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->caret_color_ = StyleCaretColor();
  }



  // caret-shape
  ECaretShape CaretShape() const {
    return static_cast<ECaretShape>(data_.caret_shape_);
  }

  void SetCaretShape(ECaretShape v) {
    data_.caret_shape_ = static_cast<unsigned>(v);
  }

  inline void ResetCaretShape() {
    data_.caret_shape_ = static_cast<unsigned>(ECaretShape::kAuto);
  }


  // clear
  
  void SetClear(EClear v) {
    data_.clear_ = static_cast<unsigned>(v);
  }

  inline void ResetClear() {
    data_.clear_ = static_cast<unsigned>(EClear::kNone);
  }


  // clip
  const LengthBox& Clip() const {
    return visual_data_->clip_;
  }



  inline void ResetClip() {
    Access(visual_data_, access_.visual_data_)->clip_ = LengthBox();
  }



  // clip-path
  


  inline void ResetClipPath() {
    Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->clip_path_ = nullptr;
  }



  // clip-rule
  WindRule ClipRule() const {
    return static_cast<WindRule>(svginherited_data_->clip_rule_);
  }

  void SetClipRule(WindRule v) {
    if (!(svginherited_data_->clip_rule_ == static_cast<unsigned>(v)))
      Access(svginherited_data_, access_.svginherited_data_)->clip_rule_ = static_cast<unsigned>(v);
  }

  inline void ResetClipRule() {
    Access(svginherited_data_, access_.svginherited_data_)->clip_rule_ = static_cast<unsigned>(RULE_NONZERO);
  }


  // color
  
  void SetColor(const StyleColor& v) {
    if (!(inherited_data_->color_ == v))
      Access(inherited_data_, access_.inherited_data_)->color_ = v;
  }

  void SetColor(StyleColor&& v) {
    if (!(inherited_data_->color_ == v))
      Access(inherited_data_, access_.inherited_data_)->color_ = std::move(v);
  }

  inline void ResetColor() {
    Access(inherited_data_, access_.inherited_data_)->color_ = StyleColor(Color::kBlack);
  }



  // color-interpolation
  EColorInterpolation ColorInterpolation() const {
    return static_cast<EColorInterpolation>(svginherited_data_->color_interpolation_);
  }

  void SetColorInterpolation(EColorInterpolation v) {
    if (!(svginherited_data_->color_interpolation_ == static_cast<unsigned>(v)))
      Access(svginherited_data_, access_.svginherited_data_)->color_interpolation_ = static_cast<unsigned>(v);
  }

  inline void ResetColorInterpolation() {
    Access(svginherited_data_, access_.svginherited_data_)->color_interpolation_ = static_cast<unsigned>(EColorInterpolation::kSRGB);
  }


  // color-interpolation-filters
  EColorInterpolation ColorInterpolationFilters() const {
    return static_cast<EColorInterpolation>(svginherited_data_->color_interpolation_filters_);
  }

  void SetColorInterpolationFilters(EColorInterpolation v) {
    if (!(svginherited_data_->color_interpolation_filters_ == static_cast<unsigned>(v)))
      Access(svginherited_data_, access_.svginherited_data_)->color_interpolation_filters_ = static_cast<unsigned>(v);
  }

  inline void ResetColorInterpolationFilters() {
    Access(svginherited_data_, access_.svginherited_data_)->color_interpolation_filters_ = static_cast<unsigned>(EColorInterpolation::kLinearrgb);
  }


  // ColorIsCurrentColor
  
  void SetColorIsCurrentColor(bool v) {
    if (!(inherited_data_->color_is_current_color_ == static_cast<unsigned>(v)))
      Access(inherited_data_, access_.inherited_data_)->color_is_current_color_ = static_cast<unsigned>(v);
  }

  inline void ResetColorIsCurrentColor() {
    Access(inherited_data_, access_.inherited_data_)->color_is_current_color_ = static_cast<unsigned>(true);
  }


  // color
  
  void SetColorIsInherited(bool v) {
    data_.color_is_inherited_ = static_cast<unsigned>(v);
  }

  inline void ResetColorIsInherited() {
    data_.color_is_inherited_ = static_cast<unsigned>(true);
  }


  // color-rendering
  EColorRendering ColorRendering() const {
    return static_cast<EColorRendering>(svginherited_data_->color_rendering_);
  }

  void SetColorRendering(EColorRendering v) {
    if (!(svginherited_data_->color_rendering_ == static_cast<unsigned>(v)))
      Access(svginherited_data_, access_.svginherited_data_)->color_rendering_ = static_cast<unsigned>(v);
  }

  inline void ResetColorRendering() {
    Access(svginherited_data_, access_.svginherited_data_)->color_rendering_ = static_cast<unsigned>(EColorRendering::kAuto);
  }


  // color-scheme
  const Vector<AtomicString>& ColorScheme() const {
    return misc_inherited_data_->misc_inherited_1_data_->color_scheme_;
  }

  void SetColorScheme(const Vector<AtomicString>& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->color_scheme_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->color_scheme_ = v;
  }

  void SetColorScheme(Vector<AtomicString>&& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->color_scheme_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->color_scheme_ = std::move(v);
  }

  inline void ResetColorScheme() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->color_scheme_ = Vector<AtomicString, 0>();
  }



  // ColorSchemeFlagsIsNormal
  bool ColorSchemeFlagsIsNormal() const {
    return static_cast<bool>(data_.color_scheme_flags_is_normal_);
  }

  void SetColorSchemeFlagsIsNormal(bool v) {
    data_.color_scheme_flags_is_normal_ = static_cast<unsigned>(v);
  }

  inline void ResetColorSchemeFlagsIsNormal() {
    data_.color_scheme_flags_is_normal_ = static_cast<unsigned>(false);
  }


  // ColorSchemeForced
  bool ColorSchemeForced() const {
    return static_cast<bool>(data_.color_scheme_forced_);
  }

  void SetColorSchemeForced(bool v) {
    data_.color_scheme_forced_ = static_cast<unsigned>(v);
  }

  inline void ResetColorSchemeForced() {
    data_.color_scheme_forced_ = static_cast<unsigned>(false);
  }


  // column-count
  unsigned short ColumnCount() const {
    return misc_data_->misc_1_data_->column_count_;
  }


  inline void ResetColumnCount() {
    Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_count_ = 1;
  }


  // column-fill
  EColumnFill GetColumnFill() const {
    return static_cast<EColumnFill>(misc_data_->column_fill_);
  }

  void SetColumnFill(EColumnFill v) {
    if (!(misc_data_->column_fill_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->column_fill_ = static_cast<unsigned>(v);
  }

  inline void ResetColumnFill() {
    Access(misc_data_, access_.misc_data_)->column_fill_ = static_cast<unsigned>(EColumnFill::kBalance);
  }


  // column-gap
  const std::optional<Length>& ColumnGap() const {
    return misc_data_->misc_1_data_->column_gap_;
  }

  void SetColumnGap(const std::optional<Length>& v) {
    if (!(misc_data_->misc_1_data_->column_gap_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_gap_ = v;
  }

  void SetColumnGap(std::optional<Length>&& v) {
    if (!(misc_data_->misc_1_data_->column_gap_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_gap_ = std::move(v);
  }

  inline void ResetColumnGap() {
    Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_gap_ = std::nullopt;
  }



  // column-height
  float ColumnHeight() const {
    return misc_data_->misc_1_data_->column_height_;
  }


  inline void ResetColumnHeight() {
    Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_height_ = 0.0f;
  }


  // column-rule-break
  RuleBreak ColumnRuleBreak() const {
    return static_cast<RuleBreak>(misc_data_->column_rule_break_);
  }

  void SetColumnRuleBreak(RuleBreak v) {
    if (!(misc_data_->column_rule_break_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->column_rule_break_ = static_cast<unsigned>(v);
  }

  inline void ResetColumnRuleBreak() {
    Access(misc_data_, access_.misc_data_)->column_rule_break_ = static_cast<unsigned>(RuleBreak::kNormal);
  }


  // column-rule-color
  const GapDataList<StyleColor>& ColumnRuleColor() const {
    return misc_data_->misc_1_data_->column_rule_color_;
  }



  inline void ResetColumnRuleColor() {
    Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_rule_color_ = GapDataList<StyleColor>::DefaultGapColorDataList();
  }



  // column-rule-inset-cap-end
  const Length& ColumnRuleInsetCapEnd() const {
    return misc_data_->misc_1_data_->column_rule_inset_cap_end_;
  }

  void SetColumnRuleInsetCapEnd(const Length& v) {
    if (!(misc_data_->misc_1_data_->column_rule_inset_cap_end_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_rule_inset_cap_end_ = v;
  }

  void SetColumnRuleInsetCapEnd(Length&& v) {
    if (!(misc_data_->misc_1_data_->column_rule_inset_cap_end_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_rule_inset_cap_end_ = std::move(v);
  }

  inline void ResetColumnRuleInsetCapEnd() {
    Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_rule_inset_cap_end_ = Length::Fixed(0);
  }



  // column-rule-inset-cap-start
  const Length& ColumnRuleInsetCapStart() const {
    return misc_data_->misc_1_data_->column_rule_inset_cap_start_;
  }

  void SetColumnRuleInsetCapStart(const Length& v) {
    if (!(misc_data_->misc_1_data_->column_rule_inset_cap_start_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_rule_inset_cap_start_ = v;
  }

  void SetColumnRuleInsetCapStart(Length&& v) {
    if (!(misc_data_->misc_1_data_->column_rule_inset_cap_start_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_rule_inset_cap_start_ = std::move(v);
  }

  inline void ResetColumnRuleInsetCapStart() {
    Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_rule_inset_cap_start_ = Length::Fixed(0);
  }



  // column-rule-inset-junction-end
  const Length& ColumnRuleInsetJunctionEnd() const {
    return misc_data_->misc_2_data_->column_rule_inset_junction_end_;
  }

  void SetColumnRuleInsetJunctionEnd(const Length& v) {
    if (!(misc_data_->misc_2_data_->column_rule_inset_junction_end_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_inset_junction_end_ = v;
  }

  void SetColumnRuleInsetJunctionEnd(Length&& v) {
    if (!(misc_data_->misc_2_data_->column_rule_inset_junction_end_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_inset_junction_end_ = std::move(v);
  }

  inline void ResetColumnRuleInsetJunctionEnd() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_inset_junction_end_ = Length::Fixed(0);
  }



  // column-rule-inset-junction-start
  const Length& ColumnRuleInsetJunctionStart() const {
    return misc_data_->misc_2_data_->column_rule_inset_junction_start_;
  }

  void SetColumnRuleInsetJunctionStart(const Length& v) {
    if (!(misc_data_->misc_2_data_->column_rule_inset_junction_start_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_inset_junction_start_ = v;
  }

  void SetColumnRuleInsetJunctionStart(Length&& v) {
    if (!(misc_data_->misc_2_data_->column_rule_inset_junction_start_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_inset_junction_start_ = std::move(v);
  }

  inline void ResetColumnRuleInsetJunctionStart() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_inset_junction_start_ = Length::Fixed(0);
  }



  // column-rule-style
  const GapDataList<EBorderStyle>& ColumnRuleStyle() const {
    return misc_data_->misc_2_data_->column_rule_style_;
  }



  inline void ResetColumnRuleStyle() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_style_ = GapDataList<EBorderStyle>::DefaultGapStyleDataList();
  }



  // column-rule-visibility-items
  RuleVisibilityItems ColumnRuleVisibilityItems() const {
    return static_cast<RuleVisibilityItems>(misc_data_->column_rule_visibility_items_);
  }

  void SetColumnRuleVisibilityItems(RuleVisibilityItems v) {
    if (!(misc_data_->column_rule_visibility_items_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->column_rule_visibility_items_ = static_cast<unsigned>(v);
  }

  inline void ResetColumnRuleVisibilityItems() {
    Access(misc_data_, access_.misc_data_)->column_rule_visibility_items_ = static_cast<unsigned>(RuleVisibilityItems::kNormal);
  }


  // column-rule-width
  const GapDataList<int>& ColumnRuleWidth() const {
    return misc_data_->misc_2_data_->column_rule_width_;
  }



  inline void ResetColumnRuleWidth() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_width_ = ComputedStyleInitialValues::InitialColumnRuleWidth();
  }



  // column-span
  EColumnSpan GetColumnSpan() const {
    return static_cast<EColumnSpan>(misc_data_->column_span_);
  }

  void SetColumnSpan(EColumnSpan v) {
    if (!(misc_data_->column_span_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->column_span_ = static_cast<unsigned>(v);
  }

  inline void ResetColumnSpan() {
    Access(misc_data_, access_.misc_data_)->column_span_ = static_cast<unsigned>(EColumnSpan::kNone);
  }


  // column-width
  float ColumnWidth() const {
    return misc_data_->misc_2_data_->column_width_;
  }


  inline void ResetColumnWidth() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_width_ = 0.0f;
  }


  // column-wrap
  EColumnWrap ColumnWrap() const {
    return static_cast<EColumnWrap>(misc_data_->column_wrap_);
  }

  void SetColumnWrap(EColumnWrap v) {
    if (!(misc_data_->column_wrap_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->column_wrap_ = static_cast<unsigned>(v);
  }

  inline void ResetColumnWrap() {
    Access(misc_data_, access_.misc_data_)->column_wrap_ = static_cast<unsigned>(EColumnWrap::kAuto);
  }


  // contain
  unsigned Contain() const {
    return static_cast<unsigned>(misc_data_->contain_);
  }

  void SetContain(unsigned v) {
    if (!(misc_data_->contain_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->contain_ = static_cast<unsigned>(v);
  }

  inline void ResetContain() {
    Access(misc_data_, access_.misc_data_)->contain_ = static_cast<unsigned>(kContainsNone);
  }


  // contain-intrinsic-height
  const StyleIntrinsicLength& ContainIntrinsicHeight() const {
    return surround_data_->contain_intrinsic_height_;
  }

  void SetContainIntrinsicHeight(const StyleIntrinsicLength& v) {
    if (!(surround_data_->contain_intrinsic_height_ == v))
      Access(surround_data_, access_.surround_data_)->contain_intrinsic_height_ = v;
  }

  void SetContainIntrinsicHeight(StyleIntrinsicLength&& v) {
    if (!(surround_data_->contain_intrinsic_height_ == v))
      Access(surround_data_, access_.surround_data_)->contain_intrinsic_height_ = std::move(v);
  }

  inline void ResetContainIntrinsicHeight() {
    Access(surround_data_, access_.surround_data_)->contain_intrinsic_height_ = StyleIntrinsicLength();
  }



  // contain-intrinsic-width
  const StyleIntrinsicLength& ContainIntrinsicWidth() const {
    return surround_data_->contain_intrinsic_width_;
  }

  void SetContainIntrinsicWidth(const StyleIntrinsicLength& v) {
    if (!(surround_data_->contain_intrinsic_width_ == v))
      Access(surround_data_, access_.surround_data_)->contain_intrinsic_width_ = v;
  }

  void SetContainIntrinsicWidth(StyleIntrinsicLength&& v) {
    if (!(surround_data_->contain_intrinsic_width_ == v))
      Access(surround_data_, access_.surround_data_)->contain_intrinsic_width_ = std::move(v);
  }

  inline void ResetContainIntrinsicWidth() {
    Access(surround_data_, access_.surround_data_)->contain_intrinsic_width_ = StyleIntrinsicLength();
  }



  // ContainerFont
  Font* ContainerFont() const {
    return inherited_data_->container_font_.Get();
  }

  void SetContainerFont(Member<Font> v) {
    if (!(inherited_data_->container_font_ == v))
      Access(inherited_data_, access_.inherited_data_)->container_font_ = std::move(v);
  }


  // container-name
  const Vector<AtomicString>& ContainerName() const {
    return misc_data_->misc_2_data_->container_name_;
  }

  void SetContainerName(const Vector<AtomicString>& v) {
    if (!(misc_data_->misc_2_data_->container_name_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->container_name_ = v;
  }

  void SetContainerName(Vector<AtomicString>&& v) {
    if (!(misc_data_->misc_2_data_->container_name_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->container_name_ = std::move(v);
  }

  inline void ResetContainerName() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->container_name_ = Vector<AtomicString>();
  }



  // container-type
  unsigned ContainerType() const {
    return static_cast<unsigned>(misc_data_->container_type_);
  }

  void SetContainerType(unsigned v) {
    if (!(misc_data_->container_type_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->container_type_ = static_cast<unsigned>(v);
  }

  inline void ResetContainerType() {
    Access(misc_data_, access_.misc_data_)->container_type_ = static_cast<unsigned>(kContainerTypeNormal);
  }


  // content
  
  void SetContent(const Member<ContentData>& v) {
    if (!(misc_data_->misc_2_data_->content_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->content_ = v;
  }

  void SetContent(Member<ContentData>&& v) {
    if (!(misc_data_->misc_2_data_->content_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->content_ = std::move(v);
  }

  inline void ResetContent() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->content_ = nullptr;
  }



  // content-visibility
  EContentVisibility ContentVisibility() const {
    return static_cast<EContentVisibility>(data_.content_visibility_);
  }

  void SetContentVisibility(EContentVisibility v) {
    data_.content_visibility_ = static_cast<unsigned>(v);
  }

  inline void ResetContentVisibility() {
    data_.content_visibility_ = static_cast<unsigned>(EContentVisibility::kVisible);
  }


  // Continue
  EContinue Continue() const {
    return static_cast<EContinue>(misc_data_->continue_);
  }

  void SetContinue(EContinue v) {
    if (!(misc_data_->continue_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->continue_ = static_cast<unsigned>(v);
  }

  inline void ResetContinue() {
    Access(misc_data_, access_.misc_data_)->continue_ = static_cast<unsigned>(EContinue::kNormal);
  }


  // corner-bottom-left-shape
  const Superellipse& CornerBottomLeftShape() const {
    return surround_data_->corner_bottom_left_shape_;
  }

  void SetCornerBottomLeftShape(const Superellipse& v) {
    if (!(surround_data_->corner_bottom_left_shape_ == v))
      Access(surround_data_, access_.surround_data_)->corner_bottom_left_shape_ = v;
  }

  void SetCornerBottomLeftShape(Superellipse&& v) {
    if (!(surround_data_->corner_bottom_left_shape_ == v))
      Access(surround_data_, access_.surround_data_)->corner_bottom_left_shape_ = std::move(v);
  }

  inline void ResetCornerBottomLeftShape() {
    Access(surround_data_, access_.surround_data_)->corner_bottom_left_shape_ = Superellipse::Round();
  }



  // corner-bottom-right-shape
  const Superellipse& CornerBottomRightShape() const {
    return surround_data_->corner_bottom_right_shape_;
  }

  void SetCornerBottomRightShape(const Superellipse& v) {
    if (!(surround_data_->corner_bottom_right_shape_ == v))
      Access(surround_data_, access_.surround_data_)->corner_bottom_right_shape_ = v;
  }

  void SetCornerBottomRightShape(Superellipse&& v) {
    if (!(surround_data_->corner_bottom_right_shape_ == v))
      Access(surround_data_, access_.surround_data_)->corner_bottom_right_shape_ = std::move(v);
  }

  inline void ResetCornerBottomRightShape() {
    Access(surround_data_, access_.surround_data_)->corner_bottom_right_shape_ = Superellipse::Round();
  }



  // corner-top-left-shape
  const Superellipse& CornerTopLeftShape() const {
    return surround_data_->corner_top_left_shape_;
  }

  void SetCornerTopLeftShape(const Superellipse& v) {
    if (!(surround_data_->corner_top_left_shape_ == v))
      Access(surround_data_, access_.surround_data_)->corner_top_left_shape_ = v;
  }

  void SetCornerTopLeftShape(Superellipse&& v) {
    if (!(surround_data_->corner_top_left_shape_ == v))
      Access(surround_data_, access_.surround_data_)->corner_top_left_shape_ = std::move(v);
  }

  inline void ResetCornerTopLeftShape() {
    Access(surround_data_, access_.surround_data_)->corner_top_left_shape_ = Superellipse::Round();
  }



  // corner-top-right-shape
  const Superellipse& CornerTopRightShape() const {
    return surround_data_->corner_top_right_shape_;
  }

  void SetCornerTopRightShape(const Superellipse& v) {
    if (!(surround_data_->corner_top_right_shape_ == v))
      Access(surround_data_, access_.surround_data_)->corner_top_right_shape_ = v;
  }

  void SetCornerTopRightShape(Superellipse&& v) {
    if (!(surround_data_->corner_top_right_shape_ == v))
      Access(surround_data_, access_.surround_data_)->corner_top_right_shape_ = std::move(v);
  }

  inline void ResetCornerTopRightShape() {
    Access(surround_data_, access_.surround_data_)->corner_top_right_shape_ = Superellipse::Round();
  }



  // CounterDirectives
  


  inline void ResetCounterDirectives() {
    Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->counter_directives_ = nullptr;
  }



  // CounterIncrementList
  CounterPropertyList* CounterIncrementList() const {
    return misc_data_->misc_7_data_->counter_increment_list_.get();
  }

  void SetCounterIncrementList(std::unique_ptr<CounterPropertyList> v) {
    if (!(misc_data_->misc_7_data_->counter_increment_list_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->counter_increment_list_ = std::move(v);
  }


  // CounterResetList
  CounterPropertyList* CounterResetList() const {
    return misc_data_->misc_7_data_->counter_reset_list_.get();
  }

  void SetCounterResetList(std::unique_ptr<CounterPropertyList> v) {
    if (!(misc_data_->misc_7_data_->counter_reset_list_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->counter_reset_list_ = std::move(v);
  }


  // CounterSetList
  CounterPropertyList* CounterSetList() const {
    return misc_data_->misc_7_data_->counter_set_list_.get();
  }

  void SetCounterSetList(std::unique_ptr<CounterPropertyList> v) {
    if (!(misc_data_->misc_7_data_->counter_set_list_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->counter_set_list_ = std::move(v);
  }


  // CssDominantBaseline
  EDominantBaseline CssDominantBaseline() const {
    return static_cast<EDominantBaseline>(svginherited_data_->css_dominant_baseline_);
  }

  void SetCssDominantBaseline(EDominantBaseline v) {
    if (!(svginherited_data_->css_dominant_baseline_ == static_cast<unsigned>(v)))
      Access(svginherited_data_, access_.svginherited_data_)->css_dominant_baseline_ = static_cast<unsigned>(v);
  }

  inline void ResetCssDominantBaseline() {
    Access(svginherited_data_, access_.svginherited_data_)->css_dominant_baseline_ = static_cast<unsigned>(EDominantBaseline::kAuto);
  }


  // cursor
  ECursor Cursor() const {
    return static_cast<ECursor>(inherited_data_->cursor_);
  }

  void SetCursor(ECursor v) {
    if (!(inherited_data_->cursor_ == static_cast<unsigned>(v)))
      Access(inherited_data_, access_.inherited_data_)->cursor_ = static_cast<unsigned>(v);
  }

  inline void ResetCursor() {
    Access(inherited_data_, access_.inherited_data_)->cursor_ = static_cast<unsigned>(ECursor::kAuto);
  }


  // CursorData
  


  inline void ResetCursorData() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->cursor_data_ = nullptr;
  }



  // cursor
  bool CursorIsInherited() const {
    return static_cast<bool>(data_.cursor_is_inherited_);
  }

  void SetCursorIsInherited(bool v) {
    data_.cursor_is_inherited_ = static_cast<unsigned>(v);
  }

  inline void ResetCursorIsInherited() {
    data_.cursor_is_inherited_ = static_cast<unsigned>(true);
  }


  // CustomHighlightNames
  


  inline void ResetCustomHighlightNames() {
    Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->custom_highlight_names_ = nullptr;
  }



  // CustomStyleCallbackDependsOnFont
  bool CustomStyleCallbackDependsOnFont() const {
    return static_cast<bool>(data_.custom_style_callback_depends_on_font_);
  }

  void SetCustomStyleCallbackDependsOnFont() {
    data_.custom_style_callback_depends_on_font_ = static_cast<unsigned>(true);
  }


  // cx
  const Length& Cx() const {
    return svg_data_->geometry_data_->cx_;
  }

  void SetCx(const Length& v) {
    if (!(svg_data_->geometry_data_->cx_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cx_ = v;
  }

  void SetCx(Length&& v) {
    if (!(svg_data_->geometry_data_->cx_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cx_ = std::move(v);
  }

  inline void ResetCx() {
    Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cx_ = Length::Fixed();
  }



  // cy
  const Length& Cy() const {
    return svg_data_->geometry_data_->cy_;
  }

  void SetCy(const Length& v) {
    if (!(svg_data_->geometry_data_->cy_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cy_ = v;
  }

  void SetCy(Length&& v) {
    if (!(svg_data_->geometry_data_->cy_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cy_ = std::move(v);
  }

  inline void ResetCy() {
    Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cy_ = Length::Fixed();
  }



  // d
  StylePath* D() const {
    return svg_data_->geometry_data_->d_.Get();
  }

  void SetD(Member<StylePath> v) {
    if (!(svg_data_->geometry_data_->d_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->d_ = std::move(v);
  }


  // DarkColorScheme
  bool DarkColorScheme() const {
    return static_cast<bool>(data_.dark_color_scheme_);
  }

  void SetDarkColorScheme(bool v) {
    data_.dark_color_scheme_ = static_cast<unsigned>(v);
  }

  inline void ResetDarkColorScheme() {
    data_.dark_color_scheme_ = static_cast<unsigned>(false);
  }


  // DependsOnAnchoredContainerQueries
  bool DependsOnAnchoredContainerQueries() const {
    return static_cast<bool>(misc_data_->depends_on_anchored_container_queries_);
  }

  void SetDependsOnAnchoredContainerQueries(bool v) {
    if (!(misc_data_->depends_on_anchored_container_queries_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->depends_on_anchored_container_queries_ = static_cast<unsigned>(v);
  }

  inline void ResetDependsOnAnchoredContainerQueries() {
    Access(misc_data_, access_.misc_data_)->depends_on_anchored_container_queries_ = static_cast<unsigned>(false);
  }


  // DependsOnScrollStateContainerQueries
  bool DependsOnScrollStateContainerQueries() const {
    return static_cast<bool>(misc_data_->depends_on_scroll_state_container_queries_);
  }

  void SetDependsOnScrollStateContainerQueries(bool v) {
    if (!(misc_data_->depends_on_scroll_state_container_queries_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->depends_on_scroll_state_container_queries_ = static_cast<unsigned>(v);
  }

  inline void ResetDependsOnScrollStateContainerQueries() {
    Access(misc_data_, access_.misc_data_)->depends_on_scroll_state_container_queries_ = static_cast<unsigned>(false);
  }


  // DependsOnSizeContainerQueries
  bool DependsOnSizeContainerQueries() const {
    return static_cast<bool>(misc_data_->depends_on_size_container_queries_);
  }

  void SetDependsOnSizeContainerQueries(bool v) {
    if (!(misc_data_->depends_on_size_container_queries_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->depends_on_size_container_queries_ = static_cast<unsigned>(v);
  }

  inline void ResetDependsOnSizeContainerQueries() {
    Access(misc_data_, access_.misc_data_)->depends_on_size_container_queries_ = static_cast<unsigned>(false);
  }


  // DependsOnStyleContainerQueries
  bool DependsOnStyleContainerQueries() const {
    return static_cast<bool>(misc_data_->depends_on_style_container_queries_);
  }

  void SetDependsOnStyleContainerQueries(bool v) {
    if (!(misc_data_->depends_on_style_container_queries_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->depends_on_style_container_queries_ = static_cast<unsigned>(v);
  }

  inline void ResetDependsOnStyleContainerQueries() {
    Access(misc_data_, access_.misc_data_)->depends_on_style_container_queries_ = static_cast<unsigned>(false);
  }


  // direction
  TextDirection Direction() const {
    return static_cast<TextDirection>(data_.direction_);
  }

  void SetDirection(TextDirection v) {
    data_.direction_ = static_cast<unsigned>(v);
  }

  inline void ResetDirection() {
    data_.direction_ = static_cast<unsigned>(TextDirection::kLtr);
  }


  // Display
  EDisplay Display() const {
    return static_cast<EDisplay>(data_.display_);
  }

  void SetDisplay(EDisplay v) {
    data_.display_ = static_cast<unsigned>(v);
  }

  inline void ResetDisplay() {
    data_.display_ = static_cast<unsigned>(EDisplay::kInline);
  }


  // DisplayLayoutCustomName
  const AtomicString& DisplayLayoutCustomName() const {
    return misc_data_->misc_7_data_->display_layout_custom_name_;
  }

  void SetDisplayLayoutCustomName(const AtomicString& v) {
    if (!(misc_data_->misc_7_data_->display_layout_custom_name_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->display_layout_custom_name_ = v;
  }

  void SetDisplayLayoutCustomName(AtomicString&& v) {
    if (!(misc_data_->misc_7_data_->display_layout_custom_name_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->display_layout_custom_name_ = std::move(v);
  }

  inline void ResetDisplayLayoutCustomName() {
    Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->display_layout_custom_name_ = g_null_atom;
  }



  // DisplayLayoutCustomParentName
  const AtomicString& DisplayLayoutCustomParentName() const {
    return misc_data_->misc_7_data_->display_layout_custom_parent_name_;
  }

  void SetDisplayLayoutCustomParentName(const AtomicString& v) {
    if (!(misc_data_->misc_7_data_->display_layout_custom_parent_name_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->display_layout_custom_parent_name_ = v;
  }

  void SetDisplayLayoutCustomParentName(AtomicString&& v) {
    if (!(misc_data_->misc_7_data_->display_layout_custom_parent_name_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->display_layout_custom_parent_name_ = std::move(v);
  }

  inline void ResetDisplayLayoutCustomParentName() {
    Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->display_layout_custom_parent_name_ = g_null_atom;
  }



  // DocumentRulesSelectors
  const Member<GCedHeapHashSet<WeakMember<StyleRule>>>& DocumentRulesSelectors() const {
    return misc_data_->misc_8_data_->document_rules_selectors_;
  }



  inline void ResetDocumentRulesSelectors() {
    Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->document_rules_selectors_ = nullptr;
  }



  // dominant-baseline
  EDominantBaseline DominantBaseline() const {
    return static_cast<EDominantBaseline>(svginherited_data_->dominant_baseline_);
  }

  void SetDominantBaseline(EDominantBaseline v) {
    if (!(svginherited_data_->dominant_baseline_ == static_cast<unsigned>(v)))
      Access(svginherited_data_, access_.svginherited_data_)->dominant_baseline_ = static_cast<unsigned>(v);
  }

  inline void ResetDominantBaseline() {
    Access(svginherited_data_, access_.svginherited_data_)->dominant_baseline_ = static_cast<unsigned>(EDominantBaseline::kAuto);
  }


  // window-drag
  EDraggableRegionMode DraggableRegionMode() const {
    return static_cast<EDraggableRegionMode>(misc_inherited_data_->draggable_region_mode_);
  }

  void SetDraggableRegionMode(EDraggableRegionMode v) {
    if (!(misc_inherited_data_->draggable_region_mode_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->draggable_region_mode_ = static_cast<unsigned>(v);
  }

  inline void ResetDraggableRegionMode() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->draggable_region_mode_ = static_cast<unsigned>(EDraggableRegionMode::kNone);
  }


  // dynamic-range-limit
  const DynamicRangeLimit& GetDynamicRangeLimit() const {
    return misc_inherited_data_->misc_inherited_1_data_->dynamic_range_limit_;
  }

  void SetDynamicRangeLimit(const DynamicRangeLimit& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->dynamic_range_limit_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->dynamic_range_limit_ = v;
  }

  void SetDynamicRangeLimit(DynamicRangeLimit&& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->dynamic_range_limit_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->dynamic_range_limit_ = std::move(v);
  }

  inline void ResetDynamicRangeLimit() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->dynamic_range_limit_ = DynamicRangeLimit(cc::PaintFlags::DynamicRangeLimit::kHigh);
  }



  // EffectiveAppearance
  AppearanceValue EffectiveAppearance() const {
    return static_cast<AppearanceValue>(misc_data_->effective_appearance_);
  }

  void SetEffectiveAppearance(AppearanceValue v) {
    if (!(misc_data_->effective_appearance_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->effective_appearance_ = static_cast<unsigned>(v);
  }

  inline void ResetEffectiveAppearance() {
    Access(misc_data_, access_.misc_data_)->effective_appearance_ = static_cast<unsigned>(AppearanceValue::kNone);
  }


  // EffectiveTouchAction
  TouchAction EffectiveTouchAction() const {
    return static_cast<TouchAction>(misc_inherited_data_->misc_inherited_2_data_->effective_touch_action_);
  }

  void SetEffectiveTouchAction(TouchAction v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->effective_touch_action_ == static_cast<unsigned>(v)))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->effective_touch_action_ = static_cast<unsigned>(v);
  }

  inline void ResetEffectiveTouchAction() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->effective_touch_action_ = static_cast<unsigned>(TouchAction::kAuto);
  }


  // EffectiveZoom
  float EffectiveZoom() const {
    return misc_inherited_data_->misc_inherited_2_data_->effective_zoom_;
  }


  inline void ResetEffectiveZoom() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->effective_zoom_ = 1.0f;
  }


  // ElementIsViewTransitionParticipant
  bool ElementIsViewTransitionParticipant() const {
    return static_cast<bool>(misc_data_->element_is_view_transition_participant_);
  }

  void SetElementIsViewTransitionParticipant() {
    if (!(misc_data_->element_is_view_transition_participant_ == static_cast<unsigned>(true)))
      Access(misc_data_, access_.misc_data_)->element_is_view_transition_participant_ = static_cast<unsigned>(true);
  }


  // empty-cells
  EEmptyCells EmptyCells() const {
    return static_cast<EEmptyCells>(misc_inherited_data_->empty_cells_);
  }

  void SetEmptyCells(EEmptyCells v) {
    if (!(misc_inherited_data_->empty_cells_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->empty_cells_ = static_cast<unsigned>(v);
  }

  inline void ResetEmptyCells() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->empty_cells_ = static_cast<unsigned>(EEmptyCells::kShow);
  }


  // empty-cells
  bool EmptyCellsIsInherited() const {
    return static_cast<bool>(data_.empty_cells_is_inherited_);
  }

  void SetEmptyCellsIsInherited(bool v) {
    data_.empty_cells_is_inherited_ = static_cast<unsigned>(v);
  }

  inline void ResetEmptyCellsIsInherited() {
    data_.empty_cells_is_inherited_ = static_cast<unsigned>(true);
  }


  // field-sizing
  EFieldSizing FieldSizing() const {
    return static_cast<EFieldSizing>(visual_data_->field_sizing_);
  }

  void SetFieldSizing(EFieldSizing v) {
    if (!(visual_data_->field_sizing_ == static_cast<unsigned>(v)))
      Access(visual_data_, access_.visual_data_)->field_sizing_ = static_cast<unsigned>(v);
  }

  inline void ResetFieldSizing() {
    Access(visual_data_, access_.visual_data_)->field_sizing_ = static_cast<unsigned>(EFieldSizing::kFixed);
  }


  // fill-opacity
  float FillOpacity() const {
    return svginherited_data_->fill_data_->fill_opacity_;
  }

  void SetFillOpacity(float v) {
    if (!(svginherited_data_->fill_data_->fill_opacity_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->fill_data_, access_.fill_data_)->fill_opacity_ = v;
  }

  inline void ResetFillOpacity() {
    Access(Access(svginherited_data_, access_.svginherited_data_)->fill_data_, access_.fill_data_)->fill_opacity_ = 1;
  }


  // fill
  const SVGPaint& FillPaint() const {
    return svginherited_data_->fill_data_->fill_paint_;
  }

  void SetFillPaint(const SVGPaint& v) {
    if (!(svginherited_data_->fill_data_->fill_paint_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->fill_data_, access_.fill_data_)->fill_paint_ = v;
  }

  void SetFillPaint(SVGPaint&& v) {
    if (!(svginherited_data_->fill_data_->fill_paint_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->fill_data_, access_.fill_data_)->fill_paint_ = std::move(v);
  }

  inline void ResetFillPaint() {
    Access(Access(svginherited_data_, access_.svginherited_data_)->fill_data_, access_.fill_data_)->fill_paint_ = SVGPaint::CreateInitialBlack();
  }



  // fill-rule
  WindRule FillRule() const {
    return static_cast<WindRule>(svginherited_data_->fill_rule_);
  }

  void SetFillRule(WindRule v) {
    if (!(svginherited_data_->fill_rule_ == static_cast<unsigned>(v)))
      Access(svginherited_data_, access_.svginherited_data_)->fill_rule_ = static_cast<unsigned>(v);
  }

  inline void ResetFillRule() {
    Access(svginherited_data_, access_.svginherited_data_)->fill_rule_ = static_cast<unsigned>(RULE_NONZERO);
  }


  // filter
  const FilterOperations& Filter() const {
    return misc_data_->misc_2_data_->filter_;
  }

  void SetFilter(const FilterOperations& v) {
    if (!(misc_data_->misc_2_data_->filter_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->filter_ = v;
  }

  void SetFilter(FilterOperations&& v) {
    if (!(misc_data_->misc_2_data_->filter_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->filter_ = std::move(v);
  }

  inline void ResetFilter() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->filter_ = FilterOperations();
  }



  // FirstLineDependsOnSizeContainerQueries
  bool FirstLineDependsOnSizeContainerQueries() const {
    return static_cast<bool>(misc_data_->first_line_depends_on_size_container_queries_);
  }

  void SetFirstLineDependsOnSizeContainerQueries(bool v) {
    if (!(misc_data_->first_line_depends_on_size_container_queries_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->first_line_depends_on_size_container_queries_ = static_cast<unsigned>(v);
  }

  inline void ResetFirstLineDependsOnSizeContainerQueries() {
    Access(misc_data_, access_.misc_data_)->first_line_depends_on_size_container_queries_ = static_cast<unsigned>(false);
  }


  // flex-basis
  const Length& FlexBasis() const {
    return misc_data_->misc_2_data_->flex_basis_;
  }

  void SetFlexBasis(const Length& v) {
    if (!(misc_data_->misc_2_data_->flex_basis_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_basis_ = v;
  }

  void SetFlexBasis(Length&& v) {
    if (!(misc_data_->misc_2_data_->flex_basis_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_basis_ = std::move(v);
  }

  inline void ResetFlexBasis() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_basis_ = Length::Auto();
  }



  // flex-direction
  EFlexDirection FlexDirection() const {
    return static_cast<EFlexDirection>(misc_data_->flex_direction_);
  }

  void SetFlexDirection(EFlexDirection v) {
    if (!(misc_data_->flex_direction_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->flex_direction_ = static_cast<unsigned>(v);
  }

  inline void ResetFlexDirection() {
    Access(misc_data_, access_.misc_data_)->flex_direction_ = static_cast<unsigned>(EFlexDirection::kRow);
  }


  // flex-grow
  float FlexGrow() const {
    return misc_data_->misc_2_data_->flex_grow_;
  }

  void SetFlexGrow(float v) {
    if (!(misc_data_->misc_2_data_->flex_grow_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_grow_ = v;
  }

  inline void ResetFlexGrow() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_grow_ = 0.0f;
  }


  // flex-line-count
  uint16_t FlexLineCount() const {
    return misc_data_->misc_2_data_->flex_line_count_;
  }

  void SetFlexLineCount(uint16_t v) {
    if (!(misc_data_->misc_2_data_->flex_line_count_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_line_count_ = v;
  }

  inline void ResetFlexLineCount() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_line_count_ = 1u;
  }


  // flex-shrink
  float FlexShrink() const {
    return misc_data_->misc_2_data_->flex_shrink_;
  }

  void SetFlexShrink(float v) {
    if (!(misc_data_->misc_2_data_->flex_shrink_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_shrink_ = v;
  }

  inline void ResetFlexShrink() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_shrink_ = 1.0f;
  }


  // flex-wrap
  const StyleFlexWrapData& FlexWrap() const {
    return misc_data_->misc_2_data_->flex_wrap_;
  }

  void SetFlexWrap(const StyleFlexWrapData& v) {
    if (!(misc_data_->misc_2_data_->flex_wrap_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_wrap_ = v;
  }

  void SetFlexWrap(StyleFlexWrapData&& v) {
    if (!(misc_data_->misc_2_data_->flex_wrap_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_wrap_ = std::move(v);
  }

  inline void ResetFlexWrap() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_wrap_ = StyleFlexWrapData(FlexWrapMode::kNowrap);
  }



  // float
  
  void SetFloating(EFloat v) {
    data_.floating_ = static_cast<unsigned>(v);
  }

  inline void ResetFloating() {
    data_.floating_ = static_cast<unsigned>(EFloat::kNone);
  }


  // flood-color
  const StyleColor& FloodColor() const {
    return svg_data_->svgmisc_data_->flood_color_;
  }

  void SetFloodColor(const StyleColor& v) {
    if (!(svg_data_->svgmisc_data_->flood_color_ == v))
      Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->flood_color_ = v;
  }

  void SetFloodColor(StyleColor&& v) {
    if (!(svg_data_->svgmisc_data_->flood_color_ == v))
      Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->flood_color_ = std::move(v);
  }

  inline void ResetFloodColor() {
    Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->flood_color_ = StyleColor(Color::kBlack);
  }



  // flood-opacity
  float FloodOpacity() const {
    return svg_data_->svgmisc_data_->flood_opacity_;
  }

  void SetFloodOpacity(float v) {
    if (!(svg_data_->svgmisc_data_->flood_opacity_ == v))
      Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->flood_opacity_ = v;
  }

  inline void ResetFloodOpacity() {
    Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->flood_opacity_ = 1;
  }


  // flow-tolerance
  const FlowTolerance& GetFlowTolerance() const {
    return misc_data_->misc_2_data_->flow_tolerance_;
  }

  void SetFlowTolerance(const FlowTolerance& v) {
    if (!(misc_data_->misc_2_data_->flow_tolerance_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flow_tolerance_ = v;
  }

  void SetFlowTolerance(FlowTolerance&& v) {
    if (!(misc_data_->misc_2_data_->flow_tolerance_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flow_tolerance_ = std::move(v);
  }

  inline void ResetFlowTolerance() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flow_tolerance_ = FlowTolerance(CSSValueID::kNormal);
  }



  // font
  Font* GetFont() const {
    return inherited_data_->font_.Get();
  }

  void SetFont(Member<Font> v) {
    if (!(inherited_data_->font_ == v))
      Access(inherited_data_, access_.inherited_data_)->font_ = std::move(v);
  }


  // forced-color-adjust
  EForcedColorAdjust ForcedColorAdjust() const {
    return static_cast<EForcedColorAdjust>(misc_inherited_data_->forced_color_adjust_);
  }

  void SetForcedColorAdjust(EForcedColorAdjust v) {
    if (!(misc_inherited_data_->forced_color_adjust_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->forced_color_adjust_ = static_cast<unsigned>(v);
  }

  inline void ResetForcedColorAdjust() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->forced_color_adjust_ = static_cast<unsigned>(EForcedColorAdjust::kAuto);
  }


  // ForcesBlockifiesChildren
  bool ForcesBlockifiesChildren() const {
    return static_cast<bool>(misc_data_->forces_blockifies_children_);
  }

  void SetForcesBlockifiesChildren() {
    if (!(misc_data_->forces_blockifies_children_ == static_cast<unsigned>(true)))
      Access(misc_data_, access_.misc_data_)->forces_blockifies_children_ = static_cast<unsigned>(true);
  }


  // ForcesStackingContext
  bool ForcesStackingContext() const {
    return static_cast<bool>(data_.forces_stacking_context_);
  }

  void SetForcesStackingContext(bool v) {
    data_.forces_stacking_context_ = static_cast<unsigned>(v);
  }

  inline void ResetForcesStackingContext() {
    data_.forces_stacking_context_ = static_cast<unsigned>(false);
  }


  // frame-sizing
  EFrameSizing FrameSizing() const {
    return static_cast<EFrameSizing>(surround_data_->frame_sizing_);
  }

  void SetFrameSizing(EFrameSizing v) {
    if (!(surround_data_->frame_sizing_ == static_cast<unsigned>(v)))
      Access(surround_data_, access_.surround_data_)->frame_sizing_ = static_cast<unsigned>(v);
  }

  inline void ResetFrameSizing() {
    Access(surround_data_, access_.surround_data_)->frame_sizing_ = static_cast<unsigned>(EFrameSizing::kAuto);
  }


  // grid-auto-columns
  const GridTrackList& GridAutoColumns() const {
    return misc_data_->misc_2_data_->grid_auto_columns_;
  }

  void SetGridAutoColumns(const GridTrackList& v) {
    if (!(misc_data_->misc_2_data_->grid_auto_columns_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->grid_auto_columns_ = v;
  }

  void SetGridAutoColumns(GridTrackList&& v) {
    if (!(misc_data_->misc_2_data_->grid_auto_columns_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->grid_auto_columns_ = std::move(v);
  }

  inline void ResetGridAutoColumns() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->grid_auto_columns_ = GridTrackList(GridTrackSize(Length::Auto()));
  }



  // grid-auto-flow
  
  void SetGridAutoFlow(GridAutoFlow v) {
    if (!(misc_data_->grid_auto_flow_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->grid_auto_flow_ = static_cast<unsigned>(v);
  }

  inline void ResetGridAutoFlow() {
    Access(misc_data_, access_.misc_data_)->grid_auto_flow_ = static_cast<unsigned>(kAutoFlowRow);
  }


  // grid-auto-rows
  const GridTrackList& GridAutoRows() const {
    return misc_data_->misc_2_data_->grid_auto_rows_;
  }

  void SetGridAutoRows(const GridTrackList& v) {
    if (!(misc_data_->misc_2_data_->grid_auto_rows_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->grid_auto_rows_ = v;
  }

  void SetGridAutoRows(GridTrackList&& v) {
    if (!(misc_data_->misc_2_data_->grid_auto_rows_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->grid_auto_rows_ = std::move(v);
  }

  inline void ResetGridAutoRows() {
    Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->grid_auto_rows_ = GridTrackList(GridTrackSize(Length::Auto()));
  }



  // grid-column-end
  const GridPosition& GridColumnEnd() const {
    return misc_data_->misc_3_data_->grid_column_end_;
  }

  void SetGridColumnEnd(const GridPosition& v) {
    if (!(misc_data_->misc_3_data_->grid_column_end_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_column_end_ = v;
  }

  void SetGridColumnEnd(GridPosition&& v) {
    if (!(misc_data_->misc_3_data_->grid_column_end_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_column_end_ = std::move(v);
  }

  inline void ResetGridColumnEnd() {
    Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_column_end_ = GridPosition();
  }



  // grid-column-start
  const GridPosition& GridColumnStart() const {
    return misc_data_->misc_3_data_->grid_column_start_;
  }

  void SetGridColumnStart(const GridPosition& v) {
    if (!(misc_data_->misc_3_data_->grid_column_start_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_column_start_ = v;
  }

  void SetGridColumnStart(GridPosition&& v) {
    if (!(misc_data_->misc_3_data_->grid_column_start_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_column_start_ = std::move(v);
  }

  inline void ResetGridColumnStart() {
    Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_column_start_ = GridPosition();
  }



  // grid-lanes-direction
  const GridLanesDirection& GetGridLanesDirection() const {
    return misc_data_->misc_3_data_->grid_lanes_direction_;
  }

  void SetGridLanesDirection(const GridLanesDirection& v) {
    if (!(misc_data_->misc_3_data_->grid_lanes_direction_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_lanes_direction_ = v;
  }

  void SetGridLanesDirection(GridLanesDirection&& v) {
    if (!(misc_data_->misc_3_data_->grid_lanes_direction_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_lanes_direction_ = std::move(v);
  }

  inline void ResetGridLanesDirection() {
    Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_lanes_direction_ = GridLanesDirection();
  }



  // grid-lanes-pack
  EGridLanesPack GridLanesPack() const {
    return static_cast<EGridLanesPack>(misc_data_->grid_lanes_pack_);
  }

  void SetGridLanesPack(EGridLanesPack v) {
    if (!(misc_data_->grid_lanes_pack_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->grid_lanes_pack_ = static_cast<unsigned>(v);
  }

  inline void ResetGridLanesPack() {
    Access(misc_data_, access_.misc_data_)->grid_lanes_pack_ = static_cast<unsigned>(EGridLanesPack::kNormal);
  }


  // grid-row-end
  const GridPosition& GridRowEnd() const {
    return misc_data_->misc_3_data_->grid_row_end_;
  }

  void SetGridRowEnd(const GridPosition& v) {
    if (!(misc_data_->misc_3_data_->grid_row_end_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_row_end_ = v;
  }

  void SetGridRowEnd(GridPosition&& v) {
    if (!(misc_data_->misc_3_data_->grid_row_end_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_row_end_ = std::move(v);
  }

  inline void ResetGridRowEnd() {
    Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_row_end_ = GridPosition();
  }



  // grid-row-start
  const GridPosition& GridRowStart() const {
    return misc_data_->misc_3_data_->grid_row_start_;
  }

  void SetGridRowStart(const GridPosition& v) {
    if (!(misc_data_->misc_3_data_->grid_row_start_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_row_start_ = v;
  }

  void SetGridRowStart(GridPosition&& v) {
    if (!(misc_data_->misc_3_data_->grid_row_start_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_row_start_ = std::move(v);
  }

  inline void ResetGridRowStart() {
    Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_row_start_ = GridPosition();
  }



  // grid-template-areas
  const Member<ComputedGridTemplateAreas>& GridTemplateAreas() const {
    return misc_data_->misc_3_data_->grid_template_areas_;
  }

  void SetGridTemplateAreas(const Member<ComputedGridTemplateAreas>& v) {
    if (!(misc_data_->misc_3_data_->grid_template_areas_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_template_areas_ = v;
  }

  void SetGridTemplateAreas(Member<ComputedGridTemplateAreas>&& v) {
    if (!(misc_data_->misc_3_data_->grid_template_areas_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_template_areas_ = std::move(v);
  }

  inline void ResetGridTemplateAreas() {
    Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_template_areas_ = nullptr;
  }



  // grid-template-columns
  const Member<ComputedGridTrackList>& SpecifiedGridTemplateColumns() const {
    return misc_data_->misc_3_data_->grid_template_columns_;
  }

  void SetGridTemplateColumns(const Member<ComputedGridTrackList>& v) {
    if (!(misc_data_->misc_3_data_->grid_template_columns_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_template_columns_ = v;
  }

  void SetGridTemplateColumns(Member<ComputedGridTrackList>&& v) {
    if (!(misc_data_->misc_3_data_->grid_template_columns_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_template_columns_ = std::move(v);
  }

  inline void ResetGridTemplateColumns() {
    Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_template_columns_ = nullptr;
  }



  // grid-template-rows
  const Member<ComputedGridTrackList>& SpecifiedGridTemplateRows() const {
    return misc_data_->misc_3_data_->grid_template_rows_;
  }

  void SetGridTemplateRows(const Member<ComputedGridTrackList>& v) {
    if (!(misc_data_->misc_3_data_->grid_template_rows_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_template_rows_ = v;
  }

  void SetGridTemplateRows(Member<ComputedGridTrackList>&& v) {
    if (!(misc_data_->misc_3_data_->grid_template_rows_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_template_rows_ = std::move(v);
  }

  inline void ResetGridTemplateRows() {
    Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_template_rows_ = nullptr;
  }



  // hanging-punctuation
  HangingPunctuation GetHangingPunctuation() const {
    return static_cast<HangingPunctuation>(misc_inherited_data_->hanging_punctuation_);
  }

  void SetHangingPunctuation(HangingPunctuation v) {
    if (!(misc_inherited_data_->hanging_punctuation_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->hanging_punctuation_ = static_cast<unsigned>(v);
  }

  inline void ResetHangingPunctuation() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->hanging_punctuation_ = static_cast<unsigned>(HangingPunctuation::kNone);
  }


  // HasAnchorEvaluator
  bool HasAnchorEvaluator() const {
    return static_cast<bool>(surround_data_->has_anchor_evaluator_);
  }

  void SetHasAnchorEvaluator() {
    if (!(surround_data_->has_anchor_evaluator_ == static_cast<unsigned>(true)))
      Access(surround_data_, access_.surround_data_)->has_anchor_evaluator_ = static_cast<unsigned>(true);
  }


  // HasAnchorFunctions
  bool HasAnchorFunctions() const {
    return static_cast<bool>(surround_data_->has_anchor_functions_);
  }

  void SetHasAnchorFunctions() {
    if (!(surround_data_->has_anchor_functions_ == static_cast<unsigned>(true)))
      Access(surround_data_, access_.surround_data_)->has_anchor_functions_ = static_cast<unsigned>(true);
  }


  // HasAttrFunction
  bool HasAttrFunction() const {
    return static_cast<bool>(data_.has_attr_function_);
  }

  void SetHasAttrFunction() {
    data_.has_attr_function_ = static_cast<unsigned>(true);
  }


  // HasAuthorBackground
  bool HasAuthorBackground() const {
    return static_cast<bool>(data_.has_author_background_);
  }

  void SetHasAuthorBackground() {
    data_.has_author_background_ = static_cast<unsigned>(true);
  }


  // HasAuthorBorder
  bool HasAuthorBorder() const {
    return static_cast<bool>(data_.has_author_border_);
  }

  void SetHasAuthorBorder() {
    data_.has_author_border_ = static_cast<unsigned>(true);
  }


  // HasAuthorBorderRadius
  bool HasAuthorBorderRadius() const {
    return static_cast<bool>(data_.has_author_border_radius_);
  }

  void SetHasAuthorBorderRadius() {
    data_.has_author_border_radius_ = static_cast<unsigned>(true);
  }


  // HasAuthorHighlightColors
  bool HasAuthorHighlightColors() const {
    return static_cast<bool>(data_.has_author_highlight_colors_);
  }

  void SetHasAuthorHighlightColors() {
    data_.has_author_highlight_colors_ = static_cast<unsigned>(true);
  }


  // HasAutoClip
  bool HasAutoClip() const {
    return static_cast<bool>(visual_data_->has_auto_clip_);
  }


  inline void ResetHasAutoClip() {
    Access(visual_data_, access_.visual_data_)->has_auto_clip_ = static_cast<unsigned>(true);
  }


  // HasAutoColumnCount
  bool HasAutoColumnCount() const {
    return static_cast<bool>(misc_data_->has_auto_column_count_);
  }


  inline void ResetHasAutoColumnCount() {
    Access(misc_data_, access_.misc_data_)->has_auto_column_count_ = static_cast<unsigned>(true);
  }


  // HasAutoColumnHeight
  bool HasAutoColumnHeight() const {
    return static_cast<bool>(misc_data_->has_auto_column_height_);
  }


  inline void ResetHasAutoColumnHeight() {
    Access(misc_data_, access_.misc_data_)->has_auto_column_height_ = static_cast<unsigned>(true);
  }


  // HasAutoColumnWidth
  bool HasAutoColumnWidth() const {
    return static_cast<bool>(misc_data_->has_auto_column_width_);
  }


  inline void ResetHasAutoColumnWidth() {
    Access(misc_data_, access_.misc_data_)->has_auto_column_width_ = static_cast<unsigned>(true);
  }


  // HasAutoZIndex
  bool HasAutoZIndex() const {
    return static_cast<bool>(box_data_->has_auto_z_index_);
  }


  inline void ResetHasAutoZIndex() {
    Access(box_data_, access_.box_data_)->has_auto_z_index_ = static_cast<unsigned>(true);
  }


  // HasClipPath
  bool HasClipPath() const {
    return static_cast<bool>(visual_data_->has_clip_path_);
  }

  void SetHasClipPath(bool v) {
    if (!(visual_data_->has_clip_path_ == static_cast<unsigned>(v)))
      Access(visual_data_, access_.visual_data_)->has_clip_path_ = static_cast<unsigned>(v);
  }

  inline void ResetHasClipPath() {
    Access(visual_data_, access_.visual_data_)->has_clip_path_ = static_cast<unsigned>(false);
  }


  // HasContainerRelativeValue
  bool HasContainerRelativeValue() const {
    return static_cast<bool>(data_.has_container_relative_value_);
  }

  void SetHasContainerRelativeValue() {
    data_.has_container_relative_value_ = static_cast<unsigned>(true);
  }


  // HasCurrentBackdropFilterAnimation
  bool HasCurrentBackdropFilterAnimation() const {
    return static_cast<bool>(misc_data_->has_current_backdrop_filter_animation_);
  }

  void SetHasCurrentBackdropFilterAnimation(bool v) {
    if (!(misc_data_->has_current_backdrop_filter_animation_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_current_backdrop_filter_animation_ = static_cast<unsigned>(v);
  }

  inline void ResetHasCurrentBackdropFilterAnimation() {
    Access(misc_data_, access_.misc_data_)->has_current_backdrop_filter_animation_ = static_cast<unsigned>(false);
  }


  // HasCurrentBackgroundColorAnimation
  bool HasCurrentBackgroundColorAnimation() const {
    return static_cast<bool>(misc_data_->has_current_background_color_animation_);
  }

  void SetHasCurrentBackgroundColorAnimation(bool v) {
    if (!(misc_data_->has_current_background_color_animation_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_current_background_color_animation_ = static_cast<unsigned>(v);
  }

  inline void ResetHasCurrentBackgroundColorAnimation() {
    Access(misc_data_, access_.misc_data_)->has_current_background_color_animation_ = static_cast<unsigned>(false);
  }


  // HasCurrentClipPathAnimation
  bool HasCurrentClipPathAnimation() const {
    return static_cast<bool>(misc_data_->has_current_clip_path_animation_);
  }

  void SetHasCurrentClipPathAnimation(bool v) {
    if (!(misc_data_->has_current_clip_path_animation_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_current_clip_path_animation_ = static_cast<unsigned>(v);
  }

  inline void ResetHasCurrentClipPathAnimation() {
    Access(misc_data_, access_.misc_data_)->has_current_clip_path_animation_ = static_cast<unsigned>(false);
  }


  // HasCurrentFilterAnimation
  bool HasCurrentFilterAnimation() const {
    return static_cast<bool>(misc_data_->has_current_filter_animation_);
  }

  void SetHasCurrentFilterAnimation(bool v) {
    if (!(misc_data_->has_current_filter_animation_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_current_filter_animation_ = static_cast<unsigned>(v);
  }

  inline void ResetHasCurrentFilterAnimation() {
    Access(misc_data_, access_.misc_data_)->has_current_filter_animation_ = static_cast<unsigned>(false);
  }


  // HasCurrentOpacityAnimation
  bool HasCurrentOpacityAnimation() const {
    return static_cast<bool>(misc_data_->has_current_opacity_animation_);
  }

  void SetHasCurrentOpacityAnimation(bool v) {
    if (!(misc_data_->has_current_opacity_animation_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_current_opacity_animation_ = static_cast<unsigned>(v);
  }

  inline void ResetHasCurrentOpacityAnimation() {
    Access(misc_data_, access_.misc_data_)->has_current_opacity_animation_ = static_cast<unsigned>(false);
  }


  // HasCurrentRotateAnimation
  bool HasCurrentRotateAnimation() const {
    return static_cast<bool>(misc_data_->has_current_rotate_animation_);
  }

  void SetHasCurrentRotateAnimation(bool v) {
    if (!(misc_data_->has_current_rotate_animation_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_current_rotate_animation_ = static_cast<unsigned>(v);
  }

  inline void ResetHasCurrentRotateAnimation() {
    Access(misc_data_, access_.misc_data_)->has_current_rotate_animation_ = static_cast<unsigned>(false);
  }


  // HasCurrentScaleAnimation
  bool HasCurrentScaleAnimation() const {
    return static_cast<bool>(misc_data_->has_current_scale_animation_);
  }

  void SetHasCurrentScaleAnimation(bool v) {
    if (!(misc_data_->has_current_scale_animation_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_current_scale_animation_ = static_cast<unsigned>(v);
  }

  inline void ResetHasCurrentScaleAnimation() {
    Access(misc_data_, access_.misc_data_)->has_current_scale_animation_ = static_cast<unsigned>(false);
  }


  // HasCurrentTransformAnimation
  bool HasCurrentTransformAnimation() const {
    return static_cast<bool>(misc_data_->has_current_transform_animation_);
  }

  void SetHasCurrentTransformAnimation(bool v) {
    if (!(misc_data_->has_current_transform_animation_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_current_transform_animation_ = static_cast<unsigned>(v);
  }

  inline void ResetHasCurrentTransformAnimation() {
    Access(misc_data_, access_.misc_data_)->has_current_transform_animation_ = static_cast<unsigned>(false);
  }


  // HasCurrentTranslateAnimation
  bool HasCurrentTranslateAnimation() const {
    return static_cast<bool>(misc_data_->has_current_translate_animation_);
  }

  void SetHasCurrentTranslateAnimation(bool v) {
    if (!(misc_data_->has_current_translate_animation_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_current_translate_animation_ = static_cast<unsigned>(v);
  }

  inline void ResetHasCurrentTranslateAnimation() {
    Access(misc_data_, access_.misc_data_)->has_current_translate_animation_ = static_cast<unsigned>(false);
  }


  // HasCustomHighlightUniversalSelector
  bool HasCustomHighlightUniversalSelector() const {
    return static_cast<bool>(misc_data_->has_custom_highlight_universal_selector_);
  }

  void SetHasCustomHighlightUniversalSelector(bool v) {
    if (!(misc_data_->has_custom_highlight_universal_selector_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_custom_highlight_universal_selector_ = static_cast<unsigned>(v);
  }

  inline void ResetHasCustomHighlightUniversalSelector() {
    Access(misc_data_, access_.misc_data_)->has_custom_highlight_universal_selector_ = static_cast<unsigned>(false);
  }


  // HasElementDependentRandomFunctions
  bool HasElementDependentRandomFunctions() const {
    return static_cast<bool>(misc_data_->has_element_dependent_random_functions_);
  }

  void SetHasElementDependentRandomFunctions() {
    if (!(misc_data_->has_element_dependent_random_functions_ == static_cast<unsigned>(true)))
      Access(misc_data_, access_.misc_data_)->has_element_dependent_random_functions_ = static_cast<unsigned>(true);
  }


  // HasEmUnits
  bool HasEmUnits() const {
    return static_cast<bool>(data_.has_em_units_);
  }

  void SetHasEmUnits() {
    data_.has_em_units_ = static_cast<unsigned>(true);
  }


  // HasEnv
  bool HasEnv() const {
    return static_cast<bool>(data_.has_env_);
  }

  void SetHasEnv() {
    data_.has_env_ = static_cast<unsigned>(true);
  }


  // HasEnvSafeAreaInsetBottom
  bool HasEnvSafeAreaInsetBottom() const {
    return static_cast<bool>(misc_data_->has_env_safe_area_inset_bottom_);
  }

  void SetHasEnvSafeAreaInsetBottom() {
    if (!(misc_data_->has_env_safe_area_inset_bottom_ == static_cast<unsigned>(true)))
      Access(misc_data_, access_.misc_data_)->has_env_safe_area_inset_bottom_ = static_cast<unsigned>(true);
  }


  // HasExplicitInheritance
  bool HasExplicitInheritance() const {
    return static_cast<bool>(data_.has_explicit_inheritance_);
  }

  void SetHasExplicitInheritance() {
    data_.has_explicit_inheritance_ = static_cast<unsigned>(true);
  }


  // HasExplicitOverflowXVisible
  bool HasExplicitOverflowXVisible() const {
    return static_cast<bool>(misc_data_->has_explicit_overflow_x_visible_);
  }

  void SetHasExplicitOverflowXVisible() {
    if (!(misc_data_->has_explicit_overflow_x_visible_ == static_cast<unsigned>(true)))
      Access(misc_data_, access_.misc_data_)->has_explicit_overflow_x_visible_ = static_cast<unsigned>(true);
  }


  // HasExplicitOverflowYVisible
  bool HasExplicitOverflowYVisible() const {
    return static_cast<bool>(misc_data_->has_explicit_overflow_y_visible_);
  }

  void SetHasExplicitOverflowYVisible() {
    if (!(misc_data_->has_explicit_overflow_y_visible_ == static_cast<unsigned>(true)))
      Access(misc_data_, access_.misc_data_)->has_explicit_overflow_y_visible_ = static_cast<unsigned>(true);
  }


  // HasGlyphRelativeUnits
  bool HasGlyphRelativeUnits() const {
    return static_cast<bool>(data_.has_glyph_relative_units_);
  }

  void SetHasGlyphRelativeUnits() {
    data_.has_glyph_relative_units_ = static_cast<unsigned>(true);
  }


  // HasLayoutContainmentForViewTransitionScope
  bool HasLayoutContainmentForViewTransitionScope() const {
    return static_cast<bool>(misc_data_->has_layout_containment_for_view_transition_scope_);
  }

  void SetHasLayoutContainmentForViewTransitionScope(bool v) {
    if (!(misc_data_->has_layout_containment_for_view_transition_scope_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_layout_containment_for_view_transition_scope_ = static_cast<unsigned>(v);
  }

  inline void ResetHasLayoutContainmentForViewTransitionScope() {
    Access(misc_data_, access_.misc_data_)->has_layout_containment_for_view_transition_scope_ = static_cast<unsigned>(false);
  }


  // HasLineHeightRelativeUnits
  bool HasLineHeightRelativeUnits() const {
    return static_cast<bool>(misc_data_->has_line_height_relative_units_);
  }

  void SetHasLineHeightRelativeUnits() {
    if (!(misc_data_->has_line_height_relative_units_ == static_cast<unsigned>(true)))
      Access(misc_data_, access_.misc_data_)->has_line_height_relative_units_ = static_cast<unsigned>(true);
  }


  // -internal-empty-line-height
  bool HasLineIfEmpty() const {
    return static_cast<bool>(misc_inherited_data_->has_line_if_empty_);
  }

  void SetHasLineIfEmpty(bool v) {
    if (!(misc_inherited_data_->has_line_if_empty_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->has_line_if_empty_ = static_cast<unsigned>(v);
  }

  inline void ResetHasLineIfEmpty() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->has_line_if_empty_ = static_cast<unsigned>(false);
  }


  // HasLogicalDirectionRelativeUnits
  bool HasLogicalDirectionRelativeUnits() const {
    return static_cast<bool>(data_.has_logical_direction_relative_units_);
  }

  void SetHasLogicalDirectionRelativeUnits() {
    data_.has_logical_direction_relative_units_ = static_cast<unsigned>(true);
  }


  // HasNonUaHighlightPseudoStyles
  bool HasNonUaHighlightPseudoStyles() const {
    return static_cast<bool>(misc_data_->has_non_ua_highlight_pseudo_styles_);
  }

  void SetHasNonUaHighlightPseudoStyles(bool v) {
    if (!(misc_data_->has_non_ua_highlight_pseudo_styles_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_non_ua_highlight_pseudo_styles_ = static_cast<unsigned>(v);
  }

  inline void ResetHasNonUaHighlightPseudoStyles() {
    Access(misc_data_, access_.misc_data_)->has_non_ua_highlight_pseudo_styles_ = static_cast<unsigned>(false);
  }


  // HasNonUniversalHighlightPseudoStyles
  bool HasNonUniversalHighlightPseudoStyles() const {
    return static_cast<bool>(misc_data_->has_non_universal_highlight_pseudo_styles_);
  }

  void SetHasNonUniversalHighlightPseudoStyles(bool v) {
    if (!(misc_data_->has_non_universal_highlight_pseudo_styles_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_non_universal_highlight_pseudo_styles_ = static_cast<unsigned>(v);
  }

  inline void ResetHasNonUniversalHighlightPseudoStyles() {
    Access(misc_data_, access_.misc_data_)->has_non_universal_highlight_pseudo_styles_ = static_cast<unsigned>(false);
  }


  // HasRootRelativeUnits
  bool HasRootRelativeUnits() const {
    return static_cast<bool>(data_.has_root_relative_units_);
  }

  void SetHasRootRelativeUnits() {
    data_.has_root_relative_units_ = static_cast<unsigned>(true);
  }


  // HasSiblingFunctions
  bool HasSiblingFunctions() const {
    return static_cast<bool>(misc_data_->has_sibling_functions_);
  }

  void SetHasSiblingFunctions() {
    if (!(misc_data_->has_sibling_functions_ == static_cast<unsigned>(true)))
      Access(misc_data_, access_.misc_data_)->has_sibling_functions_ = static_cast<unsigned>(true);
  }


  // HasSizeContainmentForViewTransitionScope
  bool HasSizeContainmentForViewTransitionScope() const {
    return static_cast<bool>(misc_data_->has_size_containment_for_view_transition_scope_);
  }

  void SetHasSizeContainmentForViewTransitionScope(bool v) {
    if (!(misc_data_->has_size_containment_for_view_transition_scope_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_size_containment_for_view_transition_scope_ = static_cast<unsigned>(v);
  }

  inline void ResetHasSizeContainmentForViewTransitionScope() {
    Access(misc_data_, access_.misc_data_)->has_size_containment_for_view_transition_scope_ = static_cast<unsigned>(false);
  }


  // HasVariableDeclaration
  bool HasVariableDeclaration() const {
    return static_cast<bool>(data_.has_variable_declaration_);
  }

  void SetHasVariableDeclaration() {
    data_.has_variable_declaration_ = static_cast<unsigned>(true);
  }


  // HasVariableReference
  bool HasVariableReference() const {
    return static_cast<bool>(data_.has_variable_reference_);
  }

  void SetHasVariableReference() {
    data_.has_variable_reference_ = static_cast<unsigned>(true);
  }


  // height
  const Length& Height() const {
    return box_data_->height_;
  }

  void SetHeight(const Length& v) {
    if (!(box_data_->height_ == v))
      Access(box_data_, access_.box_data_)->height_ = v;
  }

  void SetHeight(Length&& v) {
    if (!(box_data_->height_ == v))
      Access(box_data_, access_.box_data_)->height_ = std::move(v);
  }

  inline void ResetHeight() {
    Access(box_data_, access_.box_data_)->height_ = Length();
  }



  // HighlightData
  const StyleHighlightData& HighlightData() const {
    return inherited_data_->highlight_data_data_->highlight_data_;
  }

  void SetHighlightData(const StyleHighlightData& v) {
    if (!(inherited_data_->highlight_data_data_->highlight_data_ == v))
      Access(Access(inherited_data_, access_.inherited_data_)->highlight_data_data_, access_.highlight_data_data_)->highlight_data_ = v;
  }

  void SetHighlightData(StyleHighlightData&& v) {
    if (!(inherited_data_->highlight_data_data_->highlight_data_ == v))
      Access(Access(inherited_data_, access_.inherited_data_)->highlight_data_data_, access_.highlight_data_data_)->highlight_data_ = std::move(v);
  }

  inline void ResetHighlightData() {
    Access(Access(inherited_data_, access_.inherited_data_)->highlight_data_data_, access_.highlight_data_data_)->highlight_data_ = StyleHighlightData();
  }



  // HighlightsDependOnSizeContainerQueries
  bool HighlightsDependOnSizeContainerQueries() const {
    return static_cast<bool>(misc_data_->highlights_depend_on_size_container_queries_);
  }

  void SetHighlightsDependOnSizeContainerQueries(bool v) {
    if (!(misc_data_->highlights_depend_on_size_container_queries_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->highlights_depend_on_size_container_queries_ = static_cast<unsigned>(v);
  }

  inline void ResetHighlightsDependOnSizeContainerQueries() {
    Access(misc_data_, access_.misc_data_)->highlights_depend_on_size_container_queries_ = static_cast<unsigned>(false);
  }


  // -webkit-border-horizontal-spacing
  short HorizontalBorderSpacing() const {
    return inherited_data_->horizontal_border_spacing_;
  }

  void SetHorizontalBorderSpacing(short v) {
    if (!(inherited_data_->horizontal_border_spacing_ == v))
      Access(inherited_data_, access_.inherited_data_)->horizontal_border_spacing_ = v;
  }

  inline void ResetHorizontalBorderSpacing() {
    Access(inherited_data_, access_.inherited_data_)->horizontal_border_spacing_ = 0;
  }


  // hyphenate-limit-chars
  const StyleHyphenateLimitChars& HyphenateLimitChars() const {
    return misc_inherited_data_->misc_inherited_1_data_->hyphenate_limit_chars_;
  }

  void SetHyphenateLimitChars(const StyleHyphenateLimitChars& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->hyphenate_limit_chars_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->hyphenate_limit_chars_ = v;
  }

  void SetHyphenateLimitChars(StyleHyphenateLimitChars&& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->hyphenate_limit_chars_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->hyphenate_limit_chars_ = std::move(v);
  }

  inline void ResetHyphenateLimitChars() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->hyphenate_limit_chars_ = StyleHyphenateLimitChars();
  }



  // hyphenate-character
  const AtomicString& HyphenationString() const {
    return misc_inherited_data_->misc_inherited_1_data_->hyphenation_string_;
  }

  void SetHyphenationString(const AtomicString& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->hyphenation_string_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->hyphenation_string_ = v;
  }

  void SetHyphenationString(AtomicString&& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->hyphenation_string_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->hyphenation_string_ = std::move(v);
  }

  inline void ResetHyphenationString() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->hyphenation_string_ = AtomicString();
  }



  // hyphens
  Hyphens GetHyphens() const {
    return static_cast<Hyphens>(misc_inherited_data_->hyphens_);
  }

  void SetHyphens(Hyphens v) {
    if (!(misc_inherited_data_->hyphens_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->hyphens_ = static_cast<unsigned>(v);
  }

  inline void ResetHyphens() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->hyphens_ = static_cast<unsigned>(Hyphens::kManual);
  }


  // image-animation
  ImageAnimationEnum ImageAnimation() const {
    return static_cast<ImageAnimationEnum>(misc_inherited_data_->image_animation_);
  }

  void SetImageAnimation(ImageAnimationEnum v) {
    if (!(misc_inherited_data_->image_animation_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->image_animation_ = static_cast<unsigned>(v);
  }

  inline void ResetImageAnimation() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->image_animation_ = static_cast<unsigned>(ImageAnimationEnum::kNormal);
  }


  // image-orientation
  RespectImageOrientationEnum ImageOrientation() const {
    return static_cast<RespectImageOrientationEnum>(misc_inherited_data_->image_orientation_);
  }

  void SetImageOrientation(RespectImageOrientationEnum v) {
    if (!(misc_inherited_data_->image_orientation_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->image_orientation_ = static_cast<unsigned>(v);
  }

  inline void ResetImageOrientation() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->image_orientation_ = static_cast<unsigned>(kRespectImageOrientation);
  }


  // image-rendering
  EImageRendering ImageRendering() const {
    return static_cast<EImageRendering>(misc_inherited_data_->image_rendering_);
  }

  void SetImageRendering(EImageRendering v) {
    if (!(misc_inherited_data_->image_rendering_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->image_rendering_ = static_cast<unsigned>(v);
  }

  inline void ResetImageRendering() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->image_rendering_ = static_cast<unsigned>(EImageRendering::kAuto);
  }


  // InBaseAppearance
  bool InBaseAppearance() const {
    return static_cast<bool>(misc_inherited_data_->in_base_appearance_);
  }

  void SetInBaseAppearance(bool v) {
    if (!(misc_inherited_data_->in_base_appearance_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->in_base_appearance_ = static_cast<unsigned>(v);
  }

  inline void ResetInBaseAppearance() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->in_base_appearance_ = static_cast<unsigned>(false);
  }


  // InForcedColorsMode
  bool InForcedColorsMode() const {
    return static_cast<bool>(inherited_data_->in_forced_colors_mode_);
  }

  void SetInForcedColorsMode(bool v) {
    if (!(inherited_data_->in_forced_colors_mode_ == static_cast<unsigned>(v)))
      Access(inherited_data_, access_.inherited_data_)->in_forced_colors_mode_ = static_cast<unsigned>(v);
  }

  inline void ResetInForcedColorsMode() {
    Access(inherited_data_, access_.inherited_data_)->in_forced_colors_mode_ = static_cast<unsigned>(false);
  }


  // InheritedVariables
  


  inline void ResetInheritedVariables() {
    Access(inherited_data_, access_.inherited_data_)->inherited_variables_ = StyleInheritedVariables();
  }



  // InitialData
  StyleInitialData* InitialData() const {
    return misc_inherited_data_->misc_inherited_2_data_->initial_data_.Get();
  }

  void SetInitialData(Member<StyleInitialData> v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->initial_data_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->initial_data_ = std::move(v);
  }


  // initial-letter
  const StyleInitialLetter& InitialLetter() const {
    return misc_data_->misc_3_data_->initial_letter_;
  }

  void SetInitialLetter(const StyleInitialLetter& v) {
    if (!(misc_data_->misc_3_data_->initial_letter_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->initial_letter_ = v;
  }

  void SetInitialLetter(StyleInitialLetter&& v) {
    if (!(misc_data_->misc_3_data_->initial_letter_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->initial_letter_ = std::move(v);
  }

  inline void ResetInitialLetter() {
    Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->initial_letter_ = StyleInitialLetter();
  }



  // InlineBlockBaselineEdge
  EInlineBlockBaselineEdge InlineBlockBaselineEdge() const {
    return static_cast<EInlineBlockBaselineEdge>(data_.inline_block_baseline_edge_);
  }

  void SetInlineBlockBaselineEdge(EInlineBlockBaselineEdge v) {
    data_.inline_block_baseline_edge_ = static_cast<unsigned>(v);
  }

  inline void ResetInlineBlockBaselineEdge() {
    data_.inline_block_baseline_edge_ = static_cast<unsigned>(EInlineBlockBaselineEdge::kMarginBox);
  }


  // InlineStyleLostCascade
  bool InlineStyleLostCascade() const {
    return static_cast<bool>(misc_data_->inline_style_lost_cascade_);
  }

  void SetInlineStyleLostCascade(bool v) {
    if (!(misc_data_->inline_style_lost_cascade_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->inline_style_lost_cascade_ = static_cast<unsigned>(v);
  }

  inline void ResetInlineStyleLostCascade() {
    Access(misc_data_, access_.misc_data_)->inline_style_lost_cascade_ = static_cast<unsigned>(false);
  }


  // InsideLink
  EInsideLink InsideLink() const {
    return static_cast<EInsideLink>(data_.inside_link_);
  }

  void SetInsideLink(EInsideLink v) {
    data_.inside_link_ = static_cast<unsigned>(v);
  }

  inline void ResetInsideLink() {
    data_.inside_link_ = static_cast<unsigned>(EInsideLink::kNotInsideLink);
  }


  // interactivity
  EInteractivity Interactivity() const {
    return static_cast<EInteractivity>(misc_inherited_data_->interactivity_);
  }

  void SetInteractivity(EInteractivity v) {
    if (!(misc_inherited_data_->interactivity_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->interactivity_ = static_cast<unsigned>(v);
  }

  inline void ResetInteractivity() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->interactivity_ = static_cast<unsigned>(EInteractivity::kAuto);
  }


  // interactivity
  bool InteractivityIsInherited() const {
    return static_cast<bool>(data_.interactivity_is_inherited_);
  }

  void SetInteractivityIsInherited(bool v) {
    data_.interactivity_is_inherited_ = static_cast<unsigned>(v);
  }

  inline void ResetInteractivityIsInherited() {
    data_.interactivity_is_inherited_ = static_cast<unsigned>(true);
  }


  // interest-delay-end
  const StyleInterestDelay& InterestDelayEnd() const {
    return misc_data_->misc_3_data_->interest_delay_end_;
  }

  void SetInterestDelayEnd(const StyleInterestDelay& v) {
    if (!(misc_data_->misc_3_data_->interest_delay_end_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->interest_delay_end_ = v;
  }

  void SetInterestDelayEnd(StyleInterestDelay&& v) {
    if (!(misc_data_->misc_3_data_->interest_delay_end_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->interest_delay_end_ = std::move(v);
  }

  inline void ResetInterestDelayEnd() {
    Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->interest_delay_end_ = StyleInterestDelay();
  }



  // interest-delay-start
  const StyleInterestDelay& InterestDelayStart() const {
    return misc_data_->misc_3_data_->interest_delay_start_;
  }

  void SetInterestDelayStart(const StyleInterestDelay& v) {
    if (!(misc_data_->misc_3_data_->interest_delay_start_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->interest_delay_start_ = v;
  }

  void SetInterestDelayStart(StyleInterestDelay&& v) {
    if (!(misc_data_->misc_3_data_->interest_delay_start_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->interest_delay_start_ = std::move(v);
  }

  inline void ResetInterestDelayStart() {
    Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->interest_delay_start_ = StyleInterestDelay();
  }



  // -internal-forced-background-color
  
  void SetInternalForcedBackgroundColor(const StyleColor& v) {
    if (!(misc_data_->forced_colors_data_->internal_forced_background_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->forced_colors_data_, access_.forced_colors_data_)->internal_forced_background_color_ = v;
  }

  void SetInternalForcedBackgroundColor(StyleColor&& v) {
    if (!(misc_data_->forced_colors_data_->internal_forced_background_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->forced_colors_data_, access_.forced_colors_data_)->internal_forced_background_color_ = std::move(v);
  }

  inline void ResetInternalForcedBackgroundColor() {
    Access(Access(misc_data_, access_.misc_data_)->forced_colors_data_, access_.forced_colors_data_)->internal_forced_background_color_ = StyleColor(CSSValueID::kCanvas);
  }



  // -internal-forced-border-color
  
  void SetInternalForcedBorderColor(const StyleColor& v) {
    if (!(misc_data_->forced_colors_data_->internal_forced_border_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->forced_colors_data_, access_.forced_colors_data_)->internal_forced_border_color_ = v;
  }

  void SetInternalForcedBorderColor(StyleColor&& v) {
    if (!(misc_data_->forced_colors_data_->internal_forced_border_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->forced_colors_data_, access_.forced_colors_data_)->internal_forced_border_color_ = std::move(v);
  }

  inline void ResetInternalForcedBorderColor() {
    Access(Access(misc_data_, access_.misc_data_)->forced_colors_data_, access_.forced_colors_data_)->internal_forced_border_color_ = StyleColor::CurrentColor();
  }



  // -internal-forced-color
  
  void SetInternalForcedColor(const StyleColor& v) {
    if (!(inherited_data_->inherited_forced_colors_data_->internal_forced_color_ == v))
      Access(Access(inherited_data_, access_.inherited_data_)->inherited_forced_colors_data_, access_.inherited_forced_colors_data_)->internal_forced_color_ = v;
  }

  void SetInternalForcedColor(StyleColor&& v) {
    if (!(inherited_data_->inherited_forced_colors_data_->internal_forced_color_ == v))
      Access(Access(inherited_data_, access_.inherited_data_)->inherited_forced_colors_data_, access_.inherited_forced_colors_data_)->internal_forced_color_ = std::move(v);
  }

  inline void ResetInternalForcedColor() {
    Access(Access(inherited_data_, access_.inherited_data_)->inherited_forced_colors_data_, access_.inherited_forced_colors_data_)->internal_forced_color_ = StyleColor(CSSValueID::kCanvastext);
  }



  // -internal-forced-outline-color
  
  void SetInternalForcedOutlineColor(const StyleColor& v) {
    if (!(misc_data_->forced_colors_data_->internal_forced_outline_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->forced_colors_data_, access_.forced_colors_data_)->internal_forced_outline_color_ = v;
  }

  void SetInternalForcedOutlineColor(StyleColor&& v) {
    if (!(misc_data_->forced_colors_data_->internal_forced_outline_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->forced_colors_data_, access_.forced_colors_data_)->internal_forced_outline_color_ = std::move(v);
  }

  inline void ResetInternalForcedOutlineColor() {
    Access(Access(misc_data_, access_.misc_data_)->forced_colors_data_, access_.forced_colors_data_)->internal_forced_outline_color_ = StyleColor::CurrentColor();
  }



  // -internal-forced-visited-color
  
  void SetInternalForcedVisitedColor(const StyleColor& v) {
    if (!(inherited_data_->inherited_forced_colors_data_->internal_forced_visited_color_ == v))
      Access(Access(inherited_data_, access_.inherited_data_)->inherited_forced_colors_data_, access_.inherited_forced_colors_data_)->internal_forced_visited_color_ = v;
  }

  void SetInternalForcedVisitedColor(StyleColor&& v) {
    if (!(inherited_data_->inherited_forced_colors_data_->internal_forced_visited_color_ == v))
      Access(Access(inherited_data_, access_.inherited_data_)->inherited_forced_colors_data_, access_.inherited_forced_colors_data_)->internal_forced_visited_color_ = std::move(v);
  }

  inline void ResetInternalForcedVisitedColor() {
    Access(Access(inherited_data_, access_.inherited_data_)->inherited_forced_colors_data_, access_.inherited_forced_colors_data_)->internal_forced_visited_color_ = StyleColor(CSSValueID::kCanvastext);
  }



  // -internal-overscroll-container
  EInternalOverscrollContainer InternalOverscrollContainer() const {
    return static_cast<EInternalOverscrollContainer>(misc_data_->internal_overscroll_container_);
  }

  void SetInternalOverscrollContainer(EInternalOverscrollContainer v) {
    if (!(misc_data_->internal_overscroll_container_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->internal_overscroll_container_ = static_cast<unsigned>(v);
  }

  inline void ResetInternalOverscrollContainer() {
    Access(misc_data_, access_.misc_data_)->internal_overscroll_container_ = static_cast<unsigned>(EInternalOverscrollContainer::kNone);
  }


  // -internal-overscroll-position
  EInternalOverscrollPosition InternalOverscrollPosition() const {
    return static_cast<EInternalOverscrollPosition>(misc_data_->internal_overscroll_position_);
  }

  void SetInternalOverscrollPosition(EInternalOverscrollPosition v) {
    if (!(misc_data_->internal_overscroll_position_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->internal_overscroll_position_ = static_cast<unsigned>(v);
  }

  inline void ResetInternalOverscrollPosition() {
    Access(misc_data_, access_.misc_data_)->internal_overscroll_position_ = static_cast<unsigned>(EInternalOverscrollPosition::kNone);
  }


  // -internal-unbounded
  EInternalUnbounded InternalUnbounded() const {
    return static_cast<EInternalUnbounded>(misc_data_->internal_unbounded_);
  }

  void SetInternalUnbounded(EInternalUnbounded v) {
    if (!(misc_data_->internal_unbounded_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->internal_unbounded_ = static_cast<unsigned>(v);
  }

  inline void ResetInternalUnbounded() {
    Access(misc_data_, access_.misc_data_)->internal_unbounded_ = static_cast<unsigned>(EInternalUnbounded::kNone);
  }


  // -internal-visited-background-color
  
  void SetInternalVisitedBackgroundColor(const StyleColor& v) {
    if (!(misc_data_->visited_data_->internal_visited_background_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_background_color_ = v;
  }

  void SetInternalVisitedBackgroundColor(StyleColor&& v) {
    if (!(misc_data_->visited_data_->internal_visited_background_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_background_color_ = std::move(v);
  }

  inline void ResetInternalVisitedBackgroundColor() {
    Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_background_color_ = StyleColor(Color::kTransparent);
  }



  // -internal-visited-border-bottom-color
  
  void SetInternalVisitedBorderBottomColor(const StyleColor& v) {
    if (!(misc_data_->visited_data_->internal_visited_border_bottom_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_bottom_color_ = v;
  }

  void SetInternalVisitedBorderBottomColor(StyleColor&& v) {
    if (!(misc_data_->visited_data_->internal_visited_border_bottom_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_bottom_color_ = std::move(v);
  }

  inline void ResetInternalVisitedBorderBottomColor() {
    Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_bottom_color_ = StyleColor::CurrentColor();
  }



  // -internal-visited-border-left-color
  
  void SetInternalVisitedBorderLeftColor(const StyleColor& v) {
    if (!(misc_data_->visited_data_->internal_visited_border_left_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_left_color_ = v;
  }

  void SetInternalVisitedBorderLeftColor(StyleColor&& v) {
    if (!(misc_data_->visited_data_->internal_visited_border_left_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_left_color_ = std::move(v);
  }

  inline void ResetInternalVisitedBorderLeftColor() {
    Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_left_color_ = StyleColor::CurrentColor();
  }



  // -internal-visited-border-right-color
  
  void SetInternalVisitedBorderRightColor(const StyleColor& v) {
    if (!(misc_data_->visited_data_->internal_visited_border_right_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_right_color_ = v;
  }

  void SetInternalVisitedBorderRightColor(StyleColor&& v) {
    if (!(misc_data_->visited_data_->internal_visited_border_right_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_right_color_ = std::move(v);
  }

  inline void ResetInternalVisitedBorderRightColor() {
    Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_right_color_ = StyleColor::CurrentColor();
  }



  // -internal-visited-border-top-color
  
  void SetInternalVisitedBorderTopColor(const StyleColor& v) {
    if (!(misc_data_->visited_data_->internal_visited_border_top_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_top_color_ = v;
  }

  void SetInternalVisitedBorderTopColor(StyleColor&& v) {
    if (!(misc_data_->visited_data_->internal_visited_border_top_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_top_color_ = std::move(v);
  }

  inline void ResetInternalVisitedBorderTopColor() {
    Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_top_color_ = StyleColor::CurrentColor();
  }



  // -internal-visited-caret-color
  
  void SetInternalVisitedCaretColor(const StyleCaretColor& v) {
    if (!(inherited_data_->inherited_visited_data_->internal_visited_caret_color_ == v))
      Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_caret_color_ = v;
  }

  void SetInternalVisitedCaretColor(StyleCaretColor&& v) {
    if (!(inherited_data_->inherited_visited_data_->internal_visited_caret_color_ == v))
      Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_caret_color_ = std::move(v);
  }

  inline void ResetInternalVisitedCaretColor() {
    Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_caret_color_ = StyleCaretColor();
  }



  // -internal-visited-color
  
  void SetInternalVisitedColor(const StyleColor& v) {
    if (!(inherited_data_->internal_visited_color_ == v))
      Access(inherited_data_, access_.inherited_data_)->internal_visited_color_ = v;
  }

  void SetInternalVisitedColor(StyleColor&& v) {
    if (!(inherited_data_->internal_visited_color_ == v))
      Access(inherited_data_, access_.inherited_data_)->internal_visited_color_ = std::move(v);
  }

  inline void ResetInternalVisitedColor() {
    Access(inherited_data_, access_.inherited_data_)->internal_visited_color_ = StyleColor(Color::kBlack);
  }



  // InternalVisitedColorIsCurrentColor
  
  void SetInternalVisitedColorIsCurrentColor(bool v) {
    if (!(inherited_data_->internal_visited_color_is_current_color_ == static_cast<unsigned>(v)))
      Access(inherited_data_, access_.inherited_data_)->internal_visited_color_is_current_color_ = static_cast<unsigned>(v);
  }

  inline void ResetInternalVisitedColorIsCurrentColor() {
    Access(inherited_data_, access_.inherited_data_)->internal_visited_color_is_current_color_ = static_cast<unsigned>(true);
  }


  // -internal-visited-column-rule-color
  const GapDataList<StyleColor>& InternalVisitedColumnRuleColor() const {
    return misc_data_->visited_data_->internal_visited_column_rule_color_;
  }

  void SetInternalVisitedColumnRuleColor(const GapDataList<StyleColor>& v) {
    if (!(misc_data_->visited_data_->internal_visited_column_rule_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_column_rule_color_ = v;
  }

  void SetInternalVisitedColumnRuleColor(GapDataList<StyleColor>&& v) {
    if (!(misc_data_->visited_data_->internal_visited_column_rule_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_column_rule_color_ = std::move(v);
  }

  inline void ResetInternalVisitedColumnRuleColor() {
    Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_column_rule_color_ = GapDataList<StyleColor>::DefaultGapColorDataList();
  }



  // -internal-visited-fill
  const SVGPaint& InternalVisitedFillPaint() const {
    return svginherited_data_->fill_data_->internal_visited_fill_paint_;
  }

  void SetInternalVisitedFillPaint(const SVGPaint& v) {
    if (!(svginherited_data_->fill_data_->internal_visited_fill_paint_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->fill_data_, access_.fill_data_)->internal_visited_fill_paint_ = v;
  }

  void SetInternalVisitedFillPaint(SVGPaint&& v) {
    if (!(svginherited_data_->fill_data_->internal_visited_fill_paint_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->fill_data_, access_.fill_data_)->internal_visited_fill_paint_ = std::move(v);
  }

  inline void ResetInternalVisitedFillPaint() {
    Access(Access(svginherited_data_, access_.svginherited_data_)->fill_data_, access_.fill_data_)->internal_visited_fill_paint_ = SVGPaint(Color::kBlack);
  }



  // -internal-visited-outline-color
  
  void SetInternalVisitedOutlineColor(const StyleColor& v) {
    if (!(misc_data_->visited_data_->internal_visited_outline_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_outline_color_ = v;
  }

  void SetInternalVisitedOutlineColor(StyleColor&& v) {
    if (!(misc_data_->visited_data_->internal_visited_outline_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_outline_color_ = std::move(v);
  }

  inline void ResetInternalVisitedOutlineColor() {
    Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_outline_color_ = StyleColor::CurrentColor();
  }



  // -internal-visited-stroke
  const SVGPaint& InternalVisitedStrokePaint() const {
    return svginherited_data_->stroke_data_->internal_visited_stroke_paint_;
  }

  void SetInternalVisitedStrokePaint(const SVGPaint& v) {
    if (!(svginherited_data_->stroke_data_->internal_visited_stroke_paint_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->internal_visited_stroke_paint_ = v;
  }

  void SetInternalVisitedStrokePaint(SVGPaint&& v) {
    if (!(svginherited_data_->stroke_data_->internal_visited_stroke_paint_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->internal_visited_stroke_paint_ = std::move(v);
  }

  inline void ResetInternalVisitedStrokePaint() {
    Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->internal_visited_stroke_paint_ = SVGPaint();
  }



  // -internal-visited-text-decoration-color
  
  void SetInternalVisitedTextDecorationColor(const StyleColor& v) {
    if (!(misc_data_->visited_data_->internal_visited_text_decoration_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_text_decoration_color_ = v;
  }

  void SetInternalVisitedTextDecorationColor(StyleColor&& v) {
    if (!(misc_data_->visited_data_->internal_visited_text_decoration_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_text_decoration_color_ = std::move(v);
  }

  inline void ResetInternalVisitedTextDecorationColor() {
    Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_text_decoration_color_ = StyleColor::CurrentColor();
  }



  // -internal-visited-text-emphasis-color
  
  void SetInternalVisitedTextEmphasisColor(const StyleColor& v) {
    if (!(inherited_data_->inherited_visited_data_->internal_visited_text_emphasis_color_ == v))
      Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_text_emphasis_color_ = v;
  }

  void SetInternalVisitedTextEmphasisColor(StyleColor&& v) {
    if (!(inherited_data_->inherited_visited_data_->internal_visited_text_emphasis_color_ == v))
      Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_text_emphasis_color_ = std::move(v);
  }

  inline void ResetInternalVisitedTextEmphasisColor() {
    Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_text_emphasis_color_ = StyleColor::CurrentColor();
  }



  // -internal-visited-text-fill-color
  
  void SetInternalVisitedTextFillColor(const StyleColor& v) {
    if (!(inherited_data_->inherited_visited_data_->internal_visited_text_fill_color_ == v))
      Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_text_fill_color_ = v;
  }

  void SetInternalVisitedTextFillColor(StyleColor&& v) {
    if (!(inherited_data_->inherited_visited_data_->internal_visited_text_fill_color_ == v))
      Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_text_fill_color_ = std::move(v);
  }

  inline void ResetInternalVisitedTextFillColor() {
    Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_text_fill_color_ = StyleColor::CurrentColor();
  }



  // -internal-visited-text-stroke-color
  
  void SetInternalVisitedTextStrokeColor(const StyleColor& v) {
    if (!(inherited_data_->inherited_visited_data_->internal_visited_text_stroke_color_ == v))
      Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_text_stroke_color_ = v;
  }

  void SetInternalVisitedTextStrokeColor(StyleColor&& v) {
    if (!(inherited_data_->inherited_visited_data_->internal_visited_text_stroke_color_ == v))
      Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_text_stroke_color_ = std::move(v);
  }

  inline void ResetInternalVisitedTextStrokeColor() {
    Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_text_stroke_color_ = StyleColor::CurrentColor();
  }



  // interpolate-size
  EInterpolateSize InterpolateSize() const {
    return static_cast<EInterpolateSize>(misc_inherited_data_->interpolate_size_);
  }

  void SetInterpolateSize(EInterpolateSize v) {
    if (!(misc_inherited_data_->interpolate_size_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->interpolate_size_ = static_cast<unsigned>(v);
  }

  inline void ResetInterpolateSize() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->interpolate_size_ = static_cast<unsigned>(EInterpolateSize::kNumericOnly);
  }


  // IsBottomRelativeToSafeAreaInset
  bool IsBottomRelativeToSafeAreaInset() const {
    return static_cast<bool>(misc_data_->is_bottom_relative_to_safe_area_inset_);
  }

  void SetIsBottomRelativeToSafeAreaInset(bool v) {
    if (!(misc_data_->is_bottom_relative_to_safe_area_inset_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->is_bottom_relative_to_safe_area_inset_ = static_cast<unsigned>(v);
  }

  inline void ResetIsBottomRelativeToSafeAreaInset() {
    Access(misc_data_, access_.misc_data_)->is_bottom_relative_to_safe_area_inset_ = static_cast<unsigned>(false);
  }


  // IsCSSInert
  bool IsCSSInert() const {
    return static_cast<bool>(data_.is_css_inert_);
  }

  void SetIsCSSInert(bool v) {
    data_.is_css_inert_ = static_cast<unsigned>(v);
  }

  inline void ResetIsCSSInert() {
    data_.is_css_inert_ = static_cast<unsigned>(false);
  }


  // IsCSSInert
  bool IsCSSInertIsInherited() const {
    return static_cast<bool>(data_.is_css_inert_is_inherited_);
  }

  void SetIsCSSInertIsInherited(bool v) {
    data_.is_css_inert_is_inherited_ = static_cast<unsigned>(v);
  }

  inline void ResetIsCSSInertIsInherited() {
    data_.is_css_inert_is_inherited_ = static_cast<unsigned>(true);
  }


  // IsEnsuredInDisplayNone
  bool IsEnsuredInDisplayNone() const {
    return static_cast<bool>(data_.is_ensured_in_display_none_);
  }

  void SetIsEnsuredInDisplayNone() {
    data_.is_ensured_in_display_none_ = static_cast<unsigned>(true);
  }


  // IsFlexOrGridOrCustomItem
  bool IsFlexOrGridOrCustomItem() const {
    return static_cast<bool>(data_.is_flex_or_grid_or_custom_item_);
  }

  void SetIsFlexOrGridOrCustomItem() {
    data_.is_flex_or_grid_or_custom_item_ = static_cast<unsigned>(true);
  }


  // IsHTMLInert
  bool IsHTMLInert() const {
    return static_cast<bool>(data_.is_html_inert_);
  }

  void SetIsHTMLInert(bool v) {
    data_.is_html_inert_ = static_cast<unsigned>(v);
  }

  inline void ResetIsHTMLInert() {
    data_.is_html_inert_ = static_cast<unsigned>(false);
  }


  // IsHTMLInert
  bool IsHTMLInertIsInherited() const {
    return static_cast<bool>(data_.is_html_inert_is_inherited_);
  }

  void SetIsHTMLInertIsInherited(bool v) {
    data_.is_html_inert_is_inherited_ = static_cast<unsigned>(v);
  }

  inline void ResetIsHTMLInertIsInherited() {
    data_.is_html_inert_is_inherited_ = static_cast<unsigned>(true);
  }


  // IsInBlockifyingDisplay
  bool IsInBlockifyingDisplay() const {
    return static_cast<bool>(data_.is_in_blockifying_display_);
  }

  void SetIsInBlockifyingDisplay() {
    data_.is_in_blockifying_display_ = static_cast<unsigned>(true);
  }


  // IsInInlinifyingDisplay
  bool IsInInlinifyingDisplay() const {
    return static_cast<bool>(data_.is_in_inlinifying_display_);
  }

  void SetIsInInlinifyingDisplay() {
    data_.is_in_inlinifying_display_ = static_cast<unsigned>(true);
  }


  // IsInShrinkToFitSubtree
  bool IsInShrinkToFitSubtree() const {
    return static_cast<bool>(misc_inherited_data_->is_in_shrink_to_fit_subtree_);
  }

  void SetIsInShrinkToFitSubtree(bool v) {
    if (!(misc_inherited_data_->is_in_shrink_to_fit_subtree_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->is_in_shrink_to_fit_subtree_ = static_cast<unsigned>(v);
  }

  inline void ResetIsInShrinkToFitSubtree() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->is_in_shrink_to_fit_subtree_ = static_cast<unsigned>(false);
  }


  // IsInsideDisplayIgnoringFloatingChildren
  bool IsInsideDisplayIgnoringFloatingChildren() const {
    return static_cast<bool>(data_.is_inside_display_ignoring_floating_children_);
  }

  void SetIsInsideDisplayIgnoringFloatingChildren() {
    data_.is_inside_display_ignoring_floating_children_ = static_cast<unsigned>(true);
  }


  // IsLink
  bool IsLink() const {
    return static_cast<bool>(data_.is_link_);
  }

  void SetIsLink() {
    data_.is_link_ = static_cast<unsigned>(true);
  }


  // IsOriginalDisplayInlineType
  bool IsOriginalDisplayInlineType() const {
    return static_cast<bool>(data_.is_original_display_inline_type_);
  }

  void SetIsOriginalDisplayInlineType(bool v) {
    data_.is_original_display_inline_type_ = static_cast<unsigned>(v);
  }

  inline void ResetIsOriginalDisplayInlineType() {
    data_.is_original_display_inline_type_ = static_cast<unsigned>(true);
  }


  // IsPageMarginBox
  bool IsPageMarginBox() const {
    return static_cast<bool>(data_.is_page_margin_box_);
  }

  void SetIsPageMarginBox(bool v) {
    data_.is_page_margin_box_ = static_cast<unsigned>(v);
  }

  inline void ResetIsPageMarginBox() {
    data_.is_page_margin_box_ = static_cast<unsigned>(false);
  }


  // IsRunningBackdropFilterAnimationOnCompositor
  bool IsRunningBackdropFilterAnimationOnCompositor() const {
    return static_cast<bool>(misc_data_->is_running_backdrop_filter_animation_on_compositor_);
  }

  void SetIsRunningBackdropFilterAnimationOnCompositor(bool v) {
    if (!(misc_data_->is_running_backdrop_filter_animation_on_compositor_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->is_running_backdrop_filter_animation_on_compositor_ = static_cast<unsigned>(v);
  }

  inline void ResetIsRunningBackdropFilterAnimationOnCompositor() {
    Access(misc_data_, access_.misc_data_)->is_running_backdrop_filter_animation_on_compositor_ = static_cast<unsigned>(false);
  }


  // IsRunningFilterAnimationOnCompositor
  bool IsRunningFilterAnimationOnCompositor() const {
    return static_cast<bool>(misc_data_->is_running_filter_animation_on_compositor_);
  }

  void SetIsRunningFilterAnimationOnCompositor(bool v) {
    if (!(misc_data_->is_running_filter_animation_on_compositor_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->is_running_filter_animation_on_compositor_ = static_cast<unsigned>(v);
  }

  inline void ResetIsRunningFilterAnimationOnCompositor() {
    Access(misc_data_, access_.misc_data_)->is_running_filter_animation_on_compositor_ = static_cast<unsigned>(false);
  }


  // IsRunningOpacityAnimationOnCompositor
  bool IsRunningOpacityAnimationOnCompositor() const {
    return static_cast<bool>(misc_data_->is_running_opacity_animation_on_compositor_);
  }

  void SetIsRunningOpacityAnimationOnCompositor(bool v) {
    if (!(misc_data_->is_running_opacity_animation_on_compositor_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->is_running_opacity_animation_on_compositor_ = static_cast<unsigned>(v);
  }

  inline void ResetIsRunningOpacityAnimationOnCompositor() {
    Access(misc_data_, access_.misc_data_)->is_running_opacity_animation_on_compositor_ = static_cast<unsigned>(false);
  }


  // IsRunningRotateAnimationOnCompositor
  bool IsRunningRotateAnimationOnCompositor() const {
    return static_cast<bool>(misc_data_->is_running_rotate_animation_on_compositor_);
  }

  void SetIsRunningRotateAnimationOnCompositor(bool v) {
    if (!(misc_data_->is_running_rotate_animation_on_compositor_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->is_running_rotate_animation_on_compositor_ = static_cast<unsigned>(v);
  }

  inline void ResetIsRunningRotateAnimationOnCompositor() {
    Access(misc_data_, access_.misc_data_)->is_running_rotate_animation_on_compositor_ = static_cast<unsigned>(false);
  }


  // IsRunningScaleAnimationOnCompositor
  bool IsRunningScaleAnimationOnCompositor() const {
    return static_cast<bool>(misc_data_->is_running_scale_animation_on_compositor_);
  }

  void SetIsRunningScaleAnimationOnCompositor(bool v) {
    if (!(misc_data_->is_running_scale_animation_on_compositor_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->is_running_scale_animation_on_compositor_ = static_cast<unsigned>(v);
  }

  inline void ResetIsRunningScaleAnimationOnCompositor() {
    Access(misc_data_, access_.misc_data_)->is_running_scale_animation_on_compositor_ = static_cast<unsigned>(false);
  }


  // IsRunningTransformAnimationOnCompositor
  bool IsRunningTransformAnimationOnCompositor() const {
    return static_cast<bool>(misc_data_->is_running_transform_animation_on_compositor_);
  }

  void SetIsRunningTransformAnimationOnCompositor(bool v) {
    if (!(misc_data_->is_running_transform_animation_on_compositor_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->is_running_transform_animation_on_compositor_ = static_cast<unsigned>(v);
  }

  inline void ResetIsRunningTransformAnimationOnCompositor() {
    Access(misc_data_, access_.misc_data_)->is_running_transform_animation_on_compositor_ = static_cast<unsigned>(false);
  }


  // IsRunningTranslateAnimationOnCompositor
  bool IsRunningTranslateAnimationOnCompositor() const {
    return static_cast<bool>(misc_data_->is_running_translate_animation_on_compositor_);
  }

  void SetIsRunningTranslateAnimationOnCompositor(bool v) {
    if (!(misc_data_->is_running_translate_animation_on_compositor_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->is_running_translate_animation_on_compositor_ = static_cast<unsigned>(v);
  }

  inline void ResetIsRunningTranslateAnimationOnCompositor() {
    Access(misc_data_, access_.misc_data_)->is_running_translate_animation_on_compositor_ = static_cast<unsigned>(false);
  }


  // IsSecondaryBodyElement
  bool IsSecondaryBodyElement() const {
    return static_cast<bool>(misc_data_->is_secondary_body_element_);
  }

  void SetIsSecondaryBodyElement() {
    if (!(misc_data_->is_secondary_body_element_ == static_cast<unsigned>(true)))
      Access(misc_data_, access_.misc_data_)->is_secondary_body_element_ = static_cast<unsigned>(true);
  }


  // IsSpecifiedDisplayWebkitBox
  bool IsSpecifiedDisplayWebkitBox() const {
    return static_cast<bool>(misc_data_->is_specified_display_webkit_box_);
  }

  void SetIsSpecifiedDisplayWebkitBox() {
    if (!(misc_data_->is_specified_display_webkit_box_ == static_cast<unsigned>(true)))
      Access(misc_data_, access_.misc_data_)->is_specified_display_webkit_box_ = static_cast<unsigned>(true);
  }


  // IsStartingStyle
  bool IsStartingStyle() const {
    return static_cast<bool>(misc_data_->is_starting_style_);
  }

  void SetIsStartingStyle() {
    if (!(misc_data_->is_starting_style_ == static_cast<unsigned>(true)))
      Access(misc_data_, access_.misc_data_)->is_starting_style_ = static_cast<unsigned>(true);
  }


  // isolation
  EIsolation Isolation() const {
    return static_cast<EIsolation>(misc_data_->isolation_);
  }

  void SetIsolation(EIsolation v) {
    if (!(misc_data_->isolation_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->isolation_ = static_cast<unsigned>(v);
  }

  inline void ResetIsolation() {
    Access(misc_data_, access_.misc_data_)->isolation_ = static_cast<unsigned>(EIsolation::kAuto);
  }


  // stroke-linejoin
  LineJoin JoinStyle() const {
    return static_cast<LineJoin>(svginherited_data_->stroke_data_->join_style_);
  }

  void SetJoinStyle(LineJoin v) {
    if (!(svginherited_data_->stroke_data_->join_style_ == static_cast<unsigned>(v)))
      Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->join_style_ = static_cast<unsigned>(v);
  }

  inline void ResetJoinStyle() {
    Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->join_style_ = static_cast<unsigned>(kMiterJoin);
  }


  // justify-content
  const StyleContentAlignmentData& JustifyContent() const {
    return box_data_->justify_content_;
  }

  void SetJustifyContent(const StyleContentAlignmentData& v) {
    if (!(box_data_->justify_content_ == v))
      Access(box_data_, access_.box_data_)->justify_content_ = v;
  }

  void SetJustifyContent(StyleContentAlignmentData&& v) {
    if (!(box_data_->justify_content_ == v))
      Access(box_data_, access_.box_data_)->justify_content_ = std::move(v);
  }

  inline void ResetJustifyContent() {
    Access(box_data_, access_.box_data_)->justify_content_ = StyleContentAlignmentData(ContentPosition::kNormal, ContentDistributionType::kDefault, OverflowAlignment::kDefault);
  }



  // justify-items
  const StyleSelfAlignmentData& JustifyItems() const {
    return misc_data_->misc_3_data_->justify_items_;
  }

  void SetJustifyItems(const StyleSelfAlignmentData& v) {
    if (!(misc_data_->misc_3_data_->justify_items_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->justify_items_ = v;
  }

  void SetJustifyItems(StyleSelfAlignmentData&& v) {
    if (!(misc_data_->misc_3_data_->justify_items_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->justify_items_ = std::move(v);
  }

  inline void ResetJustifyItems() {
    Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->justify_items_ = StyleSelfAlignmentData(ItemPosition::kLegacy, OverflowAlignment::kDefault);
  }



  // justify-self
  const StyleSelfAlignmentData& JustifySelf() const {
    return misc_data_->misc_3_data_->justify_self_;
  }

  void SetJustifySelf(const StyleSelfAlignmentData& v) {
    if (!(misc_data_->misc_3_data_->justify_self_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->justify_self_ = v;
  }

  void SetJustifySelf(StyleSelfAlignmentData&& v) {
    if (!(misc_data_->misc_3_data_->justify_self_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->justify_self_ = std::move(v);
  }

  inline void ResetJustifySelf() {
    Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->justify_self_ = StyleSelfAlignmentData(ItemPosition::kAuto, OverflowAlignment::kDefault);
  }



  // left
  const Length& Left() const {
    return surround_data_->left_;
  }

  void SetLeft(const Length& v) {
    if (!(surround_data_->left_ == v))
      Access(surround_data_, access_.surround_data_)->left_ = v;
  }

  void SetLeft(Length&& v) {
    if (!(surround_data_->left_ == v))
      Access(surround_data_, access_.surround_data_)->left_ = std::move(v);
  }

  inline void ResetLeft() {
    Access(surround_data_, access_.surround_data_)->left_ = Length();
  }



  // letter-spacing
  
  void SetLetterSpacing(const Length& v) {
    if (!(inherited_data_->letter_spacing_ == v))
      Access(inherited_data_, access_.inherited_data_)->letter_spacing_ = v;
  }

  void SetLetterSpacing(Length&& v) {
    if (!(inherited_data_->letter_spacing_ == v))
      Access(inherited_data_, access_.inherited_data_)->letter_spacing_ = std::move(v);
  }

  inline void ResetLetterSpacing() {
    Access(inherited_data_, access_.inherited_data_)->letter_spacing_ = Length::Fixed();
  }



  // lighting-color
  const StyleColor& LightingColor() const {
    return svg_data_->svgmisc_data_->lighting_color_;
  }

  void SetLightingColor(const StyleColor& v) {
    if (!(svg_data_->svgmisc_data_->lighting_color_ == v))
      Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->lighting_color_ = v;
  }

  void SetLightingColor(StyleColor&& v) {
    if (!(svg_data_->svgmisc_data_->lighting_color_ == v))
      Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->lighting_color_ = std::move(v);
  }

  inline void ResetLightingColor() {
    Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->lighting_color_ = StyleColor(Color::kWhite);
  }



  // line-break
  LineBreak GetLineBreak() const {
    return static_cast<LineBreak>(misc_inherited_data_->line_break_);
  }

  void SetLineBreak(LineBreak v) {
    if (!(misc_inherited_data_->line_break_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->line_break_ = static_cast<unsigned>(v);
  }

  inline void ResetLineBreak() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->line_break_ = static_cast<unsigned>(LineBreak::kAuto);
  }


  // LineClampInternalBlockEllipsis
  EBlockEllipsis LineClampInternalBlockEllipsis() const {
    return static_cast<EBlockEllipsis>(misc_data_->line_clamp_internal_block_ellipsis_);
  }

  void SetLineClampInternalBlockEllipsis(EBlockEllipsis v) {
    if (!(misc_data_->line_clamp_internal_block_ellipsis_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->line_clamp_internal_block_ellipsis_ = static_cast<unsigned>(v);
  }

  inline void ResetLineClampInternalBlockEllipsis() {
    Access(misc_data_, access_.misc_data_)->line_clamp_internal_block_ellipsis_ = static_cast<unsigned>(EBlockEllipsis::kNoEllipsis);
  }


  // line-height
  const Length& LineHeight() const {
    return inherited_data_->line_height_;
  }

  void SetLineHeight(const Length& v) {
    if (!(inherited_data_->line_height_ == v))
      Access(inherited_data_, access_.inherited_data_)->line_height_ = v;
  }

  void SetLineHeight(Length&& v) {
    if (!(inherited_data_->line_height_ == v))
      Access(inherited_data_, access_.inherited_data_)->line_height_ = std::move(v);
  }

  inline void ResetLineHeight() {
    Access(inherited_data_, access_.inherited_data_)->line_height_ = Length::Auto();
  }



  // list-style-image
  const Member<StyleImage>& ListStyleImage() const {
    return misc_inherited_data_->misc_inherited_1_data_->list_style_image_;
  }

  void SetListStyleImage(const Member<StyleImage>& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->list_style_image_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->list_style_image_ = v;
  }

  void SetListStyleImage(Member<StyleImage>&& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->list_style_image_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->list_style_image_ = std::move(v);
  }

  inline void ResetListStyleImage() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->list_style_image_ = nullptr;
  }



  // list-style-position
  EListStylePosition ListStylePosition() const {
    return static_cast<EListStylePosition>(data_.list_style_position_);
  }

  void SetListStylePosition(EListStylePosition v) {
    data_.list_style_position_ = static_cast<unsigned>(v);
  }

  inline void ResetListStylePosition() {
    data_.list_style_position_ = static_cast<unsigned>(EListStylePosition::kOutside);
  }


  // list-style-position
  bool ListStylePositionIsInherited() const {
    return static_cast<bool>(data_.list_style_position_is_inherited_);
  }

  void SetListStylePositionIsInherited(bool v) {
    data_.list_style_position_is_inherited_ = static_cast<unsigned>(v);
  }

  inline void ResetListStylePositionIsInherited() {
    data_.list_style_position_is_inherited_ = static_cast<unsigned>(true);
  }


  // list-style-type
  const Member<ListStyleTypeData>& ListStyleType() const {
    return misc_inherited_data_->misc_inherited_1_data_->list_style_type_;
  }

  void SetListStyleType(const Member<ListStyleTypeData>& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->list_style_type_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->list_style_type_ = v;
  }

  void SetListStyleType(Member<ListStyleTypeData>&& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->list_style_type_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->list_style_type_ = std::move(v);
  }

  inline void ResetListStyleType() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->list_style_type_ = ListStyleTypeData::CreateCounterStyle(keywords::kDisc, nullptr);
  }



  // margin-bottom
  const Length& MarginBottom() const {
    return box_data_->margin_bottom_;
  }



  inline void ResetMarginBottom() {
    Access(box_data_, access_.box_data_)->margin_bottom_ = Length::Fixed();
  }



  // margin-left
  const Length& MarginLeft() const {
    return box_data_->margin_left_;
  }



  inline void ResetMarginLeft() {
    Access(box_data_, access_.box_data_)->margin_left_ = Length::Fixed();
  }



  // margin-right
  const Length& MarginRight() const {
    return box_data_->margin_right_;
  }



  inline void ResetMarginRight() {
    Access(box_data_, access_.box_data_)->margin_right_ = Length::Fixed();
  }



  // margin-top
  const Length& MarginTop() const {
    return box_data_->margin_top_;
  }



  inline void ResetMarginTop() {
    Access(box_data_, access_.box_data_)->margin_top_ = Length::Fixed();
  }



  // margin-trim
  unsigned MarginTrim() const {
    return static_cast<unsigned>(misc_data_->margin_trim_);
  }

  void SetMarginTrim(unsigned v) {
    if (!(misc_data_->margin_trim_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->margin_trim_ = static_cast<unsigned>(v);
  }

  inline void ResetMarginTrim() {
    Access(misc_data_, access_.misc_data_)->margin_trim_ = static_cast<unsigned>(kMarginTrimNone);
  }


  // marker-end
  StyleSVGResource* MarkerEndResource() const {
    return svginherited_data_->resources_data_->marker_end_resource_.Get();
  }

  void SetMarkerEndResource(Member<StyleSVGResource> v) {
    if (!(svginherited_data_->resources_data_->marker_end_resource_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->resources_data_, access_.resources_data_)->marker_end_resource_ = std::move(v);
  }


  // marker-mid
  StyleSVGResource* MarkerMidResource() const {
    return svginherited_data_->resources_data_->marker_mid_resource_.Get();
  }

  void SetMarkerMidResource(Member<StyleSVGResource> v) {
    if (!(svginherited_data_->resources_data_->marker_mid_resource_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->resources_data_, access_.resources_data_)->marker_mid_resource_ = std::move(v);
  }


  // marker-start
  StyleSVGResource* MarkerStartResource() const {
    return svginherited_data_->resources_data_->marker_start_resource_.Get();
  }

  void SetMarkerStartResource(Member<StyleSVGResource> v) {
    if (!(svginherited_data_->resources_data_->marker_start_resource_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->resources_data_, access_.resources_data_)->marker_start_resource_ = std::move(v);
  }


  // Mask
  


  inline void ResetMask() {
    Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->mask_ = FillLayer(EFillLayerType::kMask, true);
  }



  // MaskBoxImage
  


  inline void ResetMaskBoxImage() {
    Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->mask_box_image_ = NinePieceImage::MaskDefaults();
  }



  // mask-type
  EMaskType MaskType() const {
    return static_cast<EMaskType>(svg_data_->mask_type_);
  }

  void SetMaskType(EMaskType v) {
    if (!(svg_data_->mask_type_ == static_cast<unsigned>(v)))
      Access(svg_data_, access_.svg_data_)->mask_type_ = static_cast<unsigned>(v);
  }

  inline void ResetMaskType() {
    Access(svg_data_, access_.svg_data_)->mask_type_ = static_cast<unsigned>(EMaskType::kLuminance);
  }


  // MathBaseline
  const Length& GetMathBaseline() const {
    return misc_data_->math_data_->math_baseline_;
  }

  void SetMathBaseline(const Length& v) {
    if (!(misc_data_->math_data_->math_baseline_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_baseline_ = v;
  }

  void SetMathBaseline(Length&& v) {
    if (!(misc_data_->math_data_->math_baseline_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_baseline_ = std::move(v);
  }

  inline void ResetMathBaseline() {
    Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_baseline_ = Length();
  }



  // math-depth
  short MathDepth() const {
    return misc_inherited_data_->misc_inherited_1_data_->math_depth_;
  }

  void SetMathDepth(short v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->math_depth_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->math_depth_ = v;
  }

  inline void ResetMathDepth() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->math_depth_ = 0;
  }


  // MathFractionBarThickness
  const Length& GetMathFractionBarThickness() const {
    return misc_data_->math_data_->math_fraction_bar_thickness_;
  }

  void SetMathFractionBarThickness(const Length& v) {
    if (!(misc_data_->math_data_->math_fraction_bar_thickness_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_fraction_bar_thickness_ = v;
  }

  void SetMathFractionBarThickness(Length&& v) {
    if (!(misc_data_->math_data_->math_fraction_bar_thickness_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_fraction_bar_thickness_ = std::move(v);
  }

  inline void ResetMathFractionBarThickness() {
    Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_fraction_bar_thickness_ = Length();
  }



  // MathLSpace
  const Length& GetMathLSpace() const {
    return misc_data_->math_data_->math_l_space_;
  }

  void SetMathLSpace(const Length& v) {
    if (!(misc_data_->math_data_->math_l_space_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_l_space_ = v;
  }

  void SetMathLSpace(Length&& v) {
    if (!(misc_data_->math_data_->math_l_space_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_l_space_ = std::move(v);
  }

  inline void ResetMathLSpace() {
    Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_l_space_ = Length();
  }



  // MathMaxSize
  const Length& GetMathMaxSize() const {
    return misc_data_->math_data_->math_max_size_;
  }

  void SetMathMaxSize(const Length& v) {
    if (!(misc_data_->math_data_->math_max_size_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_max_size_ = v;
  }

  void SetMathMaxSize(Length&& v) {
    if (!(misc_data_->math_data_->math_max_size_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_max_size_ = std::move(v);
  }

  inline void ResetMathMaxSize() {
    Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_max_size_ = Length();
  }



  // MathMinSize
  const Length& GetMathMinSize() const {
    return misc_data_->math_data_->math_min_size_;
  }

  void SetMathMinSize(const Length& v) {
    if (!(misc_data_->math_data_->math_min_size_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_min_size_ = v;
  }

  void SetMathMinSize(Length&& v) {
    if (!(misc_data_->math_data_->math_min_size_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_min_size_ = std::move(v);
  }

  inline void ResetMathMinSize() {
    Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_min_size_ = Length();
  }



  // MathPaddedDepth
  const Length& GetMathPaddedDepth() const {
    return misc_data_->math_data_->math_padded_depth_;
  }

  void SetMathPaddedDepth(const Length& v) {
    if (!(misc_data_->math_data_->math_padded_depth_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_padded_depth_ = v;
  }

  void SetMathPaddedDepth(Length&& v) {
    if (!(misc_data_->math_data_->math_padded_depth_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_padded_depth_ = std::move(v);
  }

  inline void ResetMathPaddedDepth() {
    Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_padded_depth_ = Length();
  }



  // MathPaddedVOffset
  const Length& GetMathPaddedVOffset() const {
    return misc_data_->math_data_->math_padded_v_offset_;
  }

  void SetMathPaddedVOffset(const Length& v) {
    if (!(misc_data_->math_data_->math_padded_v_offset_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_padded_v_offset_ = v;
  }

  void SetMathPaddedVOffset(Length&& v) {
    if (!(misc_data_->math_data_->math_padded_v_offset_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_padded_v_offset_ = std::move(v);
  }

  inline void ResetMathPaddedVOffset() {
    Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_padded_v_offset_ = Length();
  }



  // MathRSpace
  const Length& GetMathRSpace() const {
    return misc_data_->math_data_->math_r_space_;
  }

  void SetMathRSpace(const Length& v) {
    if (!(misc_data_->math_data_->math_r_space_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_r_space_ = v;
  }

  void SetMathRSpace(Length&& v) {
    if (!(misc_data_->math_data_->math_r_space_ == v))
      Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_r_space_ = std::move(v);
  }

  inline void ResetMathRSpace() {
    Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_r_space_ = Length();
  }



  // math-shift
  EMathShift MathShift() const {
    return static_cast<EMathShift>(misc_inherited_data_->math_shift_);
  }

  void SetMathShift(EMathShift v) {
    if (!(misc_inherited_data_->math_shift_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->math_shift_ = static_cast<unsigned>(v);
  }

  inline void ResetMathShift() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->math_shift_ = static_cast<unsigned>(EMathShift::kNormal);
  }


  // math-style
  EMathStyle MathStyle() const {
    return static_cast<EMathStyle>(misc_inherited_data_->math_style_);
  }

  void SetMathStyle(EMathStyle v) {
    if (!(misc_inherited_data_->math_style_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->math_style_ = static_cast<unsigned>(v);
  }

  inline void ResetMathStyle() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->math_style_ = static_cast<unsigned>(EMathStyle::kNormal);
  }


  // max-content-sizing
  EMaxContentSizing MaxContentSizing() const {
    return static_cast<EMaxContentSizing>(misc_data_->max_content_sizing_);
  }

  void SetMaxContentSizing(EMaxContentSizing v) {
    if (!(misc_data_->max_content_sizing_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->max_content_sizing_ = static_cast<unsigned>(v);
  }

  inline void ResetMaxContentSizing() {
    Access(misc_data_, access_.misc_data_)->max_content_sizing_ = static_cast<unsigned>(EMaxContentSizing::kAuto);
  }


  // max-height
  const Length& MaxHeight() const {
    return box_data_->max_height_;
  }

  void SetMaxHeight(const Length& v) {
    if (!(box_data_->max_height_ == v))
      Access(box_data_, access_.box_data_)->max_height_ = v;
  }

  void SetMaxHeight(Length&& v) {
    if (!(box_data_->max_height_ == v))
      Access(box_data_, access_.box_data_)->max_height_ = std::move(v);
  }

  inline void ResetMaxHeight() {
    Access(box_data_, access_.box_data_)->max_height_ = Length::None();
  }



  // MaxLines
  const MaxLinesData& MaxLines() const {
    return misc_data_->misc_8_data_->max_lines_;
  }

  void SetMaxLines(const MaxLinesData& v) {
    if (!(misc_data_->misc_8_data_->max_lines_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->max_lines_ = v;
  }

  void SetMaxLines(MaxLinesData&& v) {
    if (!(misc_data_->misc_8_data_->max_lines_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->max_lines_ = std::move(v);
  }

  inline void ResetMaxLines() {
    Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->max_lines_ = MaxLinesData(0, true);
  }



  // max-width
  const Length& MaxWidth() const {
    return box_data_->max_width_;
  }

  void SetMaxWidth(const Length& v) {
    if (!(box_data_->max_width_ == v))
      Access(box_data_, access_.box_data_)->max_width_ = v;
  }

  void SetMaxWidth(Length&& v) {
    if (!(box_data_->max_width_ == v))
      Access(box_data_, access_.box_data_)->max_width_ = std::move(v);
  }

  inline void ResetMaxWidth() {
    Access(box_data_, access_.box_data_)->max_width_ = Length::None();
  }



  // MayHaveMargin
  bool MayHaveMargin() const {
    return static_cast<bool>(surround_data_->may_have_margin_);
  }

  void SetMayHaveMargin() {
    if (!(surround_data_->may_have_margin_ == static_cast<unsigned>(true)))
      Access(surround_data_, access_.surround_data_)->may_have_margin_ = static_cast<unsigned>(true);
  }


  // MayHavePadding
  bool MayHavePadding() const {
    return static_cast<bool>(surround_data_->may_have_padding_);
  }

  void SetMayHavePadding() {
    if (!(surround_data_->may_have_padding_ == static_cast<unsigned>(true)))
      Access(surround_data_, access_.surround_data_)->may_have_padding_ = static_cast<unsigned>(true);
  }


  // MaybeHasGapDecorations
  bool MaybeHasGapDecorations() const {
    return static_cast<bool>(visual_data_->maybe_has_gap_decorations_);
  }

  void SetMaybeHasGapDecorations() {
    if (!(visual_data_->maybe_has_gap_decorations_ == static_cast<unsigned>(true)))
      Access(visual_data_, access_.visual_data_)->maybe_has_gap_decorations_ = static_cast<unsigned>(true);
  }


  // min-height
  const Length& MinHeight() const {
    return box_data_->min_height_;
  }

  void SetMinHeight(const Length& v) {
    if (!(box_data_->min_height_ == v))
      Access(box_data_, access_.box_data_)->min_height_ = v;
  }

  void SetMinHeight(Length&& v) {
    if (!(box_data_->min_height_ == v))
      Access(box_data_, access_.box_data_)->min_height_ = std::move(v);
  }

  inline void ResetMinHeight() {
    Access(box_data_, access_.box_data_)->min_height_ = Length();
  }



  // min-width
  const Length& MinWidth() const {
    return box_data_->min_width_;
  }

  void SetMinWidth(const Length& v) {
    if (!(box_data_->min_width_ == v))
      Access(box_data_, access_.box_data_)->min_width_ = v;
  }

  void SetMinWidth(Length&& v) {
    if (!(box_data_->min_width_ == v))
      Access(box_data_, access_.box_data_)->min_width_ = std::move(v);
  }

  inline void ResetMinWidth() {
    Access(box_data_, access_.box_data_)->min_width_ = Length();
  }



  // NonInheritedVariables
  


  inline void ResetNonInheritedVariables() {
    Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->non_inherited_variables_ = StyleNonInheritedVariables();
  }



  // object-fit
  EObjectFit GetObjectFit() const {
    return static_cast<EObjectFit>(misc_data_->object_fit_);
  }

  void SetObjectFit(EObjectFit v) {
    if (!(misc_data_->object_fit_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->object_fit_ = static_cast<unsigned>(v);
  }

  inline void ResetObjectFit() {
    Access(misc_data_, access_.misc_data_)->object_fit_ = static_cast<unsigned>(EObjectFit::kFill);
  }


  // object-position
  const LengthPoint& ObjectPosition() const {
    return misc_data_->misc_3_data_->object_position_;
  }

  void SetObjectPosition(const LengthPoint& v) {
    if (!(misc_data_->misc_3_data_->object_position_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->object_position_ = v;
  }

  void SetObjectPosition(LengthPoint&& v) {
    if (!(misc_data_->misc_3_data_->object_position_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->object_position_ = std::move(v);
  }

  inline void ResetObjectPosition() {
    Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->object_position_ = LengthPoint(Length::Percent(50.0), Length::Percent(50.0));
  }



  // object-view-box
  BasicShape* ObjectViewBox() const {
    return misc_data_->misc_3_data_->object_view_box_.Get();
  }

  void SetObjectViewBox(Member<BasicShape> v) {
    if (!(misc_data_->misc_3_data_->object_view_box_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->object_view_box_ = std::move(v);
  }


  // offset-anchor
  const LengthPoint& OffsetAnchor() const {
    return misc_data_->misc_3_data_->offset_anchor_;
  }

  void SetOffsetAnchor(const LengthPoint& v) {
    if (!(misc_data_->misc_3_data_->offset_anchor_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->offset_anchor_ = v;
  }

  void SetOffsetAnchor(LengthPoint&& v) {
    if (!(misc_data_->misc_3_data_->offset_anchor_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->offset_anchor_ = std::move(v);
  }

  inline void ResetOffsetAnchor() {
    Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->offset_anchor_ = LengthPoint(Length::Auto(), Length::Auto());
  }



  // offset-distance
  const Length& OffsetDistance() const {
    return misc_data_->misc_4_data_->offset_distance_;
  }

  void SetOffsetDistance(const Length& v) {
    if (!(misc_data_->misc_4_data_->offset_distance_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->offset_distance_ = v;
  }

  void SetOffsetDistance(Length&& v) {
    if (!(misc_data_->misc_4_data_->offset_distance_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->offset_distance_ = std::move(v);
  }

  inline void ResetOffsetDistance() {
    Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->offset_distance_ = Length::Fixed(0);
  }



  // offset-path
  OffsetPathOperation* OffsetPath() const {
    return misc_data_->misc_4_data_->offset_path_.Get();
  }

  void SetOffsetPath(Member<OffsetPathOperation> v) {
    if (!(misc_data_->misc_4_data_->offset_path_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->offset_path_ = std::move(v);
  }


  // offset-position
  const LengthPoint& OffsetPosition() const {
    return misc_data_->misc_4_data_->offset_position_;
  }

  void SetOffsetPosition(const LengthPoint& v) {
    if (!(misc_data_->misc_4_data_->offset_position_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->offset_position_ = v;
  }

  void SetOffsetPosition(LengthPoint&& v) {
    if (!(misc_data_->misc_4_data_->offset_position_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->offset_position_ = std::move(v);
  }

  inline void ResetOffsetPosition() {
    Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->offset_position_ = LengthPoint(Length::None(), Length::None());
  }



  // offset-rotate
  const StyleOffsetRotation& OffsetRotate() const {
    return misc_data_->misc_4_data_->offset_rotate_;
  }

  void SetOffsetRotate(const StyleOffsetRotation& v) {
    if (!(misc_data_->misc_4_data_->offset_rotate_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->offset_rotate_ = v;
  }

  void SetOffsetRotate(StyleOffsetRotation&& v) {
    if (!(misc_data_->misc_4_data_->offset_rotate_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->offset_rotate_ = std::move(v);
  }

  inline void ResetOffsetRotate() {
    Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->offset_rotate_ = StyleOffsetRotation(0, OffsetRotationType::kAuto);
  }



  // opacity
  float Opacity() const {
    return svg_data_->opacity_;
  }


  inline void ResetOpacity() {
    Access(svg_data_, access_.svg_data_)->opacity_ = 1.0;
  }


  // order
  int Order() const {
    return misc_data_->misc_4_data_->order_;
  }

  void SetOrder(int v) {
    if (!(misc_data_->misc_4_data_->order_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->order_ = v;
  }

  inline void ResetOrder() {
    Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->order_ = 0;
  }


  // origin-trial-test-property
  EOriginTrialTestProperty OriginTrialTestProperty() const {
    return static_cast<EOriginTrialTestProperty>(data_.origin_trial_test_property_);
  }

  void SetOriginTrialTestProperty(EOriginTrialTestProperty v) {
    data_.origin_trial_test_property_ = static_cast<unsigned>(v);
  }

  inline void ResetOriginTrialTestProperty() {
    data_.origin_trial_test_property_ = static_cast<unsigned>(EOriginTrialTestProperty::kNormal);
  }


  // orphans
  short Orphans() const {
    return misc_inherited_data_->misc_inherited_1_data_->orphans_;
  }


  inline void ResetOrphans() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->orphans_ = 2;
  }


  // outline-color
  
  void SetOutlineColor(const StyleColor& v) {
    if (!(misc_data_->misc_4_data_->outline_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->outline_color_ = v;
  }

  void SetOutlineColor(StyleColor&& v) {
    if (!(misc_data_->misc_4_data_->outline_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->outline_color_ = std::move(v);
  }

  inline void ResetOutlineColor() {
    Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->outline_color_ = StyleColor::CurrentColor();
  }



  // outline-offset
  const int& OutlineOffset() const {
    return misc_data_->misc_4_data_->outline_offset_;
  }

  void SetOutlineOffset(const int& v) {
    if (!(misc_data_->misc_4_data_->outline_offset_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->outline_offset_ = v;
  }

  void SetOutlineOffset(int&& v) {
    if (!(misc_data_->misc_4_data_->outline_offset_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->outline_offset_ = std::move(v);
  }

  inline void ResetOutlineOffset() {
    Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->outline_offset_ = 0;
  }



  // outline-style
  EBorderStyle OutlineStyle() const {
    return static_cast<EBorderStyle>(misc_data_->outline_style_);
  }

  void SetOutlineStyle(EBorderStyle v) {
    if (!(misc_data_->outline_style_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->outline_style_ = static_cast<unsigned>(v);
  }

  inline void ResetOutlineStyle() {
    Access(misc_data_, access_.misc_data_)->outline_style_ = static_cast<unsigned>(EBorderStyle::kNone);
  }


  // OutlineStyleIsAuto
  bool OutlineStyleIsAuto() const {
    return static_cast<bool>(misc_data_->outline_style_is_auto_);
  }

  void SetOutlineStyleIsAuto(bool v) {
    if (!(misc_data_->outline_style_is_auto_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->outline_style_is_auto_ = static_cast<unsigned>(v);
  }

  inline void ResetOutlineStyleIsAuto() {
    Access(misc_data_, access_.misc_data_)->outline_style_is_auto_ = static_cast<unsigned>(false);
  }


  // outline-width
  const int& OutlineWidth() const {
    return misc_data_->misc_4_data_->outline_width_;
  }

  void SetOutlineWidth(const int& v) {
    if (!(misc_data_->misc_4_data_->outline_width_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->outline_width_ = v;
  }

  void SetOutlineWidth(int&& v) {
    if (!(misc_data_->misc_4_data_->outline_width_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->outline_width_ = std::move(v);
  }

  inline void ResetOutlineWidth() {
    Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->outline_width_ = 3;
  }



  // overflow-anchor
  EOverflowAnchor OverflowAnchor() const {
    return static_cast<EOverflowAnchor>(data_.overflow_anchor_);
  }

  void SetOverflowAnchor(EOverflowAnchor v) {
    data_.overflow_anchor_ = static_cast<unsigned>(v);
  }

  inline void ResetOverflowAnchor() {
    data_.overflow_anchor_ = static_cast<unsigned>(EOverflowAnchor::kAuto);
  }


  // overflow-clip-margin
  const std::optional<StyleOverflowClipMargin>& OverflowClipMargin() const {
    return box_data_->overflow_clip_margin_;
  }

  void SetOverflowClipMargin(const std::optional<StyleOverflowClipMargin>& v) {
    if (!(box_data_->overflow_clip_margin_ == v))
      Access(box_data_, access_.box_data_)->overflow_clip_margin_ = v;
  }

  void SetOverflowClipMargin(std::optional<StyleOverflowClipMargin>&& v) {
    if (!(box_data_->overflow_clip_margin_ == v))
      Access(box_data_, access_.box_data_)->overflow_clip_margin_ = std::move(v);
  }

  inline void ResetOverflowClipMargin() {
    Access(box_data_, access_.box_data_)->overflow_clip_margin_ = std::nullopt;
  }



  // overflow-wrap
  EOverflowWrap OverflowWrap() const {
    return static_cast<EOverflowWrap>(misc_inherited_data_->overflow_wrap_);
  }

  void SetOverflowWrap(EOverflowWrap v) {
    if (!(misc_inherited_data_->overflow_wrap_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->overflow_wrap_ = static_cast<unsigned>(v);
  }

  inline void ResetOverflowWrap() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->overflow_wrap_ = static_cast<unsigned>(EOverflowWrap::kNormal);
  }


  // overflow-x
  EOverflow OverflowX() const {
    return static_cast<EOverflow>(data_.overflow_x_);
  }

  void SetOverflowX(EOverflow v) {
    data_.overflow_x_ = static_cast<unsigned>(v);
  }

  inline void ResetOverflowX() {
    data_.overflow_x_ = static_cast<unsigned>(EOverflow::kVisible);
  }


  // overflow-y
  EOverflow OverflowY() const {
    return static_cast<EOverflow>(data_.overflow_y_);
  }

  void SetOverflowY(EOverflow v) {
    data_.overflow_y_ = static_cast<unsigned>(v);
  }

  inline void ResetOverflowY() {
    data_.overflow_y_ = static_cast<unsigned>(EOverflow::kVisible);
  }


  // overlay
  EOverlay Overlay() const {
    return static_cast<EOverlay>(misc_data_->overlay_);
  }

  void SetOverlay(EOverlay v) {
    if (!(misc_data_->overlay_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->overlay_ = static_cast<unsigned>(v);
  }

  inline void ResetOverlay() {
    Access(misc_data_, access_.misc_data_)->overlay_ = static_cast<unsigned>(EOverlay::kNone);
  }


  // overscroll-behavior-x
  EOverscrollBehavior OverscrollBehaviorX() const {
    return static_cast<EOverscrollBehavior>(misc_data_->overscroll_behavior_x_);
  }

  void SetOverscrollBehaviorX(EOverscrollBehavior v) {
    if (!(misc_data_->overscroll_behavior_x_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->overscroll_behavior_x_ = static_cast<unsigned>(v);
  }

  inline void ResetOverscrollBehaviorX() {
    Access(misc_data_, access_.misc_data_)->overscroll_behavior_x_ = static_cast<unsigned>(EOverscrollBehavior::kAuto);
  }


  // overscroll-behavior-y
  EOverscrollBehavior OverscrollBehaviorY() const {
    return static_cast<EOverscrollBehavior>(misc_data_->overscroll_behavior_y_);
  }

  void SetOverscrollBehaviorY(EOverscrollBehavior v) {
    if (!(misc_data_->overscroll_behavior_y_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->overscroll_behavior_y_ = static_cast<unsigned>(v);
  }

  inline void ResetOverscrollBehaviorY() {
    Access(misc_data_, access_.misc_data_)->overscroll_behavior_y_ = static_cast<unsigned>(EOverscrollBehavior::kAuto);
  }


  // overscroll-container-type
  EOverscrollContainerType OverscrollContainerType() const {
    return static_cast<EOverscrollContainerType>(misc_data_->overscroll_container_type_);
  }

  void SetOverscrollContainerType(EOverscrollContainerType v) {
    if (!(misc_data_->overscroll_container_type_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->overscroll_container_type_ = static_cast<unsigned>(v);
  }

  inline void ResetOverscrollContainerType() {
    Access(misc_data_, access_.misc_data_)->overscroll_container_type_ = static_cast<unsigned>(EOverscrollContainerType::kAuto);
  }


  // padding-bottom
  const Length& PaddingBottom() const {
    return box_data_->padding_bottom_;
  }



  inline void ResetPaddingBottom() {
    Access(box_data_, access_.box_data_)->padding_bottom_ = Length::Fixed();
  }



  // padding-left
  const Length& PaddingLeft() const {
    return box_data_->padding_left_;
  }



  inline void ResetPaddingLeft() {
    Access(box_data_, access_.box_data_)->padding_left_ = Length::Fixed();
  }



  // padding-right
  const Length& PaddingRight() const {
    return box_data_->padding_right_;
  }



  inline void ResetPaddingRight() {
    Access(box_data_, access_.box_data_)->padding_right_ = Length::Fixed();
  }



  // padding-top
  const Length& PaddingTop() const {
    return box_data_->padding_top_;
  }



  inline void ResetPaddingTop() {
    Access(box_data_, access_.box_data_)->padding_top_ = Length::Fixed();
  }



  // page
  const AtomicString& Page() const {
    return misc_data_->misc_4_data_->page_;
  }

  void SetPage(const AtomicString& v) {
    if (!(misc_data_->misc_4_data_->page_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->page_ = v;
  }

  void SetPage(AtomicString&& v) {
    if (!(misc_data_->misc_4_data_->page_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->page_ = std::move(v);
  }

  inline void ResetPage() {
    Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->page_ = AtomicString();
  }



  // page-margin-safety
  EPageMarginSafety GetPageMarginSafety() const {
    return static_cast<EPageMarginSafety>(misc_data_->page_margin_safety_);
  }


  inline void ResetPageMarginSafety() {
    Access(misc_data_, access_.misc_data_)->page_margin_safety_ = static_cast<unsigned>(EPageMarginSafety::kNone);
  }


  // page-orientation
  PageOrientation GetPageOrientation() const {
    return static_cast<PageOrientation>(misc_data_->page_orientation_);
  }

  void SetPageOrientation(PageOrientation v) {
    if (!(misc_data_->page_orientation_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->page_orientation_ = static_cast<unsigned>(v);
  }

  inline void ResetPageOrientation() {
    Access(misc_data_, access_.misc_data_)->page_orientation_ = static_cast<unsigned>(PageOrientation::kUpright);
  }


  // PageSize
  const gfx::SizeF& PageSize() const {
    return misc_data_->misc_7_data_->page_size_;
  }

  void SetPageSize(const gfx::SizeF& v) {
    if (!(misc_data_->misc_7_data_->page_size_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->page_size_ = v;
  }

  void SetPageSize(gfx::SizeF&& v) {
    if (!(misc_data_->misc_7_data_->page_size_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->page_size_ = std::move(v);
  }

  inline void ResetPageSize() {
    Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->page_size_ = gfx::SizeF();
  }



  // PageSizeType
  PageSizeType GetPageSizeType() const {
    return static_cast<PageSizeType>(misc_data_->page_size_type_);
  }

  void SetPageSizeType(PageSizeType v) {
    if (!(misc_data_->page_size_type_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->page_size_type_ = static_cast<unsigned>(v);
  }

  inline void ResetPageSizeType() {
    Access(misc_data_, access_.misc_data_)->page_size_type_ = static_cast<unsigned>(PageSizeType::kAuto);
  }


  // PaintImages
  


  inline void ResetPaintImages() {
    Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->paint_images_ = nullptr;
  }



  // paint-order
  EPaintOrder PaintOrder() const {
    return static_cast<EPaintOrder>(svginherited_data_->paint_order_);
  }

  void SetPaintOrder(EPaintOrder v) {
    if (!(svginherited_data_->paint_order_ == static_cast<unsigned>(v)))
      Access(svginherited_data_, access_.svginherited_data_)->paint_order_ = static_cast<unsigned>(v);
  }

  inline void ResetPaintOrder() {
    Access(svginherited_data_, access_.svginherited_data_)->paint_order_ = static_cast<unsigned>(kPaintOrderNormal);
  }


  // path-length
  const Length& PathLength() const {
    return svg_data_->geometry_data_->path_length_;
  }

  void SetPathLength(const Length& v) {
    if (!(svg_data_->geometry_data_->path_length_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->path_length_ = v;
  }

  void SetPathLength(Length&& v) {
    if (!(svg_data_->geometry_data_->path_length_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->path_length_ = std::move(v);
  }

  inline void ResetPathLength() {
    Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->path_length_ = Length::None();
  }



  // perspective
  float Perspective() const {
    return misc_data_->misc_4_data_->perspective_;
  }

  void SetPerspective(float v) {
    if (!(misc_data_->misc_4_data_->perspective_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->perspective_ = v;
  }

  inline void ResetPerspective() {
    Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->perspective_ = -1.0;
  }


  // perspective-origin
  const LengthPoint& PerspectiveOrigin() const {
    return misc_data_->misc_4_data_->perspective_origin_;
  }

  void SetPerspectiveOrigin(const LengthPoint& v) {
    if (!(misc_data_->misc_4_data_->perspective_origin_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->perspective_origin_ = v;
  }

  void SetPerspectiveOrigin(LengthPoint&& v) {
    if (!(misc_data_->misc_4_data_->perspective_origin_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->perspective_origin_ = std::move(v);
  }

  inline void ResetPerspectiveOrigin() {
    Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->perspective_origin_ = LengthPoint(Length::Percent(50.0), Length::Percent(50.0));
  }



  // pointer-events
  
  void SetPointerEvents(EPointerEvents v) {
    data_.pointer_events_ = static_cast<unsigned>(v);
  }

  inline void ResetPointerEvents() {
    data_.pointer_events_ = static_cast<unsigned>(EPointerEvents::kAuto);
  }


  // pointer-events
  
  void SetPointerEventsIsInherited(bool v) {
    data_.pointer_events_is_inherited_ = static_cast<unsigned>(v);
  }

  inline void ResetPointerEventsIsInherited() {
    data_.pointer_events_is_inherited_ = static_cast<unsigned>(true);
  }


  // position
  
  void SetPosition(EPosition v) {
    data_.position_ = static_cast<unsigned>(v);
  }

  inline void ResetPosition() {
    data_.position_ = static_cast<unsigned>(EPosition::kStatic);
  }


  // position-anchor
  const StylePositionAnchor& PositionAnchor() const {
    return misc_data_->misc_1_data_->position_anchor_;
  }

  void SetPositionAnchor(const StylePositionAnchor& v) {
    if (!(misc_data_->misc_1_data_->position_anchor_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->position_anchor_ = v;
  }

  void SetPositionAnchor(StylePositionAnchor&& v) {
    if (!(misc_data_->misc_1_data_->position_anchor_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->position_anchor_ = std::move(v);
  }

  inline void ResetPositionAnchor() {
    Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->position_anchor_ = StylePositionAnchor::Initial();
  }



  // position-area
  const PositionArea& GetPositionArea() const {
    return misc_data_->misc_1_data_->position_area_;
  }

  void SetPositionArea(const PositionArea& v) {
    if (!(misc_data_->misc_1_data_->position_area_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->position_area_ = v;
  }

  void SetPositionArea(PositionArea&& v) {
    if (!(misc_data_->misc_1_data_->position_area_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->position_area_ = std::move(v);
  }

  inline void ResetPositionArea() {
    Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->position_area_ = PositionArea();
  }



  // PositionAreaOffsets
  const std::optional<blink::PositionAreaOffsets>& PositionAreaOffsets() const {
    return misc_data_->misc_8_data_->position_area_offsets_;
  }

  void SetPositionAreaOffsets(const std::optional<blink::PositionAreaOffsets>& v) {
    if (!(misc_data_->misc_8_data_->position_area_offsets_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->position_area_offsets_ = v;
  }

  void SetPositionAreaOffsets(std::optional<blink::PositionAreaOffsets>&& v) {
    if (!(misc_data_->misc_8_data_->position_area_offsets_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->position_area_offsets_ = std::move(v);
  }

  inline void ResetPositionAreaOffsets() {
    Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->position_area_offsets_ = std::nullopt;
  }



  // position-try-fallbacks
  const Member<PositionTryFallbacks>& GetPositionTryFallbacks() const {
    return misc_data_->misc_4_data_->position_try_fallbacks_;
  }

  void SetPositionTryFallbacks(const Member<PositionTryFallbacks>& v) {
    if (!(misc_data_->misc_4_data_->position_try_fallbacks_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->position_try_fallbacks_ = v;
  }

  void SetPositionTryFallbacks(Member<PositionTryFallbacks>&& v) {
    if (!(misc_data_->misc_4_data_->position_try_fallbacks_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->position_try_fallbacks_ = std::move(v);
  }

  inline void ResetPositionTryFallbacks() {
    Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->position_try_fallbacks_ = nullptr;
  }



  // position-try-order
  EPositionTryOrder PositionTryOrder() const {
    return static_cast<EPositionTryOrder>(misc_data_->position_try_order_);
  }

  void SetPositionTryOrder(EPositionTryOrder v) {
    if (!(misc_data_->position_try_order_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->position_try_order_ = static_cast<unsigned>(v);
  }

  inline void ResetPositionTryOrder() {
    Access(misc_data_, access_.misc_data_)->position_try_order_ = static_cast<unsigned>(EPositionTryOrder::kNormal);
  }


  // position-visibility
  PositionVisibility GetPositionVisibility() const {
    return static_cast<PositionVisibility>(misc_data_->position_visibility_);
  }

  void SetPositionVisibility(PositionVisibility v) {
    if (!(misc_data_->position_visibility_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->position_visibility_ = static_cast<unsigned>(v);
  }

  inline void ResetPositionVisibility() {
    Access(misc_data_, access_.misc_data_)->position_visibility_ = static_cast<unsigned>(PositionVisibility::kAnchorsVisible);
  }


  // PrefersDefaultScrollbarStyles
  bool PrefersDefaultScrollbarStyles() const {
    return static_cast<bool>(data_.prefers_default_scrollbar_styles_);
  }

  void SetPrefersDefaultScrollbarStyles(bool v) {
    data_.prefers_default_scrollbar_styles_ = static_cast<unsigned>(v);
  }

  inline void ResetPrefersDefaultScrollbarStyles() {
    data_.prefers_default_scrollbar_styles_ = static_cast<unsigned>(false);
  }


  // print-color-adjust
  EPrintColorAdjust PrintColorAdjust() const {
    return static_cast<EPrintColorAdjust>(data_.print_color_adjust_);
  }

  void SetPrintColorAdjust(EPrintColorAdjust v) {
    data_.print_color_adjust_ = static_cast<unsigned>(v);
  }

  inline void ResetPrintColorAdjust() {
    data_.print_color_adjust_ = static_cast<unsigned>(EPrintColorAdjust::kEconomy);
  }


  // PseudoElementStyles
  
  void SetPseudoElementStyles(unsigned v) {
    data_.pseudo_element_styles_ = static_cast<unsigned>(v);
  }

  inline void ResetPseudoElementStyles() {
    data_.pseudo_element_styles_ = static_cast<unsigned>(kPseudoIdNone);
  }


  // quotes
  QuotesData* Quotes() const {
    return misc_inherited_data_->misc_inherited_1_data_->quotes_.get();
  }

  void SetQuotes(scoped_refptr<QuotesData> v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->quotes_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->quotes_ = std::move(v);
  }


  // r
  const Length& R() const {
    return svg_data_->geometry_data_->r_;
  }

  void SetR(const Length& v) {
    if (!(svg_data_->geometry_data_->r_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->r_ = v;
  }

  void SetR(Length&& v) {
    if (!(svg_data_->geometry_data_->r_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->r_ = std::move(v);
  }

  inline void ResetR() {
    Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->r_ = Length::Fixed();
  }



  // reading-flow
  EReadingFlow ReadingFlow() const {
    return static_cast<EReadingFlow>(misc_data_->reading_flow_);
  }

  void SetReadingFlow(EReadingFlow v) {
    if (!(misc_data_->reading_flow_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->reading_flow_ = static_cast<unsigned>(v);
  }

  inline void ResetReadingFlow() {
    Access(misc_data_, access_.misc_data_)->reading_flow_ = static_cast<unsigned>(EReadingFlow::kNormal);
  }


  // reading-order
  int ReadingOrder() const {
    return misc_data_->misc_4_data_->reading_order_;
  }

  void SetReadingOrder(int v) {
    if (!(misc_data_->misc_4_data_->reading_order_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->reading_order_ = v;
  }

  inline void ResetReadingOrder() {
    Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->reading_order_ = 0;
  }


  // RequiresAcceleratedCompositingForExternalReasons
  bool RequiresAcceleratedCompositingForExternalReasons() const {
    return static_cast<bool>(misc_data_->requires_accelerated_compositing_for_external_reasons_);
  }

  void SetRequiresAcceleratedCompositingForExternalReasons(bool v) {
    if (!(misc_data_->requires_accelerated_compositing_for_external_reasons_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->requires_accelerated_compositing_for_external_reasons_ = static_cast<unsigned>(v);
  }

  inline void ResetRequiresAcceleratedCompositingForExternalReasons() {
    Access(misc_data_, access_.misc_data_)->requires_accelerated_compositing_for_external_reasons_ = static_cast<unsigned>(false);
  }


  // resize
  
  void SetResize(EResize v) {
    if (!(misc_data_->resize_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->resize_ = static_cast<unsigned>(v);
  }

  inline void ResetResize() {
    Access(misc_data_, access_.misc_data_)->resize_ = static_cast<unsigned>(EResize::kNone);
  }


  // right
  const Length& Right() const {
    return surround_data_->right_;
  }

  void SetRight(const Length& v) {
    if (!(surround_data_->right_ == v))
      Access(surround_data_, access_.surround_data_)->right_ = v;
  }

  void SetRight(Length&& v) {
    if (!(surround_data_->right_ == v))
      Access(surround_data_, access_.surround_data_)->right_ = std::move(v);
  }

  inline void ResetRight() {
    Access(surround_data_, access_.surround_data_)->right_ = Length();
  }



  // rotate
  RotateTransformOperation* Rotate() const {
    return misc_data_->misc_4_data_->rotate_.Get();
  }

  void SetRotate(Member<RotateTransformOperation> v) {
    if (!(misc_data_->misc_4_data_->rotate_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->rotate_ = std::move(v);
  }


  // row-gap
  const std::optional<Length>& RowGap() const {
    return misc_data_->misc_4_data_->row_gap_;
  }

  void SetRowGap(const std::optional<Length>& v) {
    if (!(misc_data_->misc_4_data_->row_gap_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->row_gap_ = v;
  }

  void SetRowGap(std::optional<Length>&& v) {
    if (!(misc_data_->misc_4_data_->row_gap_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->row_gap_ = std::move(v);
  }

  inline void ResetRowGap() {
    Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->row_gap_ = std::nullopt;
  }



  // row-rule-break
  RuleBreak RowRuleBreak() const {
    return static_cast<RuleBreak>(misc_data_->row_rule_break_);
  }

  void SetRowRuleBreak(RuleBreak v) {
    if (!(misc_data_->row_rule_break_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->row_rule_break_ = static_cast<unsigned>(v);
  }

  inline void ResetRowRuleBreak() {
    Access(misc_data_, access_.misc_data_)->row_rule_break_ = static_cast<unsigned>(RuleBreak::kNormal);
  }


  // row-rule-color
  const GapDataList<StyleColor>& RowRuleColor() const {
    return misc_data_->misc_4_data_->row_rule_color_;
  }



  inline void ResetRowRuleColor() {
    Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->row_rule_color_ = GapDataList<StyleColor>::DefaultGapColorDataList();
  }



  // row-rule-inset-cap-end
  const Length& RowRuleInsetCapEnd() const {
    return misc_data_->misc_5_data_->row_rule_inset_cap_end_;
  }

  void SetRowRuleInsetCapEnd(const Length& v) {
    if (!(misc_data_->misc_5_data_->row_rule_inset_cap_end_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_cap_end_ = v;
  }

  void SetRowRuleInsetCapEnd(Length&& v) {
    if (!(misc_data_->misc_5_data_->row_rule_inset_cap_end_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_cap_end_ = std::move(v);
  }

  inline void ResetRowRuleInsetCapEnd() {
    Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_cap_end_ = Length::Fixed(0);
  }



  // row-rule-inset-cap-start
  const Length& RowRuleInsetCapStart() const {
    return misc_data_->misc_5_data_->row_rule_inset_cap_start_;
  }

  void SetRowRuleInsetCapStart(const Length& v) {
    if (!(misc_data_->misc_5_data_->row_rule_inset_cap_start_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_cap_start_ = v;
  }

  void SetRowRuleInsetCapStart(Length&& v) {
    if (!(misc_data_->misc_5_data_->row_rule_inset_cap_start_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_cap_start_ = std::move(v);
  }

  inline void ResetRowRuleInsetCapStart() {
    Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_cap_start_ = Length::Fixed(0);
  }



  // row-rule-inset-junction-end
  const Length& RowRuleInsetJunctionEnd() const {
    return misc_data_->misc_5_data_->row_rule_inset_junction_end_;
  }

  void SetRowRuleInsetJunctionEnd(const Length& v) {
    if (!(misc_data_->misc_5_data_->row_rule_inset_junction_end_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_junction_end_ = v;
  }

  void SetRowRuleInsetJunctionEnd(Length&& v) {
    if (!(misc_data_->misc_5_data_->row_rule_inset_junction_end_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_junction_end_ = std::move(v);
  }

  inline void ResetRowRuleInsetJunctionEnd() {
    Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_junction_end_ = Length::Fixed(0);
  }



  // row-rule-inset-junction-start
  const Length& RowRuleInsetJunctionStart() const {
    return misc_data_->misc_5_data_->row_rule_inset_junction_start_;
  }

  void SetRowRuleInsetJunctionStart(const Length& v) {
    if (!(misc_data_->misc_5_data_->row_rule_inset_junction_start_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_junction_start_ = v;
  }

  void SetRowRuleInsetJunctionStart(Length&& v) {
    if (!(misc_data_->misc_5_data_->row_rule_inset_junction_start_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_junction_start_ = std::move(v);
  }

  inline void ResetRowRuleInsetJunctionStart() {
    Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_junction_start_ = Length::Fixed(0);
  }



  // row-rule-style
  const GapDataList<EBorderStyle>& RowRuleStyle() const {
    return misc_data_->misc_5_data_->row_rule_style_;
  }



  inline void ResetRowRuleStyle() {
    Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_style_ = GapDataList<EBorderStyle>::DefaultGapStyleDataList();
  }



  // row-rule-visibility-items
  RuleVisibilityItems RowRuleVisibilityItems() const {
    return static_cast<RuleVisibilityItems>(misc_data_->row_rule_visibility_items_);
  }

  void SetRowRuleVisibilityItems(RuleVisibilityItems v) {
    if (!(misc_data_->row_rule_visibility_items_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->row_rule_visibility_items_ = static_cast<unsigned>(v);
  }

  inline void ResetRowRuleVisibilityItems() {
    Access(misc_data_, access_.misc_data_)->row_rule_visibility_items_ = static_cast<unsigned>(RuleVisibilityItems::kNormal);
  }


  // row-rule-width
  const GapDataList<int>& RowRuleWidth() const {
    return misc_data_->misc_5_data_->row_rule_width_;
  }



  inline void ResetRowRuleWidth() {
    Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_width_ = ComputedStyleInitialValues::InitialRowRuleWidth();
  }



  // -webkit-rtl-ordering
  EOrder RtlOrdering() const {
    return static_cast<EOrder>(data_.rtl_ordering_);
  }

  void SetRtlOrdering(EOrder v) {
    data_.rtl_ordering_ = static_cast<unsigned>(v);
  }

  inline void ResetRtlOrdering() {
    data_.rtl_ordering_ = static_cast<unsigned>(EOrder::kLogical);
  }


  // -webkit-rtl-ordering
  bool RtlOrderingIsInherited() const {
    return static_cast<bool>(data_.rtl_ordering_is_inherited_);
  }

  void SetRtlOrderingIsInherited(bool v) {
    data_.rtl_ordering_is_inherited_ = static_cast<unsigned>(v);
  }

  inline void ResetRtlOrderingIsInherited() {
    data_.rtl_ordering_is_inherited_ = static_cast<unsigned>(true);
  }


  // ruby-align
  ERubyAlign RubyAlign() const {
    return static_cast<ERubyAlign>(misc_inherited_data_->ruby_align_);
  }

  void SetRubyAlign(ERubyAlign v) {
    if (!(misc_inherited_data_->ruby_align_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->ruby_align_ = static_cast<unsigned>(v);
  }

  inline void ResetRubyAlign() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->ruby_align_ = static_cast<unsigned>(ERubyAlign::kSpaceAround);
  }


  // ruby-overhang
  ERubyOverhang RubyOverhang() const {
    return static_cast<ERubyOverhang>(misc_inherited_data_->ruby_overhang_);
  }

  void SetRubyOverhang(ERubyOverhang v) {
    if (!(misc_inherited_data_->ruby_overhang_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->ruby_overhang_ = static_cast<unsigned>(v);
  }

  inline void ResetRubyOverhang() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->ruby_overhang_ = static_cast<unsigned>(ERubyOverhang::kAuto);
  }


  // ruby-position
  RubyPosition GetRubyPosition() const {
    return static_cast<RubyPosition>(misc_inherited_data_->ruby_position_);
  }

  void SetRubyPosition(RubyPosition v) {
    if (!(misc_inherited_data_->ruby_position_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->ruby_position_ = static_cast<unsigned>(v);
  }

  inline void ResetRubyPosition() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->ruby_position_ = static_cast<unsigned>(RubyPosition::kOver);
  }


  // rule-overlap
  ERuleOverlap RuleOverlap() const {
    return static_cast<ERuleOverlap>(misc_data_->rule_overlap_);
  }

  void SetRuleOverlap(ERuleOverlap v) {
    if (!(misc_data_->rule_overlap_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->rule_overlap_ = static_cast<unsigned>(v);
  }

  inline void ResetRuleOverlap() {
    Access(misc_data_, access_.misc_data_)->rule_overlap_ = static_cast<unsigned>(ERuleOverlap::kRowOverColumn);
  }


  // rx
  const Length& Rx() const {
    return svg_data_->geometry_data_->rx_;
  }

  void SetRx(const Length& v) {
    if (!(svg_data_->geometry_data_->rx_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->rx_ = v;
  }

  void SetRx(Length&& v) {
    if (!(svg_data_->geometry_data_->rx_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->rx_ = std::move(v);
  }

  inline void ResetRx() {
    Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->rx_ = Length::Auto();
  }



  // ry
  const Length& Ry() const {
    return svg_data_->geometry_data_->ry_;
  }

  void SetRy(const Length& v) {
    if (!(svg_data_->geometry_data_->ry_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->ry_ = v;
  }

  void SetRy(Length&& v) {
    if (!(svg_data_->geometry_data_->ry_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->ry_ = std::move(v);
  }

  inline void ResetRy() {
    Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->ry_ = Length::Auto();
  }



  // scale
  ScaleTransformOperation* Scale() const {
    return misc_data_->misc_5_data_->scale_.Get();
  }

  void SetScale(Member<ScaleTransformOperation> v) {
    if (!(misc_data_->misc_5_data_->scale_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scale_ = std::move(v);
  }


  // scroll-axis-lock
  EScrollAxisLock ScrollAxisLock() const {
    return static_cast<EScrollAxisLock>(misc_data_->scroll_axis_lock_);
  }

  void SetScrollAxisLock(EScrollAxisLock v) {
    if (!(misc_data_->scroll_axis_lock_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->scroll_axis_lock_ = static_cast<unsigned>(v);
  }

  inline void ResetScrollAxisLock() {
    Access(misc_data_, access_.misc_data_)->scroll_axis_lock_ = static_cast<unsigned>(EScrollAxisLock::kAuto);
  }


  // scroll-behavior
  mojom::blink::ScrollBehavior GetScrollBehavior() const {
    return static_cast<mojom::blink::ScrollBehavior>(misc_data_->scroll_behavior_);
  }

  void SetScrollBehavior(mojom::blink::ScrollBehavior v) {
    if (!(misc_data_->scroll_behavior_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->scroll_behavior_ = static_cast<unsigned>(v);
  }

  inline void ResetScrollBehavior() {
    Access(misc_data_, access_.misc_data_)->scroll_behavior_ = static_cast<unsigned>(mojom::blink::ScrollBehavior::kAuto);
  }


  // scroll-initial-target
  EScrollInitialTarget ScrollInitialTarget() const {
    return static_cast<EScrollInitialTarget>(misc_data_->scroll_initial_target_);
  }

  void SetScrollInitialTarget(EScrollInitialTarget v) {
    if (!(misc_data_->scroll_initial_target_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->scroll_initial_target_ = static_cast<unsigned>(v);
  }

  inline void ResetScrollInitialTarget() {
    Access(misc_data_, access_.misc_data_)->scroll_initial_target_ = static_cast<unsigned>(EScrollInitialTarget::kNone);
  }


  // scroll-margin-bottom
  float ScrollMarginBottom() const {
    return misc_data_->misc_5_data_->scroll_margin_bottom_;
  }

  void SetScrollMarginBottom(float v) {
    if (!(misc_data_->misc_5_data_->scroll_margin_bottom_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_margin_bottom_ = v;
  }

  inline void ResetScrollMarginBottom() {
    Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_margin_bottom_ = 0.0f;
  }


  // scroll-margin-left
  float ScrollMarginLeft() const {
    return misc_data_->misc_5_data_->scroll_margin_left_;
  }

  void SetScrollMarginLeft(float v) {
    if (!(misc_data_->misc_5_data_->scroll_margin_left_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_margin_left_ = v;
  }

  inline void ResetScrollMarginLeft() {
    Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_margin_left_ = 0.0f;
  }


  // scroll-margin-right
  float ScrollMarginRight() const {
    return misc_data_->misc_5_data_->scroll_margin_right_;
  }

  void SetScrollMarginRight(float v) {
    if (!(misc_data_->misc_5_data_->scroll_margin_right_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_margin_right_ = v;
  }

  inline void ResetScrollMarginRight() {
    Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_margin_right_ = 0.0f;
  }


  // scroll-margin-top
  float ScrollMarginTop() const {
    return misc_data_->misc_5_data_->scroll_margin_top_;
  }

  void SetScrollMarginTop(float v) {
    if (!(misc_data_->misc_5_data_->scroll_margin_top_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_margin_top_ = v;
  }

  inline void ResetScrollMarginTop() {
    Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_margin_top_ = 0.0f;
  }


  // scroll-marker-group
  ScrollMarkerGroup* GetScrollMarkerGroup() const {
    return misc_data_->misc_5_data_->scroll_marker_group_.Get();
  }

  void SetScrollMarkerGroup(Member<ScrollMarkerGroup> v) {
    if (!(misc_data_->misc_5_data_->scroll_marker_group_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_marker_group_ = std::move(v);
  }


  // scroll-padding-bottom
  const Length& ScrollPaddingBottom() const {
    return misc_data_->misc_5_data_->scroll_padding_bottom_;
  }

  void SetScrollPaddingBottom(const Length& v) {
    if (!(misc_data_->misc_5_data_->scroll_padding_bottom_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_bottom_ = v;
  }

  void SetScrollPaddingBottom(Length&& v) {
    if (!(misc_data_->misc_5_data_->scroll_padding_bottom_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_bottom_ = std::move(v);
  }

  inline void ResetScrollPaddingBottom() {
    Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_bottom_ = Length();
  }



  // scroll-padding-left
  const Length& ScrollPaddingLeft() const {
    return misc_data_->misc_5_data_->scroll_padding_left_;
  }

  void SetScrollPaddingLeft(const Length& v) {
    if (!(misc_data_->misc_5_data_->scroll_padding_left_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_left_ = v;
  }

  void SetScrollPaddingLeft(Length&& v) {
    if (!(misc_data_->misc_5_data_->scroll_padding_left_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_left_ = std::move(v);
  }

  inline void ResetScrollPaddingLeft() {
    Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_left_ = Length();
  }



  // scroll-padding-right
  const Length& ScrollPaddingRight() const {
    return misc_data_->misc_5_data_->scroll_padding_right_;
  }

  void SetScrollPaddingRight(const Length& v) {
    if (!(misc_data_->misc_5_data_->scroll_padding_right_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_right_ = v;
  }

  void SetScrollPaddingRight(Length&& v) {
    if (!(misc_data_->misc_5_data_->scroll_padding_right_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_right_ = std::move(v);
  }

  inline void ResetScrollPaddingRight() {
    Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_right_ = Length();
  }



  // scroll-padding-top
  const Length& ScrollPaddingTop() const {
    return misc_data_->misc_5_data_->scroll_padding_top_;
  }

  void SetScrollPaddingTop(const Length& v) {
    if (!(misc_data_->misc_5_data_->scroll_padding_top_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_top_ = v;
  }

  void SetScrollPaddingTop(Length&& v) {
    if (!(misc_data_->misc_5_data_->scroll_padding_top_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_top_ = std::move(v);
  }

  inline void ResetScrollPaddingTop() {
    Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_top_ = Length();
  }



  // scroll-snap-align
  const cc::ScrollSnapAlign& GetScrollSnapAlign() const {
    return misc_data_->misc_6_data_->scroll_snap_align_;
  }

  void SetScrollSnapAlign(const cc::ScrollSnapAlign& v) {
    if (!(misc_data_->misc_6_data_->scroll_snap_align_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->scroll_snap_align_ = v;
  }

  void SetScrollSnapAlign(cc::ScrollSnapAlign&& v) {
    if (!(misc_data_->misc_6_data_->scroll_snap_align_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->scroll_snap_align_ = std::move(v);
  }

  inline void ResetScrollSnapAlign() {
    Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->scroll_snap_align_ = cc::ScrollSnapAlign();
  }



  // scroll-snap-stop
  EScrollSnapStop ScrollSnapStop() const {
    return static_cast<EScrollSnapStop>(data_.scroll_snap_stop_);
  }

  void SetScrollSnapStop(EScrollSnapStop v) {
    data_.scroll_snap_stop_ = static_cast<unsigned>(v);
  }

  inline void ResetScrollSnapStop() {
    data_.scroll_snap_stop_ = static_cast<unsigned>(EScrollSnapStop::kNormal);
  }


  // scroll-snap-type
  const cc::ScrollSnapType& GetScrollSnapType() const {
    return misc_data_->misc_6_data_->scroll_snap_type_;
  }

  void SetScrollSnapType(const cc::ScrollSnapType& v) {
    if (!(misc_data_->misc_6_data_->scroll_snap_type_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->scroll_snap_type_ = v;
  }

  void SetScrollSnapType(cc::ScrollSnapType&& v) {
    if (!(misc_data_->misc_6_data_->scroll_snap_type_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->scroll_snap_type_ = std::move(v);
  }

  inline void ResetScrollSnapType() {
    Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->scroll_snap_type_ = cc::ScrollSnapType();
  }



  // scroll-target-group
  EScrollTargetGroup ScrollTargetGroup() const {
    return static_cast<EScrollTargetGroup>(misc_data_->scroll_target_group_);
  }

  void SetScrollTargetGroup(EScrollTargetGroup v) {
    if (!(misc_data_->scroll_target_group_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->scroll_target_group_ = static_cast<unsigned>(v);
  }

  inline void ResetScrollTargetGroup() {
    Access(misc_data_, access_.misc_data_)->scroll_target_group_ = static_cast<unsigned>(EScrollTargetGroup::kNone);
  }


  // scroll-timeline-axis
  const Vector<TimelineAxis>& ScrollTimelineAxis() const {
    return misc_data_->timeline_data_->scroll_timeline_axis_;
  }

  void SetScrollTimelineAxis(const Vector<TimelineAxis>& v) {
    if (!(misc_data_->timeline_data_->scroll_timeline_axis_ == v))
      Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->scroll_timeline_axis_ = v;
  }

  void SetScrollTimelineAxis(Vector<TimelineAxis>&& v) {
    if (!(misc_data_->timeline_data_->scroll_timeline_axis_ == v))
      Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->scroll_timeline_axis_ = std::move(v);
  }

  inline void ResetScrollTimelineAxis() {
    Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->scroll_timeline_axis_ = Vector<TimelineAxis>();
  }



  // scroll-timeline-name
  const Vector<AtomicString>& ScrollTimelineName() const {
    return misc_data_->timeline_data_->scroll_timeline_name_;
  }

  void SetScrollTimelineName(const Vector<AtomicString>& v) {
    if (!(misc_data_->timeline_data_->scroll_timeline_name_ == v))
      Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->scroll_timeline_name_ = v;
  }

  void SetScrollTimelineName(Vector<AtomicString>&& v) {
    if (!(misc_data_->timeline_data_->scroll_timeline_name_ == v))
      Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->scroll_timeline_name_ = std::move(v);
  }

  inline void ResetScrollTimelineName() {
    Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->scroll_timeline_name_ = Vector<AtomicString>();
  }



  // scrollbar-color
  StyleScrollbarColor* ScrollbarColor() const {
    return misc_inherited_data_->misc_inherited_1_data_->scrollbar_color_.Get();
  }

  void SetScrollbarColor(Member<StyleScrollbarColor> v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->scrollbar_color_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->scrollbar_color_ = std::move(v);
  }


  // scrollbar-gutter
  unsigned ScrollbarGutter() const {
    return static_cast<unsigned>(misc_data_->scrollbar_gutter_);
  }

  void SetScrollbarGutter(unsigned v) {
    if (!(misc_data_->scrollbar_gutter_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->scrollbar_gutter_ = static_cast<unsigned>(v);
  }

  inline void ResetScrollbarGutter() {
    Access(misc_data_, access_.misc_data_)->scrollbar_gutter_ = static_cast<unsigned>(kScrollbarGutterAuto);
  }


  // scrollbar-width
  EScrollbarWidth ScrollbarWidth() const {
    return static_cast<EScrollbarWidth>(misc_data_->scrollbar_width_);
  }

  void SetScrollbarWidth(EScrollbarWidth v) {
    if (!(misc_data_->scrollbar_width_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->scrollbar_width_ = static_cast<unsigned>(v);
  }

  inline void ResetScrollbarWidth() {
    Access(misc_data_, access_.misc_data_)->scrollbar_width_ = static_cast<unsigned>(EScrollbarWidth::kAuto);
  }


  // shape-image-threshold
  float ShapeImageThreshold() const {
    return misc_data_->misc_6_data_->shape_image_threshold_;
  }


  inline void ResetShapeImageThreshold() {
    Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->shape_image_threshold_ = 0.0;
  }


  // shape-margin
  const Length& ShapeMargin() const {
    return misc_data_->misc_6_data_->shape_margin_;
  }

  void SetShapeMargin(const Length& v) {
    if (!(misc_data_->misc_6_data_->shape_margin_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->shape_margin_ = v;
  }

  void SetShapeMargin(Length&& v) {
    if (!(misc_data_->misc_6_data_->shape_margin_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->shape_margin_ = std::move(v);
  }

  inline void ResetShapeMargin() {
    Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->shape_margin_ = Length::Fixed(0);
  }



  // shape-outside
  
  void SetShapeOutside(const Member<ShapeValue>& v) {
    if (!(misc_data_->misc_6_data_->shape_outside_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->shape_outside_ = v;
  }

  void SetShapeOutside(Member<ShapeValue>&& v) {
    if (!(misc_data_->misc_6_data_->shape_outside_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->shape_outside_ = std::move(v);
  }

  inline void ResetShapeOutside() {
    Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->shape_outside_ = nullptr;
  }



  // shape-rendering
  EShapeRendering ShapeRendering() const {
    return static_cast<EShapeRendering>(svginherited_data_->shape_rendering_);
  }

  void SetShapeRendering(EShapeRendering v) {
    if (!(svginherited_data_->shape_rendering_ == static_cast<unsigned>(v)))
      Access(svginherited_data_, access_.svginherited_data_)->shape_rendering_ = static_cast<unsigned>(v);
  }

  inline void ResetShapeRendering() {
    Access(svginherited_data_, access_.svginherited_data_)->shape_rendering_ = static_cast<unsigned>(EShapeRendering::kAuto);
  }


  // ShouldIgnoreOverflowPropertyForInlineBlockBaseline
  bool ShouldIgnoreOverflowPropertyForInlineBlockBaseline() const {
    return static_cast<bool>(data_.should_ignore_overflow_property_for_inline_block_baseline_);
  }

  void SetShouldIgnoreOverflowPropertyForInlineBlockBaseline() {
    data_.should_ignore_overflow_property_for_inline_block_baseline_ = static_cast<unsigned>(true);
  }


  // SkipsContents
  bool SkipsContents() const {
    return static_cast<bool>(data_.skips_contents_);
  }

  void SetSkipsContents(bool v) {
    data_.skips_contents_ = static_cast<unsigned>(v);
  }

  inline void ResetSkipsContents() {
    data_.skips_contents_ = static_cast<unsigned>(false);
  }


  // speak
  ESpeak Speak() const {
    return static_cast<ESpeak>(misc_inherited_data_->speak_);
  }

  void SetSpeak(ESpeak v) {
    if (!(misc_inherited_data_->speak_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->speak_ = static_cast<unsigned>(v);
  }

  inline void ResetSpeak() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->speak_ = static_cast<unsigned>(ESpeak::kNormal);
  }


  // stop-color
  
  void SetStopColor(const StyleColor& v) {
    if (!(svg_data_->stop_data_->stop_color_ == v))
      Access(Access(svg_data_, access_.svg_data_)->stop_data_, access_.stop_data_)->stop_color_ = v;
  }

  void SetStopColor(StyleColor&& v) {
    if (!(svg_data_->stop_data_->stop_color_ == v))
      Access(Access(svg_data_, access_.svg_data_)->stop_data_, access_.stop_data_)->stop_color_ = std::move(v);
  }

  inline void ResetStopColor() {
    Access(Access(svg_data_, access_.svg_data_)->stop_data_, access_.stop_data_)->stop_color_ = StyleColor(Color::kBlack);
  }



  // stop-opacity
  float StopOpacity() const {
    return svg_data_->stop_data_->stop_opacity_;
  }

  void SetStopOpacity(float v) {
    if (!(svg_data_->stop_data_->stop_opacity_ == v))
      Access(Access(svg_data_, access_.svg_data_)->stop_data_, access_.stop_data_)->stop_opacity_ = v;
  }

  inline void ResetStopOpacity() {
    Access(Access(svg_data_, access_.svg_data_)->stop_data_, access_.stop_data_)->stop_opacity_ = 1;
  }


  // stroke-dasharray
  SVGDashArray* StrokeDashArray() const {
    return svginherited_data_->stroke_data_->stroke_dash_array_.Get();
  }

  void SetStrokeDashArray(Member<SVGDashArray> v) {
    if (!(svginherited_data_->stroke_data_->stroke_dash_array_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_dash_array_ = std::move(v);
  }


  // stroke-dashoffset
  const Length& StrokeDashOffset() const {
    return svginherited_data_->stroke_data_->stroke_dash_offset_;
  }

  void SetStrokeDashOffset(const Length& v) {
    if (!(svginherited_data_->stroke_data_->stroke_dash_offset_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_dash_offset_ = v;
  }

  void SetStrokeDashOffset(Length&& v) {
    if (!(svginherited_data_->stroke_data_->stroke_dash_offset_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_dash_offset_ = std::move(v);
  }

  inline void ResetStrokeDashOffset() {
    Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_dash_offset_ = Length::Fixed();
  }



  // stroke-miterlimit
  float StrokeMiterLimit() const {
    return svginherited_data_->stroke_data_->stroke_miter_limit_;
  }

  void SetStrokeMiterLimit(float v) {
    if (!(svginherited_data_->stroke_data_->stroke_miter_limit_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_miter_limit_ = v;
  }

  inline void ResetStrokeMiterLimit() {
    Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_miter_limit_ = 4;
  }


  // stroke-opacity
  float StrokeOpacity() const {
    return svginherited_data_->stroke_data_->stroke_opacity_;
  }

  void SetStrokeOpacity(float v) {
    if (!(svginherited_data_->stroke_data_->stroke_opacity_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_opacity_ = v;
  }

  inline void ResetStrokeOpacity() {
    Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_opacity_ = 1;
  }


  // stroke
  const SVGPaint& StrokePaint() const {
    return svginherited_data_->stroke_data_->stroke_paint_;
  }

  void SetStrokePaint(const SVGPaint& v) {
    if (!(svginherited_data_->stroke_data_->stroke_paint_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_paint_ = v;
  }

  void SetStrokePaint(SVGPaint&& v) {
    if (!(svginherited_data_->stroke_data_->stroke_paint_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_paint_ = std::move(v);
  }

  inline void ResetStrokePaint() {
    Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_paint_ = SVGPaint::CreateInitial();
  }



  // stroke-width
  const UnzoomedLength& StrokeWidth() const {
    return svginherited_data_->stroke_data_->stroke_width_;
  }

  void SetStrokeWidth(const UnzoomedLength& v) {
    if (!(svginherited_data_->stroke_data_->stroke_width_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_width_ = v;
  }

  void SetStrokeWidth(UnzoomedLength&& v) {
    if (!(svginherited_data_->stroke_data_->stroke_width_ == v))
      Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_width_ = std::move(v);
  }

  inline void ResetStrokeWidth() {
    Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_width_ = UnzoomedLength(Length::Fixed(1));
  }



  // StyleType
  PseudoId StyleType() const {
    return static_cast<PseudoId>(data_.style_type_);
  }

  void SetStyleType(PseudoId v) {
    data_.style_type_ = static_cast<unsigned>(v);
  }

  inline void ResetStyleType() {
    data_.style_type_ = static_cast<unsigned>(PseudoId::kPseudoIdNone);
  }


  // SubtreeIsSticky
  bool SubtreeIsSticky() const {
    return static_cast<bool>(misc_inherited_data_->subtree_is_sticky_);
  }

  void SetSubtreeIsSticky(bool v) {
    if (!(misc_inherited_data_->subtree_is_sticky_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->subtree_is_sticky_ = static_cast<unsigned>(v);
  }

  inline void ResetSubtreeIsSticky() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->subtree_is_sticky_ = static_cast<unsigned>(false);
  }


  // SubtreeWillChangeContents
  bool SubtreeWillChangeContents() const {
    return static_cast<bool>(misc_inherited_data_->subtree_will_change_contents_);
  }

  void SetSubtreeWillChangeContents(bool v) {
    if (!(misc_inherited_data_->subtree_will_change_contents_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->subtree_will_change_contents_ = static_cast<unsigned>(v);
  }

  inline void ResetSubtreeWillChangeContents() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->subtree_will_change_contents_ = static_cast<unsigned>(false);
  }


  // tab-size
  const TabSize& GetTabSize() const {
    return misc_inherited_data_->misc_inherited_1_data_->tab_size_;
  }



  inline void ResetTabSize() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->tab_size_ = TabSize(8);
  }



  // table-layout
  ETableLayout TableLayout() const {
    return static_cast<ETableLayout>(data_.table_layout_);
  }

  void SetTableLayout(ETableLayout v) {
    data_.table_layout_ = static_cast<unsigned>(v);
  }

  inline void ResetTableLayout() {
    data_.table_layout_ = static_cast<unsigned>(ETableLayout::kAuto);
  }


  // -webkit-tap-highlight-color
  const StyleColor& TapHighlightColor() const {
    return misc_inherited_data_->misc_inherited_2_data_->tap_highlight_color_;
  }

  void SetTapHighlightColor(const StyleColor& v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->tap_highlight_color_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->tap_highlight_color_ = v;
  }

  void SetTapHighlightColor(StyleColor&& v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->tap_highlight_color_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->tap_highlight_color_ = std::move(v);
  }

  inline void ResetTapHighlightColor() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->tap_highlight_color_ = StyleColor(LayoutTheme::GetTheme().TapHighlightColor());
  }



  // text-align
  ETextAlign GetTextAlign() const {
    return static_cast<ETextAlign>(data_.text_align_);
  }

  void SetTextAlign(ETextAlign v) {
    data_.text_align_ = static_cast<unsigned>(v);
  }

  inline void ResetTextAlign() {
    data_.text_align_ = static_cast<unsigned>(ETextAlign::kStart);
  }


  // text-align-last
  ETextAlignLast TextAlignLast() const {
    return static_cast<ETextAlignLast>(misc_inherited_data_->text_align_last_);
  }

  void SetTextAlignLast(ETextAlignLast v) {
    if (!(misc_inherited_data_->text_align_last_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->text_align_last_ = static_cast<unsigned>(v);
  }

  inline void ResetTextAlignLast() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->text_align_last_ = static_cast<unsigned>(ETextAlignLast::kAuto);
  }


  // text-anchor
  ETextAnchor TextAnchor() const {
    return static_cast<ETextAnchor>(svginherited_data_->text_anchor_);
  }

  void SetTextAnchor(ETextAnchor v) {
    if (!(svginherited_data_->text_anchor_ == static_cast<unsigned>(v)))
      Access(svginherited_data_, access_.svginherited_data_)->text_anchor_ = static_cast<unsigned>(v);
  }

  inline void ResetTextAnchor() {
    Access(svginherited_data_, access_.svginherited_data_)->text_anchor_ = static_cast<unsigned>(ETextAnchor::kStart);
  }


  // text-autospace
  ETextAutospace TextAutospace() const {
    return static_cast<ETextAutospace>(misc_inherited_data_->text_autospace_);
  }

  void SetTextAutospace(ETextAutospace v) {
    if (!(misc_inherited_data_->text_autospace_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->text_autospace_ = static_cast<unsigned>(v);
  }

  inline void ResetTextAutospace() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->text_autospace_ = static_cast<unsigned>(ETextAutospace::kNoAutospace);
  }


  // text-box-edge
  TextBoxEdge GetTextBoxEdge() const {
    return static_cast<TextBoxEdge>(misc_inherited_data_->text_box_edge_);
  }

  void SetTextBoxEdge(TextBoxEdge v) {
    if (!(misc_inherited_data_->text_box_edge_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->text_box_edge_ = static_cast<unsigned>(v);
  }

  inline void ResetTextBoxEdge() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->text_box_edge_ = static_cast<unsigned>(TextBoxEdge());
  }


  // text-box-trim
  ETextBoxTrim TextBoxTrim() const {
    return static_cast<ETextBoxTrim>(box_data_->text_box_trim_);
  }

  void SetTextBoxTrim(ETextBoxTrim v) {
    if (!(box_data_->text_box_trim_ == static_cast<unsigned>(v)))
      Access(box_data_, access_.box_data_)->text_box_trim_ = static_cast<unsigned>(v);
  }

  inline void ResetTextBoxTrim() {
    Access(box_data_, access_.box_data_)->text_box_trim_ = static_cast<unsigned>(ETextBoxTrim::kNone);
  }


  // text-combine-upright
  ETextCombine TextCombine() const {
    return static_cast<ETextCombine>(misc_inherited_data_->text_combine_);
  }

  void SetTextCombine(ETextCombine v) {
    if (!(misc_inherited_data_->text_combine_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->text_combine_ = static_cast<unsigned>(v);
  }

  inline void ResetTextCombine() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->text_combine_ = static_cast<unsigned>(ETextCombine::kNone);
  }


  // text-decoration-color
  
  void SetTextDecorationColor(const StyleColor& v) {
    if (!(misc_data_->misc_6_data_->text_decoration_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_decoration_color_ = v;
  }

  void SetTextDecorationColor(StyleColor&& v) {
    if (!(misc_data_->misc_6_data_->text_decoration_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_decoration_color_ = std::move(v);
  }

  inline void ResetTextDecorationColor() {
    Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_decoration_color_ = StyleColor::CurrentColor();
  }



  // text-decoration-inset
  const TextDecorationInset& GetTextDecorationInset() const {
    return misc_data_->misc_6_data_->text_decoration_inset_;
  }

  void SetTextDecorationInset(const TextDecorationInset& v) {
    if (!(misc_data_->misc_6_data_->text_decoration_inset_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_decoration_inset_ = v;
  }

  void SetTextDecorationInset(TextDecorationInset&& v) {
    if (!(misc_data_->misc_6_data_->text_decoration_inset_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_decoration_inset_ = std::move(v);
  }

  inline void ResetTextDecorationInset() {
    Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_decoration_inset_ = TextDecorationInset(Length::Fixed(0), Length::Fixed(0));
  }



  // text-decoration-line
  TextDecorationLine GetTextDecorationLine() const {
    return static_cast<TextDecorationLine>(visual_data_->text_decoration_line_);
  }

  void SetTextDecorationLine(TextDecorationLine v) {
    if (!(visual_data_->text_decoration_line_ == static_cast<unsigned>(v)))
      Access(visual_data_, access_.visual_data_)->text_decoration_line_ = static_cast<unsigned>(v);
  }

  inline void ResetTextDecorationLine() {
    Access(visual_data_, access_.visual_data_)->text_decoration_line_ = static_cast<unsigned>(TextDecorationLine::kNone);
  }


  // text-decoration-skip-ink
  ETextDecorationSkipInk TextDecorationSkipInk() const {
    return static_cast<ETextDecorationSkipInk>(misc_inherited_data_->text_decoration_skip_ink_);
  }

  void SetTextDecorationSkipInk(ETextDecorationSkipInk v) {
    if (!(misc_inherited_data_->text_decoration_skip_ink_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->text_decoration_skip_ink_ = static_cast<unsigned>(v);
  }

  inline void ResetTextDecorationSkipInk() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->text_decoration_skip_ink_ = static_cast<unsigned>(ETextDecorationSkipInk::kAuto);
  }


  // text-decoration-skip-spaces
  TextDecorationSkipSpaces GetTextDecorationSkipSpaces() const {
    return static_cast<TextDecorationSkipSpaces>(misc_inherited_data_->text_decoration_skip_spaces_);
  }

  void SetTextDecorationSkipSpaces(TextDecorationSkipSpaces v) {
    if (!(misc_inherited_data_->text_decoration_skip_spaces_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->text_decoration_skip_spaces_ = static_cast<unsigned>(v);
  }

  inline void ResetTextDecorationSkipSpaces() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->text_decoration_skip_spaces_ = static_cast<unsigned>(TextDecorationSkipSpaces::kStartEnd);
  }


  // text-decoration-style
  ETextDecorationStyle TextDecorationStyle() const {
    return static_cast<ETextDecorationStyle>(misc_data_->text_decoration_style_);
  }

  void SetTextDecorationStyle(ETextDecorationStyle v) {
    if (!(misc_data_->text_decoration_style_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->text_decoration_style_ = static_cast<unsigned>(v);
  }

  inline void ResetTextDecorationStyle() {
    Access(misc_data_, access_.misc_data_)->text_decoration_style_ = static_cast<unsigned>(ETextDecorationStyle::kSolid);
  }


  // text-decoration-thickness
  const TextDecorationThickness& GetTextDecorationThickness() const {
    return misc_data_->misc_6_data_->text_decoration_thickness_;
  }

  void SetTextDecorationThickness(const TextDecorationThickness& v) {
    if (!(misc_data_->misc_6_data_->text_decoration_thickness_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_decoration_thickness_ = v;
  }

  void SetTextDecorationThickness(TextDecorationThickness&& v) {
    if (!(misc_data_->misc_6_data_->text_decoration_thickness_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_decoration_thickness_ = std::move(v);
  }

  inline void ResetTextDecorationThickness() {
    Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_decoration_thickness_ = TextDecorationThickness(Length::Auto());
  }



  // text-emphasis-color
  
  void SetTextEmphasisColor(const StyleColor& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->text_emphasis_color_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->text_emphasis_color_ = v;
  }

  void SetTextEmphasisColor(StyleColor&& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->text_emphasis_color_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->text_emphasis_color_ = std::move(v);
  }

  inline void ResetTextEmphasisColor() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->text_emphasis_color_ = StyleColor::CurrentColor();
  }



  // TextEmphasisCustomMark
  const AtomicString& TextEmphasisCustomMark() const {
    return misc_inherited_data_->misc_inherited_2_data_->text_emphasis_custom_mark_;
  }

  void SetTextEmphasisCustomMark(const AtomicString& v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->text_emphasis_custom_mark_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_emphasis_custom_mark_ = v;
  }

  void SetTextEmphasisCustomMark(AtomicString&& v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->text_emphasis_custom_mark_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_emphasis_custom_mark_ = std::move(v);
  }

  inline void ResetTextEmphasisCustomMark() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_emphasis_custom_mark_ = AtomicString();
  }



  // TextEmphasisFill
  TextEmphasisFill GetTextEmphasisFill() const {
    return static_cast<TextEmphasisFill>(misc_inherited_data_->text_emphasis_fill_);
  }

  void SetTextEmphasisFill(TextEmphasisFill v) {
    if (!(misc_inherited_data_->text_emphasis_fill_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->text_emphasis_fill_ = static_cast<unsigned>(v);
  }

  inline void ResetTextEmphasisFill() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->text_emphasis_fill_ = static_cast<unsigned>(TextEmphasisFill::kFilled);
  }


  // TextEmphasisMark
  
  void SetTextEmphasisMark(TextEmphasisMark v) {
    if (!(misc_inherited_data_->text_emphasis_mark_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->text_emphasis_mark_ = static_cast<unsigned>(v);
  }

  inline void ResetTextEmphasisMark() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->text_emphasis_mark_ = static_cast<unsigned>(TextEmphasisMark::kNone);
  }


  // text-emphasis-position
  TextEmphasisPosition GetTextEmphasisPosition() const {
    return static_cast<TextEmphasisPosition>(misc_inherited_data_->text_emphasis_position_);
  }

  void SetTextEmphasisPosition(TextEmphasisPosition v) {
    if (!(misc_inherited_data_->text_emphasis_position_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->text_emphasis_position_ = static_cast<unsigned>(v);
  }

  inline void ResetTextEmphasisPosition() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->text_emphasis_position_ = static_cast<unsigned>(ComputedStyleInitialValues::InitialTextEmphasisPosition());
  }


  // -webkit-text-fill-color
  
  void SetTextFillColor(const StyleColor& v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->text_fill_color_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_fill_color_ = v;
  }

  void SetTextFillColor(StyleColor&& v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->text_fill_color_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_fill_color_ = std::move(v);
  }

  inline void ResetTextFillColor() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_fill_color_ = StyleColor::CurrentColor();
  }



  // text-fit
  const TextFit& GetTextFit() const {
    return misc_inherited_data_->misc_inherited_1_data_->text_fit_;
  }

  void SetTextFit(const TextFit& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->text_fit_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->text_fit_ = v;
  }

  void SetTextFit(TextFit&& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->text_fit_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->text_fit_ = std::move(v);
  }

  inline void ResetTextFit() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->text_fit_ = TextFit();
  }



  // text-indent
  const Length& TextIndent() const {
    return misc_inherited_data_->misc_inherited_2_data_->text_indent_;
  }

  void SetTextIndent(const Length& v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->text_indent_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_indent_ = v;
  }

  void SetTextIndent(Length&& v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->text_indent_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_indent_ = std::move(v);
  }

  inline void ResetTextIndent() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_indent_ = Length::Fixed();
  }



  // TextIndentFlags
  TextIndentFlags GetTextIndentFlags() const {
    return static_cast<TextIndentFlags>(misc_inherited_data_->text_indent_flags_);
  }

  void SetTextIndentFlags(TextIndentFlags v) {
    if (!(misc_inherited_data_->text_indent_flags_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->text_indent_flags_ = static_cast<unsigned>(v);
  }

  inline void ResetTextIndentFlags() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->text_indent_flags_ = static_cast<unsigned>(TextIndentFlags::kDefault);
  }


  // text-justify
  TextJustify GetTextJustify() const {
    return static_cast<TextJustify>(misc_inherited_data_->text_justify_);
  }

  void SetTextJustify(TextJustify v) {
    if (!(misc_inherited_data_->text_justify_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->text_justify_ = static_cast<unsigned>(v);
  }

  inline void ResetTextJustify() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->text_justify_ = static_cast<unsigned>(TextJustify::kAuto);
  }


  // text-orientation
  ETextOrientation GetTextOrientation() const {
    return static_cast<ETextOrientation>(misc_inherited_data_->text_orientation_);
  }

  void SetTextOrientation(ETextOrientation v) {
    if (!(misc_inherited_data_->text_orientation_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->text_orientation_ = static_cast<unsigned>(v);
  }

  inline void ResetTextOrientation() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->text_orientation_ = static_cast<unsigned>(ETextOrientation::kMixed);
  }


  // text-overflow
  const TextOverflowData& TextOverflow() const {
    return misc_data_->misc_6_data_->text_overflow_;
  }

  void SetTextOverflow(const TextOverflowData& v) {
    if (!(misc_data_->misc_6_data_->text_overflow_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_overflow_ = v;
  }

  void SetTextOverflow(TextOverflowData&& v) {
    if (!(misc_data_->misc_6_data_->text_overflow_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_overflow_ = std::move(v);
  }

  inline void ResetTextOverflow() {
    Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_overflow_ = TextOverflowData(TextOverflowData::Type::kClip);
  }



  // -webkit-text-security
  ETextSecurity TextSecurity() const {
    return static_cast<ETextSecurity>(misc_inherited_data_->text_security_);
  }

  void SetTextSecurity(ETextSecurity v) {
    if (!(misc_inherited_data_->text_security_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->text_security_ = static_cast<unsigned>(v);
  }

  inline void ResetTextSecurity() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->text_security_ = static_cast<unsigned>(ETextSecurity::kNone);
  }


  // text-shadow
  ShadowList* TextShadow() const {
    return misc_inherited_data_->misc_inherited_2_data_->text_shadow_.Get();
  }

  void SetTextShadow(Member<ShadowList> v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->text_shadow_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_shadow_ = std::move(v);
  }


  // text-size-adjust
  const TextSizeAdjust& GetTextSizeAdjust() const {
    return misc_inherited_data_->misc_inherited_1_data_->text_size_adjust_;
  }

  void SetTextSizeAdjust(const TextSizeAdjust& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->text_size_adjust_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->text_size_adjust_ = v;
  }

  void SetTextSizeAdjust(TextSizeAdjust&& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->text_size_adjust_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->text_size_adjust_ = std::move(v);
  }

  inline void ResetTextSizeAdjust() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->text_size_adjust_ = TextSizeAdjust::AdjustAuto();
  }



  // -webkit-text-stroke-color
  
  void SetTextStrokeColor(const StyleColor& v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->text_stroke_color_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_stroke_color_ = v;
  }

  void SetTextStrokeColor(StyleColor&& v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->text_stroke_color_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_stroke_color_ = std::move(v);
  }

  inline void ResetTextStrokeColor() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_stroke_color_ = StyleColor::CurrentColor();
  }



  // -webkit-text-stroke-width
  float TextStrokeWidth() const {
    return misc_inherited_data_->misc_inherited_2_data_->text_stroke_width_;
  }

  void SetTextStrokeWidth(float v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->text_stroke_width_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_stroke_width_ = v;
  }

  inline void ResetTextStrokeWidth() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_stroke_width_ = 0;
  }


  // text-transform
  ETextTransform TextTransform() const {
    return static_cast<ETextTransform>(inherited_data_->text_transform_);
  }

  void SetTextTransform(ETextTransform v) {
    if (!(inherited_data_->text_transform_ == static_cast<unsigned>(v)))
      Access(inherited_data_, access_.inherited_data_)->text_transform_ = static_cast<unsigned>(v);
  }

  inline void ResetTextTransform() {
    Access(inherited_data_, access_.inherited_data_)->text_transform_ = static_cast<unsigned>(ETextTransform::kNone);
  }


  // text-transform
  bool TextTransformIsInherited() const {
    return static_cast<bool>(data_.text_transform_is_inherited_);
  }

  void SetTextTransformIsInherited(bool v) {
    data_.text_transform_is_inherited_ = static_cast<unsigned>(v);
  }

  inline void ResetTextTransformIsInherited() {
    data_.text_transform_is_inherited_ = static_cast<unsigned>(true);
  }


  // text-underline-offset
  const Length& TextUnderlineOffset() const {
    return misc_inherited_data_->misc_inherited_2_data_->text_underline_offset_;
  }

  void SetTextUnderlineOffset(const Length& v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->text_underline_offset_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_underline_offset_ = v;
  }

  void SetTextUnderlineOffset(Length&& v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->text_underline_offset_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_underline_offset_ = std::move(v);
  }

  inline void ResetTextUnderlineOffset() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_underline_offset_ = Length();
  }



  // text-underline-position
  TextUnderlinePosition GetTextUnderlinePosition() const {
    return static_cast<TextUnderlinePosition>(misc_inherited_data_->text_underline_position_);
  }

  void SetTextUnderlinePosition(TextUnderlinePosition v) {
    if (!(misc_inherited_data_->text_underline_position_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->text_underline_position_ = static_cast<unsigned>(v);
  }

  inline void ResetTextUnderlinePosition() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->text_underline_position_ = static_cast<unsigned>(TextUnderlinePosition::kAuto);
  }


  // text-wrap-mode
  TextWrapMode GetTextWrapMode() const {
    return static_cast<TextWrapMode>(data_.text_wrap_mode_);
  }

  void SetTextWrapMode(TextWrapMode v) {
    data_.text_wrap_mode_ = static_cast<unsigned>(v);
  }

  inline void ResetTextWrapMode() {
    data_.text_wrap_mode_ = static_cast<unsigned>(TextWrapMode::kWrap);
  }


  // text-wrap-style
  TextWrapStyle GetTextWrapStyle() const {
    return static_cast<TextWrapStyle>(data_.text_wrap_style_);
  }

  void SetTextWrapStyle(TextWrapStyle v) {
    data_.text_wrap_style_ = static_cast<unsigned>(v);
  }

  inline void ResetTextWrapStyle() {
    data_.text_wrap_style_ = static_cast<unsigned>(TextWrapStyle::kAuto);
  }


  // timeline-scope
  const StyleTimelineScope& TimelineScope() const {
    return misc_data_->timeline_data_->timeline_scope_;
  }

  void SetTimelineScope(const StyleTimelineScope& v) {
    if (!(misc_data_->timeline_data_->timeline_scope_ == v))
      Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->timeline_scope_ = v;
  }

  void SetTimelineScope(StyleTimelineScope&& v) {
    if (!(misc_data_->timeline_data_->timeline_scope_ == v))
      Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->timeline_scope_ = std::move(v);
  }

  inline void ResetTimelineScope() {
    Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->timeline_scope_ = StyleTimelineScope();
  }



  // top
  const Length& Top() const {
    return surround_data_->top_;
  }

  void SetTop(const Length& v) {
    if (!(surround_data_->top_ == v))
      Access(surround_data_, access_.surround_data_)->top_ = v;
  }

  void SetTop(Length&& v) {
    if (!(surround_data_->top_ == v))
      Access(surround_data_, access_.surround_data_)->top_ = std::move(v);
  }

  inline void ResetTop() {
    Access(surround_data_, access_.surround_data_)->top_ = Length();
  }



  // touch-action
  TouchAction GetTouchAction() const {
    return static_cast<TouchAction>(misc_data_->misc_6_data_->touch_action_);
  }

  void SetTouchAction(TouchAction v) {
    if (!(misc_data_->misc_6_data_->touch_action_ == static_cast<unsigned>(v)))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->touch_action_ = static_cast<unsigned>(v);
  }

  inline void ResetTouchAction() {
    Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->touch_action_ = static_cast<unsigned>(TouchAction::kAuto);
  }


  // transform
  const TransformOperations& Transform() const {
    return svg_data_->transform_;
  }

  void SetTransform(const TransformOperations& v) {
    if (!(svg_data_->transform_ == v))
      Access(svg_data_, access_.svg_data_)->transform_ = v;
  }

  void SetTransform(TransformOperations&& v) {
    if (!(svg_data_->transform_ == v))
      Access(svg_data_, access_.svg_data_)->transform_ = std::move(v);
  }

  inline void ResetTransform() {
    Access(svg_data_, access_.svg_data_)->transform_ = EmptyTransformOperations();
  }



  // transform-box
  ETransformBox TransformBox() const {
    return static_cast<ETransformBox>(data_.transform_box_);
  }

  void SetTransformBox(ETransformBox v) {
    data_.transform_box_ = static_cast<unsigned>(v);
  }

  inline void ResetTransformBox() {
    data_.transform_box_ = static_cast<unsigned>(ETransformBox::kViewBox);
  }


  // transform-origin
  const TransformOrigin& GetTransformOrigin() const {
    return svg_data_->transform_origin_;
  }

  void SetTransformOrigin(const TransformOrigin& v) {
    if (!(svg_data_->transform_origin_ == v))
      Access(svg_data_, access_.svg_data_)->transform_origin_ = v;
  }

  void SetTransformOrigin(TransformOrigin&& v) {
    if (!(svg_data_->transform_origin_ == v))
      Access(svg_data_, access_.svg_data_)->transform_origin_ = std::move(v);
  }

  inline void ResetTransformOrigin() {
    Access(svg_data_, access_.svg_data_)->transform_origin_ = TransformOrigin(Length::Percent(50.0), Length::Percent(50.0), 0);
  }



  // transform-style
  ETransformStyle3D TransformStyle3D() const {
    return static_cast<ETransformStyle3D>(misc_data_->transform_style_3d_);
  }

  void SetTransformStyle3D(ETransformStyle3D v) {
    if (!(misc_data_->transform_style_3d_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->transform_style_3d_ = static_cast<unsigned>(v);
  }

  inline void ResetTransformStyle3D() {
    Access(misc_data_, access_.misc_data_)->transform_style_3d_ = static_cast<unsigned>(ETransformStyle3D::kFlat);
  }


  // Transitions
  const Member<CSSTransitionData>& Transitions() const {
    return misc_data_->misc_7_data_->transitions_;
  }



  inline void ResetTransitions() {
    Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->transitions_ = nullptr;
  }



  // translate
  TranslateTransformOperation* Translate() const {
    return misc_data_->misc_6_data_->translate_.Get();
  }

  void SetTranslate(Member<TranslateTransformOperation> v) {
    if (!(misc_data_->misc_6_data_->translate_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->translate_ = std::move(v);
  }


  // trigger-scope
  const StyleTriggerScope& TriggerScope() const {
    return misc_data_->misc_6_data_->trigger_scope_;
  }

  void SetTriggerScope(const StyleTriggerScope& v) {
    if (!(misc_data_->misc_6_data_->trigger_scope_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->trigger_scope_ = v;
  }

  void SetTriggerScope(StyleTriggerScope&& v) {
    if (!(misc_data_->misc_6_data_->trigger_scope_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->trigger_scope_ = std::move(v);
  }

  inline void ResetTriggerScope() {
    Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->trigger_scope_ = StyleTriggerScope();
  }



  // UAShadowHostData
  StyleUAShadowHostData* UAShadowHostData() const {
    return misc_inherited_data_->misc_inherited_2_data_->ua_shadow_host_data_.get();
  }

  void SetUAShadowHostData(std::unique_ptr<StyleUAShadowHostData> v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->ua_shadow_host_data_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->ua_shadow_host_data_ = std::move(v);
  }


  // UnconditionalScrollbarSize
  const gfx::Size& UnconditionalScrollbarSize() const {
    return misc_data_->misc_7_data_->unconditional_scrollbar_size_;
  }

  void SetUnconditionalScrollbarSize(const gfx::Size& v) {
    if (!(misc_data_->misc_7_data_->unconditional_scrollbar_size_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->unconditional_scrollbar_size_ = v;
  }

  void SetUnconditionalScrollbarSize(gfx::Size&& v) {
    if (!(misc_data_->misc_7_data_->unconditional_scrollbar_size_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->unconditional_scrollbar_size_ = std::move(v);
  }

  inline void ResetUnconditionalScrollbarSize() {
    Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->unconditional_scrollbar_size_ = gfx::Size();
  }



  // unicode-bidi
  UnicodeBidi GetUnicodeBidi() const {
    return static_cast<UnicodeBidi>(data_.unicode_bidi_);
  }

  void SetUnicodeBidi(UnicodeBidi v) {
    data_.unicode_bidi_ = static_cast<unsigned>(v);
  }

  inline void ResetUnicodeBidi() {
    data_.unicode_bidi_ = static_cast<unsigned>(UnicodeBidi::kNormal);
  }


  // -webkit-user-drag
  EUserDrag UserDrag() const {
    return static_cast<EUserDrag>(misc_data_->user_drag_);
  }

  void SetUserDrag(EUserDrag v) {
    if (!(misc_data_->user_drag_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->user_drag_ = static_cast<unsigned>(v);
  }

  inline void ResetUserDrag() {
    Access(misc_data_, access_.misc_data_)->user_drag_ = static_cast<unsigned>(EUserDrag::kAuto);
  }


  // -webkit-user-modify
  
  void SetUserModify(EUserModify v) {
    if (!(misc_inherited_data_->user_modify_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->user_modify_ = static_cast<unsigned>(v);
  }

  inline void ResetUserModify() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->user_modify_ = static_cast<unsigned>(EUserModify::kReadOnly);
  }


  // user-select
  
  void SetUserSelect(EUserSelect v) {
    if (!(misc_inherited_data_->user_select_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->user_select_ = static_cast<unsigned>(v);
  }

  inline void ResetUserSelect() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->user_select_ = static_cast<unsigned>(EUserSelect::kAuto);
  }


  // vector-effect
  EVectorEffect VectorEffect() const {
    return static_cast<EVectorEffect>(svg_data_->vector_effect_);
  }

  void SetVectorEffect(EVectorEffect v) {
    if (!(svg_data_->vector_effect_ == static_cast<unsigned>(v)))
      Access(svg_data_, access_.svg_data_)->vector_effect_ = static_cast<unsigned>(v);
  }

  inline void ResetVectorEffect() {
    Access(svg_data_, access_.svg_data_)->vector_effect_ = static_cast<unsigned>(EVectorEffect::kNone);
  }


  // VerticalAlign
  

  inline void ResetVerticalAlign() {
    data_.vertical_align_ = static_cast<unsigned>(static_cast<unsigned>(EVerticalAlign::kBaseline));
  }


  // VerticalAlignLength
  const Length& GetVerticalAlignLength() const {
    return box_data_->vertical_align_length_;
  }



  inline void ResetVerticalAlignLength() {
    Access(box_data_, access_.box_data_)->vertical_align_length_ = Length();
  }



  // -webkit-border-vertical-spacing
  short VerticalBorderSpacing() const {
    return inherited_data_->vertical_border_spacing_;
  }

  void SetVerticalBorderSpacing(short v) {
    if (!(inherited_data_->vertical_border_spacing_ == v))
      Access(inherited_data_, access_.inherited_data_)->vertical_border_spacing_ = v;
  }

  inline void ResetVerticalBorderSpacing() {
    Access(inherited_data_, access_.inherited_data_)->vertical_border_spacing_ = 0;
  }


  // view-timeline-axis
  const Vector<TimelineAxis>& ViewTimelineAxis() const {
    return misc_data_->timeline_data_->view_timeline_axis_;
  }

  void SetViewTimelineAxis(const Vector<TimelineAxis>& v) {
    if (!(misc_data_->timeline_data_->view_timeline_axis_ == v))
      Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->view_timeline_axis_ = v;
  }

  void SetViewTimelineAxis(Vector<TimelineAxis>&& v) {
    if (!(misc_data_->timeline_data_->view_timeline_axis_ == v))
      Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->view_timeline_axis_ = std::move(v);
  }

  inline void ResetViewTimelineAxis() {
    Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->view_timeline_axis_ = Vector<TimelineAxis>();
  }



  // view-timeline-inset
  const Vector<TimelineInset>& ViewTimelineInset() const {
    return misc_data_->timeline_data_->view_timeline_inset_;
  }

  void SetViewTimelineInset(const Vector<TimelineInset>& v) {
    if (!(misc_data_->timeline_data_->view_timeline_inset_ == v))
      Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->view_timeline_inset_ = v;
  }

  void SetViewTimelineInset(Vector<TimelineInset>&& v) {
    if (!(misc_data_->timeline_data_->view_timeline_inset_ == v))
      Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->view_timeline_inset_ = std::move(v);
  }

  inline void ResetViewTimelineInset() {
    Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->view_timeline_inset_ = Vector<TimelineInset>();
  }



  // view-timeline-name
  const Vector<AtomicString>& ViewTimelineName() const {
    return misc_data_->timeline_data_->view_timeline_name_;
  }

  void SetViewTimelineName(const Vector<AtomicString>& v) {
    if (!(misc_data_->timeline_data_->view_timeline_name_ == v))
      Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->view_timeline_name_ = v;
  }

  void SetViewTimelineName(Vector<AtomicString>&& v) {
    if (!(misc_data_->timeline_data_->view_timeline_name_ == v))
      Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->view_timeline_name_ = std::move(v);
  }

  inline void ResetViewTimelineName() {
    Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->view_timeline_name_ = Vector<AtomicString>();
  }



  // view-transition-class
  const Member<ScopedCSSNameList>& ViewTransitionClass() const {
    return misc_data_->misc_6_data_->view_transition_class_;
  }

  void SetViewTransitionClass(const Member<ScopedCSSNameList>& v) {
    if (!(misc_data_->misc_6_data_->view_transition_class_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->view_transition_class_ = v;
  }

  void SetViewTransitionClass(Member<ScopedCSSNameList>&& v) {
    if (!(misc_data_->misc_6_data_->view_transition_class_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->view_transition_class_ = std::move(v);
  }

  inline void ResetViewTransitionClass() {
    Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->view_transition_class_ = nullptr;
  }



  // view-transition-group
  const StyleViewTransitionGroup& ViewTransitionGroup() const {
    return misc_data_->misc_6_data_->view_transition_group_;
  }

  void SetViewTransitionGroup(const StyleViewTransitionGroup& v) {
    if (!(misc_data_->misc_6_data_->view_transition_group_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->view_transition_group_ = v;
  }

  void SetViewTransitionGroup(StyleViewTransitionGroup&& v) {
    if (!(misc_data_->misc_6_data_->view_transition_group_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->view_transition_group_ = std::move(v);
  }

  inline void ResetViewTransitionGroup() {
    Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->view_transition_group_ = StyleViewTransitionGroup::Normal();
  }



  // view-transition-name
  const Member<StyleViewTransitionName>& ViewTransitionName() const {
    return misc_data_->misc_6_data_->view_transition_name_;
  }

  void SetViewTransitionName(const Member<StyleViewTransitionName>& v) {
    if (!(misc_data_->misc_6_data_->view_transition_name_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->view_transition_name_ = v;
  }

  void SetViewTransitionName(Member<StyleViewTransitionName>&& v) {
    if (!(misc_data_->misc_6_data_->view_transition_name_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->view_transition_name_ = std::move(v);
  }

  inline void ResetViewTransitionName() {
    Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->view_transition_name_ = nullptr;
  }



  // view-transition-scope
  EViewTransitionScope ViewTransitionScope() const {
    return static_cast<EViewTransitionScope>(misc_data_->view_transition_scope_);
  }

  void SetViewTransitionScope(EViewTransitionScope v) {
    if (!(misc_data_->view_transition_scope_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->view_transition_scope_ = static_cast<unsigned>(v);
  }

  inline void ResetViewTransitionScope() {
    Access(misc_data_, access_.misc_data_)->view_transition_scope_ = static_cast<unsigned>(EViewTransitionScope::kNone);
  }


  // ViewportUnitFlags
  unsigned ViewportUnitFlags() const {
    return static_cast<unsigned>(data_.viewport_unit_flags_);
  }

  void SetViewportUnitFlags(unsigned v) {
    data_.viewport_unit_flags_ = static_cast<unsigned>(v);
  }

  inline void ResetViewportUnitFlags() {
    data_.viewport_unit_flags_ = static_cast<unsigned>(0);
  }


  // visibility
  EVisibility Visibility() const {
    return static_cast<EVisibility>(data_.visibility_);
  }

  void SetVisibility(EVisibility v) {
    data_.visibility_ = static_cast<unsigned>(v);
  }

  inline void ResetVisibility() {
    data_.visibility_ = static_cast<unsigned>(EVisibility::kVisible);
  }


  // visibility
  bool VisibilityIsInherited() const {
    return static_cast<bool>(data_.visibility_is_inherited_);
  }

  void SetVisibilityIsInherited(bool v) {
    data_.visibility_is_inherited_ = static_cast<unsigned>(v);
  }

  inline void ResetVisibilityIsInherited() {
    data_.visibility_is_inherited_ = static_cast<unsigned>(true);
  }


  // -webkit-line-clamp
  int WebkitLineClamp() const {
    return misc_data_->misc_7_data_->webkit_line_clamp_;
  }

  void SetWebkitLineClamp(int v) {
    if (!(misc_data_->misc_7_data_->webkit_line_clamp_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->webkit_line_clamp_ = v;
  }

  inline void ResetWebkitLineClamp() {
    Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->webkit_line_clamp_ = 0;
  }


  // white-space-collapse
  WhiteSpaceCollapse GetWhiteSpaceCollapse() const {
    return static_cast<WhiteSpaceCollapse>(data_.white_space_collapse_);
  }

  void SetWhiteSpaceCollapse(WhiteSpaceCollapse v) {
    data_.white_space_collapse_ = static_cast<unsigned>(v);
  }

  inline void ResetWhiteSpaceCollapse() {
    data_.white_space_collapse_ = static_cast<unsigned>(WhiteSpaceCollapse::kCollapse);
  }


  // widows
  short Widows() const {
    return misc_inherited_data_->misc_inherited_2_data_->widows_;
  }


  inline void ResetWidows() {
    Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->widows_ = 2;
  }


  // width
  const Length& Width() const {
    return box_data_->width_;
  }

  void SetWidth(const Length& v) {
    if (!(box_data_->width_ == v))
      Access(box_data_, access_.box_data_)->width_ = v;
  }

  void SetWidth(Length&& v) {
    if (!(box_data_->width_ == v))
      Access(box_data_, access_.box_data_)->width_ = std::move(v);
  }

  inline void ResetWidth() {
    Access(box_data_, access_.box_data_)->width_ = Length();
  }



  // will-change
  StyleWillChangeData* WillChange() const {
    return misc_data_->will_change_.Get();
  }

  void SetWillChange(Member<StyleWillChangeData> v) {
    if (!(misc_data_->will_change_ == v))
      Access(misc_data_, access_.misc_data_)->will_change_ = std::move(v);
  }


  // word-break
  EWordBreak WordBreak() const {
    return static_cast<EWordBreak>(misc_inherited_data_->word_break_);
  }

  void SetWordBreak(EWordBreak v) {
    if (!(misc_inherited_data_->word_break_ == static_cast<unsigned>(v)))
      Access(misc_inherited_data_, access_.misc_inherited_data_)->word_break_ = static_cast<unsigned>(v);
  }

  inline void ResetWordBreak() {
    Access(misc_inherited_data_, access_.misc_inherited_data_)->word_break_ = static_cast<unsigned>(EWordBreak::kNormal);
  }


  // word-spacing
  
  void SetWordSpacing(const Length& v) {
    if (!(inherited_data_->word_spacing_ == v))
      Access(inherited_data_, access_.inherited_data_)->word_spacing_ = v;
  }

  void SetWordSpacing(Length&& v) {
    if (!(inherited_data_->word_spacing_ == v))
      Access(inherited_data_, access_.inherited_data_)->word_spacing_ = std::move(v);
  }

  inline void ResetWordSpacing() {
    Access(inherited_data_, access_.inherited_data_)->word_spacing_ = Length::Fixed();
  }



  // writing-mode
  WritingMode GetWritingMode() const {
    return static_cast<WritingMode>(data_.writing_mode_);
  }

  void SetWritingMode(WritingMode v) {
    data_.writing_mode_ = static_cast<unsigned>(v);
  }

  inline void ResetWritingMode() {
    data_.writing_mode_ = static_cast<unsigned>(WritingMode::kHorizontalTb);
  }


  // x
  const Length& X() const {
    return svg_data_->geometry_data_->x_;
  }

  void SetX(const Length& v) {
    if (!(svg_data_->geometry_data_->x_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->x_ = v;
  }

  void SetX(Length&& v) {
    if (!(svg_data_->geometry_data_->x_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->x_ = std::move(v);
  }

  inline void ResetX() {
    Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->x_ = Length::Fixed();
  }



  // y
  const Length& Y() const {
    return svg_data_->geometry_data_->y_;
  }

  void SetY(const Length& v) {
    if (!(svg_data_->geometry_data_->y_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->y_ = v;
  }

  void SetY(Length&& v) {
    if (!(svg_data_->geometry_data_->y_ == v))
      Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->y_ = std::move(v);
  }

  inline void ResetY() {
    Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->y_ = Length::Fixed();
  }



  // z-index
  int ZIndex() const {
    return box_data_->z_index_;
  }


  inline void ResetZIndex() {
    Access(box_data_, access_.box_data_)->z_index_ = 0;
  }


  // zoom
  float Zoom() const {
    return visual_data_->zoom_;
  }

  void SetZoom(float v) {
    if (!(visual_data_->zoom_ == v))
      Access(visual_data_, access_.visual_data_)->zoom_ = v;
  }

  inline void ResetZoom() {
    Access(visual_data_, access_.visual_data_)->zoom_ = 1.0;
  }



 protected:
  ComputedStyleBuilderBase() = delete;

  explicit ComputedStyleBuilderBase(const ComputedStyleBase&);

  ComputedStyleBuilderBase(const ComputedStyleBase &source_for_noninherited,
                           const ComputedStyleBase &parent_style);

  void PropagateIndependentInheritedProperties(const ComputedStyleBase& parent_style);

  void CopyHighlightPropertiesFrom(const ComputedStyleBase& originating_element_style);

  // accent-color
  const StyleAutoColor& AccentColor() const {
    return misc_inherited_data_->misc_inherited_1_data_->accent_color_;
  }




  StyleAutoColor& MutableAccentColorInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->accent_color_;
  }


  // AffectedByActive
  

  // AffectedByCSSFunction
  

  // AffectedByDrag
  

  // AffectedByFocusWithin
  

  // AffectedByFunctionalMedia
  

  // AffectedByFunctionalNavigation
  

  // AffectedByHover
  

  // align-content
  



  StyleContentAlignmentData& MutableAlignContentInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->align_content_;
  }


  // -internal-align-content-block
  


  bool MutableAlignContentBlockCenterInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->align_content_block_center_);
  }


  // align-items
  



  StyleSelfAlignmentData& MutableAlignItemsInternal() {
    return Access(box_data_, access_.box_data_)->align_items_;
  }


  // align-self
  



  StyleSelfAlignmentData& MutableAlignSelfInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->align_self_;
  }


  // alignment-baseline
  


  EAlignmentBaseline MutableAlignmentBaselineInternal() {
    return static_cast<EAlignmentBaseline>(Access(svg_data_, access_.svg_data_)->alignment_baseline_);
  }


  // AllowsZIndex
  


  bool MutableAllowsZIndexInternal() {
    return static_cast<bool>(data_.allows_z_index_);
  }


  // AnchorCenterOffset
  



  std::optional<PhysicalOffset>& MutableAnchorCenterOffsetInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->anchor_center_offset_;
  }


  // anchor-name
  


  Member<ScopedCSSNameList>& MutableAnchorNameInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->anchor_name_;
  }


  // anchor-scope
  



  StyleAnchorScope& MutableAnchorScopeInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->anchor_scope_;
  }


  // Animations
  
  void SetAnimationsInternal(Member<CSSAnimationData>&& v) {
    if (!(misc_data_->misc_7_data_->animations_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->animations_ = std::move(v);
  }


  Member<CSSAnimationData>& MutableAnimationsInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->animations_;
  }


  // appearance
  AppearanceValue Appearance() const {
    return static_cast<AppearanceValue>(misc_data_->appearance_);
  }



  AppearanceValue MutableAppearanceInternal() {
    return static_cast<AppearanceValue>(Access(misc_data_, access_.misc_data_)->appearance_);
  }


  // aspect-ratio
  



  StyleAspectRatio& MutableAspectRatioInternal() {
    return Access(surround_data_, access_.surround_data_)->aspect_ratio_;
  }


  // backdrop-filter
  



  FilterOperations& MutableBackdropFilterInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->backdrop_filter_;
  }


  // backface-visibility
  


  EBackfaceVisibility MutableBackfaceVisibilityInternal() {
    return static_cast<EBackfaceVisibility>(Access(misc_data_, access_.misc_data_)->backface_visibility_);
  }


  // Background
  const FillLayer& BackgroundInternal() const {
    return background_data_->background_;
  }

  void SetBackgroundInternal(const FillLayer& v) {
    if (!(background_data_->background_ == v))
      Access(background_data_, access_.background_data_)->background_ = v;
  }

  void SetBackgroundInternal(FillLayer&& v) {
    if (!(background_data_->background_ == v))
      Access(background_data_, access_.background_data_)->background_ = std::move(v);
  }


  FillLayer& MutableBackgroundInternal() {
    return Access(background_data_, access_.background_data_)->background_;
  }


  // background-color
  const StyleColor& BackgroundColor() const {
    return background_data_->background_color_;
  }




  StyleColor& MutableBackgroundColorInternal() {
    return Access(background_data_, access_.background_data_)->background_color_;
  }


  // BaseData
  


  // BaseTextDecorationData
  


  // baseline-shift
  



  Length& MutableBaselineShiftInternal() {
    return Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->baseline_shift_;
  }


  // BaselineShiftType
  


  EBaselineShiftType MutableBaselineShiftTypeInternal() {
    return static_cast<EBaselineShiftType>(Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->baseline_shift_type_);
  }


  // baseline-source
  


  EBaselineSource MutableBaselineSourceInternal() {
    return static_cast<EBaselineSource>(Access(box_data_, access_.box_data_)->baseline_source_);
  }


  // mix-blend-mode
  


  BlendMode MutableBlendModeInternal() {
    return static_cast<BlendMode>(Access(misc_data_, access_.misc_data_)->blend_mode_);
  }


  // block-ellipsis
  


  EBlockEllipsis MutableBlockEllipsisInternal() {
    return static_cast<EBlockEllipsis>(Access(misc_inherited_data_, access_.misc_inherited_data_)->block_ellipsis_);
  }


  // border-bottom-color
  const StyleColor& BorderBottomColor() const {
    return surround_data_->border_bottom_color_;
  }




  StyleColor& MutableBorderBottomColorInternal() {
    return Access(surround_data_, access_.surround_data_)->border_bottom_color_;
  }


  // border-bottom-left-radius
  



  LengthSize& MutableBorderBottomLeftRadiusInternal() {
    return Access(surround_data_, access_.surround_data_)->border_bottom_left_radius_;
  }


  // border-bottom-right-radius
  



  LengthSize& MutableBorderBottomRightRadiusInternal() {
    return Access(surround_data_, access_.surround_data_)->border_bottom_right_radius_;
  }


  // border-bottom-style
  


  EBorderStyle MutableBorderBottomStyleInternal() {
    return static_cast<EBorderStyle>(Access(box_data_, access_.box_data_)->border_bottom_style_);
  }


  // border-bottom-width
  



  int& MutableBorderBottomWidthInternal() {
    return Access(box_data_, access_.box_data_)->border_bottom_width_;
  }


  // border-collapse
  


  EBorderCollapse MutableBorderCollapseInternal() {
    return static_cast<EBorderCollapse>(data_.border_collapse_);
  }


  // border-collapse
  


  bool MutableBorderCollapseIsInheritedInternal() {
    return static_cast<bool>(data_.border_collapse_is_inherited_);
  }


  // border-image
  



  NinePieceImage& MutableBorderImageInternal() {
    return Access(surround_data_, access_.surround_data_)->border_image_;
  }


  // border-left-color
  const StyleColor& BorderLeftColor() const {
    return surround_data_->border_left_color_;
  }




  StyleColor& MutableBorderLeftColorInternal() {
    return Access(surround_data_, access_.surround_data_)->border_left_color_;
  }


  // border-left-style
  


  EBorderStyle MutableBorderLeftStyleInternal() {
    return static_cast<EBorderStyle>(Access(box_data_, access_.box_data_)->border_left_style_);
  }


  // border-left-width
  



  int& MutableBorderLeftWidthInternal() {
    return Access(box_data_, access_.box_data_)->border_left_width_;
  }


  // border-right-color
  const StyleColor& BorderRightColor() const {
    return surround_data_->border_right_color_;
  }




  StyleColor& MutableBorderRightColorInternal() {
    return Access(surround_data_, access_.surround_data_)->border_right_color_;
  }


  // border-right-style
  


  EBorderStyle MutableBorderRightStyleInternal() {
    return static_cast<EBorderStyle>(Access(box_data_, access_.box_data_)->border_right_style_);
  }


  // border-right-width
  



  int& MutableBorderRightWidthInternal() {
    return Access(box_data_, access_.box_data_)->border_right_width_;
  }


  // border-shape
  


  Member<StyleBorderShape>& MutableBorderShapeInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->border_shape_;
  }


  // border-top-color
  const StyleColor& BorderTopColor() const {
    return surround_data_->border_top_color_;
  }




  StyleColor& MutableBorderTopColorInternal() {
    return Access(surround_data_, access_.surround_data_)->border_top_color_;
  }


  // border-top-left-radius
  



  LengthSize& MutableBorderTopLeftRadiusInternal() {
    return Access(surround_data_, access_.surround_data_)->border_top_left_radius_;
  }


  // border-top-right-radius
  



  LengthSize& MutableBorderTopRightRadiusInternal() {
    return Access(surround_data_, access_.surround_data_)->border_top_right_radius_;
  }


  // border-top-style
  


  EBorderStyle MutableBorderTopStyleInternal() {
    return static_cast<EBorderStyle>(Access(box_data_, access_.box_data_)->border_top_style_);
  }


  // border-top-width
  



  int& MutableBorderTopWidthInternal() {
    return Access(box_data_, access_.box_data_)->border_top_width_;
  }


  // bottom
  



  Length& MutableBottomInternal() {
    return Access(surround_data_, access_.surround_data_)->bottom_;
  }


  // -webkit-box-align
  


  EBoxAlignment MutableBoxAlignInternal() {
    return static_cast<EBoxAlignment>(Access(misc_data_, access_.misc_data_)->box_align_);
  }


  // box-decoration-break
  


  EBoxDecorationBreak MutableBoxDecorationBreakInternal() {
    return static_cast<EBoxDecorationBreak>(Access(box_data_, access_.box_data_)->box_decoration_break_);
  }


  // -webkit-box-direction
  EBoxDirection BoxDirection() const {
    return static_cast<EBoxDirection>(data_.box_direction_);
  }



  EBoxDirection MutableBoxDirectionInternal() {
    return static_cast<EBoxDirection>(data_.box_direction_);
  }


  // -webkit-box-flex
  


  float MutableBoxFlexInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->box_flex_;
  }


  // -webkit-box-ordinal-group
  
  void SetBoxOrdinalGroupInternal(unsigned v) {
    if (!(misc_data_->misc_7_data_->box_ordinal_group_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->box_ordinal_group_ = v;
  }


  unsigned MutableBoxOrdinalGroupInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->box_ordinal_group_;
  }


  // -webkit-box-orient
  


  EBoxOrient MutableBoxOrientInternal() {
    return static_cast<EBoxOrient>(Access(misc_data_, access_.misc_data_)->box_orient_);
  }


  // -webkit-box-pack
  


  EBoxPack MutableBoxPackInternal() {
    return static_cast<EBoxPack>(Access(misc_data_, access_.misc_data_)->box_pack_);
  }


  // -webkit-box-reflect
  


  // box-shadow
  


  // box-sizing
  


  EBoxSizing MutableBoxSizingInternal() {
    return static_cast<EBoxSizing>(data_.box_sizing_);
  }


  // break-after
  


  EBreakBetween MutableBreakAfterInternal() {
    return static_cast<EBreakBetween>(Access(misc_data_, access_.misc_data_)->break_after_);
  }


  // break-before
  


  EBreakBetween MutableBreakBeforeInternal() {
    return static_cast<EBreakBetween>(Access(misc_data_, access_.misc_data_)->break_before_);
  }


  // break-inside
  


  EBreakInside MutableBreakInsideInternal() {
    return static_cast<EBreakInside>(Access(misc_data_, access_.misc_data_)->break_inside_);
  }


  // buffered-rendering
  


  EBufferedRendering MutableBufferedRenderingInternal() {
    return static_cast<EBufferedRendering>(Access(svg_data_, access_.svg_data_)->buffered_rendering_);
  }


  // CallbackSelectors
  
  void SetCallbackSelectorsInternal(const Vector<String>& v) {
    if (!(misc_data_->misc_8_data_->callback_selectors_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->callback_selectors_ = v;
  }

  void SetCallbackSelectorsInternal(Vector<String>&& v) {
    if (!(misc_data_->misc_8_data_->callback_selectors_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->callback_selectors_ = std::move(v);
  }


  Vector<String>& MutableCallbackSelectorsInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->callback_selectors_;
  }


  // CanAffectAnimations
  

  // stroke-linecap
  


  LineCap MutableCapStyleInternal() {
    return static_cast<LineCap>(Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->cap_style_);
  }


  // caption-side
  


  ECaptionSide MutableCaptionSideInternal() {
    return static_cast<ECaptionSide>(data_.caption_side_);
  }


  // caption-side
  


  bool MutableCaptionSideIsInheritedInternal() {
    return static_cast<bool>(data_.caption_side_is_inherited_);
  }


  // caret-animation
  


  ECaretAnimation MutableCaretAnimationInternal() {
    return static_cast<ECaretAnimation>(data_.caret_animation_);
  }


  // caret-color
  const StyleCaretColor& CaretColor() const {
    return misc_inherited_data_->misc_inherited_1_data_->caret_color_;
  }




  StyleCaretColor& MutableCaretColorInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->caret_color_;
  }


  // caret-shape
  


  ECaretShape MutableCaretShapeInternal() {
    return static_cast<ECaretShape>(data_.caret_shape_);
  }


  // clear
  EClear Clear() const {
    return static_cast<EClear>(data_.clear_);
  }



  EClear MutableClearInternal() {
    return static_cast<EClear>(data_.clear_);
  }


  // clip
  
  void SetClipInternal(const LengthBox& v) {
    if (!(visual_data_->clip_ == v))
      Access(visual_data_, access_.visual_data_)->clip_ = v;
  }

  void SetClipInternal(LengthBox&& v) {
    if (!(visual_data_->clip_ == v))
      Access(visual_data_, access_.visual_data_)->clip_ = std::move(v);
  }


  LengthBox& MutableClipInternal() {
    return Access(visual_data_, access_.visual_data_)->clip_;
  }


  // clip-path
  const Member<ClipPathOperation>& ClipPathInternal() const {
    return misc_data_->misc_1_data_->clip_path_;
  }

  void SetClipPathInternal(Member<ClipPathOperation>&& v) {
    if (!(misc_data_->misc_1_data_->clip_path_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->clip_path_ = std::move(v);
  }


  Member<ClipPathOperation>& MutableClipPathInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->clip_path_;
  }


  // clip-rule
  


  WindRule MutableClipRuleInternal() {
    return static_cast<WindRule>(Access(svginherited_data_, access_.svginherited_data_)->clip_rule_);
  }


  // color
  const StyleColor& Color() const {
    return inherited_data_->color_;
  }




  StyleColor& MutableColorInternal() {
    return Access(inherited_data_, access_.inherited_data_)->color_;
  }


  // color-interpolation
  


  EColorInterpolation MutableColorInterpolationInternal() {
    return static_cast<EColorInterpolation>(Access(svginherited_data_, access_.svginherited_data_)->color_interpolation_);
  }


  // color-interpolation-filters
  


  EColorInterpolation MutableColorInterpolationFiltersInternal() {
    return static_cast<EColorInterpolation>(Access(svginherited_data_, access_.svginherited_data_)->color_interpolation_filters_);
  }


  // ColorIsCurrentColor
  bool ColorIsCurrentColor() const {
    return static_cast<bool>(inherited_data_->color_is_current_color_);
  }



  bool MutableColorIsCurrentColorInternal() {
    return static_cast<bool>(Access(inherited_data_, access_.inherited_data_)->color_is_current_color_);
  }


  // color
  bool ColorIsInherited() const {
    return static_cast<bool>(data_.color_is_inherited_);
  }



  bool MutableColorIsInheritedInternal() {
    return static_cast<bool>(data_.color_is_inherited_);
  }


  // color-rendering
  


  EColorRendering MutableColorRenderingInternal() {
    return static_cast<EColorRendering>(Access(svginherited_data_, access_.svginherited_data_)->color_rendering_);
  }


  // color-scheme
  



  Vector<AtomicString>& MutableColorSchemeInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->color_scheme_;
  }


  // ColorSchemeFlagsIsNormal
  


  bool MutableColorSchemeFlagsIsNormalInternal() {
    return static_cast<bool>(data_.color_scheme_flags_is_normal_);
  }


  // ColorSchemeForced
  


  bool MutableColorSchemeForcedInternal() {
    return static_cast<bool>(data_.color_scheme_forced_);
  }


  // column-count
  
  void SetColumnCountInternal(unsigned short v) {
    if (!(misc_data_->misc_1_data_->column_count_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_count_ = v;
  }


  unsigned short MutableColumnCountInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_count_;
  }


  // column-fill
  


  EColumnFill MutableColumnFillInternal() {
    return static_cast<EColumnFill>(Access(misc_data_, access_.misc_data_)->column_fill_);
  }


  // column-gap
  



  std::optional<Length>& MutableColumnGapInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_gap_;
  }


  // column-height
  
  void SetColumnHeightInternal(float v) {
    if (!(misc_data_->misc_1_data_->column_height_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_height_ = v;
  }


  float MutableColumnHeightInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_height_;
  }


  // column-rule-break
  


  RuleBreak MutableColumnRuleBreakInternal() {
    return static_cast<RuleBreak>(Access(misc_data_, access_.misc_data_)->column_rule_break_);
  }


  // column-rule-color
  
  void SetColumnRuleColorInternal(const GapDataList<StyleColor>& v) {
    if (!(misc_data_->misc_1_data_->column_rule_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_rule_color_ = v;
  }

  void SetColumnRuleColorInternal(GapDataList<StyleColor>&& v) {
    if (!(misc_data_->misc_1_data_->column_rule_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_rule_color_ = std::move(v);
  }


  GapDataList<StyleColor>& MutableColumnRuleColorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_rule_color_;
  }


  // column-rule-inset-cap-end
  



  Length& MutableColumnRuleInsetCapEndInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_rule_inset_cap_end_;
  }


  // column-rule-inset-cap-start
  



  Length& MutableColumnRuleInsetCapStartInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->column_rule_inset_cap_start_;
  }


  // column-rule-inset-junction-end
  



  Length& MutableColumnRuleInsetJunctionEndInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_inset_junction_end_;
  }


  // column-rule-inset-junction-start
  



  Length& MutableColumnRuleInsetJunctionStartInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_inset_junction_start_;
  }


  // column-rule-style
  
  void SetColumnRuleStyleInternal(const GapDataList<EBorderStyle>& v) {
    if (!(misc_data_->misc_2_data_->column_rule_style_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_style_ = v;
  }

  void SetColumnRuleStyleInternal(GapDataList<EBorderStyle>&& v) {
    if (!(misc_data_->misc_2_data_->column_rule_style_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_style_ = std::move(v);
  }


  GapDataList<EBorderStyle>& MutableColumnRuleStyleInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_style_;
  }


  // column-rule-visibility-items
  


  RuleVisibilityItems MutableColumnRuleVisibilityItemsInternal() {
    return static_cast<RuleVisibilityItems>(Access(misc_data_, access_.misc_data_)->column_rule_visibility_items_);
  }


  // column-rule-width
  
  void SetColumnRuleWidthInternal(const GapDataList<int>& v) {
    if (!(misc_data_->misc_2_data_->column_rule_width_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_width_ = v;
  }

  void SetColumnRuleWidthInternal(GapDataList<int>&& v) {
    if (!(misc_data_->misc_2_data_->column_rule_width_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_width_ = std::move(v);
  }


  GapDataList<int>& MutableColumnRuleWidthInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_rule_width_;
  }


  // column-span
  


  EColumnSpan MutableColumnSpanInternal() {
    return static_cast<EColumnSpan>(Access(misc_data_, access_.misc_data_)->column_span_);
  }


  // column-width
  
  void SetColumnWidthInternal(float v) {
    if (!(misc_data_->misc_2_data_->column_width_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_width_ = v;
  }


  float MutableColumnWidthInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->column_width_;
  }


  // column-wrap
  


  EColumnWrap MutableColumnWrapInternal() {
    return static_cast<EColumnWrap>(Access(misc_data_, access_.misc_data_)->column_wrap_);
  }


  // contain
  


  unsigned MutableContainInternal() {
    return static_cast<unsigned>(Access(misc_data_, access_.misc_data_)->contain_);
  }


  // contain-intrinsic-height
  



  StyleIntrinsicLength& MutableContainIntrinsicHeightInternal() {
    return Access(surround_data_, access_.surround_data_)->contain_intrinsic_height_;
  }


  // contain-intrinsic-width
  



  StyleIntrinsicLength& MutableContainIntrinsicWidthInternal() {
    return Access(surround_data_, access_.surround_data_)->contain_intrinsic_width_;
  }


  // ContainerFont
  


  // container-name
  



  Vector<AtomicString>& MutableContainerNameInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->container_name_;
  }


  // container-type
  


  unsigned MutableContainerTypeInternal() {
    return static_cast<unsigned>(Access(misc_data_, access_.misc_data_)->container_type_);
  }


  // content
  const Member<ContentData>& ContentInternal() const {
    return misc_data_->misc_2_data_->content_;
  }



  Member<ContentData>& MutableContentInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->content_;
  }


  // content-visibility
  


  EContentVisibility MutableContentVisibilityInternal() {
    return static_cast<EContentVisibility>(data_.content_visibility_);
  }


  // Continue
  


  EContinue MutableContinueInternal() {
    return static_cast<EContinue>(Access(misc_data_, access_.misc_data_)->continue_);
  }


  // corner-bottom-left-shape
  



  Superellipse& MutableCornerBottomLeftShapeInternal() {
    return Access(surround_data_, access_.surround_data_)->corner_bottom_left_shape_;
  }


  // corner-bottom-right-shape
  



  Superellipse& MutableCornerBottomRightShapeInternal() {
    return Access(surround_data_, access_.surround_data_)->corner_bottom_right_shape_;
  }


  // corner-top-left-shape
  



  Superellipse& MutableCornerTopLeftShapeInternal() {
    return Access(surround_data_, access_.surround_data_)->corner_top_left_shape_;
  }


  // corner-top-right-shape
  



  Superellipse& MutableCornerTopRightShapeInternal() {
    return Access(surround_data_, access_.surround_data_)->corner_top_right_shape_;
  }


  // CounterDirectives
  const std::unique_ptr<CounterDirectiveMap>& CounterDirectivesInternal() const {
    return misc_data_->misc_7_data_->counter_directives_;
  }

  void SetCounterDirectivesInternal(std::unique_ptr<CounterDirectiveMap>&& v) {
    if (!(misc_data_->misc_7_data_->counter_directives_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->counter_directives_ = std::move(v);
  }


  std::unique_ptr<CounterDirectiveMap>& MutableCounterDirectivesInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->counter_directives_;
  }


  // CounterIncrementList
  


  // CounterResetList
  


  // CounterSetList
  


  // CssDominantBaseline
  


  EDominantBaseline MutableCssDominantBaselineInternal() {
    return static_cast<EDominantBaseline>(Access(svginherited_data_, access_.svginherited_data_)->css_dominant_baseline_);
  }


  // cursor
  


  ECursor MutableCursorInternal() {
    return static_cast<ECursor>(Access(inherited_data_, access_.inherited_data_)->cursor_);
  }


  // CursorData
  const Member<CursorList>& CursorDataInternal() const {
    return misc_inherited_data_->misc_inherited_2_data_->cursor_data_;
  }

  void SetCursorDataInternal(Member<CursorList>&& v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->cursor_data_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->cursor_data_ = std::move(v);
  }


  Member<CursorList>& MutableCursorDataInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->cursor_data_;
  }


  // cursor
  


  bool MutableCursorIsInheritedInternal() {
    return static_cast<bool>(data_.cursor_is_inherited_);
  }


  // CustomHighlightNames
  const std::unique_ptr<HashSet<AtomicString>>& CustomHighlightNamesInternal() const {
    return misc_data_->misc_7_data_->custom_highlight_names_;
  }

  void SetCustomHighlightNamesInternal(std::unique_ptr<HashSet<AtomicString>>&& v) {
    if (!(misc_data_->misc_7_data_->custom_highlight_names_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->custom_highlight_names_ = std::move(v);
  }


  std::unique_ptr<HashSet<AtomicString>>& MutableCustomHighlightNamesInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->custom_highlight_names_;
  }


  // CustomStyleCallbackDependsOnFont
  

  // cx
  



  Length& MutableCxInternal() {
    return Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cx_;
  }


  // cy
  



  Length& MutableCyInternal() {
    return Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cy_;
  }


  // d
  


  // DarkColorScheme
  


  bool MutableDarkColorSchemeInternal() {
    return static_cast<bool>(data_.dark_color_scheme_);
  }


  // DependsOnAnchoredContainerQueries
  


  bool MutableDependsOnAnchoredContainerQueriesInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->depends_on_anchored_container_queries_);
  }


  // DependsOnScrollStateContainerQueries
  


  bool MutableDependsOnScrollStateContainerQueriesInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->depends_on_scroll_state_container_queries_);
  }


  // DependsOnSizeContainerQueries
  


  bool MutableDependsOnSizeContainerQueriesInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->depends_on_size_container_queries_);
  }


  // DependsOnStyleContainerQueries
  


  bool MutableDependsOnStyleContainerQueriesInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->depends_on_style_container_queries_);
  }


  // direction
  


  TextDirection MutableDirectionInternal() {
    return static_cast<TextDirection>(data_.direction_);
  }


  // Display
  


  EDisplay MutableDisplayInternal() {
    return static_cast<EDisplay>(data_.display_);
  }


  // DisplayLayoutCustomName
  



  AtomicString& MutableDisplayLayoutCustomNameInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->display_layout_custom_name_;
  }


  // DisplayLayoutCustomParentName
  



  AtomicString& MutableDisplayLayoutCustomParentNameInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->display_layout_custom_parent_name_;
  }


  // DocumentRulesSelectors
  
  void SetDocumentRulesSelectorsInternal(Member<GCedHeapHashSet<WeakMember<StyleRule>>>&& v) {
    if (!(misc_data_->misc_8_data_->document_rules_selectors_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->document_rules_selectors_ = std::move(v);
  }


  Member<GCedHeapHashSet<WeakMember<StyleRule>>>& MutableDocumentRulesSelectorsInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->document_rules_selectors_;
  }


  // dominant-baseline
  


  EDominantBaseline MutableDominantBaselineInternal() {
    return static_cast<EDominantBaseline>(Access(svginherited_data_, access_.svginherited_data_)->dominant_baseline_);
  }


  // window-drag
  


  EDraggableRegionMode MutableDraggableRegionModeInternal() {
    return static_cast<EDraggableRegionMode>(Access(misc_inherited_data_, access_.misc_inherited_data_)->draggable_region_mode_);
  }


  // dynamic-range-limit
  



  DynamicRangeLimit& MutableDynamicRangeLimitInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->dynamic_range_limit_;
  }


  // EffectiveAppearance
  


  AppearanceValue MutableEffectiveAppearanceInternal() {
    return static_cast<AppearanceValue>(Access(misc_data_, access_.misc_data_)->effective_appearance_);
  }


  // EffectiveTouchAction
  


  TouchAction MutableEffectiveTouchActionInternal() {
    return static_cast<TouchAction>(Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->effective_touch_action_);
  }


  // EffectiveZoom
  
  void SetEffectiveZoomInternal(float v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->effective_zoom_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->effective_zoom_ = v;
  }


  float MutableEffectiveZoomInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->effective_zoom_;
  }


  // ElementIsViewTransitionParticipant
  

  // empty-cells
  


  EEmptyCells MutableEmptyCellsInternal() {
    return static_cast<EEmptyCells>(Access(misc_inherited_data_, access_.misc_inherited_data_)->empty_cells_);
  }


  // empty-cells
  


  bool MutableEmptyCellsIsInheritedInternal() {
    return static_cast<bool>(data_.empty_cells_is_inherited_);
  }


  // field-sizing
  


  EFieldSizing MutableFieldSizingInternal() {
    return static_cast<EFieldSizing>(Access(visual_data_, access_.visual_data_)->field_sizing_);
  }


  // fill-opacity
  


  float MutableFillOpacityInternal() {
    return Access(Access(svginherited_data_, access_.svginherited_data_)->fill_data_, access_.fill_data_)->fill_opacity_;
  }


  // fill
  



  SVGPaint& MutableFillPaintInternal() {
    return Access(Access(svginherited_data_, access_.svginherited_data_)->fill_data_, access_.fill_data_)->fill_paint_;
  }


  // fill-rule
  


  WindRule MutableFillRuleInternal() {
    return static_cast<WindRule>(Access(svginherited_data_, access_.svginherited_data_)->fill_rule_);
  }


  // filter
  



  FilterOperations& MutableFilterInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->filter_;
  }


  // FirstLineDependsOnSizeContainerQueries
  


  bool MutableFirstLineDependsOnSizeContainerQueriesInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->first_line_depends_on_size_container_queries_);
  }


  // flex-basis
  



  Length& MutableFlexBasisInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_basis_;
  }


  // flex-direction
  


  EFlexDirection MutableFlexDirectionInternal() {
    return static_cast<EFlexDirection>(Access(misc_data_, access_.misc_data_)->flex_direction_);
  }


  // flex-grow
  


  float MutableFlexGrowInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_grow_;
  }


  // flex-line-count
  


  uint16_t MutableFlexLineCountInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_line_count_;
  }


  // flex-shrink
  


  float MutableFlexShrinkInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_shrink_;
  }


  // flex-wrap
  



  StyleFlexWrapData& MutableFlexWrapInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flex_wrap_;
  }


  // float
  EFloat Floating() const {
    return static_cast<EFloat>(data_.floating_);
  }



  EFloat MutableFloatingInternal() {
    return static_cast<EFloat>(data_.floating_);
  }


  // flood-color
  



  StyleColor& MutableFloodColorInternal() {
    return Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->flood_color_;
  }


  // flood-opacity
  


  float MutableFloodOpacityInternal() {
    return Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->flood_opacity_;
  }


  // flow-tolerance
  



  FlowTolerance& MutableFlowToleranceInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->flow_tolerance_;
  }


  // font
  


  // forced-color-adjust
  


  EForcedColorAdjust MutableForcedColorAdjustInternal() {
    return static_cast<EForcedColorAdjust>(Access(misc_inherited_data_, access_.misc_inherited_data_)->forced_color_adjust_);
  }


  // ForcesBlockifiesChildren
  

  // ForcesStackingContext
  


  bool MutableForcesStackingContextInternal() {
    return static_cast<bool>(data_.forces_stacking_context_);
  }


  // frame-sizing
  


  EFrameSizing MutableFrameSizingInternal() {
    return static_cast<EFrameSizing>(Access(surround_data_, access_.surround_data_)->frame_sizing_);
  }


  // grid-auto-columns
  



  GridTrackList& MutableGridAutoColumnsInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->grid_auto_columns_;
  }


  // grid-auto-flow
  GridAutoFlow GridAutoFlowInternal() const {
    return static_cast<GridAutoFlow>(misc_data_->grid_auto_flow_);
  }



  GridAutoFlow MutableGridAutoFlowInternal() {
    return static_cast<GridAutoFlow>(Access(misc_data_, access_.misc_data_)->grid_auto_flow_);
  }


  // grid-auto-rows
  



  GridTrackList& MutableGridAutoRowsInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_2_data_, access_.misc_2_data_)->grid_auto_rows_;
  }


  // grid-column-end
  



  GridPosition& MutableGridColumnEndInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_column_end_;
  }


  // grid-column-start
  



  GridPosition& MutableGridColumnStartInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_column_start_;
  }


  // grid-lanes-direction
  



  GridLanesDirection& MutableGridLanesDirectionInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_lanes_direction_;
  }


  // grid-lanes-pack
  


  EGridLanesPack MutableGridLanesPackInternal() {
    return static_cast<EGridLanesPack>(Access(misc_data_, access_.misc_data_)->grid_lanes_pack_);
  }


  // grid-row-end
  



  GridPosition& MutableGridRowEndInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_row_end_;
  }


  // grid-row-start
  



  GridPosition& MutableGridRowStartInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_row_start_;
  }


  // grid-template-areas
  


  Member<ComputedGridTemplateAreas>& MutableGridTemplateAreasInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_template_areas_;
  }


  // grid-template-columns
  


  Member<ComputedGridTrackList>& MutableGridTemplateColumnsInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_template_columns_;
  }


  // grid-template-rows
  


  Member<ComputedGridTrackList>& MutableGridTemplateRowsInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->grid_template_rows_;
  }


  // hanging-punctuation
  

  // HasAnchorEvaluator
  

  // HasAnchorFunctions
  

  // HasAttrFunction
  

  // HasAuthorBackground
  

  // HasAuthorBorder
  

  // HasAuthorBorderRadius
  

  // HasAuthorHighlightColors
  

  // HasAutoClip
  
  void SetHasAutoClipInternal(bool v) {
    if (!(visual_data_->has_auto_clip_ == static_cast<unsigned>(v)))
      Access(visual_data_, access_.visual_data_)->has_auto_clip_ = static_cast<unsigned>(v);
  }


  bool MutableHasAutoClipInternal() {
    return static_cast<bool>(Access(visual_data_, access_.visual_data_)->has_auto_clip_);
  }


  // HasAutoColumnCount
  
  void SetHasAutoColumnCountInternal(bool v) {
    if (!(misc_data_->has_auto_column_count_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_auto_column_count_ = static_cast<unsigned>(v);
  }


  bool MutableHasAutoColumnCountInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_auto_column_count_);
  }


  // HasAutoColumnHeight
  
  void SetHasAutoColumnHeightInternal(bool v) {
    if (!(misc_data_->has_auto_column_height_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_auto_column_height_ = static_cast<unsigned>(v);
  }


  bool MutableHasAutoColumnHeightInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_auto_column_height_);
  }


  // HasAutoColumnWidth
  
  void SetHasAutoColumnWidthInternal(bool v) {
    if (!(misc_data_->has_auto_column_width_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->has_auto_column_width_ = static_cast<unsigned>(v);
  }


  bool MutableHasAutoColumnWidthInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_auto_column_width_);
  }


  // HasAutoZIndex
  
  void SetHasAutoZIndexInternal(bool v) {
    if (!(box_data_->has_auto_z_index_ == static_cast<unsigned>(v)))
      Access(box_data_, access_.box_data_)->has_auto_z_index_ = static_cast<unsigned>(v);
  }


  bool MutableHasAutoZIndexInternal() {
    return static_cast<bool>(Access(box_data_, access_.box_data_)->has_auto_z_index_);
  }


  // HasClipPath
  


  bool MutableHasClipPathInternal() {
    return static_cast<bool>(Access(visual_data_, access_.visual_data_)->has_clip_path_);
  }


  // HasContainerRelativeValue
  

  // HasCurrentBackdropFilterAnimation
  


  bool MutableHasCurrentBackdropFilterAnimationInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_current_backdrop_filter_animation_);
  }


  // HasCurrentBackgroundColorAnimation
  


  bool MutableHasCurrentBackgroundColorAnimationInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_current_background_color_animation_);
  }


  // HasCurrentClipPathAnimation
  


  bool MutableHasCurrentClipPathAnimationInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_current_clip_path_animation_);
  }


  // HasCurrentFilterAnimation
  


  bool MutableHasCurrentFilterAnimationInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_current_filter_animation_);
  }


  // HasCurrentOpacityAnimation
  


  bool MutableHasCurrentOpacityAnimationInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_current_opacity_animation_);
  }


  // HasCurrentRotateAnimation
  


  bool MutableHasCurrentRotateAnimationInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_current_rotate_animation_);
  }


  // HasCurrentScaleAnimation
  


  bool MutableHasCurrentScaleAnimationInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_current_scale_animation_);
  }


  // HasCurrentTransformAnimation
  


  bool MutableHasCurrentTransformAnimationInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_current_transform_animation_);
  }


  // HasCurrentTranslateAnimation
  


  bool MutableHasCurrentTranslateAnimationInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_current_translate_animation_);
  }


  // HasCustomHighlightUniversalSelector
  


  bool MutableHasCustomHighlightUniversalSelectorInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_custom_highlight_universal_selector_);
  }


  // HasElementDependentRandomFunctions
  

  // HasEmUnits
  

  // HasEnv
  

  // HasEnvSafeAreaInsetBottom
  

  // HasExplicitInheritance
  

  // HasExplicitOverflowXVisible
  

  // HasExplicitOverflowYVisible
  

  // HasGlyphRelativeUnits
  

  // HasLayoutContainmentForViewTransitionScope
  


  bool MutableHasLayoutContainmentForViewTransitionScopeInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_layout_containment_for_view_transition_scope_);
  }


  // HasLineHeightRelativeUnits
  

  // -internal-empty-line-height
  


  bool MutableHasLineIfEmptyInternal() {
    return static_cast<bool>(Access(misc_inherited_data_, access_.misc_inherited_data_)->has_line_if_empty_);
  }


  // HasLogicalDirectionRelativeUnits
  

  // HasNonUaHighlightPseudoStyles
  


  bool MutableHasNonUaHighlightPseudoStylesInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_non_ua_highlight_pseudo_styles_);
  }


  // HasNonUniversalHighlightPseudoStyles
  


  bool MutableHasNonUniversalHighlightPseudoStylesInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_non_universal_highlight_pseudo_styles_);
  }


  // HasRootRelativeUnits
  

  // HasSiblingFunctions
  

  // HasSizeContainmentForViewTransitionScope
  


  bool MutableHasSizeContainmentForViewTransitionScopeInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->has_size_containment_for_view_transition_scope_);
  }


  // HasVariableDeclaration
  

  // HasVariableReference
  

  // height
  



  Length& MutableHeightInternal() {
    return Access(box_data_, access_.box_data_)->height_;
  }


  // HighlightData
  



  StyleHighlightData& MutableHighlightDataInternal() {
    return Access(Access(inherited_data_, access_.inherited_data_)->highlight_data_data_, access_.highlight_data_data_)->highlight_data_;
  }


  // HighlightsDependOnSizeContainerQueries
  


  bool MutableHighlightsDependOnSizeContainerQueriesInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->highlights_depend_on_size_container_queries_);
  }


  // -webkit-border-horizontal-spacing
  


  short MutableHorizontalBorderSpacingInternal() {
    return Access(inherited_data_, access_.inherited_data_)->horizontal_border_spacing_;
  }


  // hyphenate-limit-chars
  



  StyleHyphenateLimitChars& MutableHyphenateLimitCharsInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->hyphenate_limit_chars_;
  }


  // hyphenate-character
  



  AtomicString& MutableHyphenationStringInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->hyphenation_string_;
  }


  // hyphens
  


  Hyphens MutableHyphensInternal() {
    return static_cast<Hyphens>(Access(misc_inherited_data_, access_.misc_inherited_data_)->hyphens_);
  }


  // image-animation
  


  ImageAnimationEnum MutableImageAnimationInternal() {
    return static_cast<ImageAnimationEnum>(Access(misc_inherited_data_, access_.misc_inherited_data_)->image_animation_);
  }


  // image-orientation
  


  RespectImageOrientationEnum MutableImageOrientationInternal() {
    return static_cast<RespectImageOrientationEnum>(Access(misc_inherited_data_, access_.misc_inherited_data_)->image_orientation_);
  }


  // image-rendering
  


  EImageRendering MutableImageRenderingInternal() {
    return static_cast<EImageRendering>(Access(misc_inherited_data_, access_.misc_inherited_data_)->image_rendering_);
  }


  // InBaseAppearance
  


  bool MutableInBaseAppearanceInternal() {
    return static_cast<bool>(Access(misc_inherited_data_, access_.misc_inherited_data_)->in_base_appearance_);
  }


  // InForcedColorsMode
  


  bool MutableInForcedColorsModeInternal() {
    return static_cast<bool>(Access(inherited_data_, access_.inherited_data_)->in_forced_colors_mode_);
  }


  // InheritedVariables
  const StyleInheritedVariables& InheritedVariablesInternal() const {
    return inherited_data_->inherited_variables_;
  }

  void SetInheritedVariablesInternal(const StyleInheritedVariables& v) {
    if (!(inherited_data_->inherited_variables_ == v))
      Access(inherited_data_, access_.inherited_data_)->inherited_variables_ = v;
  }

  void SetInheritedVariablesInternal(StyleInheritedVariables&& v) {
    if (!(inherited_data_->inherited_variables_ == v))
      Access(inherited_data_, access_.inherited_data_)->inherited_variables_ = std::move(v);
  }


  StyleInheritedVariables& MutableInheritedVariablesInternal() {
    return Access(inherited_data_, access_.inherited_data_)->inherited_variables_;
  }


  // InitialData
  


  // initial-letter
  



  StyleInitialLetter& MutableInitialLetterInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->initial_letter_;
  }


  // InlineBlockBaselineEdge
  


  EInlineBlockBaselineEdge MutableInlineBlockBaselineEdgeInternal() {
    return static_cast<EInlineBlockBaselineEdge>(data_.inline_block_baseline_edge_);
  }


  // InlineStyleLostCascade
  


  bool MutableInlineStyleLostCascadeInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->inline_style_lost_cascade_);
  }


  // InsideLink
  


  EInsideLink MutableInsideLinkInternal() {
    return static_cast<EInsideLink>(data_.inside_link_);
  }


  // interactivity
  


  EInteractivity MutableInteractivityInternal() {
    return static_cast<EInteractivity>(Access(misc_inherited_data_, access_.misc_inherited_data_)->interactivity_);
  }


  // interactivity
  


  bool MutableInteractivityIsInheritedInternal() {
    return static_cast<bool>(data_.interactivity_is_inherited_);
  }


  // interest-delay-end
  



  StyleInterestDelay& MutableInterestDelayEndInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->interest_delay_end_;
  }


  // interest-delay-start
  



  StyleInterestDelay& MutableInterestDelayStartInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->interest_delay_start_;
  }


  // -internal-forced-background-color
  const StyleColor& InternalForcedBackgroundColor() const {
    return misc_data_->forced_colors_data_->internal_forced_background_color_;
  }




  StyleColor& MutableInternalForcedBackgroundColorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->forced_colors_data_, access_.forced_colors_data_)->internal_forced_background_color_;
  }


  // -internal-forced-border-color
  const StyleColor& InternalForcedBorderColor() const {
    return misc_data_->forced_colors_data_->internal_forced_border_color_;
  }




  StyleColor& MutableInternalForcedBorderColorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->forced_colors_data_, access_.forced_colors_data_)->internal_forced_border_color_;
  }


  // -internal-forced-color
  const StyleColor& InternalForcedColor() const {
    return inherited_data_->inherited_forced_colors_data_->internal_forced_color_;
  }




  StyleColor& MutableInternalForcedColorInternal() {
    return Access(Access(inherited_data_, access_.inherited_data_)->inherited_forced_colors_data_, access_.inherited_forced_colors_data_)->internal_forced_color_;
  }


  // -internal-forced-outline-color
  const StyleColor& InternalForcedOutlineColor() const {
    return misc_data_->forced_colors_data_->internal_forced_outline_color_;
  }




  StyleColor& MutableInternalForcedOutlineColorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->forced_colors_data_, access_.forced_colors_data_)->internal_forced_outline_color_;
  }


  // -internal-forced-visited-color
  const StyleColor& InternalForcedVisitedColor() const {
    return inherited_data_->inherited_forced_colors_data_->internal_forced_visited_color_;
  }




  StyleColor& MutableInternalForcedVisitedColorInternal() {
    return Access(Access(inherited_data_, access_.inherited_data_)->inherited_forced_colors_data_, access_.inherited_forced_colors_data_)->internal_forced_visited_color_;
  }


  // -internal-overscroll-container
  


  EInternalOverscrollContainer MutableInternalOverscrollContainerInternal() {
    return static_cast<EInternalOverscrollContainer>(Access(misc_data_, access_.misc_data_)->internal_overscroll_container_);
  }


  // -internal-overscroll-position
  


  EInternalOverscrollPosition MutableInternalOverscrollPositionInternal() {
    return static_cast<EInternalOverscrollPosition>(Access(misc_data_, access_.misc_data_)->internal_overscroll_position_);
  }


  // -internal-unbounded
  


  EInternalUnbounded MutableInternalUnboundedInternal() {
    return static_cast<EInternalUnbounded>(Access(misc_data_, access_.misc_data_)->internal_unbounded_);
  }


  // -internal-visited-background-color
  const StyleColor& InternalVisitedBackgroundColor() const {
    return misc_data_->visited_data_->internal_visited_background_color_;
  }




  StyleColor& MutableInternalVisitedBackgroundColorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_background_color_;
  }


  // -internal-visited-border-bottom-color
  const StyleColor& InternalVisitedBorderBottomColor() const {
    return misc_data_->visited_data_->internal_visited_border_bottom_color_;
  }




  StyleColor& MutableInternalVisitedBorderBottomColorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_bottom_color_;
  }


  // -internal-visited-border-left-color
  const StyleColor& InternalVisitedBorderLeftColor() const {
    return misc_data_->visited_data_->internal_visited_border_left_color_;
  }




  StyleColor& MutableInternalVisitedBorderLeftColorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_left_color_;
  }


  // -internal-visited-border-right-color
  const StyleColor& InternalVisitedBorderRightColor() const {
    return misc_data_->visited_data_->internal_visited_border_right_color_;
  }




  StyleColor& MutableInternalVisitedBorderRightColorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_right_color_;
  }


  // -internal-visited-border-top-color
  const StyleColor& InternalVisitedBorderTopColor() const {
    return misc_data_->visited_data_->internal_visited_border_top_color_;
  }




  StyleColor& MutableInternalVisitedBorderTopColorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_border_top_color_;
  }


  // -internal-visited-caret-color
  const StyleCaretColor& InternalVisitedCaretColor() const {
    return inherited_data_->inherited_visited_data_->internal_visited_caret_color_;
  }




  StyleCaretColor& MutableInternalVisitedCaretColorInternal() {
    return Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_caret_color_;
  }


  // -internal-visited-color
  const StyleColor& InternalVisitedColor() const {
    return inherited_data_->internal_visited_color_;
  }




  StyleColor& MutableInternalVisitedColorInternal() {
    return Access(inherited_data_, access_.inherited_data_)->internal_visited_color_;
  }


  // InternalVisitedColorIsCurrentColor
  bool InternalVisitedColorIsCurrentColor() const {
    return static_cast<bool>(inherited_data_->internal_visited_color_is_current_color_);
  }



  bool MutableInternalVisitedColorIsCurrentColorInternal() {
    return static_cast<bool>(Access(inherited_data_, access_.inherited_data_)->internal_visited_color_is_current_color_);
  }


  // -internal-visited-column-rule-color
  



  GapDataList<StyleColor>& MutableInternalVisitedColumnRuleColorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_column_rule_color_;
  }


  // -internal-visited-fill
  



  SVGPaint& MutableInternalVisitedFillPaintInternal() {
    return Access(Access(svginherited_data_, access_.svginherited_data_)->fill_data_, access_.fill_data_)->internal_visited_fill_paint_;
  }


  // -internal-visited-outline-color
  const StyleColor& InternalVisitedOutlineColor() const {
    return misc_data_->visited_data_->internal_visited_outline_color_;
  }




  StyleColor& MutableInternalVisitedOutlineColorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_outline_color_;
  }


  // -internal-visited-stroke
  



  SVGPaint& MutableInternalVisitedStrokePaintInternal() {
    return Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->internal_visited_stroke_paint_;
  }


  // -internal-visited-text-decoration-color
  const StyleColor& InternalVisitedTextDecorationColor() const {
    return misc_data_->visited_data_->internal_visited_text_decoration_color_;
  }




  StyleColor& MutableInternalVisitedTextDecorationColorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->visited_data_, access_.visited_data_)->internal_visited_text_decoration_color_;
  }


  // -internal-visited-text-emphasis-color
  const StyleColor& InternalVisitedTextEmphasisColor() const {
    return inherited_data_->inherited_visited_data_->internal_visited_text_emphasis_color_;
  }




  StyleColor& MutableInternalVisitedTextEmphasisColorInternal() {
    return Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_text_emphasis_color_;
  }


  // -internal-visited-text-fill-color
  const StyleColor& InternalVisitedTextFillColor() const {
    return inherited_data_->inherited_visited_data_->internal_visited_text_fill_color_;
  }




  StyleColor& MutableInternalVisitedTextFillColorInternal() {
    return Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_text_fill_color_;
  }


  // -internal-visited-text-stroke-color
  const StyleColor& InternalVisitedTextStrokeColor() const {
    return inherited_data_->inherited_visited_data_->internal_visited_text_stroke_color_;
  }




  StyleColor& MutableInternalVisitedTextStrokeColorInternal() {
    return Access(Access(inherited_data_, access_.inherited_data_)->inherited_visited_data_, access_.inherited_visited_data_)->internal_visited_text_stroke_color_;
  }


  // interpolate-size
  


  EInterpolateSize MutableInterpolateSizeInternal() {
    return static_cast<EInterpolateSize>(Access(misc_inherited_data_, access_.misc_inherited_data_)->interpolate_size_);
  }


  // IsBottomRelativeToSafeAreaInset
  


  bool MutableIsBottomRelativeToSafeAreaInsetInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->is_bottom_relative_to_safe_area_inset_);
  }


  // IsCSSInert
  


  bool MutableIsCSSInertInternal() {
    return static_cast<bool>(data_.is_css_inert_);
  }


  // IsCSSInert
  


  bool MutableIsCSSInertIsInheritedInternal() {
    return static_cast<bool>(data_.is_css_inert_is_inherited_);
  }


  // IsEnsuredInDisplayNone
  

  // IsFlexOrGridOrCustomItem
  

  // IsHTMLInert
  


  bool MutableIsHTMLInertInternal() {
    return static_cast<bool>(data_.is_html_inert_);
  }


  // IsHTMLInert
  


  bool MutableIsHTMLInertIsInheritedInternal() {
    return static_cast<bool>(data_.is_html_inert_is_inherited_);
  }


  // IsInBlockifyingDisplay
  

  // IsInInlinifyingDisplay
  

  // IsInShrinkToFitSubtree
  


  bool MutableIsInShrinkToFitSubtreeInternal() {
    return static_cast<bool>(Access(misc_inherited_data_, access_.misc_inherited_data_)->is_in_shrink_to_fit_subtree_);
  }


  // IsInsideDisplayIgnoringFloatingChildren
  

  // IsLink
  

  // IsOriginalDisplayInlineType
  


  bool MutableIsOriginalDisplayInlineTypeInternal() {
    return static_cast<bool>(data_.is_original_display_inline_type_);
  }


  // IsPageMarginBox
  


  bool MutableIsPageMarginBoxInternal() {
    return static_cast<bool>(data_.is_page_margin_box_);
  }


  // IsRunningBackdropFilterAnimationOnCompositor
  


  bool MutableIsRunningBackdropFilterAnimationOnCompositorInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->is_running_backdrop_filter_animation_on_compositor_);
  }


  // IsRunningFilterAnimationOnCompositor
  


  bool MutableIsRunningFilterAnimationOnCompositorInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->is_running_filter_animation_on_compositor_);
  }


  // IsRunningOpacityAnimationOnCompositor
  


  bool MutableIsRunningOpacityAnimationOnCompositorInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->is_running_opacity_animation_on_compositor_);
  }


  // IsRunningRotateAnimationOnCompositor
  


  bool MutableIsRunningRotateAnimationOnCompositorInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->is_running_rotate_animation_on_compositor_);
  }


  // IsRunningScaleAnimationOnCompositor
  


  bool MutableIsRunningScaleAnimationOnCompositorInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->is_running_scale_animation_on_compositor_);
  }


  // IsRunningTransformAnimationOnCompositor
  


  bool MutableIsRunningTransformAnimationOnCompositorInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->is_running_transform_animation_on_compositor_);
  }


  // IsRunningTranslateAnimationOnCompositor
  


  bool MutableIsRunningTranslateAnimationOnCompositorInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->is_running_translate_animation_on_compositor_);
  }


  // IsSecondaryBodyElement
  

  // IsSpecifiedDisplayWebkitBox
  

  // IsStartingStyle
  

  // isolation
  


  EIsolation MutableIsolationInternal() {
    return static_cast<EIsolation>(Access(misc_data_, access_.misc_data_)->isolation_);
  }


  // stroke-linejoin
  


  LineJoin MutableJoinStyleInternal() {
    return static_cast<LineJoin>(Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->join_style_);
  }


  // justify-content
  



  StyleContentAlignmentData& MutableJustifyContentInternal() {
    return Access(box_data_, access_.box_data_)->justify_content_;
  }


  // justify-items
  



  StyleSelfAlignmentData& MutableJustifyItemsInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->justify_items_;
  }


  // justify-self
  



  StyleSelfAlignmentData& MutableJustifySelfInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->justify_self_;
  }


  // left
  



  Length& MutableLeftInternal() {
    return Access(surround_data_, access_.surround_data_)->left_;
  }


  // letter-spacing
  const Length& LetterSpacingInternal() const {
    return inherited_data_->letter_spacing_;
  }




  Length& MutableLetterSpacingInternal() {
    return Access(inherited_data_, access_.inherited_data_)->letter_spacing_;
  }


  // lighting-color
  



  StyleColor& MutableLightingColorInternal() {
    return Access(Access(svg_data_, access_.svg_data_)->svgmisc_data_, access_.svgmisc_data_)->lighting_color_;
  }


  // line-break
  


  LineBreak MutableLineBreakInternal() {
    return static_cast<LineBreak>(Access(misc_inherited_data_, access_.misc_inherited_data_)->line_break_);
  }


  // LineClampInternalBlockEllipsis
  


  EBlockEllipsis MutableLineClampInternalBlockEllipsisInternal() {
    return static_cast<EBlockEllipsis>(Access(misc_data_, access_.misc_data_)->line_clamp_internal_block_ellipsis_);
  }


  // line-height
  



  Length& MutableLineHeightInternal() {
    return Access(inherited_data_, access_.inherited_data_)->line_height_;
  }


  // list-style-image
  


  Member<StyleImage>& MutableListStyleImageInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->list_style_image_;
  }


  // list-style-position
  


  EListStylePosition MutableListStylePositionInternal() {
    return static_cast<EListStylePosition>(data_.list_style_position_);
  }


  // list-style-position
  


  bool MutableListStylePositionIsInheritedInternal() {
    return static_cast<bool>(data_.list_style_position_is_inherited_);
  }


  // list-style-type
  


  Member<ListStyleTypeData>& MutableListStyleTypeInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->list_style_type_;
  }


  // margin-bottom
  
  void SetMarginBottomInternal(const Length& v) {
    if (!(box_data_->margin_bottom_ == v))
      Access(box_data_, access_.box_data_)->margin_bottom_ = v;
  }

  void SetMarginBottomInternal(Length&& v) {
    if (!(box_data_->margin_bottom_ == v))
      Access(box_data_, access_.box_data_)->margin_bottom_ = std::move(v);
  }


  Length& MutableMarginBottomInternal() {
    return Access(box_data_, access_.box_data_)->margin_bottom_;
  }


  // margin-left
  
  void SetMarginLeftInternal(const Length& v) {
    if (!(box_data_->margin_left_ == v))
      Access(box_data_, access_.box_data_)->margin_left_ = v;
  }

  void SetMarginLeftInternal(Length&& v) {
    if (!(box_data_->margin_left_ == v))
      Access(box_data_, access_.box_data_)->margin_left_ = std::move(v);
  }


  Length& MutableMarginLeftInternal() {
    return Access(box_data_, access_.box_data_)->margin_left_;
  }


  // margin-right
  
  void SetMarginRightInternal(const Length& v) {
    if (!(box_data_->margin_right_ == v))
      Access(box_data_, access_.box_data_)->margin_right_ = v;
  }

  void SetMarginRightInternal(Length&& v) {
    if (!(box_data_->margin_right_ == v))
      Access(box_data_, access_.box_data_)->margin_right_ = std::move(v);
  }


  Length& MutableMarginRightInternal() {
    return Access(box_data_, access_.box_data_)->margin_right_;
  }


  // margin-top
  
  void SetMarginTopInternal(const Length& v) {
    if (!(box_data_->margin_top_ == v))
      Access(box_data_, access_.box_data_)->margin_top_ = v;
  }

  void SetMarginTopInternal(Length&& v) {
    if (!(box_data_->margin_top_ == v))
      Access(box_data_, access_.box_data_)->margin_top_ = std::move(v);
  }


  Length& MutableMarginTopInternal() {
    return Access(box_data_, access_.box_data_)->margin_top_;
  }


  // margin-trim
  


  unsigned MutableMarginTrimInternal() {
    return static_cast<unsigned>(Access(misc_data_, access_.misc_data_)->margin_trim_);
  }


  // marker-end
  


  // marker-mid
  


  // marker-start
  


  // Mask
  const FillLayer& MaskInternal() const {
    return misc_data_->misc_7_data_->mask_;
  }

  void SetMaskInternal(const FillLayer& v) {
    if (!(misc_data_->misc_7_data_->mask_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->mask_ = v;
  }

  void SetMaskInternal(FillLayer&& v) {
    if (!(misc_data_->misc_7_data_->mask_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->mask_ = std::move(v);
  }


  FillLayer& MutableMaskInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->mask_;
  }


  // MaskBoxImage
  const NinePieceImage& MaskBoxImageInternal() const {
    return misc_data_->misc_7_data_->mask_box_image_;
  }

  void SetMaskBoxImageInternal(const NinePieceImage& v) {
    if (!(misc_data_->misc_7_data_->mask_box_image_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->mask_box_image_ = v;
  }

  void SetMaskBoxImageInternal(NinePieceImage&& v) {
    if (!(misc_data_->misc_7_data_->mask_box_image_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->mask_box_image_ = std::move(v);
  }


  NinePieceImage& MutableMaskBoxImageInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->mask_box_image_;
  }


  // mask-type
  


  EMaskType MutableMaskTypeInternal() {
    return static_cast<EMaskType>(Access(svg_data_, access_.svg_data_)->mask_type_);
  }


  // MathBaseline
  



  Length& MutableMathBaselineInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_baseline_;
  }


  // math-depth
  


  short MutableMathDepthInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->math_depth_;
  }


  // MathFractionBarThickness
  



  Length& MutableMathFractionBarThicknessInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_fraction_bar_thickness_;
  }


  // MathLSpace
  



  Length& MutableMathLSpaceInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_l_space_;
  }


  // MathMaxSize
  



  Length& MutableMathMaxSizeInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_max_size_;
  }


  // MathMinSize
  



  Length& MutableMathMinSizeInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_min_size_;
  }


  // MathPaddedDepth
  



  Length& MutableMathPaddedDepthInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_padded_depth_;
  }


  // MathPaddedVOffset
  



  Length& MutableMathPaddedVOffsetInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_padded_v_offset_;
  }


  // MathRSpace
  



  Length& MutableMathRSpaceInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->math_data_, access_.math_data_)->math_r_space_;
  }


  // math-shift
  


  EMathShift MutableMathShiftInternal() {
    return static_cast<EMathShift>(Access(misc_inherited_data_, access_.misc_inherited_data_)->math_shift_);
  }


  // math-style
  


  EMathStyle MutableMathStyleInternal() {
    return static_cast<EMathStyle>(Access(misc_inherited_data_, access_.misc_inherited_data_)->math_style_);
  }


  // max-content-sizing
  


  EMaxContentSizing MutableMaxContentSizingInternal() {
    return static_cast<EMaxContentSizing>(Access(misc_data_, access_.misc_data_)->max_content_sizing_);
  }


  // max-height
  



  Length& MutableMaxHeightInternal() {
    return Access(box_data_, access_.box_data_)->max_height_;
  }


  // MaxLines
  



  MaxLinesData& MutableMaxLinesInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->max_lines_;
  }


  // max-width
  



  Length& MutableMaxWidthInternal() {
    return Access(box_data_, access_.box_data_)->max_width_;
  }


  // MayHaveMargin
  

  // MayHavePadding
  

  // MaybeHasGapDecorations
  

  // min-height
  



  Length& MutableMinHeightInternal() {
    return Access(box_data_, access_.box_data_)->min_height_;
  }


  // min-width
  



  Length& MutableMinWidthInternal() {
    return Access(box_data_, access_.box_data_)->min_width_;
  }


  // NonInheritedVariables
  const StyleNonInheritedVariables& NonInheritedVariablesInternal() const {
    return misc_data_->misc_8_data_->non_inherited_variables_;
  }

  void SetNonInheritedVariablesInternal(const StyleNonInheritedVariables& v) {
    if (!(misc_data_->misc_8_data_->non_inherited_variables_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->non_inherited_variables_ = v;
  }

  void SetNonInheritedVariablesInternal(StyleNonInheritedVariables&& v) {
    if (!(misc_data_->misc_8_data_->non_inherited_variables_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->non_inherited_variables_ = std::move(v);
  }


  StyleNonInheritedVariables& MutableNonInheritedVariablesInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->non_inherited_variables_;
  }


  // object-fit
  


  EObjectFit MutableObjectFitInternal() {
    return static_cast<EObjectFit>(Access(misc_data_, access_.misc_data_)->object_fit_);
  }


  // object-position
  



  LengthPoint& MutableObjectPositionInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->object_position_;
  }


  // object-view-box
  


  // offset-anchor
  



  LengthPoint& MutableOffsetAnchorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_3_data_, access_.misc_3_data_)->offset_anchor_;
  }


  // offset-distance
  



  Length& MutableOffsetDistanceInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->offset_distance_;
  }


  // offset-path
  


  // offset-position
  



  LengthPoint& MutableOffsetPositionInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->offset_position_;
  }


  // offset-rotate
  



  StyleOffsetRotation& MutableOffsetRotateInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->offset_rotate_;
  }


  // opacity
  
  void SetOpacityInternal(float v) {
    if (!(svg_data_->opacity_ == v))
      Access(svg_data_, access_.svg_data_)->opacity_ = v;
  }


  float MutableOpacityInternal() {
    return Access(svg_data_, access_.svg_data_)->opacity_;
  }


  // order
  


  int MutableOrderInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->order_;
  }


  // origin-trial-test-property
  


  EOriginTrialTestProperty MutableOriginTrialTestPropertyInternal() {
    return static_cast<EOriginTrialTestProperty>(data_.origin_trial_test_property_);
  }


  // orphans
  
  void SetOrphansInternal(short v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->orphans_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->orphans_ = v;
  }


  short MutableOrphansInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->orphans_;
  }


  // outline-color
  const StyleColor& OutlineColor() const {
    return misc_data_->misc_4_data_->outline_color_;
  }




  StyleColor& MutableOutlineColorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->outline_color_;
  }


  // outline-offset
  



  int& MutableOutlineOffsetInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->outline_offset_;
  }


  // outline-style
  


  EBorderStyle MutableOutlineStyleInternal() {
    return static_cast<EBorderStyle>(Access(misc_data_, access_.misc_data_)->outline_style_);
  }


  // OutlineStyleIsAuto
  


  bool MutableOutlineStyleIsAutoInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->outline_style_is_auto_);
  }


  // outline-width
  



  int& MutableOutlineWidthInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->outline_width_;
  }


  // overflow-anchor
  


  EOverflowAnchor MutableOverflowAnchorInternal() {
    return static_cast<EOverflowAnchor>(data_.overflow_anchor_);
  }


  // overflow-clip-margin
  



  std::optional<StyleOverflowClipMargin>& MutableOverflowClipMarginInternal() {
    return Access(box_data_, access_.box_data_)->overflow_clip_margin_;
  }


  // overflow-wrap
  


  EOverflowWrap MutableOverflowWrapInternal() {
    return static_cast<EOverflowWrap>(Access(misc_inherited_data_, access_.misc_inherited_data_)->overflow_wrap_);
  }


  // overflow-x
  


  EOverflow MutableOverflowXInternal() {
    return static_cast<EOverflow>(data_.overflow_x_);
  }


  // overflow-y
  


  EOverflow MutableOverflowYInternal() {
    return static_cast<EOverflow>(data_.overflow_y_);
  }


  // overlay
  


  EOverlay MutableOverlayInternal() {
    return static_cast<EOverlay>(Access(misc_data_, access_.misc_data_)->overlay_);
  }


  // overscroll-behavior-x
  


  EOverscrollBehavior MutableOverscrollBehaviorXInternal() {
    return static_cast<EOverscrollBehavior>(Access(misc_data_, access_.misc_data_)->overscroll_behavior_x_);
  }


  // overscroll-behavior-y
  


  EOverscrollBehavior MutableOverscrollBehaviorYInternal() {
    return static_cast<EOverscrollBehavior>(Access(misc_data_, access_.misc_data_)->overscroll_behavior_y_);
  }


  // overscroll-container-type
  


  EOverscrollContainerType MutableOverscrollContainerTypeInternal() {
    return static_cast<EOverscrollContainerType>(Access(misc_data_, access_.misc_data_)->overscroll_container_type_);
  }


  // padding-bottom
  
  void SetPaddingBottomInternal(const Length& v) {
    if (!(box_data_->padding_bottom_ == v))
      Access(box_data_, access_.box_data_)->padding_bottom_ = v;
  }

  void SetPaddingBottomInternal(Length&& v) {
    if (!(box_data_->padding_bottom_ == v))
      Access(box_data_, access_.box_data_)->padding_bottom_ = std::move(v);
  }


  Length& MutablePaddingBottomInternal() {
    return Access(box_data_, access_.box_data_)->padding_bottom_;
  }


  // padding-left
  
  void SetPaddingLeftInternal(const Length& v) {
    if (!(box_data_->padding_left_ == v))
      Access(box_data_, access_.box_data_)->padding_left_ = v;
  }

  void SetPaddingLeftInternal(Length&& v) {
    if (!(box_data_->padding_left_ == v))
      Access(box_data_, access_.box_data_)->padding_left_ = std::move(v);
  }


  Length& MutablePaddingLeftInternal() {
    return Access(box_data_, access_.box_data_)->padding_left_;
  }


  // padding-right
  
  void SetPaddingRightInternal(const Length& v) {
    if (!(box_data_->padding_right_ == v))
      Access(box_data_, access_.box_data_)->padding_right_ = v;
  }

  void SetPaddingRightInternal(Length&& v) {
    if (!(box_data_->padding_right_ == v))
      Access(box_data_, access_.box_data_)->padding_right_ = std::move(v);
  }


  Length& MutablePaddingRightInternal() {
    return Access(box_data_, access_.box_data_)->padding_right_;
  }


  // padding-top
  
  void SetPaddingTopInternal(const Length& v) {
    if (!(box_data_->padding_top_ == v))
      Access(box_data_, access_.box_data_)->padding_top_ = v;
  }

  void SetPaddingTopInternal(Length&& v) {
    if (!(box_data_->padding_top_ == v))
      Access(box_data_, access_.box_data_)->padding_top_ = std::move(v);
  }


  Length& MutablePaddingTopInternal() {
    return Access(box_data_, access_.box_data_)->padding_top_;
  }


  // page
  



  AtomicString& MutablePageInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->page_;
  }


  // page-margin-safety
  
  void SetPageMarginSafetyInternal(EPageMarginSafety v) {
    if (!(misc_data_->page_margin_safety_ == static_cast<unsigned>(v)))
      Access(misc_data_, access_.misc_data_)->page_margin_safety_ = static_cast<unsigned>(v);
  }


  EPageMarginSafety MutablePageMarginSafetyInternal() {
    return static_cast<EPageMarginSafety>(Access(misc_data_, access_.misc_data_)->page_margin_safety_);
  }


  // page-orientation
  


  PageOrientation MutablePageOrientationInternal() {
    return static_cast<PageOrientation>(Access(misc_data_, access_.misc_data_)->page_orientation_);
  }


  // PageSize
  



  gfx::SizeF& MutablePageSizeInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->page_size_;
  }


  // PageSizeType
  


  PageSizeType MutablePageSizeTypeInternal() {
    return static_cast<PageSizeType>(Access(misc_data_, access_.misc_data_)->page_size_type_);
  }


  // PaintImages
  const Member<PaintImages>& PaintImagesInternal() const {
    return misc_data_->misc_8_data_->paint_images_;
  }

  void SetPaintImagesInternal(Member<PaintImages>&& v) {
    if (!(misc_data_->misc_8_data_->paint_images_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->paint_images_ = std::move(v);
  }


  Member<PaintImages>& MutablePaintImagesInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->paint_images_;
  }


  // paint-order
  


  EPaintOrder MutablePaintOrderInternal() {
    return static_cast<EPaintOrder>(Access(svginherited_data_, access_.svginherited_data_)->paint_order_);
  }


  // path-length
  



  Length& MutablePathLengthInternal() {
    return Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->path_length_;
  }


  // perspective
  


  float MutablePerspectiveInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->perspective_;
  }


  // perspective-origin
  



  LengthPoint& MutablePerspectiveOriginInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->perspective_origin_;
  }


  // pointer-events
  EPointerEvents PointerEvents() const {
    return static_cast<EPointerEvents>(data_.pointer_events_);
  }



  EPointerEvents MutablePointerEventsInternal() {
    return static_cast<EPointerEvents>(data_.pointer_events_);
  }


  // pointer-events
  bool PointerEventsIsInherited() const {
    return static_cast<bool>(data_.pointer_events_is_inherited_);
  }



  bool MutablePointerEventsIsInheritedInternal() {
    return static_cast<bool>(data_.pointer_events_is_inherited_);
  }


  // position
  EPosition PositionInternal() const {
    return static_cast<EPosition>(data_.position_);
  }



  EPosition MutablePositionInternal() {
    return static_cast<EPosition>(data_.position_);
  }


  // position-anchor
  



  StylePositionAnchor& MutablePositionAnchorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->position_anchor_;
  }


  // position-area
  



  PositionArea& MutablePositionAreaInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_1_data_, access_.misc_1_data_)->position_area_;
  }


  // PositionAreaOffsets
  



  std::optional<blink::PositionAreaOffsets>& MutablePositionAreaOffsetsInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_8_data_, access_.misc_8_data_)->position_area_offsets_;
  }


  // position-try-fallbacks
  


  Member<PositionTryFallbacks>& MutablePositionTryFallbacksInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->position_try_fallbacks_;
  }


  // position-try-order
  


  EPositionTryOrder MutablePositionTryOrderInternal() {
    return static_cast<EPositionTryOrder>(Access(misc_data_, access_.misc_data_)->position_try_order_);
  }


  // position-visibility
  


  PositionVisibility MutablePositionVisibilityInternal() {
    return static_cast<PositionVisibility>(Access(misc_data_, access_.misc_data_)->position_visibility_);
  }


  // PrefersDefaultScrollbarStyles
  


  bool MutablePrefersDefaultScrollbarStylesInternal() {
    return static_cast<bool>(data_.prefers_default_scrollbar_styles_);
  }


  // print-color-adjust
  


  EPrintColorAdjust MutablePrintColorAdjustInternal() {
    return static_cast<EPrintColorAdjust>(data_.print_color_adjust_);
  }


  // PseudoElementStyles
  unsigned PseudoElementStylesInternal() const {
    return static_cast<unsigned>(data_.pseudo_element_styles_);
  }



  unsigned MutablePseudoElementStylesInternal() {
    return static_cast<unsigned>(data_.pseudo_element_styles_);
  }


  // quotes
  


  // r
  



  Length& MutableRInternal() {
    return Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->r_;
  }


  // reading-flow
  


  EReadingFlow MutableReadingFlowInternal() {
    return static_cast<EReadingFlow>(Access(misc_data_, access_.misc_data_)->reading_flow_);
  }


  // reading-order
  


  int MutableReadingOrderInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->reading_order_;
  }


  // RequiresAcceleratedCompositingForExternalReasons
  


  bool MutableRequiresAcceleratedCompositingForExternalReasonsInternal() {
    return static_cast<bool>(Access(misc_data_, access_.misc_data_)->requires_accelerated_compositing_for_external_reasons_);
  }


  // resize
  EResize Resize() const {
    return static_cast<EResize>(misc_data_->resize_);
  }



  EResize MutableResizeInternal() {
    return static_cast<EResize>(Access(misc_data_, access_.misc_data_)->resize_);
  }


  // right
  



  Length& MutableRightInternal() {
    return Access(surround_data_, access_.surround_data_)->right_;
  }


  // rotate
  


  // row-gap
  



  std::optional<Length>& MutableRowGapInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->row_gap_;
  }


  // row-rule-break
  


  RuleBreak MutableRowRuleBreakInternal() {
    return static_cast<RuleBreak>(Access(misc_data_, access_.misc_data_)->row_rule_break_);
  }


  // row-rule-color
  
  void SetRowRuleColorInternal(const GapDataList<StyleColor>& v) {
    if (!(misc_data_->misc_4_data_->row_rule_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->row_rule_color_ = v;
  }

  void SetRowRuleColorInternal(GapDataList<StyleColor>&& v) {
    if (!(misc_data_->misc_4_data_->row_rule_color_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->row_rule_color_ = std::move(v);
  }


  GapDataList<StyleColor>& MutableRowRuleColorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_4_data_, access_.misc_4_data_)->row_rule_color_;
  }


  // row-rule-inset-cap-end
  



  Length& MutableRowRuleInsetCapEndInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_cap_end_;
  }


  // row-rule-inset-cap-start
  



  Length& MutableRowRuleInsetCapStartInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_cap_start_;
  }


  // row-rule-inset-junction-end
  



  Length& MutableRowRuleInsetJunctionEndInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_junction_end_;
  }


  // row-rule-inset-junction-start
  



  Length& MutableRowRuleInsetJunctionStartInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_inset_junction_start_;
  }


  // row-rule-style
  
  void SetRowRuleStyleInternal(const GapDataList<EBorderStyle>& v) {
    if (!(misc_data_->misc_5_data_->row_rule_style_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_style_ = v;
  }

  void SetRowRuleStyleInternal(GapDataList<EBorderStyle>&& v) {
    if (!(misc_data_->misc_5_data_->row_rule_style_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_style_ = std::move(v);
  }


  GapDataList<EBorderStyle>& MutableRowRuleStyleInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_style_;
  }


  // row-rule-visibility-items
  


  RuleVisibilityItems MutableRowRuleVisibilityItemsInternal() {
    return static_cast<RuleVisibilityItems>(Access(misc_data_, access_.misc_data_)->row_rule_visibility_items_);
  }


  // row-rule-width
  
  void SetRowRuleWidthInternal(const GapDataList<int>& v) {
    if (!(misc_data_->misc_5_data_->row_rule_width_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_width_ = v;
  }

  void SetRowRuleWidthInternal(GapDataList<int>&& v) {
    if (!(misc_data_->misc_5_data_->row_rule_width_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_width_ = std::move(v);
  }


  GapDataList<int>& MutableRowRuleWidthInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->row_rule_width_;
  }


  // -webkit-rtl-ordering
  


  EOrder MutableRtlOrderingInternal() {
    return static_cast<EOrder>(data_.rtl_ordering_);
  }


  // -webkit-rtl-ordering
  


  bool MutableRtlOrderingIsInheritedInternal() {
    return static_cast<bool>(data_.rtl_ordering_is_inherited_);
  }


  // ruby-align
  


  ERubyAlign MutableRubyAlignInternal() {
    return static_cast<ERubyAlign>(Access(misc_inherited_data_, access_.misc_inherited_data_)->ruby_align_);
  }


  // ruby-overhang
  


  ERubyOverhang MutableRubyOverhangInternal() {
    return static_cast<ERubyOverhang>(Access(misc_inherited_data_, access_.misc_inherited_data_)->ruby_overhang_);
  }


  // ruby-position
  


  RubyPosition MutableRubyPositionInternal() {
    return static_cast<RubyPosition>(Access(misc_inherited_data_, access_.misc_inherited_data_)->ruby_position_);
  }


  // rule-overlap
  


  ERuleOverlap MutableRuleOverlapInternal() {
    return static_cast<ERuleOverlap>(Access(misc_data_, access_.misc_data_)->rule_overlap_);
  }


  // rx
  



  Length& MutableRxInternal() {
    return Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->rx_;
  }


  // ry
  



  Length& MutableRyInternal() {
    return Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->ry_;
  }


  // scale
  


  // scroll-axis-lock
  


  EScrollAxisLock MutableScrollAxisLockInternal() {
    return static_cast<EScrollAxisLock>(Access(misc_data_, access_.misc_data_)->scroll_axis_lock_);
  }


  // scroll-behavior
  


  mojom::blink::ScrollBehavior MutableScrollBehaviorInternal() {
    return static_cast<mojom::blink::ScrollBehavior>(Access(misc_data_, access_.misc_data_)->scroll_behavior_);
  }


  // scroll-initial-target
  


  EScrollInitialTarget MutableScrollInitialTargetInternal() {
    return static_cast<EScrollInitialTarget>(Access(misc_data_, access_.misc_data_)->scroll_initial_target_);
  }


  // scroll-margin-bottom
  


  float MutableScrollMarginBottomInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_margin_bottom_;
  }


  // scroll-margin-left
  


  float MutableScrollMarginLeftInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_margin_left_;
  }


  // scroll-margin-right
  


  float MutableScrollMarginRightInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_margin_right_;
  }


  // scroll-margin-top
  


  float MutableScrollMarginTopInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_margin_top_;
  }


  // scroll-marker-group
  


  // scroll-padding-bottom
  



  Length& MutableScrollPaddingBottomInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_bottom_;
  }


  // scroll-padding-left
  



  Length& MutableScrollPaddingLeftInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_left_;
  }


  // scroll-padding-right
  



  Length& MutableScrollPaddingRightInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_right_;
  }


  // scroll-padding-top
  



  Length& MutableScrollPaddingTopInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_5_data_, access_.misc_5_data_)->scroll_padding_top_;
  }


  // scroll-snap-align
  



  cc::ScrollSnapAlign& MutableScrollSnapAlignInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->scroll_snap_align_;
  }


  // scroll-snap-stop
  


  EScrollSnapStop MutableScrollSnapStopInternal() {
    return static_cast<EScrollSnapStop>(data_.scroll_snap_stop_);
  }


  // scroll-snap-type
  



  cc::ScrollSnapType& MutableScrollSnapTypeInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->scroll_snap_type_;
  }


  // scroll-target-group
  


  EScrollTargetGroup MutableScrollTargetGroupInternal() {
    return static_cast<EScrollTargetGroup>(Access(misc_data_, access_.misc_data_)->scroll_target_group_);
  }


  // scroll-timeline-axis
  



  Vector<TimelineAxis>& MutableScrollTimelineAxisInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->scroll_timeline_axis_;
  }


  // scroll-timeline-name
  



  Vector<AtomicString>& MutableScrollTimelineNameInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->scroll_timeline_name_;
  }


  // scrollbar-color
  


  // scrollbar-gutter
  


  unsigned MutableScrollbarGutterInternal() {
    return static_cast<unsigned>(Access(misc_data_, access_.misc_data_)->scrollbar_gutter_);
  }


  // scrollbar-width
  


  EScrollbarWidth MutableScrollbarWidthInternal() {
    return static_cast<EScrollbarWidth>(Access(misc_data_, access_.misc_data_)->scrollbar_width_);
  }


  // shape-image-threshold
  
  void SetShapeImageThresholdInternal(float v) {
    if (!(misc_data_->misc_6_data_->shape_image_threshold_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->shape_image_threshold_ = v;
  }


  float MutableShapeImageThresholdInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->shape_image_threshold_;
  }


  // shape-margin
  



  Length& MutableShapeMarginInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->shape_margin_;
  }


  // shape-outside
  const Member<ShapeValue>& ShapeOutsideInternal() const {
    return misc_data_->misc_6_data_->shape_outside_;
  }



  Member<ShapeValue>& MutableShapeOutsideInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->shape_outside_;
  }


  // shape-rendering
  


  EShapeRendering MutableShapeRenderingInternal() {
    return static_cast<EShapeRendering>(Access(svginherited_data_, access_.svginherited_data_)->shape_rendering_);
  }


  // ShouldIgnoreOverflowPropertyForInlineBlockBaseline
  

  // SkipsContents
  


  bool MutableSkipsContentsInternal() {
    return static_cast<bool>(data_.skips_contents_);
  }


  // speak
  


  ESpeak MutableSpeakInternal() {
    return static_cast<ESpeak>(Access(misc_inherited_data_, access_.misc_inherited_data_)->speak_);
  }


  // stop-color
  const StyleColor& StopColor() const {
    return svg_data_->stop_data_->stop_color_;
  }




  StyleColor& MutableStopColorInternal() {
    return Access(Access(svg_data_, access_.svg_data_)->stop_data_, access_.stop_data_)->stop_color_;
  }


  // stop-opacity
  


  float MutableStopOpacityInternal() {
    return Access(Access(svg_data_, access_.svg_data_)->stop_data_, access_.stop_data_)->stop_opacity_;
  }


  // stroke-dasharray
  


  // stroke-dashoffset
  



  Length& MutableStrokeDashOffsetInternal() {
    return Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_dash_offset_;
  }


  // stroke-miterlimit
  


  float MutableStrokeMiterLimitInternal() {
    return Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_miter_limit_;
  }


  // stroke-opacity
  


  float MutableStrokeOpacityInternal() {
    return Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_opacity_;
  }


  // stroke
  



  SVGPaint& MutableStrokePaintInternal() {
    return Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_paint_;
  }


  // stroke-width
  



  UnzoomedLength& MutableStrokeWidthInternal() {
    return Access(Access(svginherited_data_, access_.svginherited_data_)->stroke_data_, access_.stroke_data_)->stroke_width_;
  }


  // StyleType
  


  PseudoId MutableStyleTypeInternal() {
    return static_cast<PseudoId>(data_.style_type_);
  }


  // SubtreeIsSticky
  


  bool MutableSubtreeIsStickyInternal() {
    return static_cast<bool>(Access(misc_inherited_data_, access_.misc_inherited_data_)->subtree_is_sticky_);
  }


  // SubtreeWillChangeContents
  


  bool MutableSubtreeWillChangeContentsInternal() {
    return static_cast<bool>(Access(misc_inherited_data_, access_.misc_inherited_data_)->subtree_will_change_contents_);
  }


  // tab-size
  
  void SetTabSizeInternal(const TabSize& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->tab_size_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->tab_size_ = v;
  }

  void SetTabSizeInternal(TabSize&& v) {
    if (!(misc_inherited_data_->misc_inherited_1_data_->tab_size_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->tab_size_ = std::move(v);
  }


  TabSize& MutableTabSizeInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->tab_size_;
  }


  // table-layout
  


  ETableLayout MutableTableLayoutInternal() {
    return static_cast<ETableLayout>(data_.table_layout_);
  }


  // -webkit-tap-highlight-color
  



  StyleColor& MutableTapHighlightColorInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->tap_highlight_color_;
  }


  // text-align
  


  ETextAlign MutableTextAlignInternal() {
    return static_cast<ETextAlign>(data_.text_align_);
  }


  // text-align-last
  


  ETextAlignLast MutableTextAlignLastInternal() {
    return static_cast<ETextAlignLast>(Access(misc_inherited_data_, access_.misc_inherited_data_)->text_align_last_);
  }


  // text-anchor
  


  ETextAnchor MutableTextAnchorInternal() {
    return static_cast<ETextAnchor>(Access(svginherited_data_, access_.svginherited_data_)->text_anchor_);
  }


  // text-autospace
  


  ETextAutospace MutableTextAutospaceInternal() {
    return static_cast<ETextAutospace>(Access(misc_inherited_data_, access_.misc_inherited_data_)->text_autospace_);
  }


  // text-box-edge
  


  TextBoxEdge MutableTextBoxEdgeInternal() {
    return static_cast<TextBoxEdge>(Access(misc_inherited_data_, access_.misc_inherited_data_)->text_box_edge_);
  }


  // text-box-trim
  


  ETextBoxTrim MutableTextBoxTrimInternal() {
    return static_cast<ETextBoxTrim>(Access(box_data_, access_.box_data_)->text_box_trim_);
  }


  // text-combine-upright
  


  ETextCombine MutableTextCombineInternal() {
    return static_cast<ETextCombine>(Access(misc_inherited_data_, access_.misc_inherited_data_)->text_combine_);
  }


  // text-decoration-color
  const StyleColor& TextDecorationColor() const {
    return misc_data_->misc_6_data_->text_decoration_color_;
  }




  StyleColor& MutableTextDecorationColorInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_decoration_color_;
  }


  // text-decoration-inset
  



  TextDecorationInset& MutableTextDecorationInsetInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_decoration_inset_;
  }


  // text-decoration-line
  

  // text-decoration-skip-ink
  


  ETextDecorationSkipInk MutableTextDecorationSkipInkInternal() {
    return static_cast<ETextDecorationSkipInk>(Access(misc_inherited_data_, access_.misc_inherited_data_)->text_decoration_skip_ink_);
  }


  // text-decoration-skip-spaces
  

  // text-decoration-style
  


  ETextDecorationStyle MutableTextDecorationStyleInternal() {
    return static_cast<ETextDecorationStyle>(Access(misc_data_, access_.misc_data_)->text_decoration_style_);
  }


  // text-decoration-thickness
  



  TextDecorationThickness& MutableTextDecorationThicknessInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_decoration_thickness_;
  }


  // text-emphasis-color
  const StyleColor& TextEmphasisColor() const {
    return misc_inherited_data_->misc_inherited_1_data_->text_emphasis_color_;
  }




  StyleColor& MutableTextEmphasisColorInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->text_emphasis_color_;
  }


  // TextEmphasisCustomMark
  



  AtomicString& MutableTextEmphasisCustomMarkInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_emphasis_custom_mark_;
  }


  // TextEmphasisFill
  


  TextEmphasisFill MutableTextEmphasisFillInternal() {
    return static_cast<TextEmphasisFill>(Access(misc_inherited_data_, access_.misc_inherited_data_)->text_emphasis_fill_);
  }


  // TextEmphasisMark
  TextEmphasisMark TextEmphasisMarkInternal() const {
    return static_cast<TextEmphasisMark>(misc_inherited_data_->text_emphasis_mark_);
  }



  TextEmphasisMark MutableTextEmphasisMarkInternal() {
    return static_cast<TextEmphasisMark>(Access(misc_inherited_data_, access_.misc_inherited_data_)->text_emphasis_mark_);
  }


  // text-emphasis-position
  


  TextEmphasisPosition MutableTextEmphasisPositionInternal() {
    return static_cast<TextEmphasisPosition>(Access(misc_inherited_data_, access_.misc_inherited_data_)->text_emphasis_position_);
  }


  // -webkit-text-fill-color
  const StyleColor& TextFillColor() const {
    return misc_inherited_data_->misc_inherited_2_data_->text_fill_color_;
  }




  StyleColor& MutableTextFillColorInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_fill_color_;
  }


  // text-fit
  



  TextFit& MutableTextFitInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->text_fit_;
  }


  // text-indent
  



  Length& MutableTextIndentInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_indent_;
  }


  // TextIndentFlags
  


  TextIndentFlags MutableTextIndentFlagsInternal() {
    return static_cast<TextIndentFlags>(Access(misc_inherited_data_, access_.misc_inherited_data_)->text_indent_flags_);
  }


  // text-justify
  


  TextJustify MutableTextJustifyInternal() {
    return static_cast<TextJustify>(Access(misc_inherited_data_, access_.misc_inherited_data_)->text_justify_);
  }


  // text-orientation
  


  ETextOrientation MutableTextOrientationInternal() {
    return static_cast<ETextOrientation>(Access(misc_inherited_data_, access_.misc_inherited_data_)->text_orientation_);
  }


  // text-overflow
  



  TextOverflowData& MutableTextOverflowInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->text_overflow_;
  }


  // -webkit-text-security
  


  ETextSecurity MutableTextSecurityInternal() {
    return static_cast<ETextSecurity>(Access(misc_inherited_data_, access_.misc_inherited_data_)->text_security_);
  }


  // text-shadow
  


  // text-size-adjust
  



  TextSizeAdjust& MutableTextSizeAdjustInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_1_data_, access_.misc_inherited_1_data_)->text_size_adjust_;
  }


  // -webkit-text-stroke-color
  const StyleColor& TextStrokeColor() const {
    return misc_inherited_data_->misc_inherited_2_data_->text_stroke_color_;
  }




  StyleColor& MutableTextStrokeColorInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_stroke_color_;
  }


  // -webkit-text-stroke-width
  


  float MutableTextStrokeWidthInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_stroke_width_;
  }


  // text-transform
  

  // text-transform
  


  bool MutableTextTransformIsInheritedInternal() {
    return static_cast<bool>(data_.text_transform_is_inherited_);
  }


  // text-underline-offset
  



  Length& MutableTextUnderlineOffsetInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->text_underline_offset_;
  }


  // text-underline-position
  


  TextUnderlinePosition MutableTextUnderlinePositionInternal() {
    return static_cast<TextUnderlinePosition>(Access(misc_inherited_data_, access_.misc_inherited_data_)->text_underline_position_);
  }


  // text-wrap-mode
  


  TextWrapMode MutableTextWrapModeInternal() {
    return static_cast<TextWrapMode>(data_.text_wrap_mode_);
  }


  // text-wrap-style
  


  TextWrapStyle MutableTextWrapStyleInternal() {
    return static_cast<TextWrapStyle>(data_.text_wrap_style_);
  }


  // timeline-scope
  



  StyleTimelineScope& MutableTimelineScopeInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->timeline_scope_;
  }


  // top
  



  Length& MutableTopInternal() {
    return Access(surround_data_, access_.surround_data_)->top_;
  }


  // touch-action
  


  TouchAction MutableTouchActionInternal() {
    return static_cast<TouchAction>(Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->touch_action_);
  }


  // transform
  



  TransformOperations& MutableTransformInternal() {
    return Access(svg_data_, access_.svg_data_)->transform_;
  }


  // transform-box
  


  ETransformBox MutableTransformBoxInternal() {
    return static_cast<ETransformBox>(data_.transform_box_);
  }


  // transform-origin
  



  TransformOrigin& MutableTransformOriginInternal() {
    return Access(svg_data_, access_.svg_data_)->transform_origin_;
  }


  // transform-style
  


  ETransformStyle3D MutableTransformStyle3DInternal() {
    return static_cast<ETransformStyle3D>(Access(misc_data_, access_.misc_data_)->transform_style_3d_);
  }


  // Transitions
  
  void SetTransitionsInternal(Member<CSSTransitionData>&& v) {
    if (!(misc_data_->misc_7_data_->transitions_ == v))
      Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->transitions_ = std::move(v);
  }


  Member<CSSTransitionData>& MutableTransitionsInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->transitions_;
  }


  // translate
  


  // trigger-scope
  



  StyleTriggerScope& MutableTriggerScopeInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->trigger_scope_;
  }


  // UAShadowHostData
  


  // UnconditionalScrollbarSize
  



  gfx::Size& MutableUnconditionalScrollbarSizeInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->unconditional_scrollbar_size_;
  }


  // unicode-bidi
  


  UnicodeBidi MutableUnicodeBidiInternal() {
    return static_cast<UnicodeBidi>(data_.unicode_bidi_);
  }


  // -webkit-user-drag
  


  EUserDrag MutableUserDragInternal() {
    return static_cast<EUserDrag>(Access(misc_data_, access_.misc_data_)->user_drag_);
  }


  // -webkit-user-modify
  EUserModify UserModify() const {
    return static_cast<EUserModify>(misc_inherited_data_->user_modify_);
  }



  EUserModify MutableUserModifyInternal() {
    return static_cast<EUserModify>(Access(misc_inherited_data_, access_.misc_inherited_data_)->user_modify_);
  }


  // user-select
  EUserSelect UserSelect() const {
    return static_cast<EUserSelect>(misc_inherited_data_->user_select_);
  }



  EUserSelect MutableUserSelectInternal() {
    return static_cast<EUserSelect>(Access(misc_inherited_data_, access_.misc_inherited_data_)->user_select_);
  }


  // vector-effect
  


  EVectorEffect MutableVectorEffectInternal() {
    return static_cast<EVectorEffect>(Access(svg_data_, access_.svg_data_)->vector_effect_);
  }


  // VerticalAlign
  unsigned VerticalAlignInternal() const {
    return static_cast<unsigned>(data_.vertical_align_);
  }

  void SetVerticalAlignInternal(unsigned v) {
    data_.vertical_align_ = static_cast<unsigned>(v);
  }


  unsigned MutableVerticalAlignInternal() {
    return static_cast<unsigned>(data_.vertical_align_);
  }


  // VerticalAlignLength
  
  void SetVerticalAlignLengthInternal(const Length& v) {
    if (!(box_data_->vertical_align_length_ == v))
      Access(box_data_, access_.box_data_)->vertical_align_length_ = v;
  }

  void SetVerticalAlignLengthInternal(Length&& v) {
    if (!(box_data_->vertical_align_length_ == v))
      Access(box_data_, access_.box_data_)->vertical_align_length_ = std::move(v);
  }


  Length& MutableVerticalAlignLengthInternal() {
    return Access(box_data_, access_.box_data_)->vertical_align_length_;
  }


  // -webkit-border-vertical-spacing
  


  short MutableVerticalBorderSpacingInternal() {
    return Access(inherited_data_, access_.inherited_data_)->vertical_border_spacing_;
  }


  // view-timeline-axis
  



  Vector<TimelineAxis>& MutableViewTimelineAxisInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->view_timeline_axis_;
  }


  // view-timeline-inset
  



  Vector<TimelineInset>& MutableViewTimelineInsetInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->view_timeline_inset_;
  }


  // view-timeline-name
  



  Vector<AtomicString>& MutableViewTimelineNameInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->timeline_data_, access_.timeline_data_)->view_timeline_name_;
  }


  // view-transition-class
  


  Member<ScopedCSSNameList>& MutableViewTransitionClassInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->view_transition_class_;
  }


  // view-transition-group
  



  StyleViewTransitionGroup& MutableViewTransitionGroupInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->view_transition_group_;
  }


  // view-transition-name
  


  Member<StyleViewTransitionName>& MutableViewTransitionNameInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_6_data_, access_.misc_6_data_)->view_transition_name_;
  }


  // view-transition-scope
  


  EViewTransitionScope MutableViewTransitionScopeInternal() {
    return static_cast<EViewTransitionScope>(Access(misc_data_, access_.misc_data_)->view_transition_scope_);
  }


  // ViewportUnitFlags
  


  unsigned MutableViewportUnitFlagsInternal() {
    return static_cast<unsigned>(data_.viewport_unit_flags_);
  }


  // visibility
  


  EVisibility MutableVisibilityInternal() {
    return static_cast<EVisibility>(data_.visibility_);
  }


  // visibility
  


  bool MutableVisibilityIsInheritedInternal() {
    return static_cast<bool>(data_.visibility_is_inherited_);
  }


  // -webkit-line-clamp
  


  int MutableWebkitLineClampInternal() {
    return Access(Access(misc_data_, access_.misc_data_)->misc_7_data_, access_.misc_7_data_)->webkit_line_clamp_;
  }


  // white-space-collapse
  


  WhiteSpaceCollapse MutableWhiteSpaceCollapseInternal() {
    return static_cast<WhiteSpaceCollapse>(data_.white_space_collapse_);
  }


  // widows
  
  void SetWidowsInternal(short v) {
    if (!(misc_inherited_data_->misc_inherited_2_data_->widows_ == v))
      Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->widows_ = v;
  }


  short MutableWidowsInternal() {
    return Access(Access(misc_inherited_data_, access_.misc_inherited_data_)->misc_inherited_2_data_, access_.misc_inherited_2_data_)->widows_;
  }


  // width
  



  Length& MutableWidthInternal() {
    return Access(box_data_, access_.box_data_)->width_;
  }


  // will-change
  


  // word-break
  


  EWordBreak MutableWordBreakInternal() {
    return static_cast<EWordBreak>(Access(misc_inherited_data_, access_.misc_inherited_data_)->word_break_);
  }


  // word-spacing
  const Length& WordSpacingInternal() const {
    return inherited_data_->word_spacing_;
  }




  Length& MutableWordSpacingInternal() {
    return Access(inherited_data_, access_.inherited_data_)->word_spacing_;
  }


  // writing-mode
  


  WritingMode MutableWritingModeInternal() {
    return static_cast<WritingMode>(data_.writing_mode_);
  }


  // x
  



  Length& MutableXInternal() {
    return Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->x_;
  }


  // y
  



  Length& MutableYInternal() {
    return Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->y_;
  }


  // z-index
  
  void SetZIndexInternal(int v) {
    if (!(box_data_->z_index_ == v))
      Access(box_data_, access_.box_data_)->z_index_ = v;
  }


  int MutableZIndexInternal() {
    return Access(box_data_, access_.box_data_)->z_index_;
  }


  // zoom
  


  float MutableZoomInternal() {
    return Access(visual_data_, access_.visual_data_)->zoom_;
  }



  void ResetAccess() const {
    memset(&access_, 0, sizeof(access_));
  }

 private:
  friend class ComputedStyleBase;

  // Access flags. These are passed to Access to ensure that we have
  // a private copy of the relevant group before mutation.
  mutable struct {
    bool background_data_ = false;
    bool box_data_ = false;
    bool fill_data_ = false;
    bool forced_colors_data_ = false;
    bool geometry_data_ = false;
    bool highlight_data_data_ = false;
    bool inherited_data_ = false;
    bool inherited_forced_colors_data_ = false;
    bool inherited_visited_data_ = false;
    bool math_data_ = false;
    bool misc_data_ = false;
    bool misc_inherited_data_ = false;
    bool misc_inherited_1_data_ = false;
    bool misc_inherited_2_data_ = false;
    bool misc_1_data_ = false;
    bool misc_2_data_ = false;
    bool misc_3_data_ = false;
    bool misc_4_data_ = false;
    bool misc_5_data_ = false;
    bool misc_6_data_ = false;
    bool misc_7_data_ = false;
    bool misc_8_data_ = false;
    bool resources_data_ = false;
    bool stop_data_ = false;
    bool stroke_data_ = false;
    bool surround_data_ = false;
    bool svg_data_ = false;
    bool svginherited_data_ = false;
    bool svgmisc_data_ = false;
    bool timeline_data_ = false;
    bool visited_data_ = false;
    bool visual_data_ = false;
  } access_;

  template <typename T>
  static T* Access(T*& data, bool& access_flag) {
    if (!access_flag) {
      access_flag = true;
      data = data->Copy();
    }
    return data;
  }

  template <typename T>
  static T* Access(Member<T>& data, bool& access_flag) {
    if (!access_flag) {
      access_flag = true;
      data = data->Copy();
    }
    return data.Get();
  }

  using StyleMiscInheritedData = ComputedStyleBase::StyleMiscInheritedData;
  using StyleMiscData = ComputedStyleBase::StyleMiscData;
  using StyleInheritedData = ComputedStyleBase::StyleInheritedData;
  using StyleVisualData = ComputedStyleBase::StyleVisualData;
  using StyleSvginheritedData = ComputedStyleBase::StyleSvginheritedData;
  using StyleBoxData = ComputedStyleBase::StyleBoxData;
  using StyleSVGData = ComputedStyleBase::StyleSVGData;
  using StyleSurroundData = ComputedStyleBase::StyleSurroundData;
  using StyleBackgroundData = ComputedStyleBase::StyleBackgroundData;

  // Storage.
  StyleMiscInheritedData* misc_inherited_data_;
  StyleMiscData* misc_data_;
  StyleInheritedData* inherited_data_;
  StyleVisualData* visual_data_;
  StyleSvginheritedData* svginherited_data_;
  StyleBoxData* box_data_;
  StyleSVGData* svg_data_;
  StyleSurroundData* surround_data_;
  StyleBackgroundData* background_data_;

  StyleBaseData* base_data_;

  ComputedStyleBase::Data data_;
};

}  // namespace blink

namespace blink {
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleBackgroundData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleBoxData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleFillData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleForcedColorsData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleGeometryData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleHighlightDataData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleInheritedData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleInheritedForcedColorsData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleInheritedVisitedData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMathData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMiscData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMiscInheritedData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMiscInherited1Data, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMiscInherited2Data, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMisc1Data, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMisc2Data, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMisc3Data, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMisc4Data, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMisc5Data, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMisc6Data, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMisc7Data, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMisc8Data, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleResourcesData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleStopData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleStrokeData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleSurroundData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleSVGData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleSvginheritedData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleSvgmiscData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleTimelineData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleVisitedData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleVisualData, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<
    T,
    std::enable_if_t<std::is_base_of<blink::ComputedStyleBase, T>::value>> {
  static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_BASE_H_
