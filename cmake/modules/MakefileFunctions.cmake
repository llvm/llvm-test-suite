##===- MakefileFunctions.cmake --------------------------------------------===##
#
# Defines functions used within subdirectory CMakeLists.txt, that look a bit
# like standard GNU Make functions. These support the auto-generation of
# CMakeLists.txt from Makefiles, although any use of these should probably be
# looked at and manually translated into more idiomatic CMake.
#
##===----------------------------------------------------------------------===##

# wrapper around add_subdirectory that can take multiple items.
macro(llvm_add_subdirectories)
  foreach(V ${ARGV})
    add_subdirectory(${V})
  endforeach(V)
endmacro()

# equivalent to $(addprefix var,prefix). Modifies var in place.
function(llvm_prepend var prefix)
  set(listVar "")
  foreach(f ${ARGN})
    list(APPEND listVar "${prefix}${f}")
  endforeach(f)
  set(${var} "${listVar}" PARENT_SCOPE)
endfunction()

# equivalent to $(filter needle,haystack). Returns a list containing all of the
# items in ${ARGN} (after needle) that match needle.
macro(llvm_filter output needle)
  set(${output})
  foreach(haystack_item ${ARGN})
    foreach(needle_item ${needle})
      if("${haystack_item}" STREQUAL "${needle_item}")
        list(APPEND ${output} ${haystack_item})
      endif()
    endforeach()
  endforeach()
endmacro()

# equivalent to $(filter-out needle,haystack). Inverse of llvm_filter.
macro(llvm_filter_out output needle)
  set(${output} "${ARGN}")
  llvm_filter(tmp_output ${needle} ${ARGN})
  list(REMOVE_ITEM ${output} ${tmp_output})
endmacro()
