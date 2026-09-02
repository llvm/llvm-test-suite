SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/sap_fct_splitting.bc PROPERTIES LANGUAGE C)
SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/mocks.c PROPERTIES LANGUAGE C)
# -xir must follow the -x c that CMP0119 injects alongside LANGUAGE C.
set_property(SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/sap_fct_splitting.bc
  APPEND PROPERTY COMPILE_OPTIONS "-xir")

llvm_multisource(sap_fct_splitting
  ${CMAKE_CURRENT_SOURCE_DIR}/sap_fct_splitting.bc
  ${CMAKE_CURRENT_SOURCE_DIR}/mocks.c
)
