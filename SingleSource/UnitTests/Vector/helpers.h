#include <stdio.h>

typedef float  v4sf __attribute__ ((__vector_size__ (16)));
typedef double v2sd __attribute__ ((__vector_size__ (16)));

typedef union {
  v4sf V;
  float A[4];
} FV;

typedef union {
  v2sd V;
  double A[2];
} DV;

static void printFV(FV *F) {
	printf("%f %f %f %f\n", F->A[0], F->A[1], F->A[2], F->A[3]);
}

static void printDV(DV *D) {
	printf("%g %g\n", D->A[0], D->A[1]);
}
