set(IMAGEPROC_UTILS MicroBenchmarks/ImageProcessing/utils)
list(APPEND CPPFLAGS -I ${CMAKE_SOURCE_DIR}/${IMAGEPROC_UTILS})
list(APPEND LDFLAGS -lm)

llvm_test_verify_hash_program_output(bilateralFilterOutput.txt)
llvm_test_verify(WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
  ${FPCMP} bilateralFilter.reference_output bilateralFilterOutput.txt
)

llvm_test_run(WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
llvm_test_executable(BilateralFilter ../utils/ImageHelper.cpp ../utils/glibc_compat_rand.c main.cpp bilateralFilterKernel.c)
llvm_test_data(BilateralFilter bilateralFilter.reference_output)

target_link_libraries(BilateralFilter benchmark)
