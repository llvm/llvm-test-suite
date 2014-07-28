// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: cxx_compiler -c %s cxx_11 -o %t1.o
// RUN: c_compiler -c %s -o %t2.o
// RUN: linker -o %t%exeext %t1.o %t2.o 
// RUN: runtool %t%exeext | grep  "PASSED"
#define MAXG 4

typedef signed char chtype;
#ifdef __cplusplus
extern "C" int printf(const char *, ...);
int va[MAXG] = {1, 3, 7, 10}, vb[MAXG] = {-2, -4, -7, 100}, ga, gb, nerr;
extern "C" void barcc(int, ...);
void foocc()  {  chtype a ; chtype b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barcc(0,&f);
  }
}
extern "C" void barcs(int, ...);
void foocs()  {  chtype a ; short b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barcs(0,&f);
  }
}
extern "C" void barci(int, ...);
void fooci()  {  chtype a ; int b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barci(0,&f);
  }
}
extern "C" void barcl(int, ...);
void foocl()  {  chtype a ; long b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barcl(0,&f);
  }
}
extern "C" void barcf(int, ...);
void foocf()  {  chtype a ; float b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barcf(0,&f);
  }
}
extern "C" void barcd(int, ...);
void foocd()  {  chtype a ; double b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barcd(0,&f);
  }
}
extern "C" void barsc(int, ...);
void foosc()  {  short a ; chtype b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barsc(0,&f);
  }
}
extern "C" void barss(int, ...);
void fooss()  {  short a ; short b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barss(0,&f);
  }
}
extern "C" void barsi(int, ...);
void foosi()  {  short a ; int b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barsi(0,&f);
  }
}
extern "C" void barsl(int, ...);
void foosl()  {  short a ; long b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barsl(0,&f);
  }
}
extern "C" void barsf(int, ...);
void foosf()  {  short a ; float b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barsf(0,&f);
  }
}
extern "C" void barsd(int, ...);
void foosd()  {  short a ; double b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barsd(0,&f);
  }
}
extern "C" void baric(int, ...);
void fooic()  {  int a ; chtype b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; baric(0,&f);
  }
}
extern "C" void baris(int, ...);
void foois()  {  int a ; short b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; baris(0,&f);
  }
}
extern "C" void barii(int, ...);
void fooii()  {  int a ; int b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barii(0,&f);
  }
}
extern "C" void baril(int, ...);
void fooil()  {  int a ; long b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; baril(0,&f);
  }
}
extern "C" void barif(int, ...);
void fooif()  {  int a ; float b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barif(0,&f);
  }
}
extern "C" void barid(int, ...);
void fooid()  {  int a ; double b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barid(0,&f);
  }
}
extern "C" void barlc(int, ...);
void foolc()  {  long a ; chtype b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barlc(0,&f);
  }
}
extern "C" void barls(int, ...);
void fools()  {  long a ; short b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barls(0,&f);
  }
}
extern "C" void barli(int, ...);
void fooli()  {  long a ; int b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barli(0,&f);
  }
}
extern "C" void barll(int, ...);
void fooll()  {  long a ; long b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barll(0,&f);
  }
}
extern "C" void barlf(int, ...);
void foolf()  {  long a ; float b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barlf(0,&f);
  }
}
extern "C" void barld(int, ...);
void foold()  {  long a ; double b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barld(0,&f);
  }
}
extern "C" void barfc(int, ...);
void foofc()  {  float a ; chtype b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barfc(0,&f);
  }
}
extern "C" void barfs(int, ...);
void foofs()  {  float a ; short b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barfs(0,&f);
  }
}
extern "C" void barfi(int, ...);
void foofi()  {  float a ; int b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barfi(0,&f);
  }
}
extern "C" void barfl(int, ...);
void foofl()  {  float a ; long b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barfl(0,&f);
  }
}
extern "C" void barff(int, ...);
void fooff()  {  float a ; float b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barff(0,&f);
  }
}
extern "C" void barfd(int, ...);
void foofd()  {  float a ; double b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; barfd(0,&f);
  }
}
extern "C" void bardc(int, ...);
void foodc()  {  double a ; chtype b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; bardc(0,&f);
  }
}
extern "C" void bards(int, ...);
void foods()  {  double a ; short b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; bards(0,&f);
  }
}
extern "C" void bardi(int, ...);
void foodi()  {  double a ; int b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; bardi(0,&f);
  }
}
extern "C" void bardl(int, ...);
void foodl()  {  double a ; long b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; bardl(0,&f);
  }
}
extern "C" void bardf(int, ...);
void foodf()  {  double a ; float b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; bardf(0,&f);
  }
}
extern "C" void bardd(int, ...);
void foodd()  {  double a ; double b ;
  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){
    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; bardd(0,&f);
  }
}
int main() {

  foocc();
  foocs();
  fooci();
  foocl();
  foocf();
  foocd();
  foosc();
  fooss();
  foosi();
  foosl();
  foosf();
  foosd();
  fooic();
  foois();
  fooii();
  fooil();
  fooif();
  fooid();
  foolc();
  fools();
  fooli();
  fooll();
  foolf();
  foold();
  foofc();
  foofs();
  foofi();
  foofl();
  fooff();
  foofd();
  foodc();
  foods();
  foodi();
  foodl();
  foodf();
  foodd();
  printf("%s\n", nerr ? "FAILED":"PASSED");
}
#else // __cplusplus
extern  int printf(const char *, ...);
extern int nerr, va[MAXG], vb[MAXG], ga, gb;
void checkvals(int a, int b, int l) {
  if (a != va[ga] || b != vb[gb])
    printf("ERROR@%d %d!=va[%d]==%d %d!=vb[%d]==%d %d\n", l, a, ga, va[ga], b, gb, vb[gb], nerr++);
}

void showvals(void *p, int ln)
{  
  int i;
  unsigned char *pu = (unsigned char*) p;
  printf("SHOW@%d: ", ln);
  for (i=0; i<20; i++) printf("%s%02x", (i&3)?"":" ", pu[i]);
  printf("\n");
}


// ----- chtype chtype ----
struct Fcc { chtype a; chtype b; };
void barcc(int x, struct Fcc *p) { checkvals(p->a, p->b, __LINE__); } //showvals(p, __LINE__); 

// ----- chtype short ----
struct Fcs { chtype a; short b; };
void barcs(int x, struct Fcs *p) { checkvals(p->a, p->b, __LINE__); }

// ----- chtype int ----
struct Fci { chtype a; int b; };
void barci(int x, struct Fci *p) { checkvals(p->a, p->b, __LINE__); }

// ----- chtype long ----
struct Fcl { chtype a; long b; };
void barcl(int x, struct Fcl *p) { checkvals(p->a, p->b, __LINE__); }

// ----- chtype float ----
struct Fcf { chtype a; float b; };
void barcf(int x, struct Fcf *p) { checkvals(p->a, p->b, __LINE__); }

// ----- chtype double ----
struct Fcd { chtype a; double b; };
void barcd(int x, struct Fcd *p) { checkvals(p->a, p->b, __LINE__); }

// ----- short chtype ----
struct Fsc { short a; chtype b; };
void barsc(int x, struct Fsc *p) { checkvals(p->a, p->b, __LINE__); }

// ----- short short ----
struct Fss { short a; short b; };
void barss(int x, struct Fss *p) { checkvals(p->a, p->b, __LINE__); }

// ----- short int ----
struct Fsi { short a; int b; };
void barsi(int x, struct Fsi *p) { checkvals(p->a, p->b, __LINE__); }

// ----- short long ----
struct Fsl { short a; long b; };
void barsl(int x, struct Fsl *p) { checkvals(p->a, p->b, __LINE__); }

// ----- short float ----
struct Fsf { short a; float b; };
void barsf(int x, struct Fsf *p) { checkvals(p->a, p->b, __LINE__); }

// ----- short double ----
struct Fsd { short a; double b; };
void barsd(int x, struct Fsd *p) { checkvals(p->a, p->b, __LINE__); }

// ----- int chtype ----
struct Fic { int a; chtype b; };
void baric(int x, struct Fic *p) { checkvals(p->a, p->b, __LINE__); }

// ----- int short ----
struct Fis { int a; short b; };
void baris(int x, struct Fis *p) { checkvals(p->a, p->b, __LINE__); }

// ----- int int ----
struct Fii { int a; int b; };
void barii(int x, struct Fii *p) { checkvals(p->a, p->b, __LINE__); }

// ----- int long ----
struct Fil { int a; long b; };
void baril(int x, struct Fil *p) { checkvals(p->a, p->b, __LINE__); }

// ----- int float ----
struct Fif { int a; float b; };
void barif(int x, struct Fif *p) { checkvals(p->a, p->b, __LINE__); }

// ----- int double ----
struct Fid { int a; double b; };
void barid(int x, struct Fid *p) { checkvals(p->a, p->b, __LINE__); }

// ----- long chtype ----
struct Flc { long a; chtype b; };
void barlc(int x, struct Flc *p) { checkvals(p->a, p->b, __LINE__); }

// ----- long short ----
struct Fls { long a; short b; };
void barls(int x, struct Fls *p) { checkvals(p->a, p->b, __LINE__); }

// ----- long int ----
struct Fli { long a; int b; };
void barli(int x, struct Fli *p) { checkvals(p->a, p->b, __LINE__); }

// ----- long long ----
struct Fll { long a; long b; };
void barll(int x, struct Fll *p) { checkvals(p->a, p->b, __LINE__); }

// ----- long float ----
struct Flf { long a; float b; };
void barlf(int x, struct Flf *p) { checkvals(p->a, p->b, __LINE__); }

// ----- long double ----
struct Fld { long a; double b; };
void barld(int x, struct Fld *p) { checkvals(p->a, p->b, __LINE__); }

// ----- float chtype ----
struct Ffc { float a; chtype b; };
void barfc(int x, struct Ffc *p) { checkvals(p->a, p->b, __LINE__); }

// ----- float short ----
struct Ffs { float a; short b; };
void barfs(int x, struct Ffs *p) { checkvals(p->a, p->b, __LINE__); }

// ----- float int ----
struct Ffi { float a; int b; };
void barfi(int x, struct Ffi *p) { checkvals(p->a, p->b, __LINE__); }

// ----- float long ----
struct Ffl { float a; long b; };
void barfl(int x, struct Ffl *p) { checkvals(p->a, p->b, __LINE__); }

// ----- float float ----
struct Fff { float a; float b; };
void barff(int x, struct Fff *p) { checkvals(p->a, p->b, __LINE__); }

// ----- float double ----
struct Ffd { float a; double b; };
void barfd(int x, struct Ffd *p) { checkvals(p->a, p->b, __LINE__); }

// ----- double chtype ----
struct Fdc { double a; chtype b; };
void bardc(int x, struct Fdc *p) { checkvals(p->a, p->b, __LINE__); }

// ----- double short ----
struct Fds { double a; short b; };
void bards(int x, struct Fds *p) { checkvals(p->a, p->b, __LINE__); }

// ----- double int ----
struct Fdi { double a; int b; };
void bardi(int x, struct Fdi *p) { checkvals(p->a, p->b, __LINE__); }

// ----- double long ----
struct Fdl { double a; long b; };
void bardl(int x, struct Fdl *p) { checkvals(p->a, p->b, __LINE__); }

// ----- double float ----
struct Fdf { double a; float b; };
void bardf(int x, struct Fdf *p) { checkvals(p->a, p->b, __LINE__); }

// ----- double double ----
struct Fdd { double a; double b; };
void bardd(int x, struct Fdd *p) { checkvals(p->a, p->b, __LINE__); }
#endif

// generated from the following script
#if 0
echo "#define MAXG 4"
echo "#ifdef __cplusplus"
echo "extern \"C\" int printf(const char *, ...);"
#echo "template <class T> void TMPL(T fo);"
echo "int va[MAXG] = {1, 3, 7, 10}, vb[MAXG] = {-2, -4, -7, 100}, ga, gb, nerr;"
#  type1 type2 tag1 tag2
doit()
{
   X=`echo $1 | sed -e 's/\(.\).*/\1/' `
   Y=`echo $2 | sed -e 's/\(.\).*/\1/' `
   echo "  foo$X$Y();" >> _foocalls
   echo "extern \"C\" void bar$X$Y(int, ...);"
   echo "void foo$X$Y()  {  $1 a ; $2 b ;"
   echo "  for (ga=0; ga<MAXG; ga++) for (gb=0; gb<MAXG; gb++){"
   echo "    a = va[ga]; b = vb[gb]; auto f = [a, b](int x) { return x + a + b; }; bar$X$Y(0,&f);"
   echo "  }"
   echo "}"
   echo "" >> _cpart
   echo "// ----- $1 $2 ----" >> _cpart
   echo "struct F$X$Y { $1 a; $2 b; };" >> _cpart
   echo "void bar$X${Y}(int x, struct F$X$Y *p) { checkvals(p->a, p->b, __LINE__); }" >> _cpart
}

echo > _foocalls
echo > _cpart

#echo "void foo() {"
for t1 in chtype short int long float double; do
for t2 in chtype short int long float double; do
  doit $t1 $t2
done
done
#echo "}"
   
echo "int main() {"
cat _foocalls
echo "  printf(\"%s\\n\", nerr ? \"FAILED\":\"PASSED\");"
echo "}"
echo "#else // __cplusplus"
echo "extern  int printf(const char *, ...);"
echo "extern int nerr, va[MAXG], vb[MAXG], ga, gb;"
echo "void checkvals(int a, int b, int l) {"
echo "  if (a != va[ga] || b != gb[vb])"
echo "    printf(\"ERROR@%d %d/%d %d/%d %d\\n\", l, a, va[ga], b, gb[vb], nerr++);"
echo "}"
cat _cpart
echo "#endif"
#endif
