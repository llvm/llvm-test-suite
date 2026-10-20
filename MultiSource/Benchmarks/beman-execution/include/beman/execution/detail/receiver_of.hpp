// include/beman/execution/detail/receiver_of.hpp                   -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_RECEIVER_OF
#define INCLUDED_BEMAN_EXECUTION_DETAIL_RECEIVER_OF

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.has_completions;
import beman.execution.detail.receiver;
#else
#include <beman/execution/detail/has_completions.hpp>
#include <beman/execution/detail/receiver.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
template <typename Receiver, typename Completions>
concept receiver_of =
    beman::execution::receiver<Receiver> && beman::execution::detail::has_completions<Receiver, Completions>;
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_RECEIVER_OF
