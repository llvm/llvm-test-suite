#ifndef VECTORIZER_PAGE_MAPPING_H
#define VECTORIZER_PAGE_MAPPING_H

#include <cstddef>
#include <cstdint>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#include <unistd.h>
#endif

// A contiguous mapping with independently protected ranges of pages.
class PageMapping {
  enum class Access { None, ReadOnly, ReadWrite };
  struct Region {
    size_t Pages;
    Access Protection;
  };

  unsigned char *Data = nullptr;
  size_t Size = 0;
  size_t PageSize = 0;

  bool protect(unsigned char *Begin, size_t Bytes, Access Protection) {
#ifdef _WIN32
    DWORD Flags = PAGE_NOACCESS;
    if (Protection == Access::ReadOnly)
      Flags = PAGE_READONLY;
    else if (Protection == Access::ReadWrite)
      Flags = PAGE_READWRITE;
    DWORD OldProtect;
    return VirtualProtect(Begin, Bytes, Flags, &OldProtect) != 0;
#else
    int Flags = PROT_NONE;
    if (Protection == Access::ReadOnly)
      Flags = PROT_READ;
    else if (Protection == Access::ReadWrite)
      Flags = PROT_READ | PROT_WRITE;
    return mprotect(Begin, Bytes, Flags) == 0;
#endif
  }

  void release() {
    if (!Data)
      return;
#ifdef _WIN32
    VirtualFree(Data, 0, MEM_RELEASE);
#else
    munmap(Data, Size);
#endif
    Data = nullptr;
    Size = 0;
  }

  explicit PageMapping(const std::vector<Region> &Regions) {
#ifdef _WIN32
    SYSTEM_INFO Info;
    GetSystemInfo(&Info);
    PageSize = Info.dwPageSize;
#else
    long SystemPageSize = sysconf(_SC_PAGESIZE);
    if (SystemPageSize <= 0)
      return;
    PageSize = static_cast<size_t>(SystemPageSize);
#endif
    if (!PageSize || Regions.empty())
      return;

    size_t TotalPages = 0;
    for (const Region &R : Regions) {
      if (!R.Pages || R.Pages > SIZE_MAX / PageSize - TotalPages)
        return;
      TotalPages += R.Pages;
    }
    size_t AllocationSize = TotalPages * PageSize;
#ifdef _WIN32
    void *Mapping = VirtualAlloc(nullptr, AllocationSize,
                                 MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (!Mapping)
      return;
#else
    void *Mapping = mmap(nullptr, AllocationSize, PROT_READ | PROT_WRITE,
                         MAP_PRIVATE | MAP_ANON, -1, 0);
    if (Mapping == MAP_FAILED)
      return;
#endif
    Data = static_cast<unsigned char *>(Mapping);
    Size = AllocationSize;
    unsigned char *Begin = Data;
    for (const Region &R : Regions) {
      size_t Bytes = R.Pages * PageSize;
      if (!protect(Begin, Bytes, R.Protection)) {
        release();
        return;
      }
      Begin += Bytes;
    }
  }

public:
  class Builder;

  PageMapping(const PageMapping &) = delete;
  PageMapping &operator=(const PageMapping &) = delete;
  ~PageMapping() { release(); }

  explicit operator bool() const { return Data != nullptr; }
  unsigned char *data() const { return Data; }
  size_t size() const { return Size; }
  size_t pageSize() const { return PageSize; }
};

class PageMapping::Builder {
  std::vector<Region> Regions;

public:
  Builder &inaccessiblePages(size_t Count) {
    Regions.push_back({Count, Access::None});
    return *this;
  }

  Builder &readOnlyPages(size_t Count) {
    Regions.push_back({Count, Access::ReadOnly});
    return *this;
  }

  Builder &readWritePages(size_t Count) {
    Regions.push_back({Count, Access::ReadWrite});
    return *this;
  }

  // C++17 constructs the result directly; ownership cannot be copied.
  PageMapping build() const { return PageMapping(Regions); }
};

#endif
