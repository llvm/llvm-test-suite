/*
 * This test stresses masking and sign-extension for operations on
 * signed and unsigned types less than the machine integer reg. size.
 * Several things have to happen correctly:
 * -- correct constant folding if it is done at compile-time
 * -- correct sign-extensions during native code generation for -, * and /.
 * -- correct handling of high bits during native code generation for
 *    a sequence of operations involving -, * and /.
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int
main(int argc, char** argv)
{
  unsigned long  UL = 0xafafafafc5c5b8a3;
           long   L = (long) UL;

  unsigned int   ui = (unsigned int) UL;        /* 0xc5c5b8a3 =  3318069411 */
           int    i =          (int) UL;        /* 0xc5c5b8a3 = -976897885 */

  unsigned short us = (unsigned short) UL;      /*     0xb8a3 =  47267 */
           short  s =          (short) UL;      /*     0xb8a3 = -18269 */

  uint8_t        ub = (uint8_t) UL;             /*       0xa3 =  163 */
  int8_t          b = ( int8_t) UL;             /*       0xa3 = -93 */

  printf("   ui = %u (0x%x)\t\tUL-ui = %ld (0x%x)\n",   ui, ui, UL-ui, UL-ui);
  printf("ui*ui = %u (0x%x)\t  UL/ui = %ld (0x%x)\n\n",
         (unsigned int) ui*ui, (unsigned int) ui*ui, UL/ui, UL/ui);

  printf("    i = %d (0x%x)\tL-i = %ld (0x%x)\n",     i, i, L-i, L-i);
  printf(" i* i = %d (0x%x)\tL/ i = %ld (0x%x)\n\n",
         (int) i*i,  (int) i*i, L/i, L/i);

  printf("us    = %u (0x%x)\t\tUL-us = %ld (0x%x)\n",   us, us, UL-us, UL-us);
  printf("us*us = %u (0x%x)\t  UL/us = %ld (0x%x)\n\n",
         (unsigned short) us*us, (unsigned short) us*us, UL/us, UL/us);

  printf(" s    = %d (0x%x)\tL-s = %ld (0x%x)\n",     s, s, L-s, L-s);
  printf(" s* s = %d (0x%x)\tL/ s = %ld (0x%x)\n\n",
         (short) s*s, (short) s*s, L/s, L/s);

  printf("ub    = %u (0x%x)\t\tUL-ub = %ld (0x%x)\n",   ub, ub, UL-ub, UL-ub);
  printf("ub*ub = %u (0x%x)\t\tUL/ub = %ld (0x%x)\n\n",
         (uint8_t) ub*ub, (uint8_t) ub*ub, UL/ub, UL/ub);

  printf(" b    = %d (0x%x)\t\tL-b = %ld (0x%x)\n",     b, b, L-b, L-b);
  printf(" b* b = %d (0x%x)\t\t\tL/b = %ld (0x%x)\n\n",
         (int8_t) b*b, (int8_t) b*b, L/b, L/b);

  return 0;
}
