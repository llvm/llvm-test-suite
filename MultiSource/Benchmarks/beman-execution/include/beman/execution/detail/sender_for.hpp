// include/beman/execution/detail/sender_for.hpp                    -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_FOR
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_FOR

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.sender;
import beman.execution.detail.sender_decompose;
import beman.execution.detail.tag_of_t;
#else
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/sender_decompose.hpp>
#include <beman/execution/detail/tag_of_t.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Sender, typename Tag>
concept sender_for = ::beman::execution::sender<Sender> && ::std::same_as<::beman::execution::tag_of_t<Sender>, Tag>;
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_FOR
