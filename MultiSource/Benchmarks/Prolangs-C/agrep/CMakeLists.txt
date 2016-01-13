set(PROG agrep)
set(RUN_OPTIONS -2 int ${CMAKE_CURRENT_SOURCE_DIR}/InstructionCombining.cpp.txt)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource()
