// include/beman/execution/detail/sync_wait_with_variant.hpp            -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SYNC_WAIT_WITH_VARIANT
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SYNC_WAIT_WITH_VARIANT

#include <beman/execution/detail/common.hpp>
#include <beman/execution/detail/suppress_push.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <optional>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.apply_sender;
import beman.execution.detail.callable;
import beman.execution.detail.call_result_t;
import beman.execution.detail.compl_domain;
import beman.execution.detail.default_domain;
import beman.execution.detail.into_variant;
import beman.execution.detail.sender_in;
import beman.execution.detail.set_value;
import beman.execution.detail.sync_wait;
import beman.execution.detail.value_types_of_t;
#else
#include <beman/execution/detail/apply_sender.hpp>
#include <beman/execution/detail/callable.hpp>
#include <beman/execution/detail/call_result_t.hpp>
#include <beman/execution/detail/compl_domain.hpp>
#include <beman/execution/detail/default_domain.hpp>
#include <beman/execution/detail/into_variant.hpp>
#include <beman/execution/detail/sender_in.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/sync_wait.hpp>
#include <beman/execution/detail/value_types_of_t.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <::beman::execution::sender_in<::beman::execution::detail::sync_wait_env> Sndr>
using sync_wait_with_variant_result_type =
    ::std::optional<::beman::execution::value_types_of_t<Sndr, ::beman::execution::detail::sync_wait_env>>;
} // namespace beman::execution::detail

namespace beman::execution {

struct sync_wait_with_variant_t {
    template <typename Sndr>
        requires ::beman::execution::detail::callable<
            ::beman::execution::sync_wait_t,
            ::beman::execution::detail::call_result_t<::beman::execution::into_variant_t, Sndr>>
    auto apply_sender(Sndr&& sndr) const {
        using result_type = ::beman::execution::detail::sync_wait_with_variant_result_type<Sndr>;
        if (auto opt_value =
                ::beman::execution::sync_wait(::beman::execution::into_variant(::std::forward<Sndr>(sndr)))) {
            return result_type(::std::move(::std::get<0>(*opt_value)));
        }
        return result_type(::std::nullopt);
    }

    template <typename Sndr>
        requires requires { typename ::beman::execution::detail::sync_wait_with_variant_result_type<Sndr>; }
    auto operator()(Sndr&& sndr) const {
        auto dom = ::beman::execution::detail::compl_domain<::beman::execution::set_value_t>(
            sndr, ::beman::execution::detail::sync_wait_env{});
        return ::beman::execution::apply_sender(dom, *this, ::std::forward<Sndr>(sndr));
    }
};

inline constexpr sync_wait_with_variant_t sync_wait_with_variant{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#include <beman/execution/detail/suppress_pop.hpp>

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SYNC_WAIT_WITH_VARIANT
