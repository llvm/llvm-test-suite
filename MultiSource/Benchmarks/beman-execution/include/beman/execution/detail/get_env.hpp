// include/beman/execution/detail/get_env.hpp                       -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_GET_ENV
#define INCLUDED_BEMAN_EXECUTION_DETAIL_GET_ENV

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.env;
import beman.execution.detail.queryable;
#else
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/queryable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
struct get_env_t {
    template <typename Object>
        requires(not requires(::std::add_const_t<::std::remove_cvref_t<Object>>& object) { object.get_env(); } ||
                 ::beman::execution::detail::queryable<
                     std::remove_cvref_t<decltype(::std::declval<const ::std::remove_cvref_t<Object>&>().get_env())>>)
    auto operator()(Object&& object) const noexcept -> decltype(auto) {
        ::std::add_const_t<::std::remove_cvref_t<Object>>& obj{object};
        if constexpr (requires { ::std::as_const(obj).get_env(); }) {
            static_assert(noexcept(::std::as_const(obj).get_env()), "get_env requires the expression to be noexcept");
            static_assert(
                ::beman::execution::detail::queryable<std::remove_cvref_t<decltype(::std::as_const(obj).get_env())>>,
                "get_env requires the result type to be destructible");
            return ::std::as_const(obj).get_env();
        } else {
            return ::beman::execution::env<>{};
        }
    }
};

inline constexpr get_env_t get_env{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_GET_ENV
