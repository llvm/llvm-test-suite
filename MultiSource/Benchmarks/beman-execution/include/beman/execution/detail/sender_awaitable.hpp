// include/beman/execution/detail/sender_awaitable.hpp              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_AWAITABLE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_AWAITABLE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <atomic>
#include <concepts>
#include <coroutine>
#include <exception>
#include <tuple>
#include <type_traits>
#include <utility>
#include <variant>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.as_except_ptr;
import beman.execution.detail.connect;
import beman.execution.detail.connect_result_t;
import beman.execution.detail.env_of_t;
import beman.execution.detail.env_promise;
import beman.execution.detail.fwd_env;
import beman.execution.detail.get_env;
import beman.execution.detail.is_awaitable;
import beman.execution.detail.receiver;
import beman.execution.detail.single_sender;
import beman.execution.detail.single_sender_value_type;
import beman.execution.detail.start;
import beman.execution.detail.unspecified_promise;
#else
#include <beman/execution/detail/as_except_ptr.hpp>
#include <beman/execution/detail/connect.hpp>
#include <beman/execution/detail/connect_result_t.hpp>
#include <beman/execution/detail/env_promise.hpp>
#include <beman/execution/detail/fwd_env.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/is_awaitable.hpp>
#include <beman/execution/detail/single_sender.hpp>
#include <beman/execution/detail/single_sender_value_type.hpp>
#include <beman/execution/detail/start.hpp>
#include <beman/execution/detail/unspecified_promise.hpp>
#endif

namespace beman::execution::detail {
template <class Sndr, class Promise>
class sender_awaitable {
    inline static constexpr bool enable_defence{true};
    struct unit {};
    using value_type =
        ::beman::execution::detail::single_sender_value_type<Sndr, ::beman::execution::env_of_t<Promise>>;
    using result_type  = ::std::conditional_t<::std::is_void_v<value_type>, unit, value_type>;
    using variant_type = ::std::variant<::std::monostate, result_type, ::std::exception_ptr>;
    using data_type    = ::std::tuple<variant_type, ::std::atomic<bool>, ::std::coroutine_handle<Promise>>;

    struct awaitable_receiver {
        using receiver_concept = ::beman::execution::receiver_tag;

        void resume() {
            if (not enable_defence || ::std::get<1>(*result_ptr_).exchange(true, std::memory_order_acq_rel)) {
                ::std::get<2>(*result_ptr_).resume();
            }
        }

        template <class... Args>
            requires ::std::constructible_from<result_type, Args...>
        void set_value(Args&&... args) && noexcept {
            try {
                ::std::get<0>(*result_ptr_).template emplace<1>(::std::forward<Args>(args)...);
            } catch (...) {
                ::std::get<0>(*result_ptr_).template emplace<2>(::std::current_exception());
            }
            this->resume();
        }
        template <class Error>
        void set_error(Error&& error) && noexcept {
            ::std::get<0>(*result_ptr_)
                .template emplace<2>(::beman::execution::detail::as_except_ptr(::std::forward<Error>(error)));
            this->resume();
        }

        void set_stopped() && noexcept {
            if (not enable_defence || ::std::get<1>(*result_ptr_).exchange(true, ::std::memory_order_acq_rel)) {
                static_cast<::std::coroutine_handle<>>(::std::get<2>(*result_ptr_).promise().unhandled_stopped())
                    .resume();
            }
        }

        auto get_env() const noexcept {
            return ::beman::execution::detail::fwd_env{
                ::beman::execution::get_env(::std::get<2>(*result_ptr_).promise())};
        }

        data_type* result_ptr_;
    };
    using op_state_type = ::beman::execution::connect_result_t<Sndr, awaitable_receiver>;

    data_type     result{};
    op_state_type state;

  public:
    sender_awaitable(Sndr&& sndr, Promise& p)
        : result{::std::monostate{}, false, ::std::coroutine_handle<Promise>::from_promise(p)},
          state{::beman::execution::connect(::std::forward<Sndr>(sndr),
                                            sender_awaitable::awaitable_receiver{::std::addressof(result)})} {}

    static constexpr bool     await_ready() noexcept { return false; }
    ::std::coroutine_handle<> await_suspend(::std::coroutine_handle<Promise> handle) noexcept {
        ::beman::execution::start(state);
        if (enable_defence && ::std::get<1>(this->result).exchange(true, std::memory_order_acq_rel)) {
            if (::std::holds_alternative<::std::monostate>(::std::get<0>(this->result))) {
                return ::std::get<2>(this->result).promise().unhandled_stopped();
            }
            return ::std::move(handle);
        }
        return ::std::noop_coroutine();
    }
    value_type await_resume() {
        if (::std::holds_alternative<::std::exception_ptr>(::std::get<0>(result))) {
            ::std::rethrow_exception(::std::get<::std::exception_ptr>(::std::get<0>(result)));
        }
        if constexpr (::std::is_void_v<value_type>) {
            return;
        } else {
            return ::std::get<value_type>(std::move(::std::get<0>(result)));
        }
    }
};
} // namespace beman::execution::detail

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_AWAITABLE
