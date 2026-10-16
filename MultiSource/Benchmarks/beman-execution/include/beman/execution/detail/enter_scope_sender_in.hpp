// include/beman/execution/detail/enter_scope_sender_in.hpp                        -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_ENTER_SCOPE_SENDER_IN
#define INCLUDED_BEMAN_EXECUTION_DETAIL_ENTER_SCOPE_SENDER_IN

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.enter_scope_sender;
import beman.execution.detail.env;
import beman.execution.detail.exit_scope_sender_of_t;
import beman.execution.detail.sender_in;
#else
#include <beman/execution/detail/enter_scope_sender.hpp>
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/exit_scope_sender_of_t.hpp>
#include <beman/execution/detail/sender_in.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
/*!
 * \brief An enter scope sender that can operate in the environment `Env...`.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 *
 * \details
 * Requirements:
 *   - `Sender` models `enter_scope_sender`.
 *   - `Sender` models `sender_in<Env...>`.
 *   - The completion signatures contains exactly one value completion signature, that completion
 *     signature is unary, and the type of the value models `exit_sender_in<Env...>`.
 *   - Semantic: The above exit sender undoes the action of the enter scope sender which sent it.
 */
template <typename Sender, typename Env = ::beman::execution::env<>>
concept enter_scope_sender_in =
    ::beman::execution::enter_scope_sender<Sender> && ::beman::execution::sender_in<Sender, Env> &&
    requires { typename ::beman::execution::exit_scope_sender_of_t<Sender, Env>; };
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif
