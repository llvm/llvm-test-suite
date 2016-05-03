set(PROG consumer-jpeg)
list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS -dct int -ppm -outfile /dev/null ${CMAKE_CURRENT_SOURCE_DIR}/input_large.jpg)
llvm_multisource()
