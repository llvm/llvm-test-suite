set(RUN_OPTIONS < ${CMAKE_CURRENT_SOURCE_DIR}/../data/clinton.pcm )
set(PROG rawcaudio)
set(Source rawcaudio.c adpcm.c)
llvm_multisource()
