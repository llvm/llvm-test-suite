// include/beman/execution/detail/is_constant.hpp                     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_IS_CONSTANT
#define INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_IS_CONSTANT

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <auto>
auto verify_constexpr() noexcept -> void {}

template <auto Constexpr>
concept is_constant = requires { beman::execution::detail::verify_constexpr<Constexpr>(); };
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif
