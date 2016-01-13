set(DIRS)
set(PARALLEL_DIRS)

set(PROG agrep)
set(RUN_OPTIONS -2 int ${CMAKE_CURRENT_SOURCE_DIR}/InstructionCombining.cpp.txt)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
