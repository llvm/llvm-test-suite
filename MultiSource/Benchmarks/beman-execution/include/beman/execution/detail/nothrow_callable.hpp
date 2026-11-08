// include/beman/execution/detail/nothrow_callable.hpp              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_NOTHROW_CALLABLE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_NOTHROW_CALLABLE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.callable;
#else
#include <beman/execution/detail/callable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Fun, typename... Args>
concept nothrow_callable = ::beman::execution::detail::callable<Fun, Args...> && requires(Fun&& fun, Args&&... args) {
    { ::std::forward<Fun>(fun)(::std::forward<Args>(args)...) } noexcept;
};
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_NOTHROW_CALLABLE
