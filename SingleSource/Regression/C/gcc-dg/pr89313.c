/* PR rtl-optimization/89313  */
/* { dg-do compile { target aarch64*-*-* arm*-*-* i?86-*-* powerpc*-*-* s390*-*-* x86_64-*-* } } */
/* { dg-options "-O2" } */

#if defined (__aarch64__)
# define REG "x0"
# define ASM "add"
#elif defined (__arm__)
# define REG "r0"
# define ASM "add"
#elif defined (__i386__)
# define REG "%eax"
# define ASM "mov"
#elif defined (__powerpc__) || defined (__POWERPC__)
# define REG "r3"
# define ASM "add"
#elif defined (__s390__)
# define REG "0"
# define ASM "lmg"
#elif defined (__x86_64__)
# define REG "rax"
# define ASM "mov"
#endif

long
bug (long arg)
{
  register long output asm (REG);
  long input = arg;
  asm (ASM
#if defined (__i386__)
       " %0, 0(%1,%2)"
#elif defined (__s390__)
       " %0, %1, 0(%2)"
#else
       " %0, 0(%1,%2)"
#endif
       : "=&r" (output) : "r" (input), "0" (input));
  return output;
}
