file(GLOB bcsources ${CMAKE_CURRENT_SOURCE_DIR}/../common/x86_halide_runtime.bc ${CMAKE_CURRENT_SOURCE_DIR}/bilateral_grid.bc)
SET_SOURCE_FILES_PROPERTIES(${bcsources} PROPERTIES LANGUAGE CXX)

test_img_input(rgb 0.1 10)
test_img_input(rgba 0.1 10)

llvm_test_executable(halide_bilateral_grid driver.cpp ${bcsources})
test_img_data(halide_bilateral_grid rgb)
test_img_data(halide_bilateral_grid rgba)
