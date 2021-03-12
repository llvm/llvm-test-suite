##===- Fortran.cmake ----------------------------------------------------===##
#
# Fortran-specific helper functions to build benchmarks and the
# corresponding .test files
#
##===--------------------------------------------------------------------===##


# The Ninja generator supports robust scanning for modules that are
# needed by some Fortran tests. Because Ninja does a full
# preprocessing pass on Fortran files, it is able to detect module
# dependencies that are dependent on preprocessing.
# For example,
# #ifdef FOO 
# USE MODULE_A
# #else
# USE MODULE_B
# #endif
# This is support by Ninja, but not the Unix Makefiles generator.
# More details here:
# https://gitlab.kitware.com/cmake/cmake/-/issues/16590"

function(ninja_required)
  if(NOT CMAKE_GENERATOR STREQUAL "Ninja")
    message(SEND_ERROR
      "This test is NOT supported by CMAKE_GENERATOR = ${CMAKE_GENERATOR}.\n"
      "Please use use Ninja 1.10 or later by adding -G \"Ninja\" to cmake invocation.\n")
  endif()
endfunction()

# standard CMake Utility Modules specific to Fortran
# https://cmake.org/cmake/help/latest/manual/cmake-modules.7.html
include(CheckFortranCompilerFlag)
