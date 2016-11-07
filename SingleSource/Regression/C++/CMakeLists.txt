add_subdirectory(EH)

list(APPEND LDFLAGS -lstdc++)
llvm_singlesource(PREFIX "regression-cxx")
