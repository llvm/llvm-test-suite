set(PROG miniGMG)
list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 6  2 2 2  1 1 1)
llvm_multisource()
