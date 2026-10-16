// include/beman/execution/detail/sched_env.hpp                     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SCHED_ENV
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SCHED_ENV

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.default_domain;
import beman.execution.detail.get_domain;
import beman.execution.detail.get_start_scheduler;
#else
#include <beman/execution/detail/default_domain.hpp>
#include <beman/execution/detail/get_domain.hpp>
#include <beman/execution/detail/get_start_scheduler.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Scheduler>
class sched_env {
  private:
    Scheduler sched;

  public:
    template <typename S>
    explicit sched_env(S sch) noexcept(std::is_nothrow_constructible_v<Scheduler, S>) : sched(::std::move(sch)) {}

    auto query(::beman::execution::get_start_scheduler_t) const noexcept { return this->sched; }

    auto query(::beman::execution::get_domain_t q) const noexcept {
        if constexpr (requires { this->sched.query(q); })
            return this->sched.query(q);
        else
            return ::beman::execution::default_domain{};
    }
};

template <typename Scheduler>
sched_env(Scheduler&&) -> sched_env<::std::remove_cvref_t<Scheduler>>;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SCHED_ENV
