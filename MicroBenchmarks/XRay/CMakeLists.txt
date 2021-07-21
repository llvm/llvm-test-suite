include(CheckIncludeFiles)

check_cxx_compiler_flag(-fxray-instrument COMPILER_HAS_FXRAY_INSTRUMENT)
check_include_files("xray/xray_interface.h" HAVE_XRAY_INTERFACE_INCLUDE LANGUAGE CXX)

if(COMPILER_HAS_FXRAY_INSTRUMENT AND HAVE_XRAY_INTERFACE_INCLUDE AND ARCH STREQUAL "x86" AND NOT TARGET_OS STREQUAL "Darwin")
  message(STATUS "XRay tests enabled")

  add_subdirectory(ReturnReference)
  add_subdirectory(FDRMode)
else()
  message(STATUS "Compiler does not support XRay; tests disabled")
endif()
