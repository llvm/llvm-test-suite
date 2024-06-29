# SOLLVE OpenMP Offloading Validation & Verification Suite
# https://crpl.cis.udel.edu/ompvvsollve/

if (TEST_SUITE_BENCHMARKING_ONLY)
  message(STATUS "Skipping OpenMP Validiation & Verification because benchmarking-only mode")
  return ()
endif ()

include(External)
llvm_externals_find(TEST_SUITE_SOLLVEVV_ROOT "sollve_vv" "OpenMP Offloading Validation & Verification Suite")
if (NOT TEST_SUITE_SOLLVEVV_ROOT)
  message(STATUS "Skipping OpenMP Validiation & Verification because external sources not specified")
  return ()
endif ()

include(../OpenMPOffloading.cmake)
if (NOT TARGET OpenMP_Offloading)
  message(STATUS "Skipping OpenMP Validiation & Verification because OpenMP Offloading not available")
  return ()
endif ()

message(STATUS "Adding OpenMP Offloading Validiation & Verification tests")
if (TEST_SUITE_EFFECTIVE_SYSTEM_GPU STREQUAL "all")
  file(GLOB_RECURSE _tests_sources RELATIVE "${TEST_SUITE_SOLLVEVV_ROOT}/tests"
      "${TEST_SUITE_SOLLVEVV_ROOT}/tests/*.c"
      "${TEST_SUITE_SOLLVEVV_ROOT}/tests/*.cpp"
      "${TEST_SUITE_SOLLVEVV_ROOT}/tests/*.F90"
    )
  set(TEST_SUITE_SOLLVEVV_TESTS ${_tests_sources})
  message(STATUS "Using all SOLLVE V&V tests")
else ()
  include(sollvevv_${TEST_SUITE_EFFECTIVE_SYSTEM_GPU}_tests.cmake)
endif ()


function (add_sollvevv lang)
  set(_includedir "${TEST_SUITE_SOLLVEVV_ROOT}/ompvv" )

  if (lang STREQUAL "Fortran" AND NOT TEST_SUITE_FORTRAN)
    message(STATUS "Skipping SOLLVE V&V Fortran tests in because Fortran tests are disabled")
    return ()
  endif ()

  if (NOT OpenMP_${lang}_FOUND)
    message(STATUS "Skipping SOLLVE V&V ${lang} tests in because no OpenMP for ${lang} found")
    return ()
  endif ()

  if (lang STREQUAL "C")
    set(_langext ".c")
  elseif (lang STREQUAL "CXX")
    set(_langext ".cpp")
  elseif (lang STREQUAL "Fortran")
    set(_langext ".F90")
  else ()
    return ()
  endif ()

  foreach (_file IN LISTS TEST_SUITE_SOLLVEVV_TESTS)
    get_filename_component(_ext "${_file}" EXT)
    get_filename_component(_basename "${_file}" NAME_WE)
    get_filename_component(_directory "${_file}" DIRECTORY)

    if (NOT (_ext STREQUAL _langext))
      continue ()
    endif ()

    string(REPLACE "." "" _ext "${_ext}")
    string(REPLACE "/" "_" _directory "${_directory}")
    string(REPLACE "." "" _directory "${_directory}")
    set(_name "omptargetvv-${_basename}-${_directory}-${_ext}")

    # Create a directory for the test
    set(_module_dir "${CMAKE_CURRENT_BINARY_DIR}/modules/${_name}")
    file(MAKE_DIRECTORY ${_module_dir})

    llvm_test_run()

    llvm_test_executable(${_name} "${TEST_SUITE_SOLLVEVV_ROOT}/tests/${_file}")
    target_include_directories(${_name} PRIVATE "${_includedir}")
    target_link_libraries(${_name} PUBLIC OpenMP_Offloading m)
    set_target_properties(${_name} PROPERTIES Fortran_MODULE_DIRECTORY ${_module_dir})
  endforeach ()
endfunction ()

get_property(_enabled_languages GLOBAL PROPERTY ENABLED_LANGUAGES)
foreach (_lang IN LISTS _enabled_languages)
  add_sollvevv(${_lang})
endforeach ()
