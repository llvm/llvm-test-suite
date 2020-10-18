list(APPEND LDFLAGS -lm)
set(FP_ABSTOLERANCE 0.01)
llvm_singlesource()
