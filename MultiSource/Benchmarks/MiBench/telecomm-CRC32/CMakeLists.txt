set(PROG telecomm-CRC32)
set(LDFLAGS -lm)
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/large.pcm)
llvm_multisource()
