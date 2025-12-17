# CMake module for integrating hip-tests Catch tests into llvm-test-suite
# This module provides functions to discover and build Catch-based HIP tests

include(CMakeParseArguments)

# Global variables for Catch test configuration
set(ENABLE_HIP_CATCH_TESTS OFF CACHE BOOL "Enable HIP Catch test framework and all catch test targets")
set(CATCH_TEST_CATEGORIES "unit" CACHE STRING "Semicolon-separated list of test categories to include (unit;stress;performance;perftests)")
set(CATCH_TEST_SUBDIRS "" CACHE STRING "Semicolon-separated list of test subdirectories to include (e.g., compiler;memory;stream). Empty means all subdirectories within enabled categories.")
set(HIP_CATCH_TEST_TIMEOUT 60 CACHE STRING "Timeout for individual Catch tests in seconds")
set(HIP_CATCH_TEST_VERBOSE OFF CACHE BOOL "Show verbose output with individual TEST_CASE results from Catch2")

# Local paths for Catch test infrastructure
set(HIP_CATCH_TESTS_DIR "${CMAKE_CURRENT_LIST_DIR}/catch")

# Try to find system-installed Catch2 v2.13.10+
# Note: v2.13.10 is used because v2.13.4 has glibc 2.34+ incompatibility (MINSIGSTKSZ issue)
find_package(Catch2 2.13.10 QUIET)

if(Catch2_FOUND)
  message(STATUS "Using system Catch2: ${Catch2_DIR}")
  get_target_property(CATCH2_INCLUDE_PATH Catch2::Catch2 INTERFACE_INCLUDE_DIRECTORIES)
else()
  message(STATUS "Catch2 >= 2.13.10 not found on system, fetching v2.13.10...")
  include(FetchContent)
  FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v2.13.10
    GIT_SHALLOW    TRUE
  )
  FetchContent_MakeAvailable(Catch2)
  set(CATCH2_INCLUDE_PATH "${catch2_SOURCE_DIR}/single_include/catch2")
endif()

set(CATCH2_FOUND TRUE)

# Global tracking for hierarchical targets
# These will be set as GLOBAL properties to track across function calls
define_property(GLOBAL PROPERTY CATCH_ALL_VARIANTS
  BRIEF_DOCS "List of all discovered HIP variants"
  FULL_DOCS "Tracks all variant suffixes (e.g., hip-7.2.0) discovered during configuration")

define_property(GLOBAL PROPERTY CATCH_CATEGORY_TARGETS_CREATED
  BRIEF_DOCS "List of categories for which aggregated targets have been created"
  FULL_DOCS "Prevents duplicate target creation for category-level aggregated targets")

define_property(GLOBAL PROPERTY CATCH_SUBDIR_TARGETS_CREATED
  BRIEF_DOCS "List of category-subdir pairs for which aggregated targets have been created"
  FULL_DOCS "Prevents duplicate target creation for subdirectory-level aggregated targets")

# Function to validate Catch test infrastructure
function(validate_catch_tests_infrastructure)
  set(_required_paths
    "${HIP_CATCH_TESTS_DIR}/unit/compiler"
    "${HIP_CATCH_TESTS_DIR}/external/picojson/picojson.h"
    "${HIP_CATCH_TESTS_DIR}/hipTestMain"
    "${HIP_CATCH_TESTS_DIR}/include"
  )
  # Note: Catch2 is now obtained via find_package or FetchContent, not vendored
  # Note: kernels/ directory not required for unit/compiler tests

  foreach(_path ${_required_paths})
    if(NOT EXISTS "${_path}")
      message(FATAL_ERROR "Required Catch test path not found: ${_path}")
    endif()
  endforeach()

  message(STATUS "Using local Catch test infrastructure: ${HIP_CATCH_TESTS_DIR}")
  message(STATUS "Catch2 include path: ${CATCH2_INCLUDE_PATH}")
endfunction()

# Function to discover test sources from hip-tests
# Arguments:
#   CATEGORY - Test category (unit, stress, performance, perftests)
#   SUBDIRS  - Specific subdirectories to include (optional, default: all)
# Returns:
#   Sets ${CATEGORY}_TEST_DIRS in parent scope
function(discover_catch_test_category CATEGORY)
  set(options)
  set(oneValueArgs)
  set(multiValueArgs SUBDIRS)
  cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  set(_catch_base "${HIP_CATCH_TESTS_DIR}/${CATEGORY}")

  if(NOT IS_DIRECTORY "${_catch_base}")
    message(STATUS "Category ${CATEGORY} not found in Catch tests, skipping")
    return()
  endif()

  # If specific subdirectories requested via argument, use them;
  # otherwise check CATCH_TEST_SUBDIRS cache variable;
  # otherwise discover all
  if(ARG_SUBDIRS)
    set(_test_subdirs ${ARG_SUBDIRS})
  elseif(CATCH_TEST_SUBDIRS)
    # Use subdirectories from CATCH_TEST_SUBDIRS, filtering to only those that exist
    set(_test_subdirs "")
    foreach(_subdir ${CATCH_TEST_SUBDIRS})
      if(IS_DIRECTORY "${_catch_base}/${_subdir}")
        list(APPEND _test_subdirs "${_subdir}")
        message(STATUS "Including subdirectory from CATCH_TEST_SUBDIRS: ${CATEGORY}/${_subdir}")
      else()
        message(STATUS "Subdirectory ${CATEGORY}/${_subdir} not found, skipping")
      endif()
    endforeach()
  else()
    # Discover all subdirectories automatically.
    file(GLOB _potential_subdirs RELATIVE "${_catch_base}" "${_catch_base}/*")
    set(_test_subdirs "")
    foreach(_subdir ${_potential_subdirs})
      if(IS_DIRECTORY "${_catch_base}/${_subdir}")
        # Check if directory has any .cc test files
        file(GLOB _test_files "${_catch_base}/${_subdir}/*.cc")
        if(_test_files)
          list(APPEND _test_subdirs "${_subdir}")
        endif()
      endif()
    endforeach()
  endif()

  if(_test_subdirs)
    message(STATUS "Discovered ${CATEGORY} test subdirectories: ${_test_subdirs}")
  else()
    message(STATUS "No test subdirectories found for ${CATEGORY} category")
  endif()
  set(${CATEGORY}_TEST_DIRS "${_test_subdirs}" PARENT_SCOPE)
endfunction()

# Helper function to track test targets at multiple levels
# Arguments:
#   TEST_TARGET  - The test target name (e.g., catch_unit_compiler-hip-7.2.0.test)
#   CATEGORY     - Category name (e.g., unit)
#   SUBDIR       - Subdirectory name (e.g., compiler)
#   VARIANT      - Variant suffix (e.g., hip-7.2.0)
function(track_test_target_multi_level TEST_TARGET CATEGORY SUBDIR VARIANT)
  # Track at global level (all catch tests)
  set_property(GLOBAL APPEND PROPERTY CATCH_ALL_TEST_TARGETS "${TEST_TARGET}")

  # Track at per-variant global level
  set_property(GLOBAL APPEND PROPERTY "CATCH_TEST_TARGETS_${VARIANT}" "${TEST_TARGET}")

  # Track at per-category level (all variants)
  set_property(GLOBAL APPEND PROPERTY "CATCH_${CATEGORY}_TEST_TARGETS" "${TEST_TARGET}")

  # Track at per-category-variant level
  set_property(GLOBAL APPEND PROPERTY "CATCH_${CATEGORY}_TEST_TARGETS_${VARIANT}" "${TEST_TARGET}")

  # Track at per-subdirectory level (all variants)
  set_property(GLOBAL APPEND PROPERTY "CATCH_${CATEGORY}_${SUBDIR}_TEST_TARGETS" "${TEST_TARGET}")

  # Track at per-subdirectory-variant level
  set_property(GLOBAL APPEND PROPERTY "CATCH_${CATEGORY}_${SUBDIR}_TEST_TARGETS_${VARIANT}" "${TEST_TARGET}")
endfunction()

# Function to create special generic target executables for hipSquareGenericTarget test
# This test requires additional executables built with generic-only offload architectures
# Arguments:
#   TEST_BASENAME  - Base name of the test (e.g., hipSquareGenericTarget)
#   TEST_DIR       - Directory containing the test sources
#   VARIANT_SUFFIX - Variant suffix (e.g., hip-7.2.0)
#   ROCM_PATH      - Path to ROCm installation
function(create_generic_target_executables TEST_BASENAME TEST_DIR VARIANT_SUFFIX ROCM_PATH)
  # Check if this is AMD platform (generic targets are AMD-specific)
  get_filename_component(_compiler_name "${CMAKE_CXX_COMPILER}" NAME)
  if(NOT (_compiler_name MATCHES "hipcc" OR _compiler_name MATCHES "clang"))
    message(STATUS "Skipping generic target executables (not AMD platform)")
    return()
  endif()

  message(STATUS "Creating generic target executables for ${TEST_BASENAME}-${VARIANT_SUFFIX}")

  # Generic target architecture flags
  set(_generic_archs
    "--offload-arch=gfx9-generic"
    "--offload-arch=gfx9-4-generic:sramecc+:xnack-"
    "--offload-arch=gfx9-4-generic:sramecc-:xnack-"
    "--offload-arch=gfx9-4-generic:xnack+"
    "--offload-arch=gfx10-1-generic"
    "--offload-arch=gfx10-3-generic"
    "--offload-arch=gfx11-generic"
    "--offload-arch=gfx12-generic"
  )

  set(_source_file "${TEST_DIR}/${TEST_BASENAME}.cc")
  set(_output_dir "${CMAKE_CURRENT_BINARY_DIR}/catch_tests")

  # Common source files
  set(_common_sources
    "${_source_file}"
    "${HIP_CATCH_TESTS_DIR}/hipTestMain/hip_test_context.cc"
    "${HIP_CATCH_TESTS_DIR}/hipTestMain/hip_test_features.cc"
    "${HIP_CATCH_TESTS_DIR}/hipTestMain/main.cc"
  )

  # Common include directories
  set(_include_flags
    "-I${ROCM_PATH}/include"
    "-I${HIP_CATCH_TESTS_DIR}/include"
    "-I${CATCH2_INCLUDE_PATH}"
    "-I${HIP_CATCH_TESTS_DIR}/external/picojson"
  )

  # Determine library linking flags
  if(WIN32)
    set(_libfs_flag "")
    set(_exe_suffix ".exe")
  else()
    set(_libfs_flag "-lstdc++fs")
    set(_exe_suffix "")
  endif()

  # 1. Build hipSquareGenericTargetOnly (regular fatbin with generic targets only)
  set(_exe_name_regular "hipSquareGenericTargetOnly${_exe_suffix}")
  set(_output_path_regular "${_output_dir}/${_exe_name_regular}")

  add_custom_command(
    OUTPUT "${_output_path_regular}"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${_output_dir}"
    COMMAND ${CMAKE_CXX_COMPILER}
      -DNO_GENERIC_TARGET_ONLY_TEST
      --std=c++17
      -x hip
      -mcode-object-version=6
      -w
      ${_generic_archs}
      ${_common_sources}
      -o "${_output_path_regular}"
      --hip-path=${ROCM_PATH}
      --rocm-path=${ROCM_PATH}
      --hip-link
      -rtlib=compiler-rt
      -unwindlib=libgcc
      -frtlib-add-rpath
      ${_include_flags}
      ${_libfs_flag}
    DEPENDS ${_common_sources}
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    COMMENT "Building ${_exe_name_regular} for ${VARIANT_SUFFIX}"
    VERBATIM
  )

  # 2. Build hipSquareGenericTargetOnlyCompressed (compressed fatbin with generic targets only)
  set(_exe_name_compressed "hipSquareGenericTargetOnlyCompressed${_exe_suffix}")
  set(_output_path_compressed "${_output_dir}/${_exe_name_compressed}")

  add_custom_command(
    OUTPUT "${_output_path_compressed}"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${_output_dir}"
    COMMAND ${CMAKE_CXX_COMPILER}
      -DNO_GENERIC_TARGET_ONLY_TEST
      -DGENERIC_COMPRESSED
      --std=c++17
      -x hip
      -mcode-object-version=6
      --offload-compress
      -w
      ${_generic_archs}
      ${_common_sources}
      -o "${_output_path_compressed}"
      --hip-path=${ROCM_PATH}
      --rocm-path=${ROCM_PATH}
      --hip-link
      -rtlib=compiler-rt
      -unwindlib=libgcc
      -frtlib-add-rpath
      ${_include_flags}
      ${_libfs_flag}
    DEPENDS ${_common_sources}
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    COMMENT "Building ${_exe_name_compressed} for ${VARIANT_SUFFIX}"
    VERBATIM
  )

  # Create custom targets for these executables
  add_custom_target(hipSquareGenericTargetOnly-${VARIANT_SUFFIX}
    DEPENDS "${_output_path_regular}"
  )

  add_custom_target(hipSquareGenericTargetOnlyCompressed-${VARIANT_SUFFIX}
    DEPENDS "${_output_path_compressed}"
  )

  # Make the main test executable depend on these
  set(_main_test_exe "catch_unit_compiler_${TEST_BASENAME}-${VARIANT_SUFFIX}")
  if(TARGET ${_main_test_exe})
    add_dependencies(${_main_test_exe}
      hipSquareGenericTargetOnly-${VARIANT_SUFFIX}
      hipSquareGenericTargetOnlyCompressed-${VARIANT_SUFFIX}
    )
    message(STATUS "Added generic target executable dependencies to ${_main_test_exe}")
  endif()

  # Also add to the build target hierarchy
  if(TARGET hip-tests-catch-unit-compiler-${VARIANT_SUFFIX})
    add_dependencies(hip-tests-catch-unit-compiler-${VARIANT_SUFFIX}
      hipSquareGenericTargetOnly-${VARIANT_SUFFIX}
      hipSquareGenericTargetOnlyCompressed-${VARIANT_SUFFIX}
    )
  endif()
endfunction()

# Function to create a Catch test executable
# Arguments:
#   TEST_NAME     - Name of the test
#   TEST_SOURCES  - Source file(s) (can be a single file or list of files)
#   TEST_DIR      - Directory containing the test sources
#   CATEGORY      - Test category (unit, stress, etc.)
#   SUBDIR        - Subdirectory name
#   VARIANT_SUFFIX - Variant suffix (e.g., hip-7.2.0)
#   ROCM_PATH     - Path to ROCm installation
macro(create_catch_test_executable TEST_NAME TEST_SOURCES TEST_DIR CATEGORY SUBDIR VARIANT_SUFFIX ROCM_PATH)
  set(_test_exe "${TEST_NAME}-${VARIANT_SUFFIX}")
  set(_test_sources "")

  # Build full paths to source files
  foreach(_src ${TEST_SOURCES})
    list(APPEND _test_sources "${TEST_DIR}/${_src}")
  endforeach()

  # Add hipTestMain sources (required for catch2 integration)
  list(APPEND _test_sources
    "${HIP_CATCH_TESTS_DIR}/hipTestMain/main.cc"
    "${HIP_CATCH_TESTS_DIR}/hipTestMain/hip_test_context.cc"
    "${HIP_CATCH_TESTS_DIR}/hipTestMain/hip_test_features.cc"
  )

  # Check if sources exist
  set(_valid_sources "")
  foreach(_src ${_test_sources})
    if(EXISTS "${_src}")
      list(APPEND _valid_sources "${_src}")
    else()
      message(STATUS "Source file not found: ${_src}")
    endif()
  endforeach()

  if(NOT _valid_sources)
    message(STATUS "No valid sources found for ${TEST_NAME}, skipping")
    return()
  endif()

  # Create the executable
  add_executable(${_test_exe} EXCLUDE_FROM_ALL ${_valid_sources})

  # Ensure timeit tool is built first (needed for compilation timing)
  if(TARGET build-timeit)
    add_dependencies(${_test_exe} build-timeit)
  endif()

  # Set properties
  set_target_properties(${_test_exe} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/catch_tests"
  )

  # Include directories
  target_include_directories(${_test_exe} PRIVATE
    ${CATCH2_INCLUDE_PATH}
    "${HIP_CATCH_TESTS_DIR}/include"
    "${HIP_CATCH_TESTS_DIR}/external/picojson"
  )

  # Add HIP runtime includes
  # hipcc wrapper provides these automatically, direct compilers need explicit paths
  if(NOT _compiler_name MATCHES "hipcc")
    target_include_directories(${_test_exe} PRIVATE
      "${ROCM_PATH}/include"
    )
  endif()

  # Compile definitions
  # Note: __HIP_PLATFORM_AMD__ or __HIP_PLATFORM_NVIDIA__ is automatically
  # defined by HIP headers based on the compiler backend, so no manual
  # platform definition is needed
  # target_compile_definitions(${_test_exe} PRIVATE ...)

  # Compile options
  target_compile_options(${_test_exe} PRIVATE
    ${VariantCPPFLAGS}
    -x hip
    -Wall
    -Wno-deprecated
    -Wno-unused-command-line-argument
  )

  # Special handling for hipSquareGenericTarget test - add generic target architectures
  if("${TEST_NAME}" MATCHES "hipSquareGenericTarget" AND "${CATEGORY}" STREQUAL "unit" AND "${SUBDIR}" STREQUAL "compiler")
    target_compile_options(${_test_exe} PRIVATE
      -mcode-object-version=6
      -w
      --offload-arch=gfx9-generic
      --offload-arch=gfx9-4-generic:sramecc+:xnack-
      --offload-arch=gfx9-4-generic:sramecc-:xnack-
      --offload-arch=gfx9-4-generic:xnack+
      --offload-arch=gfx10-1-generic
      --offload-arch=gfx10-3-generic
      --offload-arch=gfx11-generic
      --offload-arch=gfx12-generic
    )
    message(STATUS "Added generic target compile options to ${_test_exe}")
  endif()

  # Link options - platform-specific handling
  # If using hipcc wrapper (AMD or NVIDIA backend), it handles flags automatically
  # Otherwise, add explicit flags for AMD clang
  get_filename_component(_compiler_name "${CMAKE_CXX_COMPILER}" NAME)
  if(_compiler_name MATCHES "hipcc")
    # hipcc wrapper handles platform-specific flags automatically
    message(VERBOSE "Using hipcc wrapper: ${CMAKE_CXX_COMPILER}")
  else()
    # Direct compiler (AMD clang) - add explicit HIP link flags
    target_link_options(${_test_exe} PRIVATE
      --rocm-path=${ROCM_PATH}
      --hip-link
      -rtlib=compiler-rt
      -unwindlib=libgcc
      -frtlib-add-rpath
    )
  endif()

  # Link libraries
  target_link_libraries(${_test_exe} PRIVATE
    ${VariantLibs}
    stdc++fs
    dl
    pthread
    rt
  )

  # Add to subdirectory variant target (lowest level)
  add_dependencies(hip-tests-catch-${CATEGORY}-${SUBDIR}-${VARIANT_SUFFIX} ${_test_exe})

  # Register with LIT
  # Use console reporter for consistent output parsing in summary scripts
  # Console reporter outputs: "test cases: X | Y passed | Z failed"
  # Special handling for hipSquareGenericTarget - needs to run from catch_tests dir
  # so that helper executables (hipSquareGenericTargetOnly, etc.) can be found
  if("${TEST_NAME}" MATCHES "hipSquareGenericTarget")
    # Use WORKDIR to change directory before running (parsed as "cd DIR ; executable")
    # %S expands to source directory (where .test file is located)
    llvm_test_run(WORKDIR "%S/catch_tests" EXECUTABLE "./${_test_exe}" "--reporter" "console")
  else()
    llvm_test_run(EXECUTABLE "catch_tests/${_test_exe}" "--reporter" "console")
  endif()

  # Add verification to check if test passed
  # Catch2 prints "test cases: X | Y failed" when tests fail
  # Check for failure indicators in output (%o expands to Output/<test_name>.test.out)
  llvm_test_verify("! grep -q failed %o")

  llvm_add_test(${_test_exe}.test catch_tests/${_test_exe})

  # Track this test target at all hierarchy levels
  track_test_target_multi_level(${_test_exe}.test ${CATEGORY} ${SUBDIR} ${VARIANT_SUFFIX})

  # Also add to VARIANT_CATCH_TEST_TARGETS for backward compatibility
  list(APPEND VARIANT_CATCH_TEST_TARGETS ${_test_exe}.test)
  set(VARIANT_CATCH_TEST_TARGETS ${VARIANT_CATCH_TEST_TARGETS} PARENT_SCOPE)

  message(STATUS "Created Catch test executable: ${_test_exe}")
endmacro()

# Function to create Catch tests for a specific category and subdirectory
# Arguments:
#   CATEGORY      - Test category (unit, stress, performance)
#   SUBDIR        - Subdirectory name
#   VARIANT_SUFFIX - Variant suffix (e.g., hip-7.2.0)
#   ROCM_PATH     - Path to ROCm installation
function(create_catch_tests_for_subdir CATEGORY SUBDIR VARIANT_SUFFIX ROCM_PATH)
  set(_test_dir "${HIP_CATCH_TESTS_DIR}/${CATEGORY}/${SUBDIR}")

  # Create unique identifier for this category-subdir pair
  set(_subdir_id "${CATEGORY}-${SUBDIR}")

  # Create aggregated subdirectory-level targets (once per category-subdir pair)
  get_property(_created_subdirs GLOBAL PROPERTY CATCH_SUBDIR_TARGETS_CREATED)
  if(NOT "${_subdir_id}" IN_LIST _created_subdirs)
    message(STATUS "Creating aggregated subdirectory targets for: ${CATEGORY}/${SUBDIR}")

    # Create aggregated build target
    add_custom_target(hip-tests-catch-${CATEGORY}-${SUBDIR}
      COMMENT "Build all HIP Catch ${CATEGORY}/${SUBDIR} tests across all variants")
    add_dependencies(hip-tests-catch-${CATEGORY} hip-tests-catch-${CATEGORY}-${SUBDIR})

    # Create aggregated check target (will be populated later)
    add_custom_target(check-hip-catch-${CATEGORY}-${SUBDIR}
      COMMENT "Run all HIP Catch ${CATEGORY}/${SUBDIR} tests across all variants")
    add_dependencies(check-hip-catch-${CATEGORY} check-hip-catch-${CATEGORY}-${SUBDIR})

    # Mark as created
    set_property(GLOBAL APPEND PROPERTY CATCH_SUBDIR_TARGETS_CREATED "${_subdir_id}")
  endif()

  # Create per-variant subdirectory-level targets
  message(STATUS "Creating per-variant subdirectory targets for: ${CATEGORY}/${SUBDIR}-${VARIANT_SUFFIX}")
  add_custom_target(hip-tests-catch-${CATEGORY}-${SUBDIR}-${VARIANT_SUFFIX}
    COMMENT "Build HIP Catch ${CATEGORY}/${SUBDIR} tests for variant ${VARIANT_SUFFIX}")

  # Wire dependencies: variant-specific target to aggregated subdirectory target
  add_dependencies(hip-tests-catch-${CATEGORY}-${SUBDIR} hip-tests-catch-${CATEGORY}-${SUBDIR}-${VARIANT_SUFFIX})

  # Wire dependencies: category variant target depends on subdirectory variant target
  add_dependencies(hip-tests-catch-${CATEGORY}-${VARIANT_SUFFIX} hip-tests-catch-${CATEGORY}-${SUBDIR}-${VARIANT_SUFFIX})

  # Discover test sources directly from .cc files
  file(GLOB _test_sources RELATIVE "${_test_dir}" "${_test_dir}/*.cc")

  if(NOT _test_sources)
    message(STATUS "No test sources found in ${CATEGORY}/${SUBDIR}, skipping")
    return()
  endif()

  message(STATUS "Discovered test sources in ${CATEGORY}/${SUBDIR}: ${_test_sources}")

  # Create a separate test executable for each source file
  # This allows LIT to report statistics for each individual test
  foreach(_src ${_test_sources})
    # Get the test name from the source filename (without extension)
    get_filename_component(_test_basename "${_src}" NAME_WE)
    set(_test_name "catch_${CATEGORY}_${SUBDIR}_${_test_basename}")

    message(STATUS "Creating Catch test: ${_test_name} from ${_src}")

    # Create the test executable with just this one source file
    create_catch_test_executable("${_test_name}" "${_src}" "${_test_dir}" "${CATEGORY}" "${SUBDIR}" "${VARIANT_SUFFIX}" "${ROCM_PATH}")

    # Special handling for hipSquareGenericTarget test (unit/compiler only)
    # This test requires additional executables with generic-only targets
    if("${_test_basename}" STREQUAL "hipSquareGenericTarget" AND
       "${CATEGORY}" STREQUAL "unit" AND "${SUBDIR}" STREQUAL "compiler")
      create_generic_target_executables("${_test_basename}" "${_test_dir}" "${VARIANT_SUFFIX}" "${ROCM_PATH}")
    endif()
  endforeach()

  # Create per-variant check target for this subdirectory
  # Get test targets for this subdirectory-variant combination
  get_property(_subdir_variant_tests GLOBAL PROPERTY "CATCH_${CATEGORY}_${SUBDIR}_TEST_TARGETS_${VARIANT_SUFFIX}")

  if(_subdir_variant_tests)
    # Unified LIT-based execution with configurable verbosity
    # HIP_CATCH_TEST_VERBOSE controls output detail level (-a flag), not execution mode
    # Metrics are always collected via LIT

    # Configure LIT flags based on verbosity setting
    if(HIP_CATCH_TEST_VERBOSE)
      set(_lit_verbosity_flags "-a")  # Show all test output
    else()
      set(_lit_verbosity_flags "")    # Quiet mode - only show pass/fail
    endif()

    # Generate enhanced summary script from template
    set(CATCH_CATEGORY ${CATEGORY})
    set(CATCH_SUBDIR ${SUBDIR})
    set(CATCH_VARIANT_SUFFIX ${VARIANT_SUFFIX})
    set(_summary_script "${CMAKE_CURRENT_BINARY_DIR}/catch_tests/summary_${CATEGORY}_${SUBDIR}_${VARIANT_SUFFIX}.sh")
    configure_file(
      "${CMAKE_CURRENT_SOURCE_DIR}/catch_summary_template.sh.in"
      "${_summary_script}"
      @ONLY
    )
    execute_process(COMMAND chmod +x "${_summary_script}")

    # Create wrapper script that runs LIT then shows summary
    set(_lit_wrapper "${CMAKE_CURRENT_BINARY_DIR}/catch_tests/lit_wrapper_${CATEGORY}_${SUBDIR}_${VARIANT_SUFFIX}.sh")
    file(WRITE "${_lit_wrapper}" "#!/bin/bash\n")
    file(APPEND "${_lit_wrapper}" "cd ${CMAKE_CURRENT_BINARY_DIR}\n")
    string(REPLACE ";" " " _test_list_str "${_subdir_variant_tests}")
    file(APPEND "${_lit_wrapper}" "${TEST_SUITE_LIT} ${TEST_SUITE_LIT_FLAGS} ${_lit_verbosity_flags} ${_test_list_str}\n")
    file(APPEND "${_lit_wrapper}" "LIT_EXIT=\$?\n")
    file(APPEND "${_lit_wrapper}" "${_summary_script}\n")
    file(APPEND "${_lit_wrapper}" "exit \$LIT_EXIT\n")
    execute_process(COMMAND chmod +x "${_lit_wrapper}")

    add_custom_target(check-hip-catch-${CATEGORY}-${SUBDIR}-${VARIANT_SUFFIX}
      COMMAND ${_lit_wrapper}
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
      DEPENDS hip-tests-catch-${CATEGORY}-${SUBDIR}-${VARIANT_SUFFIX}
      USES_TERMINAL
      COMMENT "Run HIP Catch ${CATEGORY}/${SUBDIR} tests for variant ${VARIANT_SUFFIX}")

    # Ensure litsupport files (including lit.cfg) and timeit-target are available
    if(TARGET build-litsupport)
      add_dependencies(check-hip-catch-${CATEGORY}-${SUBDIR}-${VARIANT_SUFFIX} build-litsupport)
    endif()
    if(TARGET timeit-target)
      add_dependencies(check-hip-catch-${CATEGORY}-${SUBDIR}-${VARIANT_SUFFIX} timeit-target)
    endif()

    # Wire to aggregated check target (subdirectory aggregator depends on subdirectory-variant)
    add_dependencies(check-hip-catch-${CATEGORY}-${SUBDIR} check-hip-catch-${CATEGORY}-${SUBDIR}-${VARIANT_SUFFIX})
  endif()
endfunction()

# Main function to integrate Catch tests for a specific HIP variant
# Arguments:
#   VARIANT_SUFFIX - Variant suffix (e.g., hip-7.2.0)
#   ROCM_PATH     - Path to ROCm installation
function(integrate_catch_tests VARIANT_SUFFIX ROCM_PATH)
  message(STATUS "Integrating Catch tests for variant ${VARIANT_SUFFIX}")

  # Register this variant globally
  get_property(_variants GLOBAL PROPERTY CATCH_ALL_VARIANTS)
  if(NOT "${VARIANT_SUFFIX}" IN_LIST _variants)
    set_property(GLOBAL APPEND PROPERTY CATCH_ALL_VARIANTS "${VARIANT_SUFFIX}")
  endif()

  # Create catch test target for this variant
  add_custom_target(hip-tests-catch-${VARIANT_SUFFIX}
    COMMENT "Build Catch tests for HIP variant ${VARIANT_SUFFIX}")

  # Process each enabled category
  foreach(_category ${CATCH_TEST_CATEGORIES})
    message(STATUS "Processing Catch test category: ${_category}")

    # Create aggregated category-level targets (once per category)
    get_property(_created_categories GLOBAL PROPERTY CATCH_CATEGORY_TARGETS_CREATED)
    if(NOT "${_category}" IN_LIST _created_categories)
      message(STATUS "Creating aggregated category targets for: ${_category}")

      # Create aggregated build target
      add_custom_target(hip-tests-catch-${_category}
        COMMENT "Build all HIP Catch ${_category} tests across all variants")
      add_dependencies(hip-tests-catch hip-tests-catch-${_category})

      # Create aggregated check target (will be populated later)
      add_custom_target(check-hip-catch-${_category}
        COMMENT "Run all HIP Catch ${_category} tests across all variants")
      add_dependencies(check-hip-catch check-hip-catch-${_category})

      # Mark as created
      set_property(GLOBAL APPEND PROPERTY CATCH_CATEGORY_TARGETS_CREATED "${_category}")
    endif()

    # Create per-variant category-level targets
    message(STATUS "Creating per-variant category targets for: ${_category}-${VARIANT_SUFFIX}")
    add_custom_target(hip-tests-catch-${_category}-${VARIANT_SUFFIX}
      COMMENT "Build HIP Catch ${_category} tests for variant ${VARIANT_SUFFIX}")

    # Wire dependencies: variant-specific target to aggregated category target
    add_dependencies(hip-tests-catch-${_category} hip-tests-catch-${_category}-${VARIANT_SUFFIX})

    # Wire dependencies: top-level variant target depends on category variant target
    add_dependencies(hip-tests-catch-${VARIANT_SUFFIX} hip-tests-catch-${_category}-${VARIANT_SUFFIX})

    # Discover test subdirectories
    discover_catch_test_category(${_category})

    # Get the discovered subdirectories
    set(_subdir_var "${_category}_TEST_DIRS")
    if(DEFINED ${_subdir_var})
      foreach(_subdir ${${_subdir_var}})
        create_catch_tests_for_subdir("${_category}" "${_subdir}" "${VARIANT_SUFFIX}" "${ROCM_PATH}")
      endforeach()
    endif()
  endforeach()

  # Create per-variant check targets for each category
  foreach(_category ${CATCH_TEST_CATEGORIES})
    # Get test targets for this category-variant combination
    get_property(_category_variant_tests GLOBAL PROPERTY "CATCH_${_category}_TEST_TARGETS_${VARIANT_SUFFIX}")

    if(_category_variant_tests)
      # Category-variant target is just an aggregator - subdirectory-variant targets do the actual work
      add_custom_target(check-hip-catch-${_category}-${VARIANT_SUFFIX}
        DEPENDS hip-tests-catch-${_category}-${VARIANT_SUFFIX}
        COMMENT "Run HIP Catch ${_category} tests for variant ${VARIANT_SUFFIX}")

      # Wire category-variant to its subdirectory-variant targets
      set(_subdir_var "${_category}_TEST_DIRS")
      if(DEFINED ${_subdir_var})
        foreach(_subdir ${${_subdir_var}})
          if(TARGET check-hip-catch-${_category}-${_subdir}-${VARIANT_SUFFIX})
            add_dependencies(check-hip-catch-${_category}-${VARIANT_SUFFIX} check-hip-catch-${_category}-${_subdir}-${VARIANT_SUFFIX})
          endif()
        endforeach()
      endif()

      # Wire to aggregated check target (will run tests from all variants)
      add_dependencies(check-hip-catch-${_category} check-hip-catch-${_category}-${VARIANT_SUFFIX})
    endif()
  endforeach()

  # Add variant target to main catch target
  add_dependencies(hip-tests-catch hip-tests-catch-${VARIANT_SUFFIX})

  # Create variant-level check target as aggregator (category-variant targets do the actual work)
  add_custom_target(check-hip-catch-${VARIANT_SUFFIX}
    DEPENDS hip-tests-catch-${VARIANT_SUFFIX}
    COMMENT "Run all HIP Catch tests for variant ${VARIANT_SUFFIX}")

  # Wire variant target to category-variant targets
  foreach(_category ${CATCH_TEST_CATEGORIES})
    if(TARGET check-hip-catch-${_category}-${VARIANT_SUFFIX})
      add_dependencies(check-hip-catch-${VARIANT_SUFFIX} check-hip-catch-${_category}-${VARIANT_SUFFIX})
    endif()
  endforeach()

  add_dependencies(check-hip-catch check-hip-catch-${VARIANT_SUFFIX})

  message(STATUS "Integrated ${CMAKE_CURRENT_LIST_LENGTH} Catch test targets for ${VARIANT_SUFFIX}")
endfunction()

# Initialize the Catch test framework integration
macro(initialize_catch_tests)
  if(ENABLE_HIP_CATCH_TESTS)
    message(STATUS "=== Initializing HIP Catch Tests Integration ===")

    # Validate local Catch test infrastructure
    validate_catch_tests_infrastructure()

    # Create main targets
    add_custom_target(hip-tests-catch
      COMMENT "Build all HIP Catch tests")
    add_custom_target(check-hip-catch
      COMMENT "Run all HIP Catch tests")

    message(STATUS "Catch test categories enabled: ${CATCH_TEST_CATEGORIES}")
    if(CATCH_TEST_SUBDIRS)
      message(STATUS "Catch test subdirectories filter: ${CATCH_TEST_SUBDIRS}")
    else()
      message(STATUS "Catch test subdirectories filter: ALL (no filter)")
    endif()
    message(STATUS "=== Catch Tests Integration Initialized ===")
  else()
    message(STATUS "HIP Catch tests are DISABLED (set ENABLE_HIP_CATCH_TESTS=ON to enable)")
  endif()
endmacro()
