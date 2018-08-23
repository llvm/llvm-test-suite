if(ENDIAN STREQUAL "little")
  list(APPEND CFLAGS -DTARGET_RT_LITTLE_ENDIAN=1)
  list(APPEND CXXFLAGS -DTARGET_RT_LITTLE_ENDIAN=1)
else()
  list(APPEND CFLAGS -DTARGET_RT_BIG_ENDIAN=1)
  list(APPEND CXXFLAGS -DTARGET_RT_BIG_ENDIAN=1)
endif()
list(APPEND LDFLAGS -lstdc++)
set(RUN_OPTIONS - - < tune.caf)
llvm_multisource(alacconvert-decode
  EndianPortable.c
  ALACBitUtilities.c
  ALACDecoder.cpp
  ALACEncoder.cpp
  ag_dec.c
  ag_enc.c
  dp_dec.c
  dp_enc.c
  matrix_dec.c
  matrix_enc.c
  main.cpp
  CAFFileALAC.cpp
)
llvm_test_data(alacconvert-decode tune.caf)
