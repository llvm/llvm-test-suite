// include/beman/execution/detail/get_completion_signatures.hpp     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_GET_COMPLETION_SIGNATURES
#define INCLUDED_BEMAN_EXECUTION_DETAIL_GET_COMPLETION_SIGNATURES

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
import beman.execution.detail.await_result_type;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.dependent_sender_error;
import beman.execution.detail.env_promise;
import beman.execution.detail.is_awaitable;
import beman.execution.detail.is_constant;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.transform_sender;
import beman.execution.detail.valid_completion_signatures;
#else
#include <beman/execution/detail/await_result_type.hpp>
#include <beman/execution/detail/completion_signatures.hpp>
#include <beman/execution/detail/dependent_sender_error.hpp>
#include <beman/execution/detail/env_promise.hpp>
#include <beman/execution/detail/is_awaitable.hpp>
#include <beman/execution/detail/is_constant.hpp>
#include <beman/execution/detail/transform_sender.hpp>
#include <beman/execution/detail/valid_completion_signatures.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Sender, typename...>
struct get_completion_signatures_new_sender;

template <typename Sender>
struct get_completion_signatures_new_sender<Sender> {
    using type = Sender;
};

template <typename Sender, typename Env>
struct get_completion_signatures_new_sender<Sender, Env> {
    using type = decltype(::beman::execution::transform_sender(::std::declval<Sender>(), ::std::declval<Env>()));
};

template <typename Sender, typename... Env>
struct get_completion_signatures_error : std::exception {
    const char* what() const noexcept override { return "no get_completion_signatures<Sender, Env...> found"; }
};
} // namespace beman::execution::detail

namespace beman::execution {
template <typename Sender, typename... Env>
consteval auto get_completion_signatures() -> ::beman::execution::detail::valid_completion_signatures auto {
    using new_sender_type =
        typename ::beman::execution::detail::get_completion_signatures_new_sender<Sender, Env...>::type;
    auto get_complsigs{[]<typename Sndr, typename... E>() {
        if constexpr (requires {
                          {
                              ::std::remove_cvref_t<Sndr>::template get_completion_signatures<Sndr, E...>()
                          } -> ::beman::execution::detail::valid_completion_signatures;
                      }) {
            if constexpr (::beman::execution::detail::is_constant<
                              ::std::remove_cvref_t<Sndr>::template get_completion_signatures<Sndr, E...>()>) {
                return ::std::remove_cvref_t<Sndr>::template get_completion_signatures<Sndr, E...>();
            }
        } else if constexpr (requires {
                                 {
                                     ::std::remove_cvref_t<Sndr>::get_completion_signatures()
                                 } -> ::beman::execution::detail::valid_completion_signatures;
                             }) {
            if constexpr (::beman::execution::detail::is_constant<
                              ::std::remove_cvref_t<Sndr>::get_completion_signatures()>) {
                return ::std::remove_cvref_t<Sndr>::get_completion_signatures();
            }
        }
    }};
    if constexpr (requires {
                      {
                          get_complsigs.template operator()<new_sender_type, Env...>()
                      } -> ::beman::execution::detail::valid_completion_signatures;
                  })
        return get_complsigs.template operator()<new_sender_type, Env...>();
    else if constexpr (requires {
                           {
                               get_complsigs.template operator()<new_sender_type>()
                           } -> ::beman::execution::detail::valid_completion_signatures;
                       })
        return get_complsigs.template operator()<new_sender_type>();
    else if constexpr (::beman::execution::detail::is_awaitable<new_sender_type,
                                                                ::beman::execution::detail::env_promise<Env>...>) {
        using result_type = ::beman::execution::detail::
            await_result_type<new_sender_type, ::beman::execution::detail::env_promise<::std::tuple<Env...>>>;
        if constexpr (::std::same_as<void, result_type>) {
            return ::beman::execution::completion_signatures<::beman::execution::set_value_t(),
                                                             ::beman::execution::set_error_t(::std::exception_ptr),
                                                             ::beman::execution::set_stopped_t()>{};
        } else {
            return ::beman::execution::completion_signatures<::beman::execution::set_value_t(result_type),
                                                             ::beman::execution::set_error_t(::std::exception_ptr),
                                                             ::beman::execution::set_stopped_t()>{};
        }
    } else if constexpr (sizeof...(Env) == 0)
        return (throw ::beman::execution::detail::dependent_sender_error<Sender>(),
                ::beman::execution::completion_signatures<>{});
    else
        return (throw ::beman::execution::detail::get_completion_signatures_error<Sender, Env...>(),
                ::beman::execution::completion_signatures<>{});
}
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_GET_COMPLETION_SIGNATURES
