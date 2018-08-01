set(PROG optimizer-eval)
list(APPEND LDFLAGS -lm)
set(NO_REFERENCE_OUTPUT 1)
llvm_multisource()
