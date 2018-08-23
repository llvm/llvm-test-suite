list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS -dct int -ppm -outfile /dev/null input_large.jpg)
llvm_multisource(consumer-jpeg)
llvm_test_data(consumer-jpeg input_large.jpg)
