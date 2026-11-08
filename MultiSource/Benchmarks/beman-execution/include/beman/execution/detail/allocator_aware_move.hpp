// include/beman/execution/detail/allocator_aware_move.hpp          -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_ALLOCATOR_AWARE_MOVE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_ALLOCATOR_AWARE_MOVE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <exception>
#include <memory>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.get_allocator;
import beman.execution.detail.get_env;
import beman.execution.detail.product_type;
#else
#include <beman/execution/detail/get_allocator.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/product_type.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename T, typename Context>
/*!
 * \brief Utility function use to move a possibly allocator aware object with an allocator from an environment.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
auto allocator_aware_move(T&& obj, Context&& context) noexcept -> decltype(auto) {
    try {
        if constexpr (requires { ::beman::execution::get_allocator(::beman::execution::get_env(context)); }) {
            if constexpr (decltype(::beman::execution::detail::is_product_type(obj))()) {
                return obj.make_from(::beman::execution::get_allocator(::beman::execution::get_env(context)),
                                     ::std::forward<T>(obj));
            } else {
                return ::std::make_obj_using_allocator<T>(
                    ::beman::execution::get_allocator(::beman::execution::get_env(context)), ::std::forward<T>(obj));
            }
        } else {
            return ::std::forward<T>(obj);
        }
    } catch (...) {
        ::std::terminate(); //-dk:TODO investigate if that can be avoided
    }
}
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_ALLOCATOR_AWARE_MOVE
