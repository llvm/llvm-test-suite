#include "types.h"

/* add more platforms if necessary */

#ifdef UNIX
#include <sys/time.h>
#include <sys/resource.h>

int64 millisecs()
{
  struct rusage rusage;
  static int64 Time = 0;
  return ++Time; /* DO NOT TIME FOR LLVM */

  getrusage(RUSAGE_SELF,&rusage);
  return rusage.ru_utime.tv_sec * 1000 + rusage.ru_utime.tv_usec / 1000;
}

#endif
