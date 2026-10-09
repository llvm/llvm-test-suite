// Copyright 2026 The Abseil Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ABSL_CRC_INTERNAL_CRC32_X86_ARM_CRC_INTRINSICS_H_
#define ABSL_CRC_INTERNAL_CRC32_X86_ARM_CRC_INTRINSICS_H_

// The part of crc32_x86_arm_combined_simd.h that crc32c_inline.h needs: the
// detection of CRC acceleration hardware, and wrappers for the (scalar) CRC32C
// instructions.
//
// This is a separate header because crc32c_inline.h is included by
// absl/crc/crc32c.h, which is included by absl/strings/cord.h, which is
// included by most of Abseil's containers. It must not include the headers
// with the vector intrinsics, which are very expensive to parse (<arm_neon.h>,
// <x86intrin.h>, <immintrin.h>): <arm_acle.h> and <nmmintrin.h> have what is
// needed here.

#include <cstdint>

#include "absl/base/config.h"

// -------------------------------------------------------------------------
// Many x86 and ARM machines have CRC acceleration hardware.
// We can do a faster version of Extend() on such machines.
// We define a translation layer for both x86 and ARM for the ease of use and
// most performance gains.

// This implementation requires 64-bit CRC instructions (part of SSE 4.2) and
// PCLMULQDQ instructions. 32-bit builds with SSE 4.2 do exist, so the
// __x86_64__ condition is necessary.
#if defined(__x86_64__) && defined(__SSE4_2__) && defined(__PCLMUL__)

#include <nmmintrin.h>
#define ABSL_CRC_INTERNAL_HAVE_X86_SIMD

#elif defined(_MSC_VER) && !defined(__clang__) && defined(__AVX__) && \
    defined(_M_AMD64)

// MSVC AVX (/arch:AVX) implies SSE 4.2 and PCLMULQDQ.
#include <intrin.h>
#define ABSL_CRC_INTERNAL_HAVE_X86_SIMD

#elif defined(__aarch64__) && defined(__LITTLE_ENDIAN__) &&                 \
    defined(__ARM_FEATURE_CRC32) && defined(ABSL_INTERNAL_HAVE_ARM_NEON) && \
    defined(__ARM_FEATURE_CRYPTO)

#include <arm_acle.h>
#define ABSL_CRC_INTERNAL_HAVE_ARM_SIMD

#endif

namespace absl {
ABSL_NAMESPACE_BEGIN
namespace crc_internal {

// Starting with the initial value in |crc|, accumulates a CRC32 value for
// unsigned integers of different sizes.

#if defined(ABSL_CRC_INTERNAL_HAVE_X86_SIMD)

inline uint32_t CRC32_u8(uint32_t crc, uint8_t v) {
  return _mm_crc32_u8(crc, v);
}

inline uint32_t CRC32_u16(uint32_t crc, uint16_t v) {
  return _mm_crc32_u16(crc, v);
}

inline uint32_t CRC32_u32(uint32_t crc, uint32_t v) {
  return _mm_crc32_u32(crc, v);
}

inline uint32_t CRC32_u64(uint32_t crc, uint64_t v) {
  return static_cast<uint32_t>(_mm_crc32_u64(crc, v));
}

#elif defined(ABSL_CRC_INTERNAL_HAVE_ARM_SIMD)

inline uint32_t CRC32_u8(uint32_t crc, uint8_t v) { return __crc32cb(crc, v); }

inline uint32_t CRC32_u16(uint32_t crc, uint16_t v) {
  return __crc32ch(crc, v);
}

inline uint32_t CRC32_u32(uint32_t crc, uint32_t v) {
  return __crc32cw(crc, v);
}

inline uint32_t CRC32_u64(uint32_t crc, uint64_t v) {
  return __crc32cd(crc, v);
}

#endif

}  // namespace crc_internal
ABSL_NAMESPACE_END
}  // namespace absl

#endif  // ABSL_CRC_INTERNAL_CRC32_X86_ARM_CRC_INTRINSICS_H_
