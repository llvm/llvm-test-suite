//
// Testcases for
//   128/256/512 bit vdbpsadbw
// intrinsics with no mask/blend mask/zero mask forms.
//
// Here we check for _mm*_dbsad_epu8 intrinsics.
//

#include "m512_test_util.h"
#include <stdio.h>

#if DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#define ddisplay_w(...) display_pw(__VA_ARGS__)
#define ddisplay_b(...) display_pb(__VA_ARGS__)
#else
#define dprintf(...)
#define ddisplay_w(...)
#define ddisplay_b(...)
#endif // DEBUG

typedef int bool;
#define true 1
#define false 0

#define CHECK_DBPSADBW(opcode, res_bit_size, is_masked, mask, is_zero_mask,    \
                       imm)                                                    \
  {                                                                            \
    int fail = 0;                                                              \
    /* Compute the expected result. */                                         \
    expVal.zmmi =                                                              \
        compute_vdbpsadbw(&expVal, is_masked, mask, is_zero_mask, imm,         \
                          &bop1.zmmi, &bop2.zmmi, res_bit_size);               \
                                                                               \
    /* Compare the obtained and expected results. */                           \
    fail = check_equal_nw(&res, &expVal, (res_bit_size / 16),                  \
                          is_masked ? (is_zero_mask ? opcode " zero mask"      \
                                                    : opcode " blend mask")    \
                                    : opcode " no mask",                       \
                          __LINE__);                                           \
    if (fail) {                                                                \
      dprintf("\n");                                                           \
      ddisplay_w(&wres_orig, "old:", res_bit_size / 16);                       \
      dprintf("\n");                                                           \
      ddisplay_b(&bop2, "bop2:", res_bit_size / 8);                            \
      dprintf("\n");                                                           \
      ddisplay_b(&bop1, "bop1:", res_bit_size / 8);                            \
      dprintf("\n===========================================\n");              \
    }                                                                          \
  }

#define XYDBPSADBW(opcode, res_bit_size, mmsuffix, is_masked, mask,            \
                   is_zero_mask, imm, xy)                                      \
  {                                                                            \
    if (is_masked) {                                                           \
      if (is_zero_mask) {                                                      \
        /* Zero masking */                                                     \
        memset(&res, 0xFF, sizeof(res));                                       \
        res.xy##mmi[0] = mmsuffix##maskz_##dbsad_epu8(mask, bop1.xy##mmi[0],   \
                                                      bop2.xy##mmi[0], imm);   \
      } else {                                                                 \
        /* Blend masking */                                                    \
        memcpy(&res, &wres_orig, sizeof(res));                                 \
        res.xy##mmi[0] = mmsuffix##mask_##dbsad_epu8(                          \
            res.xy##mmi[0], mask, bop1.xy##mmi[0], bop2.xy##mmi[0], imm);      \
      }                                                                        \
    } else {                                                                   \
      /* No masking */                                                         \
      memset(&res, 0x0, sizeof(res));                                          \
      res.xy##mmi[0] =                                                         \
          mmsuffix##dbsad_epu8(bop1.xy##mmi[0], bop2.xy##mmi[0], imm);         \
    }                                                                          \
    CHECK_DBPSADBW(opcode, res_bit_size, is_masked, mask, is_zero_mask, imm)   \
  }

#define ZDBPSADBW(opcode, is_masked, mask, is_zero_mask, imm)                  \
  {                                                                            \
    if (is_masked) {                                                           \
      if (is_zero_mask) { /* Zero masking */                                   \
        memset(&res, 0xFF, sizeof(res));                                       \
        res.zmmi = _mm512_maskz_##dbsad_epu8(mask, bop1.zmmi, bop2.zmmi, imm); \
      } else { /* Blend masking */                                             \
        memcpy(&res, &wres_orig, sizeof(res));                                 \
        res.zmmi = _mm512_mask_##dbsad_epu8(res.zmmi, mask, bop1.zmmi,         \
                                            bop2.zmmi, imm);                   \
      }                                                                        \
    } else { /* No masking */                                                  \
      memset(&res, 0x0, sizeof(res));                                          \
      res.zmmi = _mm512_##dbsad_epu8(bop1.zmmi, bop2.zmmi, imm);               \
    }                                                                          \
    CHECK_DBPSADBW(opcode, 512, is_masked, mask, is_zero_mask, imm)            \
  }

//
// Data
//

volatile unsigned short u16_orig_arr[32] = {
    0x1000, 0x1100, 0x2200, 0x3300, 0x4400, 0x5500, 0x6600, 0x7700,
    0x8800, 0x9900, 0xaa00, 0xbb00, 0xcc00, 0xdd00, 0xee00, 0xff00,
    0x1234, 0x1111, 0x2222, 0x3333, 0x4444, 0x5555, 0x6666, 0x7777,
    0x8888, 0x9999, 0xaaaa, 0xbbbb, 0xcccc, 0xdddd, 0xeeee, 0xffff};

V512 bop1, bop2;
V512 res, expVal;
V512 wres_orig;

static void NOINLINE init() {
  int i;

  // i8 operand vectors
  //
  for (i = 0; i < 64; i++) {
    bop1.s8[i] = i;
  }
  for (i = 63; i >= 0; i--) {
    bop2.s8[63 - i] = i;
  }

  // Destructed operand vectors
  memcpy((void *)&wres_orig, (void *)u16_orig_arr, 64);
}

//
// Emulate the vdbpsadbw operation.
//

__m512i NOINLINE compute_vdbpsadbw(void *res, bool is_masked, unsigned int mask,
                                   bool zero_mask, int imm, const void *op1,
                                   const void *op2, int res_bit_size) {
  V512 *vres = (V512 *)res;
  V512 *vop1 = (V512 *)op1;
  V512 *vop2 = (V512 *)op2;
  V512 vtmp;

  int lanes = res_bit_size / 128;
  int lane, res_i;
  int elems, elem;

  dprintf("\n\n");

  // Do unmasked vdbpsadbw to get temp result.
  //
  for (lane = 0; lane < lanes; lane++) {

    dprintf("\n");
    for (elem = 0; elem < 4; elem++) {
      int op_i;

      res_i = lane * 4 + elem;
      op_i = lane * 4 + ((imm >> (2 * elem)) & 0x3);
      vtmp.u32[res_i] = vop2->u32[op_i];

      dprintf("l,e %d:%d,   tmp[%d] = op2[%d]\n", lane, elem, res_i, op_i);
    }
  }

  elems = res_bit_size / 64;

  for (elem = 0; elem < elems; elem++) {
    unsigned short *res_wp = (unsigned short *)&vres->u64[elem];
    unsigned char *op1_bp = (unsigned char *)&vop1->u64[elem];
    unsigned char *tmp_bp = (unsigned char *)&vtmp.u64[elem];

    res_wp[0] = abs(op1_bp[0] - tmp_bp[0]) + abs(op1_bp[1] - tmp_bp[1]) +
                abs(op1_bp[2] - tmp_bp[2]) + abs(op1_bp[3] - tmp_bp[3]);

    res_wp[1] = abs(op1_bp[0] - tmp_bp[1]) + abs(op1_bp[1] - tmp_bp[2]) +
                abs(op1_bp[2] - tmp_bp[3]) + abs(op1_bp[3] - tmp_bp[4]);

    res_wp[2] = abs(op1_bp[4] - tmp_bp[2]) + abs(op1_bp[5] - tmp_bp[3]) +
                abs(op1_bp[6] - tmp_bp[4]) + abs(op1_bp[7] - tmp_bp[5]);

    res_wp[3] = abs(op1_bp[4] - tmp_bp[3]) + abs(op1_bp[5] - tmp_bp[4]) +
                abs(op1_bp[6] - tmp_bp[5]) + abs(op1_bp[7] - tmp_bp[6]);
  }

  // Apply masking to get final result.
  //
  elems = res_bit_size / 16;

  for (res_i = 0; res_i < elems; res_i++) {
    int elem_mask;

    elem_mask = mask & (1 << res_i);

    // The unmasked computation above has taken care of
    // the elem_mask == 1 case.
    if (elem_mask == 0) {
      if (zero_mask) {
        // Zeroing behavior.
        vres->u16[res_i] = 0;
      } else {
        // Blending behavior
        vres->u16[res_i] = wres_orig.u16[res_i];
      }
    }
  }

  return vres->zmmi;
}

//
// Mask values.
//

#define KMASK8_NONE 0xff
#define KMASK16_NONE 0xffff
#define KMASK32_NONE 0xffffffff

#define KMASK8_ONES 0xff
#define KMASK16_ONES 0xffff
#define KMASK32_ONES 0xffffffff

#define KMASK8_ALT 0xaa
#define KMASK16_ALT 0xaaaa
#define KMASK32_ALT 0xaaaaaaaa

//
// Immediate value.
//
#define IMM_3210 0xe4

//
// Tests for vdbpsadbw
//
void do_xdbpsadbw() {
  XYDBPSADBW("EDBPSADBW", 128, _mm_, false, KMASK8_NONE, false, IMM_3210, x);

  XYDBPSADBW("EDBPSADBW", 128, _mm_, true, KMASK8_ONES, false, IMM_3210, x);

  XYDBPSADBW("EDBPSADBW", 128, _mm_, true, KMASK8_ALT, false, IMM_3210, x);

  XYDBPSADBW("EDBPSADBW", 128, _mm_, true, KMASK8_ALT, true, IMM_3210, x);
}

void do_ydbpsadbw() {
  XYDBPSADBW("YDBPSADBW", 256, _mm256_, false, KMASK16_NONE, false, IMM_3210,
             y);

  XYDBPSADBW("YDBPSADBW", 256, _mm256_, true, KMASK16_ONES, false, IMM_3210, y);

  XYDBPSADBW("YDBPSADBW", 256, _mm256_, true, KMASK16_ALT, false, IMM_3210, y);

  XYDBPSADBW("YDBPSADBW", 256, _mm256_, true, KMASK16_ALT, true, IMM_3210, y);
}

void do_zdbpsadbw() {
  ZDBPSADBW("ZDBPSADBW", false, KMASK32_NONE, false, IMM_3210);

  ZDBPSADBW("ZDBPSADBW", true, KMASK32_ONES, false, IMM_3210);

  ZDBPSADBW("ZDBPSADBW", true, KMASK32_ALT, false, IMM_3210);

  ZDBPSADBW("ZDBPSADBW", true, KMASK32_ALT, true, IMM_3210);
}

int main() {
  init();

  do_xdbpsadbw();
  do_ydbpsadbw();
  do_zdbpsadbw();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
