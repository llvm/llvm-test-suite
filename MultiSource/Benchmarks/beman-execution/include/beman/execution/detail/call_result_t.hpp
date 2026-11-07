// include/beman/execution/detail/call_result_t.hpp                 -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_CALL_RESULT
#define INCLUDED_BEMAN_EXECUTION_DETAIL_CALL_RESULT

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Fun, typename... Args>
/*!
 * \brief Type alias used determine the result of function [object] call.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
using call_result_t = decltype(::std::declval<Fun>()(std::declval<Args>()...));
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_CALL_RESULT
