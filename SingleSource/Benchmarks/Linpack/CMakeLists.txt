list(APPEND LDFLAGS -lm)
set(FP_TOLERANCE 0.0001)
# Floating point contraction must be suppressed due to accuracy issues
list(APPEND CXXFLAGS -ffp-contract=off -DFMA_DISABLED=1)
list(APPEND CFLAGS -ffp-contract=off -DFMA_DISABLED=1)

llvm_singlesource()
