// include/beman/execution/detail/unreachable.hpp                  -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_UNREACHABLE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_UNREACHABLE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <exception>
#include <utility>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
[[noreturn]] inline auto unreachable() -> void {
#ifdef __cpp_lib_unreachable
    ::std::unreachable();
#else
    ::std::terminate();
#endif
}
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_UNREACHABLE
