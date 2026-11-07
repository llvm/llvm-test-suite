// include/beman/execution/detail/queryable.hpp                     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_QUERYABLE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_QUERYABLE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename T>
concept queryable = ::std::destructible<T>;
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_QUERYABLE
