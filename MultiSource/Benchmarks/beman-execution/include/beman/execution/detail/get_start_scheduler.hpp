// include/beman/execution/detail/get_start_scheduler.hpp              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_GET_START_SCHEDULER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_GET_START_SCHEDULER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.forwarding_query;
import beman.execution.detail.scheduler;
#else
#include <beman/execution/detail/forwarding_query.hpp>
#include <beman/execution/detail/scheduler.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
struct get_start_scheduler_t : ::beman::execution::forwarding_query_t {
    template <typename Env>
        requires requires(const get_start_scheduler_t& self, const Env& env) {
            { auto(::std::as_const(env).query(self)) } -> beman::execution::scheduler;
        }
    auto operator()(const Env& env) const noexcept {
        static_assert(noexcept(::std::as_const(env).query(*this)));
        return ::std::as_const(env).query(*this);
    }
};

inline constexpr get_start_scheduler_t get_start_scheduler{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_GET_START_SCHEDULER
