##===- projects/llvm-test/Makefile -------------------------*- Makefile -*-===##
# 
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
# 
##===----------------------------------------------------------------------===##
#
# This recursively traverses the programs, building them as necessary.  This
# makefile also implements 'make report TEST=<x>'.
#
##===----------------------------------------------------------------------===##

LEVEL = .
PARALLEL_DIRS = SingleSource MultiSource External

include $(LEVEL)/Makefile.programs

build-for-llvm-top:
	./configure --with-llvmsrc=$(LLVM_TOP)/llvm --with-llvmobj=$(LLVM_TOP)/llvm --srcdir=$(LLVM_TOP)/test-suite --with-llvmgccdir=$(LLVM_TOP)/install --with-externals=$(LLVM_TOP)/externals
	$(MAKE)
