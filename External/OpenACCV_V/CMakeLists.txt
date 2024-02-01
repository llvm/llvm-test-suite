# OpenACCV&V Validation & Verification Suite
# https://github.com/OpenACCUserGroup/OpenACCV-V

include(External)

option(TEST_SUITE_FORCE_ALL "Execute all OpenACC V&V tests, even those known to be unsupported by Clang" OFF)

set(TEST_SUITE_OFFLOADING_FLAGS --offload-arch=native CACHE STRING "Compiler arguments for offloading")
set(TEST_SUITE_OFFLOADING_LDFLAGS --offload-arch=native CACHE STRING "Linker arguments for offloading")

function (add_OpenACC_vv LANG)
  if ("${LANG}" STREQUAL "C")
    set(_langext ".c")
  elseif ("${LANG}" STREQUAL "CXX")
    set(_langext ".cpp")
  elseif ("${LANG}" STREQUAL "Fortran")
    set(_langext ".F90")
  else ()
    message(FATAL_ERROR "Unsupported languge ${LANG}")
  endif ()

  file(GLOB_RECURSE _tests_sources RELATIVE "${TEST_SUITE_OPENACCVV_ROOT}/Tests" "${TEST_SUITE_OPENACCVV_ROOT}/Tests/*${_langext}" )
  foreach (_file IN LISTS _tests_sources)
    get_filename_component(_ext "${_file}" EXT)
    get_filename_component(_basename "${_file}" NAME_WE)
    get_filename_component(_directory "${_file}" DIRECTORY)
    string(REPLACE "." "" _ext "${_ext}")
    set(_name "acctargetvv-${_basename}.${_ext}")

    llvm_test_run()

    llvm_test_executable(${_name} "${TEST_SUITE_OPENACCVV_ROOT}/Tests/${_file}")
    
    # Add -fopenmp to linker command line; only done with target_link_options.
    target_link_options(${_name} PRIVATE ${OpenACC_${LANG}_FLAGS})

    # CMake's find_package(OpenACC) currently does not not introspect flags necessary for offloading.
    target_compile_options(${_name} PUBLIC ${TEST_SUITE_OFFLOADING_FLAGS})
    target_link_options(${_name} PUBLIC ${TEST_SUITE_OFFLOADING_LDFLAGS})
  endforeach ()
endfunction ()

llvm_externals_find(TEST_SUITE_OPENACCVV_ROOT "OpenACCV_V" "OpenACC Offloading Validation & Verification Suite")

if(TEST_SUITE_OPENACCVV_ROOT AND NOT TEST_SUITE_BENCHMARKING_ONLY)
  if(${CMAKE_VERSION} VERSION_LESS 3.25)
    message(STATUS "The cmake version must be at least 3.25 to perform OpenACC tests")
  endif()

  foreach (_lang in C CXX Fortran)
    if(CMAKE_${_lang}_COMPILER)
      add_OpenACC_vv(${_lang})
    endif()
  endforeach ()
endif ()
