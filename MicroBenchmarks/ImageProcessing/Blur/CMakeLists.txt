set(IMAGEPROC_UTILS MicroBenchmarks/ImageProcessing/utils)

list(APPEND CPPFLAGS -I ${CMAKE_SOURCE_DIR}/${IMAGEPROC_UTILS})
list(APPEND LDFLAGS -lm)

llvm_test_verify("${CMAKE_SOURCE_DIR}/HashProgramOutput.sh ${CMAKE_CURRENT_BINARY_DIR}/boxBlurOutput.txt")
llvm_test_verify("${FPCMP} ${CMAKE_CURRENT_BINARY_DIR}/boxBlurOutput.txt ${CMAKE_CURRENT_SOURCE_DIR}/boxBlur.reference_output")

llvm_test_verify("${CMAKE_SOURCE_DIR}/HashProgramOutput.sh ${CMAKE_CURRENT_BINARY_DIR}/gaussianBlurOutput.txt")
llvm_test_verify("${FPCMP} ${CMAKE_CURRENT_BINARY_DIR}/gaussianBlurOutput.txt ${CMAKE_CURRENT_SOURCE_DIR}/gaussianBlur.reference_output")

llvm_test_run(WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
llvm_test_executable(blur ../utils/ImageHelper.cpp ../utils/glibc_compat_rand.c main.cpp boxBlurKernel.c gaussianBlurKernel.c)

target_link_libraries(blur benchmark)
