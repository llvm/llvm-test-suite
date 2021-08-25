set(IMAGEPROC_UTILS MicroBenchmarks/ImageProcessing/utils)
list(APPEND CXXFLAGS -I ${CMAKE_SOURCE_DIR}/${IMAGEPROC_UTILS})

llvm_test_run(WORKDIR %S)
llvm_test_verify_hash_program_output(%S/bicubicOutput.txt)
llvm_test_verify(%b/${FPCMP} %S/bicubic.reference_output %S/bicubicOutput.txt)

llvm_test_verify_hash_program_output(%S/bilinearOutput.txt)
llvm_test_verify(%b/${FPCMP} %S/bilinear.reference_output %S/bilinearOutput.txt)

llvm_test_executable(Interpolation bicubicKernel.c bilinearKernel.c main.cpp ../utils/ImageHelper.cpp ../utils/glibc_compat_rand.c)
llvm_test_data(Interpolation bicubic.reference_output bilinear.reference_output)

target_link_libraries(Interpolation benchmark)
