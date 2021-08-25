set(IMAGEPROC_UTILS MicroBenchmarks/ImageProcessing/utils)
list(APPEND CPPFLAGS -I ${CMAKE_SOURCE_DIR}/${IMAGEPROC_UTILS})

llvm_test_run(WORKDIR %S)
llvm_test_verify_hash_program_output(%S/dilateOutput.txt)
llvm_test_verify(%b/${FPCMP} %S/dilate.reference_output %S/dilateOutput.txt)


llvm_test_executable(Dilate ../utils/ImageHelper.cpp ../utils/glibc_compat_rand.c main.cpp dilateKernel.c)
llvm_test_data(Dilate dilate.reference_output)

target_link_libraries(Dilate benchmark)
