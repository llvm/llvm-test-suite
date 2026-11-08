// include/beman/execution/detail/associate.hpp                       -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_ASSOCIATE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_ASSOCIATE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <memory>
#include <optional>
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.basic_sender;
import beman.execution.detail.connect;
import beman.execution.detail.connect_result_t;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.default_impls;
import beman.execution.detail.env;
import beman.execution.detail.forward_like;
import beman.execution.detail.get_completion_signatures;
import beman.execution.detail.impls_for;
import beman.execution.detail.make_sender;
import beman.execution.detail.nothrow_callable;
import beman.execution.detail.scope_token;
import beman.execution.detail.sender;
import beman.execution.detail.sender_adaptor_closure;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.start;
import beman.execution.detail.valid_completion_signatures;
#else
#include <beman/execution/detail/connect.hpp>
#include <beman/execution/detail/default_impls.hpp>
#include <beman/execution/detail/get_completion_signatures.hpp>
#include <beman/execution/detail/impls_for.hpp>
#include <beman/execution/detail/make_sender.hpp>
#include <beman/execution/detail/nothrow_callable.hpp>
#include <beman/execution/detail/scope_token.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/sender_adaptor.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <::beman::execution::scope_token Token, ::beman::execution::sender Sender>
struct associate_data {
    using wrap_sender = ::std::remove_cvref_t<decltype(::std::declval<Token&>().wrap(::std::declval<Sender>()))>;
    using assoc_t     = decltype(::std::declval<Token&>().try_associate());
    using sender_ref  = ::std::unique_ptr<wrap_sender, decltype(std::ranges::destroy_at)>;

    explicit associate_data(Token t, Sender&& s) : sender(t.wrap(::std::forward<Sender>(s))) {
        sender_ref guard{::std::addressof(this->sender)};
        this->assoc = t.try_associate();
        if (this->assoc) {
            static_cast<void>(guard.release());
        }
    }

    explicit associate_data(::std::pair<assoc_t, sender_ref> parts) : assoc(::std::move(parts.first)) {
        if (this->assoc) {
            ::std::construct_at(::std::addressof(this->sender), ::std::move(*parts.second));
        }
    }

    associate_data(const associate_data& other) noexcept(::std::is_nothrow_copy_constructible_v<wrap_sender> &&
                                                         noexcept(other.assoc.try_associate()))
        requires ::std::copy_constructible<wrap_sender>
        : assoc(other.assoc.try_associate()) {
        if (this->assoc) {
            ::std::construct_at(::std::addressof(this->sender), other.sender);
        }
    }

    associate_data(associate_data&& other) noexcept(::std::is_nothrow_move_constructible_v<wrap_sender>)
        : associate_data(::std::move(other).release()) {}

    auto operator=(const associate_data&) -> associate_data& = delete;

    auto operator=(associate_data&&) -> associate_data& = delete;

    ~associate_data() {
        if (this->assoc) {
            ::std::destroy_at(::std::addressof(this->sender));
        }
    }

    auto release() && noexcept -> ::std::pair<assoc_t, sender_ref> {
        return {::std::move(assoc), sender_ref{assoc ? ::std::addressof(this->sender) : nullptr}};
    }

    assoc_t assoc;
    union {
        wrap_sender sender;
    };
};

template <::beman::execution::scope_token Token, ::beman::execution::sender Sender>
associate_data(Token, Sender&&) -> associate_data<Token, Sender>;

struct associate_t {
    template <::beman::execution::sender Sender, ::beman::execution::scope_token Token>
    auto operator()(Sender&& sender, Token token) const {
        return ::beman::execution::detail::make_sender(
            *this, ::beman::execution::detail::associate_data(::std::move(token), ::std::forward<Sender>(sender)));
    }

    template <::beman::execution::scope_token Token>
    auto operator()(Token token) const {
        return ::beman::execution::detail::make_sender_adaptor(*this, ::std::move(token));
    }

  public:
    template <typename Sender, typename... Env>
    static consteval auto get_completion_signatures() {
        using Data         = decltype(std::declval<::std::remove_cvref_t<Sender>>().template get<1>());
        using child_type_t = ::std::remove_cvref_t<typename ::std::remove_cvref_t<Data>::wrap_sender>;
        return ::beman::execution::get_completion_signatures<child_type_t, Env...>();
    }

    struct impls_for : ::beman::execution::detail::default_impls {
        template <typename>
        struct get_wrap_sender;

        template <typename Tag, typename Data>
        struct get_wrap_sender<::beman::execution::detail::basic_sender<Tag, Data>> {
            using type = typename ::std::remove_cvref_t<Data>::wrap_sender;
        };

        template <typename AssociateData, typename Receiver>
        struct op_state {
            using assoc_t      = typename AssociateData::assoc_t;
            using sender_ref_t = typename AssociateData::sender_ref;
            using op_t         = ::beman::execution::connect_result_t<typename sender_ref_t::element_type, Receiver>;

            assoc_t assoc;
            union {
                Receiver* rcvr;
                op_t      op;
            };

            explicit op_state(::std::pair<assoc_t, sender_ref_t> parts, Receiver& r)
                : assoc(::std::move(parts.first)) {
                if (assoc) {
                    ::new (static_cast<void*>(::std::addressof(op)))
                        op_t(::beman::execution::connect(::std::move(*parts.second), ::std::move(r)));
                } else {
                    rcvr = ::std::addressof(r);
                }
            }

            explicit op_state(AssociateData&& ad, Receiver& r) : op_state(::std::move(ad).release(), r) {}

            explicit op_state(const AssociateData& ad, Receiver& r)
                requires ::std::copy_constructible<AssociateData>
                : op_state(AssociateData(ad).release(), r) {}

            op_state(const op_state&) = delete;

            op_state(op_state&&) = delete;

            ~op_state() {
                if (this->assoc) {
                    op.~op_t();
                }
            }

            auto operator=(const op_state&) -> op_state& = delete;

            auto operator=(op_state&&) -> op_state& = delete;

            auto run() noexcept -> void {
                if (this->assoc) {
                    ::beman::execution::start(this->op);
                } else {
                    ::beman::execution::set_stopped(::std::move(*this->rcvr));
                }
            }
        };

        struct get_state_impl {
            template <typename Sender, typename Receiver>
            auto operator()(Sender&& sender, Receiver& receiver) const noexcept(
                (::std::same_as<Sender, ::std::remove_cvref_t<Sender>> ||
                 ::std::is_nothrow_constructible_v<::std::remove_cvref_t<Sender>, Sender>) &&
                execution::detail::nothrow_callable<::beman::execution::connect_t,
                                                    typename get_wrap_sender<::std::remove_cvref_t<Sender>>::type,
                                                    Receiver>) {
                return op_state{
                    ::beman::execution::detail::forward_like<Sender>(::std::forward<Sender>(sender).template get<1>()),
                    receiver};
            }
        };
        static constexpr auto get_state{get_state_impl{}};
        struct start_impl {
            auto operator()(auto& state, auto&&) const noexcept -> void { state.run(); }
        };
        static constexpr auto start{start_impl{}};
    };
};

} // namespace beman::execution::detail

namespace beman::execution {
using associate_t = ::beman::execution::detail::associate_t;
inline constexpr associate_t associate{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_ASSOCIATE
