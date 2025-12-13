list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 20000 14)
llvm_multisource(StatementReordering-dbl)
set_property(TARGET StatementReordering-dbl PROPERTY C_STANDARD 99)
