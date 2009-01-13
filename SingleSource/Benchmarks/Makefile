LEVEL = ../..
PARALLEL_DIRS=Dhrystone CoyoteBench Shootout Shootout-C++ Stanford McGill \
              Misc Misc-C++ BenchmarkGame Adobe-C++
# Misc-C++-EH - someday when EH is supported in llvm-gcc we should 
#               re-enable this test. It always fails and its very slow
#               (100MB Bytecode) so we disable it for now.
LDFLAGS += -lm

include $(LEVEL)/SingleSource/Makefile.singlesrc
