// include/beman/execution/detail/affine.hpp                       -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_AFFINE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_AFFINE

#include <beman/execution/detail/common.hpp>
#include <beman/execution/detail/suppress_push.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_sender;
import beman.execution.detail.continues_on;
import beman.execution.detail.env;
import beman.execution.detail.forward_like;
import beman.execution.detail.get_completion_signatures;
import beman.execution.detail.get_start_scheduler;
import beman.execution.detail.infallible_scheduler;
import beman.execution.detail.make_sender;
import beman.execution.detail.nested_sender_has_affine;
import beman.execution.detail.schedule;
import beman.execution.detail.scheduler;
import beman.execution.detail.sender;
import beman.execution.detail.sender_adaptor_closure;
import beman.execution.detail.sender_for;
import beman.execution.detail.set_value;
import beman.execution.detail.store_receiver;
import beman.execution.detail.unstoppable_scheduler;
#else
#include <beman/execution/detail/basic_sender.hpp>
#include <beman/execution/detail/continues_on.hpp>
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/forward_like.hpp>
#include <beman/execution/detail/get_completion_signatures.hpp>
#include <beman/execution/detail/get_start_scheduler.hpp>
#include <beman/execution/detail/infallible_scheduler.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/nested_sender_has_affine.hpp>
#include <beman/execution/detail/schedule.hpp>
#include <beman/execution/detail/scheduler.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/sender_adaptor_closure.hpp>
#include <beman/execution/detail/sender_for.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/store_receiver.hpp>
#include <beman/execution/detail/unstoppable_scheduler.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
/**
 * @brief The affine_t struct is a sender adaptor closure that transforms a sender
 *        to complete on the scheduler obtained from the receiver's environment.
 *
 * This adaptor implements scheduler affinity to adapt a sender to complete on the
 * scheduler obtained the receiver's environment. The get_start_scheduler query is used
 * to obtain the scheduler on which the sender gets started.
 */
struct affine_t : ::beman::execution::sender_adaptor_closure<affine_t> {
    /**
     * @brief Adapt a sender with affine.
     *
     * @tparam Sender The deduced type of the sender to be transformed.
     * @param sender The sender to be transformed.
     * @return An adapted sender to complete on the scheduler it was started on.
     */
    template <::beman::execution::sender Sender>
    auto operator()(Sender&& sender) const {
        return ::beman::execution::detail::make_sender(
            *this, ::beman::execution::env<>{}, ::std::forward<Sender>(sender));
    }

    /**
     * @brief Overload for creating a sender adaptor from affine.
     *
     * @return A sender adaptor for the affine_t.
     */
    auto operator()() const { return ::beman::execution::detail::make_sender_adaptor(*this); }

    /**
     * @brief affine is implemented by transforming it into a use of continues_on.
     *
     * The constraints ensure that the environment provides a scheduler which is
     * infallible and, thus, can be used to guarantee completion on the correct
     * scheduler.
     *
     * The implementation first tries to see if the child sender's tag has a custom
     * affine implementation. If it does, that is used. Otherwise, the default
     * implementation gets a scheduler from the environment and uses continues_on
     * to adapt the sender to complete on that scheduler.
     *
     * @tparam Sender The type of the sender to be transformed.
     * @tparam Env The type of the environment providing the scheduler.
     * @param sender The sender to be transformed.
     * @param env The environment providing the scheduler.
     * @return A transformed sender that is affined to the scheduler.
     */
    template <::beman::execution::detail::sender_for<affine_t> Sender, typename Env>
    static auto transform_sender(::beman::execution::set_value_t, Sender&& sender, const Env& env) {
        auto& child = sender.template get<2>();
        if constexpr (::beman::execution::detail::nested_sender_has_affine<Sender>) {
            return ::beman::execution::detail::forward_like<Sender>(child).affine();
        } else {
            static_assert(
                requires {
                    {
                        ::beman::execution::get_start_scheduler(::std::declval<Env>())
                    } -> ::beman::execution::detail::infallible_scheduler<Env>;
                },
                "the result type of querying `get_start_scheduler` on an `Env` shall be a scheduler type whose "
                "schedule asynchronous operation can only complete with set_value unless stop can be requested");
            return ::beman::execution::continues_on(
                ::beman::execution::detail::forward_like<Sender>(child),
                ::beman::execution::detail::unstoppable_scheduler{::beman::execution::get_start_scheduler(env)});
        }
    }
    template <typename, typename...>
    struct get_signatures;

    template <typename Data, typename Child, typename Env>
    struct get_signatures<::beman::execution::detail::basic_sender<::beman::execution::detail::affine_t, Data, Child>,
                          Env> {
        static consteval auto get() {
            if constexpr (!requires {
                              {
                                  ::beman::execution::get_start_scheduler(::std::declval<Env>())
                              } -> ::beman::execution::detail::infallible_scheduler<Env>;
                          }) {
                throw ::beman::execution::detail::infallible_scheduler_error<Env>{};
            }
            return ::beman::execution::get_completion_signatures<Child, Env>();
        }
    };

    template <typename Data, typename Child>
    struct get_signatures<
        ::beman::execution::detail::basic_sender<::beman::execution::detail::affine_t, Data, Child>> {
        static consteval auto get() { return ::beman::execution::get_completion_signatures<Child>(); }
    };

    template <typename Sender, typename... Env>
    static consteval auto get_completion_signatures() {
        return get_signatures<::std::remove_cvref_t<Sender>, Env...>::get();
    }
};

} // namespace beman::execution::detail

namespace beman::execution {
/**
 * @brief affine is a CPO, used to adapt a sender to complete on the scheduler
 *      it got started on which is derived from get_start_scheduler on the receiver's environment.
 */
using affine_t = beman::execution::detail::affine_t;
inline constexpr beman::execution::detail::affine_t affine{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#include <beman/execution/detail/suppress_pop.hpp>

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_AFFINE
