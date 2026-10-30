// include/beman/execution/detail/sender_in.hpp                     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_IN
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_IN

#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif
#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.env;
import beman.execution.detail.get_completion_signatures;
import beman.execution.detail.is_constant;
import beman.execution.detail.queryable;
import beman.execution.detail.sender;
import beman.execution.detail.valid_completion_signatures;
#else
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/get_completion_signatures.hpp>
#include <beman/execution/detail/is_constant.hpp>
#include <beman/execution/detail/queryable.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/valid_completion_signatures.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
template <typename Sender, typename... Env>
concept sender_in =
    ::beman::execution::sender<Sender> && sizeof...(Env) <= 1 &&
    (::beman::execution::detail::queryable<Env> && ... && true) &&
    ::beman::execution::detail::is_constant<::beman::execution::get_completion_signatures<Sender, Env...>()>;
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_IN
