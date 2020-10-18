list(APPEND CXXFLAGS -pthread)
list(APPEND LDFLAGS -lm -pthread)
llvm_singlesource()
