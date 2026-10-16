// include/beman/execution/detail/stoppable_source.hpp              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_STOPPABLE_SOURCE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_STOPPABLE_SOURCE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.stoppable_token;
#else
#include <beman/execution/detail/stoppable_token.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Source> //-dk:TODO detail export
concept stoppable_source = requires(Source& source, const Source& csource) {
    { csource.get_token() } -> ::beman::execution::stoppable_token;
    { csource.stop_possible() } noexcept -> ::std::same_as<bool>;
    { csource.stop_requested() } noexcept -> ::std::same_as<bool>;
    { source.request_stop() } -> ::std::same_as<bool>;
};
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_STOPPABLE_SOURCE
