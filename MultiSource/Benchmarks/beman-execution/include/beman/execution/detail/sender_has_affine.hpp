// include/beman/execution/detail/sender_has_affine.hpp            -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_HAS_AFFINE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_HAS_AFFINE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.sender;
#else
#include <beman/execution/detail/sender.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Sender>
concept sender_has_affine = beman::execution::sender<::std::remove_cvref_t<Sender>> && requires(Sender&& sndr) {
    { ::std::forward<Sender>(sndr).affine() } -> ::beman::execution::sender;
};
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_HAS_AFFINE
