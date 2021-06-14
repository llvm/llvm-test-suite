list(APPEND CXXFLAGS -DREDSTORM) # -DREDSTORM for mkdir
# Floating point contraction must be suppressed due to accuracy issues
list(APPEND CXXFLAGS -ffp-contract=off -DFMA_DISABLED=1)
list(APPEND CFLAGS -ffp-contract=off -DFMA_DISABLED=1)

list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 50 50 50)
llvm_multisource(HPCCG)
