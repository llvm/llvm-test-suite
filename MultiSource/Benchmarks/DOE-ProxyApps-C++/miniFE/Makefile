LEVEL = ../../../..

PROG     = miniFE
CXXFLAGS = -I. -DMINIFE_SCALAR=double -DMINIFE_LOCAL_ORDINAL=int -DMINIFE_GLOBAL_ORDINAL=int -DMINIFE_CSR_MATRIX
LDFLAGS  = -lm
RUN_OPTIONS = -nx 64 -ny 64 -nz 64
include $(LEVEL)/MultiSource/Makefile.multisrc
