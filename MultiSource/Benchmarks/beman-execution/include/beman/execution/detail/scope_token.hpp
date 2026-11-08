// include/beman/execution/detail/scope_token.hpp                     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SCOPE_TOKEN
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SCOPE_TOKEN

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.completion_signatures;
import beman.execution.detail.get_completion_signatures;
import beman.execution.detail.scope_association;
import beman.execution.detail.sender;
import beman.execution.detail.sender_in;
#else
#include <beman/execution/detail/get_completion_signatures.hpp>
#include <beman/execution/detail/scope_association.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/sender_in.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct token_test_env {};

struct token_test_sender {
    using sender_concept = ::beman::execution::sender_tag;
    template <typename, typename...>
    static consteval auto get_completion_signatures() noexcept {
        return ::beman::execution::completion_signatures<>{};
    }
};
static_assert(::beman::execution::sender<::beman::execution::detail::token_test_sender>);
static_assert(::beman::execution::sender_in<::beman::execution::detail::token_test_sender,
                                            ::beman::execution::detail::token_test_env>);
} // namespace beman::execution::detail

namespace beman::execution {
template <typename Token>
concept scope_token = ::std::copyable<Token> && requires(const Token token) {
    { token.try_associate() } -> ::beman::execution::scope_association;
    {
        token.wrap(::std::declval<::beman::execution::detail::token_test_sender>())
    } -> ::beman::execution::sender_in<::beman::execution::detail::token_test_env>;
};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SCOPE_TOKEN
