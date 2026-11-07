#include "page-mapping.h"
#include <cstdint>
#include <cstdio>
#include <cstring>

#ifdef _MSC_VER
#define NOINLINE __declspec(noinline)
#define RESTRICT __restrict
#else
#define NOINLINE __attribute__((noinline))
#define RESTRICT __restrict__
#endif

NOINLINE void conditional_load(const unsigned char *RESTRICT src,
                               uint64_t *RESTRICT dst, size_t n) {
#ifdef __clang__
#pragma clang loop vectorize_width(4) interleave_count(1)
#endif
  for (size_t i = 0; i < n; ++i) {
    uint64_t value = 0;
    if (src[i])
      memcpy(&value, src + i, sizeof(value));
    dst[i] = value;
  }
}

int main() {
  constexpr size_t Iterations = 16;
  constexpr size_t AccessibleBytes = Iterations;
  auto Pages = PageMapping::Builder()
                   .inaccessiblePages(1)
                   .readWritePages(2)
                   .inaccessiblePages(1)
                   .build();
  if (!Pages || Pages.pageSize() < AccessibleBytes)
    return 1;

  // Only the guard byte of the last iteration is readable. Its value is zero,
  // so the conditional eight-byte load must not touch the protected page.
  unsigned char *Src =
      Pages.data() + Pages.size() - Pages.pageSize() - AccessibleBytes;
  uint64_t Dst[Iterations];
  for (uint64_t &Value : Dst)
    Value = 1;
  conditional_load(Src, Dst, Iterations);
  for (uint64_t Value : Dst)
    if (Value != 0)
      return 1;

  // Also exercise an active lane whose entire eight-byte access is valid.
  Src[0] = 1;
  uint64_t Expected;
  memcpy(&Expected, Src, sizeof(Expected));
  conditional_load(Src, Dst, Iterations);
  if (Dst[0] != Expected)
    return 1;
  for (size_t I = 1; I < Iterations; ++I)
    if (Dst[I] != 0)
      return 1;

  puts("PASS");
  return 0;
}
