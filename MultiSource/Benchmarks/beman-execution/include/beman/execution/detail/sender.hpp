// include/beman/execution/detail/sender.hpp                        -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.env;
import beman.execution.detail.env_promise;
import beman.execution.detail.get_env;
import beman.execution.detail.is_awaitable;
import beman.execution.detail.queryable;
#else
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/env_promise.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/is_awaitable.hpp>
#include <beman/execution/detail/queryable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
struct sender_tag {};

using sender_t [[deprecated("sender_t has been renamed sender_tag")]] = sender_tag;
} // namespace beman::execution
namespace beman::execution::detail {
template <typename Sender>
concept is_sender = ::std::derived_from<typename Sender::sender_concept, ::beman::execution::sender_tag>;

template <typename Sender>
concept enable_sender =
    ::beman::execution::detail::is_sender<Sender> ||
    ::beman::execution::detail::is_awaitable<Sender,
                                             ::beman::execution::detail::env_promise<::beman::execution::env<>>>;
} // namespace beman::execution::detail
namespace beman::execution {
template <typename Sender>
inline constexpr bool enable_sender = ::beman::execution::detail::enable_sender<Sender>;

template <typename Sender>
concept sender = ::beman::execution::enable_sender<::std::remove_cvref_t<Sender>> &&
                 requires(const ::std::remove_cvref_t<Sender>& sndr) {
                     { ::beman::execution::get_env(sndr) } -> ::beman::execution::detail::queryable;
                 } && ::std::move_constructible<::std::remove_cvref_t<Sender>> &&
                 ::std::constructible_from<::std::remove_cvref_t<Sender>, Sender>;
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER
