set(RUN_OPTIONS 31415926)
list(APPEND LDFLAGS -lstdc++)
set(HASH_PROGRAM_OUTPUT 1)
llvm_singlesource()
