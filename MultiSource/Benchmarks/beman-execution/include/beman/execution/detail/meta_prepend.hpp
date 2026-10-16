// include/beman/execution/detail/meta_prepend.hpp                  -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_META_PREPEND
#define INCLUDED_BEMAN_EXECUTION_DETAIL_META_PREPEND

#include <beman/execution/detail/common.hpp>

// ----------------------------------------------------------------------------

namespace beman::execution::detail::meta::detail {
template <typename, typename>
struct prepend;

template <template <typename...> class List, typename H, typename... T>
struct prepend<H, List<T...>> {
    using type = List<H, T...>;
};
} // namespace beman::execution::detail::meta::detail

namespace beman::execution::detail::meta {
template <typename H, typename Tail>
using prepend = typename ::beman::execution::detail::meta::detail::prepend<H, Tail>::type;
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_META_PREPEND
