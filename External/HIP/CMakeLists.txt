include(ExternalProject)

include(External)
include(GPUTestVariant)
llvm_externals_find(TEST_SUITE_HIP_ROOT "hip" "HIP prerequisites")
message(STATUS "TEST_SUITE_HIP_ROOT: ${TEST_SUITE_HIP_ROOT}")
get_filename_component(HIP_CLANG_PATH ${CMAKE_CXX_COMPILER} DIRECTORY)
message(STATUS "HIP_CLANG_PATH: ${HIP_CLANG_PATH}")

# Include Catch tests integration module

# Find Python interpreter for running llvm-lit
# The llvm-lit script may have a hardcoded Python version in its shebang
# (e.g., #!/usr/bin/python3.10) that may not be available on all systems.
# We explicitly invoke llvm-lit with the detected Python interpreter.
find_package(Python3 COMPONENTS Interpreter)

if(Python3_FOUND)
  set(HIP_TEST_SUITE_LIT ${Python3_EXECUTABLE} ${TEST_SUITE_LIT})
  set(HIP_TEST_SUITE_LIT_BINARY ${TEST_SUITE_LIT})
  message(STATUS "HIP tests will use Python: ${Python3_EXECUTABLE}")
else()
  set(HIP_TEST_SUITE_LIT ${TEST_SUITE_LIT})
  set(HIP_TEST_SUITE_LIT_BINARY ${TEST_SUITE_LIT})
  message(WARNING "Python3 not found, HIP tests may fail if llvm-lit has wrong shebang")
endif()
include(${CMAKE_CURRENT_LIST_DIR}/HipCatchTests.cmake)

# Get rocm-libraries commit from TheRock (for version alignment)
function(get_therock_rocm_libraries_version OUT_VAR)
  set(THEROCK_LOCAL_DEV_PATH "/tmp/TheRock" CACHE PATH "Local TheRock for dev")
  set(THEROCK_REPO_URL "https://github.com/ROCm/TheRock.git" CACHE STRING "TheRock URL")
  set(THEROCK_BRANCH "main" CACHE STRING "TheRock branch")

  # Check if we have a local development copy
  if(EXISTS "${THEROCK_LOCAL_DEV_PATH}/.git")
    message(STATUS "Using local TheRock: ${THEROCK_LOCAL_DEV_PATH}")
    set(_therock_path "${THEROCK_LOCAL_DEV_PATH}")
  else()
    # CI path: use shallow clone in build directory
    set(_therock_path "${CMAKE_BINARY_DIR}/_deps/therock-metadata")

    if(EXISTS "${_therock_path}/.git")
      message(STATUS "Updating cached TheRock metadata...")
      execute_process(
        COMMAND git -C "${_therock_path}" fetch --depth=1 origin ${THEROCK_BRANCH}
        RESULT_VARIABLE _fetch_result
        OUTPUT_QUIET ERROR_QUIET
      )
      if(_fetch_result EQUAL 0)
        execute_process(
          COMMAND git -C "${_therock_path}" reset --hard FETCH_HEAD
          OUTPUT_QUIET ERROR_QUIET
        )
      endif()
    else()
      message(STATUS "Cloning TheRock metadata (shallow, ~100KB)...")
      file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/_deps")
      execute_process(
        COMMAND git clone --depth=1 --filter=blob:none --no-checkout
                ${THEROCK_REPO_URL} "${_therock_path}"
        OUTPUT_QUIET ERROR_QUIET
        COMMAND_ERROR_IS_FATAL ANY
      )
      execute_process(
        COMMAND git -C "${_therock_path}" checkout ${THEROCK_BRANCH} -- .gitmodules
        OUTPUT_QUIET ERROR_QUIET
        COMMAND_ERROR_IS_FATAL ANY
      )
    endif()
  endif()

  # Extract rocm-libraries commit reference
  execute_process(
    COMMAND git -C "${_therock_path}" ls-tree HEAD rocm-libraries
    OUTPUT_VARIABLE _tree_output
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE _result
  )

  if(NOT _result EQUAL 0)
    message(FATAL_ERROR "Failed to query rocm-libraries version from TheRock")
  endif()

  string(REGEX MATCH "commit ([0-9a-f]+)" _ "${_tree_output}")
  set(${OUT_VAR} "${CMAKE_MATCH_1}" PARENT_SCOPE)
endfunction()

# Inspired from create_one_local_test. Runs hipify on the TestSource and then compiles it.
# Search for the reference files next to TestSource.
macro(create_one_hipify_cuda_test TestName TestSource VairantOffload VariantSuffix VariantCPPFlags VariantLibs)
  set(_cuda_src "${TestSource}")
  set(_hip_src "${TestName}.hip")
  set(_hipify_target "${TestName}-hipify")

  set_source_files_properties(${_hip_src} PROPERTIES LANGUAGE CXX)
  add_custom_command(OUTPUT ${_hip_src}
                     COMMAND ${HIPIFY_EXE} "${_cuda_src}" -o "${_hip_src}"
                     DEPENDS "${_cuda_src}")
  add_custom_target(${_hipify_target} DEPENDS ${_hip_src})

  set(_executable ${TestName}-${VariantSuffix})
  set(_executable_path ${CMAKE_CURRENT_BINARY_DIR}/${_executable})
  llvm_test_run()

  get_filename_component(_test_source_dir "${TestSource}" DIRECTORY)
  get_filename_component(_test_source_name "${TestSource}" NAME_WE)
  set(REFERENCE_OUTPUT "${_test_source_dir}/${test_source_name}.reference_output")
  if(EXISTS "${REFERENCE_OUTPUT}")
    llvm_test_verify(WORKDIR %S
      %b/${FPCMP} %o ${REFERENCE_OUTPUT}-${VariantSuffix}
    )
    llvm_test_executable(${_executable} ${_hip_src})
    llvm_test_data(${_executable}
                    DEST_SUFFIX "-${VariantSuffix}"
                    ${REFERENCE_OUTPUT})
  else()
    llvm_test_executable(${_executable} ${_hip_src})
  endif()

  target_compile_options(${_executable} PUBLIC ${VariantCPPFLAGS})

  # In External/CUDA, tests define a STDLIB_VERSION that matches the C++
  # standard supported by the standard library.
  # For the HIP case, we set a huge number and assume that the latest C++
  # standard version is supported by the library.
  target_compile_definitions(${_executable} PRIVATE STDLIB_VERSION=9999)
  add_dependencies(${_executable} ${_hipify_target})
  if(VariantLibs)
    target_link_libraries(${_executable} ${VariantLibs})
  endif()

  add_dependencies(hip-tests-simple-${VariantSuffix} ${_executable})
  list(APPEND VARIANT_SIMPLE_TEST_TARGETS ${_executable}.test)
endmacro()

# Create targets for HIP tests that are part of the test suite.
macro(create_local_hip_tests VariantSuffix)
  set(VariantOffload "hip")
  # Set per-source compilation/link options
  set_source_files_properties(with-fopenmp.hip PROPERTIES
    COMPILE_FLAGS -fopenmp)
  # TODO: Add the flag after the kernel argument splitting pass is enabled.
  #set_source_files_properties(split-kernel-args.hip PROPERTIES
  #  COMPILE_FLAGS "-mllvm -amdgpu-enable-split-kernel-args")
  # Add HIP tests to be added to hip-tests-simple
  list(APPEND HIP_LOCAL_TESTS array)
  list(APPEND HIP_LOCAL_TESTS empty)
  list(APPEND HIP_LOCAL_TESTS with-fopenmp)
  list(APPEND HIP_LOCAL_TESTS saxpy)
  list(APPEND HIP_LOCAL_TESTS memmove)
  list(APPEND HIP_LOCAL_TESTS memset)
  list(APPEND HIP_LOCAL_TESTS split-kernel-args)
  list(APPEND HIP_LOCAL_TESTS builtin-logb-scalbn)
  list(APPEND HIP_LOCAL_TESTS simplify-f64-cmps)
  list(APPEND HIP_LOCAL_TESTS fast-i24-div-path)
  list(APPEND HIP_LOCAL_TESTS sdiv64_32)
  list(APPEND HIP_LOCAL_TESTS sdivrem23)
  list(APPEND HIP_LOCAL_TESTS udivrem23)
  list(APPEND HIP_LOCAL_TESTS udivrem24)
  list(APPEND HIP_LOCAL_TESTS multi_output)

  list(APPEND HIP_LOCAL_TESTS InOneWeekend)
  list(APPEND HIP_LOCAL_TESTS TheNextWeek)

  # Copy files needed for ray-tracing tests.
  file(GLOB IMAGE_FILES "workload/ray-tracing/images/*.jpg" "workload/ray-tracing/images/*.png")
  file(COPY ${IMAGE_FILES} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

  foreach(_hip_test IN LISTS HIP_LOCAL_TESTS)
    set(test_source "${_hip_test}.hip")

    if(_hip_test STREQUAL "TheNextWeek" OR _hip_test STREQUAL "InOneWeekend")
      file(GLOB REF_PPM_FILES "workload/ray-tracing/${_hip_test}/*.ppm")
      file(COPY ${REF_PPM_FILES} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
      set(test_source "workload/ray-tracing/${_hip_test}/main.cc")
      # need -mfma to enable FMA in host code
      set_source_files_properties(${test_source} PROPERTIES
        COMPILE_FLAGS "-xhip -mfma")
    endif()

    # Create one test for each option set in the <_hip_test>.options file.
    create_local_tests_with_options(${_hip_test} ${test_source}
                          ${VariantOffload} ${VariantSuffix}
                          "${VariantCPPFLAGS}" "${VariantLibs}")
  endforeach()

  list(APPEND CUDA_LOCAL_TESTS algorithm)
  list(APPEND CUDA_LOCAL_TESTS cmath)
  list(APPEND CUDA_LOCAL_TESTS complex)
  list(APPEND CUDA_LOCAL_TESTS math_h)
  list(APPEND CUDA_LOCAL_TESTS new)

  find_program(HIPIFY_EXE
               NAME hipify-perl
               PATHS ${_RocmPath}/bin)

  if(HIPIFY_EXE)
      foreach(_cuda_test IN LISTS CUDA_LOCAL_TESTS)
        set(_cuda_src "${CMAKE_CURRENT_SOURCE_DIR}/../CUDA/${_cuda_test}.cu")
        create_one_hipify_cuda_test(${_cuda_test} ${_cuda_src}
          ${VariantOffload} ${VariantSuffix}
          "${VariantCPPFLAGS}" "${VariantLibs}")
      endforeach()
  else()
      message(WARNING "hipify-perl not found for ROCm installation in ${_RocmPath}.")
  endif()

  # Add test for Blender.
  configure_file(workload/blender/test_blender.sh.in ${CMAKE_CURRENT_BINARY_DIR}/test_blender.sh @ONLY)
  configure_file(workload/blender/verify_blender.sh.in ${CMAKE_CURRENT_BINARY_DIR}/verify_blender.sh @ONLY)
  file(COPY utils/log_data.py DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
  file(COPY utils/compare_image.py DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
  file(COPY utils/requirements.txt DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
  llvm_test_run(EXECUTABLE "/bin/bash" "test_blender.sh")
  llvm_test_verify(/bin/bash verify_blender.sh %o)
  llvm_add_test(blender.test test_blender.sh)
  list(APPEND VARIANT_SIMPLE_TEST_TARGETS blender.test)
endmacro()

function(create_hip_test VariantSuffix)
  message(STATUS "Creating HIP test variant ${VariantSuffix}")
  add_custom_target(hip-tests-simple-${VariantSuffix}
    COMMENT "Build HIP test variant ${VariantSuffix}")

  set(VariantCPPFLAGS ${_HIP_CPPFLAGS})
  set(VariantLibs ${_HIP_Libs})
  list(APPEND LDFLAGS ${_HIP_LDFLAGS})

  create_local_hip_tests(${VariantSuffix})
  add_dependencies(hip-tests-simple hip-tests-simple-${VariantSuffix})

  # Enable verbose output for running HIP tests.
  set(HIP_LIT_FLAGS "-v")
  if (HIP_EXPORT_XUNIT_XML)
    list(APPEND HIP_LIT_FLAGS --xunit-xml-output hip-results-${VariantSuffix}.xml)
  endif()

  add_custom_target(check-hip-simple-${VariantSuffix}
    COMMAND ${HIP_TEST_SUITE_LIT} ${HIP_LIT_FLAGS}
            ${VARIANT_SIMPLE_TEST_TARGETS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS hip-tests-simple-${VariantSuffix}
    USES_TERMINAL)
  add_dependencies(check-hip-simple check-hip-simple-${VariantSuffix})

  # Integrate Catch tests for this variant (if enabled)
  if(ENABLE_HIP_CATCH_TESTS)
    integrate_catch_tests(${VariantSuffix} ${_RocmPath})
  endif()
endfunction(create_hip_test)

macro(create_hip_tests)
  # Find all rocm installations at Externals/hip/ directory.
  # For ROCm, the path looks like rocm-4.1.0
  message(STATUS "Checking HIP prerequisites in ${TEST_SUITE_HIP_ROOT}")
  file(GLOB RocmVersions ${TEST_SUITE_HIP_ROOT}/rocm-*)
  list(SORT RocmVersions)
  foreach(RocmDir IN LISTS RocmVersions)
    get_version(RocmVersion ${RocmDir})
    message(STATUS "Found ROCm ${RocmVersion}")
    list(APPEND ROCM_PATHS ${RocmDir})
  endforeach(RocmDir)

  if(NOT ROCM_PATHS)
    message(SEND_ERROR
      "There are no ROCm installations in ${TEST_SUITE_HIP_ROOT}")
    return()
  endif()

  add_custom_target(hip-tests-simple
    COMMENT "Build all simple HIP tests")
  add_custom_target(check-hip-simple
    COMMENT "Run all simple HIP tests")

  # Initialize Catch tests framework
  initialize_catch_tests()

  if(NOT AMDGPU_ARCHS)
    list(APPEND AMDGPU_ARCHS "gfx906;gfx90a;gfx1030;gfx1100;gfx1201;gfx942;gfx950;native")
  endif()

  foreach(_RocmPath ${ROCM_PATHS})
    get_version(_RocmVersion ${_RocmPath})
    set(_HIP_Suffix "hip-${_RocmVersion}")
    # Set up HIP test flags
    set(_HIP_CPPFLAGS --rocm-path=${_RocmPath})
    set(_HIP_LDFLAGS --rocm-path=${_RocmPath} --hip-link -rtlib=compiler-rt -unwindlib=libgcc -frtlib-add-rpath)

    # Unset these for each iteration of rocm path.
    set(_ArchFlags)
    set(_ArchList)
    foreach(_AMDGPUArch IN LISTS AMDGPU_ARCHS)
      list(APPEND _ArchFlags --offload-arch=${_AMDGPUArch})
    endforeach()
    message(STATUS "Building ${_RocmPath} targets for ${AMDGPU_ARCHS}")
    list(APPEND _HIP_CPPFLAGS ${_ArchFlags})

    create_hip_test(${_HIP_Suffix})
  endforeach()

  if (EXTERNAL_HIP_TESTS_KOKKOS)
    set(EXTERNAL_HIP_TESTS_KOKKOS_TAG "4.5.01" CACHE STRING "Kokkos tag to download and test")
    ExternalProject_Add(TestKokkosHIP
      GIT_REPOSITORY  https://github.com/kokkos/kokkos.git
      GIT_TAG         ${EXTERNAL_HIP_TESTS_KOKKOS_TAG}
      CMAKE_ARGS      -DCMAKE_BUILD_TYPE=Release
                      -DCMAKE_CXX_STANDARD=17
                      -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
                      -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
                      -DKokkos_ENABLE_HIP=ON
                      -DKokkos_ARCH_AMD_GFX90A=ON
                      -DCMAKE_PREFIX_PATH=/opt/rocm
                      -DKokkos_ENABLE_TESTS=ON
      INSTALL_COMMAND ""
      TEST_COMMAND    ""
      )
    add_custom_target(build-kokkos DEPENDS TestKokkosHIP)
    ExternalProject_Get_Property(TestKokkosHIP BINARY_DIR)
    add_custom_target(test-kokkos ${CMAKE_COMMAND} -E env GTEST_FILTER=-hip.atomics:hip.bit_manip_bit_ceil "ctest" WORKING_DIRECTORY "${BINARY_DIR}" DEPENDS build-kokkos)
  endif()

  if (EXTERNAL_HIP_TESTS_GINKGO)
    set(EXTERNAL_HIP_TESTS_GINKGO_TAG "v1.9.0" CACHE STRING "Ginkgo tag to download and test")
    ExternalProject_Add(TestGinkgoHIP
      GIT_REPOSITORY  https://github.com/ginkgo-project/ginkgo.git
      GIT_TAG         ${EXTERNAL_HIP_TESTS_GINKGO_TAG}
      CMAKE_ARGS      -DGINKGO_BUILD_HIP=ON
                      -DCMAKE_PREFIX_PATH=/opt/rocm
                      -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
                      -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
                      -DGINKGO_BUILD_MPI=OFF
                      -DCMAKE_HIP_COMPILER=${CMAKE_CXX_COMPILER}
                      -DGINKGO_WITH_CCACHE=OFF
                      -DGINKGO_BUILD_EXAMPLES=OFF
      INSTALL_COMMAND ""
      TEST_COMMAND    ""
      )

    add_custom_target(build-ginkgo DEPENDS TestGinkgoHIP)
    ExternalProject_Get_Property(TestGinkgoHIP BINARY_DIR)
    add_custom_target(test-ginkgo COMMAND "ctest" "-R hip" WORKING_DIRECTORY "${BINARY_DIR}" DEPENDS build-ginkgo)
  endif()

  if (EXTERNAL_HIP_TESTS_ROCPRIM)
    # Get rocm-libraries version from TheRock
    get_therock_rocm_libraries_version(_rocm_libraries_commit)
    message(STATUS "Using rocm-libraries commit: ${_rocm_libraries_commit}")
    set(ROCPRIM_TESTS_PARALLELISM "16" CACHE STRING "-j Argument to ctest")

    include(FetchContent)
    # XXX: Can we reduce what is being downloaded here using somewhat simple mechanisms?
    FetchContent_Declare(
      rocm-libraries
      GIT_REPOSITORY https://github.com/ROCm/rocm-libraries.git
      GIT_TAG        ${_rocm_libraries_commit}
    )

    # Download rocm-libraries but don't configure yet
    FetchContent_GetProperties(rocm-libraries)
    if(NOT rocm-libraries_POPULATED)
      FetchContent_Populate(rocm-libraries)

      # Patch rocprim test/CMakeLists.txt to use PROJECT_SOURCE_DIR instead of CMAKE_SOURCE_DIR
      # This fixes the issue where CMAKE_SOURCE_DIR points to llvm-test-suite instead of rocprim
      # If not patched, enabling tests will fail during configure with a missing file
      file(READ "${rocm-libraries_SOURCE_DIR}/projects/rocprim/test/CMakeLists.txt" _rocprim_test_cmake)
      string(REPLACE "\${CMAKE_SOURCE_DIR}/test/" "\${PROJECT_SOURCE_DIR}/test/" _rocprim_test_cmake "${_rocprim_test_cmake}")
      string(REPLACE "\${CMAKE_SOURCE_DIR}/rtest." "\${PROJECT_SOURCE_DIR}/rtest." _rocprim_test_cmake "${_rocprim_test_cmake}")
      file(WRITE "${rocm-libraries_SOURCE_DIR}/projects/rocprim/test/CMakeLists.txt" "${_rocprim_test_cmake}")
    endif()

    # Configure rocPRIM as isolated external project (like Kokkos/Ginkgo pattern)
    ExternalProject_Add(rocprim-external
      SOURCE_DIR      ${rocm-libraries_SOURCE_DIR}/projects/rocprim
      BINARY_DIR      ${rocm-libraries_BINARY_DIR}/rocprim
      CMAKE_ARGS      -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
                      -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
                      -DCMAKE_HIP_COMPILER=${CMAKE_CXX_COMPILER}
                      -DGPU_TARGETS=${AMDGPU_ARCHS}
                      -DBUILD_TEST=ON
                      -DBUILD_BENCHMARK=OFF
                      -DBUILD_EXAMPLE=OFF
                      -DCMAKE_BUILD_TYPE=Release
                      -DCMAKE_BUILD_WITH_INSTALL_RPATH=ON
      BUILD_COMMAND   ""  # Don't build during configure
      INSTALL_COMMAND ""
      TEST_COMMAND    ""
    )

    # Standalone target to build all rocPRIM tests
    add_custom_target(build-rocprim
      COMMAND ${CMAKE_COMMAND} --build ${rocm-libraries_BINARY_DIR}/rocprim
      DEPENDS rocprim-external
      COMMENT "Building all rocPRIM tests"
    )

    # Standalone target to run rocPRIM tests
    add_custom_target(test-rocprim
	    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure -j ${ROCPRIM_TESTS_PARALLELISM}
      WORKING_DIRECTORY ${rocm-libraries_BINARY_DIR}/rocprim
      DEPENDS build-rocprim
      COMMENT "Running rocPRIM tests"
    )
  endif()

  # Build all HIP tests (simple + catch if enabled)
  if(ENABLE_HIP_CATCH_TESTS)
    add_custom_target(hip-tests-all DEPENDS hip-tests-simple hip-tests-catch
      COMMENT "Build all HIP tests (simple + catch).")
  else()
    add_custom_target(hip-tests-all DEPENDS hip-tests-simple
      COMMENT "Build all HIP tests (simple only, catch disabled).")
  endif()

  file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
endmacro(create_hip_tests)

if(TEST_SUITE_HIP_ROOT)
  create_hip_tests()
endif()
