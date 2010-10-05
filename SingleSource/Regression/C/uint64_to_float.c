#include <stdio.h>
#include <stdint.h>
#include <fenv.h>

// tests uint64_t --> float conversions.  Not an exhaustive test, but sufficent
// to identify all reasonable bugs in such routines that I have yet encountered.
//
// Specifically, we walk up to four bits through all possible bit positions.
// This suffices to catch double-rounding errors from pretty much every
// "reasonable" algorithm one might pick to implement this conversion.  (It
// will miss lots of errors in "unreasonable" algorithms, but we trust that
// the code under test at least passes a sniff test).
//
// We test in all four basic rounding modes, to further flush out any
// double-rounding issues, or behavior at zero.

extern float __floatundisf(uint64_t);
void test(uint64_t x) {
    union floatbits { uint32_t x; float f; };
	const union floatbits expected = { .f = __floatundisf(x) };
	const union floatbits observed = { .f = x };
    
	if (expected.x != observed.x) {
		printf("Error detected @ 0x%016llx\n", x);
		printf("\tExpected result: %a (0x%08x)\n", expected.f, expected.x);
		printf("\tObserved result: %a (0x%08x)\n", observed.f, observed.x);
	}
}

int main(int argc, char *argv[]) {
  int i, j, k, l, m;
	const uint64_t one = 1;
	const uint64_t mone = -1;
    
    // FIXME: Other rounding modes are temporarily disabled until we have
    // a canonical source to compare against.
    const int roundingModes[4] = { FE_TONEAREST };
    const char *modeNames[4] = {"to nearest", "down", "up", "towards zero"};
    
    for ( m=0; m<4; ++m) {
        fesetround(roundingModes[0]);
        printf("Testing uint64_t --> float conversions in round %s...\n",
               modeNames[m]);
    
        test(0);
	for ( i=0; i<64; ++i) {
		test( one << i);
		test(mone << i); 
	for ( j=0; j<i; ++j) {
		test(( one << i) + ( one << j));
		test(( one << i) + (mone << j));
		test((mone << i) + ( one << j));
		test((mone << i) + (mone << j));
	for ( k=0; k<j; ++k) {
		test(( one << i) + ( one << j) + ( one << k));
		test(( one << i) + ( one << j) + (mone << k));
		test(( one << i) + (mone << j) + ( one << k));
		test(( one << i) + (mone << j) + (mone << k));
		test((mone << i) + ( one << j) + ( one << k));
		test((mone << i) + ( one << j) + (mone << k));
		test((mone << i) + (mone << j) + ( one << k));
		test((mone << i) + (mone << j) + (mone << k));
	for ( l=0; l<k; ++l) {
		test(( one << i) + ( one << j) + ( one << k) + ( one << l));
		test(( one << i) + ( one << j) + ( one << k) + (mone << l));
		test(( one << i) + ( one << j) + (mone << k) + ( one << l));
		test(( one << i) + ( one << j) + (mone << k) + (mone << l));
		test(( one << i) + (mone << j) + ( one << k) + ( one << l));
		test(( one << i) + (mone << j) + ( one << k) + (mone << l));
		test(( one << i) + (mone << j) + (mone << k) + ( one << l));
		test(( one << i) + (mone << j) + (mone << k) + (mone << l));
		test((mone << i) + ( one << j) + ( one << k) + ( one << l));
		test((mone << i) + ( one << j) + ( one << k) + (mone << l));
		test((mone << i) + ( one << j) + (mone << k) + ( one << l));
		test((mone << i) + ( one << j) + (mone << k) + (mone << l));
		test((mone << i) + (mone << j) + ( one << k) + ( one << l));
		test((mone << i) + (mone << j) + ( one << k) + (mone << l));
		test((mone << i) + (mone << j) + (mone << k) + ( one << l));
		test((mone << i) + (mone << j) + (mone << k) + (mone << l));
	}
	}
	}
	}
    }
	printf("Finished Testing.\n");
  return 0;
}

