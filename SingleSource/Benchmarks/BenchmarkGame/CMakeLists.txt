set(DIRS)

set(DIRS Large)
list(APPEND LDFLAGS -lm)
llvm_singlesource()

llvm_add_subdirectories(${DIRS})
