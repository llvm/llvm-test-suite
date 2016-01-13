set(DIRS)
set(PARALLEL_DIRS)

set(PROG neural)
set(CPPFLAGS -DVERSION='"1.00"' -DCOMPDATE="\\"today\\"" -DCFLAGS='""' -DHOSTNAME="\\"thishost\\"" )
set(LDFLAGS -lm)
if(DEFINED LARGE_PROBLEM_SIZE)
  set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/ref.in)
else()
  set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/test.in)
endif()
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
