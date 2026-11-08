// include/beman/execution/detail/with_error.hpp                           -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_WITH_ERROR
#define INCLUDED_BEMAN_EXECUTION_DETAIL_WITH_ERROR

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
template <typename E>
struct with_error {
    using type = ::std::remove_cvref_t<E>;
    type error;
};
template <typename E>
with_error(E&&) -> with_error<E>;

} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif
