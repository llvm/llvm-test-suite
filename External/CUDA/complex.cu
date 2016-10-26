//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include <assert.h>
#include <stdio.h>
#include <complex>

// These are loosely adapted from libc++'s tests.  In general, we don't care a
// ton about verifying the return types or results we get, on the assumption
// that our standard library is correct. But we care deeply about calling every
// overload of every function (so that we verify that everything compiles).
//
// We do care about the results of complex multiplication / division, since
// these use code we've written.

// These tests are pretty annoying to write without C++11, so we require that.
// In addition, these tests currently don't compile with libc++, because of the
// issue in https://reviews.llvm.org/D25403.
//
// TODO: Once that issue is resolved, take out !defined(_LIBCPP_VERSION) here.
#if __cplusplus >= 201103L && !defined(_LIBCPP_VERSION)

#include <type_traits>

template <class T>
__device__ double promote(
    T, typename std::enable_if<std::is_integral<T>::value>::type* = 0);
__device__ float promote(float);
__device__ double promote(double);

__device__ void is_about(float x, float y) {
  assert(std::abs((x - y) / (x + y)) < 1.e-6);
}
__device__ void is_about(double x, double y) {
  assert(std::abs((x - y) / (x + y)) < 1.e-14);
}

template <class T>
__device__ void test_promotion_impl(T x) {
  assert(std::imag(x) == 0);
  assert(std::real(x) == x);

  using Promoted = decltype(promote(x));
  assert(std::arg(x) == arg(std::complex<Promoted>(x, 0)));
  assert(std::conj(x) == conj(std::complex<Promoted>(x, 0)));
  assert(std::norm(x) == norm(std::complex<Promoted>(x, 0)));
#ifndef __GLIBCXX__
  // libstdc++'s implementation of proj is completely broken, see
  // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=61761.
  assert(std::proj(x) == proj(std::complex<Promoted>(x, 0)));
#endif
}

__device__ void test_promotion() {
  int vals[] = {0, 1, 10};
  for (int i : vals) {
    test_promotion_impl<float>(i);
    test_promotion_impl<double>(i);
    test_promotion_impl<int>(i);
    test_promotion_impl<unsigned>(i);
    test_promotion_impl<long long>(i);
  }
}

__device__ void test_literals() {
#if __cplusplus >= 201402L
  using namespace std::literals::complex_literals;

  {
    std::complex<double> c1 = 3.0i;
    assert(c1 == std::complex<double>(0, 3.0));
    auto c2 = 3i;
    assert(c1 == c2);
  }

  {
    std::complex<float> c1 = 3.0if;
    assert(c1 == std::complex<float>(0, 3.0));
    auto c2 = 3if;
    assert(c1 == c2);
  }
#endif
}

template <class T>
__device__ void test_assignment_real() {
  std::complex<T> c;
  c = 1.5;
  assert(c.real() == 1.5);
  assert(c.imag() == 0);
}

template <class T, class U>
__device__ void test_assignment_complex() {
  std::complex<T> c;
  std::complex<T> c2(1.5, 2.5);
  c = c2;
  assert(c.real() == 1.5);
  assert(c.imag() == 2.5);
}

template <class T>
__device__ void test_plus_equals() {
  {
    std::complex<T> c;
    c += 1.5;
    assert(c.real() == 1.5);
    assert(c.imag() == 0);
  }

  {
    std::complex<T> c;
    const std::complex<T> c2(1.5, 2.5);
    c += c2;
    c += c2;
    assert(c.real() == 3);
    assert(c.imag() == 5);

    std::complex<T> c3;

    c3 = c;
    std::complex<int> ic(1, 1);
    c3 += ic;
    assert(c3.real() == 4);
    assert(c3.imag() == 6);

    c3 = c;
    std::complex<float> fc(1, 1);
    c3 += fc;
    assert(c3.real() == 4);
    assert(c3.imag() == 6);
  }
}

template <class T>
__device__ void test_minus_equals() {
  {
    std::complex<T> c;
    c -= 1.5;
    assert(c.real() == -1.5);
    assert(c.imag() == 0);
  }

  {
    std::complex<T> c;
    const std::complex<T> c2(1.5, 2.5);
    assert(c.real() == 0);
    assert(c.imag() == 0);
    c -= c2;
    assert(c.real() == -1.5);
    assert(c.imag() == -2.5);
    c -= c2;
    assert(c.real() == -3);
    assert(c.imag() == -5);

    std::complex<T> c3;

    c3 = c;
    std::complex<int> ic (1,1);
    c3 -= ic;
    assert(c3.real() == -4);
    assert(c3.imag() == -6);

    c3 = c;
    std::complex<float> fc (1,1);
    c3 -= fc;
    assert(c3.real() == -4);
    assert(c3.imag() == -6);
  }
}

template <class T>
__device__ void test_times_equals() {
  {
    std::complex<T> c(1);
    c *= 1.5;
    c *= 1.5;
    c *= -1.5;
    c.imag(2);
    c *= 1.5;
    assert(c.real() == -5.0625);
    assert(c.imag() == 3);
  }

  {
    std::complex<T> c(1);
    const std::complex<T> c2(1.5, 2.5);
    c *= c2;
    c *= c2;
    assert(c.real() == -4);
    assert(c.imag() == 7.5);

    std::complex<T> c3;

    c3 = c;
    std::complex<int> ic (1,1);
    c3 *= ic;
    assert(c3.real() == -11.5);
    assert(c3.imag() ==   3.5);

    c3 = c;
    std::complex<float> fc (1,1);
    c3 *= fc;
    assert(c3.real() == -11.5);
    assert(c3.imag() ==   3.5);
  }
}

template <class T>
__device__ void test_divide_equals() {
  {
    std::complex<T> c(1);
    c /= 0.5;
    c /= 0.5;
    c /= -0.5;
    c.imag(2);
    c /= 0.5;
    assert(c.real() == -16);
    assert(c.imag() == 4);
  }

  {
    std::complex<T> c(-4, 7.5);
    const std::complex<T> c2(1.5, 2.5);
    assert(c.real() == -4);
    assert(c.imag() == 7.5);
    c /= c2;
    assert(c.real() == 1.5);
    assert(c.imag() == 2.5);
    c /= c2;
    assert(c.real() == 1);
    assert(c.imag() == 0);

    std::complex<T> c3;

    c3 = c;
    std::complex<int> ic (1,1);
    c3 /= ic;
    assert(c3.real() ==  0.5);
    assert(c3.imag() == -0.5);

    c3 = c;
    std::complex<float> fc (1,1);
    c3 /= fc;
    assert(c3.real() ==  0.5);
    assert(c3.imag() == -0.5);
  }
}

template <class T>
__device__ void test_construct() {
  {
    const std::complex<T> c;
    assert(c.real() == 0);
    assert(c.imag() == 0);
  }
  {
    const std::complex<T> c = 7.5;
    assert(c.real() == 7.5);
    assert(c.imag() == 0);
  }
  {
    const std::complex<T> c(8.5);
    assert(c.real() == 8.5);
    assert(c.imag() == 0);
  }
  {
    const std::complex<T> c(10.5, -9.5);
    assert(c.real() == 10.5);
    assert(c.imag() == -9.5);
  }
#if __cplusplus >= 201103L
  {
    constexpr std::complex<T> c;
    static_assert(c.real() == 0, "");
    static_assert(c.imag() == 0, "");
  }
  {
    constexpr std::complex<T> c = 7.5;
    static_assert(c.real() == 7.5, "");
    static_assert(c.imag() == 0, "");
  }
  {
    constexpr std::complex<T> c(8.5);
    static_assert(c.real() == 8.5, "");
    static_assert(c.imag() == 0, "");
  }
  {
    constexpr std::complex<T> c(10.5, -9.5);
    static_assert(c.real() == 10.5, "");
    static_assert(c.imag() == -9.5, "");
  }
#endif
}

template <class T>
__device__ void test_construct_integral() {
#if __cplusplus >= 201402L
  constexpr std::complex<T> c1;
  static_assert(c1.real() == 0, "");
  static_assert(c1.imag() == 0, "");
  constexpr std::complex<T> c2(3);
  static_assert(c2.real() == 3, "");
  static_assert(c2.imag() == 0, "");
  constexpr std::complex<T> c3(3, 4);
  static_assert(c3.real() == 3, "");
  static_assert(c3.imag() == 4, "");
#endif
}

template <class T>
__device__ void test_set_real_imag() {
  std::complex<T> c;
  c.real(3.5);
  assert(c.real() == 3.5);
  assert(c.imag() == 0);
  c.imag(4.5);
  assert(c.real() == 3.5);
  assert(c.imag() == 4.5);
}

template <class T>
__device__ void test_transcendentals_etc() {
  assert(sin(std::complex<T>(0, 0)) == std::complex<T>(0, 0));
  assert(sinh(std::complex<T>(0, 0)) == std::complex<T>(0, 0));
  assert(asin(std::complex<T>(0, 0)) == std::complex<T>(0, 0));
  assert(asinh(std::complex<T>(0, 0)) == std::complex<T>(0, 0));

  assert(cos(std::complex<T>(0, 0)) == std::complex<T>(1, 0));
  assert(cosh(std::complex<T>(0, 0)) == std::complex<T>(1, 0));
  {
    std::complex<T> c = acos(std::complex<T>(0, 0));
    is_about(real(c), T(M_PI_2));
    assert(std::abs(imag(c)) < 1.e-6);
  }
  {
    std::complex<T> c = acosh(std::complex<T>(0, 0));
    assert(std::abs(real(c)) < 1.e-6);
    is_about(imag(c), T(M_PI_2));
  }

  assert(tan(std::complex<T>(0, 0)) == std::complex<T>(0, 0));
  assert(tanh(std::complex<T>(0, 0)) == std::complex<T>(0, 0));
  assert(atan(std::complex<T>(0, 0)) == std::complex<T>(0, 0));
  assert(atanh(std::complex<T>(0, 0)) == std::complex<T>(0, 0));

  assert(exp(std::complex<T>(0, 0)) == std::complex<T>(1, 0));
  assert(log10(std::complex<T>(0, 0)) == std::complex<T>(-INFINITY, 0));
  assert(log(std::complex<T>(0, 0)) == std::complex<T>(-INFINITY, 0));

  {
    std::complex<T> c = pow(std::complex<T>(2, 3), std::complex<T>(2, 0));
    is_about(real(c), -5);
    is_about(imag(c), 12);
  }
  {
    std::complex<T> c = pow(std::complex<T>(2, 3), T(2));
    is_about(real(c), -5);
    is_about(imag(c), 12);
  }
  {
    std::complex<T> c = pow(T(2), std::complex<T>(2));
    is_about(real(c), 4);
    assert(std::abs(imag(c)) < 1.e-6);
  }
  {
    std::complex<T> c = sqrt(std::complex<T>(64, 0));
    is_about(real(c), 8);
    assert(std::abs(imag(c)) < 1.e-6);
  }

  // "etc."
  assert(abs(std::complex<T>(3, 4)) == 5);
  assert(norm(std::complex<T>(3, 4)) == 25);
  assert(arg(std::complex<T>(1, 0)) == 0);
  assert(conj(std::complex<T>(1, 2)) == std::complex<T>(1, -2));

  assert(std::polar(T(0)) == std::complex<T>(0, 0));
  assert(std::polar(T(1)) == std::complex<T>(1, 0));
  assert(std::polar(T(100)) == std::complex<T>(100, 0));
  assert(std::polar(T(0), T(0)) == std::complex<T>(0, 0));
  assert(std::polar(T(1), T(0)) == std::complex<T>(1, 0));
  assert(std::polar(T(100), T(0)) == std::complex<T>(100, 0));

#ifndef __GLIBCXX__
  // libstdc++'s implementation of proj is completely broken, see
  // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=61761.
  assert(std::proj(std::complex<T>(1, 2)) == std::complex<T>(1, 2));
  assert(std::proj(std::complex<T>(-1, 2)) == std::complex<T>(-1, 2));
  assert(std::proj(std::complex<T>(1, -2)) == std::complex<T>(1, -2));
  assert(std::proj(std::complex<T>(-1, -2)) == std::complex<T>(-1, -2));
#endif
}

__global__ void tests() {
  test_promotion();
  test_literals();
  test_assignment_real<float>();
  test_assignment_real<double>();

  test_assignment_complex<float, float>();
  test_assignment_complex<float, double>();
  test_assignment_complex<double, float>();
  test_assignment_complex<double, double>();

  test_plus_equals<float>();
  test_plus_equals<double>();
  test_minus_equals<float>();
  test_minus_equals<double>();
  test_times_equals<float>();
  test_times_equals<double>();
  test_divide_equals<float>();
  test_divide_equals<double>();

  test_construct<float>();
  test_construct<double>();
  test_construct_integral<int>();

  test_set_real_imag<float>();
  test_set_real_imag<double>();

  test_transcendentals_etc<float>();
  test_transcendentals_etc<double>();
}
#else
__global__ void tests() {}
#endif

int main() {
  tests<<<1, 1>>>();
  cudaError_t err = cudaDeviceSynchronize();
  if (err != cudaSuccess) {
    printf("CUDA error %d\n", (int)err);
    return 1;
  }
  printf("Success!\n");
  return 0;
}
