#ifndef VECTORIZER_GUARD_PAGE_H
#define VECTORIZER_GUARD_PAGE_H

#include <cstddef>
#include <cstdint>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#include <unistd.h>
#endif

// Writable, zero-initialized pages followed by one inaccessible page.
class GuardedPages {
  unsigned char *Data = nullptr;
  size_t Size = 0;
  size_t MappingSize = 0;

public:
  explicit GuardedPages(size_t WritablePages = 1) {
#ifdef _WIN32
    SYSTEM_INFO Info;
    GetSystemInfo(&Info);
    size_t PageSize = Info.dwPageSize;
#else
    long SystemPageSize = sysconf(_SC_PAGESIZE);
    if (SystemPageSize <= 0)
      return;
    size_t PageSize = static_cast<size_t>(SystemPageSize);
#endif
    // Include the guard page when checking for allocation-size overflow.
    if (!PageSize || !WritablePages || WritablePages >= SIZE_MAX / PageSize)
      return;
    size_t WritableSize = WritablePages * PageSize;
    size_t AllocationSize = WritableSize + PageSize;
#ifdef _WIN32
    void *Mapping = VirtualAlloc(nullptr, AllocationSize,
                                 MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (!Mapping)
      return;
    DWORD OldProtect;
    if (!VirtualProtect(static_cast<unsigned char *>(Mapping) + WritableSize,
                        PageSize, PAGE_NOACCESS, &OldProtect)) {
      VirtualFree(Mapping, 0, MEM_RELEASE);
      return;
    }
#else
    void *Mapping = mmap(nullptr, AllocationSize, PROT_READ | PROT_WRITE,
                         MAP_PRIVATE | MAP_ANON, -1, 0);
    if (Mapping == MAP_FAILED)
      return;
    if (mprotect(static_cast<unsigned char *>(Mapping) + WritableSize, PageSize,
                 PROT_NONE)) {
      munmap(Mapping, AllocationSize);
      return;
    }
#endif
    Data = static_cast<unsigned char *>(Mapping);
    Size = WritableSize;
    MappingSize = AllocationSize;
  }

  GuardedPages(const GuardedPages &) = delete;
  GuardedPages &operator=(const GuardedPages &) = delete;

  ~GuardedPages() {
    if (!Data)
      return;
#ifdef _WIN32
    VirtualFree(Data, 0, MEM_RELEASE);
#else
    munmap(Data, MappingSize);
#endif
  }

  explicit operator bool() const { return Data != nullptr; }
  unsigned char *data() const { return Data; }
  size_t size() const { return Size; }
};

#endif
