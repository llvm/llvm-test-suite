# A test from beman.execution, an implementation of C++26 std::execution
# (P2300) built on concepts and coroutines. See README.md.

# CMAKE_CXX_STANDARD 23 needs CMake 3.20.
if(CMAKE_VERSION VERSION_LESS 3.20)
  message(STATUS "Skipping beman-execution: it needs CMake 3.20")
  return()
endif()
set(CMAKE_CXX_STANDARD 23)

include(CheckCXXSourceCompiles)
check_cxx_source_compiles("
#include <concepts>
#include <coroutine>
#if __cplusplus < 202302L || !defined(__cpp_impl_coroutine)
#error
#endif
#if !defined(__cpp_concepts) || __cpp_concepts < 202002L
#error
#endif
int main() {}
" BEMAN_EXECUTION_HAVE_CXX23)
if(NOT BEMAN_EXECUTION_HAVE_CXX23)
  message(STATUS "Skipping beman-execution: it needs C++23 with concepts and coroutines")
  return()
endif()

list(APPEND CPPFLAGS -I${CMAKE_CURRENT_SOURCE_DIR}/include)
llvm_multisource(beman-execution-awaitable_senders)
