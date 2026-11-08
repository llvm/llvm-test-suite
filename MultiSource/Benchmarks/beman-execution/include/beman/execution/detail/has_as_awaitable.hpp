// include/beman/execution/detail/has_as_awaitable.hpp              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_HAS_AS_AWAITABLE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_HAS_AS_AWAITABLE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.is_awaitable;
#else
#include <beman/execution/detail/is_awaitable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename T, typename Promise>
concept has_as_awaitable = requires(T&& obj, Promise& promise) {
    { ::std::forward<T>(obj).as_awaitable(promise) } -> ::beman::execution::detail::is_awaitable<Promise&>;
};
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_HAS_AS_AWAITABLE
