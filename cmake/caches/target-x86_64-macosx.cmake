set(XCRUN_FLAGS --sdk macosx)
set(CMAKE_OSX_ARCHITECTURES x86_64 CACHE STRING "")
include(${CMAKE_CURRENT_LIST_DIR}/util/xcode_sdk.cmake)
