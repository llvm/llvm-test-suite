file(GLOB bcsources ${CMAKE_CURRENT_SOURCE_DIR}/../common/x86_halide_runtime.bc ${CMAKE_CURRENT_SOURCE_DIR}/local_laplacian.bc)
SET_SOURCE_FILES_PROPERTIES(${bcsources} PROPERTIES LANGUAGE CXX)

set(Source ${CMAKE_CURRENT_SOURCE_DIR}/driver.cpp ${bcsources})
set(PROG halide_local_laplacian)

test_img_input(rgb 8 1 1 10)
test_img_input(rgba 8 1 1 10)

llvm_multisource()




