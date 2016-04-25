llvm_target_prefix("Vector-NEON")
list(APPEND CFLAGS -std=c99)
llvm_singlesource()
