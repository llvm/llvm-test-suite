file(GLOB _sources *.f90)

set(Source ${_sources})

# The tests report results by exit status (STOP 1 on any failure), so there is
# no reference output to compare against.  Inherited by modfile-roundtrip.
set(NO_REFERENCE_OUTPUT 1)

llvm_singlesource()

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

add_subdirectory(modfile-roundtrip)
