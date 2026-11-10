#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#include <unistd.h>
#endif

// Allocate zero-filled storage ending immediately before an inaccessible page.
// The mapping stays alive until the test process exits.
static unsigned char *allocateBeforeGuardPage(size_t Bytes) {
#ifdef _WIN32
  SYSTEM_INFO Info;
  GetSystemInfo(&Info);
  size_t PageSize = Info.dwPageSize;
  if (Bytes > PageSize)
    return nullptr;
  auto *Mem = static_cast<unsigned char *>(VirtualAlloc(
      nullptr, 2 * PageSize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
  if (!Mem)
    return nullptr;
  DWORD OldProtect;
  if (!VirtualProtect(Mem + PageSize, PageSize, PAGE_NOACCESS, &OldProtect)) {
    VirtualFree(Mem, 0, MEM_RELEASE);
    return nullptr;
  }
#else
  long PageSize = sysconf(_SC_PAGESIZE);
  if (PageSize <= 0 || Bytes > static_cast<size_t>(PageSize))
    return nullptr;
  void *Map = mmap(nullptr, 2 * PageSize, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANON, -1, 0);
  if (Map == MAP_FAILED)
    return nullptr;
  auto *Mem = static_cast<unsigned char *>(Map);
  if (mprotect(Mem + PageSize, PageSize, PROT_NONE) != 0) {
    munmap(Mem, 2 * PageSize);
    return nullptr;
  }
#endif
  return Mem + PageSize - Bytes;
}

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
  unsigned char *Src = allocateBeforeGuardPage(AccessibleBytes);
  if (!Src)
    return 1;

  // Only the guard byte of the last iteration is readable. Its value is zero,
  // so the conditional eight-byte load must not touch the protected page.
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
