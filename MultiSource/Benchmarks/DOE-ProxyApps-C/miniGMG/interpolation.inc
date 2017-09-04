//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
#include <stdint.h>
#include "timer.h"
#include "mg.h"
//------------------------------------------------------------------------------------------------------------------------------
// piecewise constant interpolation...
//
// +-------+    +---+---+
// |       |    | x | x |
// |   x   | -> +---+---+
// |       |    | x | x |
// +-------+    +---+---+
//
//------------------------------------------------------------------------------------------------------------------------------
void interpolation_constant(domain_type * domain, int level_f, double prescale_f, int id_f, int id_c){ // id_f = prescale*id_f + I_{2h}^{h}(id_c)
  int level_c = level_f+1;
  uint64_t _timeStart = CycleTime();

  int CollaborativeThreadingBoxSize = 100000; // i.e. never
  #ifdef __COLLABORATIVE_THREADING
    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;
  #endif
  int omp_across_boxes = (domain->subdomains[0].levels[level_f].dim.i <  CollaborativeThreadingBoxSize);
  int omp_within_a_box = (domain->subdomains[0].levels[level_f].dim.i >= CollaborativeThreadingBoxSize);
  int box;

  #pragma omp parallel for private(box) if(omp_across_boxes)
  for(box=0;box<domain->subdomains_per_rank;box++){
    int i,j,k;
    int ghosts_c = domain->subdomains[box].levels[level_c].ghosts;
    int pencil_c = domain->subdomains[box].levels[level_c].pencil;
    int  plane_c = domain->subdomains[box].levels[level_c].plane;
  
    int ghosts_f = domain->subdomains[box].levels[level_f].ghosts;
    int pencil_f = domain->subdomains[box].levels[level_f].pencil;
    int  plane_f = domain->subdomains[box].levels[level_f].plane;
    int  dim_i_f = domain->subdomains[box].levels[level_f].dim.i;
    int  dim_j_f = domain->subdomains[box].levels[level_f].dim.j;
    int  dim_k_f = domain->subdomains[box].levels[level_f].dim.k;
  
    double * __restrict__ grid_f = domain->subdomains[box].levels[level_f].grids[id_f] + ghosts_f*(1+pencil_f+plane_f);
    double * __restrict__ grid_c = domain->subdomains[box].levels[level_c].grids[id_c] + ghosts_c*(1+pencil_c+plane_c);
  
    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2)
    for(k=0;k<dim_k_f;k++){
    for(j=0;j<dim_j_f;j++){
    for(i=0;i<dim_i_f;i++){
      int ijk_f = (i   ) + (j   )*pencil_f + (k   )*plane_f;
      int ijk_c = (i>>1) + (j>>1)*pencil_c + (k>>1)*plane_c;
      grid_f[ijk_f] = prescale_f*grid_f[ijk_f] + grid_c[ijk_c];
    }}}
  }
  domain->cycles.interpolation[level_f] += (uint64_t)(CycleTime()-_timeStart);
}

//------------------------------------------------------------------------------------------------------------------------------
// piecewise linear interpolation...
//
//------------------------------------------------------------------------------------------------------------------------------
void interpolation_linear(domain_type * domain, int level_f, double prescale_f, int id_f, int id_c){  // id_f = prescale*id_f + I_{2h}^{h}(id_c)
  int level_c = level_f+1;
  exchange_boundary(domain,level_c,id_c,1,1,1);  // linear needs corners/edges in the coarse grid.

  uint64_t _timeStart = CycleTime();

  int CollaborativeThreadingBoxSize = 100000; // i.e. never
  #ifdef __COLLABORATIVE_THREADING
    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;
  #endif
  int omp_across_boxes = (domain->subdomains[0].levels[level_f].dim.i <  CollaborativeThreadingBoxSize);
  int omp_within_a_box = (domain->subdomains[0].levels[level_f].dim.i >= CollaborativeThreadingBoxSize);
  int box;

  #pragma omp parallel for private(box) if(omp_across_boxes)
  for(box=0;box<domain->subdomains_per_rank;box++){
    int i,j,k;
    int ghosts_c = domain->subdomains[box].levels[level_c].ghosts;
    int pencil_c = domain->subdomains[box].levels[level_c].pencil;
    int  plane_c = domain->subdomains[box].levels[level_c].plane;
    int  dim_i_c = domain->subdomains[box].levels[level_c].dim.i;
    int  dim_j_c = domain->subdomains[box].levels[level_c].dim.j;
    int  dim_k_c = domain->subdomains[box].levels[level_c].dim.k;

    int ghosts_f = domain->subdomains[box].levels[level_f].ghosts;
    int pencil_f = domain->subdomains[box].levels[level_f].pencil;
    int  plane_f = domain->subdomains[box].levels[level_f].plane;
    int  dim_i_f = domain->subdomains[box].levels[level_f].dim.i;
    int  dim_j_f = domain->subdomains[box].levels[level_f].dim.j;
    int  dim_k_f = domain->subdomains[box].levels[level_f].dim.k;

    double * __restrict__ grid_f = domain->subdomains[box].levels[level_f].grids[  id_f] + ghosts_f*(1 + pencil_f + plane_f); // [0] is first non-ghost zone element
    double * __restrict__ grid_c = domain->subdomains[box].levels[level_c].grids[  id_c] + ghosts_c*(1 + pencil_c + plane_c);

    // FIX what about dirichlet boundary conditions ???
    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2)
    for(k=0;k<dim_k_f;k++){
    for(j=0;j<dim_j_f;j++){
    for(i=0;i<dim_i_f;i++){
      int ijk_f = (i   ) + (j   )*pencil_f + (k   )*plane_f;
      int ijk_c = (i>>1) + (j>>1)*pencil_c + (k>>1)*plane_c;
 
      // -----------------------------------------------------------------------------------------------------------------------
      // Piecewise Quadratic Interpolation
      // -----------------------------------------------------------------------------------------------------------------------
      // define parabola f(x) = ax^2 + bx + c through three coarse grid cells in i-direction... x=-1, x=0, and x=1
      // interpolate to (-0.25,j,k) and (+0.25,j,k)
      // combine into 3 dimensions
      //
      // +-------+-------+-------+
      // |   o   |   o   |   o   |
      // +-------+-------+-------+
      //             .
      //             .
      //       interpolation
      //             .
      //             .
      // +---+---+---+---+---+---+
      // |   |   | x | y |   |   |
      // +---+---+---+---+---+---+
      //
      #warning using 27pt stencil for piecewise-quadratic interpolation
         double xm= 0.156250,x0=0.937500,xp=-0.093750;
         double ym= 0.156250,y0=0.937500,yp=-0.093750;
         double zm= 0.156250,z0=0.937500,zp=-0.093750;
      if(i&0x1){xm=-0.093750;x0=0.937500;xp= 0.156250;}
      if(j&0x1){ym=-0.093750;y0=0.937500;yp= 0.156250;}
      if(k&0x1){zm=-0.093750;z0=0.937500;zp= 0.156250;}
      grid_f[ijk_f] =
        prescale_f*grid_f[ijk_f                   ] +

          zm*ym*xm*grid_c[ijk_c-1-pencil_c-plane_c] +
          zm*ym*x0*grid_c[ijk_c  -pencil_c-plane_c] +
          zm*ym*xp*grid_c[ijk_c+1-pencil_c-plane_c] +
          zm*y0*xm*grid_c[ijk_c-1         -plane_c] +
          zm*y0*x0*grid_c[ijk_c           -plane_c] +
          zm*y0*xp*grid_c[ijk_c+1         -plane_c] +
          zm*yp*xm*grid_c[ijk_c-1+pencil_c-plane_c] +
          zm*yp*x0*grid_c[ijk_c  +pencil_c-plane_c] +
          zm*yp*xp*grid_c[ijk_c+1+pencil_c-plane_c] +

          z0*ym*xm*grid_c[ijk_c-1-pencil_c        ] +
          z0*ym*x0*grid_c[ijk_c  -pencil_c        ] +
          z0*ym*xp*grid_c[ijk_c+1-pencil_c        ] +
          z0*y0*xm*grid_c[ijk_c-1                 ] +
          z0*y0*x0*grid_c[ijk_c                   ] +
          z0*y0*xp*grid_c[ijk_c+1                 ] +
          z0*yp*xm*grid_c[ijk_c-1+pencil_c        ] +
          z0*yp*x0*grid_c[ijk_c  +pencil_c        ] +
          z0*yp*xp*grid_c[ijk_c+1+pencil_c        ] +

          zp*ym*xm*grid_c[ijk_c-1-pencil_c+plane_c] +
          zp*ym*x0*grid_c[ijk_c  -pencil_c+plane_c] +
          zp*ym*xp*grid_c[ijk_c+1-pencil_c+plane_c] +
          zp*y0*xm*grid_c[ijk_c-1         +plane_c] +
          zp*y0*x0*grid_c[ijk_c           +plane_c] +
          zp*y0*xp*grid_c[ijk_c+1         +plane_c] +
          zp*yp*xm*grid_c[ijk_c-1+pencil_c+plane_c] +
          zp*yp*x0*grid_c[ijk_c  +pencil_c+plane_c] +
          zp*yp*xp*grid_c[ijk_c+1+pencil_c+plane_c] ;
      /*
      // -----------------------------------------------------------------------------------------------------------------------
      // Piecewise-Linear Interpolation
      // -----------------------------------------------------------------------------------------------------------------------
      // define line f(x) = bx + c through two coarse grid cells in i-direction... x=+/-1 and x=0
      // interpolate to either (-0.25) or (+0.25)
      // combine into 3 dimensions
      //
      // +-------+-------+
      // |   o   |   o   |
      // +-------+-------+
      //         .
      //         .
      //   interpolation
      //         .
      //         .
      // +---+---+---+---+
      // |   | x | y |   |
      // +---+---+---+---+
      //
      #warning using 8pt stencil for piecewise-linear interpolation
      int delta_i=       -1;if(i&0x1)delta_i=       1; // i.e. even points look backwards while odd points look forward
      int delta_j=-pencil_c;if(j&0x1)delta_j=pencil_c;
      int delta_k= -plane_c;if(k&0x1)delta_k= plane_c;
      grid_f[ijk_f] =
        prescale_f*grid_f[ijk_f                        ] +
          0.421875*grid_c[ijk_c                        ] +
          0.140625*grid_c[ijk_c                +delta_k] +
          0.140625*grid_c[ijk_c        +delta_j        ] +
          0.046875*grid_c[ijk_c        +delta_j+delta_k] +
          0.140625*grid_c[ijk_c+delta_i                ] +
          0.046875*grid_c[ijk_c+delta_i        +delta_k] +
          0.046875*grid_c[ijk_c+delta_i+delta_j        ] +
          0.015625*grid_c[ijk_c+delta_i+delta_j+delta_k] ;
      */
      /*
      // -----------------------------------------------------------------------------------------------------------------------
      // Piecewise-Linear Interpolation
      // -----------------------------------------------------------------------------------------------------------------------
      #warning using 7pt stencil for piecewise-linear interpolation... doesn't given 2nd order FMG??
      double coefi = -0.125;if(i&0x1)coefi = 0.125;
      double coefj = -0.125;if(j&0x1)coefj = 0.125;
      double coefk = -0.125;if(k&0x1)coefk = 0.125;
      grid_f[ijk_f] = prescale_f*grid_f[ijk_f         ] +
                                 grid_c[ijk_c         ] + 
                          coefi*(grid_c[ijk_c+       1]-grid_c[ijk_c-       1]) +
                          coefj*(grid_c[ijk_c+pencil_c]-grid_c[ijk_c-pencil_c]) +
                          coefk*(grid_c[ijk_c+ plane_c]-grid_c[ijk_c- plane_c]);
      */
    }}}
  }
  domain->cycles.interpolation[level_f] += (uint64_t)(CycleTime()-_timeStart);
}
//------------------------------------------------------------------------------------------------------------------------------
