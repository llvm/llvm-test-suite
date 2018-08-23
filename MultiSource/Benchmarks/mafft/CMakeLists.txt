list(APPEND CPPFLAGS -DLLVM)
list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS -b 62 -g 0.100 -f 2.00 -h 0.100 -L < pyruvate_decarboxylase.fasta)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource(pairlocalalign
  Calignm1.c
  constants.c
  defs.c
  Falign.c
  fft.c
  fftFunctions.c
  Galign11.c
  genalign11.c
  genGalign11.c
  Halignmm.c
  io.c
  Lalign11.c
  Lalignmm.c
  mltaln9.c
  MSalign11.c
  MSalignmm.c
  mtxutl.c
  pairlocalalign.c
  partQalignmm.c
  partSalignmm.c
  Qalignmm.c
  Ralignmm.c
  rna.c
  SAalignmm.c
  Salignmm.c
  suboptalign11.c
  tddis.c
)
llvm_test_data(pairlocalalign pyruvate_decarboxylase.fasta)
