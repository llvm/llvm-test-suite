set(IMAGEPROC_UTILS MicroBenchmarks/ImageProcessing/utils)

list(APPEND CXXFLAGS -I ${CMAKE_SOURCE_DIR}/${IMAGEPROC_UTILS})
list(APPEND LDFLAGS -lm)

llvm_test_verify_hash_program_output(anisotropicDiffusionOutput.txt)
llvm_test_verify(WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
  ${FPCMP} anisotropicDiffusion.reference_output anisotropicDiffusionOutput.txt
)

llvm_test_run(WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
llvm_test_executable(AnisotropicDiffusion ../utils/ImageHelper.cpp ../utils/glibc_compat_rand.c main.cpp anisotropicDiffusionKernel.c)
llvm_test_data(AnisotropicDiffusion anisotropicDiffusion.reference_output)

target_link_libraries(AnisotropicDiffusion benchmark)
