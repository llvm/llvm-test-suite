list(APPEND FFLAGS -funsigned)

llvm_singlesource()

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
