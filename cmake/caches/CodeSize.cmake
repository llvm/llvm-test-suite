# Use -Os, don't increase code size.

set(CMAKE_C_FLAGS_RELEASE "-Os" CACHE STRING "")
set(CMAKE_CXX_FLAGS_RELEASE "-Os" CACHE STRING "")
set(CMAKE_BUILD_TYPE "Release" CACHE STRING "")
