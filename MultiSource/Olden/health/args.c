/* For copyright information, see olden_v1.0/COPYRIGHT */

/*****************************************************************
 * args.c:  Handles arguments to command line.                   *
 *          To be used with health.c.                            *
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "health.h"

void dealwithargs(int argc, char *argv[]) { 
  if (argc < 4) {
    max_level = 3;
    max_time = 15;
    seed = 1;
  } else {
    max_level = atoi(argv[1]);
    max_time = atol(argv[2]);
    seed = atol(argv[3]);
  }

  printf("max_level=%d  max_time=%lld  seed=%lld \n", max_level, max_time, seed);
}




