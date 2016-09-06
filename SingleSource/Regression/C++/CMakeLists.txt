list(APPEND LDFLAGS -lstdc++)
llvm_singlesource(PREFIX "regression-cxx")

llvm_add_subdirectories(EH)
