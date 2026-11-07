// include/beman/execution/detail/tag_of_t.hpp                      -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_TAG_OF
#define INCLUDED_BEMAN_EXECUTION_DETAIL_TAG_OF

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.sender_decompose;
#else
#include <beman/execution/detail/sender_decompose.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
template <typename Sender>
using tag_of_t = typename decltype(::beman::execution::detail::get_sender_meta(::std::declval<Sender&&>()))::tag_type;
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_TAG_OF
