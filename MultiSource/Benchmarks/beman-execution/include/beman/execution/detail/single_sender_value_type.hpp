// include/beman/execution/detail/single_sender_value_type.hpp      -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SINGLE_SENDER_VALUE_TYPE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SINGLE_SENDER_VALUE_TYPE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <tuple>
#include <type_traits>
#include <variant>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.decayed_tuple;
import beman.execution.detail.value_types_of_t;
#else
#include <beman/execution/detail/decayed_tuple.hpp>
#include <beman/execution/detail/value_types_of_t.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Sender, typename Env>
struct single_sender_value_type_helper;

template <typename Sender, typename Env>
    requires requires {
        typename ::beman::execution::value_types_of_t<Sender, Env, ::std::decay_t, ::std::type_identity_t>;
    }
struct single_sender_value_type_helper<Sender, Env> {
    using type = ::beman::execution::value_types_of_t<Sender, Env, ::std::decay_t, ::std::type_identity_t>;
};

template <typename Sender, typename Env>
    requires ::std::same_as<::std::variant<::std::tuple<>>,
                            ::beman::execution::value_types_of_t<Sender, Env, ::std::tuple, ::std::variant>> ||
             ::std::same_as<::std::variant<>,
                            ::beman::execution::value_types_of_t<Sender, Env, ::std::tuple, ::std::variant>>
struct single_sender_value_type_helper<Sender, Env> {
    using type = void;
};

template <typename Sender, typename Env>
    requires(not requires {
                typename ::beman::execution::value_types_of_t<Sender, Env, ::std::decay_t, ::std::type_identity_t>;
            }) &&
            (!::std::same_as<::std::variant<::std::tuple<>>,
                             ::beman::execution::value_types_of_t<Sender, Env, ::std::tuple, ::std::variant>>) &&
            requires {
                typename ::beman::execution::
                    value_types_of_t<Sender, Env, ::beman::execution::detail::decayed_tuple, ::std::type_identity_t>;
            }
struct single_sender_value_type_helper<Sender, Env> {
    using type = ::beman::execution::
        value_types_of_t<Sender, Env, ::beman::execution::detail::decayed_tuple, ::std::type_identity_t>;
};

template <typename Sender, typename Env>
using single_sender_value_type = typename single_sender_value_type_helper<Sender, Env>::type;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SINGLE_SENDER_VALUE_TYPE
