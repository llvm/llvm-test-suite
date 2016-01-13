set(PARALLEL_DIRS)

set(PARALLEL_DIRS C++11)
if("${ARCH}" STREQUAL "Mips")
  list(APPEND PARALLEL_DIRS Mips)
endif()

llvm_add_subdirectories(${PARALLEL_DIRS})
