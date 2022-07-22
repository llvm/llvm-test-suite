list(APPEND LDFLAGS -lm)
list(APPEND CFLAGS -std=gnu99 -Wno-int-conversion)
set(RUN_OPTIONS 20000 5)
llvm_multisource(Recurrences-flt)
