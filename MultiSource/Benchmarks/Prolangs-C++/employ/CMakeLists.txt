list(APPEND LDFLAGS -lstdc++)
set(RUN_OPTIONS 400 < ${CMAKE_CURRENT_SOURCE_DIR}/input.txt)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource(employ)
