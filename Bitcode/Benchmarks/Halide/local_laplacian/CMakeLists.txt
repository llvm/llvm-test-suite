file(GLOB bcsources ${CMAKE_CURRENT_SOURCE_DIR}/../common/x86_halide_runtime.bc ${CMAKE_CURRENT_SOURCE_DIR}/local_laplacian.bc)
SET_SOURCE_FILES_PROPERTIES(${bcsources} PROPERTIES LANGUAGE CXX)
# -xir must follow the -x c++ that CMP0119 injects alongside LANGUAGE CXX.
set_property(SOURCE ${bcsources} APPEND PROPERTY COMPILE_OPTIONS "-xir")

test_img_input(rgb 8 1 1 10)
test_img_input(rgba 8 1 1 10)

llvm_test_executable(halide_local_laplacian driver.cpp ${bcsources})
test_img_data(halide_local_laplacian rgb)
test_img_data(halide_local_laplacian rgba)
