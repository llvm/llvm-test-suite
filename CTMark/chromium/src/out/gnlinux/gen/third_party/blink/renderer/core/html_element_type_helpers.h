// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_type_helpers.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/html_tag_names.json5


#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_HTML_ELEMENT_TYPE_HELPERS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_HTML_ELEMENT_TYPE_HELPERS_H_

#include "third_party/blink/renderer/core/html/html_element.h"
#include "third_party/blink/renderer/core/html_names.h"
#include "third_party/blink/renderer/core/element_type_enum.h"

namespace blink {

class Document;

// Type checking.
class HTMLAnchorElement;
template <>
struct DowncastTraits<HTMLAnchorElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLAnchorElement;
  }
};

class HTMLAreaElement;
template <>
struct DowncastTraits<HTMLAreaElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLAreaElement;
  }
};

class HTMLAudioElement;
template <>
struct DowncastTraits<HTMLAudioElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLAudioElement;
  }
};

class HTMLBaseElement;
template <>
struct DowncastTraits<HTMLBaseElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLBaseElement;
  }
};

class HTMLBDIElement;
template <>
struct DowncastTraits<HTMLBDIElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLBDIElement;
  }
};

class HTMLBodyElement;
template <>
struct DowncastTraits<HTMLBodyElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLBodyElement;
  }
};

class HTMLBRElement;
template <>
struct DowncastTraits<HTMLBRElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLBRElement;
  }
};

class HTMLButtonElement;
template <>
struct DowncastTraits<HTMLButtonElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLButtonElement;
  }
};

class HTMLCanvasElement;
template <>
struct DowncastTraits<HTMLCanvasElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLCanvasElement;
  }
};

class HTMLTableCaptionElement;
template <>
struct DowncastTraits<HTMLTableCaptionElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLTableCaptionElement;
  }
};

class HTMLCredentialElement;
template <>
struct DowncastTraits<HTMLCredentialElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLCredentialElement;
  }
};

class HTMLDataElement;
template <>
struct DowncastTraits<HTMLDataElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLDataElement;
  }
};

class HTMLDataListElement;
template <>
struct DowncastTraits<HTMLDataListElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLDataListElement;
  }
};

class HTMLDetailsElement;
template <>
struct DowncastTraits<HTMLDetailsElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLDetailsElement;
  }
};

class HTMLDialogElement;
template <>
struct DowncastTraits<HTMLDialogElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLDialogElement;
  }
};

class HTMLDirectoryElement;
template <>
struct DowncastTraits<HTMLDirectoryElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLDirectoryElement;
  }
};

class HTMLDivElement;
template <>
struct DowncastTraits<HTMLDivElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLDivElement;
  }
};

class HTMLDListElement;
template <>
struct DowncastTraits<HTMLDListElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLDListElement;
  }
};

class HTMLEmbedElement;
template <>
struct DowncastTraits<HTMLEmbedElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLEmbedElement;
  }
};

class HTMLFieldSetElement;
template <>
struct DowncastTraits<HTMLFieldSetElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLFieldSetElement;
  }
};

class HTMLFontElement;
template <>
struct DowncastTraits<HTMLFontElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLFontElement;
  }
};

class HTMLFormElement;
template <>
struct DowncastTraits<HTMLFormElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLFormElement;
  }
};

class HTMLFrameElement;
template <>
struct DowncastTraits<HTMLFrameElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLFrameElement;
  }
};

class HTMLFrameSetElement;
template <>
struct DowncastTraits<HTMLFrameSetElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLFrameSetElement;
  }
};

class HTMLGeolocationElement;
template <>
struct DowncastTraits<HTMLGeolocationElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLGeolocationElement;
  }
};

class HTMLHeadElement;
template <>
struct DowncastTraits<HTMLHeadElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLHeadElement;
  }
};

class HTMLHRElement;
template <>
struct DowncastTraits<HTMLHRElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLHRElement;
  }
};

class HTMLHtmlElement;
template <>
struct DowncastTraits<HTMLHtmlElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLHtmlElement;
  }
};

class HTMLIFrameElement;
template <>
struct DowncastTraits<HTMLIFrameElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLIFrameElement;
  }
};

class HTMLImageElement;
template <>
struct DowncastTraits<HTMLImageElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLImageElement;
  }
};

class HTMLInputElement;
template <>
struct DowncastTraits<HTMLInputElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLInputElement;
  }
};

class HTMLLabelElement;
template <>
struct DowncastTraits<HTMLLabelElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLLabelElement;
  }
};

class HTMLLegendElement;
template <>
struct DowncastTraits<HTMLLegendElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLLegendElement;
  }
};

class HTMLLIElement;
template <>
struct DowncastTraits<HTMLLIElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLLIElement;
  }
};

class HTMLLinkElement;
template <>
struct DowncastTraits<HTMLLinkElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLLinkElement;
  }
};

class HTMLLoginElement;
template <>
struct DowncastTraits<HTMLLoginElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLLoginElement;
  }
};

class HTMLMapElement;
template <>
struct DowncastTraits<HTMLMapElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLMapElement;
  }
};

class HTMLMarqueeElement;
template <>
struct DowncastTraits<HTMLMarqueeElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLMarqueeElement;
  }
};

class HTMLMenuElement;
template <>
struct DowncastTraits<HTMLMenuElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLMenuElement;
  }
};

class HTMLMenuBarElement;
template <>
struct DowncastTraits<HTMLMenuBarElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLMenuBarElement;
  }
};

class HTMLMenuItemElement;
template <>
struct DowncastTraits<HTMLMenuItemElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLMenuItemElement;
  }
};

class HTMLMenuListElement;
template <>
struct DowncastTraits<HTMLMenuListElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLMenuListElement;
  }
};

class HTMLMetaElement;
template <>
struct DowncastTraits<HTMLMetaElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLMetaElement;
  }
};

class HTMLMeterElement;
template <>
struct DowncastTraits<HTMLMeterElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLMeterElement;
  }
};

class HTMLNoEmbedElement;
template <>
struct DowncastTraits<HTMLNoEmbedElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLNoEmbedElement;
  }
};

class HTMLNoScriptElement;
template <>
struct DowncastTraits<HTMLNoScriptElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLNoScriptElement;
  }
};

class HTMLOListElement;
template <>
struct DowncastTraits<HTMLOListElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLOListElement;
  }
};

class HTMLOptGroupElement;
template <>
struct DowncastTraits<HTMLOptGroupElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLOptGroupElement;
  }
};

class HTMLOptionElement;
template <>
struct DowncastTraits<HTMLOptionElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLOptionElement;
  }
};

class HTMLOutputElement;
template <>
struct DowncastTraits<HTMLOutputElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLOutputElement;
  }
};

class HTMLParagraphElement;
template <>
struct DowncastTraits<HTMLParagraphElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLParagraphElement;
  }
};

class HTMLParamElement;
template <>
struct DowncastTraits<HTMLParamElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLParamElement;
  }
};

class HTMLPictureElement;
template <>
struct DowncastTraits<HTMLPictureElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLPictureElement;
  }
};

class HTMLProgressElement;
template <>
struct DowncastTraits<HTMLProgressElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLProgressElement;
  }
};

class HTMLScriptElement;
template <>
struct DowncastTraits<HTMLScriptElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLScriptElement;
  }
};

class HTMLSearchElement;
template <>
struct DowncastTraits<HTMLSearchElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLSearchElement;
  }
};

class HTMLSelectElement;
template <>
struct DowncastTraits<HTMLSelectElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLSelectElement;
  }
};

class HTMLSelectedContentElement;
template <>
struct DowncastTraits<HTMLSelectedContentElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLSelectedContentElement;
  }
};

class HTMLSlotElement;
template <>
struct DowncastTraits<HTMLSlotElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLSlotElement;
  }
};

class HTMLSourceElement;
template <>
struct DowncastTraits<HTMLSourceElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLSourceElement;
  }
};

class HTMLSpanElement;
template <>
struct DowncastTraits<HTMLSpanElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLSpanElement;
  }
};

class HTMLStyleElement;
template <>
struct DowncastTraits<HTMLStyleElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLStyleElement;
  }
};

class HTMLSubMenuElement;
template <>
struct DowncastTraits<HTMLSubMenuElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLSubMenuElement;
  }
};

class HTMLSummaryElement;
template <>
struct DowncastTraits<HTMLSummaryElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLSummaryElement;
  }
};

class HTMLTableElement;
template <>
struct DowncastTraits<HTMLTableElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLTableElement;
  }
};

class HTMLTemplateElement;
template <>
struct DowncastTraits<HTMLTemplateElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLTemplateElement;
  }
};

class HTMLTextAreaElement;
template <>
struct DowncastTraits<HTMLTextAreaElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLTextAreaElement;
  }
};

class HTMLTimeElement;
template <>
struct DowncastTraits<HTMLTimeElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLTimeElement;
  }
};

class HTMLTitleElement;
template <>
struct DowncastTraits<HTMLTitleElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLTitleElement;
  }
};

class HTMLTableRowElement;
template <>
struct DowncastTraits<HTMLTableRowElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLTableRowElement;
  }
};

class HTMLTrackElement;
template <>
struct DowncastTraits<HTMLTrackElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLTrackElement;
  }
};

class HTMLUListElement;
template <>
struct DowncastTraits<HTMLUListElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLUListElement;
  }
};

class HTMLVideoElement;
template <>
struct DowncastTraits<HTMLVideoElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLVideoElement;
  }
};

class HTMLWBRElement;
template <>
struct DowncastTraits<HTMLWBRElement> {
  static bool AllowFrom(const Node& node) {
    return node.GetElementType() == ElementType::kHTMLWBRElement;
  }
};



// Tag checking.
// |tag_name| is the local name for an HTML element in lowercase.
// The corresponding HTMLElement type for the tag name will be returned.
// Do NOT use this function with SVG tag names and SVGElements.
// If |tag_name| is an undefined HTML tag name HTMLUnknownElement is returned.
//
// Note that this will return the ElementType corresponding to the
// JavaScript interface, not the C++ class. For instance, <bdi> is implemented
// in blink::HTMLBDIElement, yet we will return ElementType::kHTMLElement
// for it here, since there is no specialized JS interface for it in the standard.
// This is unlike Node::GetElementType().
ElementType HtmlElementTypeForTag(const AtomicString& tag_name, const Document*);

bool IsKnownBuiltinTagName(const AtomicString& tag_name);

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_HTML_ELEMENT_TYPE_HELPERS_H_
