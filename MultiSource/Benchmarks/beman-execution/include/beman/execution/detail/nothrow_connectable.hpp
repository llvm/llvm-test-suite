// include/beman/execution/detail/nothrow_connectable.hpp                        -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_NOTHROW_CONNECTABLE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_NOTHROW_CONNECTABLE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.connect;
import beman.execution.detail.generic_receiver;
import beman.execution.detail.nothrow_callable;
#else
#include <beman/execution/detail/connect.hpp>
#include <beman/execution/detail/generic_receiver.hpp>
#include <beman/execution/detail/nothrow_callable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
/// A sender that doesn't throw when connected to a receiver.
template <typename Sender, typename... Env>
concept nothrow_connectable =
    ::beman::execution::detail::nothrow_callable<::beman::execution::connect_t, Sender, generic_receiver<Env...>>;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif
