// include/beman/execution/detail/execution_policy.hpp              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_EXECUTION_POLICY
#define INCLUDED_BEMAN_EXECUTION_DETAIL_EXECUTION_POLICY
#include <version>
#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#ifdef __cpp_lib_execution
#include <execution>
#else
#include <type_traits>
#endif
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
#ifdef __cpp_lib_execution

using ::std::execution::par;
using ::std::execution::parallel_policy;

using ::std::execution::par_unseq;
using ::std::execution::parallel_unsequenced_policy;

using ::std::execution::seq;
using ::std::execution::sequenced_policy;

#if __cpp_lib_execution >= 201902L
using ::std::execution::unseq;
using ::std::execution::unsequenced_policy;
#endif

template <typename T>
struct is_execution_policy : ::std::is_execution_policy<T> {};

template <typename T>
inline constexpr bool is_execution_policy_v = ::beman::execution::is_execution_policy<T>::value;

#else

struct sequenced_policy {};
inline constexpr sequenced_policy seq{};

struct parallel_policy {};
inline constexpr parallel_policy par{};

struct parallel_unsequenced_policy {};
inline constexpr parallel_unsequenced_policy par_unseq{};

struct unsequenced_policy {};
inline constexpr unsequenced_policy unseq{};

template <typename>
struct is_execution_policy : ::std::false_type {};

template <>
struct is_execution_policy< ::beman::execution::sequenced_policy> : ::std::true_type {};

template <>
struct is_execution_policy< ::beman::execution::parallel_policy> : ::std::true_type {};

template <>
struct is_execution_policy< ::beman::execution::parallel_unsequenced_policy> : ::std::true_type {};

template <>
struct is_execution_policy< ::beman::execution::unsequenced_policy> : ::std::true_type {};

template <typename T>
inline constexpr bool is_execution_policy_v = ::beman::execution::is_execution_policy<T>::value;

#endif
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_EXECUTION_POLICY
