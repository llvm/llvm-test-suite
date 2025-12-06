list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 20000 5)
llvm_multisource(StatementReordering-flt)
set_property(TARGET StatementReordering-flt PROPERTY C_STANDARD 99)
