// include/beman/execution/detail/basic_sender.hpp                  -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_BASIC_SENDER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_BASIC_SENDER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <tuple>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_operation;
import beman.execution.detail.completion_signatures_for;
import beman.execution.detail.connect;
import beman.execution.detail.connect_all;
import beman.execution.detail.decays_to;
import beman.execution.detail.dependent_sender;
import beman.execution.detail.get_completion_signatures;
import beman.execution.detail.impls_for;
import beman.execution.detail.product_type;
import beman.execution.detail.receiver;
import beman.execution.detail.sender;
import beman.execution.detail.sender_decompose;
#else
#include <beman/execution/detail/basic_operation.hpp>
#include <beman/execution/detail/completion_signatures_for.hpp>
#include <beman/execution/detail/connect.hpp>
#include <beman/execution/detail/decays_to.hpp>
#include <beman/execution/detail/dependent_sender.hpp>
#include <beman/execution/detail/get_completion_signatures.hpp>
#include <beman/execution/detail/impls_for.hpp>
#include <beman/execution/detail/product_type.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/sender_decompose.hpp>
#endif

#include <beman/execution/detail/suppress_push.hpp>

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <::std::size_t Start, typename Fun, typename Tuple, ::std::size_t... I>
constexpr auto sub_apply_helper(Fun&& fun, Tuple&& tuple, ::std::index_sequence<I...>) -> decltype(auto) {
    // NOLINTNEXTLINE(bugprone-use-after-move,hicpp-invalid-access-moved)
    return ::std::forward<Fun>(fun)(::std::forward<Tuple>(tuple).template get<I + Start>()...);
}
struct sub_apply_t {
    template <::std::size_t Start, typename Fun, typename Tuple>
    constexpr auto at(Fun&& fun, Tuple&& tuple) const -> decltype(auto) {
        constexpr ::std::size_t TSize{::std::remove_cvref_t<Tuple>::size()};
        static_assert(Start <= TSize);
        return sub_apply_helper<Start>(
            ::std::forward<Fun>(fun), ::std::forward<Tuple>(tuple), ::std::make_index_sequence<TSize - Start>());
    }
};
inline constexpr sub_apply_t sub_apply{};

/*!
 * \brief Class template used to factor out common sender implementation for library senders.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <typename Tag, typename Data, typename... Child>
struct basic_sender : ::beman::execution::detail::product_type<Tag, Data, Child...> {
    //-dk:TODO friend struct ::beman::execution::detail::connect_t;
    using sender_concept      = ::beman::execution::sender_tag;
    using is_basic_sender_tag = void; //-dk:TODO need a better way to detect this is a basic sender
    using indices_for         = ::std::index_sequence_for<Child...>;
    static constexpr ::std::integral_constant<::std::size_t, sizeof...(Child) + 2> size{};

    auto get_env() const noexcept -> decltype(auto) {
        auto&& d{this->template get<1>()};
        return sub_apply.at<2>(
            [&d](auto&&... c) { return ::beman::execution::detail::get_impls_for<Tag>::get_attrs()(d, c...); }, *this);
    }

    template <typename Receiver>
        requires(!::beman::execution::receiver<Receiver>)
    auto connect(Receiver receiver) = BEMAN_EXECUTION_DELETE("the passed receiver doesn't model receiver");

    //-dk:TODO private:
#if __cpp_explicit_this_parameter < 302110L //-dk:TODO need to figure out how to use explicit this with forwarding
    template <::beman::execution::receiver Receiver>
    auto connect(Receiver receiver) & noexcept(
        noexcept(::beman::execution::detail::basic_operation<basic_sender&, Receiver>{*this, ::std::move(receiver)}))
        -> ::beman::execution::detail::basic_operation<basic_sender&, Receiver> {
        return {*this, ::std::move(receiver)};
    }
    template <::beman::execution::receiver Receiver>
    auto connect(Receiver receiver) const& noexcept(noexcept(
        ::beman::execution::detail::basic_operation<const basic_sender&, Receiver>{*this, ::std::move(receiver)}))
        -> ::beman::execution::detail::basic_operation<const basic_sender&, Receiver> {
        return {*this, ::std::move(receiver)};
    }
    template <::beman::execution::receiver Receiver>
    auto connect(Receiver receiver) && noexcept(
        noexcept(::beman::execution::detail::basic_operation<basic_sender, Receiver>{::std::move(*this),
                                                                                     ::std::move(receiver)}))
        -> ::beman::execution::detail::basic_operation<basic_sender, Receiver> {
        return {::std::move(*this), ::std::move(receiver)};
    }
#else
    template <::beman::execution::detail::decays_to<basic_sender> Self, ::beman::execution::receiver Receiver>
    auto
    connect(this Self&& self,
            Receiver receiver) noexcept(noexcept(::beman::execution::detail::basic_operation<basic_sender, Receiver>{
        ::std::forward<Self>(self), ::std::move(receiver)}))
        -> ::beman::execution::detail::basic_operation<Self, Receiver> {
        return {::std::forward<Self>(self), ::std::move(receiver)};
    }
#endif
    template <::beman::execution::detail::decays_to<basic_sender> Self, typename... Env>
        requires((sizeof...(Env) == 1) || (... && !::beman::execution::dependent_sender<Child>)) &&
                requires { Tag::template get_completion_signatures<Self, Env...>(); }
    static consteval auto
    get_completion_signatures() noexcept(noexcept(Tag::template get_completion_signatures<Self, Env...>())) {
        return Tag::template get_completion_signatures<Self, Env...>();
    }

    template <::beman::execution::detail::decays_to<basic_sender> Self>
        requires requires { Tag().affine(::std::declval<Self>()); }
    auto affine(this Self&& self) noexcept(noexcept(Tag().affine(::std::declval<Self>()))) -> decltype(auto) {
        return Tag().affine(::std::forward<Self>(self));
    }
};
} // namespace beman::execution::detail

#ifndef BEMAN_HAS_MODULES
namespace std {
template <typename Tag, typename Data, typename... Child>
struct tuple_size<::beman::execution::detail::basic_sender<Tag, Data, Child...>>
    : ::std::integral_constant<std::size_t, 2u + sizeof...(Child)> {};

template <::std::size_t I, typename... T>
struct tuple_element<I, ::beman::execution::detail::basic_sender<T...>> {
    using type =
        ::std::decay_t<decltype(::std::declval<::beman::execution::detail::basic_sender<T...>>().template get<I>())>;
};
} // namespace std
#endif

// ----------------------------------------------------------------------------

#include <beman/execution/detail/suppress_pop.hpp>

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_BASIC_SENDER
