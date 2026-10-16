// include/beman/execution/detail/dependent_sender.hpp                     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_DEPENDENT_SENDER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_DEPENDENT_SENDER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.get_completion_signatures;
import beman.execution.detail.sender;
#else
#include <beman/execution/detail/get_completion_signatures.hpp>
#include <beman/execution/detail/sender.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <auto>
auto non_dependent_sender_helper() noexcept -> void {}

template <typename Sender>
concept non_dependent_sender = ::beman::execution::sender<Sender> && requires {
    ::beman::execution::detail::non_dependent_sender_helper<::beman::execution::get_completion_signatures<Sender>()>();
};
} // namespace beman::execution::detail

namespace beman::execution {
template <typename Sender>
concept dependent_sender =
    ::beman::execution::sender<Sender> && !::beman::execution::detail::non_dependent_sender<Sender>;
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_DEPENDENT_SENDER
