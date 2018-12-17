/*
 * Here we check for punpck* and unpck* intrinsics using masm.
 */

#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>

int verbose = 0;

__m512i i1;
__m512i i2;
__m512i i3;
__m512i i4;
__m512i i5;

volatile int vol = 0; /* To prevent optimizations */

void NOINLINE display_xmm_pi(const void *p, const char *banner) {
  int i;
  V512 *v = (V512 *)p;

  if (banner) {
    printf("%s", banner);
  }

  for (i = 0; i < 4; i++) {
    printf(" 0x%0.8x", v->s32[3 - i]);
  }
  printf("\n");
}

void NOINLINE init() {
  int i;
  V512 *pi1 = (V512 *)&i1;
  V512 *pi2 = (V512 *)&i2;
  V512 *pi3 = (V512 *)&i3;

  for (i = 0; i < 64; i++) {
    pi1->u8[i] = 17 + ((i & 1) ? 1 : -1) * i + vol;

    pi2->u8[i] = 100 + ((i & 3) == 3 ? 1 : -1) * i + vol;

    pi3->u8[i] = 400 + ((i & 1) ? -1 : 1) * i + vol;
  }
}

#define check_equal_xmm(vgot, vexpected, banner)                               \
  check_equal_nd(vgot, vexpected, 4, banner, __LINE__)
#define check_equal_ymm(vgot, vexpected, banner)                               \
  check_equal_nd(vgot, vexpected, 8, banner, __LINE__)
#define check_equal_zmm(vgot, vexpected, banner)                               \
  check_equal_nd(vgot, vexpected, 16, banner, __LINE__)

void NOINLINE emulate_palignr(void *presult, const void *p1, const void *p2,
                              int shift, int num_lanes) {
  int i, lane;
  V512 *result = (V512 *)presult;
  V512 *v1 = (V512 *)p1;
  V512 *v2 = (V512 *)p2;

  if (shift < 0 || shift > 31) {
    /* Result is zero. */
    for (lane = 0; lane < num_lanes; lane++) {
      for (i = 0; i < 4; i++) {
        result->u32[4 * lane + i] = 0;
      }
    }

    return;
  }

  for (lane = 0; lane < num_lanes; lane++) {
    for (i = 0; i < (16 - shift); i++) {
      result->u8[16 * lane + i] = v2->u8[16 * lane + i + shift];
    }
    for (; i < 16 && (i + shift < 32); i++) {
      result->u8[16 * lane + i] = v1->u8[16 * lane + i - (16 - shift)];
    }
    for (; i < 16; i++) {
      result->u8[16 * lane + i] = 0;
    }
  }
}

void NOINLINE emulate_punpck_bw(void *presult, const void *p1, const void *p2,
                                int num_lanes, int high) {
  int i, lane;
  V512 *result = (V512 *)presult;
  V512 *v1 = (V512 *)p1;
  V512 *v2 = (V512 *)p2;
  int offset = high ? 8 : 0;

  for (lane = 0; lane < num_lanes; lane++) {
    for (i = 0; i < 8; i++) {
      result->u8[16 * lane + 2 * i] = v1->u8[16 * lane + i + offset];
      result->u8[16 * lane + 2 * i + 1] = v2->u8[16 * lane + i + offset];
    }
  }
}

#define emulate_punpckhbw(presult, p1, p2, num_lanes)                          \
  emulate_punpck_bw(presult, p1, p2, num_lanes, 1)
#define emulate_punpcklbw(presult, p1, p2, num_lanes)                          \
  emulate_punpck_bw(presult, p1, p2, num_lanes, 0)

void NOINLINE emulate_punpck_wd(void *presult, const void *p1, const void *p2,
                                int num_lanes, int high) {
  int i, lane;
  V512 *result = (V512 *)presult;
  V512 *v1 = (V512 *)p1;
  V512 *v2 = (V512 *)p2;
  int offset = high ? 4 : 0;

  for (lane = 0; lane < num_lanes; lane++) {
    for (i = 0; i < 8; i++) {
      result->u16[8 * lane + 2 * i] = v1->u16[8 * lane + i + offset];
      result->u16[8 * lane + 2 * i + 1] = v2->u16[8 * lane + i + offset];
    }
  }
}

#define emulate_punpckhwd(presult, p1, p2, num_lanes)                          \
  emulate_punpck_wd(presult, p1, p2, num_lanes, 1)
#define emulate_punpcklwd(presult, p1, p2, num_lanes)                          \
  emulate_punpck_wd(presult, p1, p2, num_lanes, 0)

void NOINLINE emulate_punpck_dq(void *presult, const void *p1, const void *p2,
                                int num_lanes, int high) {
  int i, lane;
  V512 *result = (V512 *)presult;
  V512 *v1 = (V512 *)p1;
  V512 *v2 = (V512 *)p2;
  int offset = high ? 2 : 0;

  for (lane = 0; lane < num_lanes; lane++) {
    for (i = 0; i < 4; i++) {
      result->u32[4 * lane + 2 * i] = v1->u32[4 * lane + i + offset];
      result->u32[4 * lane + 2 * i + 1] = v2->u32[4 * lane + i + offset];
    }
  }
}

#define emulate_punpckhdq(presult, p1, p2, num_lanes)                          \
  emulate_punpck_dq(presult, p1, p2, num_lanes, 1)
#define emulate_punpckldq(presult, p1, p2, num_lanes)                          \
  emulate_punpck_dq(presult, p1, p2, num_lanes, 0)

void NOINLINE emulate_punpck_qdq(void *presult, const void *p1, const void *p2,
                                 int num_lanes, int high) {
  int i, lane;
  V512 *result = (V512 *)presult;
  V512 *v1 = (V512 *)p1;
  V512 *v2 = (V512 *)p2;
  int offset = high ? 1 : 0;

  for (lane = 0; lane < num_lanes; lane++) {
    for (i = 0; i < 2; i++) {
      result->u64[2 * lane + 2 * i] = v1->u64[2 * lane + i + offset];
      result->u64[2 * lane + 2 * i + 1] = v2->u64[2 * lane + i + offset];
    }
  }
}

#define emulate_punpckhqdq(presult, p1, p2, num_lanes)                         \
  emulate_punpck_qdq(presult, p1, p2, num_lanes, 1)
#define emulate_punpcklqdq(presult, p1, p2, num_lanes)                         \
  emulate_punpck_qdq(presult, p1, p2, num_lanes, 0)

void NOINLINE do_punpck_bw() {
  void *p1 = &i1;
  void *p2 = &i2;
  void *p3 = &i3;

#define DO_XMM_REG_REG(opcode, reg1, reg2)                                     \
  __asm {\
        __asm mov         FULL_IREG(ax), [p1] \
        __asm movaps      reg2, [FULL_IREG(ax)] \
        __asm mov         FULL_IREG(ax), [p2] \
        __asm movaps      reg1, [FULL_IREG(ax)] \
        __asm opcode      reg1, reg2 \
        __asm mov         FULL_IREG(ax), [p3] \
        __asm movaps      [FULL_IREG(ax)], reg1                                                                     \
  }

#define DO_V_REG_REG_REG(opcode, reg1, reg2, reg3)                             \
  __asm { \
        __asm mov         FULL_IREG(ax), [p1] \
        __asm vmovaps     reg3, [FULL_IREG(ax)] \
        __asm mov         FULL_IREG(ax), [p2] \
        __asm vmovaps     reg2, [FULL_IREG(ax)] \
        __asm opcode      reg1, reg2, reg3 \
        __asm mov         FULL_IREG(ax), [p3] \
        __asm vmovaps     [FULL_IREG(ax)], reg1}

  DO_XMM_REG_REG(punpckhbw, xmm6, xmm3)
  emulate_punpckhbw(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "punpckhbw xmm6, xmm3");
  if (verbose) {
    printf("punpckhbw(i2, i1)\n");
    display_xmm_pi(&i1, "i1:  ");
    display_xmm_pi(&i2, "i2:  ");
    display_xmm_pi(&i3, "got: ");
    display_xmm_pi(&i4, "exp: ");
  }

  DO_XMM_REG_REG(punpcklbw, xmm2, xmm7)
  emulate_punpcklbw(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "punpckhbw xmm2, xmm7");

  DO_V_REG_REG_REG(vpunpckhbw, xmm1, xmm6, xmm5)
  emulate_punpckhbw(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "vpunpckhbw xmm1, xmm6, xmm5");

  DO_V_REG_REG_REG(vpunpckhbw, ymm4, ymm7, ymm5)
  emulate_punpckhbw(&i4, &i2, &i1, 2);
  check_equal_ymm(&i4, &i3, "vpunpckhbw ymm4, ymm7, ymm5");

  DO_V_REG_REG_REG(vpunpcklbw, ymm7, ymm3, ymm1)
  emulate_punpcklbw(&i4, &i2, &i1, 2);
  check_equal_ymm(&i4, &i3, "vpunpcklbw ymm7, ymm3, ymm1");

  DO_V_REG_REG_REG(vpunpckhbw, zmm4, zmm7, zmm5)
  emulate_punpckhbw(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhbw zmm4, zmm4, zmm5");

  DO_V_REG_REG_REG(vpunpcklbw, zmm7, zmm3, zmm1)
  emulate_punpcklbw(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpcklbw zmm7, zmm3, zmm1");

#if defined(__x86_64) || defined(_M_X64)

  DO_V_REG_REG_REG(vpunpckhbw, xmm19, xmm6, xmm5)
  emulate_punpckhbw(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "vpunpckhbw xmm19, xmm6, xmm5");

  DO_V_REG_REG_REG(vpunpckhbw, xmm6, xmm19, xmm5)
  emulate_punpckhbw(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "vpunpckhbw xmm6, xmm19, xmm5");

  DO_V_REG_REG_REG(vpunpckhbw, xmm6, xmm5, xmm19)
  emulate_punpckhbw(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "vpunpckhbw xmm6, xmm5, xmm19");

  DO_V_REG_REG_REG(vpunpckhbw, zmm19, zmm6, zmm5)
  emulate_punpckhbw(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhbw zmm19, zmm6, zmm5");

  DO_V_REG_REG_REG(vpunpckhbw, zmm6, zmm19, zmm5)
  emulate_punpckhbw(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhbw zmm6, zmm19, zmm5");

  DO_V_REG_REG_REG(vpunpckhbw, zmm6, zmm5, zmm19)
  emulate_punpckhbw(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhbw zmm6, zmm5, zmm19");

#endif /* defined(__x86_64) || defined(_M_X64) */
}

void NOINLINE do_punpck_wd() {
  void *p1 = &i1;
  void *p2 = &i2;
  void *p3 = &i3;

  DO_XMM_REG_REG(punpckhwd, xmm6, xmm3)
  emulate_punpckhwd(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "punpckhwd xmm6, xmm3");
  if (verbose) {
    printf("punpckhwd(i2, i1)\n");
    display_xmm_pi(&i1, "i1:  ");
    display_xmm_pi(&i2, "i2:  ");
    display_xmm_pi(&i3, "got: ");
    display_xmm_pi(&i4, "exp: ");
  }

  DO_XMM_REG_REG(punpcklwd, xmm2, xmm7)
  emulate_punpcklwd(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "punpckhwd xmm2, xmm7");

  DO_V_REG_REG_REG(vpunpckhwd, xmm1, xmm6, xmm5)
  emulate_punpckhwd(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "vpunpckhwd xmm1, xmm6, xmm5");

  DO_V_REG_REG_REG(vpunpckhwd, ymm4, ymm7, ymm5)
  emulate_punpckhwd(&i4, &i2, &i1, 2);
  check_equal_ymm(&i4, &i3, "vpunpckhwd ymm4, ymm7, ymm5");

  DO_V_REG_REG_REG(vpunpcklwd, ymm7, ymm3, ymm1)
  emulate_punpcklwd(&i4, &i2, &i1, 2);
  check_equal_ymm(&i4, &i3, "vpunpcklwd ymm7, ymm3, ymm1");

  DO_V_REG_REG_REG(vpunpckhwd, zmm4, zmm7, zmm5)
  emulate_punpckhwd(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhwd zmm4, zmm4, zmm5");

  DO_V_REG_REG_REG(vpunpcklwd, zmm7, zmm3, zmm1)
  emulate_punpcklwd(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpcklwd zmm7, zmm3, zmm1");

#if defined(__x86_64) || defined(_M_X64)

  DO_V_REG_REG_REG(vpunpckhwd, ymm19, ymm6, ymm5)
  emulate_punpckhwd(&i4, &i2, &i1, 2);
  check_equal_ymm(&i4, &i3, "vpunpckhwd ymm19, ymm6, ymm5");

  DO_V_REG_REG_REG(vpunpckhwd, ymm6, ymm19, ymm5)
  emulate_punpckhwd(&i4, &i2, &i1, 2);
  check_equal_ymm(&i4, &i3, "vpunpckhwd ymm6, ymm19, ymm5");

  DO_V_REG_REG_REG(vpunpckhwd, ymm6, ymm5, ymm19)
  emulate_punpckhwd(&i4, &i2, &i1, 2);
  check_equal_ymm(&i4, &i3, "vpunpckhwd ymm6, ymm5, ymm19");

  DO_V_REG_REG_REG(vpunpckhwd, zmm19, zmm6, zmm5)
  emulate_punpckhwd(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhwd zmm19, zmm6, zmm5");

  DO_V_REG_REG_REG(vpunpckhwd, zmm6, zmm19, zmm5)
  emulate_punpckhwd(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhwd zmm6, zmm19, zmm5");

  DO_V_REG_REG_REG(vpunpckhwd, zmm6, zmm5, zmm19)
  emulate_punpckhwd(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhwd zmm6, zmm5, zmm19");

  DO_V_REG_REG_REG(vpunpckhwd, zmm26, zmm6, zmm5)
  emulate_punpckhwd(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhwd zmm26, zmm6, zmm5");

  DO_V_REG_REG_REG(vpunpckhwd, zmm6, zmm26, zmm5)
  emulate_punpckhwd(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhwd zmm6, zmm26, zmm5");

  DO_V_REG_REG_REG(vpunpckhwd, zmm6, zmm5, zmm26)
  emulate_punpckhwd(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhwd zmm6, zmm5, zmm26");

#endif /* defined(__x86_64) || defined(_M_X64) */
}

#define DO_Z_REG_MASK_REG_REG(opcode, reg1, kreg, reg2, reg3)                  \
  __asm { \
        __asm mov         FULL_IREG(ax), [p1] \
        __asm vmovaps     reg3, [FULL_IREG(ax)] \
        __asm mov         FULL_IREG(ax), [p2] \
        __asm vmovaps     reg2, [FULL_IREG(ax)] \
        __asm kxnorw      kreg, kreg, kreg \
        __asm opcode      reg1{kreg} \
  , reg2, reg3 __asm mov FULL_IREG(ax), [p3] __asm vmovaps[FULL_IREG(ax)],     \
      reg1                                                                     \
  }

void NOINLINE do_punpck_dq() {
  void *p1 = &i1;
  void *p2 = &i2;
  void *p3 = &i3;

  DO_XMM_REG_REG(punpckhdq, xmm6, xmm3)
  emulate_punpckhdq(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "punpckhdq xmm6, xmm3");
  if (verbose) {
    printf("punpckhdq(i2, i1)\n");
    display_xmm_pi(&i1, "i1:  ");
    display_xmm_pi(&i2, "i2:  ");
    display_xmm_pi(&i3, "got: ");
    display_xmm_pi(&i4, "exp: ");
  }

  DO_XMM_REG_REG(punpckldq, xmm2, xmm7)
  emulate_punpckldq(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "punpckhdq xmm2, xmm7");

  DO_V_REG_REG_REG(vpunpckhdq, xmm1, xmm6, xmm5)
  emulate_punpckhdq(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "vpunpckhdq xmm1, xmm6, xmm5");

  DO_V_REG_REG_REG(vpunpckhdq, ymm4, ymm7, ymm5)
  emulate_punpckhdq(&i4, &i2, &i1, 2);
  check_equal_ymm(&i4, &i3, "vpunpckhdq ymm4, ymm7, ymm5");

  DO_V_REG_REG_REG(vpunpckldq, ymm7, ymm3, ymm1)
  emulate_punpckldq(&i4, &i2, &i1, 2);
  check_equal_ymm(&i4, &i3, "vpunpckldq ymm7, ymm3, ymm1");

  DO_V_REG_REG_REG(vpunpckhdq, zmm4, zmm7, zmm5)
  emulate_punpckhdq(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhdq zmm4, zmm4, zmm5");

  DO_V_REG_REG_REG(vpunpckldq, zmm7, zmm3, zmm1)
  emulate_punpckldq(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckldq zmm7, zmm3, zmm1");

#if defined(__x86_64) || defined(_M_X64)

  DO_V_REG_REG_REG(vpunpckhdq, xmm23, xmm7, xmm5)
  emulate_punpckhdq(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "vpunpckhdq xmm23, xmm7, xmm5");

  DO_V_REG_REG_REG(vpunpckhdq, xmm7, xmm23, xmm5)
  emulate_punpckhdq(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "vpunpckhdq xmm7, xmm23, xmm5");

  DO_V_REG_REG_REG(vpunpckhdq, xmm7, xmm5, xmm23)
  emulate_punpckhdq(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "vpunpckhdq xmm7, xmm5, xmm23");

  DO_V_REG_REG_REG(vpunpckhdq, ymm23, ymm16, ymm5)
  emulate_punpckhdq(&i4, &i2, &i1, 2);
  check_equal_ymm(&i4, &i3, "vpunpckhdq ymm23, ymm16, ymm5");

  DO_V_REG_REG_REG(vpunpckhdq, zmm23, zmm7, zmm5)
  emulate_punpckhdq(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhdq zmm23, zmm7, zmm5");

  DO_V_REG_REG_REG(vpunpckhdq, zmm7, zmm23, zmm5)
  emulate_punpckhdq(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhdq zmm7, zmm23, zmm5");

  DO_V_REG_REG_REG(vpunpckhdq, zmm7, zmm5, zmm23)
  emulate_punpckhdq(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhdq zmm7, zmm5, zmm23");

  DO_Z_REG_MASK_REG_REG(vpunpckhdq, zmm23, k4, zmm7, zmm5)
  emulate_punpckhdq(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhdq zmm23{k4}, zmm7, zmm5");

#endif /* defined(__x86_64) || defined(_M_X64) */
}

void NOINLINE do_punpck_qdq() {
  void *p1 = &i1;
  void *p2 = &i2;
  void *p3 = &i3;

  DO_XMM_REG_REG(punpckhqdq, xmm6, xmm3)
  emulate_punpckhqdq(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "punpckhqdq xmm6, xmm3");
  if (verbose) {
    printf("punpckhqdq(i2, i1)\n");
    display_xmm_pi(&i1, "i1:  ");
    display_xmm_pi(&i2, "i2:  ");
    display_xmm_pi(&i3, "got: ");
    display_xmm_pi(&i4, "exp: ");
  }

  DO_XMM_REG_REG(punpcklqdq, xmm2, xmm7)
  emulate_punpcklqdq(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "punpckhqdq xmm2, xmm7");

  DO_V_REG_REG_REG(vpunpckhqdq, xmm1, xmm6, xmm5)
  emulate_punpckhqdq(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "vpunpckhqdq xmm1, xmm6, xmm5");

  DO_V_REG_REG_REG(vpunpckhqdq, ymm4, ymm7, ymm5)
  emulate_punpckhqdq(&i4, &i2, &i1, 2);
  check_equal_ymm(&i4, &i3, "vpunpckhqdq ymm4, ymm7, ymm5");

  DO_V_REG_REG_REG(vpunpcklqdq, ymm7, ymm3, ymm1)
  emulate_punpcklqdq(&i4, &i2, &i1, 2);
  check_equal_ymm(&i4, &i3, "vpunpcklqdq ymm7, ymm3, ymm1");

  DO_V_REG_REG_REG(vpunpckhqdq, zmm4, zmm7, zmm5)
  emulate_punpckhqdq(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpckhqdq zmm4, zmm4, zmm5");

  DO_V_REG_REG_REG(vpunpcklqdq, zmm7, zmm3, zmm1)
  emulate_punpcklqdq(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpcklqdq zmm7, zmm3, zmm1");

#if defined(__x86_64) || defined(_M_X64)

  DO_Z_REG_MASK_REG_REG(vpunpcklqdq, zmm31, k6, zmm29, zmm27)
  emulate_punpcklqdq(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vpunpcklqdq zmm31{k6}, zmm29, zmm27");

#endif /* defined(__x86_64) || defined(_M_X64) */
}

void NOINLINE do_punpck_ps() {
  void *p1 = &i1;
  void *p2 = &i2;
  void *p3 = &i3;

  DO_XMM_REG_REG(unpckhps, xmm6, xmm3)
  emulate_punpckhdq(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "unpckhps xmm6, xmm3");
  if (verbose) {
    printf("unpckhps(i2, i1)\n");
    display_xmm_pi(&i1, "i1:  ");
    display_xmm_pi(&i2, "i2:  ");
    display_xmm_pi(&i3, "got: ");
    display_xmm_pi(&i4, "exp: ");
  }

  DO_XMM_REG_REG(unpcklps, xmm2, xmm7)
  emulate_punpckldq(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "unpckhps xmm2, xmm7");

  DO_V_REG_REG_REG(vunpckhps, xmm1, xmm6, xmm5)
  emulate_punpckhdq(&i4, &i2, &i1, 1);
  check_equal_xmm(&i4, &i3, "vunpckhps xmm1, xmm6, xmm5");

  DO_V_REG_REG_REG(vunpckhps, ymm4, ymm7, ymm5)
  emulate_punpckhdq(&i4, &i2, &i1, 2);
  check_equal_ymm(&i4, &i3, "vunpckhps ymm4, ymm7, ymm5");

  DO_V_REG_REG_REG(vunpcklps, ymm7, ymm3, ymm1)
  emulate_punpckldq(&i4, &i2, &i1, 2);
  check_equal_ymm(&i4, &i3, "vunpcklps ymm7, ymm3, ymm1");

  DO_V_REG_REG_REG(vunpckhps, zmm4, zmm7, zmm5)
  emulate_punpckhdq(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vunpckhps zmm4, zmm4, zmm5");

  DO_V_REG_REG_REG(vunpcklps, zmm7, zmm3, zmm1)
  emulate_punpckldq(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vunpcklps zmm7, zmm3, zmm1");

#if defined(__x86_64) || defined(_M_X64)

  DO_Z_REG_MASK_REG_REG(vunpcklps, zmm30, k5, zmm28, zmm26)
  emulate_punpckldq(&i4, &i2, &i1, 4);
  check_equal_zmm(&i4, &i3, "vunpcklps zmm30{k5}, zmm28, zmm26");

#endif /* defined(__x86_64) || defined(_M_X64) */
}

void NOINLINE do_palignr() {
  void *p1 = &i1;
  void *p2 = &i2;
  void *p3 = &i3;

#define DO_XMM_REG_REG_IMM(opcode, reg1, reg2, imm)                            \
  __asm {\
        __asm mov         FULL_IREG(ax), [p1] \
        __asm movaps      reg2, [FULL_IREG(ax)] \
        __asm mov         FULL_IREG(ax), [p2] \
        __asm movaps      reg1, [FULL_IREG(ax)] \
        __asm opcode      reg1, reg2, imm \
        __asm mov         FULL_IREG(ax), [p3] \
        __asm movaps      [FULL_IREG(ax)], reg1                                                                     \
  }

#define DO_V_REG_REG_REG_IMM(opcode, reg1, reg2, reg3, imm)                    \
  __asm { \
        __asm mov         FULL_IREG(ax), [p1] \
        __asm vmovaps     reg3, [FULL_IREG(ax)] \
        __asm mov         FULL_IREG(ax), [p2] \
        __asm vmovaps     reg2, [FULL_IREG(ax)] \
        __asm opcode      reg1, reg2, reg3, imm \
        __asm mov         FULL_IREG(ax), [p3] \
        __asm vmovaps     [FULL_IREG(ax)], reg1}

  DO_XMM_REG_REG_IMM(palignr, xmm6, xmm3, 19)
  emulate_palignr(&i4, &i2, &i1, 19, 1);
  check_equal_xmm(&i4, &i3, "palignr xmm6, xmm3, 19");
  if (verbose) {
    printf("palignr(i2, i1)\n");
    display_xmm_pi(&i1, "i1:  ");
    display_xmm_pi(&i2, "i2:  ");
    display_xmm_pi(&i3, "got: ");
    display_xmm_pi(&i4, "exp: ");
  }

  DO_V_REG_REG_REG_IMM(vpalignr, xmm6, xmm7, xmm3, 19)
  emulate_palignr(&i4, &i2, &i1, 19, 1);
  check_equal_xmm(&i4, &i3, "palignr xmm6, xmm7, xmm3, 19");

  DO_V_REG_REG_REG_IMM(vpalignr, ymm6, ymm7, ymm3, 19)
  emulate_palignr(&i4, &i2, &i1, 19, 2);
  check_equal_ymm(&i4, &i3, "palignr ymm6, ymm7, ymm3, 19");

  DO_V_REG_REG_REG_IMM(vpalignr, zmm4, zmm7, zmm5, 12)
  emulate_palignr(&i4, &i2, &i1, 12, 4);
  check_equal_zmm(&i4, &i3, "vpalignr zmm4, zmm4, zmm5, 12");

#if defined(__x86_64) || defined(_M_X64)

  DO_V_REG_REG_REG_IMM(vpalignr, ymm27, ymm5, ymm3, 18)
  emulate_palignr(&i4, &i2, &i1, 18, 4);
  check_equal_ymm(&i4, &i3, "vpalignr ymm27, ymm5, ymm3, 18");

  DO_V_REG_REG_REG_IMM(vpalignr, zmm3, zmm5, zmm27, 9)
  emulate_palignr(&i4, &i2, &i1, 9, 4);
  check_equal_zmm(&i4, &i3, "vpalignr zmm3, zmm5, zmm27, 9");

  DO_V_REG_REG_REG_IMM(vpalignr, zmm27, zmm5, zmm3, 22)
  emulate_palignr(&i4, &i2, &i1, 22, 4);
  check_equal_zmm(&i4, &i3, "vpalignr zmm27, zmm5, zmm3, 22");

  DO_V_REG_REG_REG_IMM(vpalignr, zmm5, zmm27, zmm3, 13)
  emulate_palignr(&i4, &i2, &i1, 13, 4);
  check_equal_zmm(&i4, &i3, "vpalignr zmm5, zmm27, zmm3, 13");

#endif /* defined(__x86_64) || defined(_M_X64) */

  i3 = _mm512_alignr_epi8(i2, i1, 6);
  emulate_palignr(&i4, &i2, &i1, 6, 4);
  check_equal_zmm(&i4, &i3, "_mm512_alignr_epi8");
}

void NOINLINE compare_reg_reg_vs_reg_mem() {
  /* Check that zmm-memory operand forms are parsed and encoded properly. */

  void *p1 = &i1;
  void *p2 = &i2;
  void *p3 = &i3;
  void *p4 = &i4;
  void *p5 = &i5;

  __asm {
        __asm mov         FULL_IREG(ax), [p1]
        __asm vmovaps     zmm1, [FULL_IREG(ax)]
        __asm mov         FULL_IREG(ax), [p2]
        __asm vmovaps     zmm2, [FULL_IREG(ax)]
        __asm mov         FULL_IREG(ax), [p3]
        __asm vmovaps     zmm3, [FULL_IREG(ax)]

        __asm vpxord      zmm6, zmm6, zmm6
        __asm vpxord      zmm7, zmm7, zmm7

         /* vpunpckhbw */

        __asm vmovaps     zmm4, zmm1
        __asm vmovaps     zmm5, zmm1
        __asm vpunpckhbw  zmm4, zmm2, zmm3
        __asm mov         FULL_IREG(ax), [p3]
        __asm vpunpckhbw  zmm5, zmm2, [FULL_IREG(ax)]
        __asm vpsubd      zmm6, zmm4, zmm5
        __asm vpord       zmm7, zmm7, zmm6

         /* vpunpcklbw */

        __asm vmovaps     zmm4, zmm1
        __asm vmovaps     zmm5, zmm1
        __asm vpunpcklbw  zmm4, zmm2, zmm3
        __asm mov         FULL_IREG(ax), [p3]
        __asm vpunpcklbw  zmm5, zmm2, [FULL_IREG(ax)]
        __asm vpsubd      zmm6, zmm4, zmm5
        __asm vpord       zmm7, zmm7, zmm6

         /* vpunpckhwd */

        __asm vmovaps     zmm4, zmm1
        __asm vmovaps     zmm5, zmm1
        __asm vpunpckhwd  zmm4, zmm2, zmm3
        __asm mov         FULL_IREG(ax), [p3]
        __asm vpunpckhwd  zmm5, zmm2, [FULL_IREG(ax)]
        __asm vpsubd      zmm6, zmm4, zmm5
        __asm vpord       zmm7, zmm7, zmm6

         /* vpunpcklwd */

        __asm vmovaps     zmm4, zmm1
        __asm vmovaps     zmm5, zmm1
        __asm vpunpcklwd  zmm4, zmm2, zmm3
        __asm mov         FULL_IREG(ax), [p3]
        __asm vpunpcklwd  zmm5, zmm2, [FULL_IREG(ax)]
        __asm vpsubd      zmm6, zmm4, zmm5
        __asm vpord       zmm7, zmm7, zmm6

         /* vpunpckhdq */

        __asm vmovaps     zmm4, zmm1
        __asm vmovaps     zmm5, zmm1
        __asm vpunpckhdq  zmm4, zmm2, zmm3
        __asm mov         FULL_IREG(ax), [p3]
        __asm vpunpckhdq  zmm5, zmm2, [FULL_IREG(ax)]
        __asm vpsubd      zmm6, zmm4, zmm5
        __asm vpord       zmm7, zmm7, zmm6

        __asm mov         FULL_IREG(ax), [p3]
        __asm vpunpcklqdq zmm5, zmm2, [FULL_IREG(ax)]{1to8}

        /* vpunpckldq */

        __asm vmovaps zmm4, zmm1 
        __asm vmovaps zmm5, zmm1 
        __asm vpunpckldq zmm4, zmm2, zmm3 
        __asm mov FULL_IREG(ax), [p3] 
        __asm vpunpckldq zmm5, zmm2, [FULL_IREG(ax)] 
        __asm vpsubd zmm6, zmm4, zmm5 
        __asm vpord zmm7, zmm7, zmm6

      /* vunpckhps */

      __asm vmovaps zmm4, zmm1 
      __asm vmovaps zmm5, zmm1 
      __asm vunpckhps zmm4, zmm2, zmm3 
      __asm mov FULL_IREG(ax), [p3] 
      __asm vunpckhps zmm5, zmm2, [FULL_IREG(ax)] 
      __asm vpsubd zmm6, zmm4, zmm5 
      __asm vpord zmm7, zmm7, zmm6

      /* vunpcklps */

      __asm vmovaps zmm4, zmm1 
      __asm vmovaps zmm5, zmm1 
      __asm vunpcklps zmm4, zmm2, zmm3 
      __asm mov FULL_IREG(ax), [p3] 
      __asm vunpcklps zmm5, zmm2, [FULL_IREG(ax)] 
      __asm vpsubd zmm6, zmm4, zmm5 
      __asm vpord zmm7, zmm7, zmm6

      /* vunpckhpd */

      __asm vmovaps zmm4, zmm1 
      __asm vmovaps zmm5, zmm1 
      __asm vunpckhpd zmm4, zmm2, zmm3 
      __asm mov FULL_IREG(ax), [p3] 
      __asm vunpckhpd zmm5, zmm2, [FULL_IREG(ax)] 
      __asm vpsubd zmm6, zmm4, zmm5 
      __asm vpord zmm7, zmm7, zmm6

      /* vunpcklpd */

      __asm vmovaps zmm4, zmm1 
      __asm vmovaps zmm5, zmm1 
      __asm vunpcklpd zmm4, zmm2, zmm3 
      __asm mov FULL_IREG(ax), [p3] 
      __asm vunpcklpd zmm5, zmm2, [FULL_IREG(ax)] 
      __asm vpsubd zmm6, zmm4, zmm5 
      __asm vpord zmm7, zmm7, zmm6

      /* vpermilps reg */

      __asm vmovaps zmm4, zmm1 
      __asm vmovaps zmm5, zmm1 
      __asm vpermilps zmm4, zmm2, zmm3 
      __asm mov FULL_IREG(ax), [p3] 
      __asm vpermilps zmm5, zmm2, [FULL_IREG(ax)] 
      __asm vpsubd zmm6, zmm4, zmm5 
      __asm vpord zmm7, zmm7, zmm6

      /* vpermilps imm */

      __asm vmovaps zmm4, zmm1 
      __asm vmovaps zmm5, zmm1 
      __asm vpermilps zmm4, zmm2, 0x35 
      __asm mov FULL_IREG(ax), [p2] 
      __asm vpermilps zmm5, [FULL_IREG(ax)], 0x35 
      __asm vpsubd zmm6, zmm4, zmm5 
      __asm vpord zmm7, zmm7, zmm6

      /* vshufps */

      /* __asm mov         FULL_IREG(ax), [p3] */
      /* __asm vbroadcastf32x4 zmm5, [FULL_IREG(ax)] */
      /* __asm vshufps     zmm4, zmm2, zmm5, 0x65 */
      __asm vshufps zmm4, zmm2, zmm3, 0x65 
      __asm mov FULL_IREG(ax), [p3] 
      __asm vshufps zmm5, zmm2, [FULL_IREG(ax)], 0x65
      /* __asm vshufps     zmm5, zmm2, [FULL_IREG(ax)]{4to16}, 0x65 */
      __asm vpsubd zmm6, zmm4, zmm5 
      __asm vpord zmm7, zmm7, zmm6

      /* vpalignr */

      __asm vpalignr zmm4, zmm2, zmm3, 0xd 
      __asm mov FULL_IREG(ax), [p3] 
      __asm vpalignr zmm5, zmm2, [FULL_IREG(ax)], 0xd 
      __asm vpsubd zmm6, zmm4, zmm5 
      __asm vpord zmm7, zmm7, zmm6

      /* Cumulative difference from zero is in zmm7, save this in i5. */

      __asm mov FULL_IREG(ax), [p5] 
      __asm vmovaps[FULL_IREG(ax)], zmm7

      /* Expected difference is zero, put zero in i4. */

      __asm vpxord zmm7, zmm7, zmm7 
      __asm mov FULL_IREG(ax), [p4] 
      __asm vmovaps[FULL_IREG(ax)], zmm7
}

check_equal_zmm(&i5, &i4, "various 512-bit reg-reg vs reg-mem");
}

int main(int argc, char *argv[]) {
  if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'v' &&
      argv[1][2] == '\0') {
    verbose = 1;
  }

  init();
  do_punpck_bw();
  do_punpck_wd();
  do_punpck_dq();
  do_punpck_qdq();
  do_punpck_ps();
  do_palignr();
  compare_reg_reg_vs_reg_mem();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
