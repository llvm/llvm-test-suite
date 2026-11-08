// include/beman/execution/detail/get_awaiter.hpp                   -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_GET_AWAITER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_GET_AWAITER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Expr, typename... Promise>
    requires(sizeof...(Promise) <= 1)
auto get_awaiter(Expr&& expr, Promise&... promise) -> decltype(auto) {
    auto transform{[&]() -> decltype(auto) {
        if constexpr (sizeof...(Promise) == 1 &&
                      requires { (..., promise.await_transform(::std::forward<Expr>(expr))); })
            return (..., promise.await_transform(::std::forward<Expr>(expr)));
        else
            return ::std::forward<Expr>(expr);
    }};
    if constexpr (requires { operator co_await(transform()); }) {

        static_assert(not requires { transform().operator co_await(); }, "only one operator co_await is allowed");
        return operator co_await(transform());
    } else if constexpr (requires { transform().operator co_await(); })
        return transform().operator co_await();
    else
        return transform();
}
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_GET_AWAITER
