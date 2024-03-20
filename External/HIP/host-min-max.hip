#include <algorithm>
#include <cstdlib>t
#include <hip/hip_runtime.h>
#include <iostream>
#include <map>
#include <string>
#include <type_traits>
#include <typeinfo>

// Convert typeid name to C++ type name
std::string demangle(const char *name) {
  static const std::map<char, std::string> demangleMap = {
      {'i', "int"},       {'f', "float"},
      {'d', "double"},    {'j', "unsigned int"},
      {'l', "long"},      {'m', "unsigned long"},
      {'x', "long long"}, {'y', "unsigned long long"}};

  auto it = demangleMap.find(name[0]);
  if (it != demangleMap.end()) {
    return it->second;
  } else {
    return std::string(name);
  }
}

void checkHipCall(hipError_t status, const char *msg) {
  if (status != hipSuccess) {
    std::cerr << "HIP Error: " << msg << " - " << hipGetErrorString(status)
              << std::endl;
    std::abort();
  }
}

template <typename T1, typename T2>
void compareResults(T1 hipResult, T2 stdResult, const std::string &testName) {
  using CommonType = typename std::common_type<T1, T2>::type;
  if (static_cast<CommonType>(hipResult) !=
      static_cast<CommonType>(stdResult)) {
    std::cerr << testName << " mismatch: HIP result " << hipResult << " ("
              << demangle(typeid(hipResult).name()) << "), std result "
              << stdResult << " (" << demangle(typeid(stdResult).name()) << ")"
              << std::endl;
    std::abort();
  }
}

template <typename T1, typename T2> void runTest(T1 a, T2 b) {
  std::cout << "\nTesting with values: " << a << " ("
            << demangle(typeid(a).name()) << ") and " << b << " ("
            << demangle(typeid(b).name()) << ")" << std::endl;

  // Using std::min and std::max as reference
  // The two arguments are converted to std::common_type first then passed
  // to std::min/max. This assumes compatiblity with CUDA.
  using CommonType = typename std::common_type<T1, T2>::type;
  CommonType stdMinResult = std::min<CommonType>(a, b);
  CommonType stdMaxResult = std::max<CommonType>(a, b);
  std::cout << "Host std::min result: " << stdMinResult
            << " (Type: " << demangle(typeid(stdMinResult).name()) << ")"
            << std::endl;
  std::cout << "Host std::max result: " << stdMaxResult
            << " (Type: " << demangle(typeid(stdMaxResult).name()) << ")"
            << std::endl;

  // Using HIP's global min/max functions
  CommonType hipMinResult = min(a, b);
  CommonType hipMaxResult = max(a, b);
  std::cout << "Host HIP min result: " << hipMinResult
            << " (Type: " << demangle(typeid(hipMinResult).name()) << ")"
            << std::endl;
  std::cout << "Host HIP max result: " << hipMaxResult
            << " (Type: " << demangle(typeid(hipMaxResult).name()) << ")"
            << std::endl;

  // Ensure the host HIP and std results match
  compareResults(hipMinResult, stdMinResult, "HIP vs std min");
  compareResults(hipMaxResult, stdMaxResult, "HIP vs std max");
}

int main() {
  checkHipCall(hipSetDevice(0), "hipSetDevice failed");

  // For mixed signed/unsigned integer arguments, assuming CUDA compatibility,
  // i.e. the signed integer is implicitly converted to unsigned type and then
  // compared.
  runTest(10uLL, -5LL);             // Testing with unsigned int and long long
  runTest(-15, 20u);                // Testing with int and unsigned int
  runTest(2147483647, 2147483648u); // Testing with int and unsigned int
  runTest(
      -922337203685477580LL,
      922337203685477580uLL); // Testing with long long and unsigned long long
  runTest(2.5f, 3.14159);     // Testing with float and double

  std::cout << "\nPass\n";
  return 0;
}
