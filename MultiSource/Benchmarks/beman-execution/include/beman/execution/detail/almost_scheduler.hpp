// include/beman/execution/detail/almost_scheduler.hpp              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_ALMOST_SCHEDULER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_ALMOST_SCHEDULER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.queryable;
import beman.execution.detail.schedule;
import beman.execution.detail.scheduler_tag;
import beman.execution.detail.sender;
#else
#include <beman/execution/detail/queryable.hpp>
#include <beman/execution/detail/schedule.hpp>
#include <beman/execution/detail/scheduler_tag.hpp>
#include <beman/execution/detail/sender.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
/*!
 * \brief Auxiliary concept used to break cycle for scheduler concept.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 * \concept almost_scheduler
 */
template <typename Scheduler>
concept almost_scheduler = ::std::derived_from<typename ::std::remove_cvref_t<Scheduler>::scheduler_concept,
                                               ::beman::execution::scheduler_tag> &&
                           ::beman::execution::detail::queryable<Scheduler> &&
                           requires(Scheduler&& sched) {
                               {
                                   ::beman::execution::schedule(::std::forward<Scheduler>(sched))
                               } -> ::beman::execution::sender;
                           } && ::std::equality_comparable<::std::remove_cvref_t<Scheduler>> &&
                           ::std::copy_constructible<::std::remove_cvref_t<Scheduler>>;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_ALMOST_SCHEDULER
