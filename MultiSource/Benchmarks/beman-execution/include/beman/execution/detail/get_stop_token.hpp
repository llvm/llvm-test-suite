// include/beman/execution/detail/get_stop_token.hpp                -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_GET_STOP_TOKEN
#define INCLUDED_BEMAN_EXECUTION_DETAIL_GET_STOP_TOKEN

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.forwarding_query;
import beman.execution.detail.never_stop_token;
import beman.execution.detail.stoppable_token;
#else
#include <beman/execution/detail/forwarding_query.hpp>
#include <beman/execution/detail/never_stop_token.hpp>
#include <beman/execution/detail/stoppable_token.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Token>
concept decayed_stoppable_token = ::beman::execution::stoppable_token<::std::decay_t<Token>>;
}
namespace beman::execution {
struct get_stop_token_t {
    template <typename Object>
        requires requires(Object&& object, const get_stop_token_t& tag) {
            { ::std::as_const(object).query(tag) } -> ::beman::execution::detail::decayed_stoppable_token;
        }
    auto operator()(Object&& object) const noexcept {
        static_assert(noexcept(::std::as_const(object).query(*this)));
        return ::std::as_const(object).query(*this);
    }

    template <typename Object>
    auto operator()(Object&&) const noexcept -> ::beman::execution::never_stop_token {
        return {};
    }

    constexpr auto query(const ::beman::execution::forwarding_query_t&) const noexcept -> bool { return true; }
};

inline constexpr get_stop_token_t get_stop_token{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_GET_STOP_TOKEN
