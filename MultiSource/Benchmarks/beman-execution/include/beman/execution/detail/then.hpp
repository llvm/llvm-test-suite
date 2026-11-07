// include/beman/execution/detail/then.hpp                          -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_THEN
#define INCLUDED_BEMAN_EXECUTION_DETAIL_THEN

#include <beman/execution/detail/common.hpp>
#include <beman/execution/detail/suppress_push.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <exception>
#include <functional>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_sender;
import beman.execution.detail.call_result_t;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.completion_signatures_for;
import beman.execution.detail.completion_signatures_of_t;
import beman.execution.detail.default_impls;
import beman.execution.detail.dependent_sender;
import beman.execution.detail.dependent_sender_error;
import beman.execution.detail.env;
import beman.execution.detail.impls_for;
import beman.execution.detail.make_sender;
import beman.execution.detail.meta.combine;
import beman.execution.detail.meta.transform;
import beman.execution.detail.meta.unique;
import beman.execution.detail.movable_value;
import beman.execution.detail.nested_sender_has_affine;
import beman.execution.detail.sender;
import beman.execution.detail.sender_adaptor_closure;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.transform_sender;
#else
#include <beman/execution/detail/call_result_t.hpp>
#include <beman/execution/detail/completion_signatures.hpp>
#include <beman/execution/detail/completion_signatures_for.hpp>
#include <beman/execution/detail/completion_signatures_of_t.hpp>
#include <beman/execution/detail/default_impls.hpp>
#include <beman/execution/detail/dependent_sender.hpp>
#include <beman/execution/detail/dependent_sender_error.hpp>
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/impls_for.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/meta_combine.hpp>
#include <beman/execution/detail/meta_transform.hpp>
#include <beman/execution/detail/meta_unique.hpp>
#include <beman/execution/detail/movable_value.hpp>
#include <beman/execution/detail/nested_sender_has_affine.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/sender_adaptor.hpp>
#include <beman/execution/detail/sender_adaptor_closure.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/transform_sender.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {

template <typename T>
struct then_set_value {
    using type = ::beman::execution::set_value_t(T);
};
template <>
struct then_set_value<void> {
    using type = ::beman::execution::set_value_t();
};

template <typename, typename, typename Completion>
struct then_transform {
    using type = Completion;
};

template <typename Fun, typename Completion, typename... T>
struct then_transform<Fun, Completion, Completion(T...)> {
    using type = typename ::beman::execution::detail::then_set_value<
        ::beman::execution::detail::call_result_t<Fun, T...>>::type;
};

template <typename Fun, typename Replace>
struct then_transform_t {
    template <typename Completion>
    using transform = typename ::beman::execution::detail::then_transform<Fun, Replace, Completion>::type;
};

template <typename, typename, typename>
struct then_exception_fun : ::std::false_type {};
template <typename Comp, typename Fun, typename... A>
struct then_exception_fun<Comp, Fun, Comp(A...)>
    : ::std::bool_constant<not noexcept(::std::declval<Fun>()(::std::declval<A>()...))> {};

template <typename, typename, typename>
struct then_exception : ::std::false_type {};
template <typename Comp, typename Fun, typename Completion, typename... Completions>
struct then_exception<Comp, Fun, ::beman::execution::completion_signatures<Completion, Completions...>> {
    static constexpr bool value{
        then_exception_fun<Comp, Fun, Completion>::value ||
        then_exception<Comp, Fun, ::beman::execution::completion_signatures<Completions...>>::value};
};

template <typename Completion>
struct then_t : ::beman::execution::sender_adaptor_closure<then_t<Completion>> {
    template <::beman::execution::detail::movable_value Fun>
    auto operator()(Fun&& fun) const noexcept(::std::is_nothrow_constructible_v<::std::remove_cvref_t<Fun>, Fun>) {
        return ::beman::execution::detail::make_sender_adaptor(*this, std::forward<decltype(fun)>(fun));
    }
    template <::beman::execution::sender Sender, ::beman::execution::detail::movable_value Fun>
    auto operator()(Sender&& sender, Fun&& fun) const
        noexcept(::std::is_nothrow_constructible_v<::std::remove_cvref_t<Sender>, Sender> &&
                 ::std::is_nothrow_constructible_v<::std::remove_cvref_t<Fun>, Fun>) {
        return ::beman::execution::detail::make_sender(
            *this, ::std::forward<Fun>(fun), ::std::forward<Sender>(sender));
    }
    template <::beman::execution::sender Sender>
        requires ::beman::execution::detail::nested_sender_has_affine<Sender>
    static auto affine(Sender&& sndr) noexcept {
        return ::std::forward<Sender>(sndr);
    }

  private:
    template <typename, typename...>
    struct get_signatures;
    template <typename Sender>
    struct get_signatures<Sender> : get_signatures<Sender, ::beman::execution::env<>> {};
    template <typename Comp, typename Fun, typename Child, typename Env>
    struct get_signatures<
        ::beman::execution::detail::basic_sender<::beman::execution::detail::then_t<Comp>, Fun, Child>,
        Env> {
        using type = ::beman::execution::detail::meta::unique<::beman::execution::detail::meta::combine<
            ::beman::execution::detail::meta::transform<
                ::beman::execution::detail::then_transform_t<Fun, Comp>::template transform,
                ::beman::execution::completion_signatures_of_t<Child, Env>>,
            ::std::conditional_t<
                ::beman::execution::detail::
                    then_exception<Comp, Fun, ::beman::execution::completion_signatures_of_t<Child, Env>>::value,
                ::beman::execution::completion_signatures<::beman::execution::set_error_t(::std::exception_ptr)>,
                ::beman::execution::completion_signatures<>>>>;
    };

  public:
    template <typename Sender, typename... Env>
    static consteval auto get_completion_signatures() {
        return typename get_signatures<std::remove_cvref_t<Sender>, Env...>::type{};
    }

    struct impls_for : ::beman::execution::detail::default_impls {
        // NOLINTBEGIN(bugprone-exception-escape)
        struct complete_impl {
            template <typename Tag, typename... Args>
            auto operator()(auto, auto& fun, auto& receiver, Tag, Args&&... args) const noexcept -> void {
                if constexpr (::std::same_as<Completion, Tag>) {
                    try {
                        auto invoke = [&] { return ::std::invoke(::std::move(fun), ::std::forward<Args>(args)...); };
                        if constexpr (::std::same_as<void, decltype(invoke())>) {
                            invoke();
                            ::beman::execution::set_value(::std::move(receiver));
                        } else {
                            ::beman::execution::set_value(::std::move(receiver), invoke());
                        }
                    } catch (...) {
                        if constexpr (not noexcept(::std::invoke(::std::move(fun), ::std::forward<Args>(args)...)

                                                       )) {
                            static_assert(noexcept(
                                ::beman::execution::set_error(::std::move(receiver), ::std::current_exception())));
                            ::beman::execution::set_error(::std::move(receiver), ::std::current_exception());
                        }
                    }
                } else {
                    static_assert(noexcept(Tag()(::std::move(receiver), ::std::forward<Args>(args)...)));
                    Tag()(::std::move(receiver), ::std::forward<Args>(args)...);
                }
            }
        };
        static constexpr auto complete{complete_impl{}};
        // NOLINTEND(bugprone-exception-escape)
    };
};
} // namespace beman::execution::detail

#include <beman/execution/detail/suppress_pop.hpp>

namespace beman::execution {
/*!
 * \brief <code>then_t</code> is the type of <code>then</code>.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
using then_t = ::beman::execution::detail::then_t<::beman::execution::set_value_t>;
/*!
 * \brief <code>upon_error_t</code> is the type of <code>upon_error</code>.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
using upon_error_t = ::beman::execution::detail::then_t<::beman::execution::set_error_t>;
/*!
 * \brief <code>upon_stopped_t</code> is the type of <code>upon_stopped</code>.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
using upon_stopped_t = ::beman::execution::detail::then_t<::beman::execution::set_stopped_t>;

/*!
 * \brief <code>then(_sender_, _fun_)</code> yields a sender transforming a <code>set_value_t(_A_...)</code> completion
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 *
 * \details
 * `then` is a callable object of type `then_t`. Invoking <code>then(_sender_, _fun_)</code> or
 * <code>_sender_ | then(_fun_)</code> yields a sender
 * which, when `start`ed starts <code>_sender_</code> and awaits its completion. When
 * <code>_sender_</code> completes `then` proceeds according to this completion:
 * - If the completion is <code>set_value(_a_...)</code>, <code>_fun_(_a_...)</code> is invoked:
 *     - if that invocation throws, `then` completes with <code>set_error(_r_, std::current_exception())</code>;
 * otherwise
 *     - if the invocation returns `void`, `then` completes with <code>set_value(_r_)</code>; otherwise
 *     - if the invocation returns <code>_v_</code>, `then` completes with <code>set_value(_r_, _v_)</code>.
 * - Otherwise, if the completion is <code>set_error(_e_)</code>, `then` completes with <code>set_error(_r_,
 * _e_)</code>
 * - Otherwise, if the completion is <code>set_stopped()</code>, `then` completes with <code>set_stopped(_r_)</code>.
 *
 * <h4>Usage</h4>
 * <pre>
 * then(<i>sender</i>, <i>fun</i>)
 * <i>sender</i> | then(<i>fun</i>)
 * </pre>
 *
 * <h4>Completions Signatures</h4>
 * The completion signatures depends on the completion signatures <code>_CS_</code> of <code>_sender_</code> (the
 * completion signatures will be deduplicated):
 * - For each <code>set_value_t(_A_...)</code> in <code>_CS_</code>,
 *     there is a completion signature
 *     <code>set_value_t(decltype(_fun_(std::declval<_A_>()...)))</code>.
 * - If for any of the <code>set_value_t(_A_...)</code> in
 *     <code>_CS_</code> the expression <code>noexcept(_fun_(std::declval<_A_>()...))</code>
 *     is `false` there is a completion signature <code>set_error_t(std::exception_ptr)</code>.
 * - Each <code>set_error_t(_Error_)</code> in <code>_CS_</code> is copied.
 * - If <code>set_stopped_t()</code> is in <code>_CS_</code> it is copied.
 *
 * <h4>Example</h4>
 *
 * <pre example="doc-then.cpp">
 * #include <beman/execution.hpp>
 * #include <cassert>
 * namespace ex = beman::execution;
 *
 * int main() {
 *     auto result = ex::sync_wait(ex::just(10) | ex::then([](int v) { return v == 3; }));
 *     assert(result);
 *     assert(*result == std::tuple(false));
 * }
 * </pre>
 */
inline constexpr ::beman::execution::then_t then{};

/*!
 * \brief <code>upon_error(_sender_, _fun_)</code> yields a sender transforming a <code>set_error_t(_E_)</code>
 * completion
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 *
 * \details
 * `upon_error` is a callable object of type `upon_error_t`. Invoking <code>upon_error(_sender_, _fun_)</code> or
 * <code>_sender_ | upon_error(_fun_)</code> yields a sender
 * which, when `start`ed starts <code>_sender_</code> and awaits its completion. When
 * <code>_sender_</code> completes `upon_error` proceeds according to this completion:
 * - If the completion is <code>set_error(_e_)</code>, <code>_fun_(_e_)</code> is invoked:
 *     - if that invocation throws, `upon_error` completes with <code>set_error(_r_, std::current_exception())</code>;
 * otherwise
 *     - if the invocation returns `void`, `upon_error` completes with <code>set_value(_r_)</code>; otherwise
 *     - if the invocation returns <code>_v_</code>, `upon_error` completes with <code>set_value(_r_, _v_)</code>.
 * - Otherwise, if the completion is <code>set_value(_a_...)</code>, `upon_error` completes with <code>set_value(_r_,
 * _a_...)</code>
 * - Otherwise, if the completion is <code>set_stopped()</code>, `upon_error` completes with
 * <code>set_stopped(_r_)</code>.
 *
 * <h4>Usage</h4>
 * <pre>
 * upon_error(<i>sender</i>, <i>fun</i>)
 * <i>sender</i> | upon_error(<i>fun</i>)
 * </pre>
 *
 * <h4>Completions Signatures</h4>
 * The completion signatures depend on the completion signatures <code>_CS_</code> of <code>_sender_</code> (the
 * completion signatures will be deduplicated):
 * - For each <code>set_error_t(_E_)</code> in <code>_CS_</code>,
 *     there is a completion signature
 *     <code>set_value_t(decltype(_fun_(std::declval<_E_>())))</code>.
 * - If for any of the <code>set_error_t(_E_)</code> in
 *     <code>_CS_</code> the expression <code>noexcept(_fun_(_std::declval<E>()_))</code>
 *     is `false` there is a completion signature <code>set_error_t(std::exception_ptr)</code>.
 * - Each <code>set_value_t(_A_...)</code> in <code>_CS_</code> is copied.
 * - If <code>set_stopped_t()</code> is in <code>_CS_</code> it is copied.
 *
 * <h4>Example</h4>
 *
 * <pre example="doc-upon_error.cpp">
 * #include <beman/execution.hpp>
 * #include <cassert>
 * namespace ex = beman::execution;
 *
 * int main() {
 *     auto result = ex::sync_wait(ex::just_error(10) | ex::upon_error([](int v) { return v == 3; }));
 *     assert(result);
 *     assert(*result == std::tuple(false));
 * }
 * </pre>
 */
inline constexpr ::beman::execution::upon_error_t upon_error{};

/*!
 * \brief <code>upon_stopped(_sender_, _fun_)</code> yields a sender transforming a <code>set_stopped_t()</code>
 * completion
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 *
 * \details
 * `upon_stopped` is a callable object of type `upon_stopped_t`. Invoking <code>upon_stopped(_sender_, _fun_)</code> or
 * <code>_sender_ | upon_stopped(_fun_)</code> yields a sender
 * which, when `start`ed starts <code>_sender_</code> and awaits its completion. When
 * <code>_sender_</code> completes `upon_stopped` proceeds according to this completion:
 * - If the completion is <code>set_stopped(_e_)</code>, <code>_fun_(_e_)</code> is invoked:
 *     - if that invocation throws, `upon_stopped` completes with <code>set_error(_r_,
 * std::current_exception())</code>; otherwise
 *     - if the invocation returns `void`, `upon_stopped` completes with <code>set_value(_r_)</code>; otherwise
 *     - if the invocation returns <code>_v_</code>, `upon_stopped` completes with <code>set_value(_r_, _v_)</code>.
 * - Otherwise, if the completion is <code>set_value(_a_...)</code>, `upon_stopped` completes with <code>set_value(_r_,
 * _a_...)</code>
 * - Otherwise, if the completion is <code>set_error(_e_)</code>, `upon_stopped` completes with <code>set_error(_r_,
 * _e_)</code>.
 *
 * <h4>Usage</h4>
 * <pre>
 * upon_stopped(<i>sender</i>, <i>fun</i>)
 * <i>sender</i> | upon_stopped(<i>fun</i>)
 * </pre>
 *
 * <h4>Completions Signatures</h4>
 * The completion signatures depend on the completion signatures <code>_CS_</code> of <code>_sender_</code> (the
 * completion signatures will be deduplicated):
 * - There is a completion signature <code>set_value_t(decltype(_fun_()))</code>.
 * - If the expression <code>noexcept(_fun_())</code> is `false` there is a completion signature
 * <code>set_error_t(std::exception_ptr)</code>.
 * - Each <code>set_value_t(_A_...)</code> in <code>_CS_</code> is copied.
 * - Each <code>set_error_t(_A_...)</code> in <code>_CS_</code> is copied.
 *
 * <h4>Example</h4>
 *
 * <pre example="doc-upon_stopped.cpp">
 * #include <beman/execution.hpp>
 * #include <cassert>
 * namespace ex = beman::execution;
 *
 * int main() {
 *     auto result = ex::sync_wait(ex::just_stopped() | ex::upon_stopped([]() { return true; }));
 *     assert(result);
 *     assert(*result == std::tuple(true));
 * }
 * </pre>
 */
inline constexpr ::beman::execution::upon_stopped_t upon_stopped{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_THEN
