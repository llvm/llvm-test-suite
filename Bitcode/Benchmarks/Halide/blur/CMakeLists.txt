file(GLOB bcsources ${CMAKE_CURRENT_SOURCE_DIR}/../common/x86_halide_runtime.bc ${CMAKE_CURRENT_SOURCE_DIR}/halide_blur.bc)
SET_SOURCE_FILES_PROPERTIES(${bcsources} PROPERTIES LANGUAGE CXX)

llvm_multisource(halide_blur
  ${CMAKE_CURRENT_SOURCE_DIR}/driver.cpp
  ${bcsources}
)
