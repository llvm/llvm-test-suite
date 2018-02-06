set(XCRUN_FLAGS --toolchain iOS --sdk iphoneos.internal)
set(CMAKE_OSX_ARCHITECTURES arm64 CACHE STRING "")
include(${CMAKE_CURRENT_LIST_DIR}/util/xcode_sdk.cmake)
