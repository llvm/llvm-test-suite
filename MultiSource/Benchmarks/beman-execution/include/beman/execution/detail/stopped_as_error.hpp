// include/beman/execution/detail/stopped_as_error.hpp                  -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_STOPPED_AS_ERROR
#define INCLUDED_BEMAN_EXECUTION_DETAIL_STOPPED_AS_ERROR

// ----------------------------------------------------------------------------
#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.forward_like;
import beman.execution.detail.just;
import beman.execution.detail.let;
import beman.execution.detail.make_sender;
import beman.execution.detail.movable_value;
import beman.execution.detail.sender;
import beman.execution.detail.sender_adaptor_closure;
import beman.execution.detail.sender_for;
import beman.execution.detail.set_value;
#else
#include <beman/execution/detail/forward_like.hpp>
#include <beman/execution/detail/just.hpp>
#include <beman/execution/detail/let.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/movable_value.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/sender_adaptor_closure.hpp>
#include <beman/execution/detail/sender_for.hpp>
#include <beman/execution/detail/set_value.hpp>
#endif

namespace beman::execution::detail {
struct stopped_as_error_t : ::beman::execution::sender_adaptor_closure<stopped_as_error_t> {
    template <::beman::execution::detail::sender_for<stopped_as_error_t> Sndr, typename Env>
    auto transform_sender(::beman::execution::set_value_t, Sndr&& sndr, Env&&) const noexcept {
        auto&& data  = sndr.template get<1>();
        auto&& child = sndr.template get<2>();
        using Error  = ::std::decay_t<decltype(data)>;
        return ::beman::execution::let_stopped(
            ::beman::execution::detail::forward_like<Sndr>(child),
            [error = ::beman::execution::detail::forward_like<Sndr>(data)]() mutable noexcept(
                ::std::is_nothrow_move_constructible_v<Error>) {
                return ::beman::execution::just_error(::std::move(error));
            });
    }

    template <::beman::execution::sender Sndr, ::beman::execution::detail::movable_value Error>
    auto operator()(Sndr&& sndr, Error error) const {
        return ::beman::execution::detail::make_sender(
            stopped_as_error_t{}, std::move(error), ::std::forward<Sndr>(sndr));
    }

    template <::beman::execution::detail::movable_value Error>
    auto operator()(Error error) const {
        return ::beman::execution::detail::make_sender_adaptor(*this, ::std::move(error));
    }
};

} // namespace beman::execution::detail

namespace beman::execution {
using stopped_as_error_t = ::beman::execution::detail::stopped_as_error_t;
inline constexpr stopped_as_error_t stopped_as_error{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_STOPPED_AS_ERROR
