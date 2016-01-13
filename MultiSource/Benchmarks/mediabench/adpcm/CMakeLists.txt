set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS rawcaudio rawdaudio)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
