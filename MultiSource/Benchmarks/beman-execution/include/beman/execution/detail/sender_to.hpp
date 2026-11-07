// include/beman/execution/detail/sender_to.hpp                     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_TO
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_TO

#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif
#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.completion_signatures_of_t;
import beman.execution.detail.connect;
import beman.execution.detail.env_of_t;
import beman.execution.detail.receiver_of;
import beman.execution.detail.sender_in;
#else
#include <beman/execution/detail/completion_signatures_of_t.hpp>
#include <beman/execution/detail/connect.hpp>
#include <beman/execution/detail/env_of_t.hpp>
#include <beman/execution/detail/receiver_of.hpp>
#include <beman/execution/detail/sender_in.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
template <typename Sender, typename Receiver>
concept sender_to =
    ::beman::execution::sender_in<Sender, ::beman::execution::env_of_t<Receiver>> &&
    ::beman::execution::receiver_of<
        Receiver,
        ::beman::execution::completion_signatures_of_t<Sender, ::beman::execution::env_of_t<Receiver>>> &&
    requires(Sender&& sndr, Receiver&& rcvr) {
        ::beman::execution::connect(::std::forward<Sender>(sndr), ::std::forward<Receiver>(rcvr));
    };
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_TO
