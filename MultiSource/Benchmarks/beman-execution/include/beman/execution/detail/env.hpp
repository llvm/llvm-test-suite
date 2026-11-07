// include/beman/execution/detail/env.hpp                             -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_ENV
#define INCLUDED_BEMAN_EXECUTION_DETAIL_ENV

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.non_assignable;
import beman.execution.detail.queryable;
import beman.execution.detail.type_list;
#else
#include <beman/execution/detail/non_assignable.hpp>
#include <beman/execution/detail/queryable.hpp>
#include <beman/execution/detail/type_list.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <::beman::execution::detail::queryable Env>
struct env_base {
    Env env_;
};

template <typename E, typename Q, typename... Args>
concept has_query = requires(const E& e) { e.query(::std::declval<Q>(), ::std::declval<Args>()...); };

template <typename Q, typename... E>
struct find_env;
template <typename Q, typename E0, typename... E>
    requires has_query<E0, Q>
struct find_env<Q, E0, E...> {
    using type = E0;
};
template <typename Q, typename E0, typename... E>
    requires(not has_query<E0, Q>)
struct find_env<Q, E0, E...> {
    using type = typename find_env<Q, E...>::type;
};

template <typename Q, typename ArgsList, typename... E>
struct find_env_with_args;
template <typename Q, typename... Args, typename E0, typename... E>
    requires ::beman::execution::detail::has_query<E0, Q, Args...>
struct find_env_with_args<Q, ::beman::execution::detail::type_list<Args...>, E0, E...> {
    using type = E0;
};
template <typename Q, typename... Args, typename E0, typename... E>
    requires(not ::beman::execution::detail::has_query<E0, Q, Args...>)
struct find_env_with_args<Q, ::beman::execution::detail::type_list<Args...>, E0, E...> {
    using type = typename find_env_with_args<Q, ::beman::execution::detail::type_list<Args...>, E...>::type;
};
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

namespace beman::execution {
template <::beman::execution::detail::queryable... Envs>
struct env : ::beman::execution::detail::env_base<Envs>... {
    [[no_unique_address]] ::beman::execution::detail::non_assignable na_{};

    template <typename Q, typename... Args>
        requires(::beman::execution::detail::has_query<Envs, Q, Args...> || ...)
    constexpr auto query(Q q, Args&&... args) const noexcept -> decltype(auto) {
        using E = typename ::beman::execution::detail::
            find_env_with_args<Q, ::beman::execution::detail::type_list<Args...>, Envs...>::type;
        return static_cast<const ::beman::execution::detail::env_base<E>&>(*this).env_.query(
            q, ::std::forward<Args>(args)...);
    }
};

template <::beman::execution::detail::queryable... Envs>
env(Envs...) -> env<::std::unwrap_reference_t<Envs>...>;
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_ENV
