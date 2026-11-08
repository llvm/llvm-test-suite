// include/beman/execution/detail/indeterminate_domain.hpp            -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_INDETERMINATE_DOMAIN
#define INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_INDETERMINATE_DOMAIN

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#include <utility>
#endif
#if BEMAN_HAS_MODULES
import beman.execution.detail.default_domain;
import beman.execution.detail.meta.unique;
import beman.execution.detail.queryable;
import beman.execution.detail.sender;
#else
#include <beman/execution/detail/default_domain.hpp>
#include <beman/execution/detail/meta_unique.hpp>
#include <beman/execution/detail/queryable.hpp>
#include <beman/execution/detail/sender.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {

template <typename... Domains>
struct indeterminate_domain {
    indeterminate_domain() = default;

    constexpr indeterminate_domain(const auto&) noexcept {}

    template <typename Tag, ::beman::execution::sender Sndr, ::beman::execution::detail::queryable Env>
    static constexpr auto transform_sender(Tag tag, Sndr&& sndr, const Env& env) noexcept(
        noexcept(::beman::execution::default_domain{}.transform_sender(tag, ::std::forward<Sndr>(sndr), env)))
        -> decltype(auto) {
        auto make_new_sender = [&]() -> decltype(auto) {
            return ::beman::execution::default_domain{}.transform_sender(tag, ::std::forward<Sndr>(sndr), env);
        };
        (..., verify_mandates_<::std::decay_t<decltype(make_new_sender())>, Domains, Tag, Sndr, Env>());
        return make_new_sender();
    }

    template <typename Expected, typename Domain, typename Tag, typename Sndr, typename Env>
    static consteval auto verify_mandates_() noexcept -> void {
        if constexpr (requires {
                          ::std::declval<Domain>().transform_sender(
                              ::std::declval<Tag>(), ::std::declval<Sndr>(), ::std::declval<const Env&>());
                      }) {
            static_assert(
                ::std::same_as<::std::decay_t<decltype(::std::declval<Domain>().transform_sender(
                                   ::std::declval<Tag>(), ::std::declval<Sndr>(), ::std::declval<const Env&>()))>,
                               Expected>,
                "indeterminate_domain: all possible domains must agree on the result "
                "type of transform_sender, or be ill-formed for the given (Tag, Sndr, Env)");
        }
    }
};

} // namespace beman::execution

template <typename... Domains1, typename... Domains2>
struct std::common_type<::beman::execution::indeterminate_domain<Domains1...>,
                        ::beman::execution::indeterminate_domain<Domains2...>> {
    using type =
        ::beman::execution::detail::meta::unique<::beman::execution::indeterminate_domain<Domains1..., Domains2...>>;
};

template <typename... Domains, typename D>
struct std::common_type<::beman::execution::indeterminate_domain<Domains...>, D> {
    using type = ::beman::execution::detail::meta::unique<::beman::execution::indeterminate_domain<Domains..., D>>;
};

template <typename D, typename... Domains>
struct std::common_type<D, ::beman::execution::indeterminate_domain<Domains...>>
    : ::std::common_type<::beman::execution::indeterminate_domain<Domains...>, D> {};

// ----------------------------------------------------------------------------

#endif
