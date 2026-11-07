// include/beman/execution/detail/exit_scope_sender_in.hpp                        -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_EXIT_SCOPE_SENDER_IN
#define INCLUDED_BEMAN_EXECUTION_DETAIL_EXIT_SCOPE_SENDER_IN

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.completion_signatures_of_t;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.exit_scope_sender;
import beman.execution.detail.nothrow_connectable;
import beman.execution.detail.sender_in;
import beman.execution.detail.set_value;
#else
#include <beman/execution/detail/completion_signatures_of_t.hpp>
#include <beman/execution/detail/completion_signatures.hpp>
#include <beman/execution/detail/exit_scope_sender.hpp>
#include <beman/execution/detail/nothrow_connectable.hpp>
#include <beman/execution/detail/sender_in.hpp>
#include <beman/execution/detail/set_value.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
/*!
 * \brief An exit scope sender that can operate in the environment `Env...`.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 *
 * \details
 * Requirements:
 *   - `Sender` models `exit_scope_sender`.
 *   - `Sender` models `sender_in<Env...>`.
 *   - `Sender` is nothrow connectable to any receiver with environment `Env...`.
 *   - The completion signatures of `Sender` in `Env...` is exactly `completion_signatures<set_value_t()>`.
 */
template <typename Sender, typename... Env>
concept exit_scope_sender_in =
    ::beman::execution::exit_scope_sender<Sender> && ::beman::execution::sender_in<Sender, Env...> &&
    ::beman::execution::detail::nothrow_connectable<Sender, Env...> &&
    std::is_same_v<::beman::execution::completion_signatures_of_t<Sender, Env...>,
                   ::beman::execution::completion_signatures<::beman::execution::set_value_t()>>;
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif
