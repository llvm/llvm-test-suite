set(FP_TOLERANCE 0.016)
list(APPEND LDFLAGS -lm)
list(APPEND TARGET_FLAGS -msse2)
list(APPEND LCCFLAGS -msse2)
# Floating point contraction must be suppressed due to accuracy issues
list(APPEND CXXFLAGS -ffp-contract=off -DFMA_DISABLED=1)
list(APPEND CFLAGS -ffp-contract=off -DFMA_DISABLED=1)
llvm_singlesource(PREFIX "Vector-")
