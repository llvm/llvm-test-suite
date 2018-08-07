set(IMAGEPROC_UTILS MicroBenchmarks/ImageProcessing/utils)
list(APPEND CPPFLAGS -I ${CMAKE_SOURCE_DIR}/${IMAGEPROC_UTILS})
list(APPEND LDFLAGS -lm)

llvm_test_verify("${CMAKE_SOURCE_DIR}/HashProgramOutput.sh ${CMAKE_CURRENT_BINARY_DIR}/orderedOutput.txt")
llvm_test_verify("${FPCMP} ${CMAKE_CURRENT_BINARY_DIR}/orderedOutput.txt ${CMAKE_CURRENT_SOURCE_DIR}/orderedDither.reference_output")

llvm_test_verify("${CMAKE_SOURCE_DIR}/HashProgramOutput.sh ${CMAKE_CURRENT_BINARY_DIR}/floydOutput.txt")
llvm_test_verify("${FPCMP} ${CMAKE_CURRENT_BINARY_DIR}/floydOutput.txt ${CMAKE_CURRENT_SOURCE_DIR}/floydDither.reference_output")

llvm_test_run(WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
llvm_test_executable(Dither main.cpp orderedDitherKernel.c  floydDitherKernel.c ../utils/ImageHelper.cpp ../utils/glibc_compat_rand.c)

target_link_libraries(Dither benchmark)
