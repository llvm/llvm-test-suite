list(APPEND LDFLAGS -lm )
set(FP_TOLERANCE 0.001)
set(Source
  chomp.c
  misr.c
  queens.c
)
if(NOT TEST_SUITE_BENCHMARKING_ONLY)
  list(APPEND Source exptree.c)
endif()
llvm_singlesource()
