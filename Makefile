##===- test/Programs/Makefile ------------------------------*- Makefile -*-===##
#
# This recursively traverses the programs, building them as necessary.  This
# makefile also implements 'make report TEST=<x>'.
#
##===----------------------------------------------------------------------===##

LEVEL = ../..
PARALLEL_DIRS = SingleSource MultiSource External
#LLVMSource 

include ${LEVEL}/test/Programs/Makefile.programs

