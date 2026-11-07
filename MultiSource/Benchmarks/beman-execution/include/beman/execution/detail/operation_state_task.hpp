// include/beman/execution/detail/operation_state_task.hpp     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_OPERATION_STATE_TASK
#define INCLUDED_BEMAN_EXECUTION_DETAIL_OPERATION_STATE_TASK

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <coroutine>
#include <exception>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.env_of_t;
import beman.execution.detail.get_env;
import beman.execution.detail.operation_state;
import beman.execution.detail.set_stopped;
import beman.execution.detail.with_await_transform;
#else
#include <beman/execution/detail/env_of_t.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/operation_state.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/with_await_transform.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Receiver>
struct operation_state_task;

template <typename Receiver>
struct connect_awaitable_promise;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

template <typename Receiver>
struct beman::execution::detail::connect_awaitable_promise
    : ::beman::execution::detail::with_await_transform<connect_awaitable_promise<Receiver>> {
    connect_awaitable_promise(auto&&, Receiver& rcvr) noexcept : receiver(rcvr) {}
    auto              initial_suspend() noexcept -> ::std::suspend_always { return {}; }
    [[noreturn]] auto final_suspend() noexcept -> ::std::suspend_always { ::std::terminate(); }
    [[noreturn]] auto unhandled_exception() noexcept -> void { ::std::terminate(); }
    [[noreturn]] auto return_void() noexcept -> void { ::std::terminate(); }

    auto unhandled_stopped() noexcept -> ::std::coroutine_handle<> {
        ::beman::execution::set_stopped(::std::move(this->receiver));
        return ::std::noop_coroutine();
    }

    auto get_env() const noexcept -> ::beman::execution::env_of_t<Receiver> {
        return ::beman::execution::get_env(this->receiver);
    }

    auto get_return_object() noexcept -> ::beman::execution::detail::operation_state_task<Receiver>;

  private:
    Receiver& receiver;
};

// ----------------------------------------------------------------------------

template <typename Receiver>
struct beman::execution::detail::operation_state_task {
    using operation_state_concept = ::beman::execution::operation_state_tag;
    using promise_type            = ::beman::execution::detail::connect_awaitable_promise<Receiver>;

    explicit operation_state_task(::std::coroutine_handle<> hndl) noexcept : handle(hndl) {}
    operation_state_task(const operation_state_task&)  = delete;
    operation_state_task(operation_state_task&& other) = delete;
    ~operation_state_task() {
        if (this->handle)
            this->handle.destroy();
    }
    auto operator=(operation_state_task&&) -> operation_state_task&      = delete;
    auto operator=(const operation_state_task&) -> operation_state_task& = delete;

    auto start() & noexcept -> void { this->handle.resume(); }

    ::std::coroutine_handle<> handle;
};

// ----------------------------------------------------------------------------

template <typename Receiver>
auto beman::execution::detail::connect_awaitable_promise<Receiver>::get_return_object() noexcept
    -> ::beman::execution::detail::operation_state_task<Receiver> {
    return ::beman::execution::detail::operation_state_task<Receiver>(
        std::coroutine_handle<connect_awaitable_promise>::from_promise(*this));
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_OPERATION_STATE_TASK
