list(APPEND CXXFLAGS -pthread)
list(APPEND LDFLAGS -lm -lstdc++ -pthread)
llvm_singlesource()
