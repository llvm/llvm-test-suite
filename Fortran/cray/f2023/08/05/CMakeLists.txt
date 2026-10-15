file(GLOB _sources *.f90)

set(Source ${_sources})

llvm_singlesource()

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
