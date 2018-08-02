set(RUN_OPTIONS < ${CMAKE_CURRENT_SOURCE_DIR}/../data/clinton.adpcm )
set(HASH_PROGRAM_OUTPUT 1)
set(Source rawdaudio.c adpcm.c)
llvm_multisource(rawdaudio)
