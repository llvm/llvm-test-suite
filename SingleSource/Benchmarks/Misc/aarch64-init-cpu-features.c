#include <stdio.h>

extern struct {
  unsigned long long features;
} __aarch64_cpu_features;

#if HAS_DARWIN_FMV
# define RUNTIME_INIT __init_cpu_features_resolver
#elif HAS_LINUX_FMV
# define RUNTIME_INIT __init_cpu_features
#endif

void RUNTIME_INIT(void);

int main() {
    RUNTIME_INIT();
    const unsigned long long first = __aarch64_cpu_features.features;

    // Manually reset it, so we can check that the result is consistent.
    __aarch64_cpu_features.features = 0;
    RUNTIME_INIT();

    if (__aarch64_cpu_features.features != first) {
        printf("FAILED consistency test: 0x%llx != 0x%llx\n", first,
               __aarch64_cpu_features.features);
        return 1;
    }

    // At 1,000,000 iterations, the reported exec_time doubles as a
    // per-iteration measurement in microseconds.
    for (int i = 0; i < 1000000; i++) {
        __aarch64_cpu_features.features = 0;
        RUNTIME_INIT();
    }
}
