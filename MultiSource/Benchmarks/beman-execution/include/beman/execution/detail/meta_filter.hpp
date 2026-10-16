// include/beman/execution/detail/meta_filter.hpp                   -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_META_FILTER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_META_FILTER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.meta.prepend;
#else
#include <beman/execution/detail/meta_prepend.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail::meta::detail {
template <template <typename> class, typename>
struct filter;

template <template <typename, typename> class, typename, typename>
struct filter_tag;

template <template <typename> class Predicate, template <typename...> class List>
struct filter<Predicate, List<>> {
    using type = List<>;
};

template <template <typename, typename> class Predicate, typename Tag, template <typename...> class List>
struct filter_tag<Predicate, Tag, List<>> {
    using type = List<>;
};

template <template <typename> class Predicate, template <typename...> class List, typename H, typename... T>
struct filter<Predicate, List<H, T...>> {
    using tail = typename beman::execution::detail::meta::detail::filter<Predicate, List<T...>>::type;
    using type = ::std::conditional_t<Predicate<H>::value, ::beman::execution::detail::meta::prepend<H, tail>, tail>;
};

template <template <typename, typename> class Predicate,
          typename Tag,
          template <typename...> class List,
          typename H,
          typename... T>
struct filter_tag<Predicate, Tag, List<H, T...>> {
    using tail = typename beman::execution::detail::meta::detail::filter_tag<Predicate, Tag, List<T...>>::type;
    using type =
        ::std::conditional_t<Predicate<Tag, H>::value, ::beman::execution::detail::meta::prepend<H, tail>, tail>;
};
} // namespace beman::execution::detail::meta::detail

namespace beman::execution::detail::meta {
template <template <typename> class Predicate, typename List>
using filter = typename ::beman::execution::detail::meta::detail::filter<Predicate, List>::type;

template <template <typename, typename> class Predicate, typename Tag, typename List>
using filter_tag = typename ::beman::execution::detail::meta::detail::filter_tag<Predicate, Tag, List>::type;
} // namespace beman::execution::detail::meta

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_META_FILTER
