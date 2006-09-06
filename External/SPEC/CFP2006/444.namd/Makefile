##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 namd test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

FP_ABSTOLERANCE = 0.00001

include ../../Makefile.spec2006

RUN_OPTIONS      = --input namd.input --iterations 1 --output namd.out
STDOUT_FILENAME := namd.out

LDFLAGS = -lstdc++ -lm
LIBS    = -lstdc++ -lm
