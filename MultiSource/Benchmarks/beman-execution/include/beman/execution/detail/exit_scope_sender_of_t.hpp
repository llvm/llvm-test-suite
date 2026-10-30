// include/beman/execution/detail/exit_scope_sender_of_t.hpp                        -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_EXIT_SCOPE_SENDER_OF_T
#define INCLUDED_BEMAN_EXECUTION_DETAIL_EXIT_SCOPE_SENDER_OF_T

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.enter_scope_sender;
import beman.execution.detail.env;
import beman.execution.detail.exit_scope_sender_in;
import beman.execution.detail.single_sender_value_type;
#else
#include <beman/execution/detail/enter_scope_sender.hpp>
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/exit_scope_sender_in.hpp>
#include <beman/execution/detail/single_sender_value_type.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
/*!
 * \brief Represents the type of exit scope sender which an asynchronous operation formed from
 *        `Sender` in `Env...` yield on completion.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 *
 * \details
 * This looks at the completion signatures of `Sender` in `Env...` and finds the unique value completion signature.
 * If there is no value completion signature, or if there are two or more value completion signatures, this type is not
 * defined.
 */
template <::beman::execution::enter_scope_sender Sender, typename Env = ::beman::execution::env<>>
    requires ::beman::execution::
                 exit_scope_sender_in<::beman::execution::detail::single_sender_value_type<Sender, Env>, Env>
using exit_scope_sender_of_t = ::beman::execution::detail::single_sender_value_type<Sender, Env>;
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif
