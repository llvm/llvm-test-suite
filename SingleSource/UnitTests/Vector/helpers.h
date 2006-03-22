#include <stdio.h>

typedef float v4sf __attribute__ ((__vector_size__ (16)));

typedef union {
  v4sf V;
  float A[4];
} FV;

static void printFV(FV *F) {
	printf("%f %f %f %f\n", F->A[0], F->A[1], F->A[2], F->A[3]);
}
