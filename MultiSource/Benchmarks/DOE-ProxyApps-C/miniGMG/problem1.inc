//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "defines.h"
#include "timer.h"
#include "mg.h"
//------------------------------------------------------------------------------------------------------------------------------
void initialize_problem(domain_type *domain, int level, double hLevel, double a, double b){
  double NPi = 2.0*M_PI;
  double Bmin =  1.0;
  double Bmax = 10.0;
  double c2 = (Bmax-Bmin)/2;
  double c1 = (Bmax+Bmin)/2;
  double c3=10.0; // how sharply (B)eta transitions
  double c4 = -5.0/0.25;

  int box;
  for(box=0;box<domain->subdomains_per_rank;box++){
    memset(domain->subdomains[box].levels[level].grids[__u_exact],0,domain->subdomains[box].levels[level].volume*sizeof(double));
    memset(domain->subdomains[box].levels[level].grids[__f      ],0,domain->subdomains[box].levels[level].volume*sizeof(double));
    int i,j,k;
    #pragma omp parallel for private(k,j,i) collapse(2)
    for(k=0;k<domain->subdomains[box].levels[level].dim.k;k++){
    for(j=0;j<domain->subdomains[box].levels[level].dim.j;j++){
    for(i=0;i<domain->subdomains[box].levels[level].dim.i;i++){
      double x = hLevel*((double)(i+domain->subdomains[box].levels[level].low.i)+0.5);
      double y = hLevel*((double)(j+domain->subdomains[box].levels[level].low.j)+0.5);
      double z = hLevel*((double)(k+domain->subdomains[box].levels[level].low.k)+0.5);
      int ijk =                                              (i+domain->subdomains[box].levels[level].ghosts)+
                domain->subdomains[box].levels[level].pencil*(j+domain->subdomains[box].levels[level].ghosts)+
                domain->subdomains[box].levels[level].plane *(k+domain->subdomains[box].levels[level].ghosts);
      //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
      double r2   = pow((x-0.50),2) +  pow((y-0.50),2) +  pow((z-0.50),2); // distance from center squared
      double r2x  = 2.0*(x-0.50);
      double r2y  = 2.0*(y-0.50);
      double r2z  = 2.0*(z-0.50);
      double r2xx = 2.0;
      double r2yy = 2.0;
      double r2zz = 2.0;
      double r    = pow(r2,0.5);
      double rx   = 0.5*r2x*pow(r2,-0.5);
      double ry   = 0.5*r2y*pow(r2,-0.5);
      double rz   = 0.5*r2z*pow(r2,-0.5);
      double rxx  = 0.5*r2xx*pow(r2,-0.5) - 0.25*r2x*r2x*pow(r2,-1.5);
      double ryy  = 0.5*r2yy*pow(r2,-0.5) - 0.25*r2y*r2y*pow(r2,-1.5);
      double rzz  = 0.5*r2zz*pow(r2,-0.5) - 0.25*r2z*r2z*pow(r2,-1.5);
      //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
      // beta (B) is a bubble...
      double A  = 1.0;
      double B  =           c1+c2*tanh( c3*(r-0.25) );
      double Bx = c2*c3*rx*(1-pow(tanh( c3*(r-0.25) ),2));
      double By = c2*c3*ry*(1-pow(tanh( c3*(r-0.25) ),2));
      double Bz = c2*c3*rz*(1-pow(tanh( c3*(r-0.25) ),2)); 
      //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
      double u   =                exp(c4*r2)*sin(NPi*x)*sin(NPi*y)*sin(NPi*z);
      double ux  = c4*r2x*u + NPi*exp(c4*r2)*cos(NPi*x)*sin(NPi*y)*sin(NPi*z);
      double uy  = c4*r2y*u + NPi*exp(c4*r2)*sin(NPi*x)*cos(NPi*y)*sin(NPi*z);
      double uz  = c4*r2z*u + NPi*exp(c4*r2)*sin(NPi*x)*sin(NPi*y)*cos(NPi*z);
      double uxx = c4*r2xx*u + c4*r2x*ux + c4*r2x*NPi*exp(c4*r2)*cos(NPi*x)*sin(NPi*y)*sin(NPi*z) - NPi*NPi*exp(c4*r2)*sin(NPi*x)*sin(NPi*y)*sin(NPi*z);
      double uyy = c4*r2yy*u + c4*r2y*uy + c4*r2y*NPi*exp(c4*r2)*sin(NPi*x)*cos(NPi*y)*sin(NPi*z) - NPi*NPi*exp(c4*r2)*sin(NPi*x)*sin(NPi*y)*sin(NPi*z);
      double uzz = c4*r2zz*u + c4*r2z*uz + c4*r2z*NPi*exp(c4*r2)*sin(NPi*x)*sin(NPi*y)*cos(NPi*z) - NPi*NPi*exp(c4*r2)*sin(NPi*x)*sin(NPi*y)*sin(NPi*z);
      double f = a*A*u - b*( (Bx*ux + By*uy + Bz*uz)  +  B*(uxx + uyy + uzz) );
      //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
      domain->subdomains[box].levels[level].grids[__alpha  ][ijk] = A;
      domain->subdomains[box].levels[level].grids[__beta   ][ijk] = B;
      domain->subdomains[box].levels[level].grids[__u_exact][ijk] = u;
      domain->subdomains[box].levels[level].grids[__f      ][ijk] = f;
    }}}
  }

  double average_value_of_f = mean(domain,level,__f);
  if(domain->rank==0){printf("\n  average value of f = %20.12e\n",average_value_of_f);fflush(stdout);}
  if(a!=0){
  shift_grid(domain,level,__f      ,__f      ,-average_value_of_f);
  shift_grid(domain,level,__u_exact,__u_exact,-average_value_of_f/a);
  }
  // what if a==0 and average_value_of_f != 0 ???
}
//------------------------------------------------------------------------------------------------------------------------------
