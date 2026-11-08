// include/beman/execution/detail/await_result_type.hpp             -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_AWAIT_RESULT_TYPE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_AWAIT_RESULT_TYPE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.get_awaiter;
#else
#include <beman/execution/detail/get_awaiter.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
/*!
 * \brief Auxiliary type alias to get the result type of an awaiter.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <typename T, typename Promise> //-dk:TODO detail export
using await_result_type =
    decltype(::beman::execution::detail::get_awaiter(::std::declval<T>(), ::std::declval<Promise&>()).await_resume());
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_AWAIT_RESULT_TYPE
