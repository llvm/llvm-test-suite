
typedef int __attribute__ ((bitwidth(31))) int31;

typedef struct { int31 pgprot; } pgprot_t;

void split_large_page(int31 addr, pgprot_t prot)
{
  int31 x;
  x = (addr ? prot : ((pgprot_t) { 0x101 } )).pgprot;
  printf("%x\n", x);
}

int main()
{
    split_large_page(0x7fffffff, (pgprot_t){0x1});
    return 0;
}
