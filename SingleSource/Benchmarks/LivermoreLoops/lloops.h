/**********************************************************************
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N 
 *
 * This is the header file that contains common code and the global
 * variables in which the kernels operate into. These globals also work
 * as a way to verify that the compiler can vectorize if the variables
 * belong to global structures, so moving them to inside the kernel would
 * invalidate that test.
 *
 * See each kernel (kernelNN.c) for more information on each test.
 *
 * This code have been tested on Linux/AMD_64 and is not guarantee to
 * work on any other combination. If you know it does, please update
 * this part of the comment.
 */
 
#include <stdio.h>
#include <math.h>

/* Timer */
#include <time.h>
struct timespec tp1;
unsigned int millisecs  = 0;
double  theseSecs = 0.0;
double  startSecs = 0.0;
double  secs;

void getSecs()
{
   clock_gettime(CLOCK_REALTIME, &tp1);
   theseSecs =  tp1.tv_sec + tp1.tv_nsec / 1e9;           
}

void start_time()
{
    getSecs();
    startSecs = theseSecs;
}

void end_time()
{
    getSecs();
    secs = theseSecs - startSecs;
    millisecs = (int)(1000.0 * secs);
}    

/* Test Variables */
struct Arrays
{
  double U[1001];
  double V[1001];
  double W[1001];
  double X[1001];
  double Y[1001];
  double Z[1001];
  double G[1001];
  double Du1[101];
  double Du2[101];
  double Du3[101];
  double Grd[1001];
  double Dex[1001];
  double Xi[1001];
  double Ex[1001];
  double Ex1[1001];
  double Dex1[1001];
  double Vx[1001];
  double Xx[1001];
  double Rx[1001];
  double Rh[2048];
  double Vsp[101];
  double Vstp[101];
  double Vxne[101];
  double Vxnd[101];
  double Ve3[101];
  double Vlr[101];
  double Vlin[101];
  double B5[101];
  double Plan[300];
  double D[300];
  double Sa[101];
  double Sb[101];     
  double P[512][4];
  double Px[101][25];
  double Cx[101][25];
  double Vy[25][101];
  double Vh[7][101];
  double Vf[7][101];
  double Vg[7][101];
  double Vs[7][101];
  double Za[7][101];
  double Zp[7][101];
  double Zq[7][101];
  double Zr[7][101];
  double Zm[7][101];
  double Zb[7][101];
  double Zu[7][101];
  double Zv[7][101];
  double Zz[7][101];               
  double B[64][64];
  double C[64][64];
  double H[64][64];     
  double U1[2][101][5];
  double U2[2][101][5];
  double U3[2][101][5];
  double Xtra[40];     
  long   E[96];
  long   F[96];
  long   Ix[1001];
  long   Ir[1001];
  long   Zone[301];
  double X0[1001];
  double W0[1001];
  double Px0[101][25];
  double P0[512][4];
  double H0[64][64];
  double Rh0[2048];
  double Vxne0[101];
  double Zr0[7][101];
  double Zu0[7][101];
  double Zv0[7][101];
  double Zz0[7][101];
  double Za0[101][25];
  double Stb50;               
  double Xx0;
}as1;

#define u        as1.U
#define v        as1.V
#define w        as1.W
#define x        as1.X
#define y        as1.Y
#define z        as1.Z
#define g        as1.G
#define du1      as1.Du1
#define du2      as1.Du2
#define du3      as1.Du3
#define grd      as1.Grd
#define dex      as1.Dex
#define xi       as1.Xi
#define ex       as1.Ex
#define ex1      as1.Ex1
#define dex1     as1.Dex1
#define vx       as1.Vx
#define xx       as1.Xx
#define rx       as1.Rx
#define rh       as1.Rh
#define vsp      as1.Vsp
#define vstp     as1.Vstp
#define vxne     as1.Vxne
#define vxnd     as1.Vxnd
#define ve3      as1.Ve3
#define vlr      as1.Vlr
#define vlin     as1.Vlin
#define b5       as1.B5
#define plan     as1.Plan
#define d        as1.D
#define sa       as1.Sa
#define sb       as1.Sb
#define p        as1.P
#define px       as1.Px
#define cx       as1.Cx
#define vy       as1.Vy
#define vh       as1.Vh
#define vf       as1.Vf
#define vg       as1.Vg
#define vs       as1.Vs
#define za       as1.Za
#define zb       as1.Zb
#define zp       as1.Zp
#define zq       as1.Zq
#define zr       as1.Zr
#define zm       as1.Zm
#define zz       as1.Zz
#define zu       as1.Zu
#define zv       as1.Zv
#define b        as1.B
#define c        as1.C
#define h        as1.H
#define u1       as1.U1
#define u2       as1.U2
#define u3       as1.U3
#define xtra     as1.Xtra
#define a11      as1.Xtra[1]
#define a12      as1.Xtra[2]
#define a13      as1.Xtra[3]
#define a21      as1.Xtra[4]
#define a22      as1.Xtra[5]
#define a23      as1.Xtra[6]
#define a31      as1.Xtra[7]
#define a32      as1.Xtra[8]
#define a33      as1.Xtra[9]
#define c0       as1.Xtra[12]
#define dk       as1.Xtra[15]
#define dm22     as1.Xtra[16]
#define dm23     as1.Xtra[17]
#define dm24     as1.Xtra[18]
#define dm25     as1.Xtra[19]
#define dm26     as1.Xtra[20]
#define dm27     as1.Xtra[21]
#define dm28     as1.Xtra[22]
#define expmax   as1.Xtra[26]
#define flx      as1.Xtra[27]
#define q        as1.Xtra[28]
#define r        as1.Xtra[30]
#define s        as1.Xtra[32]
#define sig      as1.Xtra[34]
#define stb5     as1.Xtra[35]
#define t        as1.Xtra[36]
#define xnm      as1.Xtra[39]   
#define e        as1.E  
#define f        as1.F
#define ix       as1.Ix
#define ir       as1.Ir
#define zone     as1.Zone
#define x0       as1.X0
#define w0       as1.W0
#define px0      as1.Px0
#define p0       as1.P0
#define h0       as1.H0
#define rh0      as1.Rh0
#define vxne0    as1.Vxne0
#define zr0      as1.Zr0
#define zu0      as1.Zu0
#define zv0      as1.Zv0
#define zz0      as1.Zz0
#define za0      as1.Za0
#define stb50    as1.Stb50
#define xx0      as1.Xx0              

struct Parameters
{
    long   Inner_loops;
    long   Outer_loops;
    long   Loop_mult;
    double Flops_per_loop;
    double Sumcheck[3][25];
    long   Accuracy[3][25];
    double LoopTime[3][25];
    double LoopSpeed[3][25];
    double LoopFlos[3][25];
    long   Xflops[25];
    long   Xloops[3][25];
    long   Nspan[3][25];       
    double TimeStart;
    double TimeEnd;
    double Loopohead;
    long   Count;
    long   Count2;
    long   Pass;
    long   Extra_loops[3][25];
    long   K2;
    long   K3;
    long   M16;
    long   J5;
    long   Section;
    long   N16;
    double Mastersum;
    long   M24;

    
}as2;

#define n            as2.Inner_loops
#define loop         as2.Outer_loops
#define mult         as2.Loop_mult
#define nflops       as2.Flops_per_loop
#define Checksum     as2.Sumcheck
#define accuracy     as2.Accuracy
#define RunTime      as2.LoopTime
#define Mflops       as2.LoopSpeed
#define FPops        as2.LoopFlos
#define nspan        as2.Nspan
#define xflops       as2.Xflops
#define xloops       as2.Xloops
#define StartTime    as2.TimeStart
#define EndTime      as2.TimeEnd
#define overhead_l   as2.Loopohead
#define count        as2.Count
#define count2       as2.Count2
#define pass         as2.Pass
#define extra_loops  as2.Extra_loops
#define k2           as2.K2
#define k3           as2.K3
#define m16          as2.M16
#define j5           as2.J5
#define section      as2.Section
#define n16          as2.N16
#define MasterSum    as2.Mastersum
#define m24          as2.M24

/* Forward declarations */
void init(long);
long parameters(long);
void iqranf();

/* These should really be a parameters */
#define ITERATIONS 100000
#define KERNELS 24
               
/* Initialises arrays and variables  */
void init(long which)
{
  long   i, j, k, l, m, nn;
  double ds, dw, rr, ss;
  double fuzz, fizz, buzz, scaled, one;  

  scaled =  (double)(10.0);
  scaled =  (double)(1.0) / scaled;
  fuzz =    (double)(0.0012345);
  buzz =    (double)(1.0) + fuzz;
  fizz =    (double)(1.1) * fuzz;
  one =     (double)(1.0);
     
  for ( k=0 ; k<19977 + 34132 ; k++)
    {
      if (k == 19977)
        {
          fuzz = (double)(0.0012345);
          buzz = (double) (1.0) + fuzz;
          fizz = (double) (1.1) * fuzz;
        }         
      buzz = (one - fuzz) * buzz + fuzz;
      fuzz = - fuzz;
      u[k] = (buzz - fizz) * scaled;
    }
     
  fuzz = (double)(0.0012345);
  buzz = (double) (1.0) + fuzz;
  fizz = (double) (1.1) * fuzz;
     
  for ( k=1 ; k<40 ; k++)
    {
      buzz = (one - fuzz) * buzz + fuzz;
      fuzz = - fuzz;
      xtra[k] = (buzz - fizz) * scaled;
    }

  ds = 1.0;
  dw = 0.5;
  for ( l=0 ; l<4 ; l++ )   
    {
      for ( i=0 ; i<512 ; i++ )
        {
          p[i][l] = ds;
          ds = ds + dw;
        }
    }
  for ( i=0 ; i<96 ; i++ )
    {
      e[i] = 1;
      f[i] = 1;
    }    

     
  iqranf();
  dw = -100.0;
  for ( i=0; i<1001 ; i++ )
    {
      dex[i] = dw * dex[i];
      grd[i] = ix[i];
      y[i] = grd[i] * fizz;
    }     
  flx = 0.001;

                  
  d[0]= 1.01980486428764;
  nn = n16;
    
  for ( l=1 ; l<300 ; l++ )
    {
      d[l] = d[l-1] + 1.000e-4 / d[l-1];
    }
  rr = d[nn-1];
  for ( l=1 ; l<=2 ; l++ )
    {
      m = (nn+nn)*(l-1);
      for ( j=1 ; j<=2 ; j++ )
        {
          for ( k=1 ; k<=nn ; k++ )
            {
              m = m + 1;
              ss = (double)(k);
              plan[m-1] = rr * ((ss + 1.0) / ss);
              zone[m-1] = k + k;
            }
        }
    }
  k = nn + nn + 1;
  zone[k-1] = nn;
        
  if (which == 16)
    {
      r = d[n-1];
      s = d[n-2];
      t = d[n-3];
      k3 = k2 = 0;
    }
  expmax = 20.0;
  if (which == 22)
    {
      u[n-1] = 0.99*expmax*v[n-1];
    }
  if (which == 24)
    {
      x[n/2] = -1.0e+10;
    }

  /* Make copies of data for extra loops */
 
  for ( i=0; i<1001 ; i++ )
    {
      x0[i] = x[i];
      w0[i] = w[i];
      for (j=0 ; j<25 ; j++ )
        {
          cx[i][j] = x[i]*buzz;
          px[i][j] = w[i]*fuzz;
        }
    }
  for ( i=0 ; i<101 ; i++ )
    {
      for (j=0 ; j<25 ; j++ )
        {
          px0[i][j] = px[i][j];
        }
    }
  for ( i=0 ; i<512 ; i++ )
    {
      for (j=0 ; j<4 ; j++ )
        {
          p0[i][j] = p[i][j];
        }
    }
  for ( i=0 ; i<64 ; i++ )
    {
      for (j=0 ; j<64 ; j++ )
        {
          h0[i][j] = h[i][j];
        }
    }
  for ( i=0; i<2048 ; i++ )
    {
      rh0[i] = rh[i];
    }
  for ( i=0; i<101 ; i++ )
    {
      vxne0[i] = vxne[i];
    }
  for ( i=0 ; i<7 ; i++ )
    {
      for (j=0 ; j<101 ; j++ )
        {
          zr0[i][j] = zr[i][j];
          zu0[i][j] = zu[i][j];
          zv0[i][j] = zv[i][j];
          zz0[i][j] = zz[i][j];
          za0[i][j] = za[i][j];
        }
    }
  stb50 = stb5;
  xx0 = xx[0];
                 
  return;
}

/* Set up parameters for each kernel */
long parameters(long which)
{

    long nloops[3][25] =
         { {0, 1001, 101, 1001, 1001, 1001, 64, 995, 100,
                101, 101, 1001, 1000, 64, 1001, 101, 75,
                101, 100, 101, 1000, 101, 101, 100, 1001  },
           {0,  101, 101, 101, 101, 101,  32, 101, 100,
                101, 101, 101, 100,  32, 101, 101,  40,
                101, 100, 101, 100,  50, 101, 100, 101    },
           {0,   27, 15, 27, 27, 27,  8, 21, 14,
                 15, 15, 27, 26,  8, 27, 15, 15,
                 15, 14, 15, 26, 20, 15, 14, 27           }  };


                          
    long lpass[3][25] =
          { {0, 7, 67,  9, 14, 10,  3,  4, 10, 36, 34, 11, 12,
               36, 2,  1,  25, 35,  2, 39,  1,  1, 11,  8,  5  },
            {0, 40, 40, 53, 70, 55,  7, 22,  6, 21, 19, 64, 68,
                41, 10,  1, 27, 20,  1, 23,  8,  1,  7,  5, 31   },
            {0, 28, 46, 37, 38, 40, 21, 20,  9, 26, 25, 46, 48,
                31,  8,  1, 14, 26,  2, 28,  7,  1,  8,  7, 23 } };

    double sums[3][25] = 
     {
      { 0.0,
      5.114652693224671e+04, 1.539721811668385e+03, 1.000742883066363e+01,
      5.999250595473891e-01, 4.548871642387267e+03, 4.375116344729986e+03,
      6.104251075174761e+04, 1.501268005625798e+05, 1.189443609974981e+05,
      7.310369784325296e+04, 3.342910972650109e+07, 2.907141294167248e-05,
      1.202533961842803e+11, 3.165553044000334e+09, 3.943816690352042e+04,
      5.650760000000000e+05, 1.114641772902486e+03, 1.015727037502300e+05,
      5.421816960147207e+02, 3.040644339351239e+07, 1.597308280710199e+08,
      2.938604376566697e+02, 3.549900501563623e+04, 5.000000000000000e+02
                                                                        },

      { 0.0,
      5.253344778937972e+02, 1.539721811668385e+03, 1.009741436578952e+00,
      5.999250595473891e-01, 4.589031939600982e+01, 8.631675645333210e+01,
      6.345586315784055e+02, 1.501268005625798e+05, 1.189443609974981e+05,
      7.310369784325296e+04, 3.433560407475758e+04, 7.127569130821465e-06,
      9.816387810944345e+10, 3.039983465145393e+07, 3.943816690352042e+04,
      6.480410000000000e+05, 1.114641772902486e+03, 1.015727037502300e+05,
      5.421816960147207e+02, 3.126205178815431e+04, 7.824524877232093e+07,
      2.938604376566697e+02, 3.549900501563623e+04, 5.000000000000000e+01
                                                                       },
  
      { 0.0,
      3.855104502494961e+01, 3.953296986903059e+01, 2.699309089320672e-01,
      5.999250595473891e-01, 3.182615248447483e+00, 1.120309393467088e+00,
      2.845720217644024e+01, 2.960543667875003e+03, 2.623968460874250e+03,
      1.651291227698265e+03, 6.551161335845770e+02, 1.943435981130448e-06,
      3.847124199949426e+10, 2.923540598672011e+06, 1.108997288134785e+03,
      5.152160000000000e+05, 2.947368618589360e+01, 9.700646212337040e+02,
      1.268230698051003e+01, 5.987713249475302e+02, 5.009945671204667e+07,
      6.109968728263972e+00, 4.850340602749970e+02, 1.300000000000000e+01
                                                                      } };
                            

  
    double number_flops[25] = {0, 5., 4., 2., 2., 2., 2., 16., 36., 17.,
                                   9., 1., 1., 7., 11., 33.,10., 9., 44.,
                                   6., 26., 2., 17., 11., 1.};
                        
    n = nloops[section][which];
    nspan[section][which] = n;
    n16 = nloops[section][16];
    nflops = number_flops[which];
    xflops[which] = (long)nflops;
    loop = lpass[section][which];
    xloops[section][which] = loop;
    loop = loop * mult;
    MasterSum = sums[section][which];
    count = 0;

    init(which);
    
    return 0;
}

/* iqranf procedure - "random" number generator */
void iqranf()
{
    
  long   inset, Mmin, Mmax, nn, i, kk;
  double span, spin, realn, per, scale1, qq, dkk, dp, dq;
  long   seed[3] = { 256, 12491249, 1499352848 };

  nn = 1001;
  Mmin = 1;
  Mmax = 1001;
  kk = seed[section];
    
  inset= Mmin;
  span= Mmax - Mmin;
  spin= 16807;
  per= 2147483647;
  realn= nn;
  scale1= 1.00001;
  qq= scale1 * (span / realn);
  dkk= kk;
    
  for ( i=0 ; i<nn ; i++)
    { 
      dp= dkk*spin;
      dkk= dp - (long)( dp/per)*per;
      dq= dkk*span;
      ix[i] = inset + (long)( dq/ per);
      if ((ix[i] < Mmin) | (ix[i] > Mmax))
        {
          ix[i] = inset + i + 1 * (long)qq;
        }
    }
    
  return;         
}
