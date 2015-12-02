cmake_minimum_required(VERSION 3.2)

# The test-suite is designed to be built in release mode anyway and
# falls over unless -DNDEBUG is set.
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "No build type selected, defaulting to Release")
  set(CMAKE_BUILD_TYPE "Release")
endif()

add_definitions(-DNDEBUG)

project(test-suite C CXX)

# Add path for custom modules
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules"
  )

# Sanity check our source directory to make sure that we are not trying to
# generate an in-tree build (unless on MSVC_IDE, where it is ok), and to make
# sure that we don't have any stray generated files lying around in the tree
# (which would end up getting picked up by header search, instead of the correct
# versions).
if( CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR AND NOT MSVC_IDE )
  message(FATAL_ERROR "In-source builds are not allowed.
CMake would overwrite the makefiles distributed with LLVM.
Please create a directory and run cmake from there, passing the path
to this source directory as the last argument.
This process created the file `CMakeCache.txt' and the directory `CMakeFiles'.
Please delete them.")
endif()

# Remote configuration (will be set in lit.site.cfg)
set(TEST_SUITE_REMOTE_CLIENT "ssh" CACHE STRING "Remote execution client")
set(TEST_SUITE_REMOTE_HOST "" CACHE STRING "Remote execution host")
set(TEST_SUITE_REMOTE_USER "" CACHE STRING "Remote execution user")
set(TEST_SUITE_REMOTE_PORT "" CACHE STRING "Remote execution port")
mark_as_advanced(TEST_SUITE_REMOTE_USER TEST_SUITE_REMOTE_PORT)

include(MakefileFunctions)
include(SingleMultiSource)
find_package(YACC)
find_package(TCL)

if(NOT DEFINED TARGET_OS)
  message(STATUS "Check target operating system - ${CMAKE_SYSTEM_NAME}")
  set(TARGET_OS ${CMAKE_SYSTEM_NAME})
endif()
if(NOT DEFINED ARCH)
  include(DetectArchitecture)
  detect_architecture(ARCH)
endif()
if(NOT DEFINED ENDIAN)
  include(TestBigEndian)
  test_big_endian(IS_BIGENDIAN)
  if(IS_BIGENDIAN)
    set(ENDIAN "big")
  else()
    set(ENDIAN "little")
  endif()
endif()

add_subdirectory(tools)

# Now that the tools have been created, use tools/timeit to time all other compilations.
set(CMAKE_C_COMPILE_OBJECT "${CMAKE_BINARY_DIR}/tools/timeit --summary <OBJECT>.time ${CMAKE_C_COMPILE_OBJECT}")
set(CMAKE_CXX_COMPILE_OBJECT "${CMAKE_BINARY_DIR}/tools/timeit --summary <OBJECT>.time ${CMAKE_CXX_COMPILE_OBJECT}")

add_subdirectory(SingleSource)
add_subdirectory(MultiSource)

# Produce lit.site.cfg
configure_file("${CMAKE_SOURCE_DIR}/lit.site.cfg.in" "${CMAKE_BINARY_DIR}/lit.site.cfg")
