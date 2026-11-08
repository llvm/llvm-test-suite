// include/beman/execution/detail/immovable.hpp                     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_IMMOVABLE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_IMMOVABLE

#include <beman/execution/detail/common.hpp>

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct immovable;
struct virtual_immovable;
} // namespace beman::execution::detail

struct beman::execution::detail::immovable {
    constexpr immovable()                          = default;
    immovable(immovable&&)                         = delete;
    immovable(const immovable&)                    = delete;
    ~immovable()                                   = default;
    auto operator=(immovable&&) -> immovable&      = delete;
    auto operator=(const immovable&) -> immovable& = delete;
};

struct beman::execution::detail::virtual_immovable {
    constexpr virtual_immovable()                                  = default;
    virtual_immovable(virtual_immovable&&)                         = delete;
    virtual_immovable(const virtual_immovable&)                    = delete;
    virtual ~virtual_immovable()                                   = default;
    auto operator=(virtual_immovable&&) -> virtual_immovable&      = delete;
    auto operator=(const virtual_immovable&) -> virtual_immovable& = delete;
};

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_IMMOVABLE
