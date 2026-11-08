// include/beman/execution/detail/let.hpp                           -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_LET
#define INCLUDED_BEMAN_EXECUTION_DETAIL_LET

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <exception>
#include <functional>
#include <tuple>
#include <type_traits>
#include <utility>
#include <variant>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.allocator_aware_move;
import beman.execution.detail.basic_sender;
import beman.execution.detail.call_result_t;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.completion_signatures_of_t;
import beman.execution.detail.connect;
import beman.execution.detail.decayed_tuple;
import beman.execution.detail.default_impls;
import beman.execution.detail.dependent_sender;
import beman.execution.detail.emplace_from;
import beman.execution.detail.env;
import beman.execution.detail.env_of_t;
import beman.execution.detail.forward_like;
import beman.execution.detail.fwd_env;
import beman.execution.detail.gather_signatures;
import beman.execution.detail.get_env;
import beman.execution.detail.get_completion_domain;
import beman.execution.detail.get_completion_scheduler;
import beman.execution.detail.get_completion_signatures;
import beman.execution.detail.get_domain;
import beman.execution.detail.impls_for;
import beman.execution.detail.join_env;
import beman.execution.detail.make_env;
import beman.execution.detail.make_sender;
import beman.execution.detail.meta.combine;
import beman.execution.detail.meta.filter;
import beman.execution.detail.meta.prepend;
import beman.execution.detail.meta.to;
import beman.execution.detail.meta.transform;
import beman.execution.detail.meta.unique;
import beman.execution.detail.movable_value;
import beman.execution.detail.receiver;
import beman.execution.detail.sched_env;
import beman.execution.detail.sender;
import beman.execution.detail.sender_adaptor_closure;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.start;
import beman.execution.detail.type_list;
#else
#include <beman/execution/detail/allocator_aware_move.hpp>
#include <beman/execution/detail/completion_signatures_of_t.hpp>
#include <beman/execution/detail/connect.hpp>
#include <beman/execution/detail/decayed_tuple.hpp>
#include <beman/execution/detail/default_impls.hpp>
#include <beman/execution/detail/dependent_sender.hpp>
#include <beman/execution/detail/emplace_from.hpp>
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/env_of_t.hpp>
#include <beman/execution/detail/forward_like.hpp>
#include <beman/execution/detail/fwd_env.hpp>
#include <beman/execution/detail/gather_signatures.hpp>
#include <beman/execution/detail/get_completion_domain.hpp>
#include <beman/execution/detail/impls_for.hpp>
#include <beman/execution/detail/join_env.hpp>
#include <beman/execution/detail/make_env.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/meta_combine.hpp>
#include <beman/execution/detail/meta_filter.hpp>
#include <beman/execution/detail/meta_prepend.hpp>
#include <beman/execution/detail/meta_to.hpp>
#include <beman/execution/detail/meta_transform.hpp>
#include <beman/execution/detail/meta_unique.hpp>
#include <beman/execution/detail/movable_value.hpp>
#include <beman/execution/detail/sched_env.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/sender_adaptor.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/type_list.hpp>
#endif

// ----------------------------------------------------------------------------

#include <beman/execution/detail/suppress_push.hpp>

namespace beman::execution::detail {
template <typename Tag, typename>
struct let_other_completion : ::std::true_type {};
template <typename Tag, typename... A>
struct let_other_completion<Tag, Tag(A...)> : ::std::false_type {};
template <typename Tag, typename>
struct let_matching_completion : ::std::false_type {};
template <typename Tag, typename... A>
struct let_matching_completion<Tag, Tag(A...)> : ::std::true_type {};

template <typename, typename>
struct get_successor_senders;

template <typename Fun, typename... Args>
struct get_successor_senders<Fun, ::beman::execution::detail::type_list<Args...>> {
    using type = std::invoke_result_t<Fun, Args...>;
};

template <typename, typename>
struct non_dependent_successor_helper;

template <typename Fun, typename... TypeLists>
struct non_dependent_successor_helper<Fun, ::beman::execution::detail::type_list<TypeLists...>>
    : std::bool_constant<(... &&
                          !::beman::execution::dependent_sender<
                              typename ::beman::execution::detail::get_successor_senders<Fun, TypeLists>::type>)> {};

template <typename Completion, typename Child, typename Fun>
struct non_dependent_successor
    : ::beman::execution::detail::non_dependent_successor_helper<
          Fun,
          ::beman::execution::detail::gather_signatures<Completion,
                                                        ::beman::execution::completion_signatures_of_t<Child>,
                                                        ::beman::execution::detail::type_list,
                                                        ::beman::execution::detail::type_list>> {};

template <typename Completion>
struct let_t {
    template <::beman::execution::detail::movable_value Fun>
    auto operator()(Fun&& fun) const {
        return ::beman::execution::detail::make_sender_adaptor(*this, ::std::forward<Fun>(fun));
    }
    template <::beman::execution::sender Sender, ::beman::execution::detail::movable_value Fun>
    auto operator()(Sender&& sender, Fun&& fun) const {
        return ::beman::execution::detail::make_sender(*this, ::std::forward<Fun>(fun), std::forward<Sender>(sender));
    }

    template <typename Sender, typename Env>
    static auto let_env(const Sender& sender, const Env& e) {
        if constexpr (requires {
                          ::beman::execution::detail::sched_env(
                              ::beman::execution::get_completion_scheduler<Completion>(
                                  ::beman::execution::get_env(sender), ::beman::execution::detail::fwd_env(e)));
                      }) {
            return ::beman::execution::detail::sched_env(::beman::execution::get_completion_scheduler<Completion>(
                ::beman::execution::get_env(sender), ::beman::execution::detail::fwd_env(e)));
        } else if constexpr (requires {
                                 ::beman::execution::detail::make_env(
                                     ::beman::execution::get_domain,
                                     ::beman::execution::get_completion_domain<Completion>(
                                         ::beman::execution::get_env(sender), ::beman::execution::detail::fwd_env(e)));
                             })
            return ::beman::execution::detail::make_env(
                ::beman::execution::get_domain,
                ::beman::execution::get_completion_domain<Completion>(::beman::execution::get_env(sender),
                                                                      ::beman::execution::detail::fwd_env(e)));
        else {
            return ::beman::execution::env<>{};
        }
    }

    template <typename Sndr, typename Env>
    using let_env_t = decltype(let_env(::std::declval<Sndr>(), ::std::declval<Env>()));

  private:
    template <typename, typename...>
    struct get_signatures;

    template <typename Comp, typename Fun, typename Child>
        requires ::beman::execution::detail::non_dependent_successor<Completion, Child, Fun>::value
    struct get_signatures<
        ::beman::execution::detail::basic_sender<::beman::execution::detail::let_t<Comp>, Fun, Child>>
        : get_signatures<::beman::execution::detail::basic_sender<::beman::execution::detail::let_t<Comp>, Fun, Child>,
                         ::beman::execution::env<>> {};

    template <typename Comp, typename Fun, typename Child, typename Env>
    struct get_signatures<
        ::beman::execution::detail::basic_sender<::beman::execution::detail::let_t<Comp>, Fun, Child>,
        Env> {
        template <typename T>
        using other_completion = let_other_completion<Comp, T>;
        template <typename T>
        using matching_completion = let_matching_completion<Comp, T>;

        template <typename>
        struct apply_decayed;
        template <typename C, typename... A>
        struct apply_decayed<C(A...)> {
            using sender_type = ::beman::execution::detail::call_result_t<Fun, ::std::decay_t<A>...>;
            using completions = ::std::conditional_t<
                noexcept(::std::declval<Fun>()(::std::declval<::std::decay_t<A>>()...)),
                ::beman::execution::completion_signatures<>,
                ::beman::execution::completion_signatures<::beman::execution::set_error_t(::std::exception_ptr)>>;
        };

        using successor_env =
            ::beman::execution::detail::join_env<let_env_t<Child, Env>, ::beman::execution::detail::fwd_env<Env>>;

        template <typename>
        struct get_completions;
        template <template <typename...> class L, typename... C>
        struct get_completions<L<C...>> {
            using type = ::beman::execution::detail::meta::unique<::beman::execution::detail::meta::combine<
                ::beman::execution::completion_signatures<>,
                ::beman::execution::completion_signatures_of_t<typename apply_decayed<C>::sender_type,
                                                               successor_env>...,
                typename apply_decayed<C>::completions...>>;
        };

        using upstream_completions = ::beman::execution::completion_signatures_of_t<Child, Env>;
        using other_completions    = ::beman::execution::detail::meta::filter<other_completion, upstream_completions>;
        using matching_completions =
            ::beman::execution::detail::meta::filter<matching_completion, upstream_completions>;
        using type = ::beman::execution::detail::meta::unique<
            ::beman::execution::detail::meta::combine<typename get_completions<matching_completions>::type,
                                                      other_completions>>;

        static consteval auto get() noexcept { return type{}; }
    };

  public:
    template <typename Sender, typename... Env>
        requires requires { get_signatures<std::remove_cvref_t<Sender>, Env...>::get(); }
    static consteval auto get_completion_signatures() {
        return get_signatures<std::remove_cvref_t<Sender>, Env...>::get();
    }

    struct impls_for : ::beman::execution::detail::default_impls {
        template <typename Receiver, typename Env>
        struct let_receiver {
            using receiver_concept = ::beman::execution::receiver_tag;

            Receiver& receiver;
            Env       env;

            auto get_env() const noexcept -> decltype(auto) {
                return ::beman::execution::detail::join_env(
                    this->env, ::beman::execution::detail::fwd_env(::beman::execution::get_env(this->receiver)));
            }
            template <typename Error>
            auto set_error(Error&& error) && noexcept -> void {
                ::beman::execution::set_error(::std::move(this->receiver), ::std::forward<Error>(error));
            }
            auto set_stopped() && noexcept -> void { ::beman::execution::set_stopped(::std::move(this->receiver)); }
            template <typename... Args>
            auto set_value(Args&&... args) && noexcept -> void {
                ::beman::execution::set_value(::std::move(this->receiver), ::std::forward<Args>(args)...);
            }
        };

        template <typename>
        struct filter_pred : ::std::false_type {};
        template <typename... A>
        struct filter_pred<Completion(A...)> : ::std::true_type {};
        template <typename>
        struct to_tuple;
        template <typename C, typename... A>
        struct to_tuple<C(A...)> {
            using type = ::beman::execution::detail::decayed_tuple<A...>;
        };
        template <typename T>
        using to_tuple_t = typename to_tuple<T>::type;
        template <typename Fun, typename Receiver, typename Env>
        struct to_state {
            template <typename Tuple>
            using trans =
                decltype(::beman::execution::connect(::std::apply(::std::declval<Fun>(), ::std::declval<Tuple>()),
                                                     ::std::declval<let_receiver<Receiver, Env>>()));
        };

        static constexpr auto get_state{[]<typename Sender, typename Receiver>(Sender&& sender, Receiver&& receiver) {
            auto& fun{sender.template get<1>()};
            auto& child{sender.template get<2>()};

            using fun_t   = ::std::remove_cvref_t<decltype(fun)>;
            using child_t = ::std::remove_cvref_t<decltype(child)>;
            using env_t   = let_env_t<child_t, ::beman::execution::env_of_t<Receiver>>;
            using sigs_t =
                ::beman::execution::completion_signatures_of_t<child_t, ::beman::execution::env_of_t<Receiver>>;
            using comp_sigs_t = ::beman::execution::detail::meta::filter<filter_pred, sigs_t>;
            using type_list_t = ::beman::execution::detail::meta::to<::std::variant, comp_sigs_t>;
            using tuples_t    = ::beman::execution::detail::meta::transform<to_tuple_t, type_list_t>;
            using unique_t    = ::beman::execution::detail::meta::unique<tuples_t>;
            using args_t      = ::beman::execution::detail::meta::prepend<std::monostate, unique_t>;
            using ops_t       = ::beman::execution::detail::meta::prepend<
                ::std::monostate,
                ::beman::execution::detail::meta::unique<::beman::execution::detail::meta::transform<
                    to_state<fun_t, ::std::remove_cvref_t<Receiver>, env_t>::template trans,
                    tuples_t>>>;

            struct state_t {
                fun_t  fun;
                env_t  env;
                args_t args;
                ops_t  ops2;
            };
            return state_t{
                beman::execution::detail::allocator_aware_move(::beman::execution::detail::forward_like<Sender>(fun),
                                                               receiver),
                ::beman::execution::detail::let_t<Completion>::let_env(child, ::beman::execution::get_env(receiver)),
                {},
                {}};
        }};
        template <typename Receiver, typename... Args>
        static auto let_bind(auto& state, Receiver& receiver, Args&&... args) noexcept(
            noexcept(::beman::execution::connect(::std::invoke(::std::move(state.fun), ::std::forward<Args>(args)...),
                                                 let_receiver<Receiver, decltype(state.env)>{receiver, state.env}))) {
            using args_t = ::beman::execution::detail::decayed_tuple<Args...>;
            auto mkop{[&] {
                return ::beman::execution::connect(
                    ::std::apply(::std::move(state.fun),
                                 ::std::move(state.args.template emplace<args_t>(::std::forward<Args>(args)...))),
                    let_receiver<Receiver, decltype(state.env)>{receiver, state.env});
            }};
            ::beman::execution::start(
                state.ops2.template emplace<decltype(mkop())>(beman::execution::detail::emplace_from{mkop}));
        }
        struct complete_impl {
            template <class Tag, class... Args>
            auto operator()(auto, auto& state, auto& receiver, Tag, Args&&... args) const {
                if constexpr (::std::same_as<Tag, Completion>) {
                    try {
                        let_bind(state, receiver, ::std::forward<Args>(args)...);
                    } catch (...) {
                        if constexpr (not noexcept(let_bind(state, receiver, ::std::forward<Args>(args)...))) {
                            ::beman::execution::set_error(::std::move(receiver), ::std::current_exception());
                        }
                    }
                } else {
                    Tag()(::std::move(receiver), ::std::forward<Args>(args)...);
                }
            }
        };
        static constexpr auto complete{complete_impl{}};
    };
};

} // namespace beman::execution::detail

#include <beman/execution/detail/suppress_pop.hpp>

namespace beman::execution {
using let_error_t   = ::beman::execution::detail::let_t<::beman::execution::set_error_t>;
using let_stopped_t = ::beman::execution::detail::let_t<::beman::execution::set_stopped_t>;
using let_value_t   = ::beman::execution::detail::let_t<::beman::execution::set_value_t>;

inline constexpr ::beman::execution::let_error_t   let_error{};
inline constexpr ::beman::execution::let_stopped_t let_stopped{};
inline constexpr ::beman::execution::let_value_t   let_value{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_LET
