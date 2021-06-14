list(APPEND LDFLAGS -lm)
set(FP_TOLERANCE 0.0001)
llvm_singlesource()
