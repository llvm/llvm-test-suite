list(APPEND LDFLAGS -lm -lstdc++)
set(FP_ABSTOLERANCE 0.01)
set(HASH_PROGRAM_OUTPUT 1)
llvm_singlesource()
