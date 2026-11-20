# Saved local variables accessed by another instance of their procedure,
# invoked from a call that optimizations must not move code across.
set(FFLAGS -O2)
llvm_singlesource()

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
