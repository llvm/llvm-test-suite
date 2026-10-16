// include/beman/execution/detail/get_await_completion_adaptor.hpp      -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_GET_AWAIT_COMPLETION_ADAPTOR
#define INCLUDED_BEMAN_EXECUTION_DETAIL_GET_AWAIT_COMPLETION_ADAPTOR

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.forwarding_query;
#else
#include <beman/execution/detail/forwarding_query.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
struct get_await_completion_adaptor_t {
    template <typename Env>
        requires requires(Env&& env, const get_await_completion_adaptor_t& g) { ::std::as_const(env).query(g); }
    auto operator()(Env&& env) const noexcept {
        static_assert(noexcept(::std::as_const(env).query(*this)));
        return ::std::as_const(env).query(*this);
    }
    static constexpr auto query(const ::beman::execution::forwarding_query_t&) noexcept -> bool { return true; }
};

inline constexpr get_await_completion_adaptor_t get_await_completion_adaptor{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_GET_AWAIT_COMPLETION_ADAPTOR
