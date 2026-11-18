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

static bool test(size_t Iterations) {
  unsigned char *Src = allocateBeforeGuardPage(Iterations);
  if (!Src)
    return false;

  uint64_t Dst[17];
  uint64_t Expected[17];
  for (unsigned Pattern = 0; Pattern != 2; ++Pattern) {
    // First disable all conditional loads, then enable alternating lanes whose
    // eight-byte accesses fit. The last seven bytes must remain zero, so no
    // active access crosses into the guard page.
    if (Pattern)
      for (size_t I = 0; I + sizeof(uint64_t) <= Iterations; I += 2)
        Src[I] = 1;

    // Compute the reference from padded storage, without conditional wide
    // accesses to the protected mapping in the verification code itself.
    unsigned char Copy[17 + sizeof(uint64_t)] = {};
    memcpy(Copy, Src, Iterations);
    for (size_t I = 0; I < Iterations; ++I) {
      Dst[I] = 1;
      Expected[I] = 0;
      if (Copy[I])
        memcpy(&Expected[I], Copy + I, sizeof(uint64_t));
    }
    conditional_load(Src, Dst, Iterations);
    for (size_t I = 0; I < Iterations; ++I)
      if (Dst[I] != Expected[I])
        return false;
  }
  return true;
}

int main() {
  // Exercise short loops, full vectors, and scalar or predicated tails at VF=4.
  const size_t IterationCounts[] = {3, 4, 5, 16, 17};
  for (size_t Iterations : IterationCounts)
    if (!test(Iterations))
      return 1;
  puts("PASS");
  return 0;
}
