list(APPEND LDFLAGS -lm)
set(FP_TOLERANCE 0.001)
set(Source
  Bubblesort.c
  FloatMM.c
  Oscar.c
  Perm.c
  Puzzle.c
  Queens.c
  Quicksort.c
  RealMM.c
  Towers.c
  Treesort.c
)
if(NOT TEST_SUITE_BENCHMARKING_ONLY)
  list(APPEND Source IntMM.c)
endif()
llvm_singlesource()
