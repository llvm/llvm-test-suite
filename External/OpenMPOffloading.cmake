# Introspection of OpenMP offloading support
# TODO: Could become a find_package module

if (NOT OpenMP_FOUND)
  message(STATUS "OpenMP Offloading not available because OpenMP is not available")
  return ()
endif ()


set(TEST_SUITE_SYSTEM_GPU "auto" CACHE STRING "Select only tests that Clang/Flang is expected to work with for the selected GPU (auto, native, amd, nvidia, or all)")
set_property(CACHE TEST_SUITE_SYSTEM_GPU PROPERTY STRINGS "amd" "nvidia" "all" "native" "auto")

# TODO: Run only once if included multiple times
set(TEST_SUITE_EFFECTIVE_SYSTEM_GPU "${TEST_SUITE_SYSTEM_GPU}")
if (TEST_SUITE_EFFECTIVE_SYSTEM_GPU STREQUAL "auto")
  # Test sets only maintained for Flang/Clang
  if ((CMAKE_C_COMPILER_ID STREQUAL "Clang") OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR (CMAKE_Fortran_COMPILER_ID STREQUAL "LLVMFlang"))
    set (TEST_SUITE_EFFECTIVE_SYSTEM_GPU "native")
  else ()
    set (TEST_SUITE_EFFECTIVE_SYSTEM_GPU "all")
  endif ()
endif ()
if (TEST_SUITE_EFFECTIVE_SYSTEM_GPU STREQUAL "native")
  # For LLVM, nvptx-arch and amdgpu-arch are executables in the bin directory, next to clang/flang.
  set(_searchpaths)
  foreach (_compiler IN ITEMS ${CMAKE_C_COMPILER} ${CMAKE_CXX_COMPILER} ${CMAKE_Fortran_COMPILER})
    get_filename_component(_compiler_dir "${_compiler}" DIRECTORY)
    list(APPEND _searchpaths "${_compiler_dir}")
  endforeach ()

  find_program(NVPTX_ARCH_EXECUTABLE nvptx-arch HINTS ${_searchpaths})
  execute_process(COMMAND "${NVPTX_ARCH_EXECUTABLE}" RESULT_VARIABLE _nvptx_arch_result OUTPUT_VARIABLE _nvptx_arch_output ERROR_VARIABLE _nvptx_arch_error)
  if (_nvptx_arch_result STREQUAL "0" AND _nvptx_arch_output)
    # Which Nvidia GPU is detected currently does not matter
    set(TEST_SUITE_EFFECTIVE_SYSTEM_GPU "nvidia")
  endif ()

  find_program(AMDGPU_ARCH_EXECUTABLE amdgpu-arch HINTS ${_searchpaths})
  execute_process(COMMAND "${AMDGPU_ARCH_EXECUTABLE}" RESULT_VARIABLE _amdgpu_arch_result OUTPUT_VARIABLE _amdgpu_arch_output ERROR_VARIABLE _amdgpu_arch_error)
  if (_amdgpu_arch_result STREQUAL "0" AND _amdgpu_arch_output)
    # Which AMD GPU is detected currently does not matter
    set(TEST_SUITE_EFFECTIVE_SYSTEM_GPU "amd")
  endif ()

  if (TEST_SUITE_EFFECTIVE_SYSTEM_GPU STREQUAL "native")
    if (TEST_SUITE_SYSTEM_GPU STREQUAL "auto")
      # If no preselected list is available, run all tests
      set(TEST_SUITE_EFFECTIVE_SYSTEM_GPU "all")
    else ()
      message(STATUS "OpenMP Offloading not available because no native GPU detected")
      return()
    endif ()
  else ()
    message(STATUS "Native GPU is ${_effective_SYSTEM_GPU}")
  endif ()
endif ()


# Do not try to create OpenMP_Offloading multiple times.
if (TARGET OpenMP_Offloading)
  return ()
endif ()

add_library(OpenMP_Offloading INTERFACE IMPORTED)
foreach (_lang IN ITEMS C CXX Fortran)
  if (lang STREQUAL "Fortran" AND NOT TEST_SUITE_FORTRAN)
    continue ()
  endif ()
  set(TEST_SUITE_OFFLOADING_${_lang}_FLAGS   "--offload-arch=native" CACHE STRING "Compiler arguments for OpenMP offloading in ${_lang}")
  set(TEST_SUITE_OFFLOADING_${_lang}_LDFLAGS "--offload-arch=native" CACHE STRING "Linker arguments for OpenMP offloading in ${_lang}")
  if (TARGET OpenMP::OpenMP_${_lang})
    target_link_libraries(OpenMP_Offloading INTERFACE OpenMP::OpenMP_${_lang})
  endif ()
  separate_arguments(_flags NATIVE_COMMAND ${TEST_SUITE_OFFLOADING_${_lang}_FLAGS})
  separate_arguments(_ldflags NATIVE_COMMAND ${TEST_SUITE_OFFLOADING_${_lang}_LDFLAGS})
  target_compile_options(OpenMP_Offloading INTERFACE $<$<COMPILE_LANGUAGE:${_lang}>:${_flags}>)
  target_link_options(OpenMP_Offloading INTERFACE $<$<COMPILE_LANGUAGE:${_lang}>:${_ldflags}>)
endforeach ()
