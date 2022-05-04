set(RUN_OPTIONS < clinton.pcm)
list(APPEND CFLAGS -Wno-implicit-int)
llvm_multisource(rawcaudio
  rawcaudio.c
  adpcm.c
)
llvm_test_data(rawcaudio SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../data
  clinton.pcm
)
