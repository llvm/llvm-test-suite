set(XCRUN_FLAGS --toolchain iOS --sdk iphoneos)
set(CMAKE_OSX_ARCHITECTURES thumbv7s CACHE STRING "")
include(${CMAKE_CURRENT_LIST_DIR}/util/xcode_sdk.cmake)
