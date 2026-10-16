// include/beman/execution/detail/prop.hpp                            -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_PROP
#define INCLUDED_BEMAN_EXECUTION_DETAIL_PROP

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.callable;
import beman.execution.detail.non_assignable;
#else
#include <beman/execution/detail/callable.hpp>
#include <beman/execution/detail/non_assignable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename>
struct prop_like;
}

namespace beman::execution {
template <typename Query, typename Value>
struct prop;

template <typename Query, typename Value>
prop(Query, Value, ::beman::execution::detail::non_assignable = {}) -> prop<Query, ::std::unwrap_reference_t<Value>>;
} // namespace beman::execution

template <typename V>
struct beman::execution::detail::prop_like {
    V    value;
    auto query(auto) const noexcept -> const V& { return this->value; }
};

template <typename Query, typename Value>
struct beman::execution::prop {
    static_assert(::beman::execution::detail::callable<Query, ::beman::execution::detail::prop_like<Value>>);

    [[no_unique_address]] Query                                      query_{};
    [[no_unique_address]] Value                                      value_{};
    [[no_unique_address]] ::beman::execution::detail::non_assignable non_assignable_{};

    // prop(prop&&)                = default;
    // prop(const prop&)           = default;
    // auto operator=(prop&&) -> prop&      = delete;
    // auto operator=(const prop&) -> prop& = delete;

    constexpr auto query(Query, auto&&...) const noexcept -> const Value& { return this->value_; }
};

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_PROP
