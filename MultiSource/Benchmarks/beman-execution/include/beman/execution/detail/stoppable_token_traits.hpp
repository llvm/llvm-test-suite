// include/beman/execution/detail/stoppable_token_traits.hpp               -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_STOPPABLE_TOKEN_TRAITS
#define INCLUDED_BEMAN_EXECUTION_DETAIL_STOPPABLE_TOKEN_TRAITS

#include <version>
#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#ifdef __cpp_lib_jthread
#include <stop_token>
#endif
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.check_type_alias_exist;
#else
#include <beman/execution/detail/check_type_alias_exist.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename>
struct stoppable_token_traits;

template <typename Token>
    requires requires { typename check_type_alias_exist<Token::template callback_type>; }
struct stoppable_token_traits<Token> {
    template <typename Fn>
    using callback_type = typename Token::template callback_type<Fn>;
};

#ifdef __cpp_lib_jthread
template <>
struct stoppable_token_traits<::std::stop_token> {
    template <typename Fn>
    using callback_type = ::std::stop_callback<Fn>;
};
#endif
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_STOPPABLE_TOKEN_TRAITS
