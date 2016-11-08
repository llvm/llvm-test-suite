set(REQUIRES_EH_SUPPORT 1)
list(APPEND LDFLAGS -lstdc++)
llvm_singlesource(PREFIX "Shootout-C++-")
