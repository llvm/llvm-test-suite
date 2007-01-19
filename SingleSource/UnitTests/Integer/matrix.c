
// Date: Fri Jan 12 17:32:33 CST 2007
#include "matrix.h"
#include <stdio.h>

typedef enum bool{false=0, true=1} bool;

// Module | Test
// Thread: int my_test(sc_int<17> A[8][8], sc_int<17> B[8][8] );
int my_test(int17  A[8][8], int17  B[8][8]){
{
  unsigned int i, j, k;
  int17 C[8];
  int t;
  {
  i = 0;
  for ( ; ; ) {
  bool ssdm_tmp_1 = (i < 8);
  if (!ssdm_tmp_1) break;
    {
    j = 0;
    for ( ; ; ) {
    bool ssdm_tmp_2 = (j < 8);
    if (!ssdm_tmp_2) break;
      {
        {
        k = 0;
        for ( ; ; ) {
        bool ssdm_tmp_3 = (k < 8);
        if (!ssdm_tmp_3) break;
          A[i][j] = A[i][k] * B[j][k];
        ++k;
        }
        }
        sort(A[i], C);
        t = get_gcd(C[0], C[1]);
        printf("t=%d\n", t);
      }
    ++j;
    }
    }
  ++i;
  }
  }
  return 0;
}
}
// Thread: int get_gcd(const int& a, const int& b);
int get_gcd(const int  a, const int  b){
{
  if (b == 0/*CPPASTBinaryExpression*/) 
    return a;
  
  return get_gcd( b, a % b );
}
}
// Thread: void sort(const sc_int<17> X[8], sc_int<17> Y[8]);
void sort(const int17  X[8], int17  Y[8]){
{
  unsigned int i, j;
  int17 temp;
  {
  j = 0;
  for ( ; ; ) {
  bool ssdm_tmp_4 = (j < 8);
  if (!ssdm_tmp_4) break;
    Y[j] = X[j];
  j++;
  }
  }
  {
  j = 0;
  for ( ; ; ) {
  bool ssdm_tmp_5 = (j < 8);
  if (!ssdm_tmp_5) break;
    {
      temp = -0xffff;
      {
      i = j;
      for ( ; ; ) {
      bool ssdm_tmp_6 = (i < 8);
      if (!ssdm_tmp_6) break;
        {
          temp = Y[i] > temp ? Y[i] : temp;
        }
      ++i;
      }
      }
      Y[j] = temp;
    }
  j++;
  }
  }
}
}


int main()
{
    unsigned int i, j;
            
    int17 X[8][8];
    int17 Y[8][8];

    for(i=0; i<8; i++)
        for(j=0; j<8; j++){
            X[i][j] = (i+1) * (j + 79);
            Y[i][j] = (i-1) * (j + 255);
        }
    my_test(X, Y);

    return 0;
}

// End of Module | Test
