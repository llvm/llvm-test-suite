// include/beman/execution/detail/unstoppable_scheduler.hpp          -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_UNSTOPPABLE_SCHEDULER
#define INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_UNSTOPPABLE_SCHEDULER

#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.schedule;
import beman.execution.detail.scheduler;
import beman.execution.detail.unstoppable;
#else
#include <beman/execution/detail/schedule.hpp>
#include <beman/execution/detail/scheduler.hpp>
#include <beman/execution/detail/unstoppable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <::beman::execution::scheduler Sched>
struct unstoppable_scheduler {
    using scheduler_concept = typename Sched::scheduler_concept;

    template <typename Q, typename... Args>
        requires requires { ::std::declval<Sched>().query(::std::declval<const Q&>(), ::std::declval<Args>()...); }
    auto query(const Q& q, Args&&... args) const noexcept -> decltype(auto) {
        return sched.query(q, ::std::forward<Args>(args)...);
    }

    template <typename Self>
        requires requires { ::beman::execution::schedule(::std::declval<Self>().sched); }
    auto schedule(this Self&& self) noexcept(noexcept(::beman::execution::schedule(::std::declval<Self>().sched))) {
        return ::beman::execution::unstoppable(::beman::execution::schedule(::std::forward<Self>(self).sched));
    }

    friend auto operator==(const unstoppable_scheduler& lhs, const unstoppable_scheduler& rhs) -> bool = default;

    Sched sched;
};
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_UNSTOPPABLE_SCHEDULER
