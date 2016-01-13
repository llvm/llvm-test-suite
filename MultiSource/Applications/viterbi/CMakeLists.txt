set(DIRS)
set(PARALLEL_DIRS)

set(PROG viterbi)
set(CPPFLAGS -I${CMAKE_CURRENT_SOURCE_DIR} -DPROJ_SRC_DIR=\\"${CMAKE_CURRENT_SOURCE_DIR}\\")
set(LDFLAGS )
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
