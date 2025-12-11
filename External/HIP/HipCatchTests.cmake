# CMake module for integrating hip-tests Catch tests into llvm-test-suite
# This module provides functions to discover and build Catch-based HIP tests

include(CMakeParseArguments)

# Global variables for Catch test configuration
set(ENABLE_HIP_CATCH_TESTS ON CACHE BOOL "Enable HIP Catch test framework and all catch test targets")
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

  # Create a test wrapper script
  set(_test_wrapper "${CMAKE_CURRENT_BINARY_DIR}/catch_tests/${_test_exe}_wrapper.sh")
  file(WRITE "${_test_wrapper}" "#!/bin/bash\n")
  file(APPEND "${_test_wrapper}" "# Auto-generated wrapper for ${_test_exe}\n")

  # Special handling for hipSquareGenericTarget - needs to run from catch_tests dir
  # so that helper executables (hipSquareGenericTargetOnly, etc.) can be found
  if("${TEST_NAME}" MATCHES "hipSquareGenericTarget")
    file(APPEND "${_test_wrapper}" "cd \"${CMAKE_CURRENT_BINARY_DIR}/catch_tests\" || exit 1\n")
  endif()

  # Add verbose reporting if enabled
  # Use console reporter for consistent output parsing in summary scripts
  # Console reporter outputs: "test cases: X | Y passed | Z failed"
  # Also capture exit code for accurate skip vs crash detection
  file(APPEND "${_test_wrapper}" "echo \"=== Running: ${_test_exe} ===\"\n")
  if("${TEST_NAME}" MATCHES "hipSquareGenericTarget")
    # Use relative path since we're in catch_tests dir
    file(APPEND "${_test_wrapper}" "\"./${_test_exe}\" --reporter console \"$@\"\n")
  else()
    file(APPEND "${_test_wrapper}" "\"${CMAKE_CURRENT_BINARY_DIR}/catch_tests/${_test_exe}\" --reporter console \"$@\"\n")
  endif()
  file(APPEND "${_test_wrapper}" "TEST_EXIT_CODE=\$?\n")
  file(APPEND "${_test_wrapper}" "echo \"EXIT_CODE: \$TEST_EXIT_CODE\"\n")
  file(APPEND "${_test_wrapper}" "exit \$TEST_EXIT_CODE\n")

  execute_process(COMMAND chmod +x "${_test_wrapper}")

  # Register with LIT
  # Use relative path from build directory for the wrapper script
  llvm_test_run(EXECUTABLE "/bin/bash" "catch_tests/${_test_exe}_wrapper.sh")

  # Add verification to check if test passed
  # Catch2 prints "test cases: X | Y failed" when tests fail
  # Check for failure indicators in output (%o expands to Output/<test_name>.test.out)
  llvm_test_verify("! grep -q failed %o")

  llvm_add_test(${_test_exe}.test catch_tests/${_test_exe}_wrapper.sh)

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
    # When verbose mode is enabled, create a direct-run check target (bypasses LIT)
    # Otherwise, use LIT for standard test infrastructure integration
    if(HIP_CATCH_TEST_VERBOSE)
      # Create a script that runs tests directly and shows verbose output
      set(_run_script "${CMAKE_CURRENT_BINARY_DIR}/catch_tests/run_${CATEGORY}_${SUBDIR}_${VARIANT_SUFFIX}.sh")
      file(WRITE "${_run_script}" "#!/bin/bash\n")
      file(APPEND "${_run_script}" "cd ${CMAKE_CURRENT_BINARY_DIR}\n")
      file(APPEND "${_run_script}" "FAILED=0\n")
      file(APPEND "${_run_script}" "TOTAL_FILES=0\n")
      file(APPEND "${_run_script}" "TOTAL_TESTS=0\n")
      file(APPEND "${_run_script}" "PASSED_TESTS=0\n")
      file(APPEND "${_run_script}" "FAILED_TESTS=0\n")
      file(APPEND "${_run_script}" "SKIPPED_TESTS=0\n")
      file(APPEND "${_run_script}" "CRASHED_TESTS=0\n")
      file(APPEND "${_run_script}" "echo \"\"\n")
      file(APPEND "${_run_script}" "for test in catch_tests/catch_${CATEGORY}_${SUBDIR}_*-${VARIANT_SUFFIX}; do\n")
      file(APPEND "${_run_script}" "  if [ -x \"\$test\" ]; then\n")
      file(APPEND "${_run_script}" "    TOTAL_FILES=\$((TOTAL_FILES + 1))\n")
      file(APPEND "${_run_script}" "    echo \"=== \$(basename \$test) ===\"\n")
      file(APPEND "${_run_script}" "    # Special handling for hipSquareGenericTarget - must run from catch_tests dir\n")
      file(APPEND "${_run_script}" "    if [[ \"\$test\" == *hipSquareGenericTarget* ]]; then\n")
      file(APPEND "${_run_script}" "      SAVED_DIR=\$(pwd)\n")
      file(APPEND "${_run_script}" "      cd catch_tests || exit 1\n")
      file(APPEND "${_run_script}" "      TEST_PATH=\"./\$(basename \$test)\"\n")
      file(APPEND "${_run_script}" "    else\n")
      file(APPEND "${_run_script}" "      TEST_PATH=\"\$test\"\n")
      file(APPEND "${_run_script}" "    fi\n")
      file(APPEND "${_run_script}" "    # First, get total test case count from --list-tests\n")
      file(APPEND "${_run_script}" "    LIST_OUTPUT=\$(\"\$TEST_PATH\" --list-tests 2>&1)\n")
      file(APPEND "${_run_script}" "    FILE_TOTAL=\$(echo \"\$LIST_OUTPUT\" | tail -1 | grep -o '^[0-9]*' || echo 0)\n")
      file(APPEND "${_run_script}" "    TOTAL_TESTS=\$((TOTAL_TESTS + FILE_TOTAL))\n")
      file(APPEND "${_run_script}" "    # Now run the tests with console reporter to get full summary\n")
      file(APPEND "${_run_script}" "    OUTPUT=\$(\"\$TEST_PATH\" --reporter console 2>&1)\n")
      file(APPEND "${_run_script}" "    TEST_EXIT=\$?\n")
      file(APPEND "${_run_script}" "    # Restore directory if we changed it\n")
      file(APPEND "${_run_script}" "    if [[ \"\$test\" == *hipSquareGenericTarget* ]]; then\n")
      file(APPEND "${_run_script}" "      cd \"\$SAVED_DIR\"\n")
      file(APPEND "${_run_script}" "    fi\n")
      file(APPEND "${_run_script}" "    echo \"\$OUTPUT\"\n")
      file(APPEND "${_run_script}" "    if [ \$TEST_EXIT -ne 0 ]; then\n")
      file(APPEND "${_run_script}" "      FAILED=1\n")
      file(APPEND "${_run_script}" "    fi\n")
      file(APPEND "${_run_script}" "    # Parse Catch2 summary line: 'test cases: X | Y passed | Z failed' or 'test cases: X | Y failed'\n")
     file(APPEND "${_run_script}" "    CASES_PASSED=0\n")
     file(APPEND "${_run_script}" "    CASES_FAILED=0\n")
     file(APPEND "${_run_script}" "    PARSED=0\n")
     file(APPEND "${_run_script}" "    # Parse Catch2 output - try multiple formats\n")
     file(APPEND "${_run_script}" "    # Format 1: 'test cases: X | Y passed | Z failed'\n")
     file(APPEND "${_run_script}" "    SUMMARY_LINE=\$(echo \"\$OUTPUT\" | grep '^test cases:')\n")
     file(APPEND "${_run_script}" "    if [ -n \"\$SUMMARY_LINE\" ]; then\n")
     file(APPEND "${_run_script}" "      PARSED=1\n")
     file(APPEND "${_run_script}" "      # Extract passed (if present)\n")
     file(APPEND "${_run_script}" "      CASES_PASSED=\$(echo \"\$SUMMARY_LINE\" | grep -o '[0-9]* passed' | grep -o '[0-9]*' || echo 0)\n")
     file(APPEND "${_run_script}" "      # Extract failed (if present)\n")
     file(APPEND "${_run_script}" "      CASES_FAILED=\$(echo \"\$SUMMARY_LINE\" | grep -o '[0-9]* failed' | grep -o '[0-9]*' || echo 0)\n")
     file(APPEND "${_run_script}" "      # Extract total from 'test cases: X |'\n")
     file(APPEND "${_run_script}" "      CASES_TOTAL=\$(echo \"\$SUMMARY_LINE\" | sed 's/test cases: \\([0-9]*\\).*/\\1/')\n")
     file(APPEND "${_run_script}" "      # If no explicit passed count, calculate from total - failed\n")
     file(APPEND "${_run_script}" "      if [ \$CASES_PASSED -eq 0 ] && [ \$CASES_FAILED -gt 0 ]; then\n")
     file(APPEND "${_run_script}" "        CASES_PASSED=\$((CASES_TOTAL - CASES_FAILED))\n")
     file(APPEND "${_run_script}" "      fi\n")
     file(APPEND "${_run_script}" "    fi\n")
     file(APPEND "${_run_script}" "    # Format 2: 'All tests passed (N assertion in M test cases)'\n")
     file(APPEND "${_run_script}" "    if [ \$PARSED -eq 0 ]; then\n")
     file(APPEND "${_run_script}" "      ALL_PASSED_LINE=\$(echo \"\$OUTPUT\" | grep 'All tests passed' | tail -1)\n")
     file(APPEND "${_run_script}" "      if [ -n \"\$ALL_PASSED_LINE\" ]; then\n")
     file(APPEND "${_run_script}" "        PARSED=1\n")
     file(APPEND "${_run_script}" "        # Extract test case count: 'in M test case' or 'in M test cases'\n")
     file(APPEND "${_run_script}" "        CASES_PASSED=\$(echo \"\$ALL_PASSED_LINE\" | grep -o 'in [0-9]* test case' | grep -o '[0-9]*' || echo 0)\n")
     file(APPEND "${_run_script}" "        CASES_FAILED=0\n")
     file(APPEND "${_run_script}" "      fi\n")
     file(APPEND "${_run_script}" "    fi\n")
     file(APPEND "${_run_script}" "    # Update totals if we parsed something\n")
     file(APPEND "${_run_script}" "    if [ \$PARSED -eq 1 ]; then\n")
     file(APPEND "${_run_script}" "      # Detect runtime skips by parsing 'is skipped' messages in output\n")
     file(APPEND "${_run_script}" "      # Tests that print 'is skipped' and return early are counted as 'passed' by Catch2\n")
     file(APPEND "${_run_script}" "      RUNTIME_SKIPPED=\$(echo \"\$OUTPUT\" | grep -i 'is skipped' 2>/dev/null | wc -l)\n")
     file(APPEND "${_run_script}" "      if [ \$RUNTIME_SKIPPED -gt 0 ] && [ \$CASES_PASSED -gt 0 ]; then\n")
     file(APPEND "${_run_script}" "        # Move runtime-skipped tests from Passed to Skipped\n")
     file(APPEND "${_run_script}" "        # Don't move more than what Catch2 reported as passed\n")
     file(APPEND "${_run_script}" "        if [ \$RUNTIME_SKIPPED -gt \$CASES_PASSED ]; then\n")
     file(APPEND "${_run_script}" "          RUNTIME_SKIPPED=\$CASES_PASSED\n")
     file(APPEND "${_run_script}" "        fi\n")
     file(APPEND "${_run_script}" "        CASES_PASSED=\$((CASES_PASSED - RUNTIME_SKIPPED))\n")
     file(APPEND "${_run_script}" "        SKIPPED_TESTS=\$((SKIPPED_TESTS + RUNTIME_SKIPPED))\n")
     file(APPEND "${_run_script}" "      fi\n")
     file(APPEND "${_run_script}" "      PASSED_TESTS=\$((PASSED_TESTS + CASES_PASSED))\n")
     file(APPEND "${_run_script}" "      FAILED_TESTS=\$((FAILED_TESTS + CASES_FAILED))\n")
     file(APPEND "${_run_script}" "      # Categorize incomplete tests by exit code\n")
     file(APPEND "${_run_script}" "      INCOMPLETE=\$((FILE_TOTAL - CASES_PASSED - CASES_FAILED - RUNTIME_SKIPPED))\n")
     file(APPEND "${_run_script}" "      if [ \$INCOMPLETE -gt 0 ]; then\n")
     file(APPEND "${_run_script}" "        if [ \$TEST_EXIT -eq 0 ]; then\n")
     file(APPEND "${_run_script}" "          SKIPPED_TESTS=\$((SKIPPED_TESTS + INCOMPLETE))\n")
     file(APPEND "${_run_script}" "        else\n")
     file(APPEND "${_run_script}" "          CRASHED_TESTS=\$((CRASHED_TESTS + INCOMPLETE))\n")
     file(APPEND "${_run_script}" "        fi\n")
     file(APPEND "${_run_script}" "      fi\n")
     file(APPEND "${_run_script}" "    else\n")
     file(APPEND "${_run_script}" "      # No summary line - test crashed before completing any tests\n")
     file(APPEND "${_run_script}" "      if [ \$FILE_TOTAL -gt 0 ]; then\n")
     file(APPEND "${_run_script}" "        CRASHED_TESTS=\$((CRASHED_TESTS + FILE_TOTAL))\n")
     file(APPEND "${_run_script}" "      fi\n")
     file(APPEND "${_run_script}" "    fi\n")
      file(APPEND "${_run_script}" "    echo \"(\$FILE_TOTAL TEST_CASE definitions in this file)\"\n")
      file(APPEND "${_run_script}" "    echo \"\"\n")
      file(APPEND "${_run_script}" "  fi\n")
      file(APPEND "${_run_script}" "done\n")
      file(APPEND "${_run_script}" "echo \"========================================\"\n")
      file(APPEND "${_run_script}" "echo \"Summary:\"\n")
      file(APPEND "${_run_script}" "echo \"  Test Suites: \$TOTAL_FILES\"\n")
      file(APPEND "${_run_script}" "echo \"  Total Tests: \$TOTAL_TESTS\"\n")
      file(APPEND "${_run_script}" "echo \"  Passed: \$PASSED_TESTS\"\n")
      file(APPEND "${_run_script}" "echo \"  Failed: \$FAILED_TESTS\"\n")
      file(APPEND "${_run_script}" "if [ \$SKIPPED_TESTS -gt 0 ]; then\n")
      file(APPEND "${_run_script}" "  echo \"  Skipped: \$SKIPPED_TESTS\"\n")
      file(APPEND "${_run_script}" "fi\n")
      file(APPEND "${_run_script}" "if [ \$CRASHED_TESTS -gt 0 ]; then\n")
      file(APPEND "${_run_script}" "  echo \"  Crashed/Error: \$CRASHED_TESTS\"\n")
      file(APPEND "${_run_script}" "fi\n")
      file(APPEND "${_run_script}" "echo \"========================================\"\n")
      file(APPEND "${_run_script}" "exit \$FAILED\n")
      execute_process(COMMAND chmod +x "${_run_script}")

      add_custom_target(check-hip-catch-${CATEGORY}-${SUBDIR}-${VARIANT_SUFFIX}
        COMMAND ${_run_script}
        DEPENDS hip-tests-catch-${CATEGORY}-${SUBDIR}-${VARIANT_SUFFIX}
        USES_TERMINAL
        COMMENT "Run HIP Catch ${CATEGORY}/${SUBDIR} tests (verbose mode: direct run)")
    else()
      # Standard LIT-based check target for metric collection
      # Generate a summary script to show TEST_CASE-level statistics after LIT completes
      set(_summary_script "${CMAKE_CURRENT_BINARY_DIR}/catch_tests/summary_${CATEGORY}_${SUBDIR}_${VARIANT_SUFFIX}.sh")
      file(WRITE "${_summary_script}" "#!/bin/bash\n")
      file(APPEND "${_summary_script}" "# Summary script for Catch2 TEST_CASE statistics in LIT mode\n")
      file(APPEND "${_summary_script}" "cd ${CMAKE_CURRENT_BINARY_DIR}\n")
      file(APPEND "${_summary_script}" "echo \"\"\n")
      file(APPEND "${_summary_script}" "echo \"========================================\"\n")
      file(APPEND "${_summary_script}" "echo \"Catch2 TEST_CASE Summary:\"\n")
      file(APPEND "${_summary_script}" "TOTAL_FILES=0\n")
      file(APPEND "${_summary_script}" "TOTAL_TESTS=0\n")
      file(APPEND "${_summary_script}" "PASSED_TESTS=0\n")
      file(APPEND "${_summary_script}" "FAILED_TESTS=0\n")
      file(APPEND "${_summary_script}" "SKIPPED_TESTS=0\n")
      file(APPEND "${_summary_script}" "CRASHED_TESTS=0\n")
      file(APPEND "${_summary_script}" "for test in catch_tests/catch_${CATEGORY}_${SUBDIR}_*-${VARIANT_SUFFIX}; do\n")
      file(APPEND "${_summary_script}" "  if [ -x \"\$test\" ]; then\n")
      file(APPEND "${_summary_script}" "    TOTAL_FILES=\$((TOTAL_FILES + 1))\n")
      file(APPEND "${_summary_script}" "    # Get total TEST_CASE count from --list-tests\n")
      file(APPEND "${_summary_script}" "    LIST_OUTPUT=\$(\"\$test\" --list-tests 2>&1)\n")
      file(APPEND "${_summary_script}" "    FILE_TOTAL=\$(echo \"\$LIST_OUTPUT\" | tail -1 | grep -o '^[0-9]*' || echo 0)\n")
      file(APPEND "${_summary_script}" "    TOTAL_TESTS=\$((TOTAL_TESTS + FILE_TOTAL))\n")
      file(APPEND "${_summary_script}" "    # Parse the corresponding .test.out file for results\n")
      file(APPEND "${_summary_script}" "    TEST_NAME=\$(basename \"\$test\")\n")
      file(APPEND "${_summary_script}" "    OUT_FILE=\"Output/\${TEST_NAME}.test.out\"\n")
     file(APPEND "${_summary_script}" "    if [ -f \"\$OUT_FILE\" ]; then\n")
     file(APPEND "${_summary_script}" "      CASES_PASSED=0\n")
     file(APPEND "${_summary_script}" "      CASES_FAILED=0\n")
     file(APPEND "${_summary_script}" "      PARSED=0\n")
     file(APPEND "${_summary_script}" "      # Parse Catch2 output - try multiple formats\n")
     file(APPEND "${_summary_script}" "      # Format 1: 'test cases: X | Y passed | Z failed' or 'test cases: X | Y failed'\n")
     file(APPEND "${_summary_script}" "      SUMMARY_LINE=\$(grep '^test cases:' \"\$OUT_FILE\" 2>/dev/null || echo \"\")\n")
     file(APPEND "${_summary_script}" "      if [ -n \"\$SUMMARY_LINE\" ]; then\n")
     file(APPEND "${_summary_script}" "        PARSED=1\n")
     file(APPEND "${_summary_script}" "        # Extract passed (if present)\n")
     file(APPEND "${_summary_script}" "        CASES_PASSED=\$(echo \"\$SUMMARY_LINE\" | grep -o '[0-9]* passed' | grep -o '[0-9]*' || echo 0)\n")
     file(APPEND "${_summary_script}" "        # Extract failed (if present)\n")
     file(APPEND "${_summary_script}" "        CASES_FAILED=\$(echo \"\$SUMMARY_LINE\" | grep -o '[0-9]* failed' | grep -o '[0-9]*' || echo 0)\n")
     file(APPEND "${_summary_script}" "        # Extract total from 'test cases: X |'\n")
     file(APPEND "${_summary_script}" "        CASES_TOTAL=\$(echo \"\$SUMMARY_LINE\" | sed 's/test cases: \\([0-9]*\\).*/\\1/')\n")
     file(APPEND "${_summary_script}" "        # If no explicit passed count, calculate from total - failed\n")
     file(APPEND "${_summary_script}" "        if [ \$CASES_PASSED -eq 0 ] && [ \$CASES_FAILED -gt 0 ]; then\n")
     file(APPEND "${_summary_script}" "          CASES_PASSED=\$((CASES_TOTAL - CASES_FAILED))\n")
     file(APPEND "${_summary_script}" "        fi\n")
     file(APPEND "${_summary_script}" "      fi\n")
     file(APPEND "${_summary_script}" "      # Format 2: 'All tests passed (N assertion in M test cases)'\n")
     file(APPEND "${_summary_script}" "      if [ \$PARSED -eq 0 ]; then\n")
     file(APPEND "${_summary_script}" "        ALL_PASSED_LINE=\$(grep 'All tests passed' \"\$OUT_FILE\" 2>/dev/null | tail -1 || echo \"\")\n")
     file(APPEND "${_summary_script}" "        if [ -n \"\$ALL_PASSED_LINE\" ]; then\n")
     file(APPEND "${_summary_script}" "          PARSED=1\n")
     file(APPEND "${_summary_script}" "          # Extract test case count: 'in M test case' or 'in M test cases'\n")
     file(APPEND "${_summary_script}" "          CASES_PASSED=\$(echo \"\$ALL_PASSED_LINE\" | grep -o 'in [0-9]* test case' | grep -o '[0-9]*' || echo 0)\n")
     file(APPEND "${_summary_script}" "          CASES_FAILED=0\n")
     file(APPEND "${_summary_script}" "        fi\n")
     file(APPEND "${_summary_script}" "      fi\n")
     file(APPEND "${_summary_script}" "      # Update totals if we parsed something\n")
     file(APPEND "${_summary_script}" "      if [ \$PARSED -eq 1 ]; then\n")
     file(APPEND "${_summary_script}" "        # Detect runtime skips by parsing 'is skipped' messages in output\n")
     file(APPEND "${_summary_script}" "        # Tests that print 'is skipped' and return early are counted as 'passed' by Catch2\n")
     file(APPEND "${_summary_script}" "        RUNTIME_SKIPPED=\$(grep -i 'is skipped' \"\$OUT_FILE\" 2>/dev/null | wc -l)\n")
     file(APPEND "${_summary_script}" "        if [ \$RUNTIME_SKIPPED -gt 0 ] && [ \$CASES_PASSED -gt 0 ]; then\n")
     file(APPEND "${_summary_script}" "          # Move runtime-skipped tests from Passed to Skipped\n")
     file(APPEND "${_summary_script}" "          # Don't move more than what Catch2 reported as passed\n")
     file(APPEND "${_summary_script}" "          if [ \$RUNTIME_SKIPPED -gt \$CASES_PASSED ]; then\n")
     file(APPEND "${_summary_script}" "            RUNTIME_SKIPPED=\$CASES_PASSED\n")
     file(APPEND "${_summary_script}" "          fi\n")
     file(APPEND "${_summary_script}" "          CASES_PASSED=\$((CASES_PASSED - RUNTIME_SKIPPED))\n")
     file(APPEND "${_summary_script}" "          SKIPPED_TESTS=\$((SKIPPED_TESTS + RUNTIME_SKIPPED))\n")
     file(APPEND "${_summary_script}" "        fi\n")
     file(APPEND "${_summary_script}" "        PASSED_TESTS=\$((PASSED_TESTS + CASES_PASSED))\n")
     file(APPEND "${_summary_script}" "        FAILED_TESTS=\$((FAILED_TESTS + CASES_FAILED))\n")
     file(APPEND "${_summary_script}" "        # Categorize incomplete tests using exit code from output\n")
     file(APPEND "${_summary_script}" "        INCOMPLETE=\$((FILE_TOTAL - CASES_PASSED - CASES_FAILED - RUNTIME_SKIPPED))\n")
     file(APPEND "${_summary_script}" "        if [ \$INCOMPLETE -gt 0 ]; then\n")
     file(APPEND "${_summary_script}" "          # Get exit code from output file (wrapper writes EXIT_CODE: X)\n")
     file(APPEND "${_summary_script}" "          FILE_EXIT=\$(grep '^EXIT_CODE:' \"\$OUT_FILE\" 2>/dev/null | tail -1 | grep -o '[0-9]*' || echo 1)\n")
     file(APPEND "${_summary_script}" "          if [ \"\$FILE_EXIT\" -eq 0 ]; then\n")
     file(APPEND "${_summary_script}" "            SKIPPED_TESTS=\$((SKIPPED_TESTS + INCOMPLETE))\n")
     file(APPEND "${_summary_script}" "          else\n")
     file(APPEND "${_summary_script}" "            CRASHED_TESTS=\$((CRASHED_TESTS + INCOMPLETE))\n")
     file(APPEND "${_summary_script}" "          fi\n")
     file(APPEND "${_summary_script}" "        fi\n")
     file(APPEND "${_summary_script}" "      fi\n")
      file(APPEND "${_summary_script}" "    else\n")
      file(APPEND "${_summary_script}" "      # No output file - test crashed before producing output\n")
      file(APPEND "${_summary_script}" "      if [ \$FILE_TOTAL -gt 0 ]; then\n")
      file(APPEND "${_summary_script}" "        CRASHED_TESTS=\$((CRASHED_TESTS + FILE_TOTAL))\n")
      file(APPEND "${_summary_script}" "      fi\n")
      file(APPEND "${_summary_script}" "    fi\n")
      file(APPEND "${_summary_script}" "  fi\n")
      file(APPEND "${_summary_script}" "done\n")
      file(APPEND "${_summary_script}" "echo \"  Test Suites: \$TOTAL_FILES\"\n")
      file(APPEND "${_summary_script}" "echo \"  Total Tests: \$TOTAL_TESTS\"\n")
      file(APPEND "${_summary_script}" "echo \"  Passed: \$PASSED_TESTS\"\n")
      file(APPEND "${_summary_script}" "echo \"  Failed: \$FAILED_TESTS\"\n")
      file(APPEND "${_summary_script}" "if [ \$SKIPPED_TESTS -gt 0 ]; then\n")
      file(APPEND "${_summary_script}" "  echo \"  Skipped: \$SKIPPED_TESTS\"\n")
      file(APPEND "${_summary_script}" "fi\n")
      file(APPEND "${_summary_script}" "if [ \$CRASHED_TESTS -gt 0 ]; then\n")
      file(APPEND "${_summary_script}" "  echo \"  Crashed/Error: \$CRASHED_TESTS\"\n")
      file(APPEND "${_summary_script}" "fi\n")
      file(APPEND "${_summary_script}" "echo \"========================================\"\n")
      execute_process(COMMAND chmod +x "${_summary_script}")

      # Create a wrapper script that runs LIT then shows summary
      set(_lit_wrapper "${CMAKE_CURRENT_BINARY_DIR}/catch_tests/lit_wrapper_${CATEGORY}_${SUBDIR}_${VARIANT_SUFFIX}.sh")
      file(WRITE "${_lit_wrapper}" "#!/bin/bash\n")
      file(APPEND "${_lit_wrapper}" "cd ${CMAKE_CURRENT_BINARY_DIR}\n")
      # Convert test list to space-separated string for the command
      string(REPLACE ";" " " _test_list_str "${_subdir_variant_tests}")
      file(APPEND "${_lit_wrapper}" "${TEST_SUITE_LIT} ${TEST_SUITE_LIT_FLAGS} ${_test_list_str}\n")
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
    endif()

    # Ensure litsupport files (including lit.cfg) and timeit-target are available
    if(TARGET build-litsupport)
      add_dependencies(check-hip-catch-${CATEGORY}-${SUBDIR}-${VARIANT_SUFFIX} build-litsupport)
    endif()
    if(TARGET timeit-target)
      add_dependencies(check-hip-catch-${CATEGORY}-${SUBDIR}-${VARIANT_SUFFIX} timeit-target)
    endif()

    # Wire to aggregated check target (will run tests from all variants)
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
      # Add verbose flag to LIT if verbose Catch output is enabled
      set(_lit_flags ${TEST_SUITE_LIT_FLAGS})
      if(HIP_CATCH_TEST_VERBOSE)
        list(APPEND _lit_flags -a)  # Show all output (not just failures)
      endif()

      add_custom_target(check-hip-catch-${_category}-${VARIANT_SUFFIX}
        COMMAND ${TEST_SUITE_LIT} ${_lit_flags} ${_category_variant_tests}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS hip-tests-catch-${_category}-${VARIANT_SUFFIX}
        USES_TERMINAL
        COMMENT "Run HIP Catch ${_category} tests for variant ${VARIANT_SUFFIX}")
      # Ensure litsupport files (including lit.cfg) and timeit-target are available
      if(TARGET build-litsupport)
        add_dependencies(check-hip-catch-${_category}-${VARIANT_SUFFIX} build-litsupport)
      endif()
      if(TARGET timeit-target)
        add_dependencies(check-hip-catch-${_category}-${VARIANT_SUFFIX} timeit-target)
      endif()

      # Wire to aggregated check target (will run tests from all variants)
      add_dependencies(check-hip-catch-${_category} check-hip-catch-${_category}-${VARIANT_SUFFIX})
    endif()
  endforeach()

  # Add variant target to main catch target
  add_dependencies(hip-tests-catch hip-tests-catch-${VARIANT_SUFFIX})

  # Add verbose flag to LIT if verbose Catch output is enabled
  set(_lit_flags ${TEST_SUITE_LIT_FLAGS})
  if(HIP_CATCH_TEST_VERBOSE)
    list(APPEND _lit_flags -a)  # Show all output (not just failures)
  endif()

  # Create check target
  add_custom_target(check-hip-catch-${VARIANT_SUFFIX}
    COMMAND ${TEST_SUITE_LIT} ${_lit_flags}
            ${VARIANT_CATCH_TEST_TARGETS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS hip-tests-catch-${VARIANT_SUFFIX}
    USES_TERMINAL)
  # Ensure litsupport files (including lit.cfg) and timeit-target are available
  if(TARGET build-litsupport)
    add_dependencies(check-hip-catch-${VARIANT_SUFFIX} build-litsupport)
  endif()
  if(TARGET timeit-target)
    add_dependencies(check-hip-catch-${VARIANT_SUFFIX} timeit-target)
  endif()

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
