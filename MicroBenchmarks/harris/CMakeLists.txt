list(APPEND CPPFLAGS -ffast-math)

llvm_test_run(WORKDIR %S)
llvm_test_verify_hash_program_output(%S/output.txt)
llvm_test_verify(%b/${FPCMP} %S/harris.reference_output %S/output.txt)

llvm_test_executable(harris harrisKernel.cpp main.cpp)
set_property(TARGET harris PROPERTY CXX_STANDARD 11)
target_link_libraries(harris benchmark)
llvm_test_data(harris harris.reference_output)
