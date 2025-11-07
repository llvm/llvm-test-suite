typedef unsigned long long uint64_t;
typedef long long int64_t;
typedef unsigned int uint32_t;
typedef char* opaque_ptr;

// Globals
opaque_ptr _debugInfo = 0;
opaque_ptr _sourceCodeObj = 0;

// Helper functions
void disrupt_optimizer() {}

// Mock functions
uint64_t llangStackTracePushVoid(opaque_ptr context, uint32_t lineNumber, uint64_t returnCode, opaque_ptr literal, opaque_ptr debugInfo, opaque_ptr sourceCodeObj) {
  return 0;
}

int64_t llangTestProduce(opaque_ptr obj, int64_t input) {
  return input;
}

int64_t llangTestConsume(opaque_ptr obj, int64_t input) {
  return input;
}
