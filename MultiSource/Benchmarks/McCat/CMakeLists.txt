set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS 01-qbsort 04-bisect 08-main 12-IOtest 17-bintr 03-testtrie 05-eks 09-vor 15-trie 18-imp)
if(DEFINED BENCHMARKING_ONLY)
  llvm_filter_out(TMP1 15-trie  ${PARALLEL_DIRS})
  set(PARALLEL_DIRS ${TMP1})
endif()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
