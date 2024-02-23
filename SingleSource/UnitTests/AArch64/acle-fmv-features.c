#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#ifdef __APPLE__
#include <sys/sysctl.h>
#endif

static bool safe_try_feature(bool (*try_feature)(void));

static bool any_fails = false;

#if __HAVE_FUNCTION_MULTI_VERSIONING
#define CHECK(X, BODY) \
    __attribute__((target(#X))) \
    static bool try_##X(void) { \
        do \
            BODY \
        while (0); \
        return true; \
    } \
    __attribute__((target_version(#X))) \
    static void check_##X(void) { \
        printf("%s\n", #X); \
        fflush(stdout); \
        if (!safe_try_feature(try_##X)) { \
            printf("\tFAIL\n"); \
            any_fails = true; \
        } \
    } \
    __attribute__((target_version("default"))) \
    static void check_##X(void) { \
        printf("%s\n", #X); \
        fflush(stdout); \
        if (safe_try_feature(try_##X)) { \
            printf("\tUPASS\n"); \
            any_fails = true; \
        } \
    }
#else
#define CHECK(X, BODY) \
    static void check_##X(void) { \
        printf("%s\n", #X); \
    }
#endif

CHECK(flagm, {
    asm volatile (
        "cfinv" "\n"
        "cfinv" "\n"
    );
})
CHECK(flagm2, {
    asm volatile (
        "axflag" "\n"
        "xaflag" "\n"
    );
})
CHECK(dotprod, {
    asm volatile (
        "udot v0.4S,v1.16B,v2.16B"
        : : : "v0"
    );
})
CHECK(sha3, {
    asm volatile (
        "fmov d0, #0" "\n"
        "fmov d1, #0" "\n"
        "eor3 v0.16b, v0.16b, v0.16b, v0.16b" "\n"
        : : : "v0"
    );
})
CHECK(rdm, {
    asm volatile (
        "sqrdmlah s0, s1, s2"
        : : : "s0"
    );
})
CHECK(lse, {
    uint64_t pointee = 0;
    asm volatile (
        "swp xzr, xzr, [%[pointee]]"
        : : [pointee]"r"(&pointee)
    );
})
CHECK(sha2, {
    asm volatile (
        "fmov d0, #0" "\n"
        "fmov d1, #0" "\n"
        "sha256h q0, q0, v0.4s" "\n"
        : : : "v0"
    );
})
CHECK(sha1, {
    asm volatile (
        "fmov s0, #0" "\n"
        // FIXME: sha1h is under +sha2 in clang, and +sha1 doesn't exist yet.
        ".inst 0x5e280800" "\n" // sha1h s0, s0
        : : : "v0"
    );
})
CHECK(aes, {
    asm volatile (
        "fmov d0, #0" "\n"
        "fmov d1, #0" "\n"
        "aesd v0.16B, v0.16B" "\n"
        : : : "v0"
    );
})
CHECK(pmull, {
    asm volatile (
        "fmov d0, #0" "\n"
        "pmull v0.1q, v0.1d, v0.1d" "\n"
        : : : "v0"
    );
})
CHECK(rcpc, {
    int x;
    asm volatile (
        "ldaprb w0, [%0]"
        : : "r" (&x) : "w0"
    );
})
CHECK(rcpc2, {
    int x;
    asm volatile (
        "mov x1, %0" "\n"
        // FIXME: rcpc2 instructions are under +rcpc-immo in clang, and not +rcpc2.
        ".inst 0x19400020" // ldapurb w0, [x1]
        : : "r" (&x) : "w0"
    );
})
CHECK(fcma, {
    asm volatile (
        "fmov d0, #0" "\n"
        "fcadd v0.2s, v0.2s, v0.2s, #90" "\n"
        : : : "v0"
    );
})
CHECK(jscvt, {
    asm volatile (
        "fmov d0, #0" "\n"
        "fjcvtzs w1, d0" "\n"
        : : : "w1", "d0"
    );
})
CHECK(dpb, {
    int x;
    asm volatile (
        "dc cvap, %0"
        : : "r" (&x)
    );
})
CHECK(dpb2, {
    int x;
    asm volatile (
        "dc cvadp, %0"
        : : "r" (&x)
    );
})
CHECK(bf16, {
    asm volatile (
        "bfdot v0.4S,v1.8H,v2.8H"
        : : : "v0"
    );
})
CHECK(i8mm, {
    asm volatile (
        "sudot v0.4S,v1.16B,v2.4B[0]"
        : : : "v0"
    );
})
CHECK(dit, {
    asm volatile (
        "msr DIT, x0"
        : : : "x0"
    );
})
CHECK(fp16, {
    asm volatile (
        "fmov h0, #0"
        : : : "v0"
    );
})
CHECK(ssbs2, {
    asm volatile (
        "mrs x0, SSBS" "\n"
        "msr SSBS, x0" "\n"
        : : : "x0"
    );
})
CHECK(bti, {
    // The only test for this requires reading a register that is only
    // accessible to EL1.
    #ifdef __linux__
        // On linux, the kernel intercepts the trap, and emulates it for EL0 processes.
        int val = 0;
        asm volatile("mrs %0, ID_AA64PFR1_EL1" : "=r"(val));
        // ID_AA64PFR1_EL1.BT, bits [3:0] = 0b0001 if Branch Target Identification
        // mechanism implemented.
        if ((val & 0xF) != 0x1)
          return false;
    #elif defined(__APPLE__)
        // On Apple platforms, we need to check a sysctl.
        int32_t val = 0;
        size_t size = sizeof(val);
        if (sysctlbyname("hw.optional.arm.FEAT_BTI", &val, &size, NULL, 0) || val != 1)
            return false;
    #else
        // TODO: implement me on your platform to fix this test!
    #endif
})
CHECK(simd, {
    asm volatile (
        "mov v0.B[0], w0"
        : : :
    );
})
CHECK(fp, {
    asm volatile (
        "fmov s0, #0"
        : : : "v0"
    );
})
CHECK(crc, {
    asm volatile ( "crc32b wzr, wzr, wzr");
})
CHECK(sme, {
    asm volatile (
        "rdsvl x0, #1"
        : : : "x0"
    );
})
CHECK(sme2, {
    asm volatile (
        "smstart za" "\n"
        "zero { zt0 }" "\n"
        "smstop  za" "\n"
    );
})

static bool safe_try_feature(bool (*try_feature)(void)) {
    int child = fork();
    if (child) {
        int exit_status = -1;
        if (child != waitpid(child, &exit_status, 0))
            return false;
        return exit_status == 0;
    } else {
        exit(try_feature() ? 0 : 1);
    }
}

int main(int, const char **) {
    check_flagm();
    check_flagm2();
    check_dotprod();
    check_sha3();
    check_rdm();
    check_lse();
    check_sha2();
    check_sha1();
    check_aes();
    check_pmull();
    check_rcpc();
    check_rcpc2();
    check_fcma();
    check_jscvt();
    check_dpb();
    check_dpb2();
    check_bf16();
    check_i8mm();
    check_dit();
    check_fp16();
    check_ssbs2();
    check_bti();
    check_simd();
    check_fp();
    check_crc();
    check_sme();
    check_sme2();

    return any_fails ? -1 : 0;
}
