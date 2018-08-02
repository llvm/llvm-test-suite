list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS < ${CMAKE_CURRENT_SOURCE_DIR}/large.adpcm)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource(telecomm-adpcm)
