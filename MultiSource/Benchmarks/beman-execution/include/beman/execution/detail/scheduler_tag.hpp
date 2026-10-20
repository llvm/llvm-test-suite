// include/beman/execution/detail/scheduler_tag.hpp                   -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SCHEDULER_TAG
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SCHEDULER_TAG

#include <beman/execution/detail/common.hpp>

// ----------------------------------------------------------------------------

namespace beman::execution {
/*!
 * \brief Tag type to indicate a class is a scheduler.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
struct scheduler_tag {};

using scheduler_t [[deprecated("scheduler_t has been renamed scheduler_tag")]] = scheduler_tag;
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SCHEDULER_TAG
