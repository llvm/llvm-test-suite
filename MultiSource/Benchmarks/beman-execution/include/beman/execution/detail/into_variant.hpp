// include/beman/execution/detail/into_variant.hpp                  -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_INTO_VARIANT
#define INCLUDED_BEMAN_EXECUTION_DETAIL_INTO_VARIANT

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <exception>
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_sender;
import beman.execution.detail.child_type;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.completion_signatures_for;
import beman.execution.detail.decayed_tuple;
import beman.execution.detail.default_impls;
import beman.execution.detail.dependent_sender;
import beman.execution.detail.dependent_sender_error;
import beman.execution.detail.env;
import beman.execution.detail.env_of_t;
import beman.execution.detail.error_types_of_t;
import beman.execution.detail.impls_for;
import beman.execution.detail.make_sender;
import beman.execution.detail.meta.combine;
import beman.execution.detail.sender;
import beman.execution.detail.sender_adaptor_closure;
import beman.execution.detail.sends_stopped;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.value_types_of_t;
import beman.execution.detail.variant_or_empty;
#else
#include <beman/execution/detail/child_type.hpp>
#include <beman/execution/detail/completion_signatures_for.hpp>
#include <beman/execution/detail/decayed_tuple.hpp>
#include <beman/execution/detail/default_impls.hpp>
#include <beman/execution/detail/dependent_sender.hpp>
#include <beman/execution/detail/dependent_sender_error.hpp>
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/env_of_t.hpp>
#include <beman/execution/detail/error_types_of_t.hpp>
#include <beman/execution/detail/impls_for.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/meta_combine.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/sender_adaptor_closure.hpp>
#include <beman/execution/detail/sends_stopped.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/value_types_of_t.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct into_variant_t : ::beman::execution::sender_adaptor_closure<into_variant_t> {
    template <::beman::execution::sender Sender>
    auto operator()(Sender&& sender) const {
        return ::beman::execution::detail::make_sender(*this, {}, ::std::forward<Sender>(sender));
    }

    auto operator()() const noexcept { return ::beman::execution::detail::make_sender_adaptor(*this); }

  private:
    template <typename... E>
    using make_error_types = ::beman::execution::completion_signatures<::beman::execution::set_error_t(E)...>;

  private:
    template <typename, typename...>
    struct get_signatures;
    template <typename Sender>
    struct get_signatures<Sender> : get_signatures<Sender, ::beman::execution::env<>> {};
    template <::beman::execution::sender Child, typename State, typename Env>
    struct get_signatures<
        ::beman::execution::detail::basic_sender<::beman::execution::detail::into_variant_t, State, Child>,
        Env> {

        static consteval auto get() {
            using variant_type = ::beman::execution::value_types_of_t<Child, Env>;
            using value_types  = ::std::conditional_t<
                ::std::same_as<variant_type, ::beman::execution::detail::empty_variant>,
                ::beman::execution::completion_signatures<>,
                ::beman::execution::completion_signatures<::beman::execution::set_value_t(variant_type)>>;

            using error_types = ::beman::execution::error_types_of_t<Child, Env, make_error_types>;
            using stopped_types =
                ::std::conditional_t<::beman::execution::sends_stopped<Child, Env>,
                                     ::beman::execution::completion_signatures<::beman::execution::set_stopped_t()>,
                                     ::beman::execution::completion_signatures<>>;
            using type = ::beman::execution::detail::meta::
                combine<value_types, ::beman::execution::detail::meta::combine<error_types, stopped_types>>;
            return type{};
        }
    };

  public:
    template <::beman::execution::sender Sender, typename... Env>
    static consteval auto get_completion_signatures() {
        return get_signatures<::std::remove_cvref_t<Sender>, Env...>::get();
    }
    struct impls_for : ::beman::execution::detail::default_impls {
        struct get_state_impl {
            template <typename Sender, typename Receiver>
            auto operator()(Sender&&, Receiver&&) const noexcept -> ::std::type_identity<
                ::beman::execution::value_types_of_t<::beman::execution::detail::child_type<Sender>,
                                                     ::beman::execution::env_of_t<Receiver>>> {
                return {};
            }
        };
        static constexpr auto get_state{get_state_impl{}};
        struct complete_impl {
            template <typename State, typename Tag, typename... Args>
            auto operator()(auto, State, auto& receiver, Tag, Args&&... args) const noexcept -> void {
                if constexpr (::std::same_as<Tag, ::beman::execution::set_value_t>) {
                    using variant_type = typename State::type;
                    using tuple_type   = ::beman::execution::detail::decayed_tuple<Args...>;
                    if constexpr (std::same_as<variant_type, ::beman::execution::detail::empty_variant>) {
                        static_assert(sizeof...(Args) == 0);
                        BEMAN_EXECUTION_TRY_EVAL(receiver, ::beman::execution::set_value(std::move(receiver)));
                    } else {
                        BEMAN_EXECUTION_TRY_EVAL(
                            receiver,
                            ::beman::execution::set_value(::std::move(receiver),
                                                          variant_type(tuple_type{::std::forward<Args>(args)...})));
                    }
                } else {
                    Tag()(::std::move(receiver), ::std::forward<Args>(args)...);
                }
            }
        };
        static constexpr auto complete{complete_impl{}};
    };
};

} // namespace beman::execution::detail

namespace beman::execution {
using into_variant_t = ::beman::execution::detail::into_variant_t;
inline constexpr into_variant_t into_variant{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_INTO_VARIANT
