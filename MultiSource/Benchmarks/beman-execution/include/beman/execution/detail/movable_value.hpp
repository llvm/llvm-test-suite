// include/beman/execution/detail/movable_value.hpp                 -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_MOVABLE_VALUE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_MOVABLE_VALUE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename T>
concept movable_value =
    ::std::move_constructible<::std::decay_t<T>> && ::std::constructible_from<::std::decay_t<T>, T> &&
    (!::std::is_array_v<::std::remove_reference_t<T>>);
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_MOVABLE_VALUE
