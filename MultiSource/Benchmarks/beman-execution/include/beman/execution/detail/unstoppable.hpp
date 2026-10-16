// include/beman/execution/detail/unstoppable.hpp                     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_UNSTOPPABLE
#define INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_UNSTOPPABLE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.get_stop_token;
import beman.execution.detail.never_stop_token;
import beman.execution.detail.prop;
import beman.execution.detail.sender;
import beman.execution.detail.write_env;
#else
#include <beman/execution/detail/get_stop_token.hpp>
#include <beman/execution/detail/never_stop_token.hpp>
#include <beman/execution/detail/prop.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/write_env.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct unstoppable_t {
    template <::beman::execution::sender Sndr>
    auto operator()(Sndr&& sndr) const {
        return ::beman::execution::write_env(
            ::std::forward<Sndr>(sndr),
            ::beman::execution::prop{::beman::execution::get_stop_token, ::beman::execution::never_stop_token{}, {}});
    }
};
} // namespace beman::execution::detail

namespace beman::execution {
using unstoppable_t = ::beman::execution::detail::unstoppable_t;
inline constexpr ::beman::execution::unstoppable_t unstoppable{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif
