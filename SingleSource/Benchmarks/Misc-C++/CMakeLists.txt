set(CMAKE_CXX_STANDARD 14)
add_subdirectory(Large)

list(APPEND LDFLAGS -lm)
set(FP_ABSTOLERANCE 0.01)
llvm_singlesource()
