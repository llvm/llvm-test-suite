// include/beman/execution/detail/schedule_from.hpp                 -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SCHEDULE_FROM
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SCHEDULE_FROM

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.child_type;
import beman.execution.detail.get_completion_signatures;
import beman.execution.detail.make_sender;
import beman.execution.detail.product_type;
import beman.execution.detail.sender;
#else
#include <beman/execution/detail/child_type.hpp>
#include <beman/execution/detail/get_completion_signatures.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/product_type.hpp>
#include <beman/execution/detail/sender.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {

struct schedule_from_t {
    template <typename Self, typename... Env>
    static consteval auto get_completion_signatures() {
        return ::beman::execution::get_completion_signatures<::beman::execution::detail::child_type<Self>, Env...>();
    }

    template <::beman::execution::sender Sender>
    auto operator()(Sender&& sender) const {
        return ::beman::execution::detail::make_sender(
            *this, ::beman::execution::detail::product_type<>{}, ::std::forward<Sender>(sender));
    }
};

} // namespace beman::execution::detail

namespace beman::execution {
using schedule_from_t = ::beman::execution::detail::schedule_from_t;
inline constexpr ::beman::execution::schedule_from_t schedule_from{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SCHEDULE_FROM
