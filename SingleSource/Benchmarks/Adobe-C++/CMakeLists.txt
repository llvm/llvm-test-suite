list(APPEND LDFLAGS -lm -lstdc++)
set(FP_ABSTOLERANCE 0.01)
llvm_singlesource()
