// include/beman/execution/detail/try_query.hpp                       -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_TRY_QUERY
#define INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_TRY_QUERY

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif
#if BEMAN_HAS_MODULES
import beman.execution.detail.queryable;
#else
#include <beman/execution/detail/queryable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <::beman::execution::detail::queryable Q, typename Tag, typename... Args>
    requires requires(const Q& q, Tag&& tag, Args&&... args) {
        q.query(::std::forward<Tag>(tag), ::std::forward<Args>(args)...);
    }
auto try_query(const Q& q, Tag&& tag, Args&&... args) noexcept -> decltype(auto) {
    return q.query(::std::forward<Tag>(tag), ::std::forward<Args>(args)...);
}

template <::beman::execution::detail::queryable Q, typename Tag, typename... Args>
    requires(
        not requires(const Q& q, Tag&& tag, Args&&... args) {
            q.query(::std::forward<Tag>(tag), ::std::forward<Args>(args)...);
        } && requires(const Q& q, Tag&& tag) { q.query(::std::forward<Tag>(tag)); })
auto try_query(const Q& q, Tag&& tag, Args&&...) noexcept -> decltype(auto) {
    return q.query(::std::forward<Tag>(tag));
}
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif
