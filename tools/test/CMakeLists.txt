# Copy these files to the build directory so that the tests can be run even
# without the source directory.
configure_file(test_not.sh test_not.sh
  @ONLY)

add_executable(ret1 ret1.c)
llvm_test_run(EXECUTABLE "%b/not" "%b/test/ret1")
llvm_add_test_for_target(ret1)

add_executable(ret0 ret0.c)
llvm_test_run(EXECUTABLE "%b/not" "%b/not" "%b/test/ret0")
llvm_add_test_for_target(ret0)

# Check that expected crashes are handled correctly.
add_executable(abrt abort.c)
llvm_test_run(EXECUTABLE "%b/not" "--crash" "%b/test/abrt")
llvm_add_test_for_target(abrt)

# Check that not passes environment variables to the called executable.
add_executable(check_env check_env.c)
llvm_test_run(EXECUTABLE "/bin/bash" "%b/test/test_not.sh %b")
llvm_add_test(test_not.test test_not.sh)
