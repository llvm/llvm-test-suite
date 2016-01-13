set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../..)
string(FIND "${MIPSARCH}" "mips16" TMP1)
if(NOT "" STREQUAL "${TMP1}")
  list(APPEND PARALLEL_DIRS Mips16)
endif()
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
