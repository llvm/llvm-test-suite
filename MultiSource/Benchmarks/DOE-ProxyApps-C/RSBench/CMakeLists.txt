list(APPEND LDFLAGS -lm)
list(APPEND CFLAGS -std=gnu99)
set(RUN_OPTIONS -s small -l 100000 -p 1000 -w 1000)
llvm_multisource(rsbench)
