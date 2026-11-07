// include/beman/execution/detail/starts_on.hpp                     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_STARTS_ON
#define INCLUDED_BEMAN_EXECUTION_DETAIL_STARTS_ON

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_sender;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.completion_signatures_of_t;
import beman.execution.detail.continues_on;
import beman.execution.detail.default_impls;
import beman.execution.detail.env;
import beman.execution.detail.error_types_of_t;
import beman.execution.detail.forward_like;
import beman.execution.detail.fwd_env;
import beman.execution.detail.get_completion_domain;
import beman.execution.detail.get_completion_scheduler;
import beman.execution.detail.get_completion_signatures;
import beman.execution.detail.get_env;
import beman.execution.detail.join_env;
import beman.execution.detail.just;
import beman.execution.detail.let;
import beman.execution.detail.make_sender;
import beman.execution.detail.meta.combine;
import beman.execution.detail.meta.unique;
import beman.execution.detail.query_with_default;
import beman.execution.detail.sched_env;
import beman.execution.detail.schedule_result_t;
import beman.execution.detail.scheduler;
import beman.execution.detail.sender;
import beman.execution.detail.sender_for;
import beman.execution.detail.sends_stopped;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
#else
#include <beman/execution/detail/basic_sender.hpp>
#include <beman/execution/detail/completion_signatures.hpp>
#include <beman/execution/detail/completion_signatures_of_t.hpp>
#include <beman/execution/detail/continues_on.hpp>
#include <beman/execution/detail/default_impls.hpp>
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/error_types_of_t.hpp>
#include <beman/execution/detail/forward_like.hpp>
#include <beman/execution/detail/fwd_env.hpp>
#include <beman/execution/detail/get_completion_domain.hpp>
#include <beman/execution/detail/get_completion_scheduler.hpp>
#include <beman/execution/detail/get_completion_signatures.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/join_env.hpp>
#include <beman/execution/detail/just.hpp>
#include <beman/execution/detail/let.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/meta_combine.hpp>
#include <beman/execution/detail/meta_unique.hpp>
#include <beman/execution/detail/sched_env.hpp>
#include <beman/execution/detail/schedule_result_t.hpp>
#include <beman/execution/detail/scheduler.hpp>
#include <beman/execution/detail/sender_for.hpp>
#include <beman/execution/detail/sends_stopped.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct starts_on_t {
    template <::beman::execution::detail::sender_for<::beman::execution::detail::starts_on_t> Sender, typename Env>
    static auto transform_sender(::beman::execution::set_value_t, Sender&& sender, const Env&) noexcept {
        auto&&         sched{sender.template get<1>()};
        auto&&         child{sender.template get<2>()};
        constexpr bool is_nothrow = ::std::is_nothrow_move_constructible_v<::std::remove_cvref_t<decltype(child)>>;
        return ::beman::execution::let_value(
            ::beman::execution::continues_on(::beman::execution::just(), sched),
            [child_ = ::beman::execution::detail::forward_like<Sender>(child)]() mutable noexcept(is_nothrow) {
                return ::std::move(child_);
            });
    }

  private:
    template <typename, typename...>
    struct get_signatures;
    template <typename Sender>
    struct get_signatures<Sender> : get_signatures<Sender, ::beman::execution::env<>> {};
    template <typename Scheduler, typename Child, typename Env>
    struct get_signatures<
        ::beman::execution::detail::basic_sender<::beman::execution::detail::starts_on_t, Scheduler, Child>,
        Env> {
        static consteval auto get() {
            using transformed_sndr = decltype(starts_on_t::transform_sender(
                ::beman::execution::set_value,
                ::std::declval<::beman::execution::detail::
                                   basic_sender<::beman::execution::detail::starts_on_t, Scheduler, Child>>(),
                ::std::declval<Env>()));
            return ::beman::execution::get_completion_signatures<transformed_sndr, Env>();
        }
    };

    template <typename Scheduler, typename ChildAttrs>
    struct attrs {
        template <typename Env>
        auto wrap_env(const Env& env) const noexcept {
            return ::beman::execution::detail::join_env(::beman::execution::detail::sched_env(this->sch), env);
        }

        template <typename Tag, typename... Env>
        auto query(::beman::execution::get_completion_scheduler_t<Tag>, const Env&... env) const noexcept {
            if constexpr (requires {
                              ::beman::execution::get_completion_scheduler<Tag>(this->child_attrs,
                                                                                this->wrap_env(env)...);
                          }) {
                return ::beman::execution::get_completion_scheduler<Tag>(this->child_attrs, this->wrap_env(env)...);
            } else {
                return this->sch;
            }
        }

        template <typename Tag, typename... Env>
        static auto query(::beman::execution::get_completion_domain_t<Tag>, const Env&...) noexcept
            -> decltype(::beman::execution::get_completion_domain<Tag>(
                ::std::declval<ChildAttrs>(), std::declval<attrs>().wrap_env(::std::declval<Env>())...)) {
            return {};
        }

        template <typename Tag, typename... Env>
            requires requires(const Tag& tag, const ChildAttrs& child_attrs, Env&&... env) {
                tag(::beman::execution::detail::fwd_env(child_attrs), ::std::forward<Env>(env)...);
            }
        auto query(Tag tag, Env&&... env) const noexcept {
            return tag(::beman::execution::detail::fwd_env(this->child_attrs), ::std::forward<Env>(env)...);
        }

        Scheduler  sch;
        ChildAttrs child_attrs;
    };

  public:
    template <typename Sender, typename... Env>
    static consteval auto get_completion_signatures() {
        return get_signatures<::std::remove_cvref_t<Sender>, Env...>::get();
    }

    struct impls_for : ::beman::execution::detail::default_impls {
        struct get_attrs_impl {
            auto operator()(const auto& sch, const auto& child) const noexcept {
                using Sch      = ::std::remove_cvref_t<decltype(sch)>;
                using ChildEnv = ::std::remove_cvref_t<decltype(::beman::execution::get_env(child))>;
                return attrs<Sch, ChildEnv>{sch, ::beman::execution::get_env(child)};
            }
        };
        static constexpr auto get_attrs{get_attrs_impl{}};
    };

    template <::beman::execution::scheduler Scheduler, ::beman::execution::sender Sender>
    auto operator()(Scheduler&& scheduler, Sender&& sender) const {
        return ::beman::execution::detail::make_sender(
            *this, ::std::forward<Scheduler>(scheduler), ::std::forward<Sender>(sender));
    }
};
} // namespace beman::execution::detail

namespace beman::execution {
using starts_on_t = ::beman::execution::detail::starts_on_t;
inline constexpr ::beman::execution::detail::starts_on_t starts_on{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_STARTS_ON
