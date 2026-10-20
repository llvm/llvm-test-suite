// include/beman/execution/detail/has_completions.hpp               -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_HAS_COMPLETIONS
#define INCLUDED_BEMAN_EXECUTION_DETAIL_HAS_COMPLETIONS

#include <beman/execution/detail/common.hpp>

#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.completion_signatures;
import beman.execution.detail.valid_completion_for;
#else
#include <beman/execution/detail/completion_signatures.hpp>
#include <beman/execution/detail/valid_completion_for.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {

template <typename Receiver, typename Completions>
struct has_completions_impl : std::false_type {};

template <typename Receiver, ::beman::execution::detail::valid_completion_for<Receiver>... Signatures>
struct has_completions_impl<Receiver, ::beman::execution::completion_signatures<Signatures...>> : std::true_type {};

template <typename Receiver, typename Completions>
concept has_completions = has_completions_impl<Receiver, Completions>::value;

} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_HAS_COMPLETIONS
