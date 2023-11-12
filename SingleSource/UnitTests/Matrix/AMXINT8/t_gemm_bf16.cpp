#include <immintrin.h>
#include <string.h>
#include <cassert>
#include <iostream>


#define TILE_SZ 16
__attribute__((noinline))
void inner_product2(int *A_mem, int *B_mem, int *C_mem, int M, int N, int K) {
  // tiling
  const int m = M / TILE_SZ;
  const int n = N / TILE_SZ;
  const int k = K / TILE_SZ;

  assert(!(M % TILE_SZ) && !(N % TILE_SZ) && !(K % TILE_SZ));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      __tile1024i c = {TILE_SZ, TILE_SZ*sizeof(int)};
      __tile_zero(&c);
      for (int l = 0; l < k; l++) {
        __tile1024i a = {TILE_SZ, TILE_SZ*sizeof(int)};
        __tile1024i b = {TILE_SZ, TILE_SZ*sizeof(int)};
        __tile_loadd(&a, A_mem+(i*TILE_SZ)*K+l*TILE_SZ, K*sizeof(int));
        __tile_loadd(&b, B_mem+(l*TILE_SZ)*N+j*TILE_SZ, N*sizeof(int));
        __tile_dpbf16ps(&c, a, b);
      }
      __tile_stored(C_mem+(i*TILE_SZ)*M+j*TILE_SZ, N*sizeof(int), c);
    }
}

#define TILE_M 16
#define TILE_N 16
#define TILE_K 16
#define M_ACC 2
#define N_ACC 2
#define KPACK 1
typedef int type_t;
typedef int res_type_t;

template <short Row, short Col>
class Tile {
public:
  __tile1024i& getTile() {
    return tile;
  }
private:
  __tile1024i tile {Row, Col*sizeof(int)};
};

template <short Row, short Col>
static void tilezero(Tile<Row, Col> &tile) {
  __tile_zero(&tile.getTile());
}

template <short Row, short Col>
static void tileload(Tile<Row, Col> &dst, const void *base, size_t stride) {
  __tile_loadd(&dst.getTile(), base, stride);
}

template <short Row, short Col>
static void tdp(Tile<Row, Col> &dst, Tile<Row, Col> src1, Tile<Row, Col> src2) {
  __tile_dpbf16ps(&dst.getTile(), src1.getTile(), src2.getTile());
}

template <short Row, short Col>
void tilestore(Tile<Row, Col> &src, void *base, size_t stride) {
  __tile_stored(base, stride, src.getTile());
}

__attribute__((noinline))
void inner_product(int *A_mem, int *B_mem, int *C_mem, int M, int N, int K) {
  // tiling
  assert(M%(TILE_M*M_ACC) == 0 && N%(TILE_N*N_ACC) == 0 && K%TILE_K == 0);
  for (int n = 0; n < N; n += N_ACC*TILE_N) {
    for (int m = 0; m < M; m += M_ACC*TILE_M) {
      Tile<TILE_M, TILE_N> tC[M_ACC][N_ACC];
      Tile<TILE_M, TILE_K> tA[M_ACC];
      Tile<TILE_K, TILE_N> tB;

      for (int n_acc = 0; n_acc < N_ACC; ++n_acc)
        for (int m_acc = 0; m_acc < M_ACC; ++m_acc)
          tilezero(tC[m_acc][n_acc]);

      for (int k = 0; k < K; k += TILE_K) {
        for (int n_acc = 0; n_acc < N_ACC; ++n_acc) {
          tileload(tB, B_mem+k*N+n+n_acc*TILE_N, N*sizeof(type_t)*KPACK);
          for (int m_acc = 0; m_acc < M_ACC; ++m_acc) {
            if (n_acc == 0)
              tileload(tA[m_acc], A_mem+(m + m_acc*TILE_M)*K+k, K*sizeof(type_t));
            tdp(tC[m_acc][n_acc], tA[m_acc], tB);
            if (k == K - TILE_K) {
              int mc = m + m_acc*TILE_M, nc = n + n_acc*TILE_N;
              tilestore(tC[m_acc][n_acc], C_mem+mc*N+nc, N*sizeof(res_type_t));
            }
          }
        }
      }
    }
  } 
}

float make_fp32(short x)
{
  unsigned int y = x;
  y = y << 16;
  float *res = reinterpret_cast<float*>(&y);
  return *res;
}

unsigned short make_bf16(float x)
{
  int *res = reinterpret_cast<int*>(&x);
  *res = *res >> 16;
  return (unsigned short)*res;
}

void inner_product_ref(int *A_mem, int *B_mem, int *C_mem, int M, int N, int K) {
  // tiling
  for (int m = 0; m < M; m++)
    for (int n = 0; n < N; n++) {
      for (int k = 0; k < K; k++) {
        short *va = (short *)(A_mem + m*K + k);
        short *vb = (short *)(B_mem + k*N + n);
        float acc = *((float*)(C_mem + m*N + n));
        for (int i = 0; i < 2; i++) {
          acc += (make_fp32(va[i]) * make_fp32(vb[i]));
        }
        *((float*)(C_mem + m*N + n))= acc;
      }
    }
}

#define SIZE 128 
int gA[SIZE][SIZE], gB[SIZE][SIZE], gC[SIZE][SIZE], gD[SIZE][SIZE];
int main() {
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++) {
      unsigned short *pAbh = (unsigned short *)&gA[i][j];
      *pAbh = make_bf16(0.1f * (i+j));
      *(pAbh+1) = make_bf16(0.1f * (i+j));
      unsigned short *pBbh = (unsigned short *)&gB[i][j];
      *pBbh = make_bf16(0.1f * (i+j));
      *(pBbh+1) = make_bf16(0.1f * (i+j));
    }

  inner_product_ref((int *)gA, (int *)gB, (int *)gC, SIZE, SIZE, SIZE);
  inner_product((int *)gA, (int *)gB, (int *)gD, SIZE, SIZE, SIZE);
  int err_num = memcmp(gC, gD, sizeof(gC))?1:0;
  inner_product2((int *)gA, (int *)gB, (int *)gD, SIZE, SIZE, SIZE);
  err_num = memcmp(gC, gD, sizeof(gC))?(1+err_num):err_num;
  if (err_num == 0)
    std::cout << "PASSED\n";
  else
    std::cout << "FAILED\n";
}

