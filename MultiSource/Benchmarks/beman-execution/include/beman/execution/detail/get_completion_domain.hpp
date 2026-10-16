// include/beman/execution/detail/get_completion_domain.hpp           -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_GET_COMPLETION_DOMAIN
#define INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_GET_COMPLETION_DOMAIN

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#include <utility>
#endif
#if BEMAN_HAS_MODULES
import beman.execution.detail.completion_tag;
import beman.execution.detail.default_domain;
import beman.execution.detail.forwarding_query;
import beman.execution.detail.get_completion_scheduler;
import beman.execution.detail.queryable;
import beman.execution.detail.scheduler;
import beman.execution.detail.set_value;
import beman.execution.detail.try_query;
#else
#include <beman/execution/detail/completion_tag.hpp>
#include <beman/execution/detail/default_domain.hpp>
#include <beman/execution/detail/forwarding_query.hpp>
#include <beman/execution/detail/get_completion_scheduler.hpp>
#include <beman/execution/detail/queryable.hpp>
#include <beman/execution/detail/scheduler.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/try_query.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct no_completion_domain {};

template <typename Tag = void>
    requires ::std::same_as<Tag, void> || ::beman::execution::detail::completion_tag<Tag>
struct get_completion_domain_t : ::beman::execution::forwarding_query_t {
    template <typename Q, typename... E>
    static auto impl(Q&& q, E&&... e) noexcept {
        if constexpr (requires {
                          ::beman::execution::detail::try_query(
                              ::std::forward<Q>(q), get_completion_domain_t<Tag>{}, ::std::forward<E>(e)...);
                      }) {
            return ::beman::execution::detail::try_query(
                ::std::forward<Q>(q), get_completion_domain_t<Tag>{}, ::std::forward<E>(e)...);
        } else if constexpr (::std::same_as<Tag, void>) {
            return get_completion_domain_t<::beman::execution::set_value_t>::impl(::std::forward<Q>(q),
                                                                                  ::std::forward<E>(e)...);
        } else if constexpr (requires {
                                 ::beman::execution::detail::try_query(
                                     ::beman::execution::get_completion_scheduler<Tag>(q, e...),
                                     get_completion_domain_t<::beman::execution::set_value_t>{},
                                     ::std::forward<E>(e)...);
                             }) {
            return ::beman::execution::detail::try_query(::beman::execution::get_completion_scheduler<Tag>(q, e...),
                                                         get_completion_domain_t<::beman::execution::set_value_t>{},
                                                         ::std::forward<E>(e)...);
        } else if constexpr (::beman::execution::scheduler<Q> && 0u != sizeof...(E)) {
            return ::beman::execution::default_domain{};
        } else {
            return ::beman::execution::detail::no_completion_domain{};
        }
    };

    template <typename Q, typename... E>
    using domain_of = decltype((impl)(::std::declval<Q>(), ::std::declval<E>()...));

    template <::beman::execution::detail::queryable Q, typename... E>
        requires(!::std::same_as<domain_of<Q, E...>, ::beman::execution::detail::no_completion_domain>)
    auto operator()(Q&&, E&&...) const noexcept {
        using domain = domain_of<Q, E...>;
        static_assert(noexcept(domain{}), "the domain's default constructor has to be noexcept");
        return domain{};
    }
};
} // namespace beman::execution::detail

namespace beman::execution {
template <typename Tag = void>
    requires ::std::same_as<Tag, void> || ::beman::execution::detail::completion_tag<Tag>
using get_completion_domain_t = ::beman::execution::detail::get_completion_domain_t<Tag>;
template <typename Tag = void>
    requires ::std::same_as<Tag, void> || ::beman::execution::detail::completion_tag<Tag>
inline constexpr get_completion_domain_t<Tag> get_completion_domain{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif
