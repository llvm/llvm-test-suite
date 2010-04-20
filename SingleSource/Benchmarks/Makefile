LEVEL = ../..

# TODO: Misc-C++-EH is excluded from PARALLEL_DIRS because spirit.cpp
# fails with clang.

PARALLEL_DIRS=Dhrystone CoyoteBench Shootout Shootout-C++ Stanford McGill \
              Misc Misc-C++ BenchmarkGame Adobe-C++

LDFLAGS += -lm

include $(LEVEL)/SingleSource/Makefile.singlesrc
