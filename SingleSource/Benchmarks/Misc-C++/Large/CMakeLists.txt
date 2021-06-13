list(APPEND LDFLAGS -lm)
set(FP_ABSTOLERANCE 0.01)
set(HASH_PROGRAM_OUTPUT 1)
# Floating point contraction must be suppressed due to accuracy issues
list(APPEND CXXFLAGS -ffp-contract=off -DFMA_DISABLED=1)
list(APPEND CFLAGS -ffp-contract=off -DFMA_DISABLED=1)

llvm_singlesource()
