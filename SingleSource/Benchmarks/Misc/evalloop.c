/* 
 * A performance regression test for using the GCC "labels as values" extension
 * and computed gotos to optimize the interpreter loop. This is a trick that has
 * been used by, at least, python, webkit, ruby and dalvik. See:
 * http://eli.thegreenplace.net/2012/07/12/computed-goto-for-efficient-dispatch-tables
 * for a detailed description.
 * 
 * Some uses of this trick, notably python's, can create critical edges in the
 * control flow graph which we must break to achieve reasonable performance.
 */

#include <stdio.h>
#include <stdint.h>

#define TARGET(op) \
        L##op: \
        opcode = op; \
        case op:

uint32_t sum = 0;

void execute(int code) __attribute__((noinline));
void eval(int *p)  __attribute__((noinline));

void execute(int code) {
  sum += code;
}

void eval(int *p)  {
  static void *dispatch[32] = {
   &&L0,
   &&L1,
   &&L2,
   &&L3,
   &&L4,
   &&L5,
   &&L6,
   &&L7,
   &&L8,
   &&L9,
   &&L10,
   &&L11,
   &&L12,
   &&L13,
   &&L14,
   &&L15,
   &&L16,
   &&L17,
   &&L18,
   &&L19,
   &&L20,
   &&L21,
   &&L22,
   &&L23,
   &&L24,
   &&L25,
   &&L26,
   &&L27,
   &&L28,
   &&L29,
   &&L30,
   &&L31   
  };

  int opcode = 0;
  while (1) {    
    switch(*p++) {
      TARGET(0) { return; }
      TARGET(1) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(2) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(3) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(4) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(5) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(6) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(7) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(8) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(9) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(10) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(11) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(12) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(13) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(14) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(15) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(16) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(17) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(18) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(19) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(20) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(21) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(22) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(23) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(24) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(25) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(26) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(27) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(28) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(29) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(30) { execute (opcode); goto *dispatch[*p++]; }
      TARGET(31) { execute (opcode); goto *dispatch[*p++]; }
    }
  }
}

int main() {
  const int BUFSIZE = 2048;
  // Initialize the command buffer. This must end with a 0, which is the
  // "exit" command for the interpreter loop.
  int cmds[BUFSIZE];
  for (int i = 0; i < BUFSIZE - 1; ++i)
    cmds[i] = i % 31 + 1;
  cmds[BUFSIZE - 1] = 0;

  // Run the interpreter loop over the buffer enough times to get a performance
  // estimate.
  for (int i = 0; i < 100000; ++i) {
    eval(cmds);
  }
  
  printf("Sum: %u\n", sum);
  return 0;
}
