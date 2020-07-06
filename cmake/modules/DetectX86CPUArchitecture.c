#include <cpuid.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int regs[4] = {0};
  char vendor[13];
  __cpuid(0, regs[0], regs[1], regs[2], regs[3]);
  memcpy(vendor, &regs[1], 4);
  memcpy(vendor + 4, &regs[3], 4);
  memcpy(vendor + 8, &regs[2], 4);
  vendor[12] = '\0';
  __cpuid(1, regs[0], regs[1], regs[2], regs[3]);
  short model = (regs[0] >> 4) & 0xF;
  short family = (regs[0] >> 8) & 0xF;
  short ext_model = (regs[0] >> 16) & 0xF;
  short ext_family = (regs[0] >> 20) & 0xFF;
  switch (family) {
  case 15:
    family += ext_family;
  case 6:
    model += ext_model << 4;
  }
  if (strcmp(vendor, "GenuineIntel") == 0) {
    switch (family) {
    case 6:
      switch (model) {
      case 87:
        printf("knl");
        break;
      case 92:
        printf("goldmont");
        break;
      case 90:
      case 76:
        printf("silvermont");
        break;
      case 142:
      case 158:
        printf("kaby-lake");
        break;
      case 85:
        printf("skylake-avx512");
        break;
      case 78:
      case 94:
        printf("skylake");
        break;
      case 61:
      case 71:
      case 79:
      case 86:
        printf("broadwell");
        break;
      case 60:
      case 69:
      case 70:
      case 63:
        printf("haswell");
        break;
      case 58:
      case 62:
        printf("ivy-bridge");
        break;
      case 42:
      case 45:
        printf("sandy-bridge");
        break;
      case 37:
      case 44:
      case 47:
        printf("westmere");
        break;
      case 26:
      case 30:
      case 31:
      case 46:
        printf("nehalem");
        break;
      case 23:
      case 29:
        printf("penryn");
        break;
      case 15:
        printf("merom");
        break;
      case 28:
        printf("atom");
        break;
      case 14:
        printf("core");
        break;
      default:
        printf("unknown");
        return 1;
      }
      break;
    case 7:
      printf("itanium");
      break;
    default:
      printf("unknown");
      return 1;
    }
  } else {
    if (strcmp(vendor, "AuthenticAMD") == 0) {
      switch (family) {
      case 23:
        printf("zen");
        break;
      case 22:
        printf("16h");
        break;
      case 21:
        if (model < 2)
          printf("bulldozer");
        else
          printf("piledriver");
        break;
      case 20:
        printf("14h");
        break;
      case 16:
        printf("barcelona");
        break;
      case 15:
        printf("k8");
        break;
      default:
        printf("unknown");
        return 1;
      }
    } else {
      printf("unknown!");
      return 1;
    }
  }
  return 0;
}
