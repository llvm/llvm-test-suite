/* For copyright information, see olden_v1.0/COPYRIGHT */

#ifndef TORONTO
extern int __NumNodes;
#else
extern int NumNodes;
#endif

extern int nbody;

#ifndef TORONTO
#include <cm/cmmd.h>
#include <fcntl.h>
filestuff()
{
  fcntl(fileno(stdout), F_SETFL, O_APPEND);
}
#endif


int dealwithargs(int argc, char *argv[])
{
  int level;

  if (argc > 2) 
    NumNodes = atoi(argv[2]);
  else 
    NumNodes = 4;

  if (argc > 1)
    nbody = atoi(argv[1]);
  else
    nbody = 2048;

  return level;
  
}





