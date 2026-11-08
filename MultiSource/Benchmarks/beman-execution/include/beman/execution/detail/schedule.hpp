// include/beman/execution/detail/schedule.hpp                      -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SCHEDULE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SCHEDULE

#include <beman/execution/detail/common.hpp>
#include <beman/execution/detail/suppress_push.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.sender;
#else
#include <beman/execution/detail/sender.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
struct schedule_t {
    template <typename Scheduler>
        requires(not requires(Scheduler&& sched) {
                    { ::std::forward<Scheduler>(sched).schedule() } -> ::beman::execution::sender;
                })
    auto operator()(Scheduler&& sched) const =
        BEMAN_EXECUTION_DELETE("the scheduler needs a schedule() member returning a sender");

    template <typename Scheduler>
        requires requires(Scheduler&& sched) {
            { ::std::forward<Scheduler>(sched).schedule() } -> ::beman::execution::sender;
        }
    auto operator()(Scheduler&& sched) const noexcept(noexcept(std::forward<Scheduler>(sched).schedule())) {
        return std::forward<Scheduler>(sched).schedule();
    }
};

inline constexpr ::beman::execution::schedule_t schedule{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#include <beman/execution/detail/suppress_pop.hpp>

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SCHEDULE
