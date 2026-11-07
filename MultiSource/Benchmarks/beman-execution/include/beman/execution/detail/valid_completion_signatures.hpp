// include/beman/execution/detail/valid_completion_signatures.hpp   -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_VALID_COMPLETION_SIGNATURES
#define INCLUDED_BEMAN_EXECUTION_DETAIL_VALID_COMPLETION_SIGNATURES

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.completion_signatures;
#else
#include <beman/execution/detail/completion_signatures.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename>
struct valid_completion_signatures_helper : ::std::false_type {};
template <typename... Sigs>
struct valid_completion_signatures_helper<::beman::execution::completion_signatures<Sigs...>> : ::std::true_type {};

template <typename Signatures>
concept valid_completion_signatures = valid_completion_signatures_helper<Signatures>::value;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_VALID_COMPLETION_SIGNATURES
