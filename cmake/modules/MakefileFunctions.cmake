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
