list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 80000 14)
llvm_multisource(Searching-dbl)
set_property(TARGET Searching-dbl PROPERTY C_STANDARD 99)
