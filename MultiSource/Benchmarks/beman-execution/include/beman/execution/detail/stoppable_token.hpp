// include/beman/execution/detail/stoppable_token.hpp               -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_STOPPABLE_TOKEN
#define INCLUDED_BEMAN_EXECUTION_DETAIL_STOPPABLE_TOKEN

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.check_type_alias_exist;
import beman.execution.detail.stoppable_token_traits;
#else
#include <beman/execution/detail/check_type_alias_exist.hpp>
#include <beman/execution/detail/stoppable_token_traits.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
template <typename Token>
concept stoppable_token = requires(const Token& token) {
    typename ::beman::execution::detail::check_type_alias_exist<
        ::beman::execution::detail::stoppable_token_traits<Token>::template callback_type>;
    { token.stop_requested() } noexcept -> ::std::same_as<bool>;
    { token.stop_possible() } noexcept -> ::std::same_as<bool>;
    { Token(token) } noexcept;
} && ::std::copyable<Token> && ::std::equality_comparable<Token> && ::std::swappable<Token>;
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_STOPPABLE_TOKEN
