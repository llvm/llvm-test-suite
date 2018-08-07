set(IMAGEPROC_UTILS MicroBenchmarks/ImageProcessing/utils)
list(APPEND CXXFLAGS -I ${CMAKE_SOURCE_DIR}/${IMAGEPROC_UTILS})

llvm_test_verify("${CMAKE_SOURCE_DIR}/HashProgramOutput.sh ${CMAKE_CURRENT_BINARY_DIR}/bicubicOutput.txt")
llvm_test_verify("${FPCMP} ${CMAKE_CURRENT_BINARY_DIR}/bicubicOutput.txt ${CMAKE_CURRENT_SOURCE_DIR}/bicubic.reference_output")

llvm_test_verify("${CMAKE_SOURCE_DIR}/HashProgramOutput.sh ${CMAKE_CURRENT_BINARY_DIR}/bilinearOutput.txt")
llvm_test_verify("${FPCMP} ${CMAKE_CURRENT_BINARY_DIR}/bilinearOutput.txt ${CMAKE_CURRENT_SOURCE_DIR}/bilinear.reference_output")

llvm_test_run(WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
llvm_test_executable(Interpolation bicubicKernel.c bilinearKernel.c main.cpp ../utils/ImageHelper.cpp ../utils/glibc_compat_rand.c)

target_link_libraries(Interpolation benchmark)
