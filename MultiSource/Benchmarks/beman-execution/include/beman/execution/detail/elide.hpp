// include/beman/execution/detail/elide.hpp                          -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_ELIDE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_ELIDE

#include <beman/execution/detail/common.hpp>
#include <beman/execution/detail/suppress_push.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <functional>
#include <type_traits>
#include <utility>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {

/// Helper to elide move construction of a value when it is only used once.
///
/// Uses a small lambda and conversion operator to elide the move construction.
template <std::invocable F>
struct elide {
    /// The resulting type of the elision.
    using result_t = std::invoke_result_t<F>;

    /// Constructs the elision wrapper from callable `f`.
    elide(F&& f) noexcept(noexcept(F(::std::forward<F>(f)))) : f_(::std::forward<F>(f)) {}

    /// Evaluates the callable given at construction and returns the result, eliding the move construction of the
    /// result.
    operator result_t() && noexcept(::std::is_nothrow_invocable_v<F>) { return ::std::invoke(::std::forward<F>(f_)); }

  private:
    /// The callable to evaluate when the elision is converted to the result type.
    F f_;
};

} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_ELIDE
