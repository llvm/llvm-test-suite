// include/beman/execution/detail/completion_signature.hpp          -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_COMPLETION_SIGNATURE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_COMPLETION_SIGNATURE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
#else
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename>
struct is_set_error : ::std::false_type {};
template <typename Error>
struct is_set_error<::beman::execution::set_error_t(Error)> : ::std::true_type {};

template <typename Fun>
using is_set_stopped = ::std::is_same<Fun, ::beman::execution::set_stopped_t()>;

template <typename>
struct is_set_value : ::std::false_type {};
template <typename... Args>
struct is_set_value<::beman::execution::set_value_t(Args...)> : ::std::true_type {};

/*!
 * \brief Detect if a type is a completion signature.
 *
 * \details
 * The three completion signatures are
 * - set_error_t(E) for completion with an error.
 * - set_stopped_t() to indicate that operation was cancelled.
 * - set_value_t(A...) for successful completion with a set of argument.
 *
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \concept copmletion_signature
 * \internal
 */
template <typename Fun>
concept completion_signature =
    ::beman::execution::detail::is_set_error<Fun>::value || ::beman::execution::detail::is_set_stopped<Fun>::value ||
    ::beman::execution::detail::is_set_value<Fun>::value;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_COMPLETION_SIGNATURE
