set(DIRS)
set(PARALLEL_DIRS)

set(PROG frame_layout)
set(LDFLAGS )
list(APPEND CPPFLAGS -std=c++11)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
