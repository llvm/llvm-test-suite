// include/beman/execution/detail/when_all.hpp                      -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_WHEN_ALL
#define INCLUDED_BEMAN_EXECUTION_DETAIL_WHEN_ALL

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <atomic>
#include <concepts>
#include <exception>
#include <optional>
#include <tuple>
#include <type_traits>
#include <utility>
#include <variant>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_sender;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.completion_signatures_for;
import beman.execution.detail.completion_signatures_of_t;
import beman.execution.detail.common_domain;
import beman.execution.detail.compl_domain;
import beman.execution.detail.decayed_tuple;
import beman.execution.detail.decayed_type_list;
import beman.execution.detail.default_domain;
import beman.execution.detail.default_impls;
import beman.execution.detail.dependent_sender;
import beman.execution.detail.dependent_sender_error;
import beman.execution.detail.env;
import beman.execution.detail.env_of_t;
import beman.execution.detail.error_types_of_t;
import beman.execution.detail.get_env;
import beman.execution.detail.get_completion_domain;
import beman.execution.detail.get_domain;
import beman.execution.detail.get_stop_token;
import beman.execution.detail.impls_for;
import beman.execution.detail.inplace_stop_source;
import beman.execution.detail.join_env;
import beman.execution.detail.make_env;
import beman.execution.detail.make_sender;
import beman.execution.detail.meta.combine;
import beman.execution.detail.meta.prepend;
import beman.execution.detail.meta.size;
import beman.execution.detail.meta.to;
import beman.execution.detail.meta.transform;
import beman.execution.detail.meta.unique;
import beman.execution.detail.never_stop_token;
import beman.execution.detail.on_stop_request;
import beman.execution.detail.prop;
import beman.execution.detail.sender;
import beman.execution.detail.sender_in;
import beman.execution.detail.sends_stopped;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.start;
import beman.execution.detail.stop_callback_for_t;
import beman.execution.detail.stop_token_of_t;
import beman.execution.detail.transform_sender;
import beman.execution.detail.type_list;
import beman.execution.detail.value_types_of_t;
#else
#include <beman/execution/detail/compl_domain.hpp>
#include <beman/execution/detail/common_domain.hpp>
#include <beman/execution/detail/completion_signatures_of_t.hpp>
#include <beman/execution/detail/decayed_tuple.hpp>
#include <beman/execution/detail/decayed_type_list.hpp>
#include <beman/execution/detail/default_domain.hpp>
#include <beman/execution/detail/default_impls.hpp>
#include <beman/execution/detail/dependent_sender.hpp>
#include <beman/execution/detail/dependent_sender_error.hpp>
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/env_of_t.hpp>
#include <beman/execution/detail/error_types_of_t.hpp>
#include <beman/execution/detail/get_completion_domain.hpp>
#include <beman/execution/detail/get_domain.hpp>
#include <beman/execution/detail/get_stop_token.hpp>
#include <beman/execution/detail/impls_for.hpp>
#include <beman/execution/detail/inplace_stop_source.hpp>
#include <beman/execution/detail/join_env.hpp>
#include <beman/execution/detail/make_env.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/meta_combine.hpp>
#include <beman/execution/detail/meta_prepend.hpp>
#include <beman/execution/detail/meta_size.hpp>
#include <beman/execution/detail/meta_to.hpp>
#include <beman/execution/detail/meta_transform.hpp>
#include <beman/execution/detail/meta_unique.hpp>
#include <beman/execution/detail/on_stop_request.hpp>
#include <beman/execution/detail/prop.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/sender_in.hpp>
#include <beman/execution/detail/sends_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/stop_callback_for_t.hpp>
#include <beman/execution/detail/stop_token_of_t.hpp>
#include <beman/execution/detail/transform_sender.hpp>
#include <beman/execution/detail/type_list.hpp>
#include <beman/execution/detail/value_types_of_t.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename>
struct when_all_value_types;
template <typename... T>
struct when_all_value_types<::beman::execution::detail::type_list<T...>> {
    using type = ::beman::execution::completion_signatures<::beman::execution::set_value_t(T...)>;
};

template <typename Sender>
concept valid_when_all_sender = ::beman::execution::dependent_sender<Sender> ||
                                ::beman::execution::detail::meta::size_v<
                                    ::beman::execution::value_types_of_t<Sender,
                                                                         ::beman::execution::env<>,
                                                                         ::std::tuple,
                                                                         ::beman::execution::detail::type_list>> == 1u;

inline constexpr auto make_when_all_env = [](const ::beman::execution::inplace_stop_source& stop_src,
                                             const auto&                                    env) noexcept {
    return ::beman::execution::detail::join_env(
        ::beman::execution::env{::beman::execution::prop{::beman::execution::get_stop_token, stop_src.get_token()}},
        env);
};

template <typename Env>
using when_all_env =
    decltype(make_when_all_env(::std::declval<::beman::execution::inplace_stop_source>(), ::std::declval<Env>()));

static_assert(std::same_as<::beman::execution::never_stop_token,
                           decltype(::beman::execution::get_stop_token(::std::declval<::beman::execution::env<>>()))>);
static_assert(std::same_as<::beman::execution::inplace_stop_token,
                           decltype(::beman::execution::get_stop_token(
                               ::std::declval<when_all_env<::beman::execution::env<>>>()))>);

struct when_all_t {
    template <::beman::execution::sender... Sender>
        requires(0u != sizeof...(Sender)) && (... && beman::execution::detail::valid_when_all_sender<Sender>)
    auto operator()(Sender&&... sender) const {
        return ::beman::execution::detail::make_sender(*this, {}, ::std::forward<Sender>(sender)...);
    }

  private:
    template <typename, typename...>
    struct get_signatures;
    template <typename Sender>
    struct get_signatures<Sender> : get_signatures<Sender, ::beman::execution::env<>> {};
    template <typename Data, typename Env, typename... Sender>
    struct get_signatures<
        ::beman::execution::detail::basic_sender<::beman::execution::detail::when_all_t, Data, Sender...>,
        Env> {
        template <typename... E>
        struct error_comps_t {
            using type = ::beman::execution::completion_signatures<::beman::execution::set_error_t(E)...>;
        };
        template <typename... E>
        using error_comps = typename error_comps_t<E...>::type;

        using value_types =
            typename ::beman::execution::detail::when_all_value_types<::beman::execution::detail::meta::combine<
                ::beman::execution::value_types_of_t<Sender,
                                                     when_all_env<Env>,
                                                     ::beman::execution::detail::type_list,
                                                     ::std::type_identity_t>...>>::type;
        using error_types = ::beman::execution::detail::meta::unique<::beman::execution::detail::meta::combine<
            ::beman::execution::error_types_of_t<Sender, when_all_env<Env>, error_comps>...>>;
        using stopped_types =
            ::std::conditional_t<(false || ... || ::beman::execution::sends_stopped<Sender, when_all_env<Env>>),
                                 ::beman::execution::completion_signatures<::beman::execution::set_stopped_t()>,
                                 ::beman::execution::completion_signatures<>>;
        using type = ::beman::execution::detail::meta::combine<value_types, error_types, stopped_types>;
    };

    template <typename... Sender>
    struct attrs {
        template <typename Tag, typename... Env>
        using child_domain_t = ::beman::execution::detail::common_domain_t<
            ::beman::execution::detail::compl_domain_of_t<Tag, Sender, Env...>...>;

        template <typename... Env>
            requires requires { typename child_domain_t<::beman::execution::set_value_t, Env...>; }
        static auto query(::beman::execution::get_completion_domain_t<::beman::execution::set_value_t>,
                          const Env&...) noexcept -> child_domain_t<::beman::execution::set_value_t, Env...> {
            return {};
        }

        template <typename... Env>
            requires requires {
                typename ::beman::execution::detail::common_domain_t<
                    child_domain_t<::beman::execution::set_value_t, Env...>,
                    child_domain_t<::beman::execution::set_error_t, Env...>,
                    child_domain_t<::beman::execution::set_stopped_t, Env...>>;
            }
        static auto query(::beman::execution::get_completion_domain_t<::beman::execution::set_error_t>,
                          const Env&...) noexcept
            -> ::beman::execution::detail::common_domain_t<child_domain_t<::beman::execution::set_value_t, Env...>,
                                                           child_domain_t<::beman::execution::set_error_t, Env...>,
                                                           child_domain_t<::beman::execution::set_stopped_t, Env...>> {
            return {};
        }

        template <typename... Env>
            requires requires {
                typename ::beman::execution::detail::common_domain_t<
                    child_domain_t<::beman::execution::set_value_t, Env...>,
                    child_domain_t<::beman::execution::set_stopped_t, Env...>>;
            }
        static auto query(::beman::execution::get_completion_domain_t<::beman::execution::set_stopped_t>,
                          const Env&...) noexcept
            -> ::beman::execution::detail::common_domain_t<child_domain_t<::beman::execution::set_value_t, Env...>,
                                                           child_domain_t<::beman::execution::set_stopped_t, Env...>> {
            return {};
        }
    };

  public:
    template <typename Sender, typename... Env>
    static consteval auto get_completion_signatures() {
        return typename get_signatures<std::remove_cvref_t<Sender>, Env...>::type{};
    }

    struct impls_for : ::beman::execution::detail::default_impls {
        struct get_attrs_impl {
            template <typename... Children>
            auto operator()(const auto&, const Children&...) const noexcept {
                return attrs<Children...>{};
            }
        };
        static constexpr auto get_attrs{get_attrs_impl{}};

        struct get_env_impl {
            template <typename State, typename Receiver>
            auto operator()(auto&&, State& state, const Receiver& receiver) const noexcept {
                return make_when_all_env(state.stop_src, ::beman::execution::get_env(receiver));
            }
        };
        static constexpr auto get_env{get_env_impl{}};

        struct nonesuch {};

        enum class disposition : unsigned char { started, error, stopped };

        template <typename... Values>
        struct is_nothrow_decay_copy_constructible
            : ::std::bool_constant<(... && ::std::is_nothrow_constructible_v<::std::decay_t<Values>, Values>)> {};

        template <typename Receiver, typename... Sender>
        struct state_type {
            using env_t     = when_all_env<::beman::execution::env_of_t<Receiver>>;
            using copy_fail = ::std::conditional_t<
                (... && ::beman::execution::value_types_of_t<Sender,
                                                             env_t,
                                                             is_nothrow_decay_copy_constructible,
                                                             ::std::type_identity_t>::value) &&
                    (... &&
                     ::beman::execution::error_types_of_t<Sender, env_t, is_nothrow_decay_copy_constructible>::value),
                nonesuch,
                std::exception_ptr>;
            using values_tuple = ::std::tuple<
                ::beman::execution::
                    value_types_of_t<Sender, env_t, ::beman::execution::detail::decayed_tuple, ::std::optional>...>;
            using errors_variant = ::beman::execution::detail::meta::to<
                ::std::variant,
                ::beman::execution::detail::meta::unique<::beman::execution::detail::meta::prepend<
                    nonesuch,
                    ::beman::execution::detail::meta::prepend<
                        copy_fail,
                        ::beman::execution::detail::meta::combine<::beman::execution::detail::meta::to<
                            ::beman::execution::detail::type_list,
                            ::beman::execution::detail::meta::combine<::beman::execution::error_types_of_t<
                                Sender,
                                env_t,
                                ::beman::execution::detail::decayed_type_list>...>>>>>>>;
            using stop_callback = ::beman::execution::stop_callback_for_t<
                ::beman::execution::stop_token_of_t<::beman::execution::env_of_t<Receiver>>,
                ::beman::execution::detail::on_stop_request<state_type>>;

            void arrive(Receiver& recvr) noexcept {
                if (0u == --count)
                    this->complete(recvr);
            }

            void complete(Receiver& recvr) noexcept {
                switch (disposition(this->disp)) {
                case disposition::started: {
                    auto tie = []<typename... T>(::std::tuple<T...>& t) noexcept {
                        return ::std::apply([](auto&... a) { return ::std::tie(a...); }, t);
                    };
                    auto set = [&](auto&... t) noexcept {
                        ::beman::execution::set_value(::std::move(recvr), ::std::move(t)...);
                    };

                    this->on_stop.reset();
                    ::std::apply([&](auto&... opts) noexcept { ::std::apply(set, ::std::tuple_cat(tie(*opts)...)); },
                                 this->values);
                } break;
                case disposition::error:
                    this->on_stop.reset();
                    ::std::visit(
                        [&]<typename Error>(Error& error) noexcept {
                            if constexpr (!::std::same_as<Error, nonesuch>) {
                                ::beman::execution::set_error(::std::move(recvr), ::std::move(error));
                            }
                        },
                        this->errors);
                    break;
                case disposition::stopped:
                    if constexpr ((... ||
                                   ::beman::execution::
                                       sends_stopped<Sender, when_all_env<::beman::execution::env_of_t<Receiver>>>)) {
                        this->on_stop.reset();
                        ::beman::execution::set_stopped(::std::move(recvr));
                    }
                    break;
                }
            }

            auto request_stop() -> void {
                if (1u == ++this->count)
                    --this->count;
                else {
                    this->stop_src.request_stop();
                    this->arrive(*this->receiver);
                }
            }

            Receiver*                               receiver{};
            ::std::atomic<::std::size_t>            count{sizeof...(Sender)};
            ::beman::execution::inplace_stop_source stop_src{};
            ::std::atomic<disposition>              disp{disposition::started};
            errors_variant                          errors{};
            values_tuple                            values{};
            ::std::optional<stop_callback>          on_stop{::std::nullopt};
        };

        template <typename Receiver>
        struct make_state {
            template <::beman::execution::sender_in<when_all_env<::beman::execution::env_of_t<Receiver>>>... Sender>
            auto operator()(auto, auto, Sender&&...) const {
                return state_type<Receiver, Sender...>{};
            }
        };
        struct get_state_impl {
            template <typename Sender, typename Receiver>
            auto operator()(Sender&& sender, Receiver&) const
                noexcept(noexcept(std::forward<Sender>(sender).apply(make_state<Receiver>{}))) {
                return std::forward<Sender>(sender).apply(make_state<Receiver>{});
            }
        };
        static constexpr auto get_state{get_state_impl{}};
        struct start_impl {
            template <typename State, typename Receiver, typename... Ops>
            auto operator()(State& state, Receiver& receiver, Ops&... ops) const noexcept -> void {
                state.receiver = &receiver;
                state.on_stop.emplace(::beman::execution::get_stop_token(::beman::execution::get_env(receiver)),
                                      ::beman::execution::detail::on_stop_request{state});
                (::beman::execution::start(ops), ...);
            }
        };
        static constexpr auto start{start_impl{}};
        struct complete_impl {
            template <typename Index, typename State, typename Receiver, typename Set, typename... Args>
            auto operator()(Index, State& state, Receiver& receiver, Set, Args&&... args) const noexcept -> void {
                if constexpr (::std::same_as<Set, ::beman::execution::set_error_t>) {
                    if (disposition::error != state.disp.exchange(disposition::error)) {
                        state.stop_src.request_stop();
                        using error_t          = typename std::type_identity<Args...>::type;
                        constexpr bool nothrow = ::std::is_nothrow_constructible_v<::std::decay_t<error_t>, error_t>;
                        try {
                            [&]() noexcept(nothrow) {
                                state.errors.template emplace<::std::decay_t<error_t>>(::std::forward<Args>(args)...);
                            }();
                        } catch (...) {
                            if constexpr (!nothrow) {
                                state.errors.template emplace<::std::exception_ptr>(::std::current_exception());
                            }
                        }
                    }
                } else if constexpr (::std::same_as<Set, ::beman::execution::set_stopped_t>) {
                    auto expected = disposition::started;
                    if (state.disp.compare_exchange_strong(expected, disposition::stopped)) {
                        state.stop_src.request_stop();
                    }
                } else if constexpr (!::std::same_as<decltype(State::values), ::std::tuple<>>) {
                    if (state.disp == disposition::started) {
                        auto& opt              = ::std::get<Index::value>(state.values);
                        using decayed_tuple_t  = typename ::std::decay_t<decltype(opt)>::value_type;
                        constexpr bool nothrow = std::is_nothrow_constructible_v<decayed_tuple_t, Args...>;
                        try {
                            [&]() noexcept(nothrow) { opt.emplace(::std::forward<Args>(args)...); }();
                        } catch (...) {
                            if constexpr (!nothrow) {
                                if (disposition::error != state.disp.exchange(disposition::error)) {
                                    state.stop_src.request_stop();
                                    state.errors.template emplace<::std::exception_ptr>(::std::current_exception());
                                }
                            }
                        }
                    }
                }
                state.arrive(receiver);
            }
        };
        static constexpr auto complete{complete_impl{}};
    };
};

} // namespace beman::execution::detail

namespace beman::execution {
using when_all_t = ::beman::execution::detail::when_all_t;
inline constexpr ::beman::execution::when_all_t when_all{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_WHEN_ALL
