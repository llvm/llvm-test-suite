// include/beman/execution/detail/spawn_future.hpp                    -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SPAWN_FUTURE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SPAWN_FUTURE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <exception>
#include <memory>
#include <mutex>
#include <tuple>
#include <type_traits>
#include <utility>
#include <variant>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.as_tuple;
import beman.execution.detail.basic_sender;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.completion_signatures_for;
import beman.execution.detail.completion_signatures_of_t;
import beman.execution.detail.connect_result_t;
import beman.execution.detail.decayed_tuple;
import beman.execution.detail.default_impls;
import beman.execution.detail.env;
import beman.execution.detail.get_allocator;
import beman.execution.detail.get_env;
import beman.execution.detail.impls_for;
import beman.execution.detail.inplace_stop_source;
import beman.execution.detail.join_env;
import beman.execution.detail.make_sender;
import beman.execution.detail.meta.combine;
import beman.execution.detail.meta.prepend;
import beman.execution.detail.meta.unique;
import beman.execution.detail.prop;
import beman.execution.detail.queryable;
import beman.execution.detail.receiver;
import beman.execution.detail.scope_token;
import beman.execution.detail.sender;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.spawn_get_allocator;
import beman.execution.detail.start;
import beman.execution.detail.stop_when;
import beman.execution.detail.write_env;
#else
#include <beman/execution/detail/as_tuple.hpp>
#include <beman/execution/detail/completion_signatures_of_t.hpp>
#include <beman/execution/detail/connect_result_t.hpp>
#include <beman/execution/detail/default_impls.hpp>
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/get_allocator.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/impls_for.hpp>
#include <beman/execution/detail/inplace_stop_source.hpp>
#include <beman/execution/detail/join_env.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/meta_combine.hpp>
#include <beman/execution/detail/meta_unique.hpp>
#include <beman/execution/detail/prop.hpp>
#include <beman/execution/detail/queryable.hpp>
#include <beman/execution/detail/receiver.hpp>
#include <beman/execution/detail/scope_token.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/spawn_get_allocator.hpp>
#include <beman/execution/detail/start.hpp>
#include <beman/execution/detail/stop_when.hpp>
#include <beman/execution/detail/write_env.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename>
struct non_throwing_args_copy;
template <typename Rc, typename... A>
struct non_throwing_args_copy<Rc(A...)> {
    static constexpr bool value = (true && ... && ::std::is_nothrow_constructible_v<::std::decay_t<A>, A>);
};
template <typename S>
inline constexpr bool non_throwing_args_copy_v{non_throwing_args_copy<S>::value};

template <typename Completions>
struct spawn_future_state_base;
template <typename... Sigs>
struct spawn_future_state_base<::beman::execution::completion_signatures<Sigs...>> {
    static constexpr bool has_non_throwing_args_copy = (true && ... && non_throwing_args_copy_v<Sigs>);
    using result_t                                   = ::beman::execution::detail::meta::unique<
        ::std::conditional_t<has_non_throwing_args_copy,
                             ::std::variant<::std::monostate, ::beman::execution::detail::as_tuple_t<Sigs>...>,
                             ::std::variant<::std::monostate,
                                            ::std::tuple<::beman::execution::set_error_t, ::std::exception_ptr>,
                                            ::beman::execution::detail::as_tuple_t<Sigs>...>>>;

    result_t result{};
    virtual ~spawn_future_state_base()       = default;
    virtual auto complete() noexcept -> void = 0;
};

template <typename Completions>
struct spawn_future_receiver {
    using receiver_concept = ::beman::execution::receiver_tag;
    using state_t          = ::beman::execution::detail::spawn_future_state_base<Completions>;

    state_t* state{};

    template <typename... A>
    auto set_value(A&&... a) && noexcept -> void {
        this->set_complete<::beman::execution::set_value_t>(::std::forward<A>(a)...);
    }
    template <typename E>
    auto set_error(E&& e) && noexcept -> void {
        this->set_complete<::beman::execution::set_error_t>(::std::forward<E>(e));
    }
    auto set_stopped() && noexcept -> void { this->set_complete<::beman::execution::set_stopped_t>(); }

    template <typename Tag, typename... T>
    auto set_complete(T&&... t) noexcept {
        try {
            this->state->result.template emplace<::beman::execution::detail::decayed_tuple<Tag, T...>>(
                Tag(), ::std::forward<T>(t)...);
        } catch (...) {
            if constexpr (!state_t::has_non_throwing_args_copy) {
                this->state->result
                    .template emplace<::std::tuple<::beman::execution::set_error_t, ::std::exception_ptr>>(
                        ::beman::execution::set_error_t{}, ::std::current_exception());
            }
        }
        this->state->complete();
    }
};

template <::beman::execution::sender Sndr, typename Env>
using future_spawned_sender = decltype(::beman::execution::write_env(
    ::beman::execution::detail::stop_when(::std::declval<Sndr>(),
                                          ::std::declval<::beman::execution::inplace_stop_token>()),
    ::std::declval<Env>()));

template <::beman::execution::sender Sndr, typename Env>
using spawn_future_sigs = ::beman::execution::detail::meta::unique<::beman::execution::detail::meta::prepend<
    ::beman::execution::set_stopped_t(),
    ::beman::execution::completion_signatures_of_t<::beman::execution::detail::future_spawned_sender<Sndr, Env>>>>;

template <typename Allocator, ::beman::execution::scope_token Token, ::beman::execution::sender Sndr, typename Env>
struct spawn_future_state
    : ::beman::execution::detail::spawn_future_state_base<::beman::execution::detail::spawn_future_sigs<Sndr, Env>> {
    using alloc_t          = typename ::std::allocator_traits<Allocator>::template rebind_alloc<spawn_future_state>;
    using assoc_t          = ::std::remove_cvref_t<decltype(::std::declval<const Token&>().try_associate())>;
    using traits_t         = ::std::allocator_traits<alloc_t>;
    using spawned_sender_t = ::beman::execution::detail::future_spawned_sender<Sndr, Env>;
    using sigs_t           = ::beman::execution::detail::spawn_future_sigs<Sndr, Env>;
    using receiver_t       = ::beman::execution::detail::spawn_future_receiver<sigs_t>;
    static_assert(::beman::execution::sender<spawned_sender_t>);
    static_assert(::beman::execution::receiver<receiver_t>);
    using op_t = ::beman::execution::connect_result_t<spawned_sender_t, receiver_t>;

    template <::beman::execution::sender S>
    spawn_future_state(auto a, S&& s, const Token& tok, Env env)
        : alloc(::std::move(a)),
          op(::beman::execution::write_env(
                 ::beman::execution::detail::stop_when(::std::forward<S>(s), source.get_token()), env),
             receiver_t{this}),
          assoc(tok.try_associate()) {
        if (this->assoc) {
            ::beman::execution::start(this->op);
        } else {
            ::beman::execution::set_stopped(receiver_t{this});
        }
    }
    auto complete() noexcept -> void override {
        {
            ::std::lock_guard cerberos(this->gate);
            if (this->fun == nullptr) {
                this->receiver = this;
                return;
            }
        }
        this->fun(this->receiver, *this);
    }
    auto abandon() noexcept -> void {
        bool ready{[&] {
            ::std::lock_guard cerberos(this->gate);
            if (this->receiver == nullptr) {
                this->receiver = this;
                this->fun      = [](void*, spawn_future_state& state) noexcept { state.destroy(); };
                return false;
            }
            return true;
        }()};
        if (ready) {
            this->destroy();
        } else {
            this->source.request_stop();
        }
    }
    template <::beman::execution::receiver Rcvr>
    static auto complete_receiver(Rcvr& rcvr, typename spawn_future_state::result_t& res) noexcept {
        std::visit(
            [&rcvr]<typename Tuplish>(Tuplish&& tuplish) noexcept {
                if constexpr (!::std::same_as<::std::remove_cvref_t<decltype(tuplish)>, ::std::monostate>) {
                    ::std::apply(
                        [&rcvr]<typename... Args>(auto cpo, Args&&... args) {
                            cpo(::std::move(rcvr), ::std::forward<Args>(args)...);
                        },
                        ::std::forward<Tuplish>(tuplish));
                }
            },
            ::std::move(res));
    }
    template <::beman::execution::receiver Rcvr>
    auto consume(Rcvr& rcvr) noexcept -> void {
        {
            ::std::lock_guard cerberos(this->gate);
            if (this->receiver == nullptr) {
                this->receiver = &rcvr;
                this->fun      = [](void* ptr, spawn_future_state& state) noexcept {
                    spawn_future_state::complete_receiver(*static_cast<Rcvr*>(ptr), state.result);
                };
                return;
            }
        }
        spawn_future_state::complete_receiver(rcvr, this->result);
    }
    auto destroy() noexcept -> void {
        assoc_t _ = ::std::move(this->assoc);
        alloc_t a{this->alloc};
        traits_t::destroy(a, this);
        traits_t::deallocate(a, this, 1u);
    }

    ::std::mutex                            gate{};
    alloc_t                                 alloc;
    ::beman::execution::inplace_stop_source source{};
    op_t                                    op;
    assoc_t                                 assoc;
    void*                                   receiver{};
    auto (*fun)(void*, spawn_future_state&) noexcept -> void = nullptr;
};

class spawn_future_t {
  public:
    template <::beman::execution::sender Sndr, ::beman::execution::scope_token Tok, typename Ev>
        requires ::beman::execution::detail::queryable<::std::remove_cvref_t<Ev>>
    auto operator()(Sndr&& sndr, const Tok& tok, Ev&& ev) const {
        //-dk:TODO why decltype(auto) instead of auto?
        auto make{[&]() -> decltype(auto) { return tok.wrap(::std::forward<Sndr>(sndr)); }};
        using sndr_t = decltype(make());
        static_assert(::beman::execution::sender<Sndr>);

        auto [alloc, senv] = spawn_get_allocator(sndr, ev);
        using state_t = ::beman::execution::detail::spawn_future_state<decltype(alloc), Tok, sndr_t, decltype(senv)>;
        using state_alloc_t  = typename ::std::allocator_traits<decltype(alloc)>::template rebind_alloc<state_t>;
        using state_traits_t = ::std::allocator_traits<state_alloc_t>;
        state_alloc_t state_alloc(alloc);
        state_t*      op{state_traits_t::allocate(state_alloc, 1u)};
        try {
            state_traits_t::construct(state_alloc, op, alloc, make(), tok, senv);
        } catch (...) {
            state_traits_t::deallocate(state_alloc, op, 1u);
            throw;
        }

        using deleter = decltype([](state_t* p) noexcept { p->abandon(); });
        return ::beman::execution::detail::make_sender(*this, ::std::unique_ptr<state_t, deleter>{op});
    }
    template <::beman::execution::sender Sndr, ::beman::execution::scope_token Tok>
    auto operator()(Sndr&& sndr, const Tok& tok) const {
        return (*this)(::std::forward<Sndr>(sndr), tok, ::beman::execution::env<>{});
    }

  private:
    template <typename, typename>
    struct get_signatures;
    template <typename State, typename Deleter, typename Env>
    struct get_signatures<::beman::execution::detail::basic_sender<::beman::execution::detail::spawn_future_t,
                                                                   ::std::unique_ptr<State, Deleter>>,
                          Env> {
        using type = typename State::sigs_t;
    };

  public:
    template <typename Sender, typename... Env>
    static consteval auto get_completion_signatures() {
        return typename get_signatures<std::remove_cvref_t<Sender>, Env...>::type{};
    }
    struct impls_for : ::beman::execution::detail::default_impls {
        struct start_impl {
            auto operator()(auto& state, auto& rcvr) const noexcept -> void { state->consume(rcvr); }
        };
        static constexpr auto start{start_impl{}};
    };
};

} // namespace beman::execution::detail

namespace beman::execution {
using spawn_future_t = ::beman::execution::detail::spawn_future_t;
inline constexpr spawn_future_t spawn_future{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SPAWN_FUTURE
