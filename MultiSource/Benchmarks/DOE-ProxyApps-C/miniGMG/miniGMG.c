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
#ifdef OMP
#include <omp.h>
#endif
#ifdef __MPI
#include <mpi.h>
#endif
//------------------------------------------------------------------------------------------------------------------------------
#include "defines.h"
#include "box.h"
#include "mg.h"
#include "operators.h"
//------------------------------------------------------------------------------------------------------------------------------
void MGResetTimers(domain_type * domain);
int main(int argc, char **argv){
  int MPI_Rank=0;
  int MPI_Tasks=1;
  int OMP_Threads = 1;

#ifdef OMP
  #pragma omp parallel 
  {
    #pragma omp master
    {
      OMP_Threads = omp_get_num_threads();
    }
  }
#endif    

  #ifdef __MPI
  #warning Compiling for MPI...
  int MPI_threadingModel          = -1;
//int MPI_threadingModelRequested = MPI_THREAD_SINGLE;
//int MPI_threadingModelRequested = MPI_THREAD_SERIALIZED;
  int MPI_threadingModelRequested = MPI_THREAD_FUNNELED;
//int MPI_threadingModelRequested = MPI_THREAD_MULTIPLE;
      #ifdef __MPI_THREAD_MULTIPLE
      MPI_threadingModelRequested = MPI_THREAD_MULTIPLE;
      #endif
  MPI_Init_thread(&argc, &argv, MPI_threadingModelRequested, &MPI_threadingModel);
  MPI_Comm_size(MPI_COMM_WORLD, &MPI_Tasks);
  MPI_Comm_rank(MPI_COMM_WORLD, &MPI_Rank);

  if(MPI_threadingModel>MPI_threadingModelRequested)MPI_threadingModel=MPI_threadingModelRequested;
  if(MPI_Rank==0){
       if(MPI_threadingModelRequested == MPI_THREAD_MULTIPLE  )printf("Requested MPI_THREAD_MULTIPLE, ");
  else if(MPI_threadingModelRequested == MPI_THREAD_SINGLE    )printf("Requested MPI_THREAD_SINGLE, ");
  else if(MPI_threadingModelRequested == MPI_THREAD_FUNNELED  )printf("Requested MPI_THREAD_FUNNELED, ");
  else if(MPI_threadingModelRequested == MPI_THREAD_SERIALIZED)printf("Requested MPI_THREAD_SERIALIZED, ");
  else if(MPI_threadingModelRequested == MPI_THREAD_MULTIPLE  )printf("Requested MPI_THREAD_MULTIPLE, ");
  else                                                         printf("Requested Unknown MPI Threading Model (%d), ",MPI_threadingModelRequested);
       if(MPI_threadingModel == MPI_THREAD_MULTIPLE  )printf("got MPI_THREAD_MULTIPLE\n");
  else if(MPI_threadingModel == MPI_THREAD_SINGLE    )printf("got MPI_THREAD_SINGLE\n");
  else if(MPI_threadingModel == MPI_THREAD_FUNNELED  )printf("got MPI_THREAD_FUNNELED\n");
  else if(MPI_threadingModel == MPI_THREAD_SERIALIZED)printf("got MPI_THREAD_SERIALIZED\n");
  else if(MPI_threadingModel == MPI_THREAD_MULTIPLE  )printf("got MPI_THREAD_MULTIPLE\n");
  else                                                printf("got Unknown MPI Threading Model (%d)\n",MPI_threadingModel);
  fflush(stdout);  }
    #ifdef __MPI_THREAD_MULTIPLE
    if( (MPI_threadingModelRequested == MPI_THREAD_MULTIPLE) && (MPI_threadingModel != MPI_THREAD_MULTIPLE) ){MPI_Finalize();exit(0);}
    #endif
  #endif


  int log2_subdomain_dim = 6;
  int subdomains_per_rank_in_i=256 / (1<<log2_subdomain_dim);
  int subdomains_per_rank_in_j=256 / (1<<log2_subdomain_dim);
  int subdomains_per_rank_in_k=256 / (1<<log2_subdomain_dim);
  int ranks_in_i=1;
  int ranks_in_j=1;
  int ranks_in_k=1;

  if(argc==2){
          log2_subdomain_dim=atoi(argv[1]);
          subdomains_per_rank_in_i=256 / (1<<log2_subdomain_dim);
          subdomains_per_rank_in_j=256 / (1<<log2_subdomain_dim);
          subdomains_per_rank_in_k=256 / (1<<log2_subdomain_dim);
  }else if(argc==5){
          log2_subdomain_dim=atoi(argv[1]);
    subdomains_per_rank_in_i=atoi(argv[2]);
    subdomains_per_rank_in_j=atoi(argv[3]);
    subdomains_per_rank_in_k=atoi(argv[4]);
  }else if(argc==8){
          log2_subdomain_dim=atoi(argv[1]);
    subdomains_per_rank_in_i=atoi(argv[2]);
    subdomains_per_rank_in_j=atoi(argv[3]);
    subdomains_per_rank_in_k=atoi(argv[4]);
                  ranks_in_i=atoi(argv[5]);
                  ranks_in_j=atoi(argv[6]);
                  ranks_in_k=atoi(argv[7]);
  }else if(argc!=1){
    if(MPI_Rank==0){printf("usage: ./a.out [log2_subdomain_dim]   [subdomains per rank in i,j,k]  [ranks in i,j,k]\n");}
    #ifdef __MPI
    MPI_Finalize();
    #endif
    exit(0);
  }

/*
  if(log2_subdomain_dim>7){
    if(MPI_Rank==0){printf("error, log2_subdomain_dim(%d)>7\n",log2_subdomain_dim);}
    #ifdef __MPI
    MPI_Finalize();
    #endif
    exit(0);
  }
*/

  if(ranks_in_i*ranks_in_j*ranks_in_k != MPI_Tasks){
    if(MPI_Rank==0){printf("error, ranks_in_i*ranks_in_j*ranks_in_k(%d*%d*%d=%d) != MPI_Tasks(%d)\n",ranks_in_i,ranks_in_j,ranks_in_k,ranks_in_i*ranks_in_j*ranks_in_k,MPI_Tasks);}
    #ifdef __MPI
    MPI_Finalize();
    #endif
    exit(0);
  }

  if(MPI_Rank==0)printf("%d MPI Tasks of %d threads\n",MPI_Tasks,OMP_Threads);

  int subdomain_dim_i=1<<log2_subdomain_dim;
  int subdomain_dim_j=1<<log2_subdomain_dim;
  int subdomain_dim_k=1<<log2_subdomain_dim;
  // fine dim = 128 64 32 16 8 4
  //   levels =   6  5  4  3 2 1
//int log2_coarse_dim = 2; // i.e. coarsen to 4^3
  int log2_coarse_dim = 1; // i.e. coarsen to 2^3
  int levels_in_vcycle=1+log2_subdomain_dim-log2_coarse_dim; // ie 1+log2(fine grid size)-log2(bottom grid size)
  if(MPI_Rank==0){printf("truncating the v-cycle at %d^3 subdomains\n",1<<log2_coarse_dim);fflush(stdout);}

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  int box;
  domain_type domain;
  int boundary_conditions[3] = {__BOUNDARY_PERIODIC,__BOUNDARY_PERIODIC,__BOUNDARY_PERIODIC}; // i-, j-, and k-directions
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  create_domain(&domain,
                           subdomain_dim_i,subdomain_dim_j,subdomain_dim_k,
                           subdomains_per_rank_in_i,subdomains_per_rank_in_j,subdomains_per_rank_in_k,
                           ranks_in_i,ranks_in_j,ranks_in_k,
                           MPI_Rank,
                           boundary_conditions,
                           __NumGrids,1,levels_in_vcycle);
  double h0=1.0/((double)(domain.dim.i));
  if(MPI_Rank==0){printf("initializing alpha, beta, RHS for the ``hard problem''...");fflush(stdout);}
  double  a=0.9;       // i.e. good Helmholtz
  double  b=0.9;
  initialize_problem(&domain,0,h0,a,b);
  if(MPI_Rank==0){printf("done\n");fflush(stdout);}
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  MGBuild(&domain,a,b,h0); // restrictions, dominant eigenvalue, etc...
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  int s,sMax=2;
  #ifdef __MPI
  sMax=4;
  #endif
                    //Make initial an guess for u(=0)... Solve Lu=f to precision of 1e-10...print the benchmarking timing results...
  MGResetTimers(&domain);for(s=0;s<sMax;s++){zero_grid(&domain,0,__u); MGSolve(&domain,__u,__f,a,b,1e-15);}print_timing(&domain);
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  // calculate error...
  double h3 = h0*h0*h0;
                 add_grids(&domain,0,__temp,1.0,__u_exact,-1.0,__u);       // __temp = __u_exact - __u
  double   max =      norm(&domain,0,__temp);                              // max norm of error function
  double error = sqrt( dot(&domain,0,__temp,__temp)*h3);                   // normalized L2 error ?
  if(MPI_Rank==0){printf("Error test: h = %e, max = %e\n",h0,max);}
  if(MPI_Rank==0){printf("Error test: h = %e, L2  = %e\n",h0,error);}
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  destroy_domain(&domain);
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  #ifdef __MPI
  MPI_Finalize();
  #endif
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  return(0);
}
