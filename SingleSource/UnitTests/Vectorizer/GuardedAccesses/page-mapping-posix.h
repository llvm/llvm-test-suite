#ifndef VECTORIZER_PAGE_MAPPING_POSIX_H
#define VECTORIZER_PAGE_MAPPING_POSIX_H

#include "page-access.h"
#include <cstddef>
#include <sys/mman.h>
#include <unistd.h>

namespace page_mapping {

inline size_t systemPageSize() {
  long Size = sysconf(_SC_PAGESIZE);
  return Size > 0 ? static_cast<size_t>(Size) : 0;
}

inline unsigned char *allocate(size_t Bytes) {
  void *Mapping = mmap(nullptr, Bytes, PROT_READ | PROT_WRITE,
                       MAP_PRIVATE | MAP_ANON, -1, 0);
  return Mapping == MAP_FAILED ? nullptr
                               : static_cast<unsigned char *>(Mapping);
}

inline void deallocate(unsigned char *Begin, size_t Bytes) {
  munmap(Begin, Bytes);
}

inline bool protect(unsigned char *Begin, size_t Bytes, Access Protection) {
  int Flags = PROT_NONE;
  if (Protection == Access::ReadOnly)
    Flags = PROT_READ;
  else if (Protection == Access::ReadWrite)
    Flags = PROT_READ | PROT_WRITE;
  return mprotect(Begin, Bytes, Flags) == 0;
}

} // namespace page_mapping

#endif
