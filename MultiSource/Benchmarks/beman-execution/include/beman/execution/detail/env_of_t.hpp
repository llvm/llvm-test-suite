// include/beman/execution/detail/env_of_t.hpp                      -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_ENV_OF
#define INCLUDED_BEMAN_EXECUTION_DETAIL_ENV_OF

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.get_env;
#else
#include <beman/execution/detail/get_env.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
/*!
 * \brief Determine the type of the environment associated with a type
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
template <typename T>
using env_of_t = decltype(::beman::execution::get_env(::std::declval<T>()));
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_ENV_OF
