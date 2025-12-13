list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 80000 5)
llvm_multisource(Searching-flt)
set_property(TARGET Searching-flt PROPERTY C_STANDARD 99)
