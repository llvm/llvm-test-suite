set(RUN_OPTIONS < ${CMAKE_CURRENT_SOURCE_DIR}/../data/clinton.pcm )
llvm_multisource(rawcaudio
  rawcaudio.c
  adpcm.c
)
