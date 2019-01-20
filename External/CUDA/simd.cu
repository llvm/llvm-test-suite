//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <complex>  // Needed for std::min and max to work on device.
#include <limits>

int verbose = 0;

#if __cplusplus >= 201103L
#include <type_traits>

// Convert a function into a functor with two arguments.  We rely on SFINAE to
// instantiate a function template call() which will invoke FUNC() with one or
// two arguments.
#define F(FUNC, NELTS, NARGS)                                              \
  typedef struct FUNC##_f {                                                \
    static const int num_args = NARGS;                                     \
    static const int num_elts = NELTS;                                     \
    template <typename T, int NA = num_args>                               \
    __device__ static typename std::enable_if<NA == 1, unsigned int>::type \
    call(T a, T b) {                                                       \
      return FUNC(a);                                                      \
    }                                                                      \
    template <typename T, int NA = num_args>                               \
    __device__ static typename std::enable_if<NA == 2, unsigned int>::type \
    call(T a, T b) {                                                       \
      return FUNC(a, b);                                                   \
    }                                                                      \
  } FUNC##_f

template <int N, typename T>
__device__ unsigned int pack(T a[N]) {
  unsigned int mask = (N == 2) ? 0xffff : 0xff;
  unsigned int shift = (N == 2) ? 16 : 8;
  unsigned int r = 0;
  for (int i = 0; i < N; ++i) {
    r |= ((unsigned int)a[i] & mask) << (shift * i);
  }
  return r;
}
template <int N, typename T>
__device__ void unpack(unsigned int r, T (&a)[N]) {
  unsigned int mask = (N == 2) ? 0xffff : 0xff;
  unsigned int shift = (N == 2) ? 16 : 8;
  for (int i = 0; i < N; ++i) {
    a[i] = ((r >> (shift * i)) & mask);
  }
}

enum op_t {
  OP_ABS,
  OP_ABSDIFF,
  OP_ABSS,
  OP_ADD,
  OP_ADDS,
  OP_AVG,
  OP_CMPEQ,
  OP_CMPGE,
  OP_CMPGT,
  OP_CMPLE,
  OP_CMPLT,
  OP_CMPNE,
  OP_HADD,
  OP_MAX,
  OP_MIN,
  OP_NEG,
  OP_SAD,
  OP_SETEQ,
  OP_SETGE,
  OP_SETGT,
  OP_SETLE,
  OP_SETLT,
  OP_SETNE,
  OP_SUB,
  OP_SUBS,
  OP_LAST
};

template <enum op_t OP, typename T>
__device__ inline T elt_op(T a, T b = INT_MIN) {
  switch (OP) {
    case OP_ABS:
      if (!std::numeric_limits<T>::is_signed) return a;
      // This is wrong, but that's what __vabsN() returns.  We also need to
      // handle that because abs(std::numeric_limits<T>::min()) would be an
      // undefined behavior otherwise.
      if (a == std::numeric_limits<T>::min())
        return std::numeric_limits<T>::min();
      return (a >= 0) ? a : -a;

    case OP_ABSDIFF:
      return std::abs(a - b);
    case OP_ABSS: {
      int result = std::abs(a);
      if (result > std::numeric_limits<T>::max())
        return std::numeric_limits<T>::max();
      return result;
    }
    case OP_ADD:
      return a + b;
    case OP_ADDS: {
      int result = (int)a + (int)b;
      if (result > std::numeric_limits<T>::max())
        return std::numeric_limits<T>::max();
      if (std::numeric_limits<T>::is_signed &&
          result < std::numeric_limits<T>::min())
        return std::numeric_limits<T>::min();
      return result;
    }
    case OP_AVG:
      // This is *rounded* average. For simplicity let FP do the
      // rounding. Considering that T is byte or short, we're guaranteed not to
      // lose any bits.
      return round(((float)a + (float)b) / 2.0f);
    case OP_CMPEQ:
      return a == b ? -1 : 0;
    case OP_CMPGE:
      return a >= b ? -1 : 0;
    case OP_CMPGT:
      return a > b ? -1 : 0;
    case OP_CMPLE:
      return a <= b ? -1 : 0;
    case OP_CMPLT:
      return a < b ? -1 : 0;
    case OP_CMPNE:
      return a != b ? -1 : 0;
    case OP_HADD:
      return (a + b) / 2;
    case OP_MAX:
      return std::max(a, b);
    case OP_MIN:
      return std::min(a, b);
    case OP_NEG:
      // This is wrong, but that's what __vnegN() returns.  We also need to
      // handle that because abs(std::numeric_limits<T>::min()) would be an
      // undefined behavior otherwise.
      if (std::numeric_limits<T>::is_signed &&
          a == std::numeric_limits<T>::min())
        return std::numeric_limits<T>::min();
      return -a;
    case OP_SAD:
      return std::abs(a - b);  // need to sum per-element results later.
    case OP_SETEQ:
      return a == b ? 1 : 0;
    case OP_SETGE:
      return a >= b ? 1 : 0;
    case OP_SETGT:
      return a > b ? 1 : 0;
    case OP_SETLE:
      return a <= b ? 1 : 0;
    case OP_SETLT:
      return a < b ? 1 : 0;
    case OP_SETNE:
      return a != b ? 1 : 0;
    case OP_SUB:
      return a - b;
    case OP_SUBS: {
      int result = (int)a - (int)b;
      if (result > std::numeric_limits<T>::max())
        return std::numeric_limits<T>::max();
      if (result < std::numeric_limits<T>::min())
        return std::numeric_limits<T>::min();
      return result;
    }
    default:
      assert(false && "unknown OP");
  }
  assert(false && "Unreachable.");
  return 0;
}

template <op_t OP, typename T, int N>
__device__ void simd_op(T (&r)[N], T a[N], T b[N]) {
  if (OP == OP_SAD) {
    // Sum up all elements in r[0] and clear the rest of r.
    int result = 0;
    for (int i = 0; i < N; ++i) {
      result += elt_op<OP, T>(a[i], b[i]);
      r[i] = 0;
    }
    r[0] = result;
  } else {
    // Just an element-wise op.
    for (int i = 0; i < N; ++i) {
      r[i] = elt_op<OP, T>(a[i], b[i]);
    }
  }
}

template <op_t OP, class SIMD_OP, typename T>
__device__ void test_func(int verbose, int a, int b) {
  constexpr int N = SIMD_OP::num_elts;
  int dummy_args[] = {0,
                      1,
                      -1,
                      std::numeric_limits<T>::max(),
                      std::numeric_limits<T>::max() - 1,
                      std::numeric_limits<T>::min(),
                      std::numeric_limits<T>::min() + 1};
  for (T x : dummy_args) {
    for (int e = 0; e < N; ++e) {
      T args_a[N];
      T args_b[N];
      for (int i = 0; i < N; ++i) {
        args_a[i] = x;
        args_b[i] = x;
      }
      args_a[e] = a;
      args_b[e] = b;
      unsigned int va = pack<N, T>(args_a);
      unsigned int vb = pack<N, T>(args_b);
      T expected_r[N];
      simd_op<OP, T>(expected_r, args_a, args_b);
      unsigned int evr = pack<N, T>(expected_r);
      // This is weird and I don't understand what's going on.  With T = short,
      // compiler ends up generating code which triggers the assert below
      // if verbose == false, but triggers no assert if verbose == 1. It may be
      // due to an undefined behavior somewhere, but the same code (with SIMD_OP
      // below replaced with a pack(simd_op(a,b)) (so it could run on host)
      // triggerend no ubsan reports.
      asm volatile("" ::: "memory");
      unsigned int vr = SIMD_OP::call(va, vb);
      if (verbose && vr != evr) {
        printf("e=%d a=%d b=%d va=%08x vb=%08x vr=%08x expected vr=%08x\n", e,
               a, b, va, vb, vr, evr);
      }
      assert((vr == evr) && "Value mismatch");
    }
  }
}

template <op_t OP, class SIMD_OP, typename T>
__global__ void test_kernel(int verbose) {
  int a = blockIdx.x * blockDim.x + threadIdx.x;
  int b = blockIdx.y * blockDim.y + threadIdx.y;
  test_func<OP, SIMD_OP, T>(verbose, a, b);
}

template <op_t OP, class SIMD_OP, typename T>
void test_op() {
  int elements_a = SIMD_OP::num_elts == 2 ? 0x10000 : 0x100;
  // Collapse second dimension if we test single-operand function.
  int elements_b = SIMD_OP::num_args == 2 ? elements_a : 0;
  dim3 grid_size(elements_a / 32, elements_b ? elements_b / 32 : 1, 1);
  dim3 block_size(32, elements_b ? 32 : 1, 1);
  printf("Testing %s...", __PRETTY_FUNCTION__);
  test_kernel<OP, SIMD_OP, T><<<grid_size, block_size>>>(verbose);
  cudaError_t err = cudaDeviceSynchronize();
  if (err != cudaSuccess) {
    printf("%s failed\n", __PRETTY_FUNCTION__);
    printf("CUDA error %d\n", (int)err);
    exit(EXIT_FAILURE);
  } else {
    printf("OK\n");
  }
}

// Define functor types which we can then use to parametrize device-side tests.
// F(function, num-elements, num-args)
F(__vabs2, 2, 1);
F(__vabs4, 4, 1);
F(__vabsdiffs2, 2, 2);
F(__vabsdiffs4, 4, 2);
F(__vabsdiffu2, 2, 2);
F(__vabsdiffu4, 4, 2);
F(__vabsss2, 2, 1);
F(__vabsss4, 4, 1);
F(__vadd2, 2, 2);
F(__vadd4, 4, 2);
F(__vaddss2, 2, 2);
F(__vaddus2, 2, 2);
F(__vaddss4, 4, 2);
F(__vaddus4, 4, 2);
F(__vavgs2, 2, 2);
F(__vavgu2, 2, 2);
F(__vavgs4, 4, 2);
F(__vavgu4, 4, 2);
F(__vcmpeq2, 2, 2);
F(__vcmpeq4, 4, 2);
F(__vcmpges2, 2, 2);
F(__vcmpges4, 4, 2);
F(__vcmpgeu2, 2, 2);
F(__vcmpgeu4, 4, 2);
F(__vcmpgts2, 2, 2);
F(__vcmpgts4, 4, 2);
F(__vcmpgtu2, 2, 2);
F(__vcmpgtu4, 4, 2);
F(__vcmples2, 2, 2);
F(__vcmples4, 4, 2);
F(__vcmpleu2, 2, 2);
F(__vcmpleu4, 4, 2);
F(__vcmplts2, 2, 2);
F(__vcmplts4, 4, 2);
F(__vcmpltu2, 2, 2);
F(__vcmpltu4, 4, 2);
F(__vcmpne2, 2, 2);
F(__vcmpne4, 4, 2);
F(__vhaddu2, 2, 2);
F(__vhaddu4, 4, 2);
F(__vmaxs2, 2, 2);
F(__vmaxs4, 4, 2);
F(__vmaxu2, 2, 2);
F(__vmaxu4, 4, 2);
F(__vmins2, 2, 2);
F(__vmins4, 4, 2);
F(__vminu2, 2, 2);
F(__vminu4, 4, 2);
F(__vneg2, 2, 1);
F(__vneg4, 4, 1);
F(__vsads2, 2, 2);
F(__vsadu2, 2, 2);
F(__vsads4, 4, 2);
F(__vsadu4, 4, 2);
F(__vseteq2, 2, 2);
F(__vseteq4, 4, 2);
F(__vsetges2, 2, 2);
F(__vsetges4, 4, 2);
F(__vsetgeu2, 2, 2);
F(__vsetgeu4, 4, 2);
F(__vsetgts2, 2, 2);
F(__vsetgts4, 4, 2);
F(__vsetgtu2, 2, 2);
F(__vsetgtu4, 4, 2);
F(__vsetles2, 2, 2);
F(__vsetles4, 4, 2);
F(__vsetleu2, 2, 2);
F(__vsetleu4, 4, 2);
F(__vsetlts2, 2, 2);
F(__vsetlts4, 4, 2);
F(__vsetltu2, 2, 2);
F(__vsetltu4, 4, 2);
F(__vsetne2, 2, 2);
F(__vsetne4, 4, 2);
F(__vsub2, 2, 2);
F(__vsub4, 4, 2);
F(__vsubss2, 2, 2);
F(__vsubus2, 2, 2);
F(__vsubss4, 4, 2);
F(__vsubus4, 4, 2);

void tests() {
  test_op<OP_NEG, __vneg2_f, short>();
  test_op<OP_ABS, __vabs2_f, short>();
  test_op<OP_ABS, __vabs4_f, signed char>();
  test_op<OP_ABSDIFF, __vabsdiffs2_f, short>();
  test_op<OP_ABSDIFF, __vabsdiffs4_f, signed char>();
  test_op<OP_ABSDIFF, __vabsdiffu2_f, unsigned short>();
  test_op<OP_ABSDIFF, __vabsdiffu4_f, unsigned char>();
  test_op<OP_ABSS, __vabsss2_f, short>();
  test_op<OP_ABSS, __vabsss4_f, signed char>();
  test_op<OP_ADD, __vadd2_f, short>();
  test_op<OP_ADD, __vadd4_f, signed char>();
  test_op<OP_ADDS, __vaddss2_f, short>();
  test_op<OP_ADDS, __vaddss4_f, signed char>();
  test_op<OP_ADDS, __vaddus2_f, unsigned short>();
  test_op<OP_ADDS, __vaddus4_f, unsigned char>();
  test_op<OP_AVG, __vavgs2_f, short>();
  test_op<OP_AVG, __vavgs4_f, signed char>();
  test_op<OP_AVG, __vavgu2_f, unsigned short>();
  test_op<OP_AVG, __vavgu4_f, unsigned char>();
  test_op<OP_CMPEQ, __vcmpeq2_f, short>();
  test_op<OP_CMPEQ, __vcmpeq4_f, signed char>();
  test_op<OP_CMPGE, __vcmpges2_f, short>();
  test_op<OP_CMPGE, __vcmpges4_f, signed char>();
  test_op<OP_CMPGE, __vcmpgeu2_f, unsigned short>();
  test_op<OP_CMPGE, __vcmpgeu4_f, unsigned char>();
  test_op<OP_CMPGT, __vcmpgts2_f, short>();
  test_op<OP_CMPGT, __vcmpgts4_f, signed char>();
  test_op<OP_CMPGT, __vcmpgtu2_f, unsigned short>();
  test_op<OP_CMPGT, __vcmpgtu4_f, unsigned char>();
  test_op<OP_CMPLE, __vcmples2_f, short>();
  test_op<OP_CMPLE, __vcmples4_f, signed char>();
  test_op<OP_CMPLE, __vcmpleu2_f, unsigned short>();
  test_op<OP_CMPLE, __vcmpleu4_f, unsigned char>();
  test_op<OP_CMPLT, __vcmplts2_f, short>();
  test_op<OP_CMPLT, __vcmplts4_f, signed char>();
  test_op<OP_CMPLT, __vcmpltu2_f, unsigned short>();
  test_op<OP_CMPLT, __vcmpltu4_f, unsigned char>();
  test_op<OP_CMPNE, __vcmpne2_f, short>();
  test_op<OP_CMPNE, __vcmpne4_f, signed char>();
  test_op<OP_HADD, __vhaddu2_f, unsigned short>();
  test_op<OP_HADD, __vhaddu4_f, unsigned char>();
  test_op<OP_MAX, __vmaxs2_f, short>();  // ??? Fails?
  test_op<OP_MAX, __vmaxs4_f, signed char>();
  test_op<OP_MAX, __vmaxu2_f, unsigned short>();
  test_op<OP_MAX, __vmaxu4_f, unsigned char>();
  test_op<OP_MIN, __vmins2_f, short>();
  test_op<OP_MIN, __vmins4_f, signed char>();
  test_op<OP_MIN, __vminu2_f, unsigned short>();
  test_op<OP_MIN, __vminu4_f, unsigned char>();
  test_op<OP_NEG, __vneg2_f, short>();
  test_op<OP_NEG, __vneg4_f, signed char>();
  test_op<OP_SAD, __vsads2_f, short>();
  test_op<OP_SAD, __vsads4_f, signed char>();
  test_op<OP_SAD, __vsadu2_f, unsigned short>();
  test_op<OP_SAD, __vsadu4_f, unsigned char>();
  test_op<OP_SETEQ, __vseteq2_f, short>();
  test_op<OP_SETEQ, __vseteq4_f, signed char>();
  test_op<OP_SETGE, __vsetges2_f, short>();
  test_op<OP_SETGE, __vsetges4_f, signed char>();
  test_op<OP_SETGE, __vsetgeu2_f, unsigned short>();
  test_op<OP_SETGE, __vsetgeu4_f, unsigned char>();
  test_op<OP_SETGT, __vsetgts2_f, short>();
  test_op<OP_SETGT, __vsetgts4_f, signed char>();
  test_op<OP_SETGT, __vsetgtu2_f, unsigned short>();
  test_op<OP_SETGT, __vsetgtu4_f, unsigned char>();
  test_op<OP_SETLE, __vsetles2_f, short>();
  test_op<OP_SETLE, __vsetles4_f, signed char>();
  test_op<OP_SETLE, __vsetleu2_f, unsigned short>();
  test_op<OP_SETLE, __vsetleu4_f, unsigned char>();
  test_op<OP_SETLT, __vsetlts2_f, short>();
  test_op<OP_SETLT, __vsetlts4_f, signed char>();
  test_op<OP_SETLT, __vsetltu2_f, unsigned short>();
  test_op<OP_SETLT, __vsetltu4_f, unsigned char>();
  test_op<OP_SETNE, __vsetne2_f, short>();
  test_op<OP_SETNE, __vsetne4_f, signed char>();
  test_op<OP_SUB, __vsub2_f, short>();
  test_op<OP_SUB, __vsub4_f, signed char>();
  test_op<OP_SUBS, __vsubss2_f, short>();
  test_op<OP_SUBS, __vsubss4_f, signed char>();
  test_op<OP_SUBS, __vsubus2_f, unsigned short>();
  test_op<OP_SUBS, __vsubus4_f, unsigned char>();
}
#else  // !C++11
void tests() {
  // These tests need C++11 to compile.
}
#endif

int main(int argc, char** argv) {
  int opt;
  while ((opt = getopt(argc, argv, "v")) != -1) {
    switch (opt) {
      case 'v':
        verbose = 1;
        break;
      default: /* '?' */
        fprintf(stderr, "Usage: %s [-v]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  }

  tests();
  printf("Success!\n");
  return 0;
}
