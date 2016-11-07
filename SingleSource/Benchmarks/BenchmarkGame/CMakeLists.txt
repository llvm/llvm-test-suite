add_subdirectory(Large)

list(APPEND LDFLAGS -lm)
llvm_singlesource()
