set(PROG optimizer-eval)
list(APPEND LDFLAGS -lm)
set(PROGRAM_IS_NONDETERMINISTIC 1)
llvm_multisource()
