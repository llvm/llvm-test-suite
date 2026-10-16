// include/beman/execution/detail/get_allocator.hpp                 -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_GET_ALLOCATOR
#define INCLUDED_BEMAN_EXECUTION_DETAIL_GET_ALLOCATOR

#include <beman/execution/detail/common.hpp>
#include <beman/execution/detail/suppress_push.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.forwarding_query;
import beman.execution.detail.simple_allocator;
#else
#include <beman/execution/detail/forwarding_query.hpp>
#include <beman/execution/detail/simple_allocator.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
struct get_allocator_t {
    template <typename Object>
        requires(not requires(Object&& object, const get_allocator_t& tag) { ::std::as_const(object).query(tag); })
    auto
    operator()(Object&&) const = BEMAN_EXECUTION_DELETE("the object requires a const query(get_allocator_t) overload");
    template <typename Object>
        requires(
                    not requires(const Object& object, const get_allocator_t& tag) { object.query(tag); } &&
                    not requires(Object&& object, const get_allocator_t& tag) { ::std::as_const(object).query(tag); })
    auto operator()(Object&&) const = BEMAN_EXECUTION_DELETE("the object requires a query(get_allocator_t) overload");
    template <typename Object>
        requires(not requires(const Object& object, const get_allocator_t& tag) {
                    { object.query(tag) } noexcept;
                })
    auto
    operator()(Object&&) const = BEMAN_EXECUTION_DELETE("the query(get_allocator_t) overload needs to be noexcept");

    template <typename Object>
        requires(not requires(const Object& object, const get_allocator_t& tag) {
                    { object.query(tag) } noexcept -> ::beman::execution::detail::simple_allocator<>;
                })
    auto
    operator()(Object&&) const = BEMAN_EXECUTION_DELETE("the query(get_allocator_t) overload needs to be noexcept");

    template <typename Object>
        requires(requires(const Object& object, const get_allocator_t& tag) {
            { object.query(tag) } noexcept -> ::beman::execution::detail::simple_allocator<>;
        })
    auto operator()(Object&& object) const noexcept {
        return ::std::as_const(object).query(*this);
    }

    constexpr auto query(const ::beman::execution::forwarding_query_t&) const noexcept -> bool { return true; }
};

inline constexpr get_allocator_t get_allocator{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#include <beman/execution/detail/suppress_pop.hpp>

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_GET_ALLOCATOR
