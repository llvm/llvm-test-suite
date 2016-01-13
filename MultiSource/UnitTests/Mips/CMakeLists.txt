set(PARALLEL_DIRS)

set(PARALLEL_DIRS )
string(FIND "${MIPSARCH}" "mips16" TMP1)
if(NOT "" STREQUAL "${TMP1}")
  list(APPEND PARALLEL_DIRS Mips16)
endif()

llvm_add_subdirectories(${PARALLEL_DIRS})
