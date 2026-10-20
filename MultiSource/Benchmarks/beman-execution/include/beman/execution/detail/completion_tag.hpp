// include/beman/execution/detail/completion_tag.hpp                -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_COMPLETION_TAG
#define INCLUDED_BEMAN_EXECUTION_DETAIL_COMPLETION_TAG

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
#else
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
/*!
 * \brief A helper concept used to determine if a type is one of the completion tags.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <typename Tag>
concept completion_tag =
    ::std::same_as<Tag, ::beman::execution::set_error_t> || ::std::same_as<Tag, ::beman::execution::set_stopped_t> ||
    ::std::same_as<Tag, ::beman::execution::set_value_t>;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_COMPLETION_TAG
