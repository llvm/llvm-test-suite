# SOLLVE OpenMP Offloading Validation & Verification Suite
# https://crpl.cis.udel.edu/ompvvsollve/

include(External)

option(TEST_SUITE_FORCE_ALL "Execute all SOLLVE V&V tests, even those known to be unsupported by Clang" OFF)

set(TEST_SUITE_OFFLOADING_C_FLAGS --offload-arch=native CACHE STRING "Compiler arguments for OpenMP offloading for C")
 set(TEST_SUITE_OFFLOADING_CXX_FLAGS --offload-arch=native CACHE STRING "Compiler arguments for OpenMP offloading for CXX")
set(TEST_SUITE_OFFLOADING_Fortran_FLAGS --offload-arch=native CACHE STRING "Compiler arguments for OpenMP offloading for Fortran")
set(TEST_SUITE_OFFLOADING_C_LDFLAGS --offload-arch=native CACHE STRING "Linker arguments for OpenMP offloading")
set(TEST_SUITE_OFFLOADING_CXX_LDFLAGS --offload-arch=native CACHE STRING "Linker arguments for OpenMP offloading")
set(TEST_SUITE_OFFLOADING_Fortran_LDFLAGS --offload-arch=native CACHE STRING "Linker arguments for OpenMP offloading")

set(ALL_LIST_OPTIONS
  AMD
  INTEL
  NVIDIA
  REGRESSION
)

set(CHOOSEN_LISTS)

set(REGRESSION)
set(INTEL)

include(sollvevv_nvidia_tests.cmake)
include(sollvevv_amd_tests.cmake)

function (add_sollvevv LANG)
  set(_includedir "${TEST_SUITE_SOLLVEVV_ROOT}/ompvv" )

  if ("${LANG}" STREQUAL "Fortran" AND NOT TEST_SUITE_FORTRAN)
    return ()
  endif ()

  if (NOT OpenMP_${LANG}_FOUND)
    message(FATAL_ERROR "OpenMP for ${LANG} not found")
    return ()
  endif ()

  #if (OpenMP_${LANG}_VERSION VERSION_LESS "4.5")
  #  message(FATAL_ERROR "OpenMP version ${OpenMP_${LANG}_VERSION} too old")
  #endif ()

  if ("${LANG}" STREQUAL "C")
    set(_langext ".c")
  elseif ("${LANG}" STREQUAL "CXX")
    set(_langext ".cpp")
  elseif ("${LANG}" STREQUAL "Fortran")
    set(_langext ".F90")
  else ()
    message(FATAL_ERROR "Unsupported languge ${LANG}")
  endif ()

  file(GLOB_RECURSE _tests_sources RELATIVE "${TEST_SUITE_SOLLVEVV_ROOT}/tests" "${TEST_SUITE_SOLLVEVV_ROOT}/tests/*${_langext}" )
  foreach (_file IN LISTS _tests_sources)
    get_filename_component(_ext "${_file}" EXT)
    get_filename_component(_basename "${_file}" NAME_WE)
    get_filename_component(_directory "${_file}" DIRECTORY)
    string(REPLACE "." "" _ext "${_ext}")
    string(REPLACE "/" "_" _directory "${_directory}")
    string(REPLACE "." "" _directory "${_directory}")
    set(_name "omptargetvv-${_basename}-${_directory}-${_ext}")

    if (NOT TEST_SUITE_FORCE_ALL AND NOT "${_file}" IN_LIST CHOOSEN_LISTS)
      message(STATUS "Skipping SOLLVE V&V test ${_file}")
      continue ()
    endif ()

    llvm_test_run()

    llvm_test_executable(${_name} "${TEST_SUITE_SOLLVEVV_ROOT}/tests/${_file}")
    target_include_directories(${_name} PRIVATE "${_includedir}")
    target_link_libraries(${_name} PUBLIC OpenMP::OpenMP_${_lang} m)

    # Add -fopenmp to linker command line; for some reason this is not done by target_link_libraries.
    target_link_options(${_name} PRIVATE ${OpenMP_${LANG}_FLAGS})

    # CMake's find_package(OpenMP) currently does not not introspect flags necessary for offloading.
    target_compile_options(${_name} PUBLIC ${TEST_SUITE_OFFLOADING_${LANG}_FLAGS})

    target_link_options(${_name} PUBLIC ${TEST_SUITE_OFFLOADING_${LANG}_LDFLAGS})
  endforeach ()
endfunction ()


llvm_externals_find(TEST_SUITE_SOLLVEVV_ROOT "sollve_vv" "OpenMP Offloading Validation & Verification Suite")

if(TEST_SUITE_SOLLVEVV_ROOT AND NOT TEST_SUITE_BENCHMARKING_ONLY)
  if(OpenMP_FOUND)
    message(STATUS "Adding OpenMP Offloading Validiation & Verification")
  else()
    message(STATUS "NOT using OpenMP Validiation & Verification because OpenMP was not found")
    return()
  endif()

  list(REMOVE_DUPLICATES SYSTEM_GPU)
  foreach(list_option ${SYSTEM_GPU})
    string(TOUPPER ${list_option} list_option)
    if(list_option IN_LIST ALL_LIST_OPTIONS)
      if(list_option STREQUAL "AMD")
        list(APPEND CHOOSEN_LISTS ${AMD})
        message(STATUS "adding AMD")
      endif()
      if(list_option STREQUAL "NVIDIA")
        list(APPEND CHOOSEN_LISTS ${NVIDIA})
        message(STATUS "adding NVIDIA")
      endif()
      if(list_option STREQUAL "INTEL")
        list(APPEND CHOOSEN_LISTS ${INTEL})
        message(STATUS "adding INTEL")
      endif()
      if(list_option STREQUAL "REGRESSION")
        list(APPEND CHOOSEN_LISTS ${REGRESSION})
        message(STATUS "adding REGRESSION")
      endif()
    else()
      message(STATUS "Option is unrecognized (${list_option})")
    endif()
  endforeach()
  list(REMOVE_DUPLICATES CHOOSEN_LISTS)

  foreach (_lang in C CXX Fortran)
    if(CMAKE_${_lang}_COMPILER)
      add_sollvevv(${_lang})
    endif()
  endforeach ()
endif ()
