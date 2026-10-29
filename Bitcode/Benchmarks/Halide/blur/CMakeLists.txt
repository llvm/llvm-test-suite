file(GLOB bcsources ${CMAKE_CURRENT_SOURCE_DIR}/../common/x86_halide_runtime.bc ${CMAKE_CURRENT_SOURCE_DIR}/halide_blur.bc)
SET_SOURCE_FILES_PROPERTIES(${bcsources} PROPERTIES LANGUAGE CXX)
# -xir must follow the -x c++ that CMP0119 injects alongside LANGUAGE CXX.
set_property(SOURCE ${bcsources} APPEND PROPERTY COMPILE_OPTIONS "-xir")

llvm_test_run()

llvm_test_executable(halide_blur
  driver.cpp
  ${bcsources}
)
