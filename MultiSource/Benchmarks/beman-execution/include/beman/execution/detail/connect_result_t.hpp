// include/beman/execution/detail/connect_result_t.hpp              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_CONNECT_RESULT
#define INCLUDED_BEMAN_EXECUTION_DETAIL_CONNECT_RESULT

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.connect;
#else
#include <beman/execution/detail/connect.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
/*!
 * \brief Type alias to determine the operation state type returned from `connect()`.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
template <typename Sender, typename Receiver>
using connect_result_t = decltype(::beman::execution::connect(::std::declval<Sender>(), ::std::declval<Receiver>()));
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_CONNECT_RESULT
