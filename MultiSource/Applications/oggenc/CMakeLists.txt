list(APPEND CFLAGS -fno-strict-aliasing)
# Floating point contraction must be suppressed due to accuracy issues
list(APPEND CXXFLAGS -ffp-contract=off -DFMA_DISABLED=1)
list(APPEND CFLAGS -ffp-contract=off -DFMA_DISABLED=1)

list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS -Q -s 901820 - < tune)
llvm_multisource(oggenc)
llvm_test_data(oggenc tune)
