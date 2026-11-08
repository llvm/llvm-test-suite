// include/beman/execution/detail/as_except_ptr.hpp                 -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_AS_EXCEPT_PTR
#define INCLUDED_BEMAN_EXECUTION_DETAIL_AS_EXCEPT_PTR

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <cassert>
#include <concepts>
#include <exception>
#include <system_error>
#include <type_traits>
#include <utility>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
/*!
 * \brief Turn an error into a suitable exception_ptr.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <typename Error>
//-dk:TODO add a proper precondition
decltype(auto) as_except_ptr(Error&& error) {
    if constexpr (::std::same_as<::std::exception_ptr, ::std::decay_t<Error>>) {
        return ::std::forward<Error>(error);
    } else if constexpr (::std::same_as<::std::error_code, ::std::decay_t<Error>>) {
        return ::std::make_exception_ptr(::std::system_error(error));
    } else {
        return ::std::make_exception_ptr(::std::forward<Error>(error));
    }
}
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_AS_EXCEPT_PTR
