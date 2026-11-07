#ifndef VECTORIZER_GUARD_PAGE_H
#define VECTORIZER_GUARD_PAGE_H

#include <cstddef>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#include <unistd.h>
#endif

// One writable, zero-initialized page followed by an inaccessible page.
class GuardedPages {
  unsigned char *Data = nullptr;
  size_t PageSize = 0;

public:
  GuardedPages() {
#ifdef _WIN32
    SYSTEM_INFO Info;
    GetSystemInfo(&Info);
    PageSize = Info.dwPageSize;
    void *Mapping = VirtualAlloc(nullptr, 2 * PageSize,
                                 MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (!Mapping)
      return;
    DWORD OldProtect;
    if (!VirtualProtect(static_cast<unsigned char *>(Mapping) + PageSize,
                        PageSize, PAGE_NOACCESS, &OldProtect)) {
      VirtualFree(Mapping, 0, MEM_RELEASE);
      return;
    }
#else
    long Size = sysconf(_SC_PAGESIZE);
    if (Size <= 0)
      return;
    PageSize = static_cast<size_t>(Size);
    void *Mapping = mmap(nullptr, 2 * PageSize, PROT_READ | PROT_WRITE,
                         MAP_PRIVATE | MAP_ANON, -1, 0);
    if (Mapping == MAP_FAILED)
      return;
    if (mprotect(static_cast<unsigned char *>(Mapping) + PageSize, PageSize,
                 PROT_NONE)) {
      munmap(Mapping, 2 * PageSize);
      return;
    }
#endif
    Data = static_cast<unsigned char *>(Mapping);
  }

  GuardedPages(const GuardedPages &) = delete;
  GuardedPages &operator=(const GuardedPages &) = delete;

  ~GuardedPages() {
    if (!Data)
      return;
#ifdef _WIN32
    VirtualFree(Data, 0, MEM_RELEASE);
#else
    munmap(Data, 2 * PageSize);
#endif
  }

  explicit operator bool() const { return Data != nullptr; }
  unsigned char *data() const { return Data; }
  size_t size() const { return PageSize; }
};

#endif
