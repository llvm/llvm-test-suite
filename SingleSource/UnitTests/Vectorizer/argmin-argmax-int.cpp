#include "argmin-argmax-common.h"

int main(void) {
  rng = std::mt19937(15);

  // Run tests for unsigned 8-bit types
  RUN_ALL_TESTS_FOR_TYPE(uint8_t, uint8_t)
  RUN_PRED_TESTS_FOR_TYPE(uint8_t, uint8_t)

  // Run tests for unsigned 16-bit types
  RUN_ALL_TESTS_FOR_TYPE(uint16_t, uint16_t)
  RUN_PRED_TESTS_FOR_TYPE(uint16_t, uint16_t)

  // Run tests for unsigned 32-bit types
  RUN_ALL_TESTS_FOR_TYPE(uint32_t, uint32_t)
  RUN_PRED_TESTS_FOR_TYPE(uint32_t, uint32_t)
  RUN_VF_IC_TESTS_FOR_TYPE(uint32_t, uint32_t)

  // Run tests for unsigned 64-bit types
  RUN_ALL_TESTS_FOR_TYPE(uint64_t, uint64_t)
  RUN_PRED_TESTS_FOR_TYPE(uint64_t, uint64_t)
  RUN_VF_IC_TESTS_FOR_TYPE(uint64_t, uint64_t)

  // Run tests for signed 8-bit types
  RUN_ALL_TESTS_FOR_TYPE(int8_t, int8_t)
  RUN_PRED_TESTS_FOR_TYPE(int8_t, int8_t)

  // Run tests for signed 16-bit types
  RUN_ALL_TESTS_FOR_TYPE(int16_t, int16_t)
  RUN_PRED_TESTS_FOR_TYPE(int16_t, int16_t)

  // Run tests for signed 32-bit types
  RUN_ALL_TESTS_FOR_TYPE(int32_t, int32_t)
  RUN_PRED_TESTS_FOR_TYPE(int32_t, int32_t)
  RUN_VF_IC_TESTS_FOR_TYPE(int32_t, int32_t)

  // Run tests for signed 64-bit types
  RUN_ALL_TESTS_FOR_TYPE(int64_t, int64_t)
  RUN_PRED_TESTS_FOR_TYPE(int64_t, int64_t)

  // Run tests with mixed signedness (unsigned min, signed idx)
  RUN_ALL_TESTS_FOR_TYPE(uint8_t, int8_t)
  RUN_PRED_TESTS_FOR_TYPE(uint8_t, int8_t)

  RUN_ALL_TESTS_FOR_TYPE(uint16_t, int16_t)
  RUN_PRED_TESTS_FOR_TYPE(uint16_t, int16_t)

  RUN_ALL_TESTS_FOR_TYPE(uint32_t, int32_t)
  RUN_PRED_TESTS_FOR_TYPE(uint32_t, int32_t)

  RUN_ALL_TESTS_FOR_TYPE(uint64_t, int64_t)
  RUN_PRED_TESTS_FOR_TYPE(uint64_t, int64_t)

  // Run tests with mixed signedness (signed min, unsigned idx)
  RUN_ALL_TESTS_FOR_TYPE(int8_t, uint8_t)
  RUN_PRED_TESTS_FOR_TYPE(int8_t, uint8_t)

  RUN_ALL_TESTS_FOR_TYPE(int16_t, uint16_t)
  RUN_PRED_TESTS_FOR_TYPE(int16_t, uint16_t)

  RUN_ALL_TESTS_FOR_TYPE(int32_t, uint32_t)
  RUN_PRED_TESTS_FOR_TYPE(int32_t, uint32_t)

  RUN_ALL_TESTS_FOR_TYPE(int64_t, uint64_t)
  RUN_PRED_TESTS_FOR_TYPE(int64_t, uint64_t)

  // Run truncation tests with original type combination
  RUN_TRUNC_TESTS_FOR_TYPE(uint64_t, uint32_t)

  // Run mismatch tests only for uint64_t (matching original scope)
  T_2PRED("mixed", uint64_t, uint64_t, std::numeric_limits<uint64_t>::max(), >=,
          <=, "_predicate_mismatch_0")
  T_2PRED_REV("mixed", uint64_t, uint64_t, std::numeric_limits<uint64_t>::max(),
              <=, >=, "_predicate_mismatch_1")

  return 0;
}
