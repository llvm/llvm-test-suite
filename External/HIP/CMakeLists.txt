include(ExternalProject)

include(External)
include(GPUTestVariant)
llvm_externals_find(TEST_SUITE_HIP_ROOT "hip" "HIP prerequisites")
message(STATUS "TEST_SUITE_HIP_ROOT: ${TEST_SUITE_HIP_ROOT}")
get_filename_component(HIP_CLANG_PATH ${CMAKE_CXX_COMPILER} DIRECTORY)
message(STATUS "HIP_CLANG_PATH: ${HIP_CLANG_PATH}")

# Include Catch tests integration module
include(${CMAKE_CURRENT_LIST_DIR}/HipCatchTests.cmake)

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

    create_one_local_test(${_hip_test} ${test_source}
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

  add_custom_target(check-hip-simple-${VariantSuffix}
    COMMAND ${TEST_SUITE_LIT} ${TEST_SUITE_LIT_FLAGS}
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
    list(APPEND AMDGPU_ARCHS "gfx906;gfx90a;gfx1030;gfx1100;native")
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
    ExternalProject_Add(BuildRocPrim
      GIT_REPOSITORY      https://github.com/ROCm/rocPRIM.git
      GIT_TAG             ae4d27e # Staging for ROCm 6.4
      CMAKE_ARGS          -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
                          -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
                          -DCMAKE_HIP_COMPILER=${CMAKE_CXX_COMPILER}
                          -DBUILD_TEST=ON
                          -DAMDGPU_TARGETS="${AMDGPU_ARCHS}"
                          -DCMAKE_BUILD_TYPE=Release
      INSTALL_COMMAND    ""
      TEST_COMMAND       ""
      )

    add_custom_target(build-rocprim DEPENDS BuildRocPrim)

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
