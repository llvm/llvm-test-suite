include(External)
include(GPUTestVariant)
llvm_externals_find(TEST_SUITE_CUDA_ROOT "cuda" "CUDA prerequisites")

set(SUPPORTED_GPU_CUDA_7_0
  sm_20 sm_21
  sm_30 sm_32 sm_35 sm_37
  sm_50 sm_52 sm_53)
set(SUPPORTED_GPU_CUDA_7_5 ${SUPPORTED_GPU_CUDA_7_0})

set(SUPPORTED_GPU_CUDA_8_0 ${SUPPORTED_GPU_CUDA_7_5}
  sm_60 sm_61 sm_62)

set(SUPPORTED_GPU_CUDA_9_0 ${SUPPORTED_GPU_CUDA_8_0}
  sm_70)
set(SUPPORTED_GPU_CUDA_9_1 ${SUPPORTED_GPU_CUDA_9_0}
  sm_72)
# 9.2 removed sm_2x
set(SUPPORTED_GPU_CUDA_9_2
  sm_30 sm_32 sm_35 sm_37
  sm_50 sm_52 sm_53
  sm_60 sm_61 sm_62
  sm_70 sm_72
)

set(SUPPORTED_GPU_CUDA_10_0 ${SUPPORTED_GPU_CUDA_9_2}
  sm_75)
set(SUPPORTED_GPU_CUDA_10_1 ${SUPPORTED_GPU_CUDA_10_0})
set(SUPPORTED_GPU_CUDA_10_2 ${SUPPORTED_GPU_CUDA_10_1})

set(SUPPORTED_GPU_CUDA_11_0 ${SUPPORTED_GPU_CUDA_10_2}
  sm_80)
set(SUPPORTED_GPU_CUDA_11_1 ${SUPPORTED_GPU_CUDA_11_0}
  sm_86)
set(SUPPORTED_GPU_CUDA_11_2 ${SUPPORTED_GPU_CUDA_11_1})
set(SUPPORTED_GPU_CUDA_11_3 ${SUPPORTED_GPU_CUDA_11_2})
set(SUPPORTED_GPU_CUDA_11_4 ${SUPPORTED_GPU_CUDA_11_3})
set(SUPPORTED_GPU_CUDA_11_5 ${SUPPORTED_GPU_CUDA_11_4})
set(SUPPORTED_GPU_CUDA_11_6 ${SUPPORTED_GPU_CUDA_11_5})
set(SUPPORTED_GPU_CUDA_11_7 ${SUPPORTED_GPU_CUDA_11_6})
set(SUPPORTED_GPU_CUDA_11_8 ${SUPPORTED_GPU_CUDA_11_7}
  sm_89 sm_90)

# CUDA-12.0 no longer supports sm_3x and older GPUs.
set(SUPPORTED_GPU_CUDA_12_0
  sm_50 sm_52 sm_53
  sm_60 sm_61 sm_62
  sm_70 sm_72 sm_75
  sm_80 sm_86 sm_87 sm_89
  sm_90 sm_90a
)
set(SUPPORTED_GPU_CUDA_12_1 ${SUPPORTED_GPU_CUDA_12_0})
set(SUPPORTED_GPU_CUDA_12_2 ${SUPPORTED_GPU_CUDA_12_1})
set(SUPPORTED_GPU_CUDA_12_3 ${SUPPORTED_GPU_CUDA_12_2})

set(CUDA_NEW_DRIVER ON CACHE BOOL "Use the new Clang offloading Driver")

# Create targets for CUDA tests that are part of the test suite.
macro(create_local_cuda_tests VariantSuffix)
  set(VariantOffload "cuda")
  list(APPEND CUDA_LOCAL_TESTS assert)
  list(APPEND CUDA_LOCAL_TESTS axpy)
  list(APPEND CUDA_LOCAL_TESTS algorithm)
  list(APPEND CUDA_LOCAL_TESTS cmath)
  list(APPEND CUDA_LOCAL_TESTS complex)
  list(APPEND CUDA_LOCAL_TESTS math_h)
  list(APPEND CUDA_LOCAL_TESTS new)
  list(APPEND CUDA_LOCAL_TESTS empty)
  list(APPEND CUDA_LOCAL_TESTS printf)
  list(APPEND CUDA_LOCAL_TESTS future)
  list(APPEND CUDA_LOCAL_TESTS builtin_var)
  list(APPEND CUDA_LOCAL_TESTS test_round)
  foreach(_cuda_test IN LISTS CUDA_LOCAL_TESTS)
    create_one_local_test(${_cuda_test} ${_cuda_test}.cu
                          ${VariantOffload} ${VariantSuffix}
                          "${VariantCPPFLAGS}" "${VariantLibs}")
  endforeach()

  # We only need SIMD tests on CUDA-8.0 to verify that our reference is correct
  # and matches NVIDIA-provided one.  and on CUDA-9.2 to verify that clang's
  # implementation matches the reference.  This test also happens to be the
  # longest one, so by not running unnecessary instances we speed up cuda
  # buildbot a lot.
  create_one_local_test_f(simd simd.cu
                          "cuda-(8[.]0|9[.]2)-c[+][+]11-libc[+][+]"
                          ${VariantOffload} ${VariantSuffix}
                          "${VariantCPPFLAGS}" "${VariantLibs}")
endmacro()

macro(thrust_make_test_name TestName TestSourcePath)
  string(REPLACE "${THRUST_PATH}/testing/" "" _tmp ${TestSourcePath})
  string(REPLACE "/" "-" _tmp ${_tmp})
  string(REPLACE "<" "_" _tmp ${_tmp})
  string(REPLACE ">" "_" _tmp ${_tmp})
  string(REGEX REPLACE "\.(cpp|cu)$" "" _tmp ${_tmp})
  set(${TestName} ${_tmp})
endmacro()

macro(create_one_thrust_test TestSource)
  thrust_make_test_name(_TestName ${TestSourcePath})
  set(_executable thrust-${_TestName}-${VariantSuffix})
  llvm_test_run(--verbose ${_ExtraThrustTestArgs})
  llvm_test_executable(${_executable} ${TestSource})
  target_link_libraries(${_executable} ${VariantLibs})
  target_compile_options(${_executable} BEFORE PUBLIC ${THRUST_CPPFLAGS})
  target_compile_options(${_executable} PUBLIC ${VariantCPPFLAGS})
  list(APPEND THRUST_VARIANT_TESTS ${_executable})
endmacro()

function(create_thrust_tests VariantSuffix)
  set(_ThrustMainTarget cuda-tests-thrust-${VariantSuffix})
  if(LARGE_PROBLEM_SIZE)
    set(_ExtraThrustTestArgs "--sizes=large")
  endif()
  if(THRUST_SPLIT_TESTS)
    # test framework is common for all tests, so we build it once as a
    # library.
    add_library(ThrustTestFrameworkLib-${VariantSuffix} STATIC ${ThrustTestFramework})
    target_compile_options(ThrustTestFrameworkLib-${VariantSuffix} BEFORE PRIVATE ${THRUST_CPPFLAGS})
    target_compile_options(ThrustTestFrameworkLib-${VariantSuffix} PRIVATE ${VariantCPPFLAGS})
    add_dependencies(ThrustTestFrameworkLib-${VariantSuffix} timeit-host fpcmp-host)
    list(APPEND VariantLibs ThrustTestFrameworkLib-${VariantSuffix})

    # Create individual test executable per test source file. This
    # stresses cmake -- it consumes tons of memory and takes forever
    # to finish.
    foreach(TestSourcePath IN LISTS ThrustAllTestSources)
      create_one_thrust_test(${TestSourcePath})
    endforeach()
    # Create target to build all thrust tests for this variant
    add_custom_target(${_ThrustMainTarget} DEPENDS ${THRUST_VARIANT_TESTS}
      COMMENT "Build CUDA test variant ${VariantSuffix}")
  else()
    # Single monolitic test executable. Alas this stresses linker
    # during debug build. Final executable may end up being too large
    # to link.
    # We can create one test script per thrust test, but running
    # thrust tests in parallel is bottlenecked by GPU and startup
    # overhead, so it's actually way slower than running all tests
    # sequentially.
    llvm_test_run(--verbose ${_ExtraThrustTestArgs})
    # CUDA SDK comes with its own version of thrust in its include directory.
    # In order to use the thrust library we want, its include path must precede
    # that of the CUDA SDK include path.
    llvm_test_executable(${_ThrustMainTarget} ${ThrustTestFramework} ${ThrustAllTestSources})
    target_compile_options(${_ThrustMainTarget} BEFORE PUBLIC ${THRUST_CPPFLAGS})
    target_compile_options(${_ThrustMainTarget} PUBLIC ${VariantCPPFLAGS})
    target_link_libraries(${_ThrustMainTarget} ${VariantLibs})
  endif()
  add_dependencies(cuda-tests-${VariantSuffix} cuda-tests-thrust-${VariantSuffix})
  add_dependencies(cuda-tests-thrust ${_ThrustMainTarget})
endfunction()

# Create set of tests for a given {CUDA,C++ standard,C++ library} tuple.
function(create_cuda_test_variant Std VariantSuffix)
  message(STATUS "Creating CUDA test variant ${VariantSuffix}")
  add_custom_target(cuda-tests-${VariantSuffix}
    COMMENT "Build CUDA test variant ${VariantSuffix}")

  set(VariantLibs ${_Cuda_Libs} ${_Stdlib_Libs})
  set(VariantCPPFLAGS ${_Cuda_CPPFLAGS} ${_Std_CPPFLAGS} ${_Stdlib_CPPFLAGS})
  list(APPEND LDFLAGS ${_Cuda_LDFLAGS} ${_Std_LDFLAGS} ${_Stdlib_LDFLAGS})

  # Create a separate test target for simple tests that can be built/tested quickly.
  add_custom_target(cuda-tests-simple-${VariantSuffix}
    COMMENT "Build Simple CUDA tests for ${VariantSuffix}")
  create_local_cuda_tests(${VariantSuffix})
  add_dependencies(cuda-tests-simple cuda-tests-simple-${VariantSuffix})

  if(DEFINED THRUST_PATH AND (NOT ${Std} IN_LIST "c++14;c++17;c++20"))
    create_thrust_tests(${VariantSuffix})
  endif()

  # Target for CUDA tests that take little time to build and run.
  add_custom_target(check-cuda-simple-${VariantSuffix}
    COMMAND ${TEST_SUITE_LIT} ${TEST_SUITE_LIT_FLAGS}
            ${VARIANT_SIMPLE_TEST_TARGETS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS cuda-tests-simple-${VariantSuffix}
    USES_TERMINAL)
  add_dependencies(check-cuda-simple check-cuda-simple-${VariantSuffix})
endfunction(create_cuda_test_variant)

macro(create_cuda_tests)
  message(STATUS "Checking CUDA prerequisites in ${TEST_SUITE_CUDA_ROOT}")
  file(GLOB CudaVersions ${TEST_SUITE_CUDA_ROOT}/cuda-*)
  list(SORT CudaVersions)
  foreach(CudaDir IN LISTS CudaVersions)
    get_version(CudaVersion ${CudaDir})
    message(STATUS "Found CUDA ${CudaVersion}")
    list(APPEND CUDA_PATHS ${CudaDir})
    add_library(cudart-${CudaVersion} SHARED IMPORTED)
    set_property(TARGET cudart-${CudaVersion} PROPERTY IMPORTED_LOCATION
      ${CudaDir}/lib64/libcudart.so)
  endforeach(CudaDir)

  if(NOT CUDA_PATHS)
    message(SEND_ERROR
      "There are no CUDA installations in ${TEST_SUITE_CUDA_ROOT}")
    return()
  endif()

  # Special target to build all simple tests. Useful for quick smoke test
  # before we embark on heavy-duty compilation which may not be worth it.
  add_custom_target(cuda-tests-simple
    COMMENT "Build all simple CUDA tests")
  add_custom_target(check-cuda-simple
    COMMENT "Run all simple CUDA tests")

  # set default GPU arch
  if(NOT CUDA_GPU_ARCH)
    list(APPEND CUDA_GPU_ARCH sm_35)
  endif()
  list(SORT CUDA_GPU_ARCH)

  if (CUDA_JOBS)
    set(TEST_SUITE_LIT_FLAGS ${TEST_SUITE_LIT_FLAGS} -j ${CUDA_JOBS})
  endif()

  file(GLOB GccVersions ${TEST_SUITE_CUDA_ROOT}/gcc-*)
  list(SORT GccVersions)
  foreach(GccRoot IN LISTS GccVersions)
    get_version(GccVersion ${GccRoot})
    foreach(GccDir IN ITEMS ${GccRoot} ${GccRoot}/usr/local)
      if(EXISTS ${GccDir}/bin/gcc)
	execute_process(
	  COMMAND ${GccDir}/bin/gcc -print-file-name=libstdc++.so
	  OUTPUT_VARIABLE _path_to_libstdcxx
	  OUTPUT_STRIP_TRAILING_WHITESPACE)
	if(EXISTS ${_path_to_libstdcxx})
	  message(STATUS "Found libstdc++ ${GccVersion}")
	  add_library(libstdcxx-${GccVersion} SHARED IMPORTED)
	  set_property(TARGET libstdcxx-${GccVersion} PROPERTY IMPORTED_LOCATION
	    ${_path_to_libstdcxx})
	  list(APPEND GCC_PATHS ${GccDir})
	  break()
	endif()
      endif()
    endforeach(GccDir)
  endforeach(GccRoot)

  # Find location of libc++
  execute_process(
    COMMAND ${CMAKE_CXX_COMPILER} -print-file-name=libc++.so
    OUTPUT_VARIABLE _path_to_libcxx
    OUTPUT_STRIP_TRAILING_WHITESPACE)

  if(EXISTS ${_path_to_libcxx})
    add_library(libcxx SHARED IMPORTED)
    set_property(TARGET libcxx PROPERTY IMPORTED_LOCATION ${_path_to_libcxx})
    get_filename_component(_libcxx_dir ${_path_to_libcxx} DIRECTORY)
    target_link_options(libcxx INTERFACE "-Wl,-rpath,${_libcxx_dir}")
    set(HAVE_LIBCXX 1)
  else()
    message(WARNING "Can't find libcxx location.")
  endif()

  if(EXISTS "${TEST_SUITE_CUDA_ROOT}/thrust")
    message(STATUS "Found Thrust ${THRUST_PATH}")
    add_custom_target(cuda-tests-thrust COMMENT "All thrust tests.")
    if(THRUST_SPLIT_TESTS)
      message(WARNING
	"############################################################\n"
	"Split tests for thrust will take a while to generate...     \n"
	"############################################################\n")
    endif()
    set(THRUST_PATH "${TEST_SUITE_CUDA_ROOT}/thrust" CACHE
      PATH "Thrust library path")
    set(THRUST_CPPFLAGS
      -O2
      -DTHRUST_HOST_SYSTEM=THRUST_HOST_SYSTEM_CPP
      -DTHRUST_DEVICE_SYSTEM=THRUST_DEVICE_SYSTEM_CUDA
      -I${THRUST_PATH} -I${THRUST_PATH}/testing)

    cuda_glob(ThrustTestCppSources ${THRUST_PATH}/testing/*.cpp)
    cuda_glob(ThrustTestCudaSources ${THRUST_PATH}/testing/*.cu)
    cuda_glob(ThrustTestCudaBackendSources
      ${THRUST_PATH}/testing/backend/decompose.cu
      ${THRUST_PATH}/testing/backend/cuda/*.cu)

    list(APPEND ThrustAllTestSources ${ThrustTestCppSources}
      ${ThrustTestCudaSources} ${ThrustTestCudaBackendSources})
    list(APPEND ThrustTestFramework
      ${THRUST_PATH}/testing/testframework.cpp
      ${THRUST_PATH}/testing/reduce_large.cu
      ${THRUST_PATH}/testing/unittest_tester.cu
      ${THRUST_PATH}/testing/backend/cuda/testframework.cu)

    # Remove test framework files from the list of test files.
    foreach(File IN LISTS ThrustTestFramework)
      list(REMOVE_ITEM ThrustAllTestSources ${File})
    endforeach()
  endif()

  foreach(_CudaPath ${CUDA_PATHS})
    get_version(_CudaVersion ${_CudaPath})
    set(_Cuda_Suffix "cuda-${_CudaVersion}")
    set(_Cuda_CPPFLAGS --cuda-path=${_CudaPath} -I${_CudaPath}/include)
    # clear the list of GPUs to compile for.
    set(_CudaArchFlags)
    set(_CudaArchList)
    string(REPLACE "." "_" _CudaVersionSuffix ${_CudaVersion})
    foreach(_CudaGpuArch IN LISTS CUDA_GPU_ARCH)
      if(_CudaGpuArch IN_LIST SUPPORTED_GPU_CUDA_${_CudaVersionSuffix})
        list(APPEND _CudaArchFlags --cuda-gpu-arch=${_CudaGpuArch})
        list(APPEND _CudaArchList ${_CudaGpuArch})
      endif()
    endforeach()
    if (_CudaArchList)
      message(STATUS "Building ${_Cuda_Suffix} targets for ${_CudaArchList}")
    else()
      message(WARNING "${_Cuda_Suffix} does not support ${CUDA_GPU_ARCH} GPUs. Skipped.")
      continue()
    endif()
    list(APPEND _Cuda_CPPFLAGS ${_CudaArchFlags})
    if (CUDA_NEW_DRIVER)
      list(APPEND _Cuda_CPPFLAGS -fgpu-rdc --offload-new-driver)
      list(APPEND _Cuda_LDFLAGS --offload-new-driver)
    endif()

    set(_Cuda_Libs cudart-${_CudaVersion})
    foreach(_Std IN ITEMS "c++98" "c++11" "c++14" "c++17" "c++20")
      set(_Std_Suffix "${_Std}")
      set(_Std_CPPFLAGS -std=${_Std})
      set(_Std_LDFLAGS -std=${_Std})
      foreach(_GccPath IN LISTS GCC_PATHS)
        get_version(_GccVersion ${_GccPath})
        set(_Gcc_Suffix "libstdc++-${_GccVersion}")
        # Tell clang to use libstdc++ and where to find it.
        set(_Stdlib_CPPFLAGS -stdlib=libstdc++ --gcc-toolchain=${_GccPath})
        set(_Stdlib_LDFLAGS  -stdlib=libstdc++)
        # Add libstdc++ as link dependency.
        set(_Stdlib_Libs libstdcxx-${_GccVersion})

        # libstdc++ seems not to support C++14 before version 5.0.  We still
        # want to run in C++14 mode with old libstdc++s to test compiler C++14
        # with stdlib C++11, but we add a -D so that our tests can detect this.
        if (${_GccVersion} VERSION_LESS "5.0")
          list(APPEND _Stdlib_CPPFLAGS -DSTDLIB_VERSION=2011)
        else()
          list(APPEND _Stdlib_CPPFLAGS -DSTDLIB_VERSION=2014)
        endif()

        create_cuda_test_variant(${_Std} "${_Cuda_Suffix}-${_Std_Suffix}-${_Gcc_Suffix}")
      endforeach()

      if(HAVE_LIBCXX)
        # Same as above, but for libc++
        # Tell clang to use libc++
        # We also need to add compiler's include path for cxxabi.h
        get_filename_component(_compiler_path ${CMAKE_CXX_COMPILER} DIRECTORY)
        set(_Stdlib_CPPFLAGS -stdlib=libc++ -I${_compiler_path}/../include/c++/v1
            -DSTDLIB_VERSION=2017 -D_ALLOW_UNSUPPORTED_LIBCPP)
        set(_Stdlib_LDFLAGS  -stdlib=libc++)
        set(_Stdlib_Libs libcxx)
        create_cuda_test_variant(${_Std} "${_Cuda_Suffix}-${_Std_Suffix}-libc++")
      endif()
    endforeach()
  endforeach()

  # convenience target to build all CUDA tests.
  add_custom_target(cuda-tests-all DEPENDS cuda-tests-simple cuda-tests-thrust
    COMMENT "Build all CUDA tests.")

  # stage lit config needed to control how CUDA tests are run.
  file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
endmacro(create_cuda_tests)

# We always want asserts() to run.
list(APPEND CPPFLAGS "-UNDEBUG")

if(TEST_SUITE_CUDA_ROOT)
  create_cuda_tests()
endif()

