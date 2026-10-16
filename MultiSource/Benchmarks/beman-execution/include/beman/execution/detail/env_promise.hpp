// include/beman/execution/detail/env_promise.hpp                   -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_ENV_PROMISE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_ENV_PROMISE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <coroutine>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.with_await_transform;
#else
#include <beman/execution/detail/with_await_transform.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
/*!
 * \brief A helper promise type with an associated environment
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <typename Env> //-dk:TODO detail export
struct env_promise : ::beman::execution::detail::with_await_transform<Env> {
    auto get_return_object() noexcept -> void;
    auto initial_suspend() noexcept -> ::std::suspend_always;
    auto final_suspend() noexcept -> ::std::suspend_always;
    auto unhandled_exception() noexcept -> void;
    auto return_void() noexcept -> void;
    auto unhandled_stopped() noexcept -> ::std::coroutine_handle<>;
    auto get_env() const noexcept -> const Env&;
};
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_ENV_PROMISE
