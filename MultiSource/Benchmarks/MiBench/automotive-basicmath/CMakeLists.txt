set(PROG automotive-basicmath)
list(APPEND LDFLAGS -lm)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource()
