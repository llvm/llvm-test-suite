#ifndef VECTORIZER_PAGE_MAPPING_H
#define VECTORIZER_PAGE_MAPPING_H

#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

#ifdef _WIN32
#include "page-mapping-windows.h"
#else
#include "page-mapping-posix.h"
#endif

// A contiguous mapping with independently protected ranges of pages.
class PageMapping {
  using Access = page_mapping::Access;
  struct Region {
    size_t Pages;
    Access Protection;
  };

  unsigned char *Data = nullptr;
  size_t Size = 0;
  size_t PageSize = 0;

  void swap(PageMapping &Other) noexcept {
    std::swap(Data, Other.Data);
    std::swap(Size, Other.Size);
    std::swap(PageSize, Other.PageSize);
  }

  void release() {
    if (!Data)
      return;
    page_mapping::deallocate(Data, Size);
    Data = nullptr;
    Size = 0;
    PageSize = 0;
  }

  explicit PageMapping(const std::vector<Region> &Regions)
      : PageSize(page_mapping::systemPageSize()) {
    if (!PageSize || Regions.empty())
      return;

    size_t TotalPages = 0;
    for (const Region &R : Regions) {
      if (!R.Pages || R.Pages > SIZE_MAX / PageSize - TotalPages)
        return;
      TotalPages += R.Pages;
    }
    size_t AllocationSize = TotalPages * PageSize;
    Data = page_mapping::allocate(AllocationSize);
    if (!Data)
      return;
    Size = AllocationSize;
    unsigned char *Begin = Data;
    for (const Region &R : Regions) {
      size_t Bytes = R.Pages * PageSize;
      if (!page_mapping::protect(Begin, Bytes, R.Protection)) {
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
  PageMapping(PageMapping &&Other) noexcept { swap(Other); }

  PageMapping &operator=(PageMapping &&Other) noexcept {
    if (this == &Other)
      return *this;
    release();
    swap(Other);
    return *this;
  }

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

  PageMapping build() const { return PageMapping(Regions); }
};

#endif
