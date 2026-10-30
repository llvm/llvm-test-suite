// include/beman/execution/detail/nested_sender_has_affine.hpp     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_NESTED_SENDER_HAS_AFFINE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_NESTED_SENDER_HAS_AFFINE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.sender_has_affine;
#else
#include <beman/execution/detail/sender_has_affine.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Sender>
concept nested_sender_has_affine = requires(Sender&& sndr) {
    { sndr.template get<2>() } -> ::beman::execution::detail::sender_has_affine;
};
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_NESTED_SENDER_HAS_AFFINE
