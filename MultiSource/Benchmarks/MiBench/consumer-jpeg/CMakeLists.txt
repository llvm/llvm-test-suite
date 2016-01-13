set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG consumer-jpeg)
set(LDFLAGS -lm)
set(RUN_OPTIONS -dct int -ppm -outfile Output/output_large_decode.ppm ${CMAKE_CURRENT_SOURCE_DIR}/input_large.jpg)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
