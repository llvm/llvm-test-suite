##===- projects/llvm-test/Makefile -------------------------*- Makefile -*-===##
# 
#                     The LLVM Compiler Infrastructure
#
# This file was developed by the LLVM research group and is distributed under
# the University of Illinois Open Source License. See LICENSE.TXT for details.
# 
##===----------------------------------------------------------------------===##
#
# This recursively traverses the programs, building them as necessary.  This
# makefile also implements 'make report TEST=<x>'.
#
##===----------------------------------------------------------------------===##

LEVEL = .
DIRS = Runtime
PARALLEL_DIRS = SingleSource MultiSource External

include $(LEVEL)/Makefile.programs
