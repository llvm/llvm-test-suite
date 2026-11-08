// include/beman/execution/detail/unspecified_promise.hpp           -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_UNSPECIFIED_PROMISE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_UNSPECIFIED_PROMISE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <coroutine>
#endif

namespace beman::execution::detail {
struct unspecified_promise {
    auto get_return_object() noexcept -> unspecified_promise;
    auto initial_suspend() noexcept -> ::std::suspend_never;
    auto final_suspend() noexcept -> ::std::suspend_never;
    void unhandled_exception() noexcept;
    void return_void() noexcept;
    auto unhandled_stopped() noexcept -> ::std::coroutine_handle<>;
};
} // namespace beman::execution::detail

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_UNSPECIFIED_PROMISE
