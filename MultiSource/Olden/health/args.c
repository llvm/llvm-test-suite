/* For copyright information, see olden_v1.0/COPYRIGHT */

/*****************************************************************
 * args.c:  Handles arguments to command line.                   *
 *          To be used with health.c.                            *
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "health.h"

#ifdef TORONTO
int dealwithargs(int argc, char *argv[]) { 
  if (argc < 4) {
#if 0
    printf("usage:  health <# levels> <time> <seed>\n");
    exit(1); 
#endif
    max_level = 3;
    max_time = 15;
    seed = 1;
  } else {
    max_level = atoi(argv[1]);
    max_time = atol(argv[2]);
    seed = atol(argv[3]);
  }

  printf("max_level=%d  max_time=%ld  seed=%ld \n", max_level, max_time, seed);
}
#else
int dealwithargs(int argc, char *argv[]) { 
  if (argc < 5) {
    fprintf(stderr, "usage:  health <# levels> <time> <seed> <# proc>\n");
    exit(1); }
  
  max_level = atoi(argv[1]);
  max_time = atol(argv[2]);
  seed = atol(argv[3]);
  __NumNodes = atoi(argv[4]);
}
#endif





