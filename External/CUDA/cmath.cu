//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// This file was copied from libc++'s test suite, then modified to test CUDA.
// For the most part, this consists of adding __device__ attributes and
// deleting long double.

// <cmath>

// This test requires c++11 (it's mostly decltype stuff).

#if __cplusplus >= 201103L

#include <cmath>
#include <type_traits>
#include <cassert>
#include <stdio.h>

// See PR21083
// Ambiguous is a user-defined type that defines its own overloads of cmath
// functions. When the std overloads are candidates too (by using or adl),
// they should not interfere.
struct Ambiguous : std::true_type { // ADL
    __device__ operator float () { return 0.f; }
    __device__ operator double () { return 0.; }
};
__device__ Ambiguous abs(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous acos(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous asin(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous atan(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous atan2(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous ceil(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous cos(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous cosh(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous exp(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous fabs(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous floor(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous fmod(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous frexp(Ambiguous, int*){ return Ambiguous(); }
__device__ Ambiguous ldexp(Ambiguous, int){ return Ambiguous(); }
__device__ Ambiguous log(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous log10(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous modf(Ambiguous, Ambiguous*){ return Ambiguous(); }
__device__ Ambiguous pow(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous sin(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous sinh(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous sqrt(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous tan(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous tanh(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous signbit(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous fpclassify(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous isfinite(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous isnormal(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous isgreater(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous isgreaterequal(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous isless(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous islessequal(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous islessgreater(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous isunordered(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous acosh(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous asinh(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous atanh(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous cbrt(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous copysign(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous erf(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous erfc(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous exp2(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous expm1(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous fdim(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous fma(Ambiguous, Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous fmax(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous fmin(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous hypot(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous hypot(Ambiguous, Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous ilogb(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous lgamma(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous llrint(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous llround(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous log1p(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous log2(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous logb(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous lrint(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous lround(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous nearbyint(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous nextafter(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous nexttoward(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous remainder(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous remquo(Ambiguous, Ambiguous, int*){ return Ambiguous(); }
__device__ Ambiguous rint(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous round(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous scalbln(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous scalbn(Ambiguous, Ambiguous){ return Ambiguous(); }
__device__ Ambiguous tgamma(Ambiguous){ return Ambiguous(); }
__device__ Ambiguous trunc(Ambiguous){ return Ambiguous(); }

__device__ void test_abs()
{
    static_assert((std::is_same<decltype(std::abs((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::abs((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(abs(Ambiguous())), Ambiguous>::value), "");
    assert(std::abs(-1) == 1);
    assert(std::abs(-1.) == 1);
    assert(std::abs(-1.f) == 1);
}

__device__ void test_acos()
{
    static_assert((std::is_same<decltype(std::acos((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::acos((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acos((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acos((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acos((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acos((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acos((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acos((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acos((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acos((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acosf(0)), float>::value), "");
    static_assert((std::is_same<decltype(acos(Ambiguous())), Ambiguous>::value), "");
    assert(std::acos(1) == 0);
    assert(std::acos(1.) == 0);
    assert(std::acos(1.f) == 0);
}

__device__ void test_asin()
{
    static_assert((std::is_same<decltype(std::asin((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::asin((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asin((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asin((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asin((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asin((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asin((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asin((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asin((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asin((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asinf(0)), float>::value), "");
    static_assert((std::is_same<decltype(asin(Ambiguous())), Ambiguous>::value), "");
    assert(std::asin(0) == 0);
    assert(std::asin(0.) == 0);
    assert(std::asin(0.f) == 0);
}

__device__ void test_atan()
{
    static_assert((std::is_same<decltype(std::atan((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::atan((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atanf(0)), float>::value), "");
    static_assert((std::is_same<decltype(atan(Ambiguous())), Ambiguous>::value), "");
    assert(std::atan(0) == 0);
    assert(std::atan(0.) == 0);
    assert(std::atan(0.f) == 0);
}

__device__ void test_atan2()
{
    static_assert((std::is_same<decltype(std::atan2((float)0, (float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::atan2((bool)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan2((unsigned short)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan2((float)0, (unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan2((double)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan2((int)0, (long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan2((int)0, (unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan2((double)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan2((float)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atan2f(0,0)), float>::value), "");
    static_assert((std::is_same<decltype(std::atan2((int)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(atan2(Ambiguous(), Ambiguous())), Ambiguous>::value), "");

    assert(std::atan2(0, 1) == 0);
    assert(std::atan2(0, 1.) == 0);
    assert(std::atan2(0, 1.f) == 0);

    assert(std::atan2(0., 1) == 0);
    assert(std::atan2(0., 1.) == 0);
    assert(std::atan2(0., 1.f) == 0);

    assert(std::atan2(0.f, 1) == 0);
    assert(std::atan2(0.f, 1.) == 0);
    assert(std::atan2(0.f, 1.f) == 0);
}

__device__ void test_ceil()
{
    static_assert((std::is_same<decltype(std::ceil((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::ceil((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::ceil((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::ceil((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::ceil((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::ceil((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::ceil((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::ceil((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::ceil((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::ceil((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::ceilf(0)), float>::value), "");
    static_assert((std::is_same<decltype(ceil(Ambiguous())), Ambiguous>::value), "");
    assert(std::ceil(0) == 0);
    assert(std::ceil(0.) == 0);
    assert(std::ceil(0.f) == 0);
}

__device__ void test_cos()
{
    static_assert((std::is_same<decltype(std::cos((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::cos((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cos((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cos((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cos((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cos((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cos((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cos((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cos((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cos((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cosf(0)), float>::value), "");
    static_assert((std::is_same<decltype(cos(Ambiguous())), Ambiguous>::value), "");
    assert(std::cos(0) == 1);
    assert(std::cos(0.) == 1);
    assert(std::cos(0.f) == 1);
}

__device__ void test_cosh()
{
    static_assert((std::is_same<decltype(std::cosh((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::cosh((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cosh((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cosh((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cosh((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cosh((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cosh((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cosh((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cosh((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cosh((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::coshf(0)), float>::value), "");
    static_assert((std::is_same<decltype(cosh(Ambiguous())), Ambiguous>::value), "");
    assert(std::cosh(0) == 1);
    assert(std::cosh(0.) == 1);
    assert(std::cosh(0.f) == 1);
}

__device__ void test_exp()
{
    static_assert((std::is_same<decltype(std::exp((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::exp((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::expf(0)), float>::value), "");
    static_assert((std::is_same<decltype(exp(Ambiguous())), Ambiguous>::value), "");
    assert(std::exp(0) == 1);
    assert(std::exp(0.) == 1);
    assert(std::exp(0.f) == 1);
}

__device__ void test_fabs()
{
    static_assert((std::is_same<decltype(std::fabs((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::fabs((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fabs((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fabs((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fabs((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fabs((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fabs((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fabs((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fabs((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fabs((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fabsf(0.0f)), float>::value), "");
    static_assert((std::is_same<decltype(fabs(Ambiguous())), Ambiguous>::value), "");
    assert(std::fabs(-1) == 1);
    assert(std::fabs(-1.) == 1);
    assert(std::fabs(-1.f) == 1);
}

__device__ void test_floor()
{
    static_assert((std::is_same<decltype(std::floor((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::floor((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::floor((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::floor((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::floor((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::floor((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::floor((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::floor((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::floor((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::floor((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::floorf(0)), float>::value), "");
    static_assert((std::is_same<decltype(floor(Ambiguous())), Ambiguous>::value), "");
    assert(std::floor(1) == 1);
    assert(std::floor(1.) == 1);
    assert(std::floor(1.f) == 1);
}

__device__ void test_fmod()
{
    static_assert((std::is_same<decltype(std::fmod((float)0, (float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::fmod((bool)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmod((unsigned short)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmod((float)0, (unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmod((double)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmod((int)0, (long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmod((int)0, (unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmod((double)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmod((float)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmodf(0,0)), float>::value), "");
    static_assert((std::is_same<decltype(std::fmod((int)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(fmod(Ambiguous(), Ambiguous())), Ambiguous>::value), "");

    assert(std::fmod(1.5, 1) == .5);
    assert(std::fmod(1.5, 1.) == .5);
    assert(std::fmod(1.5, 1.f) == .5);

    assert(std::fmod(1.5f, 1) == .5);
    assert(std::fmod(1.5f, 1.) == .5);
    assert(std::fmod(1.5f, 1.f) == .5);

    assert(std::fmod(2, 1) == 0);
    assert(std::fmod(2, 1.) == 0);
    assert(std::fmod(2, 1.f) == 0);
}

__device__ void test_frexp()
{
    int ip;
    static_assert((std::is_same<decltype(std::frexp((float)0, &ip)), float>::value), "");
    static_assert((std::is_same<decltype(std::frexp((bool)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::frexp((unsigned short)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::frexp((int)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::frexp((unsigned int)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::frexp((long)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::frexp((unsigned long)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::frexp((long long)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::frexp((unsigned long long)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::frexp((double)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::frexpf(0, &ip)), float>::value), "");
    static_assert((std::is_same<decltype(frexp(Ambiguous(), &ip)), Ambiguous>::value), "");
    assert(std::frexp(0, &ip) == 0);
    assert(std::frexp(0., &ip) == 0);
    assert(std::frexp(0.f, &ip) == 0);
}

__device__ void test_ldexp()
{
    int ip = 1;
    static_assert((std::is_same<decltype(std::ldexp((float)0, ip)), float>::value), "");
    static_assert((std::is_same<decltype(std::ldexp((bool)0, ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::ldexp((unsigned short)0, ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::ldexp((int)0, ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::ldexp((unsigned int)0, ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::ldexp((long)0, ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::ldexp((unsigned long)0, ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::ldexp((long long)0, ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::ldexp((unsigned long long)0, ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::ldexp((double)0, ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::ldexpf(0, ip)), float>::value), "");
    static_assert((std::is_same<decltype(ldexp(Ambiguous(), ip)), Ambiguous>::value), "");
    assert(std::ldexp(1, ip) == 2);
    assert(std::ldexp(1., ip) == 2);
    assert(std::ldexp(1.f, ip) == 2);
}

__device__ void test_log()
{
    static_assert((std::is_same<decltype(std::log((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::log((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::logf(0)), float>::value), "");
    static_assert((std::is_same<decltype(log(Ambiguous())), Ambiguous>::value), "");
    assert(std::log(1) == 0);
    assert(std::log(1.) == 0);
    assert(std::log(1.f) == 0);
}

__device__ void test_log10()
{
    static_assert((std::is_same<decltype(std::log10((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::log10((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log10((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log10((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log10((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log10((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log10((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log10((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log10((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log10((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log10f(0)), float>::value), "");
    static_assert((std::is_same<decltype(log10(Ambiguous())), Ambiguous>::value), "");
    assert(std::log10(1) == 0);
    assert(std::log10(1.) == 0);
    assert(std::log10(1.f) == 0);
}

__device__ void test_modf()
{
    static_assert((std::is_same<decltype(std::modf((float)0, (float*)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::modf((double)0, (double*)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::modff(0, (float*)0)), float>::value), "");
    static_assert((std::is_same<decltype(modf(Ambiguous(), (Ambiguous*)0)), Ambiguous>::value), "");
    double i;
    assert(std::modf(1, &i) == 0);
    assert(std::modf(1., &i) == 0);
    assert(std::modf(1.f, &i) == 0);
}

__device__ void test_pow()
{
    static_assert((std::is_same<decltype(std::pow((float)0, (float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::pow((bool)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::pow((unsigned short)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::pow((float)0, (unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::pow((double)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::pow((int)0, (long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::pow((int)0, (unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::pow((double)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::pow((float)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::powf(0,0)), float>::value), "");
    static_assert((std::is_same<decltype(std::pow((int)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(pow(Ambiguous(), Ambiguous())), Ambiguous>::value), "");
    assert(std::pow(1, 1) == 1);
    assert(std::pow(1., 1) == 1);
    assert(std::pow(1.f, 1) == 1);

    assert(std::pow(1, 1.) == 1);
    assert(std::pow(1., 1.) == 1);
    assert(std::pow(1.f, 1.) == 1);

    assert(std::pow(1, 1.f) == 1);
    assert(std::pow(1., 1.f) == 1);
    assert(std::pow(1.f, 1.f) == 1);
}

__device__ void test_sin()
{
    static_assert((std::is_same<decltype(std::sin((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::sin((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sin((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sin((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sin((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sin((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sin((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sin((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sin((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sin((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sinf(0)), float>::value), "");
    static_assert((std::is_same<decltype(sin(Ambiguous())), Ambiguous>::value), "");
    assert(std::sin(0) == 0);
    assert(std::sin(0.) == 0);
    assert(std::sin(0.f) == 0);
}

__device__ void test_sinh()
{
    static_assert((std::is_same<decltype(std::sinh((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::sinh((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sinh((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sinh((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sinh((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sinh((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sinh((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sinh((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sinh((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sinh((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sinhf(0)), float>::value), "");
    static_assert((std::is_same<decltype(sinh(Ambiguous())), Ambiguous>::value), "");
    assert(std::sinh(0) == 0);
    assert(std::sinh(0.) == 0);
    assert(std::sinh(0.f) == 0);
}

__device__ void test_sqrt()
{
    static_assert((std::is_same<decltype(std::sqrt((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::sqrt((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sqrt((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sqrt((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sqrt((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sqrt((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sqrt((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sqrt((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sqrt((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sqrt((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::sqrtf(0)), float>::value), "");
    static_assert((std::is_same<decltype(sqrt(Ambiguous())), Ambiguous>::value), "");
    assert(std::sqrt(4) == 2);
    assert(std::sqrt(4.) == 2);
    assert(std::sqrt(4.f) == 2);
}

__device__ void test_tan()
{
    static_assert((std::is_same<decltype(std::tan((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::tan((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tan((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tan((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tan((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tan((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tan((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tan((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tan((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tan((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tanf(0)), float>::value), "");
    static_assert((std::is_same<decltype(tan(Ambiguous())), Ambiguous>::value), "");
    assert(std::tan(0) == 0);
    assert(std::tan(0.) == 0);
    assert(std::tan(0.f) == 0);
}

__device__ void test_tanh()
{
    static_assert((std::is_same<decltype(std::tanh((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::tanh((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tanh((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tanh((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tanh((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tanh((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tanh((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tanh((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tanh((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tanh((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tanhf(0)), float>::value), "");
    static_assert((std::is_same<decltype(tanh(Ambiguous())), Ambiguous>::value), "");
    assert(std::tanh(0) == 0);
    assert(std::tanh(0.) == 0);
    assert(std::tanh(0.f) == 0);
}

__device__ void test_signbit()
{
#ifdef signbit
#error signbit defined
#endif
    static_assert((std::is_same<decltype(std::signbit((float)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::signbit((double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::signbit(0)), bool>::value), "");
    static_assert((std::is_same<decltype(signbit(Ambiguous())), Ambiguous>::value), "");
    assert(std::signbit(-1) == true);
    assert(std::signbit(-1.) == true);
    assert(std::signbit(-1.f) == true);
}

__device__ void test_fpclassify()
{
#ifdef fpclassify
#error fpclassify defined
#endif
    static_assert((std::is_same<decltype(std::fpclassify((float)0)), int>::value), "");
    static_assert((std::is_same<decltype(std::fpclassify((double)0)), int>::value), "");
    static_assert((std::is_same<decltype(std::fpclassify(0)), int>::value), "");
    static_assert((std::is_same<decltype(fpclassify(Ambiguous())), Ambiguous>::value), "");
    assert(std::fpclassify(-1) == FP_NORMAL);
    assert(std::fpclassify(-1.) == FP_NORMAL);
    assert(std::fpclassify(-1.f) == FP_NORMAL);
}

__device__ void test_isfinite()
{
#ifdef isfinite
#error isfinite defined
#endif
    static_assert((std::is_same<decltype(std::isfinite((float)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isfinite((double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isfinite(0)), bool>::value), "");
    static_assert((std::is_same<decltype(isfinite(Ambiguous())), Ambiguous>::value), "");
    assert(std::isfinite(-1) == true);
    assert(std::isfinite(-1.) == true);
    assert(std::isfinite(-1.f) == true);
}

__device__ void test_isnormal()
{
#ifdef isnormal
#error isnormal defined
#endif
    static_assert((std::is_same<decltype(std::isnormal((float)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isnormal((double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isnormal(0)), bool>::value), "");
    static_assert((std::is_same<decltype(isnormal(Ambiguous())), Ambiguous>::value), "");
    assert(std::isnormal(-1) == true);
    assert(std::isnormal(-1.) == true);
    assert(std::isnormal(-1.f) == true);
}

__device__ void test_isgreater()
{
#ifdef isgreater
#error isgreater defined
#endif
    static_assert((std::is_same<decltype(std::isgreater((float)0, (float)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isgreater((float)0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isgreater((double)0, (float)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isgreater((double)0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isgreater(0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(isgreater(Ambiguous(), Ambiguous())), Ambiguous>::value), "");
    assert(std::isgreater(-1, 0) == false);
    assert(std::isgreater(-1, 0.) == false);
    assert(std::isgreater(-1, 0.f) == false);

    assert(std::isgreater(-1., 0) == false);
    assert(std::isgreater(-1., 0.) == false);
    assert(std::isgreater(-1., 0.f) == false);

    assert(std::isgreater(-1.f, 0) == false);
    assert(std::isgreater(-1.f, 0.) == false);
    assert(std::isgreater(-1.f, 0.f) == false);
}

__device__ void test_isgreaterequal()
{
#ifdef isgreaterequal
#error isgreaterequal defined
#endif
    static_assert((std::is_same<decltype(std::isgreaterequal((float)0, (float)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isgreaterequal((float)0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isgreaterequal((double)0, (float)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isgreaterequal((double)0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isgreaterequal(0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(isgreaterequal(Ambiguous(), Ambiguous())), Ambiguous>::value), "");
    assert(std::isgreaterequal(-1, 0) == false);
    assert(std::isgreaterequal(-1, 0.) == false);
    assert(std::isgreaterequal(-1, 0.f) == false);

    assert(std::isgreaterequal(-1., 0) == false);
    assert(std::isgreaterequal(-1., 0.) == false);
    assert(std::isgreaterequal(-1., 0.f) == false);

    assert(std::isgreaterequal(-1.f, 0) == false);
    assert(std::isgreaterequal(-1.f, 0.) == false);
    assert(std::isgreaterequal(-1.f, 0.f) == false);
}

__device__ void test_isinf()
{
#ifdef isinf
#error isinf defined
#endif
    static_assert((std::is_same<decltype(std::isinf((float)0)), bool>::value), "");

    typedef decltype(std::isinf((double)0)) DoubleRetType;
#ifndef __linux__
    static_assert((std::is_same<DoubleRetType, bool>::value), "");
#else
    // GLIBC < 2.26 defines 'isinf(double)' with a return type of 'int' in
    // all C++ dialects. The test should tolerate this.
    // See: https://sourceware.org/bugzilla/show_bug.cgi?id=19439
    static_assert((std::is_same<DoubleRetType, bool>::value
                || std::is_same<DoubleRetType, int>::value), "");
#endif

    static_assert((std::is_same<decltype(std::isinf(0)), bool>::value), "");
    assert(std::isinf(-1) == false);
    assert(std::isinf(-1.) == false);
    assert(std::isinf(-1.f) == false);
}

__device__ void test_isless()
{
#ifdef isless
#error isless defined
#endif
    static_assert((std::is_same<decltype(std::isless((float)0, (float)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isless((float)0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isless((double)0, (float)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isless((double)0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isless(0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(isless(Ambiguous(), Ambiguous())), Ambiguous>::value), "");
    assert(std::isless(-1, 0) == true);
    assert(std::isless(-1, 0.) == true);
    assert(std::isless(-1, 0.f) == true);

    assert(std::isless(-1., 0) == true);
    assert(std::isless(-1., 0.) == true);
    assert(std::isless(-1., 0.f) == true);

    assert(std::isless(-1.f, 0) == true);
    assert(std::isless(-1.f, 0.) == true);
    assert(std::isless(-1.f, 0.f) == true);
}

__device__ void test_islessequal()
{
#ifdef islessequal
#error islessequal defined
#endif
    static_assert((std::is_same<decltype(std::islessequal((float)0, (float)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::islessequal((float)0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::islessequal((double)0, (float)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::islessequal((double)0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::islessequal(0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(islessequal(Ambiguous(), Ambiguous())), Ambiguous>::value), "");
    assert(std::islessequal(-1, 0) == true);
    assert(std::islessequal(-1, 0.) == true);
    assert(std::islessequal(-1, 0.f) == true);

    assert(std::islessequal(-1., 0) == true);
    assert(std::islessequal(-1., 0.) == true);
    assert(std::islessequal(-1., 0.f) == true);

    assert(std::islessequal(-1.f, 0) == true);
    assert(std::islessequal(-1.f, 0.) == true);
    assert(std::islessequal(-1.f, 0.f) == true);
}

__device__ void test_islessgreater()
{
#ifdef islessgreater
#error islessgreater defined
#endif
    static_assert((std::is_same<decltype(std::islessgreater((float)0, (float)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::islessgreater((float)0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::islessgreater((double)0, (float)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::islessgreater((double)0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::islessgreater(0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(islessgreater(Ambiguous(), Ambiguous())), Ambiguous>::value), "");
    assert(std::islessgreater(-1, 0) == true);
    assert(std::islessgreater(-1, 0.) == true);
    assert(std::islessgreater(-1, 0.f) == true);

    assert(std::islessgreater(-1., 0) == true);
    assert(std::islessgreater(-1., 0.) == true);
    assert(std::islessgreater(-1., 0.f) == true);

    assert(std::islessgreater(-1.f, 0) == true);
    assert(std::islessgreater(-1.f, 0.) == true);
    assert(std::islessgreater(-1.f, 0.f) == true);
}

__device__ void test_isnan()
{
#ifdef isnan
#error isnan defined
#endif
    static_assert((std::is_same<decltype(std::isnan((float)0)), bool>::value), "");

    typedef decltype(std::isnan((double)0)) DoubleRetType;
#ifndef __linux__
    static_assert((std::is_same<DoubleRetType, bool>::value), "");
#else
    // GLIBC < 2.26 defines 'isnan(double)' with a return type of 'int' in
    // all C++ dialects. The test should tolerate this.
    // See: https://sourceware.org/bugzilla/show_bug.cgi?id=19439
    static_assert((std::is_same<DoubleRetType, bool>::value
                || std::is_same<DoubleRetType, int>::value), "");
#endif

    static_assert((std::is_same<decltype(std::isnan(0)), bool>::value), "");
    assert(std::isnan(-1) == false);
    assert(std::isnan(-1.) == false);
    assert(std::isnan(-1.f) == false);
}

__device__ void test_isunordered()
{
#ifdef isunordered
#error isunordered defined
#endif
    static_assert((std::is_same<decltype(std::isunordered((float)0, (float)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isunordered((float)0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isunordered((double)0, (float)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isunordered((double)0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(std::isunordered(0, (double)0)), bool>::value), "");
    static_assert((std::is_same<decltype(isunordered(Ambiguous(), Ambiguous())), Ambiguous>::value), "");
    assert(std::isunordered(-1, 0) == false);
    assert(std::isunordered(-1, 0.) == false);
    assert(std::isunordered(-1, 0.f) == false);

    assert(std::isunordered(-1., 0) == false);
    assert(std::isunordered(-1., 0.) == false);
    assert(std::isunordered(-1., 0.f) == false);

    assert(std::isunordered(-1.f, 0) == false);
    assert(std::isunordered(-1.f, 0.) == false);
    assert(std::isunordered(-1.f, 0.f) == false);
}

__device__ void test_acosh()
{
    static_assert((std::is_same<decltype(std::acosh((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::acosh((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acosh((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acosh((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acosh((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acosh((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acosh((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acosh((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acosh((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acosh((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::acoshf(0)), float>::value), "");
    static_assert((std::is_same<decltype(acosh(Ambiguous())), Ambiguous>::value), "");
    assert(std::acosh(1) == 0);
    assert(std::acosh(1.) == 0);
    assert(std::acosh(1.f) == 0);
}

__device__ void test_asinh()
{
    static_assert((std::is_same<decltype(std::asinh((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::asinh((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asinh((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asinh((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asinh((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asinh((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asinh((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asinh((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asinh((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asinh((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::asinhf(0)), float>::value), "");
    static_assert((std::is_same<decltype(asinh(Ambiguous())), Ambiguous>::value), "");
    assert(std::asinh(0) == 0);
    assert(std::asinh(0.) == 0);
    assert(std::asinh(0.f) == 0);
}

__device__ void test_atanh()
{
    static_assert((std::is_same<decltype(std::atanh((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::atanh((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atanh((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atanh((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atanh((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atanh((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atanh((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atanh((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atanh((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atanh((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::atanhf(0)), float>::value), "");
    static_assert((std::is_same<decltype(atanh(Ambiguous())), Ambiguous>::value), "");
    assert(std::atanh(0) == 0);
    assert(std::atanh(0.) == 0);
    assert(std::atanh(0.f) == 0);
}

__device__ void test_cbrt()
{
    static_assert((std::is_same<decltype(std::cbrt((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::cbrt((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cbrt((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cbrt((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cbrt((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cbrt((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cbrt((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cbrt((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cbrt((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cbrt((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::cbrtf(0)), float>::value), "");
    static_assert((std::is_same<decltype(cbrt(Ambiguous())), Ambiguous>::value), "");
    assert(std::cbrt(1) == 1);
    assert(std::cbrt(1.) == 1);
    assert(std::cbrt(1.f) == 1);
}

__device__ void test_copysign()
{
    static_assert((std::is_same<decltype(std::copysign((float)0, (float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::copysign((bool)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::copysign((unsigned short)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::copysign((float)0, (unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::copysign((double)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::copysign((int)0, (long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::copysign((int)0, (unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::copysign((double)0, (double)0)), double>::value), "");
    // CUDA's copysign(float, double) returns a float.  This is not per spec,
    // but it's kind of reasonable -- given that copysign just copies the sign
    // of the LHS to the RHS, there's no reason that we should have to promote
    // the LHS from float to double.
    //static_assert((std::is_same<decltype(std::copysign((float)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::copysignf(0,0)), float>::value), "");
    static_assert((std::is_same<decltype(std::copysign((int)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(copysign(Ambiguous(), Ambiguous())), Ambiguous>::value), "");

    assert(std::copysign(1, 1) == 1);
    assert(std::copysign(1., 1) == 1);
    assert(std::copysign(1.f, 1) == 1);

    assert(std::copysign(1, 1.) == 1);
    assert(std::copysign(1., 1.) == 1);
    assert(std::copysign(1.f, 1.) == 1);

    assert(std::copysign(1, 1.f) == 1);
    assert(std::copysign(1., 1.f) == 1);
    assert(std::copysign(1.f, 1.f) == 1);
}

__device__ void test_erf()
{
    static_assert((std::is_same<decltype(std::erf((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::erf((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erf((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erf((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erf((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erf((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erf((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erf((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erf((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erf((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erff(0)), float>::value), "");
    static_assert((std::is_same<decltype(erf(Ambiguous())), Ambiguous>::value), "");
    assert(std::erf(0) == 0);
    assert(std::erf(0.) == 0);
    assert(std::erf(0.f) == 0);
}

__device__ void test_erfc()
{
    static_assert((std::is_same<decltype(std::erfc((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::erfc((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erfc((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erfc((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erfc((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erfc((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erfc((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erfc((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erfc((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erfc((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::erfcf(0)), float>::value), "");
    static_assert((std::is_same<decltype(erfc(Ambiguous())), Ambiguous>::value), "");
    assert(std::erfc(0) == 1);
    assert(std::erfc(0.) == 1);
    assert(std::erfc(0.f) == 1);
}

__device__ void test_exp2()
{
    static_assert((std::is_same<decltype(std::exp2((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::exp2((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp2((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp2((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp2((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp2((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp2((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp2((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp2((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp2((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::exp2f(0)), float>::value), "");
    static_assert((std::is_same<decltype(exp2(Ambiguous())), Ambiguous>::value), "");
    assert(std::exp2(1) == 2);
    assert(std::exp2(1.) == 2);
    assert(std::exp2(1.f) == 2);
}

__device__ void test_expm1()
{
    static_assert((std::is_same<decltype(std::expm1((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::expm1((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::expm1((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::expm1((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::expm1((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::expm1((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::expm1((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::expm1((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::expm1((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::expm1((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::expm1f(0)), float>::value), "");
    static_assert((std::is_same<decltype(expm1(Ambiguous())), Ambiguous>::value), "");
    assert(std::expm1(0) == 0);
    assert(std::expm1(0.) == 0);
    assert(std::expm1(0.f) == 0);
}

__device__ void test_fdim()
{
    static_assert((std::is_same<decltype(std::fdim((float)0, (float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::fdim((bool)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fdim((unsigned short)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fdim((float)0, (unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fdim((double)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fdim((int)0, (long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fdim((int)0, (unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fdim((double)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fdim((float)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fdimf(0,0)), float>::value), "");
    static_assert((std::is_same<decltype(std::fdim((int)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(fdim(Ambiguous(), Ambiguous())), Ambiguous>::value), "");

    assert(std::fdim(1, 0) == 1);
    assert(std::fdim(1., 0) == 1);
    assert(std::fdim(1.f, 0) == 1);

    assert(std::fdim(1, 0.) == 1);
    assert(std::fdim(1., 0.) == 1);
    assert(std::fdim(1.f, 0.) == 1);

    assert(std::fdim(1, 0.f) == 1);
    assert(std::fdim(1., 0.f) == 1);
    assert(std::fdim(1.f, 0.f) == 1);
}

__device__ void test_fma()
{
    static_assert((std::is_same<decltype(std::fma((bool)0, (float)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fma((char)0, (float)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fma((unsigned)0, (float)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fma((float)0, (int)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fma((float)0, (long)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fma((float)0, (float)0, (unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fma((float)0, (float)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fma((float)0, (float)0, (float)0)), float>::value), "");

    static_assert((std::is_same<decltype(std::fma((bool)0, (double)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fma((char)0, (double)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fma((unsigned)0, (double)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fma((double)0, (int)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fma((double)0, (long)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fma((double)0, (double)0, (unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fma((double)0, (double)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fma((double)0, (double)0,  (double)0)), double>::value), "");


    static_assert((std::is_same<decltype(std::fmaf(0,0,0)), float>::value), "");
    static_assert((std::is_same<decltype(fma(Ambiguous(), Ambiguous(), Ambiguous())), Ambiguous>::value), "");

    assert(std::fma(1, 1, 1) == 2);
    assert(std::fma(1., 1, 1) == 2);
    assert(std::fma(1.f, 1, 1) == 2);
    assert(std::fma(1, 1., 1) == 2);
    assert(std::fma(1., 1., 1) == 2);
    assert(std::fma(1.f, 1., 1) == 2);
    assert(std::fma(1, 1.f, 1) == 2);
    assert(std::fma(1., 1.f, 1) == 2);
    assert(std::fma(1.f, 1.f, 1) == 2);

    assert(std::fma(1, 1, 1.) == 2);
    assert(std::fma(1., 1, 1.) == 2);
    assert(std::fma(1.f, 1, 1.) == 2);
    assert(std::fma(1, 1., 1.) == 2);
    assert(std::fma(1., 1., 1.) == 2);
    assert(std::fma(1.f, 1., 1.) == 2);
    assert(std::fma(1, 1.f, 1.) == 2);
    assert(std::fma(1., 1.f, 1.) == 2);
    assert(std::fma(1.f, 1.f, 1.) == 2);

    assert(std::fma(1, 1, 1.f) == 2);
    assert(std::fma(1., 1, 1.f) == 2);
    assert(std::fma(1.f, 1, 1.f) == 2);
    assert(std::fma(1, 1., 1.f) == 2);
    assert(std::fma(1., 1., 1.f) == 2);
    assert(std::fma(1.f, 1., 1.f) == 2);
    assert(std::fma(1, 1.f, 1.f) == 2);
    assert(std::fma(1., 1.f, 1.f) == 2);
    assert(std::fma(1.f, 1.f, 1.f) == 2);
}

__device__ void test_fmax()
{
    static_assert((std::is_same<decltype(std::fmax((float)0, (float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::fmax((bool)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmax((unsigned short)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmax((float)0, (unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmax((double)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmax((int)0, (long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmax((int)0, (unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmax((double)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmax((float)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmaxf(0,0)), float>::value), "");
    static_assert((std::is_same<decltype(std::fmax((int)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(fmax(Ambiguous(), Ambiguous())), Ambiguous>::value), "");

    assert(std::fmax(1, 0) == 1);
    assert(std::fmax(1., 0) == 1);
    assert(std::fmax(1.f, 0) == 1);

    assert(std::fmax(1, 0.) == 1);
    assert(std::fmax(1., 0.) == 1);
    assert(std::fmax(1.f, 0.) == 1);

    assert(std::fmax(1, 0.f) == 1);
    assert(std::fmax(1., 0.f) == 1);
    assert(std::fmax(1.f, 0.f) == 1);
}

__device__ void test_fmin()
{
    static_assert((std::is_same<decltype(std::fmin((float)0, (float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::fmin((bool)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmin((unsigned short)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmin((float)0, (unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmin((double)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmin((int)0, (long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmin((int)0, (unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmin((double)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fmin((float)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::fminf(0,0)), float>::value), "");
    static_assert((std::is_same<decltype(std::fmin((int)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(fmin(Ambiguous(), Ambiguous())), Ambiguous>::value), "");

    assert(std::fmin(1, 0) == 0);
    assert(std::fmin(1., 0) == 0);
    assert(std::fmin(1.f, 0) == 0);

    assert(std::fmin(1, 0.) == 0);
    assert(std::fmin(1., 0.) == 0);
    assert(std::fmin(1.f, 0.) == 0);

    assert(std::fmin(1, 0.f) == 0);
    assert(std::fmin(1., 0.f) == 0);
    assert(std::fmin(1.f, 0.f) == 0);
}

__device__ void test_hypot()
{
    static_assert((std::is_same<decltype(std::hypot((float)0, (float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::hypot((bool)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypot((unsigned short)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypot((float)0, (unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypot((double)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypot((int)0, (long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypot((int)0, (unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypot((double)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypot((float)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypotf(0,0)), float>::value), "");
    static_assert((std::is_same<decltype(std::hypot((int)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(hypot(Ambiguous(), Ambiguous())), Ambiguous>::value), "");

    assert(std::hypot(3, 4) == 5);
    assert(std::hypot(3, 4.) == 5);
    assert(std::hypot(3, 4.f) == 5);

    assert(std::hypot(3., 4) == 5);
    assert(std::hypot(3., 4.) == 5);
    assert(std::hypot(3., 4.f) == 5);

    assert(std::hypot(3.f, 4) == 5);
    assert(std::hypot(3.f, 4.) == 5);
    assert(std::hypot(3.f, 4.f) == 5);

#if TEST_STD_VER > 14
    static_assert((std::is_same<decltype(std::hypot((float)0, (float)0, (float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::hypot((float)0, (bool)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypot((float)0, (unsigned short)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypot((float)0, (unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypot((float)0, (double)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypot((float)0, (int)0, (long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypot((float)0, (int)0, (unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypot((float)0, (double)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypot((float)0, (float)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::hypot((int)0, (int)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(hypot(Ambiguous(), Ambiguous(), Ambiguous())), Ambiguous>::value), "");

    assert(std::hypot(2,3,6) == 7);
    assert(std::hypot(1,4,8) == 9);
#endif
}

__device__ void test_ilogb()
{
    static_assert((std::is_same<decltype(std::ilogb((float)0)), int>::value), "");
    static_assert((std::is_same<decltype(std::ilogb((bool)0)), int>::value), "");
    static_assert((std::is_same<decltype(std::ilogb((unsigned short)0)), int>::value), "");
    static_assert((std::is_same<decltype(std::ilogb((int)0)), int>::value), "");
    static_assert((std::is_same<decltype(std::ilogb((unsigned int)0)), int>::value), "");
    static_assert((std::is_same<decltype(std::ilogb((long)0)), int>::value), "");
    static_assert((std::is_same<decltype(std::ilogb((unsigned long)0)), int>::value), "");
    static_assert((std::is_same<decltype(std::ilogb((long long)0)), int>::value), "");
    static_assert((std::is_same<decltype(std::ilogb((unsigned long long)0)), int>::value), "");
    static_assert((std::is_same<decltype(std::ilogb((double)0)), int>::value), "");
    static_assert((std::is_same<decltype(std::ilogbf(0)), int>::value), "");
    // No CUDA ilogbl (takes a long double).
    //static_assert((std::is_same<decltype(std::ilogbl(0)), int>::value), "");
    static_assert((std::is_same<decltype(ilogb(Ambiguous())), Ambiguous>::value), "");
    assert(std::ilogb(1) == 0);
    assert(std::ilogb(1.) == 0);
    assert(std::ilogb(1.f) == 0);
}

__device__ void test_lgamma()
{
    static_assert((std::is_same<decltype(std::lgamma((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::lgamma((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::lgamma((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::lgamma((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::lgamma((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::lgamma((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::lgamma((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::lgamma((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::lgamma((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::lgamma((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::lgammaf(0)), float>::value), "");
    static_assert((std::is_same<decltype(lgamma(Ambiguous())), Ambiguous>::value), "");
    assert(std::lgamma(1) == 0);
}

__device__ void test_llrint()
{
    static_assert((std::is_same<decltype(std::llrint((float)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llrint((bool)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llrint((unsigned short)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llrint((int)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llrint((unsigned int)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llrint((long)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llrint((unsigned long)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llrint((long long)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llrint((unsigned long long)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llrint((double)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llrintf(0)), long long>::value), "");
    // No CUDA llrintl (takes a long double).
    //static_assert((std::is_same<decltype(std::llrintl(0)), long long>::value), "");
    static_assert((std::is_same<decltype(llrint(Ambiguous())), Ambiguous>::value), "");
    assert(std::llrint(1) == 1LL);
    assert(std::llrint(1.) == 1LL);
#if CUDA_VERSION > 7050
    assert(std::llrint(1.f) == 1LL);
#endif
}

__device__ void test_llround()
{
    static_assert((std::is_same<decltype(std::llround((float)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llround((bool)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llround((unsigned short)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llround((int)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llround((unsigned int)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llround((long)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llround((unsigned long)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llround((long long)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llround((unsigned long long)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llround((double)0)), long long>::value), "");
    static_assert((std::is_same<decltype(std::llroundf(0)), long long>::value), "");
    // No CUDA llroundl.
    //static_assert((std::is_same<decltype(std::llroundl(0)), long long>::value), "");
    static_assert((std::is_same<decltype(llround(Ambiguous())), Ambiguous>::value), "");
    assert(std::llround(1) == 1LL);
    assert(std::llround(1.) == 1LL);
    assert(std::llround(1.f) == 1LL);
}

__device__ void test_log1p()
{
    static_assert((std::is_same<decltype(std::log1p((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::log1p((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log1p((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log1p((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log1p((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log1p((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log1p((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log1p((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log1p((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log1p((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log1pf(0)), float>::value), "");
    static_assert((std::is_same<decltype(log1p(Ambiguous())), Ambiguous>::value), "");
    assert(std::log1p(0) == 0);
    assert(std::log1p(0.) == 0);
    assert(std::log1p(0.f) == 0);
}

__device__ void test_log2()
{
    static_assert((std::is_same<decltype(std::log2((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::log2((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log2((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log2((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log2((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log2((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log2((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log2((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log2((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log2((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::log2f(0)), float>::value), "");
    static_assert((std::is_same<decltype(log2(Ambiguous())), Ambiguous>::value), "");
    assert(std::log2(1) == 0);
    assert(std::log2(1.) == 0);
    assert(std::log2(1.f) == 0);
}

__device__ void test_logb()
{
    static_assert((std::is_same<decltype(std::logb((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::logb((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::logb((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::logb((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::logb((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::logb((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::logb((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::logb((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::logb((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::logb((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::logbf(0)), float>::value), "");
    static_assert((std::is_same<decltype(logb(Ambiguous())), Ambiguous>::value), "");
    assert(std::logb(1) == 0);
    assert(std::logb(1.) == 0);
    assert(std::logb(1.f) == 0);
}

__device__ void test_lrint()
{
    static_assert((std::is_same<decltype(std::lrint((float)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lrint((bool)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lrint((unsigned short)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lrint((int)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lrint((unsigned int)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lrint((long)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lrint((unsigned long)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lrint((long long)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lrint((unsigned long long)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lrint((double)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lrintf(0)), long>::value), "");
    // No CUDA lrintl (takes a long double).
    //static_assert((std::is_same<decltype(std::lrintl(0)), long>::value), "");
    static_assert((std::is_same<decltype(lrint(Ambiguous())), Ambiguous>::value), "");
    assert(std::lrint(1) == 1L);
    assert(std::lrint(1.) == 1L);
#if CUDA_VERSION > 7050
    assert(std::lrint(1.f) == 1L);
#endif
}

__device__ void test_lround()
{
    static_assert((std::is_same<decltype(std::lround((float)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lround((bool)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lround((unsigned short)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lround((int)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lround((unsigned int)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lround((long)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lround((unsigned long)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lround((long long)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lround((unsigned long long)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lround((double)0)), long>::value), "");
    static_assert((std::is_same<decltype(std::lroundf(0)), long>::value), "");
    // No CUDA lroundl (takes a long double).
    //static_assert((std::is_same<decltype(std::lroundl(0)), long>::value), "");
    static_assert((std::is_same<decltype(lround(Ambiguous())), Ambiguous>::value), "");
    assert(std::lround(1) == 1L);
    assert(std::lround(1.) == 1L);
    assert(std::lround(1.f) == 1L);
}

__device__ void test_nan()
{
    static_assert((std::is_same<decltype(std::nan("")), double>::value), "");
    static_assert((std::is_same<decltype(std::nanf("")), float>::value), "");
}

__device__ void test_nearbyint()
{
    static_assert((std::is_same<decltype(std::nearbyint((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::nearbyint((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nearbyint((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nearbyint((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nearbyint((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nearbyint((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nearbyint((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nearbyint((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nearbyint((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nearbyint((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nearbyintf(0)), float>::value), "");
    static_assert((std::is_same<decltype(nearbyint(Ambiguous())), Ambiguous>::value), "");
    assert(std::nearbyint(1) == 1);
    assert(std::nearbyint(1.) == 1);
    assert(std::nearbyint(1.f) == 1);
}

__device__ void test_nextafter()
{
    static_assert((std::is_same<decltype(std::nextafter((float)0, (float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::nextafter((bool)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nextafter((unsigned short)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nextafter((float)0, (unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nextafter((double)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nextafter((int)0, (long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nextafter((int)0, (unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nextafter((double)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nextafter((float)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::nextafterf(0,0)), float>::value), "");
    static_assert((std::is_same<decltype(std::nextafter((int)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(nextafter(Ambiguous(), Ambiguous())), Ambiguous>::value), "");

    // Invoke all our overloads, even if we can't be bothered to check the
    // results.
    std::nextafter(0, 1);
    std::nextafter(0, 1.);
    std::nextafter(0, 1.f);

    std::nextafter(0., 1);
    std::nextafter(0., 1.);
    std::nextafter(0., 1.f);

    std::nextafter(0.f, 1);
    std::nextafter(0.f, 1.);
    std::nextafter(0.f, 1.f);
}

__device__ void test_nexttoward()
{
    static_assert((std::is_same<decltype(nexttoward(Ambiguous(), Ambiguous())), Ambiguous>::value), "");

    // Invoke all our overloads, even if we can't be bothered to check the
    // results.
    std::nexttoward(0, 1);
    std::nexttoward(0, 1.);
    std::nexttoward(0, 1.f);

    std::nexttoward(0., 1);
    std::nexttoward(0., 1.);
    std::nexttoward(0., 1.f);

    std::nexttoward(0.f, 1);
    std::nexttoward(0.f, 1.);
    std::nexttoward(0.f, 1.f);
}

__device__ void test_remainder()
{
    static_assert((std::is_same<decltype(std::remainder((float)0, (float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::remainder((bool)0, (float)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::remainder((unsigned short)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::remainder((float)0, (unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::remainder((double)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::remainder((int)0, (long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::remainder((int)0, (unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::remainder((double)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::remainder((float)0, (double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::remainderf(0,0)), float>::value), "");
    static_assert((std::is_same<decltype(std::remainder((int)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(remainder(Ambiguous(), Ambiguous())), Ambiguous>::value), "");

    assert(std::remainder(1.5, 1) == -.5);
    assert(std::remainder(1.5, 1.) == -.5);
    assert(std::remainder(1.5, 1.f) == -.5);

    assert(std::remainder(1.5f, 1) == -.5);
    assert(std::remainder(1.5f, 1.) == -.5);
    assert(std::remainder(1.5f, 1.f) == -.5);

    assert(std::remainder(2, 1) == 0);
    assert(std::remainder(2, 1.) == 0);
    assert(std::remainder(2, 1.f) == 0);
}

__device__ void test_remquo()
{
    int ip;
    static_assert((std::is_same<decltype(std::remquo((float)0, (float)0, &ip)), float>::value), "");
    static_assert((std::is_same<decltype(std::remquo((bool)0, (float)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::remquo((unsigned short)0, (double)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::remquo((float)0, (unsigned int)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::remquo((double)0, (long)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::remquo((int)0, (long long)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::remquo((int)0, (unsigned long long)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::remquo((double)0, (double)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::remquo((float)0, (double)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(std::remquof(0,0, &ip)), float>::value), "");
    static_assert((std::is_same<decltype(std::remquo((int)0, (int)0, &ip)), double>::value), "");
    static_assert((std::is_same<decltype(remquo(Ambiguous(), Ambiguous(), &ip)), Ambiguous>::value), "");

    assert(std::remquo(1, 1, &ip) == 0);
    assert(std::remquo(1, 1., &ip) == 0);
    assert(std::remquo(1, 1.f, &ip) == 0);

    assert(std::remquo(0.5, 1, &ip) == 0.5);
    assert(std::remquo(0.5, 1., &ip) == 0.5);
    assert(std::remquo(0.5, 1.f, &ip) == 0.5);

    assert(std::remquo(0.5f, 1, &ip) == 0.5);
    assert(std::remquo(0.5f, 1., &ip) == 0.5);
    assert(std::remquo(0.5f, 1.f, &ip) == 0.5);
}

__device__ void test_rint()
{
    static_assert((std::is_same<decltype(std::rint((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::rint((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::rint((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::rint((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::rint((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::rint((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::rint((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::rint((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::rint((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::rint((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::rintf(0)), float>::value), "");
    static_assert((std::is_same<decltype(rint(Ambiguous())), Ambiguous>::value), "");
    assert(std::rint(1) == 1);
    assert(std::rint(1.) == 1);
    assert(std::rint(1.f) == 1);
}

__device__ void test_round()
{
    static_assert((std::is_same<decltype(std::round((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::round((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::round((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::round((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::round((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::round((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::round((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::round((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::round((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::round((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::roundf(0)), float>::value), "");
    static_assert((std::is_same<decltype(round(Ambiguous())), Ambiguous>::value), "");
    assert(std::round(1) == 1);
    assert(std::round(1.) == 1);
    assert(std::round(1.f) == 1);
}

__device__ void test_scalbln()
{
    static_assert((std::is_same<decltype(std::scalbln((float)0, (long)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::scalbln((bool)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbln((unsigned short)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbln((int)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbln((unsigned int)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbln((long)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbln((unsigned long)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbln((long long)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbln((unsigned long long)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbln((double)0, (long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalblnf(0, (long)0)), float>::value), "");
    static_assert((std::is_same<decltype(scalbln(Ambiguous(), Ambiguous())), Ambiguous>::value), "");
    assert(std::scalbln(1, 1) == 2);
    assert(std::scalbln(1, 1.) == 2);
    assert(std::scalbln(1, 1.f) == 2);

    assert(std::scalbln(1., 1) == 2);
    assert(std::scalbln(1., 1.) == 2);
    assert(std::scalbln(1., 1.f) == 2);

    assert(std::scalbln(1.f, 1) == 2);
    assert(std::scalbln(1.f, 1.) == 2);
    assert(std::scalbln(1.f, 1.f) == 2);
}

__device__ void test_scalbn()
{
    static_assert((std::is_same<decltype(std::scalbn((float)0, (int)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::scalbn((bool)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbn((unsigned short)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbn((int)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbn((unsigned int)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbn((long)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbn((unsigned long)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbn((long long)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbn((unsigned long long)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbn((double)0, (int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::scalbnf(0, (int)0)), float>::value), "");
    static_assert((std::is_same<decltype(scalbn(Ambiguous(), Ambiguous())), Ambiguous>::value), "");
    assert(std::scalbn(1, 1) == 2);
    assert(std::scalbn(1, 1.) == 2);
    assert(std::scalbn(1, 1.f) == 2);

    assert(std::scalbn(1., 1) == 2);
    assert(std::scalbn(1., 1.) == 2);
    assert(std::scalbn(1., 1.f) == 2);

    assert(std::scalbn(1.f, 1) == 2);
    assert(std::scalbn(1.f, 1.) == 2);
    assert(std::scalbn(1.f, 1.f) == 2);
}

__device__ void test_tgamma()
{
    static_assert((std::is_same<decltype(std::tgamma((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::tgamma((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tgamma((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tgamma((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tgamma((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tgamma((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tgamma((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tgamma((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tgamma((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tgamma((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::tgammaf(0)), float>::value), "");
    static_assert((std::is_same<decltype(tgamma(Ambiguous())), Ambiguous>::value), "");
    assert(std::tgamma(1) == 1);
    assert(std::tgamma(1.) == 1);
    assert(std::tgamma(1.f) == 1);
}

__device__ void test_trunc()
{
    static_assert((std::is_same<decltype(std::trunc((float)0)), float>::value), "");
    static_assert((std::is_same<decltype(std::trunc((bool)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::trunc((unsigned short)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::trunc((int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::trunc((unsigned int)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::trunc((long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::trunc((unsigned long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::trunc((long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::trunc((unsigned long long)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::trunc((double)0)), double>::value), "");
    static_assert((std::is_same<decltype(std::truncf(0)), float>::value), "");
    static_assert((std::is_same<decltype(trunc(Ambiguous())), Ambiguous>::value), "");
    assert(std::trunc(1) == 1);
    assert(std::trunc(1.) == 1);
    assert(std::trunc(1.f) == 1);
}

__global__ void tests()
{
    test_abs();
    test_acos();
    test_asin();
    test_atan();
    test_atan2();
    test_ceil();
    test_cos();
    test_cosh();
    test_exp();
    test_fabs();
    test_floor();
    test_fmod();
    test_frexp();
    test_ldexp();
    test_log();
    test_log10();
    test_modf();
    test_pow();
    test_sin();
    test_sinh();
    test_sqrt();
    test_tan();
    test_tanh();
    test_signbit();
    test_fpclassify();
    test_isfinite();
    test_isnormal();
    test_isgreater();
    test_isgreaterequal();
    test_isinf();
    test_isless();
    test_islessequal();
    test_islessgreater();
    test_isnan();
    test_isunordered();
    test_acosh();
    test_asinh();
    test_atanh();
    test_cbrt();
    test_copysign();
    test_erf();
    test_erfc();
    test_exp2();
    test_expm1();
    test_fdim();
    test_fma();
    test_fmax();
    test_fmin();
    test_hypot();
    test_ilogb();
    test_lgamma();
    test_llrint();
    test_llround();
    test_log1p();
    test_log2();
    test_logb();
    test_lrint();
    test_lround();
    test_nan();
    test_nearbyint();
    test_nextafter();
    test_nexttoward();
    test_remainder();
    test_remquo();
    test_rint();
    test_round();
    test_scalbln();
    test_scalbn();
    test_tgamma();
    test_trunc();
}

int main() {
    tests<<<1,1>>>();
    cudaError_t err = cudaDeviceSynchronize();
    if (err != cudaSuccess) {
      printf("CUDA error %d\n", (int)err);
      return 1;
    }
    printf("Success!\n");
    return 0;
}

#else

#include <stdio.h>

// No C++11; test is a nop.
int main() {
  printf("Success!\n");
  return 0;
}

#endif // __cplusplus < 201103L
