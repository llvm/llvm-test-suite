// include/beman/execution/detail/error_types_of_t.hpp              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_ERROR_TYPES_OF
#define INCLUDED_BEMAN_EXECUTION_DETAIL_ERROR_TYPES_OF

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.completion_signatures_of_t;
import beman.execution.detail.env;
import beman.execution.detail.gather_signatures;
import beman.execution.detail.sender_in;
import beman.execution.detail.set_error;
import beman.execution.detail.variant_or_empty;
#else
#include <beman/execution/detail/completion_signatures_of_t.hpp>
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/gather_signatures.hpp>
#include <beman/execution/detail/sender_in.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/variant_or_empty.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
/*!
 * \brief Type alias to get error types for a sender
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
template <typename Sender,
          typename Env                         = ::beman::execution::env<>,
          template <typename...> class Variant = ::beman::execution::detail::variant_or_empty>
    requires ::beman::execution::sender_in<Sender, Env>
using error_types_of_t =
    ::beman::execution::detail::gather_signatures<::beman::execution::set_error_t,
                                                  ::beman::execution::completion_signatures_of_t<Sender, Env>,
                                                  ::std::type_identity_t,
                                                  Variant>;
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_ERROR_TYPES_OF
