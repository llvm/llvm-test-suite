/************************************************************************
 *                                                                      *
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N  *
 *                                                                      *
 *     These kernels measure   " C "   numerical computation            *
 *     rates for  a  spectrum  of  cpu-limited computational            *
 *     structures or benchmarks.   Mathematical  through-put            *
 *     is measured  in  units  of millions of floating-point            *
 *     operations executed per second, called Megaflops/sec.            *
 *                                                                      *
 ************************************************************************
 *     Originally from  Greg Astfalk, AT&T, P.O.Box 900, Princeton,     *
 *           NJ. 08540.    by way of Frank McMahon (LLNL).              *
 *                                                                      *
 *   Modifications by Tim Peters, Kendall Square Res. Corp. Oct 92.     *
 *                                                                      *
 *       This version by Roy Longbottom (retired, ex-CCTA UK)           *
 *             Roy_Longbottom 101323.2241@compuserve.com                *
 *                          March 1996                                  *
 *                                                                      *
 *                               REFERENCE                              *
 *                                                                      *
 *              F.H.McMahon,   The Livermore Fortran Kernels:           *
 *              A Computer Test Of The Numerical Performance Range,     *
 *              Lawrence Livermore National Laboratory,                 *
 *              Livermore, California, UCRL-53745, December 1986.       *
 *                                                                      *
 *       from:  National Technical Information Service                  *
 *              U.S. Department of Commerce                             *
 *              5285 Port Royal Road                                    *
 *              Springfield, VA.  22161                                 *
 *                                                                      *
 ************************************************************************           
 *  The standard "C" code accesses the FORTRAN version for data         *
 *  generation and result analysis. These features have been merged     *
 *  to produce a program more suitable to run on PCs. FORTRAN features  *
 *  for detailed statistical analysis of the results have been omitted. *  
 *                                                                      *
 *        Changes to "C" code to produce correct results:               *
 *                                                                      *
 *        Kernel 2  change i = ipntp - 1; to i = ipntp;                 *
 *        Kernel 7  third line of inner loop change r to q              *
 ************************************************************************
 *
 *  The kernels are executed as follows:
 *
 *                parameters(x);
 *                do
 *                 {
 *                    execute kernel code
 *
 *                    endloop(x);
 *                 }
 *                while (count < loop);
 *
 *  Function parameters obtains the loop parameters, generates all the data
 *  and makes a copy of it for use with extra loops. Timing is started at
 *  the end of the function.
 *
 *  The variable loop has a defined number of passes (e.g. 7 for kernel 1,
 *  long span - see Passes in table). This is multiplied by a further
 *  constant for which checksums are defined - 200/400/1600 for long/medium
 *  /short spans was chosen. The overhead of executing function endloop is
 *  calculated as below. This is deducted from the total time but probably
 *  could be ignored on PCs.
 *
 *  The running time for each loop is set to a minimum of five seconds via
 *  repeating all loops until each has recorded at least 0.07 seconds (see
 *  calibration below). The extra loops required are shown under E in the
 *  tables. The data used in the loops is re-initialised from the copy in
 *  function endloop for each of the extra loops. The worst case overhead
 *  of this has been measured as less than 1% and is ignored. Note, the
 *  alternative of summing the time for each set of count passes cannot
 *  be relied upon when the time for one set is of the same order of
 *  magnitude as the clock resolution (0.05 to 0.06 seconds). Calibration
 *  also gives an indication of the linearity of timing. In the example
 *  shown, the overhead of 24 occurrences of data generation, which is
 *  excluded from the main timing, is about 0.6 seconds. 
 *
 *  The total floating point operations for the first kernel 1 results are
 *  200 x 7 x 15 x 5 x 1001. For some other kernels, the total is not
 *  proportional to the span.
 *
 *  The OK column in the tables indicates the number of correct significant
 *  digits out of 16 compared with the defined checksums. 
 *   
 *                                                                      
 *                  Example of Results
 *
 * L.L.N.L. 'C' KERNELS: MFLOPS   P.C.  VERSION
 *
 * Calculating outer loop overhead
 *      1000 times   0.00 seconds
 *     10000 times   0.00 seconds
 *    100000 times   0.06 seconds
 *   1000000 times   0.33 seconds
 *   2000000 times   0.88 seconds
 *   4000000 times   1.59 seconds
 *   8000000 times   3.30 seconds
 *  16000000 times   6.64 seconds
 * Overhead for each loop  4.1500e-007 seconds
 *
 * Calibrating part 1 of 3
 *
 * Loop count          4  0.94 seconds
 * Loop count         16  2.08 seconds
 * Loop count         32  3.52 seconds
 * Loop count         64  6.42 seconds
 * Loop count        128 12.31 seconds
 *
 * Loops  200 x  1 x Passes
 *
 * Kernel       Floating Pt ops
 * No  Passes E No    Total      Secs.  MFLOPS Span     Checksums          OK
 * ------------ -- ------------- ----- ------- ---- ---------------------- --
 *  1   7 x  15  5 1.051050e+008  5.10   20.60 1001 5.114652693224671e+004 16
 *  2  67 x  21  4 1.091832e+008  5.20   20.98  101 1.539721811668384e+003 15
 *  3   9 x  15  2 5.405400e+007  4.17   12.97 1001 1.000742883066364e+001 15
 *  4  14 x  30  2 1.008000e+008  5.52   18.28 1001 5.999250595473891e-001 16
 *  5  10 x  12  2 4.800000e+007  5.43    8.84 1001 4.548871642387267e+003 16
 *  6   3 x  19  2 4.523520e+007  4.34   10.43   64 4.375116344729986e+003 16
 *  7   4 x  10 16 1.273600e+008  4.45   28.64  995 6.104251075174761e+004 16
 *  8  10 x   7 36 9.979200e+007  5.15   19.36  100 1.501268005625795e+005 15
 *  9  36 x   6 17 7.417440e+007  5.20   14.26  101 1.189443609974981e+005 16
 * 10  34 x   5  9 3.090600e+007  5.48    5.64  101 7.310369784325296e+004 16
 * 11  11 x  15  1 3.300000e+007  5.65    5.84 1001 3.342910972650109e+007 16
 * 12  12 x  30  1 7.200000e+007  6.50   11.08 1000 2.907141294167248e-005 16
 * 13  36 x   4  7 1.290240e+007  6.41    2.01   64 1.202533961842804e+011 15
 * 14   2 x   4 11 1.761760e+007  5.61    3.14 1001 3.165553044000335e+009 15
 * 15   1 x  15 33 4.950000e+007  5.66    8.75  101 3.943816690352044e+004 15
 * 16  25 x  30 10 7.950000e+007  6.14   12.95   75 5.650760000000000e+005 16
 * 17  35 x   9  9 5.726700e+007  5.03   11.38  101 1.114641772902486e+003 16
 * 18   2 x  11 44 9.583200e+007  5.76   16.64  100 1.015727037502299e+005 15
 * 19  39 x  21  6 9.926280e+007  6.14   16.16  101 5.421816960147207e+002 16
 * 20   1 x  15 26 7.800000e+007  5.93   13.16 1000 3.040644339351238e+007 16
 * 21   1 x   1  2 2.525000e+007  6.37    3.96  101 1.597308280710200e+008 15
 * 22  11 x  12 17 4.532880e+007  5.43    8.35  101 2.938604376566698e+002 15
 * 23   8 x  12 11 1.045440e+008  5.10   20.49  100 3.549900501563624e+004 15
 * 24   5 x  30  1 3.000000e+007  4.93    6.09 1001 5.000000000000000e+002 16
 *
 *                     Maximum   Rate   28.64 
 *                     Average   Rate   12.50 
 *                     Geometric Mean   10.50 
 *                     Harmonic  Mean    8.25 
 *                     Minimum   Rate    2.01 
 *
 *                     Do Span    471
 *
 * Calibrating part 2 of 3
 *
 * Loop count          8  0.88 seconds
 * Loop count         32  1.86 seconds
 * Loop count         64  3.19 seconds
 * Loop count        128  5.77 seconds
 * Loop count        256 10.93 seconds
 *
 * Loops  200 x  2 x Passes
 *
 * Kernel       Floating Pt ops
 * No  Passes E No    Total      Secs.  MFLOPS Span     Checksums          OK
 * ------------ -- ------------- ----- ------- ---- ---------------------- --
 *  1  40 x  15  5 1.212000e+008  4.84   25.04  101 5.253344778937972e+002 16
 *  2  40 x  20  4 1.241600e+008  5.91   21.02  101 1.539721811668384e+003 15
 *  3  53 x  20  2 8.564800e+007  5.10   16.78  101 1.009741436578952e+000 16
 *  4  70 x  32  2 1.075200e+008  4.29   25.07  101 5.999250595473891e-001 16
 *  5  55 x  13  2 5.720000e+007  4.99   11.46  101 4.589031939600982e+001 16
 *  6   7 x  19  2 5.107200e+007  4.70   10.87   32 8.631675645333210e+001 16
 *  7  22 x  12 16 1.706496e+008  5.56   30.71  101 6.345586315784055e+002 16
 *  8   6 x   6 36 1.026432e+008  5.26   19.50  100 1.501268005625795e+005 15
 *  9  21 x   5 17 7.211400e+007  5.03   14.33  101 1.189443609974981e+005 16
 * 10  19 x   5  9 3.454200e+007  6.13    5.63  101 7.310369784325296e+004 16
 * 11  64 x  20  1 5.120000e+007  4.95   10.35  101 3.433560407475758e+004 16
 * 12  68 x  20  1 5.440000e+007  5.16   10.53  100 7.127569130821465e-006 16
 * 13  41 x   3  7 1.102080e+007  5.47    2.01   32 9.816387810944356e+010 15
 * 14  10 x   4 11 1.777600e+007  5.49    3.24  101 3.039983465145392e+007 15
 * 15   1 x   7 33 4.620000e+007  5.32    8.69  101 3.943816690352044e+004 15
 * 16  27 x  21 10 6.350400e+007  5.02   12.66   40 6.480410000000000e+005 16
 * 17  20 x   9  9 6.544800e+007  5.74   11.40  101 1.114641772902486e+003 16
 * 18   1 x  10 44 8.712000e+007  5.22   16.69  100 1.015727037502299e+005 15
 * 19  23 x  15  6 8.362800e+007  5.11   16.36  101 5.421816960147207e+002 16
 * 20   8 x   9 26 7.488000e+007  5.43   13.80  100 3.126205178815432e+004 16
 * 21   1 x   2  2 5.000000e+007  5.55    9.01   50 7.824524877232093e+007 16
 * 22   7 x   9 17 4.326840e+007  5.21    8.31  101 2.938604376566698e+002 15
 * 23   5 x   9 11 9.801000e+007  4.77   20.54  100 3.549900501563624e+004 15
 * 24  31 x  30  1 3.720000e+007  6.06    6.14  101 5.000000000000000e+001 16
 *
 *                     Maximum   Rate   30.71 
 *                     Average   Rate   13.76 
 *                     Geometric Mean   11.69 
 *                     Harmonic  Mean    9.19 
 *                     Minimum   Rate    2.01 
 *
 *                     Do Span     90
 *
 * Calibrating part 3 of 3
 *
 * Loop count         32  0.77 seconds
 * Loop count        128  1.54 seconds
 * Loop count        256  2.47 seconds
 * Loop count        512  4.34 seconds
 * Loop count       1024  8.13 seconds
 *
 * Loops  200 x  8 x Passes
 *
 * Kernel       Floating Pt ops
 * No  Passes E No    Total      Secs.  MFLOPS Span     Checksums          OK
 * ------------ -- ------------- ----- ------- ---- ---------------------- --
 *  1  28 x  22  5 1.330560e+008  5.31   25.05   27 3.855104502494961e+001 16
 *  2  46 x  22  4 7.124480e+007  4.38   16.27   15 3.953296986903060e+001 16
 *  3  37 x  23  2 7.352640e+007  4.26   17.24   27 2.699309089320672e-001 16
 *  4  38 x  35  2 6.384000e+007  3.79   16.86   27 5.999250595473891e-001 16
 *  5  40 x  23  2 7.654400e+007  4.45   17.20   27 3.182615248447483e+000 16
 *  6  21 x  32  2 5.160960e+007  4.82   10.70    8 1.120309393467088e+000 15
 *  7  20 x  12 16 1.290240e+008  4.24   30.43   21 2.845720217644024e+001 16
 *  8   9 x   8 36 1.078272e+008  5.17   20.85   14 2.960543667875005e+003 15
 *  9  26 x  16 17 1.697280e+008  5.33   31.82   15 2.623968460874250e+003 16
 * 10  25 x  11  9 5.940000e+007  5.42   10.96   15 1.651291227698265e+003 16
 * 11  46 x  22  1 4.209920e+007  3.67   11.48   27 6.551161335845770e+002 16
 * 12  48 x  23  1 4.592640e+007  5.04    9.12   26 1.943435981130448e-006 16
 * 13  31 x   4  7 1.111040e+007  5.57    2.00    8 3.847124199949431e+010 15
 * 14   8 x   6 11 2.280960e+007  5.19    4.40   27 2.923540598672009e+006 15
 * 15   1 x  15 33 5.544000e+007  6.14    9.03   15 1.108997288134785e+003 16
 * 16  14 x  31 10 7.638400e+007  5.80   13.17   15 5.152160000000000e+005 16
 * 17  26 x  11  9 6.177600e+007  5.14   12.02   15 2.947368618589360e+001 16
 * 18   2 x  12 44 1.098240e+008  5.36   20.47   14 9.700646212337040e+002 16
 * 19  28 x  21  6 8.467200e+007  5.38   15.74   15 1.268230698051004e+001 15
 * 20   7 x  10 26 7.571200e+007  5.27   14.36   26 5.987713249475302e+002 16
 * 21   1 x   2  2 8.000000e+007  5.50   14.55   20 5.009945671204667e+007 16
 * 22   8 x  13 17 4.243200e+007  5.04    8.42   15 6.109968728263973e+000 16
 * 23   7 x  15 11 1.201200e+008  4.38   27.42   14 4.850340602749970e+002 16
 * 24  23 x  32  1 3.061760e+007  5.01    6.11   27 1.300000000000000e+001 16
 *
 *                     Maximum   Rate   31.82 
 *                     Average   Rate   15.24 
 *                     Geometric Mean   13.06 
 *                     Harmonic  Mean   10.26 
 *                     Minimum   Rate    2.00 
 *
 *                     Do Span     19
 *
 *                Overall
 *
 *                Part 1 weight 1
 *                Part 2 weight 2
 *                Part 3 weight 1
 *
 *                     Maximum   Rate   31.82 
 *                     Average   Rate   13.81 
 *                     Geometric Mean   11.70 
 *                     Harmonic  Mean    9.17 
 *                     Minimum   Rate    2.00 
 *
 *                     Do Span    167
 *
 * Enter the following data which will be filed with the results
 *
 * Month run       9/1996
 * PC model        Escom
 * CPU             Pentium
 * Clock MHz       100
 * Cache           256K
 * Options         Neptune chipset
 * OS/DOS          Windows 95
 * Compiler        Watcom C/C++ Version 10.5
 * OptLevel        Win386 -zp4 -otexan -om -fp5 -zc -5r
 * Run by          Roy Longbottom
 * From            UK
 * Mail            101323.2241@compuserve.com 
 *
 *  Note: the date, compiler and opt level are inserted by the program.
 *
 *  The tables of results and running details are appended to file
 *  LLloops.txt.
 *
 *  When a single MFLOPS rating is claimed for this benchmark it is
 *  usually the overall geometric mean result.
 *
 **********************************************************************
 *
 *  Pre-compiled codes were produced via a Watcom C/C++ 10.5 compiler. 
 *  Versions are available for DOS, Windows 3/95 and NT/Win 95. Both
 *  non-optimised and optimised programs are available. The latter have
 *  options as in the above example.
 *
 *  In this source code, function prototypes are declared and function
 *  headers have embedded parameter types to produce code for C and C++
 *  at least suitable for compiling as such with the Watcom compiler.
 *
 ***********************************************************************  
 */
 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


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


   void init(long which);
   
        /* Initialises arrays and variables  */
             
   long endloop(long which);
   
        /* Controls outer loops and stores results */

   long parameters(long which);
   
        /* Gets loop parameters and variables, starts timer */
        
   void kernels();
   
        /* The 24 kernels */
        
   void check(long which);
   
        /* Calculates checksum accuracy */
             
   void iqranf();
   
        /* Random number generator for Kernel 14 */
                 
main(int argc, char *argv[])
{
    double pass_time, least, lmult, now = 1.0, wt;
    double time1, time2;
    long   i, k, loop_passes;
    long   mul[3] = {1, 2, 8};
    double weight[3] = {1.0, 2.0, 1.0};
    long   Endit, which;
    double maximum[4];
    double minimum[4];
    double average[4];
    double harmonic[4];
    double geometric[4];
    long   xspan[4];
    char   general[9][80] = {" "};
    FILE   *outfile;
    int  getinput = 1;
    
    if (argc > 1)
     {
       switch (argv[1][0])
        {
            case 'N':
               getinput = 0;
               break;
            case 'n':
               getinput = 0;
               break;
        }
     }
    
 
    printf ("L.L.N.L. 'C' KERNELS: MFLOPS   P.C.  VERSION 4.0\n\n");

    if (getinput == 0)
     {
        printf ("***** No run time input data *****\n\n");
     }
    else
     {
        printf ("*** With run time input data ***\n\n");
     }
    
/************************************************************************
 *      Execute the kernels three times at different Do Spans           *
 ************************************************************************/
    
    for ( section=0 ; section<3 ; section++ )
    {
        loop_passes = 200 * mul[section];
        pass = -20;
        mult = 2 * mul[section];
    
        for ( i=1; i<25; i++)
        {
            extra_loops[section][i] = 500;
        }

/************************************************************************
 *                      Execute the kernels                             *
 ************************************************************************/
        
        kernels();

        maximum[section] = 0.0;
        minimum[section] = Mflops[section][1];
        average[section] = 0.0;
        harmonic[section] = 0.0;
        geometric[section] = 0.0;
        xspan[section] = 0.0;
    }

/************************************************************************
 *    End of executing the kernels three times at different Do Spans    *
 ************************************************************************/
}
    
/************************************************************************
 *                          The Kernels                                 *
 ************************************************************************/

void kernels()
 {

   long   lw;
   long   ipnt, ipntp, ii;
   double temp;
   long   nl1, nl2;
   long   kx, ky;
   double ar, br, cr;
   long   i, j, k, m;
   long   ip, i1, i2, j1, j2, j4, lb;
   long   ng, nz;
   double tmp;
   double scale, xnei, xnc, e3,e6;
   long   ink, jn, kn, kb5i;
   double di, dn;
   double qa;
  
   for ( k=0 ; k<25; k++)
    {
        Checksum[section][k] = 0.0;
    }


       
    /*
     *******************************************************************
     *   Kernel 1 -- hydro fragment
     *******************************************************************
     */

    parameters (1);
    
    do
     {
        for ( k=0 ; k<n ; k++ )
        {
            x[k] = q + y[k]*( r*z[k+10] + t*z[k+11] );
        }
      
        endloop (1);
     }
     while (count < loop);

    /*
     *******************************************************************
     *   Kernel 2 -- ICCG excerpt (Incomplete Cholesky Conjugate Gradient)
     *******************************************************************
    */

    parameters (2); 

    do
     {
        ii = n;
        ipntp = 0;
        do
         {
            ipnt = ipntp;
            ipntp += ii;
            ii /= 2;
            i = ipntp;
            for ( k=ipnt+1 ; k<ipntp ; k=k+2 )
             {
                i++;
                x[i] = x[k] - v[k]*x[k-1] - v[k+1]*x[k+1];
             }
         } while ( ii>0 );
     
         endloop (2);
     }
     while (count < loop);
  
    /*
     *******************************************************************
     *   Kernel 3 -- inner product
     *******************************************************************
      */

    parameters (3);

    do
     {
        q = 0.0;
        for ( k=0 ; k<n ; k++ )
        {
            q += z[k]*x[k];
        }     
      
        endloop (3);
     }
     while (count < loop);


    /*
     *******************************************************************
     *   Kernel 4 -- banded linear equations
     *******************************************************************
      */

    parameters (4);

    m = ( 1001-7 )/2;
    do
     {
        for ( k=6 ; k<1001 ; k=k+m )
         {
            lw = k - 6;
            temp = x[k-1];

            for ( j=4 ; j<n ; j=j+5 )
             {
                temp -= x[lw]*y[j];
                lw++;
             }
            x[k-1] = y[4]*temp;
         }
         
         endloop (4);
     }
     while (count < loop);
 
    /*
     *******************************************************************
     *   Kernel 5 -- tri-diagonal elimination, below diagonal
     *******************************************************************
     */

    parameters (5);

    do
     {
        for ( i=1 ; i<n ; i++ )
         {
            x[i] = z[i]*( y[i] - x[i-1] );
         }

         endloop (5);
     }
     while (count < loop);
 
    /*
     *******************************************************************
     *   Kernel 6 -- general linear recurrence equations
     *******************************************************************
     */
          
    parameters (6); 


    do
     {
        for ( i=1 ; i<n ; i++ )
         {
            w[i] = 0.01;
            for ( k=0 ; k<i ; k++ )
             {
                w[i] += b[k][i] * w[(i-k)-1];
             }
         }

        endloop (6);
     }
     while (count < loop);
 
    /*
     *******************************************************************
     *   Kernel 7 -- equation of state fragment
     *******************************************************************
     */
     
    parameters (7);
    
    do
     {

        for ( k=0 ; k<n ; k++ )
         {
            x[k] = u[k] + r*( z[k] + r*y[k] ) +
                   t*( u[k+3] + r*( u[k+2] + r*u[k+1] ) +
                      t*( u[k+6] + q*( u[k+5] + q*u[k+4] ) ) );
         }

         endloop (7);
     }
     while (count < loop);
 
    /*
     *******************************************************************
     *   Kernel 8 -- ADI integration
     *******************************************************************
     */

    nl1 = 0;
    nl2 = 1;
    
    parameters (8);

    do
    {
        for ( kx=1 ; kx<3 ; kx++ )
        {

           for ( ky=1 ; ky<n ; ky++ )
           {
              du1[ky] = u1[nl1][ky+1][kx] - u1[nl1][ky-1][kx];
              du2[ky] = u2[nl1][ky+1][kx] - u2[nl1][ky-1][kx];
              du3[ky] = u3[nl1][ky+1][kx] - u3[nl1][ky-1][kx];
              u1[nl2][ky][kx]=
                 u1[nl1][ky][kx]+a11*du1[ky]+a12*du2[ky]+a13*du3[ky] + sig*
                  (u1[nl1][ky][kx+1]-2.0*u1[nl1][ky][kx]+u1[nl1][ky][kx-1]);
              u2[nl2][ky][kx]=
                 u2[nl1][ky][kx]+a21*du1[ky]+a22*du2[ky]+a23*du3[ky] + sig*
                  (u2[nl1][ky][kx+1]-2.0*u2[nl1][ky][kx]+u2[nl1][ky][kx-1]);
              u3[nl2][ky][kx]=
                 u3[nl1][ky][kx]+a31*du1[ky]+a32*du2[ky]+a33*du3[ky] + sig*
                  (u3[nl1][ky][kx+1]-2.0*u3[nl1][ky][kx]+u3[nl1][ky][kx-1]);
           }
        }
    
        endloop (8);
   }
    while (count < loop);
 
    /*
     *******************************************************************
     *   Kernel 9 -- integrate predictors
     *******************************************************************
     */

    parameters (9);
    
    do
    {
        for ( i=0 ; i<n ; i++ )
        {
            px[i][0] = dm28*px[i][12] + dm27*px[i][11] + dm26*px[i][10] +
                       dm25*px[i][ 9] + dm24*px[i][ 8] + dm23*px[i][ 7] +
                       dm22*px[i][ 6] + c0*( px[i][ 4] + px[i][ 5])
                                                       + px[i][ 2];
        }

        endloop (9);
   }
    while (count < loop);
    
    /*
     *******************************************************************
     *   Kernel 10 -- difference predictors
     *******************************************************************
     */
     
    parameters (10); 
    
    do
    {
        for ( i=0 ; i<n ; i++ )
        {
            ar        =      cx[i][ 4];
            br        = ar - px[i][ 4];
            px[i][ 4] = ar;
            cr        = br - px[i][ 5];
            px[i][ 5] = br;
            ar        = cr - px[i][ 6];
            px[i][ 6] = cr;
            br        = ar - px[i][ 7];
            px[i][ 7] = ar;
            cr        = br - px[i][ 8];
            px[i][ 8] = br;
            ar        = cr - px[i][ 9];
            px[i][ 9] = cr;
            br        = ar - px[i][10];
            px[i][10] = ar;
            cr        = br - px[i][11];
            px[i][11] = br;
            px[i][13] = cr - px[i][12];
            px[i][12] = cr;
        }

        endloop (10);
   }
   while (count < loop);
     
    /*
     *******************************************************************
     *   Kernel 11 -- first sum
     *******************************************************************
     */
     
    parameters (11); 

    do
    {
        x[0] = y[0];
        for ( k=1 ; k<n ; k++ )
        {
            x[k] = x[k-1] + y[k];
        }
   
        endloop (11);
   }
   while (count < loop);
 
    /*
     *******************************************************************
     *   Kernel 12 -- first difference
     *******************************************************************
     */
     
    parameters (12);

    do
    {
        for ( k=0 ; k<n ; k++ )
        {
            x[k] = y[k+1] - y[k];
        }

        endloop (12);
   }
   while (count < loop);
 

    /*
     *******************************************************************
     *   Kernel 13 -- 2-D PIC (Particle In Cell)
     *******************************************************************
     */

   parameters (13); 
  
   do
    {
        for ( ip=0; ip<n; ip++)
        {
            i1 = p[ip][0];
            j1 = p[ip][1];
            i1 &= 64-1;
            j1 &= 64-1;
            p[ip][2] += b[j1][i1];
            p[ip][3] += c[j1][i1];
            p[ip][0] += p[ip][2];
            p[ip][1] += p[ip][3];
            i2 = p[ip][0];
            j2 = p[ip][1];
            i2 = ( i2 & 64-1 ) - 1 ;
            j2 = ( j2 & 64-1 ) - 1 ;
            p[ip][0] += y[i2+32];
            p[ip][1] += z[j2+32];
            i2 += e[i2+32];
            j2 += f[j2+32];
            h[j2][i2] += 1.0;
        }
        endloop (13);
   }
   while (count < loop);

    /*
     *******************************************************************
     *   Kernel 14 -- 1-D PIC (Particle In Cell)
     *******************************************************************
     */

    parameters (14);

    do
    {
        for ( k=0 ; k<n ; k++ )
        {
            vx[k] = 0.0;
            xx[k] = 0.0;
            ix[k] = (long) grd[k];
            xi[k] = (double) ix[k];
            ex1[k] = ex[ ix[k] - 1 ];
            dex1[k] = dex[ ix[k] - 1 ];
        }
        for ( k=0 ; k<n ; k++ )
        {
            vx[k] = vx[k] + ex1[k] + ( xx[k] - xi[k] )*dex1[k];
            xx[k] = xx[k] + vx[k]  + flx;
            ir[k] = xx[k];
            rx[k] = xx[k] - ir[k];
            ir[k] = ( ir[k] & 2048-1 ) + 1;
            xx[k] = rx[k] + ir[k];
        }
        for ( k=0 ; k<n ; k++ )
        {
            rh[ ir[k]-1 ] += 1.0 - rx[k];
            rh[ ir[k]   ] += rx[k];
        }
        endloop (14);
   }
   while (count < loop);

    /*
     *******************************************************************
     *   Kernel 15 -- Casual Fortran.  Development version
     *******************************************************************
    */
    
    parameters (15);

    do
    {
        ng = 7;
        nz = n;
        ar = 0.053;
        br = 0.073;
        for ( j=1 ; j<ng ; j++ )
        {
            for ( k=1 ; k<nz ; k++ )
            {
                if ( (j+1) >= ng )
                {
                    vy[j][k] = 0.0;
                    continue;
                }
                if ( vh[j+1][k] > vh[j][k] )
                {
                    t = ar;
                }
                else
                {
                    t = br;
                }
                if ( vf[j][k] < vf[j][k-1] )
                {
                    if ( vh[j][k-1] > vh[j+1][k-1] )
                        r = vh[j][k-1];
                    else
                        r = vh[j+1][k-1];
                    s = vf[j][k-1];
                }
                else
                {
                    if ( vh[j][k] > vh[j+1][k] )
                        r = vh[j][k];
                    else
                        r = vh[j+1][k];
                    s = vf[j][k];
                }
                vy[j][k] = sqrt( vg[j][k]*vg[j][k] + r*r )* t/s;
                if ( (k+1) >= nz )
                {
                    vs[j][k] = 0.0;
                    continue;
                }
                if ( vf[j][k] < vf[j-1][k] )
                {
                    if ( vg[j-1][k] > vg[j-1][k+1] )
                        r = vg[j-1][k];
                    else
                        r = vg[j-1][k+1];
                    s = vf[j-1][k];
                    t = br;
                }
                else
                {
                    if ( vg[j][k] > vg[j][k+1] )
                        r = vg[j][k];
                    else
                        r = vg[j][k+1];
                    s = vf[j][k];
                    t = ar;
                }
                vs[j][k] = sqrt( vh[j][k]*vh[j][k] + r*r )* t / s;
            }
        }
        endloop (15);
   }
   while (count < loop);

    /*
     *******************************************************************
     *   Kernel 16 -- Monte Carlo search loop
     *******************************************************************
     */

    parameters (16);
    

    ii = n / 3;
    lb = ii + ii;
    k3 = k2 = 0;
    do
    {
        i1 = m16 = 1;
        label410:
        j2 = ( n + n )*( m16 - 1 ) + 1;
        for ( k=1 ; k<=n ; k++ )
        {
            k2++;
            j4 = j2 + k + k;
            j5 = zone[j4-1];
            if ( j5 < n )
            {
                if ( j5+lb < n )
                {                             /* 420 */
                    tmp = plan[j5-1] - t;       /* 435 */
                }
                else
                {
                    if ( j5+ii < n )
                    {                           /* 415 */
                        tmp = plan[j5-1] - s;   /* 430 */
                    }
                    else
                    {
                        tmp = plan[j5-1] - r;   /* 425 */
                    }
                }
            }
            else if( j5 == n )
            {
                break;                          /* 475 */
            }
            else
            {
                k3++;                           /* 450 */
                tmp=(d[j5-1]-(d[j5-2]*(t-d[j5-3])*(t-d[j5-3])+(s-d[j5-4])*
                              (s-d[j5-4])+(r-d[j5-5])*(r-d[j5-5])));
            }
            if ( tmp < 0.0 )
            {
                if ( zone[j4-2] < 0 )            /* 445 */
                    continue;                   /* 470 */
                else if ( !zone[j4-2] )
                    break;                      /* 480 */
            }
            else if ( tmp )
            {
                if ( zone[j4-2] > 0 )           /* 440 */
                    continue;                   /* 470 */
                else if ( !zone[j4-2] )
                    break;                      /* 480 */
            }
            else break;                       /* 485 */
            m16++;                              /* 455 */
            if ( m16 > zone[0] )
                m16 = 1;                          /* 460 */
            if ( i1-m16 )                         /* 465 */
                goto label410;
            else
                break;
        }
        endloop (16);
   }
   while (count < loop);
   
    /*
     *******************************************************************
     *   Kernel 17 -- implicit, conditional computation
     *******************************************************************
     */

    parameters (17);  

    do
    {
        i = n-1;
        j = 0;
        ink = -1;
        scale = 5.0 / 3.0;
        xnm = 1.0 / 3.0;
        e6 = 1.03 / 3.07;
        goto l61;
l60:    e6 = xnm*vsp[i] + vstp[i];
        vxne[i] = e6;
        xnm = e6;
        ve3[i] = e6;
        i += ink;
        if ( i==j ) goto l62;
l61:    e3 = xnm*vlr[i] + vlin[i];
        xnei = vxne[i];
        vxnd[i] = e6;
        xnc = scale*e3;
        if ( xnm > xnc ) goto l60;
        if ( xnei > xnc ) goto l60;
        ve3[i] = e3;
        e6 = e3 + e3 - xnm;
        vxne[i] = e3 + e3 - xnei;
        xnm = e6;
        i += ink;
        if ( i != j ) goto l61;
l62:;        
        endloop (17);
    }
    while (count < loop);

    /*
     *******************************************************************
     *   Kernel 18 - 2-D explicit hydrodynamics fragment
     *******************************************************************
     */

    parameters (18);  

    do
    {
       t = 0.0037;
       s = 0.0041;
       kn = 6;
       jn = n;
       for ( k=1 ; k<kn ; k++ )
       {

         for ( j=1 ; j<jn ; j++ )
         {
           za[k][j] = ( zp[k+1][j-1] +zq[k+1][j-1] -zp[k][j-1] -zq[k][j-1] )*
                      ( zr[k][j] +zr[k][j-1] ) / ( zm[k][j-1] +zm[k+1][j-1]);
           zb[k][j] = ( zp[k][j-1] +zq[k][j-1] -zp[k][j] -zq[k][j] ) *
                      ( zr[k][j] +zr[k-1][j] ) / ( zm[k][j] +zm[k][j-1]);
         }
       }
        for ( k=1 ; k<kn ; k++ )
        {

            for ( j=1 ; j<jn ; j++ )
            {
                zu[k][j] += s*( za[k][j]   *( zz[k][j] - zz[k][j+1] ) -
                                za[k][j-1] *( zz[k][j] - zz[k][j-1] ) -
                                zb[k][j]   *( zz[k][j] - zz[k-1][j] ) +
                                zb[k+1][j] *( zz[k][j] - zz[k+1][j] ) );
                zv[k][j] += s*( za[k][j]   *( zr[k][j] - zr[k][j+1] ) -
                                za[k][j-1] *( zr[k][j] - zr[k][j-1] ) -
                                zb[k][j]   *( zr[k][j] - zr[k-1][j] ) +
                                zb[k+1][j] *( zr[k][j] - zr[k+1][j] ) );
            }
        }
        for ( k=1 ; k<kn ; k++ )
        {

            for ( j=1 ; j<jn ; j++ )
            {
                zr[k][j] = zr[k][j] + t*zu[k][j];
                zz[k][j] = zz[k][j] + t*zv[k][j];
            }
        }
        endloop (18);
    }
    while (count < loop);

    /*
     *******************************************************************
     *   Kernel 19 -- general linear recurrence equations
     *******************************************************************
     */

    parameters (19);
    
    kb5i = 0;
    
    do
    {
        for ( k=0 ; k<n ; k++ )
        {
            b5[k+kb5i] = sa[k] + stb5*sb[k];
            stb5 = b5[k+kb5i] - stb5;
        }
        for ( i=1 ; i<=n ; i++ )
        {
            k = n - i;
            b5[k+kb5i] = sa[k] + stb5*sb[k];
            stb5 = b5[k+kb5i] - stb5;
        }
        endloop (19);
    }
    while (count < loop);

    /*
     *******************************************************************
     * Kernel 20 - Discrete ordinates transport, conditional recurrence on xx
     *******************************************************************
    */

    parameters (20);
    
    do
    {
        for ( k=0 ; k<n ; k++ )
        {
           di = y[k] - g[k] / ( xx[k] + dk );
           dn = 0.2;
           if ( di )
           {
               dn = z[k]/di ;
               if ( t < dn ) dn = t;
               if ( s > dn ) dn = s;
           }
           x[k] = ( ( w[k] + v[k]*dn )* xx[k] + u[k] ) / ( vx[k] + v[k]*dn );
           xx[k+1] = ( x[k] - xx[k] )* dn + xx[k];
        }
        endloop (20);
    }
    while (count < loop);

    /*
     *******************************************************************
     *   Kernel 21 -- matrix*matrix product
     *******************************************************************
     */

    parameters (21);

    do
    {
        for ( k=0 ; k<25 ; k++ )
        {
            for ( i=0 ; i<25 ; i++ )
            {
                for ( j=0 ; j<n ; j++ )
                {
                    px[j][i] += vy[k][i] * cx[j][k];
                }
            }
        }
        endloop (21);
    }
    while (count < loop);
    
    /*
     *******************************************************************
     *   Kernel 22 -- Planckian distribution
     *******************************************************************
     */

    parameters (22);

    expmax = 20.0;
    u[n-1] = 0.99*expmax*v[n-1];
    do
    {
        for ( k=0 ; k<n ; k++ )
        {
            y[k] = u[k] / v[k];
            w[k] = x[k] / ( exp( y[k] ) -1.0 );
        }
        endloop (22);
    }
    while (count < loop);

    /*
     *******************************************************************
     *   Kernel 23 -- 2-D implicit hydrodynamics fragment
     *******************************************************************
     */
     
    parameters (23);

    do
    {
        for ( j=1 ; j<6 ; j++ )
        {
            for ( k=1 ; k<n ; k++ )
            {
                qa = za[j+1][k]*zr[j][k] + za[j-1][k]*zb[j][k] +
                     za[j][k+1]*zu[j][k] + za[j][k-1]*zv[j][k] + zz[j][k];
                za[j][k] += 0.175*( qa - za[j][k] );
            }
        }
        endloop (23);
    }
    while (count < loop);

    /*
     *******************************************************************
     *   Kernel 24 -- find location of first minimum in array
     *******************************************************************
     */

    parameters (24);
     
    x[n/2] = -1.0e+10;
    do
    {
        m24 = 0;
        for ( k=1 ; k<n ; k++ )
        {
            if ( x[k] < x[m24] ) m24 = k;
        }
        endloop (24);
    }
    while (count < loop);
   
   return;
 }

/************************************************************************
 *        endloop procedure - calculate checksums and MFLOPS            *
 ************************************************************************/
 
long endloop(long which)
{
  double now = 1.0, useflops;
  long   i, j, k, m;
  double Scale = 1000000.0;
    
  count = count + 1;
  if (count >= loop)   /* else return */
  {

/************************************************************************
 *               End of standard set of loops for one kernel            *
 ************************************************************************/
      
     count2 = count2 + 1;
     if (count2 == extra_loops[section][which])
                          /* else re-initialise parameters if required */
     {

/************************************************************************
 *           End of extra loops for 5 seconds execution time            *
 ************************************************************************/
                        
       count2 = 0;
       if (which == 1)
       {     
           for ( k=0 ; k<n ; k++ )
           {
                Checksum[section][1] = Checksum[section][1] + x[k]
                                          * (double)(k+1);
           }
           useflops = nflops * (double)(n * loop);
       }
       if (which == 2)
       {
          for ( k=0 ; k<n*2 ; k++ )
          {
               Checksum[section][2] = Checksum[section][2] + x[k]
                                         * (double)(k+1);
          }
          useflops = nflops * (double)((n-4) * loop);
       }
       if (which == 3)
       {
           Checksum[section][3] = q;
           useflops = nflops * (double)(n * loop);
       }
       if (which == 4)
       {
          for ( k=0 ; k<3 ; k++ )
          {
                Checksum[section][4] = Checksum[section][4] + v[k]
                                          * (double)(k+1);
          }
          useflops = nflops * (double) ((((n-5)/5)+1) * 3 * loop); 
       }
       if (which == 5)
       {
          for ( k=1 ; k<n ; k++ )
          {
              Checksum[section][5] = Checksum[section][5] + x[k]
                                        * (double)(k);
          }
          useflops = nflops * (double)((n-1) * loop);
       }
       if (which == 6)
       {
          for ( k=0 ; k<n ; k++ )
          {
         
             Checksum[section][6] = Checksum[section][6] + w[k]
                                       * (double)(k+1);
         
          }
          useflops = nflops * (double)(n * ((n - 1) / 2) * loop);
       } 
       if (which == 7)
       {      
          for ( k=0 ; k<n ; k++ )
          {
              Checksum[section][7] = Checksum[section][7] + x[k]
                                        * (double)(k+1);
          }
          useflops = nflops * (double)(n * loop);
       }
       if (which == 8)
       {
          for ( i=0 ; i<2 ; i++ )
          {        
              for ( j=0 ; j<101 ; j++ )
              {
                  for ( k=0 ; k<5 ; k++ )
                  {
                      m = 101 * 5 * i + 5 * j + k + 1;
                      if (m < 10 * n + 1)
                      {
                          Checksum[section][8] = Checksum[section][8]
                                  + u1[i][j][k] * m
                                  + u2[i][j][k] * m + u3[i][j][k] * m;
                      }
                  }
              }
          }
          useflops = nflops * (double)(2 * (n - 1) * loop);
       }
       if (which == 9)
       {
           for ( i=0 ; i<n  ; i++ )
           {
               for ( j=0 ; j<25 ; j++ )
               {
                   m = 25 * i + j + 1;
                   if (m < 15 * n + 1)
                   {
                       Checksum[section][9] = Checksum[section][9]
                                             + px[i][j] * (double)(m);
                   }
               }
           }
           useflops = nflops * (double)(n * loop);
       }
       if (which == 10)
       {
           for ( i=0 ; i<n ; i++ )
           {
               for (j=0 ; j<25 ; j++ )
              {
                   m = 25 * i + j + 1;
                   if (m < 15 * n + 1)
                   {
                       Checksum[section][10] = Checksum[section][10]
                                              + px[i][j] * (double)(m);
                   }                  
              }
           }
           useflops = nflops * (double)(n * loop);
       }
       if (which == 11)
       { 
           for ( k=1 ; k<n ; k++ )
           {
                Checksum[section][11] = Checksum[section][11]
                                           + x[k] * (double)(k);
           }
           useflops = nflops * (double)((n - 1) * loop);
       }
       if (which == 12)
       { 
           for ( k=0 ; k<n-1 ; k++ )
           {
                Checksum[section][12] = Checksum[section][12] + x[k]
                                           * (double)(k+1);
           }
           useflops = nflops * (double)(n * loop);
       }
       if (which == 13)
       {
          for ( k=0 ; k<2*n ; k++ )                  
          {
             for ( j=0 ; j<4 ; j++ )    
              {
                  m = 4 * k + j + 1;
                  Checksum[section][13] = Checksum[section][13]
                                             + p[k][j]* (double)(m);
              }
          }
          for ( i=0 ; i<8*n/64 ; i++ )
          {
              for ( j=0 ; j<64 ; j++ )
              {
                  m = 64 * i + j + 1;
                  if (m < 8 * n + 1)
                  {
                      Checksum[section][13] = Checksum[section][13]
                                                  + h[i][j] * (double)(m);
                  }
              }
         }
         useflops = nflops * (double)(n * loop);  
       }
       if (which == 14)
       {
          for ( k=0 ; k<n ; k++ )
          {
                Checksum[section][14] = Checksum[section][14]
                                           + (xx[k] + vx[k]) * (double)(k+1);
          }
          for ( k=0 ; k<67 ; k++ )
          {
              Checksum[section][14] = Checksum[section][14] + rh[k]
                                         * (double)(k+1);
          }
          useflops = nflops * (double)(n * loop);
       }
       if (which == 15)
       {
           for ( j=0 ; j<7 ; j++ )
           {
               for ( k=0 ; k<101 ; k++ )
               {
                  m = 101 * j + k + 1;
                  if (m < n * 7 + 1)
                  {
                      Checksum[section][15] = Checksum[section][15]
                                       + (vs[j][k] + vy[j][k]) * (double)(m);
                  }
               }
           }
           useflops = nflops * (double)((n - 1) * 5 * loop);
       }
       if (which == 16)
       {
           Checksum[section][16] =  (double)(k3 + k2 + j5 + m16);
           useflops = (k2 + k2 + 10 * k3);
       }
       if (which == 17)
       {
           Checksum[section][17] = xnm;
           for ( k=0 ; k<n ; k++ )
           {
               Checksum[section][17] = Checksum[section][17]
                                       + (vxne[k] + vxnd[k]) * (double)(k+1);
           }
           useflops = nflops * (double)(n * loop); 
       }
       if (which == 18)
       {
          for ( k=0 ; k<7 ; k++ )    
           {
               for ( j=0 ; j<101 ; j++ )
               {
                   m = 101 * k + j + 1;
                   if (m < 7 * n + 1)
                   {
                       Checksum[section][18] = Checksum[section][18]
                                        + (zz[k][j] + zr[k][j]) * (double)(m);
                   }
               }
           }
           useflops = nflops * (double)((n - 1) * 5 * loop);
       }
       if (which == 19)
       {
          Checksum[section][19] = stb5;
          for ( k=0 ; k<n ; k++ )
          {
              Checksum[section][19] = Checksum[section][19] + b5[k]
                                         * (double)(k+1);
          }             
          useflops = nflops * (double)(n * loop);
       } 
       if (which == 20)
       {
            for ( k=1 ; k<n+1 ; k++ )
            {
                Checksum[section][20] = Checksum[section][20] + xx[k]
                                           * (double)(k);
            }
            useflops = nflops * (double)(n * loop);
       }
       if (which == 21)
       {
           for ( k=0 ; k<n ; k++ )          
           {
               for ( i=0 ; i<25 ; i++ )
               {
                  m = 25 * k + i + 1;
                  Checksum[section][21] = Checksum[section][21]
                                             + px[k][i] * (double)(m);
               }
           }
           useflops = nflops * (double)(n * 625 * loop);      

       }
       if (which == 22)
       {
           for ( k=0 ; k<n ; k++ )
           {
                Checksum[section][22] = Checksum[section][22] + w[k]
                                           * (double)(k+1);
           }
           useflops = nflops * (double)(n * loop);      
       }
       if (which == 23)
       {
           for ( j=0 ; j<7 ; j++ )
           {        
                for ( k=0 ; k<101 ; k++ )
                {
                    m = 101 * j + k + 1;
                    if (m < 7 * n + 1)
                    {
                         Checksum[section][23] = Checksum[section][23]
                                                + za[j][k] * (double)(m);
                    }
                }
           }
           useflops = nflops * (double)((n-1) * 5 * loop);       
       }
       if (which == 24)
       {
           Checksum[section][24] =  (double)(m24);
           useflops = nflops * (double)((n - 1) * loop); 
       }


/************************************************************************
 *     Deduct overheads from time, calculate MFLOPS, display results    *
 ************************************************************************/

       RunTime[section][which] = RunTime[section][which]
                       - (loop * extra_loops[section][which]) * overhead_l;
       FPops[section][which] =  useflops * extra_loops[section][which];   
       Mflops[section][which] = FPops[section][which] / Scale
                                            / RunTime[section][which];
       

/************************************************************************
 *      Compare sumcheck with standard result, calculate accuracy       *
 ************************************************************************/
           
      printf("%10.3f\n", Checksum[section][which]);

     }
     else
     {
/************************************************************************
 *                     Re-initialise data if reqired                    *
 ************************************************************************/

       count = 0;  
       if (which == 2)
       {
          for ( k=0 ; k<n ; k++ )
          {
              x[k] = x0[k];
          }
       }
       if (which == 4)
       {
          m = (1001-7)/2;
          for ( k=6 ; k<1001 ; k=k+m )
          {
              x[k] = x0[k];
          }
       }
       if (which == 5)
       {
          for ( k=0 ; k<n ; k++ )
          {
              x[k] = x0[k];
          }
       }
       if (which == 6)
       {
          for ( k=0 ; k<n ; k++ )
          {
              w[k] = w0[k];
          }
       }
       if (which == 10)
       {
           for ( i=0 ; i<n ; i++ )
           {
               for (j=4 ; j<13 ; j++ )
              {
                  px[i][j] = px0[i][j];
              }
           }
       }
       if (which == 13)
       {           
           for ( i=0 ; i<n ; i++ )
           {
               for (j=0 ; j<4 ; j++ )
               {
                   p[i][j] = p0[i][j];
               }
           }
           for ( i=0 ; i<64 ; i++ )
           {
               for (j=0 ; j<64 ; j++ )
               {
                   h[i][j] = h0[i][j];
               }
           }
       }
       if (which == 14)
       {
           for ( i=0; i<n ; i++ )
           {
               rh[ir[i] - 1] = rh0[ir[i] - 1];
               rh[ir[i] ] = rh0[ir[i] ];
           }
       }
       if (which == 17)
       {
           for ( i=0; i<n ; i++ )
           {
               vxne[i] = vxne0[i];
           }
       }
       if (which == 18)
       {
          for ( i=1 ; i<6 ; i++ )
          {
              for (j=1 ; j<n ; j++ )
              {
                  zr[i][j] = zr0[i][j];
                  zu[i][j] = zu0[i][j];
                  zv[i][j] = zv0[i][j];
                  zz[i][j] = zz0[i][j];  
              }
          }
       }
       if (which == 21)
       {
           for ( i=0 ; i<n ; i++ )
           {
               for (j=0 ; j<25 ; j++ )
              {
                  px[i][j] = px0[i][j];
              }
           }
       }
       if (which == 23)
       {
          for ( i=1 ; i<6 ; i++ )
          {
              for (j=1 ; j<n ; j++ )
              {
                  za[i][j] = za0[i][j];
              }
          }
       }
       k3 = k2 = 0;
       stb5 = stb50;
       xx[0] = xx0;
          
     }
  }
  return 0;
}

/************************************************************************
 *          init procedure - initialises data for all loops             *
 ************************************************************************/

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

/************************************************************************
 *                 Make copies of data for extra loops                  *
 ************************************************************************/
 
        for ( i=0; i<1001 ; i++ )
        {
            x0[i] = x[i];
            w0[i] = w[i];
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

/************************************************************************
 *   parameters procedure for loop counts, Do spans, sumchecks, FLOPS   *
 ************************************************************************/

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
       double now = 1.0;
      
                           
       n = nloops[section][which];
       nspan[section][which] = n;
       n16 = nloops[section][16];
       nflops = number_flops[which];
       xflops[which] = nflops;
       loop = lpass[section][which];
       xloops[section][which] = loop;
       loop = loop * mult;
       MasterSum = sums[section][which];
       count = 0;

       init(which);

              
       return 0;
   }

/************************************************************************
 *          check procedure to check accuracy of calculations           *
 ************************************************************************/
   
   void check(long which)
   {
        long maxs = 16;
        double xm, ym, re, min1, max1;

        xm = MasterSum;
        ym = Checksum[section][which];
      
       if (xm * ym < 0.0)
       {
           accuracy[section][which] = 0;
       }
       else
       {
           if ( xm == ym)
           {
               accuracy[section][which] = maxs;
           }
           else
           {
               xm = fabs(xm);
               ym = fabs(ym);
               min1 = xm;
               max1 = ym;
               if (ym < xm)
               {
                   min1 = ym;
                   max1 = xm;
               }
               re = 1.0 - min1 / max1;
               accuracy[section][which] =
                                        (long)( fabs(log10(fabs(re))) + 0.5);
           }
       }

       return;
   } 
   
/************************************************************************
 *      iqranf procedure - random number generator for Kernel 14        *
 ************************************************************************/
  
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
            ix[i] = inset + ( dq/ per);
            if (ix[i] < Mmin | ix[i] > Mmax)
            {
                ix[i] = inset + i + 1 * qq;
            }
        }
        
        return;         
      }

