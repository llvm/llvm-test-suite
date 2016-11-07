llvm_add_subdirectories(Large)

list(APPEND LDFLAGS -lm)
llvm_singlesource()
