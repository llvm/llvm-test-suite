// include/beman/execution/detail/meta_transform.hpp                -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_META_TRANSFORM
#define INCLUDED_BEMAN_EXECUTION_DETAIL_META_TRANSFORM

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.meta.contains;
#else
#include <beman/execution/detail/meta_contains.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail::meta::detail {
template <template <typename> class Transform, typename List>
struct transform;

template <template <typename> class Transform, template <typename... T> class List, typename... T>
struct transform<Transform, List<T...>> {
    using type = List<Transform<T>...>;
};
} // namespace beman::execution::detail::meta::detail

namespace beman::execution::detail::meta {
template <template <typename> class Transform, typename List>
using transform = typename ::beman::execution::detail::meta::detail::transform<Transform, List>::type;
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_META_TRANSFORM
