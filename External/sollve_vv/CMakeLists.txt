# SOLLVE OpenMP Offloading Validation & Verification Suite
# https://crpl.cis.udel.edu/ompvvsollve/

include(External)

set(TEST_SUITE_SOLLVEVV_OFFLOADING_CFLAGS "-fopenmp-targets=nvptx64-nvidia-cuda;-Xopenmp-target;-march=sm_70" CACHE STRING "Compiler arguments for OpenMP offloading")
set(TEST_SUITE_SOLLVEVV_OFFLOADING_LDFLAGS "-fopenmp-targets=nvptx64-nvidia-cuda;-Xopenmp-target;-march=sm_70;-lomptarget" CACHE STRING "Linker arguments for OpenMP offloading")

function (add_sollvevv LANG)
  set(_includedir "${TEST_SUITE_SOLLVEVV_ROOT}/ompvv" )

  if (NOT OPENMP_${LANG}_FOUND)
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

    llvm_test_run()

    llvm_test_executable(${_name} "${TEST_SUITE_SOLLVEVV_ROOT}/tests/${_file}")
    target_include_directories(${_name} PRIVATE "${_includedir}")
    target_link_libraries(${_name} PUBLIC OpenMP::OpenMP_${_lang})

    # Add -fopenmp to linker command line; for some reason this is not done by target_link_libraries.
    target_link_options(${_name} PRIVATE ${OpenMP_${LANG}_FLAGS})

    # CMake's find_package(OpenMP) currently does not not introspect flags necessary for offloading.
    target_compile_options(${_name} PUBLIC ${TEST_SUITE_SOLLVEVV_OFFLOADING_CFLAGS})
    target_link_options(${_name} PUBLIC ${TEST_SUITE_SOLLVEVV_OFFLOADING_LDFLAGS})
  endforeach ()
endfunction ()


llvm_externals_find(TEST_SUITE_SOLLVEVV_ROOT "sollve_vv" "OpenMP Offloading Validation & Verification Suite")
if (TEST_SUITE_SOLLVEVV_ROOT AND NOT TEST_SUITE_BENCHMARKING_ONLY)
  if (OPENMP_FOUND)
    message(STATUS "Adding OpenMP Offloading Validiation & Verification")
  else ()
    message(STATUS "NOT using OpenMP Validiation & Verification because OpenMP was not found")
    return ()
  endif ()

  foreach (_lang in C CXX)
    if (CMAKE_${_lang}_COMPILER)
      add_sollvevv(${_lang})
    endif()
  endforeach ()
endif ()
