#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  # error: operand#0 does not dominate this use
  do-1.f90
  nontemporal-1.f90
  pr59488-1.f90
  pr69183.f90
  pr78298.f90
)
