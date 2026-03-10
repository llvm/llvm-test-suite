// pgo-tiled-matmul.hip - Tiled matmul kernel for offload PGO E2E testing
//
// This test demonstrates how Profile-Guided Optimization (PGO) improves
// GPU kernel performance by reducing register spills on hot code paths.
//
// == What the kernel does ==
//
// The kernel performs a grouped batched matrix multiply (C = A × B) using
// a tiled algorithm, similar to how high-performance GPU libraries like
// AMD's Composable Kernel (CK) implement convolution and GEMM operations.
//
// Each GPU thread block has 32 threads (one wavefront) and handles a
// 128×64 tile of the output matrix. Each thread computes a 16×16
// sub-tile of the output, accumulating 256 partial sums across
// K-dimension tile iterations. The threads cooperatively load input
// tiles into shared memory (LDS).
//
// The single-wavefront configuration (32 threads) is chosen because it
// achieves higher throughput than 256 threads due to better LDS
// utilization and fewer wasted boundary threads. This also matches the
// occupancy pattern of high-performance GPU kernels like CK's
// grouped_conv_bwd_weight, which runs at 1 wave/SIMD with all VGPRs
// utilized.
//
// The matrix dimensions (default 1000×1000) intentionally do not divide
// evenly into tiles, creating two code paths:
//   - Interior tiles (majority): fast path with unconditional memory loads
//   - Boundary tiles (edges): slow path with per-element bounds checking
//
// == Why PGO helps ==
//
// The 256 float accumulators per thread (plus temporary registers for
// loading from LDS) exceed the GPU's 256-VGPR register file, forcing the
// compiler to "spill" some register values to slower scratch memory.
//
// Without PGO, the compiler has no information about which code path runs
// more often, so it makes register allocation decisions without favoring
// either path. This can result in hot-path values being spilled.
//
// With PGO (-fprofile-generate / -fprofile-use), the compiler learns from
// runtime profile data that interior tiles execute ~2x more often than
// boundary tiles. The register allocator then prioritizes keeping the
// hot interior path's values in registers, spilling the cold boundary
// path's values instead. Fewer spills on the hot path means fewer slow
// scratch memory accesses during the majority of the kernel's execution.
//
// The kernel structure mirrors real workloads like CK's
// grouped_conv_bwd_weight kernel.
//
// == Usage ==
//
//   ./pgo-tiled-matmul <M> <N> <K> <groups> <runs> <verify>
//   ./pgo-tiled-matmul 1000 1000 500 4 5 1
//
// == Full PGO pipeline ==
//
//   # 1. Build instrumented binary
//   clang++ -O3 --offload-arch=gfx1100 -x hip \
//       -fprofile-generate=./profiles pgo-tiled-matmul.hip -o pgo_gen
//
//   # 2. Run to collect device profiles
//   ./pgo_gen 1000 1000 500 4 1 0
//
//   # 3. Merge device profiles
//   llvm-profdata merge -o device.profdata profiles/*.gfx1100.*.profraw
//
//   # 4. Build PGO-optimized binary
//   clang++ -O3 --offload-arch=gfx1100 -x hip \
//       -Xarch_device -fprofile-use=device.profdata \
//       pgo-tiled-matmul.hip -o pgo_use
//
//   # 5. Compare: ./pgo_use should be faster than baseline

#include <hip/hip_runtime.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>

// Sub-tile dimensions are configurable via -D flags to tune register
// pressure per GPU architecture:
//   gfx1100 (256 VGPRs): default TH_M=16, TH_N=16 → 256 accumulators → spills
//   gfx950  (512 VGPRs): -DTH_M=20 -DTH_N=16 → 320 accumulators → spills
#ifndef TH_M
#define TH_M 16
#endif
#ifndef TH_N
#define TH_N 16
#endif
#ifndef TILE_M
#define TILE_M (TH_M * 8)
#endif
#ifndef TILE_N
#define TILE_N (TH_N * 4)
#endif
#define TILE_K 8
#define THREADS_M (TILE_M / TH_M)
#define THREADS_N (TILE_N / TH_N)
#define BLOCK_SIZE (THREADS_M * THREADS_N)

__global__ __launch_bounds__(BLOCK_SIZE)
void tiled_matmul_kernel(
    const float* __restrict__ A,
    const float* __restrict__ B,
    float* __restrict__ C,
    int M, int N, int K
) {
    int group = blockIdx.z;
    int tile_row = blockIdx.y;
    int tile_col = blockIdx.x;

    int tid = threadIdx.x;
    int tr = tid / THREADS_N;
    int tc = tid % THREADS_N;

    int row_base = tile_row * TILE_M + tr * TH_M;
    int col_base = tile_col * TILE_N + tc * TH_N;

    __shared__ float sA[TILE_M][TILE_K];
    __shared__ float sB[TILE_K][TILE_N];

    float acc[TH_M][TH_N];
    #pragma unroll
    for (int i = 0; i < TH_M; i++)
        #pragma unroll
        for (int j = 0; j < TH_N; j++)
            acc[i][j] = 0.0f;

    size_t plane_a = (size_t)M * K;
    size_t plane_b = (size_t)K * N;
    size_t plane_c = (size_t)M * N;
    const float* A_g = A + (size_t)group * plane_a;
    const float* B_g = B + (size_t)group * plane_b;

    bool tile_bnd_row = ((tile_row + 1) * TILE_M > M);
    bool tile_bnd_col = ((tile_col + 1) * TILE_N > N);

    for (int kt = 0; kt < K; kt += TILE_K) {
        bool tile_bnd_k = (kt + TILE_K > K);

        if (!tile_bnd_row && !tile_bnd_k) {
            for (int i = tid; i < TILE_M * TILE_K; i += BLOCK_SIZE) {
                int r = i / TILE_K;
                int c = i % TILE_K;
                sA[r][c] = A_g[(tile_row * TILE_M + r) * K + kt + c];
            }
        } else {
            for (int i = tid; i < TILE_M * TILE_K; i += BLOCK_SIZE) {
                int r = i / TILE_K;
                int c = i % TILE_K;
                int gr = tile_row * TILE_M + r;
                int gc = kt + c;
                sA[r][c] = (gr < M && gc < K) ? A_g[gr * K + gc] : 0.0f;
            }
        }

        if (!tile_bnd_col && !tile_bnd_k) {
            for (int i = tid; i < TILE_K * TILE_N; i += BLOCK_SIZE) {
                int r = i / TILE_N;
                int c = i % TILE_N;
                sB[r][c] = B_g[(kt + r) * N + tile_col * TILE_N + c];
            }
        } else {
            for (int i = tid; i < TILE_K * TILE_N; i += BLOCK_SIZE) {
                int r = i / TILE_N;
                int c = i % TILE_N;
                int gr = kt + r;
                int gc = tile_col * TILE_N + c;
                sB[r][c] = (gr < K && gc < N) ? B_g[gr * N + gc] : 0.0f;
            }
        }

        __syncthreads();

        #pragma unroll
        for (int kk = 0; kk < TILE_K; kk++) {
            float a_reg[TH_M];
            float b_reg[TH_N];

            #pragma unroll
            for (int rm = 0; rm < TH_M; rm++)
                a_reg[rm] = sA[tr * TH_M + rm][kk];
            #pragma unroll
            for (int rn = 0; rn < TH_N; rn++)
                b_reg[rn] = sB[kk][tc * TH_N + rn];

            #pragma unroll
            for (int rm = 0; rm < TH_M; rm++)
                #pragma unroll
                for (int rn = 0; rn < TH_N; rn++)
                    acc[rm][rn] += a_reg[rm] * b_reg[rn];
        }

        __syncthreads();
    }

    float* C_g = C + (size_t)group * plane_c;
    bool out_bnd_row = (row_base + TH_M > M);
    bool out_bnd_col = (col_base + TH_N > N);

    if (!out_bnd_row && !out_bnd_col) {
        #pragma unroll
        for (int rm = 0; rm < TH_M; rm++)
            #pragma unroll
            for (int rn = 0; rn < TH_N; rn++)
                C_g[(row_base + rm) * N + col_base + rn] = acc[rm][rn];
    } else {
        for (int rm = 0; rm < TH_M; rm++)
            for (int rn = 0; rn < TH_N; rn++)
                if (row_base + rm < M && col_base + rn < N)
                    C_g[(row_base + rm) * N + col_base + rn] = acc[rm][rn];
    }
}

void matmul_ref(const float* A, const float* B, float* C,
                int M, int N, int K, int groups) {
    for (int g = 0; g < groups; g++) {
        const float* Ag = A + (size_t)g * M * K;
        const float* Bg = B + (size_t)g * K * N;
        float* Cg = C + (size_t)g * M * N;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                double sum = 0.0;
                for (int k = 0; k < K; k++)
                    sum += (double)Ag[i * K + k] * (double)Bg[k * N + j];
                Cg[i * N + j] = (float)sum;
            }
    }
}

int main(int argc, char** argv) {
    int M = (argc > 1) ? atoi(argv[1]) : 1000;
    int N = (argc > 2) ? atoi(argv[2]) : 1000;
    int K = (argc > 3) ? atoi(argv[3]) : 500;
    int groups = (argc > 4) ? atoi(argv[4]) : 4;
    int runs = (argc > 5) ? atoi(argv[5]) : 5;
    int verify = (argc > 6) ? atoi(argv[6]) : 1;

    size_t elems_A = (size_t)groups * M * K;
    size_t elems_B = (size_t)groups * K * N;
    size_t elems_C = (size_t)groups * M * N;

    float *h_A = (float*)malloc(elems_A * sizeof(float));
    float *h_B = (float*)malloc(elems_B * sizeof(float));
    float *h_C = (float*)malloc(elems_C * sizeof(float));
    float *h_ref = verify ? (float*)malloc(elems_C * sizeof(float)) : nullptr;

    srand(42);
    for (size_t i = 0; i < elems_A; i++)
        h_A[i] = (float)(rand() % 20 - 10) / 50.0f;
    for (size_t i = 0; i < elems_B; i++)
        h_B[i] = (float)(rand() % 20 - 10) / 50.0f;

    float *d_A, *d_B, *d_C;
    hipMalloc(&d_A, elems_A * sizeof(float));
    hipMalloc(&d_B, elems_B * sizeof(float));
    hipMalloc(&d_C, elems_C * sizeof(float));
    hipMemcpy(d_A, h_A, elems_A * sizeof(float), hipMemcpyHostToDevice);
    hipMemcpy(d_B, h_B, elems_B * sizeof(float), hipMemcpyHostToDevice);

    int tiles_m = (M + TILE_M - 1) / TILE_M;
    int tiles_n = (N + TILE_N - 1) / TILE_N;
    dim3 grid(tiles_n, tiles_m, groups);
    dim3 block(BLOCK_SIZE);

    tiled_matmul_kernel<<<grid, block>>>(d_A, d_B, d_C, M, N, K);
    hipDeviceSynchronize();

    if (verify) {
        hipMemcpy(h_C, d_C, elems_C * sizeof(float), hipMemcpyDeviceToHost);
        matmul_ref(h_A, h_B, h_ref, M, N, K, groups);
        float max_err = 0.0f;
        int errors = 0;
        float tol = 5e-2f + K * 1e-3f;
        for (size_t i = 0; i < elems_C; i++) {
            float diff = fabsf(h_C[i] - h_ref[i]);
            float denom = fmaxf(fabsf(h_ref[i]), 1e-6f);
            float rel = diff / denom;
            if (rel > max_err) max_err = rel;
            if (rel > tol) errors++;
        }
        if (errors != 0) {
            printf("%d errors (max_rel_err=%.6f tol=%.4f)\n", errors, max_err, tol);
            free(h_A); free(h_B); free(h_C); free(h_ref);
            hipFree(d_A); hipFree(d_B); hipFree(d_C);
            return 1;
        }
    }

    if (runs > 0) {
        hipEvent_t start, stop;
        hipEventCreate(&start);
        hipEventCreate(&stop);

        float total_ms = 0.0f;
        for (int r = 0; r < runs; r++) {
            hipEventRecord(start);
            tiled_matmul_kernel<<<grid, block>>>(d_A, d_B, d_C, M, N, K);
            hipEventRecord(stop);
            hipEventSynchronize(stop);
            float ms;
            hipEventElapsedTime(&ms, start, stop);
            total_ms += ms;
        }
        float avg_ms = total_ms / runs;
        double gflops = 2.0 * groups * M * N * K / (avg_ms * 1e-3) / 1e9;
        printf("Average: %.3f ms, %.1f GFLOPS\n", avg_ms, gflops);

        hipEventDestroy(start);
        hipEventDestroy(stop);
    }

    printf("PASSED!\n");

    hipFree(d_A); hipFree(d_B); hipFree(d_C);
    free(h_A); free(h_B); free(h_C); free(h_ref);
    return 0;
}
