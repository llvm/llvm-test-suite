set(RUN_OPTIONS < clinton.adpcm)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource(rawdaudio
  rawdaudio.c
  adpcm.c
)
llvm_test_data(rawdaudio SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../data
  clinton.adpcm
)
