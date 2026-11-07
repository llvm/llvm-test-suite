// include/beman/execution/detail/impls_for.hpp                     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_IMPLS_FOR
#define INCLUDED_BEMAN_EXECUTION_DETAIL_IMPLS_FOR

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.default_impls;
#else
#include <beman/execution/detail/default_impls.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Tag>
struct impls_for : ::beman::execution::detail::default_impls {};

template <typename Tag>
struct get_impls_for {
    static constexpr auto get_attrs() -> const auto& {
        if constexpr (requires { Tag::impls_for::get_attrs; })
            return Tag::impls_for::get_attrs;
        else
            return ::beman::execution::detail::impls_for<Tag>::get_attrs;
    }
    static constexpr auto start() -> const auto& {
        if constexpr (requires { Tag::impls_for::start; })
            return Tag::impls_for::start;
        else
            return ::beman::execution::detail::impls_for<Tag>::start;
    }
    static constexpr auto get_state() -> const auto& {
        if constexpr (requires { Tag::impls_for::get_state; })
            return Tag::impls_for::get_state;
        else
            return ::beman::execution::detail::impls_for<Tag>::get_state;
    }
    static constexpr auto get_env() -> const auto& {
        if constexpr (requires { Tag::impls_for::get_env; })
            return Tag::impls_for::get_env;
        else
            return ::beman::execution::detail::impls_for<Tag>::get_env;
    }
    static constexpr auto complete() -> const auto& {
        if constexpr (requires { Tag::impls_for::complete; })
            return Tag::impls_for::complete;
        else
            return ::beman::execution::detail::impls_for<Tag>::complete;
    }
};
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_IMPLS_FOR
