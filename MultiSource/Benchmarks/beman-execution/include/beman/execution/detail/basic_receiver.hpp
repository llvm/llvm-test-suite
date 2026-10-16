// include/beman/execution/detail/basic_receiver.hpp                -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_BASIC_RECEIVER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_BASIC_RECEIVER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_state;
import beman.execution.detail.callable;
import beman.execution.detail.env_type;
import beman.execution.detail.get_env;
import beman.execution.detail.impls_for;
import beman.execution.detail.receiver;
import beman.execution.detail.sender_decompose;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.state_type;
import beman.execution.detail.tag_of_t;
import beman.execution.detail.valid_specialization;
#else
#include <beman/execution/detail/basic_state.hpp>
#include <beman/execution/detail/callable.hpp>
#include <beman/execution/detail/env_type.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/impls_for.hpp>
#include <beman/execution/detail/receiver.hpp>
#include <beman/execution/detail/sender_decompose.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/state_type.hpp>
#include <beman/execution/detail/tag_of_t.hpp>
#include <beman/execution/detail/valid_specialization.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
/*!
 * \brief Class template used as receiver for child completions for library senders.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <typename Sender, typename Receiver, typename Index>
    requires ::beman::execution::detail::
        valid_specialization<::beman::execution::detail::env_type, Index, Sender, Receiver>
    struct basic_receiver {
    friend struct ::beman::execution::get_env_t;
    friend struct ::beman::execution::set_error_t;
    friend struct ::beman::execution::set_stopped_t;
    friend struct ::beman::execution::set_value_t;

    using receiver_concept                = ::beman::execution::receiver_tag;
    using tag_t                           = ::beman::execution::tag_of_t<Sender>;
    using state_t                         = ::beman::execution::detail::state_type<Sender, Receiver>;
    static constexpr const auto& complete = ::beman::execution::detail::get_impls_for<tag_t>::complete();
    ::beman::execution::detail::basic_state<Sender, Receiver>* op{};

  private:
    template <typename... Args>
    auto set_value(Args&&... args) && noexcept -> void
        requires ::beman::execution::detail::
            callable<decltype(complete), Index, state_t&, Receiver&, ::beman::execution::set_value_t, Args...>
    {
        this->complete(Index(),
                       this->op->state,
                       this->op->receiver,
                       ::beman::execution::set_value,
                       ::std::forward<Args>(args)...);
    }

    template <typename Error>
    auto set_error(Error&& error) && noexcept -> void
        requires ::beman::execution::detail::
            callable<decltype(complete), Index, state_t&, Receiver&, ::beman::execution::set_error_t, Error>
    {
        this->complete(
            Index(), this->op->state, this->op->receiver, ::beman::execution::set_error, ::std::forward<Error>(error));
    }

    auto set_stopped() && noexcept -> void
        requires ::beman::execution::detail::
            callable<decltype(complete), Index, state_t&, Receiver&, ::beman::execution::set_stopped_t>
    {
        this->complete(Index(), this->op->state, this->op->receiver, ::beman::execution::set_stopped_t());
    }

    auto get_env() const noexcept -> ::beman::execution::detail::env_type<Index, Sender, Receiver> {
        return ::beman::execution::detail::get_impls_for<tag_t>::get_env()(
            Index(), this->op->state, this->op->receiver);
    }
};
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_BASIC_RECEIVER
