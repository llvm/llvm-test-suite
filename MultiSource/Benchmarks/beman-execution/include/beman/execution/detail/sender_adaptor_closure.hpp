// include/beman/execution/detail/sender_adaptor_closure.hpp        -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_ADAPTOR_CLOSURE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_ADAPTOR_CLOSURE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.sender;
import beman.execution.detail.call_result_t;
import beman.execution.detail.callable;
import beman.execution.detail.class_type;
import beman.execution.detail.forward_like;
import beman.execution.detail.nothrow_callable;
import beman.execution.detail.movable_value;
import beman.execution.detail.product_type;

#else
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/class_type.hpp>
#include <beman/execution/detail/call_result_t.hpp>
#include <beman/execution/detail/callable.hpp>
#include <beman/execution/detail/forward_like.hpp>
#include <beman/execution/detail/nothrow_callable.hpp>
#include <beman/execution/detail/movable_value.hpp>
#include <beman/execution/detail/product_type.hpp>

#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail::pipeable {
/*!
 * \brief ADL anchor tag type inherited by sender_adaptor_closure.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
struct closure_t {};
} // namespace beman::execution::detail::pipeable

namespace beman::execution {
/*!
 * \brief CRTP base class for pipeable sender adaptor closure objects.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
template <detail::class_type D>
struct sender_adaptor_closure : detail::pipeable::closure_t {};

} // namespace beman::execution

namespace beman::execution::detail {

/*!
 * \brief Helper to detect a unique sender_adaptor_closure base class.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <class T>
auto get_sender_adaptor_closure_base(const sender_adaptor_closure<T>&) -> T;

/*!
 * \brief Checks that T has exactly one sender_adaptor_closure base where U == decay_t<T>.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <class T>
concept has_unique_sender_adaptor_closure_base = requires(const T& s) {
    { get_sender_adaptor_closure_base(s) } -> std::same_as<std::decay_t<T>>;
};

/*!
 * \brief Determine if a type is a pipeable sender adaptor closure.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <class T>
concept is_sender_adaptor_closure =
    std::derived_from<std::decay_t<T>, sender_adaptor_closure<std::decay_t<T>>> and
    has_unique_sender_adaptor_closure_base<std::decay_t<T>> and (not sender<std::decay_t<T>>);

/*!
 * \brief Checks that Closure is a pipeable sender adaptor closure invocable with Sender.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <class Closure, class Sender>
concept sender_adaptor_closure_for =
    is_sender_adaptor_closure<Closure> and sender<Sender> and requires(Closure&& closure, Sender&& sndr) {
        { std::forward<Closure>(closure)(std::forward<Sender>(sndr)) } -> sender;
    };

/*!
 * \brief Utility alias to copy cv-ref qualifiers from one type onto another.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <class As, class Reqs>
using apply_cvref_t = decltype(::beman::execution::detail::forward_like<As>(std::declval<Reqs&>()));

/*!
 * \brief Perfect forwarding call wrapper produced by closure-closure composition via operator|.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <class Inner, class Outer>
struct composed_sender_adaptor_closure : sender_adaptor_closure<composed_sender_adaptor_closure<Inner, Outer>> {
    [[no_unique_address]] Inner inner;
    [[no_unique_address]] Outer outer;

    template <class Self, sender Sender>
        requires callable<apply_cvref_t<Self, Inner>, Sender> and
                 callable<apply_cvref_t<Self, Outer>, call_result_t<apply_cvref_t<Self, Inner>, Sender>>
    constexpr auto operator()(this Self&& self, Sender&& sndr) noexcept(
        nothrow_callable<apply_cvref_t<Self, Inner>, Sender> and
        nothrow_callable<apply_cvref_t<Self, Outer>, call_result_t<apply_cvref_t<Self, Inner>, Sender>>)
        -> call_result_t<apply_cvref_t<Self, Outer>, call_result_t<apply_cvref_t<Self, Inner>, Sender>> {
        return ::std::forward<Self>(self).outer(::std::forward<Self>(self).inner(std::forward<Sender>(sndr)));
    }
};

// ctad
template <class Inner, class Outer>
composed_sender_adaptor_closure(Inner&&, Outer&&)
    -> composed_sender_adaptor_closure<std::decay_t<Inner>, std::decay_t<Outer>>;

/*!
 * \brief Perfect forwarding call wrapper produced by adaptor(args...) for multi-argument adaptors.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <class Adaptor, movable_value... BoundArgs>
struct bound_sender_adaptor_closure : detail::product_type<std::decay_t<BoundArgs>...>,
                                      sender_adaptor_closure<bound_sender_adaptor_closure<Adaptor, BoundArgs...>> {

    [[no_unique_address]] Adaptor adaptor;

    template <class Self, sender Sender>
        requires callable<apply_cvref_t<Self, Adaptor>, Sender, apply_cvref_t<Self, BoundArgs>...>
    constexpr auto operator()(this Self&& self, Sender&& sndr) noexcept(
        nothrow_callable<apply_cvref_t<Self, Adaptor>, Sender, apply_cvref_t<Self, BoundArgs>...>)
        -> call_result_t<apply_cvref_t<Self, Adaptor>, Sender, apply_cvref_t<Self, BoundArgs>...> {
        return self.apply([&]<typename... CvBoundArgs>(CvBoundArgs&&... bound_args) {
            return ::std::forward<Self>(self).adaptor(::std::forward<Sender>(sndr),
                                                      ::std::forward<CvBoundArgs>(bound_args)...);
        });
    }
};

template <class Tag, class... Args>
bound_sender_adaptor_closure(Tag&&, Args&&...)
    -> bound_sender_adaptor_closure<std::decay_t<Tag>, std::decay_t<Args>...>;

/*!
 * \brief Factory function producing a bound_sender_adaptor_closure from an adaptor and arguments.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 * \internal
 */
template <class Tag, class... Args>
    requires(movable_value<Args> && ...)
constexpr auto
make_sender_adaptor(Tag&& tag,
                    Args&&... args) noexcept(std::is_nothrow_constructible_v<std::decay_t<Tag>, Tag> and
                                             (std::is_nothrow_constructible_v<std::decay_t<Args>, Args> and ...))
    -> bound_sender_adaptor_closure<std::decay_t<Tag>, std::decay_t<Args>...> {
    return {{std::forward<Args>(args)...}, {}, tag};
}
} // namespace beman::execution::detail

namespace beman::execution::detail::pipeable {

/*!
 * \brief Pipe operator connecting a sender to a pipeable sender adaptor closure.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
template <sender Sender, detail::sender_adaptor_closure_for<Sender> Closure>
constexpr auto operator|(Sender&& sndr, Closure&& cl) noexcept(detail::nothrow_callable<Closure, Sender>)
    -> detail::call_result_t<Closure, Sender> {
    return std::forward<Closure>(cl)(std::forward<Sender>(sndr));
}

/*!
 * \brief Pipe operator composing two pipeable sender adaptor closure objects.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
template <detail::is_sender_adaptor_closure Inner, detail::is_sender_adaptor_closure Outer>
    requires std::constructible_from<std::decay_t<Inner>, Inner> && std::constructible_from<std::decay_t<Outer>, Outer>
constexpr auto operator|(Inner&& inner,
                         Outer&& outer) noexcept(std::is_nothrow_constructible_v<std::decay_t<Inner>, Inner> &&
                                                 std::is_nothrow_constructible_v<std::decay_t<Outer>, Outer>)
    -> detail::composed_sender_adaptor_closure<std::decay_t<Inner>, std::decay_t<Outer>> {
    return {{}, std::forward<Inner>(inner), std::forward<Outer>(outer)};
}

} // namespace beman::execution::detail::pipeable

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_ADAPTOR_CLOSURE
