// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/runtime_enabled_features.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5


#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_H_
#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_H_

#include <cstdint>
#include <optional>
#include <string_view>

#include "base/gtest_prod_util.h"
#include "base/memory/protected_memory.h"
#include "third_party/blink/renderer/platform/platform_export.h"
#include "third_party/blink/renderer/platform/wtf/allocator/allocator.h"

#define ASSERT_ORIGIN_TRIAL(feature) \
  static_assert(std::is_same<decltype(::blink::RuntimeEnabledFeatures::     \
                                          feature##EnabledByRuntimeFlag()), \
                             bool>(),                                       \
                #feature " must be part of an origin trial");

namespace blink {

class FeatureContext;

// A class that stores static enablers for all experimental features.

class PLATFORM_EXPORT RuntimeEnabledFeaturesBase {
  STATIC_ONLY(RuntimeEnabledFeaturesBase);

 private:
  // Index of each non-protected feature's flag in `feature_states_`. Using a
  // single array + indices (rather than one static bool per feature) lets
  // lookup tables store small integers instead of pointers.
  enum FlagIndex : uint16_t {
    kAboutBlankPageRespectsDarkModeOnUserActionFlagIndex,
    kAccelerated2dCanvasFlagIndex,
    kAcceleratedSmallCanvasesFlagIndex,
    kAccessibilityCheckIfcInPreviousTextOnLineFlagIndex,
    kAccessibilityCustomElementRoleNoneFlagIndex,
    kAccessibilityExposeDisplayNoneFlagIndex,
    kAccessibilityImplicitActionsFlagIndex,
    kAccessibilityMinRoleTabbableFlagIndex,
    kAccessibilityOSLevelBoldTextFlagIndex,
    kAccessibilityProhibitedNamesFlagIndex,
    kAccessibilitySerializationSizeMetricsFlagIndex,
    kAccessibilityUseAXPositionForDocumentMarkersFlagIndex,
    kAccessKeyLabelFlagIndex,
    kAddressSpaceFlagIndex,
    kAdInterestGroupAPIFlagIndex,
    kAdjustEndOfNextParagraphIfMovedParagraphIsUpdatedFlagIndex,
    kAdTaggingFlagIndex,
    kAIClassifierAPIFlagIndex,
    kAIEmbeddingsAPIFlagIndex,
    kAIEmbeddingsAPIForWorkersFlagIndex,
    kAIPageContentAnchoredFixedOffscreenNonActionabilityFlagIndex,
    kAIPageContentAnchoredNonFixedOffscreenNonActionabilityFlagIndex,
    kAIPageContentBuildOnLoadForTestingFlagIndex,
    kAIPageContentCheckGeometryFlagIndex,
    kAIPageContentConvertNodeTextToUtf8FlagIndex,
    kAIPageContentElementCSSRedactionFlagIndex,
    kAIPageContentIncludeSVGSubtreeFlagIndex,
    kAIPageContentOuterBoxMapToAncestorSpaceFlagIndex,
    kAIPageContentPaidContentAnnotationFlagIndex,
    kAIPageContentSkipUnclickableFixedOverlaysFlagIndex,
    kAIPageContentTrackedElementsIframeFlagIndex,
    kAIPageContentTrackedElementsPasswordFlagIndex,
    kAIPageContentVisualViewportClampFlagIndex,
    kAIPromptAPIFlagIndex,
    kAIPromptAPIForWorkersFlagIndex,
    kAIPromptAPILegacyIdentifiersFlagIndex,
    kAIPromptAPILegacyParamsFlagIndex,
    kAIPromptAPIMultimodalInputFlagIndex,
    kAIPromptAPIParamsFlagIndex,
    kAIPromptAPIStructuredOutputFlagIndex,
    kAIPromptAPIToolUseFlagIndex,
    kAIProofreadingAPIFlagIndex,
    kAIRewriterAPIFlagIndex,
    kAIRewriterAPIForWorkersFlagIndex,
    kAISummarizationAPIFlagIndex,
    kAISummarizationAPIForWorkersFlagIndex,
    kAISummarizationPerformancePreferenceFlagIndex,
    kAIWriterAPIFlagIndex,
    kAIWriterAPIForWorkersFlagIndex,
    kAlignZoomToCenterFlagIndex,
    kAllImagesPaintedSentToElementTimingFlagIndex,
    kAllowContentInitiatedDataUrlNavigationsFlagIndex,
    kAllowPreloadingWithCSPMetaTagFlagIndex,
    kAllowSameSiteNoneCookiesInSandboxFlagIndex,
    kAllowSvgUseToReferenceExternalDocumentRootFlagIndex,
    kAllowSyntheticTimingForCanvasCaptureFlagIndex,
    kAllowURNsInIframesFlagIndex,
    kAncestorOriginsStoredOnDocumentFlagIndex,
    kAnchorPositionAdjustmentWithoutOverflowFlagIndex,
    kAndroidDownloadableFontsMatchingFlagIndex,
    kAnimationEventAnimationFlagIndex,
    kAnimationProgressAPIFlagIndex,
    kAnimationRangeRejectRelativeLengthsFlagIndex,
    kAnimationTriggerFlagIndex,
    kAnimationWorkletFlagIndex,
    kAnnotationSpaceForMultiColFlagIndex,
    kAnnotationSpaceOnStartFlagIndex,
    kAnonymousIframeFlagIndex,
    kAOMAriaRelationshipPropertiesFlagIndex,
    kAOMAriaRelationshipPropertiesAriaOwnsFlagIndex,
    kAppearanceBaseFlagIndex,
    kApproximateGeolocationPermissionFlagIndex,
    kApproximateGeolocationPermissionAccuracyModeFlagIndex,
    kApproximateGeolocationPermissionAPIFlagIndex,
    kApproximateGeolocationWebVisibleAPIFlagIndex,
    kAppTitleFlagIndex,
    kAriaActionsFlagIndex,
    kAriaNotifyFlagIndex,
    kAriaNotifyV2FlagIndex,
    kAriaRowColIndexTextFlagIndex,
    kAttributionReportingFlagIndex,
    kAudioContextAsyncStateTransitionsFlagIndex,
    kAudioContextPlaybackStatsFlagIndex,
    kAudioContextSetSinkIdFlagIndex,
    kAudioOutputDevicesFlagIndex,
    kAudioVideoTracksFlagIndex,
    kAudioWorkletSharedPortFlagIndex,
    kAuthorSpecifiedLayoutScrollSnapBehaviorFlagIndex,
    kAutoDarkModeFlagIndex,
    kAutoDarkModeSkipImagesFlagIndex,
    kAutoDarkModeSVGSizeThresholdFlagIndex,
    kAutofillFlagIndex,
    kAutofillEventFlagIndex,
    kAutofillPreviewGenericFontFamilyFlagIndex,
    kAutofillPreviewIgnoreAuthorFontFlagIndex,
    kAutomationControlledFlagIndex,
    kAutoPictureInPictureVideoHeuristicsFlagIndex,
    kAutoSizeUsesScrollWidthForOverflowFlagIndex,
    kAvoidEmbeddedContentViewLocationFlagIndex,
    kAvoidNonSelectableSelectionBoundaryFlagIndex,
    kAvoidSynchronousBlurOnDisabledAttributeChangeFlagIndex,
    kBackfaceVisibilityInteropFlagIndex,
    kBackForwardCacheFlagIndex,
    kBackForwardCacheExperimentHTTPHeaderFlagIndex,
    kBackForwardCacheNotRestoredReasonsFlagIndex,
    kBackForwardCacheRestorationPerformanceEntryFlagIndex,
    kBackForwardCacheUpdateNotRestoredReasonsNameFlagIndex,
    kBackgroundClipTextDecorationFlagIndex,
    kBackgroundFetchFlagIndex,
    kBackgroundPageFreezeOptOutFlagIndex,
    kBarcodeDetectorFlagIndex,
    kBaseAppearanceInlineSizingFlagIndex,
    kBasicShapeCornerRadiusFlagIndex,
    kBidiCaretAffinityFlagIndex,
    kBidiVisualOrderCaretMovementFlagIndex,
    kBlinkExtensionWebViewFlagIndex,
    kBlinkExtensionWebViewMediaIntegrityFlagIndex,
    kBlinkGeometryMapperViewportFastPathFlagIndex,
    kBlinkLifecycleScriptForbiddenFlagIndex,
    kBlinkRuntimeCallStatsFlagIndex,
    kBlobBytesFlagIndex,
    kBlockingFocusWithoutUserActivationFlagIndex,
    kBlockSelectPopupUnfocusedWindowFlagIndex,
    kBoundaryEventDispatchTracksNodeRemovalFlagIndex,
    kBoxDecorationBreakCloneLineBreakingFlagIndex,
    kBrowserInitiatedAutomaticPictureInPictureFlagIndex,
    kBufferedBytesConsumerLimitSizeFlagIndex,
    kBypassPepcSecurityForTestingFlagIndex,
    kCacheControlRFC7234ParsingFlagIndex,
    kCacheControlRFC7234ParsingMetricsFlagIndex,
    kCacheStorageCodeCacheHintFlagIndex,
    kCacheStyleAdjusterFlagIndex,
    kCameraAndMicrophoneElementsFlagIndex,
    kCanvas2dCanvasFilterFlagIndex,
    kCanvas2dDeferredFlushFlagIndex,
    kCanvas2dLayersFlagIndex,
    kCanvas2dLayersWithOptionsFlagIndex,
    kCanvas2dMeshFlagIndex,
    kCanvasDrawElementFlagIndex,
    kCanvasFloatingPointFlagIndex,
    kCanvasGlobalHDRHeadroomFlagIndex,
    kCanvasGradientCSSColor4FlagIndex,
    kCanvasHDRFlagIndex,
    kCanvasTextMetricsPreciseBoundsFlagIndex,
    kCanvasToneMappingFlagIndex,
    kCanvasUsesArcPaintOpFlagIndex,
    kCapabilityDelegationDigitalCredentialsFlagIndex,
    kCapabilityDelegationDisplayCaptureRequestFlagIndex,
    kCaptureControllerFlagIndex,
    kCapturedMouseEventsFlagIndex,
    kCapturedSurfaceControlFlagIndex,
    kCapturedSurfaceResolutionFlagIndex,
    kCaptureHandleFlagIndex,
    kCaretOutsideEditableAtomicInlineFlagIndex,
    kCCTNewRFMPushBehaviorFlagIndex,
    kCDTNewCrossOriginHandlingFlagIndex,
    kCDTNewDestinationFlagIndex,
    kCDTNewReferrerAndReferrerPolicyHandlingFlagIndex,
    kCheckableInputTypeLayoutInlineFlagIndex,
    kCheckVisibilityExtraPropertiesFlagIndex,
    kClampUnfocusedSelectionCacheFlagIndex,
    kCleanUpActivationBehaviorFlagIndex,
    kClearCurrentTargetAfterDispatchFlagIndex,
    kClearDisplayLockPrePaintFlagsFlagIndex,
    kClearFocusWithinOnSubtreeRemovalFlagIndex,
    kClearTargetOnlyIfInShadowTreeFlagIndex,
    kClipboardEventTargetUsesContainerNodeFlagIndex,
    kClipboardPasteImageRespectBufferFlagIndex,
    kClipElementVisibleBoundsInLocalRootFlagIndex,
    kClipPathNestedRasterOptimizationFlagIndex,
    kCoalesceSelectionchangeEventFlagIndex,
    kCoepReflectionFlagIndex,
    kColorInputAcceptsCSSColorsFlagIndex,
    kColorSpaceDisplayP3LinearFlagIndex,
    kColorSpacePredefinedLinearSpacesFlagIndex,
    kColorSpaceRec2100LinearFlagIndex,
    kCommaSeparatedContainerQueriesFlagIndex,
    kComposedPathReturnTargetBeingDispatchedFlagIndex,
    kCompositeBGColorAnimationFlagIndex,
    kCompositeBoxShadowAnimationFlagIndex,
    kCompositeClipPathAnimationFlagIndex,
    kCompositedSelectionUpdateFlagIndex,
    kCompositingDecisionAtAnimationPhaseBoundariesFlagIndex,
    kCompositionForegroundMarkersFlagIndex,
    kCompositorEventTriggerFlagIndex,
    kCompositorTimelineTriggerFlagIndex,
    kCompressionDictionaryTransportFlagIndex,
    kComputedAccessibilityInfoFlagIndex,
    kComputePressureFlagIndex,
    kConcurrentNativePaintWorkletsFlagIndex,
    kConditionalTracingLoAFFlagIndex,
    kConnectionAllowlistEmbeddedEnforcementFlagIndex,
    kConstructableStylesheetCacheFlagIndex,
    kContactsManagerFlagIndex,
    kContactsManagerExtraPropertiesFlagIndex,
    kContainerNameOnlyFlagIndex,
    kContainerTimingFlagIndex,
    kContentIndexFlagIndex,
    kContextMenuFlagIndex,
    kControlledFrameFlagIndex,
    kControlledFrameWebRequestSecurityInfoFlagIndex,
    kCookieStoreAPIMaxAgeFlagIndex,
    kCookieStoreAPIWhitespaceStrippingFlagIndex,
    kCoopRestrictPropertiesFlagIndex,
    kCorrectTemplateFormParsingFlagIndex,
    kCorsRFC1918FlagIndex,
    kCpuPerformanceFlagIndex,
    kCrashReportingStorageAPIFlagIndex,
    kCreateInlineContentsAnonymousBlockFlagIndex,
    kCSPHashesV1FlagIndex,
    kCSPReportHashFlagIndex,
    kCSSAccentColorKeywordFlagIndex,
    kCSSActiveCaptionMapsToCanvasFlagIndex,
    kCSSAlphaColorFunctionFlagIndex,
    kCSSAlphaColorFunctionRequiresAlphaFlagIndex,
    kCSSAltCounterFlagIndex,
    kCSSAnimationIterationCompositeFlagIndex,
    kCSSArgumentGrammarFlagIndex,
    kCSSAtRuleCounterStyleImageSymbolsFlagIndex,
    kCSSAtRuleCounterStyleSpeakAsDescriptorFlagIndex,
    kCSSAttributeValueCaseSensitiveNonHTMLFlagIndex,
    kCSSBackgroundClipBorderAreaFlagIndex,
    kCSSBorderShapeFlagIndex,
    kCSSCalcSimplificationAndSerializationFlagIndex,
    kCSSCaretAnimationFlagIndex,
    kCSSCaretColorWithOptionalSecondValueFlagIndex,
    kCSSCaretShapeFlagIndex,
    kCSSCaseSensitiveSelectorFlagIndex,
    kCSSChUnitSpecCompliantFallbackFlagIndex,
    kCSSColorTypedOMFlagIndex,
    kCSSContainerProgressNotationFlagIndex,
    kCSSContainerStyleQueriesRangeFlagIndex,
    kCSSContrastColorFlagIndex,
    kCSSCornersShorthandFlagIndex,
    kCSSCounterResetReversedFlagIndex,
    kCSSCounterStyleSymbolsFunctionFlagIndex,
    kCSSCrossFadeFlagIndex,
    kCSSCustomHighlightUniversalSelectorFlagIndex,
    kCSSCustomMediaFlagIndex,
    kCSSDynamicRangeLimitFlagIndex,
    kCSSEnumeratedCustomPropertiesFlagIndex,
    kCSSFlowStartAndEndFlagIndex,
    kCSSFontFamilySerializationFlagIndex,
    kCSSFontSizeAdjustFlagIndex,
    kCSSFunctionsFlagIndex,
    kCSSGridLanesLayoutFlagIndex,
    kCSSHangingPunctuationFlagIndex,
    kCSSHexAlphaColorFlagIndex,
    kCSSIdentFunctionFlagIndex,
    kCSSImageAnimationFlagIndex,
    kCSSImageFunctionFlagIndex,
    kCSSInheritFunctionFlagIndex,
    kCSSInRangeOutOfRangeReversedRangesFlagIndex,
    kCSSKeyframesRuleLengthFlagIndex,
    kCSSLangExtendedRangesFlagIndex,
    kCSSLayoutAPIFlagIndex,
    kCSSLetterAndWordSpacingPercentageFlagIndex,
    kCSSLightDarkImageFlagIndex,
    kCSSLineClampFlagIndex,
    kCSSLineClampAsShorthandFlagIndex,
    kCSSLineClampLineBreakingEllipsisFlagIndex,
    kCSSListCounterAccountingFlagIndex,
    kCSSLogicalCombinationPseudoFlagIndex,
    kCSSMarkerNestedPseudoElementFlagIndex,
    kCssMaxContentSizingFlagIndex,
    kCSSMediaElementPseudosFlagIndex,
    kCSSMediaProgressNotationFlagIndex,
    kCSSMixinsFlagIndex,
    kCSSNestedPseudoElementsFlagIndex,
    kCSSOMGetComputedStylePseudoElementRequiresColonFlagIndex,
    kCSSOverscrollBehaviorChainFlagIndex,
    kCSSPaintAPIArgumentsFlagIndex,
    kCSSParserIgnoreCharsetForURLsFlagIndex,
    kCSSPolygonRoundingFlagIndex,
    kCSSPositionStickyStaticScrollPositionFlagIndex,
    kCSSPrivateFlagIndex,
    kCSSProgressNotationFlagIndex,
    kCSSPseudoColumnFlagIndex,
    kCSSPseudoElementBackdropFlagIndex,
    kCSSPseudoElementInterfaceFlagIndex,
    kCSSPseudoElementViewTransitionsFlagIndex,
    kCSSPseudoHasSlottedFlagIndex,
    kCSSPseudoScrollButtonsFlagIndex,
    kCSSPseudoScrollMarkersFlagIndex,
    kCSSRandomFunctionFlagIndex,
    kCSSRandomFunctionTypedOMFlagIndex,
    kCSSResizeAutoFlagIndex,
    kCSSResourceIntegrityEnforcementFlagIndex,
    kCSSRevertRuleFlagIndex,
    kCSSRubyOverhangFlagIndex,
    kCSSSafePrintableInsetFlagIndex,
    kCSSScopeifiedParentPseudoClassFlagIndex,
    kCSSScopeImportFlagIndex,
    kCSSScrolledContainerQueriesFlagIndex,
    kCSSScrollInitialTargetFlagIndex,
    kCSSScrollMarkerGroupModesFlagIndex,
    kCSSScrollMarkerTargetBeforeAfterFlagIndex,
    kCSSScrollSnapChangeEventFlagIndex,
    kCSSScrollSnapChangingEventFlagIndex,
    kCSSScrollSnapEventConstructorExposedFlagIndex,
    kCSSScrollSnapEventsFlagIndex,
    kCSSScrollSnapStopBeforeFlagIndex,
    kCSSScrollSnapTypePairFlagIndex,
    kCSSScrollTargetGroupFlagIndex,
    kCSSScrollTargetGroupAriaCurrentFlagIndex,
    kCSSShapeOutsidePathAndShapeSupportFlagIndex,
    kCSSShapeOutsideRectAndXywhSupportFlagIndex,
    kCSSStyleSheetInitBaseURLFlagIndex,
    kCSSSupportsAtRuleFunctionFlagIndex,
    kCSSSupportsForImportRulesFlagIndex,
    kCSSSupportsNamedFeatureFunctionFlagIndex,
    kCSSSystemAccentColorFlagIndex,
    kCSSTextAlignMatchParentFlagIndex,
    kCSSTextDecorationInsetFlagIndex,
    kCSSTextDecorationSkipInkAllFlagIndex,
    kCSSTextDecorationSkipSpacesFlagIndex,
    kCssTextFitFlagIndex,
    kCssTextFitReshapingFlagIndex,
    kCSSTextSpacingFlagIndex,
    kCSSTextTransformFullSizeKanaFlagIndex,
    kCSSTextTransformFullWidthFlagIndex,
    kCSSTextTransformMultiKeywordFlagIndex,
    kCSSTimelineNameConflictResolutionFlagIndex,
    kCSSTimelineScopeAllFlagIndex,
    kCSSTimelineScopeGlobalFlagIndex,
    kCSSTypedArithmeticFlagIndex,
    kCSSURLRequestModifiersFlagIndex,
    kCSSUserSelectContainFlagIndex,
    kCSSUserValidAndUserInvalidForRadioFlagIndex,
    kCSSVideoDynamicRangeMediaQueriesFlagIndex,
    kCSSViewTransitionAutoNameFlagIndex,
    kCSSWindowDragFlagIndex,
    kCSSZoomAnimationFlagIndex,
    kCustomElementsDisableFormattingFixupsFlagIndex,
    kCustomizableComboboxFlagIndex,
    kCustomizableSelectMultiplePopupFlagIndex,
    kCustomScrollbarApplyMinimumThumbLengthFlagIndex,
    kDatabaseFlagIndex,
    kDateTimeInputTypeEarlyAdvanceFixFlagIndex,
    kDeclarativeCSSModulesFlagIndex,
    kDeclarativeCSSModulesStyleTagFlagIndex,
    kDeclarativeFragmentFlagIndex,
    kDeclarativePerformanceObserverFlagIndex,
    kDeclarativeSkeletonsFlagIndex,
    kDelegatesFocusTextControlInputFixFlagIndex,
    kDeprecateUnloadOptOutFlagIndex,
    kDesktopCaptureDisableLocalEchoControlFlagIndex,
    kDesktopPWAsAdditionalWindowingControlsFlagIndex,
    kDesktopPWAsAdditionalWindowingControlsOnMoveFlagIndex,
    kDeviceAttributesFlagIndex,
    kDeviceOrientationRequestPermissionFlagIndex,
    kDevicePostureFlagIndex,
    kDialogCloseWhenOpenRemovedFlagIndex,
    kDialogNewFocusBehaviorFlagIndex,
    kDigitalCredentialsProtocolFilterFlagIndex,
    kDigitalGoodsFlagIndex,
    kDigitalGoodsV2_1FlagIndex,
    kDirectSocketsFlagIndex,
    kDirectSocketsInServiceWorkersFlagIndex,
    kDirectSocketsInSharedWorkersFlagIndex,
    kDisableAnchorCenterOnAlignJustifyItemsFlagIndex,
    kDisableDifferentOriginSubframeDialogSuppressionFlagIndex,
    kDisableEllipsisWhenScrolledFlagIndex,
    kDisableFormControlChangeEventDuringMutationFlagIndex,
    kDisconnectWebSocketOnBFCacheFlagIndex,
    kDispatchHiddenVisibilityTransitionsFlagIndex,
    kDispatchSelectionchangeEventPerElementFlagIndex,
    kDisplayContentsFocusableFlagIndex,
    kDisplayCutoutAPIFlagIndex,
    kDocumentCookieFlagIndex,
    kDocumentDomainFlagIndex,
    kDocumentIsolationPolicyFlagIndex,
    kDocumentNamedPropertiesIgnoreExposednessFlagIndex,
    kDocumentOpenIframeUnloadEventsFlagIndex,
    kDocumentOpenOriginAliasRemovalFlagIndex,
    kDocumentOpenSandboxInheritanceRemovalFlagIndex,
    kDocumentPatchingFlagIndex,
    kDocumentPictureInPictureAPIFlagIndex,
    kDocumentPictureInPicturePreferInitialPlacementFlagIndex,
    kDocumentPictureInPictureUserActivationFlagIndex,
    kDocumentPolicyDocumentDomainFlagIndex,
    kDocumentPolicyExpectNoLinkedResourcesFlagIndex,
    kDocumentPolicyIncludeJSCallStacksInCrashReportsFlagIndex,
    kDocumentPolicyInDedicatedWorkerFlagIndex,
    kDocumentPolicyJSProfilingModeFlagIndex,
    kDocumentPolicyNegotiationFlagIndex,
    kDocumentPolicyNetworkEfficiencyGuardrailsFlagIndex,
    kDocumentPolicySyncXHRFlagIndex,
    kDocumentWriteFlagIndex,
    kDOMParserXmlScriptAlreadyStartedFlagIndex,
    kDragAndDropDownloadURLListFlagIndex,
    kDragAndDropJSFileObjectsFlagIndex,
    kDragImageForLargeImagesFlagIndex,
    kDumpForAbsentKeyframeSnapshotsFlagIndex,
    kEditContextAssignmentAsPerSpecFlagIndex,
    kEditContextHandleTextOrSelectionUpdateDuringCompositionFlagIndex,
    kEditContextSelectionUpdateBeforeTextUpdateEventFlagIndex,
    kEditingUseDomPositionApiFlagIndex,
    kElasticOverscrollBackgroundPaintLocationFixFlagIndex,
    kElasticOverscrollUseEventDeltaForAxisSelectionFlagIndex,
    kElementCanvasTransformFlagIndex,
    kElementCaptureFlagIndex,
    kElementInternalsBehaviorsFlagIndex,
    kElementMatchContainerFlagIndex,
    kElementSpecificReadOnlyConstraintValidationFlagIndex,
    kEmailVerificationProtocolFlagIndex,
    kEmailVerificationStatusIndicatorFlagIndex,
    kEmbeddedContentCenterAlignBaselineFlagIndex,
    kEnableXSLTForCAPAlertsFlagIndex,
    kEndpointInclusiveCommitStylesFlagIndex,
    kEnforceAnonymityExposureFlagIndex,
    kEntropyIgnoredForFirstVideoFrameLCPFlagIndex,
    kEventPseudoTargetPropertyFlagIndex,
    kEventTimingInteractionCountFlagIndex,
    kEventTimingMatchingHTMLFlagIndex,
    kEventTimingTargetSelectorFlagIndex,
    kEventTriggerFlagIndex,
    kExperimentalContentSecurityPolicyFeaturesFlagIndex,
    kExperimentalJSProfilerMarkersFlagIndex,
    kExperimentalMachineLearningNeuralNetworkFlagIndex,
    kExperimentalPoliciesFlagIndex,
    kExposeCSSFontFeatureValuesRuleFlagIndex,
    kExposeRenderTimeNonTaoDelayedImageFlagIndex,
    kExtendedTextMetricsFlagIndex,
    kExtensionScriptTaggingFlagIndex,
    kExtensionScriptTaggingTestingAPIFlagIndex,
    kExternalPopupMenuClickEventFlagIndex,
    kEyeDropperAPIFlagIndex,
    kFaceDetectorFlagIndex,
    kFastPositionIteratorFlagIndex,
    kFedCmFlagIndex,
    kFedCmActiveModeMultipleIdentityProvidersFlagIndex,
    kFedCmAutofillFlagIndex,
    kFedCmDelegationFlagIndex,
    kFedCmIdentityHandlerFlagIndex,
    kFedCmIdPRegistrationFlagIndex,
    kFedCmLightweightModeFlagIndex,
    kFedCmMultipleIdentityProvidersFlagIndex,
    kFedCmMultipleRequestsFlagIndex,
    kFedCmNavigationInterceptionFlagIndex,
    kFencedFramesFlagIndex,
    kFencedFramesAPIChangesFlagIndex,
    kFencedFramesLocalUnpartitionedDataAccessFlagIndex,
    kFetchBodyBytesFlagIndex,
    kFetchLaterAPIFlagIndex,
    kFetchRetryFlagIndex,
    kFetchUploadStreamingFlagIndex,
    kFileColorPickerConsumeActivationFlagIndex,
    kFileHandlingFlagIndex,
    kFilePickerEventsFixFlagIndex,
    kFileSystemFlagIndex,
    kFileSystemAccessFlagIndex,
    kFileSystemAccessAPIExperimentalFlagIndex,
    kFileSystemAccessGetCloudIdentifiersFlagIndex,
    kFileSystemAccessLocalFlagIndex,
    kFileSystemAccessLockingSchemeFlagIndex,
    kFileSystemAccessOriginPrivateFlagIndex,
    kFileSystemAccessRevokeReadOnRemoveFlagIndex,
    kFileSystemAccessWriteModeFlagIndex,
    kFileSystemObserverFlagIndex,
    kFileSystemObserverUnobserveFlagIndex,
    kFilterableSelectFlagIndex,
    kFilterContainerLevelStylesFlagIndex,
    kFilteringPrimitivesFlagIndex,
    kFindBufferCollapseSkippedSpaceFlagIndex,
    kFindBufferMatchAcrossIgnoredNodesFlagIndex,
    kFindFirstMisspellingEndWhenNonEditableFlagIndex,
    kFindIgnoreSuggestionFixFlagIndex,
    kFirstLineTextMetricsFlagIndex,
    kFixHTMLFormControlElementIsReadOnlyFlagIndex,
    kFixMapElementEmptyNameBugFlagIndex,
    kFixMarkerSuppressionForAppearanceAutoFlagIndex,
    kFixSelectionPaintRangeNullOptFlagIndex,
    kFixVisualRectRemoteViewportTransformFlagIndex,
    kFledgeFlagIndex,
    kFledgeAuctionDealSupportFlagIndex,
    kFledgeBiddingAndAuctionServerAPIFlagIndex,
    kFledgeBiddingAndAuctionServerAPIMultiSellerFlagIndex,
    kFledgeClickinessFlagIndex,
    kFledgeCustomMaxAuctionAdComponentsFlagIndex,
    kFledgeDeprecatedRenderURLReplacementsFlagIndex,
    kFledgeDirectFromSellerSignalsHeaderAdSlotFlagIndex,
    kFledgeDirectFromSellerSignalsWebBundlesFlagIndex,
    kFledgeMultiBidFlagIndex,
    kFledgePrivateModelTrainingFlagIndex,
    kFledgeRealTimeReportingFlagIndex,
    kFledgeSellerNonceFlagIndex,
    kFledgeSellerScriptExecutionModeFlagIndex,
    kFledgeTrustedSignalsKVv1CreativeScanningFlagIndex,
    kFledgeTrustedSignalsKVv2ContextualDataFlagIndex,
    kFledgeTrustedSignalsKVv2SupportFlagIndex,
    kFlexWrapBalanceFlagIndex,
    kFocusgroupFlagIndex,
    kFocusgroupV2FlagIndex,
    kFocusRingRespectExplicitOutlineColorInDarkModeFlagIndex,
    kFontAccessFlagIndex,
    kFontationsPrintingFlagIndex,
    kFontDataServiceForCSSLocalFontsFlagIndex,
    kFontFallbackForTabSizeFlagIndex,
    kFontFamilyPostscriptMatchingCTMigrationFlagIndex,
    kFontFamilyStyleMatchingCTMigrationFlagIndex,
    kFontFeatureSettingsDescriptorFlagIndex,
    kFontFormatAvar2FlagIndex,
    kFontLanguageOverrideFlagIndex,
    kFontMatchAliasesAsLastResortFlagIndex,
    kFontPrewarmerShutdownFallbackFlagIndex,
    kFontStyleObliqueZeroDegreeAsNormalFlagIndex,
    kFontVariationSettingsDescriptorFlagIndex,
    kForcedColorsFlagIndex,
    kForceEagerMeasureMemoryFlagIndex,
    kForceReduceMotionFlagIndex,
    kForwardReasonToFetchBodyAbortFlagIndex,
    kFractionalScrollOffsetsFlagIndex,
    kFractionalScrollOffsetsForWebAPIFlagIndex,
    kFragmentedOofInCbFlagIndex,
    kFrameSerializerNoWebEntitiesFlagIndex,
    kFreezeFramesOnVisibilityFlagIndex,
    kGamepadButtonTypesFlagIndex,
    kGamepadMultitouchFlagIndex,
    kGamepadRawInputChangeEventFlagIndex,
    kGamepadWindowEventHandlersFlagIndex,
    kGenerateDragOverlayBeforeDragStartFlagIndex,
    kGenerateXSLTWarningBannerFlagIndex,
    kGeolocationElementFlagIndex,
    kGeometryMapperSingularTransformFixFlagIndex,
    kGeometryUtilsFlagIndex,
    kGeometryUtilsForCSSPseudoElementFlagIndex,
    kGetAllScreensMediaFlagIndex,
    kGetDisplayMediaFlagIndex,
    kGetDisplayMediaAudioSelectionFlagIndex,
    kGetDisplayMediaRequiresUserActivationFlagIndex,
    kGetDisplayMediaWindowAudioCaptureFlagIndex,
    kGetElementsByNameOnlyHTMLElementsFlagIndex,
    kGetUserMediaEchoCancellationModesFlagIndex,
    kGlobalPrivacyControlFlagIndex,
    kGlobalPrivacyControlForceFlagIndex,
    kGlobalPrivacyControlTestFlagIndex,
    kGraphemeClusterBoundsCheckFlagIndex,
    kGroupEffectFlagIndex,
    kHandleShadowDOMInSubstringUtilFlagIndex,
    kHandwritingRecognitionFlagIndex,
    kHarfRustShapingFlagIndex,
    kHasUAVisualTransitionFlagIndex,
    kHeadingOffsetFlagIndex,
    kHideVideoControlsWhenUnneededFlagIndex,
    kHighlightsFromPointFlagIndex,
    kHitTestBorderRadiusForStackingContextFlagIndex,
    kHitTestContainerTransformStateForPreserve3dFlagIndex,
    kHrefTranslateFlagIndex,
    kHstsTopLevelNavigationsOnlyFlagIndex,
    kHTMLAdoptionAlgorithmNewStepsFlagIndex,
    kHTMLAreaElementDisplayNoneFlagIndex,
    kHTMLAreaHreflangTypeFlagIndex,
    kHTMLBodyMarginPixelLengthFlagIndex,
    kHTMLCommandActionsV2FlagIndex,
    kHTMLCommandElementRemovalFlagIndex,
    kHTMLCommandForScrollCommandsFlagIndex,
    kHTMLElementScrollParentFlagIndex,
    kHTMLInputElementDropWebkitClearButtonFlagIndex,
    kHTMLInterestForInterestButtonPseudoFlagIndex,
    kHTMLLinkElementAttributeValueChangesFlagIndex,
    kHTMLParserTruncatedMarkupDeclarationFlagIndex,
    kHTMLParserYieldAndDelayOftenForTestingFlagIndex,
    kHTMLParserYieldByUserTimingFlagIndex,
    kHTMLPrintingArtifactAnnotationsFlagIndex,
    kHTMLProcessingInstructionFlagIndex,
    kHTMLSwitchAttributeFlagIndex,
    kICUCapitalizationFlagIndex,
    kIgnoreLetterSpacingInCursiveScriptsFlagIndex,
    kImageDataPixelFormatFlagIndex,
    kImageDocumentUseLayoutWidthFlagIndex,
    kImageSrcsetReselectionFlagIndex,
    kImplicitRootScrollerFlagIndex,
    kIncomingCallNotificationsFlagIndex,
    kIncrementalFontTransferFlagIndex,
    kInertElementNonEditableFlagIndex,
    kInfiniteCullRectFlagIndex,
    kInheritUserModifyWithoutContenteditableFlagIndex,
    kInlineBlockLineNavigationFlagIndex,
    kInlineCursorSkipNonIfcFlagIndex,
    kInlineScriptCacheHintFlagIndex,
    kInnerHTMLParserFastpathLogFailureFlagIndex,
    kInputDisabledHandlerFixFlagIndex,
    kInputInSelectFlagIndex,
    kInputMultipleFieldsUIFlagIndex,
    kInputMultipleFieldsUIWithPointerChecksFlagIndex,
    kInputTypeColorEnhancementsFlagIndex,
    kInsertBlockquoteBeforeOuterBlockFlagIndex,
    kInstalledAppFlagIndex,
    kInstallElementFlagIndex,
    kInstallOnDeviceSpeechRecognitionFlagIndex,
    kIntegrityPolicyScriptFlagIndex,
    kInterestEventsNonComposedFlagIndex,
    kInterestGroupsInSharedStorageWorkletFlagIndex,
    kIntersectionObserverCompositedAnimationsForceMainFramesFlagIndex,
    kInvertedColorsFlagIndex,
    kInvisibleSVGAnimationThrottlingFlagIndex,
    kJavaScriptCompileHintsPerFunctionMagicRuntimeFlagIndex,
    kJavaScriptImportTextFlagIndex,
    kJavaScriptSourcePhaseImportsFlagIndex,
    kKeyboardAccessibleTooltipFlagIndex,
    kKeySystemTrackConfigurationEncryptionSchemeFlagIndex,
    kLabelInteractiveContentCheckBeforeHandlerFlagIndex,
    kLangAttributeAwareFormControlUIFlagIndex,
    kLanguageDetectionAPIFlagIndex,
    kLanguageDetectionAPIForWorkersFlagIndex,
    kLayoutIgnoreMarginsForStickyFlagIndex,
    kLayoutOOFCollectInlinesFixFlagIndex,
    kLayoutTableCellAlignmentSafeFlagIndex,
    kLazyImageConformantLoadEventTimingFlagIndex,
    kLazyLoadVideoAndAudioFlagIndex,
    kLeftClickToHandleSuggestionFlagIndex,
    kLegacyAbstractRangeFlagIndex,
    kLightDismissFromClickFlagIndex,
    kLineBreakAfterSpaceBeforeOpenTagFlagIndex,
    kLineBreakBidiControlEnterFlagIndex,
    kLineBreakerHanKerningEndFlagIndex,
    kListOwnerMustHaveCSSBoxFlagIndex,
    kLocalNetworkAccessForWebRTCOptOutFlagIndex,
    kLocalNetworkAccessPermissionPolicyFlagIndex,
    kLocalNetworkAccessWebRTCFlagIndex,
    kLocalNetworkAccessWebSocketsTargetAddressSpaceFlagIndex,
    kLockedModeFlagIndex,
    kLoginElementFlagIndex,
    kLongAnimationFrameSourceCharPositionFlagIndex,
    kLongAnimationFrameSourceLineColumnFlagIndex,
    kLongAnimationFrameSourceLineColumnInterfaceFlagIndex,
    kLongAnimationFrameStyleDurationFlagIndex,
    kLongAnimationFrameWorkerFlagIndex,
    kLongPressLinkSelectTextFlagIndex,
    kLongTaskFromLongAnimationFrameFlagIndex,
    kMacCharacterFallbackCacheFlagIndex,
    kMacDisableCtrlHomeEndFlagIndex,
    kMachineLearningNeuralNetworkFlagIndex,
    kManagedConfigurationFlagIndex,
    kManualTextFlagIndex,
    kMarginTrimFlagIndex,
    kMaskDeserializationTimeForCrossOriginMessagesFlagIndex,
    kMaskWaitForAllImagesFlagIndex,
    kMathMLAnchorElementFlagIndex,
    kMathMLOperatorRTLMirroringFlagIndex,
    kMeasureMemoryFlagIndex,
    kMediaCapabilitiesEncodingInfoFlagIndex,
    kMediaCapabilitiesSpatialAudioFlagIndex,
    kMediaCaptionSettingsButtonFlagIndex,
    kMediaCaptureFlagIndex,
    kMediaCaptureBackgroundBlurFlagIndex,
    kMediaCaptureCameraControlsFlagIndex,
    kMediaCaptureConfigurationChangeFlagIndex,
    kMediaCaptureVoiceIsolationFlagIndex,
    kMediaControlsExpandGestureFlagIndex,
    kMediaControlsOverlayPlayButtonFlagIndex,
    kMediaElementMutedDefaultStateFlagIndex,
    kMediaElementVolumeGreaterThanOneFlagIndex,
    kMediaEngagementBypassAutoplayPoliciesFlagIndex,
    kMediaLatencyHintFlagIndex,
    kMediaPlaybackWhileNotVisiblePermissionPolicyFlagIndex,
    kMediaQueryNavigationControlsFlagIndex,
    kMediaSessionFlagIndex,
    kMediaSessionChapterInformationFlagIndex,
    kMediaSourceExperimentalFlagIndex,
    kMediaSourceExtensionsForWebCodecsFlagIndex,
    kMediaStreamTrackProcessorStatsFlagIndex,
    kMediaStreamTrackTransferFlagIndex,
    kMediaStreamTrackWebSpeechFlagIndex,
    kMemoryConsumerForNGShapeCacheFlagIndex,
    kMenuElementsFlagIndex,
    kMergeFixedLayersFlagIndex,
    kMergeStickyLayersFlagIndex,
    kMessagePortCloseEventFlagIndex,
    kMiddleClickAutoscrollFlagIndex,
    kMixedContentAutoupgradesUseIsMixedContentRestrictedInFrameFlagIndex,
    kMobileLayoutThemeFlagIndex,
    kModifyParagraphCrossEditingoundaryFlagIndex,
    kModuleMapDoNotCacheFailedFetchFlagIndex,
    kModulePreloadReferrerFlagIndex,
    kModulePreloadStyleJsonFlagIndex,
    kMoveEndingSelectionToListChildFlagIndex,
    kMoveParagraphsPreserveInlineStructureFlagIndex,
    kNavigateEventDeferCrossDocumentCommitFlagIndex,
    kNavigationEventTimingFlagIndex,
    kNavigationSourcePseudoClassFlagIndex,
    kNavigationTimingRedirectTimingViaTAOFlagIndex,
    kNavigationTypeAndPhaseFlagIndex,
    kNavigatorContentUtilsFlagIndex,
    kNetInfoConstantTypeFlagIndex,
    kNetInfoDownlinkMaxFlagIndex,
    kNewAnimationCompositingCheckingFlagIndex,
    kNewAnimationDispositionReportingFlagIndex,
    kNewHTMLSettingMethodsFlagIndex,
    kNoExtendSelectionToUserSelectNoneOutOfFlowFlagIndex,
    kNoExtendSelectionToUserSelectNoneOutOfFlowUnlessEditableFlagIndex,
    kNoFontAntialiasingFlagIndex,
    kNoIdleEncodingForWebTestsFlagIndex,
    kNoNbspForInterElementSpaceOnCopyFlagIndex,
    kNonEmptyBlockquotesOnOutdentingFlagIndex,
    kNonEmptyVisibleTextSelectionForTextFragmentFlagIndex,
    kNonStandardAppearanceValueSliderVerticalFlagIndex,
    kNormalizeLineEndingsInInsertTextFlagIndex,
    kNormalizeNbspForPasteAndDropFlagIndex,
    kNormalizeNbspRichTextOnlyFlagIndex,
    kNotificationConstructorFlagIndex,
    kNotificationContentImageFlagIndex,
    kNotificationsFlagIndex,
    kNotificationTriggersFlagIndex,
    kNotifySelectionControllerOnUnchangedSelectionFlagIndex,
    kNumberInputFullWidthCharsFlagIndex,
    kOffscreenCanvasGetContextAttributesFlagIndex,
    kOffsetMappingReuseFullWidthSpaceFixFlagIndex,
    kOffsetPathTransformUpdateFixFlagIndex,
    kOmitBlurEventOnElementRemovalFlagIndex,
    kOmitSubframeDetachmentEventsOnRemovalFlagIndex,
    kOnDeviceWebSpeechAvailableFlagIndex,
    kOnDeviceWebSpeechQualityFlagIndex,
    kOofLayoutRequiresSideEffectsFlagIndex,
    kOpaqueRangeFlagIndex,
    kOpenPopoverInvokerRestrictToSameTreeScopeFlagIndex,
    kOptionDisablednessCheckAncestorsFlagIndex,
    kOrientationEventFlagIndex,
    kOriginAPIFlagIndex,
    kOriginIsolationHeaderFlagIndex,
    kOriginPolicyFlagIndex,
    kOriginTrialsSampleAPIFlagIndex,
    kOriginTrialsSampleAPIBrowserReadWriteFlagIndex,
    kOriginTrialsSampleAPIDependentFlagIndex,
    kOriginTrialsSampleAPIDeprecationFlagIndex,
    kOriginTrialsSampleAPIExpiryGracePeriodFlagIndex,
    kOriginTrialsSampleAPIExpiryGracePeriodThirdPartyFlagIndex,
    kOriginTrialsSampleAPIImpliedFlagIndex,
    kOriginTrialsSampleAPIInvalidOSFlagIndex,
    kOriginTrialsSampleAPINavigationFlagIndex,
    kOriginTrialsSampleAPIPersistentExpiryGracePeriodFlagIndex,
    kOriginTrialsSampleAPIPersistentFeatureFlagIndex,
    kOriginTrialsSampleAPIPersistentInvalidOSFlagIndex,
    kOriginTrialsSampleAPIPersistentThirdPartyDeprecationFeatureFlagIndex,
    kOriginTrialsSampleAPIThirdPartyFlagIndex,
    kOutlineDrawAutoStyleZeroWidthFlagIndex,
    kOverlayGlobalRuleRemovalFlagIndex,
    kOverlayPropertyFlagIndex,
    kOverscrollGesturesFlagIndex,
    kPagePopupFlagIndex,
    kPagePopupCopyPasteFlagIndex,
    kPageSwapEventFlagIndex,
    kPaintCaretAfterInnerEditorPaintFlagIndex,
    kPaintHoldingForIframesFlagIndex,
    kPaintUnderInvalidationCheckingFlagIndex,
    kParakeetFlagIndex,
    kPartitionVisitedLinkDatabaseWithSelfLinksFlagIndex,
    kPasswordRevealFlagIndex,
    kPaymentAppFlagIndex,
    kPaymentLinkDetectionFlagIndex,
    kPaymentMethodChangeEventFlagIndex,
    kPaymentRequestFlagIndex,
    kPaymentRequestNonFullyActiveDocumentCheckInvalidStateErrorFlagIndex,
    kPerformanceManagerInstrumentationFlagIndex,
    kPerformanceMarkCustomUserTimingFromSubframeFlagIndex,
    kPerformanceMarkFeatureUsageFlagIndex,
    kPeriodicBackgroundSyncFlagIndex,
    kPerMethodCanMakePaymentQuotaFlagIndex,
    kPermissionsPolicyAPIFlagIndex,
    kPermissionsRequestRevokeFlagIndex,
    kPNaClFlagIndex,
    kPointerLockOnAndroidFlagIndex,
    kPointerRawUpdateOnlyInSecureContextFlagIndex,
    kPopoverHintNestedShowExceptionFlagIndex,
    kPopoverHintNewBehaviorFlagIndex,
    kPositionOutsideTabSpanCheckSiblingNodeFlagIndex,
    kPositionVisibilityIgnoreNonClipAncestorsFlagIndex,
    kPotentialPermissionsPolicyReportingFlagIndex,
    kPreciseMemoryInfoFlagIndex,
    kPreferDefaultScrollbarStylesFlagIndex,
    kPreferNonCompositedScrollingFlagIndex,
    kPreferredAudioOutputDevicesFlagIndex,
    kPrefersReducedDataFlagIndex,
    kPrefetchAndPrerenderActivationBeaconFlagIndex,
    kPreloadLinkRelDataUrlsFlagIndex,
    kPreloadScannerSkipMathMLScriptFlagIndex,
    kPrerender2FlagIndex,
    kPrerender2CrossOriginIframesFlagIndex,
    kPrerenderActivationByFormSubmissionFlagIndex,
    kPrerenderUntilScriptFlagIndex,
    kPresentationFlagIndex,
    kPreserveHtmlEquivalentTagsInTypingStyleFlagIndex,
    kPreserveUnfocusedSelectionCacheFlagIndex,
    kPreventTextSelectionJumpFlagIndex,
    kPrivateNetworkAccessNullIpAddressFlagIndex,
    kPrivateStateTokensFlagIndex,
    kPrivateStateTokensAlwaysAllowIssuanceFlagIndex,
    kProfilerAPIFlagIndex,
    kProfilerAPIForDedicatedWorkerFlagIndex,
    kProgrammaticScrollPromiseFlagIndex,
    kPropagateOverscrollBehaviorFromRootFlagIndex,
    kPseudoElementsFocusableFlagIndex,
    kPseudoElementsHitTestableFlagIndex,
    kPseudoElementsHoverableFlagIndex,
    kPushMessageDataBytesFlagIndex,
    kPushMessagingFlagIndex,
    kPushMessagingSubscriptionChangeFlagIndex,
    kQuotaExceededErrorUpdateFlagIndex,
    kRangeBoundaryFastPathFlagIndex,
    kRasterInducingScrollFlagIndex,
    kRateLimitPointerLockRequestsFlagIndex,
    kReadableStreamBYOBReaderReadMinOptionFlagIndex,
    kReadClipboardDataOnClipboardItemGetTypeFlagIndex,
    kReadingFlowWithSlotsFlagIndex,
    kRecheckParentDuringNodeVectorInsertionFlagIndex,
    kRecordSameDocumentPresentationTimeOnceFlagIndex,
    kReduceAcceptLanguageFlagIndex,
    kReduceUserAgentMinorVersionFlagIndex,
    kRegionCaptureFlagIndex,
    kRelatedWebsitePartitionAPIFlagIndex,
    kReleasePaintHoldingWithoutContentfulPaintFlagIndex,
    kRelOpenerBcgDependencyHintFlagIndex,
    kRemotePlaybackFlagIndex,
    kRemotePlaybackBackendFlagIndex,
    kRemoveCharsetAutoDetectionForISO2022JPFlagIndex,
    kRemoveChildrenInReplaceChildrenFlagIndex,
    kRemoveCollapsedPlaceholderForContentEditableFlagIndex,
    kRemoveDanglingMarkupInTargetFlagIndex,
    kRemoveDataUrlInSvgUseFlagIndex,
    kRemoveNonAllowlistedCreateEventFlagIndex,
    kRemoveScrollNodeWorkaroundFlagIndex,
    kRemoveTargetCurrentFlagIndex,
    kRemoveVisibleSelectionInDOMSelectionFlagIndex,
    kRenderPriorityAttributeFlagIndex,
    kReplaceChildrenWithFragmentFastPathFlagIndex,
    kReplacedNormalFlowStackingInlinePaintFlagIndex,
    kReportFirstFrameTimeAsRenderTimeFlagIndex,
    kReportLayoutShiftRectsInCssPixelsFlagIndex,
    kRequestIsReloadNavigationFlagIndex,
    kRequestStorageAccessForFlagIndex,
    kResourceTimingInitiatorFlagIndex,
    kResourceTimingUseCORSForBodySizesFlagIndex,
    kRespectOverscrollBehaviorForScrollBubblingFlagIndex,
    kResponsiveIframesFlagIndex,
    kRestrictGamepadAccessFlagIndex,
    kRestrictOwnAudioFlagIndex,
    kRootScrollbarFollowsBrowserThemeFlagIndex,
    kRouteMatchingFlagIndex,
    kRtcAlwaysNegotiateDataChannelsFlagIndex,
    kRtcAudioJitterBufferMaxPacketsFlagIndex,
    kRTCConfigurationIceTransportsFlagIndex,
    kRTCDataChannelPriorityFlagIndex,
    kRTCDiagnosticLoggingFlagIndex,
    kRTCEncodedAudioFrameConstructorFlagIndex,
    kRTCEncodedFrameAudioLevelFlagIndex,
    kRTCEncodedFrameSetMetadataFlagIndex,
    kRTCEncodedFrameTimestampsFlagIndex,
    kRTCEncodedSourceFlagIndex,
    kRTCEncodedVideoFrameAdditionalMetadataFlagIndex,
    kRTCEncodedVideoFrameConstructorFlagIndex,
    kRTCJitterBufferTargetFlagIndex,
    kRTCLegacyCallbackBasedGetStatsFlagIndex,
    kRTCRtpEncodingParametersCodecFlagIndex,
    kRtcRtpHeaderEncryptionPolicyFlagIndex,
    kRTCRtpScaleResolutionDownToFlagIndex,
    kRTCRtpScriptTransformFlagIndex,
    kRTCRtpTransportFlagIndex,
    kRTCStatsRelativePacketArrivalDelayFlagIndex,
    kRTCSvcScalabilityModeFlagIndex,
    kRunMicrotaskBeforeXmlScriptFlagIndex,
    kRunSnapshotPostLayoutStateStepsFlagIndex,
    kSanitizeIDNEmailFormInputFlagIndex,
    kSanitizerAPIFlagIndex,
    kScopedViewTransitionSizeContainmentFlagIndex,
    kScoreLineBreakerAbortFlagIndex,
    kScreenDetailedHdrHeadroomFlagIndex,
    kScriptBasedOnUnicodeBlockFlagIndex,
    kScriptedSpeechRecognitionFlagIndex,
    kScriptedSpeechSynthesisFlagIndex,
    kScrollAnchorPriorityCandidateSubtreeFlagIndex,
    kScrollAnchorSerializationUseParentForTextNodeFlagIndex,
    kScrollAxisLockFlagIndex,
    kScrollbarColorFlagIndex,
    kScrollbarGutterBugFixFlagIndex,
    kScrollbarWidthFlagIndex,
    kScrollingContentsCullRectOnScrollNodeFlagIndex,
    kScrollIntoViewAlignAutoFlagIndex,
    kScrollIntoViewNearestFlagIndex,
    kScrollIntoViewRootFrameViewportBugFixFlagIndex,
    kScrollPerformanceTimingFlagIndex,
    kScrollTimelineCurrentTimeFlagIndex,
    kScrollTimelineNamedRangeScrollFlagIndex,
    kScrollTopLeftInteropFlagIndex,
    kScrollToTextFragmentDirectiveLimitFlagIndex,
    kScrollToTextFragmentUniqueFragmentsFlagIndex,
    kSearchTextHighlightPseudoFlagIndex,
    kSecurePaymentConfirmationFlagIndex,
    kSecurePaymentConfirmationAvailabilityAPIFlagIndex,
    kSecurePaymentConfirmationCapabilitiesFlagIndex,
    kSecurePaymentConfirmationDebugFlagIndex,
    kSecurePaymentConfirmationExtensionsDisallowForThirdPartiesFlagIndex,
    kSecurePaymentConfirmationOptOutFlagIndex,
    kSelectAnchorInViewportFlagIndex,
    kSelectAudioOutputFlagIndex,
    kSelectedcontentelementAttributeFlagIndex,
    kSelectedcontentMultipleFlagIndex,
    kSelectedcontentSpecFlagIndex,
    kSelectionAndFocusedVisiblePositionMatchFlagIndex,
    kSelectionCollapsedDirectionNoneFlagIndex,
    kSelectionEditingBoundarySlottedContentFlagIndex,
    kSelectionFocusAffinityFlagIndex,
    kSelectionHandleWithBottomClippedFlagIndex,
    kSelectionRemoveRangeNotFoundErrorFlagIndex,
    kSelectionSetBaseAndExtentNonNullNodeFlagIndex,
    kSelectiveClipboardFormatReadFlagIndex,
    kSelectivePermissionsInterventionFlagIndex,
    kSelectRemoveOverflowHiddenFlagIndex,
    kSelectUsesFlatTreeFlagIndex,
    kSendBeaconThrowForBlobWithNonSimpleTypeFlagIndex,
    kSendEarlyLastBeginMainFrameFlagIndex,
    kSendSlotChangeSignalAfterNodeInsertedFlagIndex,
    kSensorExtraClassesFlagIndex,
    kSeparateDeferModuleScriptTasksFlagIndex,
    kSerialFlagIndex,
    kSerializeInvalidSelectorsInForgivingSelectorListFlagIndex,
    kSerializeViewTransitionStateInSPAFlagIndex,
    kSerialPortConnectedFlagIndex,
    kServiceWorkerBackgroundSyncInDedicatedWorkerFlagIndex,
    kServiceWorkerClientLifecycleStateFlagIndex,
    kServiceWorkerCodeCacheFlagIndex,
    kServiceWorkerInDedicatedWorkerFlagIndex,
    kServiceWorkerStaticRouterTimingInfoFlagIndex,
    kSetHTMLCanRunScriptsFlagIndex,
    kSetSequentialFocusStartingPointFlagIndex,
    kSetShapeFlagIndex,
    kShadowRootAdoptedStyleSheetFlagIndex,
    kShadowRootNamespaceCheckFlagIndex,
    kShadowRootReferenceTargetFlagIndex,
    kShadowRootReferenceTargetAriaOwnsFlagIndex,
    kShadowRootSlotAssignmentFlagIndex,
    kSharedArrayBufferFlagIndex,
    kSharedArrayBufferUnrestrictedAccessAllowedFlagIndex,
    kSharedStorageAPIFlagIndex,
    kSharedStorageWebLocksFlagIndex,
    kSharedWorkerFlagIndex,
    kSharedWorkerExtendedLifetimeFlagIndex,
    kSideRelativeBackgroundPositionFlagIndex,
    kSignatureBasedInlineIntegrityFlagIndex,
    kSingleAxisScrollContainersFlagIndex,
    kSingleAxisScrollContainersForScrollSnapFlagIndex,
    kSkipAdFlagIndex,
    kSkipCallbacksWhenDevToolsNotOpenFlagIndex,
    kSkipEventCaptureFlagIndex,
    kSkipStaleUndoStepsInIdleSpellCheckFlagIndex,
    kSkipTouchEventFilterFlagIndex,
    kSkipUnselectableElementsInParagraphBoundaryFlagIndex,
    kSkipViewTransitionSnapshotResumeRenderingFlagIndex,
    kSmallerViewportUnitsFlagIndex,
    kSmartCardFlagIndex,
    kSmartZoomFlagIndex,
    kSnapshotScrollTimelinesPostLayoutFlagIndex,
    kSortedLayoutShiftSourcesByImpactAreaFlagIndex,
    kSourceSpecificMulticastInDirectSocketsFlagIndex,
    kSpatNavUsesCursorInheritanceFlagIndex,
    kSpeakerSelectionFlagIndex,
    kSpecCompliantXmlMimeTypesFlagIndex,
    kSpeculationMeasurementFlagIndex,
    kSpeculationRulesModerateViewportHeuristicsControlFlagIndex,
    kSpellCheckChunkingFlagIndex,
    kSpellCheckCustomDictionaryAPIFlagIndex,
    kSplitLargeTextNodesFlagIndex,
    kSplitQualifiedNameOnFirstColonFlagIndex,
    kSplitTextNotCleanupDummySpansFlagIndex,
    kSrcsetSelectionMatchesImageSetFlagIndex,
    kStableBlinkFeaturesFlagIndex,
    kStackingContextIsNotStackedFlagIndex,
    kStaleImageNaturalSizeDuringRevalidationFlagIndex,
    kStandardizedBrowserZoomFlagIndex,
    kStandardizedBrowserZoomOptOutFlagIndex,
    kStickyPositionHasOverflowPerAxisFlagIndex,
    kStickyUserActivationAcrossSameOriginNavigationFlagIndex,
    kStorageBucketsFlagIndex,
    kStorageBucketsDurabilityFlagIndex,
    kStorageBucketsLocksFlagIndex,
    kStreamingSanitizerFlagIndex,
    kStrictMimeTypesForWorkersFlagIndex,
    kStylusHandwritingFlagIndex,
    kSubAppsFlagIndex,
    kSuppressPointerStreamAfterDragFlagIndex,
    kSvgAnimateMotionDiscreteCalcModeFlagIndex,
    kSvgAvoidResettingFilterQualityForTiledPatternFlagIndex,
    kSVGEmbeddedAsReplacedElementFlagIndex,
    kSvgEmptyAttributeStringParsingFixFlagIndex,
    kSvgEnableTextDecorationCssStylingFlagIndex,
    kSvgFallBackToContainerSizeFlagIndex,
    kSvgFeImageEXIFOrientationFlagIndex,
    kSvgFeImageSkipHiddenContainerViewportDependenceFlagIndex,
    kSvgFilterPaintsForHiddenContentFlagIndex,
    kSvgFilterUserSpaceViewportForSvgFlagIndex,
    kSvgIgnoreNegativeEllipseRadiiFlagIndex,
    kSvgIgnoreOuterTransformsFlagIndex,
    kSvgImageAnimationResetFlagIndex,
    kSvgImageNonUniformScalingFixFlagIndex,
    kSvgInlineRootPixelSnappingScaleAdjustmentFlagIndex,
    kSvgInstanceSyncOptimizationFlagIndex,
    kSvgLengthResolveUnparsedValueFlagIndex,
    kSvgNewZoomFlagIndex,
    kSVGPathDataAPIFlagIndex,
    kSvgPathLengthCssPropertyFlagIndex,
    kSvgScriptElementAsyncAttributeFlagIndex,
    kSvgScriptFragmentAlreadyStartedFlagIndex,
    kSvgSizingWithPreserveAspectRatioNoneFlagIndex,
    kSvgStyleElementReflectTypeAndMediaFlagIndex,
    kSvgSupportMediaFragmentsFlagIndex,
    kSVGTextPathSideAttributeFlagIndex,
    kSvgUseNestedResourceDocumentsFlagIndex,
    kSvgUseNestedResourceDocumentsDelayLoadFlagIndex,
    kSynthesizedKeyboardEventsForAccessibilityActionsFlagIndex,
    kSyntheticMouseHoverOverInactivePageFlagIndex,
    kSystemWakeLockFlagIndex,
    kTabAlignmentWithFloatsFlagIndex,
    kTableCellBorderColorInheritFlagIndex,
    kTableDefaultBorderColorCurrentColorFlagIndex,
    kTableIsAutoFixedLayoutFlagIndex,
    kTabSizeInRubyBaseFlagIndex,
    kTargetInShadowDeterminedBeforeListenerFlagIndex,
    kTargetRangesForBackwardDeletionUnitFlagIndex,
    kTestBlinkFeatureDefaultFlagIndex,
    kTestFeatureFlagIndex,
    kTestFeatureDependentFlagIndex,
    kTestFeatureForBrowserProcessReadWriteAccessOriginTrialFlagIndex,
    kTestFeatureImpliedFlagIndex,
    kTestFeatureStableFlagIndex,
    kTextAreaResizerFixedSizeFlagIndex,
    kTextAutoSpaceIgnoreRubyAnnotationFlagIndex,
    kTextBoxTrimForNestedListFlagIndex,
    kTextBoxTrimOnInlineBoxFlagIndex,
    kTextDetectorFlagIndex,
    kTextEmphasisLetterSpacingFlagIndex,
    kTextEmphasisPositionAutoFlagIndex,
    kTextEmphasisPunctuationExceptionsFlagIndex,
    kTextEmphasisWithRubyFlagIndex,
    kTextFragmentAPIFlagIndex,
    kTextFragmentIdentifiersFlagIndex,
    kTextFragmentTapOpensContextMenuFlagIndex,
    kTextIteratorExcludeAutofilledSelectFixFlagIndex,
    kTextMetricsBaselinesFlagIndex,
    kTextOverflowClipWithSelectionFlagIndex,
    kTextOverflowStringFlagIndex,
    kTextScaleMetaTagFlagIndex,
    kTextSpacingTrimFallbackFlagIndex,
    kTextSpacingTrimFallback2FlagIndex,
    kTextSpacingTrimFallbackChwsFlagIndex,
    kTextStreamMethodFlagIndex,
    kTimelineTriggerFlagIndex,
    kTimerThrottlingForBackgroundTabsFlagIndex,
    kTimestampBasedCLSTrackingFlagIndex,
    kTimeZoneChangeEventFlagIndex,
    kTopicsAPIFlagIndex,
    kTouchDragAndContextMenuFlagIndex,
    kTouchDragAndDropFlagIndex,
    kTouchDragOnShortPressFlagIndex,
    kTouchEventFeatureDetectionFlagIndex,
    kTouchTextEditingRedesignFlagIndex,
    kTransferableRTCDataChannelFlagIndex,
    kTranslateServiceFlagIndex,
    kTranslationAPIFlagIndex,
    kTranslationAPIForWorkersFlagIndex,
    kTreatMhtmlInitialDocumentLoadsAsCrossDocumentFlagIndex,
    kTreeRubyPlacementFlagIndex,
    kTrustedTypesCreateParserOptionsFlagIndex,
    kTrustedTypesFromLiteralFlagIndex,
    kTrustedTypesHTMLFlagIndex,
    kTrustedTypesUseCodeLikeFlagIndex,
    kTwoPhaseViewTransitionFlagIndex,
    kUAImageReplacementAPIFlagIndex,
    kUnboundedElementFlagIndex,
    kUnboundedElementOnTheOpenWebFlagIndex,
    kUnclosedFormControlIsInvalidFlagIndex,
    kUnexposedTaskIdsFlagIndex,
    kUnprefixedSpeechRecognitionFlagIndex,
    kUnrestrictedMeasureUserAgentSpecificMemoryFlagIndex,
    kUnrestrictedSharedArrayBufferFlagIndex,
    kUnrestrictedUsbFlagIndex,
    kUpdateComplexSafaAreaConstraintsFlagIndex,
    kUpdateSelectionOnNodeInsertionFlagIndex,
    kURLPatternCompareComponentFlagIndex,
    kURLPatternGenerateFlagIndex,
    kURLSearchParamsHasAndDeleteMultipleArgsFlagIndex,
    kUseBeginFramePresentationFeedbackFlagIndex,
    kUseLargestPaintedImageForLCPCandidateFlagIndex,
    kUseLowQualityInterpolationFlagIndex,
    kUseOriginalDomOffsetsForOffsetMapFlagIndex,
    kUsePaintGeometryForIntersectionFlagIndex,
    kUsePositionForPointInFlexibleBoxWithSingleChildElementFlagIndex,
    kUsePositionIfIsVisuallyEquivalentCandidateFlagIndex,
    kUserActionPseudosStopAtTopLayerFlagIndex,
    kUserDefinedEntryPointTimingFlagIndex,
    kUserMediaElementFlagIndex,
    kUserMediaElementLegacyFlagIndex,
    kUseShadowHostStyleCheckEditableFlagIndex,
    kUseUndoStepElementDispatchBeforeInputFlagIndex,
    kV8IdleTasksFlagIndex,
    kVariableSystemFontSupportOnWindowsFlagIndex,
    kVideoAutoFullscreenFlagIndex,
    kVideoFrameMetadataBackgroundBlurFlagIndex,
    kVideoFrameMetadataRtpTimestampFlagIndex,
    kVideoFullscreenOrientationLockFlagIndex,
    kVideoRotateToFullscreenFlagIndex,
    kVideoTrackGeneratorFlagIndex,
    kVideoTrackGeneratorInWindowFlagIndex,
    kVideoTrackGeneratorInWorkerFlagIndex,
    kViewportHeightClientHintHeaderFlagIndex,
    kViewportSegmentsFlagIndex,
    kViewTransitionDOMCallbackAfterCommitFlagIndex,
    kViewTransitionLongCallbackTimeoutForTestingFlagIndex,
    kVisibilityCollapseColumnFlagIndex,
    kVisualRectMappingFixForExpansionFlagIndex,
    kWakeLockFlagIndex,
    kWarnOnContentVisibilityRenderAccessFlagIndex,
    kWebAppInstallationFlagIndex,
    kWebAppLaunchQueueFlagIndex,
    kWebAppScopeExtensionsFlagIndex,
    kWebAppScopeSystemAccentColorFlagIndex,
    kWebAppTabStripFlagIndex,
    kWebAppTabStripCustomizationsFlagIndex,
    kWebAppTranslationsFlagIndex,
    kWebAssemblyCustomDescriptorsV2FlagIndex,
    kWebAssemblyJSPromiseIntegrationFlagIndex,
    kWebAudioBypassOutputBufferingFlagIndex,
    kWebAudioBypassOutputBufferingOptOutFlagIndex,
    kWebAudioConfigurableRenderQuantumFlagIndex,
    kWebAuthFlagIndex,
    kWebAuthAuthenticatorAttachmentFlagIndex,
    kWebAuthenticationAmbientFlagIndex,
    kWebAuthenticationAttestationFormatsFlagIndex,
    kWebAuthenticationCmtgKeyFlagIndex,
    kWebAuthenticationCrossDeviceFallbackUrlFlagIndex,
    kWebAuthenticationRemoteDesktopSupportFlagIndex,
    kWebAutocorrectByDefaultFlagIndex,
    kWebBluetoothFlagIndex,
    kWebBluetoothGetDevicesFlagIndex,
    kWebBluetoothScanningFlagIndex,
    kWebBluetoothWatchAdvertisementsFlagIndex,
    kWebBluetoothWorldIsolatedCacheFlagIndex,
    kWebCodecsVideoEncoderBuffersFlagIndex,
    kWebCryptoPQCFlagIndex,
    kWebGLDeveloperExtensionsFlagIndex,
    kWebGLDraftExtensionsFlagIndex,
    kWebGLDrawingBufferStorageFlagIndex,
    kWebGLOnWebGPUFlagIndex,
    kWebGLToneMappingFlagIndex,
    kWebGPUDeveloperFeaturesFlagIndex,
    kWebGPUExperimentalFeaturesFlagIndex,
    kWebGPUExperimentalResourceTableFlagIndex,
    kWebGPUExternalImageHDRHeadroomFlagIndex,
    kWebGPUMapSyncOnWorkersFlagIndex,
    kWebGPUMultithreadDawnWireOnWorkersFlagIndex,
    kWebHapticsFlagIndex,
    kWebHIDFlagIndex,
    kWebHIDOnServiceWorkersFlagIndex,
    kWebHIDWorldIsolatedCacheFlagIndex,
    kWebIdentityDigitalCredentialsFlagIndex,
    kWebIdentityDigitalCredentialsCreationFlagIndex,
    kWebIDLBigIntUsesToBigIntFlagIndex,
    kWebMCPFlagIndex,
    kWebMCPDeclarativeFileInputFlagIndex,
    kWebMCPFormAssociatedCustomElementsFlagIndex,
    kWebMCPTestingFlagIndex,
    kWebNFCFlagIndex,
    kWebOTPFlagIndex,
    kWebOTPAssertionFeaturePolicyFlagIndex,
    kWebPreferencesFlagIndex,
    kWebPrintingFlagIndex,
    kWebRtcSctpSnapFlagIndex,
    kWebSerialWorldIsolatedCacheFlagIndex,
    kWebShareFlagIndex,
    kWebSocketOptionBagFlagIndex,
    kWebSocketStreamFlagIndex,
    kWebSocketStreamStandardBinaryChunkTypeFlagIndex,
    kWebSpeechRecognitionContextFlagIndex,
    kWebSpeechTimestampsFlagIndex,
    kWebSpeechUnspokenPunctuationFlagIndex,
    kWebTransportAnticipatedConcurrentIncomingStreamsFlagIndex,
    kWebTransportApplicationProtocolFlagIndex,
    kWebTransportCongestionControlFlagIndex,
    kWebTransportCreateStreamsBeforeReadyFlagIndex,
    kWebTransportCustomCertificatesFlagIndex,
    kWebTransportDatagramsReadableTypeFlagIndex,
    kWebTransportDatagramsWritableFlagIndex,
    kWebTransportDrainingFlagIndex,
    kWebTransportHeadersFlagIndex,
    kWebTransportReceiveStreamFlagIndex,
    kWebTransportReliabilityFlagIndex,
    kWebTransportSendGroupFlagIndex,
    kWebTransportStatsFlagIndex,
    kWebUIBundledCodeCacheAsyncFetchFlagIndex,
    kWebUSBFlagIndex,
    kWebUSBOnDedicatedWorkersFlagIndex,
    kWebUSBOnServiceWorkersFlagIndex,
    kWebViewEnvReorderFixFlagIndex,
    kWebVTTCueLayoutByPositionAlignmentFlagIndex,
    kWebVTTCueTightLineBoxFlagIndex,
    kWebVTTLineAndPositionAlignmentFlagIndex,
    kWebVTTRegionsFlagIndex,
    kWebXRFlagIndex,
    kWebXREnabledFeaturesFlagIndex,
    kWebXRFrameRateFlagIndex,
    kWebXRFrontFacingFlagIndex,
    kWebXRGPUBindingFlagIndex,
    kWebXRHitTestEntityTypesFlagIndex,
    kWebXRImageTrackingFlagIndex,
    kWebXRLayersFlagIndex,
    kWebXRLayersCommonFlagIndex,
    kWebXRMediaBindingFlagIndex,
    kWebXRMeshDetectionFlagIndex,
    kWebXRPlaneDetectionFlagIndex,
    kWebXRPoseMotionDataFlagIndex,
    kWebXRSpecParityFlagIndex,
    kWebXRVisibilityMaskFlagIndex,
    kWheelEventMomentumFlagIndex,
    kWindowDefaultStatusFlagIndex,
    kWindowOpenAlwaysOnTopFlagIndex,
    kWordSkipSpacesPunctuationFixFlagIndex,
    kXMLNoExternalEntitiesFlagIndex,
    kXMLParserReplaceLoneSurrogatesFlagIndex,
    kXMLParsingRustFlagIndex,
    kXMLRustForNonXsltFlagIndex,
    kXMLSerializerConsistentDefaultNsDeclMatchingFlagIndex,
    kXMLViewerForIframesFlagIndex,
    kXSLTFlagIndex,
    kXSLTSpecialTrialFlagIndex,
    kFlagIndexCount,
  };
  static bool feature_states_[kFlagIndexCount];

 public:
  class PLATFORM_EXPORT Backup {
   public:
    explicit Backup();
    void Restore();

   private:
    bool feature_states_[kFlagIndexCount];
    bool is_mojo_js_enabled_;
    bool is_mojo_js_test_enabled_;
    bool is_protected_origin_trials_sample_api_enabled_;
    bool is_protected_origin_trials_sample_api_dependent_enabled_;
    bool is_protected_origin_trials_sample_api_implied_enabled_;
    bool is_test_feature_protected_enabled_;
    bool is_test_feature_protected_dependent_enabled_;
    bool is_test_feature_protected_implied_enabled_;
  };

  // Simple getter methods for protected memory values that ensure they are
  // properly initialized before first access.
  static bool get_is_mojo_js_enabled_();
  static bool get_is_mojo_js_test_enabled_();
  static bool get_is_protected_origin_trials_sample_api_enabled_();
  static bool get_is_protected_origin_trials_sample_api_dependent_enabled_();
  static bool get_is_protected_origin_trials_sample_api_implied_enabled_();
  static bool get_is_test_feature_protected_enabled_();
  static bool get_is_test_feature_protected_dependent_enabled_();
  static bool get_is_test_feature_protected_implied_enabled_();

  static bool AboutBlankPageRespectsDarkModeOnUserActionEnabled() {
    return feature_states_[kAboutBlankPageRespectsDarkModeOnUserActionFlagIndex];
  }

  static bool AboutBlankPageRespectsDarkModeOnUserActionEnabled(const FeatureContext*) { return AboutBlankPageRespectsDarkModeOnUserActionEnabled(); }

  static bool Accelerated2dCanvasEnabled() {
    return feature_states_[kAccelerated2dCanvasFlagIndex];
  }

  static bool Accelerated2dCanvasEnabled(const FeatureContext*) { return Accelerated2dCanvasEnabled(); }

  static bool AcceleratedSmallCanvasesEnabled() {
    return feature_states_[kAcceleratedSmallCanvasesFlagIndex];
  }

  static bool AcceleratedSmallCanvasesEnabled(const FeatureContext*) { return AcceleratedSmallCanvasesEnabled(); }

  static bool AccessibilityCheckIfcInPreviousTextOnLineEnabled() {
    return feature_states_[kAccessibilityCheckIfcInPreviousTextOnLineFlagIndex];
  }

  static bool AccessibilityCheckIfcInPreviousTextOnLineEnabled(const FeatureContext*) { return AccessibilityCheckIfcInPreviousTextOnLineEnabled(); }

  static bool AccessibilityCustomElementRoleNoneEnabled() {
    return feature_states_[kAccessibilityCustomElementRoleNoneFlagIndex];
  }

  static bool AccessibilityCustomElementRoleNoneEnabled(const FeatureContext*) { return AccessibilityCustomElementRoleNoneEnabled(); }

  static bool AccessibilityExposeDisplayNoneEnabled() {
    return feature_states_[kAccessibilityExposeDisplayNoneFlagIndex];
  }

  static bool AccessibilityExposeDisplayNoneEnabled(const FeatureContext*) { return AccessibilityExposeDisplayNoneEnabled(); }

  static bool AccessibilityImplicitActionsEnabled() {
    return feature_states_[kAccessibilityImplicitActionsFlagIndex];
  }

  static bool AccessibilityImplicitActionsEnabled(const FeatureContext*) { return AccessibilityImplicitActionsEnabled(); }

  static bool AccessibilityMinRoleTabbableEnabled() {
    return feature_states_[kAccessibilityMinRoleTabbableFlagIndex];
  }

  static bool AccessibilityMinRoleTabbableEnabled(const FeatureContext*) { return AccessibilityMinRoleTabbableEnabled(); }

  static bool AccessibilityOSLevelBoldTextEnabled() {
    return feature_states_[kAccessibilityOSLevelBoldTextFlagIndex];
  }

  static bool AccessibilityOSLevelBoldTextEnabled(const FeatureContext*) { return AccessibilityOSLevelBoldTextEnabled(); }

  static bool AccessibilityProhibitedNamesEnabled() {
    return feature_states_[kAccessibilityProhibitedNamesFlagIndex];
  }

  static bool AccessibilityProhibitedNamesEnabled(const FeatureContext*) { return AccessibilityProhibitedNamesEnabled(); }

  static bool AccessibilitySerializationSizeMetricsEnabled() {
    return feature_states_[kAccessibilitySerializationSizeMetricsFlagIndex];
  }

  static bool AccessibilitySerializationSizeMetricsEnabled(const FeatureContext*) { return AccessibilitySerializationSizeMetricsEnabled(); }

  static bool AccessibilityUseAXPositionForDocumentMarkersEnabled() {
    return feature_states_[kAccessibilityUseAXPositionForDocumentMarkersFlagIndex];
  }

  static bool AccessibilityUseAXPositionForDocumentMarkersEnabled(const FeatureContext*) { return AccessibilityUseAXPositionForDocumentMarkersEnabled(); }

  static bool AccessKeyLabelEnabled() {
    return feature_states_[kAccessKeyLabelFlagIndex];
  }

  static bool AccessKeyLabelEnabled(const FeatureContext*) { return AccessKeyLabelEnabled(); }

  static bool AddressSpaceEnabled() {
    if (CorsRFC1918Enabled())
      return true;
    return feature_states_[kAddressSpaceFlagIndex];
  }

  static bool AddressSpaceEnabled(const FeatureContext*) { return AddressSpaceEnabled(); }

  static bool AdjustEndOfNextParagraphIfMovedParagraphIsUpdatedEnabled() {
    return feature_states_[kAdjustEndOfNextParagraphIfMovedParagraphIsUpdatedFlagIndex];
  }

  static bool AdjustEndOfNextParagraphIfMovedParagraphIsUpdatedEnabled(const FeatureContext*) { return AdjustEndOfNextParagraphIfMovedParagraphIsUpdatedEnabled(); }

  static bool AdTaggingEnabled() {
    return feature_states_[kAdTaggingFlagIndex];
  }

  static bool AdTaggingEnabled(const FeatureContext*) { return AdTaggingEnabled(); }

  static bool AIClassifierAPIEnabled() {
    return feature_states_[kAIClassifierAPIFlagIndex];
  }

  static bool AIClassifierAPIEnabled(const FeatureContext*) { return AIClassifierAPIEnabled(); }

  static bool AIEmbeddingsAPIEnabled() {
    return feature_states_[kAIEmbeddingsAPIFlagIndex];
  }

  static bool AIEmbeddingsAPIEnabled(const FeatureContext*) { return AIEmbeddingsAPIEnabled(); }

  static bool AIEmbeddingsAPIForWorkersEnabled() {
    return feature_states_[kAIEmbeddingsAPIForWorkersFlagIndex];
  }

  static bool AIEmbeddingsAPIForWorkersEnabled(const FeatureContext*) { return AIEmbeddingsAPIForWorkersEnabled(); }

  static bool AIPageContentAnchoredFixedOffscreenNonActionabilityEnabled() {
    return feature_states_[kAIPageContentAnchoredFixedOffscreenNonActionabilityFlagIndex];
  }

  static bool AIPageContentAnchoredFixedOffscreenNonActionabilityEnabled(const FeatureContext*) { return AIPageContentAnchoredFixedOffscreenNonActionabilityEnabled(); }

  static bool AIPageContentAnchoredNonFixedOffscreenNonActionabilityEnabled() {
    return feature_states_[kAIPageContentAnchoredNonFixedOffscreenNonActionabilityFlagIndex];
  }

  static bool AIPageContentAnchoredNonFixedOffscreenNonActionabilityEnabled(const FeatureContext*) { return AIPageContentAnchoredNonFixedOffscreenNonActionabilityEnabled(); }

  static bool AIPageContentBuildOnLoadForTestingEnabled() {
    return feature_states_[kAIPageContentBuildOnLoadForTestingFlagIndex];
  }

  static bool AIPageContentBuildOnLoadForTestingEnabled(const FeatureContext*) { return AIPageContentBuildOnLoadForTestingEnabled(); }

  static bool AIPageContentCheckGeometryEnabled() {
    return feature_states_[kAIPageContentCheckGeometryFlagIndex];
  }

  static bool AIPageContentCheckGeometryEnabled(const FeatureContext*) { return AIPageContentCheckGeometryEnabled(); }

  static bool AIPageContentConvertNodeTextToUtf8Enabled() {
    return feature_states_[kAIPageContentConvertNodeTextToUtf8FlagIndex];
  }

  static bool AIPageContentConvertNodeTextToUtf8Enabled(const FeatureContext*) { return AIPageContentConvertNodeTextToUtf8Enabled(); }

  static bool AIPageContentElementCSSRedactionEnabled() {
    return feature_states_[kAIPageContentElementCSSRedactionFlagIndex];
  }

  static bool AIPageContentElementCSSRedactionEnabled(const FeatureContext*) { return AIPageContentElementCSSRedactionEnabled(); }

  static bool AIPageContentIncludeSVGSubtreeEnabled() {
    return feature_states_[kAIPageContentIncludeSVGSubtreeFlagIndex];
  }

  static bool AIPageContentIncludeSVGSubtreeEnabled(const FeatureContext*) { return AIPageContentIncludeSVGSubtreeEnabled(); }

  static bool AIPageContentOuterBoxMapToAncestorSpaceEnabled() {
    return feature_states_[kAIPageContentOuterBoxMapToAncestorSpaceFlagIndex];
  }

  static bool AIPageContentOuterBoxMapToAncestorSpaceEnabled(const FeatureContext*) { return AIPageContentOuterBoxMapToAncestorSpaceEnabled(); }

  static bool AIPageContentPaidContentAnnotationEnabled() {
    return feature_states_[kAIPageContentPaidContentAnnotationFlagIndex];
  }

  static bool AIPageContentPaidContentAnnotationEnabled(const FeatureContext*) { return AIPageContentPaidContentAnnotationEnabled(); }

  static bool AIPageContentSkipUnclickableFixedOverlaysEnabled() {
    return feature_states_[kAIPageContentSkipUnclickableFixedOverlaysFlagIndex];
  }

  static bool AIPageContentSkipUnclickableFixedOverlaysEnabled(const FeatureContext*) { return AIPageContentSkipUnclickableFixedOverlaysEnabled(); }

  static bool AIPageContentTrackedElementsIframeEnabled() {
    return feature_states_[kAIPageContentTrackedElementsIframeFlagIndex];
  }

  static bool AIPageContentTrackedElementsIframeEnabled(const FeatureContext*) { return AIPageContentTrackedElementsIframeEnabled(); }

  static bool AIPageContentTrackedElementsPasswordEnabled() {
    return feature_states_[kAIPageContentTrackedElementsPasswordFlagIndex];
  }

  static bool AIPageContentTrackedElementsPasswordEnabled(const FeatureContext*) { return AIPageContentTrackedElementsPasswordEnabled(); }

  static bool AIPageContentVisualViewportClampEnabled() {
    if (AIPageContentBuildOnLoadForTestingEnabled())
      return true;
    return feature_states_[kAIPageContentVisualViewportClampFlagIndex];
  }

  static bool AIPageContentVisualViewportClampEnabled(const FeatureContext*) { return AIPageContentVisualViewportClampEnabled(); }

  static bool AIPromptAPIEnabled() {
    return feature_states_[kAIPromptAPIFlagIndex];
  }

  static bool AIPromptAPIEnabled(const FeatureContext*) { return AIPromptAPIEnabled(); }

  static bool AIPromptAPIForWorkersEnabled() {
    return feature_states_[kAIPromptAPIForWorkersFlagIndex];
  }

  static bool AIPromptAPIForWorkersEnabled(const FeatureContext*) { return AIPromptAPIForWorkersEnabled(); }

  static bool AIPromptAPILegacyIdentifiersEnabled() {
    return feature_states_[kAIPromptAPILegacyIdentifiersFlagIndex];
  }

  static bool AIPromptAPILegacyIdentifiersEnabled(const FeatureContext*) { return AIPromptAPILegacyIdentifiersEnabled(); }

  static bool AIPromptAPILegacyParamsEnabled() {
    return feature_states_[kAIPromptAPILegacyParamsFlagIndex];
  }

  static bool AIPromptAPILegacyParamsEnabled(const FeatureContext*) { return AIPromptAPILegacyParamsEnabled(); }

  static bool AIPromptAPIMultimodalInputEnabled() {
    return feature_states_[kAIPromptAPIMultimodalInputFlagIndex];
  }

  static bool AIPromptAPIMultimodalInputEnabled(const FeatureContext*) { return AIPromptAPIMultimodalInputEnabled(); }

  static bool AIPromptAPIStructuredOutputEnabled() {
    return feature_states_[kAIPromptAPIStructuredOutputFlagIndex];
  }

  static bool AIPromptAPIStructuredOutputEnabled(const FeatureContext*) { return AIPromptAPIStructuredOutputEnabled(); }

  static bool AIPromptAPIToolUseEnabled() {
    return feature_states_[kAIPromptAPIToolUseFlagIndex];
  }

  static bool AIPromptAPIToolUseEnabled(const FeatureContext*) { return AIPromptAPIToolUseEnabled(); }

  static bool AIRewriterAPIForWorkersEnabled() {
    return feature_states_[kAIRewriterAPIForWorkersFlagIndex];
  }

  static bool AIRewriterAPIForWorkersEnabled(const FeatureContext*) { return AIRewriterAPIForWorkersEnabled(); }

  static bool AISummarizationAPIEnabled() {
    return feature_states_[kAISummarizationAPIFlagIndex];
  }

  static bool AISummarizationAPIEnabled(const FeatureContext*) { return AISummarizationAPIEnabled(); }

  static bool AISummarizationAPIForWorkersEnabled() {
    return feature_states_[kAISummarizationAPIForWorkersFlagIndex];
  }

  static bool AISummarizationAPIForWorkersEnabled(const FeatureContext*) { return AISummarizationAPIForWorkersEnabled(); }

  static bool AISummarizationPerformancePreferenceEnabled() {
    return feature_states_[kAISummarizationPerformancePreferenceFlagIndex];
  }

  static bool AISummarizationPerformancePreferenceEnabled(const FeatureContext*) { return AISummarizationPerformancePreferenceEnabled(); }

  static bool AIWriterAPIForWorkersEnabled() {
    return feature_states_[kAIWriterAPIForWorkersFlagIndex];
  }

  static bool AIWriterAPIForWorkersEnabled(const FeatureContext*) { return AIWriterAPIForWorkersEnabled(); }

  static bool AlignZoomToCenterEnabled() {
    return feature_states_[kAlignZoomToCenterFlagIndex];
  }

  static bool AlignZoomToCenterEnabled(const FeatureContext*) { return AlignZoomToCenterEnabled(); }

  static bool AllImagesPaintedSentToElementTimingEnabled() {
    return feature_states_[kAllImagesPaintedSentToElementTimingFlagIndex];
  }

  static bool AllImagesPaintedSentToElementTimingEnabled(const FeatureContext*) { return AllImagesPaintedSentToElementTimingEnabled(); }

  static bool AllowContentInitiatedDataUrlNavigationsEnabled() {
    return feature_states_[kAllowContentInitiatedDataUrlNavigationsFlagIndex];
  }

  static bool AllowContentInitiatedDataUrlNavigationsEnabled(const FeatureContext*) { return AllowContentInitiatedDataUrlNavigationsEnabled(); }

  static bool AllowPreloadingWithCSPMetaTagEnabled() {
    return feature_states_[kAllowPreloadingWithCSPMetaTagFlagIndex];
  }

  static bool AllowPreloadingWithCSPMetaTagEnabled(const FeatureContext*) { return AllowPreloadingWithCSPMetaTagEnabled(); }

  static bool AllowSameSiteNoneCookiesInSandboxEnabled() {
    return feature_states_[kAllowSameSiteNoneCookiesInSandboxFlagIndex];
  }

  static bool AllowSameSiteNoneCookiesInSandboxEnabled(const FeatureContext*) { return AllowSameSiteNoneCookiesInSandboxEnabled(); }

  static bool AllowSvgUseToReferenceExternalDocumentRootEnabled() {
    return feature_states_[kAllowSvgUseToReferenceExternalDocumentRootFlagIndex];
  }

  static bool AllowSvgUseToReferenceExternalDocumentRootEnabled(const FeatureContext*) { return AllowSvgUseToReferenceExternalDocumentRootEnabled(); }

  static bool AllowSyntheticTimingForCanvasCaptureEnabled() {
    return feature_states_[kAllowSyntheticTimingForCanvasCaptureFlagIndex];
  }

  static bool AllowSyntheticTimingForCanvasCaptureEnabled(const FeatureContext*) { return AllowSyntheticTimingForCanvasCaptureEnabled(); }

  static bool AllowURNsInIframesEnabled() {
    return feature_states_[kAllowURNsInIframesFlagIndex];
  }

  static bool AllowURNsInIframesEnabled(const FeatureContext*) { return AllowURNsInIframesEnabled(); }

  static bool AncestorOriginsStoredOnDocumentEnabled() {
    return feature_states_[kAncestorOriginsStoredOnDocumentFlagIndex];
  }

  static bool AncestorOriginsStoredOnDocumentEnabled(const FeatureContext*) { return AncestorOriginsStoredOnDocumentEnabled(); }

  static bool AnchorPositionAdjustmentWithoutOverflowEnabled() {
    return feature_states_[kAnchorPositionAdjustmentWithoutOverflowFlagIndex];
  }

  static bool AnchorPositionAdjustmentWithoutOverflowEnabled(const FeatureContext*) { return AnchorPositionAdjustmentWithoutOverflowEnabled(); }

  static bool AndroidDownloadableFontsMatchingEnabled() {
    return feature_states_[kAndroidDownloadableFontsMatchingFlagIndex];
  }

  static bool AndroidDownloadableFontsMatchingEnabled(const FeatureContext*) { return AndroidDownloadableFontsMatchingEnabled(); }

  static bool AnimationEventAnimationEnabled() {
    return feature_states_[kAnimationEventAnimationFlagIndex];
  }

  static bool AnimationEventAnimationEnabled(const FeatureContext*) { return AnimationEventAnimationEnabled(); }

  static bool AnimationProgressAPIEnabled() {
    return feature_states_[kAnimationProgressAPIFlagIndex];
  }

  static bool AnimationProgressAPIEnabled(const FeatureContext*) { return AnimationProgressAPIEnabled(); }

  static bool AnimationRangeRejectRelativeLengthsEnabled() {
    return feature_states_[kAnimationRangeRejectRelativeLengthsFlagIndex];
  }

  static bool AnimationRangeRejectRelativeLengthsEnabled(const FeatureContext*) { return AnimationRangeRejectRelativeLengthsEnabled(); }

  static bool AnimationTriggerEnabled() {
    if (EventTriggerEnabled())
      return true;
    if (TimelineTriggerEnabled())
      return true;
    return feature_states_[kAnimationTriggerFlagIndex];
  }

  static bool AnimationTriggerEnabled(const FeatureContext*) { return AnimationTriggerEnabled(); }

  static bool AnimationWorkletEnabled() {
    return feature_states_[kAnimationWorkletFlagIndex];
  }

  static bool AnimationWorkletEnabled(const FeatureContext*) { return AnimationWorkletEnabled(); }

  static bool AnnotationSpaceForMultiColEnabled() {
    if (!AnnotationSpaceOnStartEnabled())
      return false;
    return feature_states_[kAnnotationSpaceForMultiColFlagIndex];
  }

  static bool AnnotationSpaceForMultiColEnabled(const FeatureContext*) { return AnnotationSpaceForMultiColEnabled(); }

  static bool AnnotationSpaceOnStartEnabled() {
    return feature_states_[kAnnotationSpaceOnStartFlagIndex];
  }

  static bool AnnotationSpaceOnStartEnabled(const FeatureContext*) { return AnnotationSpaceOnStartEnabled(); }

  static bool AnonymousIframeEnabled() {
    return feature_states_[kAnonymousIframeFlagIndex];
  }

  static bool AnonymousIframeEnabled(const FeatureContext*) { return AnonymousIframeEnabled(); }

  static bool AOMAriaRelationshipPropertiesEnabled() {
    return feature_states_[kAOMAriaRelationshipPropertiesFlagIndex];
  }

  static bool AOMAriaRelationshipPropertiesEnabled(const FeatureContext*) { return AOMAriaRelationshipPropertiesEnabled(); }

  static bool AOMAriaRelationshipPropertiesAriaOwnsEnabled() {
    if (!AOMAriaRelationshipPropertiesEnabled())
      return false;
    return feature_states_[kAOMAriaRelationshipPropertiesAriaOwnsFlagIndex];
  }

  static bool AOMAriaRelationshipPropertiesAriaOwnsEnabled(const FeatureContext*) { return AOMAriaRelationshipPropertiesAriaOwnsEnabled(); }

  static bool AppearanceBaseEnabled() {
    return feature_states_[kAppearanceBaseFlagIndex];
  }

  static bool AppearanceBaseEnabled(const FeatureContext*) { return AppearanceBaseEnabled(); }

  static bool ApproximateGeolocationPermissionEnabled() {
    return feature_states_[kApproximateGeolocationPermissionFlagIndex];
  }

  static bool ApproximateGeolocationPermissionEnabled(const FeatureContext*) { return ApproximateGeolocationPermissionEnabled(); }

  static bool ApproximateGeolocationPermissionAccuracyModeEnabled() {
    if (!ApproximateGeolocationPermissionEnabled())
      return false;
    return feature_states_[kApproximateGeolocationPermissionAccuracyModeFlagIndex];
  }

  static bool ApproximateGeolocationPermissionAccuracyModeEnabled(const FeatureContext*) { return ApproximateGeolocationPermissionAccuracyModeEnabled(); }

  static bool ApproximateGeolocationPermissionAPIEnabled() {
    if (!ApproximateGeolocationPermissionEnabled())
      return false;
    return feature_states_[kApproximateGeolocationPermissionAPIFlagIndex];
  }

  static bool ApproximateGeolocationPermissionAPIEnabled(const FeatureContext*) { return ApproximateGeolocationPermissionAPIEnabled(); }

  static bool ApproximateGeolocationWebVisibleAPIEnabled() {
    if (!ApproximateGeolocationPermissionEnabled())
      return false;
    return feature_states_[kApproximateGeolocationWebVisibleAPIFlagIndex];
  }

  static bool ApproximateGeolocationWebVisibleAPIEnabled(const FeatureContext*) { return ApproximateGeolocationWebVisibleAPIEnabled(); }

  static bool AriaActionsEnabled() {
    return feature_states_[kAriaActionsFlagIndex];
  }

  static bool AriaActionsEnabled(const FeatureContext*) { return AriaActionsEnabled(); }

  static bool AriaNotifyEnabled() {
    if (AriaNotifyV2Enabled())
      return true;
    return feature_states_[kAriaNotifyFlagIndex];
  }

  static bool AriaNotifyEnabled(const FeatureContext*) { return AriaNotifyEnabled(); }

  static bool AriaNotifyV2Enabled() {
    return feature_states_[kAriaNotifyV2FlagIndex];
  }

  static bool AriaNotifyV2Enabled(const FeatureContext*) { return AriaNotifyV2Enabled(); }

  static bool AriaRowColIndexTextEnabled() {
    return feature_states_[kAriaRowColIndexTextFlagIndex];
  }

  static bool AriaRowColIndexTextEnabled(const FeatureContext*) { return AriaRowColIndexTextEnabled(); }

  static bool AttributionReportingEnabled() {
    return feature_states_[kAttributionReportingFlagIndex];
  }

  static bool AttributionReportingEnabled(const FeatureContext*) { return AttributionReportingEnabled(); }

  static bool AudioContextAsyncStateTransitionsEnabled() {
    return feature_states_[kAudioContextAsyncStateTransitionsFlagIndex];
  }

  static bool AudioContextAsyncStateTransitionsEnabled(const FeatureContext*) { return AudioContextAsyncStateTransitionsEnabled(); }

  static bool AudioContextPlaybackStatsEnabled() {
    return feature_states_[kAudioContextPlaybackStatsFlagIndex];
  }

  static bool AudioContextPlaybackStatsEnabled(const FeatureContext*) { return AudioContextPlaybackStatsEnabled(); }

  static bool AudioContextSetSinkIdEnabled() {
    return feature_states_[kAudioContextSetSinkIdFlagIndex];
  }

  static bool AudioContextSetSinkIdEnabled(const FeatureContext*) { return AudioContextSetSinkIdEnabled(); }

  static bool AudioOutputDevicesEnabled() {
    return feature_states_[kAudioOutputDevicesFlagIndex];
  }

  static bool AudioOutputDevicesEnabled(const FeatureContext*) { return AudioOutputDevicesEnabled(); }

  static bool AudioVideoTracksEnabled() {
    return feature_states_[kAudioVideoTracksFlagIndex];
  }

  static bool AudioVideoTracksEnabled(const FeatureContext*) { return AudioVideoTracksEnabled(); }

  static bool AudioWorkletSharedPortEnabled() {
    return feature_states_[kAudioWorkletSharedPortFlagIndex];
  }

  static bool AudioWorkletSharedPortEnabled(const FeatureContext*) { return AudioWorkletSharedPortEnabled(); }

  static bool AuthorSpecifiedLayoutScrollSnapBehaviorEnabled() {
    return feature_states_[kAuthorSpecifiedLayoutScrollSnapBehaviorFlagIndex];
  }

  static bool AuthorSpecifiedLayoutScrollSnapBehaviorEnabled(const FeatureContext*) { return AuthorSpecifiedLayoutScrollSnapBehaviorEnabled(); }

  static bool AutoDarkModeEnabled() {
    return feature_states_[kAutoDarkModeFlagIndex];
  }

  static bool AutoDarkModeEnabled(const FeatureContext*) { return AutoDarkModeEnabled(); }

  static bool AutoDarkModeSkipImagesEnabled() {
    return feature_states_[kAutoDarkModeSkipImagesFlagIndex];
  }

  static bool AutoDarkModeSkipImagesEnabled(const FeatureContext*) { return AutoDarkModeSkipImagesEnabled(); }

  static bool AutoDarkModeSVGSizeThresholdEnabled() {
    return feature_states_[kAutoDarkModeSVGSizeThresholdFlagIndex];
  }

  static bool AutoDarkModeSVGSizeThresholdEnabled(const FeatureContext*) { return AutoDarkModeSVGSizeThresholdEnabled(); }

  static bool AutofillEnabled() {
    return feature_states_[kAutofillFlagIndex];
  }

  static bool AutofillEnabled(const FeatureContext*) { return AutofillEnabled(); }

  static bool AutofillPreviewGenericFontFamilyEnabled() {
    return feature_states_[kAutofillPreviewGenericFontFamilyFlagIndex];
  }

  static bool AutofillPreviewGenericFontFamilyEnabled(const FeatureContext*) { return AutofillPreviewGenericFontFamilyEnabled(); }

  static bool AutofillPreviewIgnoreAuthorFontEnabled() {
    return feature_states_[kAutofillPreviewIgnoreAuthorFontFlagIndex];
  }

  static bool AutofillPreviewIgnoreAuthorFontEnabled(const FeatureContext*) { return AutofillPreviewIgnoreAuthorFontEnabled(); }

  static bool AutomationControlledEnabled() {
    return feature_states_[kAutomationControlledFlagIndex];
  }

  static bool AutomationControlledEnabled(const FeatureContext*) { return AutomationControlledEnabled(); }

  static bool AutoPictureInPictureVideoHeuristicsEnabled() {
    return feature_states_[kAutoPictureInPictureVideoHeuristicsFlagIndex];
  }

  static bool AutoPictureInPictureVideoHeuristicsEnabled(const FeatureContext*) { return AutoPictureInPictureVideoHeuristicsEnabled(); }

  static bool AutoSizeUsesScrollWidthForOverflowEnabled() {
    return feature_states_[kAutoSizeUsesScrollWidthForOverflowFlagIndex];
  }

  static bool AutoSizeUsesScrollWidthForOverflowEnabled(const FeatureContext*) { return AutoSizeUsesScrollWidthForOverflowEnabled(); }

  static bool AvoidEmbeddedContentViewLocationEnabled() {
    return feature_states_[kAvoidEmbeddedContentViewLocationFlagIndex];
  }

  static bool AvoidEmbeddedContentViewLocationEnabled(const FeatureContext*) { return AvoidEmbeddedContentViewLocationEnabled(); }

  static bool AvoidNonSelectableSelectionBoundaryEnabled() {
    return feature_states_[kAvoidNonSelectableSelectionBoundaryFlagIndex];
  }

  static bool AvoidNonSelectableSelectionBoundaryEnabled(const FeatureContext*) { return AvoidNonSelectableSelectionBoundaryEnabled(); }

  static bool AvoidSynchronousBlurOnDisabledAttributeChangeEnabled() {
    return feature_states_[kAvoidSynchronousBlurOnDisabledAttributeChangeFlagIndex];
  }

  static bool AvoidSynchronousBlurOnDisabledAttributeChangeEnabled(const FeatureContext*) { return AvoidSynchronousBlurOnDisabledAttributeChangeEnabled(); }

  static bool BackfaceVisibilityInteropEnabled() {
    return feature_states_[kBackfaceVisibilityInteropFlagIndex];
  }

  static bool BackfaceVisibilityInteropEnabled(const FeatureContext*) { return BackfaceVisibilityInteropEnabled(); }

  static bool BackForwardCacheEnabled() {
    return feature_states_[kBackForwardCacheFlagIndex];
  }

  static bool BackForwardCacheEnabled(const FeatureContext*) { return BackForwardCacheEnabled(); }

  static bool BackForwardCacheRestorationPerformanceEntryEnabled() {
    return feature_states_[kBackForwardCacheRestorationPerformanceEntryFlagIndex];
  }

  static bool BackForwardCacheRestorationPerformanceEntryEnabled(const FeatureContext*) { return BackForwardCacheRestorationPerformanceEntryEnabled(); }

  static bool BackForwardCacheUpdateNotRestoredReasonsNameEnabled() {
    return feature_states_[kBackForwardCacheUpdateNotRestoredReasonsNameFlagIndex];
  }

  static bool BackForwardCacheUpdateNotRestoredReasonsNameEnabled(const FeatureContext*) { return BackForwardCacheUpdateNotRestoredReasonsNameEnabled(); }

  static bool BackgroundClipTextDecorationEnabled() {
    return feature_states_[kBackgroundClipTextDecorationFlagIndex];
  }

  static bool BackgroundClipTextDecorationEnabled(const FeatureContext*) { return BackgroundClipTextDecorationEnabled(); }

  static bool BackgroundFetchEnabled() {
    return feature_states_[kBackgroundFetchFlagIndex];
  }

  static bool BackgroundFetchEnabled(const FeatureContext*) { return BackgroundFetchEnabled(); }

  static bool BarcodeDetectorEnabled() {
    return feature_states_[kBarcodeDetectorFlagIndex];
  }

  static bool BarcodeDetectorEnabled(const FeatureContext*) { return BarcodeDetectorEnabled(); }

  static bool BaseAppearanceInlineSizingEnabled() {
    return feature_states_[kBaseAppearanceInlineSizingFlagIndex];
  }

  static bool BaseAppearanceInlineSizingEnabled(const FeatureContext*) { return BaseAppearanceInlineSizingEnabled(); }

  static bool BasicShapeCornerRadiusEnabled() {
    return feature_states_[kBasicShapeCornerRadiusFlagIndex];
  }

  static bool BasicShapeCornerRadiusEnabled(const FeatureContext*) { return BasicShapeCornerRadiusEnabled(); }

  static bool BidiCaretAffinityEnabled() {
    return feature_states_[kBidiCaretAffinityFlagIndex];
  }

  static bool BidiCaretAffinityEnabled(const FeatureContext*) { return BidiCaretAffinityEnabled(); }

  static bool BidiVisualOrderCaretMovementEnabled() {
    if (!BidiCaretAffinityEnabled())
      return false;
    return feature_states_[kBidiVisualOrderCaretMovementFlagIndex];
  }

  static bool BidiVisualOrderCaretMovementEnabled(const FeatureContext*) { return BidiVisualOrderCaretMovementEnabled(); }

  static bool BlinkExtensionWebViewEnabled() {
    return feature_states_[kBlinkExtensionWebViewFlagIndex];
  }

  static bool BlinkExtensionWebViewEnabled(const FeatureContext*) { return BlinkExtensionWebViewEnabled(); }

  static bool BlinkExtensionWebViewMediaIntegrityEnabled() {
    return feature_states_[kBlinkExtensionWebViewMediaIntegrityFlagIndex];
  }

  static bool BlinkExtensionWebViewMediaIntegrityEnabled(const FeatureContext*) { return BlinkExtensionWebViewMediaIntegrityEnabled(); }

  static bool BlinkGeometryMapperViewportFastPathEnabled() {
    return feature_states_[kBlinkGeometryMapperViewportFastPathFlagIndex];
  }

  static bool BlinkGeometryMapperViewportFastPathEnabled(const FeatureContext*) { return BlinkGeometryMapperViewportFastPathEnabled(); }

  static bool BlinkLifecycleScriptForbiddenEnabled() {
    return feature_states_[kBlinkLifecycleScriptForbiddenFlagIndex];
  }

  static bool BlinkLifecycleScriptForbiddenEnabled(const FeatureContext*) { return BlinkLifecycleScriptForbiddenEnabled(); }

  static bool BlinkRuntimeCallStatsEnabled() {
    return feature_states_[kBlinkRuntimeCallStatsFlagIndex];
  }

  static bool BlinkRuntimeCallStatsEnabled(const FeatureContext*) { return BlinkRuntimeCallStatsEnabled(); }

  static bool BlobBytesEnabled() {
    return feature_states_[kBlobBytesFlagIndex];
  }

  static bool BlobBytesEnabled(const FeatureContext*) { return BlobBytesEnabled(); }

  static bool BlockSelectPopupUnfocusedWindowEnabled() {
    return feature_states_[kBlockSelectPopupUnfocusedWindowFlagIndex];
  }

  static bool BlockSelectPopupUnfocusedWindowEnabled(const FeatureContext*) { return BlockSelectPopupUnfocusedWindowEnabled(); }

  static bool BoundaryEventDispatchTracksNodeRemovalEnabled() {
    return feature_states_[kBoundaryEventDispatchTracksNodeRemovalFlagIndex];
  }

  static bool BoundaryEventDispatchTracksNodeRemovalEnabled(const FeatureContext*) { return BoundaryEventDispatchTracksNodeRemovalEnabled(); }

  static bool BoxDecorationBreakCloneLineBreakingEnabled() {
    return feature_states_[kBoxDecorationBreakCloneLineBreakingFlagIndex];
  }

  static bool BoxDecorationBreakCloneLineBreakingEnabled(const FeatureContext*) { return BoxDecorationBreakCloneLineBreakingEnabled(); }

  static bool BrowserInitiatedAutomaticPictureInPictureEnabled() {
    return feature_states_[kBrowserInitiatedAutomaticPictureInPictureFlagIndex];
  }

  static bool BrowserInitiatedAutomaticPictureInPictureEnabled(const FeatureContext*) { return BrowserInitiatedAutomaticPictureInPictureEnabled(); }

  static bool BufferedBytesConsumerLimitSizeEnabled() {
    return feature_states_[kBufferedBytesConsumerLimitSizeFlagIndex];
  }

  static bool BufferedBytesConsumerLimitSizeEnabled(const FeatureContext*) { return BufferedBytesConsumerLimitSizeEnabled(); }

  static bool BypassPepcSecurityForTestingEnabled() {
    return feature_states_[kBypassPepcSecurityForTestingFlagIndex];
  }

  static bool BypassPepcSecurityForTestingEnabled(const FeatureContext*) { return BypassPepcSecurityForTestingEnabled(); }

  static bool CacheControlRFC7234ParsingEnabled() {
    return feature_states_[kCacheControlRFC7234ParsingFlagIndex];
  }

  static bool CacheControlRFC7234ParsingEnabled(const FeatureContext*) { return CacheControlRFC7234ParsingEnabled(); }

  static bool CacheControlRFC7234ParsingMetricsEnabled() {
    return feature_states_[kCacheControlRFC7234ParsingMetricsFlagIndex];
  }

  static bool CacheControlRFC7234ParsingMetricsEnabled(const FeatureContext*) { return CacheControlRFC7234ParsingMetricsEnabled(); }

  static bool CacheStyleAdjusterEnabled() {
    return feature_states_[kCacheStyleAdjusterFlagIndex];
  }

  static bool CacheStyleAdjusterEnabled(const FeatureContext*) { return CacheStyleAdjusterEnabled(); }

  static bool CameraAndMicrophoneElementsEnabled() {
    return feature_states_[kCameraAndMicrophoneElementsFlagIndex];
  }

  static bool CameraAndMicrophoneElementsEnabled(const FeatureContext*) { return CameraAndMicrophoneElementsEnabled(); }

  static bool Canvas2dCanvasFilterEnabled() {
    return feature_states_[kCanvas2dCanvasFilterFlagIndex];
  }

  static bool Canvas2dCanvasFilterEnabled(const FeatureContext*) { return Canvas2dCanvasFilterEnabled(); }

  static bool Canvas2dDeferredFlushEnabled() {
    return feature_states_[kCanvas2dDeferredFlushFlagIndex];
  }

  static bool Canvas2dDeferredFlushEnabled(const FeatureContext*) { return Canvas2dDeferredFlushEnabled(); }

  static bool Canvas2dLayersEnabled() {
    return feature_states_[kCanvas2dLayersFlagIndex];
  }

  static bool Canvas2dLayersEnabled(const FeatureContext*) { return Canvas2dLayersEnabled(); }

  static bool Canvas2dLayersWithOptionsEnabled() {
    if (!Canvas2dLayersEnabled())
      return false;
    return feature_states_[kCanvas2dLayersWithOptionsFlagIndex];
  }

  static bool Canvas2dLayersWithOptionsEnabled(const FeatureContext*) { return Canvas2dLayersWithOptionsEnabled(); }

  static bool CanvasFloatingPointEnabled() {
    return feature_states_[kCanvasFloatingPointFlagIndex];
  }

  static bool CanvasFloatingPointEnabled(const FeatureContext*) { return CanvasFloatingPointEnabled(); }

  static bool CanvasGlobalHDRHeadroomEnabled() {
    return feature_states_[kCanvasGlobalHDRHeadroomFlagIndex];
  }

  static bool CanvasGlobalHDRHeadroomEnabled(const FeatureContext*) { return CanvasGlobalHDRHeadroomEnabled(); }

  static bool CanvasGradientCSSColor4Enabled() {
    return feature_states_[kCanvasGradientCSSColor4FlagIndex];
  }

  static bool CanvasGradientCSSColor4Enabled(const FeatureContext*) { return CanvasGradientCSSColor4Enabled(); }

  static bool CanvasHDREnabled() {
    return feature_states_[kCanvasHDRFlagIndex];
  }

  static bool CanvasHDREnabled(const FeatureContext*) { return CanvasHDREnabled(); }

  static bool CanvasTextMetricsPreciseBoundsEnabled() {
    return feature_states_[kCanvasTextMetricsPreciseBoundsFlagIndex];
  }

  static bool CanvasTextMetricsPreciseBoundsEnabled(const FeatureContext*) { return CanvasTextMetricsPreciseBoundsEnabled(); }

  static bool CanvasToneMappingEnabled() {
    return feature_states_[kCanvasToneMappingFlagIndex];
  }

  static bool CanvasToneMappingEnabled(const FeatureContext*) { return CanvasToneMappingEnabled(); }

  static bool CanvasUsesArcPaintOpEnabled() {
    return feature_states_[kCanvasUsesArcPaintOpFlagIndex];
  }

  static bool CanvasUsesArcPaintOpEnabled(const FeatureContext*) { return CanvasUsesArcPaintOpEnabled(); }

  static bool CapabilityDelegationDigitalCredentialsEnabled() {
    return feature_states_[kCapabilityDelegationDigitalCredentialsFlagIndex];
  }

  static bool CapabilityDelegationDigitalCredentialsEnabled(const FeatureContext*) { return CapabilityDelegationDigitalCredentialsEnabled(); }

  static bool CapabilityDelegationDisplayCaptureRequestEnabled() {
    return feature_states_[kCapabilityDelegationDisplayCaptureRequestFlagIndex];
  }

  static bool CapabilityDelegationDisplayCaptureRequestEnabled(const FeatureContext*) { return CapabilityDelegationDisplayCaptureRequestEnabled(); }

  static bool CaptureControllerEnabled() {
    return feature_states_[kCaptureControllerFlagIndex];
  }

  static bool CaptureControllerEnabled(const FeatureContext*) { return CaptureControllerEnabled(); }

  static bool CapturedMouseEventsEnabled() {
    if (!CaptureControllerEnabled())
      return false;
    return feature_states_[kCapturedMouseEventsFlagIndex];
  }

  static bool CapturedMouseEventsEnabled(const FeatureContext*) { return CapturedMouseEventsEnabled(); }

  static bool CapturedSurfaceControlEnabled() {
    return feature_states_[kCapturedSurfaceControlFlagIndex];
  }

  static bool CapturedSurfaceControlEnabled(const FeatureContext*) { return CapturedSurfaceControlEnabled(); }

  static bool CapturedSurfaceResolutionEnabled() {
    return feature_states_[kCapturedSurfaceResolutionFlagIndex];
  }

  static bool CapturedSurfaceResolutionEnabled(const FeatureContext*) { return CapturedSurfaceResolutionEnabled(); }

  static bool CaptureHandleEnabled() {
    if (!GetDisplayMediaEnabled())
      return false;
    return feature_states_[kCaptureHandleFlagIndex];
  }

  static bool CaptureHandleEnabled(const FeatureContext*) { return CaptureHandleEnabled(); }

  static bool CaretOutsideEditableAtomicInlineEnabled() {
    return feature_states_[kCaretOutsideEditableAtomicInlineFlagIndex];
  }

  static bool CaretOutsideEditableAtomicInlineEnabled(const FeatureContext*) { return CaretOutsideEditableAtomicInlineEnabled(); }

  static bool CCTNewRFMPushBehaviorEnabled() {
    return feature_states_[kCCTNewRFMPushBehaviorFlagIndex];
  }

  static bool CCTNewRFMPushBehaviorEnabled(const FeatureContext*) { return CCTNewRFMPushBehaviorEnabled(); }

  static bool CDTNewCrossOriginHandlingEnabled() {
    return feature_states_[kCDTNewCrossOriginHandlingFlagIndex];
  }

  static bool CDTNewCrossOriginHandlingEnabled(const FeatureContext*) { return CDTNewCrossOriginHandlingEnabled(); }

  static bool CDTNewDestinationEnabled() {
    return feature_states_[kCDTNewDestinationFlagIndex];
  }

  static bool CDTNewDestinationEnabled(const FeatureContext*) { return CDTNewDestinationEnabled(); }

  static bool CDTNewReferrerAndReferrerPolicyHandlingEnabled() {
    return feature_states_[kCDTNewReferrerAndReferrerPolicyHandlingFlagIndex];
  }

  static bool CDTNewReferrerAndReferrerPolicyHandlingEnabled(const FeatureContext*) { return CDTNewReferrerAndReferrerPolicyHandlingEnabled(); }

  static bool CheckableInputTypeLayoutInlineEnabled() {
    return feature_states_[kCheckableInputTypeLayoutInlineFlagIndex];
  }

  static bool CheckableInputTypeLayoutInlineEnabled(const FeatureContext*) { return CheckableInputTypeLayoutInlineEnabled(); }

  static bool CheckVisibilityExtraPropertiesEnabled() {
    return feature_states_[kCheckVisibilityExtraPropertiesFlagIndex];
  }

  static bool CheckVisibilityExtraPropertiesEnabled(const FeatureContext*) { return CheckVisibilityExtraPropertiesEnabled(); }

  static bool ClampUnfocusedSelectionCacheEnabled() {
    return feature_states_[kClampUnfocusedSelectionCacheFlagIndex];
  }

  static bool ClampUnfocusedSelectionCacheEnabled(const FeatureContext*) { return ClampUnfocusedSelectionCacheEnabled(); }

  static bool CleanUpActivationBehaviorEnabled() {
    return feature_states_[kCleanUpActivationBehaviorFlagIndex];
  }

  static bool CleanUpActivationBehaviorEnabled(const FeatureContext*) { return CleanUpActivationBehaviorEnabled(); }

  static bool ClearCurrentTargetAfterDispatchEnabled() {
    return feature_states_[kClearCurrentTargetAfterDispatchFlagIndex];
  }

  static bool ClearCurrentTargetAfterDispatchEnabled(const FeatureContext*) { return ClearCurrentTargetAfterDispatchEnabled(); }

  static bool ClearDisplayLockPrePaintFlagsEnabled() {
    return feature_states_[kClearDisplayLockPrePaintFlagsFlagIndex];
  }

  static bool ClearDisplayLockPrePaintFlagsEnabled(const FeatureContext*) { return ClearDisplayLockPrePaintFlagsEnabled(); }

  static bool ClearFocusWithinOnSubtreeRemovalEnabled() {
    return feature_states_[kClearFocusWithinOnSubtreeRemovalFlagIndex];
  }

  static bool ClearFocusWithinOnSubtreeRemovalEnabled(const FeatureContext*) { return ClearFocusWithinOnSubtreeRemovalEnabled(); }

  static bool ClearTargetOnlyIfInShadowTreeEnabled() {
    return feature_states_[kClearTargetOnlyIfInShadowTreeFlagIndex];
  }

  static bool ClearTargetOnlyIfInShadowTreeEnabled(const FeatureContext*) { return ClearTargetOnlyIfInShadowTreeEnabled(); }

  static bool ClipboardEventTargetUsesContainerNodeEnabled() {
    return feature_states_[kClipboardEventTargetUsesContainerNodeFlagIndex];
  }

  static bool ClipboardEventTargetUsesContainerNodeEnabled(const FeatureContext*) { return ClipboardEventTargetUsesContainerNodeEnabled(); }

  static bool ClipboardPasteImageRespectBufferEnabled() {
    return feature_states_[kClipboardPasteImageRespectBufferFlagIndex];
  }

  static bool ClipboardPasteImageRespectBufferEnabled(const FeatureContext*) { return ClipboardPasteImageRespectBufferEnabled(); }

  static bool ClipElementVisibleBoundsInLocalRootEnabled() {
    return feature_states_[kClipElementVisibleBoundsInLocalRootFlagIndex];
  }

  static bool ClipElementVisibleBoundsInLocalRootEnabled(const FeatureContext*) { return ClipElementVisibleBoundsInLocalRootEnabled(); }

  static bool ClipPathNestedRasterOptimizationEnabled() {
    return feature_states_[kClipPathNestedRasterOptimizationFlagIndex];
  }

  static bool ClipPathNestedRasterOptimizationEnabled(const FeatureContext*) { return ClipPathNestedRasterOptimizationEnabled(); }

  static bool CoalesceSelectionchangeEventEnabled() {
    return feature_states_[kCoalesceSelectionchangeEventFlagIndex];
  }

  static bool CoalesceSelectionchangeEventEnabled(const FeatureContext*) { return CoalesceSelectionchangeEventEnabled(); }

  static bool CoepReflectionEnabled() {
    return feature_states_[kCoepReflectionFlagIndex];
  }

  static bool CoepReflectionEnabled(const FeatureContext*) { return CoepReflectionEnabled(); }

  static bool ColorInputAcceptsCSSColorsEnabled() {
    return feature_states_[kColorInputAcceptsCSSColorsFlagIndex];
  }

  static bool ColorInputAcceptsCSSColorsEnabled(const FeatureContext*) { return ColorInputAcceptsCSSColorsEnabled(); }

  static bool ColorSpaceDisplayP3LinearEnabled() {
    return feature_states_[kColorSpaceDisplayP3LinearFlagIndex];
  }

  static bool ColorSpaceDisplayP3LinearEnabled(const FeatureContext*) { return ColorSpaceDisplayP3LinearEnabled(); }

  static bool ColorSpacePredefinedLinearSpacesEnabled() {
    return feature_states_[kColorSpacePredefinedLinearSpacesFlagIndex];
  }

  static bool ColorSpacePredefinedLinearSpacesEnabled(const FeatureContext*) { return ColorSpacePredefinedLinearSpacesEnabled(); }

  static bool ColorSpaceRec2100LinearEnabled() {
    return feature_states_[kColorSpaceRec2100LinearFlagIndex];
  }

  static bool ColorSpaceRec2100LinearEnabled(const FeatureContext*) { return ColorSpaceRec2100LinearEnabled(); }

  static bool CommaSeparatedContainerQueriesEnabled() {
    return feature_states_[kCommaSeparatedContainerQueriesFlagIndex];
  }

  static bool CommaSeparatedContainerQueriesEnabled(const FeatureContext*) { return CommaSeparatedContainerQueriesEnabled(); }

  static bool ComposedPathReturnTargetBeingDispatchedEnabled() {
    return feature_states_[kComposedPathReturnTargetBeingDispatchedFlagIndex];
  }

  static bool ComposedPathReturnTargetBeingDispatchedEnabled(const FeatureContext*) { return ComposedPathReturnTargetBeingDispatchedEnabled(); }

  static bool CompositeBGColorAnimationEnabled() {
    return feature_states_[kCompositeBGColorAnimationFlagIndex];
  }

  static bool CompositeBGColorAnimationEnabled(const FeatureContext*) { return CompositeBGColorAnimationEnabled(); }

  static bool CompositeBoxShadowAnimationEnabled() {
    return feature_states_[kCompositeBoxShadowAnimationFlagIndex];
  }

  static bool CompositeBoxShadowAnimationEnabled(const FeatureContext*) { return CompositeBoxShadowAnimationEnabled(); }

  static bool CompositeClipPathAnimationEnabled() {
    return feature_states_[kCompositeClipPathAnimationFlagIndex];
  }

  static bool CompositeClipPathAnimationEnabled(const FeatureContext*) { return CompositeClipPathAnimationEnabled(); }

  static bool CompositedSelectionUpdateEnabled() {
    return feature_states_[kCompositedSelectionUpdateFlagIndex];
  }

  static bool CompositedSelectionUpdateEnabled(const FeatureContext*) { return CompositedSelectionUpdateEnabled(); }

  static bool CompositingDecisionAtAnimationPhaseBoundariesEnabled() {
    return feature_states_[kCompositingDecisionAtAnimationPhaseBoundariesFlagIndex];
  }

  static bool CompositingDecisionAtAnimationPhaseBoundariesEnabled(const FeatureContext*) { return CompositingDecisionAtAnimationPhaseBoundariesEnabled(); }

  static bool CompositionForegroundMarkersEnabled() {
    return feature_states_[kCompositionForegroundMarkersFlagIndex];
  }

  static bool CompositionForegroundMarkersEnabled(const FeatureContext*) { return CompositionForegroundMarkersEnabled(); }

  static bool CompositorEventTriggerEnabled() {
    return feature_states_[kCompositorEventTriggerFlagIndex];
  }

  static bool CompositorEventTriggerEnabled(const FeatureContext*) { return CompositorEventTriggerEnabled(); }

  static bool CompositorTimelineTriggerEnabled() {
    return feature_states_[kCompositorTimelineTriggerFlagIndex];
  }

  static bool CompositorTimelineTriggerEnabled(const FeatureContext*) { return CompositorTimelineTriggerEnabled(); }

  static bool CompressionDictionaryTransportEnabled() {
    return feature_states_[kCompressionDictionaryTransportFlagIndex];
  }

  static bool CompressionDictionaryTransportEnabled(const FeatureContext*) { return CompressionDictionaryTransportEnabled(); }

  static bool ComputedAccessibilityInfoEnabled() {
    return feature_states_[kComputedAccessibilityInfoFlagIndex];
  }

  static bool ComputedAccessibilityInfoEnabled(const FeatureContext*) { return ComputedAccessibilityInfoEnabled(); }

  static bool ComputePressureEnabled() {
    return feature_states_[kComputePressureFlagIndex];
  }

  static bool ComputePressureEnabled(const FeatureContext*) { return ComputePressureEnabled(); }

  static bool ConcurrentNativePaintWorkletsEnabled() {
    return feature_states_[kConcurrentNativePaintWorkletsFlagIndex];
  }

  static bool ConcurrentNativePaintWorkletsEnabled(const FeatureContext*) { return ConcurrentNativePaintWorkletsEnabled(); }

  static bool ConditionalTracingLoAFEnabled() {
    return feature_states_[kConditionalTracingLoAFFlagIndex];
  }

  static bool ConditionalTracingLoAFEnabled(const FeatureContext*) { return ConditionalTracingLoAFEnabled(); }

  static bool ConstructableStylesheetCacheEnabled() {
    return feature_states_[kConstructableStylesheetCacheFlagIndex];
  }

  static bool ConstructableStylesheetCacheEnabled(const FeatureContext*) { return ConstructableStylesheetCacheEnabled(); }

  static bool ContactsManagerEnabled() {
    return feature_states_[kContactsManagerFlagIndex];
  }

  static bool ContactsManagerEnabled(const FeatureContext*) { return ContactsManagerEnabled(); }

  static bool ContactsManagerExtraPropertiesEnabled() {
    return feature_states_[kContactsManagerExtraPropertiesFlagIndex];
  }

  static bool ContactsManagerExtraPropertiesEnabled(const FeatureContext*) { return ContactsManagerExtraPropertiesEnabled(); }

  static bool ContainerNameOnlyEnabled() {
    return feature_states_[kContainerNameOnlyFlagIndex];
  }

  static bool ContainerNameOnlyEnabled(const FeatureContext*) { return ContainerNameOnlyEnabled(); }

  static bool ContentIndexEnabled() {
    return feature_states_[kContentIndexFlagIndex];
  }

  static bool ContentIndexEnabled(const FeatureContext*) { return ContentIndexEnabled(); }

  static bool ContextMenuEnabled() {
    return feature_states_[kContextMenuFlagIndex];
  }

  static bool ContextMenuEnabled(const FeatureContext*) { return ContextMenuEnabled(); }

  static bool ControlledFrameEnabled() {
    return feature_states_[kControlledFrameFlagIndex];
  }

  static bool ControlledFrameEnabled(const FeatureContext*) { return ControlledFrameEnabled(); }

  static bool ControlledFrameWebRequestSecurityInfoEnabled() {
    if (!ControlledFrameEnabled())
      return false;
    return feature_states_[kControlledFrameWebRequestSecurityInfoFlagIndex];
  }

  static bool ControlledFrameWebRequestSecurityInfoEnabled(const FeatureContext*) { return ControlledFrameWebRequestSecurityInfoEnabled(); }

  static bool CookieStoreAPIMaxAgeEnabled() {
    return feature_states_[kCookieStoreAPIMaxAgeFlagIndex];
  }

  static bool CookieStoreAPIMaxAgeEnabled(const FeatureContext*) { return CookieStoreAPIMaxAgeEnabled(); }

  static bool CookieStoreAPIWhitespaceStrippingEnabled() {
    return feature_states_[kCookieStoreAPIWhitespaceStrippingFlagIndex];
  }

  static bool CookieStoreAPIWhitespaceStrippingEnabled(const FeatureContext*) { return CookieStoreAPIWhitespaceStrippingEnabled(); }

  static bool CorrectTemplateFormParsingEnabled() {
    return feature_states_[kCorrectTemplateFormParsingFlagIndex];
  }

  static bool CorrectTemplateFormParsingEnabled(const FeatureContext*) { return CorrectTemplateFormParsingEnabled(); }

  static bool CorsRFC1918Enabled() {
    return feature_states_[kCorsRFC1918FlagIndex];
  }

  static bool CorsRFC1918Enabled(const FeatureContext*) { return CorsRFC1918Enabled(); }

  static bool CreateInlineContentsAnonymousBlockEnabled() {
    return feature_states_[kCreateInlineContentsAnonymousBlockFlagIndex];
  }

  static bool CreateInlineContentsAnonymousBlockEnabled(const FeatureContext*) { return CreateInlineContentsAnonymousBlockEnabled(); }

  static bool CSPReportHashEnabled() {
    return feature_states_[kCSPReportHashFlagIndex];
  }

  static bool CSPReportHashEnabled(const FeatureContext*) { return CSPReportHashEnabled(); }

  static bool CSSAccentColorKeywordEnabled() {
    return feature_states_[kCSSAccentColorKeywordFlagIndex];
  }

  static bool CSSAccentColorKeywordEnabled(const FeatureContext*) { return CSSAccentColorKeywordEnabled(); }

  static bool CSSActiveCaptionMapsToCanvasEnabled() {
    return feature_states_[kCSSActiveCaptionMapsToCanvasFlagIndex];
  }

  static bool CSSActiveCaptionMapsToCanvasEnabled(const FeatureContext*) { return CSSActiveCaptionMapsToCanvasEnabled(); }

  static bool CSSAlphaColorFunctionEnabled() {
    return feature_states_[kCSSAlphaColorFunctionFlagIndex];
  }

  static bool CSSAlphaColorFunctionEnabled(const FeatureContext*) { return CSSAlphaColorFunctionEnabled(); }

  static bool CSSAlphaColorFunctionRequiresAlphaEnabled() {
    return feature_states_[kCSSAlphaColorFunctionRequiresAlphaFlagIndex];
  }

  static bool CSSAlphaColorFunctionRequiresAlphaEnabled(const FeatureContext*) { return CSSAlphaColorFunctionRequiresAlphaEnabled(); }

  static bool CSSAltCounterEnabled() {
    return feature_states_[kCSSAltCounterFlagIndex];
  }

  static bool CSSAltCounterEnabled(const FeatureContext*) { return CSSAltCounterEnabled(); }

  static bool CSSAnimationIterationCompositeEnabled() {
    return feature_states_[kCSSAnimationIterationCompositeFlagIndex];
  }

  static bool CSSAnimationIterationCompositeEnabled(const FeatureContext*) { return CSSAnimationIterationCompositeEnabled(); }

  static bool CSSArgumentGrammarEnabled() {
    return feature_states_[kCSSArgumentGrammarFlagIndex];
  }

  static bool CSSArgumentGrammarEnabled(const FeatureContext*) { return CSSArgumentGrammarEnabled(); }

  static bool CSSAtRuleCounterStyleImageSymbolsEnabled() {
    return feature_states_[kCSSAtRuleCounterStyleImageSymbolsFlagIndex];
  }

  static bool CSSAtRuleCounterStyleImageSymbolsEnabled(const FeatureContext*) { return CSSAtRuleCounterStyleImageSymbolsEnabled(); }

  static bool CSSAtRuleCounterStyleSpeakAsDescriptorEnabled() {
    return feature_states_[kCSSAtRuleCounterStyleSpeakAsDescriptorFlagIndex];
  }

  static bool CSSAtRuleCounterStyleSpeakAsDescriptorEnabled(const FeatureContext*) { return CSSAtRuleCounterStyleSpeakAsDescriptorEnabled(); }

  static bool CSSAttributeValueCaseSensitiveNonHTMLEnabled() {
    return feature_states_[kCSSAttributeValueCaseSensitiveNonHTMLFlagIndex];
  }

  static bool CSSAttributeValueCaseSensitiveNonHTMLEnabled(const FeatureContext*) { return CSSAttributeValueCaseSensitiveNonHTMLEnabled(); }

  static bool CSSBackgroundClipBorderAreaEnabled() {
    return feature_states_[kCSSBackgroundClipBorderAreaFlagIndex];
  }

  static bool CSSBackgroundClipBorderAreaEnabled(const FeatureContext*) { return CSSBackgroundClipBorderAreaEnabled(); }

  static bool CSSBorderShapeEnabled() {
    return feature_states_[kCSSBorderShapeFlagIndex];
  }

  static bool CSSBorderShapeEnabled(const FeatureContext*) { return CSSBorderShapeEnabled(); }

  static bool CSSCalcSimplificationAndSerializationEnabled() {
    return feature_states_[kCSSCalcSimplificationAndSerializationFlagIndex];
  }

  static bool CSSCalcSimplificationAndSerializationEnabled(const FeatureContext*) { return CSSCalcSimplificationAndSerializationEnabled(); }

  static bool CSSCaretAnimationEnabled() {
    return feature_states_[kCSSCaretAnimationFlagIndex];
  }

  static bool CSSCaretAnimationEnabled(const FeatureContext*) { return CSSCaretAnimationEnabled(); }

  static bool CSSCaretColorWithOptionalSecondValueEnabled() {
    return feature_states_[kCSSCaretColorWithOptionalSecondValueFlagIndex];
  }

  static bool CSSCaretColorWithOptionalSecondValueEnabled(const FeatureContext*) { return CSSCaretColorWithOptionalSecondValueEnabled(); }

  static bool CSSCaretShapeEnabled() {
    return feature_states_[kCSSCaretShapeFlagIndex];
  }

  static bool CSSCaretShapeEnabled(const FeatureContext*) { return CSSCaretShapeEnabled(); }

  static bool CSSCaseSensitiveSelectorEnabled() {
    return feature_states_[kCSSCaseSensitiveSelectorFlagIndex];
  }

  static bool CSSCaseSensitiveSelectorEnabled(const FeatureContext*) { return CSSCaseSensitiveSelectorEnabled(); }

  static bool CSSChUnitSpecCompliantFallbackEnabled() {
    return feature_states_[kCSSChUnitSpecCompliantFallbackFlagIndex];
  }

  static bool CSSChUnitSpecCompliantFallbackEnabled(const FeatureContext*) { return CSSChUnitSpecCompliantFallbackEnabled(); }

  static bool CSSColorTypedOMEnabled() {
    return feature_states_[kCSSColorTypedOMFlagIndex];
  }

  static bool CSSColorTypedOMEnabled(const FeatureContext*) { return CSSColorTypedOMEnabled(); }

  static bool CSSContainerProgressNotationEnabled() {
    return feature_states_[kCSSContainerProgressNotationFlagIndex];
  }

  static bool CSSContainerProgressNotationEnabled(const FeatureContext*) { return CSSContainerProgressNotationEnabled(); }

  static bool CSSContainerStyleQueriesRangeEnabled() {
    return feature_states_[kCSSContainerStyleQueriesRangeFlagIndex];
  }

  static bool CSSContainerStyleQueriesRangeEnabled(const FeatureContext*) { return CSSContainerStyleQueriesRangeEnabled(); }

  static bool CSSContrastColorEnabled() {
    return feature_states_[kCSSContrastColorFlagIndex];
  }

  static bool CSSContrastColorEnabled(const FeatureContext*) { return CSSContrastColorEnabled(); }

  static bool CSSCornersShorthandEnabled() {
    return feature_states_[kCSSCornersShorthandFlagIndex];
  }

  static bool CSSCornersShorthandEnabled(const FeatureContext*) { return CSSCornersShorthandEnabled(); }

  static bool CSSCounterResetReversedEnabled() {
    return feature_states_[kCSSCounterResetReversedFlagIndex];
  }

  static bool CSSCounterResetReversedEnabled(const FeatureContext*) { return CSSCounterResetReversedEnabled(); }

  static bool CSSCounterStyleSymbolsFunctionEnabled() {
    return feature_states_[kCSSCounterStyleSymbolsFunctionFlagIndex];
  }

  static bool CSSCounterStyleSymbolsFunctionEnabled(const FeatureContext*) { return CSSCounterStyleSymbolsFunctionEnabled(); }

  static bool CSSCrossFadeEnabled() {
    return feature_states_[kCSSCrossFadeFlagIndex];
  }

  static bool CSSCrossFadeEnabled(const FeatureContext*) { return CSSCrossFadeEnabled(); }

  static bool CSSCustomHighlightUniversalSelectorEnabled() {
    return feature_states_[kCSSCustomHighlightUniversalSelectorFlagIndex];
  }

  static bool CSSCustomHighlightUniversalSelectorEnabled(const FeatureContext*) { return CSSCustomHighlightUniversalSelectorEnabled(); }

  static bool CSSCustomMediaEnabled() {
    return feature_states_[kCSSCustomMediaFlagIndex];
  }

  static bool CSSCustomMediaEnabled(const FeatureContext*) { return CSSCustomMediaEnabled(); }

  static bool CSSDynamicRangeLimitEnabled() {
    return feature_states_[kCSSDynamicRangeLimitFlagIndex];
  }

  static bool CSSDynamicRangeLimitEnabled(const FeatureContext*) { return CSSDynamicRangeLimitEnabled(); }

  static bool CSSEnumeratedCustomPropertiesEnabled() {
    return feature_states_[kCSSEnumeratedCustomPropertiesFlagIndex];
  }

  static bool CSSEnumeratedCustomPropertiesEnabled(const FeatureContext*) { return CSSEnumeratedCustomPropertiesEnabled(); }

  static bool CSSFlowStartAndEndEnabled() {
    return feature_states_[kCSSFlowStartAndEndFlagIndex];
  }

  static bool CSSFlowStartAndEndEnabled(const FeatureContext*) { return CSSFlowStartAndEndEnabled(); }

  static bool CSSFontFamilySerializationEnabled() {
    return feature_states_[kCSSFontFamilySerializationFlagIndex];
  }

  static bool CSSFontFamilySerializationEnabled(const FeatureContext*) { return CSSFontFamilySerializationEnabled(); }

  static bool CSSFontSizeAdjustEnabled() {
    return feature_states_[kCSSFontSizeAdjustFlagIndex];
  }

  static bool CSSFontSizeAdjustEnabled(const FeatureContext*) { return CSSFontSizeAdjustEnabled(); }

  static bool CSSFunctionsEnabled() {
    return feature_states_[kCSSFunctionsFlagIndex];
  }

  static bool CSSFunctionsEnabled(const FeatureContext*) { return CSSFunctionsEnabled(); }

  static bool CSSGridLanesLayoutEnabled() {
    return feature_states_[kCSSGridLanesLayoutFlagIndex];
  }

  static bool CSSGridLanesLayoutEnabled(const FeatureContext*) { return CSSGridLanesLayoutEnabled(); }

  static bool CSSHangingPunctuationEnabled() {
    return feature_states_[kCSSHangingPunctuationFlagIndex];
  }

  static bool CSSHangingPunctuationEnabled(const FeatureContext*) { return CSSHangingPunctuationEnabled(); }

  static bool CSSHexAlphaColorEnabled() {
    return feature_states_[kCSSHexAlphaColorFlagIndex];
  }

  static bool CSSHexAlphaColorEnabled(const FeatureContext*) { return CSSHexAlphaColorEnabled(); }

  static bool CSSIdentFunctionEnabled() {
    return feature_states_[kCSSIdentFunctionFlagIndex];
  }

  static bool CSSIdentFunctionEnabled(const FeatureContext*) { return CSSIdentFunctionEnabled(); }

  static bool CSSImageAnimationEnabled() {
    return feature_states_[kCSSImageAnimationFlagIndex];
  }

  static bool CSSImageAnimationEnabled(const FeatureContext*) { return CSSImageAnimationEnabled(); }

  static bool CSSImageFunctionEnabled() {
    return feature_states_[kCSSImageFunctionFlagIndex];
  }

  static bool CSSImageFunctionEnabled(const FeatureContext*) { return CSSImageFunctionEnabled(); }

  static bool CSSInheritFunctionEnabled() {
    return feature_states_[kCSSInheritFunctionFlagIndex];
  }

  static bool CSSInheritFunctionEnabled(const FeatureContext*) { return CSSInheritFunctionEnabled(); }

  static bool CSSInRangeOutOfRangeReversedRangesEnabled() {
    return feature_states_[kCSSInRangeOutOfRangeReversedRangesFlagIndex];
  }

  static bool CSSInRangeOutOfRangeReversedRangesEnabled(const FeatureContext*) { return CSSInRangeOutOfRangeReversedRangesEnabled(); }

  static bool CSSKeyframesRuleLengthEnabled() {
    return feature_states_[kCSSKeyframesRuleLengthFlagIndex];
  }

  static bool CSSKeyframesRuleLengthEnabled(const FeatureContext*) { return CSSKeyframesRuleLengthEnabled(); }

  static bool CSSLangExtendedRangesEnabled() {
    return feature_states_[kCSSLangExtendedRangesFlagIndex];
  }

  static bool CSSLangExtendedRangesEnabled(const FeatureContext*) { return CSSLangExtendedRangesEnabled(); }

  static bool CSSLayoutAPIEnabled() {
    return feature_states_[kCSSLayoutAPIFlagIndex];
  }

  static bool CSSLayoutAPIEnabled(const FeatureContext*) { return CSSLayoutAPIEnabled(); }

  static bool CSSLetterAndWordSpacingPercentageEnabled() {
    return feature_states_[kCSSLetterAndWordSpacingPercentageFlagIndex];
  }

  static bool CSSLetterAndWordSpacingPercentageEnabled(const FeatureContext*) { return CSSLetterAndWordSpacingPercentageEnabled(); }

  static bool CSSLightDarkImageEnabled() {
    return feature_states_[kCSSLightDarkImageFlagIndex];
  }

  static bool CSSLightDarkImageEnabled(const FeatureContext*) { return CSSLightDarkImageEnabled(); }

  static bool CSSLineClampEnabled() {
    return feature_states_[kCSSLineClampFlagIndex];
  }

  static bool CSSLineClampEnabled(const FeatureContext*) { return CSSLineClampEnabled(); }

  static bool CSSLineClampAsShorthandEnabled() {
    if (!CSSLineClampEnabled())
      return false;
    return feature_states_[kCSSLineClampAsShorthandFlagIndex];
  }

  static bool CSSLineClampAsShorthandEnabled(const FeatureContext*) { return CSSLineClampAsShorthandEnabled(); }

  static bool CSSLineClampLineBreakingEllipsisEnabled() {
    if (!CSSLineClampEnabled())
      return false;
    return feature_states_[kCSSLineClampLineBreakingEllipsisFlagIndex];
  }

  static bool CSSLineClampLineBreakingEllipsisEnabled(const FeatureContext*) { return CSSLineClampLineBreakingEllipsisEnabled(); }

  static bool CSSListCounterAccountingEnabled() {
    return feature_states_[kCSSListCounterAccountingFlagIndex];
  }

  static bool CSSListCounterAccountingEnabled(const FeatureContext*) { return CSSListCounterAccountingEnabled(); }

  static bool CSSLogicalCombinationPseudoEnabled() {
    return feature_states_[kCSSLogicalCombinationPseudoFlagIndex];
  }

  static bool CSSLogicalCombinationPseudoEnabled(const FeatureContext*) { return CSSLogicalCombinationPseudoEnabled(); }

  static bool CSSMarkerNestedPseudoElementEnabled() {
    return feature_states_[kCSSMarkerNestedPseudoElementFlagIndex];
  }

  static bool CSSMarkerNestedPseudoElementEnabled(const FeatureContext*) { return CSSMarkerNestedPseudoElementEnabled(); }

  static bool CssMaxContentSizingEnabled() {
    return feature_states_[kCssMaxContentSizingFlagIndex];
  }

  static bool CssMaxContentSizingEnabled(const FeatureContext*) { return CssMaxContentSizingEnabled(); }

  static bool CSSMediaElementPseudosEnabled() {
    return feature_states_[kCSSMediaElementPseudosFlagIndex];
  }

  static bool CSSMediaElementPseudosEnabled(const FeatureContext*) { return CSSMediaElementPseudosEnabled(); }

  static bool CSSMediaProgressNotationEnabled() {
    return feature_states_[kCSSMediaProgressNotationFlagIndex];
  }

  static bool CSSMediaProgressNotationEnabled(const FeatureContext*) { return CSSMediaProgressNotationEnabled(); }

  static bool CSSMixinsEnabled() {
    return feature_states_[kCSSMixinsFlagIndex];
  }

  static bool CSSMixinsEnabled(const FeatureContext*) { return CSSMixinsEnabled(); }

  static bool CSSNestedPseudoElementsEnabled() {
    return feature_states_[kCSSNestedPseudoElementsFlagIndex];
  }

  static bool CSSNestedPseudoElementsEnabled(const FeatureContext*) { return CSSNestedPseudoElementsEnabled(); }

  static bool CSSOMGetComputedStylePseudoElementRequiresColonEnabled() {
    return feature_states_[kCSSOMGetComputedStylePseudoElementRequiresColonFlagIndex];
  }

  static bool CSSOMGetComputedStylePseudoElementRequiresColonEnabled(const FeatureContext*) { return CSSOMGetComputedStylePseudoElementRequiresColonEnabled(); }

  static bool CSSOverscrollBehaviorChainEnabled() {
    return feature_states_[kCSSOverscrollBehaviorChainFlagIndex];
  }

  static bool CSSOverscrollBehaviorChainEnabled(const FeatureContext*) { return CSSOverscrollBehaviorChainEnabled(); }

  static bool CSSPaintAPIArgumentsEnabled() {
    return feature_states_[kCSSPaintAPIArgumentsFlagIndex];
  }

  static bool CSSPaintAPIArgumentsEnabled(const FeatureContext*) { return CSSPaintAPIArgumentsEnabled(); }

  static bool CSSParserIgnoreCharsetForURLsEnabled() {
    return feature_states_[kCSSParserIgnoreCharsetForURLsFlagIndex];
  }

  static bool CSSParserIgnoreCharsetForURLsEnabled(const FeatureContext*) { return CSSParserIgnoreCharsetForURLsEnabled(); }

  static bool CSSPolygonRoundingEnabled() {
    return feature_states_[kCSSPolygonRoundingFlagIndex];
  }

  static bool CSSPolygonRoundingEnabled(const FeatureContext*) { return CSSPolygonRoundingEnabled(); }

  static bool CSSPositionStickyStaticScrollPositionEnabled() {
    return feature_states_[kCSSPositionStickyStaticScrollPositionFlagIndex];
  }

  static bool CSSPositionStickyStaticScrollPositionEnabled(const FeatureContext*) { return CSSPositionStickyStaticScrollPositionEnabled(); }

  static bool CSSPrivateEnabled() {
    return feature_states_[kCSSPrivateFlagIndex];
  }

  static bool CSSPrivateEnabled(const FeatureContext*) { return CSSPrivateEnabled(); }

  static bool CSSProgressNotationEnabled() {
    return feature_states_[kCSSProgressNotationFlagIndex];
  }

  static bool CSSProgressNotationEnabled(const FeatureContext*) { return CSSProgressNotationEnabled(); }

  static bool CSSPseudoColumnEnabled() {
    return feature_states_[kCSSPseudoColumnFlagIndex];
  }

  static bool CSSPseudoColumnEnabled(const FeatureContext*) { return CSSPseudoColumnEnabled(); }

  static bool CSSPseudoElementBackdropEnabled() {
    return feature_states_[kCSSPseudoElementBackdropFlagIndex];
  }

  static bool CSSPseudoElementBackdropEnabled(const FeatureContext*) { return CSSPseudoElementBackdropEnabled(); }

  static bool CSSPseudoElementInterfaceEnabled() {
    return feature_states_[kCSSPseudoElementInterfaceFlagIndex];
  }

  static bool CSSPseudoElementInterfaceEnabled(const FeatureContext*) { return CSSPseudoElementInterfaceEnabled(); }

  static bool CSSPseudoElementViewTransitionsEnabled() {
    if (!CSSPseudoElementInterfaceEnabled())
      return false;
    return feature_states_[kCSSPseudoElementViewTransitionsFlagIndex];
  }

  static bool CSSPseudoElementViewTransitionsEnabled(const FeatureContext*) { return CSSPseudoElementViewTransitionsEnabled(); }

  static bool CSSPseudoHasSlottedEnabled() {
    return feature_states_[kCSSPseudoHasSlottedFlagIndex];
  }

  static bool CSSPseudoHasSlottedEnabled(const FeatureContext*) { return CSSPseudoHasSlottedEnabled(); }

  static bool CSSPseudoScrollButtonsEnabled() {
    if (!PseudoElementsFocusableEnabled())
      return false;
    return feature_states_[kCSSPseudoScrollButtonsFlagIndex];
  }

  static bool CSSPseudoScrollButtonsEnabled(const FeatureContext*) { return CSSPseudoScrollButtonsEnabled(); }

  static bool CSSPseudoScrollMarkersEnabled() {
    if (!PseudoElementsFocusableEnabled())
      return false;
    return feature_states_[kCSSPseudoScrollMarkersFlagIndex];
  }

  static bool CSSPseudoScrollMarkersEnabled(const FeatureContext*) { return CSSPseudoScrollMarkersEnabled(); }

  static bool CSSRandomFunctionEnabled() {
    return feature_states_[kCSSRandomFunctionFlagIndex];
  }

  static bool CSSRandomFunctionEnabled(const FeatureContext*) { return CSSRandomFunctionEnabled(); }

  static bool CSSRandomFunctionTypedOMEnabled() {
    if (!CSSRandomFunctionEnabled())
      return false;
    return feature_states_[kCSSRandomFunctionTypedOMFlagIndex];
  }

  static bool CSSRandomFunctionTypedOMEnabled(const FeatureContext*) { return CSSRandomFunctionTypedOMEnabled(); }

  static bool CSSResizeAutoEnabled() {
    return feature_states_[kCSSResizeAutoFlagIndex];
  }

  static bool CSSResizeAutoEnabled(const FeatureContext*) { return CSSResizeAutoEnabled(); }

  static bool CSSResourceIntegrityEnforcementEnabled() {
    return feature_states_[kCSSResourceIntegrityEnforcementFlagIndex];
  }

  static bool CSSResourceIntegrityEnforcementEnabled(const FeatureContext*) { return CSSResourceIntegrityEnforcementEnabled(); }

  static bool CSSRevertRuleEnabled() {
    return feature_states_[kCSSRevertRuleFlagIndex];
  }

  static bool CSSRevertRuleEnabled(const FeatureContext*) { return CSSRevertRuleEnabled(); }

  static bool CSSRubyOverhangEnabled() {
    return feature_states_[kCSSRubyOverhangFlagIndex];
  }

  static bool CSSRubyOverhangEnabled(const FeatureContext*) { return CSSRubyOverhangEnabled(); }

  static bool CSSSafePrintableInsetEnabled() {
    return feature_states_[kCSSSafePrintableInsetFlagIndex];
  }

  static bool CSSSafePrintableInsetEnabled(const FeatureContext*) { return CSSSafePrintableInsetEnabled(); }

  static bool CSSScopeifiedParentPseudoClassEnabled() {
    return feature_states_[kCSSScopeifiedParentPseudoClassFlagIndex];
  }

  static bool CSSScopeifiedParentPseudoClassEnabled(const FeatureContext*) { return CSSScopeifiedParentPseudoClassEnabled(); }

  static bool CSSScopeImportEnabled() {
    return feature_states_[kCSSScopeImportFlagIndex];
  }

  static bool CSSScopeImportEnabled(const FeatureContext*) { return CSSScopeImportEnabled(); }

  static bool CSSScrolledContainerQueriesEnabled() {
    return feature_states_[kCSSScrolledContainerQueriesFlagIndex];
  }

  static bool CSSScrolledContainerQueriesEnabled(const FeatureContext*) { return CSSScrolledContainerQueriesEnabled(); }

  static bool CSSScrollInitialTargetEnabled() {
    return feature_states_[kCSSScrollInitialTargetFlagIndex];
  }

  static bool CSSScrollInitialTargetEnabled(const FeatureContext*) { return CSSScrollInitialTargetEnabled(); }

  static bool CSSScrollMarkerGroupModesEnabled() {
    return feature_states_[kCSSScrollMarkerGroupModesFlagIndex];
  }

  static bool CSSScrollMarkerGroupModesEnabled(const FeatureContext*) { return CSSScrollMarkerGroupModesEnabled(); }

  static bool CSSScrollMarkerTargetBeforeAfterEnabled() {
    return feature_states_[kCSSScrollMarkerTargetBeforeAfterFlagIndex];
  }

  static bool CSSScrollMarkerTargetBeforeAfterEnabled(const FeatureContext*) { return CSSScrollMarkerTargetBeforeAfterEnabled(); }

  static bool CSSScrollSnapChangeEventEnabled() {
    return feature_states_[kCSSScrollSnapChangeEventFlagIndex];
  }

  static bool CSSScrollSnapChangeEventEnabled(const FeatureContext*) { return CSSScrollSnapChangeEventEnabled(); }

  static bool CSSScrollSnapChangingEventEnabled() {
    return feature_states_[kCSSScrollSnapChangingEventFlagIndex];
  }

  static bool CSSScrollSnapChangingEventEnabled(const FeatureContext*) { return CSSScrollSnapChangingEventEnabled(); }

  static bool CSSScrollSnapEventConstructorExposedEnabled() {
    return feature_states_[kCSSScrollSnapEventConstructorExposedFlagIndex];
  }

  static bool CSSScrollSnapEventConstructorExposedEnabled(const FeatureContext*) { return CSSScrollSnapEventConstructorExposedEnabled(); }

  static bool CSSScrollSnapEventsEnabled() {
    if (CSSScrollSnapChangeEventEnabled())
      return true;
    if (CSSScrollSnapChangingEventEnabled())
      return true;
    return feature_states_[kCSSScrollSnapEventsFlagIndex];
  }

  static bool CSSScrollSnapEventsEnabled(const FeatureContext*) { return CSSScrollSnapEventsEnabled(); }

  static bool CSSScrollSnapStopBeforeEnabled() {
    return feature_states_[kCSSScrollSnapStopBeforeFlagIndex];
  }

  static bool CSSScrollSnapStopBeforeEnabled(const FeatureContext*) { return CSSScrollSnapStopBeforeEnabled(); }

  static bool CSSScrollSnapTypePairEnabled() {
    return feature_states_[kCSSScrollSnapTypePairFlagIndex];
  }

  static bool CSSScrollSnapTypePairEnabled(const FeatureContext*) { return CSSScrollSnapTypePairEnabled(); }

  static bool CSSScrollTargetGroupEnabled() {
    return feature_states_[kCSSScrollTargetGroupFlagIndex];
  }

  static bool CSSScrollTargetGroupEnabled(const FeatureContext*) { return CSSScrollTargetGroupEnabled(); }

  static bool CSSScrollTargetGroupAriaCurrentEnabled() {
    return feature_states_[kCSSScrollTargetGroupAriaCurrentFlagIndex];
  }

  static bool CSSScrollTargetGroupAriaCurrentEnabled(const FeatureContext*) { return CSSScrollTargetGroupAriaCurrentEnabled(); }

  static bool CSSShapeOutsidePathAndShapeSupportEnabled() {
    return feature_states_[kCSSShapeOutsidePathAndShapeSupportFlagIndex];
  }

  static bool CSSShapeOutsidePathAndShapeSupportEnabled(const FeatureContext*) { return CSSShapeOutsidePathAndShapeSupportEnabled(); }

  static bool CSSShapeOutsideRectAndXywhSupportEnabled() {
    return feature_states_[kCSSShapeOutsideRectAndXywhSupportFlagIndex];
  }

  static bool CSSShapeOutsideRectAndXywhSupportEnabled(const FeatureContext*) { return CSSShapeOutsideRectAndXywhSupportEnabled(); }

  static bool CSSStyleSheetInitBaseURLEnabled() {
    return feature_states_[kCSSStyleSheetInitBaseURLFlagIndex];
  }

  static bool CSSStyleSheetInitBaseURLEnabled(const FeatureContext*) { return CSSStyleSheetInitBaseURLEnabled(); }

  static bool CSSSupportsAtRuleFunctionEnabled() {
    return feature_states_[kCSSSupportsAtRuleFunctionFlagIndex];
  }

  static bool CSSSupportsAtRuleFunctionEnabled(const FeatureContext*) { return CSSSupportsAtRuleFunctionEnabled(); }

  static bool CSSSupportsForImportRulesEnabled() {
    return feature_states_[kCSSSupportsForImportRulesFlagIndex];
  }

  static bool CSSSupportsForImportRulesEnabled(const FeatureContext*) { return CSSSupportsForImportRulesEnabled(); }

  static bool CSSSupportsNamedFeatureFunctionEnabled() {
    return feature_states_[kCSSSupportsNamedFeatureFunctionFlagIndex];
  }

  static bool CSSSupportsNamedFeatureFunctionEnabled(const FeatureContext*) { return CSSSupportsNamedFeatureFunctionEnabled(); }

  static bool CSSSystemAccentColorEnabled() {
    return feature_states_[kCSSSystemAccentColorFlagIndex];
  }

  static bool CSSSystemAccentColorEnabled(const FeatureContext*) { return CSSSystemAccentColorEnabled(); }

  static bool CSSTextAlignMatchParentEnabled() {
    return feature_states_[kCSSTextAlignMatchParentFlagIndex];
  }

  static bool CSSTextAlignMatchParentEnabled(const FeatureContext*) { return CSSTextAlignMatchParentEnabled(); }

  static bool CSSTextDecorationInsetEnabled() {
    return feature_states_[kCSSTextDecorationInsetFlagIndex];
  }

  static bool CSSTextDecorationInsetEnabled(const FeatureContext*) { return CSSTextDecorationInsetEnabled(); }

  static bool CSSTextDecorationSkipInkAllEnabled() {
    return feature_states_[kCSSTextDecorationSkipInkAllFlagIndex];
  }

  static bool CSSTextDecorationSkipInkAllEnabled(const FeatureContext*) { return CSSTextDecorationSkipInkAllEnabled(); }

  static bool CSSTextDecorationSkipSpacesEnabled() {
    return feature_states_[kCSSTextDecorationSkipSpacesFlagIndex];
  }

  static bool CSSTextDecorationSkipSpacesEnabled(const FeatureContext*) { return CSSTextDecorationSkipSpacesEnabled(); }

  static bool CssTextFitEnabled() {
    return feature_states_[kCssTextFitFlagIndex];
  }

  static bool CssTextFitEnabled(const FeatureContext*) { return CssTextFitEnabled(); }

  static bool CssTextFitReshapingEnabled() {
    return feature_states_[kCssTextFitReshapingFlagIndex];
  }

  static bool CssTextFitReshapingEnabled(const FeatureContext*) { return CssTextFitReshapingEnabled(); }

  static bool CSSTextSpacingEnabled() {
    return feature_states_[kCSSTextSpacingFlagIndex];
  }

  static bool CSSTextSpacingEnabled(const FeatureContext*) { return CSSTextSpacingEnabled(); }

  static bool CSSTextTransformFullSizeKanaEnabled() {
    return feature_states_[kCSSTextTransformFullSizeKanaFlagIndex];
  }

  static bool CSSTextTransformFullSizeKanaEnabled(const FeatureContext*) { return CSSTextTransformFullSizeKanaEnabled(); }

  static bool CSSTextTransformFullWidthEnabled() {
    return feature_states_[kCSSTextTransformFullWidthFlagIndex];
  }

  static bool CSSTextTransformFullWidthEnabled(const FeatureContext*) { return CSSTextTransformFullWidthEnabled(); }

  static bool CSSTextTransformMultiKeywordEnabled() {
    if (!CSSTextTransformFullWidthEnabled())
      return false;
    if (!CSSTextTransformFullSizeKanaEnabled())
      return false;
    return feature_states_[kCSSTextTransformMultiKeywordFlagIndex];
  }

  static bool CSSTextTransformMultiKeywordEnabled(const FeatureContext*) { return CSSTextTransformMultiKeywordEnabled(); }

  static bool CSSTimelineNameConflictResolutionEnabled() {
    return feature_states_[kCSSTimelineNameConflictResolutionFlagIndex];
  }

  static bool CSSTimelineNameConflictResolutionEnabled(const FeatureContext*) { return CSSTimelineNameConflictResolutionEnabled(); }

  static bool CSSTimelineScopeAllEnabled() {
    return feature_states_[kCSSTimelineScopeAllFlagIndex];
  }

  static bool CSSTimelineScopeAllEnabled(const FeatureContext*) { return CSSTimelineScopeAllEnabled(); }

  static bool CSSTimelineScopeGlobalEnabled() {
    return feature_states_[kCSSTimelineScopeGlobalFlagIndex];
  }

  static bool CSSTimelineScopeGlobalEnabled(const FeatureContext*) { return CSSTimelineScopeGlobalEnabled(); }

  static bool CSSTypedArithmeticEnabled() {
    return feature_states_[kCSSTypedArithmeticFlagIndex];
  }

  static bool CSSTypedArithmeticEnabled(const FeatureContext*) { return CSSTypedArithmeticEnabled(); }

  static bool CSSURLRequestModifiersEnabled() {
    return feature_states_[kCSSURLRequestModifiersFlagIndex];
  }

  static bool CSSURLRequestModifiersEnabled(const FeatureContext*) { return CSSURLRequestModifiersEnabled(); }

  static bool CSSUserSelectContainEnabled() {
    return feature_states_[kCSSUserSelectContainFlagIndex];
  }

  static bool CSSUserSelectContainEnabled(const FeatureContext*) { return CSSUserSelectContainEnabled(); }

  static bool CSSUserValidAndUserInvalidForRadioEnabled() {
    return feature_states_[kCSSUserValidAndUserInvalidForRadioFlagIndex];
  }

  static bool CSSUserValidAndUserInvalidForRadioEnabled(const FeatureContext*) { return CSSUserValidAndUserInvalidForRadioEnabled(); }

  static bool CSSVideoDynamicRangeMediaQueriesEnabled() {
    return feature_states_[kCSSVideoDynamicRangeMediaQueriesFlagIndex];
  }

  static bool CSSVideoDynamicRangeMediaQueriesEnabled(const FeatureContext*) { return CSSVideoDynamicRangeMediaQueriesEnabled(); }

  static bool CSSViewTransitionAutoNameEnabled() {
    return feature_states_[kCSSViewTransitionAutoNameFlagIndex];
  }

  static bool CSSViewTransitionAutoNameEnabled(const FeatureContext*) { return CSSViewTransitionAutoNameEnabled(); }

  static bool CSSWindowDragEnabled() {
    return feature_states_[kCSSWindowDragFlagIndex];
  }

  static bool CSSWindowDragEnabled(const FeatureContext*) { return CSSWindowDragEnabled(); }

  static bool CSSZoomAnimationEnabled() {
    return feature_states_[kCSSZoomAnimationFlagIndex];
  }

  static bool CSSZoomAnimationEnabled(const FeatureContext*) { return CSSZoomAnimationEnabled(); }

  static bool CustomElementsDisableFormattingFixupsEnabled() {
    return feature_states_[kCustomElementsDisableFormattingFixupsFlagIndex];
  }

  static bool CustomElementsDisableFormattingFixupsEnabled(const FeatureContext*) { return CustomElementsDisableFormattingFixupsEnabled(); }

  static bool CustomizableComboboxEnabled() {
    if (!AppearanceBaseEnabled())
      return false;
    return feature_states_[kCustomizableComboboxFlagIndex];
  }

  static bool CustomizableComboboxEnabled(const FeatureContext*) { return CustomizableComboboxEnabled(); }

  static bool CustomizableSelectMultiplePopupEnabled() {
    return feature_states_[kCustomizableSelectMultiplePopupFlagIndex];
  }

  static bool CustomizableSelectMultiplePopupEnabled(const FeatureContext*) { return CustomizableSelectMultiplePopupEnabled(); }

  static bool CustomScrollbarApplyMinimumThumbLengthEnabled() {
    return feature_states_[kCustomScrollbarApplyMinimumThumbLengthFlagIndex];
  }

  static bool CustomScrollbarApplyMinimumThumbLengthEnabled(const FeatureContext*) { return CustomScrollbarApplyMinimumThumbLengthEnabled(); }

  static bool DatabaseEnabled() {
    return feature_states_[kDatabaseFlagIndex];
  }

  static bool DatabaseEnabled(const FeatureContext*) { return DatabaseEnabled(); }

  static bool DateTimeInputTypeEarlyAdvanceFixEnabled() {
    return feature_states_[kDateTimeInputTypeEarlyAdvanceFixFlagIndex];
  }

  static bool DateTimeInputTypeEarlyAdvanceFixEnabled(const FeatureContext*) { return DateTimeInputTypeEarlyAdvanceFixEnabled(); }

  static bool DeclarativeCSSModulesStyleTagEnabled() {
    return feature_states_[kDeclarativeCSSModulesStyleTagFlagIndex];
  }

  static bool DeclarativeCSSModulesStyleTagEnabled(const FeatureContext*) { return DeclarativeCSSModulesStyleTagEnabled(); }

  static bool DeclarativeFragmentEnabled() {
    if (!DocumentPatchingEnabled())
      return false;
    return feature_states_[kDeclarativeFragmentFlagIndex];
  }

  static bool DeclarativeFragmentEnabled(const FeatureContext*) { return DeclarativeFragmentEnabled(); }

  static bool DeclarativeSkeletonsEnabled() {
    return feature_states_[kDeclarativeSkeletonsFlagIndex];
  }

  static bool DeclarativeSkeletonsEnabled(const FeatureContext*) { return DeclarativeSkeletonsEnabled(); }

  static bool DelegatesFocusTextControlInputFixEnabled() {
    return feature_states_[kDelegatesFocusTextControlInputFixFlagIndex];
  }

  static bool DelegatesFocusTextControlInputFixEnabled(const FeatureContext*) { return DelegatesFocusTextControlInputFixEnabled(); }

  static bool DesktopCaptureDisableLocalEchoControlEnabled() {
    return feature_states_[kDesktopCaptureDisableLocalEchoControlFlagIndex];
  }

  static bool DesktopCaptureDisableLocalEchoControlEnabled(const FeatureContext*) { return DesktopCaptureDisableLocalEchoControlEnabled(); }

  static bool DesktopPWAsAdditionalWindowingControlsEnabled() {
    return feature_states_[kDesktopPWAsAdditionalWindowingControlsFlagIndex];
  }

  static bool DesktopPWAsAdditionalWindowingControlsEnabled(const FeatureContext*) { return DesktopPWAsAdditionalWindowingControlsEnabled(); }

  static bool DesktopPWAsAdditionalWindowingControlsOnMoveEnabled() {
    return feature_states_[kDesktopPWAsAdditionalWindowingControlsOnMoveFlagIndex];
  }

  static bool DesktopPWAsAdditionalWindowingControlsOnMoveEnabled(const FeatureContext*) { return DesktopPWAsAdditionalWindowingControlsOnMoveEnabled(); }

  static bool DeviceAttributesEnabled() {
    return feature_states_[kDeviceAttributesFlagIndex];
  }

  static bool DeviceAttributesEnabled(const FeatureContext*) { return DeviceAttributesEnabled(); }

  static bool DeviceOrientationRequestPermissionEnabled() {
    return feature_states_[kDeviceOrientationRequestPermissionFlagIndex];
  }

  static bool DeviceOrientationRequestPermissionEnabled(const FeatureContext*) { return DeviceOrientationRequestPermissionEnabled(); }

  static bool DevicePostureEnabled() {
    return feature_states_[kDevicePostureFlagIndex];
  }

  static bool DevicePostureEnabled(const FeatureContext*) { return DevicePostureEnabled(); }

  static bool DialogCloseWhenOpenRemovedEnabled() {
    return feature_states_[kDialogCloseWhenOpenRemovedFlagIndex];
  }

  static bool DialogCloseWhenOpenRemovedEnabled(const FeatureContext*) { return DialogCloseWhenOpenRemovedEnabled(); }

  static bool DialogNewFocusBehaviorEnabled() {
    return feature_states_[kDialogNewFocusBehaviorFlagIndex];
  }

  static bool DialogNewFocusBehaviorEnabled(const FeatureContext*) { return DialogNewFocusBehaviorEnabled(); }

  static bool DigitalCredentialsProtocolFilterEnabled() {
    return feature_states_[kDigitalCredentialsProtocolFilterFlagIndex];
  }

  static bool DigitalCredentialsProtocolFilterEnabled(const FeatureContext*) { return DigitalCredentialsProtocolFilterEnabled(); }

  static bool DigitalGoodsV2_1Enabled() {
    return feature_states_[kDigitalGoodsV2_1FlagIndex];
  }

  static bool DigitalGoodsV2_1Enabled(const FeatureContext*) { return DigitalGoodsV2_1Enabled(); }

  static bool DirectSocketsEnabled() {
    return feature_states_[kDirectSocketsFlagIndex];
  }

  static bool DirectSocketsEnabled(const FeatureContext*);

  static bool DirectSocketsInServiceWorkersEnabled() {
    return feature_states_[kDirectSocketsInServiceWorkersFlagIndex];
  }

  static bool DirectSocketsInServiceWorkersEnabled(const FeatureContext*) { return DirectSocketsInServiceWorkersEnabled(); }

  static bool DirectSocketsInSharedWorkersEnabled() {
    return feature_states_[kDirectSocketsInSharedWorkersFlagIndex];
  }

  static bool DirectSocketsInSharedWorkersEnabled(const FeatureContext*) { return DirectSocketsInSharedWorkersEnabled(); }

  static bool DisableAnchorCenterOnAlignJustifyItemsEnabled() {
    return feature_states_[kDisableAnchorCenterOnAlignJustifyItemsFlagIndex];
  }

  static bool DisableAnchorCenterOnAlignJustifyItemsEnabled(const FeatureContext*) { return DisableAnchorCenterOnAlignJustifyItemsEnabled(); }

  static bool DisableEllipsisWhenScrolledEnabled() {
    return feature_states_[kDisableEllipsisWhenScrolledFlagIndex];
  }

  static bool DisableEllipsisWhenScrolledEnabled(const FeatureContext*) { return DisableEllipsisWhenScrolledEnabled(); }

  static bool DisableFormControlChangeEventDuringMutationEnabled() {
    return feature_states_[kDisableFormControlChangeEventDuringMutationFlagIndex];
  }

  static bool DisableFormControlChangeEventDuringMutationEnabled(const FeatureContext*) { return DisableFormControlChangeEventDuringMutationEnabled(); }

  static bool DisconnectWebSocketOnBFCacheEnabled() {
    return feature_states_[kDisconnectWebSocketOnBFCacheFlagIndex];
  }

  static bool DisconnectWebSocketOnBFCacheEnabled(const FeatureContext*) { return DisconnectWebSocketOnBFCacheEnabled(); }

  static bool DispatchHiddenVisibilityTransitionsEnabled() {
    return feature_states_[kDispatchHiddenVisibilityTransitionsFlagIndex];
  }

  static bool DispatchHiddenVisibilityTransitionsEnabled(const FeatureContext*) { return DispatchHiddenVisibilityTransitionsEnabled(); }

  static bool DispatchSelectionchangeEventPerElementEnabled() {
    return feature_states_[kDispatchSelectionchangeEventPerElementFlagIndex];
  }

  static bool DispatchSelectionchangeEventPerElementEnabled(const FeatureContext*) { return DispatchSelectionchangeEventPerElementEnabled(); }

  static bool DisplayContentsFocusableEnabled() {
    return feature_states_[kDisplayContentsFocusableFlagIndex];
  }

  static bool DisplayContentsFocusableEnabled(const FeatureContext*) { return DisplayContentsFocusableEnabled(); }

  static bool DisplayCutoutAPIEnabled() {
    return feature_states_[kDisplayCutoutAPIFlagIndex];
  }

  static bool DisplayCutoutAPIEnabled(const FeatureContext*) { return DisplayCutoutAPIEnabled(); }

  static bool DocumentCookieEnabled() {
    return feature_states_[kDocumentCookieFlagIndex];
  }

  static bool DocumentCookieEnabled(const FeatureContext*) { return DocumentCookieEnabled(); }

  static bool DocumentDomainEnabled() {
    return feature_states_[kDocumentDomainFlagIndex];
  }

  static bool DocumentDomainEnabled(const FeatureContext*) { return DocumentDomainEnabled(); }

  static bool DocumentNamedPropertiesIgnoreExposednessEnabled() {
    return feature_states_[kDocumentNamedPropertiesIgnoreExposednessFlagIndex];
  }

  static bool DocumentNamedPropertiesIgnoreExposednessEnabled(const FeatureContext*) { return DocumentNamedPropertiesIgnoreExposednessEnabled(); }

  static bool DocumentOpenIframeUnloadEventsEnabled() {
    return feature_states_[kDocumentOpenIframeUnloadEventsFlagIndex];
  }

  static bool DocumentOpenIframeUnloadEventsEnabled(const FeatureContext*) { return DocumentOpenIframeUnloadEventsEnabled(); }

  static bool DocumentOpenOriginAliasRemovalEnabled() {
    return feature_states_[kDocumentOpenOriginAliasRemovalFlagIndex];
  }

  static bool DocumentOpenOriginAliasRemovalEnabled(const FeatureContext*) { return DocumentOpenOriginAliasRemovalEnabled(); }

  static bool DocumentOpenSandboxInheritanceRemovalEnabled() {
    return feature_states_[kDocumentOpenSandboxInheritanceRemovalFlagIndex];
  }

  static bool DocumentOpenSandboxInheritanceRemovalEnabled(const FeatureContext*) { return DocumentOpenSandboxInheritanceRemovalEnabled(); }

  static bool DocumentPatchingEnabled() {
    return feature_states_[kDocumentPatchingFlagIndex];
  }

  static bool DocumentPatchingEnabled(const FeatureContext*) { return DocumentPatchingEnabled(); }

  static bool DocumentPictureInPictureAPIEnabled() {
    return feature_states_[kDocumentPictureInPictureAPIFlagIndex];
  }

  static bool DocumentPictureInPictureAPIEnabled(const FeatureContext*) { return DocumentPictureInPictureAPIEnabled(); }

  static bool DocumentPictureInPicturePreferInitialPlacementEnabled() {
    return feature_states_[kDocumentPictureInPicturePreferInitialPlacementFlagIndex];
  }

  static bool DocumentPictureInPicturePreferInitialPlacementEnabled(const FeatureContext*) { return DocumentPictureInPicturePreferInitialPlacementEnabled(); }

  static bool DocumentPictureInPictureUserActivationEnabled() {
    return feature_states_[kDocumentPictureInPictureUserActivationFlagIndex];
  }

  static bool DocumentPictureInPictureUserActivationEnabled(const FeatureContext*) { return DocumentPictureInPictureUserActivationEnabled(); }

  static bool DocumentPolicyDocumentDomainEnabled() {
    return feature_states_[kDocumentPolicyDocumentDomainFlagIndex];
  }

  static bool DocumentPolicyDocumentDomainEnabled(const FeatureContext*) { return DocumentPolicyDocumentDomainEnabled(); }

  static bool DocumentPolicyExpectNoLinkedResourcesEnabled() {
    return feature_states_[kDocumentPolicyExpectNoLinkedResourcesFlagIndex];
  }

  static bool DocumentPolicyExpectNoLinkedResourcesEnabled(const FeatureContext*) { return DocumentPolicyExpectNoLinkedResourcesEnabled(); }

  static bool DocumentPolicyIncludeJSCallStacksInCrashReportsEnabled() {
    return feature_states_[kDocumentPolicyIncludeJSCallStacksInCrashReportsFlagIndex];
  }

  static bool DocumentPolicyIncludeJSCallStacksInCrashReportsEnabled(const FeatureContext*) { return DocumentPolicyIncludeJSCallStacksInCrashReportsEnabled(); }

  static bool DocumentPolicyInDedicatedWorkerEnabled() {
    return feature_states_[kDocumentPolicyInDedicatedWorkerFlagIndex];
  }

  static bool DocumentPolicyInDedicatedWorkerEnabled(const FeatureContext*) { return DocumentPolicyInDedicatedWorkerEnabled(); }

  static bool DocumentPolicyJSProfilingModeEnabled() {
    return feature_states_[kDocumentPolicyJSProfilingModeFlagIndex];
  }

  static bool DocumentPolicyJSProfilingModeEnabled(const FeatureContext*) { return DocumentPolicyJSProfilingModeEnabled(); }

  static bool DocumentPolicyNetworkEfficiencyGuardrailsEnabled() {
    return feature_states_[kDocumentPolicyNetworkEfficiencyGuardrailsFlagIndex];
  }

  static bool DocumentPolicyNetworkEfficiencyGuardrailsEnabled(const FeatureContext*) { return DocumentPolicyNetworkEfficiencyGuardrailsEnabled(); }

  static bool DocumentPolicySyncXHREnabled() {
    return feature_states_[kDocumentPolicySyncXHRFlagIndex];
  }

  static bool DocumentPolicySyncXHREnabled(const FeatureContext*) { return DocumentPolicySyncXHREnabled(); }

  static bool DocumentWriteEnabled() {
    return feature_states_[kDocumentWriteFlagIndex];
  }

  static bool DocumentWriteEnabled(const FeatureContext*) { return DocumentWriteEnabled(); }

  static bool DOMParserXmlScriptAlreadyStartedEnabled() {
    return feature_states_[kDOMParserXmlScriptAlreadyStartedFlagIndex];
  }

  static bool DOMParserXmlScriptAlreadyStartedEnabled(const FeatureContext*) { return DOMParserXmlScriptAlreadyStartedEnabled(); }

  static bool DragAndDropDownloadURLListEnabled() {
    return feature_states_[kDragAndDropDownloadURLListFlagIndex];
  }

  static bool DragAndDropDownloadURLListEnabled(const FeatureContext*) { return DragAndDropDownloadURLListEnabled(); }

  static bool DragAndDropJSFileObjectsEnabled() {
    return feature_states_[kDragAndDropJSFileObjectsFlagIndex];
  }

  static bool DragAndDropJSFileObjectsEnabled(const FeatureContext*) { return DragAndDropJSFileObjectsEnabled(); }

  static bool DragImageForLargeImagesEnabled() {
    return feature_states_[kDragImageForLargeImagesFlagIndex];
  }

  static bool DragImageForLargeImagesEnabled(const FeatureContext*) { return DragImageForLargeImagesEnabled(); }

  static bool DumpForAbsentKeyframeSnapshotsEnabled() {
    return feature_states_[kDumpForAbsentKeyframeSnapshotsFlagIndex];
  }

  static bool DumpForAbsentKeyframeSnapshotsEnabled(const FeatureContext*) { return DumpForAbsentKeyframeSnapshotsEnabled(); }

  static bool EditContextAssignmentAsPerSpecEnabled() {
    return feature_states_[kEditContextAssignmentAsPerSpecFlagIndex];
  }

  static bool EditContextAssignmentAsPerSpecEnabled(const FeatureContext*) { return EditContextAssignmentAsPerSpecEnabled(); }

  static bool EditContextHandleTextOrSelectionUpdateDuringCompositionEnabled() {
    return feature_states_[kEditContextHandleTextOrSelectionUpdateDuringCompositionFlagIndex];
  }

  static bool EditContextHandleTextOrSelectionUpdateDuringCompositionEnabled(const FeatureContext*) { return EditContextHandleTextOrSelectionUpdateDuringCompositionEnabled(); }

  static bool EditContextSelectionUpdateBeforeTextUpdateEventEnabled() {
    return feature_states_[kEditContextSelectionUpdateBeforeTextUpdateEventFlagIndex];
  }

  static bool EditContextSelectionUpdateBeforeTextUpdateEventEnabled(const FeatureContext*) { return EditContextSelectionUpdateBeforeTextUpdateEventEnabled(); }

  static bool EditingUseDomPositionApiEnabled() {
    return feature_states_[kEditingUseDomPositionApiFlagIndex];
  }

  static bool EditingUseDomPositionApiEnabled(const FeatureContext*) { return EditingUseDomPositionApiEnabled(); }

  static bool ElasticOverscrollBackgroundPaintLocationFixEnabled() {
    return feature_states_[kElasticOverscrollBackgroundPaintLocationFixFlagIndex];
  }

  static bool ElasticOverscrollBackgroundPaintLocationFixEnabled(const FeatureContext*) { return ElasticOverscrollBackgroundPaintLocationFixEnabled(); }

  static bool ElasticOverscrollUseEventDeltaForAxisSelectionEnabled() {
    return feature_states_[kElasticOverscrollUseEventDeltaForAxisSelectionFlagIndex];
  }

  static bool ElasticOverscrollUseEventDeltaForAxisSelectionEnabled(const FeatureContext*) { return ElasticOverscrollUseEventDeltaForAxisSelectionEnabled(); }

  static bool ElementCanvasTransformEnabled() {
    return feature_states_[kElementCanvasTransformFlagIndex];
  }

  static bool ElementCanvasTransformEnabled(const FeatureContext*) { return ElementCanvasTransformEnabled(); }

  static bool ElementCaptureEnabled() {
    return feature_states_[kElementCaptureFlagIndex];
  }

  static bool ElementCaptureEnabled(const FeatureContext*) { return ElementCaptureEnabled(); }

  static bool ElementInternalsBehaviorsEnabled() {
    return feature_states_[kElementInternalsBehaviorsFlagIndex];
  }

  static bool ElementInternalsBehaviorsEnabled(const FeatureContext*) { return ElementInternalsBehaviorsEnabled(); }

  static bool ElementMatchContainerEnabled() {
    return feature_states_[kElementMatchContainerFlagIndex];
  }

  static bool ElementMatchContainerEnabled(const FeatureContext*) { return ElementMatchContainerEnabled(); }

  static bool ElementSpecificReadOnlyConstraintValidationEnabled() {
    return feature_states_[kElementSpecificReadOnlyConstraintValidationFlagIndex];
  }

  static bool ElementSpecificReadOnlyConstraintValidationEnabled(const FeatureContext*) { return ElementSpecificReadOnlyConstraintValidationEnabled(); }

  static bool EmbeddedContentCenterAlignBaselineEnabled() {
    return feature_states_[kEmbeddedContentCenterAlignBaselineFlagIndex];
  }

  static bool EmbeddedContentCenterAlignBaselineEnabled(const FeatureContext*) { return EmbeddedContentCenterAlignBaselineEnabled(); }

  static bool EnableXSLTForCAPAlertsEnabled() {
    return feature_states_[kEnableXSLTForCAPAlertsFlagIndex];
  }

  static bool EnableXSLTForCAPAlertsEnabled(const FeatureContext*) { return EnableXSLTForCAPAlertsEnabled(); }

  static bool EndpointInclusiveCommitStylesEnabled() {
    return feature_states_[kEndpointInclusiveCommitStylesFlagIndex];
  }

  static bool EndpointInclusiveCommitStylesEnabled(const FeatureContext*) { return EndpointInclusiveCommitStylesEnabled(); }

  static bool EnforceAnonymityExposureEnabled() {
    return feature_states_[kEnforceAnonymityExposureFlagIndex];
  }

  static bool EnforceAnonymityExposureEnabled(const FeatureContext*) { return EnforceAnonymityExposureEnabled(); }

  static bool EntropyIgnoredForFirstVideoFrameLCPEnabled() {
    return feature_states_[kEntropyIgnoredForFirstVideoFrameLCPFlagIndex];
  }

  static bool EntropyIgnoredForFirstVideoFrameLCPEnabled(const FeatureContext*) { return EntropyIgnoredForFirstVideoFrameLCPEnabled(); }

  static bool EventPseudoTargetPropertyEnabled() {
    if (!CSSPseudoElementInterfaceEnabled())
      return false;
    return feature_states_[kEventPseudoTargetPropertyFlagIndex];
  }

  static bool EventPseudoTargetPropertyEnabled(const FeatureContext*) { return EventPseudoTargetPropertyEnabled(); }

  static bool EventTimingInteractionCountEnabled() {
    return feature_states_[kEventTimingInteractionCountFlagIndex];
  }

  static bool EventTimingInteractionCountEnabled(const FeatureContext*) { return EventTimingInteractionCountEnabled(); }

  static bool EventTimingMatchingHTMLEnabled() {
    return feature_states_[kEventTimingMatchingHTMLFlagIndex];
  }

  static bool EventTimingMatchingHTMLEnabled(const FeatureContext*) { return EventTimingMatchingHTMLEnabled(); }

  static bool EventTimingTargetSelectorEnabled() {
    return feature_states_[kEventTimingTargetSelectorFlagIndex];
  }

  static bool EventTimingTargetSelectorEnabled(const FeatureContext*) { return EventTimingTargetSelectorEnabled(); }

  static bool EventTriggerEnabled() {
    return feature_states_[kEventTriggerFlagIndex];
  }

  static bool EventTriggerEnabled(const FeatureContext*) { return EventTriggerEnabled(); }

  static bool ExperimentalContentSecurityPolicyFeaturesEnabled() {
    return feature_states_[kExperimentalContentSecurityPolicyFeaturesFlagIndex];
  }

  static bool ExperimentalContentSecurityPolicyFeaturesEnabled(const FeatureContext*) { return ExperimentalContentSecurityPolicyFeaturesEnabled(); }

  static bool ExperimentalMachineLearningNeuralNetworkEnabled() {
    return feature_states_[kExperimentalMachineLearningNeuralNetworkFlagIndex];
  }

  static bool ExperimentalMachineLearningNeuralNetworkEnabled(const FeatureContext*) { return ExperimentalMachineLearningNeuralNetworkEnabled(); }

  static bool ExperimentalPoliciesEnabled() {
    return feature_states_[kExperimentalPoliciesFlagIndex];
  }

  static bool ExperimentalPoliciesEnabled(const FeatureContext*) { return ExperimentalPoliciesEnabled(); }

  static bool ExposeCSSFontFeatureValuesRuleEnabled() {
    return feature_states_[kExposeCSSFontFeatureValuesRuleFlagIndex];
  }

  static bool ExposeCSSFontFeatureValuesRuleEnabled(const FeatureContext*) { return ExposeCSSFontFeatureValuesRuleEnabled(); }

  static bool ExposeRenderTimeNonTaoDelayedImageEnabled() {
    return feature_states_[kExposeRenderTimeNonTaoDelayedImageFlagIndex];
  }

  static bool ExposeRenderTimeNonTaoDelayedImageEnabled(const FeatureContext*) { return ExposeRenderTimeNonTaoDelayedImageEnabled(); }

  static bool ExtensionScriptTaggingEnabled() {
    return feature_states_[kExtensionScriptTaggingFlagIndex];
  }

  static bool ExtensionScriptTaggingEnabled(const FeatureContext*) { return ExtensionScriptTaggingEnabled(); }

  static bool ExtensionScriptTaggingTestingAPIEnabled() {
    return feature_states_[kExtensionScriptTaggingTestingAPIFlagIndex];
  }

  static bool ExtensionScriptTaggingTestingAPIEnabled(const FeatureContext*) { return ExtensionScriptTaggingTestingAPIEnabled(); }

  static bool ExternalPopupMenuClickEventEnabled() {
    return feature_states_[kExternalPopupMenuClickEventFlagIndex];
  }

  static bool ExternalPopupMenuClickEventEnabled(const FeatureContext*) { return ExternalPopupMenuClickEventEnabled(); }

  static bool EyeDropperAPIEnabled() {
    return feature_states_[kEyeDropperAPIFlagIndex];
  }

  static bool EyeDropperAPIEnabled(const FeatureContext*) { return EyeDropperAPIEnabled(); }

  static bool FaceDetectorEnabled() {
    return feature_states_[kFaceDetectorFlagIndex];
  }

  static bool FaceDetectorEnabled(const FeatureContext*) { return FaceDetectorEnabled(); }

  static bool FastPositionIteratorEnabled() {
    return feature_states_[kFastPositionIteratorFlagIndex];
  }

  static bool FastPositionIteratorEnabled(const FeatureContext*) { return FastPositionIteratorEnabled(); }

  static bool FedCmEnabled() {
    return feature_states_[kFedCmFlagIndex];
  }

  static bool FedCmEnabled(const FeatureContext*) { return FedCmEnabled(); }

  static bool FedCmAutofillEnabled() {
    if (FedCmDelegationEnabled())
      return true;
    return feature_states_[kFedCmAutofillFlagIndex];
  }

  static bool FedCmAutofillEnabled(const FeatureContext*) { return FedCmAutofillEnabled(); }

  static bool FedCmDelegationEnabled() {
    if (!FedCmEnabled())
      return false;
    return feature_states_[kFedCmDelegationFlagIndex];
  }

  static bool FedCmDelegationEnabled(const FeatureContext*) { return FedCmDelegationEnabled(); }

  static bool FedCmIdentityHandlerEnabled() {
    if (!FedCmEnabled())
      return false;
    return feature_states_[kFedCmIdentityHandlerFlagIndex];
  }

  static bool FedCmIdentityHandlerEnabled(const FeatureContext*) { return FedCmIdentityHandlerEnabled(); }

  static bool FedCmIdPRegistrationEnabled() {
    if (!FedCmEnabled())
      return false;
    return feature_states_[kFedCmIdPRegistrationFlagIndex];
  }

  static bool FedCmIdPRegistrationEnabled(const FeatureContext*) { return FedCmIdPRegistrationEnabled(); }

  static bool FedCmLightweightModeEnabled() {
    if (!FedCmEnabled())
      return false;
    return feature_states_[kFedCmLightweightModeFlagIndex];
  }

  static bool FedCmLightweightModeEnabled(const FeatureContext*) { return FedCmLightweightModeEnabled(); }

  static bool FedCmMultipleRequestsEnabled() {
    if (!FedCmEnabled())
      return false;
    return feature_states_[kFedCmMultipleRequestsFlagIndex];
  }

  static bool FedCmMultipleRequestsEnabled(const FeatureContext*) { return FedCmMultipleRequestsEnabled(); }

  static bool FedCmNavigationInterceptionEnabled() {
    if (!FedCmEnabled())
      return false;
    return feature_states_[kFedCmNavigationInterceptionFlagIndex];
  }

  static bool FedCmNavigationInterceptionEnabled(const FeatureContext*) { return FedCmNavigationInterceptionEnabled(); }

  static bool FencedFramesEnabled() {
    return feature_states_[kFencedFramesFlagIndex];
  }

  static bool FencedFramesEnabled(const FeatureContext*) { return FencedFramesEnabled(); }

  static bool FencedFramesAPIChangesEnabled() {
    return feature_states_[kFencedFramesAPIChangesFlagIndex];
  }

  static bool FencedFramesAPIChangesEnabled(const FeatureContext*) { return FencedFramesAPIChangesEnabled(); }

  static bool FencedFramesLocalUnpartitionedDataAccessEnabled() {
    return feature_states_[kFencedFramesLocalUnpartitionedDataAccessFlagIndex];
  }

  static bool FencedFramesLocalUnpartitionedDataAccessEnabled(const FeatureContext*) { return FencedFramesLocalUnpartitionedDataAccessEnabled(); }

  static bool FetchBodyBytesEnabled() {
    return feature_states_[kFetchBodyBytesFlagIndex];
  }

  static bool FetchBodyBytesEnabled(const FeatureContext*) { return FetchBodyBytesEnabled(); }

  static bool FetchLaterAPIEnabled() {
    return feature_states_[kFetchLaterAPIFlagIndex];
  }

  static bool FetchLaterAPIEnabled(const FeatureContext*) { return FetchLaterAPIEnabled(); }

  static bool FetchUploadStreamingEnabled() {
    return feature_states_[kFetchUploadStreamingFlagIndex];
  }

  static bool FetchUploadStreamingEnabled(const FeatureContext*) { return FetchUploadStreamingEnabled(); }

  static bool FileColorPickerConsumeActivationEnabled() {
    return feature_states_[kFileColorPickerConsumeActivationFlagIndex];
  }

  static bool FileColorPickerConsumeActivationEnabled(const FeatureContext*) { return FileColorPickerConsumeActivationEnabled(); }

  static bool FileHandlingEnabled() {
    if (!FileSystemAccessLocalEnabled())
      return false;
    return feature_states_[kFileHandlingFlagIndex];
  }

  static bool FileHandlingEnabled(const FeatureContext*) { return FileHandlingEnabled(); }

  static bool FilePickerEventsFixEnabled() {
    return feature_states_[kFilePickerEventsFixFlagIndex];
  }

  static bool FilePickerEventsFixEnabled(const FeatureContext*) { return FilePickerEventsFixEnabled(); }

  static bool FileSystemEnabled() {
    return feature_states_[kFileSystemFlagIndex];
  }

  static bool FileSystemEnabled(const FeatureContext*) { return FileSystemEnabled(); }

  static bool FileSystemAccessEnabled() {
    if (FileSystemAccessLocalEnabled())
      return true;
    if (FileSystemAccessOriginPrivateEnabled())
      return true;
    return feature_states_[kFileSystemAccessFlagIndex];
  }

  static bool FileSystemAccessEnabled(const FeatureContext*) { return FileSystemAccessEnabled(); }

  static bool FileSystemAccessAPIExperimentalEnabled() {
    return feature_states_[kFileSystemAccessAPIExperimentalFlagIndex];
  }

  static bool FileSystemAccessAPIExperimentalEnabled(const FeatureContext*) { return FileSystemAccessAPIExperimentalEnabled(); }

  static bool FileSystemAccessGetCloudIdentifiersEnabled() {
    return feature_states_[kFileSystemAccessGetCloudIdentifiersFlagIndex];
  }

  static bool FileSystemAccessGetCloudIdentifiersEnabled(const FeatureContext*) { return FileSystemAccessGetCloudIdentifiersEnabled(); }

  static bool FileSystemAccessLocalEnabled() {
    return feature_states_[kFileSystemAccessLocalFlagIndex];
  }

  static bool FileSystemAccessLocalEnabled(const FeatureContext*) { return FileSystemAccessLocalEnabled(); }

  static bool FileSystemAccessLockingSchemeEnabled() {
    return feature_states_[kFileSystemAccessLockingSchemeFlagIndex];
  }

  static bool FileSystemAccessLockingSchemeEnabled(const FeatureContext*) { return FileSystemAccessLockingSchemeEnabled(); }

  static bool FileSystemAccessOriginPrivateEnabled() {
    return feature_states_[kFileSystemAccessOriginPrivateFlagIndex];
  }

  static bool FileSystemAccessOriginPrivateEnabled(const FeatureContext*) { return FileSystemAccessOriginPrivateEnabled(); }

  static bool FileSystemAccessRevokeReadOnRemoveEnabled() {
    if (!FileSystemAccessWriteModeEnabled())
      return false;
    return feature_states_[kFileSystemAccessRevokeReadOnRemoveFlagIndex];
  }

  static bool FileSystemAccessRevokeReadOnRemoveEnabled(const FeatureContext*) { return FileSystemAccessRevokeReadOnRemoveEnabled(); }

  static bool FileSystemAccessWriteModeEnabled() {
    return feature_states_[kFileSystemAccessWriteModeFlagIndex];
  }

  static bool FileSystemAccessWriteModeEnabled(const FeatureContext*) { return FileSystemAccessWriteModeEnabled(); }

  static bool FileSystemObserverEnabled() {
    if (!FileSystemAccessEnabled())
      return false;
    return feature_states_[kFileSystemObserverFlagIndex];
  }

  static bool FileSystemObserverEnabled(const FeatureContext*) { return FileSystemObserverEnabled(); }

  static bool FileSystemObserverUnobserveEnabled() {
    return feature_states_[kFileSystemObserverUnobserveFlagIndex];
  }

  static bool FileSystemObserverUnobserveEnabled(const FeatureContext*) { return FileSystemObserverUnobserveEnabled(); }

  static bool FilterableSelectEnabled() {
    return feature_states_[kFilterableSelectFlagIndex];
  }

  static bool FilterableSelectEnabled(const FeatureContext*) { return FilterableSelectEnabled(); }

  static bool FilterContainerLevelStylesEnabled() {
    return feature_states_[kFilterContainerLevelStylesFlagIndex];
  }

  static bool FilterContainerLevelStylesEnabled(const FeatureContext*) { return FilterContainerLevelStylesEnabled(); }

  static bool FilteringPrimitivesEnabled() {
    if (FilterableSelectEnabled())
      return true;
    if (CustomizableComboboxEnabled())
      return true;
    return feature_states_[kFilteringPrimitivesFlagIndex];
  }

  static bool FilteringPrimitivesEnabled(const FeatureContext*) { return FilteringPrimitivesEnabled(); }

  static bool FindBufferCollapseSkippedSpaceEnabled() {
    return feature_states_[kFindBufferCollapseSkippedSpaceFlagIndex];
  }

  static bool FindBufferCollapseSkippedSpaceEnabled(const FeatureContext*) { return FindBufferCollapseSkippedSpaceEnabled(); }

  static bool FindBufferMatchAcrossIgnoredNodesEnabled() {
    return feature_states_[kFindBufferMatchAcrossIgnoredNodesFlagIndex];
  }

  static bool FindBufferMatchAcrossIgnoredNodesEnabled(const FeatureContext*) { return FindBufferMatchAcrossIgnoredNodesEnabled(); }

  static bool FindFirstMisspellingEndWhenNonEditableEnabled() {
    return feature_states_[kFindFirstMisspellingEndWhenNonEditableFlagIndex];
  }

  static bool FindFirstMisspellingEndWhenNonEditableEnabled(const FeatureContext*) { return FindFirstMisspellingEndWhenNonEditableEnabled(); }

  static bool FindIgnoreSuggestionFixEnabled() {
    return feature_states_[kFindIgnoreSuggestionFixFlagIndex];
  }

  static bool FindIgnoreSuggestionFixEnabled(const FeatureContext*) { return FindIgnoreSuggestionFixEnabled(); }

  static bool FirstLineTextMetricsEnabled() {
    return feature_states_[kFirstLineTextMetricsFlagIndex];
  }

  static bool FirstLineTextMetricsEnabled(const FeatureContext*) { return FirstLineTextMetricsEnabled(); }

  static bool FixHTMLFormControlElementIsReadOnlyEnabled() {
    return feature_states_[kFixHTMLFormControlElementIsReadOnlyFlagIndex];
  }

  static bool FixHTMLFormControlElementIsReadOnlyEnabled(const FeatureContext*) { return FixHTMLFormControlElementIsReadOnlyEnabled(); }

  static bool FixMapElementEmptyNameBugEnabled() {
    return feature_states_[kFixMapElementEmptyNameBugFlagIndex];
  }

  static bool FixMapElementEmptyNameBugEnabled(const FeatureContext*) { return FixMapElementEmptyNameBugEnabled(); }

  static bool FixMarkerSuppressionForAppearanceAutoEnabled() {
    return feature_states_[kFixMarkerSuppressionForAppearanceAutoFlagIndex];
  }

  static bool FixMarkerSuppressionForAppearanceAutoEnabled(const FeatureContext*) { return FixMarkerSuppressionForAppearanceAutoEnabled(); }

  static bool FixSelectionPaintRangeNullOptEnabled() {
    return feature_states_[kFixSelectionPaintRangeNullOptFlagIndex];
  }

  static bool FixSelectionPaintRangeNullOptEnabled(const FeatureContext*) { return FixSelectionPaintRangeNullOptEnabled(); }

  static bool FixVisualRectRemoteViewportTransformEnabled() {
    return feature_states_[kFixVisualRectRemoteViewportTransformFlagIndex];
  }

  static bool FixVisualRectRemoteViewportTransformEnabled(const FeatureContext*) { return FixVisualRectRemoteViewportTransformEnabled(); }

  static bool FledgeEnabled() {
    return feature_states_[kFledgeFlagIndex];
  }

  static bool FledgeEnabled(const FeatureContext*) { return FledgeEnabled(); }

  static bool FledgeAuctionDealSupportEnabled() {
    return feature_states_[kFledgeAuctionDealSupportFlagIndex];
  }

  static bool FledgeAuctionDealSupportEnabled(const FeatureContext*) { return FledgeAuctionDealSupportEnabled(); }

  static bool FledgeBiddingAndAuctionServerAPIMultiSellerEnabled() {
    return feature_states_[kFledgeBiddingAndAuctionServerAPIMultiSellerFlagIndex];
  }

  static bool FledgeBiddingAndAuctionServerAPIMultiSellerEnabled(const FeatureContext*) { return FledgeBiddingAndAuctionServerAPIMultiSellerEnabled(); }

  static bool FledgeClickinessEnabled() {
    return feature_states_[kFledgeClickinessFlagIndex];
  }

  static bool FledgeClickinessEnabled(const FeatureContext*) { return FledgeClickinessEnabled(); }

  static bool FledgeCustomMaxAuctionAdComponentsEnabled() {
    return feature_states_[kFledgeCustomMaxAuctionAdComponentsFlagIndex];
  }

  static bool FledgeCustomMaxAuctionAdComponentsEnabled(const FeatureContext*) { return FledgeCustomMaxAuctionAdComponentsEnabled(); }

  static bool FledgeDeprecatedRenderURLReplacementsEnabled() {
    return feature_states_[kFledgeDeprecatedRenderURLReplacementsFlagIndex];
  }

  static bool FledgeDeprecatedRenderURLReplacementsEnabled(const FeatureContext*) { return FledgeDeprecatedRenderURLReplacementsEnabled(); }

  static bool FledgeDirectFromSellerSignalsHeaderAdSlotEnabled() {
    return feature_states_[kFledgeDirectFromSellerSignalsHeaderAdSlotFlagIndex];
  }

  static bool FledgeDirectFromSellerSignalsHeaderAdSlotEnabled(const FeatureContext*) { return FledgeDirectFromSellerSignalsHeaderAdSlotEnabled(); }

  static bool FledgeDirectFromSellerSignalsWebBundlesEnabled() {
    return feature_states_[kFledgeDirectFromSellerSignalsWebBundlesFlagIndex];
  }

  static bool FledgeDirectFromSellerSignalsWebBundlesEnabled(const FeatureContext*) { return FledgeDirectFromSellerSignalsWebBundlesEnabled(); }

  static bool FledgeMultiBidEnabled() {
    return feature_states_[kFledgeMultiBidFlagIndex];
  }

  static bool FledgeMultiBidEnabled(const FeatureContext*) { return FledgeMultiBidEnabled(); }

  static bool FledgePrivateModelTrainingEnabled() {
    return feature_states_[kFledgePrivateModelTrainingFlagIndex];
  }

  static bool FledgePrivateModelTrainingEnabled(const FeatureContext*) { return FledgePrivateModelTrainingEnabled(); }

  static bool FledgeRealTimeReportingEnabled() {
    return feature_states_[kFledgeRealTimeReportingFlagIndex];
  }

  static bool FledgeRealTimeReportingEnabled(const FeatureContext*) { return FledgeRealTimeReportingEnabled(); }

  static bool FledgeSellerNonceEnabled() {
    return feature_states_[kFledgeSellerNonceFlagIndex];
  }

  static bool FledgeSellerNonceEnabled(const FeatureContext*) { return FledgeSellerNonceEnabled(); }

  static bool FledgeSellerScriptExecutionModeEnabled() {
    return feature_states_[kFledgeSellerScriptExecutionModeFlagIndex];
  }

  static bool FledgeSellerScriptExecutionModeEnabled(const FeatureContext*) { return FledgeSellerScriptExecutionModeEnabled(); }

  static bool FledgeTrustedSignalsKVv1CreativeScanningEnabled() {
    return feature_states_[kFledgeTrustedSignalsKVv1CreativeScanningFlagIndex];
  }

  static bool FledgeTrustedSignalsKVv1CreativeScanningEnabled(const FeatureContext*) { return FledgeTrustedSignalsKVv1CreativeScanningEnabled(); }

  static bool FledgeTrustedSignalsKVv2ContextualDataEnabled() {
    if (!FledgeTrustedSignalsKVv2SupportEnabled())
      return false;
    return feature_states_[kFledgeTrustedSignalsKVv2ContextualDataFlagIndex];
  }

  static bool FledgeTrustedSignalsKVv2ContextualDataEnabled(const FeatureContext*) { return FledgeTrustedSignalsKVv2ContextualDataEnabled(); }

  static bool FledgeTrustedSignalsKVv2SupportEnabled() {
    return feature_states_[kFledgeTrustedSignalsKVv2SupportFlagIndex];
  }

  static bool FledgeTrustedSignalsKVv2SupportEnabled(const FeatureContext*) { return FledgeTrustedSignalsKVv2SupportEnabled(); }

  static bool FlexWrapBalanceEnabled() {
    return feature_states_[kFlexWrapBalanceFlagIndex];
  }

  static bool FlexWrapBalanceEnabled(const FeatureContext*) { return FlexWrapBalanceEnabled(); }

  static bool FocusgroupEnabled() {
    return feature_states_[kFocusgroupFlagIndex];
  }

  static bool FocusgroupEnabled(const FeatureContext*) { return FocusgroupEnabled(); }

  static bool FocusgroupV2Enabled() {
    if (!FocusgroupEnabled())
      return false;
    return feature_states_[kFocusgroupV2FlagIndex];
  }

  static bool FocusgroupV2Enabled(const FeatureContext*) { return FocusgroupV2Enabled(); }

  static bool FocusRingRespectExplicitOutlineColorInDarkModeEnabled() {
    return feature_states_[kFocusRingRespectExplicitOutlineColorInDarkModeFlagIndex];
  }

  static bool FocusRingRespectExplicitOutlineColorInDarkModeEnabled(const FeatureContext*) { return FocusRingRespectExplicitOutlineColorInDarkModeEnabled(); }

  static bool FontAccessEnabled() {
    return feature_states_[kFontAccessFlagIndex];
  }

  static bool FontAccessEnabled(const FeatureContext*) { return FontAccessEnabled(); }

  static bool FontationsPrintingEnabled() {
    return feature_states_[kFontationsPrintingFlagIndex];
  }

  static bool FontationsPrintingEnabled(const FeatureContext*) { return FontationsPrintingEnabled(); }

  static bool FontDataServiceForCSSLocalFontsEnabled() {
    return feature_states_[kFontDataServiceForCSSLocalFontsFlagIndex];
  }

  static bool FontDataServiceForCSSLocalFontsEnabled(const FeatureContext*) { return FontDataServiceForCSSLocalFontsEnabled(); }

  static bool FontFallbackForTabSizeEnabled() {
    return feature_states_[kFontFallbackForTabSizeFlagIndex];
  }

  static bool FontFallbackForTabSizeEnabled(const FeatureContext*) { return FontFallbackForTabSizeEnabled(); }

  static bool FontFamilyPostscriptMatchingCTMigrationEnabled() {
    return feature_states_[kFontFamilyPostscriptMatchingCTMigrationFlagIndex];
  }

  static bool FontFamilyPostscriptMatchingCTMigrationEnabled(const FeatureContext*) { return FontFamilyPostscriptMatchingCTMigrationEnabled(); }

  static bool FontFamilyStyleMatchingCTMigrationEnabled() {
    return feature_states_[kFontFamilyStyleMatchingCTMigrationFlagIndex];
  }

  static bool FontFamilyStyleMatchingCTMigrationEnabled(const FeatureContext*) { return FontFamilyStyleMatchingCTMigrationEnabled(); }

  static bool FontFeatureSettingsDescriptorEnabled() {
    return feature_states_[kFontFeatureSettingsDescriptorFlagIndex];
  }

  static bool FontFeatureSettingsDescriptorEnabled(const FeatureContext*) { return FontFeatureSettingsDescriptorEnabled(); }

  static bool FontFormatAvar2Enabled() {
    return feature_states_[kFontFormatAvar2FlagIndex];
  }

  static bool FontFormatAvar2Enabled(const FeatureContext*) { return FontFormatAvar2Enabled(); }

  static bool FontLanguageOverrideEnabled() {
    return feature_states_[kFontLanguageOverrideFlagIndex];
  }

  static bool FontLanguageOverrideEnabled(const FeatureContext*) { return FontLanguageOverrideEnabled(); }

  static bool FontMatchAliasesAsLastResortEnabled() {
    return feature_states_[kFontMatchAliasesAsLastResortFlagIndex];
  }

  static bool FontMatchAliasesAsLastResortEnabled(const FeatureContext*) { return FontMatchAliasesAsLastResortEnabled(); }

  static bool FontPrewarmerShutdownFallbackEnabled() {
    return feature_states_[kFontPrewarmerShutdownFallbackFlagIndex];
  }

  static bool FontPrewarmerShutdownFallbackEnabled(const FeatureContext*) { return FontPrewarmerShutdownFallbackEnabled(); }

  static bool FontStyleObliqueZeroDegreeAsNormalEnabled() {
    return feature_states_[kFontStyleObliqueZeroDegreeAsNormalFlagIndex];
  }

  static bool FontStyleObliqueZeroDegreeAsNormalEnabled(const FeatureContext*) { return FontStyleObliqueZeroDegreeAsNormalEnabled(); }

  static bool FontVariationSettingsDescriptorEnabled() {
    return feature_states_[kFontVariationSettingsDescriptorFlagIndex];
  }

  static bool FontVariationSettingsDescriptorEnabled(const FeatureContext*) { return FontVariationSettingsDescriptorEnabled(); }

  static bool ForcedColorsEnabled() {
    return feature_states_[kForcedColorsFlagIndex];
  }

  static bool ForcedColorsEnabled(const FeatureContext*) { return ForcedColorsEnabled(); }

  static bool ForceEagerMeasureMemoryEnabled() {
    return feature_states_[kForceEagerMeasureMemoryFlagIndex];
  }

  static bool ForceEagerMeasureMemoryEnabled(const FeatureContext*) { return ForceEagerMeasureMemoryEnabled(); }

  static bool ForceReduceMotionEnabled() {
    return feature_states_[kForceReduceMotionFlagIndex];
  }

  static bool ForceReduceMotionEnabled(const FeatureContext*) { return ForceReduceMotionEnabled(); }

  static bool ForwardReasonToFetchBodyAbortEnabled() {
    return feature_states_[kForwardReasonToFetchBodyAbortFlagIndex];
  }

  static bool ForwardReasonToFetchBodyAbortEnabled(const FeatureContext*) { return ForwardReasonToFetchBodyAbortEnabled(); }

  static bool FractionalScrollOffsetsEnabled() {
    if (FractionalScrollOffsetsForWebAPIEnabled())
      return true;
    return feature_states_[kFractionalScrollOffsetsFlagIndex];
  }

  static bool FractionalScrollOffsetsEnabled(const FeatureContext*) { return FractionalScrollOffsetsEnabled(); }

  static bool FractionalScrollOffsetsForWebAPIEnabled() {
    return feature_states_[kFractionalScrollOffsetsForWebAPIFlagIndex];
  }

  static bool FractionalScrollOffsetsForWebAPIEnabled(const FeatureContext*) { return FractionalScrollOffsetsForWebAPIEnabled(); }

  static bool FragmentedOofInCbEnabled() {
    return feature_states_[kFragmentedOofInCbFlagIndex];
  }

  static bool FragmentedOofInCbEnabled(const FeatureContext*) { return FragmentedOofInCbEnabled(); }

  static bool FrameSerializerNoWebEntitiesEnabled() {
    return feature_states_[kFrameSerializerNoWebEntitiesFlagIndex];
  }

  static bool FrameSerializerNoWebEntitiesEnabled(const FeatureContext*) { return FrameSerializerNoWebEntitiesEnabled(); }

  static bool FreezeFramesOnVisibilityEnabled() {
    return feature_states_[kFreezeFramesOnVisibilityFlagIndex];
  }

  static bool FreezeFramesOnVisibilityEnabled(const FeatureContext*) { return FreezeFramesOnVisibilityEnabled(); }

  static bool GamepadButtonTypesEnabled() {
    return feature_states_[kGamepadButtonTypesFlagIndex];
  }

  static bool GamepadButtonTypesEnabled(const FeatureContext*) { return GamepadButtonTypesEnabled(); }

  static bool GamepadMultitouchEnabled() {
    return feature_states_[kGamepadMultitouchFlagIndex];
  }

  static bool GamepadMultitouchEnabled(const FeatureContext*) { return GamepadMultitouchEnabled(); }

  static bool GamepadWindowEventHandlersEnabled() {
    return feature_states_[kGamepadWindowEventHandlersFlagIndex];
  }

  static bool GamepadWindowEventHandlersEnabled(const FeatureContext*) { return GamepadWindowEventHandlersEnabled(); }

  static bool GenerateDragOverlayBeforeDragStartEnabled() {
    return feature_states_[kGenerateDragOverlayBeforeDragStartFlagIndex];
  }

  static bool GenerateDragOverlayBeforeDragStartEnabled(const FeatureContext*) { return GenerateDragOverlayBeforeDragStartEnabled(); }

  static bool GenerateXSLTWarningBannerEnabled() {
    return feature_states_[kGenerateXSLTWarningBannerFlagIndex];
  }

  static bool GenerateXSLTWarningBannerEnabled(const FeatureContext*) { return GenerateXSLTWarningBannerEnabled(); }

  static bool GeolocationElementEnabled() {
    return feature_states_[kGeolocationElementFlagIndex];
  }

  static bool GeolocationElementEnabled(const FeatureContext*) { return GeolocationElementEnabled(); }

  static bool GeometryMapperSingularTransformFixEnabled() {
    return feature_states_[kGeometryMapperSingularTransformFixFlagIndex];
  }

  static bool GeometryMapperSingularTransformFixEnabled(const FeatureContext*) { return GeometryMapperSingularTransformFixEnabled(); }

  static bool GeometryUtilsEnabled() {
    return feature_states_[kGeometryUtilsFlagIndex];
  }

  static bool GeometryUtilsEnabled(const FeatureContext*) { return GeometryUtilsEnabled(); }

  static bool GeometryUtilsForCSSPseudoElementEnabled() {
    if (!CSSPseudoElementInterfaceEnabled())
      return false;
    return feature_states_[kGeometryUtilsForCSSPseudoElementFlagIndex];
  }

  static bool GeometryUtilsForCSSPseudoElementEnabled(const FeatureContext*) { return GeometryUtilsForCSSPseudoElementEnabled(); }

  static bool GetAllScreensMediaEnabled() {
    if (!GetDisplayMediaEnabled())
      return false;
    return feature_states_[kGetAllScreensMediaFlagIndex];
  }

  static bool GetAllScreensMediaEnabled(const FeatureContext*) { return GetAllScreensMediaEnabled(); }

  static bool GetDisplayMediaEnabled() {
    return feature_states_[kGetDisplayMediaFlagIndex];
  }

  static bool GetDisplayMediaEnabled(const FeatureContext*) { return GetDisplayMediaEnabled(); }

  static bool GetDisplayMediaAudioSelectionEnabled() {
    if (!GetDisplayMediaEnabled())
      return false;
    return feature_states_[kGetDisplayMediaAudioSelectionFlagIndex];
  }

  static bool GetDisplayMediaAudioSelectionEnabled(const FeatureContext*) { return GetDisplayMediaAudioSelectionEnabled(); }

  static bool GetDisplayMediaRequiresUserActivationEnabled() {
    if (!GetDisplayMediaEnabled())
      return false;
    return feature_states_[kGetDisplayMediaRequiresUserActivationFlagIndex];
  }

  static bool GetDisplayMediaRequiresUserActivationEnabled(const FeatureContext*) { return GetDisplayMediaRequiresUserActivationEnabled(); }

  static bool GetDisplayMediaWindowAudioCaptureEnabled() {
    return feature_states_[kGetDisplayMediaWindowAudioCaptureFlagIndex];
  }

  static bool GetDisplayMediaWindowAudioCaptureEnabled(const FeatureContext*);

  static bool GetElementsByNameOnlyHTMLElementsEnabled() {
    return feature_states_[kGetElementsByNameOnlyHTMLElementsFlagIndex];
  }

  static bool GetElementsByNameOnlyHTMLElementsEnabled(const FeatureContext*) { return GetElementsByNameOnlyHTMLElementsEnabled(); }

  static bool GetUserMediaEchoCancellationModesEnabled() {
    return feature_states_[kGetUserMediaEchoCancellationModesFlagIndex];
  }

  static bool GetUserMediaEchoCancellationModesEnabled(const FeatureContext*) { return GetUserMediaEchoCancellationModesEnabled(); }

  static bool GlobalPrivacyControlEnabled() {
    if (GlobalPrivacyControlForceEnabled())
      return true;
    if (GlobalPrivacyControlTestEnabled())
      return true;
    return feature_states_[kGlobalPrivacyControlFlagIndex];
  }

  static bool GlobalPrivacyControlEnabled(const FeatureContext*) { return GlobalPrivacyControlEnabled(); }

  static bool GlobalPrivacyControlForceEnabled() {
    return feature_states_[kGlobalPrivacyControlForceFlagIndex];
  }

  static bool GlobalPrivacyControlForceEnabled(const FeatureContext*) { return GlobalPrivacyControlForceEnabled(); }

  static bool GlobalPrivacyControlTestEnabled() {
    return feature_states_[kGlobalPrivacyControlTestFlagIndex];
  }

  static bool GlobalPrivacyControlTestEnabled(const FeatureContext*) { return GlobalPrivacyControlTestEnabled(); }

  static bool GraphemeClusterBoundsCheckEnabled() {
    return feature_states_[kGraphemeClusterBoundsCheckFlagIndex];
  }

  static bool GraphemeClusterBoundsCheckEnabled(const FeatureContext*) { return GraphemeClusterBoundsCheckEnabled(); }

  static bool GroupEffectEnabled() {
    return feature_states_[kGroupEffectFlagIndex];
  }

  static bool GroupEffectEnabled(const FeatureContext*) { return GroupEffectEnabled(); }

  static bool HandleShadowDOMInSubstringUtilEnabled() {
    return feature_states_[kHandleShadowDOMInSubstringUtilFlagIndex];
  }

  static bool HandleShadowDOMInSubstringUtilEnabled(const FeatureContext*) { return HandleShadowDOMInSubstringUtilEnabled(); }

  static bool HandwritingRecognitionEnabled() {
    return feature_states_[kHandwritingRecognitionFlagIndex];
  }

  static bool HandwritingRecognitionEnabled(const FeatureContext*) { return HandwritingRecognitionEnabled(); }

  static bool HarfRustShapingEnabled() {
    return feature_states_[kHarfRustShapingFlagIndex];
  }

  static bool HarfRustShapingEnabled(const FeatureContext*) { return HarfRustShapingEnabled(); }

  static bool HasUAVisualTransitionEnabled() {
    return feature_states_[kHasUAVisualTransitionFlagIndex];
  }

  static bool HasUAVisualTransitionEnabled(const FeatureContext*) { return HasUAVisualTransitionEnabled(); }

  static bool HeadingOffsetEnabled() {
    return feature_states_[kHeadingOffsetFlagIndex];
  }

  static bool HeadingOffsetEnabled(const FeatureContext*) { return HeadingOffsetEnabled(); }

  static bool HideVideoControlsWhenUnneededEnabled() {
    return feature_states_[kHideVideoControlsWhenUnneededFlagIndex];
  }

  static bool HideVideoControlsWhenUnneededEnabled(const FeatureContext*) { return HideVideoControlsWhenUnneededEnabled(); }

  static bool HighlightsFromPointEnabled() {
    return feature_states_[kHighlightsFromPointFlagIndex];
  }

  static bool HighlightsFromPointEnabled(const FeatureContext*) { return HighlightsFromPointEnabled(); }

  static bool HitTestBorderRadiusForStackingContextEnabled() {
    return feature_states_[kHitTestBorderRadiusForStackingContextFlagIndex];
  }

  static bool HitTestBorderRadiusForStackingContextEnabled(const FeatureContext*) { return HitTestBorderRadiusForStackingContextEnabled(); }

  static bool HitTestContainerTransformStateForPreserve3dEnabled() {
    return feature_states_[kHitTestContainerTransformStateForPreserve3dFlagIndex];
  }

  static bool HitTestContainerTransformStateForPreserve3dEnabled(const FeatureContext*) { return HitTestContainerTransformStateForPreserve3dEnabled(); }

  static bool HstsTopLevelNavigationsOnlyEnabled() {
    return feature_states_[kHstsTopLevelNavigationsOnlyFlagIndex];
  }

  static bool HstsTopLevelNavigationsOnlyEnabled(const FeatureContext*) { return HstsTopLevelNavigationsOnlyEnabled(); }

  static bool HTMLAdoptionAlgorithmNewStepsEnabled() {
    return feature_states_[kHTMLAdoptionAlgorithmNewStepsFlagIndex];
  }

  static bool HTMLAdoptionAlgorithmNewStepsEnabled(const FeatureContext*) { return HTMLAdoptionAlgorithmNewStepsEnabled(); }

  static bool HTMLAreaElementDisplayNoneEnabled() {
    return feature_states_[kHTMLAreaElementDisplayNoneFlagIndex];
  }

  static bool HTMLAreaElementDisplayNoneEnabled(const FeatureContext*) { return HTMLAreaElementDisplayNoneEnabled(); }

  static bool HTMLAreaHreflangTypeEnabled() {
    return feature_states_[kHTMLAreaHreflangTypeFlagIndex];
  }

  static bool HTMLAreaHreflangTypeEnabled(const FeatureContext*) { return HTMLAreaHreflangTypeEnabled(); }

  static bool HTMLBodyMarginPixelLengthEnabled() {
    return feature_states_[kHTMLBodyMarginPixelLengthFlagIndex];
  }

  static bool HTMLBodyMarginPixelLengthEnabled(const FeatureContext*) { return HTMLBodyMarginPixelLengthEnabled(); }

  static bool HTMLCommandActionsV2Enabled() {
    return feature_states_[kHTMLCommandActionsV2FlagIndex];
  }

  static bool HTMLCommandActionsV2Enabled(const FeatureContext*) { return HTMLCommandActionsV2Enabled(); }

  static bool HTMLCommandElementRemovalEnabled() {
    return feature_states_[kHTMLCommandElementRemovalFlagIndex];
  }

  static bool HTMLCommandElementRemovalEnabled(const FeatureContext*) { return HTMLCommandElementRemovalEnabled(); }

  static bool HTMLCommandForScrollCommandsEnabled() {
    return feature_states_[kHTMLCommandForScrollCommandsFlagIndex];
  }

  static bool HTMLCommandForScrollCommandsEnabled(const FeatureContext*) { return HTMLCommandForScrollCommandsEnabled(); }

  static bool HTMLElementScrollParentEnabled() {
    return feature_states_[kHTMLElementScrollParentFlagIndex];
  }

  static bool HTMLElementScrollParentEnabled(const FeatureContext*) { return HTMLElementScrollParentEnabled(); }

  static bool HTMLInputElementDropWebkitClearButtonEnabled() {
    return feature_states_[kHTMLInputElementDropWebkitClearButtonFlagIndex];
  }

  static bool HTMLInputElementDropWebkitClearButtonEnabled(const FeatureContext*) { return HTMLInputElementDropWebkitClearButtonEnabled(); }

  static bool HTMLInterestForInterestButtonPseudoEnabled() {
    return feature_states_[kHTMLInterestForInterestButtonPseudoFlagIndex];
  }

  static bool HTMLInterestForInterestButtonPseudoEnabled(const FeatureContext*) { return HTMLInterestForInterestButtonPseudoEnabled(); }

  static bool HTMLLinkElementAttributeValueChangesEnabled() {
    return feature_states_[kHTMLLinkElementAttributeValueChangesFlagIndex];
  }

  static bool HTMLLinkElementAttributeValueChangesEnabled(const FeatureContext*) { return HTMLLinkElementAttributeValueChangesEnabled(); }

  static bool HTMLParserTruncatedMarkupDeclarationEnabled() {
    return feature_states_[kHTMLParserTruncatedMarkupDeclarationFlagIndex];
  }

  static bool HTMLParserTruncatedMarkupDeclarationEnabled(const FeatureContext*) { return HTMLParserTruncatedMarkupDeclarationEnabled(); }

  static bool HTMLParserYieldAndDelayOftenForTestingEnabled() {
    return feature_states_[kHTMLParserYieldAndDelayOftenForTestingFlagIndex];
  }

  static bool HTMLParserYieldAndDelayOftenForTestingEnabled(const FeatureContext*) { return HTMLParserYieldAndDelayOftenForTestingEnabled(); }

  static bool HTMLParserYieldByUserTimingEnabled() {
    return feature_states_[kHTMLParserYieldByUserTimingFlagIndex];
  }

  static bool HTMLParserYieldByUserTimingEnabled(const FeatureContext*) { return HTMLParserYieldByUserTimingEnabled(); }

  static bool HTMLPrintingArtifactAnnotationsEnabled() {
    return feature_states_[kHTMLPrintingArtifactAnnotationsFlagIndex];
  }

  static bool HTMLPrintingArtifactAnnotationsEnabled(const FeatureContext*) { return HTMLPrintingArtifactAnnotationsEnabled(); }

  static bool HTMLProcessingInstructionEnabled() {
    return feature_states_[kHTMLProcessingInstructionFlagIndex];
  }

  static bool HTMLProcessingInstructionEnabled(const FeatureContext*) { return HTMLProcessingInstructionEnabled(); }

  static bool HTMLSwitchAttributeEnabled() {
    return feature_states_[kHTMLSwitchAttributeFlagIndex];
  }

  static bool HTMLSwitchAttributeEnabled(const FeatureContext*) { return HTMLSwitchAttributeEnabled(); }

  static bool ICUCapitalizationEnabled() {
    return feature_states_[kICUCapitalizationFlagIndex];
  }

  static bool ICUCapitalizationEnabled(const FeatureContext*) { return ICUCapitalizationEnabled(); }

  static bool IgnoreLetterSpacingInCursiveScriptsEnabled() {
    return feature_states_[kIgnoreLetterSpacingInCursiveScriptsFlagIndex];
  }

  static bool IgnoreLetterSpacingInCursiveScriptsEnabled(const FeatureContext*) { return IgnoreLetterSpacingInCursiveScriptsEnabled(); }

  static bool ImageDataPixelFormatEnabled() {
    return feature_states_[kImageDataPixelFormatFlagIndex];
  }

  static bool ImageDataPixelFormatEnabled(const FeatureContext*) { return ImageDataPixelFormatEnabled(); }

  static bool ImageDocumentUseLayoutWidthEnabled() {
    return feature_states_[kImageDocumentUseLayoutWidthFlagIndex];
  }

  static bool ImageDocumentUseLayoutWidthEnabled(const FeatureContext*) { return ImageDocumentUseLayoutWidthEnabled(); }

  static bool ImageSrcsetReselectionEnabled() {
    return feature_states_[kImageSrcsetReselectionFlagIndex];
  }

  static bool ImageSrcsetReselectionEnabled(const FeatureContext*) { return ImageSrcsetReselectionEnabled(); }

  static bool ImplicitRootScrollerEnabled() {
    return feature_states_[kImplicitRootScrollerFlagIndex];
  }

  static bool ImplicitRootScrollerEnabled(const FeatureContext*) { return ImplicitRootScrollerEnabled(); }

  static bool IncrementalFontTransferEnabled() {
    return feature_states_[kIncrementalFontTransferFlagIndex];
  }

  static bool IncrementalFontTransferEnabled(const FeatureContext*) { return IncrementalFontTransferEnabled(); }

  static bool InertElementNonEditableEnabled() {
    return feature_states_[kInertElementNonEditableFlagIndex];
  }

  static bool InertElementNonEditableEnabled(const FeatureContext*) { return InertElementNonEditableEnabled(); }

  static bool InfiniteCullRectEnabled() {
    return feature_states_[kInfiniteCullRectFlagIndex];
  }

  static bool InfiniteCullRectEnabled(const FeatureContext*) { return InfiniteCullRectEnabled(); }

  static bool InheritUserModifyWithoutContenteditableEnabled() {
    return feature_states_[kInheritUserModifyWithoutContenteditableFlagIndex];
  }

  static bool InheritUserModifyWithoutContenteditableEnabled(const FeatureContext*) { return InheritUserModifyWithoutContenteditableEnabled(); }

  static bool InlineBlockLineNavigationEnabled() {
    return feature_states_[kInlineBlockLineNavigationFlagIndex];
  }

  static bool InlineBlockLineNavigationEnabled(const FeatureContext*) { return InlineBlockLineNavigationEnabled(); }

  static bool InlineCursorSkipNonIfcEnabled() {
    return feature_states_[kInlineCursorSkipNonIfcFlagIndex];
  }

  static bool InlineCursorSkipNonIfcEnabled(const FeatureContext*) { return InlineCursorSkipNonIfcEnabled(); }

  static bool InlineScriptCacheHintEnabled() {
    return feature_states_[kInlineScriptCacheHintFlagIndex];
  }

  static bool InlineScriptCacheHintEnabled(const FeatureContext*) { return InlineScriptCacheHintEnabled(); }

  static bool InnerHTMLParserFastpathLogFailureEnabled() {
    return feature_states_[kInnerHTMLParserFastpathLogFailureFlagIndex];
  }

  static bool InnerHTMLParserFastpathLogFailureEnabled(const FeatureContext*) { return InnerHTMLParserFastpathLogFailureEnabled(); }

  static bool InputDisabledHandlerFixEnabled() {
    return feature_states_[kInputDisabledHandlerFixFlagIndex];
  }

  static bool InputDisabledHandlerFixEnabled(const FeatureContext*) { return InputDisabledHandlerFixEnabled(); }

  static bool InputInSelectEnabled() {
    return feature_states_[kInputInSelectFlagIndex];
  }

  static bool InputInSelectEnabled(const FeatureContext*) { return InputInSelectEnabled(); }

  static bool InputMultipleFieldsUIEnabled() {
    if (InputMultipleFieldsUIWithPointerChecksEnabled())
      return true;
    return feature_states_[kInputMultipleFieldsUIFlagIndex];
  }

  static bool InputMultipleFieldsUIEnabled(const FeatureContext*) { return InputMultipleFieldsUIEnabled(); }

  static bool InputMultipleFieldsUIWithPointerChecksEnabled() {
    return feature_states_[kInputMultipleFieldsUIWithPointerChecksFlagIndex];
  }

  static bool InputMultipleFieldsUIWithPointerChecksEnabled(const FeatureContext*) { return InputMultipleFieldsUIWithPointerChecksEnabled(); }

  static bool InputTypeColorEnhancementsEnabled() {
    return feature_states_[kInputTypeColorEnhancementsFlagIndex];
  }

  static bool InputTypeColorEnhancementsEnabled(const FeatureContext*) { return InputTypeColorEnhancementsEnabled(); }

  static bool InsertBlockquoteBeforeOuterBlockEnabled() {
    return feature_states_[kInsertBlockquoteBeforeOuterBlockFlagIndex];
  }

  static bool InsertBlockquoteBeforeOuterBlockEnabled(const FeatureContext*) { return InsertBlockquoteBeforeOuterBlockEnabled(); }

  static bool InstalledAppEnabled() {
    return feature_states_[kInstalledAppFlagIndex];
  }

  static bool InstalledAppEnabled(const FeatureContext*) { return InstalledAppEnabled(); }

  static bool InstallOnDeviceSpeechRecognitionEnabled() {
    return feature_states_[kInstallOnDeviceSpeechRecognitionFlagIndex];
  }

  static bool InstallOnDeviceSpeechRecognitionEnabled(const FeatureContext*) { return InstallOnDeviceSpeechRecognitionEnabled(); }

  static bool IntegrityPolicyScriptEnabled() {
    return feature_states_[kIntegrityPolicyScriptFlagIndex];
  }

  static bool IntegrityPolicyScriptEnabled(const FeatureContext*) { return IntegrityPolicyScriptEnabled(); }

  static bool InterestEventsNonComposedEnabled() {
    return feature_states_[kInterestEventsNonComposedFlagIndex];
  }

  static bool InterestEventsNonComposedEnabled(const FeatureContext*) { return InterestEventsNonComposedEnabled(); }

  static bool InterestGroupsInSharedStorageWorkletEnabled() {
    return feature_states_[kInterestGroupsInSharedStorageWorkletFlagIndex];
  }

  static bool InterestGroupsInSharedStorageWorkletEnabled(const FeatureContext*) { return InterestGroupsInSharedStorageWorkletEnabled(); }

  static bool IntersectionObserverCompositedAnimationsForceMainFramesEnabled() {
    return feature_states_[kIntersectionObserverCompositedAnimationsForceMainFramesFlagIndex];
  }

  static bool IntersectionObserverCompositedAnimationsForceMainFramesEnabled(const FeatureContext*) { return IntersectionObserverCompositedAnimationsForceMainFramesEnabled(); }

  static bool InvertedColorsEnabled() {
    return feature_states_[kInvertedColorsFlagIndex];
  }

  static bool InvertedColorsEnabled(const FeatureContext*) { return InvertedColorsEnabled(); }

  static bool InvisibleSVGAnimationThrottlingEnabled() {
    return feature_states_[kInvisibleSVGAnimationThrottlingFlagIndex];
  }

  static bool InvisibleSVGAnimationThrottlingEnabled(const FeatureContext*) { return InvisibleSVGAnimationThrottlingEnabled(); }

  static bool JavaScriptImportTextEnabled() {
    return feature_states_[kJavaScriptImportTextFlagIndex];
  }

  static bool JavaScriptImportTextEnabled(const FeatureContext*) { return JavaScriptImportTextEnabled(); }

  static bool JavaScriptSourcePhaseImportsEnabled() {
    return feature_states_[kJavaScriptSourcePhaseImportsFlagIndex];
  }

  static bool JavaScriptSourcePhaseImportsEnabled(const FeatureContext*) { return JavaScriptSourcePhaseImportsEnabled(); }

  static bool KeyboardAccessibleTooltipEnabled() {
    return feature_states_[kKeyboardAccessibleTooltipFlagIndex];
  }

  static bool KeyboardAccessibleTooltipEnabled(const FeatureContext*) { return KeyboardAccessibleTooltipEnabled(); }

  static bool KeySystemTrackConfigurationEncryptionSchemeEnabled() {
    return feature_states_[kKeySystemTrackConfigurationEncryptionSchemeFlagIndex];
  }

  static bool KeySystemTrackConfigurationEncryptionSchemeEnabled(const FeatureContext*) { return KeySystemTrackConfigurationEncryptionSchemeEnabled(); }

  static bool LabelInteractiveContentCheckBeforeHandlerEnabled() {
    return feature_states_[kLabelInteractiveContentCheckBeforeHandlerFlagIndex];
  }

  static bool LabelInteractiveContentCheckBeforeHandlerEnabled(const FeatureContext*) { return LabelInteractiveContentCheckBeforeHandlerEnabled(); }

  static bool LangAttributeAwareFormControlUIEnabled() {
    return feature_states_[kLangAttributeAwareFormControlUIFlagIndex];
  }

  static bool LangAttributeAwareFormControlUIEnabled(const FeatureContext*) { return LangAttributeAwareFormControlUIEnabled(); }

  static bool LanguageDetectionAPIEnabled() {
    return feature_states_[kLanguageDetectionAPIFlagIndex];
  }

  static bool LanguageDetectionAPIEnabled(const FeatureContext*) { return LanguageDetectionAPIEnabled(); }

  static bool LanguageDetectionAPIForWorkersEnabled() {
    return feature_states_[kLanguageDetectionAPIForWorkersFlagIndex];
  }

  static bool LanguageDetectionAPIForWorkersEnabled(const FeatureContext*) { return LanguageDetectionAPIForWorkersEnabled(); }

  static bool LayoutIgnoreMarginsForStickyEnabled() {
    return feature_states_[kLayoutIgnoreMarginsForStickyFlagIndex];
  }

  static bool LayoutIgnoreMarginsForStickyEnabled(const FeatureContext*) { return LayoutIgnoreMarginsForStickyEnabled(); }

  static bool LayoutOOFCollectInlinesFixEnabled() {
    return feature_states_[kLayoutOOFCollectInlinesFixFlagIndex];
  }

  static bool LayoutOOFCollectInlinesFixEnabled(const FeatureContext*) { return LayoutOOFCollectInlinesFixEnabled(); }

  static bool LayoutTableCellAlignmentSafeEnabled() {
    return feature_states_[kLayoutTableCellAlignmentSafeFlagIndex];
  }

  static bool LayoutTableCellAlignmentSafeEnabled(const FeatureContext*) { return LayoutTableCellAlignmentSafeEnabled(); }

  static bool LazyImageConformantLoadEventTimingEnabled() {
    return feature_states_[kLazyImageConformantLoadEventTimingFlagIndex];
  }

  static bool LazyImageConformantLoadEventTimingEnabled(const FeatureContext*) { return LazyImageConformantLoadEventTimingEnabled(); }

  static bool LazyLoadVideoAndAudioEnabled() {
    return feature_states_[kLazyLoadVideoAndAudioFlagIndex];
  }

  static bool LazyLoadVideoAndAudioEnabled(const FeatureContext*) { return LazyLoadVideoAndAudioEnabled(); }

  static bool LeftClickToHandleSuggestionEnabled() {
    return feature_states_[kLeftClickToHandleSuggestionFlagIndex];
  }

  static bool LeftClickToHandleSuggestionEnabled(const FeatureContext*) { return LeftClickToHandleSuggestionEnabled(); }

  static bool LegacyAbstractRangeEnabled() {
    return feature_states_[kLegacyAbstractRangeFlagIndex];
  }

  static bool LegacyAbstractRangeEnabled(const FeatureContext*) { return LegacyAbstractRangeEnabled(); }

  static bool LightDismissFromClickEnabled() {
    return feature_states_[kLightDismissFromClickFlagIndex];
  }

  static bool LightDismissFromClickEnabled(const FeatureContext*) { return LightDismissFromClickEnabled(); }

  static bool LineBreakAfterSpaceBeforeOpenTagEnabled() {
    return feature_states_[kLineBreakAfterSpaceBeforeOpenTagFlagIndex];
  }

  static bool LineBreakAfterSpaceBeforeOpenTagEnabled(const FeatureContext*) { return LineBreakAfterSpaceBeforeOpenTagEnabled(); }

  static bool LineBreakBidiControlEnterEnabled() {
    return feature_states_[kLineBreakBidiControlEnterFlagIndex];
  }

  static bool LineBreakBidiControlEnterEnabled(const FeatureContext*) { return LineBreakBidiControlEnterEnabled(); }

  static bool LineBreakerHanKerningEndEnabled() {
    return feature_states_[kLineBreakerHanKerningEndFlagIndex];
  }

  static bool LineBreakerHanKerningEndEnabled(const FeatureContext*) { return LineBreakerHanKerningEndEnabled(); }

  static bool ListOwnerMustHaveCSSBoxEnabled() {
    return feature_states_[kListOwnerMustHaveCSSBoxFlagIndex];
  }

  static bool ListOwnerMustHaveCSSBoxEnabled(const FeatureContext*) { return ListOwnerMustHaveCSSBoxEnabled(); }

  static bool LocalNetworkAccessPermissionPolicyEnabled() {
    return feature_states_[kLocalNetworkAccessPermissionPolicyFlagIndex];
  }

  static bool LocalNetworkAccessPermissionPolicyEnabled(const FeatureContext*) { return LocalNetworkAccessPermissionPolicyEnabled(); }

  static bool LocalNetworkAccessWebRTCEnabled() {
    return feature_states_[kLocalNetworkAccessWebRTCFlagIndex];
  }

  static bool LocalNetworkAccessWebRTCEnabled(const FeatureContext*) { return LocalNetworkAccessWebRTCEnabled(); }

  static bool LocalNetworkAccessWebSocketsTargetAddressSpaceEnabled() {
    if (!WebSocketOptionBagEnabled())
      return false;
    return feature_states_[kLocalNetworkAccessWebSocketsTargetAddressSpaceFlagIndex];
  }

  static bool LocalNetworkAccessWebSocketsTargetAddressSpaceEnabled(const FeatureContext*) { return LocalNetworkAccessWebSocketsTargetAddressSpaceEnabled(); }

  static bool LockedModeEnabled() {
    return feature_states_[kLockedModeFlagIndex];
  }

  static bool LockedModeEnabled(const FeatureContext*) { return LockedModeEnabled(); }

  static bool LoginElementEnabled() {
    if (!FedCmEnabled())
      return false;
    return feature_states_[kLoginElementFlagIndex];
  }

  static bool LoginElementEnabled(const FeatureContext*) { return LoginElementEnabled(); }

  static bool LongAnimationFrameSourceCharPositionEnabled() {
    return feature_states_[kLongAnimationFrameSourceCharPositionFlagIndex];
  }

  static bool LongAnimationFrameSourceCharPositionEnabled(const FeatureContext*) { return LongAnimationFrameSourceCharPositionEnabled(); }

  static bool LongAnimationFrameSourceLineColumnEnabled() {
    if (LongAnimationFrameSourceLineColumnInterfaceEnabled())
      return true;
    return feature_states_[kLongAnimationFrameSourceLineColumnFlagIndex];
  }

  static bool LongAnimationFrameSourceLineColumnEnabled(const FeatureContext*) { return LongAnimationFrameSourceLineColumnEnabled(); }

  static bool LongAnimationFrameSourceLineColumnInterfaceEnabled() {
    return feature_states_[kLongAnimationFrameSourceLineColumnInterfaceFlagIndex];
  }

  static bool LongAnimationFrameSourceLineColumnInterfaceEnabled(const FeatureContext*) { return LongAnimationFrameSourceLineColumnInterfaceEnabled(); }

  static bool LongAnimationFrameWorkerEnabled() {
    return feature_states_[kLongAnimationFrameWorkerFlagIndex];
  }

  static bool LongAnimationFrameWorkerEnabled(const FeatureContext*) { return LongAnimationFrameWorkerEnabled(); }

  static bool LongPressLinkSelectTextEnabled() {
    return feature_states_[kLongPressLinkSelectTextFlagIndex];
  }

  static bool LongPressLinkSelectTextEnabled(const FeatureContext*) { return LongPressLinkSelectTextEnabled(); }

  static bool LongTaskFromLongAnimationFrameEnabled() {
    return feature_states_[kLongTaskFromLongAnimationFrameFlagIndex];
  }

  static bool LongTaskFromLongAnimationFrameEnabled(const FeatureContext*) { return LongTaskFromLongAnimationFrameEnabled(); }

  static bool MacCharacterFallbackCacheEnabled() {
    return feature_states_[kMacCharacterFallbackCacheFlagIndex];
  }

  static bool MacCharacterFallbackCacheEnabled(const FeatureContext*) { return MacCharacterFallbackCacheEnabled(); }

  static bool MacDisableCtrlHomeEndEnabled() {
    return feature_states_[kMacDisableCtrlHomeEndFlagIndex];
  }

  static bool MacDisableCtrlHomeEndEnabled(const FeatureContext*) { return MacDisableCtrlHomeEndEnabled(); }

  static bool MachineLearningNeuralNetworkEnabled() {
    return feature_states_[kMachineLearningNeuralNetworkFlagIndex];
  }

  static bool MachineLearningNeuralNetworkEnabled(const FeatureContext*) { return MachineLearningNeuralNetworkEnabled(); }

  static bool ManagedConfigurationEnabled() {
    return feature_states_[kManagedConfigurationFlagIndex];
  }

  static bool ManagedConfigurationEnabled(const FeatureContext*) { return ManagedConfigurationEnabled(); }

  static bool ManualTextEnabled() {
    return feature_states_[kManualTextFlagIndex];
  }

  static bool ManualTextEnabled(const FeatureContext*) { return ManualTextEnabled(); }

  static bool MarginTrimEnabled() {
    return feature_states_[kMarginTrimFlagIndex];
  }

  static bool MarginTrimEnabled(const FeatureContext*) { return MarginTrimEnabled(); }

  static bool MaskDeserializationTimeForCrossOriginMessagesEnabled() {
    return feature_states_[kMaskDeserializationTimeForCrossOriginMessagesFlagIndex];
  }

  static bool MaskDeserializationTimeForCrossOriginMessagesEnabled(const FeatureContext*) { return MaskDeserializationTimeForCrossOriginMessagesEnabled(); }

  static bool MaskWaitForAllImagesEnabled() {
    return feature_states_[kMaskWaitForAllImagesFlagIndex];
  }

  static bool MaskWaitForAllImagesEnabled(const FeatureContext*) { return MaskWaitForAllImagesEnabled(); }

  static bool MathMLAnchorElementEnabled() {
    return feature_states_[kMathMLAnchorElementFlagIndex];
  }

  static bool MathMLAnchorElementEnabled(const FeatureContext*) { return MathMLAnchorElementEnabled(); }

  static bool MathMLOperatorRTLMirroringEnabled() {
    return feature_states_[kMathMLOperatorRTLMirroringFlagIndex];
  }

  static bool MathMLOperatorRTLMirroringEnabled(const FeatureContext*) { return MathMLOperatorRTLMirroringEnabled(); }

  static bool MeasureMemoryEnabled() {
    return feature_states_[kMeasureMemoryFlagIndex];
  }

  static bool MeasureMemoryEnabled(const FeatureContext*) { return MeasureMemoryEnabled(); }

  static bool MediaCapabilitiesEncodingInfoEnabled() {
    return feature_states_[kMediaCapabilitiesEncodingInfoFlagIndex];
  }

  static bool MediaCapabilitiesEncodingInfoEnabled(const FeatureContext*) { return MediaCapabilitiesEncodingInfoEnabled(); }

  static bool MediaCapabilitiesSpatialAudioEnabled() {
    return feature_states_[kMediaCapabilitiesSpatialAudioFlagIndex];
  }

  static bool MediaCapabilitiesSpatialAudioEnabled(const FeatureContext*) { return MediaCapabilitiesSpatialAudioEnabled(); }

  static bool MediaCaptionSettingsButtonEnabled() {
    return feature_states_[kMediaCaptionSettingsButtonFlagIndex];
  }

  static bool MediaCaptionSettingsButtonEnabled(const FeatureContext*) { return MediaCaptionSettingsButtonEnabled(); }

  static bool MediaCaptureEnabled() {
    return feature_states_[kMediaCaptureFlagIndex];
  }

  static bool MediaCaptureEnabled(const FeatureContext*) { return MediaCaptureEnabled(); }

  static bool MediaCaptureCameraControlsEnabled() {
    return feature_states_[kMediaCaptureCameraControlsFlagIndex];
  }

  static bool MediaCaptureCameraControlsEnabled(const FeatureContext*) { return MediaCaptureCameraControlsEnabled(); }

  static bool MediaCaptureVoiceIsolationEnabled() {
    return feature_states_[kMediaCaptureVoiceIsolationFlagIndex];
  }

  static bool MediaCaptureVoiceIsolationEnabled(const FeatureContext*) { return MediaCaptureVoiceIsolationEnabled(); }

  static bool MediaControlsExpandGestureEnabled() {
    return feature_states_[kMediaControlsExpandGestureFlagIndex];
  }

  static bool MediaControlsExpandGestureEnabled(const FeatureContext*) { return MediaControlsExpandGestureEnabled(); }

  static bool MediaControlsOverlayPlayButtonEnabled() {
    return feature_states_[kMediaControlsOverlayPlayButtonFlagIndex];
  }

  static bool MediaControlsOverlayPlayButtonEnabled(const FeatureContext*) { return MediaControlsOverlayPlayButtonEnabled(); }

  static bool MediaElementMutedDefaultStateEnabled() {
    return feature_states_[kMediaElementMutedDefaultStateFlagIndex];
  }

  static bool MediaElementMutedDefaultStateEnabled(const FeatureContext*) { return MediaElementMutedDefaultStateEnabled(); }

  static bool MediaElementVolumeGreaterThanOneEnabled() {
    return feature_states_[kMediaElementVolumeGreaterThanOneFlagIndex];
  }

  static bool MediaElementVolumeGreaterThanOneEnabled(const FeatureContext*) { return MediaElementVolumeGreaterThanOneEnabled(); }

  static bool MediaEngagementBypassAutoplayPoliciesEnabled() {
    return feature_states_[kMediaEngagementBypassAutoplayPoliciesFlagIndex];
  }

  static bool MediaEngagementBypassAutoplayPoliciesEnabled(const FeatureContext*) { return MediaEngagementBypassAutoplayPoliciesEnabled(); }

  static bool MediaLatencyHintEnabled() {
    return feature_states_[kMediaLatencyHintFlagIndex];
  }

  static bool MediaLatencyHintEnabled(const FeatureContext*) { return MediaLatencyHintEnabled(); }

  static bool MediaPlaybackWhileNotVisiblePermissionPolicyEnabled() {
    return feature_states_[kMediaPlaybackWhileNotVisiblePermissionPolicyFlagIndex];
  }

  static bool MediaPlaybackWhileNotVisiblePermissionPolicyEnabled(const FeatureContext*) { return MediaPlaybackWhileNotVisiblePermissionPolicyEnabled(); }

  static bool MediaQueryNavigationControlsEnabled() {
    return feature_states_[kMediaQueryNavigationControlsFlagIndex];
  }

  static bool MediaQueryNavigationControlsEnabled(const FeatureContext*) { return MediaQueryNavigationControlsEnabled(); }

  static bool MediaSessionEnabled() {
    return feature_states_[kMediaSessionFlagIndex];
  }

  static bool MediaSessionEnabled(const FeatureContext*) { return MediaSessionEnabled(); }

  static bool MediaSessionChapterInformationEnabled() {
    return feature_states_[kMediaSessionChapterInformationFlagIndex];
  }

  static bool MediaSessionChapterInformationEnabled(const FeatureContext*) { return MediaSessionChapterInformationEnabled(); }

  static bool MediaSourceExperimentalEnabled() {
    return feature_states_[kMediaSourceExperimentalFlagIndex];
  }

  static bool MediaSourceExperimentalEnabled(const FeatureContext*) { return MediaSourceExperimentalEnabled(); }

  static bool MediaStreamTrackProcessorStatsEnabled() {
    return feature_states_[kMediaStreamTrackProcessorStatsFlagIndex];
  }

  static bool MediaStreamTrackProcessorStatsEnabled(const FeatureContext*) { return MediaStreamTrackProcessorStatsEnabled(); }

  static bool MediaStreamTrackTransferEnabled() {
    return feature_states_[kMediaStreamTrackTransferFlagIndex];
  }

  static bool MediaStreamTrackTransferEnabled(const FeatureContext*) { return MediaStreamTrackTransferEnabled(); }

  static bool MediaStreamTrackWebSpeechEnabled() {
    return feature_states_[kMediaStreamTrackWebSpeechFlagIndex];
  }

  static bool MediaStreamTrackWebSpeechEnabled(const FeatureContext*) { return MediaStreamTrackWebSpeechEnabled(); }

  static bool MemoryConsumerForNGShapeCacheEnabled() {
    return feature_states_[kMemoryConsumerForNGShapeCacheFlagIndex];
  }

  static bool MemoryConsumerForNGShapeCacheEnabled(const FeatureContext*) { return MemoryConsumerForNGShapeCacheEnabled(); }

  static bool MenuElementsEnabled() {
    return feature_states_[kMenuElementsFlagIndex];
  }

  static bool MenuElementsEnabled(const FeatureContext*) { return MenuElementsEnabled(); }

  static bool MergeFixedLayersEnabled() {
    return feature_states_[kMergeFixedLayersFlagIndex];
  }

  static bool MergeFixedLayersEnabled(const FeatureContext*) { return MergeFixedLayersEnabled(); }

  static bool MergeStickyLayersEnabled() {
    return feature_states_[kMergeStickyLayersFlagIndex];
  }

  static bool MergeStickyLayersEnabled(const FeatureContext*) { return MergeStickyLayersEnabled(); }

  static bool MessagePortCloseEventEnabled() {
    return feature_states_[kMessagePortCloseEventFlagIndex];
  }

  static bool MessagePortCloseEventEnabled(const FeatureContext*) { return MessagePortCloseEventEnabled(); }

  static bool MiddleClickAutoscrollEnabled() {
    return feature_states_[kMiddleClickAutoscrollFlagIndex];
  }

  static bool MiddleClickAutoscrollEnabled(const FeatureContext*) { return MiddleClickAutoscrollEnabled(); }

  static bool MixedContentAutoupgradesUseIsMixedContentRestrictedInFrameEnabled() {
    return feature_states_[kMixedContentAutoupgradesUseIsMixedContentRestrictedInFrameFlagIndex];
  }

  static bool MixedContentAutoupgradesUseIsMixedContentRestrictedInFrameEnabled(const FeatureContext*) { return MixedContentAutoupgradesUseIsMixedContentRestrictedInFrameEnabled(); }

  static bool MobileLayoutThemeEnabled() {
    return feature_states_[kMobileLayoutThemeFlagIndex];
  }

  static bool MobileLayoutThemeEnabled(const FeatureContext*) { return MobileLayoutThemeEnabled(); }

  static bool ModifyParagraphCrossEditingoundaryEnabled() {
    return feature_states_[kModifyParagraphCrossEditingoundaryFlagIndex];
  }

  static bool ModifyParagraphCrossEditingoundaryEnabled(const FeatureContext*) { return ModifyParagraphCrossEditingoundaryEnabled(); }

  static bool ModuleMapDoNotCacheFailedFetchEnabled() {
    return feature_states_[kModuleMapDoNotCacheFailedFetchFlagIndex];
  }

  static bool ModuleMapDoNotCacheFailedFetchEnabled(const FeatureContext*) { return ModuleMapDoNotCacheFailedFetchEnabled(); }

  static bool ModulePreloadReferrerEnabled() {
    return feature_states_[kModulePreloadReferrerFlagIndex];
  }

  static bool ModulePreloadReferrerEnabled(const FeatureContext*) { return ModulePreloadReferrerEnabled(); }

  static bool ModulePreloadStyleJsonEnabled() {
    return feature_states_[kModulePreloadStyleJsonFlagIndex];
  }

  static bool ModulePreloadStyleJsonEnabled(const FeatureContext*) { return ModulePreloadStyleJsonEnabled(); }

  static bool MojoJSEnabled() {
    return get_is_mojo_js_enabled_();
  }

  static bool MojoJSEnabled(const FeatureContext*) { return MojoJSEnabled(); }

  static bool MojoJSTestEnabled() {
    return get_is_mojo_js_test_enabled_();
  }

  static bool MojoJSTestEnabled(const FeatureContext*) { return MojoJSTestEnabled(); }

  static bool MoveEndingSelectionToListChildEnabled() {
    return feature_states_[kMoveEndingSelectionToListChildFlagIndex];
  }

  static bool MoveEndingSelectionToListChildEnabled(const FeatureContext*) { return MoveEndingSelectionToListChildEnabled(); }

  static bool MoveParagraphsPreserveInlineStructureEnabled() {
    return feature_states_[kMoveParagraphsPreserveInlineStructureFlagIndex];
  }

  static bool MoveParagraphsPreserveInlineStructureEnabled(const FeatureContext*) { return MoveParagraphsPreserveInlineStructureEnabled(); }

  static bool NavigateEventDeferCrossDocumentCommitEnabled() {
    return feature_states_[kNavigateEventDeferCrossDocumentCommitFlagIndex];
  }

  static bool NavigateEventDeferCrossDocumentCommitEnabled(const FeatureContext*) { return NavigateEventDeferCrossDocumentCommitEnabled(); }

  static bool NavigationEventTimingEnabled() {
    return feature_states_[kNavigationEventTimingFlagIndex];
  }

  static bool NavigationEventTimingEnabled(const FeatureContext*) { return NavigationEventTimingEnabled(); }

  static bool NavigationSourcePseudoClassEnabled() {
    if (RouteMatchingEnabled())
      return true;
    return feature_states_[kNavigationSourcePseudoClassFlagIndex];
  }

  static bool NavigationSourcePseudoClassEnabled(const FeatureContext*) { return NavigationSourcePseudoClassEnabled(); }

  static bool NavigationTimingRedirectTimingViaTAOEnabled() {
    return feature_states_[kNavigationTimingRedirectTimingViaTAOFlagIndex];
  }

  static bool NavigationTimingRedirectTimingViaTAOEnabled(const FeatureContext*) { return NavigationTimingRedirectTimingViaTAOEnabled(); }

  static bool NavigationTypeAndPhaseEnabled() {
    if (!RouteMatchingEnabled())
      return false;
    return feature_states_[kNavigationTypeAndPhaseFlagIndex];
  }

  static bool NavigationTypeAndPhaseEnabled(const FeatureContext*) { return NavigationTypeAndPhaseEnabled(); }

  static bool NavigatorContentUtilsEnabled() {
    return feature_states_[kNavigatorContentUtilsFlagIndex];
  }

  static bool NavigatorContentUtilsEnabled(const FeatureContext*) { return NavigatorContentUtilsEnabled(); }

  static bool NetInfoConstantTypeEnabled() {
    return feature_states_[kNetInfoConstantTypeFlagIndex];
  }

  static bool NetInfoConstantTypeEnabled(const FeatureContext*) { return NetInfoConstantTypeEnabled(); }

  static bool NetInfoDownlinkMaxEnabled() {
    return feature_states_[kNetInfoDownlinkMaxFlagIndex];
  }

  static bool NetInfoDownlinkMaxEnabled(const FeatureContext*) { return NetInfoDownlinkMaxEnabled(); }

  static bool NewAnimationCompositingCheckingEnabled() {
    return feature_states_[kNewAnimationCompositingCheckingFlagIndex];
  }

  static bool NewAnimationCompositingCheckingEnabled(const FeatureContext*) { return NewAnimationCompositingCheckingEnabled(); }

  static bool NewAnimationDispositionReportingEnabled() {
    return feature_states_[kNewAnimationDispositionReportingFlagIndex];
  }

  static bool NewAnimationDispositionReportingEnabled(const FeatureContext*) { return NewAnimationDispositionReportingEnabled(); }

  static bool NewHTMLSettingMethodsEnabled() {
    if (!SetHTMLCanRunScriptsEnabled())
      return false;
    if (!StreamingSanitizerEnabled())
      return false;
    if (!TrustedTypesCreateParserOptionsEnabled())
      return false;
    return feature_states_[kNewHTMLSettingMethodsFlagIndex];
  }

  static bool NewHTMLSettingMethodsEnabled(const FeatureContext*) { return NewHTMLSettingMethodsEnabled(); }

  static bool NoExtendSelectionToUserSelectNoneOutOfFlowEnabled() {
    return feature_states_[kNoExtendSelectionToUserSelectNoneOutOfFlowFlagIndex];
  }

  static bool NoExtendSelectionToUserSelectNoneOutOfFlowEnabled(const FeatureContext*) { return NoExtendSelectionToUserSelectNoneOutOfFlowEnabled(); }

  static bool NoExtendSelectionToUserSelectNoneOutOfFlowUnlessEditableEnabled() {
    return feature_states_[kNoExtendSelectionToUserSelectNoneOutOfFlowUnlessEditableFlagIndex];
  }

  static bool NoExtendSelectionToUserSelectNoneOutOfFlowUnlessEditableEnabled(const FeatureContext*) { return NoExtendSelectionToUserSelectNoneOutOfFlowUnlessEditableEnabled(); }

  static bool NoFontAntialiasingEnabled() {
    return feature_states_[kNoFontAntialiasingFlagIndex];
  }

  static bool NoFontAntialiasingEnabled(const FeatureContext*) { return NoFontAntialiasingEnabled(); }

  static bool NoIdleEncodingForWebTestsEnabled() {
    return feature_states_[kNoIdleEncodingForWebTestsFlagIndex];
  }

  static bool NoIdleEncodingForWebTestsEnabled(const FeatureContext*) { return NoIdleEncodingForWebTestsEnabled(); }

  static bool NoNbspForInterElementSpaceOnCopyEnabled() {
    return feature_states_[kNoNbspForInterElementSpaceOnCopyFlagIndex];
  }

  static bool NoNbspForInterElementSpaceOnCopyEnabled(const FeatureContext*) { return NoNbspForInterElementSpaceOnCopyEnabled(); }

  static bool NonEmptyBlockquotesOnOutdentingEnabled() {
    return feature_states_[kNonEmptyBlockquotesOnOutdentingFlagIndex];
  }

  static bool NonEmptyBlockquotesOnOutdentingEnabled(const FeatureContext*) { return NonEmptyBlockquotesOnOutdentingEnabled(); }

  static bool NonEmptyVisibleTextSelectionForTextFragmentEnabled() {
    return feature_states_[kNonEmptyVisibleTextSelectionForTextFragmentFlagIndex];
  }

  static bool NonEmptyVisibleTextSelectionForTextFragmentEnabled(const FeatureContext*) { return NonEmptyVisibleTextSelectionForTextFragmentEnabled(); }

  static bool NonStandardAppearanceValueSliderVerticalEnabled() {
    return feature_states_[kNonStandardAppearanceValueSliderVerticalFlagIndex];
  }

  static bool NonStandardAppearanceValueSliderVerticalEnabled(const FeatureContext*) { return NonStandardAppearanceValueSliderVerticalEnabled(); }

  static bool NormalizeLineEndingsInInsertTextEnabled() {
    return feature_states_[kNormalizeLineEndingsInInsertTextFlagIndex];
  }

  static bool NormalizeLineEndingsInInsertTextEnabled(const FeatureContext*) { return NormalizeLineEndingsInInsertTextEnabled(); }

  static bool NormalizeNbspForPasteAndDropEnabled() {
    return feature_states_[kNormalizeNbspForPasteAndDropFlagIndex];
  }

  static bool NormalizeNbspForPasteAndDropEnabled(const FeatureContext*) { return NormalizeNbspForPasteAndDropEnabled(); }

  static bool NormalizeNbspRichTextOnlyEnabled() {
    if (!NormalizeNbspForPasteAndDropEnabled())
      return false;
    return feature_states_[kNormalizeNbspRichTextOnlyFlagIndex];
  }

  static bool NormalizeNbspRichTextOnlyEnabled(const FeatureContext*) { return NormalizeNbspRichTextOnlyEnabled(); }

  static bool NotificationConstructorEnabled() {
    return feature_states_[kNotificationConstructorFlagIndex];
  }

  static bool NotificationConstructorEnabled(const FeatureContext*) { return NotificationConstructorEnabled(); }

  static bool NotificationContentImageEnabled() {
    return feature_states_[kNotificationContentImageFlagIndex];
  }

  static bool NotificationContentImageEnabled(const FeatureContext*) { return NotificationContentImageEnabled(); }

  static bool NotificationsEnabled() {
    return feature_states_[kNotificationsFlagIndex];
  }

  static bool NotificationsEnabled(const FeatureContext*) { return NotificationsEnabled(); }

  static bool NotifySelectionControllerOnUnchangedSelectionEnabled() {
    return feature_states_[kNotifySelectionControllerOnUnchangedSelectionFlagIndex];
  }

  static bool NotifySelectionControllerOnUnchangedSelectionEnabled(const FeatureContext*) { return NotifySelectionControllerOnUnchangedSelectionEnabled(); }

  static bool NumberInputFullWidthCharsEnabled() {
    return feature_states_[kNumberInputFullWidthCharsFlagIndex];
  }

  static bool NumberInputFullWidthCharsEnabled(const FeatureContext*) { return NumberInputFullWidthCharsEnabled(); }

  static bool OffscreenCanvasGetContextAttributesEnabled() {
    return feature_states_[kOffscreenCanvasGetContextAttributesFlagIndex];
  }

  static bool OffscreenCanvasGetContextAttributesEnabled(const FeatureContext*) { return OffscreenCanvasGetContextAttributesEnabled(); }

  static bool OffsetMappingReuseFullWidthSpaceFixEnabled() {
    return feature_states_[kOffsetMappingReuseFullWidthSpaceFixFlagIndex];
  }

  static bool OffsetMappingReuseFullWidthSpaceFixEnabled(const FeatureContext*) { return OffsetMappingReuseFullWidthSpaceFixEnabled(); }

  static bool OffsetPathTransformUpdateFixEnabled() {
    return feature_states_[kOffsetPathTransformUpdateFixFlagIndex];
  }

  static bool OffsetPathTransformUpdateFixEnabled(const FeatureContext*) { return OffsetPathTransformUpdateFixEnabled(); }

  static bool OmitBlurEventOnElementRemovalEnabled() {
    return feature_states_[kOmitBlurEventOnElementRemovalFlagIndex];
  }

  static bool OmitBlurEventOnElementRemovalEnabled(const FeatureContext*) { return OmitBlurEventOnElementRemovalEnabled(); }

  static bool OmitSubframeDetachmentEventsOnRemovalEnabled() {
    return feature_states_[kOmitSubframeDetachmentEventsOnRemovalFlagIndex];
  }

  static bool OmitSubframeDetachmentEventsOnRemovalEnabled(const FeatureContext*) { return OmitSubframeDetachmentEventsOnRemovalEnabled(); }

  static bool OnDeviceWebSpeechAvailableEnabled() {
    return feature_states_[kOnDeviceWebSpeechAvailableFlagIndex];
  }

  static bool OnDeviceWebSpeechAvailableEnabled(const FeatureContext*) { return OnDeviceWebSpeechAvailableEnabled(); }

  static bool OnDeviceWebSpeechQualityEnabled() {
    return feature_states_[kOnDeviceWebSpeechQualityFlagIndex];
  }

  static bool OnDeviceWebSpeechQualityEnabled(const FeatureContext*) { return OnDeviceWebSpeechQualityEnabled(); }

  static bool OofLayoutRequiresSideEffectsEnabled() {
    return feature_states_[kOofLayoutRequiresSideEffectsFlagIndex];
  }

  static bool OofLayoutRequiresSideEffectsEnabled(const FeatureContext*) { return OofLayoutRequiresSideEffectsEnabled(); }

  static bool OpaqueRangeEnabled() {
    return feature_states_[kOpaqueRangeFlagIndex];
  }

  static bool OpaqueRangeEnabled(const FeatureContext*) { return OpaqueRangeEnabled(); }

  static bool OpenPopoverInvokerRestrictToSameTreeScopeEnabled() {
    return feature_states_[kOpenPopoverInvokerRestrictToSameTreeScopeFlagIndex];
  }

  static bool OpenPopoverInvokerRestrictToSameTreeScopeEnabled(const FeatureContext*) { return OpenPopoverInvokerRestrictToSameTreeScopeEnabled(); }

  static bool OptionDisablednessCheckAncestorsEnabled() {
    return feature_states_[kOptionDisablednessCheckAncestorsFlagIndex];
  }

  static bool OptionDisablednessCheckAncestorsEnabled(const FeatureContext*) { return OptionDisablednessCheckAncestorsEnabled(); }

  static bool OrientationEventEnabled() {
    return feature_states_[kOrientationEventFlagIndex];
  }

  static bool OrientationEventEnabled(const FeatureContext*) { return OrientationEventEnabled(); }

  static bool OriginAPIEnabled() {
    return feature_states_[kOriginAPIFlagIndex];
  }

  static bool OriginAPIEnabled(const FeatureContext*) { return OriginAPIEnabled(); }

  static bool OriginIsolationHeaderEnabled() {
    return feature_states_[kOriginIsolationHeaderFlagIndex];
  }

  static bool OriginIsolationHeaderEnabled(const FeatureContext*) { return OriginIsolationHeaderEnabled(); }

  static bool OriginPolicyEnabled() {
    return feature_states_[kOriginPolicyFlagIndex];
  }

  static bool OriginPolicyEnabled(const FeatureContext*) { return OriginPolicyEnabled(); }

  static bool OutlineDrawAutoStyleZeroWidthEnabled() {
    return feature_states_[kOutlineDrawAutoStyleZeroWidthFlagIndex];
  }

  static bool OutlineDrawAutoStyleZeroWidthEnabled(const FeatureContext*) { return OutlineDrawAutoStyleZeroWidthEnabled(); }

  static bool OverlayGlobalRuleRemovalEnabled() {
    return feature_states_[kOverlayGlobalRuleRemovalFlagIndex];
  }

  static bool OverlayGlobalRuleRemovalEnabled(const FeatureContext*) { return OverlayGlobalRuleRemovalEnabled(); }

  static bool OverlayPropertyEnabled() {
    return feature_states_[kOverlayPropertyFlagIndex];
  }

  static bool OverlayPropertyEnabled(const FeatureContext*) { return OverlayPropertyEnabled(); }

  static bool OverscrollGesturesEnabled() {
    return feature_states_[kOverscrollGesturesFlagIndex];
  }

  static bool OverscrollGesturesEnabled(const FeatureContext*) { return OverscrollGesturesEnabled(); }

  static bool PagePopupEnabled() {
    return feature_states_[kPagePopupFlagIndex];
  }

  static bool PagePopupEnabled(const FeatureContext*) { return PagePopupEnabled(); }

  static bool PagePopupCopyPasteEnabled() {
    if (!PagePopupEnabled())
      return false;
    return feature_states_[kPagePopupCopyPasteFlagIndex];
  }

  static bool PagePopupCopyPasteEnabled(const FeatureContext*) { return PagePopupCopyPasteEnabled(); }

  static bool PageSwapEventEnabled() {
    return feature_states_[kPageSwapEventFlagIndex];
  }

  static bool PageSwapEventEnabled(const FeatureContext*) { return PageSwapEventEnabled(); }

  static bool PaintCaretAfterInnerEditorPaintEnabled() {
    return feature_states_[kPaintCaretAfterInnerEditorPaintFlagIndex];
  }

  static bool PaintCaretAfterInnerEditorPaintEnabled(const FeatureContext*) { return PaintCaretAfterInnerEditorPaintEnabled(); }

  static bool PaintHoldingForIframesEnabled() {
    return feature_states_[kPaintHoldingForIframesFlagIndex];
  }

  static bool PaintHoldingForIframesEnabled(const FeatureContext*) { return PaintHoldingForIframesEnabled(); }

  static bool PaintUnderInvalidationCheckingEnabled() {
    return feature_states_[kPaintUnderInvalidationCheckingFlagIndex];
  }

  static bool PaintUnderInvalidationCheckingEnabled(const FeatureContext*) { return PaintUnderInvalidationCheckingEnabled(); }

  static bool PartitionVisitedLinkDatabaseWithSelfLinksEnabled() {
    return feature_states_[kPartitionVisitedLinkDatabaseWithSelfLinksFlagIndex];
  }

  static bool PartitionVisitedLinkDatabaseWithSelfLinksEnabled(const FeatureContext*) { return PartitionVisitedLinkDatabaseWithSelfLinksEnabled(); }

  static bool PasswordRevealEnabled() {
    return feature_states_[kPasswordRevealFlagIndex];
  }

  static bool PasswordRevealEnabled(const FeatureContext*) { return PasswordRevealEnabled(); }

  static bool PaymentAppEnabled() {
    return feature_states_[kPaymentAppFlagIndex];
  }

  static bool PaymentAppEnabled(const FeatureContext*) { return PaymentAppEnabled(); }

  static bool PaymentLinkDetectionEnabled() {
    return feature_states_[kPaymentLinkDetectionFlagIndex];
  }

  static bool PaymentLinkDetectionEnabled(const FeatureContext*) { return PaymentLinkDetectionEnabled(); }

  static bool PaymentMethodChangeEventEnabled() {
    if (!PaymentRequestEnabled())
      return false;
    return feature_states_[kPaymentMethodChangeEventFlagIndex];
  }

  static bool PaymentMethodChangeEventEnabled(const FeatureContext*) { return PaymentMethodChangeEventEnabled(); }

  static bool PaymentRequestEnabled() {
    return feature_states_[kPaymentRequestFlagIndex];
  }

  static bool PaymentRequestEnabled(const FeatureContext*) { return PaymentRequestEnabled(); }

  static bool PaymentRequestNonFullyActiveDocumentCheckInvalidStateErrorEnabled() {
    return feature_states_[kPaymentRequestNonFullyActiveDocumentCheckInvalidStateErrorFlagIndex];
  }

  static bool PaymentRequestNonFullyActiveDocumentCheckInvalidStateErrorEnabled(const FeatureContext*) { return PaymentRequestNonFullyActiveDocumentCheckInvalidStateErrorEnabled(); }

  static bool PerformanceManagerInstrumentationEnabled() {
    return feature_states_[kPerformanceManagerInstrumentationFlagIndex];
  }

  static bool PerformanceManagerInstrumentationEnabled(const FeatureContext*) { return PerformanceManagerInstrumentationEnabled(); }

  static bool PerformanceMarkCustomUserTimingFromSubframeEnabled() {
    return feature_states_[kPerformanceMarkCustomUserTimingFromSubframeFlagIndex];
  }

  static bool PerformanceMarkCustomUserTimingFromSubframeEnabled(const FeatureContext*) { return PerformanceMarkCustomUserTimingFromSubframeEnabled(); }

  static bool PerformanceMarkFeatureUsageEnabled() {
    return feature_states_[kPerformanceMarkFeatureUsageFlagIndex];
  }

  static bool PerformanceMarkFeatureUsageEnabled(const FeatureContext*) { return PerformanceMarkFeatureUsageEnabled(); }

  static bool PeriodicBackgroundSyncEnabled() {
    return feature_states_[kPeriodicBackgroundSyncFlagIndex];
  }

  static bool PeriodicBackgroundSyncEnabled(const FeatureContext*) { return PeriodicBackgroundSyncEnabled(); }

  static bool PermissionsPolicyAPIEnabled() {
    return feature_states_[kPermissionsPolicyAPIFlagIndex];
  }

  static bool PermissionsPolicyAPIEnabled(const FeatureContext*) { return PermissionsPolicyAPIEnabled(); }

  static bool PermissionsRequestRevokeEnabled() {
    return feature_states_[kPermissionsRequestRevokeFlagIndex];
  }

  static bool PermissionsRequestRevokeEnabled(const FeatureContext*) { return PermissionsRequestRevokeEnabled(); }

  static bool PointerLockOnAndroidEnabled() {
    return feature_states_[kPointerLockOnAndroidFlagIndex];
  }

  static bool PointerLockOnAndroidEnabled(const FeatureContext*) { return PointerLockOnAndroidEnabled(); }

  static bool PointerRawUpdateOnlyInSecureContextEnabled() {
    return feature_states_[kPointerRawUpdateOnlyInSecureContextFlagIndex];
  }

  static bool PointerRawUpdateOnlyInSecureContextEnabled(const FeatureContext*) { return PointerRawUpdateOnlyInSecureContextEnabled(); }

  static bool PopoverHintNestedShowExceptionEnabled() {
    return feature_states_[kPopoverHintNestedShowExceptionFlagIndex];
  }

  static bool PopoverHintNestedShowExceptionEnabled(const FeatureContext*) { return PopoverHintNestedShowExceptionEnabled(); }

  static bool PopoverHintNewBehaviorEnabled() {
    return feature_states_[kPopoverHintNewBehaviorFlagIndex];
  }

  static bool PopoverHintNewBehaviorEnabled(const FeatureContext*) { return PopoverHintNewBehaviorEnabled(); }

  static bool PositionOutsideTabSpanCheckSiblingNodeEnabled() {
    return feature_states_[kPositionOutsideTabSpanCheckSiblingNodeFlagIndex];
  }

  static bool PositionOutsideTabSpanCheckSiblingNodeEnabled(const FeatureContext*) { return PositionOutsideTabSpanCheckSiblingNodeEnabled(); }

  static bool PositionVisibilityIgnoreNonClipAncestorsEnabled() {
    return feature_states_[kPositionVisibilityIgnoreNonClipAncestorsFlagIndex];
  }

  static bool PositionVisibilityIgnoreNonClipAncestorsEnabled(const FeatureContext*) { return PositionVisibilityIgnoreNonClipAncestorsEnabled(); }

  static bool PotentialPermissionsPolicyReportingEnabled() {
    return feature_states_[kPotentialPermissionsPolicyReportingFlagIndex];
  }

  static bool PotentialPermissionsPolicyReportingEnabled(const FeatureContext*) { return PotentialPermissionsPolicyReportingEnabled(); }

  static bool PreciseMemoryInfoEnabled() {
    return feature_states_[kPreciseMemoryInfoFlagIndex];
  }

  static bool PreciseMemoryInfoEnabled(const FeatureContext*) { return PreciseMemoryInfoEnabled(); }

  static bool PreferDefaultScrollbarStylesEnabled() {
    return feature_states_[kPreferDefaultScrollbarStylesFlagIndex];
  }

  static bool PreferDefaultScrollbarStylesEnabled(const FeatureContext*) { return PreferDefaultScrollbarStylesEnabled(); }

  static bool PreferNonCompositedScrollingEnabled() {
    return feature_states_[kPreferNonCompositedScrollingFlagIndex];
  }

  static bool PreferNonCompositedScrollingEnabled(const FeatureContext*) { return PreferNonCompositedScrollingEnabled(); }

  static bool PrefersReducedDataEnabled() {
    return feature_states_[kPrefersReducedDataFlagIndex];
  }

  static bool PrefersReducedDataEnabled(const FeatureContext*) { return PrefersReducedDataEnabled(); }

  static bool PreloadLinkRelDataUrlsEnabled() {
    return feature_states_[kPreloadLinkRelDataUrlsFlagIndex];
  }

  static bool PreloadLinkRelDataUrlsEnabled(const FeatureContext*) { return PreloadLinkRelDataUrlsEnabled(); }

  static bool PreloadScannerSkipMathMLScriptEnabled() {
    return feature_states_[kPreloadScannerSkipMathMLScriptFlagIndex];
  }

  static bool PreloadScannerSkipMathMLScriptEnabled(const FeatureContext*) { return PreloadScannerSkipMathMLScriptEnabled(); }

  static bool Prerender2Enabled() {
    return feature_states_[kPrerender2FlagIndex];
  }

  static bool Prerender2Enabled(const FeatureContext*) { return Prerender2Enabled(); }

  static bool PresentationEnabled() {
    return feature_states_[kPresentationFlagIndex];
  }

  static bool PresentationEnabled(const FeatureContext*) { return PresentationEnabled(); }

  static bool PreserveHtmlEquivalentTagsInTypingStyleEnabled() {
    return feature_states_[kPreserveHtmlEquivalentTagsInTypingStyleFlagIndex];
  }

  static bool PreserveHtmlEquivalentTagsInTypingStyleEnabled(const FeatureContext*) { return PreserveHtmlEquivalentTagsInTypingStyleEnabled(); }

  static bool PreserveUnfocusedSelectionCacheEnabled() {
    return feature_states_[kPreserveUnfocusedSelectionCacheFlagIndex];
  }

  static bool PreserveUnfocusedSelectionCacheEnabled(const FeatureContext*) { return PreserveUnfocusedSelectionCacheEnabled(); }

  static bool PreventTextSelectionJumpEnabled() {
    return feature_states_[kPreventTextSelectionJumpFlagIndex];
  }

  static bool PreventTextSelectionJumpEnabled(const FeatureContext*) { return PreventTextSelectionJumpEnabled(); }

  static bool PrivateNetworkAccessNullIpAddressEnabled() {
    return feature_states_[kPrivateNetworkAccessNullIpAddressFlagIndex];
  }

  static bool PrivateNetworkAccessNullIpAddressEnabled(const FeatureContext*) { return PrivateNetworkAccessNullIpAddressEnabled(); }

  static bool PrivateStateTokensEnabled() {
    return feature_states_[kPrivateStateTokensFlagIndex];
  }

  static bool PrivateStateTokensEnabled(const FeatureContext*) { return PrivateStateTokensEnabled(); }

  static bool PrivateStateTokensAlwaysAllowIssuanceEnabled() {
    return feature_states_[kPrivateStateTokensAlwaysAllowIssuanceFlagIndex];
  }

  static bool PrivateStateTokensAlwaysAllowIssuanceEnabled(const FeatureContext*) { return PrivateStateTokensAlwaysAllowIssuanceEnabled(); }

  static bool ProfilerAPIEnabled() {
    return feature_states_[kProfilerAPIFlagIndex];
  }

  static bool ProfilerAPIEnabled(const FeatureContext*) { return ProfilerAPIEnabled(); }

  static bool ProfilerAPIForDedicatedWorkerEnabled() {
    return feature_states_[kProfilerAPIForDedicatedWorkerFlagIndex];
  }

  static bool ProfilerAPIForDedicatedWorkerEnabled(const FeatureContext*) { return ProfilerAPIForDedicatedWorkerEnabled(); }

  static bool ProgrammaticScrollPromiseEnabled() {
    return feature_states_[kProgrammaticScrollPromiseFlagIndex];
  }

  static bool ProgrammaticScrollPromiseEnabled(const FeatureContext*) { return ProgrammaticScrollPromiseEnabled(); }

  static bool PropagateOverscrollBehaviorFromRootEnabled() {
    return feature_states_[kPropagateOverscrollBehaviorFromRootFlagIndex];
  }

  static bool PropagateOverscrollBehaviorFromRootEnabled(const FeatureContext*) { return PropagateOverscrollBehaviorFromRootEnabled(); }

  static bool PseudoElementsFocusableEnabled() {
    return feature_states_[kPseudoElementsFocusableFlagIndex];
  }

  static bool PseudoElementsFocusableEnabled(const FeatureContext*) { return PseudoElementsFocusableEnabled(); }

  static bool PseudoElementsHitTestableEnabled() {
    return feature_states_[kPseudoElementsHitTestableFlagIndex];
  }

  static bool PseudoElementsHitTestableEnabled(const FeatureContext*) { return PseudoElementsHitTestableEnabled(); }

  static bool PseudoElementsHoverableEnabled() {
    if (!PseudoElementsHitTestableEnabled())
      return false;
    return feature_states_[kPseudoElementsHoverableFlagIndex];
  }

  static bool PseudoElementsHoverableEnabled(const FeatureContext*) { return PseudoElementsHoverableEnabled(); }

  static bool PushMessageDataBytesEnabled() {
    if (!PushMessagingEnabled())
      return false;
    return feature_states_[kPushMessageDataBytesFlagIndex];
  }

  static bool PushMessageDataBytesEnabled(const FeatureContext*) { return PushMessageDataBytesEnabled(); }

  static bool PushMessagingEnabled() {
    return feature_states_[kPushMessagingFlagIndex];
  }

  static bool PushMessagingEnabled(const FeatureContext*) { return PushMessagingEnabled(); }

  static bool PushMessagingSubscriptionChangeEnabled() {
    return feature_states_[kPushMessagingSubscriptionChangeFlagIndex];
  }

  static bool PushMessagingSubscriptionChangeEnabled(const FeatureContext*) { return PushMessagingSubscriptionChangeEnabled(); }

  static bool QuotaExceededErrorUpdateEnabled() {
    return feature_states_[kQuotaExceededErrorUpdateFlagIndex];
  }

  static bool QuotaExceededErrorUpdateEnabled(const FeatureContext*) { return QuotaExceededErrorUpdateEnabled(); }

  static bool RangeBoundaryFastPathEnabled() {
    return feature_states_[kRangeBoundaryFastPathFlagIndex];
  }

  static bool RangeBoundaryFastPathEnabled(const FeatureContext*) { return RangeBoundaryFastPathEnabled(); }

  static bool RasterInducingScrollEnabled() {
    return feature_states_[kRasterInducingScrollFlagIndex];
  }

  static bool RasterInducingScrollEnabled(const FeatureContext*) { return RasterInducingScrollEnabled(); }

  static bool RateLimitPointerLockRequestsEnabled() {
    return feature_states_[kRateLimitPointerLockRequestsFlagIndex];
  }

  static bool RateLimitPointerLockRequestsEnabled(const FeatureContext*) { return RateLimitPointerLockRequestsEnabled(); }

  static bool ReadableStreamBYOBReaderReadMinOptionEnabled() {
    return feature_states_[kReadableStreamBYOBReaderReadMinOptionFlagIndex];
  }

  static bool ReadableStreamBYOBReaderReadMinOptionEnabled(const FeatureContext*) { return ReadableStreamBYOBReaderReadMinOptionEnabled(); }

  static bool ReadClipboardDataOnClipboardItemGetTypeEnabled() {
    return feature_states_[kReadClipboardDataOnClipboardItemGetTypeFlagIndex];
  }

  static bool ReadClipboardDataOnClipboardItemGetTypeEnabled(const FeatureContext*) { return ReadClipboardDataOnClipboardItemGetTypeEnabled(); }

  static bool ReadingFlowWithSlotsEnabled() {
    return feature_states_[kReadingFlowWithSlotsFlagIndex];
  }

  static bool ReadingFlowWithSlotsEnabled(const FeatureContext*) { return ReadingFlowWithSlotsEnabled(); }

  static bool RecheckParentDuringNodeVectorInsertionEnabled() {
    return feature_states_[kRecheckParentDuringNodeVectorInsertionFlagIndex];
  }

  static bool RecheckParentDuringNodeVectorInsertionEnabled(const FeatureContext*) { return RecheckParentDuringNodeVectorInsertionEnabled(); }

  static bool RecordSameDocumentPresentationTimeOnceEnabled() {
    return feature_states_[kRecordSameDocumentPresentationTimeOnceFlagIndex];
  }

  static bool RecordSameDocumentPresentationTimeOnceEnabled(const FeatureContext*) { return RecordSameDocumentPresentationTimeOnceEnabled(); }

  static bool ReduceAcceptLanguageEnabled() {
    return feature_states_[kReduceAcceptLanguageFlagIndex];
  }

  static bool ReduceAcceptLanguageEnabled(const FeatureContext*) { return ReduceAcceptLanguageEnabled(); }

  static bool ReduceUserAgentMinorVersionEnabled() {
    return feature_states_[kReduceUserAgentMinorVersionFlagIndex];
  }

  static bool ReduceUserAgentMinorVersionEnabled(const FeatureContext*) { return ReduceUserAgentMinorVersionEnabled(); }

  static bool RegionCaptureEnabled() {
    return feature_states_[kRegionCaptureFlagIndex];
  }

  static bool RegionCaptureEnabled(const FeatureContext*) { return RegionCaptureEnabled(); }

  static bool RelatedWebsitePartitionAPIEnabled() {
    return feature_states_[kRelatedWebsitePartitionAPIFlagIndex];
  }

  static bool RelatedWebsitePartitionAPIEnabled(const FeatureContext*) { return RelatedWebsitePartitionAPIEnabled(); }

  static bool ReleasePaintHoldingWithoutContentfulPaintEnabled() {
    return feature_states_[kReleasePaintHoldingWithoutContentfulPaintFlagIndex];
  }

  static bool ReleasePaintHoldingWithoutContentfulPaintEnabled(const FeatureContext*) { return ReleasePaintHoldingWithoutContentfulPaintEnabled(); }

  static bool RelOpenerBcgDependencyHintEnabled() {
    return feature_states_[kRelOpenerBcgDependencyHintFlagIndex];
  }

  static bool RelOpenerBcgDependencyHintEnabled(const FeatureContext*) { return RelOpenerBcgDependencyHintEnabled(); }

  static bool RemotePlaybackEnabled() {
    return feature_states_[kRemotePlaybackFlagIndex];
  }

  static bool RemotePlaybackEnabled(const FeatureContext*) { return RemotePlaybackEnabled(); }

  static bool RemotePlaybackBackendEnabled() {
    return feature_states_[kRemotePlaybackBackendFlagIndex];
  }

  static bool RemotePlaybackBackendEnabled(const FeatureContext*) { return RemotePlaybackBackendEnabled(); }

  static bool RemoveCharsetAutoDetectionForISO2022JPEnabled() {
    return feature_states_[kRemoveCharsetAutoDetectionForISO2022JPFlagIndex];
  }

  static bool RemoveCharsetAutoDetectionForISO2022JPEnabled(const FeatureContext*) { return RemoveCharsetAutoDetectionForISO2022JPEnabled(); }

  static bool RemoveChildrenInReplaceChildrenEnabled() {
    return feature_states_[kRemoveChildrenInReplaceChildrenFlagIndex];
  }

  static bool RemoveChildrenInReplaceChildrenEnabled(const FeatureContext*) { return RemoveChildrenInReplaceChildrenEnabled(); }

  static bool RemoveCollapsedPlaceholderForContentEditableEnabled() {
    return feature_states_[kRemoveCollapsedPlaceholderForContentEditableFlagIndex];
  }

  static bool RemoveCollapsedPlaceholderForContentEditableEnabled(const FeatureContext*) { return RemoveCollapsedPlaceholderForContentEditableEnabled(); }

  static bool RemoveDanglingMarkupInTargetEnabled() {
    return feature_states_[kRemoveDanglingMarkupInTargetFlagIndex];
  }

  static bool RemoveDanglingMarkupInTargetEnabled(const FeatureContext*) { return RemoveDanglingMarkupInTargetEnabled(); }

  static bool RemoveDataUrlInSvgUseEnabled() {
    return feature_states_[kRemoveDataUrlInSvgUseFlagIndex];
  }

  static bool RemoveDataUrlInSvgUseEnabled(const FeatureContext*) { return RemoveDataUrlInSvgUseEnabled(); }

  static bool RemoveNonAllowlistedCreateEventEnabled() {
    return feature_states_[kRemoveNonAllowlistedCreateEventFlagIndex];
  }

  static bool RemoveNonAllowlistedCreateEventEnabled(const FeatureContext*) { return RemoveNonAllowlistedCreateEventEnabled(); }

  static bool RemoveScrollNodeWorkaroundEnabled() {
    return feature_states_[kRemoveScrollNodeWorkaroundFlagIndex];
  }

  static bool RemoveScrollNodeWorkaroundEnabled(const FeatureContext*) { return RemoveScrollNodeWorkaroundEnabled(); }

  static bool RemoveTargetCurrentEnabled() {
    return feature_states_[kRemoveTargetCurrentFlagIndex];
  }

  static bool RemoveTargetCurrentEnabled(const FeatureContext*) { return RemoveTargetCurrentEnabled(); }

  static bool RemoveVisibleSelectionInDOMSelectionEnabled() {
    return feature_states_[kRemoveVisibleSelectionInDOMSelectionFlagIndex];
  }

  static bool RemoveVisibleSelectionInDOMSelectionEnabled(const FeatureContext*) { return RemoveVisibleSelectionInDOMSelectionEnabled(); }

  static bool RenderPriorityAttributeEnabled() {
    return feature_states_[kRenderPriorityAttributeFlagIndex];
  }

  static bool RenderPriorityAttributeEnabled(const FeatureContext*) { return RenderPriorityAttributeEnabled(); }

  static bool ReplaceChildrenWithFragmentFastPathEnabled() {
    return feature_states_[kReplaceChildrenWithFragmentFastPathFlagIndex];
  }

  static bool ReplaceChildrenWithFragmentFastPathEnabled(const FeatureContext*) { return ReplaceChildrenWithFragmentFastPathEnabled(); }

  static bool ReplacedNormalFlowStackingInlinePaintEnabled() {
    return feature_states_[kReplacedNormalFlowStackingInlinePaintFlagIndex];
  }

  static bool ReplacedNormalFlowStackingInlinePaintEnabled(const FeatureContext*) { return ReplacedNormalFlowStackingInlinePaintEnabled(); }

  static bool ReportFirstFrameTimeAsRenderTimeEnabled() {
    return feature_states_[kReportFirstFrameTimeAsRenderTimeFlagIndex];
  }

  static bool ReportFirstFrameTimeAsRenderTimeEnabled(const FeatureContext*) { return ReportFirstFrameTimeAsRenderTimeEnabled(); }

  static bool ReportLayoutShiftRectsInCssPixelsEnabled() {
    return feature_states_[kReportLayoutShiftRectsInCssPixelsFlagIndex];
  }

  static bool ReportLayoutShiftRectsInCssPixelsEnabled(const FeatureContext*) { return ReportLayoutShiftRectsInCssPixelsEnabled(); }

  static bool RequestIsReloadNavigationEnabled() {
    return feature_states_[kRequestIsReloadNavigationFlagIndex];
  }

  static bool RequestIsReloadNavigationEnabled(const FeatureContext*) { return RequestIsReloadNavigationEnabled(); }

  static bool RequestStorageAccessForEnabled() {
    return feature_states_[kRequestStorageAccessForFlagIndex];
  }

  static bool RequestStorageAccessForEnabled(const FeatureContext*) { return RequestStorageAccessForEnabled(); }

  static bool ResourceTimingInitiatorEnabled() {
    return feature_states_[kResourceTimingInitiatorFlagIndex];
  }

  static bool ResourceTimingInitiatorEnabled(const FeatureContext*) { return ResourceTimingInitiatorEnabled(); }

  static bool ResourceTimingUseCORSForBodySizesEnabled() {
    return feature_states_[kResourceTimingUseCORSForBodySizesFlagIndex];
  }

  static bool ResourceTimingUseCORSForBodySizesEnabled(const FeatureContext*) { return ResourceTimingUseCORSForBodySizesEnabled(); }

  static bool RespectOverscrollBehaviorForScrollBubblingEnabled() {
    return feature_states_[kRespectOverscrollBehaviorForScrollBubblingFlagIndex];
  }

  static bool RespectOverscrollBehaviorForScrollBubblingEnabled(const FeatureContext*) { return RespectOverscrollBehaviorForScrollBubblingEnabled(); }

  static bool ResponsiveIframesEnabled() {
    return feature_states_[kResponsiveIframesFlagIndex];
  }

  static bool ResponsiveIframesEnabled(const FeatureContext*) { return ResponsiveIframesEnabled(); }

  static bool RestrictGamepadAccessEnabled() {
    return feature_states_[kRestrictGamepadAccessFlagIndex];
  }

  static bool RestrictGamepadAccessEnabled(const FeatureContext*) { return RestrictGamepadAccessEnabled(); }

  static bool RestrictOwnAudioEnabled() {
    return feature_states_[kRestrictOwnAudioFlagIndex];
  }

  static bool RestrictOwnAudioEnabled(const FeatureContext*) { return RestrictOwnAudioEnabled(); }

  static bool RootScrollbarFollowsBrowserThemeEnabled() {
    return feature_states_[kRootScrollbarFollowsBrowserThemeFlagIndex];
  }

  static bool RootScrollbarFollowsBrowserThemeEnabled(const FeatureContext*) { return RootScrollbarFollowsBrowserThemeEnabled(); }

  static bool RouteMatchingEnabled() {
    return feature_states_[kRouteMatchingFlagIndex];
  }

  static bool RouteMatchingEnabled(const FeatureContext*) { return RouteMatchingEnabled(); }

  static bool RtcAlwaysNegotiateDataChannelsEnabled() {
    return feature_states_[kRtcAlwaysNegotiateDataChannelsFlagIndex];
  }

  static bool RtcAlwaysNegotiateDataChannelsEnabled(const FeatureContext*) { return RtcAlwaysNegotiateDataChannelsEnabled(); }

  static bool RTCConfigurationIceTransportsEnabled() {
    return feature_states_[kRTCConfigurationIceTransportsFlagIndex];
  }

  static bool RTCConfigurationIceTransportsEnabled(const FeatureContext*) { return RTCConfigurationIceTransportsEnabled(); }

  static bool RTCDataChannelPriorityEnabled() {
    return feature_states_[kRTCDataChannelPriorityFlagIndex];
  }

  static bool RTCDataChannelPriorityEnabled(const FeatureContext*) { return RTCDataChannelPriorityEnabled(); }

  static bool RTCEncodedAudioFrameConstructorEnabled() {
    return feature_states_[kRTCEncodedAudioFrameConstructorFlagIndex];
  }

  static bool RTCEncodedAudioFrameConstructorEnabled(const FeatureContext*) { return RTCEncodedAudioFrameConstructorEnabled(); }

  static bool RTCEncodedFrameAudioLevelEnabled() {
    return feature_states_[kRTCEncodedFrameAudioLevelFlagIndex];
  }

  static bool RTCEncodedFrameAudioLevelEnabled(const FeatureContext*) { return RTCEncodedFrameAudioLevelEnabled(); }

  static bool RTCEncodedFrameTimestampsEnabled() {
    return feature_states_[kRTCEncodedFrameTimestampsFlagIndex];
  }

  static bool RTCEncodedFrameTimestampsEnabled(const FeatureContext*) { return RTCEncodedFrameTimestampsEnabled(); }

  static bool RTCEncodedSourceEnabled() {
    return feature_states_[kRTCEncodedSourceFlagIndex];
  }

  static bool RTCEncodedSourceEnabled(const FeatureContext*) { return RTCEncodedSourceEnabled(); }

  static bool RTCEncodedVideoFrameAdditionalMetadataEnabled() {
    return feature_states_[kRTCEncodedVideoFrameAdditionalMetadataFlagIndex];
  }

  static bool RTCEncodedVideoFrameAdditionalMetadataEnabled(const FeatureContext*) { return RTCEncodedVideoFrameAdditionalMetadataEnabled(); }

  static bool RTCEncodedVideoFrameConstructorEnabled() {
    return feature_states_[kRTCEncodedVideoFrameConstructorFlagIndex];
  }

  static bool RTCEncodedVideoFrameConstructorEnabled(const FeatureContext*) { return RTCEncodedVideoFrameConstructorEnabled(); }

  static bool RTCJitterBufferTargetEnabled() {
    return feature_states_[kRTCJitterBufferTargetFlagIndex];
  }

  static bool RTCJitterBufferTargetEnabled(const FeatureContext*) { return RTCJitterBufferTargetEnabled(); }

  static bool RTCRtpEncodingParametersCodecEnabled() {
    return feature_states_[kRTCRtpEncodingParametersCodecFlagIndex];
  }

  static bool RTCRtpEncodingParametersCodecEnabled(const FeatureContext*) { return RTCRtpEncodingParametersCodecEnabled(); }

  static bool RtcRtpHeaderEncryptionPolicyEnabled() {
    return feature_states_[kRtcRtpHeaderEncryptionPolicyFlagIndex];
  }

  static bool RtcRtpHeaderEncryptionPolicyEnabled(const FeatureContext*) { return RtcRtpHeaderEncryptionPolicyEnabled(); }

  static bool RTCRtpScaleResolutionDownToEnabled() {
    return feature_states_[kRTCRtpScaleResolutionDownToFlagIndex];
  }

  static bool RTCRtpScaleResolutionDownToEnabled(const FeatureContext*) { return RTCRtpScaleResolutionDownToEnabled(); }

  static bool RTCRtpScriptTransformEnabled() {
    return feature_states_[kRTCRtpScriptTransformFlagIndex];
  }

  static bool RTCRtpScriptTransformEnabled(const FeatureContext*) { return RTCRtpScriptTransformEnabled(); }

  static bool RTCRtpTransportEnabled() {
    return feature_states_[kRTCRtpTransportFlagIndex];
  }

  static bool RTCRtpTransportEnabled(const FeatureContext*) { return RTCRtpTransportEnabled(); }

  static bool RTCSvcScalabilityModeEnabled() {
    return feature_states_[kRTCSvcScalabilityModeFlagIndex];
  }

  static bool RTCSvcScalabilityModeEnabled(const FeatureContext*) { return RTCSvcScalabilityModeEnabled(); }

  static bool RunMicrotaskBeforeXmlScriptEnabled() {
    return feature_states_[kRunMicrotaskBeforeXmlScriptFlagIndex];
  }

  static bool RunMicrotaskBeforeXmlScriptEnabled(const FeatureContext*) { return RunMicrotaskBeforeXmlScriptEnabled(); }

  static bool RunSnapshotPostLayoutStateStepsEnabled() {
    return feature_states_[kRunSnapshotPostLayoutStateStepsFlagIndex];
  }

  static bool RunSnapshotPostLayoutStateStepsEnabled(const FeatureContext*) { return RunSnapshotPostLayoutStateStepsEnabled(); }

  static bool SanitizeIDNEmailFormInputEnabled() {
    return feature_states_[kSanitizeIDNEmailFormInputFlagIndex];
  }

  static bool SanitizeIDNEmailFormInputEnabled(const FeatureContext*) { return SanitizeIDNEmailFormInputEnabled(); }

  static bool SanitizerAPIEnabled() {
    return feature_states_[kSanitizerAPIFlagIndex];
  }

  static bool SanitizerAPIEnabled(const FeatureContext*) { return SanitizerAPIEnabled(); }

  static bool ScopedViewTransitionSizeContainmentEnabled() {
    return feature_states_[kScopedViewTransitionSizeContainmentFlagIndex];
  }

  static bool ScopedViewTransitionSizeContainmentEnabled(const FeatureContext*) { return ScopedViewTransitionSizeContainmentEnabled(); }

  static bool ScoreLineBreakerAbortEnabled() {
    return feature_states_[kScoreLineBreakerAbortFlagIndex];
  }

  static bool ScoreLineBreakerAbortEnabled(const FeatureContext*) { return ScoreLineBreakerAbortEnabled(); }

  static bool ScreenDetailedHdrHeadroomEnabled() {
    return feature_states_[kScreenDetailedHdrHeadroomFlagIndex];
  }

  static bool ScreenDetailedHdrHeadroomEnabled(const FeatureContext*) { return ScreenDetailedHdrHeadroomEnabled(); }

  static bool ScriptBasedOnUnicodeBlockEnabled() {
    return feature_states_[kScriptBasedOnUnicodeBlockFlagIndex];
  }

  static bool ScriptBasedOnUnicodeBlockEnabled(const FeatureContext*) { return ScriptBasedOnUnicodeBlockEnabled(); }

  static bool ScriptedSpeechRecognitionEnabled() {
    return feature_states_[kScriptedSpeechRecognitionFlagIndex];
  }

  static bool ScriptedSpeechRecognitionEnabled(const FeatureContext*) { return ScriptedSpeechRecognitionEnabled(); }

  static bool ScriptedSpeechSynthesisEnabled() {
    return feature_states_[kScriptedSpeechSynthesisFlagIndex];
  }

  static bool ScriptedSpeechSynthesisEnabled(const FeatureContext*) { return ScriptedSpeechSynthesisEnabled(); }

  static bool ScrollAnchorPriorityCandidateSubtreeEnabled() {
    return feature_states_[kScrollAnchorPriorityCandidateSubtreeFlagIndex];
  }

  static bool ScrollAnchorPriorityCandidateSubtreeEnabled(const FeatureContext*) { return ScrollAnchorPriorityCandidateSubtreeEnabled(); }

  static bool ScrollAnchorSerializationUseParentForTextNodeEnabled() {
    return feature_states_[kScrollAnchorSerializationUseParentForTextNodeFlagIndex];
  }

  static bool ScrollAnchorSerializationUseParentForTextNodeEnabled(const FeatureContext*) { return ScrollAnchorSerializationUseParentForTextNodeEnabled(); }

  static bool ScrollAxisLockEnabled() {
    return feature_states_[kScrollAxisLockFlagIndex];
  }

  static bool ScrollAxisLockEnabled(const FeatureContext*) { return ScrollAxisLockEnabled(); }

  static bool ScrollbarColorEnabled() {
    return feature_states_[kScrollbarColorFlagIndex];
  }

  static bool ScrollbarColorEnabled(const FeatureContext*) { return ScrollbarColorEnabled(); }

  static bool ScrollbarGutterBugFixEnabled() {
    return feature_states_[kScrollbarGutterBugFixFlagIndex];
  }

  static bool ScrollbarGutterBugFixEnabled(const FeatureContext*) { return ScrollbarGutterBugFixEnabled(); }

  static bool ScrollbarWidthEnabled() {
    return feature_states_[kScrollbarWidthFlagIndex];
  }

  static bool ScrollbarWidthEnabled(const FeatureContext*) { return ScrollbarWidthEnabled(); }

  static bool ScrollingContentsCullRectOnScrollNodeEnabled() {
    if (MergeStickyLayersEnabled())
      return true;
    return feature_states_[kScrollingContentsCullRectOnScrollNodeFlagIndex];
  }

  static bool ScrollingContentsCullRectOnScrollNodeEnabled(const FeatureContext*) { return ScrollingContentsCullRectOnScrollNodeEnabled(); }

  static bool ScrollIntoViewAlignAutoEnabled() {
    return feature_states_[kScrollIntoViewAlignAutoFlagIndex];
  }

  static bool ScrollIntoViewAlignAutoEnabled(const FeatureContext*) { return ScrollIntoViewAlignAutoEnabled(); }

  static bool ScrollIntoViewNearestEnabled() {
    return feature_states_[kScrollIntoViewNearestFlagIndex];
  }

  static bool ScrollIntoViewNearestEnabled(const FeatureContext*) { return ScrollIntoViewNearestEnabled(); }

  static bool ScrollIntoViewRootFrameViewportBugFixEnabled() {
    return feature_states_[kScrollIntoViewRootFrameViewportBugFixFlagIndex];
  }

  static bool ScrollIntoViewRootFrameViewportBugFixEnabled(const FeatureContext*) { return ScrollIntoViewRootFrameViewportBugFixEnabled(); }

  static bool ScrollPerformanceTimingEnabled() {
    return feature_states_[kScrollPerformanceTimingFlagIndex];
  }

  static bool ScrollPerformanceTimingEnabled(const FeatureContext*) { return ScrollPerformanceTimingEnabled(); }

  static bool ScrollTimelineCurrentTimeEnabled() {
    return feature_states_[kScrollTimelineCurrentTimeFlagIndex];
  }

  static bool ScrollTimelineCurrentTimeEnabled(const FeatureContext*) { return ScrollTimelineCurrentTimeEnabled(); }

  static bool ScrollTimelineNamedRangeScrollEnabled() {
    return feature_states_[kScrollTimelineNamedRangeScrollFlagIndex];
  }

  static bool ScrollTimelineNamedRangeScrollEnabled(const FeatureContext*) { return ScrollTimelineNamedRangeScrollEnabled(); }

  static bool ScrollTopLeftInteropEnabled() {
    return feature_states_[kScrollTopLeftInteropFlagIndex];
  }

  static bool ScrollTopLeftInteropEnabled(const FeatureContext*) { return ScrollTopLeftInteropEnabled(); }

  static bool ScrollToTextFragmentDirectiveLimitEnabled() {
    return feature_states_[kScrollToTextFragmentDirectiveLimitFlagIndex];
  }

  static bool ScrollToTextFragmentDirectiveLimitEnabled(const FeatureContext*) { return ScrollToTextFragmentDirectiveLimitEnabled(); }

  static bool ScrollToTextFragmentUniqueFragmentsEnabled() {
    return feature_states_[kScrollToTextFragmentUniqueFragmentsFlagIndex];
  }

  static bool ScrollToTextFragmentUniqueFragmentsEnabled(const FeatureContext*) { return ScrollToTextFragmentUniqueFragmentsEnabled(); }

  static bool SearchTextHighlightPseudoEnabled() {
    return feature_states_[kSearchTextHighlightPseudoFlagIndex];
  }

  static bool SearchTextHighlightPseudoEnabled(const FeatureContext*) { return SearchTextHighlightPseudoEnabled(); }

  static bool SecurePaymentConfirmationEnabled() {
    return feature_states_[kSecurePaymentConfirmationFlagIndex];
  }

  static bool SecurePaymentConfirmationEnabled(const FeatureContext*) { return SecurePaymentConfirmationEnabled(); }

  static bool SecurePaymentConfirmationAvailabilityAPIEnabled() {
    return feature_states_[kSecurePaymentConfirmationAvailabilityAPIFlagIndex];
  }

  static bool SecurePaymentConfirmationAvailabilityAPIEnabled(const FeatureContext*) { return SecurePaymentConfirmationAvailabilityAPIEnabled(); }

  static bool SecurePaymentConfirmationCapabilitiesEnabled() {
    return feature_states_[kSecurePaymentConfirmationCapabilitiesFlagIndex];
  }

  static bool SecurePaymentConfirmationCapabilitiesEnabled(const FeatureContext*) { return SecurePaymentConfirmationCapabilitiesEnabled(); }

  static bool SecurePaymentConfirmationDebugEnabled() {
    return feature_states_[kSecurePaymentConfirmationDebugFlagIndex];
  }

  static bool SecurePaymentConfirmationDebugEnabled(const FeatureContext*) { return SecurePaymentConfirmationDebugEnabled(); }

  static bool SecurePaymentConfirmationExtensionsDisallowForThirdPartiesEnabled() {
    return feature_states_[kSecurePaymentConfirmationExtensionsDisallowForThirdPartiesFlagIndex];
  }

  static bool SecurePaymentConfirmationExtensionsDisallowForThirdPartiesEnabled(const FeatureContext*) { return SecurePaymentConfirmationExtensionsDisallowForThirdPartiesEnabled(); }

  static bool SelectAnchorInViewportEnabled() {
    return feature_states_[kSelectAnchorInViewportFlagIndex];
  }

  static bool SelectAnchorInViewportEnabled(const FeatureContext*) { return SelectAnchorInViewportEnabled(); }

  static bool SelectAudioOutputEnabled() {
    return feature_states_[kSelectAudioOutputFlagIndex];
  }

  static bool SelectAudioOutputEnabled(const FeatureContext*) { return SelectAudioOutputEnabled(); }

  static bool SelectedcontentelementAttributeEnabled() {
    if (!SelectedcontentSpecEnabled())
      return false;
    return feature_states_[kSelectedcontentelementAttributeFlagIndex];
  }

  static bool SelectedcontentelementAttributeEnabled(const FeatureContext*) { return SelectedcontentelementAttributeEnabled(); }

  static bool SelectedcontentMultipleEnabled() {
    if (!SelectedcontentSpecEnabled())
      return false;
    if (!CustomizableSelectMultiplePopupEnabled())
      return false;
    return feature_states_[kSelectedcontentMultipleFlagIndex];
  }

  static bool SelectedcontentMultipleEnabled(const FeatureContext*) { return SelectedcontentMultipleEnabled(); }

  static bool SelectedcontentSpecEnabled() {
    return feature_states_[kSelectedcontentSpecFlagIndex];
  }

  static bool SelectedcontentSpecEnabled(const FeatureContext*) { return SelectedcontentSpecEnabled(); }

  static bool SelectionAndFocusedVisiblePositionMatchEnabled() {
    return feature_states_[kSelectionAndFocusedVisiblePositionMatchFlagIndex];
  }

  static bool SelectionAndFocusedVisiblePositionMatchEnabled(const FeatureContext*) { return SelectionAndFocusedVisiblePositionMatchEnabled(); }

  static bool SelectionCollapsedDirectionNoneEnabled() {
    return feature_states_[kSelectionCollapsedDirectionNoneFlagIndex];
  }

  static bool SelectionCollapsedDirectionNoneEnabled(const FeatureContext*) { return SelectionCollapsedDirectionNoneEnabled(); }

  static bool SelectionEditingBoundarySlottedContentEnabled() {
    return feature_states_[kSelectionEditingBoundarySlottedContentFlagIndex];
  }

  static bool SelectionEditingBoundarySlottedContentEnabled(const FeatureContext*) { return SelectionEditingBoundarySlottedContentEnabled(); }

  static bool SelectionFocusAffinityEnabled() {
    return feature_states_[kSelectionFocusAffinityFlagIndex];
  }

  static bool SelectionFocusAffinityEnabled(const FeatureContext*) { return SelectionFocusAffinityEnabled(); }

  static bool SelectionHandleWithBottomClippedEnabled() {
    return feature_states_[kSelectionHandleWithBottomClippedFlagIndex];
  }

  static bool SelectionHandleWithBottomClippedEnabled(const FeatureContext*) { return SelectionHandleWithBottomClippedEnabled(); }

  static bool SelectionRemoveRangeNotFoundErrorEnabled() {
    return feature_states_[kSelectionRemoveRangeNotFoundErrorFlagIndex];
  }

  static bool SelectionRemoveRangeNotFoundErrorEnabled(const FeatureContext*) { return SelectionRemoveRangeNotFoundErrorEnabled(); }

  static bool SelectionSetBaseAndExtentNonNullNodeEnabled() {
    return feature_states_[kSelectionSetBaseAndExtentNonNullNodeFlagIndex];
  }

  static bool SelectionSetBaseAndExtentNonNullNodeEnabled(const FeatureContext*) { return SelectionSetBaseAndExtentNonNullNodeEnabled(); }

  static bool SelectiveClipboardFormatReadEnabled() {
    return feature_states_[kSelectiveClipboardFormatReadFlagIndex];
  }

  static bool SelectiveClipboardFormatReadEnabled(const FeatureContext*) { return SelectiveClipboardFormatReadEnabled(); }

  static bool SelectivePermissionsInterventionEnabled() {
    return feature_states_[kSelectivePermissionsInterventionFlagIndex];
  }

  static bool SelectivePermissionsInterventionEnabled(const FeatureContext*) { return SelectivePermissionsInterventionEnabled(); }

  static bool SelectRemoveOverflowHiddenEnabled() {
    return feature_states_[kSelectRemoveOverflowHiddenFlagIndex];
  }

  static bool SelectRemoveOverflowHiddenEnabled(const FeatureContext*) { return SelectRemoveOverflowHiddenEnabled(); }

  static bool SelectUsesFlatTreeEnabled() {
    return feature_states_[kSelectUsesFlatTreeFlagIndex];
  }

  static bool SelectUsesFlatTreeEnabled(const FeatureContext*) { return SelectUsesFlatTreeEnabled(); }

  static bool SendBeaconThrowForBlobWithNonSimpleTypeEnabled() {
    return feature_states_[kSendBeaconThrowForBlobWithNonSimpleTypeFlagIndex];
  }

  static bool SendBeaconThrowForBlobWithNonSimpleTypeEnabled(const FeatureContext*) { return SendBeaconThrowForBlobWithNonSimpleTypeEnabled(); }

  static bool SendEarlyLastBeginMainFrameEnabled() {
    return feature_states_[kSendEarlyLastBeginMainFrameFlagIndex];
  }

  static bool SendEarlyLastBeginMainFrameEnabled(const FeatureContext*) { return SendEarlyLastBeginMainFrameEnabled(); }

  static bool SendSlotChangeSignalAfterNodeInsertedEnabled() {
    return feature_states_[kSendSlotChangeSignalAfterNodeInsertedFlagIndex];
  }

  static bool SendSlotChangeSignalAfterNodeInsertedEnabled(const FeatureContext*) { return SendSlotChangeSignalAfterNodeInsertedEnabled(); }

  static bool SensorExtraClassesEnabled() {
    return feature_states_[kSensorExtraClassesFlagIndex];
  }

  static bool SensorExtraClassesEnabled(const FeatureContext*) { return SensorExtraClassesEnabled(); }

  static bool SeparateDeferModuleScriptTasksEnabled() {
    return feature_states_[kSeparateDeferModuleScriptTasksFlagIndex];
  }

  static bool SeparateDeferModuleScriptTasksEnabled(const FeatureContext*) { return SeparateDeferModuleScriptTasksEnabled(); }

  static bool SerialEnabled() {
    return feature_states_[kSerialFlagIndex];
  }

  static bool SerialEnabled(const FeatureContext*) { return SerialEnabled(); }

  static bool SerializeInvalidSelectorsInForgivingSelectorListEnabled() {
    return feature_states_[kSerializeInvalidSelectorsInForgivingSelectorListFlagIndex];
  }

  static bool SerializeInvalidSelectorsInForgivingSelectorListEnabled(const FeatureContext*) { return SerializeInvalidSelectorsInForgivingSelectorListEnabled(); }

  static bool SerializeViewTransitionStateInSPAEnabled() {
    return feature_states_[kSerializeViewTransitionStateInSPAFlagIndex];
  }

  static bool SerializeViewTransitionStateInSPAEnabled(const FeatureContext*) { return SerializeViewTransitionStateInSPAEnabled(); }

  static bool SerialPortConnectedEnabled() {
    return feature_states_[kSerialPortConnectedFlagIndex];
  }

  static bool SerialPortConnectedEnabled(const FeatureContext*) { return SerialPortConnectedEnabled(); }

  static bool ServiceWorkerBackgroundSyncInDedicatedWorkerEnabled() {
    if (!ServiceWorkerInDedicatedWorkerEnabled())
      return false;
    return feature_states_[kServiceWorkerBackgroundSyncInDedicatedWorkerFlagIndex];
  }

  static bool ServiceWorkerBackgroundSyncInDedicatedWorkerEnabled(const FeatureContext*) { return ServiceWorkerBackgroundSyncInDedicatedWorkerEnabled(); }

  static bool ServiceWorkerClientLifecycleStateEnabled() {
    return feature_states_[kServiceWorkerClientLifecycleStateFlagIndex];
  }

  static bool ServiceWorkerClientLifecycleStateEnabled(const FeatureContext*) { return ServiceWorkerClientLifecycleStateEnabled(); }

  static bool ServiceWorkerCodeCacheEnabled() {
    return feature_states_[kServiceWorkerCodeCacheFlagIndex];
  }

  static bool ServiceWorkerCodeCacheEnabled(const FeatureContext*) { return ServiceWorkerCodeCacheEnabled(); }

  static bool ServiceWorkerInDedicatedWorkerEnabled() {
    return feature_states_[kServiceWorkerInDedicatedWorkerFlagIndex];
  }

  static bool ServiceWorkerInDedicatedWorkerEnabled(const FeatureContext*) { return ServiceWorkerInDedicatedWorkerEnabled(); }

  static bool ServiceWorkerStaticRouterTimingInfoEnabled() {
    return feature_states_[kServiceWorkerStaticRouterTimingInfoFlagIndex];
  }

  static bool ServiceWorkerStaticRouterTimingInfoEnabled(const FeatureContext*) { return ServiceWorkerStaticRouterTimingInfoEnabled(); }

  static bool SetHTMLCanRunScriptsEnabled() {
    return feature_states_[kSetHTMLCanRunScriptsFlagIndex];
  }

  static bool SetHTMLCanRunScriptsEnabled(const FeatureContext*) { return SetHTMLCanRunScriptsEnabled(); }

  static bool SetSequentialFocusStartingPointEnabled() {
    return feature_states_[kSetSequentialFocusStartingPointFlagIndex];
  }

  static bool SetSequentialFocusStartingPointEnabled(const FeatureContext*) { return SetSequentialFocusStartingPointEnabled(); }

  static bool SetShapeEnabled() {
    return feature_states_[kSetShapeFlagIndex];
  }

  static bool SetShapeEnabled(const FeatureContext*);

  static bool ShadowRootNamespaceCheckEnabled() {
    return feature_states_[kShadowRootNamespaceCheckFlagIndex];
  }

  static bool ShadowRootNamespaceCheckEnabled(const FeatureContext*) { return ShadowRootNamespaceCheckEnabled(); }

  static bool ShadowRootReferenceTargetAriaOwnsEnabled() {
    return feature_states_[kShadowRootReferenceTargetAriaOwnsFlagIndex];
  }

  static bool ShadowRootReferenceTargetAriaOwnsEnabled(const FeatureContext*) { return ShadowRootReferenceTargetAriaOwnsEnabled(); }

  static bool ShadowRootSlotAssignmentEnabled() {
    return feature_states_[kShadowRootSlotAssignmentFlagIndex];
  }

  static bool ShadowRootSlotAssignmentEnabled(const FeatureContext*) { return ShadowRootSlotAssignmentEnabled(); }

  static bool SharedArrayBufferEnabled() {
    return feature_states_[kSharedArrayBufferFlagIndex];
  }

  static bool SharedArrayBufferEnabled(const FeatureContext*) { return SharedArrayBufferEnabled(); }

  static bool SharedArrayBufferUnrestrictedAccessAllowedEnabled() {
    return feature_states_[kSharedArrayBufferUnrestrictedAccessAllowedFlagIndex];
  }

  static bool SharedArrayBufferUnrestrictedAccessAllowedEnabled(const FeatureContext*) { return SharedArrayBufferUnrestrictedAccessAllowedEnabled(); }

  static bool SharedStorageAPIEnabled() {
    return feature_states_[kSharedStorageAPIFlagIndex];
  }

  static bool SharedStorageAPIEnabled(const FeatureContext*) { return SharedStorageAPIEnabled(); }

  static bool SharedStorageWebLocksEnabled() {
    if (!SharedStorageAPIEnabled())
      return false;
    return feature_states_[kSharedStorageWebLocksFlagIndex];
  }

  static bool SharedStorageWebLocksEnabled(const FeatureContext*) { return SharedStorageWebLocksEnabled(); }

  static bool SharedWorkerEnabled() {
    return feature_states_[kSharedWorkerFlagIndex];
  }

  static bool SharedWorkerEnabled(const FeatureContext*) { return SharedWorkerEnabled(); }

  static bool SideRelativeBackgroundPositionEnabled() {
    return feature_states_[kSideRelativeBackgroundPositionFlagIndex];
  }

  static bool SideRelativeBackgroundPositionEnabled(const FeatureContext*) { return SideRelativeBackgroundPositionEnabled(); }

  static bool SignatureBasedInlineIntegrityEnabled() {
    return feature_states_[kSignatureBasedInlineIntegrityFlagIndex];
  }

  static bool SignatureBasedInlineIntegrityEnabled(const FeatureContext*) { return SignatureBasedInlineIntegrityEnabled(); }

  static bool SingleAxisScrollContainersEnabled() {
    return feature_states_[kSingleAxisScrollContainersFlagIndex];
  }

  static bool SingleAxisScrollContainersEnabled(const FeatureContext*) { return SingleAxisScrollContainersEnabled(); }

  static bool SingleAxisScrollContainersForScrollSnapEnabled() {
    if (!SingleAxisScrollContainersEnabled())
      return false;
    return feature_states_[kSingleAxisScrollContainersForScrollSnapFlagIndex];
  }

  static bool SingleAxisScrollContainersForScrollSnapEnabled(const FeatureContext*) { return SingleAxisScrollContainersForScrollSnapEnabled(); }

  static bool SkipAdEnabled() {
    if (!MediaSessionEnabled())
      return false;
    return feature_states_[kSkipAdFlagIndex];
  }

  static bool SkipAdEnabled(const FeatureContext*) { return SkipAdEnabled(); }

  static bool SkipCallbacksWhenDevToolsNotOpenEnabled() {
    return feature_states_[kSkipCallbacksWhenDevToolsNotOpenFlagIndex];
  }

  static bool SkipCallbacksWhenDevToolsNotOpenEnabled(const FeatureContext*) { return SkipCallbacksWhenDevToolsNotOpenEnabled(); }

  static bool SkipEventCaptureEnabled() {
    return feature_states_[kSkipEventCaptureFlagIndex];
  }

  static bool SkipEventCaptureEnabled(const FeatureContext*) { return SkipEventCaptureEnabled(); }

  static bool SkipStaleUndoStepsInIdleSpellCheckEnabled() {
    return feature_states_[kSkipStaleUndoStepsInIdleSpellCheckFlagIndex];
  }

  static bool SkipStaleUndoStepsInIdleSpellCheckEnabled(const FeatureContext*) { return SkipStaleUndoStepsInIdleSpellCheckEnabled(); }

  static bool SkipTouchEventFilterEnabled() {
    return feature_states_[kSkipTouchEventFilterFlagIndex];
  }

  static bool SkipTouchEventFilterEnabled(const FeatureContext*) { return SkipTouchEventFilterEnabled(); }

  static bool SkipUnselectableElementsInParagraphBoundaryEnabled() {
    return feature_states_[kSkipUnselectableElementsInParagraphBoundaryFlagIndex];
  }

  static bool SkipUnselectableElementsInParagraphBoundaryEnabled(const FeatureContext*) { return SkipUnselectableElementsInParagraphBoundaryEnabled(); }

  static bool SkipViewTransitionSnapshotResumeRenderingEnabled() {
    return feature_states_[kSkipViewTransitionSnapshotResumeRenderingFlagIndex];
  }

  static bool SkipViewTransitionSnapshotResumeRenderingEnabled(const FeatureContext*) { return SkipViewTransitionSnapshotResumeRenderingEnabled(); }

  static bool SmallerViewportUnitsEnabled() {
    return feature_states_[kSmallerViewportUnitsFlagIndex];
  }

  static bool SmallerViewportUnitsEnabled(const FeatureContext*) { return SmallerViewportUnitsEnabled(); }

  static bool SmartCardEnabled() {
    return feature_states_[kSmartCardFlagIndex];
  }

  static bool SmartCardEnabled(const FeatureContext*) { return SmartCardEnabled(); }

  static bool SmartZoomEnabled() {
    return feature_states_[kSmartZoomFlagIndex];
  }

  static bool SmartZoomEnabled(const FeatureContext*) { return SmartZoomEnabled(); }

  static bool SnapshotScrollTimelinesPostLayoutEnabled() {
    if (!RunSnapshotPostLayoutStateStepsEnabled())
      return false;
    return feature_states_[kSnapshotScrollTimelinesPostLayoutFlagIndex];
  }

  static bool SnapshotScrollTimelinesPostLayoutEnabled(const FeatureContext*) { return SnapshotScrollTimelinesPostLayoutEnabled(); }

  static bool SortedLayoutShiftSourcesByImpactAreaEnabled() {
    return feature_states_[kSortedLayoutShiftSourcesByImpactAreaFlagIndex];
  }

  static bool SortedLayoutShiftSourcesByImpactAreaEnabled(const FeatureContext*) { return SortedLayoutShiftSourcesByImpactAreaEnabled(); }

  static bool SourceSpecificMulticastInDirectSocketsEnabled() {
    return feature_states_[kSourceSpecificMulticastInDirectSocketsFlagIndex];
  }

  static bool SourceSpecificMulticastInDirectSocketsEnabled(const FeatureContext*) { return SourceSpecificMulticastInDirectSocketsEnabled(); }

  static bool SpatNavUsesCursorInheritanceEnabled() {
    return feature_states_[kSpatNavUsesCursorInheritanceFlagIndex];
  }

  static bool SpatNavUsesCursorInheritanceEnabled(const FeatureContext*) { return SpatNavUsesCursorInheritanceEnabled(); }

  static bool SpeakerSelectionEnabled() {
    return feature_states_[kSpeakerSelectionFlagIndex];
  }

  static bool SpeakerSelectionEnabled(const FeatureContext*) { return SpeakerSelectionEnabled(); }

  static bool SpecCompliantXmlMimeTypesEnabled() {
    return feature_states_[kSpecCompliantXmlMimeTypesFlagIndex];
  }

  static bool SpecCompliantXmlMimeTypesEnabled(const FeatureContext*) { return SpecCompliantXmlMimeTypesEnabled(); }

  static bool SpellCheckChunkingEnabled() {
    return feature_states_[kSpellCheckChunkingFlagIndex];
  }

  static bool SpellCheckChunkingEnabled(const FeatureContext*) { return SpellCheckChunkingEnabled(); }

  static bool SpellCheckCustomDictionaryAPIEnabled() {
    return feature_states_[kSpellCheckCustomDictionaryAPIFlagIndex];
  }

  static bool SpellCheckCustomDictionaryAPIEnabled(const FeatureContext*) { return SpellCheckCustomDictionaryAPIEnabled(); }

  static bool SplitLargeTextNodesEnabled() {
    return feature_states_[kSplitLargeTextNodesFlagIndex];
  }

  static bool SplitLargeTextNodesEnabled(const FeatureContext*) { return SplitLargeTextNodesEnabled(); }

  static bool SplitQualifiedNameOnFirstColonEnabled() {
    return feature_states_[kSplitQualifiedNameOnFirstColonFlagIndex];
  }

  static bool SplitQualifiedNameOnFirstColonEnabled(const FeatureContext*) { return SplitQualifiedNameOnFirstColonEnabled(); }

  static bool SplitTextNotCleanupDummySpansEnabled() {
    return feature_states_[kSplitTextNotCleanupDummySpansFlagIndex];
  }

  static bool SplitTextNotCleanupDummySpansEnabled(const FeatureContext*) { return SplitTextNotCleanupDummySpansEnabled(); }

  static bool SrcsetSelectionMatchesImageSetEnabled() {
    return feature_states_[kSrcsetSelectionMatchesImageSetFlagIndex];
  }

  static bool SrcsetSelectionMatchesImageSetEnabled(const FeatureContext*) { return SrcsetSelectionMatchesImageSetEnabled(); }

  static bool StableBlinkFeaturesEnabled() {
    return feature_states_[kStableBlinkFeaturesFlagIndex];
  }

  static bool StableBlinkFeaturesEnabled(const FeatureContext*) { return StableBlinkFeaturesEnabled(); }

  static bool StackingContextIsNotStackedEnabled() {
    return feature_states_[kStackingContextIsNotStackedFlagIndex];
  }

  static bool StackingContextIsNotStackedEnabled(const FeatureContext*) { return StackingContextIsNotStackedEnabled(); }

  static bool StaleImageNaturalSizeDuringRevalidationEnabled() {
    return feature_states_[kStaleImageNaturalSizeDuringRevalidationFlagIndex];
  }

  static bool StaleImageNaturalSizeDuringRevalidationEnabled(const FeatureContext*) { return StaleImageNaturalSizeDuringRevalidationEnabled(); }

  static bool StandardizedBrowserZoomEnabled() {
    return feature_states_[kStandardizedBrowserZoomFlagIndex];
  }

  static bool StandardizedBrowserZoomEnabled(const FeatureContext*) { return StandardizedBrowserZoomEnabled(); }

  static bool StickyPositionHasOverflowPerAxisEnabled() {
    return feature_states_[kStickyPositionHasOverflowPerAxisFlagIndex];
  }

  static bool StickyPositionHasOverflowPerAxisEnabled(const FeatureContext*) { return StickyPositionHasOverflowPerAxisEnabled(); }

  static bool StickyUserActivationAcrossSameOriginNavigationEnabled() {
    return feature_states_[kStickyUserActivationAcrossSameOriginNavigationFlagIndex];
  }

  static bool StickyUserActivationAcrossSameOriginNavigationEnabled(const FeatureContext*) { return StickyUserActivationAcrossSameOriginNavigationEnabled(); }

  static bool StorageBucketsEnabled() {
    return feature_states_[kStorageBucketsFlagIndex];
  }

  static bool StorageBucketsEnabled(const FeatureContext*) { return StorageBucketsEnabled(); }

  static bool StorageBucketsDurabilityEnabled() {
    return feature_states_[kStorageBucketsDurabilityFlagIndex];
  }

  static bool StorageBucketsDurabilityEnabled(const FeatureContext*) { return StorageBucketsDurabilityEnabled(); }

  static bool StorageBucketsLocksEnabled() {
    return feature_states_[kStorageBucketsLocksFlagIndex];
  }

  static bool StorageBucketsLocksEnabled(const FeatureContext*) { return StorageBucketsLocksEnabled(); }

  static bool StreamingSanitizerEnabled() {
    return feature_states_[kStreamingSanitizerFlagIndex];
  }

  static bool StreamingSanitizerEnabled(const FeatureContext*) { return StreamingSanitizerEnabled(); }

  static bool StrictMimeTypesForWorkersEnabled() {
    return feature_states_[kStrictMimeTypesForWorkersFlagIndex];
  }

  static bool StrictMimeTypesForWorkersEnabled(const FeatureContext*) { return StrictMimeTypesForWorkersEnabled(); }

  static bool StylusHandwritingEnabled() {
    return feature_states_[kStylusHandwritingFlagIndex];
  }

  static bool StylusHandwritingEnabled(const FeatureContext*) { return StylusHandwritingEnabled(); }

  static bool SubAppsEnabled() {
    return feature_states_[kSubAppsFlagIndex];
  }

  static bool SubAppsEnabled(const FeatureContext*) { return SubAppsEnabled(); }

  static bool SuppressPointerStreamAfterDragEnabled() {
    return feature_states_[kSuppressPointerStreamAfterDragFlagIndex];
  }

  static bool SuppressPointerStreamAfterDragEnabled(const FeatureContext*) { return SuppressPointerStreamAfterDragEnabled(); }

  static bool SvgAnimateMotionDiscreteCalcModeEnabled() {
    return feature_states_[kSvgAnimateMotionDiscreteCalcModeFlagIndex];
  }

  static bool SvgAnimateMotionDiscreteCalcModeEnabled(const FeatureContext*) { return SvgAnimateMotionDiscreteCalcModeEnabled(); }

  static bool SvgAvoidResettingFilterQualityForTiledPatternEnabled() {
    return feature_states_[kSvgAvoidResettingFilterQualityForTiledPatternFlagIndex];
  }

  static bool SvgAvoidResettingFilterQualityForTiledPatternEnabled(const FeatureContext*) { return SvgAvoidResettingFilterQualityForTiledPatternEnabled(); }

  static bool SVGEmbeddedAsReplacedElementEnabled() {
    return feature_states_[kSVGEmbeddedAsReplacedElementFlagIndex];
  }

  static bool SVGEmbeddedAsReplacedElementEnabled(const FeatureContext*) { return SVGEmbeddedAsReplacedElementEnabled(); }

  static bool SvgEmptyAttributeStringParsingFixEnabled() {
    return feature_states_[kSvgEmptyAttributeStringParsingFixFlagIndex];
  }

  static bool SvgEmptyAttributeStringParsingFixEnabled(const FeatureContext*) { return SvgEmptyAttributeStringParsingFixEnabled(); }

  static bool SvgEnableTextDecorationCssStylingEnabled() {
    return feature_states_[kSvgEnableTextDecorationCssStylingFlagIndex];
  }

  static bool SvgEnableTextDecorationCssStylingEnabled(const FeatureContext*) { return SvgEnableTextDecorationCssStylingEnabled(); }

  static bool SvgFallBackToContainerSizeEnabled() {
    return feature_states_[kSvgFallBackToContainerSizeFlagIndex];
  }

  static bool SvgFallBackToContainerSizeEnabled(const FeatureContext*) { return SvgFallBackToContainerSizeEnabled(); }

  static bool SvgFeImageEXIFOrientationEnabled() {
    return feature_states_[kSvgFeImageEXIFOrientationFlagIndex];
  }

  static bool SvgFeImageEXIFOrientationEnabled(const FeatureContext*) { return SvgFeImageEXIFOrientationEnabled(); }

  static bool SvgFeImageSkipHiddenContainerViewportDependenceEnabled() {
    return feature_states_[kSvgFeImageSkipHiddenContainerViewportDependenceFlagIndex];
  }

  static bool SvgFeImageSkipHiddenContainerViewportDependenceEnabled(const FeatureContext*) { return SvgFeImageSkipHiddenContainerViewportDependenceEnabled(); }

  static bool SvgFilterPaintsForHiddenContentEnabled() {
    return feature_states_[kSvgFilterPaintsForHiddenContentFlagIndex];
  }

  static bool SvgFilterPaintsForHiddenContentEnabled(const FeatureContext*) { return SvgFilterPaintsForHiddenContentEnabled(); }

  static bool SvgFilterUserSpaceViewportForSvgEnabled() {
    return feature_states_[kSvgFilterUserSpaceViewportForSvgFlagIndex];
  }

  static bool SvgFilterUserSpaceViewportForSvgEnabled(const FeatureContext*) { return SvgFilterUserSpaceViewportForSvgEnabled(); }

  static bool SvgIgnoreNegativeEllipseRadiiEnabled() {
    return feature_states_[kSvgIgnoreNegativeEllipseRadiiFlagIndex];
  }

  static bool SvgIgnoreNegativeEllipseRadiiEnabled(const FeatureContext*) { return SvgIgnoreNegativeEllipseRadiiEnabled(); }

  static bool SvgIgnoreOuterTransformsEnabled() {
    return feature_states_[kSvgIgnoreOuterTransformsFlagIndex];
  }

  static bool SvgIgnoreOuterTransformsEnabled(const FeatureContext*) { return SvgIgnoreOuterTransformsEnabled(); }

  static bool SvgImageAnimationResetEnabled() {
    return feature_states_[kSvgImageAnimationResetFlagIndex];
  }

  static bool SvgImageAnimationResetEnabled(const FeatureContext*) { return SvgImageAnimationResetEnabled(); }

  static bool SvgImageNonUniformScalingFixEnabled() {
    return feature_states_[kSvgImageNonUniformScalingFixFlagIndex];
  }

  static bool SvgImageNonUniformScalingFixEnabled(const FeatureContext*) { return SvgImageNonUniformScalingFixEnabled(); }

  static bool SvgInlineRootPixelSnappingScaleAdjustmentEnabled() {
    return feature_states_[kSvgInlineRootPixelSnappingScaleAdjustmentFlagIndex];
  }

  static bool SvgInlineRootPixelSnappingScaleAdjustmentEnabled(const FeatureContext*) { return SvgInlineRootPixelSnappingScaleAdjustmentEnabled(); }

  static bool SvgInstanceSyncOptimizationEnabled() {
    return feature_states_[kSvgInstanceSyncOptimizationFlagIndex];
  }

  static bool SvgInstanceSyncOptimizationEnabled(const FeatureContext*) { return SvgInstanceSyncOptimizationEnabled(); }

  static bool SvgLengthResolveUnparsedValueEnabled() {
    return feature_states_[kSvgLengthResolveUnparsedValueFlagIndex];
  }

  static bool SvgLengthResolveUnparsedValueEnabled(const FeatureContext*) { return SvgLengthResolveUnparsedValueEnabled(); }

  static bool SvgNewZoomEnabled() {
    return feature_states_[kSvgNewZoomFlagIndex];
  }

  static bool SvgNewZoomEnabled(const FeatureContext*) { return SvgNewZoomEnabled(); }

  static bool SVGPathDataAPIEnabled() {
    return feature_states_[kSVGPathDataAPIFlagIndex];
  }

  static bool SVGPathDataAPIEnabled(const FeatureContext*) { return SVGPathDataAPIEnabled(); }

  static bool SvgPathLengthCssPropertyEnabled() {
    return feature_states_[kSvgPathLengthCssPropertyFlagIndex];
  }

  static bool SvgPathLengthCssPropertyEnabled(const FeatureContext*) { return SvgPathLengthCssPropertyEnabled(); }

  static bool SvgScriptElementAsyncAttributeEnabled() {
    return feature_states_[kSvgScriptElementAsyncAttributeFlagIndex];
  }

  static bool SvgScriptElementAsyncAttributeEnabled(const FeatureContext*) { return SvgScriptElementAsyncAttributeEnabled(); }

  static bool SvgScriptFragmentAlreadyStartedEnabled() {
    return feature_states_[kSvgScriptFragmentAlreadyStartedFlagIndex];
  }

  static bool SvgScriptFragmentAlreadyStartedEnabled(const FeatureContext*) { return SvgScriptFragmentAlreadyStartedEnabled(); }

  static bool SvgSizingWithPreserveAspectRatioNoneEnabled() {
    return feature_states_[kSvgSizingWithPreserveAspectRatioNoneFlagIndex];
  }

  static bool SvgSizingWithPreserveAspectRatioNoneEnabled(const FeatureContext*) { return SvgSizingWithPreserveAspectRatioNoneEnabled(); }

  static bool SvgStyleElementReflectTypeAndMediaEnabled() {
    return feature_states_[kSvgStyleElementReflectTypeAndMediaFlagIndex];
  }

  static bool SvgStyleElementReflectTypeAndMediaEnabled(const FeatureContext*) { return SvgStyleElementReflectTypeAndMediaEnabled(); }

  static bool SvgSupportMediaFragmentsEnabled() {
    return feature_states_[kSvgSupportMediaFragmentsFlagIndex];
  }

  static bool SvgSupportMediaFragmentsEnabled(const FeatureContext*) { return SvgSupportMediaFragmentsEnabled(); }

  static bool SVGTextPathSideAttributeEnabled() {
    return feature_states_[kSVGTextPathSideAttributeFlagIndex];
  }

  static bool SVGTextPathSideAttributeEnabled(const FeatureContext*) { return SVGTextPathSideAttributeEnabled(); }

  static bool SvgUseNestedResourceDocumentsEnabled() {
    return feature_states_[kSvgUseNestedResourceDocumentsFlagIndex];
  }

  static bool SvgUseNestedResourceDocumentsEnabled(const FeatureContext*) { return SvgUseNestedResourceDocumentsEnabled(); }

  static bool SvgUseNestedResourceDocumentsDelayLoadEnabled() {
    return feature_states_[kSvgUseNestedResourceDocumentsDelayLoadFlagIndex];
  }

  static bool SvgUseNestedResourceDocumentsDelayLoadEnabled(const FeatureContext*) { return SvgUseNestedResourceDocumentsDelayLoadEnabled(); }

  static bool SynthesizedKeyboardEventsForAccessibilityActionsEnabled() {
    return feature_states_[kSynthesizedKeyboardEventsForAccessibilityActionsFlagIndex];
  }

  static bool SynthesizedKeyboardEventsForAccessibilityActionsEnabled(const FeatureContext*) { return SynthesizedKeyboardEventsForAccessibilityActionsEnabled(); }

  static bool SyntheticMouseHoverOverInactivePageEnabled() {
    return feature_states_[kSyntheticMouseHoverOverInactivePageFlagIndex];
  }

  static bool SyntheticMouseHoverOverInactivePageEnabled(const FeatureContext*) { return SyntheticMouseHoverOverInactivePageEnabled(); }

  static bool SystemWakeLockEnabled() {
    return feature_states_[kSystemWakeLockFlagIndex];
  }

  static bool SystemWakeLockEnabled(const FeatureContext*) { return SystemWakeLockEnabled(); }

  static bool TabAlignmentWithFloatsEnabled() {
    return feature_states_[kTabAlignmentWithFloatsFlagIndex];
  }

  static bool TabAlignmentWithFloatsEnabled(const FeatureContext*) { return TabAlignmentWithFloatsEnabled(); }

  static bool TableCellBorderColorInheritEnabled() {
    return feature_states_[kTableCellBorderColorInheritFlagIndex];
  }

  static bool TableCellBorderColorInheritEnabled(const FeatureContext*) { return TableCellBorderColorInheritEnabled(); }

  static bool TableDefaultBorderColorCurrentColorEnabled() {
    return feature_states_[kTableDefaultBorderColorCurrentColorFlagIndex];
  }

  static bool TableDefaultBorderColorCurrentColorEnabled(const FeatureContext*) { return TableDefaultBorderColorCurrentColorEnabled(); }

  static bool TableIsAutoFixedLayoutEnabled() {
    return feature_states_[kTableIsAutoFixedLayoutFlagIndex];
  }

  static bool TableIsAutoFixedLayoutEnabled(const FeatureContext*) { return TableIsAutoFixedLayoutEnabled(); }

  static bool TabSizeInRubyBaseEnabled() {
    return feature_states_[kTabSizeInRubyBaseFlagIndex];
  }

  static bool TabSizeInRubyBaseEnabled(const FeatureContext*) { return TabSizeInRubyBaseEnabled(); }

  static bool TargetInShadowDeterminedBeforeListenerEnabled() {
    return feature_states_[kTargetInShadowDeterminedBeforeListenerFlagIndex];
  }

  static bool TargetInShadowDeterminedBeforeListenerEnabled(const FeatureContext*) { return TargetInShadowDeterminedBeforeListenerEnabled(); }

  static bool TargetRangesForBackwardDeletionUnitEnabled() {
    return feature_states_[kTargetRangesForBackwardDeletionUnitFlagIndex];
  }

  static bool TargetRangesForBackwardDeletionUnitEnabled(const FeatureContext*) { return TargetRangesForBackwardDeletionUnitEnabled(); }

  static bool TestBlinkFeatureDefaultEnabled() {
    return feature_states_[kTestBlinkFeatureDefaultFlagIndex];
  }

  static bool TestBlinkFeatureDefaultEnabled(const FeatureContext*) { return TestBlinkFeatureDefaultEnabled(); }

  static bool TestFeatureEnabled() {
    return feature_states_[kTestFeatureFlagIndex];
  }

  static bool TestFeatureEnabled(const FeatureContext*);

  static bool TestFeatureDependentEnabled() {
    if (!TestFeatureImpliedEnabled())
      return false;
    return feature_states_[kTestFeatureDependentFlagIndex];
  }

  static bool TestFeatureDependentEnabled(const FeatureContext*) { return TestFeatureDependentEnabled(); }

  static bool TestFeatureImpliedEnabled() {
    if (TestFeatureEnabled())
      return true;
    return feature_states_[kTestFeatureImpliedFlagIndex];
  }

  static bool TestFeatureImpliedEnabled(const FeatureContext*) { return TestFeatureImpliedEnabled(); }

  static bool TestFeatureProtectedEnabled() {
    return get_is_test_feature_protected_enabled_();
  }

  static bool TestFeatureProtectedEnabled(const FeatureContext*) { return TestFeatureProtectedEnabled(); }

  static bool TestFeatureProtectedDependentEnabled() {
    if (!TestFeatureProtectedImpliedEnabled())
      return false;
    return get_is_test_feature_protected_dependent_enabled_();
  }

  static bool TestFeatureProtectedDependentEnabled(const FeatureContext*) { return TestFeatureProtectedDependentEnabled(); }

  static bool TestFeatureProtectedImpliedEnabled() {
    if (TestFeatureProtectedEnabled())
      return true;
    return get_is_test_feature_protected_implied_enabled_();
  }

  static bool TestFeatureProtectedImpliedEnabled(const FeatureContext*) { return TestFeatureProtectedImpliedEnabled(); }

  static bool TestFeatureStableEnabled() {
    return feature_states_[kTestFeatureStableFlagIndex];
  }

  static bool TestFeatureStableEnabled(const FeatureContext*) { return TestFeatureStableEnabled(); }

  static bool TextAreaResizerFixedSizeEnabled() {
    return feature_states_[kTextAreaResizerFixedSizeFlagIndex];
  }

  static bool TextAreaResizerFixedSizeEnabled(const FeatureContext*) { return TextAreaResizerFixedSizeEnabled(); }

  static bool TextAutoSpaceIgnoreRubyAnnotationEnabled() {
    return feature_states_[kTextAutoSpaceIgnoreRubyAnnotationFlagIndex];
  }

  static bool TextAutoSpaceIgnoreRubyAnnotationEnabled(const FeatureContext*) { return TextAutoSpaceIgnoreRubyAnnotationEnabled(); }

  static bool TextBoxTrimForNestedListEnabled() {
    return feature_states_[kTextBoxTrimForNestedListFlagIndex];
  }

  static bool TextBoxTrimForNestedListEnabled(const FeatureContext*) { return TextBoxTrimForNestedListEnabled(); }

  static bool TextBoxTrimOnInlineBoxEnabled() {
    return feature_states_[kTextBoxTrimOnInlineBoxFlagIndex];
  }

  static bool TextBoxTrimOnInlineBoxEnabled(const FeatureContext*) { return TextBoxTrimOnInlineBoxEnabled(); }

  static bool TextDetectorEnabled() {
    return feature_states_[kTextDetectorFlagIndex];
  }

  static bool TextDetectorEnabled(const FeatureContext*) { return TextDetectorEnabled(); }

  static bool TextEmphasisLetterSpacingEnabled() {
    return feature_states_[kTextEmphasisLetterSpacingFlagIndex];
  }

  static bool TextEmphasisLetterSpacingEnabled(const FeatureContext*) { return TextEmphasisLetterSpacingEnabled(); }

  static bool TextEmphasisPositionAutoEnabled() {
    return feature_states_[kTextEmphasisPositionAutoFlagIndex];
  }

  static bool TextEmphasisPositionAutoEnabled(const FeatureContext*) { return TextEmphasisPositionAutoEnabled(); }

  static bool TextEmphasisPunctuationExceptionsEnabled() {
    return feature_states_[kTextEmphasisPunctuationExceptionsFlagIndex];
  }

  static bool TextEmphasisPunctuationExceptionsEnabled(const FeatureContext*) { return TextEmphasisPunctuationExceptionsEnabled(); }

  static bool TextEmphasisWithRubyEnabled() {
    return feature_states_[kTextEmphasisWithRubyFlagIndex];
  }

  static bool TextEmphasisWithRubyEnabled(const FeatureContext*) { return TextEmphasisWithRubyEnabled(); }

  static bool TextFragmentAPIEnabled() {
    return feature_states_[kTextFragmentAPIFlagIndex];
  }

  static bool TextFragmentAPIEnabled(const FeatureContext*) { return TextFragmentAPIEnabled(); }

  static bool TextFragmentTapOpensContextMenuEnabled() {
    return feature_states_[kTextFragmentTapOpensContextMenuFlagIndex];
  }

  static bool TextFragmentTapOpensContextMenuEnabled(const FeatureContext*) { return TextFragmentTapOpensContextMenuEnabled(); }

  static bool TextIteratorExcludeAutofilledSelectFixEnabled() {
    return feature_states_[kTextIteratorExcludeAutofilledSelectFixFlagIndex];
  }

  static bool TextIteratorExcludeAutofilledSelectFixEnabled(const FeatureContext*) { return TextIteratorExcludeAutofilledSelectFixEnabled(); }

  static bool TextMetricsBaselinesEnabled() {
    return feature_states_[kTextMetricsBaselinesFlagIndex];
  }

  static bool TextMetricsBaselinesEnabled(const FeatureContext*) { return TextMetricsBaselinesEnabled(); }

  static bool TextOverflowClipWithSelectionEnabled() {
    return feature_states_[kTextOverflowClipWithSelectionFlagIndex];
  }

  static bool TextOverflowClipWithSelectionEnabled(const FeatureContext*) { return TextOverflowClipWithSelectionEnabled(); }

  static bool TextOverflowStringEnabled() {
    return feature_states_[kTextOverflowStringFlagIndex];
  }

  static bool TextOverflowStringEnabled(const FeatureContext*) { return TextOverflowStringEnabled(); }

  static bool TextScaleMetaTagEnabled() {
    return feature_states_[kTextScaleMetaTagFlagIndex];
  }

  static bool TextScaleMetaTagEnabled(const FeatureContext*) { return TextScaleMetaTagEnabled(); }

  static bool TextSpacingTrimFallbackEnabled() {
    return feature_states_[kTextSpacingTrimFallbackFlagIndex];
  }

  static bool TextSpacingTrimFallbackEnabled(const FeatureContext*) { return TextSpacingTrimFallbackEnabled(); }

  static bool TextSpacingTrimFallback2Enabled() {
    if (!TextSpacingTrimFallbackEnabled())
      return false;
    return feature_states_[kTextSpacingTrimFallback2FlagIndex];
  }

  static bool TextSpacingTrimFallback2Enabled(const FeatureContext*) { return TextSpacingTrimFallback2Enabled(); }

  static bool TextSpacingTrimFallbackChwsEnabled() {
    if (!TextSpacingTrimFallbackEnabled())
      return false;
    return feature_states_[kTextSpacingTrimFallbackChwsFlagIndex];
  }

  static bool TextSpacingTrimFallbackChwsEnabled(const FeatureContext*) { return TextSpacingTrimFallbackChwsEnabled(); }

  static bool TextStreamMethodEnabled() {
    return feature_states_[kTextStreamMethodFlagIndex];
  }

  static bool TextStreamMethodEnabled(const FeatureContext*) { return TextStreamMethodEnabled(); }

  static bool TimelineTriggerEnabled() {
    return feature_states_[kTimelineTriggerFlagIndex];
  }

  static bool TimelineTriggerEnabled(const FeatureContext*) { return TimelineTriggerEnabled(); }

  static bool TimerThrottlingForBackgroundTabsEnabled() {
    return feature_states_[kTimerThrottlingForBackgroundTabsFlagIndex];
  }

  static bool TimerThrottlingForBackgroundTabsEnabled(const FeatureContext*) { return TimerThrottlingForBackgroundTabsEnabled(); }

  static bool TimestampBasedCLSTrackingEnabled() {
    return feature_states_[kTimestampBasedCLSTrackingFlagIndex];
  }

  static bool TimestampBasedCLSTrackingEnabled(const FeatureContext*) { return TimestampBasedCLSTrackingEnabled(); }

  static bool TimeZoneChangeEventEnabled() {
    return feature_states_[kTimeZoneChangeEventFlagIndex];
  }

  static bool TimeZoneChangeEventEnabled(const FeatureContext*) { return TimeZoneChangeEventEnabled(); }

  static bool TopicsAPIEnabled() {
    return feature_states_[kTopicsAPIFlagIndex];
  }

  static bool TopicsAPIEnabled(const FeatureContext*) { return TopicsAPIEnabled(); }

  static bool TouchDragAndContextMenuEnabled() {
    return feature_states_[kTouchDragAndContextMenuFlagIndex];
  }

  static bool TouchDragAndContextMenuEnabled(const FeatureContext*) { return TouchDragAndContextMenuEnabled(); }

  static bool TouchDragAndDropEnabled() {
    return feature_states_[kTouchDragAndDropFlagIndex];
  }

  static bool TouchDragAndDropEnabled(const FeatureContext*) { return TouchDragAndDropEnabled(); }

  static bool TouchDragOnShortPressEnabled() {
    if (!TouchDragAndDropEnabled())
      return false;
    return feature_states_[kTouchDragOnShortPressFlagIndex];
  }

  static bool TouchDragOnShortPressEnabled(const FeatureContext*) { return TouchDragOnShortPressEnabled(); }

  static bool TouchTextEditingRedesignEnabled() {
    return feature_states_[kTouchTextEditingRedesignFlagIndex];
  }

  static bool TouchTextEditingRedesignEnabled(const FeatureContext*) { return TouchTextEditingRedesignEnabled(); }

  static bool TransferableRTCDataChannelEnabled() {
    return feature_states_[kTransferableRTCDataChannelFlagIndex];
  }

  static bool TransferableRTCDataChannelEnabled(const FeatureContext*) { return TransferableRTCDataChannelEnabled(); }

  static bool TranslateServiceEnabled() {
    return feature_states_[kTranslateServiceFlagIndex];
  }

  static bool TranslateServiceEnabled(const FeatureContext*) { return TranslateServiceEnabled(); }

  static bool TranslationAPIEnabled() {
    return feature_states_[kTranslationAPIFlagIndex];
  }

  static bool TranslationAPIEnabled(const FeatureContext*) { return TranslationAPIEnabled(); }

  static bool TranslationAPIForWorkersEnabled() {
    return feature_states_[kTranslationAPIForWorkersFlagIndex];
  }

  static bool TranslationAPIForWorkersEnabled(const FeatureContext*) { return TranslationAPIForWorkersEnabled(); }

  static bool TreatMhtmlInitialDocumentLoadsAsCrossDocumentEnabled() {
    return feature_states_[kTreatMhtmlInitialDocumentLoadsAsCrossDocumentFlagIndex];
  }

  static bool TreatMhtmlInitialDocumentLoadsAsCrossDocumentEnabled(const FeatureContext*) { return TreatMhtmlInitialDocumentLoadsAsCrossDocumentEnabled(); }

  static bool TreeRubyPlacementEnabled() {
    return feature_states_[kTreeRubyPlacementFlagIndex];
  }

  static bool TreeRubyPlacementEnabled(const FeatureContext*) { return TreeRubyPlacementEnabled(); }

  static bool TrustedTypesCreateParserOptionsEnabled() {
    if (!SanitizerAPIEnabled())
      return false;
    if (!SetHTMLCanRunScriptsEnabled())
      return false;
    return feature_states_[kTrustedTypesCreateParserOptionsFlagIndex];
  }

  static bool TrustedTypesCreateParserOptionsEnabled(const FeatureContext*) { return TrustedTypesCreateParserOptionsEnabled(); }

  static bool TrustedTypesFromLiteralEnabled() {
    return feature_states_[kTrustedTypesFromLiteralFlagIndex];
  }

  static bool TrustedTypesFromLiteralEnabled(const FeatureContext*) { return TrustedTypesFromLiteralEnabled(); }

  static bool TrustedTypesHTMLEnabled() {
    return feature_states_[kTrustedTypesHTMLFlagIndex];
  }

  static bool TrustedTypesHTMLEnabled(const FeatureContext*) { return TrustedTypesHTMLEnabled(); }

  static bool TrustedTypesUseCodeLikeEnabled() {
    return feature_states_[kTrustedTypesUseCodeLikeFlagIndex];
  }

  static bool TrustedTypesUseCodeLikeEnabled(const FeatureContext*) { return TrustedTypesUseCodeLikeEnabled(); }

  static bool TwoPhaseViewTransitionEnabled() {
    return feature_states_[kTwoPhaseViewTransitionFlagIndex];
  }

  static bool TwoPhaseViewTransitionEnabled(const FeatureContext*) { return TwoPhaseViewTransitionEnabled(); }

  static bool UnboundedElementEnabled() {
    if (UnboundedElementOnTheOpenWebEnabled())
      return true;
    return feature_states_[kUnboundedElementFlagIndex];
  }

  static bool UnboundedElementEnabled(const FeatureContext*) { return UnboundedElementEnabled(); }

  static bool UnboundedElementOnTheOpenWebEnabled() {
    return feature_states_[kUnboundedElementOnTheOpenWebFlagIndex];
  }

  static bool UnboundedElementOnTheOpenWebEnabled(const FeatureContext*) { return UnboundedElementOnTheOpenWebEnabled(); }

  static bool UnclosedFormControlIsInvalidEnabled() {
    return feature_states_[kUnclosedFormControlIsInvalidFlagIndex];
  }

  static bool UnclosedFormControlIsInvalidEnabled(const FeatureContext*) { return UnclosedFormControlIsInvalidEnabled(); }

  static bool UnexposedTaskIdsEnabled() {
    return feature_states_[kUnexposedTaskIdsFlagIndex];
  }

  static bool UnexposedTaskIdsEnabled(const FeatureContext*) { return UnexposedTaskIdsEnabled(); }

  static bool UnprefixedSpeechRecognitionEnabled() {
    return feature_states_[kUnprefixedSpeechRecognitionFlagIndex];
  }

  static bool UnprefixedSpeechRecognitionEnabled(const FeatureContext*) { return UnprefixedSpeechRecognitionEnabled(); }

  static bool UnrestrictedMeasureUserAgentSpecificMemoryEnabled() {
    return feature_states_[kUnrestrictedMeasureUserAgentSpecificMemoryFlagIndex];
  }

  static bool UnrestrictedMeasureUserAgentSpecificMemoryEnabled(const FeatureContext*) { return UnrestrictedMeasureUserAgentSpecificMemoryEnabled(); }

  static bool UnrestrictedUsbEnabled() {
    if (!WebUSBEnabled())
      return false;
    return feature_states_[kUnrestrictedUsbFlagIndex];
  }

  static bool UnrestrictedUsbEnabled(const FeatureContext*) { return UnrestrictedUsbEnabled(); }

  static bool UpdateComplexSafaAreaConstraintsEnabled() {
    return feature_states_[kUpdateComplexSafaAreaConstraintsFlagIndex];
  }

  static bool UpdateComplexSafaAreaConstraintsEnabled(const FeatureContext*) { return UpdateComplexSafaAreaConstraintsEnabled(); }

  static bool UpdateSelectionOnNodeInsertionEnabled() {
    return feature_states_[kUpdateSelectionOnNodeInsertionFlagIndex];
  }

  static bool UpdateSelectionOnNodeInsertionEnabled(const FeatureContext*) { return UpdateSelectionOnNodeInsertionEnabled(); }

  static bool URLPatternCompareComponentEnabled() {
    return feature_states_[kURLPatternCompareComponentFlagIndex];
  }

  static bool URLPatternCompareComponentEnabled(const FeatureContext*) { return URLPatternCompareComponentEnabled(); }

  static bool URLPatternGenerateEnabled() {
    return feature_states_[kURLPatternGenerateFlagIndex];
  }

  static bool URLPatternGenerateEnabled(const FeatureContext*) { return URLPatternGenerateEnabled(); }

  static bool URLSearchParamsHasAndDeleteMultipleArgsEnabled() {
    return feature_states_[kURLSearchParamsHasAndDeleteMultipleArgsFlagIndex];
  }

  static bool URLSearchParamsHasAndDeleteMultipleArgsEnabled(const FeatureContext*) { return URLSearchParamsHasAndDeleteMultipleArgsEnabled(); }

  static bool UseBeginFramePresentationFeedbackEnabled() {
    return feature_states_[kUseBeginFramePresentationFeedbackFlagIndex];
  }

  static bool UseBeginFramePresentationFeedbackEnabled(const FeatureContext*) { return UseBeginFramePresentationFeedbackEnabled(); }

  static bool UseLargestPaintedImageForLCPCandidateEnabled() {
    return feature_states_[kUseLargestPaintedImageForLCPCandidateFlagIndex];
  }

  static bool UseLargestPaintedImageForLCPCandidateEnabled(const FeatureContext*) { return UseLargestPaintedImageForLCPCandidateEnabled(); }

  static bool UseLowQualityInterpolationEnabled() {
    return feature_states_[kUseLowQualityInterpolationFlagIndex];
  }

  static bool UseLowQualityInterpolationEnabled(const FeatureContext*) { return UseLowQualityInterpolationEnabled(); }

  static bool UseOriginalDomOffsetsForOffsetMapEnabled() {
    return feature_states_[kUseOriginalDomOffsetsForOffsetMapFlagIndex];
  }

  static bool UseOriginalDomOffsetsForOffsetMapEnabled(const FeatureContext*) { return UseOriginalDomOffsetsForOffsetMapEnabled(); }

  static bool UsePaintGeometryForIntersectionEnabled() {
    return feature_states_[kUsePaintGeometryForIntersectionFlagIndex];
  }

  static bool UsePaintGeometryForIntersectionEnabled(const FeatureContext*) { return UsePaintGeometryForIntersectionEnabled(); }

  static bool UsePositionForPointInFlexibleBoxWithSingleChildElementEnabled() {
    return feature_states_[kUsePositionForPointInFlexibleBoxWithSingleChildElementFlagIndex];
  }

  static bool UsePositionForPointInFlexibleBoxWithSingleChildElementEnabled(const FeatureContext*) { return UsePositionForPointInFlexibleBoxWithSingleChildElementEnabled(); }

  static bool UsePositionIfIsVisuallyEquivalentCandidateEnabled() {
    return feature_states_[kUsePositionIfIsVisuallyEquivalentCandidateFlagIndex];
  }

  static bool UsePositionIfIsVisuallyEquivalentCandidateEnabled(const FeatureContext*) { return UsePositionIfIsVisuallyEquivalentCandidateEnabled(); }

  static bool UserActionPseudosStopAtTopLayerEnabled() {
    return feature_states_[kUserActionPseudosStopAtTopLayerFlagIndex];
  }

  static bool UserActionPseudosStopAtTopLayerEnabled(const FeatureContext*) { return UserActionPseudosStopAtTopLayerEnabled(); }

  static bool UserDefinedEntryPointTimingEnabled() {
    return feature_states_[kUserDefinedEntryPointTimingFlagIndex];
  }

  static bool UserDefinedEntryPointTimingEnabled(const FeatureContext*) { return UserDefinedEntryPointTimingEnabled(); }

  static bool UserMediaElementEnabled() {
    return feature_states_[kUserMediaElementFlagIndex];
  }

  static bool UserMediaElementEnabled(const FeatureContext*) { return UserMediaElementEnabled(); }

  static bool UseShadowHostStyleCheckEditableEnabled() {
    return feature_states_[kUseShadowHostStyleCheckEditableFlagIndex];
  }

  static bool UseShadowHostStyleCheckEditableEnabled(const FeatureContext*) { return UseShadowHostStyleCheckEditableEnabled(); }

  static bool UseUndoStepElementDispatchBeforeInputEnabled() {
    return feature_states_[kUseUndoStepElementDispatchBeforeInputFlagIndex];
  }

  static bool UseUndoStepElementDispatchBeforeInputEnabled(const FeatureContext*) { return UseUndoStepElementDispatchBeforeInputEnabled(); }

  static bool V8IdleTasksEnabled() {
    return feature_states_[kV8IdleTasksFlagIndex];
  }

  static bool V8IdleTasksEnabled(const FeatureContext*) { return V8IdleTasksEnabled(); }

  static bool VariableSystemFontSupportOnWindowsEnabled() {
    return feature_states_[kVariableSystemFontSupportOnWindowsFlagIndex];
  }

  static bool VariableSystemFontSupportOnWindowsEnabled(const FeatureContext*) { return VariableSystemFontSupportOnWindowsEnabled(); }

  static bool VideoAutoFullscreenEnabled() {
    return feature_states_[kVideoAutoFullscreenFlagIndex];
  }

  static bool VideoAutoFullscreenEnabled(const FeatureContext*) { return VideoAutoFullscreenEnabled(); }

  static bool VideoFrameMetadataBackgroundBlurEnabled() {
    return feature_states_[kVideoFrameMetadataBackgroundBlurFlagIndex];
  }

  static bool VideoFrameMetadataBackgroundBlurEnabled(const FeatureContext*) { return VideoFrameMetadataBackgroundBlurEnabled(); }

  static bool VideoFrameMetadataRtpTimestampEnabled() {
    return feature_states_[kVideoFrameMetadataRtpTimestampFlagIndex];
  }

  static bool VideoFrameMetadataRtpTimestampEnabled(const FeatureContext*) { return VideoFrameMetadataRtpTimestampEnabled(); }

  static bool VideoFullscreenOrientationLockEnabled() {
    return feature_states_[kVideoFullscreenOrientationLockFlagIndex];
  }

  static bool VideoFullscreenOrientationLockEnabled(const FeatureContext*) { return VideoFullscreenOrientationLockEnabled(); }

  static bool VideoRotateToFullscreenEnabled() {
    return feature_states_[kVideoRotateToFullscreenFlagIndex];
  }

  static bool VideoRotateToFullscreenEnabled(const FeatureContext*) { return VideoRotateToFullscreenEnabled(); }

  static bool VideoTrackGeneratorEnabled() {
    return feature_states_[kVideoTrackGeneratorFlagIndex];
  }

  static bool VideoTrackGeneratorEnabled(const FeatureContext*) { return VideoTrackGeneratorEnabled(); }

  static bool VideoTrackGeneratorInWindowEnabled() {
    return feature_states_[kVideoTrackGeneratorInWindowFlagIndex];
  }

  static bool VideoTrackGeneratorInWindowEnabled(const FeatureContext*) { return VideoTrackGeneratorInWindowEnabled(); }

  static bool VideoTrackGeneratorInWorkerEnabled() {
    return feature_states_[kVideoTrackGeneratorInWorkerFlagIndex];
  }

  static bool VideoTrackGeneratorInWorkerEnabled(const FeatureContext*) { return VideoTrackGeneratorInWorkerEnabled(); }

  static bool ViewportHeightClientHintHeaderEnabled() {
    return feature_states_[kViewportHeightClientHintHeaderFlagIndex];
  }

  static bool ViewportHeightClientHintHeaderEnabled(const FeatureContext*) { return ViewportHeightClientHintHeaderEnabled(); }

  static bool ViewportSegmentsEnabled() {
    return feature_states_[kViewportSegmentsFlagIndex];
  }

  static bool ViewportSegmentsEnabled(const FeatureContext*) { return ViewportSegmentsEnabled(); }

  static bool ViewTransitionDOMCallbackAfterCommitEnabled() {
    return feature_states_[kViewTransitionDOMCallbackAfterCommitFlagIndex];
  }

  static bool ViewTransitionDOMCallbackAfterCommitEnabled(const FeatureContext*) { return ViewTransitionDOMCallbackAfterCommitEnabled(); }

  static bool ViewTransitionLongCallbackTimeoutForTestingEnabled() {
    return feature_states_[kViewTransitionLongCallbackTimeoutForTestingFlagIndex];
  }

  static bool ViewTransitionLongCallbackTimeoutForTestingEnabled(const FeatureContext*) { return ViewTransitionLongCallbackTimeoutForTestingEnabled(); }

  static bool VisibilityCollapseColumnEnabled() {
    return feature_states_[kVisibilityCollapseColumnFlagIndex];
  }

  static bool VisibilityCollapseColumnEnabled(const FeatureContext*) { return VisibilityCollapseColumnEnabled(); }

  static bool VisualRectMappingFixForExpansionEnabled() {
    return feature_states_[kVisualRectMappingFixForExpansionFlagIndex];
  }

  static bool VisualRectMappingFixForExpansionEnabled(const FeatureContext*) { return VisualRectMappingFixForExpansionEnabled(); }

  static bool WakeLockEnabled() {
    if (SystemWakeLockEnabled())
      return true;
    return feature_states_[kWakeLockFlagIndex];
  }

  static bool WakeLockEnabled(const FeatureContext*) { return WakeLockEnabled(); }

  static bool WarnOnContentVisibilityRenderAccessEnabled() {
    return feature_states_[kWarnOnContentVisibilityRenderAccessFlagIndex];
  }

  static bool WarnOnContentVisibilityRenderAccessEnabled(const FeatureContext*) { return WarnOnContentVisibilityRenderAccessEnabled(); }

  static bool WebAppLaunchQueueEnabled() {
    return feature_states_[kWebAppLaunchQueueFlagIndex];
  }

  static bool WebAppLaunchQueueEnabled(const FeatureContext*) { return WebAppLaunchQueueEnabled(); }

  static bool WebAppScopeSystemAccentColorEnabled() {
    return feature_states_[kWebAppScopeSystemAccentColorFlagIndex];
  }

  static bool WebAppScopeSystemAccentColorEnabled(const FeatureContext*) { return WebAppScopeSystemAccentColorEnabled(); }

  static bool WebAppTabStripEnabled() {
    return feature_states_[kWebAppTabStripFlagIndex];
  }

  static bool WebAppTabStripEnabled(const FeatureContext*) { return WebAppTabStripEnabled(); }

  static bool WebAppTabStripCustomizationsEnabled() {
    return feature_states_[kWebAppTabStripCustomizationsFlagIndex];
  }

  static bool WebAppTabStripCustomizationsEnabled(const FeatureContext*) { return WebAppTabStripCustomizationsEnabled(); }

  static bool WebAppTranslationsEnabled() {
    return feature_states_[kWebAppTranslationsFlagIndex];
  }

  static bool WebAppTranslationsEnabled(const FeatureContext*) { return WebAppTranslationsEnabled(); }

  static bool WebAudioBypassOutputBufferingEnabled() {
    return feature_states_[kWebAudioBypassOutputBufferingFlagIndex];
  }

  static bool WebAudioBypassOutputBufferingEnabled(const FeatureContext*) { return WebAudioBypassOutputBufferingEnabled(); }

  static bool WebAudioBypassOutputBufferingOptOutEnabled() {
    return feature_states_[kWebAudioBypassOutputBufferingOptOutFlagIndex];
  }

  static bool WebAudioBypassOutputBufferingOptOutEnabled(const FeatureContext*) { return WebAudioBypassOutputBufferingOptOutEnabled(); }

  static bool WebAuthEnabled() {
    return feature_states_[kWebAuthFlagIndex];
  }

  static bool WebAuthEnabled(const FeatureContext*) { return WebAuthEnabled(); }

  static bool WebAuthAuthenticatorAttachmentEnabled() {
    return feature_states_[kWebAuthAuthenticatorAttachmentFlagIndex];
  }

  static bool WebAuthAuthenticatorAttachmentEnabled(const FeatureContext*) { return WebAuthAuthenticatorAttachmentEnabled(); }

  static bool WebAuthenticationAmbientEnabled() {
    return feature_states_[kWebAuthenticationAmbientFlagIndex];
  }

  static bool WebAuthenticationAmbientEnabled(const FeatureContext*) { return WebAuthenticationAmbientEnabled(); }

  static bool WebAuthenticationCmtgKeyEnabled() {
    return feature_states_[kWebAuthenticationCmtgKeyFlagIndex];
  }

  static bool WebAuthenticationCmtgKeyEnabled(const FeatureContext*) { return WebAuthenticationCmtgKeyEnabled(); }

  static bool WebAuthenticationCrossDeviceFallbackUrlEnabled() {
    return feature_states_[kWebAuthenticationCrossDeviceFallbackUrlFlagIndex];
  }

  static bool WebAuthenticationCrossDeviceFallbackUrlEnabled(const FeatureContext*) { return WebAuthenticationCrossDeviceFallbackUrlEnabled(); }

  static bool WebAuthenticationRemoteDesktopSupportEnabled() {
    return feature_states_[kWebAuthenticationRemoteDesktopSupportFlagIndex];
  }

  static bool WebAuthenticationRemoteDesktopSupportEnabled(const FeatureContext*) { return WebAuthenticationRemoteDesktopSupportEnabled(); }

  static bool WebAutocorrectByDefaultEnabled() {
    return feature_states_[kWebAutocorrectByDefaultFlagIndex];
  }

  static bool WebAutocorrectByDefaultEnabled(const FeatureContext*) { return WebAutocorrectByDefaultEnabled(); }

  static bool WebBluetoothEnabled() {
    return feature_states_[kWebBluetoothFlagIndex];
  }

  static bool WebBluetoothEnabled(const FeatureContext*) { return WebBluetoothEnabled(); }

  static bool WebBluetoothGetDevicesEnabled() {
    return feature_states_[kWebBluetoothGetDevicesFlagIndex];
  }

  static bool WebBluetoothGetDevicesEnabled(const FeatureContext*) { return WebBluetoothGetDevicesEnabled(); }

  static bool WebBluetoothScanningEnabled() {
    return feature_states_[kWebBluetoothScanningFlagIndex];
  }

  static bool WebBluetoothScanningEnabled(const FeatureContext*) { return WebBluetoothScanningEnabled(); }

  static bool WebBluetoothWatchAdvertisementsEnabled() {
    return feature_states_[kWebBluetoothWatchAdvertisementsFlagIndex];
  }

  static bool WebBluetoothWatchAdvertisementsEnabled(const FeatureContext*) { return WebBluetoothWatchAdvertisementsEnabled(); }

  static bool WebBluetoothWorldIsolatedCacheEnabled() {
    return feature_states_[kWebBluetoothWorldIsolatedCacheFlagIndex];
  }

  static bool WebBluetoothWorldIsolatedCacheEnabled(const FeatureContext*) { return WebBluetoothWorldIsolatedCacheEnabled(); }

  static bool WebCodecsVideoEncoderBuffersEnabled() {
    return feature_states_[kWebCodecsVideoEncoderBuffersFlagIndex];
  }

  static bool WebCodecsVideoEncoderBuffersEnabled(const FeatureContext*) { return WebCodecsVideoEncoderBuffersEnabled(); }

  static bool WebGLDeveloperExtensionsEnabled() {
    return feature_states_[kWebGLDeveloperExtensionsFlagIndex];
  }

  static bool WebGLDeveloperExtensionsEnabled(const FeatureContext*) { return WebGLDeveloperExtensionsEnabled(); }

  static bool WebGLDraftExtensionsEnabled() {
    return feature_states_[kWebGLDraftExtensionsFlagIndex];
  }

  static bool WebGLDraftExtensionsEnabled(const FeatureContext*) { return WebGLDraftExtensionsEnabled(); }

  static bool WebGLDrawingBufferStorageEnabled() {
    return feature_states_[kWebGLDrawingBufferStorageFlagIndex];
  }

  static bool WebGLDrawingBufferStorageEnabled(const FeatureContext*) { return WebGLDrawingBufferStorageEnabled(); }

  static bool WebGLOnWebGPUEnabled() {
    return feature_states_[kWebGLOnWebGPUFlagIndex];
  }

  static bool WebGLOnWebGPUEnabled(const FeatureContext*) { return WebGLOnWebGPUEnabled(); }

  static bool WebGLToneMappingEnabled() {
    return feature_states_[kWebGLToneMappingFlagIndex];
  }

  static bool WebGLToneMappingEnabled(const FeatureContext*) { return WebGLToneMappingEnabled(); }

  static bool WebGPUDeveloperFeaturesEnabled() {
    return feature_states_[kWebGPUDeveloperFeaturesFlagIndex];
  }

  static bool WebGPUDeveloperFeaturesEnabled(const FeatureContext*) { return WebGPUDeveloperFeaturesEnabled(); }

  static bool WebGPUExperimentalFeaturesEnabled() {
    return feature_states_[kWebGPUExperimentalFeaturesFlagIndex];
  }

  static bool WebGPUExperimentalFeaturesEnabled(const FeatureContext*) { return WebGPUExperimentalFeaturesEnabled(); }

  static bool WebGPUExperimentalResourceTableEnabled() {
    if (WebGPUExperimentalFeaturesEnabled())
      return true;
    return feature_states_[kWebGPUExperimentalResourceTableFlagIndex];
  }

  static bool WebGPUExperimentalResourceTableEnabled(const FeatureContext*) { return WebGPUExperimentalResourceTableEnabled(); }

  static bool WebGPUExternalImageHDRHeadroomEnabled() {
    return feature_states_[kWebGPUExternalImageHDRHeadroomFlagIndex];
  }

  static bool WebGPUExternalImageHDRHeadroomEnabled(const FeatureContext*) { return WebGPUExternalImageHDRHeadroomEnabled(); }

  static bool WebGPUMapSyncOnWorkersEnabled() {
    return feature_states_[kWebGPUMapSyncOnWorkersFlagIndex];
  }

  static bool WebGPUMapSyncOnWorkersEnabled(const FeatureContext*) { return WebGPUMapSyncOnWorkersEnabled(); }

  static bool WebGPUMultithreadDawnWireOnWorkersEnabled() {
    if (WebGPUMapSyncOnWorkersEnabled())
      return true;
    return feature_states_[kWebGPUMultithreadDawnWireOnWorkersFlagIndex];
  }

  static bool WebGPUMultithreadDawnWireOnWorkersEnabled(const FeatureContext*) { return WebGPUMultithreadDawnWireOnWorkersEnabled(); }

  static bool WebHapticsEnabled() {
    return feature_states_[kWebHapticsFlagIndex];
  }

  static bool WebHapticsEnabled(const FeatureContext*) { return WebHapticsEnabled(); }

  static bool WebHIDEnabled() {
    return feature_states_[kWebHIDFlagIndex];
  }

  static bool WebHIDEnabled(const FeatureContext*) { return WebHIDEnabled(); }

  static bool WebHIDOnServiceWorkersEnabled() {
    if (!WebHIDEnabled())
      return false;
    return feature_states_[kWebHIDOnServiceWorkersFlagIndex];
  }

  static bool WebHIDOnServiceWorkersEnabled(const FeatureContext*) { return WebHIDOnServiceWorkersEnabled(); }

  static bool WebHIDWorldIsolatedCacheEnabled() {
    return feature_states_[kWebHIDWorldIsolatedCacheFlagIndex];
  }

  static bool WebHIDWorldIsolatedCacheEnabled(const FeatureContext*) { return WebHIDWorldIsolatedCacheEnabled(); }

  static bool WebIdentityDigitalCredentialsEnabled() {
    return feature_states_[kWebIdentityDigitalCredentialsFlagIndex];
  }

  static bool WebIdentityDigitalCredentialsEnabled(const FeatureContext*) { return WebIdentityDigitalCredentialsEnabled(); }

  static bool WebIDLBigIntUsesToBigIntEnabled() {
    return feature_states_[kWebIDLBigIntUsesToBigIntFlagIndex];
  }

  static bool WebIDLBigIntUsesToBigIntEnabled(const FeatureContext*) { return WebIDLBigIntUsesToBigIntEnabled(); }

  static bool WebMCPDeclarativeFileInputEnabled() {
    return feature_states_[kWebMCPDeclarativeFileInputFlagIndex];
  }

  static bool WebMCPDeclarativeFileInputEnabled(const FeatureContext*) { return WebMCPDeclarativeFileInputEnabled(); }

  static bool WebMCPFormAssociatedCustomElementsEnabled() {
    return feature_states_[kWebMCPFormAssociatedCustomElementsFlagIndex];
  }

  static bool WebMCPFormAssociatedCustomElementsEnabled(const FeatureContext*) { return WebMCPFormAssociatedCustomElementsEnabled(); }

  static bool WebMCPTestingEnabled() {
    return feature_states_[kWebMCPTestingFlagIndex];
  }

  static bool WebMCPTestingEnabled(const FeatureContext*) { return WebMCPTestingEnabled(); }

  static bool WebNFCEnabled() {
    return feature_states_[kWebNFCFlagIndex];
  }

  static bool WebNFCEnabled(const FeatureContext*) { return WebNFCEnabled(); }

  static bool WebOTPEnabled() {
    return feature_states_[kWebOTPFlagIndex];
  }

  static bool WebOTPEnabled(const FeatureContext*) { return WebOTPEnabled(); }

  static bool WebOTPAssertionFeaturePolicyEnabled() {
    if (!WebOTPEnabled())
      return false;
    return feature_states_[kWebOTPAssertionFeaturePolicyFlagIndex];
  }

  static bool WebOTPAssertionFeaturePolicyEnabled(const FeatureContext*) { return WebOTPAssertionFeaturePolicyEnabled(); }

  static bool WebPreferencesEnabled() {
    return feature_states_[kWebPreferencesFlagIndex];
  }

  static bool WebPreferencesEnabled(const FeatureContext*) { return WebPreferencesEnabled(); }

  static bool WebPrintingEnabled() {
    return feature_states_[kWebPrintingFlagIndex];
  }

  static bool WebPrintingEnabled(const FeatureContext*) { return WebPrintingEnabled(); }

  static bool WebSerialWorldIsolatedCacheEnabled() {
    return feature_states_[kWebSerialWorldIsolatedCacheFlagIndex];
  }

  static bool WebSerialWorldIsolatedCacheEnabled(const FeatureContext*) { return WebSerialWorldIsolatedCacheEnabled(); }

  static bool WebShareEnabled() {
    return feature_states_[kWebShareFlagIndex];
  }

  static bool WebShareEnabled(const FeatureContext*) { return WebShareEnabled(); }

  static bool WebSocketOptionBagEnabled() {
    return feature_states_[kWebSocketOptionBagFlagIndex];
  }

  static bool WebSocketOptionBagEnabled(const FeatureContext*) { return WebSocketOptionBagEnabled(); }

  static bool WebSocketStreamEnabled() {
    return feature_states_[kWebSocketStreamFlagIndex];
  }

  static bool WebSocketStreamEnabled(const FeatureContext*) { return WebSocketStreamEnabled(); }

  static bool WebSocketStreamStandardBinaryChunkTypeEnabled() {
    return feature_states_[kWebSocketStreamStandardBinaryChunkTypeFlagIndex];
  }

  static bool WebSocketStreamStandardBinaryChunkTypeEnabled(const FeatureContext*) { return WebSocketStreamStandardBinaryChunkTypeEnabled(); }

  static bool WebSpeechRecognitionContextEnabled() {
    return feature_states_[kWebSpeechRecognitionContextFlagIndex];
  }

  static bool WebSpeechRecognitionContextEnabled(const FeatureContext*) { return WebSpeechRecognitionContextEnabled(); }

  static bool WebSpeechTimestampsEnabled() {
    return feature_states_[kWebSpeechTimestampsFlagIndex];
  }

  static bool WebSpeechTimestampsEnabled(const FeatureContext*) { return WebSpeechTimestampsEnabled(); }

  static bool WebSpeechUnspokenPunctuationEnabled() {
    return feature_states_[kWebSpeechUnspokenPunctuationFlagIndex];
  }

  static bool WebSpeechUnspokenPunctuationEnabled(const FeatureContext*) { return WebSpeechUnspokenPunctuationEnabled(); }

  static bool WebTransportAnticipatedConcurrentIncomingStreamsEnabled() {
    return feature_states_[kWebTransportAnticipatedConcurrentIncomingStreamsFlagIndex];
  }

  static bool WebTransportAnticipatedConcurrentIncomingStreamsEnabled(const FeatureContext*) { return WebTransportAnticipatedConcurrentIncomingStreamsEnabled(); }

  static bool WebTransportApplicationProtocolEnabled() {
    return feature_states_[kWebTransportApplicationProtocolFlagIndex];
  }

  static bool WebTransportApplicationProtocolEnabled(const FeatureContext*) { return WebTransportApplicationProtocolEnabled(); }

  static bool WebTransportCongestionControlEnabled() {
    return feature_states_[kWebTransportCongestionControlFlagIndex];
  }

  static bool WebTransportCongestionControlEnabled(const FeatureContext*) { return WebTransportCongestionControlEnabled(); }

  static bool WebTransportCreateStreamsBeforeReadyEnabled() {
    return feature_states_[kWebTransportCreateStreamsBeforeReadyFlagIndex];
  }

  static bool WebTransportCreateStreamsBeforeReadyEnabled(const FeatureContext*) { return WebTransportCreateStreamsBeforeReadyEnabled(); }

  static bool WebTransportDatagramsReadableTypeEnabled() {
    return feature_states_[kWebTransportDatagramsReadableTypeFlagIndex];
  }

  static bool WebTransportDatagramsReadableTypeEnabled(const FeatureContext*) { return WebTransportDatagramsReadableTypeEnabled(); }

  static bool WebTransportDatagramsWritableEnabled() {
    if (!WebTransportSendGroupEnabled())
      return false;
    return feature_states_[kWebTransportDatagramsWritableFlagIndex];
  }

  static bool WebTransportDatagramsWritableEnabled(const FeatureContext*) { return WebTransportDatagramsWritableEnabled(); }

  static bool WebTransportDrainingEnabled() {
    return feature_states_[kWebTransportDrainingFlagIndex];
  }

  static bool WebTransportDrainingEnabled(const FeatureContext*) { return WebTransportDrainingEnabled(); }

  static bool WebTransportHeadersEnabled() {
    return feature_states_[kWebTransportHeadersFlagIndex];
  }

  static bool WebTransportHeadersEnabled(const FeatureContext*) { return WebTransportHeadersEnabled(); }

  static bool WebTransportReceiveStreamEnabled() {
    return feature_states_[kWebTransportReceiveStreamFlagIndex];
  }

  static bool WebTransportReceiveStreamEnabled(const FeatureContext*) { return WebTransportReceiveStreamEnabled(); }

  static bool WebTransportReliabilityEnabled() {
    return feature_states_[kWebTransportReliabilityFlagIndex];
  }

  static bool WebTransportReliabilityEnabled(const FeatureContext*) { return WebTransportReliabilityEnabled(); }

  static bool WebTransportSendGroupEnabled() {
    return feature_states_[kWebTransportSendGroupFlagIndex];
  }

  static bool WebTransportSendGroupEnabled(const FeatureContext*) { return WebTransportSendGroupEnabled(); }

  static bool WebTransportStatsEnabled() {
    return feature_states_[kWebTransportStatsFlagIndex];
  }

  static bool WebTransportStatsEnabled(const FeatureContext*) { return WebTransportStatsEnabled(); }

  static bool WebUIBundledCodeCacheAsyncFetchEnabled() {
    return feature_states_[kWebUIBundledCodeCacheAsyncFetchFlagIndex];
  }

  static bool WebUIBundledCodeCacheAsyncFetchEnabled(const FeatureContext*) { return WebUIBundledCodeCacheAsyncFetchEnabled(); }

  static bool WebUSBEnabled() {
    return feature_states_[kWebUSBFlagIndex];
  }

  static bool WebUSBEnabled(const FeatureContext*) { return WebUSBEnabled(); }

  static bool WebUSBOnDedicatedWorkersEnabled() {
    if (!WebUSBEnabled())
      return false;
    return feature_states_[kWebUSBOnDedicatedWorkersFlagIndex];
  }

  static bool WebUSBOnDedicatedWorkersEnabled(const FeatureContext*) { return WebUSBOnDedicatedWorkersEnabled(); }

  static bool WebUSBOnServiceWorkersEnabled() {
    if (!WebUSBEnabled())
      return false;
    return feature_states_[kWebUSBOnServiceWorkersFlagIndex];
  }

  static bool WebUSBOnServiceWorkersEnabled(const FeatureContext*) { return WebUSBOnServiceWorkersEnabled(); }

  static bool WebViewEnvReorderFixEnabled() {
    return feature_states_[kWebViewEnvReorderFixFlagIndex];
  }

  static bool WebViewEnvReorderFixEnabled(const FeatureContext*) { return WebViewEnvReorderFixEnabled(); }

  static bool WebVTTCueLayoutByPositionAlignmentEnabled() {
    return feature_states_[kWebVTTCueLayoutByPositionAlignmentFlagIndex];
  }

  static bool WebVTTCueLayoutByPositionAlignmentEnabled(const FeatureContext*) { return WebVTTCueLayoutByPositionAlignmentEnabled(); }

  static bool WebVTTCueTightLineBoxEnabled() {
    return feature_states_[kWebVTTCueTightLineBoxFlagIndex];
  }

  static bool WebVTTCueTightLineBoxEnabled(const FeatureContext*) { return WebVTTCueTightLineBoxEnabled(); }

  static bool WebVTTLineAndPositionAlignmentEnabled() {
    return feature_states_[kWebVTTLineAndPositionAlignmentFlagIndex];
  }

  static bool WebVTTLineAndPositionAlignmentEnabled(const FeatureContext*) { return WebVTTLineAndPositionAlignmentEnabled(); }

  static bool WebVTTRegionsEnabled() {
    return feature_states_[kWebVTTRegionsFlagIndex];
  }

  static bool WebVTTRegionsEnabled(const FeatureContext*) { return WebVTTRegionsEnabled(); }

  static bool WebXREnabled() {
    return feature_states_[kWebXRFlagIndex];
  }

  static bool WebXREnabled(const FeatureContext*) { return WebXREnabled(); }

  static bool WebXREnabledFeaturesEnabled() {
    if (!WebXREnabled())
      return false;
    return feature_states_[kWebXREnabledFeaturesFlagIndex];
  }

  static bool WebXREnabledFeaturesEnabled(const FeatureContext*) { return WebXREnabledFeaturesEnabled(); }

  static bool WebXRFrameRateEnabled() {
    if (!WebXREnabled())
      return false;
    return feature_states_[kWebXRFrameRateFlagIndex];
  }

  static bool WebXRFrameRateEnabled(const FeatureContext*) { return WebXRFrameRateEnabled(); }

  static bool WebXRFrontFacingEnabled() {
    if (!WebXREnabled())
      return false;
    return feature_states_[kWebXRFrontFacingFlagIndex];
  }

  static bool WebXRFrontFacingEnabled(const FeatureContext*) { return WebXRFrontFacingEnabled(); }

  static bool WebXRGPUBindingEnabled() {
    if (!WebXREnabled())
      return false;
    return feature_states_[kWebXRGPUBindingFlagIndex];
  }

  static bool WebXRGPUBindingEnabled(const FeatureContext*) { return WebXRGPUBindingEnabled(); }

  static bool WebXRHitTestEntityTypesEnabled() {
    if (!WebXREnabled())
      return false;
    return feature_states_[kWebXRHitTestEntityTypesFlagIndex];
  }

  static bool WebXRHitTestEntityTypesEnabled(const FeatureContext*) { return WebXRHitTestEntityTypesEnabled(); }

  static bool WebXRLayersEnabled() {
    if (!WebXREnabled())
      return false;
    return feature_states_[kWebXRLayersFlagIndex];
  }

  static bool WebXRLayersEnabled(const FeatureContext*) { return WebXRLayersEnabled(); }

  static bool WebXRLayersCommonEnabled() {
    if (WebXRLayersEnabled())
      return true;
    if (WebXRGPUBindingEnabled())
      return true;
    return feature_states_[kWebXRLayersCommonFlagIndex];
  }

  static bool WebXRLayersCommonEnabled(const FeatureContext*) { return WebXRLayersCommonEnabled(); }

  static bool WebXRMediaBindingEnabled() {
    if (!WebXRLayersEnabled())
      return false;
    return feature_states_[kWebXRMediaBindingFlagIndex];
  }

  static bool WebXRMediaBindingEnabled(const FeatureContext*) { return WebXRMediaBindingEnabled(); }

  static bool WebXRMeshDetectionEnabled() {
    if (!WebXREnabled())
      return false;
    return feature_states_[kWebXRMeshDetectionFlagIndex];
  }

  static bool WebXRMeshDetectionEnabled(const FeatureContext*) { return WebXRMeshDetectionEnabled(); }

  static bool WebXRPoseMotionDataEnabled() {
    if (!WebXREnabled())
      return false;
    return feature_states_[kWebXRPoseMotionDataFlagIndex];
  }

  static bool WebXRPoseMotionDataEnabled(const FeatureContext*) { return WebXRPoseMotionDataEnabled(); }

  static bool WebXRSpecParityEnabled() {
    if (!WebXREnabled())
      return false;
    return feature_states_[kWebXRSpecParityFlagIndex];
  }

  static bool WebXRSpecParityEnabled(const FeatureContext*) { return WebXRSpecParityEnabled(); }

  static bool WebXRVisibilityMaskEnabled() {
    if (!WebXREnabled())
      return false;
    return feature_states_[kWebXRVisibilityMaskFlagIndex];
  }

  static bool WebXRVisibilityMaskEnabled(const FeatureContext*) { return WebXRVisibilityMaskEnabled(); }

  static bool WheelEventMomentumEnabled() {
    return feature_states_[kWheelEventMomentumFlagIndex];
  }

  static bool WheelEventMomentumEnabled(const FeatureContext*) { return WheelEventMomentumEnabled(); }

  static bool WindowDefaultStatusEnabled() {
    return feature_states_[kWindowDefaultStatusFlagIndex];
  }

  static bool WindowDefaultStatusEnabled(const FeatureContext*) { return WindowDefaultStatusEnabled(); }

  static bool WindowOpenAlwaysOnTopEnabled() {
    return feature_states_[kWindowOpenAlwaysOnTopFlagIndex];
  }

  static bool WindowOpenAlwaysOnTopEnabled(const FeatureContext*) { return WindowOpenAlwaysOnTopEnabled(); }

  static bool WordSkipSpacesPunctuationFixEnabled() {
    return feature_states_[kWordSkipSpacesPunctuationFixFlagIndex];
  }

  static bool WordSkipSpacesPunctuationFixEnabled(const FeatureContext*) { return WordSkipSpacesPunctuationFixEnabled(); }

  static bool XMLNoExternalEntitiesEnabled() {
    return feature_states_[kXMLNoExternalEntitiesFlagIndex];
  }

  static bool XMLNoExternalEntitiesEnabled(const FeatureContext*) { return XMLNoExternalEntitiesEnabled(); }

  static bool XMLParserReplaceLoneSurrogatesEnabled() {
    return feature_states_[kXMLParserReplaceLoneSurrogatesFlagIndex];
  }

  static bool XMLParserReplaceLoneSurrogatesEnabled(const FeatureContext*) { return XMLParserReplaceLoneSurrogatesEnabled(); }

  static bool XMLParsingRustEnabled() {
    return feature_states_[kXMLParsingRustFlagIndex];
  }

  static bool XMLParsingRustEnabled(const FeatureContext*) { return XMLParsingRustEnabled(); }

  static bool XMLRustForNonXsltEnabled() {
    return feature_states_[kXMLRustForNonXsltFlagIndex];
  }

  static bool XMLRustForNonXsltEnabled(const FeatureContext*) { return XMLRustForNonXsltEnabled(); }

  static bool XMLSerializerConsistentDefaultNsDeclMatchingEnabled() {
    return feature_states_[kXMLSerializerConsistentDefaultNsDeclMatchingFlagIndex];
  }

  static bool XMLSerializerConsistentDefaultNsDeclMatchingEnabled(const FeatureContext*) { return XMLSerializerConsistentDefaultNsDeclMatchingEnabled(); }

  static bool XMLViewerForIframesEnabled() {
    return feature_states_[kXMLViewerForIframesFlagIndex];
  }

  static bool XMLViewerForIframesEnabled(const FeatureContext*) { return XMLViewerForIframesEnabled(); }

  static bool XSLTSpecialTrialEnabled() {
    return feature_states_[kXSLTSpecialTrialFlagIndex];
  }

  static bool XSLTSpecialTrialEnabled(const FeatureContext*) { return XSLTSpecialTrialEnabled(); }


  // Origin-trial-enabled features:
  //
  // These features are currently part of an origin trial (see
  // https://www.chromium.org/blink/origin-trials). <feature>EnabledByRuntimeFlag()
  // can be used to test whether the feature is unconditionally enabled
  // (for example, by starting the browser with the appropriate command-line flag).
  // However, that is almost always the incorrect check. Most renderer code should
  // be calling <feature>Enabled(const FeatureContext*) instead, to test if the
  // feature is enabled in a given context.

  static bool AdInterestGroupAPIEnabledByRuntimeFlag() { return AdInterestGroupAPIEnabled(nullptr); }
  static bool AdInterestGroupAPIEnabled(const FeatureContext*);

  static bool AIPromptAPIParamsEnabledByRuntimeFlag() { return AIPromptAPIParamsEnabled(nullptr); }
  static bool AIPromptAPIParamsEnabled(const FeatureContext*);

  static bool AIProofreadingAPIEnabledByRuntimeFlag() { return AIProofreadingAPIEnabled(nullptr); }
  static bool AIProofreadingAPIEnabled(const FeatureContext*);

  static bool AIRewriterAPIEnabledByRuntimeFlag() { return AIRewriterAPIEnabled(nullptr); }
  static bool AIRewriterAPIEnabled(const FeatureContext*);

  static bool AIWriterAPIEnabledByRuntimeFlag() { return AIWriterAPIEnabled(nullptr); }
  static bool AIWriterAPIEnabled(const FeatureContext*);

  static bool AppTitleEnabledByRuntimeFlag() { return AppTitleEnabled(nullptr); }
  static bool AppTitleEnabled(const FeatureContext*);

  static bool AutofillEventEnabledByRuntimeFlag() { return AutofillEventEnabled(nullptr); }
  static bool AutofillEventEnabled(const FeatureContext*);

  static bool BackForwardCacheExperimentHTTPHeaderEnabledByRuntimeFlag() { return BackForwardCacheExperimentHTTPHeaderEnabled(nullptr); }
  static bool BackForwardCacheExperimentHTTPHeaderEnabled(const FeatureContext*);

  static bool BackForwardCacheNotRestoredReasonsEnabledByRuntimeFlag() { return BackForwardCacheNotRestoredReasonsEnabled(nullptr); }
  static bool BackForwardCacheNotRestoredReasonsEnabled(const FeatureContext*);

  static bool BackgroundPageFreezeOptOutEnabledByRuntimeFlag() { return BackgroundPageFreezeOptOutEnabled(nullptr); }
  static bool BackgroundPageFreezeOptOutEnabled(const FeatureContext*);

  static bool BlockingFocusWithoutUserActivationEnabledByRuntimeFlag() { return BlockingFocusWithoutUserActivationEnabled(nullptr); }
  static bool BlockingFocusWithoutUserActivationEnabled(const FeatureContext*);

  static bool CacheStorageCodeCacheHintEnabledByRuntimeFlag() { return CacheStorageCodeCacheHintEnabled(nullptr); }
  static bool CacheStorageCodeCacheHintEnabled(const FeatureContext*);

  static bool Canvas2dMeshEnabledByRuntimeFlag() { return Canvas2dMeshEnabled(nullptr); }
  static bool Canvas2dMeshEnabled(const FeatureContext*);

  static bool CanvasDrawElementEnabledByRuntimeFlag() { return CanvasDrawElementEnabled(nullptr); }
  static bool CanvasDrawElementEnabled(const FeatureContext*);

  static bool ConnectionAllowlistEmbeddedEnforcementEnabledByRuntimeFlag() { return ConnectionAllowlistEmbeddedEnforcementEnabled(nullptr); }
  static bool ConnectionAllowlistEmbeddedEnforcementEnabled(const FeatureContext*);

  static bool ContainerTimingEnabledByRuntimeFlag() { return ContainerTimingEnabled(nullptr); }
  static bool ContainerTimingEnabled(const FeatureContext*);

  static bool CoopRestrictPropertiesEnabledByRuntimeFlag() { return CoopRestrictPropertiesEnabled(nullptr); }
  static bool CoopRestrictPropertiesEnabled(const FeatureContext*);

  static bool CpuPerformanceEnabledByRuntimeFlag() { return CpuPerformanceEnabled(nullptr); }
  static bool CpuPerformanceEnabled(const FeatureContext*);

  static bool CrashReportingStorageAPIEnabledByRuntimeFlag() { return CrashReportingStorageAPIEnabled(nullptr); }
  static bool CrashReportingStorageAPIEnabled(const FeatureContext*);

  static bool CSPHashesV1EnabledByRuntimeFlag() { return CSPHashesV1Enabled(nullptr); }
  static bool CSPHashesV1Enabled(const FeatureContext*);

  static bool DeclarativeCSSModulesEnabledByRuntimeFlag() { return DeclarativeCSSModulesEnabled(nullptr); }
  static bool DeclarativeCSSModulesEnabled(const FeatureContext*);

  static bool DeclarativePerformanceObserverEnabledByRuntimeFlag() { return DeclarativePerformanceObserverEnabled(nullptr); }
  static bool DeclarativePerformanceObserverEnabled(const FeatureContext*);

  static bool DeprecateUnloadOptOutEnabledByRuntimeFlag() { return DeprecateUnloadOptOutEnabled(nullptr); }
  static bool DeprecateUnloadOptOutEnabled(const FeatureContext*);

  static bool DigitalGoodsEnabledByRuntimeFlag() { return DigitalGoodsEnabled(nullptr); }
  static bool DigitalGoodsEnabled(const FeatureContext*);

  static bool DisableDifferentOriginSubframeDialogSuppressionEnabledByRuntimeFlag() { return DisableDifferentOriginSubframeDialogSuppressionEnabled(nullptr); }
  static bool DisableDifferentOriginSubframeDialogSuppressionEnabled(const FeatureContext*);

  static bool DocumentIsolationPolicyEnabledByRuntimeFlag() { return DocumentIsolationPolicyEnabled(nullptr); }
  static bool DocumentIsolationPolicyEnabled(const FeatureContext*);

  static bool DocumentPolicyNegotiationEnabledByRuntimeFlag() { return DocumentPolicyNegotiationEnabled(nullptr); }
  static bool DocumentPolicyNegotiationEnabled(const FeatureContext*);

  static bool EmailVerificationProtocolEnabledByRuntimeFlag() { return EmailVerificationProtocolEnabled(nullptr); }
  static bool EmailVerificationProtocolEnabled(const FeatureContext*);

  static bool EmailVerificationStatusIndicatorEnabledByRuntimeFlag() { return EmailVerificationStatusIndicatorEnabled(nullptr); }
  static bool EmailVerificationStatusIndicatorEnabled(const FeatureContext*);

  static bool ExperimentalJSProfilerMarkersEnabledByRuntimeFlag() { return ExperimentalJSProfilerMarkersEnabled(nullptr); }
  static bool ExperimentalJSProfilerMarkersEnabled(const FeatureContext*);

  static bool ExtendedTextMetricsEnabledByRuntimeFlag() { return ExtendedTextMetricsEnabled(nullptr); }
  static bool ExtendedTextMetricsEnabled(const FeatureContext*);

  static bool FedCmActiveModeMultipleIdentityProvidersEnabledByRuntimeFlag() { return FedCmActiveModeMultipleIdentityProvidersEnabled(nullptr); }
  static bool FedCmActiveModeMultipleIdentityProvidersEnabled(const FeatureContext*);

  static bool FedCmMultipleIdentityProvidersEnabledByRuntimeFlag() { return FedCmMultipleIdentityProvidersEnabled(nullptr); }
  static bool FedCmMultipleIdentityProvidersEnabled(const FeatureContext*);

  static bool FetchRetryEnabledByRuntimeFlag() { return FetchRetryEnabled(nullptr); }
  static bool FetchRetryEnabled(const FeatureContext*);

  static bool FledgeBiddingAndAuctionServerAPIEnabledByRuntimeFlag() { return FledgeBiddingAndAuctionServerAPIEnabled(nullptr); }
  static bool FledgeBiddingAndAuctionServerAPIEnabled(const FeatureContext*);

  static bool GamepadRawInputChangeEventEnabledByRuntimeFlag() { return GamepadRawInputChangeEventEnabled(nullptr); }
  static bool GamepadRawInputChangeEventEnabled(const FeatureContext*);

  static bool HrefTranslateEnabledByRuntimeFlag() { return HrefTranslateEnabled(nullptr); }
  static bool HrefTranslateEnabled(const FeatureContext*);

  static bool IncomingCallNotificationsEnabledByRuntimeFlag() { return IncomingCallNotificationsEnabled(nullptr); }
  static bool IncomingCallNotificationsEnabled(const FeatureContext*);

  static bool InstallElementEnabledByRuntimeFlag() { return InstallElementEnabled(nullptr); }
  static bool InstallElementEnabled(const FeatureContext*);

  static bool JavaScriptCompileHintsPerFunctionMagicRuntimeEnabledByRuntimeFlag() { return JavaScriptCompileHintsPerFunctionMagicRuntimeEnabled(nullptr); }
  static bool JavaScriptCompileHintsPerFunctionMagicRuntimeEnabled(const FeatureContext*);

  static bool LocalNetworkAccessForWebRTCOptOutEnabledByRuntimeFlag() { return LocalNetworkAccessForWebRTCOptOutEnabled(nullptr); }
  static bool LocalNetworkAccessForWebRTCOptOutEnabled(const FeatureContext*);

  static bool LongAnimationFrameStyleDurationEnabledByRuntimeFlag() { return LongAnimationFrameStyleDurationEnabled(nullptr); }
  static bool LongAnimationFrameStyleDurationEnabled(const FeatureContext*);

  static bool MediaCaptureBackgroundBlurEnabledByRuntimeFlag() { return MediaCaptureBackgroundBlurEnabled(nullptr); }
  static bool MediaCaptureBackgroundBlurEnabled(const FeatureContext*);

  static bool MediaCaptureConfigurationChangeEnabledByRuntimeFlag() { return MediaCaptureConfigurationChangeEnabled(nullptr); }
  static bool MediaCaptureConfigurationChangeEnabled(const FeatureContext*);

  static bool MediaSourceExtensionsForWebCodecsEnabledByRuntimeFlag() { return MediaSourceExtensionsForWebCodecsEnabled(nullptr); }
  static bool MediaSourceExtensionsForWebCodecsEnabled(const FeatureContext*);

  static bool NotificationTriggersEnabledByRuntimeFlag() { return NotificationTriggersEnabled(nullptr); }
  static bool NotificationTriggersEnabled(const FeatureContext*);

  static bool OriginTrialsSampleAPIEnabledByRuntimeFlag() { return OriginTrialsSampleAPIEnabled(nullptr); }
  static bool OriginTrialsSampleAPIEnabled(const FeatureContext*);

  static bool OriginTrialsSampleAPIBrowserReadWriteEnabledByRuntimeFlag() { return OriginTrialsSampleAPIBrowserReadWriteEnabled(nullptr); }
  static bool OriginTrialsSampleAPIBrowserReadWriteEnabled(const FeatureContext*);

  static bool OriginTrialsSampleAPIDependentEnabledByRuntimeFlag() { return OriginTrialsSampleAPIDependentEnabled(nullptr); }
  static bool OriginTrialsSampleAPIDependentEnabled(const FeatureContext*);

  static bool OriginTrialsSampleAPIDeprecationEnabledByRuntimeFlag() { return OriginTrialsSampleAPIDeprecationEnabled(nullptr); }
  static bool OriginTrialsSampleAPIDeprecationEnabled(const FeatureContext*);

  static bool OriginTrialsSampleAPIExpiryGracePeriodEnabledByRuntimeFlag() { return OriginTrialsSampleAPIExpiryGracePeriodEnabled(nullptr); }
  static bool OriginTrialsSampleAPIExpiryGracePeriodEnabled(const FeatureContext*);

  static bool OriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabledByRuntimeFlag() { return OriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled(nullptr); }
  static bool OriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled(const FeatureContext*);

  static bool OriginTrialsSampleAPIImpliedEnabledByRuntimeFlag() { return OriginTrialsSampleAPIImpliedEnabled(nullptr); }
  static bool OriginTrialsSampleAPIImpliedEnabled(const FeatureContext*);

  static bool OriginTrialsSampleAPIInvalidOSEnabledByRuntimeFlag() { return OriginTrialsSampleAPIInvalidOSEnabled(nullptr); }
  static bool OriginTrialsSampleAPIInvalidOSEnabled(const FeatureContext*);

  static bool OriginTrialsSampleAPINavigationEnabledByRuntimeFlag() { return OriginTrialsSampleAPINavigationEnabled(nullptr); }
  static bool OriginTrialsSampleAPINavigationEnabled(const FeatureContext*);

  static bool OriginTrialsSampleAPIPersistentExpiryGracePeriodEnabledByRuntimeFlag() { return OriginTrialsSampleAPIPersistentExpiryGracePeriodEnabled(nullptr); }
  static bool OriginTrialsSampleAPIPersistentExpiryGracePeriodEnabled(const FeatureContext*);

  static bool OriginTrialsSampleAPIPersistentFeatureEnabledByRuntimeFlag() { return OriginTrialsSampleAPIPersistentFeatureEnabled(nullptr); }
  static bool OriginTrialsSampleAPIPersistentFeatureEnabled(const FeatureContext*);

  static bool OriginTrialsSampleAPIPersistentInvalidOSEnabledByRuntimeFlag() { return OriginTrialsSampleAPIPersistentInvalidOSEnabled(nullptr); }
  static bool OriginTrialsSampleAPIPersistentInvalidOSEnabled(const FeatureContext*);

  static bool OriginTrialsSampleAPIPersistentThirdPartyDeprecationFeatureEnabledByRuntimeFlag() { return OriginTrialsSampleAPIPersistentThirdPartyDeprecationFeatureEnabled(nullptr); }
  static bool OriginTrialsSampleAPIPersistentThirdPartyDeprecationFeatureEnabled(const FeatureContext*);

  static bool OriginTrialsSampleAPIThirdPartyEnabledByRuntimeFlag() { return OriginTrialsSampleAPIThirdPartyEnabled(nullptr); }
  static bool OriginTrialsSampleAPIThirdPartyEnabled(const FeatureContext*);

  static bool ParakeetEnabledByRuntimeFlag() { return ParakeetEnabled(nullptr); }
  static bool ParakeetEnabled(const FeatureContext*);

  static bool PerMethodCanMakePaymentQuotaEnabledByRuntimeFlag() { return PerMethodCanMakePaymentQuotaEnabled(nullptr); }
  static bool PerMethodCanMakePaymentQuotaEnabled(const FeatureContext*);

  static bool PNaClEnabledByRuntimeFlag() { return PNaClEnabled(nullptr); }
  static bool PNaClEnabled(const FeatureContext*);

  static bool PreferredAudioOutputDevicesEnabledByRuntimeFlag() { return PreferredAudioOutputDevicesEnabled(nullptr); }
  static bool PreferredAudioOutputDevicesEnabled(const FeatureContext*);

  static bool PrefetchAndPrerenderActivationBeaconEnabledByRuntimeFlag() { return PrefetchAndPrerenderActivationBeaconEnabled(nullptr); }
  static bool PrefetchAndPrerenderActivationBeaconEnabled(const FeatureContext*);

  static bool Prerender2CrossOriginIframesEnabledByRuntimeFlag() { return Prerender2CrossOriginIframesEnabled(nullptr); }
  static bool Prerender2CrossOriginIframesEnabled(const FeatureContext*);

  static bool PrerenderActivationByFormSubmissionEnabledByRuntimeFlag() { return PrerenderActivationByFormSubmissionEnabled(nullptr); }
  static bool PrerenderActivationByFormSubmissionEnabled(const FeatureContext*);

  static bool PrerenderUntilScriptEnabledByRuntimeFlag() { return PrerenderUntilScriptEnabled(nullptr); }
  static bool PrerenderUntilScriptEnabled(const FeatureContext*);

  static bool ProtectedOriginTrialsSampleAPIEnabledByRuntimeFlag() { return ProtectedOriginTrialsSampleAPIEnabled(nullptr); }
  static bool ProtectedOriginTrialsSampleAPIEnabled(const FeatureContext*);

  static bool ProtectedOriginTrialsSampleAPIDependentEnabledByRuntimeFlag() { return ProtectedOriginTrialsSampleAPIDependentEnabled(nullptr); }
  static bool ProtectedOriginTrialsSampleAPIDependentEnabled(const FeatureContext*);

  static bool ProtectedOriginTrialsSampleAPIImpliedEnabledByRuntimeFlag() { return ProtectedOriginTrialsSampleAPIImpliedEnabled(nullptr); }
  static bool ProtectedOriginTrialsSampleAPIImpliedEnabled(const FeatureContext*);

  static bool RtcAudioJitterBufferMaxPacketsEnabledByRuntimeFlag() { return RtcAudioJitterBufferMaxPacketsEnabled(nullptr); }
  static bool RtcAudioJitterBufferMaxPacketsEnabled(const FeatureContext*);

  static bool RTCDiagnosticLoggingEnabledByRuntimeFlag() { return RTCDiagnosticLoggingEnabled(nullptr); }
  static bool RTCDiagnosticLoggingEnabled(const FeatureContext*);

  static bool RTCEncodedFrameSetMetadataEnabledByRuntimeFlag() { return RTCEncodedFrameSetMetadataEnabled(nullptr); }
  static bool RTCEncodedFrameSetMetadataEnabled(const FeatureContext*);

  static bool RTCLegacyCallbackBasedGetStatsEnabledByRuntimeFlag() { return RTCLegacyCallbackBasedGetStatsEnabled(nullptr); }
  static bool RTCLegacyCallbackBasedGetStatsEnabled(const FeatureContext*);

  static bool RTCStatsRelativePacketArrivalDelayEnabledByRuntimeFlag() { return RTCStatsRelativePacketArrivalDelayEnabled(nullptr); }
  static bool RTCStatsRelativePacketArrivalDelayEnabled(const FeatureContext*);

  static bool SecurePaymentConfirmationOptOutEnabledByRuntimeFlag() { return SecurePaymentConfirmationOptOutEnabled(nullptr); }
  static bool SecurePaymentConfirmationOptOutEnabled(const FeatureContext*);

  static bool ShadowRootAdoptedStyleSheetEnabledByRuntimeFlag() { return ShadowRootAdoptedStyleSheetEnabled(nullptr); }
  static bool ShadowRootAdoptedStyleSheetEnabled(const FeatureContext*);

  static bool ShadowRootReferenceTargetEnabledByRuntimeFlag() { return ShadowRootReferenceTargetEnabled(nullptr); }
  static bool ShadowRootReferenceTargetEnabled(const FeatureContext*);

  static bool SharedWorkerExtendedLifetimeEnabledByRuntimeFlag() { return SharedWorkerExtendedLifetimeEnabled(nullptr); }
  static bool SharedWorkerExtendedLifetimeEnabled(const FeatureContext*);

  static bool SpeculationMeasurementEnabledByRuntimeFlag() { return SpeculationMeasurementEnabled(nullptr); }
  static bool SpeculationMeasurementEnabled(const FeatureContext*);

  static bool SpeculationRulesModerateViewportHeuristicsControlEnabledByRuntimeFlag() { return SpeculationRulesModerateViewportHeuristicsControlEnabled(nullptr); }
  static bool SpeculationRulesModerateViewportHeuristicsControlEnabled(const FeatureContext*);

  static bool StandardizedBrowserZoomOptOutEnabledByRuntimeFlag() { return StandardizedBrowserZoomOptOutEnabled(nullptr); }
  static bool StandardizedBrowserZoomOptOutEnabled(const FeatureContext*);

  static bool TestFeatureForBrowserProcessReadWriteAccessOriginTrialEnabledByRuntimeFlag() { return TestFeatureForBrowserProcessReadWriteAccessOriginTrialEnabled(nullptr); }
  static bool TestFeatureForBrowserProcessReadWriteAccessOriginTrialEnabled(const FeatureContext*);

  static bool TextFragmentIdentifiersEnabledByRuntimeFlag() { return TextFragmentIdentifiersEnabled(nullptr); }
  static bool TextFragmentIdentifiersEnabled(const FeatureContext*);

  static bool TouchEventFeatureDetectionEnabledByRuntimeFlag() { return TouchEventFeatureDetectionEnabled(nullptr); }
  static bool TouchEventFeatureDetectionEnabled(const FeatureContext*);

  static bool UAImageReplacementAPIEnabledByRuntimeFlag() { return UAImageReplacementAPIEnabled(nullptr); }
  static bool UAImageReplacementAPIEnabled(const FeatureContext*);

  static bool UnrestrictedSharedArrayBufferEnabledByRuntimeFlag() { return UnrestrictedSharedArrayBufferEnabled(nullptr); }
  static bool UnrestrictedSharedArrayBufferEnabled(const FeatureContext*);

  static bool UserMediaElementLegacyEnabledByRuntimeFlag() { return UserMediaElementLegacyEnabled(nullptr); }
  static bool UserMediaElementLegacyEnabled(const FeatureContext*);

  static bool WebAppInstallationEnabledByRuntimeFlag() { return WebAppInstallationEnabled(nullptr); }
  static bool WebAppInstallationEnabled(const FeatureContext*);

  static bool WebAppScopeExtensionsEnabledByRuntimeFlag() { return WebAppScopeExtensionsEnabled(nullptr); }
  static bool WebAppScopeExtensionsEnabled(const FeatureContext*);

  static bool WebAssemblyCustomDescriptorsV2EnabledByRuntimeFlag() { return WebAssemblyCustomDescriptorsV2Enabled(nullptr); }
  static bool WebAssemblyCustomDescriptorsV2Enabled(const FeatureContext*);

  static bool WebAssemblyJSPromiseIntegrationEnabledByRuntimeFlag() { return WebAssemblyJSPromiseIntegrationEnabled(nullptr); }
  static bool WebAssemblyJSPromiseIntegrationEnabled(const FeatureContext*);

  static bool WebAudioConfigurableRenderQuantumEnabledByRuntimeFlag() { return WebAudioConfigurableRenderQuantumEnabled(nullptr); }
  static bool WebAudioConfigurableRenderQuantumEnabled(const FeatureContext*);

  static bool WebAuthenticationAttestationFormatsEnabledByRuntimeFlag() { return WebAuthenticationAttestationFormatsEnabled(nullptr); }
  static bool WebAuthenticationAttestationFormatsEnabled(const FeatureContext*);

  static bool WebCryptoPQCEnabledByRuntimeFlag() { return WebCryptoPQCEnabled(nullptr); }
  static bool WebCryptoPQCEnabled(const FeatureContext*);

  static bool WebIdentityDigitalCredentialsCreationEnabledByRuntimeFlag() { return WebIdentityDigitalCredentialsCreationEnabled(nullptr); }
  static bool WebIdentityDigitalCredentialsCreationEnabled(const FeatureContext*);

  static bool WebMCPEnabledByRuntimeFlag() { return WebMCPEnabled(nullptr); }
  static bool WebMCPEnabled(const FeatureContext*);

  static bool WebRtcSctpSnapEnabledByRuntimeFlag() { return WebRtcSctpSnapEnabled(nullptr); }
  static bool WebRtcSctpSnapEnabled(const FeatureContext*);

  static bool WebTransportCustomCertificatesEnabledByRuntimeFlag() { return WebTransportCustomCertificatesEnabled(nullptr); }
  static bool WebTransportCustomCertificatesEnabled(const FeatureContext*);

  static bool WebXRImageTrackingEnabledByRuntimeFlag() { return WebXRImageTrackingEnabled(nullptr); }
  static bool WebXRImageTrackingEnabled(const FeatureContext*);

  static bool WebXRPlaneDetectionEnabledByRuntimeFlag() { return WebXRPlaneDetectionEnabled(nullptr); }
  static bool WebXRPlaneDetectionEnabled(const FeatureContext*);

  static bool XSLTEnabledByRuntimeFlag() { return XSLTEnabled(nullptr); }
  static bool XSLTEnabled(const FeatureContext*);


  static bool IsFeatureEnabledFromString(std::string_view name);

 protected:
  // See the comment in RuntimeEnabledFeatures for why these are protected.
  static void SetStableFeaturesEnabled(bool);
  static void SetExperimentalFeaturesEnabled(bool);
  static void SetTestFeaturesEnabled(bool);
  static void SetOriginTrialControlledFeaturesEnabled(bool);

  static void SetFeatureEnabledFromString(std::string_view name, bool enabled);
  static void UpdateStatusFromBaseFeatures();

  static void SetAboutBlankPageRespectsDarkModeOnUserActionEnabled(bool enabled) { feature_states_[kAboutBlankPageRespectsDarkModeOnUserActionFlagIndex] = enabled; }
  static void SetAccelerated2dCanvasEnabled(bool enabled) { feature_states_[kAccelerated2dCanvasFlagIndex] = enabled; }
  static void SetAcceleratedSmallCanvasesEnabled(bool enabled) { feature_states_[kAcceleratedSmallCanvasesFlagIndex] = enabled; }
  static void SetAccessibilityCheckIfcInPreviousTextOnLineEnabled(bool enabled) { feature_states_[kAccessibilityCheckIfcInPreviousTextOnLineFlagIndex] = enabled; }
  static void SetAccessibilityCustomElementRoleNoneEnabled(bool enabled) { feature_states_[kAccessibilityCustomElementRoleNoneFlagIndex] = enabled; }
  static void SetAccessibilityExposeDisplayNoneEnabled(bool enabled) { feature_states_[kAccessibilityExposeDisplayNoneFlagIndex] = enabled; }
  static void SetAccessibilityImplicitActionsEnabled(bool enabled) { feature_states_[kAccessibilityImplicitActionsFlagIndex] = enabled; }
  static void SetAccessibilityMinRoleTabbableEnabled(bool enabled) { feature_states_[kAccessibilityMinRoleTabbableFlagIndex] = enabled; }
  static void SetAccessibilityOSLevelBoldTextEnabled(bool enabled) { feature_states_[kAccessibilityOSLevelBoldTextFlagIndex] = enabled; }
  static void SetAccessibilityProhibitedNamesEnabled(bool enabled) { feature_states_[kAccessibilityProhibitedNamesFlagIndex] = enabled; }
  static void SetAccessibilitySerializationSizeMetricsEnabled(bool enabled) { feature_states_[kAccessibilitySerializationSizeMetricsFlagIndex] = enabled; }
  static void SetAccessibilityUseAXPositionForDocumentMarkersEnabled(bool enabled) { feature_states_[kAccessibilityUseAXPositionForDocumentMarkersFlagIndex] = enabled; }
  static void SetAccessKeyLabelEnabled(bool enabled) { feature_states_[kAccessKeyLabelFlagIndex] = enabled; }
  static void SetAddressSpaceEnabled(bool enabled) { feature_states_[kAddressSpaceFlagIndex] = enabled; }
  static void SetAdInterestGroupAPIEnabled(bool enabled) { feature_states_[kAdInterestGroupAPIFlagIndex] = enabled; }
  static void SetAdjustEndOfNextParagraphIfMovedParagraphIsUpdatedEnabled(bool enabled) { feature_states_[kAdjustEndOfNextParagraphIfMovedParagraphIsUpdatedFlagIndex] = enabled; }
  static void SetAdTaggingEnabled(bool enabled) { feature_states_[kAdTaggingFlagIndex] = enabled; }
  static void SetAIClassifierAPIEnabled(bool enabled) { feature_states_[kAIClassifierAPIFlagIndex] = enabled; }
  static void SetAIEmbeddingsAPIEnabled(bool enabled) { feature_states_[kAIEmbeddingsAPIFlagIndex] = enabled; }
  static void SetAIEmbeddingsAPIForWorkersEnabled(bool enabled) { feature_states_[kAIEmbeddingsAPIForWorkersFlagIndex] = enabled; }
  static void SetAIPageContentAnchoredFixedOffscreenNonActionabilityEnabled(bool enabled) { feature_states_[kAIPageContentAnchoredFixedOffscreenNonActionabilityFlagIndex] = enabled; }
  static void SetAIPageContentAnchoredNonFixedOffscreenNonActionabilityEnabled(bool enabled) { feature_states_[kAIPageContentAnchoredNonFixedOffscreenNonActionabilityFlagIndex] = enabled; }
  static void SetAIPageContentBuildOnLoadForTestingEnabled(bool enabled) { feature_states_[kAIPageContentBuildOnLoadForTestingFlagIndex] = enabled; }
  static void SetAIPageContentCheckGeometryEnabled(bool enabled) { feature_states_[kAIPageContentCheckGeometryFlagIndex] = enabled; }
  static void SetAIPageContentConvertNodeTextToUtf8Enabled(bool enabled) { feature_states_[kAIPageContentConvertNodeTextToUtf8FlagIndex] = enabled; }
  static void SetAIPageContentElementCSSRedactionEnabled(bool enabled) { feature_states_[kAIPageContentElementCSSRedactionFlagIndex] = enabled; }
  static void SetAIPageContentIncludeSVGSubtreeEnabled(bool enabled) { feature_states_[kAIPageContentIncludeSVGSubtreeFlagIndex] = enabled; }
  static void SetAIPageContentOuterBoxMapToAncestorSpaceEnabled(bool enabled) { feature_states_[kAIPageContentOuterBoxMapToAncestorSpaceFlagIndex] = enabled; }
  static void SetAIPageContentPaidContentAnnotationEnabled(bool enabled) { feature_states_[kAIPageContentPaidContentAnnotationFlagIndex] = enabled; }
  static void SetAIPageContentSkipUnclickableFixedOverlaysEnabled(bool enabled) { feature_states_[kAIPageContentSkipUnclickableFixedOverlaysFlagIndex] = enabled; }
  static void SetAIPageContentTrackedElementsIframeEnabled(bool enabled) { feature_states_[kAIPageContentTrackedElementsIframeFlagIndex] = enabled; }
  static void SetAIPageContentTrackedElementsPasswordEnabled(bool enabled) { feature_states_[kAIPageContentTrackedElementsPasswordFlagIndex] = enabled; }
  static void SetAIPageContentVisualViewportClampEnabled(bool enabled) { feature_states_[kAIPageContentVisualViewportClampFlagIndex] = enabled; }
  static void SetAIPromptAPIEnabled(bool enabled) { feature_states_[kAIPromptAPIFlagIndex] = enabled; }
  static void SetAIPromptAPIForWorkersEnabled(bool enabled) { feature_states_[kAIPromptAPIForWorkersFlagIndex] = enabled; }
  static void SetAIPromptAPILegacyIdentifiersEnabled(bool enabled) { feature_states_[kAIPromptAPILegacyIdentifiersFlagIndex] = enabled; }
  static void SetAIPromptAPILegacyParamsEnabled(bool enabled) { feature_states_[kAIPromptAPILegacyParamsFlagIndex] = enabled; }
  static void SetAIPromptAPIMultimodalInputEnabled(bool enabled) { feature_states_[kAIPromptAPIMultimodalInputFlagIndex] = enabled; }
  static void SetAIPromptAPIParamsEnabled(bool enabled) { feature_states_[kAIPromptAPIParamsFlagIndex] = enabled; }
  static void SetAIPromptAPIStructuredOutputEnabled(bool enabled) { feature_states_[kAIPromptAPIStructuredOutputFlagIndex] = enabled; }
  static void SetAIPromptAPIToolUseEnabled(bool enabled) { feature_states_[kAIPromptAPIToolUseFlagIndex] = enabled; }
  static void SetAIProofreadingAPIEnabled(bool enabled) { feature_states_[kAIProofreadingAPIFlagIndex] = enabled; }
  static void SetAIRewriterAPIEnabled(bool enabled) { feature_states_[kAIRewriterAPIFlagIndex] = enabled; }
  static void SetAIRewriterAPIForWorkersEnabled(bool enabled) { feature_states_[kAIRewriterAPIForWorkersFlagIndex] = enabled; }
  static void SetAISummarizationAPIEnabled(bool enabled) { feature_states_[kAISummarizationAPIFlagIndex] = enabled; }
  static void SetAISummarizationAPIForWorkersEnabled(bool enabled) { feature_states_[kAISummarizationAPIForWorkersFlagIndex] = enabled; }
  static void SetAISummarizationPerformancePreferenceEnabled(bool enabled) { feature_states_[kAISummarizationPerformancePreferenceFlagIndex] = enabled; }
  static void SetAIWriterAPIEnabled(bool enabled) { feature_states_[kAIWriterAPIFlagIndex] = enabled; }
  static void SetAIWriterAPIForWorkersEnabled(bool enabled) { feature_states_[kAIWriterAPIForWorkersFlagIndex] = enabled; }
  static void SetAlignZoomToCenterEnabled(bool enabled) { feature_states_[kAlignZoomToCenterFlagIndex] = enabled; }
  static void SetAllImagesPaintedSentToElementTimingEnabled(bool enabled) { feature_states_[kAllImagesPaintedSentToElementTimingFlagIndex] = enabled; }
  static void SetAllowContentInitiatedDataUrlNavigationsEnabled(bool enabled) { feature_states_[kAllowContentInitiatedDataUrlNavigationsFlagIndex] = enabled; }
  static void SetAllowPreloadingWithCSPMetaTagEnabled(bool enabled) { feature_states_[kAllowPreloadingWithCSPMetaTagFlagIndex] = enabled; }
  static void SetAllowSameSiteNoneCookiesInSandboxEnabled(bool enabled) { feature_states_[kAllowSameSiteNoneCookiesInSandboxFlagIndex] = enabled; }
  static void SetAllowSvgUseToReferenceExternalDocumentRootEnabled(bool enabled) { feature_states_[kAllowSvgUseToReferenceExternalDocumentRootFlagIndex] = enabled; }
  static void SetAllowSyntheticTimingForCanvasCaptureEnabled(bool enabled) { feature_states_[kAllowSyntheticTimingForCanvasCaptureFlagIndex] = enabled; }
  static void SetAllowURNsInIframesEnabled(bool enabled) { feature_states_[kAllowURNsInIframesFlagIndex] = enabled; }
  static void SetAncestorOriginsStoredOnDocumentEnabled(bool enabled) { feature_states_[kAncestorOriginsStoredOnDocumentFlagIndex] = enabled; }
  static void SetAnchorPositionAdjustmentWithoutOverflowEnabled(bool enabled) { feature_states_[kAnchorPositionAdjustmentWithoutOverflowFlagIndex] = enabled; }
  static void SetAndroidDownloadableFontsMatchingEnabled(bool enabled) { feature_states_[kAndroidDownloadableFontsMatchingFlagIndex] = enabled; }
  static void SetAnimationEventAnimationEnabled(bool enabled) { feature_states_[kAnimationEventAnimationFlagIndex] = enabled; }
  static void SetAnimationProgressAPIEnabled(bool enabled) { feature_states_[kAnimationProgressAPIFlagIndex] = enabled; }
  static void SetAnimationRangeRejectRelativeLengthsEnabled(bool enabled) { feature_states_[kAnimationRangeRejectRelativeLengthsFlagIndex] = enabled; }
  static void SetAnimationTriggerEnabled(bool enabled) { feature_states_[kAnimationTriggerFlagIndex] = enabled; }
  static void SetAnimationWorkletEnabled(bool enabled) { feature_states_[kAnimationWorkletFlagIndex] = enabled; }
  static void SetAnnotationSpaceForMultiColEnabled(bool enabled) { feature_states_[kAnnotationSpaceForMultiColFlagIndex] = enabled; }
  static void SetAnnotationSpaceOnStartEnabled(bool enabled) { feature_states_[kAnnotationSpaceOnStartFlagIndex] = enabled; }
  static void SetAnonymousIframeEnabled(bool enabled) { feature_states_[kAnonymousIframeFlagIndex] = enabled; }
  static void SetAOMAriaRelationshipPropertiesEnabled(bool enabled) { feature_states_[kAOMAriaRelationshipPropertiesFlagIndex] = enabled; }
  static void SetAOMAriaRelationshipPropertiesAriaOwnsEnabled(bool enabled) { feature_states_[kAOMAriaRelationshipPropertiesAriaOwnsFlagIndex] = enabled; }
  static void SetAppearanceBaseEnabled(bool enabled) { feature_states_[kAppearanceBaseFlagIndex] = enabled; }
  static void SetApproximateGeolocationPermissionEnabled(bool enabled) { feature_states_[kApproximateGeolocationPermissionFlagIndex] = enabled; }
  static void SetApproximateGeolocationPermissionAccuracyModeEnabled(bool enabled) { feature_states_[kApproximateGeolocationPermissionAccuracyModeFlagIndex] = enabled; }
  static void SetApproximateGeolocationPermissionAPIEnabled(bool enabled) { feature_states_[kApproximateGeolocationPermissionAPIFlagIndex] = enabled; }
  static void SetApproximateGeolocationWebVisibleAPIEnabled(bool enabled) { feature_states_[kApproximateGeolocationWebVisibleAPIFlagIndex] = enabled; }
  static void SetAppTitleEnabled(bool enabled) { feature_states_[kAppTitleFlagIndex] = enabled; }
  static void SetAriaActionsEnabled(bool enabled) { feature_states_[kAriaActionsFlagIndex] = enabled; }
  static void SetAriaNotifyEnabled(bool enabled) { feature_states_[kAriaNotifyFlagIndex] = enabled; }
  static void SetAriaNotifyV2Enabled(bool enabled) { feature_states_[kAriaNotifyV2FlagIndex] = enabled; }
  static void SetAriaRowColIndexTextEnabled(bool enabled) { feature_states_[kAriaRowColIndexTextFlagIndex] = enabled; }
  static void SetAttributionReportingEnabled(bool enabled) { feature_states_[kAttributionReportingFlagIndex] = enabled; }
  static void SetAudioContextAsyncStateTransitionsEnabled(bool enabled) { feature_states_[kAudioContextAsyncStateTransitionsFlagIndex] = enabled; }
  static void SetAudioContextPlaybackStatsEnabled(bool enabled) { feature_states_[kAudioContextPlaybackStatsFlagIndex] = enabled; }
  static void SetAudioContextSetSinkIdEnabled(bool enabled) { feature_states_[kAudioContextSetSinkIdFlagIndex] = enabled; }
  static void SetAudioOutputDevicesEnabled(bool enabled) { feature_states_[kAudioOutputDevicesFlagIndex] = enabled; }
  static void SetAudioVideoTracksEnabled(bool enabled) { feature_states_[kAudioVideoTracksFlagIndex] = enabled; }
  static void SetAudioWorkletSharedPortEnabled(bool enabled) { feature_states_[kAudioWorkletSharedPortFlagIndex] = enabled; }
  static void SetAuthorSpecifiedLayoutScrollSnapBehaviorEnabled(bool enabled) { feature_states_[kAuthorSpecifiedLayoutScrollSnapBehaviorFlagIndex] = enabled; }
  static void SetAutoDarkModeEnabled(bool enabled) { feature_states_[kAutoDarkModeFlagIndex] = enabled; }
  static void SetAutoDarkModeSkipImagesEnabled(bool enabled) { feature_states_[kAutoDarkModeSkipImagesFlagIndex] = enabled; }
  static void SetAutoDarkModeSVGSizeThresholdEnabled(bool enabled) { feature_states_[kAutoDarkModeSVGSizeThresholdFlagIndex] = enabled; }
  static void SetAutofillEnabled(bool enabled) { feature_states_[kAutofillFlagIndex] = enabled; }
  static void SetAutofillEventEnabled(bool enabled) { feature_states_[kAutofillEventFlagIndex] = enabled; }
  static void SetAutofillPreviewGenericFontFamilyEnabled(bool enabled) { feature_states_[kAutofillPreviewGenericFontFamilyFlagIndex] = enabled; }
  static void SetAutofillPreviewIgnoreAuthorFontEnabled(bool enabled) { feature_states_[kAutofillPreviewIgnoreAuthorFontFlagIndex] = enabled; }
  static void SetAutomationControlledEnabled(bool enabled) { feature_states_[kAutomationControlledFlagIndex] = enabled; }
  static void SetAutoPictureInPictureVideoHeuristicsEnabled(bool enabled) { feature_states_[kAutoPictureInPictureVideoHeuristicsFlagIndex] = enabled; }
  static void SetAutoSizeUsesScrollWidthForOverflowEnabled(bool enabled) { feature_states_[kAutoSizeUsesScrollWidthForOverflowFlagIndex] = enabled; }
  static void SetAvoidEmbeddedContentViewLocationEnabled(bool enabled) { feature_states_[kAvoidEmbeddedContentViewLocationFlagIndex] = enabled; }
  static void SetAvoidNonSelectableSelectionBoundaryEnabled(bool enabled) { feature_states_[kAvoidNonSelectableSelectionBoundaryFlagIndex] = enabled; }
  static void SetAvoidSynchronousBlurOnDisabledAttributeChangeEnabled(bool enabled) { feature_states_[kAvoidSynchronousBlurOnDisabledAttributeChangeFlagIndex] = enabled; }
  static void SetBackfaceVisibilityInteropEnabled(bool enabled) { feature_states_[kBackfaceVisibilityInteropFlagIndex] = enabled; }
  static void SetBackForwardCacheEnabled(bool enabled) { feature_states_[kBackForwardCacheFlagIndex] = enabled; }
  static void SetBackForwardCacheExperimentHTTPHeaderEnabled(bool enabled) { feature_states_[kBackForwardCacheExperimentHTTPHeaderFlagIndex] = enabled; }
  static void SetBackForwardCacheNotRestoredReasonsEnabled(bool enabled) { feature_states_[kBackForwardCacheNotRestoredReasonsFlagIndex] = enabled; }
  static void SetBackForwardCacheRestorationPerformanceEntryEnabled(bool enabled) { feature_states_[kBackForwardCacheRestorationPerformanceEntryFlagIndex] = enabled; }
  static void SetBackForwardCacheUpdateNotRestoredReasonsNameEnabled(bool enabled) { feature_states_[kBackForwardCacheUpdateNotRestoredReasonsNameFlagIndex] = enabled; }
  static void SetBackgroundClipTextDecorationEnabled(bool enabled) { feature_states_[kBackgroundClipTextDecorationFlagIndex] = enabled; }
  static void SetBackgroundFetchEnabled(bool enabled) { feature_states_[kBackgroundFetchFlagIndex] = enabled; }
  static void SetBackgroundPageFreezeOptOutEnabled(bool enabled) { feature_states_[kBackgroundPageFreezeOptOutFlagIndex] = enabled; }
  static void SetBarcodeDetectorEnabled(bool enabled) { feature_states_[kBarcodeDetectorFlagIndex] = enabled; }
  static void SetBaseAppearanceInlineSizingEnabled(bool enabled) { feature_states_[kBaseAppearanceInlineSizingFlagIndex] = enabled; }
  static void SetBasicShapeCornerRadiusEnabled(bool enabled) { feature_states_[kBasicShapeCornerRadiusFlagIndex] = enabled; }
  static void SetBidiCaretAffinityEnabled(bool enabled) { feature_states_[kBidiCaretAffinityFlagIndex] = enabled; }
  static void SetBidiVisualOrderCaretMovementEnabled(bool enabled) { feature_states_[kBidiVisualOrderCaretMovementFlagIndex] = enabled; }
  static void SetBlinkExtensionWebViewEnabled(bool enabled) { feature_states_[kBlinkExtensionWebViewFlagIndex] = enabled; }
  static void SetBlinkExtensionWebViewMediaIntegrityEnabled(bool enabled) { feature_states_[kBlinkExtensionWebViewMediaIntegrityFlagIndex] = enabled; }
  static void SetBlinkGeometryMapperViewportFastPathEnabled(bool enabled) { feature_states_[kBlinkGeometryMapperViewportFastPathFlagIndex] = enabled; }
  static void SetBlinkLifecycleScriptForbiddenEnabled(bool enabled) { feature_states_[kBlinkLifecycleScriptForbiddenFlagIndex] = enabled; }
  static void SetBlinkRuntimeCallStatsEnabled(bool enabled) { feature_states_[kBlinkRuntimeCallStatsFlagIndex] = enabled; }
  static void SetBlobBytesEnabled(bool enabled) { feature_states_[kBlobBytesFlagIndex] = enabled; }
  static void SetBlockingFocusWithoutUserActivationEnabled(bool enabled) { feature_states_[kBlockingFocusWithoutUserActivationFlagIndex] = enabled; }
  static void SetBlockSelectPopupUnfocusedWindowEnabled(bool enabled) { feature_states_[kBlockSelectPopupUnfocusedWindowFlagIndex] = enabled; }
  static void SetBoundaryEventDispatchTracksNodeRemovalEnabled(bool enabled) { feature_states_[kBoundaryEventDispatchTracksNodeRemovalFlagIndex] = enabled; }
  static void SetBoxDecorationBreakCloneLineBreakingEnabled(bool enabled) { feature_states_[kBoxDecorationBreakCloneLineBreakingFlagIndex] = enabled; }
  static void SetBrowserInitiatedAutomaticPictureInPictureEnabled(bool enabled) { feature_states_[kBrowserInitiatedAutomaticPictureInPictureFlagIndex] = enabled; }
  static void SetBufferedBytesConsumerLimitSizeEnabled(bool enabled) { feature_states_[kBufferedBytesConsumerLimitSizeFlagIndex] = enabled; }
  static void SetBypassPepcSecurityForTestingEnabled(bool enabled) { feature_states_[kBypassPepcSecurityForTestingFlagIndex] = enabled; }
  static void SetCacheControlRFC7234ParsingEnabled(bool enabled) { feature_states_[kCacheControlRFC7234ParsingFlagIndex] = enabled; }
  static void SetCacheControlRFC7234ParsingMetricsEnabled(bool enabled) { feature_states_[kCacheControlRFC7234ParsingMetricsFlagIndex] = enabled; }
  static void SetCacheStorageCodeCacheHintEnabled(bool enabled) { feature_states_[kCacheStorageCodeCacheHintFlagIndex] = enabled; }
  static void SetCacheStyleAdjusterEnabled(bool enabled) { feature_states_[kCacheStyleAdjusterFlagIndex] = enabled; }
  static void SetCameraAndMicrophoneElementsEnabled(bool enabled) { feature_states_[kCameraAndMicrophoneElementsFlagIndex] = enabled; }
  static void SetCanvas2dCanvasFilterEnabled(bool enabled) { feature_states_[kCanvas2dCanvasFilterFlagIndex] = enabled; }
  static void SetCanvas2dDeferredFlushEnabled(bool enabled) { feature_states_[kCanvas2dDeferredFlushFlagIndex] = enabled; }
  static void SetCanvas2dLayersEnabled(bool enabled) { feature_states_[kCanvas2dLayersFlagIndex] = enabled; }
  static void SetCanvas2dLayersWithOptionsEnabled(bool enabled) { feature_states_[kCanvas2dLayersWithOptionsFlagIndex] = enabled; }
  static void SetCanvas2dMeshEnabled(bool enabled) { feature_states_[kCanvas2dMeshFlagIndex] = enabled; }
  static void SetCanvasDrawElementEnabled(bool enabled) { feature_states_[kCanvasDrawElementFlagIndex] = enabled; }
  static void SetCanvasFloatingPointEnabled(bool enabled) { feature_states_[kCanvasFloatingPointFlagIndex] = enabled; }
  static void SetCanvasGlobalHDRHeadroomEnabled(bool enabled) { feature_states_[kCanvasGlobalHDRHeadroomFlagIndex] = enabled; }
  static void SetCanvasGradientCSSColor4Enabled(bool enabled) { feature_states_[kCanvasGradientCSSColor4FlagIndex] = enabled; }
  static void SetCanvasHDREnabled(bool enabled) { feature_states_[kCanvasHDRFlagIndex] = enabled; }
  static void SetCanvasTextMetricsPreciseBoundsEnabled(bool enabled) { feature_states_[kCanvasTextMetricsPreciseBoundsFlagIndex] = enabled; }
  static void SetCanvasToneMappingEnabled(bool enabled) { feature_states_[kCanvasToneMappingFlagIndex] = enabled; }
  static void SetCanvasUsesArcPaintOpEnabled(bool enabled) { feature_states_[kCanvasUsesArcPaintOpFlagIndex] = enabled; }
  static void SetCapabilityDelegationDigitalCredentialsEnabled(bool enabled) { feature_states_[kCapabilityDelegationDigitalCredentialsFlagIndex] = enabled; }
  static void SetCapabilityDelegationDisplayCaptureRequestEnabled(bool enabled) { feature_states_[kCapabilityDelegationDisplayCaptureRequestFlagIndex] = enabled; }
  static void SetCaptureControllerEnabled(bool enabled) { feature_states_[kCaptureControllerFlagIndex] = enabled; }
  static void SetCapturedMouseEventsEnabled(bool enabled) { feature_states_[kCapturedMouseEventsFlagIndex] = enabled; }
  static void SetCapturedSurfaceControlEnabled(bool enabled) { feature_states_[kCapturedSurfaceControlFlagIndex] = enabled; }
  static void SetCapturedSurfaceResolutionEnabled(bool enabled) { feature_states_[kCapturedSurfaceResolutionFlagIndex] = enabled; }
  static void SetCaptureHandleEnabled(bool enabled) { feature_states_[kCaptureHandleFlagIndex] = enabled; }
  static void SetCaretOutsideEditableAtomicInlineEnabled(bool enabled) { feature_states_[kCaretOutsideEditableAtomicInlineFlagIndex] = enabled; }
  static void SetCCTNewRFMPushBehaviorEnabled(bool enabled) { feature_states_[kCCTNewRFMPushBehaviorFlagIndex] = enabled; }
  static void SetCDTNewCrossOriginHandlingEnabled(bool enabled) { feature_states_[kCDTNewCrossOriginHandlingFlagIndex] = enabled; }
  static void SetCDTNewDestinationEnabled(bool enabled) { feature_states_[kCDTNewDestinationFlagIndex] = enabled; }
  static void SetCDTNewReferrerAndReferrerPolicyHandlingEnabled(bool enabled) { feature_states_[kCDTNewReferrerAndReferrerPolicyHandlingFlagIndex] = enabled; }
  static void SetCheckableInputTypeLayoutInlineEnabled(bool enabled) { feature_states_[kCheckableInputTypeLayoutInlineFlagIndex] = enabled; }
  static void SetCheckVisibilityExtraPropertiesEnabled(bool enabled) { feature_states_[kCheckVisibilityExtraPropertiesFlagIndex] = enabled; }
  static void SetClampUnfocusedSelectionCacheEnabled(bool enabled) { feature_states_[kClampUnfocusedSelectionCacheFlagIndex] = enabled; }
  static void SetCleanUpActivationBehaviorEnabled(bool enabled) { feature_states_[kCleanUpActivationBehaviorFlagIndex] = enabled; }
  static void SetClearCurrentTargetAfterDispatchEnabled(bool enabled) { feature_states_[kClearCurrentTargetAfterDispatchFlagIndex] = enabled; }
  static void SetClearDisplayLockPrePaintFlagsEnabled(bool enabled) { feature_states_[kClearDisplayLockPrePaintFlagsFlagIndex] = enabled; }
  static void SetClearFocusWithinOnSubtreeRemovalEnabled(bool enabled) { feature_states_[kClearFocusWithinOnSubtreeRemovalFlagIndex] = enabled; }
  static void SetClearTargetOnlyIfInShadowTreeEnabled(bool enabled) { feature_states_[kClearTargetOnlyIfInShadowTreeFlagIndex] = enabled; }
  static void SetClipboardEventTargetUsesContainerNodeEnabled(bool enabled) { feature_states_[kClipboardEventTargetUsesContainerNodeFlagIndex] = enabled; }
  static void SetClipboardPasteImageRespectBufferEnabled(bool enabled) { feature_states_[kClipboardPasteImageRespectBufferFlagIndex] = enabled; }
  static void SetClipElementVisibleBoundsInLocalRootEnabled(bool enabled) { feature_states_[kClipElementVisibleBoundsInLocalRootFlagIndex] = enabled; }
  static void SetClipPathNestedRasterOptimizationEnabled(bool enabled) { feature_states_[kClipPathNestedRasterOptimizationFlagIndex] = enabled; }
  static void SetCoalesceSelectionchangeEventEnabled(bool enabled) { feature_states_[kCoalesceSelectionchangeEventFlagIndex] = enabled; }
  static void SetCoepReflectionEnabled(bool enabled) { feature_states_[kCoepReflectionFlagIndex] = enabled; }
  static void SetColorInputAcceptsCSSColorsEnabled(bool enabled) { feature_states_[kColorInputAcceptsCSSColorsFlagIndex] = enabled; }
  static void SetColorSpaceDisplayP3LinearEnabled(bool enabled) { feature_states_[kColorSpaceDisplayP3LinearFlagIndex] = enabled; }
  static void SetColorSpacePredefinedLinearSpacesEnabled(bool enabled) { feature_states_[kColorSpacePredefinedLinearSpacesFlagIndex] = enabled; }
  static void SetColorSpaceRec2100LinearEnabled(bool enabled) { feature_states_[kColorSpaceRec2100LinearFlagIndex] = enabled; }
  static void SetCommaSeparatedContainerQueriesEnabled(bool enabled) { feature_states_[kCommaSeparatedContainerQueriesFlagIndex] = enabled; }
  static void SetComposedPathReturnTargetBeingDispatchedEnabled(bool enabled) { feature_states_[kComposedPathReturnTargetBeingDispatchedFlagIndex] = enabled; }
  static void SetCompositeBGColorAnimationEnabled(bool enabled) { feature_states_[kCompositeBGColorAnimationFlagIndex] = enabled; }
  static void SetCompositeBoxShadowAnimationEnabled(bool enabled) { feature_states_[kCompositeBoxShadowAnimationFlagIndex] = enabled; }
  static void SetCompositeClipPathAnimationEnabled(bool enabled) { feature_states_[kCompositeClipPathAnimationFlagIndex] = enabled; }
  static void SetCompositedSelectionUpdateEnabled(bool enabled) { feature_states_[kCompositedSelectionUpdateFlagIndex] = enabled; }
  static void SetCompositingDecisionAtAnimationPhaseBoundariesEnabled(bool enabled) { feature_states_[kCompositingDecisionAtAnimationPhaseBoundariesFlagIndex] = enabled; }
  static void SetCompositionForegroundMarkersEnabled(bool enabled) { feature_states_[kCompositionForegroundMarkersFlagIndex] = enabled; }
  static void SetCompositorEventTriggerEnabled(bool enabled) { feature_states_[kCompositorEventTriggerFlagIndex] = enabled; }
  static void SetCompositorTimelineTriggerEnabled(bool enabled) { feature_states_[kCompositorTimelineTriggerFlagIndex] = enabled; }
  static void SetCompressionDictionaryTransportEnabled(bool enabled) { feature_states_[kCompressionDictionaryTransportFlagIndex] = enabled; }
  static void SetComputedAccessibilityInfoEnabled(bool enabled) { feature_states_[kComputedAccessibilityInfoFlagIndex] = enabled; }
  static void SetComputePressureEnabled(bool enabled) { feature_states_[kComputePressureFlagIndex] = enabled; }
  static void SetConcurrentNativePaintWorkletsEnabled(bool enabled) { feature_states_[kConcurrentNativePaintWorkletsFlagIndex] = enabled; }
  static void SetConditionalTracingLoAFEnabled(bool enabled) { feature_states_[kConditionalTracingLoAFFlagIndex] = enabled; }
  static void SetConnectionAllowlistEmbeddedEnforcementEnabled(bool enabled) { feature_states_[kConnectionAllowlistEmbeddedEnforcementFlagIndex] = enabled; }
  static void SetConstructableStylesheetCacheEnabled(bool enabled) { feature_states_[kConstructableStylesheetCacheFlagIndex] = enabled; }
  static void SetContactsManagerEnabled(bool enabled) { feature_states_[kContactsManagerFlagIndex] = enabled; }
  static void SetContactsManagerExtraPropertiesEnabled(bool enabled) { feature_states_[kContactsManagerExtraPropertiesFlagIndex] = enabled; }
  static void SetContainerNameOnlyEnabled(bool enabled) { feature_states_[kContainerNameOnlyFlagIndex] = enabled; }
  static void SetContainerTimingEnabled(bool enabled) { feature_states_[kContainerTimingFlagIndex] = enabled; }
  static void SetContentIndexEnabled(bool enabled) { feature_states_[kContentIndexFlagIndex] = enabled; }
  static void SetContextMenuEnabled(bool enabled) { feature_states_[kContextMenuFlagIndex] = enabled; }
  static void SetControlledFrameEnabled(bool enabled) { feature_states_[kControlledFrameFlagIndex] = enabled; }
  static void SetControlledFrameWebRequestSecurityInfoEnabled(bool enabled) { feature_states_[kControlledFrameWebRequestSecurityInfoFlagIndex] = enabled; }
  static void SetCookieStoreAPIMaxAgeEnabled(bool enabled) { feature_states_[kCookieStoreAPIMaxAgeFlagIndex] = enabled; }
  static void SetCookieStoreAPIWhitespaceStrippingEnabled(bool enabled) { feature_states_[kCookieStoreAPIWhitespaceStrippingFlagIndex] = enabled; }
  static void SetCoopRestrictPropertiesEnabled(bool enabled) { feature_states_[kCoopRestrictPropertiesFlagIndex] = enabled; }
  static void SetCorrectTemplateFormParsingEnabled(bool enabled) { feature_states_[kCorrectTemplateFormParsingFlagIndex] = enabled; }
  static void SetCorsRFC1918Enabled(bool enabled) { feature_states_[kCorsRFC1918FlagIndex] = enabled; }
  static void SetCpuPerformanceEnabled(bool enabled) { feature_states_[kCpuPerformanceFlagIndex] = enabled; }
  static void SetCrashReportingStorageAPIEnabled(bool enabled) { feature_states_[kCrashReportingStorageAPIFlagIndex] = enabled; }
  static void SetCreateInlineContentsAnonymousBlockEnabled(bool enabled) { feature_states_[kCreateInlineContentsAnonymousBlockFlagIndex] = enabled; }
  static void SetCSPHashesV1Enabled(bool enabled) { feature_states_[kCSPHashesV1FlagIndex] = enabled; }
  static void SetCSPReportHashEnabled(bool enabled) { feature_states_[kCSPReportHashFlagIndex] = enabled; }
  static void SetCSSAccentColorKeywordEnabled(bool enabled) { feature_states_[kCSSAccentColorKeywordFlagIndex] = enabled; }
  static void SetCSSActiveCaptionMapsToCanvasEnabled(bool enabled) { feature_states_[kCSSActiveCaptionMapsToCanvasFlagIndex] = enabled; }
  static void SetCSSAlphaColorFunctionEnabled(bool enabled) { feature_states_[kCSSAlphaColorFunctionFlagIndex] = enabled; }
  static void SetCSSAlphaColorFunctionRequiresAlphaEnabled(bool enabled) { feature_states_[kCSSAlphaColorFunctionRequiresAlphaFlagIndex] = enabled; }
  static void SetCSSAltCounterEnabled(bool enabled) { feature_states_[kCSSAltCounterFlagIndex] = enabled; }
  static void SetCSSAnimationIterationCompositeEnabled(bool enabled) { feature_states_[kCSSAnimationIterationCompositeFlagIndex] = enabled; }
  static void SetCSSArgumentGrammarEnabled(bool enabled) { feature_states_[kCSSArgumentGrammarFlagIndex] = enabled; }
  static void SetCSSAtRuleCounterStyleImageSymbolsEnabled(bool enabled) { feature_states_[kCSSAtRuleCounterStyleImageSymbolsFlagIndex] = enabled; }
  static void SetCSSAtRuleCounterStyleSpeakAsDescriptorEnabled(bool enabled) { feature_states_[kCSSAtRuleCounterStyleSpeakAsDescriptorFlagIndex] = enabled; }
  static void SetCSSAttributeValueCaseSensitiveNonHTMLEnabled(bool enabled) { feature_states_[kCSSAttributeValueCaseSensitiveNonHTMLFlagIndex] = enabled; }
  static void SetCSSBackgroundClipBorderAreaEnabled(bool enabled) { feature_states_[kCSSBackgroundClipBorderAreaFlagIndex] = enabled; }
  static void SetCSSBorderShapeEnabled(bool enabled) { feature_states_[kCSSBorderShapeFlagIndex] = enabled; }
  static void SetCSSCalcSimplificationAndSerializationEnabled(bool enabled) { feature_states_[kCSSCalcSimplificationAndSerializationFlagIndex] = enabled; }
  static void SetCSSCaretAnimationEnabled(bool enabled) { feature_states_[kCSSCaretAnimationFlagIndex] = enabled; }
  static void SetCSSCaretColorWithOptionalSecondValueEnabled(bool enabled) { feature_states_[kCSSCaretColorWithOptionalSecondValueFlagIndex] = enabled; }
  static void SetCSSCaretShapeEnabled(bool enabled) { feature_states_[kCSSCaretShapeFlagIndex] = enabled; }
  static void SetCSSCaseSensitiveSelectorEnabled(bool enabled) { feature_states_[kCSSCaseSensitiveSelectorFlagIndex] = enabled; }
  static void SetCSSChUnitSpecCompliantFallbackEnabled(bool enabled) { feature_states_[kCSSChUnitSpecCompliantFallbackFlagIndex] = enabled; }
  static void SetCSSColorTypedOMEnabled(bool enabled) { feature_states_[kCSSColorTypedOMFlagIndex] = enabled; }
  static void SetCSSContainerProgressNotationEnabled(bool enabled) { feature_states_[kCSSContainerProgressNotationFlagIndex] = enabled; }
  static void SetCSSContainerStyleQueriesRangeEnabled(bool enabled) { feature_states_[kCSSContainerStyleQueriesRangeFlagIndex] = enabled; }
  static void SetCSSContrastColorEnabled(bool enabled) { feature_states_[kCSSContrastColorFlagIndex] = enabled; }
  static void SetCSSCornersShorthandEnabled(bool enabled) { feature_states_[kCSSCornersShorthandFlagIndex] = enabled; }
  static void SetCSSCounterResetReversedEnabled(bool enabled) { feature_states_[kCSSCounterResetReversedFlagIndex] = enabled; }
  static void SetCSSCounterStyleSymbolsFunctionEnabled(bool enabled) { feature_states_[kCSSCounterStyleSymbolsFunctionFlagIndex] = enabled; }
  static void SetCSSCrossFadeEnabled(bool enabled) { feature_states_[kCSSCrossFadeFlagIndex] = enabled; }
  static void SetCSSCustomHighlightUniversalSelectorEnabled(bool enabled) { feature_states_[kCSSCustomHighlightUniversalSelectorFlagIndex] = enabled; }
  static void SetCSSCustomMediaEnabled(bool enabled) { feature_states_[kCSSCustomMediaFlagIndex] = enabled; }
  static void SetCSSDynamicRangeLimitEnabled(bool enabled) { feature_states_[kCSSDynamicRangeLimitFlagIndex] = enabled; }
  static void SetCSSEnumeratedCustomPropertiesEnabled(bool enabled) { feature_states_[kCSSEnumeratedCustomPropertiesFlagIndex] = enabled; }
  static void SetCSSFlowStartAndEndEnabled(bool enabled) { feature_states_[kCSSFlowStartAndEndFlagIndex] = enabled; }
  static void SetCSSFontFamilySerializationEnabled(bool enabled) { feature_states_[kCSSFontFamilySerializationFlagIndex] = enabled; }
  static void SetCSSFontSizeAdjustEnabled(bool enabled) { feature_states_[kCSSFontSizeAdjustFlagIndex] = enabled; }
  static void SetCSSFunctionsEnabled(bool enabled) { feature_states_[kCSSFunctionsFlagIndex] = enabled; }
  static void SetCSSGridLanesLayoutEnabled(bool enabled) { feature_states_[kCSSGridLanesLayoutFlagIndex] = enabled; }
  static void SetCSSHangingPunctuationEnabled(bool enabled) { feature_states_[kCSSHangingPunctuationFlagIndex] = enabled; }
  static void SetCSSHexAlphaColorEnabled(bool enabled) { feature_states_[kCSSHexAlphaColorFlagIndex] = enabled; }
  static void SetCSSIdentFunctionEnabled(bool enabled) { feature_states_[kCSSIdentFunctionFlagIndex] = enabled; }
  static void SetCSSImageAnimationEnabled(bool enabled) { feature_states_[kCSSImageAnimationFlagIndex] = enabled; }
  static void SetCSSImageFunctionEnabled(bool enabled) { feature_states_[kCSSImageFunctionFlagIndex] = enabled; }
  static void SetCSSInheritFunctionEnabled(bool enabled) { feature_states_[kCSSInheritFunctionFlagIndex] = enabled; }
  static void SetCSSInRangeOutOfRangeReversedRangesEnabled(bool enabled) { feature_states_[kCSSInRangeOutOfRangeReversedRangesFlagIndex] = enabled; }
  static void SetCSSKeyframesRuleLengthEnabled(bool enabled) { feature_states_[kCSSKeyframesRuleLengthFlagIndex] = enabled; }
  static void SetCSSLangExtendedRangesEnabled(bool enabled) { feature_states_[kCSSLangExtendedRangesFlagIndex] = enabled; }
  static void SetCSSLayoutAPIEnabled(bool enabled) { feature_states_[kCSSLayoutAPIFlagIndex] = enabled; }
  static void SetCSSLetterAndWordSpacingPercentageEnabled(bool enabled) { feature_states_[kCSSLetterAndWordSpacingPercentageFlagIndex] = enabled; }
  static void SetCSSLightDarkImageEnabled(bool enabled) { feature_states_[kCSSLightDarkImageFlagIndex] = enabled; }
  static void SetCSSLineClampEnabled(bool enabled) { feature_states_[kCSSLineClampFlagIndex] = enabled; }
  static void SetCSSLineClampAsShorthandEnabled(bool enabled) { feature_states_[kCSSLineClampAsShorthandFlagIndex] = enabled; }
  static void SetCSSLineClampLineBreakingEllipsisEnabled(bool enabled) { feature_states_[kCSSLineClampLineBreakingEllipsisFlagIndex] = enabled; }
  static void SetCSSListCounterAccountingEnabled(bool enabled) { feature_states_[kCSSListCounterAccountingFlagIndex] = enabled; }
  static void SetCSSLogicalCombinationPseudoEnabled(bool enabled) { feature_states_[kCSSLogicalCombinationPseudoFlagIndex] = enabled; }
  static void SetCSSMarkerNestedPseudoElementEnabled(bool enabled) { feature_states_[kCSSMarkerNestedPseudoElementFlagIndex] = enabled; }
  static void SetCssMaxContentSizingEnabled(bool enabled) { feature_states_[kCssMaxContentSizingFlagIndex] = enabled; }
  static void SetCSSMediaElementPseudosEnabled(bool enabled) { feature_states_[kCSSMediaElementPseudosFlagIndex] = enabled; }
  static void SetCSSMediaProgressNotationEnabled(bool enabled) { feature_states_[kCSSMediaProgressNotationFlagIndex] = enabled; }
  static void SetCSSMixinsEnabled(bool enabled) { feature_states_[kCSSMixinsFlagIndex] = enabled; }
  static void SetCSSNestedPseudoElementsEnabled(bool enabled) { feature_states_[kCSSNestedPseudoElementsFlagIndex] = enabled; }
  static void SetCSSOMGetComputedStylePseudoElementRequiresColonEnabled(bool enabled) { feature_states_[kCSSOMGetComputedStylePseudoElementRequiresColonFlagIndex] = enabled; }
  static void SetCSSOverscrollBehaviorChainEnabled(bool enabled) { feature_states_[kCSSOverscrollBehaviorChainFlagIndex] = enabled; }
  static void SetCSSPaintAPIArgumentsEnabled(bool enabled) { feature_states_[kCSSPaintAPIArgumentsFlagIndex] = enabled; }
  static void SetCSSParserIgnoreCharsetForURLsEnabled(bool enabled) { feature_states_[kCSSParserIgnoreCharsetForURLsFlagIndex] = enabled; }
  static void SetCSSPolygonRoundingEnabled(bool enabled) { feature_states_[kCSSPolygonRoundingFlagIndex] = enabled; }
  static void SetCSSPositionStickyStaticScrollPositionEnabled(bool enabled) { feature_states_[kCSSPositionStickyStaticScrollPositionFlagIndex] = enabled; }
  static void SetCSSPrivateEnabled(bool enabled) { feature_states_[kCSSPrivateFlagIndex] = enabled; }
  static void SetCSSProgressNotationEnabled(bool enabled) { feature_states_[kCSSProgressNotationFlagIndex] = enabled; }
  static void SetCSSPseudoColumnEnabled(bool enabled) { feature_states_[kCSSPseudoColumnFlagIndex] = enabled; }
  static void SetCSSPseudoElementBackdropEnabled(bool enabled) { feature_states_[kCSSPseudoElementBackdropFlagIndex] = enabled; }
  static void SetCSSPseudoElementInterfaceEnabled(bool enabled) { feature_states_[kCSSPseudoElementInterfaceFlagIndex] = enabled; }
  static void SetCSSPseudoElementViewTransitionsEnabled(bool enabled) { feature_states_[kCSSPseudoElementViewTransitionsFlagIndex] = enabled; }
  static void SetCSSPseudoHasSlottedEnabled(bool enabled) { feature_states_[kCSSPseudoHasSlottedFlagIndex] = enabled; }
  static void SetCSSPseudoScrollButtonsEnabled(bool enabled) { feature_states_[kCSSPseudoScrollButtonsFlagIndex] = enabled; }
  static void SetCSSPseudoScrollMarkersEnabled(bool enabled) { feature_states_[kCSSPseudoScrollMarkersFlagIndex] = enabled; }
  static void SetCSSRandomFunctionEnabled(bool enabled) { feature_states_[kCSSRandomFunctionFlagIndex] = enabled; }
  static void SetCSSRandomFunctionTypedOMEnabled(bool enabled) { feature_states_[kCSSRandomFunctionTypedOMFlagIndex] = enabled; }
  static void SetCSSResizeAutoEnabled(bool enabled) { feature_states_[kCSSResizeAutoFlagIndex] = enabled; }
  static void SetCSSResourceIntegrityEnforcementEnabled(bool enabled) { feature_states_[kCSSResourceIntegrityEnforcementFlagIndex] = enabled; }
  static void SetCSSRevertRuleEnabled(bool enabled) { feature_states_[kCSSRevertRuleFlagIndex] = enabled; }
  static void SetCSSRubyOverhangEnabled(bool enabled) { feature_states_[kCSSRubyOverhangFlagIndex] = enabled; }
  static void SetCSSSafePrintableInsetEnabled(bool enabled) { feature_states_[kCSSSafePrintableInsetFlagIndex] = enabled; }
  static void SetCSSScopeifiedParentPseudoClassEnabled(bool enabled) { feature_states_[kCSSScopeifiedParentPseudoClassFlagIndex] = enabled; }
  static void SetCSSScopeImportEnabled(bool enabled) { feature_states_[kCSSScopeImportFlagIndex] = enabled; }
  static void SetCSSScrolledContainerQueriesEnabled(bool enabled) { feature_states_[kCSSScrolledContainerQueriesFlagIndex] = enabled; }
  static void SetCSSScrollInitialTargetEnabled(bool enabled) { feature_states_[kCSSScrollInitialTargetFlagIndex] = enabled; }
  static void SetCSSScrollMarkerGroupModesEnabled(bool enabled) { feature_states_[kCSSScrollMarkerGroupModesFlagIndex] = enabled; }
  static void SetCSSScrollMarkerTargetBeforeAfterEnabled(bool enabled) { feature_states_[kCSSScrollMarkerTargetBeforeAfterFlagIndex] = enabled; }
  static void SetCSSScrollSnapChangeEventEnabled(bool enabled) { feature_states_[kCSSScrollSnapChangeEventFlagIndex] = enabled; }
  static void SetCSSScrollSnapChangingEventEnabled(bool enabled) { feature_states_[kCSSScrollSnapChangingEventFlagIndex] = enabled; }
  static void SetCSSScrollSnapEventConstructorExposedEnabled(bool enabled) { feature_states_[kCSSScrollSnapEventConstructorExposedFlagIndex] = enabled; }
  static void SetCSSScrollSnapEventsEnabled(bool enabled) { feature_states_[kCSSScrollSnapEventsFlagIndex] = enabled; }
  static void SetCSSScrollSnapStopBeforeEnabled(bool enabled) { feature_states_[kCSSScrollSnapStopBeforeFlagIndex] = enabled; }
  static void SetCSSScrollSnapTypePairEnabled(bool enabled) { feature_states_[kCSSScrollSnapTypePairFlagIndex] = enabled; }
  static void SetCSSScrollTargetGroupEnabled(bool enabled) { feature_states_[kCSSScrollTargetGroupFlagIndex] = enabled; }
  static void SetCSSScrollTargetGroupAriaCurrentEnabled(bool enabled) { feature_states_[kCSSScrollTargetGroupAriaCurrentFlagIndex] = enabled; }
  static void SetCSSShapeOutsidePathAndShapeSupportEnabled(bool enabled) { feature_states_[kCSSShapeOutsidePathAndShapeSupportFlagIndex] = enabled; }
  static void SetCSSShapeOutsideRectAndXywhSupportEnabled(bool enabled) { feature_states_[kCSSShapeOutsideRectAndXywhSupportFlagIndex] = enabled; }
  static void SetCSSStyleSheetInitBaseURLEnabled(bool enabled) { feature_states_[kCSSStyleSheetInitBaseURLFlagIndex] = enabled; }
  static void SetCSSSupportsAtRuleFunctionEnabled(bool enabled) { feature_states_[kCSSSupportsAtRuleFunctionFlagIndex] = enabled; }
  static void SetCSSSupportsForImportRulesEnabled(bool enabled) { feature_states_[kCSSSupportsForImportRulesFlagIndex] = enabled; }
  static void SetCSSSupportsNamedFeatureFunctionEnabled(bool enabled) { feature_states_[kCSSSupportsNamedFeatureFunctionFlagIndex] = enabled; }
  static void SetCSSSystemAccentColorEnabled(bool enabled) { feature_states_[kCSSSystemAccentColorFlagIndex] = enabled; }
  static void SetCSSTextAlignMatchParentEnabled(bool enabled) { feature_states_[kCSSTextAlignMatchParentFlagIndex] = enabled; }
  static void SetCSSTextDecorationInsetEnabled(bool enabled) { feature_states_[kCSSTextDecorationInsetFlagIndex] = enabled; }
  static void SetCSSTextDecorationSkipInkAllEnabled(bool enabled) { feature_states_[kCSSTextDecorationSkipInkAllFlagIndex] = enabled; }
  static void SetCSSTextDecorationSkipSpacesEnabled(bool enabled) { feature_states_[kCSSTextDecorationSkipSpacesFlagIndex] = enabled; }
  static void SetCssTextFitEnabled(bool enabled) { feature_states_[kCssTextFitFlagIndex] = enabled; }
  static void SetCssTextFitReshapingEnabled(bool enabled) { feature_states_[kCssTextFitReshapingFlagIndex] = enabled; }
  static void SetCSSTextSpacingEnabled(bool enabled) { feature_states_[kCSSTextSpacingFlagIndex] = enabled; }
  static void SetCSSTextTransformFullSizeKanaEnabled(bool enabled) { feature_states_[kCSSTextTransformFullSizeKanaFlagIndex] = enabled; }
  static void SetCSSTextTransformFullWidthEnabled(bool enabled) { feature_states_[kCSSTextTransformFullWidthFlagIndex] = enabled; }
  static void SetCSSTextTransformMultiKeywordEnabled(bool enabled) { feature_states_[kCSSTextTransformMultiKeywordFlagIndex] = enabled; }
  static void SetCSSTimelineNameConflictResolutionEnabled(bool enabled) { feature_states_[kCSSTimelineNameConflictResolutionFlagIndex] = enabled; }
  static void SetCSSTimelineScopeAllEnabled(bool enabled) { feature_states_[kCSSTimelineScopeAllFlagIndex] = enabled; }
  static void SetCSSTimelineScopeGlobalEnabled(bool enabled) { feature_states_[kCSSTimelineScopeGlobalFlagIndex] = enabled; }
  static void SetCSSTypedArithmeticEnabled(bool enabled) { feature_states_[kCSSTypedArithmeticFlagIndex] = enabled; }
  static void SetCSSURLRequestModifiersEnabled(bool enabled) { feature_states_[kCSSURLRequestModifiersFlagIndex] = enabled; }
  static void SetCSSUserSelectContainEnabled(bool enabled) { feature_states_[kCSSUserSelectContainFlagIndex] = enabled; }
  static void SetCSSUserValidAndUserInvalidForRadioEnabled(bool enabled) { feature_states_[kCSSUserValidAndUserInvalidForRadioFlagIndex] = enabled; }
  static void SetCSSVideoDynamicRangeMediaQueriesEnabled(bool enabled) { feature_states_[kCSSVideoDynamicRangeMediaQueriesFlagIndex] = enabled; }
  static void SetCSSViewTransitionAutoNameEnabled(bool enabled) { feature_states_[kCSSViewTransitionAutoNameFlagIndex] = enabled; }
  static void SetCSSWindowDragEnabled(bool enabled) { feature_states_[kCSSWindowDragFlagIndex] = enabled; }
  static void SetCSSZoomAnimationEnabled(bool enabled) { feature_states_[kCSSZoomAnimationFlagIndex] = enabled; }
  static void SetCustomElementsDisableFormattingFixupsEnabled(bool enabled) { feature_states_[kCustomElementsDisableFormattingFixupsFlagIndex] = enabled; }
  static void SetCustomizableComboboxEnabled(bool enabled) { feature_states_[kCustomizableComboboxFlagIndex] = enabled; }
  static void SetCustomizableSelectMultiplePopupEnabled(bool enabled) { feature_states_[kCustomizableSelectMultiplePopupFlagIndex] = enabled; }
  static void SetCustomScrollbarApplyMinimumThumbLengthEnabled(bool enabled) { feature_states_[kCustomScrollbarApplyMinimumThumbLengthFlagIndex] = enabled; }
  static void SetDatabaseEnabled(bool enabled) { feature_states_[kDatabaseFlagIndex] = enabled; }
  static void SetDateTimeInputTypeEarlyAdvanceFixEnabled(bool enabled) { feature_states_[kDateTimeInputTypeEarlyAdvanceFixFlagIndex] = enabled; }
  static void SetDeclarativeCSSModulesEnabled(bool enabled) { feature_states_[kDeclarativeCSSModulesFlagIndex] = enabled; }
  static void SetDeclarativeCSSModulesStyleTagEnabled(bool enabled) { feature_states_[kDeclarativeCSSModulesStyleTagFlagIndex] = enabled; }
  static void SetDeclarativeFragmentEnabled(bool enabled) { feature_states_[kDeclarativeFragmentFlagIndex] = enabled; }
  static void SetDeclarativePerformanceObserverEnabled(bool enabled) { feature_states_[kDeclarativePerformanceObserverFlagIndex] = enabled; }
  static void SetDeclarativeSkeletonsEnabled(bool enabled) { feature_states_[kDeclarativeSkeletonsFlagIndex] = enabled; }
  static void SetDelegatesFocusTextControlInputFixEnabled(bool enabled) { feature_states_[kDelegatesFocusTextControlInputFixFlagIndex] = enabled; }
  static void SetDeprecateUnloadOptOutEnabled(bool enabled) { feature_states_[kDeprecateUnloadOptOutFlagIndex] = enabled; }
  static void SetDesktopCaptureDisableLocalEchoControlEnabled(bool enabled) { feature_states_[kDesktopCaptureDisableLocalEchoControlFlagIndex] = enabled; }
  static void SetDesktopPWAsAdditionalWindowingControlsEnabled(bool enabled) { feature_states_[kDesktopPWAsAdditionalWindowingControlsFlagIndex] = enabled; }
  static void SetDesktopPWAsAdditionalWindowingControlsOnMoveEnabled(bool enabled) { feature_states_[kDesktopPWAsAdditionalWindowingControlsOnMoveFlagIndex] = enabled; }
  static void SetDeviceAttributesEnabled(bool enabled) { feature_states_[kDeviceAttributesFlagIndex] = enabled; }
  static void SetDeviceOrientationRequestPermissionEnabled(bool enabled) { feature_states_[kDeviceOrientationRequestPermissionFlagIndex] = enabled; }
  static void SetDevicePostureEnabled(bool enabled) { feature_states_[kDevicePostureFlagIndex] = enabled; }
  static void SetDialogCloseWhenOpenRemovedEnabled(bool enabled) { feature_states_[kDialogCloseWhenOpenRemovedFlagIndex] = enabled; }
  static void SetDialogNewFocusBehaviorEnabled(bool enabled) { feature_states_[kDialogNewFocusBehaviorFlagIndex] = enabled; }
  static void SetDigitalCredentialsProtocolFilterEnabled(bool enabled) { feature_states_[kDigitalCredentialsProtocolFilterFlagIndex] = enabled; }
  static void SetDigitalGoodsEnabled(bool enabled) { feature_states_[kDigitalGoodsFlagIndex] = enabled; }
  static void SetDigitalGoodsV2_1Enabled(bool enabled) { feature_states_[kDigitalGoodsV2_1FlagIndex] = enabled; }
  static void SetDirectSocketsEnabled(bool enabled) { feature_states_[kDirectSocketsFlagIndex] = enabled; }
  static void SetDirectSocketsInServiceWorkersEnabled(bool enabled) { feature_states_[kDirectSocketsInServiceWorkersFlagIndex] = enabled; }
  static void SetDirectSocketsInSharedWorkersEnabled(bool enabled) { feature_states_[kDirectSocketsInSharedWorkersFlagIndex] = enabled; }
  static void SetDisableAnchorCenterOnAlignJustifyItemsEnabled(bool enabled) { feature_states_[kDisableAnchorCenterOnAlignJustifyItemsFlagIndex] = enabled; }
  static void SetDisableDifferentOriginSubframeDialogSuppressionEnabled(bool enabled) { feature_states_[kDisableDifferentOriginSubframeDialogSuppressionFlagIndex] = enabled; }
  static void SetDisableEllipsisWhenScrolledEnabled(bool enabled) { feature_states_[kDisableEllipsisWhenScrolledFlagIndex] = enabled; }
  static void SetDisableFormControlChangeEventDuringMutationEnabled(bool enabled) { feature_states_[kDisableFormControlChangeEventDuringMutationFlagIndex] = enabled; }
  static void SetDisconnectWebSocketOnBFCacheEnabled(bool enabled) { feature_states_[kDisconnectWebSocketOnBFCacheFlagIndex] = enabled; }
  static void SetDispatchHiddenVisibilityTransitionsEnabled(bool enabled) { feature_states_[kDispatchHiddenVisibilityTransitionsFlagIndex] = enabled; }
  static void SetDispatchSelectionchangeEventPerElementEnabled(bool enabled) { feature_states_[kDispatchSelectionchangeEventPerElementFlagIndex] = enabled; }
  static void SetDisplayContentsFocusableEnabled(bool enabled) { feature_states_[kDisplayContentsFocusableFlagIndex] = enabled; }
  static void SetDisplayCutoutAPIEnabled(bool enabled) { feature_states_[kDisplayCutoutAPIFlagIndex] = enabled; }
  static void SetDocumentCookieEnabled(bool enabled) { feature_states_[kDocumentCookieFlagIndex] = enabled; }
  static void SetDocumentDomainEnabled(bool enabled) { feature_states_[kDocumentDomainFlagIndex] = enabled; }
  static void SetDocumentIsolationPolicyEnabled(bool enabled) { feature_states_[kDocumentIsolationPolicyFlagIndex] = enabled; }
  static void SetDocumentNamedPropertiesIgnoreExposednessEnabled(bool enabled) { feature_states_[kDocumentNamedPropertiesIgnoreExposednessFlagIndex] = enabled; }
  static void SetDocumentOpenIframeUnloadEventsEnabled(bool enabled) { feature_states_[kDocumentOpenIframeUnloadEventsFlagIndex] = enabled; }
  static void SetDocumentOpenOriginAliasRemovalEnabled(bool enabled) { feature_states_[kDocumentOpenOriginAliasRemovalFlagIndex] = enabled; }
  static void SetDocumentOpenSandboxInheritanceRemovalEnabled(bool enabled) { feature_states_[kDocumentOpenSandboxInheritanceRemovalFlagIndex] = enabled; }
  static void SetDocumentPatchingEnabled(bool enabled) { feature_states_[kDocumentPatchingFlagIndex] = enabled; }
  static void SetDocumentPictureInPictureAPIEnabled(bool enabled) { feature_states_[kDocumentPictureInPictureAPIFlagIndex] = enabled; }
  static void SetDocumentPictureInPicturePreferInitialPlacementEnabled(bool enabled) { feature_states_[kDocumentPictureInPicturePreferInitialPlacementFlagIndex] = enabled; }
  static void SetDocumentPictureInPictureUserActivationEnabled(bool enabled) { feature_states_[kDocumentPictureInPictureUserActivationFlagIndex] = enabled; }
  static void SetDocumentPolicyDocumentDomainEnabled(bool enabled) { feature_states_[kDocumentPolicyDocumentDomainFlagIndex] = enabled; }
  static void SetDocumentPolicyExpectNoLinkedResourcesEnabled(bool enabled) { feature_states_[kDocumentPolicyExpectNoLinkedResourcesFlagIndex] = enabled; }
  static void SetDocumentPolicyIncludeJSCallStacksInCrashReportsEnabled(bool enabled) { feature_states_[kDocumentPolicyIncludeJSCallStacksInCrashReportsFlagIndex] = enabled; }
  static void SetDocumentPolicyInDedicatedWorkerEnabled(bool enabled) { feature_states_[kDocumentPolicyInDedicatedWorkerFlagIndex] = enabled; }
  static void SetDocumentPolicyJSProfilingModeEnabled(bool enabled) { feature_states_[kDocumentPolicyJSProfilingModeFlagIndex] = enabled; }
  static void SetDocumentPolicyNegotiationEnabled(bool enabled) { feature_states_[kDocumentPolicyNegotiationFlagIndex] = enabled; }
  static void SetDocumentPolicyNetworkEfficiencyGuardrailsEnabled(bool enabled) { feature_states_[kDocumentPolicyNetworkEfficiencyGuardrailsFlagIndex] = enabled; }
  static void SetDocumentPolicySyncXHREnabled(bool enabled) { feature_states_[kDocumentPolicySyncXHRFlagIndex] = enabled; }
  static void SetDocumentWriteEnabled(bool enabled) { feature_states_[kDocumentWriteFlagIndex] = enabled; }
  static void SetDOMParserXmlScriptAlreadyStartedEnabled(bool enabled) { feature_states_[kDOMParserXmlScriptAlreadyStartedFlagIndex] = enabled; }
  static void SetDragAndDropDownloadURLListEnabled(bool enabled) { feature_states_[kDragAndDropDownloadURLListFlagIndex] = enabled; }
  static void SetDragAndDropJSFileObjectsEnabled(bool enabled) { feature_states_[kDragAndDropJSFileObjectsFlagIndex] = enabled; }
  static void SetDragImageForLargeImagesEnabled(bool enabled) { feature_states_[kDragImageForLargeImagesFlagIndex] = enabled; }
  static void SetDumpForAbsentKeyframeSnapshotsEnabled(bool enabled) { feature_states_[kDumpForAbsentKeyframeSnapshotsFlagIndex] = enabled; }
  static void SetEditContextAssignmentAsPerSpecEnabled(bool enabled) { feature_states_[kEditContextAssignmentAsPerSpecFlagIndex] = enabled; }
  static void SetEditContextHandleTextOrSelectionUpdateDuringCompositionEnabled(bool enabled) { feature_states_[kEditContextHandleTextOrSelectionUpdateDuringCompositionFlagIndex] = enabled; }
  static void SetEditContextSelectionUpdateBeforeTextUpdateEventEnabled(bool enabled) { feature_states_[kEditContextSelectionUpdateBeforeTextUpdateEventFlagIndex] = enabled; }
  static void SetEditingUseDomPositionApiEnabled(bool enabled) { feature_states_[kEditingUseDomPositionApiFlagIndex] = enabled; }
  static void SetElasticOverscrollBackgroundPaintLocationFixEnabled(bool enabled) { feature_states_[kElasticOverscrollBackgroundPaintLocationFixFlagIndex] = enabled; }
  static void SetElasticOverscrollUseEventDeltaForAxisSelectionEnabled(bool enabled) { feature_states_[kElasticOverscrollUseEventDeltaForAxisSelectionFlagIndex] = enabled; }
  static void SetElementCanvasTransformEnabled(bool enabled) { feature_states_[kElementCanvasTransformFlagIndex] = enabled; }
  static void SetElementCaptureEnabled(bool enabled) { feature_states_[kElementCaptureFlagIndex] = enabled; }
  static void SetElementInternalsBehaviorsEnabled(bool enabled) { feature_states_[kElementInternalsBehaviorsFlagIndex] = enabled; }
  static void SetElementMatchContainerEnabled(bool enabled) { feature_states_[kElementMatchContainerFlagIndex] = enabled; }
  static void SetElementSpecificReadOnlyConstraintValidationEnabled(bool enabled) { feature_states_[kElementSpecificReadOnlyConstraintValidationFlagIndex] = enabled; }
  static void SetEmailVerificationProtocolEnabled(bool enabled) { feature_states_[kEmailVerificationProtocolFlagIndex] = enabled; }
  static void SetEmailVerificationStatusIndicatorEnabled(bool enabled) { feature_states_[kEmailVerificationStatusIndicatorFlagIndex] = enabled; }
  static void SetEmbeddedContentCenterAlignBaselineEnabled(bool enabled) { feature_states_[kEmbeddedContentCenterAlignBaselineFlagIndex] = enabled; }
  static void SetEnableXSLTForCAPAlertsEnabled(bool enabled) { feature_states_[kEnableXSLTForCAPAlertsFlagIndex] = enabled; }
  static void SetEndpointInclusiveCommitStylesEnabled(bool enabled) { feature_states_[kEndpointInclusiveCommitStylesFlagIndex] = enabled; }
  static void SetEnforceAnonymityExposureEnabled(bool enabled) { feature_states_[kEnforceAnonymityExposureFlagIndex] = enabled; }
  static void SetEntropyIgnoredForFirstVideoFrameLCPEnabled(bool enabled) { feature_states_[kEntropyIgnoredForFirstVideoFrameLCPFlagIndex] = enabled; }
  static void SetEventPseudoTargetPropertyEnabled(bool enabled) { feature_states_[kEventPseudoTargetPropertyFlagIndex] = enabled; }
  static void SetEventTimingInteractionCountEnabled(bool enabled) { feature_states_[kEventTimingInteractionCountFlagIndex] = enabled; }
  static void SetEventTimingMatchingHTMLEnabled(bool enabled) { feature_states_[kEventTimingMatchingHTMLFlagIndex] = enabled; }
  static void SetEventTimingTargetSelectorEnabled(bool enabled) { feature_states_[kEventTimingTargetSelectorFlagIndex] = enabled; }
  static void SetEventTriggerEnabled(bool enabled) { feature_states_[kEventTriggerFlagIndex] = enabled; }
  static void SetExperimentalContentSecurityPolicyFeaturesEnabled(bool enabled) { feature_states_[kExperimentalContentSecurityPolicyFeaturesFlagIndex] = enabled; }
  static void SetExperimentalJSProfilerMarkersEnabled(bool enabled) { feature_states_[kExperimentalJSProfilerMarkersFlagIndex] = enabled; }
  static void SetExperimentalMachineLearningNeuralNetworkEnabled(bool enabled) { feature_states_[kExperimentalMachineLearningNeuralNetworkFlagIndex] = enabled; }
  static void SetExperimentalPoliciesEnabled(bool enabled) { feature_states_[kExperimentalPoliciesFlagIndex] = enabled; }
  static void SetExposeCSSFontFeatureValuesRuleEnabled(bool enabled) { feature_states_[kExposeCSSFontFeatureValuesRuleFlagIndex] = enabled; }
  static void SetExposeRenderTimeNonTaoDelayedImageEnabled(bool enabled) { feature_states_[kExposeRenderTimeNonTaoDelayedImageFlagIndex] = enabled; }
  static void SetExtendedTextMetricsEnabled(bool enabled) { feature_states_[kExtendedTextMetricsFlagIndex] = enabled; }
  static void SetExtensionScriptTaggingEnabled(bool enabled) { feature_states_[kExtensionScriptTaggingFlagIndex] = enabled; }
  static void SetExtensionScriptTaggingTestingAPIEnabled(bool enabled) { feature_states_[kExtensionScriptTaggingTestingAPIFlagIndex] = enabled; }
  static void SetExternalPopupMenuClickEventEnabled(bool enabled) { feature_states_[kExternalPopupMenuClickEventFlagIndex] = enabled; }
  static void SetEyeDropperAPIEnabled(bool enabled) { feature_states_[kEyeDropperAPIFlagIndex] = enabled; }
  static void SetFaceDetectorEnabled(bool enabled) { feature_states_[kFaceDetectorFlagIndex] = enabled; }
  static void SetFastPositionIteratorEnabled(bool enabled) { feature_states_[kFastPositionIteratorFlagIndex] = enabled; }
  static void SetFedCmEnabled(bool enabled) { feature_states_[kFedCmFlagIndex] = enabled; }
  static void SetFedCmActiveModeMultipleIdentityProvidersEnabled(bool enabled) { feature_states_[kFedCmActiveModeMultipleIdentityProvidersFlagIndex] = enabled; }
  static void SetFedCmAutofillEnabled(bool enabled) { feature_states_[kFedCmAutofillFlagIndex] = enabled; }
  static void SetFedCmDelegationEnabled(bool enabled) { feature_states_[kFedCmDelegationFlagIndex] = enabled; }
  static void SetFedCmIdentityHandlerEnabled(bool enabled) { feature_states_[kFedCmIdentityHandlerFlagIndex] = enabled; }
  static void SetFedCmIdPRegistrationEnabled(bool enabled) { feature_states_[kFedCmIdPRegistrationFlagIndex] = enabled; }
  static void SetFedCmLightweightModeEnabled(bool enabled) { feature_states_[kFedCmLightweightModeFlagIndex] = enabled; }
  static void SetFedCmMultipleIdentityProvidersEnabled(bool enabled) { feature_states_[kFedCmMultipleIdentityProvidersFlagIndex] = enabled; }
  static void SetFedCmMultipleRequestsEnabled(bool enabled) { feature_states_[kFedCmMultipleRequestsFlagIndex] = enabled; }
  static void SetFedCmNavigationInterceptionEnabled(bool enabled) { feature_states_[kFedCmNavigationInterceptionFlagIndex] = enabled; }
  static void SetFencedFramesEnabled(bool enabled) { feature_states_[kFencedFramesFlagIndex] = enabled; }
  static void SetFencedFramesAPIChangesEnabled(bool enabled) { feature_states_[kFencedFramesAPIChangesFlagIndex] = enabled; }
  static void SetFencedFramesLocalUnpartitionedDataAccessEnabled(bool enabled) { feature_states_[kFencedFramesLocalUnpartitionedDataAccessFlagIndex] = enabled; }
  static void SetFetchBodyBytesEnabled(bool enabled) { feature_states_[kFetchBodyBytesFlagIndex] = enabled; }
  static void SetFetchLaterAPIEnabled(bool enabled) { feature_states_[kFetchLaterAPIFlagIndex] = enabled; }
  static void SetFetchRetryEnabled(bool enabled) { feature_states_[kFetchRetryFlagIndex] = enabled; }
  static void SetFetchUploadStreamingEnabled(bool enabled) { feature_states_[kFetchUploadStreamingFlagIndex] = enabled; }
  static void SetFileColorPickerConsumeActivationEnabled(bool enabled) { feature_states_[kFileColorPickerConsumeActivationFlagIndex] = enabled; }
  static void SetFileHandlingEnabled(bool enabled) { feature_states_[kFileHandlingFlagIndex] = enabled; }
  static void SetFilePickerEventsFixEnabled(bool enabled) { feature_states_[kFilePickerEventsFixFlagIndex] = enabled; }
  static void SetFileSystemEnabled(bool enabled) { feature_states_[kFileSystemFlagIndex] = enabled; }
  static void SetFileSystemAccessEnabled(bool enabled) { feature_states_[kFileSystemAccessFlagIndex] = enabled; }
  static void SetFileSystemAccessAPIExperimentalEnabled(bool enabled) { feature_states_[kFileSystemAccessAPIExperimentalFlagIndex] = enabled; }
  static void SetFileSystemAccessGetCloudIdentifiersEnabled(bool enabled) { feature_states_[kFileSystemAccessGetCloudIdentifiersFlagIndex] = enabled; }
  static void SetFileSystemAccessLocalEnabled(bool enabled) { feature_states_[kFileSystemAccessLocalFlagIndex] = enabled; }
  static void SetFileSystemAccessLockingSchemeEnabled(bool enabled) { feature_states_[kFileSystemAccessLockingSchemeFlagIndex] = enabled; }
  static void SetFileSystemAccessOriginPrivateEnabled(bool enabled) { feature_states_[kFileSystemAccessOriginPrivateFlagIndex] = enabled; }
  static void SetFileSystemAccessRevokeReadOnRemoveEnabled(bool enabled) { feature_states_[kFileSystemAccessRevokeReadOnRemoveFlagIndex] = enabled; }
  static void SetFileSystemAccessWriteModeEnabled(bool enabled) { feature_states_[kFileSystemAccessWriteModeFlagIndex] = enabled; }
  static void SetFileSystemObserverEnabled(bool enabled) { feature_states_[kFileSystemObserverFlagIndex] = enabled; }
  static void SetFileSystemObserverUnobserveEnabled(bool enabled) { feature_states_[kFileSystemObserverUnobserveFlagIndex] = enabled; }
  static void SetFilterableSelectEnabled(bool enabled) { feature_states_[kFilterableSelectFlagIndex] = enabled; }
  static void SetFilterContainerLevelStylesEnabled(bool enabled) { feature_states_[kFilterContainerLevelStylesFlagIndex] = enabled; }
  static void SetFilteringPrimitivesEnabled(bool enabled) { feature_states_[kFilteringPrimitivesFlagIndex] = enabled; }
  static void SetFindBufferCollapseSkippedSpaceEnabled(bool enabled) { feature_states_[kFindBufferCollapseSkippedSpaceFlagIndex] = enabled; }
  static void SetFindBufferMatchAcrossIgnoredNodesEnabled(bool enabled) { feature_states_[kFindBufferMatchAcrossIgnoredNodesFlagIndex] = enabled; }
  static void SetFindFirstMisspellingEndWhenNonEditableEnabled(bool enabled) { feature_states_[kFindFirstMisspellingEndWhenNonEditableFlagIndex] = enabled; }
  static void SetFindIgnoreSuggestionFixEnabled(bool enabled) { feature_states_[kFindIgnoreSuggestionFixFlagIndex] = enabled; }
  static void SetFirstLineTextMetricsEnabled(bool enabled) { feature_states_[kFirstLineTextMetricsFlagIndex] = enabled; }
  static void SetFixHTMLFormControlElementIsReadOnlyEnabled(bool enabled) { feature_states_[kFixHTMLFormControlElementIsReadOnlyFlagIndex] = enabled; }
  static void SetFixMapElementEmptyNameBugEnabled(bool enabled) { feature_states_[kFixMapElementEmptyNameBugFlagIndex] = enabled; }
  static void SetFixMarkerSuppressionForAppearanceAutoEnabled(bool enabled) { feature_states_[kFixMarkerSuppressionForAppearanceAutoFlagIndex] = enabled; }
  static void SetFixSelectionPaintRangeNullOptEnabled(bool enabled) { feature_states_[kFixSelectionPaintRangeNullOptFlagIndex] = enabled; }
  static void SetFixVisualRectRemoteViewportTransformEnabled(bool enabled) { feature_states_[kFixVisualRectRemoteViewportTransformFlagIndex] = enabled; }
  static void SetFledgeEnabled(bool enabled) { feature_states_[kFledgeFlagIndex] = enabled; }
  static void SetFledgeAuctionDealSupportEnabled(bool enabled) { feature_states_[kFledgeAuctionDealSupportFlagIndex] = enabled; }
  static void SetFledgeBiddingAndAuctionServerAPIEnabled(bool enabled) { feature_states_[kFledgeBiddingAndAuctionServerAPIFlagIndex] = enabled; }
  static void SetFledgeBiddingAndAuctionServerAPIMultiSellerEnabled(bool enabled) { feature_states_[kFledgeBiddingAndAuctionServerAPIMultiSellerFlagIndex] = enabled; }
  static void SetFledgeClickinessEnabled(bool enabled) { feature_states_[kFledgeClickinessFlagIndex] = enabled; }
  static void SetFledgeCustomMaxAuctionAdComponentsEnabled(bool enabled) { feature_states_[kFledgeCustomMaxAuctionAdComponentsFlagIndex] = enabled; }
  static void SetFledgeDeprecatedRenderURLReplacementsEnabled(bool enabled) { feature_states_[kFledgeDeprecatedRenderURLReplacementsFlagIndex] = enabled; }
  static void SetFledgeDirectFromSellerSignalsHeaderAdSlotEnabled(bool enabled) { feature_states_[kFledgeDirectFromSellerSignalsHeaderAdSlotFlagIndex] = enabled; }
  static void SetFledgeDirectFromSellerSignalsWebBundlesEnabled(bool enabled) { feature_states_[kFledgeDirectFromSellerSignalsWebBundlesFlagIndex] = enabled; }
  static void SetFledgeMultiBidEnabled(bool enabled) { feature_states_[kFledgeMultiBidFlagIndex] = enabled; }
  static void SetFledgePrivateModelTrainingEnabled(bool enabled) { feature_states_[kFledgePrivateModelTrainingFlagIndex] = enabled; }
  static void SetFledgeRealTimeReportingEnabled(bool enabled) { feature_states_[kFledgeRealTimeReportingFlagIndex] = enabled; }
  static void SetFledgeSellerNonceEnabled(bool enabled) { feature_states_[kFledgeSellerNonceFlagIndex] = enabled; }
  static void SetFledgeSellerScriptExecutionModeEnabled(bool enabled) { feature_states_[kFledgeSellerScriptExecutionModeFlagIndex] = enabled; }
  static void SetFledgeTrustedSignalsKVv1CreativeScanningEnabled(bool enabled) { feature_states_[kFledgeTrustedSignalsKVv1CreativeScanningFlagIndex] = enabled; }
  static void SetFledgeTrustedSignalsKVv2ContextualDataEnabled(bool enabled) { feature_states_[kFledgeTrustedSignalsKVv2ContextualDataFlagIndex] = enabled; }
  static void SetFledgeTrustedSignalsKVv2SupportEnabled(bool enabled) { feature_states_[kFledgeTrustedSignalsKVv2SupportFlagIndex] = enabled; }
  static void SetFlexWrapBalanceEnabled(bool enabled) { feature_states_[kFlexWrapBalanceFlagIndex] = enabled; }
  static void SetFocusgroupEnabled(bool enabled) { feature_states_[kFocusgroupFlagIndex] = enabled; }
  static void SetFocusgroupV2Enabled(bool enabled) { feature_states_[kFocusgroupV2FlagIndex] = enabled; }
  static void SetFocusRingRespectExplicitOutlineColorInDarkModeEnabled(bool enabled) { feature_states_[kFocusRingRespectExplicitOutlineColorInDarkModeFlagIndex] = enabled; }
  static void SetFontAccessEnabled(bool enabled) { feature_states_[kFontAccessFlagIndex] = enabled; }
  static void SetFontationsPrintingEnabled(bool enabled) { feature_states_[kFontationsPrintingFlagIndex] = enabled; }
  static void SetFontDataServiceForCSSLocalFontsEnabled(bool enabled) { feature_states_[kFontDataServiceForCSSLocalFontsFlagIndex] = enabled; }
  static void SetFontFallbackForTabSizeEnabled(bool enabled) { feature_states_[kFontFallbackForTabSizeFlagIndex] = enabled; }
  static void SetFontFamilyPostscriptMatchingCTMigrationEnabled(bool enabled) { feature_states_[kFontFamilyPostscriptMatchingCTMigrationFlagIndex] = enabled; }
  static void SetFontFamilyStyleMatchingCTMigrationEnabled(bool enabled) { feature_states_[kFontFamilyStyleMatchingCTMigrationFlagIndex] = enabled; }
  static void SetFontFeatureSettingsDescriptorEnabled(bool enabled) { feature_states_[kFontFeatureSettingsDescriptorFlagIndex] = enabled; }
  static void SetFontFormatAvar2Enabled(bool enabled) { feature_states_[kFontFormatAvar2FlagIndex] = enabled; }
  static void SetFontLanguageOverrideEnabled(bool enabled) { feature_states_[kFontLanguageOverrideFlagIndex] = enabled; }
  static void SetFontMatchAliasesAsLastResortEnabled(bool enabled) { feature_states_[kFontMatchAliasesAsLastResortFlagIndex] = enabled; }
  static void SetFontPrewarmerShutdownFallbackEnabled(bool enabled) { feature_states_[kFontPrewarmerShutdownFallbackFlagIndex] = enabled; }
  static void SetFontStyleObliqueZeroDegreeAsNormalEnabled(bool enabled) { feature_states_[kFontStyleObliqueZeroDegreeAsNormalFlagIndex] = enabled; }
  static void SetFontVariationSettingsDescriptorEnabled(bool enabled) { feature_states_[kFontVariationSettingsDescriptorFlagIndex] = enabled; }
  static void SetForcedColorsEnabled(bool enabled) { feature_states_[kForcedColorsFlagIndex] = enabled; }
  static void SetForceEagerMeasureMemoryEnabled(bool enabled) { feature_states_[kForceEagerMeasureMemoryFlagIndex] = enabled; }
  static void SetForceReduceMotionEnabled(bool enabled) { feature_states_[kForceReduceMotionFlagIndex] = enabled; }
  static void SetForwardReasonToFetchBodyAbortEnabled(bool enabled) { feature_states_[kForwardReasonToFetchBodyAbortFlagIndex] = enabled; }
  static void SetFractionalScrollOffsetsEnabled(bool enabled) { feature_states_[kFractionalScrollOffsetsFlagIndex] = enabled; }
  static void SetFractionalScrollOffsetsForWebAPIEnabled(bool enabled) { feature_states_[kFractionalScrollOffsetsForWebAPIFlagIndex] = enabled; }
  static void SetFragmentedOofInCbEnabled(bool enabled) { feature_states_[kFragmentedOofInCbFlagIndex] = enabled; }
  static void SetFrameSerializerNoWebEntitiesEnabled(bool enabled) { feature_states_[kFrameSerializerNoWebEntitiesFlagIndex] = enabled; }
  static void SetFreezeFramesOnVisibilityEnabled(bool enabled) { feature_states_[kFreezeFramesOnVisibilityFlagIndex] = enabled; }
  static void SetGamepadButtonTypesEnabled(bool enabled) { feature_states_[kGamepadButtonTypesFlagIndex] = enabled; }
  static void SetGamepadMultitouchEnabled(bool enabled) { feature_states_[kGamepadMultitouchFlagIndex] = enabled; }
  static void SetGamepadRawInputChangeEventEnabled(bool enabled) { feature_states_[kGamepadRawInputChangeEventFlagIndex] = enabled; }
  static void SetGamepadWindowEventHandlersEnabled(bool enabled) { feature_states_[kGamepadWindowEventHandlersFlagIndex] = enabled; }
  static void SetGenerateDragOverlayBeforeDragStartEnabled(bool enabled) { feature_states_[kGenerateDragOverlayBeforeDragStartFlagIndex] = enabled; }
  static void SetGenerateXSLTWarningBannerEnabled(bool enabled) { feature_states_[kGenerateXSLTWarningBannerFlagIndex] = enabled; }
  static void SetGeolocationElementEnabled(bool enabled) { feature_states_[kGeolocationElementFlagIndex] = enabled; }
  static void SetGeometryMapperSingularTransformFixEnabled(bool enabled) { feature_states_[kGeometryMapperSingularTransformFixFlagIndex] = enabled; }
  static void SetGeometryUtilsEnabled(bool enabled) { feature_states_[kGeometryUtilsFlagIndex] = enabled; }
  static void SetGeometryUtilsForCSSPseudoElementEnabled(bool enabled) { feature_states_[kGeometryUtilsForCSSPseudoElementFlagIndex] = enabled; }
  static void SetGetAllScreensMediaEnabled(bool enabled) { feature_states_[kGetAllScreensMediaFlagIndex] = enabled; }
  static void SetGetDisplayMediaEnabled(bool enabled) { feature_states_[kGetDisplayMediaFlagIndex] = enabled; }
  static void SetGetDisplayMediaAudioSelectionEnabled(bool enabled) { feature_states_[kGetDisplayMediaAudioSelectionFlagIndex] = enabled; }
  static void SetGetDisplayMediaRequiresUserActivationEnabled(bool enabled) { feature_states_[kGetDisplayMediaRequiresUserActivationFlagIndex] = enabled; }
  static void SetGetDisplayMediaWindowAudioCaptureEnabled(bool enabled) { feature_states_[kGetDisplayMediaWindowAudioCaptureFlagIndex] = enabled; }
  static void SetGetElementsByNameOnlyHTMLElementsEnabled(bool enabled) { feature_states_[kGetElementsByNameOnlyHTMLElementsFlagIndex] = enabled; }
  static void SetGetUserMediaEchoCancellationModesEnabled(bool enabled) { feature_states_[kGetUserMediaEchoCancellationModesFlagIndex] = enabled; }
  static void SetGlobalPrivacyControlEnabled(bool enabled) { feature_states_[kGlobalPrivacyControlFlagIndex] = enabled; }
  static void SetGlobalPrivacyControlForceEnabled(bool enabled) { feature_states_[kGlobalPrivacyControlForceFlagIndex] = enabled; }
  static void SetGlobalPrivacyControlTestEnabled(bool enabled) { feature_states_[kGlobalPrivacyControlTestFlagIndex] = enabled; }
  static void SetGraphemeClusterBoundsCheckEnabled(bool enabled) { feature_states_[kGraphemeClusterBoundsCheckFlagIndex] = enabled; }
  static void SetGroupEffectEnabled(bool enabled) { feature_states_[kGroupEffectFlagIndex] = enabled; }
  static void SetHandleShadowDOMInSubstringUtilEnabled(bool enabled) { feature_states_[kHandleShadowDOMInSubstringUtilFlagIndex] = enabled; }
  static void SetHandwritingRecognitionEnabled(bool enabled) { feature_states_[kHandwritingRecognitionFlagIndex] = enabled; }
  static void SetHarfRustShapingEnabled(bool enabled) { feature_states_[kHarfRustShapingFlagIndex] = enabled; }
  static void SetHasUAVisualTransitionEnabled(bool enabled) { feature_states_[kHasUAVisualTransitionFlagIndex] = enabled; }
  static void SetHeadingOffsetEnabled(bool enabled) { feature_states_[kHeadingOffsetFlagIndex] = enabled; }
  static void SetHideVideoControlsWhenUnneededEnabled(bool enabled) { feature_states_[kHideVideoControlsWhenUnneededFlagIndex] = enabled; }
  static void SetHighlightsFromPointEnabled(bool enabled) { feature_states_[kHighlightsFromPointFlagIndex] = enabled; }
  static void SetHitTestBorderRadiusForStackingContextEnabled(bool enabled) { feature_states_[kHitTestBorderRadiusForStackingContextFlagIndex] = enabled; }
  static void SetHitTestContainerTransformStateForPreserve3dEnabled(bool enabled) { feature_states_[kHitTestContainerTransformStateForPreserve3dFlagIndex] = enabled; }
  static void SetHrefTranslateEnabled(bool enabled) { feature_states_[kHrefTranslateFlagIndex] = enabled; }
  static void SetHstsTopLevelNavigationsOnlyEnabled(bool enabled) { feature_states_[kHstsTopLevelNavigationsOnlyFlagIndex] = enabled; }
  static void SetHTMLAdoptionAlgorithmNewStepsEnabled(bool enabled) { feature_states_[kHTMLAdoptionAlgorithmNewStepsFlagIndex] = enabled; }
  static void SetHTMLAreaElementDisplayNoneEnabled(bool enabled) { feature_states_[kHTMLAreaElementDisplayNoneFlagIndex] = enabled; }
  static void SetHTMLAreaHreflangTypeEnabled(bool enabled) { feature_states_[kHTMLAreaHreflangTypeFlagIndex] = enabled; }
  static void SetHTMLBodyMarginPixelLengthEnabled(bool enabled) { feature_states_[kHTMLBodyMarginPixelLengthFlagIndex] = enabled; }
  static void SetHTMLCommandActionsV2Enabled(bool enabled) { feature_states_[kHTMLCommandActionsV2FlagIndex] = enabled; }
  static void SetHTMLCommandElementRemovalEnabled(bool enabled) { feature_states_[kHTMLCommandElementRemovalFlagIndex] = enabled; }
  static void SetHTMLCommandForScrollCommandsEnabled(bool enabled) { feature_states_[kHTMLCommandForScrollCommandsFlagIndex] = enabled; }
  static void SetHTMLElementScrollParentEnabled(bool enabled) { feature_states_[kHTMLElementScrollParentFlagIndex] = enabled; }
  static void SetHTMLInputElementDropWebkitClearButtonEnabled(bool enabled) { feature_states_[kHTMLInputElementDropWebkitClearButtonFlagIndex] = enabled; }
  static void SetHTMLInterestForInterestButtonPseudoEnabled(bool enabled) { feature_states_[kHTMLInterestForInterestButtonPseudoFlagIndex] = enabled; }
  static void SetHTMLLinkElementAttributeValueChangesEnabled(bool enabled) { feature_states_[kHTMLLinkElementAttributeValueChangesFlagIndex] = enabled; }
  static void SetHTMLParserTruncatedMarkupDeclarationEnabled(bool enabled) { feature_states_[kHTMLParserTruncatedMarkupDeclarationFlagIndex] = enabled; }
  static void SetHTMLParserYieldAndDelayOftenForTestingEnabled(bool enabled) { feature_states_[kHTMLParserYieldAndDelayOftenForTestingFlagIndex] = enabled; }
  static void SetHTMLParserYieldByUserTimingEnabled(bool enabled) { feature_states_[kHTMLParserYieldByUserTimingFlagIndex] = enabled; }
  static void SetHTMLPrintingArtifactAnnotationsEnabled(bool enabled) { feature_states_[kHTMLPrintingArtifactAnnotationsFlagIndex] = enabled; }
  static void SetHTMLProcessingInstructionEnabled(bool enabled) { feature_states_[kHTMLProcessingInstructionFlagIndex] = enabled; }
  static void SetHTMLSwitchAttributeEnabled(bool enabled) { feature_states_[kHTMLSwitchAttributeFlagIndex] = enabled; }
  static void SetICUCapitalizationEnabled(bool enabled) { feature_states_[kICUCapitalizationFlagIndex] = enabled; }
  static void SetIgnoreLetterSpacingInCursiveScriptsEnabled(bool enabled) { feature_states_[kIgnoreLetterSpacingInCursiveScriptsFlagIndex] = enabled; }
  static void SetImageDataPixelFormatEnabled(bool enabled) { feature_states_[kImageDataPixelFormatFlagIndex] = enabled; }
  static void SetImageDocumentUseLayoutWidthEnabled(bool enabled) { feature_states_[kImageDocumentUseLayoutWidthFlagIndex] = enabled; }
  static void SetImageSrcsetReselectionEnabled(bool enabled) { feature_states_[kImageSrcsetReselectionFlagIndex] = enabled; }
  static void SetImplicitRootScrollerEnabled(bool enabled) { feature_states_[kImplicitRootScrollerFlagIndex] = enabled; }
  static void SetIncomingCallNotificationsEnabled(bool enabled) { feature_states_[kIncomingCallNotificationsFlagIndex] = enabled; }
  static void SetIncrementalFontTransferEnabled(bool enabled) { feature_states_[kIncrementalFontTransferFlagIndex] = enabled; }
  static void SetInertElementNonEditableEnabled(bool enabled) { feature_states_[kInertElementNonEditableFlagIndex] = enabled; }
  static void SetInfiniteCullRectEnabled(bool enabled) { feature_states_[kInfiniteCullRectFlagIndex] = enabled; }
  static void SetInheritUserModifyWithoutContenteditableEnabled(bool enabled) { feature_states_[kInheritUserModifyWithoutContenteditableFlagIndex] = enabled; }
  static void SetInlineBlockLineNavigationEnabled(bool enabled) { feature_states_[kInlineBlockLineNavigationFlagIndex] = enabled; }
  static void SetInlineCursorSkipNonIfcEnabled(bool enabled) { feature_states_[kInlineCursorSkipNonIfcFlagIndex] = enabled; }
  static void SetInlineScriptCacheHintEnabled(bool enabled) { feature_states_[kInlineScriptCacheHintFlagIndex] = enabled; }
  static void SetInnerHTMLParserFastpathLogFailureEnabled(bool enabled) { feature_states_[kInnerHTMLParserFastpathLogFailureFlagIndex] = enabled; }
  static void SetInputDisabledHandlerFixEnabled(bool enabled) { feature_states_[kInputDisabledHandlerFixFlagIndex] = enabled; }
  static void SetInputInSelectEnabled(bool enabled) { feature_states_[kInputInSelectFlagIndex] = enabled; }
  static void SetInputMultipleFieldsUIEnabled(bool enabled) { feature_states_[kInputMultipleFieldsUIFlagIndex] = enabled; }
  static void SetInputMultipleFieldsUIWithPointerChecksEnabled(bool enabled) { feature_states_[kInputMultipleFieldsUIWithPointerChecksFlagIndex] = enabled; }
  static void SetInputTypeColorEnhancementsEnabled(bool enabled) { feature_states_[kInputTypeColorEnhancementsFlagIndex] = enabled; }
  static void SetInsertBlockquoteBeforeOuterBlockEnabled(bool enabled) { feature_states_[kInsertBlockquoteBeforeOuterBlockFlagIndex] = enabled; }
  static void SetInstalledAppEnabled(bool enabled) { feature_states_[kInstalledAppFlagIndex] = enabled; }
  static void SetInstallElementEnabled(bool enabled) { feature_states_[kInstallElementFlagIndex] = enabled; }
  static void SetInstallOnDeviceSpeechRecognitionEnabled(bool enabled) { feature_states_[kInstallOnDeviceSpeechRecognitionFlagIndex] = enabled; }
  static void SetIntegrityPolicyScriptEnabled(bool enabled) { feature_states_[kIntegrityPolicyScriptFlagIndex] = enabled; }
  static void SetInterestEventsNonComposedEnabled(bool enabled) { feature_states_[kInterestEventsNonComposedFlagIndex] = enabled; }
  static void SetInterestGroupsInSharedStorageWorkletEnabled(bool enabled) { feature_states_[kInterestGroupsInSharedStorageWorkletFlagIndex] = enabled; }
  static void SetIntersectionObserverCompositedAnimationsForceMainFramesEnabled(bool enabled) { feature_states_[kIntersectionObserverCompositedAnimationsForceMainFramesFlagIndex] = enabled; }
  static void SetInvertedColorsEnabled(bool enabled) { feature_states_[kInvertedColorsFlagIndex] = enabled; }
  static void SetInvisibleSVGAnimationThrottlingEnabled(bool enabled) { feature_states_[kInvisibleSVGAnimationThrottlingFlagIndex] = enabled; }
  static void SetJavaScriptCompileHintsPerFunctionMagicRuntimeEnabled(bool enabled) { feature_states_[kJavaScriptCompileHintsPerFunctionMagicRuntimeFlagIndex] = enabled; }
  static void SetJavaScriptImportTextEnabled(bool enabled) { feature_states_[kJavaScriptImportTextFlagIndex] = enabled; }
  static void SetJavaScriptSourcePhaseImportsEnabled(bool enabled) { feature_states_[kJavaScriptSourcePhaseImportsFlagIndex] = enabled; }
  static void SetKeyboardAccessibleTooltipEnabled(bool enabled) { feature_states_[kKeyboardAccessibleTooltipFlagIndex] = enabled; }
  static void SetKeySystemTrackConfigurationEncryptionSchemeEnabled(bool enabled) { feature_states_[kKeySystemTrackConfigurationEncryptionSchemeFlagIndex] = enabled; }
  static void SetLabelInteractiveContentCheckBeforeHandlerEnabled(bool enabled) { feature_states_[kLabelInteractiveContentCheckBeforeHandlerFlagIndex] = enabled; }
  static void SetLangAttributeAwareFormControlUIEnabled(bool enabled) { feature_states_[kLangAttributeAwareFormControlUIFlagIndex] = enabled; }
  static void SetLanguageDetectionAPIEnabled(bool enabled) { feature_states_[kLanguageDetectionAPIFlagIndex] = enabled; }
  static void SetLanguageDetectionAPIForWorkersEnabled(bool enabled) { feature_states_[kLanguageDetectionAPIForWorkersFlagIndex] = enabled; }
  static void SetLayoutIgnoreMarginsForStickyEnabled(bool enabled) { feature_states_[kLayoutIgnoreMarginsForStickyFlagIndex] = enabled; }
  static void SetLayoutOOFCollectInlinesFixEnabled(bool enabled) { feature_states_[kLayoutOOFCollectInlinesFixFlagIndex] = enabled; }
  static void SetLayoutTableCellAlignmentSafeEnabled(bool enabled) { feature_states_[kLayoutTableCellAlignmentSafeFlagIndex] = enabled; }
  static void SetLazyImageConformantLoadEventTimingEnabled(bool enabled) { feature_states_[kLazyImageConformantLoadEventTimingFlagIndex] = enabled; }
  static void SetLazyLoadVideoAndAudioEnabled(bool enabled) { feature_states_[kLazyLoadVideoAndAudioFlagIndex] = enabled; }
  static void SetLeftClickToHandleSuggestionEnabled(bool enabled) { feature_states_[kLeftClickToHandleSuggestionFlagIndex] = enabled; }
  static void SetLegacyAbstractRangeEnabled(bool enabled) { feature_states_[kLegacyAbstractRangeFlagIndex] = enabled; }
  static void SetLightDismissFromClickEnabled(bool enabled) { feature_states_[kLightDismissFromClickFlagIndex] = enabled; }
  static void SetLineBreakAfterSpaceBeforeOpenTagEnabled(bool enabled) { feature_states_[kLineBreakAfterSpaceBeforeOpenTagFlagIndex] = enabled; }
  static void SetLineBreakBidiControlEnterEnabled(bool enabled) { feature_states_[kLineBreakBidiControlEnterFlagIndex] = enabled; }
  static void SetLineBreakerHanKerningEndEnabled(bool enabled) { feature_states_[kLineBreakerHanKerningEndFlagIndex] = enabled; }
  static void SetListOwnerMustHaveCSSBoxEnabled(bool enabled) { feature_states_[kListOwnerMustHaveCSSBoxFlagIndex] = enabled; }
  static void SetLocalNetworkAccessForWebRTCOptOutEnabled(bool enabled) { feature_states_[kLocalNetworkAccessForWebRTCOptOutFlagIndex] = enabled; }
  static void SetLocalNetworkAccessPermissionPolicyEnabled(bool enabled) { feature_states_[kLocalNetworkAccessPermissionPolicyFlagIndex] = enabled; }
  static void SetLocalNetworkAccessWebRTCEnabled(bool enabled) { feature_states_[kLocalNetworkAccessWebRTCFlagIndex] = enabled; }
  static void SetLocalNetworkAccessWebSocketsTargetAddressSpaceEnabled(bool enabled) { feature_states_[kLocalNetworkAccessWebSocketsTargetAddressSpaceFlagIndex] = enabled; }
  static void SetLockedModeEnabled(bool enabled) { feature_states_[kLockedModeFlagIndex] = enabled; }
  static void SetLoginElementEnabled(bool enabled) { feature_states_[kLoginElementFlagIndex] = enabled; }
  static void SetLongAnimationFrameSourceCharPositionEnabled(bool enabled) { feature_states_[kLongAnimationFrameSourceCharPositionFlagIndex] = enabled; }
  static void SetLongAnimationFrameSourceLineColumnEnabled(bool enabled) { feature_states_[kLongAnimationFrameSourceLineColumnFlagIndex] = enabled; }
  static void SetLongAnimationFrameSourceLineColumnInterfaceEnabled(bool enabled) { feature_states_[kLongAnimationFrameSourceLineColumnInterfaceFlagIndex] = enabled; }
  static void SetLongAnimationFrameStyleDurationEnabled(bool enabled) { feature_states_[kLongAnimationFrameStyleDurationFlagIndex] = enabled; }
  static void SetLongAnimationFrameWorkerEnabled(bool enabled) { feature_states_[kLongAnimationFrameWorkerFlagIndex] = enabled; }
  static void SetLongPressLinkSelectTextEnabled(bool enabled) { feature_states_[kLongPressLinkSelectTextFlagIndex] = enabled; }
  static void SetLongTaskFromLongAnimationFrameEnabled(bool enabled) { feature_states_[kLongTaskFromLongAnimationFrameFlagIndex] = enabled; }
  static void SetMacCharacterFallbackCacheEnabled(bool enabled) { feature_states_[kMacCharacterFallbackCacheFlagIndex] = enabled; }
  static void SetMacDisableCtrlHomeEndEnabled(bool enabled) { feature_states_[kMacDisableCtrlHomeEndFlagIndex] = enabled; }
  static void SetMachineLearningNeuralNetworkEnabled(bool enabled) { feature_states_[kMachineLearningNeuralNetworkFlagIndex] = enabled; }
  static void SetManagedConfigurationEnabled(bool enabled) { feature_states_[kManagedConfigurationFlagIndex] = enabled; }
  static void SetManualTextEnabled(bool enabled) { feature_states_[kManualTextFlagIndex] = enabled; }
  static void SetMarginTrimEnabled(bool enabled) { feature_states_[kMarginTrimFlagIndex] = enabled; }
  static void SetMaskDeserializationTimeForCrossOriginMessagesEnabled(bool enabled) { feature_states_[kMaskDeserializationTimeForCrossOriginMessagesFlagIndex] = enabled; }
  static void SetMaskWaitForAllImagesEnabled(bool enabled) { feature_states_[kMaskWaitForAllImagesFlagIndex] = enabled; }
  static void SetMathMLAnchorElementEnabled(bool enabled) { feature_states_[kMathMLAnchorElementFlagIndex] = enabled; }
  static void SetMathMLOperatorRTLMirroringEnabled(bool enabled) { feature_states_[kMathMLOperatorRTLMirroringFlagIndex] = enabled; }
  static void SetMeasureMemoryEnabled(bool enabled) { feature_states_[kMeasureMemoryFlagIndex] = enabled; }
  static void SetMediaCapabilitiesEncodingInfoEnabled(bool enabled) { feature_states_[kMediaCapabilitiesEncodingInfoFlagIndex] = enabled; }
  static void SetMediaCapabilitiesSpatialAudioEnabled(bool enabled) { feature_states_[kMediaCapabilitiesSpatialAudioFlagIndex] = enabled; }
  static void SetMediaCaptionSettingsButtonEnabled(bool enabled) { feature_states_[kMediaCaptionSettingsButtonFlagIndex] = enabled; }
  static void SetMediaCaptureEnabled(bool enabled) { feature_states_[kMediaCaptureFlagIndex] = enabled; }
  static void SetMediaCaptureBackgroundBlurEnabled(bool enabled) { feature_states_[kMediaCaptureBackgroundBlurFlagIndex] = enabled; }
  static void SetMediaCaptureCameraControlsEnabled(bool enabled) { feature_states_[kMediaCaptureCameraControlsFlagIndex] = enabled; }
  static void SetMediaCaptureConfigurationChangeEnabled(bool enabled) { feature_states_[kMediaCaptureConfigurationChangeFlagIndex] = enabled; }
  static void SetMediaCaptureVoiceIsolationEnabled(bool enabled) { feature_states_[kMediaCaptureVoiceIsolationFlagIndex] = enabled; }
  static void SetMediaControlsExpandGestureEnabled(bool enabled) { feature_states_[kMediaControlsExpandGestureFlagIndex] = enabled; }
  static void SetMediaControlsOverlayPlayButtonEnabled(bool enabled) { feature_states_[kMediaControlsOverlayPlayButtonFlagIndex] = enabled; }
  static void SetMediaElementMutedDefaultStateEnabled(bool enabled) { feature_states_[kMediaElementMutedDefaultStateFlagIndex] = enabled; }
  static void SetMediaElementVolumeGreaterThanOneEnabled(bool enabled) { feature_states_[kMediaElementVolumeGreaterThanOneFlagIndex] = enabled; }
  static void SetMediaEngagementBypassAutoplayPoliciesEnabled(bool enabled) { feature_states_[kMediaEngagementBypassAutoplayPoliciesFlagIndex] = enabled; }
  static void SetMediaLatencyHintEnabled(bool enabled) { feature_states_[kMediaLatencyHintFlagIndex] = enabled; }
  static void SetMediaPlaybackWhileNotVisiblePermissionPolicyEnabled(bool enabled) { feature_states_[kMediaPlaybackWhileNotVisiblePermissionPolicyFlagIndex] = enabled; }
  static void SetMediaQueryNavigationControlsEnabled(bool enabled) { feature_states_[kMediaQueryNavigationControlsFlagIndex] = enabled; }
  static void SetMediaSessionEnabled(bool enabled) { feature_states_[kMediaSessionFlagIndex] = enabled; }
  static void SetMediaSessionChapterInformationEnabled(bool enabled) { feature_states_[kMediaSessionChapterInformationFlagIndex] = enabled; }
  static void SetMediaSourceExperimentalEnabled(bool enabled) { feature_states_[kMediaSourceExperimentalFlagIndex] = enabled; }
  static void SetMediaSourceExtensionsForWebCodecsEnabled(bool enabled) { feature_states_[kMediaSourceExtensionsForWebCodecsFlagIndex] = enabled; }
  static void SetMediaStreamTrackProcessorStatsEnabled(bool enabled) { feature_states_[kMediaStreamTrackProcessorStatsFlagIndex] = enabled; }
  static void SetMediaStreamTrackTransferEnabled(bool enabled) { feature_states_[kMediaStreamTrackTransferFlagIndex] = enabled; }
  static void SetMediaStreamTrackWebSpeechEnabled(bool enabled) { feature_states_[kMediaStreamTrackWebSpeechFlagIndex] = enabled; }
  static void SetMemoryConsumerForNGShapeCacheEnabled(bool enabled) { feature_states_[kMemoryConsumerForNGShapeCacheFlagIndex] = enabled; }
  static void SetMenuElementsEnabled(bool enabled) { feature_states_[kMenuElementsFlagIndex] = enabled; }
  static void SetMergeFixedLayersEnabled(bool enabled) { feature_states_[kMergeFixedLayersFlagIndex] = enabled; }
  static void SetMergeStickyLayersEnabled(bool enabled) { feature_states_[kMergeStickyLayersFlagIndex] = enabled; }
  static void SetMessagePortCloseEventEnabled(bool enabled) { feature_states_[kMessagePortCloseEventFlagIndex] = enabled; }
  static void SetMiddleClickAutoscrollEnabled(bool enabled) { feature_states_[kMiddleClickAutoscrollFlagIndex] = enabled; }
  static void SetMixedContentAutoupgradesUseIsMixedContentRestrictedInFrameEnabled(bool enabled) { feature_states_[kMixedContentAutoupgradesUseIsMixedContentRestrictedInFrameFlagIndex] = enabled; }
  static void SetMobileLayoutThemeEnabled(bool enabled) { feature_states_[kMobileLayoutThemeFlagIndex] = enabled; }
  static void SetModifyParagraphCrossEditingoundaryEnabled(bool enabled) { feature_states_[kModifyParagraphCrossEditingoundaryFlagIndex] = enabled; }
  static void SetModuleMapDoNotCacheFailedFetchEnabled(bool enabled) { feature_states_[kModuleMapDoNotCacheFailedFetchFlagIndex] = enabled; }
  static void SetModulePreloadReferrerEnabled(bool enabled) { feature_states_[kModulePreloadReferrerFlagIndex] = enabled; }
  static void SetModulePreloadStyleJsonEnabled(bool enabled) { feature_states_[kModulePreloadStyleJsonFlagIndex] = enabled; }
  static void SetMojoJSEnabled(bool enabled);
  static void SetMojoJSTestEnabled(bool enabled);
  static void SetMoveEndingSelectionToListChildEnabled(bool enabled) { feature_states_[kMoveEndingSelectionToListChildFlagIndex] = enabled; }
  static void SetMoveParagraphsPreserveInlineStructureEnabled(bool enabled) { feature_states_[kMoveParagraphsPreserveInlineStructureFlagIndex] = enabled; }
  static void SetNavigateEventDeferCrossDocumentCommitEnabled(bool enabled) { feature_states_[kNavigateEventDeferCrossDocumentCommitFlagIndex] = enabled; }
  static void SetNavigationEventTimingEnabled(bool enabled) { feature_states_[kNavigationEventTimingFlagIndex] = enabled; }
  static void SetNavigationSourcePseudoClassEnabled(bool enabled) { feature_states_[kNavigationSourcePseudoClassFlagIndex] = enabled; }
  static void SetNavigationTimingRedirectTimingViaTAOEnabled(bool enabled) { feature_states_[kNavigationTimingRedirectTimingViaTAOFlagIndex] = enabled; }
  static void SetNavigationTypeAndPhaseEnabled(bool enabled) { feature_states_[kNavigationTypeAndPhaseFlagIndex] = enabled; }
  static void SetNavigatorContentUtilsEnabled(bool enabled) { feature_states_[kNavigatorContentUtilsFlagIndex] = enabled; }
  static void SetNetInfoConstantTypeEnabled(bool enabled) { feature_states_[kNetInfoConstantTypeFlagIndex] = enabled; }
  static void SetNetInfoDownlinkMaxEnabled(bool enabled) { feature_states_[kNetInfoDownlinkMaxFlagIndex] = enabled; }
  static void SetNewAnimationCompositingCheckingEnabled(bool enabled) { feature_states_[kNewAnimationCompositingCheckingFlagIndex] = enabled; }
  static void SetNewAnimationDispositionReportingEnabled(bool enabled) { feature_states_[kNewAnimationDispositionReportingFlagIndex] = enabled; }
  static void SetNewHTMLSettingMethodsEnabled(bool enabled) { feature_states_[kNewHTMLSettingMethodsFlagIndex] = enabled; }
  static void SetNoExtendSelectionToUserSelectNoneOutOfFlowEnabled(bool enabled) { feature_states_[kNoExtendSelectionToUserSelectNoneOutOfFlowFlagIndex] = enabled; }
  static void SetNoExtendSelectionToUserSelectNoneOutOfFlowUnlessEditableEnabled(bool enabled) { feature_states_[kNoExtendSelectionToUserSelectNoneOutOfFlowUnlessEditableFlagIndex] = enabled; }
  static void SetNoFontAntialiasingEnabled(bool enabled) { feature_states_[kNoFontAntialiasingFlagIndex] = enabled; }
  static void SetNoIdleEncodingForWebTestsEnabled(bool enabled) { feature_states_[kNoIdleEncodingForWebTestsFlagIndex] = enabled; }
  static void SetNoNbspForInterElementSpaceOnCopyEnabled(bool enabled) { feature_states_[kNoNbspForInterElementSpaceOnCopyFlagIndex] = enabled; }
  static void SetNonEmptyBlockquotesOnOutdentingEnabled(bool enabled) { feature_states_[kNonEmptyBlockquotesOnOutdentingFlagIndex] = enabled; }
  static void SetNonEmptyVisibleTextSelectionForTextFragmentEnabled(bool enabled) { feature_states_[kNonEmptyVisibleTextSelectionForTextFragmentFlagIndex] = enabled; }
  static void SetNonStandardAppearanceValueSliderVerticalEnabled(bool enabled) { feature_states_[kNonStandardAppearanceValueSliderVerticalFlagIndex] = enabled; }
  static void SetNormalizeLineEndingsInInsertTextEnabled(bool enabled) { feature_states_[kNormalizeLineEndingsInInsertTextFlagIndex] = enabled; }
  static void SetNormalizeNbspForPasteAndDropEnabled(bool enabled) { feature_states_[kNormalizeNbspForPasteAndDropFlagIndex] = enabled; }
  static void SetNormalizeNbspRichTextOnlyEnabled(bool enabled) { feature_states_[kNormalizeNbspRichTextOnlyFlagIndex] = enabled; }
  static void SetNotificationConstructorEnabled(bool enabled) { feature_states_[kNotificationConstructorFlagIndex] = enabled; }
  static void SetNotificationContentImageEnabled(bool enabled) { feature_states_[kNotificationContentImageFlagIndex] = enabled; }
  static void SetNotificationsEnabled(bool enabled) { feature_states_[kNotificationsFlagIndex] = enabled; }
  static void SetNotificationTriggersEnabled(bool enabled) { feature_states_[kNotificationTriggersFlagIndex] = enabled; }
  static void SetNotifySelectionControllerOnUnchangedSelectionEnabled(bool enabled) { feature_states_[kNotifySelectionControllerOnUnchangedSelectionFlagIndex] = enabled; }
  static void SetNumberInputFullWidthCharsEnabled(bool enabled) { feature_states_[kNumberInputFullWidthCharsFlagIndex] = enabled; }
  static void SetOffscreenCanvasGetContextAttributesEnabled(bool enabled) { feature_states_[kOffscreenCanvasGetContextAttributesFlagIndex] = enabled; }
  static void SetOffsetMappingReuseFullWidthSpaceFixEnabled(bool enabled) { feature_states_[kOffsetMappingReuseFullWidthSpaceFixFlagIndex] = enabled; }
  static void SetOffsetPathTransformUpdateFixEnabled(bool enabled) { feature_states_[kOffsetPathTransformUpdateFixFlagIndex] = enabled; }
  static void SetOmitBlurEventOnElementRemovalEnabled(bool enabled) { feature_states_[kOmitBlurEventOnElementRemovalFlagIndex] = enabled; }
  static void SetOmitSubframeDetachmentEventsOnRemovalEnabled(bool enabled) { feature_states_[kOmitSubframeDetachmentEventsOnRemovalFlagIndex] = enabled; }
  static void SetOnDeviceWebSpeechAvailableEnabled(bool enabled) { feature_states_[kOnDeviceWebSpeechAvailableFlagIndex] = enabled; }
  static void SetOnDeviceWebSpeechQualityEnabled(bool enabled) { feature_states_[kOnDeviceWebSpeechQualityFlagIndex] = enabled; }
  static void SetOofLayoutRequiresSideEffectsEnabled(bool enabled) { feature_states_[kOofLayoutRequiresSideEffectsFlagIndex] = enabled; }
  static void SetOpaqueRangeEnabled(bool enabled) { feature_states_[kOpaqueRangeFlagIndex] = enabled; }
  static void SetOpenPopoverInvokerRestrictToSameTreeScopeEnabled(bool enabled) { feature_states_[kOpenPopoverInvokerRestrictToSameTreeScopeFlagIndex] = enabled; }
  static void SetOptionDisablednessCheckAncestorsEnabled(bool enabled) { feature_states_[kOptionDisablednessCheckAncestorsFlagIndex] = enabled; }
  static void SetOrientationEventEnabled(bool enabled) { feature_states_[kOrientationEventFlagIndex] = enabled; }
  static void SetOriginAPIEnabled(bool enabled) { feature_states_[kOriginAPIFlagIndex] = enabled; }
  static void SetOriginIsolationHeaderEnabled(bool enabled) { feature_states_[kOriginIsolationHeaderFlagIndex] = enabled; }
  static void SetOriginPolicyEnabled(bool enabled) { feature_states_[kOriginPolicyFlagIndex] = enabled; }
  static void SetOriginTrialsSampleAPIEnabled(bool enabled) { feature_states_[kOriginTrialsSampleAPIFlagIndex] = enabled; }
  static void SetOriginTrialsSampleAPIBrowserReadWriteEnabled(bool enabled) { feature_states_[kOriginTrialsSampleAPIBrowserReadWriteFlagIndex] = enabled; }
  static void SetOriginTrialsSampleAPIDependentEnabled(bool enabled) { feature_states_[kOriginTrialsSampleAPIDependentFlagIndex] = enabled; }
  static void SetOriginTrialsSampleAPIDeprecationEnabled(bool enabled) { feature_states_[kOriginTrialsSampleAPIDeprecationFlagIndex] = enabled; }
  static void SetOriginTrialsSampleAPIExpiryGracePeriodEnabled(bool enabled) { feature_states_[kOriginTrialsSampleAPIExpiryGracePeriodFlagIndex] = enabled; }
  static void SetOriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled(bool enabled) { feature_states_[kOriginTrialsSampleAPIExpiryGracePeriodThirdPartyFlagIndex] = enabled; }
  static void SetOriginTrialsSampleAPIImpliedEnabled(bool enabled) { feature_states_[kOriginTrialsSampleAPIImpliedFlagIndex] = enabled; }
  static void SetOriginTrialsSampleAPIInvalidOSEnabled(bool enabled) { feature_states_[kOriginTrialsSampleAPIInvalidOSFlagIndex] = enabled; }
  static void SetOriginTrialsSampleAPINavigationEnabled(bool enabled) { feature_states_[kOriginTrialsSampleAPINavigationFlagIndex] = enabled; }
  static void SetOriginTrialsSampleAPIPersistentExpiryGracePeriodEnabled(bool enabled) { feature_states_[kOriginTrialsSampleAPIPersistentExpiryGracePeriodFlagIndex] = enabled; }
  static void SetOriginTrialsSampleAPIPersistentFeatureEnabled(bool enabled) { feature_states_[kOriginTrialsSampleAPIPersistentFeatureFlagIndex] = enabled; }
  static void SetOriginTrialsSampleAPIPersistentInvalidOSEnabled(bool enabled) { feature_states_[kOriginTrialsSampleAPIPersistentInvalidOSFlagIndex] = enabled; }
  static void SetOriginTrialsSampleAPIPersistentThirdPartyDeprecationFeatureEnabled(bool enabled) { feature_states_[kOriginTrialsSampleAPIPersistentThirdPartyDeprecationFeatureFlagIndex] = enabled; }
  static void SetOriginTrialsSampleAPIThirdPartyEnabled(bool enabled) { feature_states_[kOriginTrialsSampleAPIThirdPartyFlagIndex] = enabled; }
  static void SetOutlineDrawAutoStyleZeroWidthEnabled(bool enabled) { feature_states_[kOutlineDrawAutoStyleZeroWidthFlagIndex] = enabled; }
  static void SetOverlayGlobalRuleRemovalEnabled(bool enabled) { feature_states_[kOverlayGlobalRuleRemovalFlagIndex] = enabled; }
  static void SetOverlayPropertyEnabled(bool enabled) { feature_states_[kOverlayPropertyFlagIndex] = enabled; }
  static void SetOverscrollGesturesEnabled(bool enabled) { feature_states_[kOverscrollGesturesFlagIndex] = enabled; }
  static void SetPagePopupEnabled(bool enabled) { feature_states_[kPagePopupFlagIndex] = enabled; }
  static void SetPagePopupCopyPasteEnabled(bool enabled) { feature_states_[kPagePopupCopyPasteFlagIndex] = enabled; }
  static void SetPageSwapEventEnabled(bool enabled) { feature_states_[kPageSwapEventFlagIndex] = enabled; }
  static void SetPaintCaretAfterInnerEditorPaintEnabled(bool enabled) { feature_states_[kPaintCaretAfterInnerEditorPaintFlagIndex] = enabled; }
  static void SetPaintHoldingForIframesEnabled(bool enabled) { feature_states_[kPaintHoldingForIframesFlagIndex] = enabled; }
  static void SetPaintUnderInvalidationCheckingEnabled(bool enabled) { feature_states_[kPaintUnderInvalidationCheckingFlagIndex] = enabled; }
  static void SetParakeetEnabled(bool enabled) { feature_states_[kParakeetFlagIndex] = enabled; }
  static void SetPartitionVisitedLinkDatabaseWithSelfLinksEnabled(bool enabled) { feature_states_[kPartitionVisitedLinkDatabaseWithSelfLinksFlagIndex] = enabled; }
  static void SetPasswordRevealEnabled(bool enabled) { feature_states_[kPasswordRevealFlagIndex] = enabled; }
  static void SetPaymentAppEnabled(bool enabled) { feature_states_[kPaymentAppFlagIndex] = enabled; }
  static void SetPaymentLinkDetectionEnabled(bool enabled) { feature_states_[kPaymentLinkDetectionFlagIndex] = enabled; }
  static void SetPaymentMethodChangeEventEnabled(bool enabled) { feature_states_[kPaymentMethodChangeEventFlagIndex] = enabled; }
  static void SetPaymentRequestEnabled(bool enabled) { feature_states_[kPaymentRequestFlagIndex] = enabled; }
  static void SetPaymentRequestNonFullyActiveDocumentCheckInvalidStateErrorEnabled(bool enabled) { feature_states_[kPaymentRequestNonFullyActiveDocumentCheckInvalidStateErrorFlagIndex] = enabled; }
  static void SetPerformanceManagerInstrumentationEnabled(bool enabled) { feature_states_[kPerformanceManagerInstrumentationFlagIndex] = enabled; }
  static void SetPerformanceMarkCustomUserTimingFromSubframeEnabled(bool enabled) { feature_states_[kPerformanceMarkCustomUserTimingFromSubframeFlagIndex] = enabled; }
  static void SetPerformanceMarkFeatureUsageEnabled(bool enabled) { feature_states_[kPerformanceMarkFeatureUsageFlagIndex] = enabled; }
  static void SetPeriodicBackgroundSyncEnabled(bool enabled) { feature_states_[kPeriodicBackgroundSyncFlagIndex] = enabled; }
  static void SetPerMethodCanMakePaymentQuotaEnabled(bool enabled) { feature_states_[kPerMethodCanMakePaymentQuotaFlagIndex] = enabled; }
  static void SetPermissionsPolicyAPIEnabled(bool enabled) { feature_states_[kPermissionsPolicyAPIFlagIndex] = enabled; }
  static void SetPermissionsRequestRevokeEnabled(bool enabled) { feature_states_[kPermissionsRequestRevokeFlagIndex] = enabled; }
  static void SetPNaClEnabled(bool enabled) { feature_states_[kPNaClFlagIndex] = enabled; }
  static void SetPointerLockOnAndroidEnabled(bool enabled) { feature_states_[kPointerLockOnAndroidFlagIndex] = enabled; }
  static void SetPointerRawUpdateOnlyInSecureContextEnabled(bool enabled) { feature_states_[kPointerRawUpdateOnlyInSecureContextFlagIndex] = enabled; }
  static void SetPopoverHintNestedShowExceptionEnabled(bool enabled) { feature_states_[kPopoverHintNestedShowExceptionFlagIndex] = enabled; }
  static void SetPopoverHintNewBehaviorEnabled(bool enabled) { feature_states_[kPopoverHintNewBehaviorFlagIndex] = enabled; }
  static void SetPositionOutsideTabSpanCheckSiblingNodeEnabled(bool enabled) { feature_states_[kPositionOutsideTabSpanCheckSiblingNodeFlagIndex] = enabled; }
  static void SetPositionVisibilityIgnoreNonClipAncestorsEnabled(bool enabled) { feature_states_[kPositionVisibilityIgnoreNonClipAncestorsFlagIndex] = enabled; }
  static void SetPotentialPermissionsPolicyReportingEnabled(bool enabled) { feature_states_[kPotentialPermissionsPolicyReportingFlagIndex] = enabled; }
  static void SetPreciseMemoryInfoEnabled(bool enabled) { feature_states_[kPreciseMemoryInfoFlagIndex] = enabled; }
  static void SetPreferDefaultScrollbarStylesEnabled(bool enabled) { feature_states_[kPreferDefaultScrollbarStylesFlagIndex] = enabled; }
  static void SetPreferNonCompositedScrollingEnabled(bool enabled) { feature_states_[kPreferNonCompositedScrollingFlagIndex] = enabled; }
  static void SetPreferredAudioOutputDevicesEnabled(bool enabled) { feature_states_[kPreferredAudioOutputDevicesFlagIndex] = enabled; }
  static void SetPrefersReducedDataEnabled(bool enabled) { feature_states_[kPrefersReducedDataFlagIndex] = enabled; }
  static void SetPrefetchAndPrerenderActivationBeaconEnabled(bool enabled) { feature_states_[kPrefetchAndPrerenderActivationBeaconFlagIndex] = enabled; }
  static void SetPreloadLinkRelDataUrlsEnabled(bool enabled) { feature_states_[kPreloadLinkRelDataUrlsFlagIndex] = enabled; }
  static void SetPreloadScannerSkipMathMLScriptEnabled(bool enabled) { feature_states_[kPreloadScannerSkipMathMLScriptFlagIndex] = enabled; }
  static void SetPrerender2Enabled(bool enabled) { feature_states_[kPrerender2FlagIndex] = enabled; }
  static void SetPrerender2CrossOriginIframesEnabled(bool enabled) { feature_states_[kPrerender2CrossOriginIframesFlagIndex] = enabled; }
  static void SetPrerenderActivationByFormSubmissionEnabled(bool enabled) { feature_states_[kPrerenderActivationByFormSubmissionFlagIndex] = enabled; }
  static void SetPrerenderUntilScriptEnabled(bool enabled) { feature_states_[kPrerenderUntilScriptFlagIndex] = enabled; }
  static void SetPresentationEnabled(bool enabled) { feature_states_[kPresentationFlagIndex] = enabled; }
  static void SetPreserveHtmlEquivalentTagsInTypingStyleEnabled(bool enabled) { feature_states_[kPreserveHtmlEquivalentTagsInTypingStyleFlagIndex] = enabled; }
  static void SetPreserveUnfocusedSelectionCacheEnabled(bool enabled) { feature_states_[kPreserveUnfocusedSelectionCacheFlagIndex] = enabled; }
  static void SetPreventTextSelectionJumpEnabled(bool enabled) { feature_states_[kPreventTextSelectionJumpFlagIndex] = enabled; }
  static void SetPrivateNetworkAccessNullIpAddressEnabled(bool enabled) { feature_states_[kPrivateNetworkAccessNullIpAddressFlagIndex] = enabled; }
  static void SetPrivateStateTokensEnabled(bool enabled) { feature_states_[kPrivateStateTokensFlagIndex] = enabled; }
  static void SetPrivateStateTokensAlwaysAllowIssuanceEnabled(bool enabled) { feature_states_[kPrivateStateTokensAlwaysAllowIssuanceFlagIndex] = enabled; }
  static void SetProfilerAPIEnabled(bool enabled) { feature_states_[kProfilerAPIFlagIndex] = enabled; }
  static void SetProfilerAPIForDedicatedWorkerEnabled(bool enabled) { feature_states_[kProfilerAPIForDedicatedWorkerFlagIndex] = enabled; }
  static void SetProgrammaticScrollPromiseEnabled(bool enabled) { feature_states_[kProgrammaticScrollPromiseFlagIndex] = enabled; }
  static void SetPropagateOverscrollBehaviorFromRootEnabled(bool enabled) { feature_states_[kPropagateOverscrollBehaviorFromRootFlagIndex] = enabled; }
  static void SetProtectedOriginTrialsSampleAPIEnabled(bool enabled);
  static void SetProtectedOriginTrialsSampleAPIDependentEnabled(bool enabled);
  static void SetProtectedOriginTrialsSampleAPIImpliedEnabled(bool enabled);
  static void SetPseudoElementsFocusableEnabled(bool enabled) { feature_states_[kPseudoElementsFocusableFlagIndex] = enabled; }
  static void SetPseudoElementsHitTestableEnabled(bool enabled) { feature_states_[kPseudoElementsHitTestableFlagIndex] = enabled; }
  static void SetPseudoElementsHoverableEnabled(bool enabled) { feature_states_[kPseudoElementsHoverableFlagIndex] = enabled; }
  static void SetPushMessageDataBytesEnabled(bool enabled) { feature_states_[kPushMessageDataBytesFlagIndex] = enabled; }
  static void SetPushMessagingEnabled(bool enabled) { feature_states_[kPushMessagingFlagIndex] = enabled; }
  static void SetPushMessagingSubscriptionChangeEnabled(bool enabled) { feature_states_[kPushMessagingSubscriptionChangeFlagIndex] = enabled; }
  static void SetQuotaExceededErrorUpdateEnabled(bool enabled) { feature_states_[kQuotaExceededErrorUpdateFlagIndex] = enabled; }
  static void SetRangeBoundaryFastPathEnabled(bool enabled) { feature_states_[kRangeBoundaryFastPathFlagIndex] = enabled; }
  static void SetRasterInducingScrollEnabled(bool enabled) { feature_states_[kRasterInducingScrollFlagIndex] = enabled; }
  static void SetRateLimitPointerLockRequestsEnabled(bool enabled) { feature_states_[kRateLimitPointerLockRequestsFlagIndex] = enabled; }
  static void SetReadableStreamBYOBReaderReadMinOptionEnabled(bool enabled) { feature_states_[kReadableStreamBYOBReaderReadMinOptionFlagIndex] = enabled; }
  static void SetReadClipboardDataOnClipboardItemGetTypeEnabled(bool enabled) { feature_states_[kReadClipboardDataOnClipboardItemGetTypeFlagIndex] = enabled; }
  static void SetReadingFlowWithSlotsEnabled(bool enabled) { feature_states_[kReadingFlowWithSlotsFlagIndex] = enabled; }
  static void SetRecheckParentDuringNodeVectorInsertionEnabled(bool enabled) { feature_states_[kRecheckParentDuringNodeVectorInsertionFlagIndex] = enabled; }
  static void SetRecordSameDocumentPresentationTimeOnceEnabled(bool enabled) { feature_states_[kRecordSameDocumentPresentationTimeOnceFlagIndex] = enabled; }
  static void SetReduceAcceptLanguageEnabled(bool enabled) { feature_states_[kReduceAcceptLanguageFlagIndex] = enabled; }
  static void SetReduceUserAgentMinorVersionEnabled(bool enabled) { feature_states_[kReduceUserAgentMinorVersionFlagIndex] = enabled; }
  static void SetRegionCaptureEnabled(bool enabled) { feature_states_[kRegionCaptureFlagIndex] = enabled; }
  static void SetRelatedWebsitePartitionAPIEnabled(bool enabled) { feature_states_[kRelatedWebsitePartitionAPIFlagIndex] = enabled; }
  static void SetReleasePaintHoldingWithoutContentfulPaintEnabled(bool enabled) { feature_states_[kReleasePaintHoldingWithoutContentfulPaintFlagIndex] = enabled; }
  static void SetRelOpenerBcgDependencyHintEnabled(bool enabled) { feature_states_[kRelOpenerBcgDependencyHintFlagIndex] = enabled; }
  static void SetRemotePlaybackEnabled(bool enabled) { feature_states_[kRemotePlaybackFlagIndex] = enabled; }
  static void SetRemotePlaybackBackendEnabled(bool enabled) { feature_states_[kRemotePlaybackBackendFlagIndex] = enabled; }
  static void SetRemoveCharsetAutoDetectionForISO2022JPEnabled(bool enabled) { feature_states_[kRemoveCharsetAutoDetectionForISO2022JPFlagIndex] = enabled; }
  static void SetRemoveChildrenInReplaceChildrenEnabled(bool enabled) { feature_states_[kRemoveChildrenInReplaceChildrenFlagIndex] = enabled; }
  static void SetRemoveCollapsedPlaceholderForContentEditableEnabled(bool enabled) { feature_states_[kRemoveCollapsedPlaceholderForContentEditableFlagIndex] = enabled; }
  static void SetRemoveDanglingMarkupInTargetEnabled(bool enabled) { feature_states_[kRemoveDanglingMarkupInTargetFlagIndex] = enabled; }
  static void SetRemoveDataUrlInSvgUseEnabled(bool enabled) { feature_states_[kRemoveDataUrlInSvgUseFlagIndex] = enabled; }
  static void SetRemoveNonAllowlistedCreateEventEnabled(bool enabled) { feature_states_[kRemoveNonAllowlistedCreateEventFlagIndex] = enabled; }
  static void SetRemoveScrollNodeWorkaroundEnabled(bool enabled) { feature_states_[kRemoveScrollNodeWorkaroundFlagIndex] = enabled; }
  static void SetRemoveTargetCurrentEnabled(bool enabled) { feature_states_[kRemoveTargetCurrentFlagIndex] = enabled; }
  static void SetRemoveVisibleSelectionInDOMSelectionEnabled(bool enabled) { feature_states_[kRemoveVisibleSelectionInDOMSelectionFlagIndex] = enabled; }
  static void SetRenderPriorityAttributeEnabled(bool enabled) { feature_states_[kRenderPriorityAttributeFlagIndex] = enabled; }
  static void SetReplaceChildrenWithFragmentFastPathEnabled(bool enabled) { feature_states_[kReplaceChildrenWithFragmentFastPathFlagIndex] = enabled; }
  static void SetReplacedNormalFlowStackingInlinePaintEnabled(bool enabled) { feature_states_[kReplacedNormalFlowStackingInlinePaintFlagIndex] = enabled; }
  static void SetReportFirstFrameTimeAsRenderTimeEnabled(bool enabled) { feature_states_[kReportFirstFrameTimeAsRenderTimeFlagIndex] = enabled; }
  static void SetReportLayoutShiftRectsInCssPixelsEnabled(bool enabled) { feature_states_[kReportLayoutShiftRectsInCssPixelsFlagIndex] = enabled; }
  static void SetRequestIsReloadNavigationEnabled(bool enabled) { feature_states_[kRequestIsReloadNavigationFlagIndex] = enabled; }
  static void SetRequestStorageAccessForEnabled(bool enabled) { feature_states_[kRequestStorageAccessForFlagIndex] = enabled; }
  static void SetResourceTimingInitiatorEnabled(bool enabled) { feature_states_[kResourceTimingInitiatorFlagIndex] = enabled; }
  static void SetResourceTimingUseCORSForBodySizesEnabled(bool enabled) { feature_states_[kResourceTimingUseCORSForBodySizesFlagIndex] = enabled; }
  static void SetRespectOverscrollBehaviorForScrollBubblingEnabled(bool enabled) { feature_states_[kRespectOverscrollBehaviorForScrollBubblingFlagIndex] = enabled; }
  static void SetResponsiveIframesEnabled(bool enabled) { feature_states_[kResponsiveIframesFlagIndex] = enabled; }
  static void SetRestrictGamepadAccessEnabled(bool enabled) { feature_states_[kRestrictGamepadAccessFlagIndex] = enabled; }
  static void SetRestrictOwnAudioEnabled(bool enabled) { feature_states_[kRestrictOwnAudioFlagIndex] = enabled; }
  static void SetRootScrollbarFollowsBrowserThemeEnabled(bool enabled) { feature_states_[kRootScrollbarFollowsBrowserThemeFlagIndex] = enabled; }
  static void SetRouteMatchingEnabled(bool enabled) { feature_states_[kRouteMatchingFlagIndex] = enabled; }
  static void SetRtcAlwaysNegotiateDataChannelsEnabled(bool enabled) { feature_states_[kRtcAlwaysNegotiateDataChannelsFlagIndex] = enabled; }
  static void SetRtcAudioJitterBufferMaxPacketsEnabled(bool enabled) { feature_states_[kRtcAudioJitterBufferMaxPacketsFlagIndex] = enabled; }
  static void SetRTCConfigurationIceTransportsEnabled(bool enabled) { feature_states_[kRTCConfigurationIceTransportsFlagIndex] = enabled; }
  static void SetRTCDataChannelPriorityEnabled(bool enabled) { feature_states_[kRTCDataChannelPriorityFlagIndex] = enabled; }
  static void SetRTCDiagnosticLoggingEnabled(bool enabled) { feature_states_[kRTCDiagnosticLoggingFlagIndex] = enabled; }
  static void SetRTCEncodedAudioFrameConstructorEnabled(bool enabled) { feature_states_[kRTCEncodedAudioFrameConstructorFlagIndex] = enabled; }
  static void SetRTCEncodedFrameAudioLevelEnabled(bool enabled) { feature_states_[kRTCEncodedFrameAudioLevelFlagIndex] = enabled; }
  static void SetRTCEncodedFrameSetMetadataEnabled(bool enabled) { feature_states_[kRTCEncodedFrameSetMetadataFlagIndex] = enabled; }
  static void SetRTCEncodedFrameTimestampsEnabled(bool enabled) { feature_states_[kRTCEncodedFrameTimestampsFlagIndex] = enabled; }
  static void SetRTCEncodedSourceEnabled(bool enabled) { feature_states_[kRTCEncodedSourceFlagIndex] = enabled; }
  static void SetRTCEncodedVideoFrameAdditionalMetadataEnabled(bool enabled) { feature_states_[kRTCEncodedVideoFrameAdditionalMetadataFlagIndex] = enabled; }
  static void SetRTCEncodedVideoFrameConstructorEnabled(bool enabled) { feature_states_[kRTCEncodedVideoFrameConstructorFlagIndex] = enabled; }
  static void SetRTCJitterBufferTargetEnabled(bool enabled) { feature_states_[kRTCJitterBufferTargetFlagIndex] = enabled; }
  static void SetRTCLegacyCallbackBasedGetStatsEnabled(bool enabled) { feature_states_[kRTCLegacyCallbackBasedGetStatsFlagIndex] = enabled; }
  static void SetRTCRtpEncodingParametersCodecEnabled(bool enabled) { feature_states_[kRTCRtpEncodingParametersCodecFlagIndex] = enabled; }
  static void SetRtcRtpHeaderEncryptionPolicyEnabled(bool enabled) { feature_states_[kRtcRtpHeaderEncryptionPolicyFlagIndex] = enabled; }
  static void SetRTCRtpScaleResolutionDownToEnabled(bool enabled) { feature_states_[kRTCRtpScaleResolutionDownToFlagIndex] = enabled; }
  static void SetRTCRtpScriptTransformEnabled(bool enabled) { feature_states_[kRTCRtpScriptTransformFlagIndex] = enabled; }
  static void SetRTCRtpTransportEnabled(bool enabled) { feature_states_[kRTCRtpTransportFlagIndex] = enabled; }
  static void SetRTCStatsRelativePacketArrivalDelayEnabled(bool enabled) { feature_states_[kRTCStatsRelativePacketArrivalDelayFlagIndex] = enabled; }
  static void SetRTCSvcScalabilityModeEnabled(bool enabled) { feature_states_[kRTCSvcScalabilityModeFlagIndex] = enabled; }
  static void SetRunMicrotaskBeforeXmlScriptEnabled(bool enabled) { feature_states_[kRunMicrotaskBeforeXmlScriptFlagIndex] = enabled; }
  static void SetRunSnapshotPostLayoutStateStepsEnabled(bool enabled) { feature_states_[kRunSnapshotPostLayoutStateStepsFlagIndex] = enabled; }
  static void SetSanitizeIDNEmailFormInputEnabled(bool enabled) { feature_states_[kSanitizeIDNEmailFormInputFlagIndex] = enabled; }
  static void SetSanitizerAPIEnabled(bool enabled) { feature_states_[kSanitizerAPIFlagIndex] = enabled; }
  static void SetScopedViewTransitionSizeContainmentEnabled(bool enabled) { feature_states_[kScopedViewTransitionSizeContainmentFlagIndex] = enabled; }
  static void SetScoreLineBreakerAbortEnabled(bool enabled) { feature_states_[kScoreLineBreakerAbortFlagIndex] = enabled; }
  static void SetScreenDetailedHdrHeadroomEnabled(bool enabled) { feature_states_[kScreenDetailedHdrHeadroomFlagIndex] = enabled; }
  static void SetScriptBasedOnUnicodeBlockEnabled(bool enabled) { feature_states_[kScriptBasedOnUnicodeBlockFlagIndex] = enabled; }
  static void SetScriptedSpeechRecognitionEnabled(bool enabled) { feature_states_[kScriptedSpeechRecognitionFlagIndex] = enabled; }
  static void SetScriptedSpeechSynthesisEnabled(bool enabled) { feature_states_[kScriptedSpeechSynthesisFlagIndex] = enabled; }
  static void SetScrollAnchorPriorityCandidateSubtreeEnabled(bool enabled) { feature_states_[kScrollAnchorPriorityCandidateSubtreeFlagIndex] = enabled; }
  static void SetScrollAnchorSerializationUseParentForTextNodeEnabled(bool enabled) { feature_states_[kScrollAnchorSerializationUseParentForTextNodeFlagIndex] = enabled; }
  static void SetScrollAxisLockEnabled(bool enabled) { feature_states_[kScrollAxisLockFlagIndex] = enabled; }
  static void SetScrollbarColorEnabled(bool enabled) { feature_states_[kScrollbarColorFlagIndex] = enabled; }
  static void SetScrollbarGutterBugFixEnabled(bool enabled) { feature_states_[kScrollbarGutterBugFixFlagIndex] = enabled; }
  static void SetScrollbarWidthEnabled(bool enabled) { feature_states_[kScrollbarWidthFlagIndex] = enabled; }
  static void SetScrollingContentsCullRectOnScrollNodeEnabled(bool enabled) { feature_states_[kScrollingContentsCullRectOnScrollNodeFlagIndex] = enabled; }
  static void SetScrollIntoViewAlignAutoEnabled(bool enabled) { feature_states_[kScrollIntoViewAlignAutoFlagIndex] = enabled; }
  static void SetScrollIntoViewNearestEnabled(bool enabled) { feature_states_[kScrollIntoViewNearestFlagIndex] = enabled; }
  static void SetScrollIntoViewRootFrameViewportBugFixEnabled(bool enabled) { feature_states_[kScrollIntoViewRootFrameViewportBugFixFlagIndex] = enabled; }
  static void SetScrollPerformanceTimingEnabled(bool enabled) { feature_states_[kScrollPerformanceTimingFlagIndex] = enabled; }
  static void SetScrollTimelineCurrentTimeEnabled(bool enabled) { feature_states_[kScrollTimelineCurrentTimeFlagIndex] = enabled; }
  static void SetScrollTimelineNamedRangeScrollEnabled(bool enabled) { feature_states_[kScrollTimelineNamedRangeScrollFlagIndex] = enabled; }
  static void SetScrollTopLeftInteropEnabled(bool enabled) { feature_states_[kScrollTopLeftInteropFlagIndex] = enabled; }
  static void SetScrollToTextFragmentDirectiveLimitEnabled(bool enabled) { feature_states_[kScrollToTextFragmentDirectiveLimitFlagIndex] = enabled; }
  static void SetScrollToTextFragmentUniqueFragmentsEnabled(bool enabled) { feature_states_[kScrollToTextFragmentUniqueFragmentsFlagIndex] = enabled; }
  static void SetSearchTextHighlightPseudoEnabled(bool enabled) { feature_states_[kSearchTextHighlightPseudoFlagIndex] = enabled; }
  static void SetSecurePaymentConfirmationEnabled(bool enabled) { feature_states_[kSecurePaymentConfirmationFlagIndex] = enabled; }
  static void SetSecurePaymentConfirmationAvailabilityAPIEnabled(bool enabled) { feature_states_[kSecurePaymentConfirmationAvailabilityAPIFlagIndex] = enabled; }
  static void SetSecurePaymentConfirmationCapabilitiesEnabled(bool enabled) { feature_states_[kSecurePaymentConfirmationCapabilitiesFlagIndex] = enabled; }
  static void SetSecurePaymentConfirmationDebugEnabled(bool enabled) { feature_states_[kSecurePaymentConfirmationDebugFlagIndex] = enabled; }
  static void SetSecurePaymentConfirmationExtensionsDisallowForThirdPartiesEnabled(bool enabled) { feature_states_[kSecurePaymentConfirmationExtensionsDisallowForThirdPartiesFlagIndex] = enabled; }
  static void SetSecurePaymentConfirmationOptOutEnabled(bool enabled) { feature_states_[kSecurePaymentConfirmationOptOutFlagIndex] = enabled; }
  static void SetSelectAnchorInViewportEnabled(bool enabled) { feature_states_[kSelectAnchorInViewportFlagIndex] = enabled; }
  static void SetSelectAudioOutputEnabled(bool enabled) { feature_states_[kSelectAudioOutputFlagIndex] = enabled; }
  static void SetSelectedcontentelementAttributeEnabled(bool enabled) { feature_states_[kSelectedcontentelementAttributeFlagIndex] = enabled; }
  static void SetSelectedcontentMultipleEnabled(bool enabled) { feature_states_[kSelectedcontentMultipleFlagIndex] = enabled; }
  static void SetSelectedcontentSpecEnabled(bool enabled) { feature_states_[kSelectedcontentSpecFlagIndex] = enabled; }
  static void SetSelectionAndFocusedVisiblePositionMatchEnabled(bool enabled) { feature_states_[kSelectionAndFocusedVisiblePositionMatchFlagIndex] = enabled; }
  static void SetSelectionCollapsedDirectionNoneEnabled(bool enabled) { feature_states_[kSelectionCollapsedDirectionNoneFlagIndex] = enabled; }
  static void SetSelectionEditingBoundarySlottedContentEnabled(bool enabled) { feature_states_[kSelectionEditingBoundarySlottedContentFlagIndex] = enabled; }
  static void SetSelectionFocusAffinityEnabled(bool enabled) { feature_states_[kSelectionFocusAffinityFlagIndex] = enabled; }
  static void SetSelectionHandleWithBottomClippedEnabled(bool enabled) { feature_states_[kSelectionHandleWithBottomClippedFlagIndex] = enabled; }
  static void SetSelectionRemoveRangeNotFoundErrorEnabled(bool enabled) { feature_states_[kSelectionRemoveRangeNotFoundErrorFlagIndex] = enabled; }
  static void SetSelectionSetBaseAndExtentNonNullNodeEnabled(bool enabled) { feature_states_[kSelectionSetBaseAndExtentNonNullNodeFlagIndex] = enabled; }
  static void SetSelectiveClipboardFormatReadEnabled(bool enabled) { feature_states_[kSelectiveClipboardFormatReadFlagIndex] = enabled; }
  static void SetSelectivePermissionsInterventionEnabled(bool enabled) { feature_states_[kSelectivePermissionsInterventionFlagIndex] = enabled; }
  static void SetSelectRemoveOverflowHiddenEnabled(bool enabled) { feature_states_[kSelectRemoveOverflowHiddenFlagIndex] = enabled; }
  static void SetSelectUsesFlatTreeEnabled(bool enabled) { feature_states_[kSelectUsesFlatTreeFlagIndex] = enabled; }
  static void SetSendBeaconThrowForBlobWithNonSimpleTypeEnabled(bool enabled) { feature_states_[kSendBeaconThrowForBlobWithNonSimpleTypeFlagIndex] = enabled; }
  static void SetSendEarlyLastBeginMainFrameEnabled(bool enabled) { feature_states_[kSendEarlyLastBeginMainFrameFlagIndex] = enabled; }
  static void SetSendSlotChangeSignalAfterNodeInsertedEnabled(bool enabled) { feature_states_[kSendSlotChangeSignalAfterNodeInsertedFlagIndex] = enabled; }
  static void SetSensorExtraClassesEnabled(bool enabled) { feature_states_[kSensorExtraClassesFlagIndex] = enabled; }
  static void SetSeparateDeferModuleScriptTasksEnabled(bool enabled) { feature_states_[kSeparateDeferModuleScriptTasksFlagIndex] = enabled; }
  static void SetSerialEnabled(bool enabled) { feature_states_[kSerialFlagIndex] = enabled; }
  static void SetSerializeInvalidSelectorsInForgivingSelectorListEnabled(bool enabled) { feature_states_[kSerializeInvalidSelectorsInForgivingSelectorListFlagIndex] = enabled; }
  static void SetSerializeViewTransitionStateInSPAEnabled(bool enabled) { feature_states_[kSerializeViewTransitionStateInSPAFlagIndex] = enabled; }
  static void SetSerialPortConnectedEnabled(bool enabled) { feature_states_[kSerialPortConnectedFlagIndex] = enabled; }
  static void SetServiceWorkerBackgroundSyncInDedicatedWorkerEnabled(bool enabled) { feature_states_[kServiceWorkerBackgroundSyncInDedicatedWorkerFlagIndex] = enabled; }
  static void SetServiceWorkerClientLifecycleStateEnabled(bool enabled) { feature_states_[kServiceWorkerClientLifecycleStateFlagIndex] = enabled; }
  static void SetServiceWorkerCodeCacheEnabled(bool enabled) { feature_states_[kServiceWorkerCodeCacheFlagIndex] = enabled; }
  static void SetServiceWorkerInDedicatedWorkerEnabled(bool enabled) { feature_states_[kServiceWorkerInDedicatedWorkerFlagIndex] = enabled; }
  static void SetServiceWorkerStaticRouterTimingInfoEnabled(bool enabled) { feature_states_[kServiceWorkerStaticRouterTimingInfoFlagIndex] = enabled; }
  static void SetSetHTMLCanRunScriptsEnabled(bool enabled) { feature_states_[kSetHTMLCanRunScriptsFlagIndex] = enabled; }
  static void SetSetSequentialFocusStartingPointEnabled(bool enabled) { feature_states_[kSetSequentialFocusStartingPointFlagIndex] = enabled; }
  static void SetSetShapeEnabled(bool enabled) { feature_states_[kSetShapeFlagIndex] = enabled; }
  static void SetShadowRootAdoptedStyleSheetEnabled(bool enabled) { feature_states_[kShadowRootAdoptedStyleSheetFlagIndex] = enabled; }
  static void SetShadowRootNamespaceCheckEnabled(bool enabled) { feature_states_[kShadowRootNamespaceCheckFlagIndex] = enabled; }
  static void SetShadowRootReferenceTargetEnabled(bool enabled) { feature_states_[kShadowRootReferenceTargetFlagIndex] = enabled; }
  static void SetShadowRootReferenceTargetAriaOwnsEnabled(bool enabled) { feature_states_[kShadowRootReferenceTargetAriaOwnsFlagIndex] = enabled; }
  static void SetShadowRootSlotAssignmentEnabled(bool enabled) { feature_states_[kShadowRootSlotAssignmentFlagIndex] = enabled; }
  static void SetSharedArrayBufferEnabled(bool enabled) { feature_states_[kSharedArrayBufferFlagIndex] = enabled; }
  static void SetSharedArrayBufferUnrestrictedAccessAllowedEnabled(bool enabled) { feature_states_[kSharedArrayBufferUnrestrictedAccessAllowedFlagIndex] = enabled; }
  static void SetSharedStorageAPIEnabled(bool enabled) { feature_states_[kSharedStorageAPIFlagIndex] = enabled; }
  static void SetSharedStorageWebLocksEnabled(bool enabled) { feature_states_[kSharedStorageWebLocksFlagIndex] = enabled; }
  static void SetSharedWorkerEnabled(bool enabled) { feature_states_[kSharedWorkerFlagIndex] = enabled; }
  static void SetSharedWorkerExtendedLifetimeEnabled(bool enabled) { feature_states_[kSharedWorkerExtendedLifetimeFlagIndex] = enabled; }
  static void SetSideRelativeBackgroundPositionEnabled(bool enabled) { feature_states_[kSideRelativeBackgroundPositionFlagIndex] = enabled; }
  static void SetSignatureBasedInlineIntegrityEnabled(bool enabled) { feature_states_[kSignatureBasedInlineIntegrityFlagIndex] = enabled; }
  static void SetSingleAxisScrollContainersEnabled(bool enabled) { feature_states_[kSingleAxisScrollContainersFlagIndex] = enabled; }
  static void SetSingleAxisScrollContainersForScrollSnapEnabled(bool enabled) { feature_states_[kSingleAxisScrollContainersForScrollSnapFlagIndex] = enabled; }
  static void SetSkipAdEnabled(bool enabled) { feature_states_[kSkipAdFlagIndex] = enabled; }
  static void SetSkipCallbacksWhenDevToolsNotOpenEnabled(bool enabled) { feature_states_[kSkipCallbacksWhenDevToolsNotOpenFlagIndex] = enabled; }
  static void SetSkipEventCaptureEnabled(bool enabled) { feature_states_[kSkipEventCaptureFlagIndex] = enabled; }
  static void SetSkipStaleUndoStepsInIdleSpellCheckEnabled(bool enabled) { feature_states_[kSkipStaleUndoStepsInIdleSpellCheckFlagIndex] = enabled; }
  static void SetSkipTouchEventFilterEnabled(bool enabled) { feature_states_[kSkipTouchEventFilterFlagIndex] = enabled; }
  static void SetSkipUnselectableElementsInParagraphBoundaryEnabled(bool enabled) { feature_states_[kSkipUnselectableElementsInParagraphBoundaryFlagIndex] = enabled; }
  static void SetSkipViewTransitionSnapshotResumeRenderingEnabled(bool enabled) { feature_states_[kSkipViewTransitionSnapshotResumeRenderingFlagIndex] = enabled; }
  static void SetSmallerViewportUnitsEnabled(bool enabled) { feature_states_[kSmallerViewportUnitsFlagIndex] = enabled; }
  static void SetSmartCardEnabled(bool enabled) { feature_states_[kSmartCardFlagIndex] = enabled; }
  static void SetSmartZoomEnabled(bool enabled) { feature_states_[kSmartZoomFlagIndex] = enabled; }
  static void SetSnapshotScrollTimelinesPostLayoutEnabled(bool enabled) { feature_states_[kSnapshotScrollTimelinesPostLayoutFlagIndex] = enabled; }
  static void SetSortedLayoutShiftSourcesByImpactAreaEnabled(bool enabled) { feature_states_[kSortedLayoutShiftSourcesByImpactAreaFlagIndex] = enabled; }
  static void SetSourceSpecificMulticastInDirectSocketsEnabled(bool enabled) { feature_states_[kSourceSpecificMulticastInDirectSocketsFlagIndex] = enabled; }
  static void SetSpatNavUsesCursorInheritanceEnabled(bool enabled) { feature_states_[kSpatNavUsesCursorInheritanceFlagIndex] = enabled; }
  static void SetSpeakerSelectionEnabled(bool enabled) { feature_states_[kSpeakerSelectionFlagIndex] = enabled; }
  static void SetSpecCompliantXmlMimeTypesEnabled(bool enabled) { feature_states_[kSpecCompliantXmlMimeTypesFlagIndex] = enabled; }
  static void SetSpeculationMeasurementEnabled(bool enabled) { feature_states_[kSpeculationMeasurementFlagIndex] = enabled; }
  static void SetSpeculationRulesModerateViewportHeuristicsControlEnabled(bool enabled) { feature_states_[kSpeculationRulesModerateViewportHeuristicsControlFlagIndex] = enabled; }
  static void SetSpellCheckChunkingEnabled(bool enabled) { feature_states_[kSpellCheckChunkingFlagIndex] = enabled; }
  static void SetSpellCheckCustomDictionaryAPIEnabled(bool enabled) { feature_states_[kSpellCheckCustomDictionaryAPIFlagIndex] = enabled; }
  static void SetSplitLargeTextNodesEnabled(bool enabled) { feature_states_[kSplitLargeTextNodesFlagIndex] = enabled; }
  static void SetSplitQualifiedNameOnFirstColonEnabled(bool enabled) { feature_states_[kSplitQualifiedNameOnFirstColonFlagIndex] = enabled; }
  static void SetSplitTextNotCleanupDummySpansEnabled(bool enabled) { feature_states_[kSplitTextNotCleanupDummySpansFlagIndex] = enabled; }
  static void SetSrcsetSelectionMatchesImageSetEnabled(bool enabled) { feature_states_[kSrcsetSelectionMatchesImageSetFlagIndex] = enabled; }
  static void SetStableBlinkFeaturesEnabled(bool enabled) { feature_states_[kStableBlinkFeaturesFlagIndex] = enabled; }
  static void SetStackingContextIsNotStackedEnabled(bool enabled) { feature_states_[kStackingContextIsNotStackedFlagIndex] = enabled; }
  static void SetStaleImageNaturalSizeDuringRevalidationEnabled(bool enabled) { feature_states_[kStaleImageNaturalSizeDuringRevalidationFlagIndex] = enabled; }
  static void SetStandardizedBrowserZoomEnabled(bool enabled) { feature_states_[kStandardizedBrowserZoomFlagIndex] = enabled; }
  static void SetStandardizedBrowserZoomOptOutEnabled(bool enabled) { feature_states_[kStandardizedBrowserZoomOptOutFlagIndex] = enabled; }
  static void SetStickyPositionHasOverflowPerAxisEnabled(bool enabled) { feature_states_[kStickyPositionHasOverflowPerAxisFlagIndex] = enabled; }
  static void SetStickyUserActivationAcrossSameOriginNavigationEnabled(bool enabled) { feature_states_[kStickyUserActivationAcrossSameOriginNavigationFlagIndex] = enabled; }
  static void SetStorageBucketsEnabled(bool enabled) { feature_states_[kStorageBucketsFlagIndex] = enabled; }
  static void SetStorageBucketsDurabilityEnabled(bool enabled) { feature_states_[kStorageBucketsDurabilityFlagIndex] = enabled; }
  static void SetStorageBucketsLocksEnabled(bool enabled) { feature_states_[kStorageBucketsLocksFlagIndex] = enabled; }
  static void SetStreamingSanitizerEnabled(bool enabled) { feature_states_[kStreamingSanitizerFlagIndex] = enabled; }
  static void SetStrictMimeTypesForWorkersEnabled(bool enabled) { feature_states_[kStrictMimeTypesForWorkersFlagIndex] = enabled; }
  static void SetStylusHandwritingEnabled(bool enabled) { feature_states_[kStylusHandwritingFlagIndex] = enabled; }
  static void SetSubAppsEnabled(bool enabled) { feature_states_[kSubAppsFlagIndex] = enabled; }
  static void SetSuppressPointerStreamAfterDragEnabled(bool enabled) { feature_states_[kSuppressPointerStreamAfterDragFlagIndex] = enabled; }
  static void SetSvgAnimateMotionDiscreteCalcModeEnabled(bool enabled) { feature_states_[kSvgAnimateMotionDiscreteCalcModeFlagIndex] = enabled; }
  static void SetSvgAvoidResettingFilterQualityForTiledPatternEnabled(bool enabled) { feature_states_[kSvgAvoidResettingFilterQualityForTiledPatternFlagIndex] = enabled; }
  static void SetSVGEmbeddedAsReplacedElementEnabled(bool enabled) { feature_states_[kSVGEmbeddedAsReplacedElementFlagIndex] = enabled; }
  static void SetSvgEmptyAttributeStringParsingFixEnabled(bool enabled) { feature_states_[kSvgEmptyAttributeStringParsingFixFlagIndex] = enabled; }
  static void SetSvgEnableTextDecorationCssStylingEnabled(bool enabled) { feature_states_[kSvgEnableTextDecorationCssStylingFlagIndex] = enabled; }
  static void SetSvgFallBackToContainerSizeEnabled(bool enabled) { feature_states_[kSvgFallBackToContainerSizeFlagIndex] = enabled; }
  static void SetSvgFeImageEXIFOrientationEnabled(bool enabled) { feature_states_[kSvgFeImageEXIFOrientationFlagIndex] = enabled; }
  static void SetSvgFeImageSkipHiddenContainerViewportDependenceEnabled(bool enabled) { feature_states_[kSvgFeImageSkipHiddenContainerViewportDependenceFlagIndex] = enabled; }
  static void SetSvgFilterPaintsForHiddenContentEnabled(bool enabled) { feature_states_[kSvgFilterPaintsForHiddenContentFlagIndex] = enabled; }
  static void SetSvgFilterUserSpaceViewportForSvgEnabled(bool enabled) { feature_states_[kSvgFilterUserSpaceViewportForSvgFlagIndex] = enabled; }
  static void SetSvgIgnoreNegativeEllipseRadiiEnabled(bool enabled) { feature_states_[kSvgIgnoreNegativeEllipseRadiiFlagIndex] = enabled; }
  static void SetSvgIgnoreOuterTransformsEnabled(bool enabled) { feature_states_[kSvgIgnoreOuterTransformsFlagIndex] = enabled; }
  static void SetSvgImageAnimationResetEnabled(bool enabled) { feature_states_[kSvgImageAnimationResetFlagIndex] = enabled; }
  static void SetSvgImageNonUniformScalingFixEnabled(bool enabled) { feature_states_[kSvgImageNonUniformScalingFixFlagIndex] = enabled; }
  static void SetSvgInlineRootPixelSnappingScaleAdjustmentEnabled(bool enabled) { feature_states_[kSvgInlineRootPixelSnappingScaleAdjustmentFlagIndex] = enabled; }
  static void SetSvgInstanceSyncOptimizationEnabled(bool enabled) { feature_states_[kSvgInstanceSyncOptimizationFlagIndex] = enabled; }
  static void SetSvgLengthResolveUnparsedValueEnabled(bool enabled) { feature_states_[kSvgLengthResolveUnparsedValueFlagIndex] = enabled; }
  static void SetSvgNewZoomEnabled(bool enabled) { feature_states_[kSvgNewZoomFlagIndex] = enabled; }
  static void SetSVGPathDataAPIEnabled(bool enabled) { feature_states_[kSVGPathDataAPIFlagIndex] = enabled; }
  static void SetSvgPathLengthCssPropertyEnabled(bool enabled) { feature_states_[kSvgPathLengthCssPropertyFlagIndex] = enabled; }
  static void SetSvgScriptElementAsyncAttributeEnabled(bool enabled) { feature_states_[kSvgScriptElementAsyncAttributeFlagIndex] = enabled; }
  static void SetSvgScriptFragmentAlreadyStartedEnabled(bool enabled) { feature_states_[kSvgScriptFragmentAlreadyStartedFlagIndex] = enabled; }
  static void SetSvgSizingWithPreserveAspectRatioNoneEnabled(bool enabled) { feature_states_[kSvgSizingWithPreserveAspectRatioNoneFlagIndex] = enabled; }
  static void SetSvgStyleElementReflectTypeAndMediaEnabled(bool enabled) { feature_states_[kSvgStyleElementReflectTypeAndMediaFlagIndex] = enabled; }
  static void SetSvgSupportMediaFragmentsEnabled(bool enabled) { feature_states_[kSvgSupportMediaFragmentsFlagIndex] = enabled; }
  static void SetSVGTextPathSideAttributeEnabled(bool enabled) { feature_states_[kSVGTextPathSideAttributeFlagIndex] = enabled; }
  static void SetSvgUseNestedResourceDocumentsEnabled(bool enabled) { feature_states_[kSvgUseNestedResourceDocumentsFlagIndex] = enabled; }
  static void SetSvgUseNestedResourceDocumentsDelayLoadEnabled(bool enabled) { feature_states_[kSvgUseNestedResourceDocumentsDelayLoadFlagIndex] = enabled; }
  static void SetSynthesizedKeyboardEventsForAccessibilityActionsEnabled(bool enabled) { feature_states_[kSynthesizedKeyboardEventsForAccessibilityActionsFlagIndex] = enabled; }
  static void SetSyntheticMouseHoverOverInactivePageEnabled(bool enabled) { feature_states_[kSyntheticMouseHoverOverInactivePageFlagIndex] = enabled; }
  static void SetSystemWakeLockEnabled(bool enabled) { feature_states_[kSystemWakeLockFlagIndex] = enabled; }
  static void SetTabAlignmentWithFloatsEnabled(bool enabled) { feature_states_[kTabAlignmentWithFloatsFlagIndex] = enabled; }
  static void SetTableCellBorderColorInheritEnabled(bool enabled) { feature_states_[kTableCellBorderColorInheritFlagIndex] = enabled; }
  static void SetTableDefaultBorderColorCurrentColorEnabled(bool enabled) { feature_states_[kTableDefaultBorderColorCurrentColorFlagIndex] = enabled; }
  static void SetTableIsAutoFixedLayoutEnabled(bool enabled) { feature_states_[kTableIsAutoFixedLayoutFlagIndex] = enabled; }
  static void SetTabSizeInRubyBaseEnabled(bool enabled) { feature_states_[kTabSizeInRubyBaseFlagIndex] = enabled; }
  static void SetTargetInShadowDeterminedBeforeListenerEnabled(bool enabled) { feature_states_[kTargetInShadowDeterminedBeforeListenerFlagIndex] = enabled; }
  static void SetTargetRangesForBackwardDeletionUnitEnabled(bool enabled) { feature_states_[kTargetRangesForBackwardDeletionUnitFlagIndex] = enabled; }
  static void SetTestBlinkFeatureDefaultEnabled(bool enabled) { feature_states_[kTestBlinkFeatureDefaultFlagIndex] = enabled; }
  static void SetTestFeatureEnabled(bool enabled) { feature_states_[kTestFeatureFlagIndex] = enabled; }
  static void SetTestFeatureDependentEnabled(bool enabled) { feature_states_[kTestFeatureDependentFlagIndex] = enabled; }
  static void SetTestFeatureForBrowserProcessReadWriteAccessOriginTrialEnabled(bool enabled) { feature_states_[kTestFeatureForBrowserProcessReadWriteAccessOriginTrialFlagIndex] = enabled; }
  static void SetTestFeatureImpliedEnabled(bool enabled) { feature_states_[kTestFeatureImpliedFlagIndex] = enabled; }
  static void SetTestFeatureProtectedEnabled(bool enabled);
  static void SetTestFeatureProtectedDependentEnabled(bool enabled);
  static void SetTestFeatureProtectedImpliedEnabled(bool enabled);
  static void SetTestFeatureStableEnabled(bool enabled) { feature_states_[kTestFeatureStableFlagIndex] = enabled; }
  static void SetTextAreaResizerFixedSizeEnabled(bool enabled) { feature_states_[kTextAreaResizerFixedSizeFlagIndex] = enabled; }
  static void SetTextAutoSpaceIgnoreRubyAnnotationEnabled(bool enabled) { feature_states_[kTextAutoSpaceIgnoreRubyAnnotationFlagIndex] = enabled; }
  static void SetTextBoxTrimForNestedListEnabled(bool enabled) { feature_states_[kTextBoxTrimForNestedListFlagIndex] = enabled; }
  static void SetTextBoxTrimOnInlineBoxEnabled(bool enabled) { feature_states_[kTextBoxTrimOnInlineBoxFlagIndex] = enabled; }
  static void SetTextDetectorEnabled(bool enabled) { feature_states_[kTextDetectorFlagIndex] = enabled; }
  static void SetTextEmphasisLetterSpacingEnabled(bool enabled) { feature_states_[kTextEmphasisLetterSpacingFlagIndex] = enabled; }
  static void SetTextEmphasisPositionAutoEnabled(bool enabled) { feature_states_[kTextEmphasisPositionAutoFlagIndex] = enabled; }
  static void SetTextEmphasisPunctuationExceptionsEnabled(bool enabled) { feature_states_[kTextEmphasisPunctuationExceptionsFlagIndex] = enabled; }
  static void SetTextEmphasisWithRubyEnabled(bool enabled) { feature_states_[kTextEmphasisWithRubyFlagIndex] = enabled; }
  static void SetTextFragmentAPIEnabled(bool enabled) { feature_states_[kTextFragmentAPIFlagIndex] = enabled; }
  static void SetTextFragmentIdentifiersEnabled(bool enabled) { feature_states_[kTextFragmentIdentifiersFlagIndex] = enabled; }
  static void SetTextFragmentTapOpensContextMenuEnabled(bool enabled) { feature_states_[kTextFragmentTapOpensContextMenuFlagIndex] = enabled; }
  static void SetTextIteratorExcludeAutofilledSelectFixEnabled(bool enabled) { feature_states_[kTextIteratorExcludeAutofilledSelectFixFlagIndex] = enabled; }
  static void SetTextMetricsBaselinesEnabled(bool enabled) { feature_states_[kTextMetricsBaselinesFlagIndex] = enabled; }
  static void SetTextOverflowClipWithSelectionEnabled(bool enabled) { feature_states_[kTextOverflowClipWithSelectionFlagIndex] = enabled; }
  static void SetTextOverflowStringEnabled(bool enabled) { feature_states_[kTextOverflowStringFlagIndex] = enabled; }
  static void SetTextScaleMetaTagEnabled(bool enabled) { feature_states_[kTextScaleMetaTagFlagIndex] = enabled; }
  static void SetTextSpacingTrimFallbackEnabled(bool enabled) { feature_states_[kTextSpacingTrimFallbackFlagIndex] = enabled; }
  static void SetTextSpacingTrimFallback2Enabled(bool enabled) { feature_states_[kTextSpacingTrimFallback2FlagIndex] = enabled; }
  static void SetTextSpacingTrimFallbackChwsEnabled(bool enabled) { feature_states_[kTextSpacingTrimFallbackChwsFlagIndex] = enabled; }
  static void SetTextStreamMethodEnabled(bool enabled) { feature_states_[kTextStreamMethodFlagIndex] = enabled; }
  static void SetTimelineTriggerEnabled(bool enabled) { feature_states_[kTimelineTriggerFlagIndex] = enabled; }
  static void SetTimerThrottlingForBackgroundTabsEnabled(bool enabled) { feature_states_[kTimerThrottlingForBackgroundTabsFlagIndex] = enabled; }
  static void SetTimestampBasedCLSTrackingEnabled(bool enabled) { feature_states_[kTimestampBasedCLSTrackingFlagIndex] = enabled; }
  static void SetTimeZoneChangeEventEnabled(bool enabled) { feature_states_[kTimeZoneChangeEventFlagIndex] = enabled; }
  static void SetTopicsAPIEnabled(bool enabled) { feature_states_[kTopicsAPIFlagIndex] = enabled; }
  static void SetTouchDragAndContextMenuEnabled(bool enabled) { feature_states_[kTouchDragAndContextMenuFlagIndex] = enabled; }
  static void SetTouchDragAndDropEnabled(bool enabled) { feature_states_[kTouchDragAndDropFlagIndex] = enabled; }
  static void SetTouchDragOnShortPressEnabled(bool enabled) { feature_states_[kTouchDragOnShortPressFlagIndex] = enabled; }
  static void SetTouchEventFeatureDetectionEnabled(bool enabled) { feature_states_[kTouchEventFeatureDetectionFlagIndex] = enabled; }
  static void SetTouchTextEditingRedesignEnabled(bool enabled) { feature_states_[kTouchTextEditingRedesignFlagIndex] = enabled; }
  static void SetTransferableRTCDataChannelEnabled(bool enabled) { feature_states_[kTransferableRTCDataChannelFlagIndex] = enabled; }
  static void SetTranslateServiceEnabled(bool enabled) { feature_states_[kTranslateServiceFlagIndex] = enabled; }
  static void SetTranslationAPIEnabled(bool enabled) { feature_states_[kTranslationAPIFlagIndex] = enabled; }
  static void SetTranslationAPIForWorkersEnabled(bool enabled) { feature_states_[kTranslationAPIForWorkersFlagIndex] = enabled; }
  static void SetTreatMhtmlInitialDocumentLoadsAsCrossDocumentEnabled(bool enabled) { feature_states_[kTreatMhtmlInitialDocumentLoadsAsCrossDocumentFlagIndex] = enabled; }
  static void SetTreeRubyPlacementEnabled(bool enabled) { feature_states_[kTreeRubyPlacementFlagIndex] = enabled; }
  static void SetTrustedTypesCreateParserOptionsEnabled(bool enabled) { feature_states_[kTrustedTypesCreateParserOptionsFlagIndex] = enabled; }
  static void SetTrustedTypesFromLiteralEnabled(bool enabled) { feature_states_[kTrustedTypesFromLiteralFlagIndex] = enabled; }
  static void SetTrustedTypesHTMLEnabled(bool enabled) { feature_states_[kTrustedTypesHTMLFlagIndex] = enabled; }
  static void SetTrustedTypesUseCodeLikeEnabled(bool enabled) { feature_states_[kTrustedTypesUseCodeLikeFlagIndex] = enabled; }
  static void SetTwoPhaseViewTransitionEnabled(bool enabled) { feature_states_[kTwoPhaseViewTransitionFlagIndex] = enabled; }
  static void SetUAImageReplacementAPIEnabled(bool enabled) { feature_states_[kUAImageReplacementAPIFlagIndex] = enabled; }
  static void SetUnboundedElementEnabled(bool enabled) { feature_states_[kUnboundedElementFlagIndex] = enabled; }
  static void SetUnboundedElementOnTheOpenWebEnabled(bool enabled) { feature_states_[kUnboundedElementOnTheOpenWebFlagIndex] = enabled; }
  static void SetUnclosedFormControlIsInvalidEnabled(bool enabled) { feature_states_[kUnclosedFormControlIsInvalidFlagIndex] = enabled; }
  static void SetUnexposedTaskIdsEnabled(bool enabled) { feature_states_[kUnexposedTaskIdsFlagIndex] = enabled; }
  static void SetUnprefixedSpeechRecognitionEnabled(bool enabled) { feature_states_[kUnprefixedSpeechRecognitionFlagIndex] = enabled; }
  static void SetUnrestrictedMeasureUserAgentSpecificMemoryEnabled(bool enabled) { feature_states_[kUnrestrictedMeasureUserAgentSpecificMemoryFlagIndex] = enabled; }
  static void SetUnrestrictedSharedArrayBufferEnabled(bool enabled) { feature_states_[kUnrestrictedSharedArrayBufferFlagIndex] = enabled; }
  static void SetUnrestrictedUsbEnabled(bool enabled) { feature_states_[kUnrestrictedUsbFlagIndex] = enabled; }
  static void SetUpdateComplexSafaAreaConstraintsEnabled(bool enabled) { feature_states_[kUpdateComplexSafaAreaConstraintsFlagIndex] = enabled; }
  static void SetUpdateSelectionOnNodeInsertionEnabled(bool enabled) { feature_states_[kUpdateSelectionOnNodeInsertionFlagIndex] = enabled; }
  static void SetURLPatternCompareComponentEnabled(bool enabled) { feature_states_[kURLPatternCompareComponentFlagIndex] = enabled; }
  static void SetURLPatternGenerateEnabled(bool enabled) { feature_states_[kURLPatternGenerateFlagIndex] = enabled; }
  static void SetURLSearchParamsHasAndDeleteMultipleArgsEnabled(bool enabled) { feature_states_[kURLSearchParamsHasAndDeleteMultipleArgsFlagIndex] = enabled; }
  static void SetUseBeginFramePresentationFeedbackEnabled(bool enabled) { feature_states_[kUseBeginFramePresentationFeedbackFlagIndex] = enabled; }
  static void SetUseLargestPaintedImageForLCPCandidateEnabled(bool enabled) { feature_states_[kUseLargestPaintedImageForLCPCandidateFlagIndex] = enabled; }
  static void SetUseLowQualityInterpolationEnabled(bool enabled) { feature_states_[kUseLowQualityInterpolationFlagIndex] = enabled; }
  static void SetUseOriginalDomOffsetsForOffsetMapEnabled(bool enabled) { feature_states_[kUseOriginalDomOffsetsForOffsetMapFlagIndex] = enabled; }
  static void SetUsePaintGeometryForIntersectionEnabled(bool enabled) { feature_states_[kUsePaintGeometryForIntersectionFlagIndex] = enabled; }
  static void SetUsePositionForPointInFlexibleBoxWithSingleChildElementEnabled(bool enabled) { feature_states_[kUsePositionForPointInFlexibleBoxWithSingleChildElementFlagIndex] = enabled; }
  static void SetUsePositionIfIsVisuallyEquivalentCandidateEnabled(bool enabled) { feature_states_[kUsePositionIfIsVisuallyEquivalentCandidateFlagIndex] = enabled; }
  static void SetUserActionPseudosStopAtTopLayerEnabled(bool enabled) { feature_states_[kUserActionPseudosStopAtTopLayerFlagIndex] = enabled; }
  static void SetUserDefinedEntryPointTimingEnabled(bool enabled) { feature_states_[kUserDefinedEntryPointTimingFlagIndex] = enabled; }
  static void SetUserMediaElementEnabled(bool enabled) { feature_states_[kUserMediaElementFlagIndex] = enabled; }
  static void SetUserMediaElementLegacyEnabled(bool enabled) { feature_states_[kUserMediaElementLegacyFlagIndex] = enabled; }
  static void SetUseShadowHostStyleCheckEditableEnabled(bool enabled) { feature_states_[kUseShadowHostStyleCheckEditableFlagIndex] = enabled; }
  static void SetUseUndoStepElementDispatchBeforeInputEnabled(bool enabled) { feature_states_[kUseUndoStepElementDispatchBeforeInputFlagIndex] = enabled; }
  static void SetV8IdleTasksEnabled(bool enabled) { feature_states_[kV8IdleTasksFlagIndex] = enabled; }
  static void SetVariableSystemFontSupportOnWindowsEnabled(bool enabled) { feature_states_[kVariableSystemFontSupportOnWindowsFlagIndex] = enabled; }
  static void SetVideoAutoFullscreenEnabled(bool enabled) { feature_states_[kVideoAutoFullscreenFlagIndex] = enabled; }
  static void SetVideoFrameMetadataBackgroundBlurEnabled(bool enabled) { feature_states_[kVideoFrameMetadataBackgroundBlurFlagIndex] = enabled; }
  static void SetVideoFrameMetadataRtpTimestampEnabled(bool enabled) { feature_states_[kVideoFrameMetadataRtpTimestampFlagIndex] = enabled; }
  static void SetVideoFullscreenOrientationLockEnabled(bool enabled) { feature_states_[kVideoFullscreenOrientationLockFlagIndex] = enabled; }
  static void SetVideoRotateToFullscreenEnabled(bool enabled) { feature_states_[kVideoRotateToFullscreenFlagIndex] = enabled; }
  static void SetVideoTrackGeneratorEnabled(bool enabled) { feature_states_[kVideoTrackGeneratorFlagIndex] = enabled; }
  static void SetVideoTrackGeneratorInWindowEnabled(bool enabled) { feature_states_[kVideoTrackGeneratorInWindowFlagIndex] = enabled; }
  static void SetVideoTrackGeneratorInWorkerEnabled(bool enabled) { feature_states_[kVideoTrackGeneratorInWorkerFlagIndex] = enabled; }
  static void SetViewportHeightClientHintHeaderEnabled(bool enabled) { feature_states_[kViewportHeightClientHintHeaderFlagIndex] = enabled; }
  static void SetViewportSegmentsEnabled(bool enabled) { feature_states_[kViewportSegmentsFlagIndex] = enabled; }
  static void SetViewTransitionDOMCallbackAfterCommitEnabled(bool enabled) { feature_states_[kViewTransitionDOMCallbackAfterCommitFlagIndex] = enabled; }
  static void SetViewTransitionLongCallbackTimeoutForTestingEnabled(bool enabled) { feature_states_[kViewTransitionLongCallbackTimeoutForTestingFlagIndex] = enabled; }
  static void SetVisibilityCollapseColumnEnabled(bool enabled) { feature_states_[kVisibilityCollapseColumnFlagIndex] = enabled; }
  static void SetVisualRectMappingFixForExpansionEnabled(bool enabled) { feature_states_[kVisualRectMappingFixForExpansionFlagIndex] = enabled; }
  static void SetWakeLockEnabled(bool enabled) { feature_states_[kWakeLockFlagIndex] = enabled; }
  static void SetWarnOnContentVisibilityRenderAccessEnabled(bool enabled) { feature_states_[kWarnOnContentVisibilityRenderAccessFlagIndex] = enabled; }
  static void SetWebAppInstallationEnabled(bool enabled) { feature_states_[kWebAppInstallationFlagIndex] = enabled; }
  static void SetWebAppLaunchQueueEnabled(bool enabled) { feature_states_[kWebAppLaunchQueueFlagIndex] = enabled; }
  static void SetWebAppScopeExtensionsEnabled(bool enabled) { feature_states_[kWebAppScopeExtensionsFlagIndex] = enabled; }
  static void SetWebAppScopeSystemAccentColorEnabled(bool enabled) { feature_states_[kWebAppScopeSystemAccentColorFlagIndex] = enabled; }
  static void SetWebAppTabStripEnabled(bool enabled) { feature_states_[kWebAppTabStripFlagIndex] = enabled; }
  static void SetWebAppTabStripCustomizationsEnabled(bool enabled) { feature_states_[kWebAppTabStripCustomizationsFlagIndex] = enabled; }
  static void SetWebAppTranslationsEnabled(bool enabled) { feature_states_[kWebAppTranslationsFlagIndex] = enabled; }
  static void SetWebAssemblyCustomDescriptorsV2Enabled(bool enabled) { feature_states_[kWebAssemblyCustomDescriptorsV2FlagIndex] = enabled; }
  static void SetWebAssemblyJSPromiseIntegrationEnabled(bool enabled) { feature_states_[kWebAssemblyJSPromiseIntegrationFlagIndex] = enabled; }
  static void SetWebAudioBypassOutputBufferingEnabled(bool enabled) { feature_states_[kWebAudioBypassOutputBufferingFlagIndex] = enabled; }
  static void SetWebAudioBypassOutputBufferingOptOutEnabled(bool enabled) { feature_states_[kWebAudioBypassOutputBufferingOptOutFlagIndex] = enabled; }
  static void SetWebAudioConfigurableRenderQuantumEnabled(bool enabled) { feature_states_[kWebAudioConfigurableRenderQuantumFlagIndex] = enabled; }
  static void SetWebAuthEnabled(bool enabled) { feature_states_[kWebAuthFlagIndex] = enabled; }
  static void SetWebAuthAuthenticatorAttachmentEnabled(bool enabled) { feature_states_[kWebAuthAuthenticatorAttachmentFlagIndex] = enabled; }
  static void SetWebAuthenticationAmbientEnabled(bool enabled) { feature_states_[kWebAuthenticationAmbientFlagIndex] = enabled; }
  static void SetWebAuthenticationAttestationFormatsEnabled(bool enabled) { feature_states_[kWebAuthenticationAttestationFormatsFlagIndex] = enabled; }
  static void SetWebAuthenticationCmtgKeyEnabled(bool enabled) { feature_states_[kWebAuthenticationCmtgKeyFlagIndex] = enabled; }
  static void SetWebAuthenticationCrossDeviceFallbackUrlEnabled(bool enabled) { feature_states_[kWebAuthenticationCrossDeviceFallbackUrlFlagIndex] = enabled; }
  static void SetWebAuthenticationRemoteDesktopSupportEnabled(bool enabled) { feature_states_[kWebAuthenticationRemoteDesktopSupportFlagIndex] = enabled; }
  static void SetWebAutocorrectByDefaultEnabled(bool enabled) { feature_states_[kWebAutocorrectByDefaultFlagIndex] = enabled; }
  static void SetWebBluetoothEnabled(bool enabled) { feature_states_[kWebBluetoothFlagIndex] = enabled; }
  static void SetWebBluetoothGetDevicesEnabled(bool enabled) { feature_states_[kWebBluetoothGetDevicesFlagIndex] = enabled; }
  static void SetWebBluetoothScanningEnabled(bool enabled) { feature_states_[kWebBluetoothScanningFlagIndex] = enabled; }
  static void SetWebBluetoothWatchAdvertisementsEnabled(bool enabled) { feature_states_[kWebBluetoothWatchAdvertisementsFlagIndex] = enabled; }
  static void SetWebBluetoothWorldIsolatedCacheEnabled(bool enabled) { feature_states_[kWebBluetoothWorldIsolatedCacheFlagIndex] = enabled; }
  static void SetWebCodecsVideoEncoderBuffersEnabled(bool enabled) { feature_states_[kWebCodecsVideoEncoderBuffersFlagIndex] = enabled; }
  static void SetWebCryptoPQCEnabled(bool enabled) { feature_states_[kWebCryptoPQCFlagIndex] = enabled; }
  static void SetWebGLDeveloperExtensionsEnabled(bool enabled) { feature_states_[kWebGLDeveloperExtensionsFlagIndex] = enabled; }
  static void SetWebGLDraftExtensionsEnabled(bool enabled) { feature_states_[kWebGLDraftExtensionsFlagIndex] = enabled; }
  static void SetWebGLDrawingBufferStorageEnabled(bool enabled) { feature_states_[kWebGLDrawingBufferStorageFlagIndex] = enabled; }
  static void SetWebGLOnWebGPUEnabled(bool enabled) { feature_states_[kWebGLOnWebGPUFlagIndex] = enabled; }
  static void SetWebGLToneMappingEnabled(bool enabled) { feature_states_[kWebGLToneMappingFlagIndex] = enabled; }
  static void SetWebGPUDeveloperFeaturesEnabled(bool enabled) { feature_states_[kWebGPUDeveloperFeaturesFlagIndex] = enabled; }
  static void SetWebGPUExperimentalFeaturesEnabled(bool enabled) { feature_states_[kWebGPUExperimentalFeaturesFlagIndex] = enabled; }
  static void SetWebGPUExperimentalResourceTableEnabled(bool enabled) { feature_states_[kWebGPUExperimentalResourceTableFlagIndex] = enabled; }
  static void SetWebGPUExternalImageHDRHeadroomEnabled(bool enabled) { feature_states_[kWebGPUExternalImageHDRHeadroomFlagIndex] = enabled; }
  static void SetWebGPUMapSyncOnWorkersEnabled(bool enabled) { feature_states_[kWebGPUMapSyncOnWorkersFlagIndex] = enabled; }
  static void SetWebGPUMultithreadDawnWireOnWorkersEnabled(bool enabled) { feature_states_[kWebGPUMultithreadDawnWireOnWorkersFlagIndex] = enabled; }
  static void SetWebHapticsEnabled(bool enabled) { feature_states_[kWebHapticsFlagIndex] = enabled; }
  static void SetWebHIDEnabled(bool enabled) { feature_states_[kWebHIDFlagIndex] = enabled; }
  static void SetWebHIDOnServiceWorkersEnabled(bool enabled) { feature_states_[kWebHIDOnServiceWorkersFlagIndex] = enabled; }
  static void SetWebHIDWorldIsolatedCacheEnabled(bool enabled) { feature_states_[kWebHIDWorldIsolatedCacheFlagIndex] = enabled; }
  static void SetWebIdentityDigitalCredentialsEnabled(bool enabled) { feature_states_[kWebIdentityDigitalCredentialsFlagIndex] = enabled; }
  static void SetWebIdentityDigitalCredentialsCreationEnabled(bool enabled) { feature_states_[kWebIdentityDigitalCredentialsCreationFlagIndex] = enabled; }
  static void SetWebIDLBigIntUsesToBigIntEnabled(bool enabled) { feature_states_[kWebIDLBigIntUsesToBigIntFlagIndex] = enabled; }
  static void SetWebMCPEnabled(bool enabled) { feature_states_[kWebMCPFlagIndex] = enabled; }
  static void SetWebMCPDeclarativeFileInputEnabled(bool enabled) { feature_states_[kWebMCPDeclarativeFileInputFlagIndex] = enabled; }
  static void SetWebMCPFormAssociatedCustomElementsEnabled(bool enabled) { feature_states_[kWebMCPFormAssociatedCustomElementsFlagIndex] = enabled; }
  static void SetWebMCPTestingEnabled(bool enabled) { feature_states_[kWebMCPTestingFlagIndex] = enabled; }
  static void SetWebNFCEnabled(bool enabled) { feature_states_[kWebNFCFlagIndex] = enabled; }
  static void SetWebOTPEnabled(bool enabled) { feature_states_[kWebOTPFlagIndex] = enabled; }
  static void SetWebOTPAssertionFeaturePolicyEnabled(bool enabled) { feature_states_[kWebOTPAssertionFeaturePolicyFlagIndex] = enabled; }
  static void SetWebPreferencesEnabled(bool enabled) { feature_states_[kWebPreferencesFlagIndex] = enabled; }
  static void SetWebPrintingEnabled(bool enabled) { feature_states_[kWebPrintingFlagIndex] = enabled; }
  static void SetWebRtcSctpSnapEnabled(bool enabled) { feature_states_[kWebRtcSctpSnapFlagIndex] = enabled; }
  static void SetWebSerialWorldIsolatedCacheEnabled(bool enabled) { feature_states_[kWebSerialWorldIsolatedCacheFlagIndex] = enabled; }
  static void SetWebShareEnabled(bool enabled) { feature_states_[kWebShareFlagIndex] = enabled; }
  static void SetWebSocketOptionBagEnabled(bool enabled) { feature_states_[kWebSocketOptionBagFlagIndex] = enabled; }
  static void SetWebSocketStreamEnabled(bool enabled) { feature_states_[kWebSocketStreamFlagIndex] = enabled; }
  static void SetWebSocketStreamStandardBinaryChunkTypeEnabled(bool enabled) { feature_states_[kWebSocketStreamStandardBinaryChunkTypeFlagIndex] = enabled; }
  static void SetWebSpeechRecognitionContextEnabled(bool enabled) { feature_states_[kWebSpeechRecognitionContextFlagIndex] = enabled; }
  static void SetWebSpeechTimestampsEnabled(bool enabled) { feature_states_[kWebSpeechTimestampsFlagIndex] = enabled; }
  static void SetWebSpeechUnspokenPunctuationEnabled(bool enabled) { feature_states_[kWebSpeechUnspokenPunctuationFlagIndex] = enabled; }
  static void SetWebTransportAnticipatedConcurrentIncomingStreamsEnabled(bool enabled) { feature_states_[kWebTransportAnticipatedConcurrentIncomingStreamsFlagIndex] = enabled; }
  static void SetWebTransportApplicationProtocolEnabled(bool enabled) { feature_states_[kWebTransportApplicationProtocolFlagIndex] = enabled; }
  static void SetWebTransportCongestionControlEnabled(bool enabled) { feature_states_[kWebTransportCongestionControlFlagIndex] = enabled; }
  static void SetWebTransportCreateStreamsBeforeReadyEnabled(bool enabled) { feature_states_[kWebTransportCreateStreamsBeforeReadyFlagIndex] = enabled; }
  static void SetWebTransportCustomCertificatesEnabled(bool enabled) { feature_states_[kWebTransportCustomCertificatesFlagIndex] = enabled; }
  static void SetWebTransportDatagramsReadableTypeEnabled(bool enabled) { feature_states_[kWebTransportDatagramsReadableTypeFlagIndex] = enabled; }
  static void SetWebTransportDatagramsWritableEnabled(bool enabled) { feature_states_[kWebTransportDatagramsWritableFlagIndex] = enabled; }
  static void SetWebTransportDrainingEnabled(bool enabled) { feature_states_[kWebTransportDrainingFlagIndex] = enabled; }
  static void SetWebTransportHeadersEnabled(bool enabled) { feature_states_[kWebTransportHeadersFlagIndex] = enabled; }
  static void SetWebTransportReceiveStreamEnabled(bool enabled) { feature_states_[kWebTransportReceiveStreamFlagIndex] = enabled; }
  static void SetWebTransportReliabilityEnabled(bool enabled) { feature_states_[kWebTransportReliabilityFlagIndex] = enabled; }
  static void SetWebTransportSendGroupEnabled(bool enabled) { feature_states_[kWebTransportSendGroupFlagIndex] = enabled; }
  static void SetWebTransportStatsEnabled(bool enabled) { feature_states_[kWebTransportStatsFlagIndex] = enabled; }
  static void SetWebUIBundledCodeCacheAsyncFetchEnabled(bool enabled) { feature_states_[kWebUIBundledCodeCacheAsyncFetchFlagIndex] = enabled; }
  static void SetWebUSBEnabled(bool enabled) { feature_states_[kWebUSBFlagIndex] = enabled; }
  static void SetWebUSBOnDedicatedWorkersEnabled(bool enabled) { feature_states_[kWebUSBOnDedicatedWorkersFlagIndex] = enabled; }
  static void SetWebUSBOnServiceWorkersEnabled(bool enabled) { feature_states_[kWebUSBOnServiceWorkersFlagIndex] = enabled; }
  static void SetWebViewEnvReorderFixEnabled(bool enabled) { feature_states_[kWebViewEnvReorderFixFlagIndex] = enabled; }
  static void SetWebVTTCueLayoutByPositionAlignmentEnabled(bool enabled) { feature_states_[kWebVTTCueLayoutByPositionAlignmentFlagIndex] = enabled; }
  static void SetWebVTTCueTightLineBoxEnabled(bool enabled) { feature_states_[kWebVTTCueTightLineBoxFlagIndex] = enabled; }
  static void SetWebVTTLineAndPositionAlignmentEnabled(bool enabled) { feature_states_[kWebVTTLineAndPositionAlignmentFlagIndex] = enabled; }
  static void SetWebVTTRegionsEnabled(bool enabled) { feature_states_[kWebVTTRegionsFlagIndex] = enabled; }
  static void SetWebXREnabled(bool enabled) { feature_states_[kWebXRFlagIndex] = enabled; }
  static void SetWebXREnabledFeaturesEnabled(bool enabled) { feature_states_[kWebXREnabledFeaturesFlagIndex] = enabled; }
  static void SetWebXRFrameRateEnabled(bool enabled) { feature_states_[kWebXRFrameRateFlagIndex] = enabled; }
  static void SetWebXRFrontFacingEnabled(bool enabled) { feature_states_[kWebXRFrontFacingFlagIndex] = enabled; }
  static void SetWebXRGPUBindingEnabled(bool enabled) { feature_states_[kWebXRGPUBindingFlagIndex] = enabled; }
  static void SetWebXRHitTestEntityTypesEnabled(bool enabled) { feature_states_[kWebXRHitTestEntityTypesFlagIndex] = enabled; }
  static void SetWebXRImageTrackingEnabled(bool enabled) { feature_states_[kWebXRImageTrackingFlagIndex] = enabled; }
  static void SetWebXRLayersEnabled(bool enabled) { feature_states_[kWebXRLayersFlagIndex] = enabled; }
  static void SetWebXRLayersCommonEnabled(bool enabled) { feature_states_[kWebXRLayersCommonFlagIndex] = enabled; }
  static void SetWebXRMediaBindingEnabled(bool enabled) { feature_states_[kWebXRMediaBindingFlagIndex] = enabled; }
  static void SetWebXRMeshDetectionEnabled(bool enabled) { feature_states_[kWebXRMeshDetectionFlagIndex] = enabled; }
  static void SetWebXRPlaneDetectionEnabled(bool enabled) { feature_states_[kWebXRPlaneDetectionFlagIndex] = enabled; }
  static void SetWebXRPoseMotionDataEnabled(bool enabled) { feature_states_[kWebXRPoseMotionDataFlagIndex] = enabled; }
  static void SetWebXRSpecParityEnabled(bool enabled) { feature_states_[kWebXRSpecParityFlagIndex] = enabled; }
  static void SetWebXRVisibilityMaskEnabled(bool enabled) { feature_states_[kWebXRVisibilityMaskFlagIndex] = enabled; }
  static void SetWheelEventMomentumEnabled(bool enabled) { feature_states_[kWheelEventMomentumFlagIndex] = enabled; }
  static void SetWindowDefaultStatusEnabled(bool enabled) { feature_states_[kWindowDefaultStatusFlagIndex] = enabled; }
  static void SetWindowOpenAlwaysOnTopEnabled(bool enabled) { feature_states_[kWindowOpenAlwaysOnTopFlagIndex] = enabled; }
  static void SetWordSkipSpacesPunctuationFixEnabled(bool enabled) { feature_states_[kWordSkipSpacesPunctuationFixFlagIndex] = enabled; }
  static void SetXMLNoExternalEntitiesEnabled(bool enabled) { feature_states_[kXMLNoExternalEntitiesFlagIndex] = enabled; }
  static void SetXMLParserReplaceLoneSurrogatesEnabled(bool enabled) { feature_states_[kXMLParserReplaceLoneSurrogatesFlagIndex] = enabled; }
  static void SetXMLParsingRustEnabled(bool enabled) { feature_states_[kXMLParsingRustFlagIndex] = enabled; }
  static void SetXMLRustForNonXsltEnabled(bool enabled) { feature_states_[kXMLRustForNonXsltFlagIndex] = enabled; }
  static void SetXMLSerializerConsistentDefaultNsDeclMatchingEnabled(bool enabled) { feature_states_[kXMLSerializerConsistentDefaultNsDeclMatchingFlagIndex] = enabled; }
  static void SetXMLViewerForIframesEnabled(bool enabled) { feature_states_[kXMLViewerForIframesFlagIndex] = enabled; }
  static void SetXSLTEnabled(bool enabled) { feature_states_[kXSLTFlagIndex] = enabled; }
  static void SetXSLTSpecialTrialEnabled(bool enabled) { feature_states_[kXSLTSpecialTrialFlagIndex] = enabled; }

 private:
  friend class RuntimeEnabledFeaturesTestHelpers;

  // Returns the `feature_states_` index of the non-protected feature named
  // `name`, or std::nullopt if there is no such feature. Shared by
  // SetFeatureEnabledFromString() and IsFeatureEnabledFromString() so that the
  // lookup tables only exist once.
  static std::optional<uint16_t> FindFeatureFlagIndex(std::string_view name);

  static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_mojo_js_enabled_;
  static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_mojo_js_test_enabled_;
  static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_protected_origin_trials_sample_api_enabled_;
  static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_protected_origin_trials_sample_api_dependent_enabled_;
  static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_protected_origin_trials_sample_api_implied_enabled_;
  static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_test_feature_protected_enabled_;
  static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_test_feature_protected_dependent_enabled_;
  static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_test_feature_protected_implied_enabled_;
};

class PLATFORM_EXPORT RuntimeEnabledFeatures : public RuntimeEnabledFeaturesBase {
  STATIC_ONLY(RuntimeEnabledFeatures);

  // Only the following friends are allowed to use the setters defined in the
  // protected section of RuntimeEnabledFeaturesBase. Normally, unit tests
  // should use the ScopedFeatureNameForTest classes defined in
  // platform/testing/runtime_enabled_features_test_helpers.h.
  friend class DevToolsEmulator;
  friend class InternalRuntimeFlags;
  friend class V8ContextSnapshotImpl;
  friend class WebRuntimeFeaturesBase;
  friend class WebRuntimeFeatures;
  friend class WebView;
  friend class RuntimeEnabledFeaturesTestTraits;
  friend class RuntimeProtectedEnabledFeaturesTestTraits;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_H_
