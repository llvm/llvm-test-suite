set(RUN_OPTIONS -b mei16v2.m2v -r -f -o0 tmp%d)
list(APPEND LDFLAGS -lm)
llvm_multisource(mpeg2decode
  display.c
  gethdr.c
  idct.c
  mpeg2dec.c
  store.c
  verify.c
  getbits.c
  getpic.c
  idctref.c
  recon.c
  subspic.c
  getblk.c
  getvlc.c
  motion.c
  spatscal.c
  systems.c
)
llvm_test_data(mpeg2decode SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../data
  mei16v2.m2v
)
