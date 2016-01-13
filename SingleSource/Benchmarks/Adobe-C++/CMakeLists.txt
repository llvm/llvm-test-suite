list(APPEND LDFLAGS -lm -lstdc++)
set(LIBS -lstdc++)
set(FP_ABSTOLERANCE 0.01)
llvm_singlesource()
