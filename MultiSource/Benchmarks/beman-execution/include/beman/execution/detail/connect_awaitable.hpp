// include/beman/execution/detail/connect_awaitable.hpp             -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_CONNECT_AWAITABLE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_CONNECT_AWAITABLE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <coroutine>
#include <exception>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.await_result_type;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.operation_state_task;
import beman.execution.detail.receiver;
import beman.execution.detail.receiver_of;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.suspend_complete;
#else
#include <beman/execution/detail/await_result_type.hpp>
#include <beman/execution/detail/completion_signatures.hpp>
#include <beman/execution/detail/operation_state_task.hpp>
#include <beman/execution/detail/receiver.hpp>
#include <beman/execution/detail/receiver_of.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/suspend_complete.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
/*!
 * \brief A helper template used determine the completion signature for type T which may be void
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <typename T>
struct awaiter_set_value {
    using type = ::beman::execution::set_value_t(T);
};
/*!
 * \brief Specialization for awaiter_set_value when the type is void
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <>
struct awaiter_set_value<void> {
    using type = ::beman::execution::set_value_t();
};

/*!
 * \brief A helper template used to determine the completion signature matching an awaiter
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <typename Awaiter, typename Receiver>
using awaiter_completion_signatures = ::beman::execution::completion_signatures<
    typename ::beman::execution::detail::awaiter_set_value<::beman::execution::detail::await_result_type<
        Awaiter,
        ::beman::execution::detail::connect_awaitable_promise<Receiver>>>::type,
    ::beman::execution::set_error_t(::std::exception_ptr),
    ::beman::execution::set_stopped_t()>;

/*!
 * \brief A helper function used to connect an awaiter to a receiver
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <typename Awaiter, ::beman::execution::receiver Receiver>
auto connect_awaitable(Awaiter awaiter, Receiver receiver)
    -> ::beman::execution::detail::operation_state_task<Receiver>
    requires ::beman::execution::
        receiver_of<Receiver, ::beman::execution::detail::awaiter_completion_signatures<Awaiter, Receiver>>
{
    // NOTE: suspened_complete(...) is co_await to make sure that the
    //    coroutine is suspended at the point when set_*(...) is called.
    using result_type =
        ::beman::execution::detail::await_result_type<Awaiter,
                                                      ::beman::execution::detail::connect_awaitable_promise<Receiver>>;

    ::std::exception_ptr ep;
    try {
        if constexpr (std::same_as<void, result_type>) {
            co_await ::std::move(awaiter);
            co_await ::beman::execution::detail::suspend_complete(::beman::execution::set_value,
                                                                  ::std::move(receiver));
        } else {
            co_await ::beman::execution::detail::suspend_complete(
                ::beman::execution::set_value, ::std::move(receiver), co_await ::std::move(awaiter));
        }
    } catch (...) {
        ep = ::std::current_exception();
    }
    co_await ::beman::execution::detail::suspend_complete(::beman::execution::set_error, ::std::move(receiver), ep);
}
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_CONNECT_AWAITABLE
