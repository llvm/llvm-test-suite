/* PR inline-asm/8832 */
/* { dg-do compile } */
/* { dg-options "-O2 -dP -fno-thread-jumps" } */

/* Verify that GCC doesn't optimize
   old style asm instructions.  */

void foo(int v)
{
  if (v)
    asm ("dummy1");

  asm ("dummy2");

  if (v)
    asm ("dummy3");
}

/* The purpose of the test below is to check that there are two branches
   in the generated code, supposedly corresponding to the if-statements.
   It tries to check for jump_insn (set (pc) pattern, so that jump_insns
   corresponding to return are not taken into account.  */
/* { dg-final { scan-assembler "jump_insn.*set \\(pc\\).*jump_insn.*set \\(pc\\)"} } */
