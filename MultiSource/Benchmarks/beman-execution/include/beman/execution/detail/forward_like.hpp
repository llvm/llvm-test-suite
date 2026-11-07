// include/beman/execution/detail/forward_like.hpp                  -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_FORWARD_LIKE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_FORWARD_LIKE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#include <utility>
#endif

// ----------------------------------------------------------------------------
// std::forward_like() doesn't work on some compilers, yet. This header
// provides a work-around.

namespace beman::execution::detail {
template <typename>
struct forward_like_helper;

template <typename T>
struct forward_like_helper {
    template <typename U>
    static auto forward(U&& u) -> ::std::remove_reference_t<U>&& {
        return ::std::move(u); // NOLINT(bugprone-move-forwarding-reference)
    }
};
template <typename T>
struct forward_like_helper<T&&> {
    template <typename U>
    static auto forward(U&& u) -> ::std::remove_cvref_t<U>&& {
        return ::std::move(u); // NOLINT(bugprone-move-forwarding-reference)
    }
};
template <typename T>
struct forward_like_helper<T&> {
    template <typename U>
    static auto forward(U&& u) -> ::std::remove_cvref_t<U>& {
        return ::std::forward<U&&>(u);
    }
};
template <typename T>
struct forward_like_helper<const T&&> {
    template <typename U>
    static auto forward(U&& u) -> const ::std::remove_cvref_t<U>&& {
        return ::std::move(u); // NOLINT(bugprone-move-forwarding-reference)
    }
};
template <typename T>
struct forward_like_helper<const T&> {
    template <typename U>
    static auto forward(U&& u) -> const ::std::remove_cvref_t<U>& {
        return ::std::forward<U&&>(u);
    }
};

// The overload own_forward_like is used for testing on systems
// which actually do provide an implementation.
template <typename T, typename U>
auto own_forward_like(U&& u) noexcept -> decltype(auto) {
    return ::beman::execution::detail::forward_like_helper<T>::forward(::std::forward<U>(u));
}

/*!
 * \brief Helper function to forward a subobject (in case the standard library version is unavailable)
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <typename T, typename U>
auto forward_like(U&& u) noexcept -> decltype(auto) {
#if 202207 <= disabled__cpp_lib_forward_like
    return ::std::forward_like<T>(::std::forward<U>(u));
#else
    return ::beman::execution::detail::forward_like_helper<T>::forward(::std::forward<U>(u));
#endif
}

} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_FORWARD_LIKE
