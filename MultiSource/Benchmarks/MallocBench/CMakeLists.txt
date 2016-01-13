set(PARALLEL_DIRS)

set(PARALLEL_DIRS cfrac espresso gs)
if("${ARCH}" STREQUAL "Alpha")
  llvm_filter_out(TMP1 cfrac  ${PARALLEL_DIRS})
  set(PARALLEL_DIRS ${TMP1})
endif()

llvm_add_subdirectories(${PARALLEL_DIRS})
