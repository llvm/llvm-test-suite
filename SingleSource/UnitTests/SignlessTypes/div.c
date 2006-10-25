/* 
 * This file is used to test division operations in conjunction with
 * the Signless Types feature. The DIV instruction was replaced with
 * UDIV, SDIV and FDIV instructions. The tests here are aimed at
 * triggering InstructionCombining transforms to exercise them and
 * ensure they are not altering the computed values.
 */

#include <stdio.h>

unsigned 
udivTest1(unsigned X, unsigned Y) {

  unsigned Tally = 0;
  /* 0 / X == 0 */
  Tally += 0 / X;

  /* div X, 1 == X */
  Tally += X / 1;

  /* div X, -1 == -X */
  Tally += X / -1;

  /* div X, (Cond ? 0 : Y) -> div X, Y.  */
  Tally += ( X == Y ? 0 : Y );
  Tally += ( X == Y ? ((unsigned)0) : Y );

  /* div X, (Cond ? Y : 0) -> div X, Y */
  Tally += ( X != Y ? Y : 0 );
  Tally += ( X != Y ? Y : ((unsigned)0) );

  /* (X / C1) / C2  -> X / (C1*C2) */
  Tally += ( X / 2 ) / 4;
  Tally += ( X / ((unsigned)2)) / ((unsigned)4);

  /* X udiv C^2 -> X >> C */
  Tally += X / 4;
  Tally += X / ((unsigned)4);

  /* X udiv (C1 << N), where C1 is "1<<C2"  -->  X >> (N+C2) */
  Tally += X / (4 << Y);
  Tally += X / (((unsigned)4) << Y);

  /* udiv X, (Select Cond, C1, C2) --> Select Cond, (shr X, C1), (shr X, C2) */
  Tally += X / (X == Y, 2, 4);
  Tally += X / (X == Y, ((unsigned)2), ((unsigned)4));

  /* -X/C -> X/-C */
  Tally += -X / 2;
  Tally += -X / ((unsigned)2);

  return Tally;
}

int main(int argc, char**argv) {
  unsigned result = udivTest1(42, 3);
  printf("udivTest1(42,17) = %u\n", udivTest1(42,17));
}
