##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building SPEC2006 floating point tests.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../..

PARALLEL_DIRS := \
    410.bwaves   \
    416.gamess   \
    433.milc     \
    434.zeusmp   \
    435.gromacs  \
    437.leslie3d \
    444.namd     \
    459.GemsFDTD \
    470.lbm

# These compile but need other things to run:
#   450.soplex    - enter.cc:535, works at -O0, not at -O2
#   453.povray    - c++ exceptions
#   465.tonto     - infinite loop, works at -O0, not at -O2
#   482.sphinx3   - generates control file at run time
# These don't compile
#   436.cactusADM - multiple dirs
#   447.dealII    - multiple dirs
#   454.calculix  - multiple dirs
#   481.wrf       - multiple dirs

# Get the $(ARCH) setting
include $(LEVEL)/Makefile.config

include $(LEVEL)/Makefile.programs
