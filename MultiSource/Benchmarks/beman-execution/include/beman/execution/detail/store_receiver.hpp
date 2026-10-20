// include/beman/execution/detail/store_receiver.hpp                  -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_STORE_RECEIVER
#define INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_STORE_RECEIVER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <memory>
#include <utility>
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.connect;
import beman.execution.detail.connect_result_t;
import beman.execution.detail.env_of_t;
import beman.execution.detail.get_completion_signatures;
import beman.execution.detail.get_env;
import beman.execution.detail.operation_state;
import beman.execution.detail.receiver;
import beman.execution.detail.sender;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.start;
#else
#include <beman/execution/detail/connect.hpp>
#include <beman/execution/detail/connect_result_t.hpp>
#include <beman/execution/detail/env_of_t.hpp>
#include <beman/execution/detail/get_completion_signatures.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/receiver.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/operation_state.hpp>
#include <beman/execution/detail/start.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct store_receiver_t {
    template <::beman::execution::receiver Rcvr>
    struct receiver {
        using receiver_concept = ::beman::execution::receiver_tag;
        Rcvr* rcvr;
        template <typename... Args>
        auto set_value(Args&&... args) && noexcept -> void {
            ::beman::execution::set_value(::std::move(*this->rcvr), ::std::forward<Args>(args)...);
        }
        template <typename Error>
        auto set_error(Error&& error) && noexcept -> void {
            ::beman::execution::set_error(::std::move(*this->rcvr), ::std::forward<Error>(error));
        }
        auto set_stopped() && noexcept -> void { ::beman::execution::set_stopped(::std::move(*this->rcvr)); }
        auto get_env() const noexcept { return ::beman::execution::get_env(*this->rcvr); }
    };
    template <::beman::execution::sender Sndr, typename Trans, ::beman::execution::receiver Rcvr>
    struct state {
        using operation_state_concept = ::beman::execution::operation_state_tag;
        using env_t                   = ::beman::execution::env_of_t<Rcvr>;
        using state_t = ::beman::execution::connect_result_t<decltype(::std::declval<Trans>()(
                                                                 ::std::declval<Sndr>(), ::std::declval<env_t>())),
                                                             receiver<Rcvr>>;
        Rcvr    rcvr;
        state_t op_state;
        template <::beman::execution::sender S, typename T, ::beman::execution::receiver R>
        state(S&& sndr, T&& trans, R&& r)
            : rcvr(::std::forward<R>(r)),
              op_state(::beman::execution::connect(
                  ::std::forward<T>(trans)(::std::forward<S>(sndr), ::beman::execution::get_env(this->rcvr)),
                  receiver<Rcvr>{::std::addressof(this->rcvr)})) {}
        auto start() & noexcept { ::beman::execution::start(this->op_state); }
    };
    template <::beman::execution::sender Sndr, typename Trans>
    struct sender {
        using sender_concept = ::beman::execution::sender_tag;
        using trans_t        = ::std::remove_cvref_t<Trans>;
        template <typename, typename... Env>
        static consteval auto get_completion_signatures() noexcept {
            return ::beman::execution::get_completion_signatures<
                decltype(::std::declval<trans_t>()(::std::declval<Sndr>(), ::std::declval<Env>()...)),
                Env...>();
        }
        ::std::remove_cvref_t<Sndr> sndr;
        trans_t                     trans;

        template <::beman::execution::receiver Receiver>
        auto connect(Receiver&& r) && {
            static_assert(::beman::execution::operation_state<state<Sndr, Trans, ::std::remove_cvref_t<Receiver>>>);
            return state<Sndr, Trans, ::std::remove_cvref_t<Receiver>>(
                ::std::move(this->sndr), ::std::move(this->trans), ::std::forward<Receiver>(r));
        }
        template <::beman::execution::receiver Receiver>
        auto connect(Receiver&& r) const& {
            static_assert(::beman::execution::operation_state<state<Sndr, Trans, ::std::remove_cvref_t<Receiver>>>);
            return state<Sndr, Trans, ::std::remove_cvref_t<Receiver>>(
                this->sndr, this->trans, ::std::forward<Receiver>(r));
        }
    };
    template <::beman::execution::sender Sndr, typename Trans>
    auto operator()(Sndr&& sndr, Trans&& trans) const {
        static_assert(::beman::execution::sender<sender<Sndr, Trans>>);
        return sender<Sndr, Trans>{::std::forward<Sndr>(sndr), ::std::forward<Trans>(trans)};
    }
};

inline constexpr store_receiver_t store_receiver{};
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif
