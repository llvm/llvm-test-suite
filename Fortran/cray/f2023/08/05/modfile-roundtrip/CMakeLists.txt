# Separately compiled provider module, submodules, and consumer: each USE and
# SUBMODULE reads the module file written by the previous compilation.
set(Source provider.f90 child.f90 grandchild.f90 main.f90)
llvm_multisource(declaration-explicit-array-bounds-modfile)

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
