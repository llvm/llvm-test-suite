// include/beman/execution/detail/when_all_with_variant.hpp         -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_WHEN_ALL_WITH_VARIANT
#define INCLUDED_BEMAN_EXECUTION_DETAIL_WHEN_ALL_WITH_VARIANT

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_sender;
import beman.execution.detail.common_domain;
import beman.execution.detail.compl_domain;
import beman.execution.detail.default_impls;
import beman.execution.detail.env;
import beman.execution.detail.forward_like;
import beman.execution.detail.get_completion_domain;
import beman.execution.detail.get_completion_signatures;
import beman.execution.detail.into_variant;
import beman.execution.detail.make_sender;
import beman.execution.detail.sender;
import beman.execution.detail.sender_for;
import beman.execution.detail.set_value;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.when_all;
#else
#include <beman/execution/detail/basic_sender.hpp>
#include <beman/execution/detail/common_domain.hpp>
#include <beman/execution/detail/compl_domain.hpp>
#include <beman/execution/detail/default_impls.hpp>
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/forward_like.hpp>
#include <beman/execution/detail/get_completion_domain.hpp>
#include <beman/execution/detail/get_completion_signatures.hpp>
#include <beman/execution/detail/into_variant.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/sender_for.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/when_all.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct when_all_with_variant_t {
    template <::beman::execution::detail::sender_for<when_all_with_variant_t> Sender, typename Env>
    auto transform_sender(::beman::execution::set_value_t, Sender&& sender, const Env&) const noexcept {
        return ::std::forward<Sender>(sender).apply([](auto&&, auto&&, auto&&... child) {
            return ::beman::execution::when_all(
                ::beman::execution::into_variant(::beman::execution::detail::forward_like<Sender>(child))...);
        });
    }

    template <::beman::execution::sender... Sender>
    auto operator()(Sender&&... sender) const {
        return ::beman::execution::detail::make_sender(*this, {}, ::std::forward<Sender>(sender)...);
    }

  private:
    template <typename, typename...>
    struct get_signatures;
    template <typename Sender>
    struct get_signatures<Sender> : get_signatures<Sender, ::beman::execution::env<>> {};
    template <typename Data, typename Env, typename... Children>
    struct get_signatures<::beman::execution::detail::
                              basic_sender<::beman::execution::detail::when_all_with_variant_t, Data, Children...>,
                          Env> {

        static consteval auto get() {
            using sndr_t = decltype(::beman::execution::when_all(
                ::beman::execution::into_variant(::std::declval<Children>())...));
            return ::beman::execution::get_completion_signatures<sndr_t, Env>();
        }
    };

    template <typename... Children>
    struct attrs {
        template <typename Tag, typename... Env>
        using child_domain_t =
            ::beman::execution::detail::common_domain_t<::beman::execution::detail::compl_domain_of_t<
                Tag,
                ::std::invoke_result_t<::beman::execution::into_variant_t, Children>,
                Env...>...>;

        template <typename... Env>
            requires requires { typename child_domain_t<::beman::execution::set_value_t, Env...>; }
        static auto query(::beman::execution::get_completion_domain_t<::beman::execution::set_value_t>,
                          const Env&...) noexcept -> child_domain_t<::beman::execution::set_value_t, Env...> {
            return {};
        }

        template <typename... Env>
            requires requires {
                typename ::beman::execution::detail::common_domain_t<
                    child_domain_t<::beman::execution::set_value_t, Env...>,
                    child_domain_t<::beman::execution::set_error_t, Env...>,
                    child_domain_t<::beman::execution::set_stopped_t, Env...>>;
            }
        static auto query(::beman::execution::get_completion_domain_t<::beman::execution::set_error_t>,
                          const Env&...) noexcept
            -> ::beman::execution::detail::common_domain_t<child_domain_t<::beman::execution::set_value_t, Env...>,
                                                           child_domain_t<::beman::execution::set_error_t, Env...>,
                                                           child_domain_t<::beman::execution::set_stopped_t, Env...>> {
            return {};
        }

        template <typename... Env>
            requires requires {
                typename ::beman::execution::detail::common_domain_t<
                    child_domain_t<::beman::execution::set_value_t, Env...>,
                    child_domain_t<::beman::execution::set_stopped_t, Env...>>;
            }
        static auto query(::beman::execution::get_completion_domain_t<::beman::execution::set_stopped_t>,
                          const Env&...) noexcept
            -> ::beman::execution::detail::common_domain_t<child_domain_t<::beman::execution::set_value_t, Env...>,
                                                           child_domain_t<::beman::execution::set_stopped_t, Env...>> {
            return {};
        }
    };

  public:
    template <::beman::execution::sender Sender, typename... Env>
    static consteval auto get_completion_signatures() {
        return get_signatures<::std::remove_cvref_t<Sender>, Env...>::get();
    }

    struct impls_for : ::beman::execution::detail::default_impls {
        struct get_attrs_impl {
            template <typename... Children>
            auto operator()(const auto&, const Children&...) const noexcept {
                return attrs<Children...>{};
            }
        };
        static constexpr auto get_attrs{get_attrs_impl{}};
    };
};
} // namespace beman::execution::detail

namespace beman::execution {
using when_all_with_variant_t = ::beman::execution::detail::when_all_with_variant_t;
inline constexpr ::beman::execution::when_all_with_variant_t when_all_with_variant{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_WHEN_ALL_WITH_VARIANT
