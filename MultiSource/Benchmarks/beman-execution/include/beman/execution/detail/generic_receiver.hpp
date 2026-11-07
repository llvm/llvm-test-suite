// include/beman/execution/detail/generic_receiver.hpp                        -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_GENERIC_RECEIVER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_GENERIC_RECEIVER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.env;
import beman.execution.detail.receiver;
import beman.execution.detail.unreachable;
#else
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/receiver.hpp>
#include <beman/execution/detail/unreachable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {

/// A receiver with environment `Env` that accepts every possible completion.
template <typename Env = ::beman::execution::env<>>
struct generic_receiver {
    using receiver_concept = ::beman::execution::receiver_tag;

    template <typename... T>
    void set_value(T&&...) && noexcept {}
    template <typename E>
    void set_error(E&&) && noexcept {}
    void set_stopped() && noexcept {}

    auto get_env() const noexcept -> Env { ::beman::execution::detail::unreachable(); }
};

} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif
