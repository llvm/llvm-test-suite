set(IMAGEPROC_UTILS MicroBenchmarks/ImageProcessing/utils)
list(APPEND CPPFLAGS -I ${CMAKE_SOURCE_DIR}/${IMAGEPROC_UTILS})
list(APPEND LDFLAGS -lm)

llvm_test_verify_hash_program_output(orderedOutput.txt)
llvm_test_verify(WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
  ${FPCMP} orderedDither.reference_output orderedOutput.txt
)

llvm_test_verify_hash_program_output(floydOutput.txt)
llvm_test_verify(WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
  ${FPCMP} floydDither.reference_output floydOutput.txt
)

llvm_test_run(WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
llvm_test_executable(Dither main.cpp orderedDitherKernel.c  floydDitherKernel.c ../utils/ImageHelper.cpp ../utils/glibc_compat_rand.c)
llvm_test_data(Dither orderedDither.reference_output floydDither.reference_output)

target_link_libraries(Dither benchmark)
