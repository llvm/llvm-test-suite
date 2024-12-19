cmake_minimum_required(VERSION 3.13.4)

include(CheckSymbolExists)


project(test-suite C CXX)

if("Fortran" IN_LIST TEST_SUITE_SUBDIRS)
  set(TEST_SUITE_FORTRAN_default ON)
else()
  set(TEST_SUITE_FORTRAN_default OFF)
endif()
option(TEST_SUITE_FORTRAN "Enable Fortran test suite" ${TEST_SUITE_FORTRAN_default})

if(TEST_SUITE_FORTRAN)
  enable_language(Fortran)
endif()

function(append value)
  foreach(variable ${ARGN})
    set(${variable} "${${variable}} ${value}" PARENT_SCOPE)
  endforeach(variable)
endfunction()

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
if(TEST_SUITE_FORTRAN)
    mark_as_advanced(CLEAR CMAKE_Fortran_COMPILER)
endif()

if(CMAKE_C_COMPILER_ID MATCHES "Clang" AND CMAKE_C_SIMULATE_ID MATCHES "MSVC")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /FIstdio.h")
endif()

# The files in cmake/caches often want to pass along additional flags to select
# the target architecture. Note that you should still use
# CMAKE_OSX_ARCHITECTURES and CMAKE_C_COMPILER_TARGET where possible.
set(TEST_SUITE_ARCH_FLAGS CACHE STRING
   "Extra flags to select target architecture.")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${TEST_SUITE_ARCH_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TEST_SUITE_ARCH_FLAGS}")
if(TEST_SUITE_FORTRAN)
  set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} ${TEST_SUITE_ARCH_FLAGS}")
endif()
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${TEST_SUITE_ARCH_FLAGS}")

set(LLVM_CODESIGNING_IDENTITY "" CACHE STRING
  "Sign executables and dylibs with the given identity or skip if empty (Darwin Only)")

add_definitions(-DNDEBUG)
option(TEST_SUITE_SUPPRESS_WARNINGS "Suppress all warnings" ON)
if(${TEST_SUITE_SUPPRESS_WARNINGS})
  if(NOT CMAKE_Fortran_COMPILER_ID STREQUAL "LLVMFlang")
    # NOTE: ATM (18/8/23) LLVM Flang does not support the -w flag.
    # FIXME: Don't use add_definitions to add compiler flags
    add_definitions(-w)
  endif()
endif()

# We want reproducible builds, so using __DATE__ and __TIME__ is bad
# FIXME: Add this unconditionally when flang starts supporting it.
if(NOT CMAKE_Fortran_COMPILER_ID STREQUAL "LLVMFlang")
  add_definitions(-Werror=date-time)
endif()

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

# Sanity check SIZEOF_VOID_P. This is sometimes empty when compiler detection
# failed, error out to avoid a mostly working but invalid setup.
if(NOT CMAKE_SIZEOF_VOID_P)
  message(FATAL_ERROR "CMAKE_SIZEOF_VOID_P is not defined")
endif()

# Remote configuration (will be set in lit.site.cfg)
set(TEST_SUITE_REMOTE_CLIENT "ssh" CACHE STRING "Remote execution client")
set(TEST_SUITE_REMOTE_HOST "" CACHE STRING "Remote execution host")
mark_as_advanced(TEST_SUITE_REMOTE_CLIENT)

if(TEST_SUITE_REMOTE_HOST)
  add_custom_target(rsync
    COMMAND ${PROJECT_SOURCE_DIR}/utils/rsync.sh
                ${TEST_SUITE_REMOTE_CLIENT}
                ${TEST_SUITE_REMOTE_HOST}
                ${PROJECT_BINARY_DIR}
    USES_TERMINAL
  )
endif()

# Run Under configuration for RunSafely.sh (will be set in lit.site.cfg)
set(TEST_SUITE_RUN_UNDER "" CACHE STRING "RunSafely.sh run-under (-u) parameter")

# User mode emulation configuration (e.g. running under qemu)
# (will be set in lit.site.cfg)
set(TEST_SUITE_USER_MODE_EMULATION NO CACHE BOOL
    "RUN_UNDER is used to run tests under emulation.")
# Set value to python style True/False
if (TEST_SUITE_USER_MODE_EMULATION)
  set(TEST_SUITE_USER_MODE_EMULATION "True")
else()
  set(TEST_SUITE_USER_MODE_EMULATION "False")
endif()


# run type/benchmark size configuration (mostly for SPEC at the moment)
set(TEST_SUITE_RUN_TYPE "train" CACHE STRING
    "Type of benchmark inputs (may be test,train or ref)")

get_filename_component(CMAKE_C_COMPILER_DIRECTORY ${CMAKE_C_COMPILER} DIRECTORY)

option(TEST_SUITE_COLLECT_CODE_SIZE "Measure code size of binaries" ON)
if(TEST_SUITE_COLLECT_CODE_SIZE)
  find_program(TEST_SUITE_LLVM_SIZE NAMES "llvm-size"
               HINTS ${CMAKE_C_COMPILER_DIRECTORY})
  mark_as_advanced(TEST_SUITE_LLVM_SIZE)
  if(TEST_SUITE_LLVM_SIZE STREQUAL "TEST_SUITE_LLVM_SIZE-NOTFOUND")
    message(FATAL_ERROR "llvm-size not found.
Make sure it is in your path or set TEST_SUITE_COLLECT_CODE_SIZE to OFF")
  endif()
endif()

option(TEST_SUITE_USE_IR_PGO
  "Use IR PGO instrumentation (requires TEST_SUITE_PROFILE_GENERATE)" OFF)

# Enable profile generate mode in lit. Note that this does not automatically
# add something like -fprofile-instr-generate to the compiler flags.
option(TEST_SUITE_PROFILE_GENERATE "Enable lit profile generate mode" OFF)
# Set value to python style True/False
if(TEST_SUITE_PROFILE_GENERATE)
  find_program(TEST_SUITE_LLVM_PROFDATA NAMES "llvm-profdata"
               HINTS ${CMAKE_C_COMPILER_DIRECTORY})
  mark_as_advanced(TEST_SUITE_LLVM_PROFDATA)
  if(TEST_SUITE_LLVM_PROFDATA STREQUAL "TEST_SUITE_LLVM_PROFDATA-NOTFOUND")
    message(FATAL_ERROR "llvm-profdata not found.
Make sure it is in your path or set TEST_SUITE_PROFILE_GENERATE to OFF")
  endif()

  set(TEST_SUITE_PROFILE_GENERATE "True")

  set(profile_instrumentation_flags -fprofile-instr-generate)
  if(TEST_SUITE_USE_IR_PGO)
    set(profile_instrumentation_flags -fprofile-generate)
  endif()

  list(APPEND CFLAGS   ${profile_instrumentation_flags})
  list(APPEND CXXFLAGS ${profile_instrumentation_flags})
  list(APPEND LDFLAGS  ${profile_instrumentation_flags})
else()
  set(TEST_SUITE_PROFILE_GENERATE "False")
endif()

option(TEST_SUITE_PROFILE_USE
      "Add apropriate -fprofile-instr-use to CFLAGS/CXXFLAGS for each benchmark"
      OFF)

# When running the test-suite in diagnosis mode, use these flags passed by
# LNT to gather data, for examples -ftime-report, or -mllvm -stats. This way
# the user specified CMAKE_C_FLAGS etc. need not be changed.
set(TEST_SUITE_DIAGNOSE_FLAGS CACHE STRING
   "Extra flags appended to CMAKE_C_FLAGS + CMAKE_CXX_FLAGS + CMAKE_Fortran_FLAGS")
set(TEST_SUITE_DIAGNOSE_LINKER_FLAGS CACHE STRING
    "Extra flags appended to CMAKE_EXE_LINKER_FLAGS")
mark_as_advanced(TEST_SUITE_DIAGNOSE_FLAGS TEST_SUITE_DIAGNOSE_LINKER_FLAGS)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${TEST_SUITE_DIAGNOSE_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TEST_SUITE_DIAGNOSE_FLAGS}")
if(TEST_SUITE_FORTRAN)
  set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} ${TEST_SUITE_DIAGNOSE_FLAGS}")
endif()

set(CMAKE_EXE_LINKER_FLAGS
    "${CMAKE_EXE_LINKER_FLAGS} ${TEST_SUITE_DIAGNOSE_LINKER_FLAGS}")

if (TESTSUITE_USE_LINKER)
    append("-fuse-ld=${TESTSUITE_USE_LINKER}"
    CMAKE_EXE_LINKER_FLAGS CMAKE_MODULE_LINKER_FLAGS CMAKE_SHARED_LINKER_FLAG)
endif()

# Append extra flags. These extra flags are mainly meant for cache files that
# want to apply flags that get not override even when the user manually
# specifies CMAKE_C_FLAGS and similar.
set(TEST_SUITE_EXTRA_C_FLAGS CACHE STRING "Extra flags for CMAKE_C_FLAGS")
set(TEST_SUITE_EXTRA_CXX_FLAGS CACHE STRING "Extra flags for CMAKE_CXX_FLAGS")
if(TEST_SUITE_FORTRAN)
  set(TEST_SUITE_EXTRA_Fortran_FLAGS CACHE STRING "Extra flags for CMAKE_Fortran_FLAGS")
endif()

set(TEST_SUITE_EXTRA_EXE_LINKER_FLAGS CACHE STRING
    "Extra flags for CMAKE_EXE_LINKER_FLAGS")
mark_as_advanced(TEST_SUITE_EXTRA_C_FLAGS, TEST_SUITE_EXTRA_CXX_FLAGS,
                 TEST_SUITE_EXTRA_EXE_LINKER_FLAGS)

if(TEST_SUITE_FORTRAN)
  mark_as_advanced(TEST_SUITE_EXTRA_Fortran_FLAGS TEST_SUITE_EXTRA_EXE_LINKER_FLAGS)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${TEST_SUITE_EXTRA_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TEST_SUITE_EXTRA_CXX_FLAGS}")
if(TEST_SUITE_FORTRAN)
  set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} ${TEST_SUITE_EXTRA_Fortran_FLAGS}")
endif()

set(CMAKE_EXE_LINKER_FLAGS
    "${CMAKE_EXE_LINKER_FLAGS} ${TEST_SUITE_EXTRA_EXE_LINKER_FLAGS}")

if(CMAKE_SYSTEM_NAME STREQUAL "AIX")
  # Use X/OPEN compatibility flag on AIX for C tests to avoid problems
  # with some versions of the system headers.
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_XOPEN_SOURCE=700")
  # On AIX, the environment variable 'OBJECT_MODE' specifies the bit
  # mode for compilation.
  if(DEFINED ENV{OBJECT_MODE})
    # Specify maximum data heap size on AIX for 32-bit programs.
    if($ENV{OBJECT_MODE} STREQUAL "32")
      set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-bmaxdata:0x80000000")
    endif()
  endif()
endif()

include(HandleCompilerRT)

include(TestSuite)
include(SingleMultiSource)
# Needs by External/sollve_vv.
find_package(OpenMP)
# Fortran Helper Modules
if(TEST_SUITE_FORTRAN)
  include(Fortran)
endif()

if(NOT DEFINED TARGET_OS)
  message(STATUS "Check target operating system - ${CMAKE_SYSTEM_NAME}")
  set(TARGET_OS ${CMAKE_SYSTEM_NAME})
endif()
if(NOT DEFINED ARCH)
  include(DetectArchitecture)
  detect_architecture(ARCH)
endif()
if(NOT DEFINED X86CPU_ARCH AND ARCH STREQUAL "x86")
  include(DetectArchitecture)
  detect_x86_cpu_architecture(X86CPU_ARCH)
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
       "Disable position independent executables and ASLR" ON)
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

# PowerPC/Linux needs -ffp-contract=off so that:
#     The outputs can be compared to gcc.
#     The outputs match the reference outputs.
if(ARCH STREQUAL "PowerPC")
  check_symbol_exists(_LP64 "" PPC_IS_PPC64_ENABLED)
  add_definitions(-ffp-contract=off)
endif()

find_program(TEST_SUITE_LIT NAMES "lit" "llvm-lit")
set(TEST_SUITE_LIT_FLAGS "-sv" CACHE STRING "Flags used when running lit")
mark_as_advanced(TEST_SUITE_LIT TEST_SUITE_LIT_FLAGS)
mark_as_advanced(TEST_SUITE_LIT)

add_subdirectory(tools)

# Turn on ignore whitespacing on WIN32 to avoid line-ending mismatch
if(TARGET_OS STREQUAL "Windows")
  set(FP_IGNOREWHITESPACE ON)
endif()

# Shortcut for the path to the fpcmp executable
set(FPCMP fpcmp-target)
if (TEST_SUITE_USER_MODE_EMULATION)
  set(FPCMP fpcmp)
endif()

add_subdirectory(litsupport)

option(TEST_SUITE_COLLECT_COMPILE_TIME
       "Measure compile time by wrapping compiler invocations in timeit" ON)
if(TEST_SUITE_COLLECT_COMPILE_TIME)
  set(CMAKE_C_COMPILE_OBJECT "${CMAKE_BINARY_DIR}/tools/timeit --summary <OBJECT>.time ${CMAKE_C_COMPILE_OBJECT}")
  set(CMAKE_CXX_COMPILE_OBJECT "${CMAKE_BINARY_DIR}/tools/timeit --summary <OBJECT>.time ${CMAKE_CXX_COMPILE_OBJECT}")
  set(CMAKE_C_LINK_EXECUTABLE "${CMAKE_BINARY_DIR}/tools/timeit --summary <TARGET>.link.time ${CMAKE_C_LINK_EXECUTABLE}")
  set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_BINARY_DIR}/tools/timeit --summary <TARGET>.link.time ${CMAKE_CXX_LINK_EXECUTABLE}")
endif()

option(TEST_SUITE_BENCHMARKING_ONLY "Only run the benchmarking only subset" OFF)

option(TEST_SUITE_COLLECT_STATS "Collect LLVM statistics" OFF)
if(TEST_SUITE_COLLECT_STATS)
  list(APPEND CFLAGS -save-stats=obj)
  list(APPEND CXXFLAGS -save-stats=obj)
  # Collect stats for LTO step too.
  if (${CMAKE_C_FLAGS} MATCHES ".*-flto.*" AND
      ${CMAKE_CXX_FLAGS} MATCHES ".*-flto.*")
    list(APPEND LDFLAGS -save-stats=obj)
  endif()
endif()

# Detect and include subdirectories
# This allows to: Place additional test-suites into the toplevel test-suite
# directory where they will be picked up automatically. Alternatively you may
# manually specify directories to include test-suites at external locations
# and to leave out some of the default ones.
if(NOT TEST_SUITE_SUBDIRS)
  file(GLOB sub_cmakelists RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} */CMakeLists.txt)
  set(TEST_SUITE_SUBDIRS "")
  foreach(entry ${sub_cmakelists})
    get_filename_component(subdir ${entry} DIRECTORY)
    list(APPEND TEST_SUITE_SUBDIRS ${subdir})
  endforeach()
  # Drop things we do not want to be automatically added.
  list(REMOVE_ITEM TEST_SUITE_SUBDIRS litsupport tools CTMark)
  if(NOT TEST_SUITE_FORTRAN)
    list(REMOVE_ITEM TEST_SUITE_SUBDIRS Fortran)
  endif()
  # Separately add tests for tools.
  list(APPEND TEST_SUITE_SUBDIRS tools/test)
  set(TEST_SUITE_SUBDIRS "${TEST_SUITE_SUBDIRS}")
endif()
set(TEST_SUITE_SUBDIRS "${TEST_SUITE_SUBDIRS}" CACHE STRING
    "Semicolon separated list of directories with CMakeLists.txt to include")

foreach(subdir ${TEST_SUITE_SUBDIRS})
  # When we add subdirs outside the toplevel source directory then we have to
  # make up a directory to use for the builddir.
  if(subdir MATCHES "^/" OR subdir MATCHES "\\.\\.")
    if(subdir MATCHES "/$")
      message(FATAL_ERROR "Subdir must not end in '/'")
    endif()
    get_filename_component(subdir_name ${subdir} NAME)
  else()
    set(subdir_name ${subdir})
  endif()
  message(STATUS "Adding directory ${subdir}")
  add_subdirectory(${subdir} ${subdir_name})
endforeach()

option(TEST_SUITE_RUN_BENCHMARKS "Actually run the benchmarks in lit" ON)

set(TEST_SUITE_EXTRA_LIT_MODULES "" CACHE STRING
    "Semicolon separated list of extra lit modules in use")
mark_as_advanced(TEST_SUITE_EXTRA_LIT_MODULES)
# Construct list testing modules (see also litsupport/modules/*.py)
set(LIT_MODULES ${TEST_SUITE_EXTRA_LIT_MODULES})
if(TEST_SUITE_RUN_BENCHMARKS)
  list(APPEND LIT_MODULES run)
endif()
if(TEST_SUITE_COLLECT_CODE_SIZE)
  list(APPEND LIT_MODULES codesize)
endif()
list(APPEND LIT_MODULES hash)
if(TEST_SUITE_COLLECT_COMPILE_TIME)
  list(APPEND LIT_MODULES compiletime)
endif()
if(TEST_SUITE_RUN_UNDER)
  list(APPEND LIT_MODULES run_under)
endif()
list(APPEND LIT_MODULES timeit)
if(TEST_SUITE_PROFILE_GENERATE)
  list(APPEND LIT_MODULES profilegen)
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
