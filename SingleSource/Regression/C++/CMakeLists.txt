add_subdirectory(EH)

list(APPEND LDFLAGS -lstdc++)
llvm_singlesource(PREFIX "Regression-C++-")
