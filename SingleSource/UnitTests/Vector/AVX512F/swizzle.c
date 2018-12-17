
/*
 * Exercise some swizzles, upconverts and downconverts.
 * This test was created to check correctness
 * of the following intrinsics support:
 *      vmovdqa32()
 *      vmovdqa64()
 */

#include "m512_test_util.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(__x86_64) || defined(_M_X64)
/*
 * Exercise encoding zmm registers above zmm15, including one that
 * has the fifth bit set and one that doesn't.
 */
#define bigzmm zmm28
#define mediumzmm zmm20
#else
#define bigzmm zmm7
#define mediumzmm zmm3
#endif

volatile int vi[16] = {0x12345678, 0x87654321, 0x05040302, 0x8594a3b2,
                       0x92745638, 0xa0b0c0d0, 0xd0b0a040, 0x14322341,
                       0xf24bee68, 0x3ed29ff6, 0xa2d46e46, 0x02119d99,
                       0x1289a683, 0x0c4563de, 0x3edfd4a4, 0x49d52d48};

V512 src, dst1, dst2, t0, t1;

static void NOINLINE init() {
  int i;

  for (i = 0; i < 16; i++) {
    src.s32[i] = vi[i];
  }

  memset(&dst1, 0, sizeof(dst1));
  memset(&dst2, 0, sizeof(dst2));
}

void NOINLINE do_mov_32() {
  int i, v;
  void *psrc = &src;
  void *pdst = &dst1;

  init();

  __asm {
        mov       FULL_IREG(cx), [psrc]
        mov       FULL_IREG(dx), [pdst]
        vmovdqa32 bigzmm, [FULL_IREG(cx)]
        vmovdqa32 mediumzmm, bigzmm
        vmovdqu32 [FULL_IREG(dx)], mediumzmm
  }

  for (i = 0; i < 16; i++) {
    v = src.s32[i];
    dst2.s32[i] = v;
  }
  check_equal_nd(&dst1, &dst2, 16, "vmovdqa32", __LINE__);
}

void NOINLINE do_mov_32_masked() {
  int i, k;
  void *psrc = &src;
  void *pdst = &dst1;

  k = 0xaaaa; /* every other bit is set */

  init();

  __asm {
        mov         eax, k
        kmovw       k6, eax
        mov         FULL_IREG(cx), [psrc]
        mov         FULL_IREG(dx), [pdst]
        vzeroall
        vmovdqa32   bigzmm{k6}, [FULL_IREG(cx)] 
        vmovdqa32 mediumzmm { k6 }, bigzmm 
        vmovdqu32[FULL_IREG(dx)]{k6}, mediumzmm
  }

  memset(&t0, 0, sizeof(t0));

  /* Emulate vmovdqa32   bigzmm{k6}, [src] */

  for (i = 0; i < 16; i++) {
    if (k & (1 << i)) {
      dst2.s32[i] = src.u32[i];
    }
  }
  check_equal_nd(&dst1, &dst2, 16, "vmovdqa32 masked", __LINE__);
}

void NOINLINE do_mov_64() {
  int i;
  void *psrc = &src;
  void *pdst = &dst1;

  init();

  __asm {
        mov       FULL_IREG(cx), [psrc]
        mov       FULL_IREG(dx), [pdst]
        vmovdqa64 bigzmm, [FULL_IREG(cx)]
        vmovdqa64 mediumzmm, bigzmm
        vmovdqu64 [FULL_IREG(dx)], mediumzmm
  }

  for (i = 0; i < 8; i++) {
    dst2.u64[i] = src.u64[i];
  }
  check_equal_nq(&dst1, &dst2, 8, "vmovdqa64", __LINE__);
}

void NOINLINE do_mov_64_masked() {
  int i, k;
  void *psrc = &src;
  void *pdst = &dst1;

  k = 0xaa; /* every other bit is set */

  init();

  __asm {
        mov         eax, k
        kmovw       k5, eax
        mov         FULL_IREG(cx), [psrc]
        mov         FULL_IREG(dx), [pdst]
        vzeroall
        vmovdqa64   bigzmm{k5}, [FULL_IREG(cx)] 
        vmovdqa64 mediumzmm { k5 }, bigzmm 
        vmovdqu64[FULL_IREG(dx)]{k5}, mediumzmm
  }

  memset(&t0, 0, sizeof(t0));

  /* emulate vmovdqa64   bigzmm{k5}, [src] */

  for (i = 0; i < 8; i++) {
    if (k & (1 << i)) {
      t0.u64[i] = src.u64[i];
    }
  }

  /* emulate vmovdqa64   mediumzmm{k5}, bigzmm */

  for (i = 0; i < 8; i++) {
    t1.u64[i] = t0.u64[i];
  }

  for (i = 0; i < 8; i++) {
    if (k & (1 << i)) {
      t0.u64[i] = t1.u64[i];
    }
  }

  /* emulate vmovdqu64   [dst1]{k5}, mediumzmm */

  for (i = 0; i < 8; i++) {
    if (k & (1 << i)) {
      dst2.u64[i] = t0.u64[i];
    }
  }
  check_equal_nq(&dst1, &dst2, 8, "vmovdqa64 masked", __LINE__);
}

int main() {
  do_mov_32();
  do_mov_32_masked();
  do_mov_64();
  do_mov_64_masked();
  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }
  printf("PASSED\n");
  return 0;
}
