#ifndef VECTORIZER_PAGE_MAPPING_WINDOWS_H
#define VECTORIZER_PAGE_MAPPING_WINDOWS_H

#include "page-access.h"
#include <cstddef>
#include <windows.h>

namespace page_mapping {

inline size_t systemPageSize() {
  SYSTEM_INFO Info;
  GetSystemInfo(&Info);
  return Info.dwPageSize;
}

inline unsigned char *allocate(size_t Bytes) {
  return static_cast<unsigned char *>(
      VirtualAlloc(nullptr, Bytes, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
}

inline void deallocate(unsigned char *Begin, size_t) {
  VirtualFree(Begin, 0, MEM_RELEASE);
}

inline bool protect(unsigned char *Begin, size_t Bytes, Access Protection) {
  DWORD Flags = PAGE_NOACCESS;
  if (Protection == Access::ReadOnly)
    Flags = PAGE_READONLY;
  else if (Protection == Access::ReadWrite)
    Flags = PAGE_READWRITE;
  DWORD OldProtect;
  return VirtualProtect(Begin, Bytes, Flags, &OldProtect) != 0;
}

} // namespace page_mapping

#endif
