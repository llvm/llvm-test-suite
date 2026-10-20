// include/beman/execution/detail/data_type.hpp                       -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_DATA_TYPE
#define INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_DATA_TYPE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Sndr>
using data_type = decltype(::std::declval<Sndr>().template get<1>());
}

// ----------------------------------------------------------------------------

#endif
