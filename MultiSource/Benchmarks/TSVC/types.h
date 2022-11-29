#ifndef TYPES_H
#define TYPES_H

#define LEN 32000
#define LEN2 256

#ifndef TYPE
  #define TYPE float
  #define FABS(x) fabsf(x)
#else
  #define FABS(x) fabs(x)
#endif

#ifndef X_TYPE
  #define X_TYPE TYPE
#endif

#ifndef ALIGNMENT
#define ALIGNMENT 16
#endif

#endif // TYPES_H

