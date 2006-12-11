#include <stdio.h>

long zz() { return 0x00000000L; }
long zs() { return 0x0000ffffL; }
long zu() { return 0x00007fffL; }
long sz() { return 0xffff0000L; }
long ss() { return 0xffffffffL; }
long su() { return 0xffff7fffL; }
long uz() { return 0x7fff0000L; }
long us() { return 0x7fffffffL; }
long uu() { return 0x7fff7fffL; }

long long zzzz() { return 0x0000000000000000LL; }
long long zzzs() { return 0x000000000000ffffLL; }
long long zzzu() { return 0x0000000000007fffLL; }
long long zzsz() { return 0x00000000ffff0000LL; }
long long zzss() { return 0x00000000ffffffffLL; }
long long zzsu() { return 0x00000000ffff7fffLL; }
long long zzuz() { return 0x000000007fff0000LL; }
long long zzus() { return 0x000000007fffffffLL; }
long long zzuu() { return 0x000000007fff7fffLL; }
long long zszz() { return 0x0000ffff00000000LL; }
long long zszs() { return 0x0000ffff0000ffffLL; }
long long zszu() { return 0x0000ffff00007fffLL; }
long long zssz() { return 0x0000ffffffff0000LL; }
long long zsss() { return 0x0000ffffffffffffLL; }
long long zssu() { return 0x0000ffffffff7fffLL; }
long long zsuz() { return 0x0000ffff7fff0000LL; }
long long zsus() { return 0x0000ffff7fffffffLL; }
long long zsuu() { return 0x0000ffff7fff7fffLL; }
long long zuzz() { return 0x00007fff00000000LL; }
long long zuzs() { return 0x00007fff0000ffffLL; }
long long zuzu() { return 0x00007fff00007fffLL; }
long long zusz() { return 0x00007fffffff0000LL; }
long long zuss() { return 0x00007fffffffffffLL; }
long long zusu() { return 0x00007fffffff7fffLL; }
long long zuuz() { return 0x00007fff7fff0000LL; }
long long zuus() { return 0x00007fff7fffffffLL; }
long long zuuu() { return 0x00007fff7fff7fffLL; }
long long szzz() { return 0xffff000000000000LL; }
long long szzs() { return 0xffff00000000ffffLL; }
long long szzu() { return 0xffff000000007fffLL; }
long long szsz() { return 0xffff0000ffff0000LL; }
long long szss() { return 0xffff0000ffffffffLL; }
long long szsu() { return 0xffff0000ffff7fffLL; }
long long szuz() { return 0xffff00007fff0000LL; }
long long szus() { return 0xffff00007fffffffLL; }
long long szuu() { return 0xffff00007fff7fffLL; }
long long sszz() { return 0xffffffff00000000LL; }
long long sszs() { return 0xffffffff0000ffffLL; }
long long sszu() { return 0xffffffff00007fffLL; }
long long sssz() { return 0xffffffffffff0000LL; }
long long ssss() { return 0xffffffffffffffffLL; }
long long sssu() { return 0xffffffffffff7fffLL; }
long long ssuz() { return 0xffffffff7fff0000LL; }
long long ssus() { return 0xffffffff7fffffffLL; }
long long ssuu() { return 0xffffffff7fff7fffLL; }
long long suzz() { return 0xffff7fff00000000LL; }
long long suzs() { return 0xffff7fff0000ffffLL; }
long long suzu() { return 0xffff7fff00007fffLL; }
long long susz() { return 0xffff7fffffff0000LL; }
long long suss() { return 0xffff7fffffffffffLL; }
long long susu() { return 0xffff7fffffff7fffLL; }
long long suuz() { return 0xffff7fff7fff0000LL; }
long long suus() { return 0xffff7fff7fffffffLL; }
long long suuu() { return 0xffff7fff7fff7fffLL; }
long long uzzz() { return 0x7fff000000000000LL; }
long long uzzs() { return 0x7fff00000000ffffLL; }
long long uzzu() { return 0x7fff000000007fffLL; }
long long uzsz() { return 0x7fff0000ffff0000LL; }
long long uzss() { return 0x7fff0000ffffffffLL; }
long long uzsu() { return 0x7fff0000ffff7fffLL; }
long long uzuz() { return 0x7fff00007fff0000LL; }
long long uzus() { return 0x7fff00007fffffffLL; }
long long uzuu() { return 0x7fff00007fff7fffLL; }
long long uszz() { return 0x7fffffff00000000LL; }
long long uszs() { return 0x7fffffff0000ffffLL; }
long long uszu() { return 0x7fffffff00007fffLL; }
long long ussz() { return 0x7fffffffffff0000LL; }
long long usss() { return 0x7fffffffffffffffLL; }
long long ussu() { return 0x7fffffffffff7fffLL; }
long long usuz() { return 0x7fffffff7fff0000LL; }
long long usus() { return 0x7fffffff7fffffffLL; }
long long usuu() { return 0x7fffffff7fff7fffLL; }
long long uuzz() { return 0x7fff7fff00000000LL; }
long long uuzs() { return 0x7fff7fff0000ffffLL; }
long long uuzu() { return 0x7fff7fff00007fffLL; }
long long uusz() { return 0x7fff7fffffff0000LL; }
long long uuss() { return 0x7fff7fffffffffffLL; }
long long uusu() { return 0x7fff7fffffff7fffLL; }
long long uuuz() { return 0x7fff7fff7fff0000LL; }
long long uuus() { return 0x7fff7fff7fffffffLL; }
long long uuuu() { return 0x7fff7fff7fff7fffLL; }

int main(int argc, const char *argv[]) {
  printf("%08x\n", zz());
  printf("%08x\n", zs());
  printf("%08x\n", zu());
  printf("%08x\n", sz());
  printf("%08x\n", ss());
  printf("%08x\n", su());
  printf("%08x\n", uz());
  printf("%08x\n", us());
  printf("%08x\n", uu());
  
  printf("%016llx\n", zzzz());
  printf("%016llx\n", zzzs());
  printf("%016llx\n", zzzu());
  printf("%016llx\n", zzsz());
  printf("%016llx\n", zzss());
  printf("%016llx\n", zzsu());
  printf("%016llx\n", zzuz());
  printf("%016llx\n", zzus());
  printf("%016llx\n", zzuu());
  printf("%016llx\n", zszz());
  printf("%016llx\n", zszs());
  printf("%016llx\n", zszu());
  printf("%016llx\n", zssz());
  printf("%016llx\n", zsss());
  printf("%016llx\n", zssu());
  printf("%016llx\n", zsuz());
  printf("%016llx\n", zsus());
  printf("%016llx\n", zsuu());
  printf("%016llx\n", zuzz());
  printf("%016llx\n", zuzs());
  printf("%016llx\n", zuzu());
  printf("%016llx\n", zusz());
  printf("%016llx\n", zuss());
  printf("%016llx\n", zusu());
  printf("%016llx\n", zuuz());
  printf("%016llx\n", zuus());
  printf("%016llx\n", zuuu());
  printf("%016llx\n", szzz());
  printf("%016llx\n", szzs());
  printf("%016llx\n", szzu());
  printf("%016llx\n", szsz());
  printf("%016llx\n", szss());
  printf("%016llx\n", szsu());
  printf("%016llx\n", szuz());
  printf("%016llx\n", szus());
  printf("%016llx\n", szuu());
  printf("%016llx\n", sszz());
  printf("%016llx\n", sszs());
  printf("%016llx\n", sszu());
  printf("%016llx\n", sssz());
  printf("%016llx\n", ssss());
  printf("%016llx\n", sssu());
  printf("%016llx\n", ssuz());
  printf("%016llx\n", ssus());
  printf("%016llx\n", ssuu());
  printf("%016llx\n", suzz());
  printf("%016llx\n", suzs());
  printf("%016llx\n", suzu());
  printf("%016llx\n", susz());
  printf("%016llx\n", suss());
  printf("%016llx\n", susu());
  printf("%016llx\n", suuz());
  printf("%016llx\n", suus());
  printf("%016llx\n", suuu());
  printf("%016llx\n", uzzz());
  printf("%016llx\n", uzzs());
  printf("%016llx\n", uzzu());
  printf("%016llx\n", uzsz());
  printf("%016llx\n", uzss());
  printf("%016llx\n", uzsu());
  printf("%016llx\n", uzuz());
  printf("%016llx\n", uzus());
  printf("%016llx\n", uzuu());
  printf("%016llx\n", uszz());
  printf("%016llx\n", uszs());
  printf("%016llx\n", uszu());
  printf("%016llx\n", ussz());
  printf("%016llx\n", usss());
  printf("%016llx\n", ussu());
  printf("%016llx\n", usuz());
  printf("%016llx\n", usus());
  printf("%016llx\n", usuu());
  printf("%016llx\n", uuzz());
  printf("%016llx\n", uuzs());
  printf("%016llx\n", uuzu());
  printf("%016llx\n", uusz());
  printf("%016llx\n", uuss());
  printf("%016llx\n", uusu());
  printf("%016llx\n", uuuz());
  printf("%016llx\n", uuus());
  printf("%016llx\n", uuuu());

  return 0;
}
