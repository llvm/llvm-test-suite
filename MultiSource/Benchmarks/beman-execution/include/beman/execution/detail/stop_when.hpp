// include/beman/execution/detail/stop_when.hpp                       -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_STOP_WHEN
#define INCLUDED_BEMAN_EXECUTION_DETAIL_STOP_WHEN

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <iostream>
#include <optional>
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.connect;
import beman.execution.detail.get_completion_signatures;
import beman.execution.detail.get_env;
import beman.execution.detail.get_stop_token;
import beman.execution.detail.inplace_stop_source;
import beman.execution.detail.operation_state;
import beman.execution.detail.receiver;
import beman.execution.detail.sender;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.start;
import beman.execution.detail.stop_callback_for_t;
import beman.execution.detail.stoppable_token;
import beman.execution.detail.unstoppable_token;
#else
#include <beman/execution/detail/connect.hpp>
#include <beman/execution/detail/get_completion_signatures.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/get_stop_token.hpp>
#include <beman/execution/detail/inplace_stop_source.hpp>
#include <beman/execution/detail/operation_state.hpp>
#include <beman/execution/detail/receiver.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/start.hpp>
#include <beman/execution/detail/stop_callback_for_t.hpp>
#include <beman/execution/detail/stoppable_token.hpp>
#include <beman/execution/detail/unstoppable_token.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
inline constexpr struct stop_when_t {
    template <::beman::execution::sender Sndr, ::beman::execution::stoppable_token Tok>
    struct sender;

    template <::beman::execution::sender Sndr, ::beman::execution::stoppable_token Tok>
    auto operator()(Sndr&& sndr, Tok&& tok) const noexcept;
} stop_when{};
} // namespace beman::execution::detail

template <::beman::execution::sender Sndr, ::beman::execution::stoppable_token Tok>
struct beman::execution::detail::stop_when_t::sender {
    using sender_concept = ::beman::execution::sender_tag;

    stop_when_t               stop_when{};
    std::remove_cvref_t<Tok>  tok;
    std::remove_cvref_t<Sndr> sndr;

    template <::beman::execution::receiver Rcvr>
    struct base_state {
        using rcvr_t = ::std::remove_cvref_t<Rcvr>;
        rcvr_t                                  rcvr;
        ::beman::execution::inplace_stop_source source{};
        base_state(Rcvr&& r) : rcvr(::std::forward<Rcvr>(r)) {}
        virtual ~base_state() noexcept          = default;
        virtual auto reset() & noexcept -> void = 0;
    };
    template <::beman::execution::receiver Rcvr>
    struct state : base_state<Rcvr> {
        using operation_state_concept = ::beman::execution::operation_state_tag;
        using rcvr_t                  = base_state<Rcvr>::rcvr_t;
        using token1_t                = ::std::remove_cvref_t<Tok>;
        using token2_t =
            decltype(::beman::execution::get_stop_token(::beman::execution::get_env(::std::declval<rcvr_t>())));

        struct cb_t {
            ::beman::execution::inplace_stop_source& source;
            auto                                     operator()() const noexcept {
                ::std::cout << "stop_when: stop requested\n" << ::std::flush;
                this->source.request_stop();
            }
        };
        struct env {
            base_state<Rcvr>* st;
            auto              query(const ::beman::execution::get_stop_token_t&) const noexcept {
                return this->st->source.get_token();
            }
            template <typename Q, typename... A>
                requires requires(const Q& q, A&&... a, const rcvr_t& r) {
                    q(::beman::execution::get_env(r), ::std::forward<A>(a)...);
                }
            auto query(const Q& q, A&&... a) const noexcept {
                return q(::beman::execution::get_env(this->st->rcvr), ::std::forward<A>(a)...);
            }
        };

        struct receiver {
            using receiver_concept = ::beman::execution::receiver_tag;
            base_state<Rcvr>* st;

            auto get_env() const noexcept -> env { return env{this->st}; }
            template <typename... A>
            auto set_value(A&&... a) const noexcept -> void {
                this->st->reset();
                ::beman::execution::set_value(::std::move(this->st->rcvr), ::std::forward<A>(a)...);
            }
            template <typename E>
            auto set_error(E&& e) const noexcept -> void {
                this->st->reset();
                ::beman::execution::set_error(::std::move(this->st->rcvr), ::std::forward<E>(e));
            }
            auto set_stopped() const noexcept -> void {
                this->st->reset();
                ::beman::execution::set_stopped(::std::move(this->st->rcvr));
            }
        };
        using inner_state_t =
            decltype(::beman::execution::connect(::std::declval<Sndr>(), ::std::declval<receiver>()));

        token1_t                                                               tok;
        std::optional<::beman::execution::stop_callback_for_t<token1_t, cb_t>> cb1;
        std::optional<::beman::execution::stop_callback_for_t<token2_t, cb_t>> cb2;
        inner_state_t                                                          inner_state;

        template <::beman::execution::sender S, ::beman::execution::stoppable_token T, ::beman::execution::receiver R>
        state(S&& s, T&& t, R&& r)
            : base_state<Rcvr>{::std::forward<R>(r)},
              tok(::std::forward<T>(t)),
              inner_state(::beman::execution::connect(::std::forward<S>(s), receiver{this})) {}

        auto start() & noexcept {
            this->cb1.emplace(this->tok, cb_t{this->source});
            this->cb2.emplace(::beman::execution::get_stop_token(::beman::execution::get_env(this->rcvr)),
                              cb_t{this->source});
            ::beman::execution::start(this->inner_state);
        }
        auto reset() & noexcept -> void override {
            this->cb1.reset();
            this->cb2.reset();
        }
    };

    template <typename, typename... E>
    static consteval auto get_completion_signatures() noexcept {
        return ::beman::execution::get_completion_signatures<std::remove_cvref_t<Sndr>, E...>();
    }
    template <::beman::execution::receiver Rcvr>
    auto connect(Rcvr&& rcvr) && -> state<Rcvr> {
        return state<Rcvr>{std::move(this->sndr), ::std::move(this->tok), ::std::forward<Rcvr>(rcvr)};
    }
};

template <::beman::execution::sender Sndr, ::beman::execution::stoppable_token Tok>
inline auto beman::execution::detail::stop_when_t::operator()(Sndr&& sndr, Tok&& tok) const noexcept {
    if constexpr (::beman::execution::unstoppable_token<Tok>) {
        return ::std::forward<Sndr>(sndr);
    } else {
        return sender<Sndr, Tok>{*this, ::std::forward<Tok>(tok), ::std::forward<Sndr>(sndr)};
    }
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_STOP_WHEN
