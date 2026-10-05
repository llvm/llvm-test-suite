// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_qualified_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/aria_properties.json5
//   ../../third_party/blink/renderer/core/html/html_attribute_names.json5
//   ../../third_party/blink/renderer/core/html/html_tag_names.json5


#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_HTML_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_HTML_NAMES_H_

#include "base/containers/heap_array.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/dom/qualified_name.h"

namespace blink {

class HTMLQualifiedName : public QualifiedNameWithHash { };

namespace html_names {

// Namespace
CORE_EXPORT extern const AtomicString& xhtmlNamespaceURI;

// Tags

enum class HTMLTag {
  // Explicitly give unknown a value of 0 as comparison to unknown happens a
  // lot, and comparing to 0 saves an instruction on some hardware.
  kUnknown = 0,
  kA,
  kAbbr,
  kAcronym,
  kAddress,
  kApplet,
  kArea,
  kArticle,
  kAside,
  kAudio,
  kB,
  kBase,
  kBasefont,
  kBdi,
  kBdo,
  kBgsound,
  kBig,
  kBlockquote,
  kBody,
  kBr,
  kButton,
  kCamera,
  kCanvas,
  kCaption,
  kCenter,
  kCite,
  kCode,
  kCol,
  kColgroup,
  kCommand,
  kCredential,
  kData,
  kDatalist,
  kDd,
  kDel,
  kDetails,
  kDfn,
  kDialog,
  kDir,
  kDiv,
  kDl,
  kDt,
  kEm,
  kEmbed,
  kFencedframeOrUnknown,
  kFieldset,
  kFigcaption,
  kFigure,
  kFont,
  kFooter,
  kForm,
  kFrame,
  kFrameset,
  kGeolocation,
  kH1,
  kH2,
  kH3,
  kH4,
  kH5,
  kH6,
  kHead,
  kHeader,
  kHgroup,
  kHr,
  kHTML,
  kI,
  kIFrame,
  kImage,
  kImg,
  kInput,
  kIns,
  kInstallOrUnknown,
  kKbd,
  kKeygen,
  kLabel,
  kLayer,
  kLegend,
  kLi,
  kLink,
  kListing,
  kLogin,
  kMain,
  kMap,
  kMark,
  kMarquee,
  kMenu,
  kMenubar,
  kMenuitem,
  kMenulist,
  kMeta,
  kMeter,
  kMicrophone,
  kNav,
  kNobr,
  kNoembed,
  kNoframes,
  kNolayer,
  kNoscript,
  kObject,
  kOl,
  kOptgroup,
  kOption,
  kOutput,
  kP,
  kParam,
  kPicture,
  kPlaintext,
  kPre,
  kProgress,
  kQ,
  kRb,
  kRp,
  kRt,
  kRTC,
  kRuby,
  kS,
  kSamp,
  kScript,
  kSearch,
  kSection,
  kSelect,
  kSelectedcontent,
  kSlot,
  kSmall,
  kSource,
  kSpan,
  kStrike,
  kStrong,
  kStyle,
  kSub,
  kSubmenu,
  kSummary,
  kSup,
  kTable,
  kTbody,
  kTd,
  kTemplate,
  kTextarea,
  kTfoot,
  kTh,
  kThead,
  kTime,
  kTitle,
  kTr,
  kTrack,
  kTt,
  kU,
  kUl,
  kUsermediaOrUnknown,
  kVar,
  kVideo,
  kWbr,
  kXmp,
};

CORE_EXPORT extern const blink::HTMLQualifiedName& kATag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kAbbrTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kAcronymTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kAddressTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kAppletTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kAreaTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kArticleTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kAsideTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kAudioTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBaseTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBasefontTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBdiTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBdoTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBgsoundTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBigTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBlockquoteTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBodyTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBrTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kButtonTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kCameraTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kCanvasTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kCaptionTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kCenterTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kCiteTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kCodeTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kColTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kColgroupTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kCommandTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kCredentialTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDataTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDatalistTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDdTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDelTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDetailsTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDfnTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDialogTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDirTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDivTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDlTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDtTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kEmTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kEmbedTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFencedframeTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFieldsetTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFigcaptionTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFigureTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFontTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFooterTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFormTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFrameTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFramesetTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kGeolocationTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kH1Tag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kH2Tag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kH3Tag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kH4Tag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kH5Tag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kH6Tag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kHeadTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kHeaderTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kHgroupTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kHrTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kHTMLTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kITag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kIFrameTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kImageTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kImgTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kInputTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kInsTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kInstallTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kKbdTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kKeygenTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kLabelTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kLayerTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kLegendTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kLiTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kLinkTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kListingTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kLoginTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMainTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMapTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMarkTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMarqueeTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMenuTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMenubarTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMenuitemTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMenulistTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMetaTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMeterTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMicrophoneTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kNavTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kNobrTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kNoembedTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kNoframesTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kNolayerTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kNoscriptTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kObjectTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kOlTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kOptgroupTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kOptionTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kOutputTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kPTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kParamTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kPictureTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kPlaintextTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kPreTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kProgressTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kQTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kRbTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kRpTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kRtTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kRTCTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kRubyTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSampTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kScriptTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSearchTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSectionTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSelectTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSelectedcontentTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSlotTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSmallTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSourceTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSpanTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kStrikeTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kStrongTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kStyleTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSubTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSubmenuTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSummaryTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSupTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTableTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTbodyTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTdTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTemplateTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTextareaTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTfootTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kThTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTheadTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTimeTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTitleTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTrTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTrackTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTtTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kUTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kUlTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kUsermediaTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kVarTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kVideoTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kWbrTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kXmpTag;

// Attributes
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAbbrAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAcceptAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAcceptCharsetAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAccesskeyAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAccuracymodeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kActionAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAdauctionheadersAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAlignAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAlinkAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAllowAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAllowfullscreenAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAllowpaymentrequestAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAlphaAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAltAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kArchiveAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaActionsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaActivedescendantAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaAtomicAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaAutocompleteAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaBraillelabelAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaBrailleroledescriptionAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaBusyAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaCheckedAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaColcountAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaColindexAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaColindextextAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaColspanAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaControlsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaCurrentAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaDescribedbyAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaDescriptionAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaDetailsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaDisabledAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaErrormessageAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaExpandedAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaFlowtoAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaHaspopupAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaHiddenAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaInvalidAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaKeyshortcutsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaLabelAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaLabeledbyAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaLabelledbyAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaLevelAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaLiveAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaModalAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaMultilineAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaMultiselectableAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaOrientationAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaOwnsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaPlaceholderAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaPosinsetAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaPressedAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaReadonlyAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaRelevantAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaRequiredAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaRoledescriptionAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaRowcountAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaRowindexAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaRowindextextAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaRowspanAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaSelectedAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaSetsizeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaSortAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaValuemaxAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaValueminAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaValuenowAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAriaValuetextAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAsyncAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAttributionsrcAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAutocapitalizeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAutocompleteAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAutocorrectAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAutofocusAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAutolocateAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAutoplayAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kAxisAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kBackgroundAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kBehaviorAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kBgcolorAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kBlockingAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kBorderAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kBordercolorAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kBrowsingtopicsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kBufferAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCachehintAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCaptureAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCellpaddingAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCellspacingAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kChallengeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCharAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCharoffAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCharsetAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCheckableAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCheckedAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCiteAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kClassAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kClassidAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kClearAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kClientidAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kClosedbyAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCodeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCodebaseAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCodetypeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kColorAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kColorspaceAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kColsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kColspanAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCommandAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCommandforAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCompactAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kConfigurlAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kConnectionallowlistAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kContainertimingAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kContainertimingIgnoreAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kContainertimingignoreAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kContentAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kContenteditableAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kControlsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kControlslistAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCoordsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCredentiallessAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCrossoriginAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCspAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kCustomelementregistryAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDataAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDataSrcAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDatetimeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDeclareAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDecodingAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDefaultAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDefaultcheckedAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDeferAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDelegatesfocusAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDirAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDirectionAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDirnameAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDisabledAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDisablepictureinpictureAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDisableremoteplaybackAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDomainhintAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDownloadAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDraggableAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kDrawableAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kElementtimingAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kEnctypeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kEndAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kEnterkeyhintAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kEventAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kExportpartsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kFaceAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kFetchpriorityAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kFieldsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kFilterAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kFocusgroupAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kFocusgroupstartAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kForAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kFormAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kFormactionAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kFormenctypeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kFormmethodAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kFormnovalidateAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kFormtargetAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kFrameAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kFrameborderAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kHeadersAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kHeadingoffsetAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kHeadingresetAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kHeightAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kHiddenAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kHighAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kHrefAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kHreflangAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kHreftranslateAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kHspaceAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kHttpEquivAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kIdAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kImagesizesAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kImagesrcsetAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kIncrementalAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kInertAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kInputmodeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kInstallurlAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kIntegrityAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kInterestforAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kInvisibleAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kIsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kIsmapAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kItempropAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kKeytypeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kKindAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kLabelAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kLangAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kLanguageAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kLatencyhintAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kLayoutsubtreeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kLeftmarginAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kLinkAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kListAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kLoadingAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kLoginhintAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kLongdescAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kLoopAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kLowAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kLowsrcAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kManifestAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kManifestidAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kMarginheightAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kMarginwidthAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kMarkerAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kMaxAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kMaxlengthAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kMayscriptAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kMediaAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kMethodAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kMinAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kMinlengthAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kMultipleAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kMutedAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kNameAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kNohrefAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kNomoduleAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kNonceAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kNoresizeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kNoshadeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kNovalidateAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kNowrapAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kObjectAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnabortAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnafterprintAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnanimationcancelAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnanimationendAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnanimationiterationAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnanimationstartAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnautofillAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnauxclickAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnbeforecopyAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnbeforecutAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnbeforefilterAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnbeforeinputAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnbeforepasteAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnbeforeprintAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnbeforetoggleAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnbeforeunloadAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnblurAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOncancelAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOncanplayAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOncanplaythroughAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnchangeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnclickAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOncloseAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOncommandAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOncontentvisibilityautostatechangeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOncontextlostAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOncontextmenuAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOncontextrestoredAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOncopyAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOncuechangeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOncutAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOndblclickAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOndragAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOndragendAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOndragenterAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOndragleaveAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOndragoverAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOndragstartAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOndropAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOndurationchangeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnemptiedAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnendedAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnerrorAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnfocusAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnfocusinAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnfocusoutAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnformdataAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOngotpointercaptureAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnhashchangeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOninputAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOninstallresultAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOninvalidAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnkeydownAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnkeypressAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnkeyupAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnlanguagechangeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnloadAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnloadeddataAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnloadedmetadataAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnloadstartAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnlocationAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnlostpointercaptureAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnmessageAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnmessageerrorAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnmousedownAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnmouseenterAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnmouseleaveAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnmousemoveAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnmouseoutAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnmouseoverAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnmouseupAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnmousewheelAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnmoveAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnofflineAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnonlineAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnorientationchangeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpagehideAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpageshowAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpasteAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpauseAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnplayAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnplayingAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpointercancelAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpointerdownAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpointerenterAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpointerleaveAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpointermoveAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpointeroutAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpointeroverAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpointerrawupdateAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpointerupAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpopstateAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnprogressAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpromptactionAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnpromptdismissAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnratechangeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnresetAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnresizeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnscrollAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnscrollendAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnscrollsnapchangeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnscrollsnapchangingAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnsearchAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnsecuritypolicyviolationAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnseekedAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnseekingAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnselectAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnselectionchangeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnselectstartAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnshowAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnslotchangeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnstalledAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnstorageAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnstreamAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnsubmitAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnsuspendAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOntimeupdateAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOntimezonechangeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOntoggleAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOntouchcancelAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOntouchendAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOntouchmoveAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOntouchstartAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOntransitionendAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnunloadAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnvalidationstatuschangeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnvolumechangeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnwaitingAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnwebkitanimationendAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnwebkitanimationiterationAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnwebkitanimationstartAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnwebkitfullscreenchangeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnwebkitfullscreenerrorAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnwebkittransitionendAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOnwheelAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOpenAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOptimumAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOverscrollareaAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kOverscrollcontainerAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kParamsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kParsepartsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPartAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPatternAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPingAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPlaceholderAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPlaysinlineAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPolicyAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPopoverAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPopovertargetAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPopovertargetactionAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPosterAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPreciseAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPreciselocationAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPreloadAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPrivatetokenAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPropertyAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kPseudoAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kReadonlyAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kReferrerpolicyAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kRelAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kRequiredAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kRevAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kReversedAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kRoleAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kRowsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kRowspanAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kRulesAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSandboxAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSanitizeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSchemeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kScopeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kScrollamountAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kScrolldelayAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kScrollingAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSelectAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSelectedAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSelectedcontentelementAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kShadowrootAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kShadowrootadoptedstylesheetsAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kShadowrootclonableAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kShadowrootcustomelementregistryAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kShadowrootdelegatesfocusAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kShadowrootmodeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kShadowrootreferencetargetAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kShadowrootserializableAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kShadowrootslotassignmentAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kShapeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSignatureAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSizeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSizesAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSlotAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSpanAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSpecifierAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSpellcheckAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSrcAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSrcdocAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSrclangAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSrcsetAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kStandbyAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kStartAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kStepAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kStyleAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSummaryAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kSwitchAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kTabindexAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kTargetAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kTextAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kTitleAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kToolautosubmitAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kTooldescriptionAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kToolnameAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kToolparamdescriptionAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kTooltitleAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kTopmarginAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kTranslateAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kTruespeedAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kTypeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kUnboundedAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kUsemapAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kValignAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kValueAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kValuetypeAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kVersionAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kVirtualkeyboardpolicyAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kVlinkAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kVspaceAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kWatchAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kWebkitdirectoryAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kWidthAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kWrapAttr;
CORE_EXPORT extern const blink::QualifiedNameWithHash& kWritingsuggestionsAttr;

constexpr unsigned kTagsCount = 152;
CORE_EXPORT base::HeapArray<const QualifiedName*> GetTags();

constexpr unsigned kAttrsCount = 460;
CORE_EXPORT base::HeapArray<const QualifiedName*> GetAttrs();

CORE_EXPORT  extern const blink::HTMLQualifiedName& TagToQualifiedName(HTMLTag tag);

void Init();

}  // namespace html_names
}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_HTML_NAMES_H_
