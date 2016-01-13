string(FIND "${MIPSARCH}" "mips16" TMP1)
if(NOT "" STREQUAL "${TMP1}")
  llvm_add_subdirectories(Mips16)
endif()
