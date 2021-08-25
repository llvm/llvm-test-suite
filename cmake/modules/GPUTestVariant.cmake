include(External)
# This file provides common functions and macros to generate
# targets and executables for the tests in External/CUDA and
# External/HIP.

# Helper macro to extract version number at the end of the string
# Input: get_version(Var String)
#    Where String = /some/string/with/version-x.y.z
# Output:
#    Sets Var=x.y.z
macro(get_version Var Path)
    string(REGEX MATCH "[0-9]+(\\.[0-9]+)*$" ${Var} ${Path})
endmacro (get_version)

# Helper function to glob CUDA source files and set LANGUAGE property
# to CXX on each of them. Sets Var in parent scope to the list of
# files found.
macro(gpu_glob Var)
  file(GLOB FileList ${ARGN})
  foreach(File IN LISTS FileList)
    if(${File} MATCHES ".*\.cu$" OR ${File} MATCHES ".*\.hip$")
      set_source_files_properties(${File} PROPERTIES LANGUAGE CXX)
    endif()
  endforeach()
  set(${Var} ${FileList})
endmacro(gpu_glob)

macro(create_one_local_test_f Name FileGlob FilterRegex
                              VariantOffload VariantSuffix
                              VariantCPPFLAGS VariantLibs)
  if (${VariantSuffix} MATCHES ${FilterRegex})
    gpu_glob(_sources ${FileGlob})
    set(_executable ${Name}-${VariantSuffix})
    set(_executable_path ${CMAKE_CURRENT_BINARY_DIR}/${_executable})
    llvm_test_run()
    set(REFERENCE_OUTPUT)
    # Verify reference output if it exists.
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${Name}.reference_output)
      set(REFERENCE_OUTPUT ${Name}.reference_output)
      llvm_test_verify(WORKDIR %S
        %b/${FPCMP} %o ${REFERENCE_OUTPUT}-${VariantSuffix}
      )
      llvm_test_executable(${_executable} ${_sources})
      llvm_test_data(${_executable}
                     DEST_SUFFIX "-${VariantSuffix}"
                     ${REFERENCE_OUTPUT})
    else()
      llvm_test_executable(${_executable} ${_sources})
    endif()
    target_compile_options(${_executable} PUBLIC ${VariantCPPFLAGS})
    if(VariantLibs)
      target_link_libraries(${_executable} ${VariantLibs})
    endif()
    if (${VariantOffload} MATCHES "hip")
      add_dependencies(hip-tests-simple-${VariantSuffix} ${_executable})
    else()
      add_dependencies(cuda-tests-simple-${VariantSuffix} ${_executable})
    endif()
    # Local tests are presumed to be fast.
    list(APPEND VARIANT_SIMPLE_TEST_TARGETS ${_executable}.test)
  endif()
endmacro()

# Helper macro to create a local test for a VariantSuffix.
# Inputs: Name, File, Offload, Suffix, CPPFLAGS, Libs
# Output: Dependencies added for <cuda||hip>-tests-simple-<suffix>,
#         and VARIANT_SIMPLE_TEST_TARGETS created.
macro(create_one_local_test Name FileGlob
                            VariantOffload VariantSuffix
                            VariantCPPFLAGS VariantLibs)
  create_one_local_test_f(${Name} ${FileGlob} ".*"
                          ${VariantOffload} ${VariantSuffix}
                          "${VariantCPPFLAGS}" "${VariantLibs}")
endmacro()

