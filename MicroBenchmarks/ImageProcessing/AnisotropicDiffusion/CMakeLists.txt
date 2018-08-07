set(IMAGEPROC_UTILS MicroBenchmarks/ImageProcessing/utils)

list(APPEND CXXFLAGS -I ${CMAKE_SOURCE_DIR}/${IMAGEPROC_UTILS})
list(APPEND LDFLAGS -lm)

llvm_test_verify("${CMAKE_SOURCE_DIR}/HashProgramOutput.sh ${CMAKE_CURRENT_BINARY_DIR}/anisotropicDiffusionOutput.txt")
llvm_test_verify("${FPCMP} ${CMAKE_CURRENT_BINARY_DIR}/anisotropicDiffusionOutput.txt ${CMAKE_CURRENT_SOURCE_DIR}/anisotropicDiffusion.reference_output")

llvm_test_run(WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
llvm_test_executable(AnisotropicDiffusion ../utils/ImageHelper.cpp ../utils/glibc_compat_rand.c main.cpp anisotropicDiffusionKernel.c)

target_link_libraries(AnisotropicDiffusion benchmark)
