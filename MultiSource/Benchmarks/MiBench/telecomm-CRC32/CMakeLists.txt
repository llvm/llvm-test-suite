list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/large.pcm)
llvm_multisource(telecomm-CRC32)
