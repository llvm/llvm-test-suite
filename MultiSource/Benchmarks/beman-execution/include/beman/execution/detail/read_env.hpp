// include/beman/execution/detail/read_env.hpp                      -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_READ_ENV
#define INCLUDED_BEMAN_EXECUTION_DETAIL_READ_ENV

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <exception>
#include <stdexcept>
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_sender;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.completion_signatures_for;
import beman.execution.detail.data_type;
import beman.execution.detail.default_impls;
import beman.execution.detail.env_of_t;
import beman.execution.detail.get_env;
import beman.execution.detail.impls_for;
import beman.execution.detail.make_sender;
import beman.execution.detail.sender;
import beman.execution.detail.set_error;
import beman.execution.detail.set_value;
#else
#include <beman/execution/detail/completion_signatures.hpp>
#include <beman/execution/detail/completion_signatures_for.hpp>
#include <beman/execution/detail/data_type.hpp>
#include <beman/execution/detail/default_impls.hpp>
#include <beman/execution/detail/env_of_t.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/impls_for.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_value.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct read_env_t {
    auto operator()(auto&& query) const { return ::beman::execution::detail::make_sender(*this, query); }
    template <::beman::execution::sender Sender>
    static auto affine(Sender&& sndr) noexcept {
        return ::std::forward<Sender>(sndr);
    }

  private:
    template <typename, typename>
    struct get_signatures;
    template <typename Query, typename Env>
        requires std::invocable<Query, const Env&>
    struct get_signatures<::beman::execution::detail::basic_sender<::beman::execution::detail::read_env_t, Query>,
                          Env> {
        using set_value_type = ::beman::execution::set_value_t(
            decltype(::std::declval<Query>()(::std::as_const(::std::declval<::std::add_lvalue_reference_t<Env>>()))));
        using set_error_type = ::beman::execution::set_error_t(::std::exception_ptr);
        using type = ::std::conditional_t<noexcept(::std::declval<Query>()(::std::declval<const Env&>())),
                                          ::beman::execution::completion_signatures<set_value_type>,
                                          ::beman::execution::completion_signatures<set_value_type, set_error_type>>;
    };

  public:
    template <typename Sender, typename Env>
        requires requires { typename get_signatures<::std::remove_cvref_t<Sender>, Env>::type; }
    static consteval auto get_completion_signatures() {
        return typename get_signatures<::std::remove_cvref_t<Sender>, Env>::type{};
    }
    struct impls_for : ::beman::execution::detail::default_impls {
        struct start_impl {
            template <typename Query, typename Receiver>
            auto operator()(Query query, Receiver& receiver) const noexcept -> void {
                try {
                    auto env{::beman::execution::get_env(receiver)};
                    ::beman::execution::set_value(::std::move(receiver), query(env));
                } catch (...) {
                    if constexpr (!std::is_nothrow_invocable_v<Query, ::beman::execution::env_of_t<Receiver>>) {
                        ::beman::execution::set_error(::std::move(receiver), ::std::current_exception());
                    }
                }
            }
        };
        static constexpr start_impl start{};

        template <typename Sndr, typename Env>
        static consteval void check_types() {
            using query_type = ::std::decay_t<::beman::execution::detail::data_type<Sndr>>;
            if constexpr (!requires(const Env& env) { query_type()(env); }) {
                throw ::std::logic_error("query is not invocable with the environment of the receiver");
            } else if constexpr (::std::same_as<::std::invoke_result_t<query_type, const Env&>, void>) {
                throw ::std::logic_error("query returns void with the environment of the receiver");
            }
        }
    };
};

} // namespace beman::execution::detail

namespace beman::execution {
using read_env_t = beman::execution::detail::read_env_t;
inline constexpr read_env_t read_env{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_READ_ENV
