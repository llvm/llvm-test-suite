SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/sap_fct_splitting.bc PROPERTIES LANGUAGE C)
SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/mocks.c PROPERTIES LANGUAGE C)

find_package(Threads)
list(APPEND LDFLAGS ${CMAKE_THREAD_LIBS_INIT})
foreach(lib ${CMAKE_DL_LIBS})
  list(APPEND LDFLAGS -l${lib})
endforeach()

llvm_multisource(sap_fct_splitting
  ${CMAKE_CURRENT_SOURCE_DIR}/sap_fct_splitting.bc
  ${CMAKE_CURRENT_SOURCE_DIR}/mocks.c
)
