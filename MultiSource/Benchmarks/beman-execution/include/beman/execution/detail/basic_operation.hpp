// include/beman/execution/detail/basic_operation.hpp               -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_BASIC_OPERATION
#define INCLUDED_BEMAN_EXECUTION_DETAIL_BASIC_OPERATION

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <functional>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_state;
import beman.execution.detail.connect_all;
import beman.execution.detail.connect_all_result;
import beman.execution.detail.impls_for;
import beman.execution.detail.indices_for;
import beman.execution.detail.operation_state;
import beman.execution.detail.sender_decompose;
import beman.execution.detail.start;
import beman.execution.detail.state_type;
import beman.execution.detail.tag_of_t;
import beman.execution.detail.valid_specialization;
#else
#include <beman/execution/detail/basic_state.hpp>
#include <beman/execution/detail/connect_all_result.hpp>
#include <beman/execution/detail/impls_for.hpp>
#include <beman/execution/detail/operation_state.hpp>
#include <beman/execution/detail/sender_decompose.hpp>
#include <beman/execution/detail/start.hpp>
#include <beman/execution/detail/state_type.hpp>
#include <beman/execution/detail/tag_of_t.hpp>
#include <beman/execution/detail/valid_specialization.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
/*!
 * \brief Class template use to factor out common operation state needs.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
//-dk:TODO the export below shouldn't be needed, but MSVC++ seems to require it (2026-02-01)
template <typename Sender, typename Receiver> //-dk:TODO detail export
    requires ::beman::execution::detail::
        //-dk:TODO why is the remove_cvref_t needed...?
    valid_specialization<::beman::execution::detail::state_type, std::remove_cvref_t<Sender>, Receiver>
struct basic_operation : ::beman::execution::detail::basic_state<Sender, Receiver> {
    // static_assert(std::same_as<Sender, std::remove_cvref_t<Sender>>);
    friend struct ::beman::execution::start_t;
    using operation_state_concept = ::beman::execution::operation_state_tag;
    using tag_t                   = ::beman::execution::tag_of_t<Sender>;

    using inner_ops_t = ::beman::execution::detail::connect_all_result<Sender, Receiver>;
    inner_ops_t inner_ops;

    basic_operation(Sender&& sender, Receiver&& rcvr) noexcept(
        noexcept(::beman::execution::detail::basic_state<Sender, Receiver>(::std::forward<Sender>(sender),
                                                                           ::std::move(rcvr))) &&
        noexcept(::beman::execution::detail::connect_all(this,
                                                         ::std::forward<Sender>(sender),
                                                         ::beman::execution::detail::indices_for<Sender>())))
        : ::beman::execution::detail::basic_state<Sender, Receiver>(::std::forward<Sender>(sender), ::std::move(rcvr)),
          // NOLINTBEGIN(bugprone-use-after-move,hicpp-invalid-access-moved)
          //-dk:TODO deal with moving the sender twice
          inner_ops(::beman::execution::detail::connect_all(
              this, ::std::forward<Sender>(sender), ::beman::execution::detail::indices_for<Sender>())) {}
    // NOLINTEND(bugprone-use-after-move,hicpp-invalid-access-moved)

    basic_operation(const basic_operation&) = delete;

    auto operator=(const basic_operation&) -> basic_operation& = delete;

  private:
    auto start() & noexcept -> void {
        ::std::invoke(
            [this]<::std::size_t... I>(::std::index_sequence<I...>) {
                ::beman::execution::detail::get_impls_for<tag_t>::start()(
                    this->state, this->receiver, this->inner_ops.template get<I>()...);
            },
            ::std::make_index_sequence<inner_ops_t::size()>{});
    }
};
template <typename Sender, typename Receiver>
basic_operation(Sender&&, Receiver&&) -> basic_operation<Sender&&, Receiver>;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_BASIC_OPERATION
