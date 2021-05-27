set(IMAGEPROC_UTILS MicroBenchmarks/ImageProcessing/utils)

list(APPEND CPPFLAGS -I ${CMAKE_SOURCE_DIR}/${IMAGEPROC_UTILS})
list(APPEND LDFLAGS -lm)

if(ARCH STREQUAL "x86")
  # Floating point contraction must be suppressed due to accuracy issues
  list(APPEND CXXFLAGS -ffp-contract=off -DFMA_DISABLED=1)
  list(APPEND CFLAGS -ffp-contract=off -DFMA_DISABLED=1)
endif()

llvm_test_verify_hash_program_output(boxBlurOutput.txt)
llvm_test_verify(WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
  ${FPCMP} boxBlur.reference_output boxBlurOutput.txt
)

llvm_test_verify_hash_program_output(gaussianBlurOutput.txt)
llvm_test_verify(WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
  ${FPCMP} gaussianBlur.reference_output gaussianBlurOutput.txt
)

llvm_test_run(WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
llvm_test_executable(blur ../utils/ImageHelper.cpp ../utils/glibc_compat_rand.c main.cpp boxBlurKernel.c gaussianBlurKernel.c)
llvm_test_data(blur boxBlur.reference_output gaussianBlur.reference_output)

target_link_libraries(blur benchmark)
