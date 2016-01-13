set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS adpcm g721 gsm jpeg mpeg2)

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
