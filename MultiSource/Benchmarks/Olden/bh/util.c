/* For copyright information, see olden_v1.0/COPYRIGHT */

/*
 * UTIL: various useful routines and functions.
 * Copyright (c) 1991, Joshua E. Barnes, Honolulu, HI.
 * 	    It's free because it's yours.
 */

#include "stdinc.h"

#define A	16807.0
#define M	2147483647.0

/* random:
 * return a random number, which is also the next seed.
 */
double my_rand(double seed)
{
    double	t = A*seed  + 1; 
    double floor();


    seed = t - (M * floor(t / M));
    return seed;

} /* end of random */

/*
 * XRAND: generate floating-point random number.
 */

double xrand(double xl, double xh, double r)
{   double res;

    res = xl + (xh-xl)*r/2147483647.0;
    return (res);
}




/*
 * CPUTIME: compute CPU time in min.
 */

#include <sys/types.h>
#include <sys/times.h>

#  define HZ  60.0

double cputime()
{
    struct tms buffer;

    if (times(&buffer) == -1)
	error("times() call failed\n");
    return (buffer.tms_utime / (60.0 * HZ));
}

/*
 * ERROR: scream and die quickly.
 */

error(char *msg, char *a1, char *a2, char *a3, char *a4)
{
    extern int errno;

    fprintf(stderr, msg, a1, a2, a3, a4);
    if (errno != 0)
        perror("Error");
    exit(0);
}



