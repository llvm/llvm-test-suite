#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# These tests are skipped because they hit a 'not yet implemented' assertion
# in flang and thus fail to compile. They should be removed from here when the
# corresponding feature is implemented. Eventually, this vairable should be
# removed altogether once all the missing features are implemented.
file (GLOB UNIMPLEMENTED_FILES
  # unimplemented: BIND(C) INTENT(OUT) allocatable deallocation in HLFIR
  bind-c-intent-out-2.f90
)
