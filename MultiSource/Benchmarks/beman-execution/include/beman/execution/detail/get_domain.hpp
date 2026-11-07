// include/beman/execution/detail/get_domain.hpp                    -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_GET_DOMAIN
#define INCLUDED_BEMAN_EXECUTION_DETAIL_GET_DOMAIN

#include <beman/execution/detail/common.hpp>
#include <beman/execution/detail/suppress_push.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.default_domain;
import beman.execution.detail.forwarding_query;
import beman.execution.detail.get_completion_domain;
import beman.execution.detail.get_scheduler;
import beman.execution.detail.hide_sched;
import beman.execution.detail.set_value;
#else
#include <beman/execution/detail/default_domain.hpp>
#include <beman/execution/detail/forwarding_query.hpp>
#include <beman/execution/detail/get_completion_domain.hpp>
#include <beman/execution/detail/get_scheduler.hpp>
#include <beman/execution/detail/hide_sched.hpp>
#include <beman/execution/detail/set_value.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct get_domain_t : ::beman::execution::forwarding_query_t {
    template <typename Env>
    constexpr auto operator()(Env&& env) const noexcept {
        if constexpr (requires { ::std::as_const(env).query(*this); }) {
            using type = decltype(auto(::std::as_const(env).query(*this)));
            static_assert(noexcept(type{}));
            return type{};
        } else if constexpr (requires {
                                 ::beman::execution::get_completion_domain<::beman::execution::set_value_t>(
                                     ::beman::execution::get_scheduler(env),
                                     ::beman::execution::detail::hide_sched(env));
                             }) {
            using type = decltype(auto(::beman::execution::get_completion_domain<::beman::execution::set_value_t>(
                ::beman::execution::get_scheduler(env), ::beman::execution::detail::hide_sched(env))));
            static_assert(noexcept(type{}));
            return type{};
        } else if constexpr (requires {
                                 ::beman::execution::get_completion_domain<::beman::execution::set_value_t>(
                                     ::beman::execution::get_scheduler(env),
                                     ::beman::execution::detail::hide_sched(env));
                             }) {
            using type = decltype(auto(::beman::execution::get_completion_domain<::beman::execution::set_value_t>(
                ::beman::execution::get_scheduler(env), ::beman::execution::detail::hide_sched(env))));
            static_assert(noexcept(type{}));
            return type{};
        } else {
            return ::beman::execution::default_domain{};
        }
    }
};
} // namespace beman::execution::detail

namespace beman::execution {
using get_domain_t = ::beman::execution::detail::get_domain_t;
inline constexpr get_domain_t get_domain{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#include <beman/execution/detail/suppress_pop.hpp>

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_GET_DOMAIN
