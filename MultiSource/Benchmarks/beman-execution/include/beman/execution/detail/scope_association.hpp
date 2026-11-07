// include/beman/execution/detail/scope_association.hpp                         -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SCOPE_ASSOCIATION
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SCOPE_ASSOCIATION

#include <concepts>
#include <type_traits>

// ----------------------------------------------------------------------------

namespace beman::execution {
template <typename Assoc>
concept scope_association =
    ::std::movable<Assoc> && ::std::is_nothrow_move_constructible_v<Assoc> &&
    ::std::is_nothrow_move_assignable_v<Assoc> && ::std::default_initializable<Assoc> && requires(const Assoc assoc) {
        { static_cast<bool>(assoc) } noexcept;
        { assoc.try_associate() } -> ::std::same_as<Assoc>;
    };
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SCOPE_ASSOCIATION
