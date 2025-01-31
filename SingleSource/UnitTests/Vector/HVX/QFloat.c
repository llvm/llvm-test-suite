
#include <stdio.h>
#include <stdlib.h>

#include <hexagon_types.h>
#if !defined(__linux__)
#include <hexagon_standalone.h>
#endif

union ui32f {
  int32_t i;
  float f;
};
union ui16f16 {
  int16_t i;
  __fp16 f16;
};

// 128 byte vectors
#define VSIZE_BYTES 128
#define VSIZE_WORDS VSIZE_BYTES / 4

void print_vector_words(HVX_Vector x) {
  for (int i = 0; i < VSIZE_WORDS; i++) {
    if (!(i % 8))
      printf("\n");
    printf("0x%08lx ", x[i]);
  }

  printf("\n");
}

//
// Create vectors
//

// create a vector of floats from a float
static __attribute__((always_inline)) HVX_Vector
create_sfv_from_sf(float value) {
  union ui32f cvt;
  cvt.f = value;
  HVX_Vector tmp = Q6_V_vsplat_R(cvt.i);
  return tmp;
}

// create a vector of half floats from a float
static __attribute__((always_inline)) HVX_Vector
create_hfv_from_sf(float value) {
  __fp16 hf = value;
  union ui16f16 cvt;
  cvt.f16 = hf;
  HVX_Vector tmp = Q6_Vh_vsplat_R(cvt.i);
  return tmp;
}

// create a vector of qf32's from a float
static __attribute__((always_inline)) HVX_Vector
create_qf32v_from_sf(float value) {
  HVX_Vector tmp =
      Q6_Vqf32_vadd_Vqf32Vsf(Q6_V_vsplat_R(0), create_sfv_from_sf(value));
  return tmp;
}

// create a vector of qf16's from a float
static __attribute__((always_inline)) HVX_Vector
create_qf16v_from_sf(float value) {
  // create qf16 vector from hf
  HVX_Vector tmp =
      Q6_Vqf16_vadd_Vqf16Vhf(Q6_V_vsplat_R(0), create_hfv_from_sf(value));
  return tmp;
}

//
// Conversion vectors
//

// convert qf32 vector to float vector
static __attribute__((always_inline)) HVX_Vector
convert_qf32v_to_fltv(HVX_Vector vect) {
  HVX_Vector tmp = Q6_Vsf_equals_Vqf32(vect);
  return tmp;
}

// convert qf16 vector to half float vector
static __attribute__((always_inline)) HVX_Vector
convert_qf16v_to_hfv(HVX_Vector vect) {
  HVX_Vector tmp = Q6_Vhf_equals_Vqf16(vect);
  return tmp;
}

//
// Extraction routines
//

// get lowest float from a vector of floats
static __attribute__((always_inline)) float
get_flt0_from_fltv(HVX_Vector vect) {
  union ui32f cvt;
  cvt.i = vect[0];
  return cvt.f;
}

// get lowest float from a vector of qf32's
static __attribute__((always_inline)) float
get_flt0_from_qf32v(HVX_Vector vect) {
  union ui32f cvt;
  HVX_Vector tmp = convert_qf32v_to_fltv(vect);
  cvt.i = tmp[0];
  return cvt.f;
}

// get lowest float from a vector of halfs
static __attribute__((always_inline)) float
get_flt0_from_halfv(HVX_Vector vect) {
  union ui16f16 cvt;
  cvt.i = (vect[0] & 0xffff);
  return (float)cvt.f16;
}

// get lowest float from a vector of qf16's
static __attribute__((always_inline)) float
get_flt0_from_qf16v(HVX_Vector vect) {
  return get_flt0_from_halfv(convert_qf16v_to_hfv(vect));
}

// get lowest float from a vector pair of qf32's
static __attribute__((always_inline)) float
get_flt0_from_qf32vp(HVX_VectorPair vect) {
  union ui32f cvt;
  HVX_Vector tmp = convert_qf32v_to_fltv(HEXAGON_HVX_GET_V0(vect));
  cvt.i = tmp[0];
  return cvt.f;
}

int main(int argc, char **argv) {
#if !defined(__linux__)
  SIM_ACQUIRE_HVX;
  SIM_SET_HVX_DOUBLE_MODE;
#endif

  // create 2 sf vectors in IEEE-754 format
  HVX_Vector v1 = create_sfv_from_sf(0.5);
  HVX_Vector v2 = create_sfv_from_sf(0.25);

  // create 2 vectors in the qf32 format
  HVX_Vector v3 = create_qf32v_from_sf(0.5);
  HVX_Vector v4 = create_qf32v_from_sf(0.25);

  printf("\nAdd intrinsics with a qf32 result\n");

  // add the IEEE vectors into a qf32 vector
  HVX_Vector result1 = Q6_Vqf32_vadd_VsfVsf(v1, v2);
  printf("The sum of flt  %f and flt  %f is %f\n", get_flt0_from_fltv(v1),
         get_flt0_from_fltv(v2), get_flt0_from_qf32v(result1));

  // add the qf32 vectors into a qf32 vector
  HVX_Vector result2 = Q6_Vqf32_vadd_Vqf32Vqf32(v3, v4);
  printf("The sum of qf32 %f and qf32 %f is %f\n", get_flt0_from_qf32v(v3),
         get_flt0_from_qf32v(v4), get_flt0_from_qf32v(result2));

  // add a qf32 vector and an IEEE vector into a qf32 vector
  HVX_Vector result3 = Q6_Vqf32_vadd_Vqf32Vsf(v3, v2);
  printf("The sum of qf32 %f and flt  %f is %f\n", get_flt0_from_qf32v(v3),
         get_flt0_from_fltv(v2), get_flt0_from_qf32v(result3));

  printf("\nSubtract intrinsics with a qf32 result\n");

  // subtract the IEEE vectors into a qf32 vector
  HVX_Vector result4 = Q6_Vqf32_vsub_VsfVsf(v1, v2);
  printf("The sum of flt  %f and flt  -%f is %f\n", get_flt0_from_fltv(v1),
         get_flt0_from_fltv(v2), get_flt0_from_qf32v(result4));

  // add the qf32 vectors into a qf32 vector
  HVX_Vector result5 = Q6_Vqf32_vsub_Vqf32Vqf32(v3, v4);
  printf("The sum of qf32 %f and qf32 -%f is %f\n", get_flt0_from_qf32v(v3),
         get_flt0_from_qf32v(v4), get_flt0_from_qf32v(result5));

  // add a qf32 vector and an IEEE vector into a qf32 vector
  HVX_Vector result6 = Q6_Vqf32_vsub_Vqf32Vsf(v3, v2);
  printf("The sum of qf32 %f and flt  -%f is %f\n", get_flt0_from_qf32v(v3),
         get_flt0_from_fltv(v2), get_flt0_from_qf32v(result6));

  printf("\nMultiply intrinsics with a qf32 result\n");

  // multiply the IEEE vectors into a qf32 vector
  HVX_Vector result7 = Q6_Vqf32_vmpy_VsfVsf(v1, v2);
  printf("The result of flt  %f * flt  %f is %f\n", get_flt0_from_fltv(v1),
         get_flt0_from_fltv(v2), get_flt0_from_qf32v(result7));

  // multiply the qf32 vectors into a qf32 vector
  HVX_Vector result8 = Q6_Vqf32_vmpy_Vqf32Vqf32(v3, v4);
  printf("The result of qf32 %f * qf32 %f is %f\n", get_flt0_from_qf32v(v3),
         get_flt0_from_qf32v(v4), get_flt0_from_qf32v(result8));

  // create 2 half vectors in the IEEE-754 format
  HVX_Vector v5 = create_hfv_from_sf(0.5);
  HVX_Vector v6 = create_hfv_from_sf(0.25);

  // create 2 vectors in the qf16 format
  HVX_Vector v7 = create_qf16v_from_sf(0.5);
  HVX_Vector v8 = create_qf16v_from_sf(0.25);

  printf("\nAdd intrinsics with a qf16 result\n");

  // add the IEEE hf vectors into a qf16 vector
  HVX_Vector result9 = Q6_Vqf16_vadd_VhfVhf(v5, v6);
  printf("The sum of hf   %.3f and hf   %.3f is %.3f\n",
         get_flt0_from_halfv(v5), get_flt0_from_halfv(v6),
         get_flt0_from_qf16v(result9));

  // add the qf16 vectors into a qf16 vector
  HVX_Vector result10 = Q6_Vqf16_vadd_Vqf16Vqf16(v7, v8);
  printf("The sum of qf16 %.3f and qf16 %.3f is %.3f\n",
         get_flt0_from_qf16v(v7), get_flt0_from_qf16v(v8),
         get_flt0_from_qf16v(result10));

  // add a qf16 vector and an IEEE hf vector into a qf16 vector
  HVX_Vector result11 = Q6_Vqf16_vadd_Vqf16Vhf(v7, v6);
  printf("The sum of qf16 %.3f and hf   %.3f is %.3f\n",
         get_flt0_from_qf16v(v7), get_flt0_from_halfv(v6),
         get_flt0_from_qf16v(result11));

  printf("\nSubtract intrinsics with a qf16 result\n");

  // add the IEEE hf vectors into a qf16 vector
  HVX_Vector result12 = Q6_Vqf16_vsub_VhfVhf(v5, v6);
  printf("The sum of hf   %.3f and hf   -%.3f is %.3f\n",
         get_flt0_from_halfv(v5), get_flt0_from_halfv(v6),
         get_flt0_from_qf16v(result12));

  // add the qf16 vectors into a qf16 vector
  HVX_Vector result13 = Q6_Vqf16_vsub_Vqf16Vqf16(v7, v8);
  printf("The sum of qf16 %.3f and qf16 -%.3f is %.3f\n",
         get_flt0_from_qf16v(v7), get_flt0_from_qf16v(v8),
         get_flt0_from_qf16v(result13));

  // add a qf16 vector and an IEEE hf vector into a qf16 vector
  HVX_Vector result14 = Q6_Vqf16_vsub_Vqf16Vhf(v7, v6);
  printf("The sum of qf16 %.3f and hf   -%.3f is %.3f\n",
         get_flt0_from_qf16v(v7), get_flt0_from_halfv(v6),
         get_flt0_from_qf16v(result14));

  printf("\nMultiply intrinsics with a qf16 result\n");

  // multiply the IEEE hf vectors into a qf16 vector
  HVX_Vector result15 = Q6_Vqf16_vmpy_VhfVhf(v5, v6);
  printf("The result of hf   %.3f * hf   %.3f is %.3f\n",
         get_flt0_from_halfv(v5), get_flt0_from_halfv(v6),
         get_flt0_from_qf16v(result15));

  // multiply the qf16 vectors into a qf16 vector
  HVX_Vector result16 = Q6_Vqf16_vmpy_Vqf16Vqf16(v7, v8);
  printf("The result of qf16 %.3f * qf16 %.3f is %.3f\n",
         get_flt0_from_qf16v(v7), get_flt0_from_qf16v(v8),
         get_flt0_from_qf16v(result16));

  // multiply the qf16 vector with a hf vector into a qf16 vector
  HVX_Vector result17 = Q6_Vqf16_vmpy_Vqf16Vhf(v7, v6);
  printf("The result of qf16 %.3f * hf   %.3f is %.3f\n",
         get_flt0_from_qf16v(v7), get_flt0_from_halfv(v6),
         get_flt0_from_qf16v(result17));

  // multiply with pair results

  printf("\nMultiply hf/qf16 intrinsics with a qf32 result\n");

  // multiply the IEEE hf vectors into a qf32 vector pair
  HVX_VectorPair result18 = Q6_Wqf32_vmpy_VhfVhf(v5, v6);
  printf("The result of hf   %.3f * hf   %.3f is %.3f\n",
         get_flt0_from_halfv(v5), get_flt0_from_halfv(v6),
         get_flt0_from_qf32vp(result18));

  // multiply the qf16 vectors into a qf32 vector pair
  HVX_VectorPair result19 = Q6_Wqf32_vmpy_Vqf16Vqf16(v7, v8);
  printf("The result of qf16 %.3f * qf16 %.3f is %.3f\n",
         get_flt0_from_qf16v(v7), get_flt0_from_qf16v(v8),
         get_flt0_from_qf32vp(result19));

  // multiply the qf16 vector with a hf vector into a qf32 vector
  HVX_VectorPair result20 = Q6_Wqf32_vmpy_Vqf16Vhf(v7, v6);
  printf("The result of qf16 %.3f * hf   %.3f is %.3f\n",
         get_flt0_from_qf16v(v7), get_flt0_from_halfv(v6),
         get_flt0_from_qf32vp(result20));

  // create_qf32v_from_qf16v(HVX_Vector qf16)

  printf("\nCompare instrinsics\n");

  // compare 2 single float vectors
  HVX_VectorPred Pred = Q6_Q_vcmp_gt_VsfVsf(v1, v2);

  // sum the bits
  HVX_Vector sum = Q6_Vw_prefixsum_Q(Pred);
  printf("The sum of the predicate bits from the sf compare is %ld\n", sum[31]);

  // compare 2 half float vectors
  Pred = Q6_Q_vcmp_gt_VhfVhf(v5, v6);

  // sum the bits
  sum = Q6_Vh_prefixsum_Q(Pred);
  printf("The sum of the predicate bits from the hf compare is %ld\n",
         sum[31] >> 16);

  printf("\nMin/Max instrinsics\n");

  // get a vector that is the max of 2 sf vectors
  HVX_Vector sfmax = Q6_Vsf_vmax_VsfVsf(v1, v2);
  printf("The max value of sf v1 and sf v2 is %f\n", get_flt0_from_fltv(sfmax));

  // get a vector that is the min of 2 sf vectors
  HVX_Vector sfmin = Q6_Vsf_vmin_VsfVsf(v1, v2);
  printf("The min value of sf v1 and sf v2 is %f\n", get_flt0_from_fltv(sfmin));

  // get a vector that is the max of 2 hf vectors
  HVX_Vector hfmax = Q6_Vhf_vmax_VhfVhf(v5, v6);
  printf("The max value of hf v5 and sf v6 is %f\n",
         get_flt0_from_halfv(hfmax));

  // get a vector that is the min of 2 hf vectors
  HVX_Vector hfmin = Q6_Vhf_vmin_VhfVhf(v5, v6);
  printf("The min value of hf v5 and sf v6 is %f\n",
         get_flt0_from_halfv(hfmin));

  return 0;
}
