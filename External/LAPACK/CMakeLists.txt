include(ExternalProject)
include(External)

option(TEST_SUITE_ENABLE_LAPACK
  "Download and test the pinned LAPACK version" OFF)
llvm_externals_find(TEST_SUITE_LAPACK_ROOT "lapack" "LAPACK")

if(NOT TEST_SUITE_LAPACK_ROOT AND NOT TEST_SUITE_ENABLE_LAPACK)
  return()
endif()

if(NOT TEST_SUITE_FORTRAN)
  message(FATAL_ERROR
    "LAPACK requires Fortran support. Configure with TEST_SUITE_FORTRAN=ON.")
endif()

find_package(Python3 REQUIRED COMPONENTS Interpreter)

set(LAPACK_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/lapack-build")

if(CMAKE_Fortran_FLAGS MATCHES "-ffp-contract=fast")
  message(WARNING "LAPACK tests require -ffp-contract=off for numerical accuracy."
                  " -ffp-contract=fast being overriden for LAPACK build.")
endif()

set(LAPACK_CMAKE_ARGS
  "-DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}"
  "-DCMAKE_C_COMPILER:FILEPATH=${CMAKE_C_COMPILER}"
  "-DCMAKE_Fortran_COMPILER:FILEPATH=${CMAKE_Fortran_COMPILER}"
  "-DCMAKE_C_FLAGS:STRING=${CMAKE_C_FLAGS}"
  "-DCMAKE_Fortran_FLAGS:STRING=${CMAKE_Fortran_FLAGS} -ffp-contract=off"
  "-DCMAKE_EXE_LINKER_FLAGS:STRING=${CMAKE_EXE_LINKER_FLAGS}"
  "-DBUILD_TESTING:BOOL=ON"
  "-DLAPACKE:BOOL=ON"
  "-DPython3_EXECUTABLE:FILEPATH=${Python3_EXECUTABLE}")

if(TEST_SUITE_LAPACK_ROOT)
  set(LAPACK_SOURCE_ARGS
    SOURCE_DIR "${TEST_SUITE_LAPACK_ROOT}"
    DOWNLOAD_COMMAND ""
    UPDATE_COMMAND "")
else()
  # We need a newer LAPACK than the latest release for full flang support.
  # This can be changed to a fixed release when LAPACK next does one.
  set(LAPACK_SOURCE_ARGS
    GIT_REPOSITORY "https://github.com/Reference-LAPACK/lapack"
    GIT_TAG "51b349470b3b26c948d068deb45c9b120a47ed32"
    SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/lapack-src")
endif()

ExternalProject_Add(LAPACK
  ${LAPACK_SOURCE_ARGS}
  BINARY_DIR "${LAPACK_BINARY_DIR}"
  CMAKE_ARGS ${LAPACK_CMAKE_ARGS}
  INSTALL_COMMAND ""
  TEST_COMMAND "")

# The normal top-level check target must finish the external build before LIT
# executes lapack.test. Testing itself deliberately remains outside the
# ExternalProject stamp machinery so every check invocation reruns it.
set_property(GLOBAL APPEND PROPERTY TEST_SUITE_TARGETS
  LAPACK build-litsupport build-timeit-target)

# Run LAPACK tests with the same level of parallelism as lit
if(DEFINED LIT_MAX_WORKERS)
  set(LAPACK_CTEST_PARALLEL_LEVEL ${LIT_MAX_WORKERS})
else()
  set(LAPACK_CTEST_PARALLEL_LEVEL 0)
endif()

configure_file(lapack.py.in lapack.test @ONLY)
configure_file(lit.local.cfg.in lit.local.cfg @ONLY)

add_custom_target(build-lapack DEPENDS LAPACK)
add_custom_target(check-lapack
  COMMAND ${TEST_SUITE_LIT} ${TEST_SUITE_LIT_FLAGS} lapack.test
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  DEPENDS LAPACK build-litsupport build-timeit-target
  USES_TERMINAL)
