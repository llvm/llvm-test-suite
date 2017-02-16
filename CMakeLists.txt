cmake_minimum_required(VERSION 3.4.3)

include(CheckSymbolExists)

project(test-suite C CXX)

# The test-suite is designed to be built in release mode anyway and
# falls over unless -DNDEBUG is set.
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "No build type selected, defaulting to Release")
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()
# Selecting installation directories or build types is untypical.
mark_as_advanced(CMAKE_INSTALL_PREFIX CMAKE_BUILD_TYPE)
# On the other hand we often want to switch compiler or cflags
mark_as_advanced(CLEAR CMAKE_C_COMPILER CMAKE_CXX_COMPILER CMAKE_LINKER
  CMAKE_C_FLAGS CMAKE_CXX_FLAGS CMAKE_EXE_LINKER_FLAGS)

# The files in cmake/caches often want to pass along additional flags to select
# the target architecture. Note that you should still use
# CMAKE_OSX_ARCHITECTURES and CMAKE_C_COMPILER_TARGET where possible.
set(TEST_SUITE_ARCH_FLAGS CACHE STRING
   "Extra flags to select target architecture.")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${TEST_SUITE_ARCH_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TEST_SUITE_ARCH_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${TEST_SUITE_ARCH_FLAGS}")

add_definitions(-DNDEBUG)
option(TEST_SUITE_SUPPRESS_WARNINGS "Suppress all warnings" ON)
if(${TEST_SUITE_SUPPRESS_WARNINGS})
  add_definitions(-w)
endif()

# We want reproducible builds, so using __DATE__ and __TIME__ is bad
add_definitions(-Werror=date-time)

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
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR AND NOT MSVC_IDE)
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
mark_as_advanced(TEST_SUITE_REMOTE_CLIENT TEST_SUITE_REMOTE_USER TEST_SUITE_REMOTE_PORT)

# Run Under configuration for RunSafely.sh (will be set in lit.site.cfg)
set(TEST_SUITE_RUN_UNDER "" CACHE STRING "RunSafely.sh run-under (-u) parameter")

# run type/benchmark size configuration (mostly for SPEC at the moment)
set(TEST_SUITE_RUN_TYPE "train" CACHE STRING
    "Type of benchmark inputs (may be test,train or ref)")

get_filename_component(CMAKE_C_COMPILER_DIRECTORY ${CMAKE_C_COMPILER} DIRECTORY)
find_program(TEST_SUITE_LLVM_SIZE NAMES "llvm-size"
             HINTS ${CMAKE_C_COMPILER_DIRECTORY})
find_program(TEST_SUITE_LLVM_PROFDATA NAMES "llvm-profdata"
             HINTS ${CMAKE_C_COMPILER_DIRECTORY})
mark_as_advanced(TEST_SUITE_LLVM_SIZE TEST_SUITE_LLVM_PROFDATA)

# Enable profile generate mode in lit. Note that this does not automatically
# add something like -fprofile-instr-generate to the compiler flags.
option(TEST_SUITE_PROFILE_GENERATE "Enable lit profile generate mode" Off)
# Set value to python style True/False
if(TEST_SUITE_PROFILE_GENERATE)
  set(TEST_SUITE_PROFILE_GENERATE "True")
  list(APPEND CFLAGS -fprofile-instr-generate)
  list(APPEND CXXFLAGS -fprofile-instr-generate)
  list(APPEND LDFLAGS -fprofile-instr-generate)
else()
  set(TEST_SUITE_PROFILE_GENERATE "False")
endif()

option(TEST_SUITE_PROFILE_USE
      "Add apropriate -fprofile-instr-use to CFLAGS/CXXFLAGS for each benchmark"
      Off)

# When running the test-suite in diagnosis mode, use these flags passed by
# LNT to gather data, for examples -ftime-report, or -mllvm -stats. This way
# the user specified CMAKE_C_FLAGS etc. need not be changed.
set(TEST_SUITE_DIAGNOSE_FLAGS CACHE STRING
   "Extra flags appended to CMAKE_C_FLAGS + CMAKE_CXX_FLAGS")
set(TEST_SUITE_DIAGNOSE_LINKER_FLAGS CACHE STRING
    "Extra flags appended to CMAKE_EXE_LINKER_FLAGS")
mark_as_advanced(TEST_SUITE_DIAGNOSE_FLAGS TEST_SUITE_DIAGNOSE_LINKER_FLAGS)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${TEST_SUITE_DIAGNOSE_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TEST_SUITE_DIAGNOSE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS
    "${CMAKE_EXE_LINKER_FLAGS} ${TEST_SUITE_DIAGNOSE_LINKER_FLAGS}")

include(TestSuite)
include(SingleMultiSource)
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

# Disabling address space randomization makes the performance of memory/cache
# intensive benchmarks more deterministic.
option(TEST_SUITE_DISABLE_PIE
       "Disable position independent executables and ASLR" On)
mark_as_advanced(TEST_SUITE_DISABLE_PIE)
if(TEST_SUITE_DISABLE_PIE)
  if(APPLE AND NOT ARCH STREQUAL "AArch64")
    list(APPEND LDFLAGS -Wl,-no_pie)
  endif()
  # TODO: Add apropriate flags to disable PIE/ASLR on linux, bsd, ...
endif()

if(ARCH STREQUAL "Mips")
  check_symbol_exists(__mips16 "" MIPS_IS_MIPS16_ENABLED)
  check_symbol_exists(__mips64 "" MIPS_IS_MIPS64_ENABLED)
endif()

find_program(TEST_SUITE_LIT NAMES "lit" "llvm-lit")
set(TEST_SUITE_LIT_FLAGS "-sv" CACHE STRING "Flags used when running lit")
mark_as_advanced(TEST_SUITE_LIT TEST_SUITE_LIT_FLAGS)
mark_as_advanced(TEST_SUITE_LIT)

add_subdirectory(tools)
# Shortcut for the path to the fpcmp executable
set(FPCMP ${CMAKE_BINARY_DIR}/tools/fpcmp)

option(TEST_SUITE_TAKE_COMPILE_TIME
       "Measure compile time by wrapping compiler invocations in timeit" On)
mark_as_advanced(TEST_SUITE_TAKE_COMPILE_TIME)
if(TEST_SUITE_TAKE_COMPILE_TIME)
  set(CMAKE_C_COMPILE_OBJECT "${CMAKE_BINARY_DIR}/tools/timeit --summary <OBJECT>.time ${CMAKE_C_COMPILE_OBJECT}")
  set(CMAKE_CXX_COMPILE_OBJECT "${CMAKE_BINARY_DIR}/tools/timeit --summary <OBJECT>.time ${CMAKE_CXX_COMPILE_OBJECT}")
  set(CMAKE_C_LINK_EXECUTABLE "${CMAKE_BINARY_DIR}/tools/timeit --summary <TARGET>.link.time ${CMAKE_C_LINK_EXECUTABLE}")
  set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_BINARY_DIR}/tools/timeit --summary <TARGET>.link.time ${CMAKE_CXX_LINK_EXECUTABLE}")
endif()

option(TEST_SUITE_BENCHMARKING_ONLY "Only run the benchmarking only subset" Off)

option(TEST_SUITE_COLLECT_STATS "Collect LLVM statistics" Off)
if(TEST_SUITE_COLLECT_STATS)
  list(APPEND CFLAGS -save-stats=obj)
  list(APPEND CXXFLAGS -save-stats=obj)
endif()

# Detect and include subdirectories
# This allows to: Place additional test-suites into the toplevel test-suite
# directory where they will be picked up automatically. Alternatively you may
# manually specify directories to include test-suites at external locations
# and to leave out some of the default ones.
if(NOT TEST_SUITE_SUBDIRS)
  file(GLOB sub_cmakelists */CMakeLists.txt)
  set(TEST_SUITE_SUBDIRS "")
  foreach(entry ${sub_cmakelists})
    get_filename_component(subdir ${entry} DIRECTORY)
    # Exclude tools and CTMark from default list
    if(NOT ${subdir} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR}/tools AND
       NOT ${subdir} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR}/CTMark)
      list(APPEND TEST_SUITE_SUBDIRS ${subdir})
    endif()
  endforeach()
  set(TEST_SUITE_SUBDIRS "${TEST_SUITE_SUBDIRS}" CACHE STRING
      "Semicolon separated list of directories with CMakeLists.txt to include")
endif()
mark_as_advanced(TEST_SUITE_SUBDIRS)

foreach(subdir ${TEST_SUITE_SUBDIRS})
  message(STATUS "Adding directory ${subdir}")
  add_subdirectory(${subdir})
endforeach()

option(TEST_SUITE_RUN_BENCHMARKS "Actually run the benchmarks in lit" On)

set(LIT_MODULES "")
if(TEST_SUITE_RUN_BENCHMARKS)
  list(APPEND LIT_MODULES run)
endif()
list(APPEND LIT_MODULES codesize)
list(APPEND LIT_MODULES hash)
if(TEST_SUITE_TAKE_COMPILE_TIME)
  list(APPEND LIT_MODULES compiletime)
endif()
if(TEST_SUITE_RUN_UNDER)
  list(APPEND LIT_MODULES run_under)
endif()
list(APPEND LIT_MODULES timeit)
if(TEST_SUITE_PROFILE_GENERATE)
  list(APPEND LIT_MODULES profilegen)
endif()
if(TEST_SUITE_REMOTE_HOST)
  list(APPEND LIT_MODULES remote)
endif()
if(TEST_SUITE_COLLECT_STATS)
  list(APPEND LIT_MODULES stats)
endif()

# Produce lit.site.cfg
configure_file("${PROJECT_SOURCE_DIR}/lit.site.cfg.in" "${CMAKE_BINARY_DIR}/lit.site.cfg")

get_property(TEST_SUITE_TARGETS GLOBAL PROPERTY TEST_SUITE_TARGETS)
add_custom_target(check
  COMMAND ${TEST_SUITE_LIT} ${TEST_SUITE_LIT_FLAGS} .
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS ${TEST_SUITE_TARGETS}
  USES_TERMINAL
  )
