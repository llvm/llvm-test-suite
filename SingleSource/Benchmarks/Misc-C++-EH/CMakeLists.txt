set(CMAKE_CXX_STANDARD 14)
list(APPEND CXXFLAGS -pthread)
list(APPEND LDFLAGS -lm -pthread)
llvm_singlesource()
