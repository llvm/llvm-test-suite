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

static bool safe_try_feature(bool (*try_feature)(void), bool is_exempt);

static bool any_fails = false;

#if __HAVE_FUNCTION_MULTI_VERSIONING
#define CHECK(FN_NAME_SUFFIX, FMV_FEATURE, TARGET_GUARD, IS_EXEMPT, BODY) \
    __attribute__((target(#TARGET_GUARD))) \
    static bool try_##FN_NAME_SUFFIX(void) { \
        do \
            BODY \
        while (0); \
        return true; \
    } \
    __attribute__((target_version(#FMV_FEATURE))) \
    static void check_##FN_NAME_SUFFIX(void) { \
        printf("%s\n", #FMV_FEATURE); \
        fflush(stdout); \
        /* non-default versions are never exempt from diagnostics */ \
        if (!safe_try_feature(try_##FN_NAME_SUFFIX, false)) { \
            printf("\tFAIL\n"); \
            any_fails = true; \
        } \
    } \
    __attribute__((target_version("default"))) \
    static void check_##FN_NAME_SUFFIX(void) { \
        printf("%s\n", #FMV_FEATURE); \
        fflush(stdout); \
        /* default versions are allowed to UPASS when IS_EXEMPT = true */ \
        if (safe_try_feature(try_##FN_NAME_SUFFIX, IS_EXEMPT)) { \
            printf("\tUPASS\n"); \
            any_fails = true; \
        } \
    }
#else
#define CHECK(FN_NAME_SUFFIX, FMV_FEATURE, TARGET_GUARD, IS_EXEMPT, BODY) \
    static void check_##FN_NAME_SUFFIX(void) { \
        printf("%s\n", #FMV_FEATURE); \
    }
#endif

CHECK(flagm, flagm, flagm, false, {
    asm volatile (
        "cfinv" "\n"
        "cfinv" "\n"
    );
})
CHECK(flagm2, flagm2, arch=armv8.5-a, false, {
    asm volatile (
        "axflag" "\n"
        "xaflag" "\n"
    );
})
CHECK(dotprod, dotprod, dotprod, false, {
    asm volatile (
        "udot v0.4S,v1.16B,v2.16B"
        : : : "v0"
    );
})
CHECK(sha3, sha3, sha3, false, {
    asm volatile (
        "fmov d0, #0" "\n"
        "fmov d1, #0" "\n"
        "eor3 v0.16b, v0.16b, v0.16b, v0.16b" "\n"
        : : : "v0"
    );
})
CHECK(rdm, rdm, rdm, false, {
    asm volatile (
        "sqrdmlah s0, s1, s2"
        : : : "s0"
    );
})
CHECK(lse, lse, lse, false, {
    uint64_t pointee = 0;
    asm volatile (
        "swp xzr, xzr, [%[pointee]]"
        : : [pointee]"r"(&pointee)
    );
})
CHECK(sha2, sha2, sha2, false, {
    asm volatile (
        "fmov d0, #0" "\n"
        "fmov d1, #0" "\n"
        "sha256h q0, q0, v0.4s" "\n"
        "sha1h s0, s0" "\n"
        : : : "v0"
    );
})
CHECK(aes, aes, aes, false, {
    asm volatile (
        "fmov d0, #0" "\n"
        "fmov d1, #0" "\n"
        "aesd v0.16B, v0.16B" "\n"
        "pmull v0.1q, v0.1d, v0.1d" "\n"
        : : : "v0"
    );
})
CHECK(rcpc, rcpc, rcpc, false, {
    int x;
    asm volatile (
        "ldaprb w0, [%0]"
        : : "r" (&x) : "w0"
    );
})
CHECK(rcpc2, rcpc2, arch=armv8.4-a, false, {
    int x;
    asm volatile (
        "mov x1, %0" "\n"
        "ldapurb w0, [x1]" "\n"
        : : "r" (&x) : "w0", "x1"
    );
})
CHECK(fcma, fcma, fcma, false, {
    asm volatile (
        "fmov d0, #0" "\n"
        "fcadd v0.2s, v0.2s, v0.2s, #90" "\n"
        : : : "v0"
    );
})
CHECK(jscvt, jscvt, jscvt, false, {
    asm volatile (
        "fmov d0, #0" "\n"
        "fjcvtzs w1, d0" "\n"
        : : : "w1", "d0"
    );
})
CHECK(dpb, dpb, arch=armv8.2-a, false, {
    int x;
    asm volatile (
        "dc cvap, %0"
        : : "r" (&x)
    );
})
CHECK(dpb2, dpb2, arch=armv8.5-a, false, {
    int x;
    asm volatile (
        "dc cvadp, %0"
        : : "r" (&x)
    );
})
CHECK(bf16, bf16, bf16, false, {
    asm volatile (
        "bfdot v0.4S,v1.8H,v2.8H"
        : : : "v0"
    );
})
CHECK(i8mm, i8mm, i8mm, false, {
    asm volatile (
        "sudot v0.4S,v1.16B,v2.4B[0]"
        : : : "v0"
    );
})
CHECK(dit, dit, dit, false, {
    asm volatile (
        "msr DIT, x0"
        : : : "x0"
    );
})
CHECK(fp16, fp16, fp16, false, {
    asm volatile (
        "fmov h0, #0"
        : : : "v0"
    );
})
// When running try_ssbs() on hardware which is affected by the "SSBS not fully
// self-synchronizing" errata, the linux kernel mutes the detection of ssbs via
// hardware caps. As a result the default version ends up running the ssbs code
// which was expected to trap originally. Passing IS_EXEMPT = true here allows
// the default version to UPASS.
CHECK(ssbs, ssbs, ssbs, true, {
    asm volatile (
        "mrs x0, SSBS" "\n"
        "msr SSBS, x0" "\n"
        : : : "x0"
    );
})
CHECK(bti, bti, bti, false, {
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
CHECK(simd, simd, simd, false, {
    asm volatile (
        "mov v0.B[0], w0"
        : : :
    );
})
CHECK(fp, fp, fp, false, {
    asm volatile (
        "fmov s0, #0"
        : : : "v0"
    );
})
CHECK(crc, crc, crc, false, {
    asm volatile ( "crc32b wzr, wzr, wzr");
})
CHECK(sme, sme, sme, false, {
    asm volatile (
        "rdsvl x0, #1"
        : : : "x0"
    );
})
CHECK(sme2, sme2, sme2, false, {
    asm volatile (
        "smstart za" "\n"
        "zero { zt0 }" "\n"
        "smstop  za" "\n"
    );
})
CHECK(f32mm, f32mm, f32mm, false, {
    asm volatile (
        "fmmla z0.s, z1.s, z2.s"
        : : : "v0"
    );
})
CHECK(f64mm, f64mm, f64mm, false, {
    asm volatile (
        "fmmla z0.d, z1.d, z2.d"
        : : : "v0"
    );
})
CHECK(fp16fml, fp16fml, fp16fml, false, {
    asm volatile (
        "fmlal v0.2s, v1.2h, v2.2h"
         : : : "v0"
    );
})
CHECK(frintts, frintts, arch=armv8.5-a, false, {
    asm volatile (
        "frint32z s0, s1"
        : : : "v0"
    );
})
CHECK(rcpc3, rcpc3, rcpc3, false, {
    long x;
    asm volatile (
        "stilp wzr, wzr, [%0]"
        : : "r" (&x) : "memory"
    );
})
CHECK(rng, rng, rng, false, {
     asm volatile (
         "mrs x0, rndr" "\n"
         "mrs x1, rndrrs" "\n"
         : : : "x0", "x1"
     );
})
CHECK(sve, sve, sve, false, {
     asm volatile (
         "fadda s0, p7, s0, z31.s"
         : : : "v0"
     );
})
CHECK(sve2, sve2, sve2, false, {
     asm volatile (
         "match p15.b, p7/z, z0.b, z1.b"
         : : : "p15", "cc"
     );
})
CHECK(sve2_aes, sve2-aes, sve2-aes, false, {
     asm volatile (
         "aese z0.b, z0.b, z1.b" "\n"
         "pmullt z2.q, z0.d, z1.d" "\n"
         : : : "z0", "z2"
     );
})
CHECK(sve2_bitperm, sve2-bitperm, sve2-bitperm, false, {
     asm volatile (
         "bext z0.s, z1.s, z2.s"
         : : : "z0"
     );
})
CHECK(sve2_sha3, sve2-sha3, sve2-sha3, false, {
     asm volatile (
         "rax1 z0.d, z1.d, z2.d"
         : : : "z0"
     );
})
CHECK(sve2_sm4, sve2-sm4, sve2-sm4, false, {
     asm volatile (
         "sm4e z0.s, z0.s, z2.s"
         : : : "z0"
     );
})
CHECK(wfxt, wfxt, wfxt, false, {
     asm volatile (
         "wfet x0" "\n"
         "wfit x1" "\n"
     );
})
CHECK(sb, sb, sb, false, {
     asm volatile ("sb");
})
CHECK(sm4, sm4, sm4, false, {
     asm volatile (
         "sm4e v0.4s, v1.4s"
         : : : "v0"
     );
})
CHECK(sme_f64f64, sme-f64f64, sme-f64f64, false, {
     asm volatile (
         "fmops za0.d, p0/m, p0/m, z0.d, z0.d"
         : : : "za"
     );
})
CHECK(sme_i16i64, sme-i16i64, sme-i16i64, false, {
     asm volatile (
         "smopa za0.d, p0/m, p0/m, z0.h, z0.h"
         : : : "za"
     );
})
CHECK(mops, mops, mops, false, {
     long dst[64];
     long src[64];
     size_t n = 32;
     long *to = dst;
     long *from = src;
     asm volatile (
         "cpyfp [%0]!, [%1]!, %2!" "\n"
         "cpyfm [%0]!, [%1]!, %2!" "\n"
         "cpyfe [%0]!, [%1]!, %2!" "\n"
         : "+r" (to), "+r" (from), "+r" (n)
         : : "cc", "memory"
     );
})
// We can't use any FEAT_MTE2 instruction in this test since they are undefined
// at EL0. Therefore passing IS_EXEMPT = true here allows the default version to
// UPASS on a system which doesn't have FEAT_MTE2 but has FEAT_MTE.
CHECK(memtag, memtag, memtag, true, {
    asm volatile (
        "irg x0, sp"
        : : : "x0"
    );
})
CHECK(cssc, cssc, cssc, false, {
    asm volatile (
        "cnt x0, x1"
        : : : "x0"
    );
})

static bool safe_try_feature(bool (*try_feature)(void), bool is_exempt) {
    int child = fork();
    if (child) {
        int exit_status = -1;
        if (child != waitpid(child, &exit_status, 0))
            return false;
        return exit_status == 0;
    } else {
        exit((try_feature() && !is_exempt) ? EXIT_SUCCESS : EXIT_FAILURE);
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
    check_aes();
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
    check_ssbs();
    check_bti();
    check_simd();
    check_fp();
    check_crc();
    check_sme();
    check_sme2();
    check_f32mm();
    check_f64mm();
    check_fp16fml();
    check_frintts();
    check_rcpc3();
    check_rng();
    check_sve();
    check_sve2();
    check_sve2_aes();
    check_sve2_bitperm();
    check_sve2_sha3();
    check_sve2_sm4();
    check_wfxt();
    check_sb();
    check_sm4();
    check_sme_f64f64();
    check_sme_i16i64();
    check_mops();
    check_memtag();
    check_cssc();

    return any_fails ? -1 : 0;
}
