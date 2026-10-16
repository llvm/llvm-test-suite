// include/beman/execution/detail/simple_allocator.hpp              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SIMPLE_ALLOCATOR
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SIMPLE_ALLOCATOR

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <cstddef>
#include <type_traits>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Alloc>
concept simple_allocator =
    requires(::std::remove_cvref_t<Alloc> alloc, ::std::size_t n) {
        { *alloc.allocate(n) } -> ::std::same_as<typename ::std::remove_cvref_t<Alloc>::value_type&>;
        alloc.deallocate(alloc.allocate(n), n);
    } && ::std::copy_constructible<::std::remove_cvref_t<Alloc>> &&
    ::std::equality_comparable<::std::remove_cvref_t<Alloc>>;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SIMPLE_ALLOCATOR
