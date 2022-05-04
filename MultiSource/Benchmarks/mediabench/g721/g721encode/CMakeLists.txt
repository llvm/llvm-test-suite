set(RUN_OPTIONS -4 -l < clinton.pcm)
list(APPEND CFLAGS -Wno-implicit-int)
llvm_multisource(encode
  encode.c
  g711.c
  g721.c
  g723_24.c
  g723_40.c
  g72x.c
)
llvm_test_data(encode SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../data
  clinton.pcm
)
