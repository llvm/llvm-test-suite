#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <iostream>

#include "common.h"

template <typename Ty>
using Fn4Ty = std::function<Ty(bool *, bool *, Ty *, Ty *, unsigned, int)>;

template <typename Ty>
static void checkVectorFunction(Fn4Ty<Ty> ScalarFn, Fn4Ty<Ty> VectorFn,
                                const char *Name) {
  std::cout << "Checking " << Name << "\n";

  unsigned N = 1000;
  std::unique_ptr<bool[]> Cond0(new bool[N]);
  std::unique_ptr<bool[]> Cond1(new bool[N]);
  std::unique_ptr<Ty[]> Data0(new Ty[N]);
  std::unique_ptr<Ty[]> Data1(new Ty[N]);
  init_cond(Cond0, N);
  init_cond(Cond1, N);
  init_data(Data0, N);
  init_data(Data1, N);
  int X = 10;
  
  Ty Reference = ScalarFn(&Cond0[0], &Cond1[0], &Data0[0], &Data1[0], N, X);
  Ty ToCheck = VectorFn(&Cond0[0], &Cond1[0], &Data0[0], &Data1[0], N, X);
  check(Reference, ToCheck, N);
}

int main(void) {
  rng = std::mt19937(15);

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      int t = -1;,
      for (int i = 0; i < N; i++) {
        if (x < data0[i])
          t = data0[i];
      }
      return t;);
    checkVectorFunction<uint32_t>(ScalarFn, VectorFn, "simple_csa_int_select");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      int t = -1;,
      for (int i = 0; i < N; i++) {
        if (i < data0[i])
          t = data0[i];
      }
      return t;);
    checkVectorFunction<uint32_t>(ScalarFn, VectorFn,
                                  "simple_csa_int_select_induction_cmp");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      float t = 1.0f;,
      for (int i = 0; i < N; i++) {
        if (0.0f < data0[i])
          t = data0[i];
      }
      return t; // use t
    );
    checkVectorFunction<float>(ScalarFn, VectorFn, "simple_csa_float_select");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      int t = -1;,
      for (int i = 0; i < N; i++) {
        if (cond0[i])
          t = data0[i];
      }
      return t; // use t
    );
    checkVectorFunction<uint32_t>(ScalarFn, VectorFn, "simple_csa_int");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      float t = 1.0f;,
      for (int i = 0; i < N; i++) {
        if (cond0[i])
          t = data0[i];
      }
      return t; // use t
    );
    checkVectorFunction<float>(ScalarFn, VectorFn, "simple_csa_float");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      int t = -1; int s = -1;,
      for (int i = 0; i < N; i++) {
        if (x < data0[i])
          t = data0[i];
        if (x < data1[i])
          s = data1[i];
      }
      return t | s; // use t and s
    );
    checkVectorFunction<uint32_t>(ScalarFn, VectorFn,
                                  "csa_in_series_int_select");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      int t = -1; int s = -1;,
      for (int i = 0; i < N; i++) {
        if (i < data0[i])
          t = data0[i];
        if (i < data1[i])
          s = data1[i];
      }
      return t | s; // use t and s
    );
    checkVectorFunction<uint32_t>(ScalarFn, VectorFn,
                                  "csa_in_series_int_select_induction_cmp");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      float t = 1.0f; float s = 1.0f;,
      for (int i = 0; i < N; i++) {
        if (0.0f < data0[i])
          t = data0[i];
        if (0.0f < data1[i])
          s = data1[i];
      }
      return t + s; // use t and s
    );
    checkVectorFunction<float>(ScalarFn, VectorFn,
                               "csa_in_series_float_select");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      int t = -1; int s = -1;,
      for (int i = 0; i < N; i++) {
        if (cond0[i])
          t = data0[i];
        if (cond1[i])
          s = data1[i];
      }
      return t | s; // use t and s
    );
    checkVectorFunction<uint32_t>(ScalarFn, VectorFn, "csa_in_series_int");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      float t = 1.0f; float s = 1.0f;,
      for (int i = 0; i < N; i++) {
        if (cond0[i])
          t = data0[i];
        if (cond1[i])
          s = data1[i];
      }
      return t + s; // use t and s
    );
    checkVectorFunction<float>(ScalarFn, VectorFn, "csa_in_series_float");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      int t = -1;,
      for (int i = 0; i < N; i++) {
        if (cond0[i])
          t = data0[i];
        if (cond1[i])
          t = data1[i];
      }
      return t; // use t
    );
    checkVectorFunction<uint32_t>(ScalarFn, VectorFn,
                                  "csa_in_series_same_scalar_int");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      float t = 1.0f;,
      for (int i = 0; i < N; i++) {
        if (0.0f < data0[i])
          t = data0[i];
        if (0.0f < data1[i])
          t = data1[i];
      }
      return t; // use t
    );
    checkVectorFunction<uint32_t>(ScalarFn, VectorFn,
                                  "csa_in_series_same_scalar_float_select");
  }


  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      float t = 1.0f;,
      for (int i = 0; i < N; i++) {
        if (cond0[i])
          t = data0[i];
        if (cond1[i])
          t = data1[i];
      }
      return t; // use t
    );
    checkVectorFunction<uint32_t>(ScalarFn, VectorFn,
                                  "csa_in_series_same_scalar_float");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      int t = -1; int s = -1;,
      for (int i = 0; i < N; i++) {
        if (cond0[i]) {
          t = data0[i];
          s = data1[i];
        }
      }
      return t | s; // use t and s
    );
    checkVectorFunction<uint32_t>(ScalarFn, VectorFn, "csa_same_cond_int");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      float t = 1.0f; float s = 1.0f;,
      for (int i = 0; i < N; i++) {
        if (cond0[i]) {
          t = data0[i];
          s = data1[i];
        }
      }
      return t + s; // use t and s
    );
    checkVectorFunction<float>(ScalarFn, VectorFn, "csa_same_cond_float");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      int t = -1;,
      for (int i = 0; i < N; i++) {
        if (cond0[i])
          t = data0[i];
        else if (cond1[i])
          t = data1[i];
      }
      return t; // use t
    );
    checkVectorFunction<uint32_t>(ScalarFn, VectorFn,
                                  "csa_else_if_same_scalar_int");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      float t = 1.0f;,
      for (int i = 0; i < N; i++) {
        if (cond0[i])
          t = data0[i];
        else if (cond1[i])
          t = data1[i];
      }
      return t; // use t
    );
    checkVectorFunction<float>(ScalarFn, VectorFn,
                               "csa_else_if_same_scalar_float");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
       int t = -1; int s = -1;,
       for (int i = 0; i < N; i++) {
         if (cond0[i])
           t = data0[i];
         else if (cond1[i])
           s = data1[i];
       }
       return t | s; // use t and s
    );
    checkVectorFunction<uint32_t>(ScalarFn, VectorFn, "csa_else_if_int");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      float t = 1.0f; float s = 1.0f;,
      for (int i = 0; i < N; i++) {
        if (cond0[i])
          t = data0[i];
        else if (cond1[i])
          s = data1[i];
      }
      return t + s; // use t and s
    );
    checkVectorFunction<float>(ScalarFn, VectorFn, "csa_else_if_float");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      int *t = nullptr;,
      for (int i = 0; i < N; i++) {
        if (x < *data0[i])
          t = data0[i];
      }
      return t; // use t
    );
    checkVectorFunction<int *>(ScalarFn, VectorFn, "simple_csa_ptr_select");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      int *t = nullptr;,
      for (int i = 0; i < N; i++) {
        if (x < *data0[i])
          t = data0[i];
      }
      return t; // use t
    );
    checkVectorFunction<int*>(ScalarFn, VectorFn,
                               "simple_csa_ptr_select_induction_cmp");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN4(
      int t = 0;,
      for (int i = 0; i < N; i++) {
        if (x != data0[i])
          t = data0[i];
      }
      return t; // use t
    );
    checkVectorFunction<float>(ScalarFn, VectorFn,
                               "simple_csa_int_select_neg_cond");
  }

  return 0;
}
