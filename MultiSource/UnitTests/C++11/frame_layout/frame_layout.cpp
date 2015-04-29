// This file aims to test basic correctness of frame lowering done
// by the compiler.
//
// On at least the AArch64 architecture, the main potential type of
// areas in a stack frame are:
// * incoming arguments.
// * callee-saved registers
// * padding space for aligning local variables more than what's guaranteed
//   by the ABI, e.g. by C11's _Alignas keyword, C++11's alignas keyword, or
//   gnu's __attribute__((aligned__(x)))
// * local variables/spill slots
// * variable-length arrays
//
// All - or almost all? - combinations of these areas being present or
// not are possible - depending on features used in the function the
// stack frame belongs to.
//
// In this test file, templates and template meta-programming is used
// to create a function instantiation for all combinations of a
// particular area being present/non-empty on the stack frame.
// Look for the template "test_frame" function below.
//
// For each of these instantiated template functions, the following
// things are checked, to ensure the compiler correctly compiled the
// code:
// * an exception can be correctly thrown across the function.
// * check arguments values are as expected.
// * The locals/VLAs that require alignment are indeed aligned as expected,
//   and have the expected values.
// * callee-save registers were saved/restored correctly
//
// The checking is implemented by constructing a "trace" of information
// while the function is executing. After the function has executed, the
// trace is checked for expected values. A more direct implementation, e.g.
// checking values during the execution of the function, would not make
// it possible to construct some of the functions in the testing space,
// e.g. leaf functions.

#include <cstring>
#include <cassert>
#include <iostream>
#include <string>
#include <climits>
#include <vector>

/* LotsOfLiveValues is a helper class to produce high register pressure, i.e.
   lots of
   expensive-to-recompute live values. */
template <typename T> struct LotsOfLiveValues {
  __attribute__((always_inline)) LotsOfLiveValues(const T seed)
      : d1(seed), d2(d1 + d1), d3(d1 + d2), d4(d1 + d3), d5(d1 + d4),
        d6(d1 + d5), d7(d1 + d6), d8(d1 + d7), d9(d1 + d8), d10(d1 + d9),
        d11(d1 + d10), d12(d1 + d11), d13(d1 + d12), d14(d1 + d13),
        d15(d1 + d14), d16(d1 + d15), d17(d1 + d16), d18(d1 + d17),
        d19(d1 + d18), d20(d1 + d19), d21(d1 + d20), d22(d1 + d21),
        d23(d1 + d22), d24(d1 + d23), d25(d1 + d24), d26(d1 + d25),
        d27(d1 + d26), d28(d1 + d27), d29(d1 + d28), d30(d1 + d29),
        d31(d1 + d30), d32(d1 + d31), d33(d1 + d32), d34(d1 + d33),
        d35(d1 + d34), d36(d1 + d35), d37(d1 + d36), d38(d1 + d37),
        d39(d1 + d38) {}

  T d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16, d17,
      d18, d19, d20, d21, d22, d23, d24, d25, d26, d27, d28, d29, d30, d31, d32,
      d33, d34, d35, d36, d37, d38, d39;

  __attribute__((always_inline)) T makeLive() const {
    return d39 / d38 / d37 / d36 / d35 / d34 / d33 / d32 / d31 / d30 / d29 /
           d28 / d27 / d26 / d25 / d24 / d23 / d22 / d21 / d20 / d19 / d18 /
           d17 / d16 / d15 / d14 / d13 / d12 / d11 / d10 / d9 / d8 / d7 / d6 /
           d5 / d4 / d3 / d2 / d1;
  }

  __attribute__((always_inline)) T consumeLiveValues(const T dep_value) const {
    return (d1 / d2 / d3 / d4 / d5 / d6 / d7 / d8 / d9 / d10 / d11 / d12 / d13 /
            d14 / d15 / d16 / d17 / d18 / d19 / d20 / d21 / d22 / d23 / d24 /
            d25 / d26 / d27 / d28 / d29 / d30 / d31 / d32 / d33 / d34 / d35 /
            d36 / d37 / d38 / d39 / dep_value);
  }
  __attribute__((always_inline)) T produce_register_pressure() const {
    return makeLive() * consumeLiveValues(d1);
  }
};

static bool is_alignment_as_expected(const void *p,
                                     const unsigned expected_alignment) {
  return ((std::ptrdiff_t)p & (((std::ptrdiff_t)expected_alignment) - 1)) == 0;
}

template <typename T>
static bool check_and_print_value_and_alignment(
    const char *variant, const char *label, const unsigned expected_alignment,
    const void *p, const T value, const T expected_value) {
  const bool alignment_ok = is_alignment_as_expected(p, expected_alignment);
  const bool value_ok = value == expected_value;

  std::cout << variant << ", " << label
            << ", alignment: " << expected_alignment;
  if (alignment_ok && value_ok)
    std::cout << " OK";
  else {
    if (!alignment_ok)
      std::cout << " ALIGNMENT NOT AS EXPECTED: " << p;
    if (!value_ok)
      std::cout << " CONTENT NOT AS EXPECTED: " << value << " instead of "
                << expected_value;
  }
  std::cout << std::endl;

  return !(alignment_ok && value_ok);
}

union trace_element {
  void *p;
  int l;
  double d;
};

__attribute__((noinline)) bool check_trace(
    const char *variant, const char *input, const trace_element *trace,
    const double expected_d_value, const unsigned locals_alignment,
    const bool with_vla, const unsigned vla_size, const unsigned vla_alignment,
    const bool force_callee_save, const bool throw_exception,
    const int exception_value) {
  bool problem_found = false;
  // see definition of test_frame function below for what to expect & test in
  // trace.

  // 1. check argument passing
  const double d_value = trace++->d;
  problem_found = check_and_print_value_and_alignment<double>(
      variant, "arg_passing", 0, 0, d_value, expected_d_value);

  // 2. check locals
  const int aligned_int_value = trace++->l;
  const void *aligned_int_address = trace++->p;
  const double aligned_double_value = trace++->d;
  const void *aligned_double_address = trace++->p;

  problem_found |= check_and_print_value_and_alignment<int>(
      variant, "int_local", locals_alignment, aligned_int_address,
      aligned_int_value, (int)*input++);
  problem_found |= check_and_print_value_and_alignment<double>(
      variant, "double_local", locals_alignment, aligned_double_address,
      aligned_double_value, (double)*input++);

  // 3. check vla
  if (with_vla) {
    // just copy to the first and last byte in the vla to check correct vla
    // access
    const char vla_content_begin_expected = *input++;
    const char vla_content_end_expected = *input++;

    const char vla_content_begin = trace++->l;
    const void *address_of_vla_begin = trace++->p;
    const char vla_content_end = trace++->l;
    const void *address_of_vla_end = trace++->p;
    problem_found |= check_and_print_value_and_alignment<char>(
        variant, "vla_start", vla_alignment, address_of_vla_begin,
        vla_content_begin, vla_content_begin_expected);
    problem_found |= check_and_print_value_and_alignment<char>(
        variant, "vla_end", 1, address_of_vla_end, vla_content_end,
        vla_content_end_expected);
  }

  // 4. callee-save triggering
  if (force_callee_save) {
    LotsOfLiveValues<int> i(*input++);
    LotsOfLiveValues<double> d(*input++);
    const int expected_int_result = i.produce_register_pressure();
    const double expected_double_result = d.produce_register_pressure();
    problem_found |= check_and_print_value_and_alignment<char>(
        variant, "callee_save_int", 1, 0, trace++->l, expected_int_result);
    problem_found |= check_and_print_value_and_alignment<char>(
        variant, "callee_save_double", 1, 0, trace++->d,
        expected_double_result);
  }

  // 6. exception unwinding happened correctly
  int expected_exception_value = (throw_exception) ? 42 : -1;
  problem_found |= check_and_print_value_and_alignment<int>(
      variant, "thrown_value", 1, 0, exception_value, expected_exception_value);

  return problem_found;
}

void function_throwing_exception();

// 5. checking correct operation when arguments need to be passed on the stack.
//    This is done by the ...ExtraArgs variadice template argument.
template <unsigned locals_alignment, bool with_vla, unsigned vla_alignment,
          bool force_callee_save_and_spills, bool throw_exception,
          class... ExtraArgs>
__attribute__((noinline)) void test_frame(ExtraArgs..., const unsigned vla_size,
                                          const char *input,
                                          trace_element *trace,
                                          const double d_argument) {
  // 1. check argument passing
  // check correct passing of the double argument.
  // correct passing of integer/pointer arguments is already checked by this
  // function
  // using the vla_size/input/trace arguments in multiple places.
  trace++->d = d_argument;

  // 2.  checking correct access to potentially aligned locals
  volatile int aligned_int __attribute__((__aligned__(locals_alignment)));
  volatile double aligned_double __attribute__((__aligned__(locals_alignment)));
  aligned_int = (int)*input++;
  aligned_double = (double)*input++;
  trace++->l = aligned_int;
  trace++->p = (void *)&aligned_int;
  trace++->d = aligned_double;
  trace++->p = (void *)&aligned_double;

  // 3. checking correct access to potentially aligned vlas
  if (with_vla) {
    volatile char aligned_vla[vla_size]
        __attribute__((__aligned__(vla_alignment)));
    // just copy to the first and last byte in the vla to check correct vla
    // access
    aligned_vla[0] = *input++;
    aligned_vla[vla_size - 1] = *input++;

    trace++->l = aligned_vla[0];
    trace++->p = (void *)&(aligned_vla[0]);
    trace++->l = aligned_vla[vla_size - 1];
    trace++->p = (void *)&(aligned_vla[vla_size - 1]);
  }

  // 4. checking correct operation when callee-save registers are very likely to
  // be saved/restored.
  //    To do that, instantiate code with lots of overlapping live ranges that
  //    will force the
  //    register allocator to also use the callee-save registers + force use of
  //    spill/fill
  //    slots.
  if (force_callee_save_and_spills) {
    // to check correct restoring of callee-save registers, the caller of this
    // function makes
    // sure there are a lot of live ranges crossing the call to this function.
    LotsOfLiveValues<int> i(*input++);
    LotsOfLiveValues<double> d(*input++);
    trace++->l = i.produce_register_pressure();
    trace++->d = d.produce_register_pressure();
  }

  // 6. Check that the frame gets unwound correctly when an exception is thrown
  //    accros this function.
  if (throw_exception) {
    function_throwing_exception();
  }
}

const std::vector<const char *> testDescriptionHeader(
    {// read each column from top to bottom for the below to make sense.
     "AVCAE", "LLARX", "IALGC", "G|LSE", "N|E P", "E|EOT", "D| NI", " |S O",
     "L|ASN", "O|VT|", "C|EA|", "A||C|", "L||K|", "S||||", "|||||", "VVVVV",
    });

const std::string getTestDescriptionString(bool overaligned_locals,
                                           bool with_vla,
                                           bool force_callee_save_and_spills,
                                           bool ensure_args_go_on_stack,
                                           bool throw_exception) {
  return std::string("") + (overaligned_locals ? "+" : "-") +
         (with_vla ? "+" : "-") + (force_callee_save_and_spills ? "+" : "-") +
         (ensure_args_go_on_stack ? "+" : "-") + (throw_exception ? "+" : "-");
}

template <bool overaligned_locals, bool with_vla,
          bool force_callee_save_and_spills, bool ensure_args_go_on_stack,
          bool throw_exception>
__attribute__((noinline)) bool check_frame_variant(
    int seed, volatile int &dumping_ground) {
  const char *input = "abcdefghijklmnopqrstuvwxyz";
  union trace_element trace[100];
  const int vla_size = 100;
  int exception_value = -1;
  constexpr int locals_alignment = overaligned_locals ? 4096 : 2;
  constexpr int vla_alignment = 2048;
  const std::string test_description = getTestDescriptionString(
      overaligned_locals, with_vla, force_callee_save_and_spills,
      ensure_args_go_on_stack, throw_exception);
  // Need to check that callee-save registers are restored correctly, by making
  // sure all registers are live at point where test_frame is called.
  // 4. To check that callee save registers are saved & restored correctly over
  //    the function call, we're creating lots of live ranges across the call
  //    to test_frame, in the hope that this will force the register allocator
  //    to store live information into the callee save registers.
  LotsOfLiveValues<double> liveValues_double(seed);
  LotsOfLiveValues<int> liveValues_int(seed);
  const double d_value =
      liveValues_double.makeLive() + liveValues_int.makeLive();
  try {
    if (ensure_args_go_on_stack) {
      // add lots of extra dummy arguments to make the information-passing
      // argument go on
      // the stack instead of registers.
      // Assume that 20 integer and 20 floating point values is enough to
      // completely
      // fill up the available registers for argument passing
      test_frame<locals_alignment, with_vla, vla_alignment,
                 force_callee_save_and_spills, throw_exception, int, int, int,
                 int, int, int, int, int, int, int, int, int, int, int, int,
                 int, int, int, int, int, double, double, double, double,
                 double, double, double, double, double, double, double, double,
                 double, double, double, double, double, double, double,
                 double>(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, vla_size, input, trace, d_value);
    } else {
      test_frame<locals_alignment, with_vla, vla_alignment,
                 force_callee_save_and_spills, throw_exception>(vla_size, input,
                                                                trace, d_value);
    }
    dumping_ground += (int)(liveValues_double.consumeLiveValues(trace[0].d) +
                            liveValues_int.consumeLiveValues(trace[0].l));
  } catch (int i) {
    exception_value = i;
  }
  return check_trace(test_description.c_str(), input, trace, d_value,
                     locals_alignment, with_vla, vla_size, vla_alignment,
                     force_callee_save_and_spills, throw_exception,
                     exception_value);
}

int main() {
  bool problem_found = false;
  volatile int dumping_ground;
  const int seed = 42;
  for (auto &s : testDescriptionHeader)
    std::cout << s << std::endl;
  const bool T = true;
  const bool F = false;
  problem_found |= check_frame_variant<T, F, F, F, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, F, F, F, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<T, T, F, F, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, T, F, F, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<T, F, T, F, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, F, T, F, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<T, T, T, F, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, T, T, F, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<T, F, F, T, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, F, F, T, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<T, T, F, T, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, T, F, T, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<T, F, T, T, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, F, T, T, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<T, T, T, T, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, T, T, T, F>(seed, dumping_ground);
  problem_found |= check_frame_variant<T, F, F, F, T>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, F, F, F, T>(seed, dumping_ground);
  problem_found |= check_frame_variant<T, T, F, F, T>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, T, F, F, T>(seed, dumping_ground);
  problem_found |= check_frame_variant<T, F, T, F, T>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, F, T, F, T>(seed, dumping_ground);
  problem_found |= check_frame_variant<T, T, T, F, T>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, T, T, F, T>(seed, dumping_ground);
  problem_found |= check_frame_variant<T, F, F, T, T>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, F, F, T, T>(seed, dumping_ground);
  problem_found |= check_frame_variant<T, T, F, T, T>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, T, F, T, T>(seed, dumping_ground);
  problem_found |= check_frame_variant<T, F, T, T, T>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, F, T, T, T>(seed, dumping_ground);
  problem_found |= check_frame_variant<T, T, T, T, T>(seed, dumping_ground);
  problem_found |= check_frame_variant<F, T, T, T, T>(seed, dumping_ground);
  return problem_found ? -1 : 0;
}
