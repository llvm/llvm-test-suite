/* For copyright information, see olden_v1.0/COPYRIGHT */
#ifndef TORONTO
#include <cm/cmmd.h>
#include <fcntl.h>
#endif

extern int atoi(const char *);

int NumNodes = 1;

int dealwithargs(int argc, char *argv[])
{
  int level;

  if (argc > 1)
    level = atoi(argv[1]);
  else
    level = 64;

  return level;

}






