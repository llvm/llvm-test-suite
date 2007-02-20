//===--- gptest.cpp --- Test Cases for Bit Accurate Types -----------------===//
//
// This file was developed by Guoling Han and is distributed under the 
// University of Illinois Open Source License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This is a validating test for arithmetic operations that uses the gp (pari)
// calculator to validate APInt's computations.
//
//===----------------------------------------------------------------------===//

#include "llvm/ADT/APInt.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "llvm/System/Signals.h"

using namespace llvm;

APInt x(21, 0x1fffff);
APInt y(21, 0x0fffff);

void print(const APInt& X, bool wantSigned = false, bool withNL = true) {
  std::string decstr = X.toString(10,wantSigned);
  printf("%s", decstr.c_str());
  if (withNL)
    printf("\n");
}

APInt randomAPInt(unsigned bits) {
  APInt val(bits, 0u);
  for (unsigned i = 0; i < bits; ++i) {
    unsigned bit = rand() % 2;
    val = val.shl(1);
    val |= APInt(bits, bit);
  }
  return val;
}

void test_interface(const APInt &val) {
  printf("INTERFACE TEST: val = "); print(val);
  unsigned bitwidth = val.getBitWidth();
  unsigned pos = rand() % bitwidth;
  printf("val[%u] = %d\n", pos, val[pos]);
  APInt smax(APInt::getMaxValue(bitwidth, true));
  APInt umax(APInt::getMaxValue(bitwidth, false));
  APInt smin(APInt::getMinValue(bitwidth, true));
  APInt umin(APInt::getMinValue(bitwidth, false));
  printf("APInt::getMinValue(%d, true)  = ", bitwidth); print(smin,true);
  printf("APInt::getMaxValue(%d, true)  = ", bitwidth); print(smax,true);
  printf("APInt::getMinValue(%d, false) = ", bitwidth); print(umin);
  printf("APInt::getMaxValue(%d, false) = ", bitwidth); print(umax);
  APInt null = APInt::getNullValue(bitwidth);
  APInt allone = APInt::getAllOnesValue(bitwidth);
  printf("APInt::getNullValue(%d) = ", bitwidth); print(null);
  printf("APInt::getAllOnesValue(%d) = ", bitwidth); print(allone);
  APInt x(val);
  x.set(pos);
  printf("val.set(%d) = ", pos);  print(x);
  x.set();
  printf("val.set() = "); print(x);
  x = val;
  x.clear(pos);
  printf("val.clear(%d) = ", pos);  print(x);
  x.clear();
  printf("val.clear() = "); print(x);
  x = val;
  x.flip(pos);
  printf("val.flip(%d) = ", pos); print(x);
  x = val;
  x.flip();
  printf("val.flip() = "); print(x);
  unsigned bitsize = bitwidth / 2;
  printf("val.getHiBits(%d) = ", bitsize); print(val.getHiBits(bitsize));
  printf("val.getLoBits(%d) = ", bitsize); print(val.getLoBits(bitsize));
  printf("val.isIntN(%d) = %d\n", bitwidth, val.isIntN(bitwidth));
}

void test_unops(const APInt &val) {
  printf("UNARY OPERATORS TEST: val = "); print(val);
  APInt x(val);
  x++;
  printf("val++ = "); print(x);
  x = val;
  ++x;
  printf("++val = "); print(x);
  x = val;
  x--;
  printf("val-- = "); print(x);
  x = val;
  --x;
  printf("--val = "); print(x);
  x = -val;
  printf("-val = "); print(x);
  x = ~val;
  printf("~val = "); print(x);
  printf("!val = %d\n", !val);
  printf("val.isPowerOf2() = %d\n", val.isPowerOf2());
  printf("val.logBase2() = %d\n", val.logBase2());
  printf("val.countLeadingZeros() = %d\n", val.countLeadingZeros());
  printf("val.countTrailingZeros() = %d\n", val.countTrailingZeros());
  printf("val.countPopulation() = %d\n", val.countPopulation());
  printf("val.getBitWidth() = %d\n", val.getBitWidth());
  if (val.getBitWidth() >= 16 && val.getBitWidth() % 16 == 0) {
    x = val.byteSwap();
    printf("val.byteSwap() = "); print(x);
  }
  printf("val.roundToDouble(false) = %f\n", val.roundToDouble(false));
  printf("val.roundToDouble(true)  = %f\n", val.roundToDouble(true));
  printf("val.getValue() = ");
  if (val.getBitWidth() > 64)
    printf("too wide\n");
  else
    printf("%lu\n", val.getValue());
}

void old_test_binops(const APInt &v1, const APInt &v2) {
  printf("BINARY OPERATORS TEST: \n      vl: "); print(v1,false,false);
  printf("\n      v2: "); print(v2);
  APInt result(v1);
  result &= v2;
  printf("v1 &= v2: "); print(result);
  result = v1;
  result |= v2;
  printf("v1 |= v2: "); print(result);
  result = v1;
  result ^= v2;
  printf("v1 ^= v2: "); print(result);
  result = v1;
  result *= v2;
  printf("v1 *= v2: "); print(result);
  result = v1;
  result += v2;
  printf("v1 += v2: "); print(result);
  result = v1;
  result -= v2;
  printf("v1 -= v2: "); print(result);
  result = v1 & v2;
  printf("v1 &  v2: "); print(result);
  result = v1 | v2;
  printf("v1 |  v2: "); print(result);
  result = v1 ^ v2;
  printf("v1 ^  v2: "); print(result);
  result = v1 * v2;
  printf("v1 *  v2: "); print(result);
  result = v1 + v2;
  printf("v1 +  v2: "); print(result);
  result = v1 - v2;
  printf("v1 -  v2: "); print(result);
  printf("v1 == v2: %d\n", v1 == v2);
  printf("v1 != v2: %d\n", v1 != v2);
  printf("v1.eq(v2): %d\n", v1.eq(v2));
  printf("v1.ne(v2): %d\n", v1.ne(v2));
  printf("v1.ult(v2): %d\n", v1.ult(v2));
  printf("v1.slt(v2): %d\n", v1.slt(v2));
  printf("v1.ule(v2): %d\n", v1.ule(v2));
  printf("v1.sle(v2): %d\n", v1.sle(v2));
  printf("v1.ugt(v2): %d\n", v1.ugt(v2));
  printf("v1.sgt(v2): %d\n", v1.sgt(v2));
  printf("v1.uge(v2): %d\n", v1.uge(v2));
  printf("v1.sge(v2): %d\n", v1.sge(v2));
  {
    using namespace APIntOps;
    unsigned shiftAmt = rand() % v1.getBitWidth();
    result = ashr(v1,shiftAmt);
    printf("ashr(v1,%d) = ", shiftAmt); print(result);
    result = lshr(v1,shiftAmt);
    printf("lshr(v1,%d) = ", shiftAmt); print(result);
    result = shl(v1,shiftAmt);
    printf("shl(v1,%d) = ", shiftAmt); print(result);
    if (v2 == APInt(v2.getBitWidth(), 0))
      printf("sdiv/udiv/srem/urem not tested, v2 == 0\n");
    else {
      result = sdiv(v1,v2);
      printf("sdiv(v1,v2) = "); print(result);
      result = udiv(v1,v2);
      printf("udiv(v1,v2) = "); print(result);
      result = srem(v1,v2);
      printf("srem(v1,v2) = "); print(result);
      result = urem(v1,v2);
      printf("urem(v1,v2) = "); print(result);
    }
  }
}

static int input = 0, output = 0;

std::string getBinopCmd(const APInt &v1, std::string op, const APInt &v2, 
                     bool wantSigned = false) {
  std::string Result;
  Result += "truncate(";
  Result += v1.toString(10,wantSigned);
  Result += " " + op + " ";
  Result += v2.toString(10,wantSigned);
  Result += ")\n";
  return Result;
}

std::string getResult(const std::string& cmd) {
  const char *command = cmd.c_str();
  if (-1 == write(output, command, cmd.size())) {
    std::string msg = "write: " + cmd;
    perror(msg.c_str());
    exit(1);
  }
  usleep(1000); // try to switch contexts
  char buf[1024];
  int len = read(input, buf, 1024);
  if (-1 == len) {
    std::string msg = "read: " + cmd;
    perror(msg.c_str());
    exit(1);
  }
  // We're only interested in the last line.
  if (char * nl = strrchr(buf, '\n')) {
    *nl = 0;
    if (char *nnl = strrchr(nl, '\n'))
      return std::string(nnl+1);
  }
  return std::string(buf);
}

void doMultiply(const APInt &v1, const APInt &v2) {
  std::string cmd = getBinopCmd(v1, "*", v2);
  std::string result = getResult(cmd);
  APInt r = v1 * v2;
  std::string apresult = r.toString(10, false);
  if (result != apresult) {
    printf("ERROR: ");
    print(v1, false, false);
    printf(" * ");
    print(v2, false, false);
    printf(" = %s (not %s)\n", result.c_str(), apresult.c_str());
  }
}

void test_binops(const APInt &v1, const APInt &v2) {
  doMultiply(v1, v2);
}

void Shutdown() {
  close(input);
  close(output);
}

/* function executed by the user-interacting process. */
void test_driver(int input_pipe[], int output_pipe[]) {

  int c;    /* user input - must be 'int', to recognize EOF (= -1). */
  char ch;  /* the same - as a char. */
  int rc;   /* return values of functions. */

  /* first, close unnecessary file descriptors */
  close(input_pipe[1]); /* we don't need to write to this pipe.  */
  close(output_pipe[0]); /* we don't need to read from this pipe. */

  // Simplify input/output file descriptors
  input = input_pipe[0];
  output = output_pipe[1];

  // Make sure we close these to give gp an eof and terminate it
  sys::SetInterruptFunction(Shutdown);

  // Initialize random number generator
  srand(0);

  // Start loop over the range of bits of interest
  for (unsigned bits = 1; bits <= 256; ++bits) {
    // Indicate which test case we are running
    printf("\nTEST CASE: %d BITS\n\n", bits);
    // Gather some test data
    APInt zero(bits,0);
    APInt one(bits,1);
    APInt two(bits,2);
    APInt three(bits,3);
    APInt min = APInt::getMinValue(bits, true);
    APInt max = APInt::getMaxValue(bits, true);
    APInt mid = APIntOps::lshr(max, bits/2);
    APInt r1 = randomAPInt(bits);
    APInt r2 = randomAPInt(bits);
    APInt *list[9];
    list[0] = &zero;
    list[1] = &one;
    list[2] = &two;
    list[3] = &three;
    list[4] = &min;
    list[5] = &r1;
    list[6] = &mid;
    list[7] = &r2;
    list[8] = &max;

    // Generate and issue commands to calculator for
    // all combinations of pairs of values.
    for (unsigned i = 0; i < 9; ++i) {
      for (unsigned j = 0; j < 9; ++j) {
        test_binops(*(list[i]), *(list[j]));
      }
    }
  }

  /* close pipes and exit. */
  Shutdown();
  exit(0);
}

/* now comes the function executed by the translator process. */
void calculator(int input_pipe[], int output_pipe[])
{
    int c;    /* user input - must be 'int', to recognize EOF (= -1). */
    char ch;  /* the same - as a char. */
    int rc;   /* return values of functions. */

    printf("In translator\n");

    /* first, close unnecessary file descriptors */
    close(input_pipe[1]); /* we don't need to write to this pipe.  */
    close(output_pipe[0]); /* we don't need to read from this pipe. */

    /* set up the stdin/stdout */
    if (-1 == dup2(input_pipe[0], STDIN_FILENO)) {
      perror("dup2 for stdin");
      exit(1);
    }
    if (-1 == dup2(output_pipe[1], STDOUT_FILENO)) {
      perror("dup2 for stdout");
      exit(1);
    }

    // exec gp with modes:
    //   --quiet (don't print banner), 
    //   --fast (don't read init files) 
    //   --test (no history, wrap long lines)
    execlp("gp", "gp", "--quiet", "--fast", "--test", (char*)NULL);
    perror("execlp");
    exit(1);
}

/* and finally, the main function: spawn off two processes, */
/* and let each of them execute its function.               */
int main(int argc, char* argv[])
{
    /* 2 arrays to contain file descriptors, for two pipes. */
    int user_to_translator[2];
    int translator_to_user[2];
    int pid;       /* pid of child process, or 0, as returned via fork.    */
    int rc;        /* stores return values of various routines.            */

    /* first, create one pipe. */
    rc = pipe(user_to_translator);
    if (rc == -1) {
	perror("main: pipe user_to_translator");
	exit(1);
    }
    /* then, create another pipe. */
    rc = pipe(translator_to_user);
    if (rc == -1) {
	perror("main: pipe translator_to_user");
	exit(1);
    }

    /* now fork off a child process, and set their handling routines. */
    pid = fork();

    switch (pid) {
	case -1:	/* fork failed. */
	    perror("main: fork");
	    exit(1);
	case 0:		/* inside child process.  */
	    calculator(user_to_translator, translator_to_user); /* line 'A' */
	    /* NOT REACHED */
	default:	/* inside parent process. */
	    test_driver(translator_to_user, user_to_translator); /* line 'B' */
	    /* NOT REACHED */
    }

    return 0;	/* NOT REACHED */
}

