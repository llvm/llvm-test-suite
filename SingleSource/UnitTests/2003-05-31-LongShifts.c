
void Test(long long Val, int Amt) {
  printf("0x%llx op %d:\n", Val, Amt);
  printf("  sar: 0x%llx\n  shr: 0x%llx\n  shl: 0x%llx\n", Val >> Amt, 
         (unsigned long long)Val >> Amt, Val << Amt);
}

int main() {
  Test(123, 4);
  Test(123, 34);
  Test(-4, 4);
  Test(-5, 34);
  Test(-6000000000LL, 4);
  Test(-6000000000LL, 34);
  Test( 6000000000LL, 4);
  Test( 6000000000LL, 34);
  return 0;
}
