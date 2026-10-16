// include/beman/execution/detail/env_type.hpp                      -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_ENV_TYPE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_ENV_TYPE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.call_result_t;
import beman.execution.detail.impls_for;
import beman.execution.detail.sender_decompose;
import beman.execution.detail.state_type;
import beman.execution.detail.tag_of_t;
#else
#include <beman/execution/detail/call_result_t.hpp>
#include <beman/execution/detail/impls_for.hpp>
#include <beman/execution/detail/sender_decompose.hpp>
#include <beman/execution/detail/state_type.hpp>
#include <beman/execution/detail/tag_of_t.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
/*!
 * \brief Helper alias to determine the environment type associated with sender in a basic_sender
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <typename Index, typename Sender, typename Receiver>
using env_type = ::beman::execution::detail::call_result_t<
    decltype(::beman::execution::detail::get_impls_for<::beman::execution::tag_of_t<Sender>>::get_env()),
    Index,
    ::beman::execution::detail::state_type<Sender, Receiver>&,
    const Receiver&>;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_ENV_TYPE
