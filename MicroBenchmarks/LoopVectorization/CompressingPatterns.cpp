/* ============= Benchmark setup ============= */

#define ITERATIONS 100000

#include "./LoopBenchHelper.h"

#define DEF_COMPRESS_LOOP(name, paramTys, args, init, loop, ret)                    \
  DEF_LOOP_BENCH(name, paramTys, args, init, loop, ret)

#define DEF_SIMPLE_COMPRESS(name, loop, ret)                                        \
  DEF_COMPRESS_LOOP(                                                           \
      name, /*arrayTys=*/(T *, T *, T *), /*params=*/                          \
      (T *__restrict__ Src, T *__restrict__ Dst, T *__restrict__ Cmp),         \
      INIT_BLOCK(uint64_t Idx = 0;), loop, ret);

/* ============= Define Benchmarks ============= */

DEF_SIMPLE_COMPRESS(compress_patterns_single_compress,
                    (for (unsigned i = 0; i < ITERATIONS; ++i) {
                      if (Cmp[i])
                        Dst[Idx++] = Src[i];
                    }), RET_VOID);

DEF_SIMPLE_COMPRESS(compress_patterns_single_expand,
                    (for (unsigned i = 0; i < ITERATIONS; ++i) {
                      if (Cmp[i])
                        Dst[i] = Src[Idx++];
                    }), RET_VOID);

DEF_COMPRESS_LOOP(compress_patterns_nested_compress,
                  /*arrayTys=*/(T *, T *, T *, T *),
                  /*params=*/
                  (T *__restrict__ Src, T *__restrict__ Dst,
                   T *__restrict__ CmpA, T *__restrict__ CmpB),
                  INIT_BLOCK(uint64_t Idx = 0;),
                  (for (unsigned i = 0; i < ITERATIONS; ++i) {
                    if (CmpA[i])
                      if (CmpB[i])
                        Dst[Idx++] = Src[i];
                  }), RET_VOID);

DEF_COMPRESS_LOOP(compress_patterns_multiple_conditional_inductions,
                  /*arrayTys=*/(T *, T *, T *, T *, T *),
                  /*params=*/
                  (T *__restrict__ Src, T *__restrict__ DstA,
                   T *__restrict__ DstB, T *__restrict__ CmpA,
                   T *__restrict__ CmpB),
                  INIT_BLOCK(uint64_t IdxA = 0; uint64_t IdxB = 0;),
                  (for (unsigned i = 0; i < ITERATIONS; ++i) {
                    if (CmpA[i])
                      DstA[IdxA++] = Src[i];
                    if (CmpB[i])
                      DstB[IdxB++] = Src[i];
                  }), RET_VOID);

DEF_COMPRESS_LOOP(compress_patterns_compress_and_expand_many,
                  /*arrayTys=*/(T *, T *, T *, T *, T *, T *),
                  /*params=*/
                  (T *__restrict__ dst0, T *__restrict__ dst1,
                   const T *__restrict__ src0, const T *__restrict__ src1,
                   const T *__restrict__ aux, const T *__restrict__ cond),
                  INIT_BLOCK(uint64_t idx = 0;),
                  (for (int i = 0; i < ITERATIONS; i++) {
                    if (cond[i]) {
                      T x = src0[i];  // masked load
                      T y = src1[i];  // masked load
                      T z = aux[idx]; // expand load

                      x = x + z;
                      y = y - z;

                      dst0[idx] = x; // compress store
                      dst1[idx] = y; // compress store

                      idx++;
                    }
                  }), RET_VOID);

DEF_SIMPLE_COMPRESS(compress_patterns_compress_liveout,
               (for (unsigned i = 0; i < ITERATIONS; ++i) {
                 if (Cmp[i])
                   Dst[Idx++] = Src[i];
               }),
               ({ return Idx; }));

#define ADD_BENCHMARK(ty)                                                      \
  BENCHMARK_CASE(compress_patterns_single_compress, ty);                       \
  BENCHMARK_CASE(compress_patterns_single_expand, ty);                         \
  BENCHMARK_CASE(compress_patterns_nested_compress, ty);                       \
  BENCHMARK_CASE(compress_patterns_multiple_conditional_inductions, ty);       \
  BENCHMARK_CASE(compress_patterns_compress_and_expand_many, ty);              \
  BENCHMARK_CASE(compress_patterns_compress_liveout, ty);

ADD_BENCHMARK(uint8_t);
ADD_BENCHMARK(uint16_t);
ADD_BENCHMARK(int32_t);
ADD_BENCHMARK(int64_t);
ADD_BENCHMARK(float);
ADD_BENCHMARK(double);
