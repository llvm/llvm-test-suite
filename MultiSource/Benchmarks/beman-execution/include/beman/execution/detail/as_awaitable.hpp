// include/beman/execution/detail/as_awaitable.hpp                  -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_AS_AWAITABLE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_AS_AWAITABLE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <coroutine>
#include <functional>
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.env_of_t;
import beman.execution.detail.get_await_completion_adaptor;
import beman.execution.detail.get_awaiter;
import beman.execution.detail.get_env;
import beman.execution.detail.query_with_default;
import beman.execution.detail.is_awaitable;
import beman.execution.detail.is_awaiter;
import beman.execution.detail.sender_awaitable;
import beman.execution.detail.single_sender;
import beman.execution.detail.transform_sender;
#else
#include <beman/execution/detail/env_of_t.hpp>
#include <beman/execution/detail/get_await_completion_adaptor.hpp>
#include <beman/execution/detail/get_awaiter.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/query_with_default.hpp>
#include <beman/execution/detail/is_awaitable.hpp>
#include <beman/execution/detail/is_awaiter.hpp>
#include <beman/execution/detail/sender_awaitable.hpp>
#include <beman/execution/detail/single_sender.hpp>
#include <beman/execution/detail/transform_sender.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Sndr>
auto adapt_for_await_completion(Sndr&& sndr) {
    auto adaptor = ::beman::execution::detail::query_with_default(
        ::beman::execution::get_await_completion_adaptor, ::beman::execution::get_env(sndr), ::std::identity{});
    return adaptor(::std::forward<Sndr>(sndr));
}

template <typename Expr, typename Promise>
auto transform_and_adapt_for_await_completion(Expr&& expr, Promise& promise) {
    auto sndr = ::beman::execution::transform_sender(::std::forward<Expr>(expr), ::beman::execution::get_env(promise));
    return ::beman::execution::detail::adapt_for_await_completion(::std::move(sndr));
}

template <typename Expr, typename Promise>
using await_completion_sender_t = decltype(::beman::execution::detail::transform_and_adapt_for_await_completion(
    ::std::declval<Expr>(), ::std::declval<Promise&>()));

template <typename Expr, typename Promise>
concept await_completion_sender =
    ::beman::execution::detail::single_sender<Expr, ::beman::execution::env_of_t<Promise>> &&
    requires { typename ::beman::execution::detail::await_completion_sender_t<Expr, Promise>; };

template <typename Expr, typename Promise>
concept has_await_completion_as_awaitable =
    ::beman::execution::detail::await_completion_sender<Expr, Promise> && requires(Promise& promise) {
        ::std::declval<::beman::execution::detail::await_completion_sender_t<Expr, Promise>>().as_awaitable(promise);
    };

template <typename Expr, typename Promise>
concept directly_awaitable = requires {
    {
        ::beman::execution::detail::get_awaiter(::std::declval<Expr>())
    } -> ::beman::execution::detail::is_awaiter<Promise>;
};
} // namespace beman::execution::detail

namespace beman::execution {
/*!
 * \brief Turn an entity, e.g., a sender, into an awaitable.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
struct as_awaitable_t {
    template <typename Expr, typename Promise>
    auto operator()(Expr&& expr, Promise& promise) const -> decltype(auto) {
        if constexpr (requires { ::std::forward<Expr>(expr).as_awaitable(promise); }) {
            static_assert(
                ::beman::execution::detail::is_awaitable<decltype(::std::forward<Expr>(expr).as_awaitable(promise)),
                                                         Promise>,
                "as_awaitable must return an awaitable");
            return ::std::forward<Expr>(expr).as_awaitable(promise);
        } else if constexpr (::beman::execution::detail::has_await_completion_as_awaitable<Expr, Promise>) {
            using result_t =
                decltype(::std::declval<::beman::execution::detail::await_completion_sender_t<Expr, Promise>>()
                             .as_awaitable(::std::declval<Promise&>()));
            static_assert(::beman::execution::detail::is_awaitable<result_t, Promise>,
                          "as_awaitable must return an awaitable");
            auto sndr = ::beman::execution::detail::transform_and_adapt_for_await_completion(
                ::std::forward<Expr>(expr), promise);
            return ::std::move(sndr).as_awaitable(promise);
        } else if constexpr (::beman::execution::detail::directly_awaitable<Expr, Promise>) {
            return (static_cast<void>(promise), ::std::forward<Expr>(expr));
        } else if constexpr (::beman::execution::detail::await_completion_sender<Expr, Promise>) {
            auto sndr = ::beman::execution::detail::transform_and_adapt_for_await_completion(
                ::std::forward<Expr>(expr), promise);
            return ::beman::execution::detail::sender_awaitable<decltype(sndr), Promise>{::std::move(sndr), promise};
        } else {
            return (static_cast<void>(promise), ::std::forward<Expr>(expr));
        }
    }
};
inline constexpr ::beman::execution::as_awaitable_t as_awaitable{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_AS_AWAITABLE
