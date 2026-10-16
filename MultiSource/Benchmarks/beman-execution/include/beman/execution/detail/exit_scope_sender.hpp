// include/beman/execution/detail/exit_scope_sender.hpp                        -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_EXIT_SCOPE_SENDER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_EXIT_SCOPE_SENDER

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
/*!
 * \brief A sender that does not throw when decay-copied or moved.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
template <typename Sender>
concept exit_scope_sender =
    ::beman::execution::sender<Sender> && std::is_nothrow_constructible_v<::std::remove_cvref_t<Sender>, Sender> &&
    std::is_nothrow_move_constructible_v<::std::remove_cvref_t<Sender>>;
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif
