set(IMAGEPROC_UTILS MicroBenchmarks/ImageProcessing/utils)
list(APPEND CPPFLAGS -I ${CMAKE_SOURCE_DIR}/${IMAGEPROC_UTILS})
list(APPEND LDFLAGS -lm)

# Floating point contraction must be suppressed due to accuracy issues
list(APPEND CXXFLAGS -ffp-contract=off -DFMA_DISABLED=1)
list(APPEND CFLAGS -ffp-contract=off -DFMA_DISABLED=1)

llvm_test_run(WORKDIR %S)
llvm_test_verify_hash_program_output(%S/bilateralFilterOutput.txt)
llvm_test_verify(
  %b/${FPCMP} %S/bilateralFilter.reference_output %S/bilateralFilterOutput.txt)

llvm_test_executable(BilateralFilter ../utils/ImageHelper.cpp ../utils/glibc_compat_rand.c main.cpp bilateralFilterKernel.c)
llvm_test_data(BilateralFilter bilateralFilter.reference_output)

target_link_libraries(BilateralFilter benchmark)
