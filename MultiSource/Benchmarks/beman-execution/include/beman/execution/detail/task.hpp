// include/beman/execution/detail/task.hpp                              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_TASK
#define INCLUDED_BEMAN_EXECUTION_DETAIL_TASK

#include <cassert>
#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <coroutine>
#include <exception>
#include <functional>
#include <memory>
#include <system_error>
#include <type_traits>
#include <utility>
#include <variant>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.affine;
import beman.execution.detail.as_awaitable;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.decayed_same_as;
import beman.execution.detail.env;
import beman.execution.detail.env_of_t;
import beman.execution.detail.find_allocator;
import beman.execution.detail.forwarding_query;
import beman.execution.detail.get_allocator;
import beman.execution.detail.get_env;
import beman.execution.detail.get_scheduler;
import beman.execution.detail.get_start_scheduler;
import beman.execution.detail.get_stop_token;
import beman.execution.detail.inline_scheduler;
import beman.execution.detail.inplace_stop_source;
import beman.execution.detail.meta.combine;
import beman.execution.detail.meta.contains;
import beman.execution.detail.meta.index;
import beman.execution.detail.operation_state;
import beman.execution.detail.receiver;
import beman.execution.detail.scheduler;
import beman.execution.detail.sender;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.simple_allocator;
import beman.execution.detail.stoppable_source;
import beman.execution.detail.stoppable_token;
import beman.execution.detail.stop_callback_for_t;
import beman.execution.detail.stop_token_of_t;
import beman.execution.detail.sub_visit;
import beman.execution.detail.task_scheduler;
import beman.execution.detail.type_list;
import beman.execution.detail.with_error;
import beman.execution.detail.unreachable;
#else
#include <beman/execution/detail/affine.hpp>
#include <beman/execution/detail/as_awaitable.hpp>
#include <beman/execution/detail/completion_signatures.hpp>
#include <beman/execution/detail/decayed_same_as.hpp>
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/env_of_t.hpp>
#include <beman/execution/detail/find_allocator.hpp>
#include <beman/execution/detail/forwarding_query.hpp>
#include <beman/execution/detail/get_allocator.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/get_scheduler.hpp>
#include <beman/execution/detail/get_start_scheduler.hpp>
#include <beman/execution/detail/get_stop_token.hpp>
#include <beman/execution/detail/inline_scheduler.hpp>
#include <beman/execution/detail/inplace_stop_source.hpp>
#include <beman/execution/detail/meta_combine.hpp>
#include <beman/execution/detail/meta_contains.hpp>
#include <beman/execution/detail/meta_index.hpp>
#include <beman/execution/detail/operation_state.hpp>
#include <beman/execution/detail/receiver.hpp>
#include <beman/execution/detail/scheduler.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/simple_allocator.hpp>
#include <beman/execution/detail/stoppable_source.hpp>
#include <beman/execution/detail/stoppable_token.hpp>
#include <beman/execution/detail/stop_callback_for_t.hpp>
#include <beman/execution/detail/stop_token_of_t.hpp>
#include <beman/execution/detail/sub_visit.hpp>
#include <beman/execution/detail/task_scheduler.hpp>
#include <beman/execution/detail/type_list.hpp>
#include <beman/execution/detail/with_error.hpp>
#include <beman/execution/detail/unreachable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail::task {
template <typename Promise>
class handle {
  private:
    struct deleter {
        auto operator()(Promise* p) noexcept -> void {
            if (p) {
                ::std::coroutine_handle<Promise>::from_promise(*p).destroy();
            }
        }
    };
    ::std::unique_ptr<Promise, deleter> h;

  public:
    explicit handle(Promise* promise) noexcept : h(promise) {}

    auto reset() noexcept -> void { this->h.reset(); }

    template <typename... A>
    auto start(A&&... a) noexcept {
        return this->h->start(::std::forward<A>(a)...);
    }

    auto release() noexcept -> ::std::coroutine_handle<Promise> {
        return ::std::coroutine_handle<Promise>::from_promise(*this->h.release());
    }

    auto get() const noexcept -> Promise* { return this->h.get(); }

    auto get_env() const noexcept { return ::beman::execution::get_env(*this->h); }
};

template <typename Allocator>
struct allocator_support {
    using allocator_traits = ::std::allocator_traits<Allocator>;

    static auto offset(::std::size_t size) noexcept -> ::std::size_t {
        return (size + alignof(Allocator) - 1u) & ~(alignof(Allocator) - 1u);
    }

    static auto get_allocator(void* ptr, ::std::size_t size) noexcept -> Allocator* {
        ptr = static_cast<::std::byte*>(ptr) + offset(size);
        return ::std::launder(reinterpret_cast<Allocator*>(ptr));
    }

    template <typename... Args>
    auto operator new(std::size_t size, const Args&... args) -> void* {
        if constexpr (::std::same_as<Allocator, ::std::allocator<::std::byte>>) {
            Allocator alloc{};
            return allocator_traits::allocate(alloc, size);
        } else {
            Allocator alloc{::beman::execution::detail::find_allocator<Allocator>(args...)};
            void*     ptr{allocator_traits::allocate(alloc, allocator_support::offset(size) + sizeof(Allocator))};
            try {
                new (allocator_support::get_allocator(ptr, size)) Allocator(alloc);
            } catch (...) {
                allocator_traits::deallocate(
                    alloc, static_cast<::std::byte*>(ptr), allocator_support::offset(size) + sizeof(Allocator));
                throw;
            }
            return ptr;
        }
    }

    auto operator delete(void* ptr, ::std::size_t size) noexcept -> void {
        if constexpr (::std::same_as<Allocator, ::std::allocator<::std::byte>>) {
            Allocator alloc{};
            allocator_traits::deallocate(alloc, static_cast<::std::byte*>(ptr), size);
        } else {
            Allocator* aptr{allocator_support::get_allocator(ptr, size)};
            Allocator  alloc{*aptr};
            aptr->~Allocator();
            allocator_traits::deallocate(
                alloc, static_cast<::std::byte*>(ptr), allocator_support::offset(size) + sizeof(Allocator));
        }
    }

    auto operator delete(void* ptr, ::std::size_t size, const auto&...) noexcept -> void {
        allocator_support::operator delete(ptr, size);
    }
};

template <typename>
struct allocator_of {
    using type = ::std::allocator<::std::byte>;
};
template <typename Context>
    requires requires { typename Context::allocator_type; }
struct allocator_of<Context> {
    using alloc_t = typename Context::allocator_type;
    static_assert(::beman::execution::detail::simple_allocator<alloc_t>,
                  "The type alias allocator_type needs to refer to an allocator");
    using type = ::std::allocator_traits<alloc_t>::template rebind_alloc<::std::byte>;
};
template <typename Context>
using allocator_of_t = typename allocator_of<Context>::type;

template <typename R>
struct value_signature {
    using type = ::beman::execution::set_value_t(R);
};
template <>
struct value_signature<void> {
    using type = ::beman::execution::set_value_t();
};

template <typename R>
using value_signature_t = typename value_signature<R>::type;

template <typename>
struct error_types_of {
    using type = ::beman::execution::completion_signatures<::beman::execution::set_error_t(::std::exception_ptr)>;
};
template <typename Context>
    requires requires { typename Context::error_types; }
struct error_types_of<Context> {
    using type = typename Context::error_types;
};
template <typename Context>
using error_types_of_t = typename error_types_of<Context>::type;

template <typename>
struct has_exception_signature;

template <typename... Sigs>
struct has_exception_signature<::beman::execution::completion_signatures<Sigs...>>
    : ::std::bool_constant<
          ::beman::execution::detail::meta::contains<::beman::execution::set_error_t(::std::exception_ptr), Sigs...>> {
};

template <typename>
struct start_scheduler_of {
    using type = ::beman::execution::task_scheduler;
};
template <typename Context>
    requires requires { typename Context::start_scheduler_type; }
struct start_scheduler_of<Context> {
    using type = typename Context::start_scheduler_type;
    static_assert(::beman::execution::scheduler<type>,
                  "The type alias start_scheduler_type needs to refer to a scheduler");
};
template <typename Context>
using start_scheduler_of_t = typename start_scheduler_of<Context>::type;

template <typename>
struct stop_source_of {
    using type = ::beman::execution::inplace_stop_source;
};
template <typename Context>
    requires requires { typename Context::stop_source_type; }
struct stop_source_of<Context> {
    using type = typename Context::stop_source_type;
    static_assert(::beman::execution::detail::stoppable_source<type>,
                  "The type alias stop_source_type needs to refer to a stoppable-source");
};
template <typename Context>
using stop_source_of_t = typename stop_source_of<Context>::type;

struct void_type {};

template <typename Value, typename Errors>
class result_type;

template <typename Value, typename... Errors>
class result_type<Value, ::beman::execution::completion_signatures<::beman::execution::set_error_t(Errors)...>> {
  private:
    using value_type = ::std::conditional_t<::std::same_as<void, Value>, void_type, Value>;

  public:
    template <typename T>
    auto set_value(T&& value) -> void {
        this->result.template emplace<1uz>(::std::forward<T>(value));
    }

    template <typename E>
    auto set_error(E&& error) -> void {
        static constexpr ::std::size_t index = ::beman::execution::detail::meta::
            index_v<::beman::execution::detail::type_list<::std::remove_cvref_t<Errors>...>, ::std::remove_cvref_t<E>>;
        static_assert(index != static_cast<::std::size_t>(-1),
                      "Error type not supported: 'E' is not among the defined Errors.");
        this->result.template emplace<2uz + index>(::std::forward<E>(error));
    }

    auto no_completion_set() const noexcept -> bool { return this->result.index() == 0uz; }

    template <::beman::execution::receiver Receiver>
    auto result_complete(Receiver rcvr) noexcept -> void {
        switch (this->result.index()) {
        case 0:
            ::beman::execution::set_stopped(::std::move(rcvr));
            break;
        case 1:
            if constexpr (::std::same_as<void_type, value_type>)
                ::beman::execution::set_value(::std::move(rcvr));
            else
                ::beman::execution::set_value(::std::move(rcvr), ::std::move(::std::get<1uz>(this->result)));
            break;
        default:
            if constexpr (0uz < sizeof...(Errors)) {
                ::beman::execution::detail::sub_visit<2uz>(
                    [&rcvr](auto& error) { ::beman::execution::set_error(::std::move(rcvr), ::std::move(error)); },
                    this->result);
            }
            break;
        }
    }
    auto result_resume() {
        switch (this->result.index()) {
        case 0:
            ::beman::execution::detail::unreachable();
            break;
        case 1:
            break;
        default:
            if constexpr (0uz < sizeof...(Errors))
                ::beman::execution::detail::sub_visit<2uz>(
                    []<typename E>(E& error) {
                        if constexpr (::std::same_as<::std::remove_cvref_t<E>, ::std::exception_ptr>) {
                            std::rethrow_exception(::std::move(error));
                        } else if constexpr (::std::same_as<::std::remove_cvref_t<E>, ::std::error_code>) {
                            throw ::std::system_error{::std::move(error)};
                        } else {
                            throw ::std::move(error);
                        }
                    },
                    this->result);
            ::beman::execution::detail::unreachable();
            break;
        }
        if constexpr (::std::same_as<void_type, value_type>) {
            return;
        } else {
            return ::std::move(::std::get<1uz>(this->result));
        }
    }

  private:
    ::std::variant<::std::monostate, value_type, ::std::remove_cvref_t<Errors>...> result;
};
template <typename Value>
class result_type<Value, ::beman::execution::completion_signatures<>> {
  private:
    using value_type = ::std::conditional_t<::std::same_as<void, Value>, void_type, Value>;

    ::std::variant<std::monostate, value_type> result;

  public:
    template <typename T>
    auto set_value(T&& value) -> void {
        this->result.template emplace<1uz>(::std::forward<T>(value));
    }

    auto no_completion_set() const noexcept -> bool { return this->result.index() == 0; }

    template <::beman::execution::receiver Receiver>
    auto result_complete(Receiver rcvr) noexcept -> void {
        switch (this->result.index()) {
        case 0:
            ::beman::execution::set_stopped(::std::move(rcvr));
            break;
        case 1:
            if constexpr (::std::same_as<void_type, value_type>) {
                ::beman::execution::set_value(::std::move(rcvr));
            } else {
                ::beman::execution::set_value(::std::move(rcvr), ::std::move(::std::get<1uz>(this->result)));
            }
            break;
        default:
            ::beman::execution::detail::unreachable();
            break;
        }
    }

    auto result_resume() noexcept {
        if (this->result.index() != 1) [[unlikely]] {
            ::beman::execution::detail::unreachable();
        }
        if constexpr (::std::same_as<void_type, value_type>) {
            return;
        } else {
            return ::std::move(::std::get<1uz>(this->result));
        }
    }
};

template <typename, typename>
struct own_env {
    using type = ::beman::execution::env<>;
};

template <typename Environment, typename RcvrEnv>
    requires requires { typename Environment::template env_type<RcvrEnv>; }
struct own_env<Environment, RcvrEnv> {
    using type = Environment::template env_type<RcvrEnv>;
};

template <typename Environment, typename RcvrEnv>
struct env_holder {
    using own_env_t = typename own_env<Environment, RcvrEnv>::type;

    static auto make_own_env(const RcvrEnv& rcvr_env) noexcept -> own_env_t {
        if constexpr (::std::constructible_from<own_env_t, const RcvrEnv&>) {
            return own_env_t(rcvr_env);
        } else {
            return own_env_t();
        }
    }

    static auto make_environment(const RcvrEnv& rcvr_env, const own_env_t& own_env) noexcept -> Environment {
        if constexpr (::std::constructible_from<Environment, const own_env_t&>) {
            return Environment(own_env);
        } else if constexpr (::std::constructible_from<Environment, const RcvrEnv&>) {
            return Environment(rcvr_env);
        } else {
            return Environment();
        }
    }

    explicit env_holder(const RcvrEnv& rcvr_env) noexcept
        : own_env(env_holder::make_own_env(rcvr_env)), environment(env_holder::make_environment(rcvr_env, own_env)) {}

    own_env_t   own_env;
    Environment environment;
};

template <typename StopSource, typename StopToken>
class propagator {
  public:
    template <typename... Args>
        requires ::std::constructible_from<StopSource, Args...>
    explicit propagator(StopToken stop_token, Args&&... args)
        : stop_source_(::std::forward<Args>(args)...),
          stop_callback_(::std::move(stop_token), ::std::bind_front(&propagator::propagate, this)) {}

    auto get_token() const noexcept { return stop_source_.get_token(); }

  private:
    auto propagate() -> void { stop_source_.request_stop(); }

  private:
    using stop_cb_t = decltype(::std::bind_front(&propagator::propagate, ::std::declval<propagator*>()));

    StopSource                                                    stop_source_;
    ::beman::execution::stop_callback_for_t<StopToken, stop_cb_t> stop_callback_;
};

template <typename StopSource, typename StopToken>
    requires ::std::same_as<::std::decay_t<decltype(::std::declval<StopSource>().get_token())>, StopToken>
class propagator<StopSource, StopToken> {
  public:
    explicit propagator(StopToken stop_token) noexcept : stop_token_(::std::move(stop_token)) {}

    auto get_token() const noexcept -> StopToken { return stop_token_; }

  private:
    StopToken stop_token_;
};

template <typename Sched, typename Env, typename Alloc>
auto make_sched(const Env& env, const Alloc& alloc) noexcept -> Sched {
    if constexpr (requires {
                      ::std::make_obj_using_allocator<Sched>(alloc, ::beman::execution::get_start_scheduler(env));
                  }) {
        return ::std::make_obj_using_allocator<Sched>(alloc, ::beman::execution::get_start_scheduler(env));
    } else if constexpr (requires {
                             ::std::make_obj_using_allocator<Sched>(alloc, ::beman::execution::get_scheduler(env));
                         }) {
        return ::std::make_obj_using_allocator<Sched>(alloc, ::beman::execution::get_scheduler(env));
    } else if constexpr (std::default_initializable<Sched>) {
        return Sched();
    } else {
        static_assert(false,
                      "`Env` should provide `get_start_scheduler` or `get_scheduler`; otherwise, `Sched` should be "
                      "default-initializable.");
        ::beman::execution::detail::unreachable();
    }
}

template <typename Value, typename Environment>
// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
class state_base : public result_type<Value, error_types_of_t<Environment>> {
  public:
    using allocator_type   = allocator_of_t<Environment>;
    using stop_source_type = stop_source_of_t<Environment>;
    using stop_token_type  = decltype(::std::declval<stop_source_type>().get_token());
    using scheduler_type   = start_scheduler_of_t<Environment>;

    state_base() = default;

    state_base(const state_base&) = delete;

    state_base(state_base&&) = delete;

    ~state_base() = default;

    auto operator=(const state_base&) -> state_base& = delete;

    auto operator=(state_base&&) -> state_base& = delete;

    auto complete() noexcept -> std::coroutine_handle<> { return this->do_complete(); }
    auto get_allocator() noexcept -> allocator_type { return this->do_get_allocator(); }
    auto get_stop_token() noexcept -> stop_token_type { return this->do_get_stop_token(); }
    auto get_environment() noexcept -> Environment& { return this->do_get_environment(); }
    auto get_start_scheduler() noexcept -> scheduler_type { return this->do_get_start_scheduler(); }

  private:
    virtual auto do_complete() noexcept -> ::std::coroutine_handle<> = 0;
    virtual auto do_get_allocator() noexcept -> allocator_type       = 0;
    virtual auto do_get_stop_token() noexcept -> stop_token_type     = 0;
    virtual auto do_get_environment() noexcept -> Environment&       = 0;
    virtual auto do_get_start_scheduler() noexcept -> scheduler_type = 0;
};

template <typename Value, typename Environment, typename OwnPromise, typename Receiver>
// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct state : state_base<Value, Environment> {
    using operation_state_concept = ::beman::execution::operation_state_tag;
    using scheduler_type          = typename state_base<Value, Environment>::scheduler_type;
    using allocator_type          = typename state_base<Value, Environment>::allocator_type;
    using stop_source_type        = typename state_base<Value, Environment>::stop_source_type;
    using stop_token_type         = typename state_base<Value, Environment>::stop_token_type;
    using upstream_stop_token_t   = ::beman::execution::stop_token_of_t<::beman::execution::env_of_t<Receiver>>;

    template <typename H, typename Env>
    state(Receiver r, H h, const Env& env) noexcept
        : rcvr(::std::move(r)),
          handle(std::move(h)),
          holder(env),
          scheduler(::beman::execution::detail::task::make_sched<scheduler_type>(env, do_get_allocator())),
          propagator(::beman::execution::get_stop_token(env)) {}

    auto start() & noexcept -> void { this->handle.start(this).resume(); }

  private:
    auto do_complete() noexcept -> ::std::coroutine_handle<> final {
        this->handle.reset();
        this->result_complete(::std::move(this->rcvr));
        return ::std::noop_coroutine();
    }

    auto do_get_allocator() noexcept -> allocator_type final {
        if constexpr (requires {
                          allocator_type(::beman::execution::get_allocator(::beman::execution::get_env(this->rcvr)));
                      }) {
            return allocator_type(::beman::execution::get_allocator(::beman::execution::get_env(this->rcvr)));
        } else {
            return allocator_type();
        }
    }

    auto do_get_start_scheduler() noexcept -> scheduler_type final { return this->scheduler; }

    auto do_get_stop_token() noexcept -> stop_token_type final { return this->propagator.get_token(); }

    auto do_get_environment() noexcept -> Environment& final { return this->holder.environment; }

    Receiver                                                                              rcvr;
    ::beman::execution::detail::task::handle<OwnPromise>                                  handle;
    env_holder<Environment, ::beman::execution::env_of_t<Receiver>>                       holder;
    scheduler_type                                                                        scheduler;
    ::beman::execution::detail::task::propagator<stop_source_type, upstream_stop_token_t> propagator;
};

template <typename Value, typename Environment, typename OwnPromise, typename ParentPromise>
// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
class awaiter : public state_base<Value, Environment> {
  public:
    using allocator_type        = typename state_base<Value, Environment>::allocator_type;
    using scheduler_type        = typename state_base<Value, Environment>::scheduler_type;
    using stop_source_type      = typename state_base<Value, Environment>::stop_source_type;
    using stop_token_type       = typename state_base<Value, Environment>::stop_token_type;
    using upstream_stop_token_t = ::beman::execution::stop_token_of_t<::beman::execution::env_of_t<ParentPromise>>;

    explicit awaiter(::std::coroutine_handle<ParentPromise> parent, handle<OwnPromise> h, const auto& env) noexcept
        : parent(parent),
          handle(std::move(h)),
          holder(env),
          scheduler(::beman::execution::detail::task::make_sched<scheduler_type>(env, do_get_allocator())),
          propagator(::beman::execution::get_stop_token(env)) {}

    static constexpr auto await_ready() noexcept -> bool { return false; }

    auto await_suspend([[maybe_unused]] ::std::coroutine_handle<ParentPromise> p) noexcept
        -> ::std::coroutine_handle<> {
        assert(p == this->parent);
        return this->handle.start(this);
    }

    auto await_resume() -> Value { return this->result_resume(); }

  private:
    auto do_complete() noexcept -> std::coroutine_handle<> final {
        if (this->no_completion_set()) {
            return this->parent.promise().unhandled_stopped();
        }
        return this->parent;
    }

    auto do_get_allocator() noexcept -> allocator_type final {
        if constexpr (requires {
                          ::beman::execution::get_allocator(::beman::execution::get_env(this->parent.promise()));
                      }) {
            return ::beman::execution::get_allocator(::beman::execution::get_env(this->parent.promise()));
        } else {
            return allocator_type();
        }
    }

    auto do_get_start_scheduler() noexcept -> scheduler_type final { return this->scheduler; }

    auto do_get_stop_token() noexcept -> stop_token_type final { return this->propagator.get_token(); }

    auto do_get_environment() noexcept -> Environment& final { return this->holder.environment; }

    ::std::coroutine_handle<ParentPromise>                                                parent;
    ::beman::execution::detail::task::handle<OwnPromise>                                  handle;
    env_holder<Environment, ::beman::execution::env_of_t<ParentPromise>>                  holder;
    scheduler_type                                                                        scheduler;
    ::beman::execution::detail::task::propagator<stop_source_type, upstream_stop_token_t> propagator;
};

template <typename Promise>
struct promise_env {
    auto query(const ::beman::execution::get_scheduler_t&) const noexcept -> typename Promise::scheduler_type {
        return this->promise->get_start_scheduler();
    }

    auto query(const ::beman::execution::get_start_scheduler_t&) const noexcept -> typename Promise::scheduler_type {
        return this->promise->get_start_scheduler();
    }

    auto query(const ::beman::execution::get_allocator_t&) const noexcept -> typename Promise::allocator_type {
        return this->promise->get_allocator();
    }

    auto query(const ::beman::execution::get_stop_token_t&) const noexcept -> typename Promise::stop_token_type {
        return this->promise->get_stop_token();
    }

    template <typename Q, typename... Args>
        requires(::beman::execution::forwarding_query(Q())) && requires(const Promise* p, Q q, Args&&... args) {
            q(p->get_environment(), ::std::forward<Args>(args)...);
        }
    auto query(Q q, Args&&... args) const noexcept {
        return q(this->promise->get_environment(), ::std::forward<Args>(args)...);
    }

    const Promise* promise;
};

struct final_awaiter {
    static constexpr auto await_ready() noexcept -> bool { return false; }

    template <typename Promise>
    static auto await_suspend(::std::coroutine_handle<Promise> handle) noexcept {
        return handle.promise().notify_complete();
    }

    static constexpr auto await_resume() noexcept -> void {}
};

template <typename Value, typename Environment>
class promise_base {
  public:
    template <typename T = Value>
    auto return_value(T&& value) -> void {
        this->get_state()->set_value(::std::forward<T>(value));
    }

  public:
    auto set_state(state_base<Value, Environment>* s) noexcept -> void { this->state_ = s; }
    auto get_state() const noexcept -> state_base<Value, Environment>* { return this->state_; }

  private:
    state_base<Value, Environment>* state_{};
};

template <typename Environment>
class promise_base<void, Environment> {
  public:
    auto return_void() -> void { this->get_state()->set_value(void_type{}); }

  public:
    auto set_state(state_base<void, Environment>* s) noexcept -> void { this->state_ = s; }

    auto get_state() const noexcept -> state_base<void, Environment>* { return this->state_; }

  private:
    state_base<void, Environment>* state_{};
};

template <typename Coroutine, typename Value, typename Environment>
class promise_type : public ::beman::execution::detail::task::promise_base<::std::remove_cvref_t<Value>, Environment>,
                     public ::beman::execution::detail::task::allocator_support<
                         ::beman::execution::detail::task::allocator_of_t<Environment>> {
  public:
    using allocator_type   = allocator_of_t<Environment>;
    using scheduler_type   = start_scheduler_of_t<Environment>;
    using stop_source_type = stop_source_of_t<Environment>;
    using stop_token_type  = decltype(::std::declval<stop_source_type>().get_token());

    static auto initial_suspend() noexcept -> ::std::suspend_always { return {}; }

    static auto final_suspend() noexcept -> ::beman::execution::detail::task::final_awaiter { return {}; }

    auto unhandled_exception() noexcept -> void {
        using error_types = error_types_of_t<Environment>;
        if constexpr (::beman::execution::detail::task::has_exception_signature<error_types>::value) {
            this->get_state()->set_error(::std::current_exception());
        } else {
            ::std::terminate();
        }
    }

    auto unhandled_stopped() -> std::coroutine_handle<> { return this->get_state()->complete(); }

    auto get_return_object() noexcept {
        return Coroutine(::beman::execution::detail::task::handle<promise_type>(this));
    }

    template <::beman::execution::sender Expr>
    auto await_transform(Expr&& expr) -> decltype(auto) {
        if constexpr (::std::same_as<scheduler_type, ::beman::execution::inline_scheduler>) {
            return ::beman::execution::as_awaitable(::std::forward<Expr>(expr), *this);
        } else {
            return ::beman::execution::as_awaitable(::beman::execution::affine(::std::forward<Expr>(expr)), *this);
        }
    }

    template <typename E>
    auto yield_value(::beman::execution::with_error<E> with) noexcept
        -> ::beman::execution::detail::task::final_awaiter {
        this->get_state()->set_error(::std::move(with.error));
        return {};
    }

    auto get_env() const noexcept -> ::beman::execution::detail::task::promise_env<promise_type> { return {this}; }

    auto start(::beman::execution::detail::task::state_base<Value, Environment>* state) -> ::std::coroutine_handle<> {
        this->set_state(state);
        return ::std::coroutine_handle<promise_type>::from_promise(*this);
    }

    auto notify_complete() noexcept -> ::std::coroutine_handle<> { return this->get_state()->complete(); }

    auto get_start_scheduler() const noexcept -> scheduler_type { return this->get_state()->get_start_scheduler(); }

    auto get_allocator() const noexcept -> allocator_type { return this->get_state()->get_allocator(); }

    auto get_stop_token() const noexcept -> stop_token_type { return this->get_state()->get_stop_token(); }

    auto get_environment() const noexcept -> const Environment& { return this->get_state()->get_environment(); }
};

} // namespace beman::execution::detail::task

namespace beman::execution {
template <typename Value = void, typename Environment = ::beman::execution::env<>>
class task {
    friend ::beman::execution::detail::task::promise_type<task, Value, Environment>;

  public:
    using sender_concept       = ::beman::execution::sender_tag;
    using promise_type         = ::beman::execution::detail::task::promise_type<task, Value, Environment>;
    using allocator_type       = ::beman::execution::detail::task::allocator_of_t<Environment>;
    using start_scheduler_type = ::beman::execution::detail::task::start_scheduler_of_t<Environment>;
    using stop_source_type     = ::beman::execution::detail::task::stop_source_of_t<Environment>;
    using stop_token_type      = decltype(::std::declval<stop_source_type>().get_token());
    using error_types          = ::beman::execution::detail::task::error_types_of_t<Environment>;

  private:
    template <typename Receiver>
    using state = ::beman::execution::detail::task::state<Value, Environment, promise_type, Receiver>;

    template <typename ParentPromise>
    using awaiter = ::beman::execution::detail::task::awaiter<Value, Environment, promise_type, ParentPromise>;

    using signatures = ::beman::execution::detail::meta::combine<
        ::beman::execution::completion_signatures<::beman::execution::detail::task::value_signature_t<Value>,
                                                  ::beman::execution::set_stopped_t()>,
        error_types>;

  public:
    task(const task&) = delete;

    task(task&&) noexcept = default;

    task& operator=(const task&) = delete;

    task& operator=(task&&) noexcept = default;

    ~task() = default;

    template <::beman::execution::detail::decayed_same_as<task>, typename...>
    static consteval auto get_completion_signatures() noexcept -> signatures {
        return {};
    }

    template <::beman::execution::receiver Receiver>
    auto connect(Receiver receiver) && noexcept -> state<Receiver> {
        auto env = ::beman::execution::get_env(receiver);
        return state<Receiver>(::std::move(receiver), ::std::move(this->handle), env);
    }

    template <typename ParentPromise>
    auto as_awaitable(ParentPromise& parent) && noexcept -> awaiter<ParentPromise> {
        auto env = ::beman::execution::get_env(parent);
        return awaiter<ParentPromise>(parent, ::std::move(this->handle), env);
    }

  private:
    explicit task(::beman::execution::detail::task::handle<promise_type> h) noexcept : handle(::std::move(h)) {}

    ::beman::execution::detail::task::handle<promise_type> handle;
};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_TASK
