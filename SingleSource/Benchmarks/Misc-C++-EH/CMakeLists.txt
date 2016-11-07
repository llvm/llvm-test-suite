list(APPEND CXXFLAGS -pthread)
list(APPEND LDFLAGS -lm -lstdc++ -pthread)
set(REQUIRES_EH_SUPPORT 1)
llvm_singlesource()
