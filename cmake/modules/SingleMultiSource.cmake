##===- SingleMultiSource.cmake --------------------------------------------===##
#
# This defines functions to be used by the SingleSource and MultiSource
# directories. This style of defining benchmarks is considered obsolete now
# and it is recommended to only use the functions in TestSuite.cmake and
# TestFile.cmake instead.
#
# Defines helpers to add executables and tests. The entry points to this
# file are:
#   `llvm_singlesource([PREFIX p])`, and
#   `llvm_multisource()`
#
# Following convenience functions provide shortcuts for common test cases:
#
# llvm_singlesource([PREFIX p])
#
#   Invokes llvm_test_executable() for each c/c++ source file.  If
#   'sources is emptyno sources are specified, creates test executables
#   for all C/C++ files in current directory.
#   Passes optional PREFIX parameter to llvm_test_executable().
#
# llvm_multisource(target)
#   Invokes llvm_test_executable(${target} [sources...])
#
##===----------------------------------------------------------------------===##

include(TestSuite)

# Configure the current directory as a SingleSource subdirectory - i.e. every
# file in *.{c,cpp,cc} is treated as its own test.
function(llvm_singlesource)
  cmake_parse_arguments(_LSARG "" "PREFIX" "" ${ARGN})
  if(DEFINED Source)
    set(sources ${Source})
  else()
    file(GLOB sources *.c *.cpp *.cc)
  endif()
  foreach(source ${sources})
    basename(name ${source})
    set(_target ${_LSARG_PREFIX}${name})
    llvm_test_executable_no_test(${_target} ${source})
    set_property(TARGET ${_target} PROPERTY TEST_NAME ${name})
    llvm_test_traditional(${_target})
    llvm_add_test_for_target(${_target})
  endforeach()
endfunction()

# Configure the current directory as a MultiSource subdirectory - i.e. there is
# one test and it consists of all sources in the directory (or a curated list,
# if Source is defined).
function(llvm_multisource target)
  set(sources ${ARGN})
  if(NOT sources)
    file(GLOB sources *.c *.cpp *.cc)
  endif()

  llvm_test_executable_no_test(${target} ${sources})
  llvm_test_traditional(${target})
  llvm_add_test_for_target(${target})
endfunction()

macro(llvm_test_verify_hash_program_output _file)
  llvm_test_verify(WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_BINARY_DIR}/tools/HashProgramOutput.sh ${_file}
  )
endmacro()

# Sets Var to ${name} with directory and shortest extension removed.
macro(basename Var name)
  # strip directory name
  get_filename_component(_filename ${name} NAME)
  # remove shortest extension.
  string(REGEX REPLACE "\\.[^.]*$" "" ${Var} ${_filename})
endmacro()

# Traditionally CMakeLists.txt files would set RUN_OPTIONS, SMALL_PROBLEM_SIZE,
# HASH_PROGRAM_OUTPUT, etc.
# Create llvm_test_run() and llvm_test_verify() invocation for that.
function(llvm_test_traditional target)
  get_property(name TARGET ${target} PROPERTY TEST_NAME)
  if(NOT name)
    set(name ${target})
  endif()

  # Always run in the same directory as the executable
  list(INSERT RUN_OPTIONS 0 WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
  llvm_test_run(${RUN_OPTIONS})

  # Hash if we've been asked to.
  if(HASH_PROGRAM_OUTPUT)
    llvm_test_verify_hash_program_output(%o)
  endif()

  # Find the reference output file key name.
  if(NOT NO_REFERENCE_OUTPUT)
    if(SMALL_PROBLEM_SIZE)
      set(SIZE_SUFFIX small)
    elseif(LARGE_PROBLEM_SIZE)
      set(SIZE_SUFFIX large)
    else()
      set(SIZE_SUFFIX)
    endif()

    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${ENDIAN}-endian.${SIZE_SUFFIX})
      set(REFERENCE_OUTPUT ${name}.reference_output.${ENDIAN}-endian.${SIZE_SUFFIX})
    elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${SIZE_SUFFIX})
      set(REFERENCE_OUTPUT ${name}.reference_output.${SIZE_SUFFIX})
    elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${ENDIAN}-endian)
      set(REFERENCE_OUTPUT ${name}.reference_output.${ENDIAN}-endian)
    elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output)
      set(REFERENCE_OUTPUT ${name}.reference_output)
    else()
      message("-- No reference output found for test ${name}")
    endif()
  endif()

  if(REFERENCE_OUTPUT)
    set(DIFFPROG ${FPCMP})
    if(FP_TOLERANCE)
      set(DIFFPROG "${DIFFPROG} -r ${FP_TOLERANCE}")
    endif()
    if(FP_ABSTOLERANCE)
      set(DIFFPROG "${DIFFPROG} -a ${FP_ABSTOLERANCE}")
    endif()
    llvm_test_verify(WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
      ${DIFFPROG} %o ${REFERENCE_OUTPUT}
    )
    llvm_test_data(${target} ${REFERENCE_OUTPUT})
  endif()
  set(TESTSCRIPT "${TESTSCRIPT}" PARENT_SCOPE)
endfunction()
