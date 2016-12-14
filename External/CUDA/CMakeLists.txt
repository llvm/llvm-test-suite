llvm_externals_find(TEST_SUITE_CUDA_ROOT "cuda" "CUDA prerequisites")

# Helper macro to extract version number at the end of the string
# Input: get_version(Var String)
#    Where String = /some/string/with/version-x.y.z
# Output:
#    Sets Var=x.y.z
macro(get_version Var Path)
    string(REGEX MATCH "[0-9]+(\.[0-9]+)+" ${Var} ${Path})
endmacro (get_version)

# Helper function to glob CUDA source files and set LANGUAGE property
# to CXX on each of them. Sets Var in parent scope to the list of
# files found.
macro(cuda_glob Var)
  file(GLOB FileList ${ARGN})
  foreach(File IN LISTS FileList)
    if(${File} MATCHES ".*\.cu$")
      set_source_files_properties(${File} PROPERTIES LANGUAGE CXX)
    endif()
  endforeach()
  set(${Var} ${FileList})
endmacro(cuda_glob)

macro(create_one_local_test Name FileGlob)
  cuda_glob(_sources ${FileGlob})
  set(_executable ${Name}-${VariantSuffix})
  set(_executable_path ${CMAKE_CURRENT_BINARY_DIR}/${_executable})
  # Verify reference output if it exists.
  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${Name}.reference_output)
    set(NO_REFERENCE_OUTPUT 1)
    set(REFERENCE_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${Name}.reference_output)
    llvm_test_traditional(${_executable})
  else()
    # otherwise just run the executable.
    llvm_test_run()
  endif()
  llvm_test_executable(${_executable} ${_sources})
  if(VariantLibs)
    target_link_libraries(${_executable} ${VariantLibs})
  endif()
  add_dependencies(cuda-tests-simple-${VariantSuffix} ${_executable})
  # Local tests are presumed to be fast.
  list(APPEND CUDA_SIMPLE_TEST_TARGETS ${_executable}.test)
endmacro()

# Create targets for CUDA tests that are part of the test suite.
macro(create_local_cuda_tests VariantSuffix)
  create_one_local_test(assert assert.cu)
  create_one_local_test(axpy axpy.cu)
  create_one_local_test(algorithm algorithm.cu)
  create_one_local_test(cmath cmath.cu)
  create_one_local_test(complex complex.cu)
  create_one_local_test(math_h math_h.cu)
  create_one_local_test(empty empty.cu)
  create_one_local_test(printf printf.cu)
  create_one_local_test(future future.cu)
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
  target_compile_options(${_executable} PUBLIC ${THRUST_CPPFLAGS})
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
    append_compile_flags(ThrustTestFrameworkLib-${VariantSuffix} ${CPPFLAGS} ${THRUST_CPPFLAGS})
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
    llvm_test_executable(${_ThrustMainTarget} ${ThrustTestFramework} ${ThrustAllTestSources})
    target_compile_options(${_ThrustMainTarget} PUBLIC ${THRUST_CPPFLAGS})
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
  list(APPEND CPPFLAGS ${_Cuda_CPPFLAGS} ${_Std_CPPFLAGS} ${_Stdlib_CPPFLAGS})
  list(APPEND LDFLAGS ${_Cuda_LDFLAGS} ${_Std_LDFLAGS} ${_Stdlib_LDFLAGS})

  # Create a separate test target for simple tests that can be built/tested quickly.
  add_custom_target(cuda-tests-simple-${VariantSuffix}
    COMMENT "Build Simple CUDA tests for ${VariantSuffix}")
  create_local_cuda_tests(${VariantSuffix})
  add_dependencies(cuda-tests-simple cuda-tests-simple-${VariantSuffix})

  if(EXISTS ${THRUST_PATH} AND (NOT ${Std} STREQUAL "c++14"))
    create_thrust_tests(${VariantSuffix})
  endif()

  # Target for CUDA tests that take little time to build and run.
  add_custom_target(check-cuda-simple-${VariantSuffix}
    COMMAND ${TEST_SUITE_LIT} ${TEST_SUITE_LIT_FLAGS}
            ${CUDA_SIMPLE_TEST_TARGETS}
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

  if (CUDA_JOBS)
    set(TEST_SUITE_LIT_FLAGS ${TEST_SUITE_LIT_FLAGS} -j ${CUDA_JOBS})
  endif()

  foreach(GpuArch IN LISTS CUDA_GPU_ARCH)
    list(APPEND CPPFLAGS --cuda-gpu-arch=${GpuArch})
  endforeach()

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
	    ${GccDir}/lib64/libstdc++.so)
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
    set(_Cuda_Libs cudart-${_CudaVersion})
    foreach(_Std IN ITEMS "c++98" "c++11" "c++14")
      set(_Std_Suffix "${_Std}")
      set(_Std_CPPFLAGS -std=${_Std})
      set(_Std_LDFLAGS -std=${_Std})
      foreach(_GccPath IN LISTS GCC_PATHS)
        get_version(_GccVersion ${_GccPath})
        # libstdc++ seems not to support C++14 before version 5.0.
        if(${_Std} STREQUAL "c++14" AND ${_GccVersion} VERSION_LESS "5.0")
          continue()
        endif()
        set(_Gcc_Suffix "libstdc++-${_GccVersion}")
        # Tell clang to use libstdc++ and where to find it.
        set(_Stdlib_CPPFLAGS -stdlib=libstdc++ -gcc-toolchain ${_GccPath})
        set(_Stdlib_LDFLAGS  -stdlib=libstdc++)
        # Add libstdc++ as link dependency.
        set(_Stdlib_Libs libstdcxx-${_GccVersion})

        create_cuda_test_variant(${_Std} "${_Cuda_Suffix}-${_Std_Suffix}-${_Gcc_Suffix}")
      endforeach()

      if(HAVE_LIBCXX)
	# Same as above, but for libc++
	# Tell clang to use libc++
	# We also need to add compiler's include path for cxxabi.h
	get_filename_component(_compiler_path ${CMAKE_CXX_COMPILER} DIRECTORY)
	set(_Stdlib_CPPFLAGS -stdlib=libc++ -I${_compiler_path}/../include/c++-build)
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

