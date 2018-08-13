set(IMAGEPROC_UTILS MicroBenchmarks/ImageProcessing/utils)
list(APPEND CPPFLAGS -I ${CMAKE_SOURCE_DIR}/${IMAGEPROC_UTILS})

llvm_test_verify("${CMAKE_SOURCE_DIR}/HashProgramOutput.sh ${CMAKE_CURRENT_BINARY_DIR}/dilateOutput.txt")
llvm_test_verify("${FPCMP} ${CMAKE_CURRENT_BINARY_DIR}/dilateOutput.txt ${CMAKE_CURRENT_SOURCE_DIR}/dilate.reference_output")

llvm_test_run(WORKDIR ${CMAKE_CURRENT_BINARY_DIR})

llvm_test_executable(Dilate ../utils/ImageHelper.cpp ../utils/glibc_compat_rand.c main.cpp dilateKernel.c)

target_link_libraries(Dilate benchmark)
