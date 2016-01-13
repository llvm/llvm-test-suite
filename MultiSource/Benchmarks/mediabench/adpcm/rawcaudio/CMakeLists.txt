set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../../..)
set(STDIN_FILENAME ${CMAKE_CURRENT_SOURCE_DIR}/../data/clinton.pcm )
set(PROG rawcaudio)
set(Source rawcaudio.c adpcm.c)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
