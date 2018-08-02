set(OBJS scan.o util.o main.o number.o storage.o load.o execute.o bc.o global.o)
set(RUN_OPTIONS < ${CMAKE_CURRENT_SOURCE_DIR}/primes.b)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource(bc)
