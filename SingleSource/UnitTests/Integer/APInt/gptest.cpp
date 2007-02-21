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
  const char *command = cmd.c_str();
  if (-1 == write(output, command, cmd.size())) {
    std::string msg = "write: " + cmd;
    msg.resize(msg.size()-1);
    perror(msg.c_str());
    exit(1);
  }
   usleep(1); // try to switch contexts
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


bool getCompare(const APInt &v1, const std::string &op, 
                const APInt &v2, bool wantSigned = false) {

  std::string cmd = v1.toString(10, wantSigned) + op + 
                    v2.toString(10, wantSigned) + '\n';
  std::string result = getResult(cmd);
  return bool(atoi(result.c_str()));
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
    report(v1,v2," % ", result,apresult);
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

void doComparisons(const APInt &v1, const APInt &v2) {
  bool result = getCompare(v1, "==", v2);
  bool apresult = v1 == v2;
  if (result != apresult)
    report(v1,v2," == ", (result?"true":"false"), (apresult?"true":"false"));
  result = getCompare(v1, "!=", v2);
  apresult = v1 != v2;
  if (result != apresult)
    report(v1,v2," != ", (result?"true":"false"), (apresult?"true":"false"));
  result = getCompare(v1, "<", v2);
  apresult = v1.ult(v2);
  if (result != apresult)
    report(v1,v2," < ", (result?"true":"false"), (apresult?"true":"false"));
  result = getCompare(v1, "<=", v2);
  apresult = v1.ule(v2);
  if (result != apresult)
    report(v1,v2," <= ", (result?"true":"false"), (apresult?"true":"false"));
  result = getCompare(v1, ">", v2);
  apresult = v1.ugt(v2);
  if (result != apresult)
    report(v1,v2," > ", (result?"true":"false"), (apresult?"true":"false"));
  result = getCompare(v1, ">=", v2);
  apresult = v1.uge(v2);
  if (result != apresult)
    report(v1,v2," >= ", (result?"true":"false"), (apresult?"true":"false"));
}

void test_binops(const APInt &v1, const APInt &v2) {
  doAdd(v1,v2);
  doSubtract(v1,v2);
  doMultiply(v1, v2);
  doDivide(v1, v2);
  doComparisons(v1, v2);
}

void Shutdown() {
  // Be nice and tell gp to stop
  write(output, "quit\n", 5);
  // Close our descriptors
  close(input);
  close(output); // gp will get SIGPIPE if not terminated
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
  for (unsigned bits = 1; bits <= 1024; bits++) {
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

