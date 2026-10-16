// include/beman/execution/detail/just.hpp                          -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_JUST
#define INCLUDED_BEMAN_EXECUTION_DETAIL_JUST

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <memory>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_sender;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.completion_signatures_for;
import beman.execution.detail.default_impls;
import beman.execution.detail.impls_for;
import beman.execution.detail.make_sender;
import beman.execution.detail.movable_value;
import beman.execution.detail.product_type;
import beman.execution.detail.sender;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
#else
#include <beman/execution/detail/completion_signatures_for.hpp>
#include <beman/execution/detail/default_impls.hpp>
#include <beman/execution/detail/impls_for.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/movable_value.hpp>
#include <beman/execution/detail/product_type.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#endif

// ----------------------------------------------------------------------------

#include <beman/execution/detail/suppress_push.hpp>

namespace beman::execution::detail {
template <typename Completion, typename... T>
concept just_size = (!::std::same_as<Completion, ::beman::execution::set_error_t> or 1u == sizeof...(T)) &&
                    (!::std::same_as<Completion, ::beman::execution::set_stopped_t> or 0u == sizeof...(T));

template <typename Completion>
struct just_t {
    template <typename... T>
        requires ::beman::execution::detail::just_size<Completion, T...> &&
                 (::beman::execution::detail::movable_value<T> && ...)
    auto operator()(T&&... arg) const
        noexcept((::std::is_nothrow_constructible_v<::std::remove_cvref_t<T>, T> && ...)) {
        return ::beman::execution::detail::make_sender(
            *this, ::beman::execution::detail::product_type{::std::forward<T>(arg)...});
    }

    template <::beman::execution::sender Sender>
    static auto affine(Sender&& sndr) noexcept {
        return ::std::forward<Sender>(sndr);
    }

  private:
    template <typename>
    struct get_signatures;
    template <typename C, typename... T>
    struct get_signatures<
        ::beman::execution::detail::basic_sender<just_t<C>, ::beman::execution::detail::product_type<T...>>> {
        using type = ::beman::execution::completion_signatures<::std::remove_cvref_t<C>(T...)>;
    };

  public:
    template <::beman::execution::sender Sender, typename...>
    static consteval auto get_completion_signatures() {
        return typename get_signatures<::std::remove_cvref_t<Sender>>::type{};
    }
    struct impls_for : ::beman::execution::detail::default_impls {
        struct start_impl {
            template <typename State>
            auto operator()(State& state, auto& receiver) const noexcept -> void {
                [&state, &receiver]<::std::size_t... I>(::std::index_sequence<I...>) {
                    Completion()(::std::move(receiver), ::std::move(state.template get<I>())...);
                }(::std::make_index_sequence<State::size()>{});
            }
        };
        static constexpr auto start{start_impl{}};
    };
};

} // namespace beman::execution::detail

#include <beman/execution/detail/suppress_pop.hpp>

namespace beman::execution {
using just_t         = ::beman::execution::detail::just_t<::beman::execution::set_value_t>;
using just_error_t   = ::beman::execution::detail::just_t<::beman::execution::set_error_t>;
using just_stopped_t = ::beman::execution::detail::just_t<::beman::execution::set_stopped_t>;

/*!
 * \brief <code>just(_arg_...)</code> yields a sender completing with <code>set_value_t(_Arg_...)</code>
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 *
 * \details
 * `just` is a callable object of type `just_t`. Invoking <code>just(_arg_...)</code> yields a sender which stores its
 * arguments and produces a value completion with these arguments when started. This sender completes synchronously
 * when started.
 *
 * <h4>Usage</h4>
 * <pre>
 * just(<i>arg</i>...)
 * </pre>
 *
 * Above <code>_Arg_...</code> is a pack of the types of <code>_arg_...</code>
 * after removing top-level `const` and reference qualifications
 * (<code>std::remove_cvref_t&lt;decltype(_arg_)&gt;...</code>).
 *
 * <h4>Completions Signatures</h4>
 * <pre>
 * completion_signatures<
 *     set_value_t(<i>Arg</i>...)
 * >;
 * </pre>
 *
 * <h4>Example</h4>
 *
 * The normal use of <code>just(_args_...)</code> is as the starting
 * point of a work graph. Various other examples will use `just` as
 * their starting. The example below create a sender yielding three
 * values and awaits the completion using <code>sync_wait(_sender_)</code>:
 * for a value completion of <code>_sender_</code> it will yield an
 * <code>std::optional&lt;std::tuple&lt;_Args_...&gt;&gt;</code> with the
 * `tuple` containing the value copied/moved from the original arguments
 * (an `optional` is returned to indicate cancellation).
 *
 * <pre example="doc_just.cpp">
 * #include <beman/execution.hpp>
 * #include <cassert>
 * #include <string>
 * using namespace std::string_literals;
 *
 * int main() {
 *     auto result = ex::sync_wait(ex::just(17, "hello"s, true));
 *     assert(result);
 *     assert(*result == std::tuple(17, "hello"s, true));
 * }
 * </pre>
 */
inline constexpr ::beman::execution::just_t just{};

/*!
 * \brief <code>just_error(_error_)</code> yields a sender completing with <code>set_error_t(_Error_)</code>
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 *
 * \details
 * `just_error` is a callable object of type `just_error_t`. Invoking <code>just_error(_error_)</code> yields a sender
 * which stores its argument and produces an error completion with this error when started. This sender completes
 * synchronously when started.
 *
 * <h4>Usage</h4>
 * <pre>
 * just_error(<i>error</i>)
 * </pre>
 *
 * The type <code>_Error_</code> used above is the type of <code>_error_</code>
 * after removing top-level `const` and reference qualifications
 * (<code>std::remove_cvref_t&lt;decltype(error)&gt;</code>).
 *
 * <h4>Completions Signatures</h4>
 * <pre>
 * completion_signatures<
 *     set_error_t(<i>Error</i>)
 * >;
 * </pre>
 *
 * <h4>Example</h4>
 *
 * The normal use of <code>just_error(_error_)</code> is to report an
 * error as the result of some work in a work graph. It would, e.g., be
 * used as the completion produced by `let_value`.
 * The example below creates a sender yielding an `std::error_code` on the error
 * channel and
 * uses that as the input for `upon_error` consuming the error and producing
 * a value completion: using <code>sync_wait(just_error(_error_))</code>
 * directly doesn't work because `sync_wait` requires exactly one value completion
 * from its argument and `set_error` only has an error completion. The function used with `upon_error` verifies that
 * the expected code was produced and also sets the flag `had_error` indicating it was called at all. This flag is
 * checked after waiting for the result in `sync_wait`.
 *
 * <pre example="doc_just_error.cpp">
 * #include <beman/execution.hpp>
 * #include <system_error>
 * #include <cassert>
 * namespace ex = beman::execution;
 *
 * int main() {
 *     bool had_error{false};
 *     auto result = ex::sync_wait(ex::just_error(std::error_code(17, std::system_category())) |
 *                                 ex::upon_error([&](std::error_code ec) {
 *                                     assert(ec.value() == 17);
 *                                     had_error = true;
 *                                 }));
 *     assert(had_error);
 * }
 * </pre>
 */
inline constexpr ::beman::execution::just_error_t just_error{};

/*!
 * \brief <code>just_stopped()</code> yields a sender completing with <code>set_stopped_t()</code>
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 *
 * \details
 * `just_stopped` is a callable object of type `just_stopped_t`. Invoking <code>just_stopped()</code> yields a sender
 * which produces a cancellation completion when started. This sender completes synchronously when started.
 *
 * <h4>Usage</h4>
 * <pre>
 * just_stopped()
 * </pre>
 *
 * <h4>Completions Signatures</h4>
 * <pre>
 * completion_signatures<
 *     set_stopped_t()
 * >;
 * </pre>
 *
 * <h4>Example</h4>
 *
 * The normal use of <code>just_stopped()</code> is to report a
 * cancellation as the result of some work in a work graph. It would, e.g., be
 * used as the completion produced by `let_value`.
 * The example below creates a sender yielding a completion on the cancellation
 * channel and
 * uses that as the input for `upon_stopped` consuming the cancellation and producing
 * a value completion: using <code>sync_wait(just_stopped())</code>
 * directly doesn't work because `sync_wait` requires exactly one value completion
 * from its argument and `set_stopped` only has a cancellation completion. The function used with `upon_stopped`
 * sets the flag `had_stopped` indicating it
 * was called at all. This flag is checked after waiting for the result
 * in `sync_wait`.
 *
 * <pre example="doc_just_error.cpp">
 * #include <beman/execution.hpp>
 * #include <system_error>
 * #include <cassert>
 * namespace ex = beman::execution;
 *
 * int main() {
 *     bool had_stopped{false};
 *     auto result = ex::sync_wait(ex::just_error(std::error_code(17, std::system_category())) |
 *                                 ex::upon_error([&](std::error_code ec) {
 *                                     assert(ec.value() == 17);
 *                                     had_stopped = true;
 *                                 }));
 *     assert(had_stopped);
 * }
 * </pre>
 */
inline constexpr ::beman::execution::just_stopped_t just_stopped{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_JUST
