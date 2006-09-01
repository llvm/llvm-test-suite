##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 wrf test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

FP_TOLERANCE    = 5e-2
FP_ABSTOLERANCE = 1.0e-2

include ../../Makefile.spec2006
include $(PROJ_SRC_ROOT)/Makefile.FORTRAN

FPPFLAGS += -w -m literal.pm \
            -DINTIO -DIWORDSIZE=4 -DDWORDSIZE=8 -DRWORDSIZE=4 -DLWORDSIZE=4   \
            -DNETCDF  -DTRIEDNTRUE -DLIMIT_ARGS -DEM_CORE=1  -DNMM_CORE=0     \
            -DNMM_MAX_DIM=1000 -DCOAMPS_CORE=0  -DEXP_CORE=0 -DF90_STANDALONE \
            -DCONFIG_BUF_LEN=8192 -DMAX_DOMAINS_F=21 -DNO_NAMELIST_PRINT      \
            -I$(SPEC_BENCH_DIR)/src

CPPFLAGS += -I$(SPEC_BENCH_DIR)/src -I$(SPEC_BENCH_DIR)/src/netcdf/include

STDOUT_FILENAME := rsl.out.0000
