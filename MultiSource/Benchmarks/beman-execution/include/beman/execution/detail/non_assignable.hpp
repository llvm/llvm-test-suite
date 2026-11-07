// include/beman/execution/detail/non_assignable.hpp                  -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_NON_ASSIGNABLE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_NON_ASSIGNABLE

#include <beman/execution/detail/common.hpp>

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct non_assignable;
}

// ----------------------------------------------------------------------------

struct beman::execution::detail::non_assignable {
    non_assignable()                                         = default;
    non_assignable(non_assignable&&)                         = default;
    non_assignable(const non_assignable&)                    = default;
    auto operator=(non_assignable&&) -> non_assignable&      = delete;
    auto operator=(const non_assignable&) -> non_assignable& = delete;
};

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_NON_ASSIGNABLE
