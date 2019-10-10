# The following cause errors if they are passed to clang via CFLAGS
set(CLANG_ERRORING_CFLAGS
  "-fno-early-inlining"
  "-fno-ira-share-spill-slots"
  "-ftree-loop-distribution"
  "-fno-tree-bit-ccp"
  "-fno-tree-coalesce-vars"
)

# This pulls out options in dg-options into `${Variable}`
function(gcc_torture_dg_options_cflags Variable File)
  # Some files have dg-options which we need to pick up. These should be in
  # the first line but often aren't.
  #
  # We also need to be careful not to pick up target-specific dg-options.
  set(DG_CFLAGS)

  file(STRINGS ${File} FileLines)
  foreach(FileLine ${FileLines})
    # Looking for `dg-options "..."` or `dg-additional-options "..."` without
    # `{ target` afterwards (ignoring spaces).
    if(FileLine MATCHES "dg-(additional-)?options ({ )?\"([^\"]*)\"( })?(.*)")
      # This is needed to turn the string into a list of CFLAGS
      separate_arguments(FILE_CFLAGS UNIX_COMMAND ${CMAKE_MATCH_3})
      # This does the negative lookahead for `{ target` anywhere in the rest of
      # the line
      if(NOT ${CMAKE_MATCH_5} MATCHES "{ +target")
        list(APPEND DG_CFLAGS ${FILE_CFLAGS})
      endif()
    endif()
  endforeach()

  # Remove any flags that will make clang error
  if (DG_CFLAGS)
    list(REMOVE_ITEM DG_CFLAGS ${CLANG_ERRORING_CFLAGS})
  endif()

  # Set the parent scope variable
  set(${Variable} ${DG_CFLAGS} PARENT_SCOPE)
endfunction()

function(gcc_torture_execute_test File)
  cmake_parse_arguments(_TORTURE "" "PREFIX" "CFLAGS;LDFLAGS" ${ARGN})
  # There are a few tests with duplicate filenames, and CMake wants all target
  # names to be unique, so we add a disambiguator to the target name. The
  # disambiguator is based upon the directory structure, swapping `/` for `-`.
  get_filename_component(Name ${File} NAME_WE)
  set(_target "${_TORTURE_PREFIX}-${Name}")

  gcc_torture_dg_options_cflags(DG_CFLAGS ${File})

  # Add any flags that were requested
  list(APPEND CFLAGS ${DG_CFLAGS} ${_TORTURE_CFLAGS})
  list(APPEND LDFLAGS ${_TORTURE_LDFLAGS})

  llvm_test_executable_no_test(${_target} ${File})
  llvm_test_run()

  llvm_add_test_for_target(${_target})
endfunction()

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

add_subdirectory(execute)