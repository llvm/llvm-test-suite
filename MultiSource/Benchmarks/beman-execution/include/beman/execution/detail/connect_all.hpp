// include/beman/execution/detail/connect_all.hpp                   -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_CONNECT_ALL
#define INCLUDED_BEMAN_EXECUTION_DETAIL_CONNECT_ALL

#include <beman/execution/detail/common.hpp>
#include <beman/execution/detail/suppress_push.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <cstddef>
#include <tuple>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_receiver;
import beman.execution.detail.basic_state;
import beman.execution.detail.connect;
import beman.execution.detail.connect_result_t;
import beman.execution.detail.forward_like;
import beman.execution.detail.product_type;
import beman.execution.detail.sender_decompose;
#else
#include <beman/execution/detail/basic_receiver.hpp>
#include <beman/execution/detail/basic_state.hpp>
#include <beman/execution/detail/connect.hpp>
#include <beman/execution/detail/connect_result_t.hpp>
#include <beman/execution/detail/forward_like.hpp>
#include <beman/execution/detail/product_type.hpp>
#include <beman/execution/detail/sender_decompose.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename T>
inline constexpr ::std::size_t get_tuple_size() {
    using type = ::std::remove_cvref_t<T>;
    if constexpr (requires { type::size(); })
        return type::size();
    else
        return std::tuple_size_v<type>;
}
/*!
 * \brief A helper types whose call operator connects all children of a basic_sender
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
struct connect_all_t {
  private:
    template <typename Fun, typename Tuple, ::std::size_t... I>
    static auto apply_with_index_helper(::std::index_sequence<I...> seq, Fun&& fun, Tuple&& tuple) noexcept(noexcept(
        ::std::forward<Fun>(fun)(seq, ::beman::execution::detail::forward_like<Tuple>(::std::get<I>(tuple))...)))
        -> decltype(auto) {
        return ::std::forward<Fun>(fun)(seq, ::beman::execution::detail::forward_like<Tuple>(::std::get<I>(tuple))...);
    }
    template <typename Fun, typename Tuple>
    static auto apply_with_index(Fun&& fun, Tuple&& tuple) noexcept(noexcept(
        apply_with_index_helper(::std::make_index_sequence<::beman::execution::detail::get_tuple_size<Tuple>()>{},
                                ::std::forward<Fun>(fun),
                                ::std::forward<Tuple>(tuple)))) -> decltype(auto) {
        return apply_with_index_helper(
            ::std::make_index_sequence<::beman::execution::detail::get_tuple_size<Tuple>()>{},
            ::std::forward<Fun>(fun),
            ::std::forward<Tuple>(tuple));
    }

    template <::std::size_t Start, typename Fun, typename Tuple, ::std::size_t... I>
    static auto sub_apply_with_index_helper(::std::index_sequence<I...> seq, Fun&& fun, Tuple&& tuple) noexcept(
        noexcept(::std::forward<Fun>(fun)(
            seq, ::beman::execution::detail::forward_like<Tuple>(tuple.template get<I + Start>())...)))
        -> decltype(auto) {
        return ::std::forward<Fun>(fun)(
            seq, ::beman::execution::detail::forward_like<Tuple>(tuple.template get<I + Start>())...);
    }
    template <::std::size_t Start, typename Fun, typename Tuple>
        requires requires { ::std::declval<Tuple>().size(); }
    static auto sub_apply_with_index(Fun&& fun, Tuple&& tuple) noexcept(noexcept(sub_apply_with_index_helper<Start>(
        ::std::make_index_sequence<::beman::execution::detail::get_tuple_size<Tuple>() - Start>{},
        ::std::forward<Fun>(fun),
        ::std::forward<Tuple>(tuple)))) -> decltype(auto) {
        return sub_apply_with_index_helper<Start>(
            ::std::make_index_sequence<::beman::execution::detail::get_tuple_size<Tuple>() - Start>{},
            ::std::forward<Fun>(fun),
            ::std::forward<Tuple>(tuple));
    }
    template <::std::size_t Start, typename Fun, typename Tuple>
        requires(not requires { ::std::declval<Tuple>().size(); })
    static auto
    sub_apply_with_index(Fun&& fun,
                         Tuple&&) noexcept(noexcept(::std::forward<Fun>(fun)(::std::make_index_sequence<0u>{}))) {
        return ::std::forward<Fun>(fun)(::std::make_index_sequence<0u>{});
    }

    template <typename Sender, typename Receiver>
    struct connect_helper {
        ::beman::execution::detail::basic_state<Sender, Receiver>* op;

        template <::std::size_t... J, typename... C>
        auto operator()(::std::index_sequence<J...>, C&&... c) noexcept(
            (noexcept(::beman::execution::connect(
                 ::beman::execution::detail::forward_like<Sender>(c),
                 ::beman::execution::detail::
                     basic_receiver<Sender, Receiver, ::std::integral_constant<::std::size_t, J>>{this->op})) &&
             ... && true)) -> decltype(auto) {
            return ::beman::execution::detail::product_type{::beman::execution::connect(
                ::beman::execution::detail::forward_like<Sender>(c),
                ::beman::execution::detail::
                    basic_receiver<Sender, Receiver, ::std::integral_constant<::std::size_t, J>>{this->op})...};
        }
    };

    static auto use(auto&&...) {}

  public:
    //-dk:TODO is the S parameter deviating from the spec?
    template <typename Sender, typename S, typename Receiver, ::std::size_t... I>
        requires requires(Sender&& s) {
            s.size();
            s.template get<0>();
        }
    auto operator()(::beman::execution::detail::basic_state<Sender, Receiver>* op,
                    S&&                                                        sender,
                    ::std::index_sequence<I...>) const
        noexcept(noexcept(sub_apply_with_index<2>(connect_helper<Sender, Receiver>{op}, ::std::forward<S>(sender))))
            -> decltype(auto) {
        return sub_apply_with_index<2>(connect_helper<Sender, Receiver>{op}, ::std::forward<S>(sender));
    }
    template <typename Sender, typename S, typename Receiver, ::std::size_t... I>
    auto operator()(::beman::execution::detail::basic_state<Sender, Receiver>* op,
                    S&&                                                        sender,
                    ::std::index_sequence<I...>) const
        noexcept(noexcept(apply_with_index(
            connect_helper<Sender, Receiver>{op},
            ::beman::execution::detail::get_sender_data(::std::forward<S>(sender)).children))) -> decltype(auto) {
        return apply_with_index(connect_helper<Sender, Receiver>{op},
                                ::beman::execution::detail::get_sender_data(::std::forward<S>(sender)).children);
    }
};

/*!
 * \brief A helper object of type connect_all_t
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
//-dk:TODO the export below shouldn't be needed, but MSVC++ seems to require it (2026-02-01)
inline constexpr connect_all_t connect_all{}; //-dk:TODO detail export
} // namespace beman::execution::detail

#include <beman/execution/detail/suppress_pop.hpp>

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_CONNECT_ALL
