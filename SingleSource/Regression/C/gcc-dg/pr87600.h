#if defined (__aarch64__)
# define REG1 "x0"
# define REG2 "x1"
# define ASM0 "mov"
# define ASM1 "add"
#elif defined (__arm__)
# define REG1 "r0"
# define REG2 "r1"
# define ASM0 "mov"
# define ASM1 "add"
#elif defined (__i386__)
# define REG1 "%eax"
# define REG2 "%edx"
# define ASM0 "mov"
# define ASM1 "movl"
#elif defined (__powerpc__) || defined (__POWERPC__)
# define REG1 "r3"
# define REG2 "r4"
# define ASM0 "mr"
# define ASM1 "add"
#elif defined (__s390__)
# define REG1 "0"
# define REG2 "1"
# define ASM0 "lgr"
# define ASM1 "lmg"
#elif defined (__x86_64__)
# define REG1 "rax"
# define REG2 "rdx"
# define ASM0 "mov"
# define ASM1 "add"
#endif
