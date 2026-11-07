// include/beman/execution/detail/unstoppable_token.hpp             -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_UNSTOPPABLE_TOKEN
#define INCLUDED_BEMAN_EXECUTION_DETAIL_UNSTOPPABLE_TOKEN

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.stoppable_source;
import beman.execution.detail.stoppable_token;
#else
#include <beman/execution/detail/stoppable_source.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
template <typename Token>
concept unstoppable_token = ::beman::execution::stoppable_token<Token> &&
                            requires() { requires ::std::bool_constant<not Token::stop_possible()>::value; };
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_UNSTOPPABLE_TOKEN
