// include/beman/execution/detail/with_await_transform.hpp          -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_WITH_AWAIT_TRANSFORM
#define INCLUDED_BEMAN_EXECUTION_DETAIL_WITH_AWAIT_TRANSFORM

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.has_as_awaitable;
#else
#include <beman/execution/detail/has_as_awaitable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
// NOLINTBEGIN(bugprone-crtp-constructor-accessibility)
template <typename Derived>
struct with_await_transform {
    template <typename T>
    auto await_transform(T&& obj) noexcept -> T&& {
        return ::std::forward<T>(obj);
    }

    template <::beman::execution::detail::has_as_awaitable<Derived> T>
    auto await_transform(T&& obj) noexcept(noexcept(::std::forward<T>(obj).as_awaitable(::std::declval<Derived&>())))
        -> decltype(auto) {
        return ::std::forward<T>(obj).as_awaitable(static_cast<Derived&>(*this));
    }
};
// NOLINTEND(bugprone-crtp-constructor-accessibility)
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_WITH_AWAIT_TRANSFORM
