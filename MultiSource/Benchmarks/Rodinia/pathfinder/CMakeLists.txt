set(PROG pathfinder)
list(APPEND CFLAGS -I${CMAKE_CURRENT_SOURCE_DIR}/../Common/)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource(pathfinder 
  main.c 
  pathfinderKernel.c 
  ../Common/glibc_compat_rand.c
)
