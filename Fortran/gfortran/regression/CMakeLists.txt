#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# PREFIX_EXECUTE and PREFIX_COMPILE are used in gfortran_add_execute_test and
# gfortran_add_compile_test respectively.
set(PREFIX_EXECUTE "gfortran-regression-execute")
set(PREFIX_COMPILE "gfortran-regression-compile")

gfortran_populate_tests()

add_subdirectory(analyzer)
add_subdirectory(asan)
add_subdirectory(c-interop)
add_subdirectory(coarray)
add_subdirectory(debug)
add_subdirectory(g77)
add_subdirectory(goacc)
add_subdirectory(goacc-gomp)
add_subdirectory(gomp)
add_subdirectory(gomp/appendix-a)
add_subdirectory(graphite)
add_subdirectory(guality)
add_subdirectory(ieee)
add_subdirectory(lto)
add_subdirectory(prof)
add_subdirectory(ubsan)
add_subdirectory(vect)

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
