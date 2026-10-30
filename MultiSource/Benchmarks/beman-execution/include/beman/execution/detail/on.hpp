// include/beman/execution/detail/on.hpp                            -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_ON
#define INCLUDED_BEMAN_EXECUTION_DETAIL_ON

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_sender;
import beman.execution.detail.call_with_default;
import beman.execution.detail.completion_signatures_of_t;
import beman.execution.detail.continues_on;
import beman.execution.detail.default_impls;
import beman.execution.detail.default_domain;
import beman.execution.detail.env_of_t;
import beman.execution.detail.forward_like;
import beman.execution.detail.fwd_env;
import beman.execution.detail.get_completion_domain;
import beman.execution.detail.get_completion_signatures;
import beman.execution.detail.get_completion_scheduler;
import beman.execution.detail.get_domain;
import beman.execution.detail.get_env;
import beman.execution.detail.get_start_scheduler;
import beman.execution.detail.join_env;
import beman.execution.detail.make_sender;
import beman.execution.detail.product_type;
import beman.execution.detail.query_with_default;
import beman.execution.detail.sched_env;
import beman.execution.detail.scheduler;
import beman.execution.detail.sender;
import beman.execution.detail.sender_adaptor_closure;
import beman.execution.detail.sender_for;
import beman.execution.detail.set_value;
import beman.execution.detail.starts_on;
import beman.execution.detail.transform_sender;
#else
#include <beman/execution/detail/basic_sender.hpp>
#include <beman/execution/detail/call_with_default.hpp>
#include <beman/execution/detail/continues_on.hpp>
#include <beman/execution/detail/default_impls.hpp>
#include <beman/execution/detail/default_domain.hpp>
#include <beman/execution/detail/env_of_t.hpp>
#include <beman/execution/detail/forward_like.hpp>
#include <beman/execution/detail/fwd_env.hpp>
#include <beman/execution/detail/get_completion_domain.hpp>
#include <beman/execution/detail/get_completion_signatures.hpp>
#include <beman/execution/detail/get_completion_scheduler.hpp>
#include <beman/execution/detail/get_domain.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/get_start_scheduler.hpp>
#include <beman/execution/detail/join_env.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/product_type.hpp>
#include <beman/execution/detail/query_with_default.hpp>
#include <beman/execution/detail/sched_env.hpp>
#include <beman/execution/detail/scheduler.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/sender_adaptor_closure.hpp>
#include <beman/execution/detail/sender_for.hpp>
#include <beman/execution/detail/starts_on.hpp>
#include <beman/execution/detail/transform_sender.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct on_t : ::beman::execution::sender_adaptor_closure<on_t> {
    template <typename Env, typename OutSndr>
    static auto dry_run(OutSndr&& out_sndr) noexcept {
        auto& [_, data, child] = out_sndr;
        if constexpr (::beman::execution::scheduler<decltype(data)>) {
            return ::std::bool_constant<::std::invocable<::beman::execution::get_start_scheduler_t, Env>>{};
        } else {
            ::std::bool_constant<
                ::std::invocable<::beman::execution::get_completion_scheduler_t<::beman::execution::set_value_t>,
                                 ::beman::execution::env_of_t<decltype(child)>,
                                 Env>>{};
        }
    }

    template <::beman::execution::detail::sender_for<on_t> OutSndr, typename Env>
        requires(decltype(on_t::dry_run<Env>(::std::declval<OutSndr>()))::value)
    static auto transform_sender(::beman::execution::set_value_t, OutSndr&& out_sndr, const Env& env)
        -> decltype(auto) {
        auto&& data  = out_sndr.template get<1>();
        auto&& child = out_sndr.template get<2>();

        if constexpr (::beman::execution::scheduler<decltype(data)>) {
            auto start_sch = ::beman::execution::get_start_scheduler(env);
            return ::beman::execution::continues_on(
                ::beman::execution::starts_on(::beman::execution::detail::forward_like<OutSndr>(data),
                                              ::beman::execution::detail::forward_like<OutSndr>(child)),
                ::std::move(start_sch));
        } else {
            auto& [sch, closure] = data;
            auto orig_sch        = ::beman::execution::get_completion_scheduler<::beman::execution::set_value_t>(
                ::beman::execution::get_env(child), env);

            return ::beman::execution::continues_on(
                ::beman::execution::detail::forward_like<OutSndr>(closure)(
                    ::beman::execution::continues_on(::beman::execution::detail::forward_like<OutSndr>(child), sch)),
                orig_sch);
        }
    }

    struct impls_for : ::beman::execution::detail::default_impls {
        struct get_attrs_impl {
            template <typename Sched, typename Child>
            auto operator()(const Sched&, const Child& child) const noexcept {
                using ChildAttrs = ::std::remove_cvref_t<::beman::execution::env_of_t<Child>>;
                return attrs1<ChildAttrs>{::beman::execution::get_env(child)};
            }

            template <typename Sched, typename Closure, typename Child>
            auto operator()(const ::beman::execution::detail::product_type<Sched, Closure>&,
                            const Child& child) const noexcept {
                using ChildAttrs = ::std::remove_cvref_t<::beman::execution::env_of_t<Child>>;
                return attrs2<ChildAttrs>{::beman::execution::get_env(child)};
            }
        };

        static constexpr auto get_attrs{get_attrs_impl{}};
    };

    template <::beman::execution::scheduler Sch, ::beman::execution::sender Sndr>
        requires ::beman::execution::detail::is_sender_adaptor_closure<Sndr>
    auto operator()(Sch&&, Sndr&&) const -> void =
        BEMAN_EXECUTION_DELETE("on(sch, sndr) requires that sndr isn't both a sender and sender adaptor closure");

    template <::beman::execution::scheduler                         Sch,
              ::beman::execution::sender                            Sndr,
              ::beman::execution::detail::is_sender_adaptor_closure Closure>
        requires ::beman::execution::detail::is_sender_adaptor_closure<Sndr>
    auto operator()(Sndr&&, Sch&&, Closure&&) const -> void = BEMAN_EXECUTION_DELETE(
        "on(sndr, sch, closure) requires that sndr isn't both a sender and sender adaptor closure");

    template <::beman::execution::scheduler Sch, ::beman::execution::sender Sndr>
    auto operator()(Sch&& sch, Sndr&& sndr) const {
        return ::beman::execution::detail::make_sender(*this, ::std::forward<Sch>(sch), ::std::forward<Sndr>(sndr));
    }
    template <::beman::execution::scheduler                         Sch,
              ::beman::execution::sender                            Sndr,
              ::beman::execution::detail::is_sender_adaptor_closure Closure>
    auto operator()(Sndr&& sndr, Sch&& sch, Closure&& closure) const {
        return ::beman::execution::detail::make_sender(
            *this,
            ::beman::execution::detail::product_type{::std::forward<Sch>(sch), ::std::forward<Closure>(closure)},
            ::std::forward<Sndr>(sndr));
    }
    template <::beman::execution::scheduler Sch, ::beman::execution::detail::is_sender_adaptor_closure Closure>
    auto operator()(Sch&& sch, Closure&& closure) const {
        return ::beman::execution::detail::make_sender_adaptor(
            *this, ::std::forward<Sch>(sch), ::std::forward<Closure>(closure));
    }

  private:
    template <typename>
    struct is_completion_query : ::std::false_type {};

    template <typename Tag>
    struct is_completion_query<::beman::execution::get_completion_scheduler_t<Tag>> : ::std::true_type {};

    template <typename Tag>
    struct is_completion_query<::beman::execution::get_completion_domain_t<Tag>> : ::std::true_type {};

    template <typename ChildAttrs>
    struct attrs_base {
        template <typename Query, typename... Args>
            requires(!is_completion_query<::std::remove_cvref_t<Query>>::value) &&
                    requires(const ChildAttrs& child_attrs, Query query, Args&&... args) {
                        query(::beman::execution::detail::fwd_env(child_attrs), ::std::forward<Args>(args)...);
                    }
        auto query(Query query, Args&&... args) const noexcept {
            return query(::beman::execution::detail::fwd_env(this->child_attrs), ::std::forward<Args>(args)...);
        }

        ChildAttrs child_attrs;
    };

    template <typename ChildAttrs>
    struct attrs1 : attrs_base<ChildAttrs> {
        using attrs_base<ChildAttrs>::query;

        template <typename Tag, typename Env>
            requires requires(const Env& env) {
                ::beman::execution::get_completion_scheduler<Tag>(::beman::execution::get_start_scheduler(env),
                                                                  ::beman::execution::detail::fwd_env(env));
            }
        auto query(::beman::execution::get_completion_scheduler_t<Tag>, const Env& env) const noexcept {
            auto sched = ::beman::execution::get_start_scheduler(env);
            return ::beman::execution::get_completion_scheduler<Tag>(sched, ::beman::execution::detail::fwd_env(env));
        }

        template <typename Tag, typename Env>
            requires requires(const Env& env) {
                ::beman::execution::get_completion_domain<Tag>(::beman::execution::get_start_scheduler(env),
                                                               ::beman::execution::detail::fwd_env(env));
            }
        auto query(::beman::execution::get_completion_domain_t<Tag>, const Env& env) const noexcept {
            auto sched = ::beman::execution::get_start_scheduler(env);
            return ::beman::execution::get_completion_domain<Tag>(sched, ::beman::execution::detail::fwd_env(env));
        }
    };

    template <typename ChildAttrs>
    struct attrs2 : attrs_base<ChildAttrs> {
        using attrs_base<ChildAttrs>::query;

        template <typename Env>
        auto original_sched(const Env& env) const noexcept {
            return ::beman::execution::get_completion_scheduler<::beman::execution::set_value_t>(this->child_attrs,
                                                                                                 env);
        }

        template <typename Tag, typename Env>
            requires requires(const attrs2& self, const Env& env) {
                ::beman::execution::get_completion_scheduler<Tag>(self.original_sched(env),
                                                                  ::beman::execution::detail::fwd_env(env));
            }
        auto query(::beman::execution::get_completion_scheduler_t<Tag>, const Env& env) const noexcept {
            return ::beman::execution::get_completion_scheduler<Tag>(this->original_sched(env),
                                                                     ::beman::execution::detail::fwd_env(env));
        }

        template <typename Tag, typename Env>
            requires requires(const attrs2& self, const Env& env) {
                ::beman::execution::get_completion_domain<Tag>(self.original_sched(env),
                                                               ::beman::execution::detail::fwd_env(env));
            }
        auto query(::beman::execution::get_completion_domain_t<Tag>, const Env& env) const noexcept {
            return ::beman::execution::get_completion_domain<Tag>(this->original_sched(env),
                                                                  ::beman::execution::detail::fwd_env(env));
        }
    };

    template <typename, typename...>
    struct get_signatures;

    /// for `on(scheduler, sender)`
    template <typename Sched, typename Child, typename Env>
    struct get_signatures<::beman::execution::detail::basic_sender<::beman::execution::detail::on_t, Sched, Child>,
                          Env> {
        static consteval auto get()
            requires ::std::invocable<::beman::execution::get_start_scheduler_t, Env>
        {
            using transformed_sndr = decltype(on_t::transform_sender(
                ::beman::execution::set_value,
                ::std::declval<
                    ::beman::execution::detail::basic_sender<::beman::execution::detail::on_t, Sched, Child>>(),
                ::std::declval<Env>()));
            return ::beman::execution::get_completion_signatures<transformed_sndr, Env>();
        }
    };

    /// for `on(sender, scheduler, closure)`
    template <typename Sched, typename Closure, typename Child, typename Env>
    struct get_signatures<
        ::beman::execution::detail::basic_sender<::beman::execution::detail::on_t,
                                                 ::beman::execution::detail::product_type<Sched, Closure>,
                                                 Child>,
        Env> {
        static consteval auto get()
            requires ::std::invocable<::beman::execution::get_completion_scheduler_t<::beman::execution::set_value_t>,
                                      ::beman::execution::env_of_t<Child>,
                                      Env>
        {
            using transformed_sndr = decltype(on_t::transform_sender(
                ::beman::execution::set_value,
                ::std::declval<
                    ::beman::execution::detail::basic_sender<::beman::execution::detail::on_t,
                                                             ::beman::execution::detail::product_type<Sched, Closure>,
                                                             Child>>(),
                ::std::declval<Env>()));
            return ::beman::execution::get_completion_signatures<transformed_sndr, Env>();
        }
    };

  public:
    template <typename Sender, typename Env>
        requires requires { get_signatures<std::remove_cvref_t<Sender>, Env>::get(); }
    static consteval auto get_completion_signatures() noexcept {
        return get_signatures<std::remove_cvref_t<Sender>, Env>::get();
    }
};

} // namespace beman::execution::detail

namespace beman::execution {
using on_t = ::beman::execution::detail::on_t;
inline constexpr ::beman::execution::on_t on{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#include <beman/execution/detail/suppress_pop.hpp>

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_ON
