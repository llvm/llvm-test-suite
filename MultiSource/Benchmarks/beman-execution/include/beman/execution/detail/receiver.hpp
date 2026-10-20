// include/beman/execution/detail/receiver.hpp                      -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_RECEIVER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_RECEIVER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.get_env;
import beman.execution.detail.queryable;
#else
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/queryable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
struct receiver_tag {};

using receiver_t [[deprecated("receiver_t has been renamed receiver_tag")]] = receiver_tag;

template <typename Rcvr>
concept receiver =
    ::std::derived_from<typename ::std::remove_cvref_t<Rcvr>::receiver_concept, ::beman::execution::receiver_tag> &&
    requires(const ::std::remove_cvref_t<Rcvr>& rcvr) {
        { ::beman::execution::get_env(rcvr) } -> ::beman::execution::detail::queryable;
    } && ::std::move_constructible<::std::remove_cvref_t<Rcvr>> &&
    ::std::constructible_from<::std::remove_cvref_t<Rcvr>, Rcvr> &&
    (!::std::is_final_v<::std::remove_cvref_t<Rcvr>>) &&
    ::std::is_nothrow_move_constructible_v<::std::remove_cvref_t<Rcvr>>;
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_RECEIVER
