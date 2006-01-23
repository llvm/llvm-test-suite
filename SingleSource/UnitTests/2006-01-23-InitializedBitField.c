#include <stdio.h>

// Test that static initializers for things with bitfields work.

struct S0 {
  unsigned int A:2;
  unsigned short B:3;
  unsigned C:24;
} s0 = { 2, 7, 123479 };

struct S1 {
  float F;
  int A : 31;
  int B : 1;
  long long C : 31;
} s1 = { 123.456f, 12 };

struct S2 {
  int A : 31;
  int B : 2;
  long long C : 31;
} s2 = { 123456, -1, 45123 };

struct S3 {
  int A;
  long long B : 31;
  int C : 4;
} s3 = { 4567812, -123, 2 };

struct S4 {
  short A;
  int B : 16;
} s4 = { 0x1234, 0x5678 };

struct S5 {
  short A;
  long long B : 48;
} s5 = { 0x1234, 0x56789ABCDE1LL};

struct S6 {
  int A : 31;
  int B : 1;
  long long C : 31;
  long long D : 2;
} s6 = { 1243, -1, 24112412, 3};

struct S7 {
  _Bool D : 8;
  _Bool D2 : 8;
  int D3 : 8;
  long long : 9;
  float B;
} s7 = { 1, 0, 123, 1.023f };

struct S8 {
  int A : 31;
  int B : 1;
  long long C : 31;
  long long D : 34;
  long long E : 2;
} s8 = { 123412312, 0, 1231231241, 12312312312LL, 1 };

struct S9 {
  int A : 31;
  int B : 2;
  long long C : 31;
} s9 = {12312412, 1, 123123124 };

struct S10 {
  _Bool D : 8;
  _Bool D2 : 8;
  int D3 : 15;
  long long : 9;
  int B;
} s10 = { 1, 0, 21321, 44444 };

struct S11 {
  _Bool D : 8;
  int : 0;
  int B;
} s11 = { 1, 3};

int main() {
  printf("s0 = %d, %d, %d\n", s0.A, s0.B, s0.C);
  printf("s1 = %f, %d, %d, %d\n", s1.F, s1.A, s1.B, (int)s1.C);
  printf("s2 = %d, %d, %d\n", s2.A, s2.B, (int)s2.C);
  printf("s3 = %d, %d, %d\n", s3.A, (int)s3.B, s3.C);
  printf("s4 = %d, %d\n", s4.A, s4.B);
  printf("s5 = %d %lld\n", s5.A, s5.B);
  printf("s6 = %d, %d, %d, %d\n", s6.A, s6.B, (int)s6.C, (int)s6.D);
  printf("s7 = %d, %d, %d, %f\n", s7.D, s7.D2, (int)s7.D3, s7.B);
  printf("s8 = %d, %d, %d, %lld, %d\n", s8.A, s8.B, (int)s8.C, (long long)s8.D,
         s8.E);
  printf("s9 = %d, %d, %d\n", s9.A, s9.B, (int)s9.C);
  printf("s10 = %d, %d, %d, %d\n", s10.D, s10.D2, s10.D3, s10.B);
  printf("s11 = %d, %d\n", s11.D, s11.B);
}
