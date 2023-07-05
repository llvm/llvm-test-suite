#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

message(STATUS "Adding directory Fortran/gfortran/torture")

# PREFIX_EXECUTE and PREFIX_COMPILE are used in gfortran_add_execute_test and
# gfortran_add_compile_test respectively.
set(PREFIX_EXECUTE "gfortran-torture-execute")
set(PREFIX_COMPILE "gfortran-torture-compile")

add_subdirectory(compile)
add_subdirectory(execute)

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
