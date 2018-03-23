//
// See README-LCALS_license.txt for access and distribution restrictions
//

//
// Header file defining macros, routines, structures used in Loop Subset B.
//

#ifndef SubsetDataB_HXX
#define SubsetDataB_HXX

namespace {

//
// Function used in TRAP_INT loop.
//
LCALS_INLINE
Real_type trap_int_func(Real_type x,
                        Real_type y,
                        Real_type xp,
                        Real_type yp)
{
   Real_type denom = (x - xp)*(x - xp) + (y - yp)*(y - yp);
   denom = 1.0/sqrt(denom);
   return denom;
}

}  // closing brace for unnamed namespace

#endif  // closing endif for header file include guard
