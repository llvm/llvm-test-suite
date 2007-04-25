extern int test_weak () __attribute__ ((weak));

int main(){
  int (*t)() = test_weak;
  if (t)
    return t();
  else return 250;
}
