# MultiSource/Benchmarks Makefile:  Build all subdirectories automatically

LEVEL = ../../../..
include $(LEVEL)/Makefile.config

PARALLEL_DIRS  := $(basename $(shell ls $(SourceDir) | grep -v CVS | grep -v Makefile))

include $(LEVEL)/test/Programs/Makefile.programs
