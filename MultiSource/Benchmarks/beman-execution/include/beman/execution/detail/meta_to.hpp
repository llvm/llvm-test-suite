// include/beman/execution/detail/meta_to                           -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_META_TO
#define INCLUDED_BEMAN_EXECUTION_DETAIL_META_TO

#include <beman/execution/detail/common.hpp>

// ----------------------------------------------------------------------------

namespace beman::execution::detail::meta {
template <template <typename...> class To, typename>
struct to_type_list;
template <template <typename...> class To, template <typename...> class List, typename... T>
struct to_type_list<To, List<T...>> {
    using type = To<T...>;
};
template <template <typename...> class To, typename T>
using to = typename ::beman::execution::detail::meta::to_type_list<To, T>::type;
} // namespace beman::execution::detail::meta

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_META_TO
