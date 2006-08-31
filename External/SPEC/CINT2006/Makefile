##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building SPEC2006 integer tests.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../..
PARALLEL_DIRS := \
	401.bzip2      \
	403.gcc        \
	429.mcf        \
        456.hmmer      \
        458.sjeng      \
        462.libquantum \
        464.h264ref    \
        473.astar

# 400.perlbench -- Need Makefile Help
# 445.gobmk     -- Multiple Dirs
# 471.omnetpp   -- Multiple Dirs
# 483.xalancbmk -- Needs C++ Exceptions

# Get the $(ARCH) setting
include $(LEVEL)/Makefile.config

include $(LEVEL)/Makefile.programs
