// include/beman/execution/detail/get_delegation_scheduler.hpp      -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_GET_DELEGATION_SCHEDULER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_GET_DELEGATION_SCHEDULER

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
struct get_delegation_scheduler_t {
    template <typename Env>
        requires requires(Env&& env, const get_delegation_scheduler_t& g) {
            { auto(::std::as_const(env).query(g)) } -> ::beman::execution::scheduler;
        }
    auto operator()(Env&& env) const noexcept {
        static_assert(noexcept(::std::as_const(env).query(*this)));
        return ::std::as_const(env).query(*this);
    }
    constexpr auto query(const ::beman::execution::forwarding_query_t&) const noexcept -> bool { return true; }
};

inline constexpr get_delegation_scheduler_t get_delegation_scheduler{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_GET_DELEGATION_SCHEDULER
