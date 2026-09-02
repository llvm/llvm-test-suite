# -xir must follow the -x c that CMP0119 injects alongside LANGUAGE C.
SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/sap_fct_splitting.bc PROPERTIES LANGUAGE C COMPILE_OPTIONS "-xir")
SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/mocks.c PROPERTIES LANGUAGE C)

llvm_multisource(sap_fct_splitting
  ${CMAKE_CURRENT_SOURCE_DIR}/sap_fct_splitting.bc
  ${CMAKE_CURRENT_SOURCE_DIR}/mocks.c
)
