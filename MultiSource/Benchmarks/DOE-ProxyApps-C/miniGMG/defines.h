//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
// Helmholtz ~ Laplacian() = a*alpha*Identity - b*Divergence*beta*Gradient
//------------------------------------------------------------------------------------------------------------------------------
#ifndef DEFINES_H
#define DEFINES_H
#define  __u           0 // = what we're eventually solving for (u), cell centered
#define  __f           1 // = original right-hand side (Au=f), cell centered
#define  __alpha       2 // cell centered constant
#define  __beta        3 // cell centered constant
//------------------------------------------------------------------------------------------------------------------
#define  __lambda      4 // cell centered constant (inverse of the diagonal)
#define  __beta_i      5 // face constant (n.b. element 0 is the left face of the ghost zone element)
#define  __beta_j      6 // face constant (n.b. element 0 is the back face of the ghost zone element)
#define  __beta_k      7 // face constant (n.b. element 0 is the bottom face of the ghost zone element)
#define  __ee          8 // = used for correction (ee) in residual correction form, cell centered
#define  __f_minus_Av  9 // = used for initial right-hand side (f-Av) in residual correction form, cell centered
#define  __temp       10 // = used for unrestricted residual (r), cell centered
#define  __u_exact    11
//------------------------------------------------------------------------------------------------------------------
#define  __NumGrids   12 // total number of grids and the starting location for bottom solver grids
//------------------------------------------------------------------------------------------------------------------

// FIX, these should be adhoc allocated starting with __NumGrids
// For CG bottom solver
#define  __r          13
#define  __p          14
#define  __Ap         16

// For BiCGStab bottom solver
#define  __r0         12
#define  __r          13
#define  __p          14
#define  __s          15
#define  __Ap         16
#define  __As         17

// For CABiCGStab bottom solver
#define  __rt         12
#define  __r          13
#define  __p          14
#define  __PRrt       15 // starting location for the 2S+1 extra p[]'s, 2S extra r[]'s, and rt

// For CACG bottom solver
#define  __r0         12
#define  __r          13
#define  __p          14
#define  __PRrt       15 // starting location for the S+1 extra p[]'s, S extra r[]'s, and rt
#endif
