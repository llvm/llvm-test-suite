// include/beman/execution/detail/get_scheduler.hpp                 -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_GET_SCHEDULER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_GET_SCHEDULER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.forwarding_query;
import beman.execution.detail.get_completion_scheduler;
import beman.execution.detail.hide_sched;
import beman.execution.detail.set_value;
#else
#include <beman/execution/detail/forwarding_query.hpp>
#include <beman/execution/detail/get_completion_scheduler.hpp>
#include <beman/execution/detail/hide_sched.hpp>
#include <beman/execution/detail/set_value.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct get_scheduler_t : ::beman::execution::forwarding_query_t {
    template <typename Env>
        requires requires(const get_scheduler_t& self, Env&& env) {
            ::std::as_const(env).query(self);
            ::beman::execution::get_completion_scheduler<::beman::execution::set_value_t>(
                ::std::as_const(env).query(self), ::beman::execution::detail::hide_sched(env));
        }
    auto operator()(Env&& env) const noexcept {
        static_assert(noexcept(::beman::execution::get_completion_scheduler<::beman::execution::set_value_t>(
            ::std::as_const(env).query(*this), ::beman::execution::detail::hide_sched(env))));
        return ::beman::execution::get_completion_scheduler<::beman::execution::set_value_t>(
            ::std::as_const(env).query(*this), ::beman::execution::detail::hide_sched(env));
    }
};
} // namespace beman::execution::detail

namespace beman::execution {
using get_scheduler_t = ::beman::execution::detail::get_scheduler_t;
inline constexpr get_scheduler_t get_scheduler{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_GET_SCHEDULER
