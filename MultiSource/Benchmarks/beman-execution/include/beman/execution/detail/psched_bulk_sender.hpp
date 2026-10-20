// include/beman/execution/detail/psched_bulk_sender.hpp              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_PSCHED_BULK_SENDER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_PSCHED_BULK_SENDER

#include <cassert>
#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <cstddef>
#include <concepts>
#include <exception>
#include <memory>
#include <optional>
#include <span>
#include <type_traits>
#include <utility>
#include <variant>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.connect;
import beman.execution.detail.connect_result_t;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.decayed_tuple;
import beman.execution.detail.env_of_t;
import beman.execution.detail.execution_policy;
import beman.execution.detail.get_completion_signatures;
import beman.execution.detail.get_env;
import beman.execution.detail.get_stop_token;
import beman.execution.detail.inplace_stop_source;
import beman.execution.detail.meta.combine;
import beman.execution.detail.meta.prepend;
import beman.execution.detail.meta.unique;
import beman.execution.detail.operation_state;
import beman.execution.detail.parallel_scheduler_replacement;
import beman.execution.detail.receiver;
import beman.execution.detail.sender;
import beman.execution.detail.start;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.stop_propagator;
import beman.execution.detail.stop_token_of_t;
import beman.execution.detail.unreachable;
import beman.execution.detail.value_types_of_t;
#else
#include <beman/execution/detail/connect.hpp>
#include <beman/execution/detail/connect_result_t.hpp>
#include <beman/execution/detail/completion_signatures.hpp>
#include <beman/execution/detail/decayed_tuple.hpp>
#include <beman/execution/detail/env_of_t.hpp>
#include <beman/execution/detail/execution_policy.hpp>
#include <beman/execution/detail/get_completion_signatures.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/get_stop_token.hpp>
#include <beman/execution/detail/inplace_stop_source.hpp>
#include <beman/execution/detail/meta_combine.hpp>
#include <beman/execution/detail/meta_prepend.hpp>
#include <beman/execution/detail/meta_unique.hpp>
#include <beman/execution/detail/operation_state.hpp>
#include <beman/execution/detail/parallel_scheduler_replacement.hpp>
#include <beman/execution/detail/receiver.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/start.hpp>
#include <beman/execution/detail/stop_propagator.hpp>
#include <beman/execution/detail/stop_token_of_t.hpp>
#include <beman/execution/detail/unreachable.hpp>
#include <beman/execution/detail/value_types_of_t.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
inline constexpr ::std::size_t psched_storage_alignment = alignof(::std::max_align_t);
inline constexpr ::std::size_t psched_storage_size      = 6uz * sizeof(void*);
template <bool IsChunked, typename Policy, typename Shape, typename Fn, typename Child>
struct psched_bulk_sender {
    using sender_concept = ::beman::execution::sender_tag;
    using backend_type   = ::beman::execution::parallel_scheduler_replacement::parallel_scheduler_backend;

    static constexpr bool is_parallel_policy = ::std::same_as<Policy, ::beman::execution::parallel_policy> ||
                                               ::std::same_as<Policy, ::beman::execution::parallel_unsequenced_policy>;
    template <typename Rcvr>
    struct rcvr_proxy : ::beman::execution::parallel_scheduler_replacement::bulk_item_receiver_proxy {
        using result_type = ::beman::execution::detail::meta::
            prepend<::std::monostate, ::beman::execution::value_types_of_t<Child, ::beman::execution::env_of_t<Rcvr>>>;
        using stop_token_t = ::beman::execution::stop_token_of_t<::beman::execution::env_of_t<Rcvr>>;

        rcvr_proxy(::std::shared_ptr<backend_type> backend, Rcvr rcvr, Policy policy, Shape shape, Fn fn) noexcept
            : backend(::std::move(backend)),
              sp(::beman::execution::get_stop_token(::beman::execution::get_env(rcvr))),
              rcvr(::std::move(rcvr)),
              policy(::std::move(policy)),
              shape(::std::move(shape)),
              fn(::std::move(fn)) {}

        auto get_env() const noexcept { return ::beman::execution::get_env(rcvr); }

        auto execute(::std::size_t begin, ::std::size_t end) noexcept -> void final {
            assert(begin < end);
            assert(IsChunked || !is_parallel_policy || end - begin == 1uz);
            const Shape first   = is_parallel_policy ? static_cast<Shape>(begin) : Shape(0);
            const Shape last    = is_parallel_policy ? static_cast<Shape>(end) : shape;
            const auto  call_fn = [=, this]<typename... Args>(const Args&... args) {
                if constexpr (IsChunked) {
                    static_assert(::std::invocable<Fn, Shape, Shape, const Args&...>);
                    fn(first, last, args...);
                } else {
                    static_assert(::std::invocable<Fn, Shape, const Args&...>);
                    for (Shape i = first; i < last; ++i) {
                        fn(i, args...);
                    }
                }
            };
            ::std::visit(
                [&]<typename T>(T& tpl) {
                    if constexpr (::std::same_as<T, ::std::monostate>) {
                        ::beman::execution::detail::unreachable();
                    } else {
                        ::std::apply(call_fn, ::std::move(tpl));
                    }
                },
                result);
        }

        auto set_value() noexcept -> void final {
            const auto call_set_value = [this]<typename... Args>(Args&&... args) {
                ::beman::execution::set_value(::std::move(rcvr), ::std::forward<Args>(args)...);
            };
            try {
                ::std::visit(
                    [&]<typename T>(T tpl) {
                        if constexpr (::std::same_as<T, std::monostate>) {
                            ::beman::execution::detail::unreachable();
                        } else {
                            ::std::apply(call_set_value, ::std::move(tpl));
                        }
                    },
                    ::std::move(result));
            } catch (...) {
                this->set_error(::std::current_exception());
            }
        }

        template <typename E>
        auto set_error(E e) noexcept -> void {
            ::beman::execution::set_error(::std::move(rcvr), ::std::move(e));
        }

        auto set_error(::std::exception_ptr e) noexcept -> void final { this->set_error<>(::std::move(e)); }

        auto set_stopped() noexcept -> void final { ::beman::execution::set_stopped(::std::move(rcvr)); }

      private:
        auto query_stop_token() const noexcept -> ::std::optional<::beman::execution::inplace_stop_token> final {
            return sp.get_token();
        }

      public:
        alignas(psched_storage_alignment)::std::byte storage[psched_storage_size];
        ::std::shared_ptr<backend_type>                                                 backend;
        result_type                                                                     result;
        [[no_unique_address]] ::beman::execution::detail::stop_propagator<stop_token_t> sp;
        Rcvr                                                                            rcvr;
        Policy                                                                          policy;
        Shape                                                                           shape;
        Fn                                                                              fn;
    };

    template <typename Rcvr>
    struct state {
        using operation_state_concept = ::beman::execution::operation_state_tag;
        using result_type             = ::beman::execution::detail::meta::
            prepend<::std::monostate, ::beman::execution::value_types_of_t<Child, ::beman::execution::env_of_t<Rcvr>>>;

        struct receiver_ref {
            using receiver_concept = ::beman::execution::receiver_tag;

            template <typename... Args>
            auto set_value(Args&&... args) noexcept -> void try {
                using arg_t = ::beman::execution::detail::decayed_tuple<Args...>;
                proxy->result.template emplace<arg_t>(::std::forward<Args>(args)...);
                if (!proxy->backend) [[unlikely]] {
                    ::std::terminate();
                }
                const ::std::size_t s = is_parallel_policy ? proxy->shape : 1uz;
                if constexpr (IsChunked) {
                    proxy->backend->schedule_bulk_chunked(s, *proxy, proxy->storage);
                } else {
                    proxy->backend->schedule_bulk_unchunked(s, *proxy, proxy->storage);
                }
            } catch (...) {
                proxy->set_error(::std::current_exception());
            }

            template <typename E>
            auto set_error(E e) noexcept -> void {
                proxy->set_error(::std::move(e));
            }

            auto set_stopped() noexcept -> void { proxy->set_stopped(); }

            auto get_env() const noexcept { return proxy->get_env(); }

            rcvr_proxy<Rcvr>* proxy;
        };
        using sub_state_t = ::beman::execution::connect_result_t<Child, receiver_ref>;

        state(::std::shared_ptr<backend_type> backend, Child child, Rcvr rcvr, Policy policy, Shape shape, Fn fn)
            : proxy(std::move(backend), ::std::move(rcvr), ::std::move(policy), ::std::move(shape), ::std::move(fn)),
              sub_state(::beman::execution::connect(::std::move(child), receiver_ref{&proxy})) {}

        auto start() & noexcept -> void { ::beman::execution::start(sub_state); }

        rcvr_proxy<Rcvr> proxy;
        sub_state_t      sub_state;
    };

    template <typename, typename... Env>
    static consteval auto get_completion_signatures() {
        constexpr auto compl_sigs = ::beman::execution::get_completion_signatures<Child, Env...>();
        return ::beman::execution::detail::meta::unique<::beman::execution::detail::meta::combine<
            ::std::remove_cvref_t<decltype(compl_sigs)>,
            ::beman::execution::completion_signatures<::beman::execution::set_error_t(::std::exception_ptr)>>>{};
    }

    template <typename Rcvr>
    auto connect(Rcvr rcvr) && noexcept {
        return state<Rcvr>{::std::move(backend),
                           ::std::move(child),
                           ::std::move(rcvr),
                           ::std::move(policy),
                           ::std::move(shape),
                           ::std::move(fn)};
    }

    auto get_env() const noexcept { return ::beman::execution::get_env(child); }

    [[no_unique_address]] ::std::bool_constant<IsChunked> _;
    ::std::shared_ptr<backend_type>                       backend;
    Policy                                                policy;
    Shape                                                 shape;
    Fn                                                    fn;
    Child                                                 child;
};
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_PSCHED_BULK_SENDER
