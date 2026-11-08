// include/beman/execution/detail/meta_contains.hpp                 -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_META_CONTAINS
#define INCLUDED_BEMAN_EXECUTION_DETAIL_META_CONTAINS

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail::meta {
template <typename T, typename... S>
inline constexpr bool contains{(::std::same_as<T, S> || ...)};
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_META_CONTAINS
