// include/beman/execution/detail/hide_sched.hpp                      -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_HIDE_SCHED
#define INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_HIDE_SCHED

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <utility>
#endif
#if BEMAN_HAS_MODULES
import beman.execution.detail.queryable;
#else
#include <beman/execution/detail/queryable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct get_domain_t;
struct get_scheduler_t;

template <::beman::execution::detail::queryable Q>
struct hide_sched_t {
    template <typename Tag, typename... Args>
        requires requires { ::std::declval<Q>().query(::std::declval<Tag>(), ::std::declval<Args>()...); }
    auto query(Tag&& tag, Args&&... args) const noexcept -> decltype(auto) {
        return q.query(::std::forward<Tag>(tag), ::std::forward<Args>(args)...);
    }

    template <typename... Args>
    auto query(::beman::execution::detail::get_domain_t, Args&&... args) const noexcept -> void = delete;

    template <typename... Args>
    auto query(::beman::execution::detail::get_scheduler_t, Args&&... args) const noexcept -> void = delete;

    const Q& q;
};

template <::beman::execution::detail::queryable Q>
auto hide_sched(const Q& q) noexcept {
    return ::beman::execution::detail::hide_sched_t<Q>{q};
}
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_HIDE_SCHED
