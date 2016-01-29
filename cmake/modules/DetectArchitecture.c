#if defined(__aarch64__)
const char *str = "ARCHITECTURE IS AArch64";
#elif defined(__arm__)
const char *str = "ARCHITECTURE IS ARM";
#elif defined(__alpha__)
const char *str = "ARCHITECTURE IS Alpha";
#elif defined(__mips__)
const char *str = "ARCHITECTURE IS Mips";
#elif defined(__powerpc__) || defined(__ppc__) || defined(__power__)
const char *str = "ARCHITECTURE IS PowerPC";
#elif defined(__s390__)
const char *str = "ARCHITECTURE IS SystemZ";
#elif defined(__sparc__)
const char *str = "ARCHITECTURE IS Sparc";
#elif defined(__xcore__)
const char *str = "ARCHITECTURE IS XCore";
#elif defined(__i386__) || defined(__x86_64__)
const char *str = "ARCHITECTURE IS x86";
#endif

int main(int argc, char **argv) {
    int require = str[argc];
    (void)argv;
    return require;
}
