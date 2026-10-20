// include/beman/execution/detail/meta_index.hpp                     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_META_INDEX
#define INCLUDED_BEMAN_EXECUTION_DETAIL_META_INDEX

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <cstddef>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail::meta {
template <::std::size_t, typename, typename>
struct index {
    static constexpr ::std::size_t value = static_cast<::std::size_t>(-1);
};
template <::std::size_t I, template <typename...> class L, typename First, typename... Rest, typename T>
struct index<I, L<First, Rest...>, T> : index<I + 1uz, L<Rest...>, T> {};
template <::std::size_t I, template <typename...> class L, typename... Rest, typename T>
struct index<I, L<T, Rest...>, T> {
    static constexpr ::std::size_t value = I;
};
template <typename List, typename T>
inline constexpr ::std::size_t index_v{::beman::execution::detail::meta::index<0uz, List, T>::value};
} // namespace beman::execution::detail::meta

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_META_INDEX
