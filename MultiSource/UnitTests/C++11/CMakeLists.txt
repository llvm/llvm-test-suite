set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS frame_layout)
list(APPEND CPPFLAGS -std=c++11)
string(FIND "${MIPSARCH}" "mips16" TMP1)
if(NOT "" STREQUAL "${TMP1}")
  llvm_filter_out(TMP2 frame_layout  ${PARALLEL_DIRS})
  set(PARALLEL_DIRS ${TMP2})
endif()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
