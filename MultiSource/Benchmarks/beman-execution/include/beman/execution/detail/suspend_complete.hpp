// include/beman/execution/detail/suspend_complete.hpp              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SUSPEND_COMPLETE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SUSPEND_COMPLETE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <coroutine>
#include <exception>
#include <utility>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Fun, typename... Args>
auto suspend_complete(Fun fun, Args&&... args) noexcept {
    auto f{[&, fun]() noexcept { fun(::std::forward<Args>(args)...); }};
    struct awaiter {
        decltype(f) fun;

        static constexpr auto await_ready() noexcept -> bool { return false; }
        auto                  await_suspend(::std::coroutine_handle<>) noexcept { this->fun(); }
#if __cpp_lib_unreachable < 202202L
        [[noreturn]] auto await_resume() noexcept -> void { ::std::terminate(); }
#else
        [[noreturn]] auto await_resume() noexcept -> void { ::std::unreachable(); }
#endif
    };
    return awaiter{f};
}
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SUSPEND_COMPLETE
