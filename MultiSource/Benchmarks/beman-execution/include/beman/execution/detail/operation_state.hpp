// include/beman/execution/detail/operation_state.hpp               -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_OPERATION_STATE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_OPERATION_STATE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.start;
#else
#include <beman/execution/detail/start.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
struct operation_state_tag {};

using operation_state_t [[deprecated("operation_state_t has been renamed operation_state_tag")]] = operation_state_tag;

template <typename State>
concept operation_state =
    ::std::derived_from<typename State::operation_state_concept, ::beman::execution::operation_state_tag> &&
    ::std::is_object_v<State> && requires(State& state) {
        { ::beman::execution::start(state) } noexcept;
    };
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_OPERATION_STATE
