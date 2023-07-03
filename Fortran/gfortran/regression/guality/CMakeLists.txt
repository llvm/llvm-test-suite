#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

message(STATUS "Adding directory Fortran/gfortran/regression/guality")

# The tests in this directory seem to check the interaction of the compiler with
# gdb. It is not clear how we can test that - or if we even want to.
