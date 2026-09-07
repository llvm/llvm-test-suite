SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/halide_runtime.bc PROPERTIES LANGUAGE CXX)
SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/vector_widen.bc PROPERTIES LANGUAGE CXX)
# -xir must follow the -x c++ that CMP0119 injects alongside LANGUAGE CXX.
set_property(SOURCE
  ${CMAKE_CURRENT_SOURCE_DIR}/halide_runtime.bc
  ${CMAKE_CURRENT_SOURCE_DIR}/vector_widen.bc
  APPEND PROPERTY COMPILE_OPTIONS "-xir")

find_package(Threads)
list(APPEND LDFLAGS ${CMAKE_THREAD_LIBS_INIT})
foreach(lib ${CMAKE_DL_LIBS})
  list(APPEND LDFLAGS -l${lib})
endforeach()

llvm_multisource(widen_bug
  ${CMAKE_CURRENT_SOURCE_DIR}/driver.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/halide_runtime.bc
  ${CMAKE_CURRENT_SOURCE_DIR}/vector_widen.bc
)
