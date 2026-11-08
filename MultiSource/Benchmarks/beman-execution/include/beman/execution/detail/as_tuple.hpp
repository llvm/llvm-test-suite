// include/beman/execution/detail/as_tuple.hpp                        -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_AS_TUPLE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_AS_TUPLE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.decayed_tuple;
#else
#include <beman/execution/detail/decayed_tuple.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
/*!
 * \brief Turn a completion signatures into a std::tuple type.
 * \internal
 */
template <typename T>
struct as_tuple;
/*!
 * \brief The actual operational partial specialization of as_tuple.
 * \internal
 */
template <typename Rc, typename... A>
struct as_tuple<Rc(A...)> {
    using type = ::beman::execution::detail::decayed_tuple<Rc, A...>;
};

template <typename T>
using as_tuple_t = typename ::beman::execution::detail::as_tuple<T>::type;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_AS_TUPLE
