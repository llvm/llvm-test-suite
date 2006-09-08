##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building SPEC2006 floating point tests.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../..

PARALLEL_DIRS :=  \
    410.bwaves    \
    416.gamess    \
    433.milc      \
    434.zeusmp    \
    435.gromacs   \
    436.cactusADM \
    437.leslie3d  \
    444.namd      \
    447.dealII    \
    454.calculix  \
    459.GemsFDTD  \
    470.lbm       \
    481.wrf


# These compile but need other things to run:
#   450.soplex    - enter.cc:535, works at -O0, not at -O2
#   453.povray    - c++ exceptions
#   465.tonto     - infinite loop, works at -O0, not at -O2
#   482.sphinx3   - generates control file at run time

# Get the $(ARCH) setting
include $(LEVEL)/Makefile.config

include $(LEVEL)/Makefile.programs
