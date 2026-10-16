// include/beman/execution/detail/child_type.hpp                    -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_CHILD_TYPE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_CHILD_TYPE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <cstddef>
#include <type_traits>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
/*!
 * \brief Auxiliary type alias used to determine the type of a child sender.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <typename Sender, ::std::size_t I = 0u>
using child_type = decltype(::std::declval<Sender>().template get<I + 2>());
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_CHILD_TYPE
