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
#include "llvm/ADT/StringExtras.h"
#include "llvm/System/Signals.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace llvm;

static int input = 0, output = 0;

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

std::string getResult(const std::string& cmd) {
#if 0
  printf("Command: %s", cmd.c_str());
  fflush(stdout);
#endif
  const char *command = cmd.c_str();
  if (-1 == write(output, command, cmd.size())) {
    std::string msg = "write: " + cmd;
    msg.resize(msg.size()-1);
    perror(msg.c_str());
    exit(1);
  }
  char buf[4096];
  int len = read(input, buf, 4095);
  if (-1 == len) {
    std::string msg = "read: " + cmd;
    msg.resize(msg.size()-1);
    perror(msg.c_str());
    exit(1);
  }
  buf[len] = 0;
  // Clear the trailing newline
  if (char * nl = strrchr(buf, '\n'))
    *nl = 0;
  return std::string(buf);
}

std::string getBinop(const APInt &v1, const std::string &op, 
                     const APInt &v2, bool wantSigned = false) {
  APInt mask = APInt::getAllOnesValue(v1.getBitWidth());
  std::string cmd;
  cmd += "bitand(truncate(";
  cmd += v1.toString(10,wantSigned);
  cmd += " " + op + " ";
  cmd += v2.toString(10,wantSigned);
  cmd += "), bitneg(0," + utostr(unsigned(v1.getBitWidth())) + "))\n";
  return getResult(cmd);
}

void report(const APInt &v1, const APInt &v2, const std::string& op, 
            const std::string& result, const std::string& apresult) {
  print(v1, false, false);
  printf(op.c_str());
  print(v2, false, false);
  printf(" = %s (not %s)\n", result.c_str(), apresult.c_str());
  fflush(stdout);
}

void doMultiply(const APInt &v1, const APInt &v2) {
  std::string result = getBinop(v1, "*", v2);
  APInt r = v1 * v2;
  std::string apresult = r.toString(10, false);
  if (result != apresult) 
    report(v1,v2," * ", result,apresult);
}

void doDivide(const APInt &v1, const APInt &v2) {
  if (v2 == APInt(v2.getBitWidth(),0))
    return;
  std::string result = getBinop(v1, "/", v2);
  APInt r = APIntOps::udiv(v1, v2);
  std::string apresult = r.toString(10, false);
  if (result != apresult)
    report(v1,v2," / ", result,apresult);
}

void doRemainder(const APInt &v1, const APInt &v2) {
  if (v2 == APInt(v2.getBitWidth(),0))
    return;
  std::string result = getBinop(v1, "%", v2);
  APInt r = APIntOps::urem(v1, v2);
  std::string apresult = r.toString(10, false);
  if (result != apresult)
    report(v1,v2," %% ", result,apresult);
}

void doAdd(const APInt &v1, const APInt &v2) {
  std::string result = getBinop(v1, "+", v2);
  APInt r = v1 + v2;
  std::string apresult = r.toString(10, false);
  if (result != apresult)
    report(v1,v2," + ", result,apresult);
}

void doSubtract(const APInt &v1, const APInt &v2) {
  std::string result = getBinop(v1, "-", v2);
  APInt r = v1 - v2;
  std::string apresult = r.toString(10, false);
  if (result != apresult)
    report(v1,v2," - ", result,apresult);
}

void doAnd(const APInt &v1, const APInt &v2) {
  std::string cmd;
  cmd += "bitand(";
  cmd += v1.toString(10,false);
  cmd += ",";
  cmd += v2.toString(10,false);
  cmd += ")\n";
  std::string result = getResult(cmd);
  APInt r = v1 & v2;
  std::string apresult = r.toString(10, false);
  if (result != apresult)
    report(v1, v2, " and ", result,apresult);
}

void doOr(const APInt &v1, const APInt &v2) {
  std::string cmd;
  cmd += "bitor(";
  cmd += v1.toString(10,false);
  cmd += ",";
  cmd += v2.toString(10,false);
  cmd += ")\n";
  std::string result = getResult(cmd);
  APInt r = v1 | v2;
  std::string apresult = r.toString(10, false);
  if (result != apresult)
    report(v1, v2, " or ", result,apresult);
}

void doXor(const APInt &v1, const APInt &v2) {
  std::string cmd;
  cmd += "bitxor(";
  cmd += v1.toString(10,false);
  cmd += ",";
  cmd += v2.toString(10,false);
  cmd += ")\n";
  std::string result = getResult(cmd);
  APInt r = v1 ^ v2;
  std::string apresult = r.toString(10, false);
  if (result != apresult)
    report(v1, v2, " xor ", result,apresult);
}

void doComplement(const APInt &v1) {
  std::string cmd;
  cmd += "bitneg(";
  cmd += v1.toString(10,false);
  cmd += "," + utostr(v1.getBitWidth()) + ")\n";
  std::string result = getResult(cmd);
  APInt r = ~v1;
  std::string apresult = r.toString(10, false);
  if (result != apresult) {
    printf("~ ");
    print(v1, false, false);
    printf(" = %s (not %s)\n", result.c_str(), apresult.c_str());
    fflush(stdout);
  }
}

void doBitTest(const APInt &v1) {
  for (int i = 0; i < v1.getBitWidth(); i++) {
    std::string cmd;
    cmd += "bittest(";
    cmd += v1.toString(10,false);
    cmd += "," + utostr(i) + ")\n";
    bool gpresult = atoi(getResult(cmd).c_str());
    bool apresult = v1[i];
    if (gpresult != apresult) {
      print(v1, false, false);
      printf("[%d] = %s (not %s)\n", i,
        (gpresult?"true":"false"), (apresult?"true":"false"));
      fflush(stdout);
    }
  }
}

void doShift(const APInt &v1) {
  APInt mask = APInt::getAllOnesValue(v1.getBitWidth());
  for (int i = 1; i <= v1.getBitWidth(); i++) {
    std::string cmd;
    cmd += "bitand(truncate(shift(";
    cmd += v1.toString(10,false);
    cmd += "," + utostr(unsigned(i)) + ")), ";
    cmd += "bitneg(0," + utostr(unsigned(v1.getBitWidth())) + "))\n";
    std::string gpresult = getResult(cmd);
    APInt R1 = v1.shl(i);
    std::string apresult = R1.toString(10,false);
    if (gpresult != apresult) {
      print(v1, false, false);
      printf(" << %d = %s (not %s)\n", i, gpresult.c_str(), apresult.c_str());
      fflush(stdout);
    }
    cmd = "bitand(truncate(shift(";
    cmd += v1.toString(10,false);
    cmd += ",-" + utostr(i) + ")), ";
    cmd += "bitneg(0," + utostr(unsigned(v1.getBitWidth())) + "))\n";
    gpresult = getResult(cmd);
    R1 = v1.lshr(i);
    apresult = R1.toString(10,false);
    if (gpresult != apresult) {
      print(v1, false, false);
      printf(" u>> %d = %s (not %s)\n", i, gpresult.c_str(), apresult.c_str());
      fflush(stdout);
    }
  }
}

void doCompare(const APInt &v1, const std::string &op, 
                const APInt &v2, bool apresult) {
  std::string cmd = v1.toString(10, false) + op + 
                    v2.toString(10, false) + '\n';
  bool gpresult = atoi(getResult(cmd).c_str());
  if (gpresult != apresult)
    report(v1,v2, op, (apresult?"true":"false"), (apresult?"true":"false"));
}

void test_binops(const APInt &v1, const APInt &v2) {
  doAdd(v1,v2);
  doSubtract(v1,v2);
  doMultiply(v1, v2);
  doDivide(v1, v2);
  doRemainder(v1,v2);
  doAnd(v1,v2);
  doOr(v1,v2);
  doXor(v1,v2);
  doCompare(v1, "==", v2, v1 == v2);
  doCompare(v1, "!=", v2, v1 != v2);
  doCompare(v1, "< ", v2, v1.ult(v2));
  doCompare(v1, "<=", v2, v1.ule(v2));
  doCompare(v1, "> ", v2, v1.ugt(v2));
  doCompare(v1, ">=", v2, v1.uge(v2));
}

void Shutdown() {
  // Be nice and tell gp to stop
  write(output, "quit\n", 5);
  // Close our descriptors
  close(input);
  close(output); // gp will get SIGPIPE if not terminated
}

/* function executed by the user-interacting process. */
void test_driver(int low, int high, int input_pipe[], int output_pipe[]) {

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
  for (int bits = low; bits <= high; bits++) {
    // Indicate which test case we are running
    printf("\nTEST CASE: %d BITS\n", bits);
    fflush(stdout);
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
      doComplement(*(list[i]));
      doBitTest(*(list[i]));
      doShift(*(list[i]));
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
    if (-1 == dup2(output_pipe[1], STDERR_FILENO)) {
      perror("dup2 for stderr");
      exit(1);
    }

    // exec gp with modes:
    //   --quiet (don't print banner), 
    //   --fast (don't read init files) 
    execlp("gp", "gp", "--quiet", "--fast", (char*)NULL);
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
    int low_bit = 1;
    int high_bit = 1024;

    // Get the arguments
    if (argc > 2) {
      low_bit = atoi(argv[1]);
      high_bit = atoi(argv[2]);
    }

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
	    calculator(user_to_translator, translator_to_user);
	    /* NOT REACHED */
	default:	/* inside parent process. */
	    test_driver(low_bit, high_bit, translator_to_user, user_to_translator);
	    /* NOT REACHED */
    }

    return 0;	/* NOT REACHED */
}

