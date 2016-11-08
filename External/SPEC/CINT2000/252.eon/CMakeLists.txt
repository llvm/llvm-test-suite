list(APPEND CPPFLAGS -include errno.h -include string.h -DHAS_ERRLIST -DUSE_STRERROR -DSPEC_STDCPP)
if(ARCH STREQUAL "PowerPC")
  list(APPEND CPPFLAGS -DFMAX_IS_DOUBLE)
endif()
list(APPEND CXXFLAGS -fno-exceptions -Wno-deprecated -fpermissive)
list(APPEND LDFLAGS -lm)

include_directories(${BENCHMARK_DIR}/src)

# There's more sourcefiles in the directory than necessary so enumerate the ones
# we want.
set(SourceNames
  ggCoverageSolidTexture.cc
  ggPathDielectricMaterial.cc
  ggBox2.cc
  ggBox3.cc
  ggRasterSurfaceTexture.cc
  ggJitterSample1.cc
  ggNRooksSample2.cc
  ggJitterSample2.cc
  ggRGBFPixel.cc
  ggRotatingPinholeCamera.cc
  ggRandomSample2.cc
  ggRandomSample3.cc
  ggSolidNoise2.cc
  ggSolidNoise3.cc
  ggSolidTexture.cc
  ggOakSolidTexture.cc
  ggSpecularMaterial.cc
  ggNA.cc
  ggMaterial.cc
  ggDiffuseMaterial.cc
  ggDielectricMaterial.cc
  ggConductorMaterial.cc
  ggEdgeDiscrepancy.cc
  ggPolishedMaterial.cc
  ggFrameInterpolation.cc
  ggQuaternion.cc
  ggSpline.cc
  ggONB2.cc
  ggONB3.cc
  ggFrame2.cc
  ggFrame3.cc
  ggHMatrix3.cc
  ggSphere.cc
  ggRGBE.cc
  ggGamma.cc
  ggBRDF.cc
  ggDiffuseBRDF.cc
  ggPhongBRDF.cc
  ggPolishedBRDF.cc
  ggCamera.cc
  ggPinholeCamera.cc
  ggThinLensCamera.cc
  ggErr.cc
  ggPixelFilter.cc
  ggTrianglePixelFilter.cc
  ggBoxPixelFilter.cc
  ggFormat.cc
  ggGeometry.cc
  ggHAffineMatrix3.cc
  ggHShearMatrix3.cc
  ggHBoxMatrix3.cc
  ggHPerspectiveMatrix3.cc
  ggHTranslationMatrix3.cc
  ggHRigidBodyMatrix3.cc
  ggHRotationMatrix3.cc
  ggHScaleMatrix3.cc
  ggHPoint3.cc
  ggPoint2.cc
  ggPoint3.cc
  ggOptics.cc
  ggPlane.cc
  ggPolygon.cc
  ggGrayPixel_x.cc
  ggRGBPixel_x.cc
  ggRay2.cc
  ggRay3.cc
  ggBoardFloorSolidTexture.cc
  ggVector2.cc
  ggVector3.cc
  ggString.cc
  ggFineSpectrum.cc
  ggSpectrum.cc
  eon.cc
  eonImageCalculator.cc
  mrObjectRecord.cc
  mrCoarsePixelRenderer.cc
  mrIndirectPixelRenderer.cc
  mrRushmeierPixelRenderer.cc
  mrBruteForcePixelRenderer.cc
  mrKajiyaPixelRenderer.cc
  mrCookPixelRenderer.cc
  mrGrid.cc
  mrScene.cc
  mrCamera.cc
  mrTriangle.cc
  mrFastTriangle.cc
  mrPolygon.cc
  mrXYDisk.cc
  mrXZDisk.cc
  mrYZDisk.cc
  mrPhongAreaXYRectangleLuminaire.cc
  mrPhongAreaXZRectangleLuminaire.cc
  mrPhongAreaYZRectangleLuminaire.cc
  mrEmitter.cc
  mrImposter.cc
  mrLinkedObjects.cc
  mrBox.cc
  mrXCylinder.cc
  mrYCylinder.cc
  mrZCylinder.cc
  mrDiffuseAreaZCylinderLuminaire.cc
  mrDiffuseCosineZCylinderLuminaire.cc
  mrDiffuseVisibleAreaZCylinderLuminaire.cc
  mrXEllipticalCylinder.cc
  mrYEllipticalCylinder.cc
  mrZEllipticalCylinder.cc
  mrSpotAreaXYDiskLuminaire.cc
  mrDiffuseAreaXYRectangleLuminaire.cc
  mrDiffuseAreaXZRectangleLuminaire.cc
  mrDiffuseAreaYZRectangleLuminaire.cc
  mrSurfaceList.cc
  mrDiffuseAreaTriangleLuminaire.cc
  mrDiffuseAreaSphereLuminaire.cc
  mrDiffuseCosineSphereLuminaire.cc
  mrDiffuseSolidAngleSphereLuminaire.cc
  mrShellLuminaire.cc
  mrInstance.cc
  mrMaterial.cc
  mrPhongAreaTriangleLuminaire.cc
  mrSolidTexture.cc
  mrSphere.cc
  mrSurface.cc
  mrSurfaceTexture.cc
  mrXYRectangle.cc
  mrXZRectangle.cc
  mrYZRectangle.cc
  myrand.cc
)
set(Source "")
foreach(FILENAME ${SourceNames})
  list(APPEND Source ${BENCHMARK_DIR}/src/${FILENAME})
endforeach()

macro(test_input run_type)
  set(INPUT_DIR ${BENCHMARK_DIR}/data/${run_type}/input)
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR ${INPUT_DIR}
    chair.control.cook chair.camera chair.surfaces
    ${CMAKE_CURRENT_BINARY_DIR}/chair.cook.ppm
    ppm
    ${CMAKE_CURRENT_BINARY_DIR}/pixels_out.cook
  )
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR ${INPUT_DIR}
    chair.control.rushmeier chair.camera chair.surfaces
    ${CMAKE_CURRENT_BINARY_DIR}/chair.rushmeier.ppm
    ppm
    ${CMAKE_CURRENT_BINARY_DIR}/pixels_out.rushmeier
  )
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR ${INPUT_DIR}
    chair.control.kajiya chair.camera chair.surfaces
    ${CMAKE_CURRENT_BINARY_DIR}/chair.kajiya.ppm
    ppm
    ${CMAKE_CURRENT_BINARY_DIR}/pixels_out.kajiya
  )

  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -a 0.005
    ${BENCHMARK_DIR}/data/${run_type}/output/pixels_out.cook
    ${CMAKE_CURRENT_BINARY_DIR}/pixels_out.cook
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -a 0.005
    ${BENCHMARK_DIR}/data/${run_type}/output/pixels_out.rushmeier
    ${CMAKE_CURRENT_BINARY_DIR}/pixels_out.rushmeier
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -a 0.005
    ${BENCHMARK_DIR}/data/${run_type}/output/pixels_out.kajiya
    ${CMAKE_CURRENT_BINARY_DIR}/pixels_out.kajiya
  )
endmacro()

test_input(ref)
test_input(train)
test_input(test)

llvm_test_executable(${PROG} ${Source})
