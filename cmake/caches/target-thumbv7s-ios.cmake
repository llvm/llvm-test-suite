set(XCRUN_FLAGS --toolchain iOS --sdk iphoneos)
set(ARCH_FLAGS "${ARCH_FLAGS} -arch thumbv7s")
include(${CMAKE_CURRENT_LIST_DIR}/util/xcode_sdk.cmake)
