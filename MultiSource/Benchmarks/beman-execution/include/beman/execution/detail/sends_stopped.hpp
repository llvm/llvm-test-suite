// include/beman/execution/detail/sends_stopped.hpp                 -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SENDS_STOPPED
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SENDS_STOPPED

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.completion_signatures_of_t;
import beman.execution.detail.env;
import beman.execution.detail.gather_signatures;
import beman.execution.detail.sender_in;
import beman.execution.detail.set_stopped;
import beman.execution.detail.type_list;
#else
#include <beman/execution/detail/completion_signatures_of_t.hpp>
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/gather_signatures.hpp>
#include <beman/execution/detail/sender_in.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/type_list.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
template <typename Sender, typename Env = ::beman::execution::env<>>
    requires ::beman::execution::sender_in<Sender, Env>
inline constexpr bool sends_stopped{!::std::same_as<
    ::beman::execution::detail::type_list<>,
    ::beman::execution::detail::gather_signatures<::beman::execution::set_stopped_t,
                                                  ::beman::execution::completion_signatures_of_t<Sender, Env>,
                                                  ::beman::execution::detail::type_list,
                                                  ::beman::execution::detail::type_list>>};
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SENDS_STOPPED
