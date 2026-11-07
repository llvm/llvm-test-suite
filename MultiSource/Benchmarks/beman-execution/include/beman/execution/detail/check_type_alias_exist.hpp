// include/beman/execution/detail/check_type_alias_exist.hpp        -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_CHECK_TYPE_ALIAS_EXIST
#define INCLUDED_BEMAN_EXECUTION_DETAIL_CHECK_TYPE_ALIAS_EXIST

#include <beman/execution/detail/common.hpp>

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
/*!
 * \brief Auxiliary class template used to detect whether a type alias exist within a class.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <template <typename> class>
struct check_type_alias_exist;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_CHECK_TYPE_ALIAS_EXIST
