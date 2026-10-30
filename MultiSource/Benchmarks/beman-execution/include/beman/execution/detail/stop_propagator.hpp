// include/beman/execution/detail/stop_propagator.hpp                -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_STOP_PROPAGATOR
#define INCLUDED_BEMAN_EXECUTION_DETAIL_STOP_PROPAGATOR

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <functional>
#include <optional>
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.inplace_stop_source;
import beman.execution.detail.stoppable_source;
import beman.execution.detail.stoppable_token;
import beman.execution.detail.stop_callback_for_t;
import beman.execution.detail.unstoppable_token;
#else
#include <beman/execution/detail/inplace_stop_source.hpp>
#include <beman/execution/detail/stoppable_source.hpp>
#include <beman/execution/detail/stoppable_token.hpp>
#include <beman/execution/detail/stop_callback_for_t.hpp>
#include <beman/execution/detail/unstoppable_token.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <::beman::execution::stoppable_token StopToken>
class stop_propagator {
  public:
    explicit stop_propagator(StopToken stop_token) noexcept
        : stop_callback_(::std::move(stop_token), ::std::bind_front(&stop_propagator::propagate, this)) {}

    auto get_token() const noexcept -> ::std::optional<::beman::execution::inplace_stop_token> {
        return stop_source_.get_token();
    }

  private:
    auto propagate() noexcept -> void { stop_source_.request_stop(); }

  private:
    using stop_cb_t = decltype(::std::bind_front(&stop_propagator::propagate, ::std::declval<stop_propagator*>()));

    ::beman::execution::inplace_stop_source                       stop_source_;
    ::beman::execution::stop_callback_for_t<StopToken, stop_cb_t> stop_callback_;
};

template <>
class stop_propagator<::beman::execution::inplace_stop_token> {
  public:
    explicit stop_propagator(::beman::execution::inplace_stop_token stop_token) noexcept : stop_token_(stop_token) {}

    auto get_token() const noexcept -> ::std::optional<::beman::execution::inplace_stop_token> { return stop_token_; }

  private:
    ::beman::execution::inplace_stop_token stop_token_;
};

template <::beman::execution::unstoppable_token StopToken>
class stop_propagator<StopToken> {
  public:
    explicit stop_propagator(StopToken) noexcept {}

    static auto get_token() noexcept -> ::std::optional<::beman::execution::inplace_stop_token> {
        return ::std::nullopt;
    }
};
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_STOP_PROPAGATOR
