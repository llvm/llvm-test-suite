// include/beman/execution/detail/find_allocator.hpp                       -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_FIND_ALLOCATOR
#define INCLUDED_BEMAN_EXECUTION_DETAIL_FIND_ALLOCATOR

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <memory>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Allocator>
Allocator find_allocator() noexcept {
    return Allocator();
}
template <typename Allocator>
Allocator find_allocator(const ::std::allocator_arg_t&) noexcept {
    static_assert(
        requires {
            { Allocator() } -> ::std::same_as<void>;
        }, "There needs to be an allocator argument following std::allocator_arg");
    return Allocator();
}

template <typename Allocator, typename Alloc, typename... A>
Allocator find_allocator(const ::std::allocator_arg_t&, const Alloc& alloc, const A&...) noexcept {
    static_assert(
        requires(const Alloc& a) { Allocator(a); },
        "The allocator needs to be constructible from the argument following std::allocator");
    return Allocator(alloc);
}
template <typename Allocator, typename A0, typename... A>
Allocator find_allocator(A0 const&, const A&... a) noexcept {
    return ::beman::execution::detail::find_allocator<Allocator>(a...);
}

} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif
