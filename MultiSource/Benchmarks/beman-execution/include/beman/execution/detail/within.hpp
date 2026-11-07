// include/beman/execution/detail/within.hpp                          -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_WITHIN
#define INCLUDED_BEMAN_EXECUTION_DETAIL_WITHIN

#include <beman/execution/detail/common.hpp>
#include <beman/execution/detail/suppress_push.hpp>
#include <cassert>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <exception>
#include <functional>
#include <optional>
#include <utility>
#include <variant>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_sender;
import beman.execution.detail.completion_signatures_of_t;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.completion_storage;
import beman.execution.detail.connect;
import beman.execution.detail.connect_result_t;
import beman.execution.detail.default_impls;
import beman.execution.detail.elide;
import beman.execution.detail.enter_scope_sender;
import beman.execution.detail.env;
import beman.execution.detail.env_of_t;
import beman.execution.detail.error_types_of_t;
import beman.execution.detail.exit_scope_sender_of_t;
import beman.execution.detail.get_env;
import beman.execution.detail.impls_for;
import beman.execution.detail.make_sender;
import beman.execution.detail.meta.combine;
import beman.execution.detail.meta.unique;
import beman.execution.detail.nothrow_callable;
import beman.execution.detail.product_type;
import beman.execution.detail.operation_state;
import beman.execution.detail.receiver;
import beman.execution.detail.sender;
import beman.execution.detail.sends_stopped;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.start;
import beman.execution.detail.unreachable;
#else
#include <beman/execution/detail/basic_sender.hpp>
#include <beman/execution/detail/completion_signatures_of_t.hpp>
#include <beman/execution/detail/completion_signatures.hpp>
#include <beman/execution/detail/completion_storage.hpp>
#include <beman/execution/detail/connect.hpp>
#include <beman/execution/detail/connect_result_t.hpp>
#include <beman/execution/detail/default_impls.hpp>
#include <beman/execution/detail/elide.hpp>
#include <beman/execution/detail/enter_scope_sender.hpp>
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/env_of_t.hpp>
#include <beman/execution/detail/error_types_of_t.hpp>
#include <beman/execution/detail/exit_scope_sender_of_t.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/impls_for.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/meta_combine.hpp>
#include <beman/execution/detail/meta_unique.hpp>
#include <beman/execution/detail/nothrow_callable.hpp>
#include <beman/execution/detail/product_type.hpp>
#include <beman/execution/detail/operation_state.hpp>
#include <beman/execution/detail/receiver.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/sends_stopped.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/start.hpp>
#include <beman/execution/detail/unreachable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {

/// The type of the `within` algorithm.
struct within_t {
    /// Creates a sender that runs `work` within the scope of `scope`.
    template <::beman::execution::enter_scope_sender Scope, ::beman::execution::sender Work>
    auto operator()(Scope&& scope, Work&& work) const
        noexcept(::std::is_nothrow_constructible_v<::std::remove_cvref_t<Scope>, Scope> &&
                 ::std::is_nothrow_constructible_v<::std::remove_cvref_t<Work>, Work>) {
        return ::beman::execution::detail::make_sender(
            *this,
            ::beman::execution::detail::product_type{::std::forward<decltype(scope)>(scope),
                                                     ::std::forward<decltype(work)>(work)});
    }

  private:
    /// Helper that yields the signatures of the `within` sender `Sender` when used with the environment `Env`.
    template <typename Sender, typename... Env>
    struct get_signatures;
    template <typename Sender>
    struct get_signatures<Sender> : get_signatures<Sender, ::beman::execution::env<>> {};
    template <typename Scope, typename Work, typename Env>
    struct get_signatures<
        ::beman::execution::detail::basic_sender<::beman::execution::detail::within_t,
                                                 ::beman::execution::detail::product_type<Scope, Work>>,
        Env> {
        template <typename... E>
        /// Converts error types `E...` to a `completion_signatures` type with `set_error_t(E)...` signatures.
        using as_set_error = ::beman::execution::completion_signatures<::beman::execution::set_error_t(E)...>;

        /// The error signatures of `Scope` sender.
        using scope_error_types = ::beman::execution::error_types_of_t<Scope, Env, as_set_error>;
        /// The stopped signatures of `Scope` sender.
        using scope_stopped_types =
            ::std::conditional_t<::beman::execution::sends_stopped<Scope, Env>,
                                 ::beman::execution::completion_signatures<::beman::execution::set_stopped_t()>,
                                 ::beman::execution::completion_signatures<>>;
        /// The resulting completion signatures of the `within` sender.
        /// This is the combination of the completion signatures of `Work` and the error and stopped signatures of
        /// `Scope`.
        using type = ::beman::execution::detail::meta::unique<::beman::execution::detail::meta::combine<
            ::beman::execution::completion_signatures_of_t<Work, Env>,
            ::beman::execution::detail::meta::combine<scope_error_types, scope_stopped_types>>>;
    };

  public:
    /// Returns the completion signatures of the `within` sender `Sender` when used with the environment `Env`.
    template <typename Sender, typename... Env>
    static consteval auto get_completion_signatures() noexcept {
        return typename get_signatures<::std::remove_cvref_t<Sender>, Env...>::type{};
    }

    template <::beman::execution::enter_scope_sender Scope,
              ::beman::execution::sender             Work,
              ::beman::execution::receiver           Receiver>
    struct state;

    struct impls_for : ::beman::execution::detail::default_impls {
        struct get_state_impl {

            template <typename Receiver>
            auto operator()(auto&& sender, Receiver&& receiver) const noexcept(false) {
                auto&& data = ::std::forward<decltype(sender)>(sender).template get<1>();
                return ::beman::execution::detail::within_t::state<
                    decltype(::std::forward<decltype(data)>(data).template get<0>()),
                    decltype(::std::forward<decltype(data)>(data).template get<1>()),
                    Receiver>(::std::forward<decltype(data)>(data).template get<0>(),
                              ::std::forward<decltype(data)>(data).template get<1>(),
                              std::forward<Receiver>(receiver));
            }
        };
        static constexpr auto get_state{get_state_impl{}};
        struct start_impl {
            auto operator()(auto& s, auto&) const noexcept { s.start(); }
        };
        static constexpr auto start{start_impl{}};
    };
};

/// Base class for a receiver that delegates to a state object.
template <typename State, typename Env>
struct within_receiver_base {
    /// This is a receiver.
    using receiver_concept = ::beman::execution::receiver_tag;

    /// Returns the environment of the receiver.
    auto get_env() const noexcept -> Env { return state_.get_env(); }

    /// The state object that this receiver delegates to.
    State& state_;
};

/// Receiver connected to the enter operation.
template <typename State, typename Env>
struct within_enter_receiver : ::beman::execution::detail::within_receiver_base<State, Env> {
    using ::beman::execution::detail::within_receiver_base<State, Env>::state_;

    /// Handles success completion of the enter operation.
    template <typename... Args>
    void set_value(Args&&... args) && noexcept {
        state_.on_enter_set_value(::std::forward<Args>(args)...);
    }
    /// Handles error completion of the enter operation.
    template <typename E>
    void set_error(E&& e) && noexcept {
        state_.on_enter_set_error(::std::forward<E>(e));
    }
    /// Handles stopped completion of the enter operation.
    void set_stopped() && noexcept { state_.on_enter_set_stopped(); }
};

/// Receiver connected to the exit operation.
template <typename State, typename Env>
struct within_exit_receiver : ::beman::execution::detail::within_receiver_base<State, Env> {
    using ::beman::execution::detail::within_receiver_base<State, Env>::state_;

    /// Handles success completion of the exit operation.
    void set_value() && noexcept { state_.on_exit_set_value(); }
};

/// Receiver connected to the work operation.
template <typename State, typename Env>
struct within_work_receiver : ::beman::execution::detail::within_receiver_base<State, Env> {
    using ::beman::execution::detail::within_receiver_base<State, Env>::state_;

    /// Handles success completion of the work operation.
    template <typename... Args>
    void set_value(Args&&... args) && noexcept {
        state_.on_work_completion(::beman::execution::set_value_t{}, ::std::forward<Args>(args)...);
    }
    /// Handles error completion of the work operation.
    template <typename E>
    void set_error(E&& e) && noexcept {
        state_.on_work_completion(::beman::execution::set_error_t{}, ::std::forward<E>(e));
    }
    /// Handles stopped completion of the work operation.
    void set_stopped() && noexcept { state_.on_work_completion(::beman::execution::set_stopped_t{}); }
};

/// The operation state of the `within` sender constructed from `Scope` and `Work`, and connected to `Receiver`.
template <::beman::execution::enter_scope_sender Scope,
          ::beman::execution::sender             Work,
          ::beman::execution::receiver           Receiver>
struct within_t::state {
    using operation_state_concept = ::beman::execution::operation_state_tag;
    using self_t                  = state<Scope, Work, Receiver>;
    using scope_t                 = ::std::remove_cvref_t<Scope>;
    using work_t                  = ::std::remove_cvref_t<Work>;
    using env_t                   = ::beman::execution::env_of_t<Receiver>;
    using exit_scope_sender_t     = ::beman::execution::exit_scope_sender_of_t<scope_t, env_t>;
    using enter_receiver_t        = ::beman::execution::detail::within_enter_receiver<self_t, env_t>;
    using work_receiver_t         = ::beman::execution::detail::within_work_receiver<self_t, env_t>;
    using exit_receiver_t         = ::beman::execution::detail::within_exit_receiver<self_t, env_t>;
    using enter_op_t              = ::beman::execution::connect_result_t<scope_t, enter_receiver_t>;
    using work_op_t               = ::beman::execution::connect_result_t<work_t, work_receiver_t>;
    using exit_op_t               = ::beman::execution::connect_result_t<exit_scope_sender_t, exit_receiver_t>;
    using work_completions_t      = ::beman::execution::completion_signatures_of_t<work_t, env_t>;

    /// The state that is needed during the execution of "enter" async operation.
    struct enter_state {
        /// The operation state of the "enter" async operation.
        enter_op_t op;
        /// The work sender that will be executed after the "enter" async operation completes successfully.
        work_t work;
    };

    /// The state that is needed during the execution of "work" async operation.
    struct work_state {
        /// The operation state of the "work" async operation.
        work_op_t op;
        /// The exit scope sender that will be executed after the "work" async operation completes successfully.
        exit_scope_sender_t exit_sender;
    };

    /// The state that is needed during the execution of "exit" async operation.
    struct exit_state {
        /// The operation state of the "exit" async operation.
        exit_op_t op;
        /// The completion signals produced by "work" operation, which will be used to complete our operation.
        ::beman::execution::detail::completion_storage<work_completions_t> work_completion;
    };

    /// The final receiver of this operation.
    ::std::remove_cvref_t<Receiver> receiver;
    /// The state needed in various stages of our operation.
    std::variant<enter_state, work_state, exit_state> state_;

    /// Constructs `*this` from given arguments.
    template <::beman::execution::sender S, ::beman::execution::sender W>
    state(S&& scope, W&& work, Receiver&& r)
        : receiver(std::forward<Receiver>(r)),
          state_(std::in_place_type<enter_state>, ::beman::execution::detail::elide([&]() noexcept {
                     return enter_state{
                         ::beman::execution::connect(::std::forward<S>(scope), enter_receiver_t{{*this}}),
                         ::std::forward<W>(work)};
                 })) {}

    /// Starts the `within` async operation represented by `*this`.
    auto start() noexcept -> void {
        // Start the operation for the enter scope sender; this would eventually trigger the rest of the work.
        const auto p = std::get_if<enter_state>(&state_);
        assert(p);
        ::beman::execution::start(p->op);
    }

    /// Returns the environment of the target receiver.
    auto get_env() const noexcept -> env_t { return ::beman::execution::get_env(this->receiver); }

    /// Called when the enter scope sender completes successfully with `exit_sender`.
    void on_enter_set_value(exit_scope_sender_t&& exit_sender) noexcept {
        constexpr auto nothrow =
            ::beman::execution::detail::nothrow_callable<::beman::execution::connect_t, work_t, work_receiver_t>;

        const auto p = std::get_if<enter_state>(&state_);
        assert(p);
        try {
            auto  work_sender = ::std::move(p->work);
            auto& new_state =
                this->state_.template emplace<work_state>(::beman::execution::detail::elide([&]() noexcept {
                    return work_state{::beman::execution::connect(::std::move(work_sender), work_receiver_t{{*this}}),
                                      ::std::move(exit_sender)};
                }));
            ::beman::execution::start(new_state.op);
        } catch (...) {
            if constexpr (nothrow) {
                ::beman::execution::detail::unreachable();
            } else {
                ::beman::execution::set_error(::std::move(this->receiver), ::std::current_exception());
            }
        }
    }

    /// Called when the enter scope sender completes with an error `e`.
    template <typename E>
    void on_enter_set_error(E&& e) noexcept {
        ::beman::execution::set_error(::std::move(this->receiver), ::std::forward<E>(e));
    }

    /// Called when the enter scope sender is stopped.
    void on_enter_set_stopped() noexcept { ::beman::execution::set_stopped(::std::move(this->receiver)); }

    /// Called when the work sender completes with tag `t` and `args...` to move to the exit state.
    template <typename Tag, typename... Args>
    void on_work_completion(Tag t, Args&&... args) noexcept {
        const auto p = std::get_if<work_state>(&state_);
        assert(p);

        // Put the args in the completion storage, before destroying the operation state.
        ::beman::execution::detail::completion_storage<work_completions_t> completion;
        completion.store(t, ::std::forward<Args>(args)...);
        auto exit_sender = ::std::move(p->exit_sender);
        // Replace the state as we transition to "exit" state.
        auto& new_state = this->state_.template emplace<exit_state>(::beman::execution::detail::elide([&]() noexcept {
            return exit_state{::beman::execution::connect(::std::move(exit_sender), exit_receiver_t{{*this}}),
                              std::move(completion)};
        }));
        ::beman::execution::start(new_state.op);
    }

    /// Called when the exit scope sender completes successfully to complete the entire operation in `*this`.
    void on_exit_set_value() noexcept {
        const auto p = std::get_if<exit_state>(&state_);
        assert(p);
        std::move(p->work_completion).complete(::std::move(this->receiver));
    }
};

}; // namespace beman::execution::detail

#include <beman/execution/detail/suppress_pop.hpp>

namespace beman::execution {
/*!
 * \brief `within_t` is the type of `within`.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
using within_t = ::beman::execution::detail::within_t;

/*!
 * \brief `within` is a sender adaptor that runs a work sender within the scope of a scope sender.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 *
 * The `within` sender adaptor takes two senders: a scope sender and a work sender. It runs the work sender within the
 * context of the scope.
 *
 * Usually forwards the completion of the work sender, but may also complete with an error or stopped signal if the
 * scope sender completes with an error or is stopped.
 */
inline constexpr ::beman::execution::within_t within{};

} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_WITHIN
