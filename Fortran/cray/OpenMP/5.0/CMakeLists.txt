list(APPEND FFLAGS -fopenmp -fopenmp-version=52)
list(APPEND LDFLAGS -fopenmp)

llvm_singlesource()

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
