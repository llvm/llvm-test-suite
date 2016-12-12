#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fourier.h"

// RNG implemented localy to avoid library incongruences
#ifdef RAND_MAX
#undef RAND_MAX
#endif
#define RAND_MAX 32767
static unsigned long long int next = 1;

int rand( void ) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % RAND_MAX+1;
}

void srand( unsigned int seed ) {
    next = seed;
}
// End of RNG implementation

/* Return 0 when V1 and V2 do not match within the allowed FP_ABSTOLERANCE.  */
static inline int
check_FP(float V1, float V2) {
  double AbsTolerance = FP_ABSTOLERANCE;
  double Diff = fabs(V1 - V2);
  if (Diff > AbsTolerance) {
    fprintf(stderr, "A = %lf and B = %lf differ more than"
                  " FP_ABSTOLERANCE = %lf\n", V1, V2, AbsTolerance);
    return 0;
  }

  return 1;
}

int main(int argc, char *argv[]) {
	unsigned MAXSIZE;
	unsigned MAXWAVES;
	unsigned i,j;
	float *RealIn;
	float *ImagIn;
	float *RealOut;
	float *ImagOut;
	float *RealOut_StrictFP;
	float *ImagOut_StrictFP;
	float *coeff;
	float *amp;
	int invfft=0;

	if (argc<3)
	{
		printf("Usage: fft <waves> <length> -i\n");
		printf("-i performs an inverse fft\n");
		printf("make <waves> random sinusoids");
		printf("<length> is the number of samples\n");
		exit(-1);
	}
	else if (argc==4)
		invfft = !strncmp(argv[3],"-i",2);
	MAXSIZE=atoi(argv[2]);
	MAXWAVES=atoi(argv[1]);
  srand(1);
		
 RealIn=(float*)malloc(sizeof(float)*MAXSIZE);
 ImagIn=(float*)malloc(sizeof(float)*MAXSIZE);
 RealOut=(float*)malloc(sizeof(float)*MAXSIZE);
 ImagOut=(float*)malloc(sizeof(float)*MAXSIZE);
 RealOut_StrictFP=(float*)malloc(sizeof(float)*MAXSIZE);
 ImagOut_StrictFP=(float*)malloc(sizeof(float)*MAXSIZE);
 coeff=(float*)malloc(sizeof(float)*MAXWAVES);
 amp=(float*)malloc(sizeof(float)*MAXWAVES);

 /* Makes MAXWAVES waves of random amplitude and period */
	for(i=0;i<MAXWAVES;i++) 
	{
		coeff[i] = i%1000;
		amp[i] = i%1000;
	}
 for(i=0;i<MAXSIZE;i++) 
 {
   /*   RealIn[i]=rand();*/
	 RealIn[i]=0;
	 for(j=0;j<MAXWAVES;j++) 
	 {
		 /* randomly select sin or cos */
		 if (rand()%2)
		 {
		 		RealIn[i]+=coeff[j]*cos(amp[j]*i);
			}
		 else
		 {
		 	RealIn[i]+=coeff[j]*sin(amp[j]*i);
		 }
  	 ImagIn[i]=0;
	 }
 }

 /* regular*/
 fft_float (MAXSIZE,invfft,RealIn,ImagIn,RealOut,ImagOut);
 fft_float_StrictFP (MAXSIZE,invfft,RealIn,ImagIn,RealOut_StrictFP,ImagOut_StrictFP);
 
 printf("RealOut:\n");
 for (i=0;i<MAXSIZE;i++) {
   if (!check_FP(RealOut[i], RealOut_StrictFP[i]))
     return 1;
   printf("%f \t", RealOut_StrictFP[i]);
 }
 printf("\n");

printf("ImagOut:\n");
 for (i=0;i<MAXSIZE;i++) {
   if (!check_FP(ImagOut[i], ImagOut_StrictFP[i]))
     return 1;
   printf("%f \t", ImagOut_StrictFP[i]);
 }
 printf("\n");

 free(RealIn);
 free(ImagIn);
 free(RealOut);
 free(ImagOut);
 free(RealOut_StrictFP);
 free(ImagOut_StrictFP);
 free(coeff);
 free(amp);
 exit(0);


}
