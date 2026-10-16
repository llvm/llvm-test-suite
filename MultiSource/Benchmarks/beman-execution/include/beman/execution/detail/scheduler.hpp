// include/beman/execution/detail/scheduler.hpp                     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SCHEDULER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SCHEDULER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.almost_scheduler;
import beman.execution.detail.get_forward_progress_guarantee;
import beman.execution.detail.schedule;
import beman.execution.detail.sender;
#else
#include <beman/execution/detail/almost_scheduler.hpp>
#include <beman/execution/detail/get_forward_progress_guarantee.hpp>
#include <beman/execution/detail/schedule.hpp>
#include <beman/execution/detail/sender.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
template <typename Scheduler>
concept scheduler = ::beman::execution::detail::almost_scheduler<Scheduler> && requires(Scheduler&& sched) {
    { ::beman::execution::schedule(::std::forward<Scheduler>(sched)) } -> ::beman::execution::sender;
    {
        ::beman::execution::get_forward_progress_guarantee(sched)
    } -> ::std::same_as<::beman::execution::forward_progress_guarantee>;
} && ::std::equality_comparable<::std::remove_cvref_t<Scheduler>> && ::std::copyable<::std::remove_cvref_t<Scheduler>>;
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SCHEDULER
