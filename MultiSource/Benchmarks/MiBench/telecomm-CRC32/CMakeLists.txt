list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS large.pcm)
llvm_multisource(telecomm-CRC32)
llvm_test_data(telecomm-CRC32 large.pcm)
