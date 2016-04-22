llvm_target_prefix("regression-cxx")
list(APPEND LDFLAGS -lstdc++)
llvm_singlesource()

llvm_add_subdirectories(EH)
