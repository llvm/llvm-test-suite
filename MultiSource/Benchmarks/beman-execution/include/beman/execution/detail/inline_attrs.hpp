// include/beman/execution/detail/inline_attrs.hpp                   -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_INLINE_ATTRS
#define INCLUDED_BEMAN_EXECUTION_DETAIL_INLINE_ATTRS

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.get_completion_domain;
import beman.execution.detail.get_completion_scheduler;
import beman.execution.detail.get_domain;
import beman.execution.detail.get_scheduler;
#else
#include <beman/execution/detail/get_completion_domain.hpp>
#include <beman/execution/detail/get_completion_scheduler.hpp>
#include <beman/execution/detail/get_domain.hpp>
#include <beman/execution/detail/get_scheduler.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {

template <typename Tag>
struct inline_attrs {
    template <typename Env>
        requires requires(const Env& env) { ::beman::execution::get_scheduler(env); }
    constexpr auto query(const ::beman::execution::get_completion_scheduler_t<Tag>&, const Env& env) const noexcept {
        return ::beman::execution::get_scheduler(env);
    }

    template <typename Env>
        requires requires(const Env& env) { ::beman::execution::get_domain(env); }
    constexpr auto query(const ::beman::execution::get_completion_domain_t<Tag>&, const Env& env) const noexcept {
        return ::beman::execution::get_domain(env);
    }
};

} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_INLINE_ATTRS
