//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
//------------------------------------------------------------------------------------------------------------------------------
#ifdef __MPI
#include <mpi.h>
#endif
//------------------------------------------------------------------------------------------------------------------------------
#include "defines.h"
#include "box.h"
#include "mg.h"
#include "operators.h"
#include "timer.h"
//------------------------------------------------------------------------------------------------------------------------------
#warning Using Diagonally Preconditioned Iterative Solvers
#define DiagonallyPrecondition
//------------------------------------------------------------------------------------------------------------------------------
#ifndef    __CA_KRYLOV_S
#define    __CA_KRYLOV_S     4
#endif

//#define __VERBOSE
//#define __DEBUG
//------------------------------------------------------------------------------------------------------------------------------
// z[r] = alpha*A[r][c]*x[c]+beta*y[r]   // [row][col]
// z[r] = alpha*A[r][c]*x[c]+beta*y[r]   // [row][col]
#define __gemv(z,alpha,A,x,beta,y,rows,cols)  {int r,c;double sum;for(r=0;r<(rows);r++){sum=0.0;for(c=0;c<(cols);c++){sum+=(A)[r][c]*(x)[c];}(z)[r]=(alpha)*sum+(beta)*(y)[r];}}
static inline void __axpy(double * z, double alpha, double * x, double beta, double * y, int n){ // z[n] = alpha*x[n]+beta*y[n]
  int nn;
  for(nn=0;nn<n;nn++){
    z[nn] = alpha*x[nn] + beta*y[nn];
  }
}
static inline double __dot(double * x, double * y, int n){ // x[n].y[n]
  int nn;
  double sum = 0.0;
  for(nn=0;nn<n;nn++){
    sum += x[nn]*y[nn];
  }
  return(sum);
}
static inline void __zero(double * z, int n){ // z[n] = 0.0
  int nn;
  for(nn=0;nn<n;nn++){
    z[nn] = 0.0;
  }
}


//------------------------------------------------------------------------------------------------------------------------------
void TelescopingCABiCGStab(domain_type * domain, int level, int e_id, int R_id, double a, double b, double desired_reduction_in_norm){
  // based on Erin Carson/Jim Demmel/Nick Knight's s-Step BiCGStab Algorithm 3.4
  // However, the formation of [P,R] is expensive ~ 4S+1 exchanges.  Moreover, formation of G[][] requires (4S+2)(4S+1) grid operations.
  //   When the required number of iterations is small, this overhead is large and can make the s-step version slower than vanilla BiCGStab
  //   Thus, this version is a telescoping s-step method that will start out with s=1, then do s=2, then s=4


  // note: __CA_KRYLOV_S should be tiny (2-8?).  As such, 4*__CA_KRYLOV_S+1 is also tiny (9-33).  Just allocate on the stack...
  double  temp1[4*__CA_KRYLOV_S+1];                                             //
  double  temp2[4*__CA_KRYLOV_S+1];                                             //
  double  temp3[4*__CA_KRYLOV_S+1];                                             //
  double     Tp[4*__CA_KRYLOV_S+1][4*__CA_KRYLOV_S+1];                          // T'  indexed as [row][col]
  double    Tpp[4*__CA_KRYLOV_S+1][4*__CA_KRYLOV_S+1];                          // T'' indexed as [row][col]
  double     aj[4*__CA_KRYLOV_S+1];                                             //
  double     cj[4*__CA_KRYLOV_S+1];                                             //
  double     ej[4*__CA_KRYLOV_S+1];                                             //
  double   Tpaj[4*__CA_KRYLOV_S+1];                                             //
  double   Tpcj[4*__CA_KRYLOV_S+1];                                             //
  double  Tppaj[4*__CA_KRYLOV_S+1];                                             //
  double      G[4*__CA_KRYLOV_S+1][4*__CA_KRYLOV_S+1];                          // extracted from first 4*__CA_KRYLOV_S+1 columns of Gg[][].  indexed as [row][col]
  double      g[4*__CA_KRYLOV_S+1];                                             // extracted from last [4*__CA_KRYLOV_S+1] column of Gg[][].
  double    Gg[(4*__CA_KRYLOV_S+1)*(4*__CA_KRYLOV_S+2)];                        // buffer to hold the Gram-like matrix produced by matmul().  indexed as [row*(4*__CA_KRYLOV_S+2) + col]
  int      PRrt[4*__CA_KRYLOV_S+2];                                             // grid_id's of the concatenation of the 2S+1 matrix powers of P, 2S matrix powers of R, and rt

  int mMax=200;
  int m=0,n;
  int i,j,k;
  int BiCGStabFailed    = 0;
  int BiCGStabConverged = 0;
  double g_dot_Tpaj,alpha,omega_numerator,omega_denominator,omega,delta,delta_next,beta;
  double L2_norm_of_rt,L2_norm_of_residual,cj_dot_Gcj,L2_norm_of_s;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  residual(domain,level,__rt,e_id,R_id,a,b);                                    // rt[] = R_id[] - A(e_id)... note, if DPC, then rt = R-AD^-1De
  scale_grid(domain,level,__r,1.0,__rt);                                        // r[] = rt[]
  scale_grid(domain,level,__p,1.0,__rt);                                        // p[] = rt[]
  double norm_of_rt = norm(domain,level,__rt);                                  // the norm of the initial residual...
  #ifdef __VERBOSE
  if(domain->rank==0)printf("m=%8d, norm   =%0.20f\n",m,norm_of_rt);
  #endif
  if(norm_of_rt == 0.0){BiCGStabConverged=1;}                                   // entered BiCGStab with exact solution
  delta = dot(domain,level,__r,__rt);                                           // delta = dot(r,rt)
  if(delta==0.0){BiCGStabConverged=1;}                                          // entered BiCGStab with exact solution (square of L2 norm of __r)
  L2_norm_of_rt = sqrt(delta);

  int __ca_krylov_s = 1;
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  while( (m<mMax) && (!BiCGStabFailed) && (!BiCGStabConverged) ){               // while(not done){
    __zero(   aj,4*__ca_krylov_s+1);                                            //
    __zero(   cj,4*__ca_krylov_s+1);                                            //
    __zero(   ej,4*__ca_krylov_s+1);                                            //
    __zero( Tpaj,4*__ca_krylov_s+1);                                            //
    __zero( Tpcj,4*__ca_krylov_s+1);                                            //
    __zero(Tppaj,4*__ca_krylov_s+1);                                            //
    __zero(temp1,4*__ca_krylov_s+1);                                            //
    __zero(temp2,4*__ca_krylov_s+1);                                            //
    __zero(temp3,4*__ca_krylov_s+1);                                            //
 
    for(i=0;i<4*__ca_krylov_s+1;i++)for(j=0;j<4*__ca_krylov_s+1;j++) Tp[i][j]=0;// initialize Tp[][] and Tpp[][] ...
    for(i=0;i<4*__ca_krylov_s+1;i++)for(j=0;j<4*__ca_krylov_s+1;j++)Tpp[i][j]=0;//
    for(i=                0;i<2*__ca_krylov_s  ;i++){ Tp[i+1][i]=1;}            // monomial basis... Fixed (typo in SIAM paper)
    for(i=2*__ca_krylov_s+1;i<4*__ca_krylov_s  ;i++){ Tp[i+1][i]=1;}            //
    for(i=                0;i<2*__ca_krylov_s-1;i++){Tpp[i+2][i]=1;}            //
    for(i=2*__ca_krylov_s+1;i<4*__ca_krylov_s-1;i++){Tpp[i+2][i]=1;}            //

    for(i=0;i<4*__ca_krylov_s+1;i++){PRrt[                i] = __PRrt+i;}       // columns of PRrt map to the consecutive spare grid indices starting at __PRrt
                                     PRrt[4*__ca_krylov_s+1] = __rt;            // last column or PRrt (r tilde) maps to rt
    int *P = PRrt+                0;                                            // grid_id's of the 2S+1 Matrix Powers of P.  P[i] is the grid_id of A^i(p)
    int *R = PRrt+2*__ca_krylov_s+1;                                            // grid_id's of the 2S   Matrix Powers of R.  R[i] is the grid_id of A^i(r)

    // Using the monomial basis, compute 2s+1 matrix powers on p[] and 2s matrix powers on r[] one power at a time 
    // (conventional approach applicable to CHOMBO and BoxLib)
    scale_grid(domain,level,P[0],1.0,__p);                                      // P[0] = A^0p = __p
    for(n=1;n<2*__ca_krylov_s+1;n++){                                           // naive way of calculating the monomial basis.
      #ifdef DiagonallyPrecondition                                             //
      mul_grids(domain,level,__temp,1.0,__lambda,P[n-1]);                       //   temp[] = lambda[]*P[n-1]
      apply_op(domain,level,P[n],__temp,a,b);                                   //   P[n] = AD^{-1}__temp = AD^{-1}P[n-1] = ((AD^{-1})^n)p
      #else                                                                     //
      apply_op(domain,level,P[n],P[n-1],a,b);                                   //   P[n] = A(P[n-1]) = (A^n)p
      #endif                                                                    //
    }
    scale_grid(domain,level,R[0],1.0,__r);                                      // R[0] = A^0r = __r
    for(n=1;n<2*__ca_krylov_s;n++){                                             // naive way of calculating the monomial basis.
      #ifdef DiagonallyPrecondition                                             //
      mul_grids(domain,level,__temp,1.0,__lambda,R[n-1]);                       //   temp[] = lambda[]*R[n-1]
      apply_op(domain,level,R[n],__temp,a,b);                                   //   R[n] = AD^{-1}__temp = AD^{-1}R[n-1]
      #else                                                                     //
      apply_op(domain,level,R[n],R[n-1],a,b);                                   //   R[n] = A(R[n-1]) = (A^n)r
      #endif                                                                    //
    }

    // Compute Gg[][] = [P,R]^T * [P,R,rt] (Matmul with grids with ghost zones but only one MPI_AllReduce)
    domain->CAKrylov_formations_of_G++;                                         //   Record the number of times CABiCGStab formed G[][]
    matmul_grids(domain,level,Gg,PRrt,PRrt,4*__ca_krylov_s+1,4*__ca_krylov_s+2,1);
    for(i=0,k=0;i<4*__ca_krylov_s+1;i++){                                       // extract G[][] and g[] from Gg[]
    for(j=0    ;j<4*__ca_krylov_s+1;j++){G[i][j] = Gg[k++];}                    // first 4*__ca_krylov_s+1 elements in each row go to G[][].
                                         g[i]    = Gg[k++];                     // last element in row goes to g[].
    }

    for(i=0;i<4*__ca_krylov_s+1;i++)aj[i]=0.0;aj[                0]=1.0;        // initialized based on (3.26)
    for(i=0;i<4*__ca_krylov_s+1;i++)cj[i]=0.0;cj[2*__ca_krylov_s+1]=1.0;        // initialized based on (3.26)
    for(i=0;i<4*__ca_krylov_s+1;i++)ej[i]=0.0;                                  // initialized based on (3.26)

    for(n=0;n<__ca_krylov_s;n++){                                                               // for(n=0;n<__ca_krylov_s;n++){
      domain->Krylov_iterations++;                                                              // record number of inner-loop (j) iterations for comparison
      __gemv( Tpaj,   1.0, Tp,   aj,   0.0, Tpaj,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //    T'aj
      __gemv( Tpcj,   1.0, Tp,   cj,   0.0, Tpcj,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //    T'cj
      __gemv(Tppaj,   1.0,Tpp,   aj,   0.0,Tppaj,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //   T''aj
                       g_dot_Tpaj = __dot(g,Tpaj,4*__ca_krylov_s+1);                            // (g,T'aj)
      if(g_dot_Tpaj == 0.0){                                                                    // pivot breakdown ???
        #ifdef __VERBOSE                                                                        //
        if(domain->rank==0){printf("g_dot_Tpaj == 0.0\n");}                                     //
        #endif                                                                                  //
        BiCGStabFailed=1;break;                                                                 //
      }                                                                                         //
      alpha = delta / g_dot_Tpaj;                                                               // delta / (g,T'aj)
      if(isinf(alpha)){                                                                         // alpha = big/tiny(overflow) = inf -> breakdown
        #ifdef __VERBOSE                                                                        //
        if(domain->rank==0){printf("alpha == inf\n");}                                          // 
        #endif                                                                                  //
        BiCGStabFailed=1;break;                                                                 // 
      }                                                                                         // 
      #if 0                                                                                     // seems to have accuracy problems in finite precision...
      __gemv(temp1,-alpha,  G, Tpaj,   0.0,temp1,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //  temp1[] =       - alpha*GT'aj
      __gemv(temp1,   1.0,  G,   cj,   1.0,temp1,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //  temp1[] =   Gcj - alpha*GT'aj
      __gemv(temp2,-alpha,  G,Tppaj,   0.0,temp2,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //  temp2[] =       − alpha*GT′′aj
      __gemv(temp2,   1.0,  G, Tpcj,   1.0,temp2,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //  temp2[] = GT′cj − alpha*GT′′aj
      __axpy(temp3,   1.0,     Tpcj,-alpha,Tppaj,4*__ca_krylov_s+1);                            //  temp3[] =  T′cj − alpha*T′′aj
             omega_numerator = __dot(temp3,temp1,4*__ca_krylov_s+1);                            //  (temp3,temp1) = ( T'cj-alpha*T''aj ,   Gcj-alpha*GT'aj )
           omega_denominator = __dot(temp3,temp2,4*__ca_krylov_s+1);                            //  (temp3,temp2) = ( T′cj−alpha*T′′aj , GT′cj−alpha*GT′′aj )
      #else                                                                                     // better to change the order of operations Gx-Gy -> G(x-y) ...  (note, G is symmetric)
      __axpy(temp1,   1.0,     Tpcj,-alpha,Tppaj,4*__ca_krylov_s+1);                            //  temp1[] =  (T'cj - alpha*T''aj)
      __gemv(temp2,   1.0,  G,temp1,   0.0,temp2,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //  temp2[] = G(T'cj - alpha*T''aj)
      __axpy(temp3,   1.0,       cj,-alpha, Tpaj,4*__ca_krylov_s+1);                            //  temp3[] =     cj - alpha*T'aj
             omega_numerator = __dot(temp3,temp2,4*__ca_krylov_s+1);                            //  (temp3,temp2) = ( (  cj - alpha*T'aj ) , G(T'cj - alpha*T''aj) )
           omega_denominator = __dot(temp1,temp2,4*__ca_krylov_s+1);                            //  (temp1,temp2) = ( (T'cj - alpha*T''aj) , G(T'cj - alpha*T''aj) )
      #endif                                                                                    // 
      // NOTE: omega_numerator/omega_denominator can be 0/x or 0/0, but should never be x/0
      // If omega_numerator==0, and ||s||==0, then convergence, x=x+alpha*aj
      // If omega_numerator==0, and ||s||!=0, then stabilization breakdown

      // !!! PARTIAL UPDATE OF ej MUST HAPPEN BEFORE THE CHECK ON OMEGA TO ENSURE FORWARD PROGRESS !!!
      __axpy(   ej,1.0,ej,       alpha,   aj,4*__ca_krylov_s+1);                                // ej[] = ej[] + alpha*aj[]    

      // calculate the norm of Saad's vector 's' to check intra s-step convergence...
      __axpy(temp1,   1.0,       cj,-alpha, Tpaj,4*__ca_krylov_s+1);                            //  temp1[] =   cj - alpha*T'aj
      __gemv(temp2,   1.0,  G,temp1,   0.0,temp2,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //  temp2[] = G(cj - alpha*T'aj)
                                 L2_norm_of_s = __dot(temp1,temp2,4*__ca_krylov_s+1);           //  (temp1,temp2) = ( (cj - alpha*T'aj) , G(cj - alpha*T'aj) )  == square of L2 norm of s in exact arithmetic
      if(L2_norm_of_s<0)L2_norm_of_s=0;else L2_norm_of_s=sqrt(L2_norm_of_s);                    // finite precision can lead to the norm^2 being < 0 (Demmel says flush to 0.0)
      #ifdef __VERBOSE                                                                          //
      if(domain->rank==0){printf("m=%8d, norm(s)=%0.20f\n",m+n,L2_norm_of_s);}                  //
      #endif                                                                                    //
      if(L2_norm_of_s < desired_reduction_in_norm*L2_norm_of_rt){BiCGStabConverged=1;break;}    // terminate the inner n-loop


      if(omega_denominator == 0.0){                                                             // ??? breakdown
        #ifdef __VERBOSE                                                                        //
        if(domain->rank==0){if(omega_denominator == 0.0)printf("omega_denominator == 0.0\n");}  //
        #endif                                                                                  //
        BiCGStabFailed=1;break;                                                                 //
      }                                                                                         //
      omega = omega_numerator / omega_denominator;                                              // 
      if(isinf(omega)){                                                                         // omega = big/tiny(oveflow) = inf
        #ifdef __VERBOSE                                                                        //
        if(domain->rank==0){if(isinf(omega))printf("omega == inf\n");}                          // 
        #endif                                                                                  //
        BiCGStabFailed=1;break;                                                                 //
      }                                                                                         //
      // !!! COMPLETE THE UPDATE OF ej & cj now that omega is known to be ok                    //
      __axpy(   ej,1.0,ej,       omega,   cj,4*__ca_krylov_s+1);                                // ej[] = ej[] + alpha*aj[] + omega*cj[]
      __axpy(   ej,1.0,ej,-omega*alpha, Tpaj,4*__ca_krylov_s+1);                                // ej[] = ej[] + alpha*aj[] + omega*cj[] - omega*alpha*T'aj[]
      __axpy(   cj,1.0,cj,      -omega, Tpcj,4*__ca_krylov_s+1);                                // cj[] = cj[] - omega*T'cj[]
      __axpy(   cj,1.0,cj,      -alpha, Tpaj,4*__ca_krylov_s+1);                                // cj[] = cj[] - omega*T'cj[] - alpha*T'aj[]
      __axpy(   cj,1.0,cj, omega*alpha,Tppaj,4*__ca_krylov_s+1);                                // cj[] = cj[] - omega*T'cj[] - alpha*T'aj[] + omega*alpha*T''aj[]


      // calculate the norm of the incremental residual (Saad's vector 'r') to check intra s-step convergence...
      __gemv(temp1,   1.0,  G,   cj,   0.0,temp1,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          // temp1[] = Gcj
                                       cj_dot_Gcj = __dot(cj,temp1,4*__ca_krylov_s+1);          // sqrt( (cj,Gcj) ) == L2 norm of the intermediate residual in exact arithmetic
      L2_norm_of_residual = 0.0;if(cj_dot_Gcj>0)L2_norm_of_residual=sqrt(cj_dot_Gcj);           // finite precision can lead to the norm^2 being < 0 (Demmel says flush to 0.0)
      #ifdef __VERBOSE 
      if(domain->rank==0){printf("m=%8d, norm(r)=%0.20f (cj_dot_Gcj=%0.20e)\n",m+n,L2_norm_of_residual,cj_dot_Gcj);}
      #endif
      if(L2_norm_of_residual < desired_reduction_in_norm*L2_norm_of_rt){BiCGStabConverged=1;break;} // terminate the inner n-loop


      delta_next = __dot( g,cj,4*__ca_krylov_s+1);                                              // (g,cj)
      #ifdef __VERBOSE                                                                          //
      if(domain->rank==0){                                                                      //
        if(isinf(delta_next)     ){printf("delta == inf\n");}                                   // delta = big/tiny(overflow) = inf
        if(delta_next      == 0.0){printf("delta == 0.0\n");}                                   // Lanczos breakdown
        if(omega_numerator == 0.0){printf("omega_numerator == 0.0\n");}                         // stabilization breakdown
        if(omega           == 0.0){printf("omega == 0.0\n");}                                   // stabilization breakdown 
      }                                                                                         //
      #endif                                                                                    //
      if(isinf(delta_next)){BiCGStabFailed   =1;break;}                                         // delta = inf?
      if(delta_next  ==0.0){BiCGStabFailed   =1;break;}                                         // Lanczos breakdown...
      if(omega       ==0.0){BiCGStabFailed   =1;break;}                                         // stabilization breakdown 
      beta = (delta_next/delta)*(alpha/omega);                                                  // (delta_next/delta)*(alpha/omega)
      #ifdef __VERBOSE                                                                          //
      if(domain->rank==0){                                                                      //
        if(isinf(beta)           ){printf("beta == inf\n");}                                    // beta = inf?
        if(beta            == 0.0){printf("beta == 0.0\n");}                                    // beta = 0?  can't make further progress(?)
      }                                                                                         //
      #endif                                                                                    //
      if(isinf(beta)      ){BiCGStabFailed   =1;break;}                                         // beta = inf?
      if(beta       == 0.0){BiCGStabFailed   =1;break;}                                         // beta = 0?  can't make further progress(?)
      __axpy(   aj,1.0,cj,        beta,   aj,4*__ca_krylov_s+1);                                // aj[] = cj[] + beta*aj[]
      __axpy(   aj,1.0,aj, -omega*beta, Tpaj,4*__ca_krylov_s+1);                                // aj[] = cj[] + beta*aj[] - omega*beta*T'aj
      delta = delta_next;                                                                       // delta = delta_next

    }                                                                                           // inner n (j) loop

    // update iterates...
    for(i=0;i<4*__ca_krylov_s+1;i++){add_grids(domain,level,e_id,1.0,e_id,ej[i],PRrt[i]);}      // e_id[] = [P,R]ej + e_id[]
    if(!BiCGStabFailed && !BiCGStabConverged){                                                  // if we're done, then there is no point in updating these
                                     add_grids(domain,level, __p,0.0, __p,aj[0],PRrt[0]);       //    p[] = [P,R]aj
    for(i=1;i<4*__ca_krylov_s+1;i++){add_grids(domain,level, __p,1.0, __p,aj[i],PRrt[i]);}      //          ...
                                     add_grids(domain,level, __r,0.0, __r,cj[0],PRrt[0]);       //    r[] = [P,R]cj
    for(i=1;i<4*__ca_krylov_s+1;i++){add_grids(domain,level, __r,1.0, __r,cj[i],PRrt[i]);}      //          ...
    }                                                                                           //
    m+=__ca_krylov_s;                                                                           //   m+=ca_krylov_s;
    __ca_krylov_s*=2;if(__ca_krylov_s>__CA_KRYLOV_S)__ca_krylov_s=__CA_KRYLOV_S;
  }                                                                                       // } // outer m loop
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  #ifdef DiagonallyPrecondition
  mul_grids(domain,level,e_id,1.0,__lambda,e_id);                                         //   e_id[] = lambda[]*e_id[] // i.e. e = D^{-1}e'
  #endif

}


//------------------------------------------------------------------------------------------------------------------------------
void CABiCGStab(domain_type * domain, int level, int e_id, int R_id, double a, double b, double desired_reduction_in_norm){
  // based on Erin Carson/Jim Demmel/Nick Knight's s-Step BiCGStab Algorithm 3.4

  // note: __CA_KRYLOV_S should be tiny (2-8?).  As such, 4*__CA_KRYLOV_S+1 is also tiny (9-33).  Just allocate on the stack...
  double  temp1[4*__CA_KRYLOV_S+1];                                             //
  double  temp2[4*__CA_KRYLOV_S+1];                                             //
  double  temp3[4*__CA_KRYLOV_S+1];                                             //
  double     Tp[4*__CA_KRYLOV_S+1][4*__CA_KRYLOV_S+1];                          // T'  indexed as [row][col]
  double    Tpp[4*__CA_KRYLOV_S+1][4*__CA_KRYLOV_S+1];                          // T'' indexed as [row][col]
  double     aj[4*__CA_KRYLOV_S+1];                                             //
  double     cj[4*__CA_KRYLOV_S+1];                                             //
  double     ej[4*__CA_KRYLOV_S+1];                                             //
  double   Tpaj[4*__CA_KRYLOV_S+1];                                             //
  double   Tpcj[4*__CA_KRYLOV_S+1];                                             //
  double  Tppaj[4*__CA_KRYLOV_S+1];                                             //
  double      G[4*__CA_KRYLOV_S+1][4*__CA_KRYLOV_S+1];                          // extracted from first 4*__CA_KRYLOV_S+1 columns of Gg[][].  indexed as [row][col]
  double      g[4*__CA_KRYLOV_S+1];                                             // extracted from last [4*__CA_KRYLOV_S+1] column of Gg[][].
  double    Gg[(4*__CA_KRYLOV_S+1)*(4*__CA_KRYLOV_S+2)];                        // buffer to hold the Gram-like matrix produced by matmul().  indexed as [row*(4*__CA_KRYLOV_S+2) + col]
  int      PRrt[4*__CA_KRYLOV_S+2];                                             // grid_id's of the concatenation of the 2S+1 matrix powers of P, 2S matrix powers of R, and rt
  int *P = PRrt+                0;                                              // grid_id's of the 2S+1 Matrix Powers of P.  P[i] is the grid_id of A^i(p)
  int *R = PRrt+2*__CA_KRYLOV_S+1;                                              // grid_id's of the 2S   Matrix Powers of R.  R[i] is the grid_id of A^i(r)

  int mMax=200;
  int m=0,n;
  int i,j,k;
  int BiCGStabFailed    = 0;
  int BiCGStabConverged = 0;
  double g_dot_Tpaj,alpha,omega_numerator,omega_denominator,omega,delta,delta_next,beta;
  double L2_norm_of_rt,L2_norm_of_residual,cj_dot_Gcj,L2_norm_of_s;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  residual(domain,level,__rt,e_id,R_id,a,b);                                    // rt[] = R_id[] - A(e_id)... note, if DPC, then rt = R-AD^-1De
  scale_grid(domain,level,__r,1.0,__rt);                                        // r[] = rt[]
  scale_grid(domain,level,__p,1.0,__rt);                                        // p[] = rt[]
  double norm_of_rt = norm(domain,level,__rt);                                  // the norm of the initial residual...
  #ifdef __VERBOSE
  if(domain->rank==0)printf("m=%8d, norm   =%0.20f\n",m,norm_of_rt);
  #endif
  if(norm_of_rt == 0.0){BiCGStabConverged=1;}                                   // entered BiCGStab with exact solution
  delta = dot(domain,level,__r,__rt);                                           // delta = dot(r,rt)
  if(delta==0.0){BiCGStabConverged=1;}                                          // entered BiCGStab with exact solution (square of L2 norm of __r)
  L2_norm_of_rt = sqrt(delta);

  int __ca_krylov_s = __CA_KRYLOV_S;                                            // by making this a variable, I prevent the compiler from optimizing more than the telescoping version, thus preserving a bit-identcal result

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  for(i=0;i<4*__ca_krylov_s+1;i++)for(j=0;j<4*__ca_krylov_s+1;j++) Tp[i][j]=0;  // initialize Tp[][] and Tpp[][] ...
  for(i=0;i<4*__ca_krylov_s+1;i++)for(j=0;j<4*__ca_krylov_s+1;j++)Tpp[i][j]=0;  //
  for(i=                0;i<2*__ca_krylov_s  ;i++){ Tp[i+1][i]=1;}              // monomial basis... Fixed (typo in SIAM paper)
  for(i=2*__ca_krylov_s+1;i<4*__ca_krylov_s  ;i++){ Tp[i+1][i]=1;}              //
  for(i=                0;i<2*__ca_krylov_s-1;i++){Tpp[i+2][i]=1;}              //
  for(i=2*__ca_krylov_s+1;i<4*__ca_krylov_s-1;i++){Tpp[i+2][i]=1;}              //

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  for(i=0;i<4*__ca_krylov_s+1;i++){PRrt[                i] = __PRrt+i;}         // columns of PRrt map to the consecutive spare grid indices starting at __PRrt
                                   PRrt[4*__ca_krylov_s+1] = __rt;              // last column or PRrt (r tilde) maps to rt

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  while( (m<mMax) && (!BiCGStabFailed) && (!BiCGStabConverged) ){               // while(not done){
    __zero(   aj,4*__ca_krylov_s+1);                                            //
    __zero(   cj,4*__ca_krylov_s+1);                                            //
    __zero(   ej,4*__ca_krylov_s+1);                                            //
    __zero( Tpaj,4*__ca_krylov_s+1);                                            //
    __zero( Tpcj,4*__ca_krylov_s+1);                                            //
    __zero(Tppaj,4*__ca_krylov_s+1);                                            //
    __zero(temp1,4*__ca_krylov_s+1);                                            //
    __zero(temp2,4*__ca_krylov_s+1);                                            //
    __zero(temp3,4*__ca_krylov_s+1);                                            //

    // Using the monomial basis, compute 2s+1 matrix powers on p[] and 2s matrix powers on r[] one power at a time 
    // (conventional approach applicable to CHOMBO and BoxLib)
    scale_grid(domain,level,P[0],1.0,__p);                                      // P[0] = A^0p = __p
    for(n=1;n<2*__ca_krylov_s+1;n++){                                           // naive way of calculating the monomial basis.
      #ifdef DiagonallyPrecondition                                             //
      mul_grids(domain,level,__temp,1.0,__lambda,P[n-1]);                       //   temp[] = lambda[]*P[n-1]
      apply_op(domain,level,P[n],__temp,a,b);                                   //   P[n] = AD^{-1}__temp = AD^{-1}P[n-1] = ((AD^{-1})^n)p
      #else                                                                     //
      apply_op(domain,level,P[n],P[n-1],a,b);                                   //   P[n] = A(P[n-1]) = (A^n)p
      #endif                                                                    //
    }
    scale_grid(domain,level,R[0],1.0,__r);                                      // R[0] = A^0r = __r
    for(n=1;n<2*__ca_krylov_s;n++){                                             // naive way of calculating the monomial basis.
      #ifdef DiagonallyPrecondition                                             //
      mul_grids(domain,level,__temp,1.0,__lambda,R[n-1]);                       //   temp[] = lambda[]*R[n-1]
      apply_op(domain,level,R[n],__temp,a,b);                                   //   R[n] = AD^{-1}__temp = AD^{-1}R[n-1]
      #else                                                                     //
      apply_op(domain,level,R[n],R[n-1],a,b);                                   //   R[n] = A(R[n-1]) = (A^n)r
      #endif                                                                    //
    }

    // Compute Gg[][] = [P,R]^T * [P,R,rt] (Matmul with grids with ghost zones but only one MPI_AllReduce)
    domain->CAKrylov_formations_of_G++;                                         //   Record the number of times CABiCGStab formed G[][]
    matmul_grids(domain,level,Gg,PRrt,PRrt,4*__ca_krylov_s+1,4*__ca_krylov_s+2,1);
    for(i=0,k=0;i<4*__ca_krylov_s+1;i++){                                       // extract G[][] and g[] from Gg[]
    for(j=0    ;j<4*__ca_krylov_s+1;j++){G[i][j] = Gg[k++];}                    // first 4*__ca_krylov_s+1 elements in each row go to G[][].
                                         g[i]    = Gg[k++];                     // last element in row goes to g[].
    }

    for(i=0;i<4*__ca_krylov_s+1;i++)aj[i]=0.0;aj[                0]=1.0;        // initialized based on (3.26)
    for(i=0;i<4*__ca_krylov_s+1;i++)cj[i]=0.0;cj[2*__ca_krylov_s+1]=1.0;        // initialized based on (3.26)
    for(i=0;i<4*__ca_krylov_s+1;i++)ej[i]=0.0;                                  // initialized based on (3.26)

    for(n=0;n<__ca_krylov_s;n++){                                                               // for(n=0;n<__ca_krylov_s;n++){
      domain->Krylov_iterations++;                                                              // record number of inner-loop (j) iterations for comparison
      __gemv( Tpaj,   1.0, Tp,   aj,   0.0, Tpaj,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //    T'aj
      __gemv( Tpcj,   1.0, Tp,   cj,   0.0, Tpcj,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //    T'cj
      __gemv(Tppaj,   1.0,Tpp,   aj,   0.0,Tppaj,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //   T''aj
                       g_dot_Tpaj = __dot(g,Tpaj,4*__ca_krylov_s+1);                            // (g,T'aj)
      if(g_dot_Tpaj == 0.0){                                                                    // pivot breakdown ???
        #ifdef __VERBOSE                                                                        //
        if(domain->rank==0){printf("g_dot_Tpaj == 0.0\n");}                                     //
        #endif                                                                                  //
        BiCGStabFailed=1;break;                                                                 //
      }                                                                                         //
      alpha = delta / g_dot_Tpaj;                                                               // delta / (g,T'aj)
      if(isinf(alpha)){                                                                         // alpha = big/tiny(overflow) = inf -> breakdown
        #ifdef __VERBOSE                                                                        //
        if(domain->rank==0){printf("alpha == inf\n");}                                          // 
        #endif                                                                                  //
        BiCGStabFailed=1;break;                                                                 // 
      }                                                                                         // 
      #if 0                                                                                     // seems to have accuracy problems in finite precision...
      __gemv(temp1,-alpha,  G, Tpaj,   0.0,temp1,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //  temp1[] =       - alpha*GT'aj
      __gemv(temp1,   1.0,  G,   cj,   1.0,temp1,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //  temp1[] =   Gcj - alpha*GT'aj
      __gemv(temp2,-alpha,  G,Tppaj,   0.0,temp2,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //  temp2[] =       − alpha*GT′′aj
      __gemv(temp2,   1.0,  G, Tpcj,   1.0,temp2,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //  temp2[] = GT′cj − alpha*GT′′aj
      __axpy(temp3,   1.0,     Tpcj,-alpha,Tppaj,4*__ca_krylov_s+1);                            //  temp3[] =  T′cj − alpha*T′′aj
             omega_numerator = __dot(temp3,temp1,4*__ca_krylov_s+1);                            //  (temp3,temp1) = ( T'cj-alpha*T''aj ,   Gcj-alpha*GT'aj )
           omega_denominator = __dot(temp3,temp2,4*__ca_krylov_s+1);                            //  (temp3,temp2) = ( T′cj−alpha*T′′aj , GT′cj−alpha*GT′′aj )
      #else                                                                                     // better to change the order of operations Gx-Gy -> G(x-y) ...  (note, G is symmetric)
      __axpy(temp1,   1.0,     Tpcj,-alpha,Tppaj,4*__ca_krylov_s+1);                            //  temp1[] =  (T'cj - alpha*T''aj)
      __gemv(temp2,   1.0,  G,temp1,   0.0,temp2,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //  temp2[] = G(T'cj - alpha*T''aj)
      __axpy(temp3,   1.0,       cj,-alpha, Tpaj,4*__ca_krylov_s+1);                            //  temp3[] =     cj - alpha*T'aj
             omega_numerator = __dot(temp3,temp2,4*__ca_krylov_s+1);                            //  (temp3,temp2) = ( (  cj - alpha*T'aj ) , G(T'cj - alpha*T''aj) )
           omega_denominator = __dot(temp1,temp2,4*__ca_krylov_s+1);                            //  (temp1,temp2) = ( (T'cj - alpha*T''aj) , G(T'cj - alpha*T''aj) )
      #endif                                                                                    // 
      // NOTE: omega_numerator/omega_denominator can be 0/x or 0/0, but should never be x/0
      // If omega_numerator==0, and ||s||==0, then convergence, x=x+alpha*aj
      // If omega_numerator==0, and ||s||!=0, then stabilization breakdown

      // !!! PARTIAL UPDATE OF ej MUST HAPPEN BEFORE THE CHECK ON OMEGA TO ENSURE FORWARD PROGRESS !!!
      __axpy(   ej,1.0,ej,       alpha,   aj,4*__ca_krylov_s+1);                                // ej[] = ej[] + alpha*aj[]    

      // calculate the norm of Saad's vector 's' to check intra s-step convergence...
      __axpy(temp1,   1.0,       cj,-alpha, Tpaj,4*__ca_krylov_s+1);                            //  temp1[] =   cj - alpha*T'aj
      __gemv(temp2,   1.0,  G,temp1,   0.0,temp2,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          //  temp2[] = G(cj - alpha*T'aj)
                                 L2_norm_of_s = __dot(temp1,temp2,4*__ca_krylov_s+1);           //  (temp1,temp2) = ( (cj - alpha*T'aj) , G(cj - alpha*T'aj) )  == square of L2 norm of s in exact arithmetic
      if(L2_norm_of_s<0)L2_norm_of_s=0;else L2_norm_of_s=sqrt(L2_norm_of_s);                    // finite precision can lead to the norm^2 being < 0 (Demmel says flush to 0.0)
      #ifdef __VERBOSE                                                                          //
      if(domain->rank==0){printf("m=%8d, norm(s)=%0.20f\n",m+n,L2_norm_of_s);}                  //
      #endif                                                                                    //
      if(L2_norm_of_s < desired_reduction_in_norm*L2_norm_of_rt){BiCGStabConverged=1;break;}    // terminate the inner n-loop


      if(omega_denominator == 0.0){                                                             // ??? breakdown
        #ifdef __VERBOSE                                                                        //
        if(domain->rank==0){if(omega_denominator == 0.0)printf("omega_denominator == 0.0\n");}  //
        #endif                                                                                  //
        BiCGStabFailed=1;break;                                                                 //
      }                                                                                         //
      omega = omega_numerator / omega_denominator;                                              // 
      if(isinf(omega)){                                                                         // omega = big/tiny(oveflow) = inf
        #ifdef __VERBOSE                                                                        //
        if(domain->rank==0){if(isinf(omega))printf("omega == inf\n");}                          // 
        #endif                                                                                  //
        BiCGStabFailed=1;break;                                                                 //
      }                                                                                         //
      // !!! COMPLETE THE UPDATE OF ej & cj now that omega is known to be ok                    //
      __axpy(   ej,1.0,ej,       omega,   cj,4*__ca_krylov_s+1);                                // ej[] = ej[] + alpha*aj[] + omega*cj[]
      __axpy(   ej,1.0,ej,-omega*alpha, Tpaj,4*__ca_krylov_s+1);                                // ej[] = ej[] + alpha*aj[] + omega*cj[] - omega*alpha*T'aj[]
      __axpy(   cj,1.0,cj,      -omega, Tpcj,4*__ca_krylov_s+1);                                // cj[] = cj[] - omega*T'cj[]
      __axpy(   cj,1.0,cj,      -alpha, Tpaj,4*__ca_krylov_s+1);                                // cj[] = cj[] - omega*T'cj[] - alpha*T'aj[]
      __axpy(   cj,1.0,cj, omega*alpha,Tppaj,4*__ca_krylov_s+1);                                // cj[] = cj[] - omega*T'cj[] - alpha*T'aj[] + omega*alpha*T''aj[]


      // calculate the norm of the incremental residual (Saad's vector 'r') to check intra s-step convergence...
      __gemv(temp1,   1.0,  G,   cj,   0.0,temp1,4*__ca_krylov_s+1,4*__ca_krylov_s+1);          // temp1[] = Gcj
                                       cj_dot_Gcj = __dot(cj,temp1,4*__ca_krylov_s+1);          // sqrt( (cj,Gcj) ) == L2 norm of the intermediate residual in exact arithmetic
      L2_norm_of_residual = 0.0;if(cj_dot_Gcj>0)L2_norm_of_residual=sqrt(cj_dot_Gcj);           // finite precision can lead to the norm^2 being < 0 (Demmel says flush to 0.0)
      #ifdef __VERBOSE 
      if(domain->rank==0){printf("m=%8d, norm(r)=%0.20f (cj_dot_Gcj=%0.20e)\n",m+n,L2_norm_of_residual,cj_dot_Gcj);}
      #endif
      if(L2_norm_of_residual < desired_reduction_in_norm*L2_norm_of_rt){BiCGStabConverged=1;break;} // terminate the inner n-loop


      delta_next = __dot( g,cj,4*__ca_krylov_s+1);                                              // (g,cj)
      #ifdef __VERBOSE                                                                          //
      if(domain->rank==0){                                                                      //
        if(isinf(delta_next)     ){printf("delta == inf\n");}                                   // delta = big/tiny(overflow) = inf
        if(delta_next      == 0.0){printf("delta == 0.0\n");}                                   // Lanczos breakdown
        if(omega_numerator == 0.0){printf("omega_numerator == 0.0\n");}                         // stabilization breakdown
        if(omega           == 0.0){printf("omega == 0.0\n");}                                   // stabilization breakdown 
      }                                                                                         //
      #endif                                                                                    //
      if(isinf(delta_next)){BiCGStabFailed   =1;break;}                                         // delta = inf?
      if(delta_next  ==0.0){BiCGStabFailed   =1;break;}                                         // Lanczos breakdown...
      if(omega       ==0.0){BiCGStabFailed   =1;break;}                                         // stabilization breakdown 
      beta = (delta_next/delta)*(alpha/omega);                                                  // (delta_next/delta)*(alpha/omega)
      #ifdef __VERBOSE                                                                          //
      if(domain->rank==0){                                                                      //
        if(isinf(beta)           ){printf("beta == inf\n");}                                    // beta = inf?
        if(beta            == 0.0){printf("beta == 0.0\n");}                                    // beta = 0?  can't make further progress(?)
      }                                                                                         //
      #endif                                                                                    //
      if(isinf(beta)      ){BiCGStabFailed   =1;break;}                                         // beta = inf?
      if(beta       == 0.0){BiCGStabFailed   =1;break;}                                         // beta = 0?  can't make further progress(?)
      __axpy(   aj,1.0,cj,        beta,   aj,4*__ca_krylov_s+1);                                // aj[] = cj[] + beta*aj[]
      __axpy(   aj,1.0,aj, -omega*beta, Tpaj,4*__ca_krylov_s+1);                                // aj[] = cj[] + beta*aj[] - omega*beta*T'aj
      delta = delta_next;                                                                       // delta = delta_next

    }                                                                                           // inner n (j) loop

    // update iterates...
    for(i=0;i<4*__ca_krylov_s+1;i++){add_grids(domain,level,e_id,1.0,e_id,ej[i],PRrt[i]);}      // e_id[] = [P,R]ej + e_id[]
    if(!BiCGStabFailed && !BiCGStabConverged){                                                  // if we're done, then there is no point in updating these
                                     add_grids(domain,level, __p,0.0, __p,aj[0],PRrt[0]);       //    p[] = [P,R]aj
    for(i=1;i<4*__ca_krylov_s+1;i++){add_grids(domain,level, __p,1.0, __p,aj[i],PRrt[i]);}      //          ...
                                     add_grids(domain,level, __r,0.0, __r,cj[0],PRrt[0]);       //    r[] = [P,R]cj
    for(i=1;i<4*__ca_krylov_s+1;i++){add_grids(domain,level, __r,1.0, __r,cj[i],PRrt[i]);}      //          ...
    }                                                                                           //
    m+=__ca_krylov_s;                                                                           //   m+=__ca_krylov_s;
  }                                                                                             // } // outer m loop
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  #ifdef DiagonallyPrecondition
  mul_grids(domain,level,e_id,1.0,__lambda,e_id);                                               //   e_id[] = lambda[]*e_id[] // i.e. e = D^{-1}e'
  #endif
}


//------------------------------------------------------------------------------------------------------------------------------
void BiCGStab(domain_type * domain, int level, int x_id, int R_id, double a, double b, double desired_reduction_in_norm){
  // Algorithm 7.7 in Iterative Methods for Sparse Linear Systems(Yousef Saad)
  // uses "right" preconditioning...  AD^{-1}(Dx) = b ... AD^{-1}y = b ... solve for y, then solve for x = D^{-1}y
  int jMax=200;
  int j=0;
  int BiCGStabFailed    = 0;
  int BiCGStabConverged = 0;
  residual(domain,level,__r0,x_id,R_id,a,b);                                    // r0[] = R_id[] - A(x_id)
  scale_grid(domain,level,__r,1.0,__r0);                                        // r[] = r0[]
  scale_grid(domain,level,__p,1.0,__r0);                                        // p[] = r0[]
  double r_dot_r0 = dot(domain,level,__r,__r0);                                 // r_dot_r0 = dot(r,r0)
  double norm_of_r0 = norm(domain,level,__r);                                   // the norm of the initial residual...
  if(r_dot_r0   == 0.0){BiCGStabConverged=1;}                                   // entered BiCGStab with exact solution
  if(norm_of_r0 == 0.0){BiCGStabConverged=1;}                                   // entered BiCGStab with exact solution
  while( (j<jMax) && (!BiCGStabFailed) && (!BiCGStabConverged) ){               // while(not done){
    j++;domain->Krylov_iterations++;                                            //
    #ifdef DiagonallyPrecondition                                               //
    mul_grids(domain,level,__temp,1.0,__lambda,__p);                            //   temp[] = lambda[]*p[]
    apply_op(domain,level,__Ap,__temp,a,b);                                     //   Ap = AD^{-1}(p)
    #else                                                                       //
    apply_op(domain,level,__Ap,__p,a,b);                                        //   Ap = A(p)
    #endif                                                                      //
    double Ap_dot_r0 = dot(domain,level,__Ap,__r0);                             //   Ap_dot_r0 = dot(Ap,r0)
    if(Ap_dot_r0 == 0.0){BiCGStabFailed=1;break;}                               //   pivot breakdown ???
    double alpha = r_dot_r0 / Ap_dot_r0;                                        //   alpha = r_dot_r0 / Ap_dot_r0
    if(isinf(alpha)){BiCGStabFailed=1;break;}                                   //   pivot breakdown ???
    add_grids(domain,level,x_id,1.0,x_id, alpha,__p );                          //   x_id[] = x_id[] + alpha*p[]
    add_grids(domain,level,__s ,1.0,__r ,-alpha,__Ap);                          //   s[]    = r[]    - alpha*Ap[]   (intermediate residual?)
    double norm_of_s = norm(domain,level,__s);                                  //   FIX - redundant??  norm of intermediate residual
    if(norm_of_s == 0.0){BiCGStabConverged=1;break;}                            //   FIX - redundant??  if As_dot_As==0, then As must be 0 which implies s==0
    if(norm_of_s < desired_reduction_in_norm*norm_of_r0){BiCGStabConverged=1;break;}
    #ifdef DiagonallyPrecondition                                               //
    mul_grids(domain,level,__temp,1.0,__lambda,__s);                            //   temp[] = lambda[]*s[]
    apply_op(domain,level,__As,__temp,a,b);                                     //   As = AD^{-1}(s)
    #else                                                                       //
    apply_op(domain,level,__As,__s,a,b);                                        //   As = A(s)
    #endif                                                                      //
    double As_dot_As = dot(domain,level,__As,__As);                             //   As_dot_As = dot(As,As)
    double As_dot_s  = dot(domain,level,__As, __s);                             //   As_dot_s  = dot(As, s)
    if(As_dot_As == 0.0){BiCGStabConverged=1;break;}                            //   converged ?
    double omega = As_dot_s / As_dot_As;                                        //   omega = As_dot_s / As_dot_As
    if(omega == 0.0){BiCGStabFailed=1;break;}                                   //   stabilization breakdown ???
    if(isinf(omega)){BiCGStabFailed=1;break;}                                   //   stabilization breakdown ???
    add_grids(domain,level,  x_id,  1.0,x_id, omega,__s   );                    //   x_id[] = x_id[] + omega*s[]
    add_grids(domain,level,__r   ,  1.0,__s ,-omega,__As  );                    //   r[]    = s[]    - omega*As[]  (recursively computed / updated residual)
    double norm_of_r = norm(domain,level,__r);                                  //   norm of recursively computed residual (good enough??)
    if(norm_of_r == 0.0){BiCGStabConverged=1;break;}                            //
    if(norm_of_r < desired_reduction_in_norm*norm_of_r0){BiCGStabConverged=1;break;}
    #ifdef __DEBUG                                                              //
    residual(domain,level,__temp,x_id,R_id,a,b);                                //
    double norm_of_residual = norm(domain,level,__temp);                        //
    if(domain->rank==0)printf("j=%8d, norm=%12.6e, norm_inital=%12.6e, reduction=%e\n",j,norm_of_residual,norm_of_r0,norm_of_residual/norm_of_r0);   //
    #endif                                                                      //
    double r_dot_r0_new = dot(domain,level,__r,__r0);                           //   r_dot_r0_new = dot(r,r0)
    if(r_dot_r0_new == 0.0){BiCGStabFailed=1;break;}                            //   Lanczos breakdown ???
    double beta = (r_dot_r0_new/r_dot_r0) * (alpha/omega);                      //   beta = (r_dot_r0_new/r_dot_r0) * (alpha/omega)
    if(isinf(beta)){BiCGStabFailed=1;break;}                                    //   ???
    add_grids(domain,level,__temp,1.0,__p,-omega,__Ap  );                       //   __temp =         (p[]-omega*Ap[])
    add_grids(domain,level,__p   ,1.0,__r,  beta,__temp);                       //   p[] = r[] + beta*(p[]-omega*Ap[])
    r_dot_r0 = r_dot_r0_new;                                                    //   r_dot_r0 = r_dot_r0_new   (save old r_dot_r0)
  }                                                                             // }
    #ifdef DiagonallyPrecondition                                               //
    mul_grids(domain,level,x_id,1.0,__lambda,x_id);                             //   x_id[] = lambda[]*x_id[] // i.e. x = D^{-1}x'
    #endif                                                                      //
}

//------------------------------------------------------------------------------------------------------------------------------
void CACG(domain_type * domain, int level, int e_id, int R_id, double a, double b, double desired_reduction_in_norm){
  // based on Lauren Goodfriend, Yinghui Huang, and David Thorman's derivation in their Spring 2013 CS267 Report

  double  temp1[2*__CA_KRYLOV_S+1];                                            //
  double  temp2[2*__CA_KRYLOV_S+1];                                            //
  double  temp3[2*__CA_KRYLOV_S+1];                                            //
  double     aj[2*__CA_KRYLOV_S+1];                                            //
  double     cj[2*__CA_KRYLOV_S+1];                                            //
  double     ej[2*__CA_KRYLOV_S+1];                                            //
  double   Tpaj[2*__CA_KRYLOV_S+1];                                            //
  double     Tp[2*__CA_KRYLOV_S+1][2*__CA_KRYLOV_S+1];                         // T'  indexed as [row][col]
  double      G[2*__CA_KRYLOV_S+1][2*__CA_KRYLOV_S+1];                         // extracted from first 2*__CA_KRYLOV_S+1 columns of Gg[][].  indexed as [row][col]
  double   Gbuf[(2*__CA_KRYLOV_S+1)*(2*__CA_KRYLOV_S+1)];                      // buffer to hold the Gram-like matrix produced by matmul().  indexed as [row*(2*__CA_KRYLOV_S+1) + col]
  int      PR[2*__CA_KRYLOV_S+1];                                              // grid_id's of the concatenation of the S+1 matrix powers of P, and the S matrix powers of R
  int *P = PR+               0;                                                // grid_id's of the S+1 Matrix Powers of P.  P[i] is the grid_id of A^i(p)
  int *R = PR+__CA_KRYLOV_S+1;                                                 // grid_id's of the S   Matrix Powers of R.  R[i] is the grid_id of A^i(r)

  int mMax=200;
  int m=0,n;
  int i,j,k;
  int CGFailed    = 0;
  int CGConverged = 0;

  double aj_dot_GTpaj,cj_dot_Gcj,alpha,cj_dot_Gcj_new,beta,L2_norm_of_r0,L2_norm_of_residual,delta;

  residual(domain,level,__r0,e_id,R_id,a,b);                                                     // r0[] = R_id[] - A(e_id)
  scale_grid(domain,level,__r,1.0,__r0);                                                         // r[] = r0[]
  scale_grid(domain,level,__p,1.0,__r0);                                                         // p[] = r0[]
  double norm_of_r0 = norm(domain,level,__r0);                                                   // the norm of the initial residual...
  if(norm_of_r0 == 0.0){CGConverged=1;}                                                          // entered CG with exact solution

  delta = dot(domain,level,__r,__r0);                                                            // delta = dot(r,r0)
  if(delta==0.0){CGConverged=1;}                                                                 // entered CG with exact solution (square of L2 norm of __r)
  L2_norm_of_r0 = sqrt(delta);                                                                   // 



  // initialize Tp[][] ...
  for(i=0;i<2*__CA_KRYLOV_S+1;i++)for(j=0;j<2*__CA_KRYLOV_S+1;j++) Tp[i][j]=0;                  // zero Tp
  for(i=              0;i<  __CA_KRYLOV_S  ;i++){ Tp[i+1][i]=1;}                                // monomial basis
  for(i=__CA_KRYLOV_S+1;i<2*__CA_KRYLOV_S  ;i++){ Tp[i+1][i]=1;}                                //

  for(i=0;i<2*__CA_KRYLOV_S+1;i++){PR[i] = __PRrt+i;}                                           // columns of PR map to the consecutive spare grids allocated for the bottom solver starting at __PRrt


  while( (m<mMax) && (!CGFailed) && (!CGConverged) ){                                           // while(not done){
    __zero(   aj,2*__CA_KRYLOV_S+1);
    __zero(   cj,2*__CA_KRYLOV_S+1);
    __zero(   ej,2*__CA_KRYLOV_S+1);
    __zero( Tpaj,2*__CA_KRYLOV_S+1);
    __zero(temp1,2*__CA_KRYLOV_S+1);
    __zero(temp2,2*__CA_KRYLOV_S+1);
    __zero(temp3,2*__CA_KRYLOV_S+1);

    // Using the monomial basis, compute s+1 matrix powers on p[] and s matrix powers on r[] one power at a time
    //  (conventional approach applicable to CHOMBO and BoxLib)
    scale_grid(domain,level,P[0],1.0,__p);                                                      // P[0] = A^0p = __p
    for(n=1;n<__CA_KRYLOV_S+1;n++){                                                             // naive way of calculating the monomial basis.
      apply_op(domain,level,P[n],P[n-1],a,b);                                                   // P[n] = A(P[n-1]) = A^(n)p
    }
    scale_grid(domain,level,R[0],1.0,__r);                                                      // R[0] = A^0r = __r
    for(n=1;n<__CA_KRYLOV_S;n++){                                                               // naive way of calculating the monomial basis.
      apply_op(domain,level,R[n],R[n-1],a,b);                                                   // R[n] = A(R[n-1]) = A^(n)r
    }


    // form G[][] and g[]
    domain->CAKrylov_formations_of_G++;                                                         //   Record the number of times CACG formed G[][]
    matmul_grids(domain,level,Gbuf,PR,PR,2*__CA_KRYLOV_S+1,2*__CA_KRYLOV_S+1,1);                // Compute Gbuf[][] = [P,R]^T * [P,R] (Matmul with grids but only one MPI_AllReduce)
    for(i=0,k=0;i<2*__CA_KRYLOV_S+1;i++){                                                       // extract G[][] from Gbuf[]
    for(j=0    ;j<2*__CA_KRYLOV_S+1;j++){G[i][j] = Gbuf[k++];}                                  // first 2*__CA_KRYLOV_S+1 elements in each row go to G[][].
    }


    for(i=0;i<2*__CA_KRYLOV_S+1;i++)aj[i]=0.0;aj[               0]=1.0;                         // initialized based on (???)
    for(i=0;i<2*__CA_KRYLOV_S+1;i++)cj[i]=0.0;cj[__CA_KRYLOV_S+1]=1.0;                          // initialized based on (???)
    for(i=0;i<2*__CA_KRYLOV_S+1;i++)ej[i]=0.0;                                                  // initialized based on (???)

    for(n=0;n<__CA_KRYLOV_S;n++){                                                               // for(n=0;n<__CA_KRYLOV_S;n++){
      domain->Krylov_iterations++;                                                              //   record number of inner-loop (j) iterations for comparison
      __gemv( Tpaj,1.0,Tp,  aj,0.0, Tpaj,2*__CA_KRYLOV_S+1,2*__CA_KRYLOV_S+1);                  //               T'aj
      __gemv(temp1,1.0, G,Tpaj,0.0,temp1,2*__CA_KRYLOV_S+1,2*__CA_KRYLOV_S+1);                  //    temp1[] = GT'aj
      __gemv(temp2,1.0, G,  cj,0.0,temp2,2*__CA_KRYLOV_S+1,2*__CA_KRYLOV_S+1);                  //    temp2[] = Gcj
           aj_dot_GTpaj = __dot(aj,temp1,2*__CA_KRYLOV_S+1);                                    //   (aj,GT'aj)
             cj_dot_Gcj = __dot(cj,temp2,2*__CA_KRYLOV_S+1);                                    //   (cj,  Gcj)
      // FIX, can cj_dot_Gcj ever be zero ?
      if(aj_dot_GTpaj == 0.0){                                                                  //   pivot breakdown ???
        CGFailed=1;break;                                                                       //
      }                                                                                         //
      alpha = cj_dot_Gcj / aj_dot_GTpaj;                                                        //   alpha = (cj,Gcj) / (aj,GT'aj)
      if(isinf(alpha)){                                                                         //   alpha = big/tiny(overflow) = inf -> breakdown
        CGFailed=1;break;                                                                       // 
      }                                                                                         //
      __axpy(   ej,1.0,ej,   alpha,   aj,2*__CA_KRYLOV_S+1);                                    //   ej[] = ej[] + alpha*aj[]    
      __axpy(   cj,1.0,cj,  -alpha, Tpaj,2*__CA_KRYLOV_S+1);                                    //   cj[] = cj[] - alpha*T'*aj[]    
      __gemv(temp2,1.0, G,  cj,0.0,temp2,2*__CA_KRYLOV_S+1,2*__CA_KRYLOV_S+1);                  //    temp2[] = Gcj
         cj_dot_Gcj_new = __dot(cj,temp2,2*__CA_KRYLOV_S+1);                                    //   (cj,  Gcj)
      // calculate the norm of the incremental residual (Saad's vector 'r') to check intra s-step convergence... == cj_dot_Gcj_new??
      L2_norm_of_residual = 0.0;if(cj_dot_Gcj_new>0)L2_norm_of_residual=sqrt(cj_dot_Gcj_new);   // finite precision can lead to the norm^2 being < 0 (Demmel says flush to 0.0)
      if(L2_norm_of_residual < desired_reduction_in_norm*L2_norm_of_r0){CGConverged=1;break;}   // terminate the inner n-loop
      if(cj_dot_Gcj_new == 0.0){                                                                //   Lanczos breakdown ???
        CGFailed=1;break;                                                                       //
      }                                                                                         //
      beta = cj_dot_Gcj_new / cj_dot_Gcj;                                                       // 
      if(isinf(beta)){CGFailed=1;break;}                                                        //   beta = inf?
      if(beta == 0.0){CGFailed=1;break;}                                                        //   beta = 0?  can't make further progress(?)
      __axpy(   aj,1.0,cj,    beta,   aj,2*__CA_KRYLOV_S+1);                                    //   cj[] = cj[] + beta*aj[]    

    }                                                                                           // inner n (j) loop

    // update iterates...
    for(i=0;i<2*__CA_KRYLOV_S+1;i++){add_grids(domain,level,e_id,1.0,e_id,ej[i],PR[i]);}        // e_id[] = [P,R]ej + e_id[]
    if(!CGFailed && !CGConverged){                                                              // if we're done, then there is no point in updating these
                                     add_grids(domain,level, __p,0.0, __p,aj[0],PR[0]);         //    p[] = [P,R]aj
    for(i=1;i<2*__CA_KRYLOV_S+1;i++){add_grids(domain,level, __p,1.0, __p,aj[i],PR[i]);}        //          ...
                                     add_grids(domain,level, __r,0.0, __r,cj[0],PR[0]);         //    r[] = [P,R]cj
    for(i=1;i<2*__CA_KRYLOV_S+1;i++){add_grids(domain,level, __r,1.0, __r,cj[i],PR[i]);}        //          ...
    }
                              m+=__CA_KRYLOV_S;                                                 //   m+=__CA_KRYLOV_S;
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  }                                                                                             // } // outer m loop

}


//------------------------------------------------------------------------------------------------------------------------------
void CG(domain_type * domain, int level, int x_id, int R_id, double a, double b, double desired_reduction_in_norm){
  // Algorithm 6.18 in Iterative Methods for Sparse Linear Systems(Yousef Saad)
  int jMax=200;
  int j=0;
  int CGFailed    = 0;
  int CGConverged = 0;
  residual(domain,level,__r0,x_id,R_id,a,b);                                   // r0[] = R_id[] - A(x_id)
  scale_grid(domain,level,__r,1.0,__r0);                                       // r[] = r0[]
  scale_grid(domain,level,__p,1.0,__r0);                                       // p[] = r0[]
  double norm_of_r0 = norm(domain,level,__r);                                  // the norm of the initial residual...
  if(norm_of_r0 == 0.0){CGConverged=1;}                                        // entered CG with exact solution
  double r_dot_r = dot(domain,level,__r,__r);                                  // r_dot_r = dot(r,r)
  while( (j<jMax) && (!CGFailed) && (!CGConverged) ){                          // while(not done){
    j++;domain->Krylov_iterations++;                                           //
    apply_op(domain,level,__Ap,__p,a,b);                                       //   Ap = A(p)
    double Ap_dot_p = dot(domain,level,__Ap,__p);                              //   Ap_dot_p = dot(Ap,p)
    if(Ap_dot_p == 0.0){CGFailed=1;break;}                                     //   pivot breakdown ???
    double alpha = r_dot_r / Ap_dot_p;                                         //   alpha = r_dot_r / Ap_dot_p
    if(isinf(alpha)){CGFailed=1;break;}                                        //   ???
    add_grids(domain,level,x_id,1.0,x_id, alpha,__p );                         //   x_id[] = x_id[] + alpha*p[]
    add_grids(domain,level,__r ,1.0,__r ,-alpha,__Ap);                         //   r[]    = r[]    - alpha*Ap[]   (intermediate residual?)
    double norm_of_r = norm(domain,level,__r);                                 //   norm of intermediate residual
    if(norm_of_r == 0.0){CGConverged=1;break;}                                 //
    if(norm_of_r < desired_reduction_in_norm*norm_of_r0){CGConverged=1;break;} //
    double r_dot_r_new = dot(domain,level,__r,__r);                            //   r_dot_r_new = dot(r_{j+1},r_{j+1})
    if(r_dot_r_new == 0.0){CGFailed=1;break;}                                  //   Lanczos breakdown ???
    double beta = (r_dot_r_new/r_dot_r);                                       //   beta = (r_dot_r_new/r_dot_r)
    if(isinf(beta)){CGFailed=1;break;}                                         //   ???
    add_grids(domain,level,__p,1.0,__r,beta,__p );                             //   p[] = r[] + beta*p[]
    r_dot_r = r_dot_r_new;                                                     //   r_dot_r = r_dot_r_new   (save old r_dot_r)
  }                                                                            // }
}

//------------------------------------------------------------------------------------------------------------------------------
void IterativeSolver(domain_type * domain, int level, int e_id, int R_id, double a, double b, double desired_reduction_in_norm){ 
  // code presumes e_id was an externally initialized with the initial guess
  #ifdef __USE_BICGSTAB
    #warning Using BiCGStab bottom solver...
    BiCGStab(domain,level,e_id,R_id,a,b,desired_reduction_in_norm);
  #elif  __USE_CG
    #warning Using CG bottom solver...
    CG(domain,level,e_id,R_id,a,b,desired_reduction_in_norm);
  #elif  __USE_CABICGSTAB
    #warning Using Communication-Avoiding BiCGStab bottom solver... 
  //           CABiCGStab(domain,level,e_id,R_id,a,b,desired_reduction_in_norm);
    TelescopingCABiCGStab(domain,level,e_id,R_id,a,b,desired_reduction_in_norm);
  #elif  __USE_CACG
    #warning Using Communication-Avoiding CG bottom solver... 
    CACG(domain,level,e_id,R_id,a,b,desired_reduction_in_norm);
  #else // just multiple smooth()'s
    #warning Defaulting to simple bottom solver with fixed number of smooths...
    int s,numSmoothsBottom=48;
    for(s=0;s<numSmoothsBottom;s+=numSmooths)smooth(domain,level,e_id,R_id,a,b);
  #endif
}

int IterativeSolver_NumGrids(){
  // additionally number of grids required by an iterative solver...
  #ifdef __USE_BICGSTAB
  return(6);                  // BiCGStab requires additional grids r0,r,p,s,Ap,As
  #elif  __USE_CG
  return(6);                  // CG requires extra grids r0,r,p,Ap
  #elif  __USE_CABICGSTAB
  return(4+4*__CA_KRYLOV_S); // CABiCGStab requires additional grids rt,p,r,P[2s+1],R[2s].
  #elif  __USE_CACG
  return(4+2*__CA_KRYLOV_S); // CACG requires additional grids r0,p,r,P[s+1],R[s].
  #endif
  return(0);                  // simply doing multiple smooths requires no extra grids
}
//------------------------------------------------------------------------------------------------------------------------------
