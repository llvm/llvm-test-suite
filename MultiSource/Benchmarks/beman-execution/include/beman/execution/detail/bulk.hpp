// include/beman/execution/detail/bulk.hpp                         -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_BULK
#define INCLUDED_BEMAN_EXECUTION_DETAIL_BULK

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <exception>
#include <functional>
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_sender;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.completion_signatures_of_t;
import beman.execution.detail.default_impls;
import beman.execution.detail.execution_policy;
import beman.execution.detail.forward_like;
import beman.execution.detail.make_sender;
import beman.execution.detail.meta.combine;
import beman.execution.detail.meta.unique;
import beman.execution.detail.product_type;
import beman.execution.detail.sender;
import beman.execution.detail.sender_adaptor_closure;
import beman.execution.detail.sender_for;
import beman.execution.detail.set_error;
import beman.execution.detail.set_value;
#else
#include <beman/execution/detail/basic_sender.hpp>
#include <beman/execution/detail/completion_signatures.hpp>
#include <beman/execution/detail/completion_signatures_of_t.hpp>
#include <beman/execution/detail/default_impls.hpp>
#include <beman/execution/detail/execution_policy.hpp>
#include <beman/execution/detail/forward_like.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/meta_combine.hpp>
#include <beman/execution/detail/meta_unique.hpp>
#include <beman/execution/detail/product_type.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/sender_adaptor_closure.hpp>
#include <beman/execution/detail/sender_for.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_value.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <bool IsChunked, typename F, typename Shape, typename... Args>
struct bulk_traits;

template <typename F, typename Shape, typename... Args>
struct bulk_traits<true, F, Shape, Args...> { // for bulk_chunked
    static constexpr bool is_invocable = ::std::is_invocable_v<F&, Shape, Shape, Args&...>;

    static constexpr bool is_nothrow_invocable = ::std::is_nothrow_invocable_v<F&, Shape, Shape, Args&...>;

    static auto invoke(F& fn, Shape shape, Args&... args) noexcept(is_nothrow_invocable) -> void {
        if (shape > static_cast<Shape>(0)) [[likely]] {
            std::invoke(fn, 0, shape, args...);
        }
    }
};

template <typename F, typename Shape, typename... Args>
struct bulk_traits<false, F, Shape, Args...> { // for bulk_unchunked
    static constexpr bool is_invocable = ::std::invocable<F, Shape, Args...>;

    static constexpr bool is_nothrow_invocable = ::std::is_nothrow_invocable_v<F, Shape, Args...>;

    static auto invoke(F& fn, Shape shape, Args&... args) noexcept(is_nothrow_invocable) -> void {
        for (auto i = static_cast<Shape>(0); i < shape; ++i) {
            std::invoke(fn, i, args...);
        }
    }
};

template <bool IsChunked, typename F, typename Shape, typename Completions>
struct bulk_transform_signatures;

template <bool IsChunked, typename F, typename Shape, typename... Sigs>
struct bulk_transform_signatures<IsChunked, F, Shape, ::beman::execution::completion_signatures<Sigs...>> {
    template <typename>
    struct is_nothrow : ::std::true_type {};

    template <typename... Args>
    struct is_nothrow<::beman::execution::set_value_t(Args...)>
        : ::std::bool_constant<
              ::beman::execution::detail::bulk_traits<IsChunked, F, Shape, Args...>::is_nothrow_invocable> {};

    using type = ::beman::execution::detail::meta::unique<::beman::execution::detail::meta::combine<
        ::beman::execution::completion_signatures<Sigs...>,
        ::std::conditional_t<
            (... && is_nothrow<Sigs>::value),
            ::beman::execution::completion_signatures<>,
            ::beman::execution::completion_signatures<::beman::execution::set_error_t(::std::exception_ptr)>>>>;
};

template <bool IsChunked>
struct bulk_algo_t {
    template <typename Policy, typename Shape, typename F>
        requires(::beman::execution::is_execution_policy_v<::std::remove_cvref_t<Policy>> && ::std::integral<Shape> &&
                 ::std::copy_constructible<::std::decay_t<F>>)
    auto operator()(Policy&& policy, Shape shape, F&& f) const {
        return ::beman::execution::detail::make_sender_adaptor(
            *this, ::std::forward<Policy>(policy), shape, ::std::forward<F>(f));
    }

    template <typename Sender, typename Policy, typename Shape, typename F>
        requires(::beman::execution::sender<Sender> &&
                 ::beman::execution::is_execution_policy_v<::std::remove_cvref_t<Policy>> && ::std::integral<Shape> &&
                 ::std::copy_constructible<::std::decay_t<F>>)
    auto operator()(Sender&& sndr, Policy&& policy, Shape shape, F&& f) const {
        return ::beman::execution::detail::make_sender(
            *this,
            ::beman::execution::detail::product_type<::std::remove_cvref_t<Policy>, Shape, ::std::decay_t<F>>{
                ::std::forward<Policy>(policy), shape, ::std::forward<F>(f)},
            ::std::forward<Sender>(sndr));
    }

  private:
    static constexpr bool is_chunked = IsChunked;

    template <typename, typename...>
    struct get_signatures;
    template <typename Policy, typename Shape, typename F, typename Sender, typename... Env>
    struct get_signatures<
        ::beman::execution::detail::
            basic_sender<bulk_algo_t, ::beman::execution::detail::product_type<Policy, Shape, F>, Sender>,
        Env...> {
        using type = typename ::beman::execution::detail::bulk_transform_signatures<
            is_chunked,
            F,
            Shape,
            ::beman::execution::completion_signatures_of_t<Sender, Env...>>::type;
    };

  public:
    template <typename Sender, typename... Env>
    static consteval auto get_completion_signatures() noexcept {
        return typename get_signatures<::std::remove_cvref_t<Sender>, Env...>::type{};
    }

    struct impls_for : ::beman::execution::detail::default_impls {
        struct complete_impl {
            template <typename Index,
                      typename Policy,
                      typename Shape,
                      typename Fun,
                      typename Receiver,
                      typename Tag,
                      typename... Args>
                requires(!::std::same_as<Tag, set_value_t> ||
                         ::beman::execution::detail::bulk_traits<is_chunked, Fun, Shape, Args...>::is_invocable)
            auto operator()(Index,
                            ::beman::execution::detail::product_type<Policy, Shape, Fun>& state,
                            Receiver&                                                     rcvr,
                            Tag,
                            Args&&... args) const noexcept -> void {
                if constexpr (::std::same_as<Tag, set_value_t>) {
                    auto& [policy, shape, f] = state;
                    constexpr bool nothrow =
                        ::beman::execution::detail::bulk_traits<is_chunked, Fun, Shape, Args...>::is_nothrow_invocable;
                    try {
                        [&]() noexcept(nothrow) {
                            ::beman::execution::detail::bulk_traits<is_chunked, Fun, Shape, Args...>::invoke(
                                f, shape, args...);
                            Tag()(::std::move(rcvr), ::std::forward<Args>(args)...);
                        }();
                    } catch (...) {
                        if constexpr (!nothrow) {
                            ::beman::execution::set_error(::std::move(rcvr), ::std::current_exception());
                        }
                    }
                } else {
                    Tag()(::std::move(rcvr), ::std::forward<Args>(args)...);
                }
            }
        };
        static constexpr complete_impl complete{};
    };
};

using bulk_chunked_t = ::beman::execution::detail::bulk_algo_t<true>;

using bulk_unchunked_t = ::beman::execution::detail::bulk_algo_t<false>;

struct bulk_t {
    template <typename Policy, typename Shape, typename F>
        requires(::beman::execution::is_execution_policy_v<::std::remove_cvref_t<Policy>> && ::std::integral<Shape> &&
                 ::std::copy_constructible<::std::decay_t<F>>)
    auto operator()(Policy&& policy, Shape shape, F&& f) const {
        return ::beman::execution::detail::make_sender_adaptor(
            *this, ::std::forward<Policy>(policy), shape, ::std::forward<F>(f));
    }

    template <typename Sender, typename Policy, typename Shape, typename F>
        requires(::beman::execution::sender<Sender> &&
                 ::beman::execution::is_execution_policy_v<::std::remove_cvref_t<Policy>> && ::std::integral<Shape> &&
                 ::std::copy_constructible<::std::decay_t<F>>)
    auto operator()(Sender&& sndr, Policy&& policy, Shape shape, F&& f) const {
        return ::beman::execution::detail::make_sender(
            *this,
            ::beman::execution::detail::product_type<::std::remove_cvref_t<Policy>, Shape, ::std::decay_t<F>>{
                ::std::forward<Policy>(policy), shape, ::std::forward<F>(f)},
            ::std::forward<Sender>(sndr));
    }

    template <::beman::execution::detail::sender_for<bulk_t> Sender, typename Env>
    auto transform_sender(::beman::execution::set_value_t, Sender&& sndr, const Env&) const {
        auto data  = ::beman::execution::detail::forward_like<Sender>(sndr.template get<1>());
        auto child = ::beman::execution::detail::forward_like<Sender>(sndr.template get<2>());

        auto& policy = data.template get<0>();
        auto& shape  = data.template get<1>();
        auto& f      = data.template get<2>();

        return bulk_chunked_t{}(::std::move(child),
                                policy,
                                shape,
                                this->wrap_chunked<::std::remove_cvref_t<decltype(shape)>>(::std::move(f)));
    }

  private:
    template <typename, typename...>
    struct get_signatures;
    template <typename Policy, typename Shape, typename F, typename Sender, typename... Env>
    struct get_signatures<::beman::execution::detail::
                              basic_sender<bulk_t, ::beman::execution::detail::product_type<Policy, Shape, F>, Sender>,
                          Env...> {
        using type = typename ::beman::execution::detail::bulk_transform_signatures<
            false,
            F,
            Shape,
            ::beman::execution::completion_signatures_of_t<Sender, Env...>>::type;
    };

    template <typename Shape, typename Fn>
    static auto wrap_chunked(Fn f) noexcept {
        return [f = std::move(f)]<typename... Args>(Shape begin, Shape end, Args&&... args) noexcept(
                   ::std::is_nothrow_invocable_v<Fn&, Shape, Args&...>) {
            while (begin != end) {
                std::invoke(f, begin++, args...);
            }
        };
    }

  public:
    template <typename Sender, typename... Env>
    static consteval auto get_completion_signatures() noexcept {
        return typename get_signatures<::std::remove_cvref_t<Sender>, Env...>::type{};
    }
};

} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

namespace beman::execution {

using bulk_t           = ::beman::execution::detail::bulk_t;
using bulk_chunked_t   = ::beman::execution::detail::bulk_chunked_t;
using bulk_unchunked_t = ::beman::execution::detail::bulk_unchunked_t;

inline constexpr ::beman::execution::bulk_t           bulk{};
inline constexpr ::beman::execution::bulk_chunked_t   bulk_chunked{};
inline constexpr ::beman::execution::bulk_unchunked_t bulk_unchunked{};

} // namespace beman::execution

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_BULK
