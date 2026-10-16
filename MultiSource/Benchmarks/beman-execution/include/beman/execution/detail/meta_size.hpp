// include/beman/execution/detail/meta_size.hpp                     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_META_SIZE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_META_SIZE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <cstddef>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail::meta {
template <typename>
struct size;
template <template <typename...> class L, typename... T>
struct size<L<T...>> {
    static constexpr ::std::size_t value{sizeof...(T)};
};
template <typename T>
inline constexpr ::std::size_t size_v{::beman::execution::detail::meta::size<T>::value};
} // namespace beman::execution::detail::meta

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_META_SIZE
