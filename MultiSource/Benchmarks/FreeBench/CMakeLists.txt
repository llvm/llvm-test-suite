set(PARALLEL_DIRS)

set(PARALLEL_DIRS distray mason pcompress2 analyzer fourinarow neural pifft)
if("${ARCH}" STREQUAL "Sparc")
  llvm_filter_out(TMP1 analyzer  ${PARALLEL_DIRS})
  set(PARALLEL_DIRS ${TMP1})
endif()

llvm_add_subdirectories(${PARALLEL_DIRS})
