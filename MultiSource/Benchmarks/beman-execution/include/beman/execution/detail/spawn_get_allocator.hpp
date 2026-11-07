// include/beman/execution/detail/spawn_get_allocator.hpp             -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SPAWN_GET_ALLOCATOR
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SPAWN_GET_ALLOCATOR

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <memory>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.get_allocator;
import beman.execution.detail.get_env;
import beman.execution.detail.join_env;
import beman.execution.detail.prop;
import beman.execution.detail.sender;
#else
#include <beman/execution/detail/get_allocator.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/join_env.hpp>
#include <beman/execution/detail/prop.hpp>
#include <beman/execution/detail/sender.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <::beman::execution::sender Sndr, typename Ev>
auto spawn_get_allocator(const Sndr& sndr, const Ev& ev) {
    if constexpr (requires { ::beman::execution::get_allocator(ev); }) {
        return ::std::pair(::beman::execution::get_allocator(ev), ev);
    } else if constexpr (requires { ::beman::execution::get_allocator(::beman::execution::get_env(sndr)); }) {
        auto alloc{::beman::execution::get_allocator(::beman::execution::get_env(sndr))};
        return ::std::pair(alloc,
                           ::beman::execution::detail::join_env(
                               ::beman::execution::prop(::beman::execution::get_allocator, alloc), ev));
    } else {
        return ::std::pair(::std::allocator<void>{}, ev);
    }
}

} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SPAWN_GET_ALLOCATOR
