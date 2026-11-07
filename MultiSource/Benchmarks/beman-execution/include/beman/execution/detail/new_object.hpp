// include/beman/execution/detail/new_object.hpp                      -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_NEW_OBJECT
#define INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_NEW_OBJECT

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <memory>
#include <utility>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename T, typename Allocator, typename... Args>
[[nodiscard]] auto new_object(const Allocator& allocator, Args&&... args) -> T* {
    using alloc_t      = typename ::std::allocator_traits<Allocator>::template rebind_alloc<T>;
    using alloc_traits = ::std::allocator_traits<alloc_t>;
    alloc_t alloc(allocator);
    auto    ptr = alloc_traits::allocate(alloc, 1);
    try {
        alloc_traits::construct(alloc, ptr, ::std::forward<Args>(args)...);
        return ptr;
    } catch (...) {
        alloc_traits::deallocate(alloc, ptr, 1);
        throw;
    }
}

template <typename Allocator, typename T>
auto delete_object(const Allocator& allocator, T* ptr) noexcept -> void {
    using alloc_t      = typename ::std::allocator_traits<Allocator>::template rebind_alloc<T>;
    using alloc_traits = ::std::allocator_traits<alloc_t>;
    alloc_t alloc(allocator);
    alloc_traits::destroy(alloc, ptr);
    alloc_traits::deallocate(alloc, ptr, 1);
}
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_NEW_OBJECT
