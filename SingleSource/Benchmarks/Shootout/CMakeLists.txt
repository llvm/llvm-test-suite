list(APPEND LDFLAGS -lm)
list(APPEND CPPFLAGS -Wno-error=incompatible-pointer-types)
set(Source
  ackermann.c
  ary3.c
  fib2.c
  hash.c
  heapsort.c
  lists.c
  matrix.c
  methcall.c
  nestedloop.c
  objinst.c
  random.c
  sieve.c
  strcat.c
)
if(NOT TEST_SUITE_BENCHMARKING_ONLY)
  list(APPEND Source hello.c)
endif()
llvm_singlesource(PREFIX Shootout-)
set_property(TARGET Shootout-methcall Shootout-objinst PROPERTY C_STANDARD 17)
