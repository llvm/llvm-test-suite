set(DIRS)
set(PARALLEL_DIRS)

set(PROG mst)
set(CPPFLAGS -DTORONTO)
set(LDFLAGS )
if(DEFINED LARGE_PROBLEM_SIZE)
  set(RUN_OPTIONS 4000)
else()
  set(RUN_OPTIONS 1000)
endif()
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
