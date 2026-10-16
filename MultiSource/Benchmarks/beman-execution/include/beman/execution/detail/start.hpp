// include/beman/execution/detail/start.hpp                         -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_START
#define INCLUDED_BEMAN_EXECUTION_DETAIL_START

#include <beman/execution/detail/common.hpp>
#include <beman/execution/detail/suppress_push.hpp>

// ----------------------------------------------------------------------------

namespace beman::execution {
struct start_t {
    template <typename State>
    auto operator()(State&&) const -> void = BEMAN_EXECUTION_DELETE("start(obj) requires an lvalue argument");
    template <typename State>
        requires(not requires(State& state) { state.start(); })
    auto operator()(State&) const -> void = BEMAN_EXECUTION_DELETE("state needs to have a start() member");
    template <typename State>
        requires(not requires(const State& state) { state.start(); })
    auto operator()(const State&) const -> void = BEMAN_EXECUTION_DELETE("state needs to have a start() member");

    template <typename State>
    auto operator()(const State& state) const noexcept -> void {
        static_assert(noexcept(state.start()), "state start() member has to be noexcept");
        state.start();
    }
    // NOLINTBEGIN(misc-no-recursion)
    template <typename State>
    auto operator()(State& state) const noexcept -> void {
        static_assert(noexcept(state.start()), "state start() member has to be noexcept");
        state.start();
    }
    // NOLINTEND(misc-no-recursion)
};

inline constexpr start_t start{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#include <beman/execution/detail/suppress_pop.hpp>

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_START
