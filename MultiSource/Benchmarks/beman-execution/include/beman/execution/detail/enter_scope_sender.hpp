// include/beman/execution/detail/enter_scope_sender.hpp                        -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_ENTER_SCOPE_SENDER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_ENTER_SCOPE_SENDER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.sender;
#else
#include <beman/execution/detail/sender.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
template <typename Sender>
/*!
 * \brief Sender corresponding to the action of entering a scope.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
concept enter_scope_sender = ::beman::execution::sender<Sender>;
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif
