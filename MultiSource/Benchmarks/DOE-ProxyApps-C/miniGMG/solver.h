//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
#ifndef SOLVER_H
#define SOLVER_H
#include "mg.h"
void IterativeSolver(domain_type *domain, int level, int e_id, int R_id, double a, double b, double desired_reduction_in_norm);
int  IterativeSolver_NumGrids();
#endif
