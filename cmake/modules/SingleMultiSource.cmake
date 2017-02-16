##===- SingleMultiSource.cmake --------------------------------------------===##
#
# This defines macros to be used by the SingleSource and MultiSource
# directories. This style of defining benchmarks is considered obsolete now
# and it is recommended to only use the macros in TestSuite.cmake and
# TestFile.cmake instead.
#
# Defines helpers to add executables and tests. The entry points to this
# file are:
#   `llvm_singlesource([PREFIX p] [TARGET_VAR VarName])`, and
#   `llvm_multisource([PREFIX p] [TARGET_VAR VarName])`
#
# Following convenience macros provide shortcuts for common test cases:
#
# llvm_singlesource([PREFIX p] [TARGET_VAR VarName])
#
#   Invokes llvm_test_executable() for each c/c++ source file.  If
#   'sources is emptyno sources are specified, creates test executables
#   for all C/C++ files in current directory.
#   Passes optional PREFIX parameter to llvm_test_executable().
#   If optional TARGET_VAR is specified, the variable is set to
#   list of all created targets.
#
# llvm_multisource([PREFIX p] [TARGET_VAR VarName])
#   Invokes llvm_test_executable(${PROG} [sources...])
#
##===----------------------------------------------------------------------===##

include(TestSuite)

# Configure the current directory as a SingleSource subdirectory - i.e. every
# file in *.{c,cpp,cc} is treated as its own test.
macro(llvm_singlesource)
  cmake_parse_arguments(_LSARG "" "PREFIX;TARGET_VAR" "" ${ARGN})
  if(DEFINED Source)
    set(sources ${Source})
  else()
    file(GLOB sources *.c *.cpp *.cc)
  endif()
  foreach(source ${sources})
    basename(name ${source})
    if(NOT TESTSCRIPT)
      llvm_test_traditional(${name})
    endif()
    set(_target ${_LSARG_PREFIX}${name})
    llvm_test_executable(${_target} ${source})
    if(_LSARG_TARGET_VAR)
      list(APPEND ${_LSARG_TARGET_VAR} ${_target}})
    endif()
  endforeach()
endmacro()

# Configure the current directory as a MultiSource subdirectory - i.e. there is
# one test and it consists of all sources in the directory (or a curated list,
# if Source is defined).
macro(llvm_multisource)
  cmake_parse_arguments(_LMARG "" "PREFIX;TARGET_VAR" "" ${ARGN})
  if(DEFINED Source)
    set(sources ${Source})
  else()
    file(GLOB sources *.c *.cpp *.cc)
  endif()
  list(LENGTH sources sources_len)

  if(sources_len GREATER 0 AND PROG)
    if(NOT TESTSCRIPT)
      llvm_test_traditional(${PROG})
    endif()
    set(_target ${_LMARG_PREFIX}${PROG})
    llvm_test_executable(${_target} ${sources})
    target_include_directories(${_target}
      PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
    if(_LMARG_TARGET_VAR)
      set(${_LMARG_TARGET_VAR} ${_target})
    endif()
  endif()
endmacro()

# Sets Var to ${name} with directory and shortest extension removed.
macro(basename Var name)
  # strip directory name
  get_filename_component(_filename ${name} NAME)
  # remove shortest extension.
  string(REGEX REPLACE "\\.[^.]*$" "" ${Var} ${_filename})
endmacro()

# Traditionally CMakeLists.txt files would set RUN_OPTIONS, STDIN_FILENAME,
# SMALL_PROBLEM_SIZE, HASH_PROGRAM_OUTPUT, etc.
# Create llvm_test_run() and llvm_test_verify() invocation for that.
function(llvm_test_traditional name)
  if(STDIN_FILENAME)
    list(APPEND RUN_OPTIONS "< ${STDIN_FILENAME}")
  endif()
  if(WORKDIR)
    list(APPEND RUN_OPTIONS WORKDIR ${WORKDIR})
  endif()
  llvm_test_run(${RUN_OPTIONS})

  # Hash if we've been asked to.
  if(HASH_PROGRAM_OUTPUT)
    llvm_test_verify("${CMAKE_SOURCE_DIR}/HashProgramOutput.sh %o")
  endif()

  if(NOT PROGRAM_IS_NONDETERMINISTIC)
    # Find the reference output file key name.
    if(SMALL_PROBLEM_SIZE)
      set(KEY small)
    elseif(LARGE_PROBLEM_SIZE)
      set(KEY large)
    else()
      set(KEY)
    endif()

    # Pick the best reference output based on "programname.reference_output".
    if(NOT NO_REFERENCE_OUTPUT)
      if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${ENDIAN}-endian.${KEY})
        set(REFERENCE_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${ENDIAN}-endian.${KEY})
      elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${KEY})
        set(REFERENCE_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${KEY})
      elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${ENDIAN}-endian)
        set(REFERENCE_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${ENDIAN}-endian)
      elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output)
        set(REFERENCE_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output)
      else()
        message("-- No reference output found for test ${name}")
      endif()
    endif()

    set(DIFFPROG ${CMAKE_BINARY_DIR}/tools/fpcmp)
    if(FP_TOLERANCE)
      set(DIFFPROG "${DIFFPROG} -r ${FP_TOLERANCE}")
    endif()
    if(FP_ABSTOLERANCE)
      set(DIFFPROG "${DIFFPROG} -a ${FP_ABSTOLERANCE}")
    endif()
    if(REFERENCE_OUTPUT)
      llvm_test_verify("${DIFFPROG} %o ${REFERENCE_OUTPUT}")
    endif()
  endif()
  set(TESTSCRIPT "${TESTSCRIPT}" PARENT_SCOPE)
endfunction()


