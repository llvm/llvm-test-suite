llvm_add_subdirectories(EH)

list(APPEND LDFLAGS -lstdc++)
llvm_singlesource(PREFIX "regression-cxx")
