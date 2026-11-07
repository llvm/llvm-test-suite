// include/beman/execution/detail/query_with_default.hpp            -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_QUERY_WITH_DEFAULT
#define INCLUDED_BEMAN_EXECUTION_DETAIL_QUERY_WITH_DEFAULT

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Tag, typename Env, typename Value>
    requires requires(const Tag& tag, const Env& env) { tag(env); }
constexpr auto query_with_default(Tag, const Env& env, Value&&) noexcept(noexcept(Tag()(env))) -> decltype(auto) {
    return Tag()(env);
}

template <typename Tag, typename Env, typename Value>
constexpr auto
query_with_default(Tag, const Env&, Value&& value) noexcept(noexcept(static_cast<Value>(std::forward<Value>(value))))
    -> decltype(auto) {
    return static_cast<Value>(std::forward<Value>(value));
}

} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_QUERY_WITH_DEFAULT
