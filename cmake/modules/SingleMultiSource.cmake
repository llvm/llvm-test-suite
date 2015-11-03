##===- SingleMultiSource.cmake --------------------------------------------===##
#
# Defines helpers to add executables and tests. The entry points to this
# file are:
#   `llvm_singlesource()` and
#   `llvm_multisource()`
#
# Each is a macro that uses the environment it was called in to determine
# what to build and how, and generates a test file that can be given to LIT.
# The test file is generated at configure time.
#
##===----------------------------------------------------------------------===##

# get_unique_exe_name - Given a source file name after which a test should be
# named, create a unique name for the test. Usually this is just the source file
# with the suffix stripped, but in some cases this ends up causing duplicates
# so attempt to make each unique (by adding pathname segments until they become
# unique).
#
# FIXME: Swap this with a simpler procedure to just append a numeral
set_property(GLOBAL PROPERTY registered_executables)
function(get_unique_exe_name new_name main_src)
  get_property(registered_executables GLOBAL PROPERTY registered_executables)

  string(REGEX REPLACE ".[cp]+$" "" path ${main_src})
  string(REGEX REPLACE ".*/" "" name ${path})
  list(FIND registered_executables ${name} name_idx)

  if(${name_idx} EQUAL -1)
    set(${new_name} ${name} PARENT_SCOPE)
    set_property(GLOBAL APPEND PROPERTY registered_executables ${name})
    return()
  endif()

  # There is a clash. Rename the target. Each time around the loop pull in
  # a new path component.
  foreach(n RANGE 1 4)
    string(REGEX REPLACE ".*/([^/]+/${name})" "\\1" name ${path})
    string(REGEX REPLACE "/" "-" safe_name ${name})

    list(FIND registered_executables ${safe_name} name_idx)
    if(${name_idx} EQUAL -1)
      set(${new_name} ${safe_name} PARENT_SCOPE)
      set_property(GLOBAL APPEND PROPERTY registered_executables ${safe_name})
      return()
    endif()
  endforeach()
  message(FATAL_ERROR "Failed to uniquify executable name!")
endfunction()

# append_cflags - add flags to the CFLAGS for target.
macro(append_cflags target flags)
  if(NOT "${${flags}}" STREQUAL "")
    get_target_property(old_cflags ${target} COMPILE_FLAGS)
    if(${old_cflags} STREQUAL "old_cflags-NOTFOUND")
      set(old_cflags)
    endif()
    string(REPLACE ";" " " s "${old_cflags};${${flags}}")
    set_target_properties(${target} PROPERTIES COMPILE_FLAGS ${s})
  endif()
endmacro()

# append_ldflags - add flags to the LDFLAGS for target.
macro(append_ldflags target flags)
  if(NOT "${${flags}}" STREQUAL "")
    get_target_property(old_ldflags ${target} LINK_FLAGS)
    if(${old_ldflags} STREQUAL "old_ldflags-NOTFOUND")
      set(old_ldflags)
    endif()
    string(REPLACE ";" " " s "${old_ldflags};${${flags}}")
    set_target_properties(${target} PROPERTIES LINK_FLAGS ${s})
  endif()
endmacro()

# llvm_add_test - Create a .test driver file suitable for LIT.
#
# The test template lives in cmake/lit-test-template.in and is configured by this function.
function(llvm_add_test name exename)
  set(VERIFYSCRIPT "")

  # Hash if we've been asked to, otherwise just use "touch" as an identity function.
  if(HASH_PROGRAM_OUTPUT)
	set(VERIFYSCRIPT "${VERIFYSCRIPT}\nVERIFY: ${CMAKE_SOURCE_DIR}/HashProgramOutput.sh %o")
  endif()

  # Find the reference output file key name.
  if(SMALL_PROBLEM_SIZE)
    set(KEY small)
  elseif(LARGE_PROBLEM_SIZE)
    set(KEY large)
  else()
    set(KEY)
  endif()

  # If the program is nondeterministic, don't bother diffing and use "touch" again as an identity.
  if(NOT DEFINED PROGRAM_IS_NONDETERMINISTIC)
    # Pick the best reference output based on "programname.reference_output".
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${ENDIAN}-endian.${KEY})
      set(REFERENCE_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${ENDIAN}-endian.${KEY})
    elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${KEY})
      set(REFERENCE_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${KEY})
    elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${ENDIAN}-endian)
      set(REFERENCE_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${ENDIAN}-endian)
    elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output)
      set(REFERENCE_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output)
    else()
      # Just compare to its own output. This will always succeed, but here's hoping the
      # test in question uses its exit value to determine status, so it'll be caught by
      # the previous RUN line.
      set(REFERENCE_OUTPUT "%o")
      message("-- No reference output found for test ${name}")
    endif()

    set(DIFFPROG ${CMAKE_BINARY_DIR}/tools/fpcmp)
    if(DEFINED FP_TOLERANCE)
      set(DIFFPROG "${DIFFPROG} -r ${FP_TOLERANCE}")
    endif()
    if(DEFINED FP_ABSTOLERANCE)
      set(DIFFPROG "${DIFFPROG} -a ${FP_ABSTOLERANCE}")
    endif()
	set(VERIFYSCRIPT "${VERIFYSCRIPT}\nVERIFY: ${DIFFPROG} %o ${REFERENCE_OUTPUT}")
  endif()

  set(RUNSCRIPT "RUN: ${CMAKE_CURRENT_BINARY_DIR}/${exename}")
  if(DEFINED RUN_OPTIONS)
    # RUN_OPTIONS is a semicolon-separated list. Change it into a whitespace-separated string.
    string(REPLACE ";" " " RUN_OPTIONS "${RUN_OPTIONS}")
	set(RUNSCRIPT "${RUNSCRIPT} ${RUN_OPTIONS}")
  endif()

  if(DEFINED STDIN_FILENAME)
	set(RUNSCRIPT "${RUNSCRIPT} < ${STDIN_FILENAME}")
  endif()

  # Produce .test file
  file(GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${exename}.test
    CONTENT "${RUNSCRIPT}${VERIFYSCRIPT}\n")
endfunction()

# llvm_singlesource - configure the current directory as a SingleSource subdirectory -
# i.e. every file in *.{c,cpp,cc} is treated as its own test.
macro(llvm_singlesource)
  file(GLOB sources *.c *.cpp *.cc)
  foreach(source ${sources})
    # Find the pure name of the test
    string(REGEX REPLACE ".[cp]+$" "" path ${source})
    string(REGEX REPLACE ".*/" "" name ${path})

    # Should we skip this?
    list(FIND PROGRAMS_TO_SKIP ${name} name_idx)
    if(${name_idx} EQUAL -1)
      get_unique_exe_name(source_exename ${source})
      add_executable(${source_exename} ${source})
      append_cflags(${source_exename} CFLAGS)
      append_cflags(${source_exename} CPPFLAGS)
      append_cflags(${source_exename} CXXFLAGS)
      append_ldflags(${source_exename} LDFLAGS)
      llvm_add_test(${name} ${source_exename})
      add_dependencies(${source_exename} timeit fpcmp)
    endif()
  endforeach()
endmacro()

# llvm_multisource - configure the current directory as a MultiSource subdirectory -
# i.e. there is one test and it consists of all sources in the directory (or a curated
# list, if Source is defined).
macro(llvm_multisource)
  if(DEFINED Source)
    set(sources ${Source})
  else()
    file(GLOB sources *.c *.cpp *.cc)
  endif()
  list(LENGTH sources sources_len)

  if(sources_len GREATER 0 AND DEFINED PROG)
  # Should we skip this?
  list(FIND PROGRAMS_TO_SKIP ${PROG} name_idx)
  if(${name_idx} EQUAL -1)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR})
    include_directories(${CMAKE_CURRENT_BINARY_DIR})
    get_unique_exe_name(source_exename "${PROG}.c")
    add_executable(${source_exename} ${sources})
    append_cflags(${source_exename} CFLAGS)
    append_cflags(${source_exename} CPPFLAGS)
    append_cflags(${source_exename} CXXFLAGS)
    append_ldflags(${source_exename} LDFLAGS)
    llvm_add_test(${PROG} ${source_exename})
    add_dependencies(${source_exename} timeit fpcmp)
  endif()
endif()
endmacro()
