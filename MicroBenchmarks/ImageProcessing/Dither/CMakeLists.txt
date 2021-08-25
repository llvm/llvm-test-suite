set(IMAGEPROC_UTILS MicroBenchmarks/ImageProcessing/utils)
list(APPEND CPPFLAGS -I ${CMAKE_SOURCE_DIR}/${IMAGEPROC_UTILS})
list(APPEND LDFLAGS -lm)

llvm_test_run(WORKDIR %S)
llvm_test_verify_hash_program_output(%S/orderedOutput.txt)
llvm_test_verify(
  %b/${FPCMP} %S/orderedDither.reference_output %S/orderedOutput.txt)

llvm_test_verify_hash_program_output(%S/floydOutput.txt)
llvm_test_verify(
  %b/${FPCMP} %S/floydDither.reference_output %S/floydOutput.txt)

llvm_test_executable(Dither main.cpp orderedDitherKernel.c  floydDitherKernel.c ../utils/ImageHelper.cpp ../utils/glibc_compat_rand.c)
llvm_test_data(Dither orderedDither.reference_output floydDither.reference_output)

target_link_libraries(Dither benchmark)
