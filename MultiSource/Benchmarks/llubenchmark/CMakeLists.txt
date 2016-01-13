set(DIRS)
set(PARALLEL_DIRS)

set(PROG llu)
set(CPPFLAGS )
set(LDFLAGS )
if(DEFINED LARGE_PROBLEM_SIZE)
  set(RUN_OPTIONS -i 6000)
else()
  set(RUN_OPTIONS -i 3000)
endif()
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
