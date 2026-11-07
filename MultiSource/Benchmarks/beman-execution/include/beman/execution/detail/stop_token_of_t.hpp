// include/beman/execution/detail/stop_token_of_t.hpp               -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_STOP_TOKEN_OF
#define INCLUDED_BEMAN_EXECUTION_DETAIL_STOP_TOKEN_OF

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.get_stop_token;
#else
#include <beman/execution/detail/get_stop_token.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
template <typename T>
using stop_token_of_t = ::std::remove_cvref_t<decltype(::beman::execution::get_stop_token(::std::declval<T>()))>;
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_STOP_TOKEN_OF
