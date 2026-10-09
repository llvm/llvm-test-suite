set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -fenumeration-type")

llvm_singlesource()

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
