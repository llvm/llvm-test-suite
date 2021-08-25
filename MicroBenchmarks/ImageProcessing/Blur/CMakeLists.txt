set(IMAGEPROC_UTILS MicroBenchmarks/ImageProcessing/utils)

list(APPEND CPPFLAGS -I ${CMAKE_SOURCE_DIR}/${IMAGEPROC_UTILS})
list(APPEND LDFLAGS -lm)

# Floating point contraction must be suppressed due to accuracy issues
list(APPEND CXXFLAGS -ffp-contract=off -DFMA_DISABLED=1)
list(APPEND CFLAGS -ffp-contract=off -DFMA_DISABLED=1)

llvm_test_run(WORKDIR %S)
llvm_test_verify_hash_program_output(%S/boxBlurOutput.txt)
llvm_test_verify(%b/${FPCMP} %S/boxBlur.reference_output %S/boxBlurOutput.txt)

llvm_test_verify_hash_program_output(%S/gaussianBlurOutput.txt)
llvm_test_verify(
  %b/${FPCMP} %S/gaussianBlur.reference_output %S/gaussianBlurOutput.txt)

llvm_test_executable(blur ../utils/ImageHelper.cpp ../utils/glibc_compat_rand.c main.cpp boxBlurKernel.c gaussianBlurKernel.c)
llvm_test_data(blur boxBlur.reference_output gaussianBlur.reference_output)

target_link_libraries(blur benchmark)
