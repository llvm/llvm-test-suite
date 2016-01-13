set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../)
set(PROG MultipleResults)
set(LDFLAGS )
set(EXTRA_TEST_RESULTS_FILE ${CMAKE_CURRENT_BINARY_DIR}/Output/MultipleResults.extra-results.txt)
set(RUN_OPTIONS ${EXTRA_TEST_RESULTS_FILE})
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
