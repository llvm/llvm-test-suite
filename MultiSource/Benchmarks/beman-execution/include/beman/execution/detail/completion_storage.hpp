// include/beman/execution/detail/completion_storage.hpp                          -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_COMPLETION_STORAGE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_COMPLETION_STORAGE

#include <beman/execution/detail/common.hpp>
#include <beman/execution/detail/suppress_push.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <exception>
#include <tuple>
#include <type_traits>
#include <variant>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.completion_signatures;
import beman.execution.detail.receiver_of;
import beman.execution.detail.receiver;
import beman.execution.detail.set_error;
import beman.execution.detail.unreachable;
#else
#include <beman/execution/detail/completion_signatures.hpp>
#include <beman/execution/detail/receiver_of.hpp>
#include <beman/execution/detail/receiver.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/unreachable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {

/// For a signature `Sig` of the form `Tag(Args...)`, compute the corresponding tuple type that can store the
/// completion.
template <typename Sig>
struct tuple_for_signature;

template <typename Tag, typename... Args>
struct tuple_for_signature<Tag(Args...)> {
    /// The tuple type corresponding to the signature `Tag(Args...)`.
    using type = ::std::tuple<Tag, ::std::remove_cvref_t<Args>...>;

    /// Helper function to be used in overloaded scenario to select the correct tuple type from a set of arguments.
    static auto select_tuple(Tag t, Args&&... args) -> type;
};

/// The variant storage for a set of completion signatures.
template <typename Signatures>
struct variant_for_signatures;

template <typename... Sigs>
struct variant_for_signatures<::beman::execution::completion_signatures<Sigs...>>
    : ::beman::execution::detail::tuple_for_signature<Sigs>... {
    /// The type of the variant that can store any of the completions in `Sigs...`.
    using type =
        ::std::variant<std::monostate, typename ::beman::execution::detail::tuple_for_signature<Sigs>::type...>;

    /// Stores in `storage` the completion with tag `t` and arguments `args...`.
    ///
    /// If the construction of the tuple throws, it will store a `set_error` completion with the current exception.
    template <typename Tag, typename... Args>
    static auto store_into_variant(type& storage, Tag t, Args&&... args) noexcept {
        using tuple_type = decltype(select_tuple(t, ::std::forward<Args>(args)...));
        try {
            storage.template emplace<tuple_type>(t, ::std::forward<Args>(args)...);
        } catch (...) {
            if constexpr (!std::is_nothrow_constructible_v<tuple_type, Tag, Args&&...>) {
                store_into_variant(storage, ::beman::execution::set_error_t{}, ::std::current_exception());
            } else {
                ::beman::execution::detail::unreachable();
            }
        }
    }

    /// Completes `receiver` with the completion stored in `storage`.
    ///
    /// The completion receives a copy of the stored tuple, in case the completion destroys the storage.
    template <::beman::execution::receiver Receiver>
    static void complete_from_variant(type&& storage, Receiver&& receiver) noexcept {
        std::visit(
            [&](auto&& tuple_data) {
                using tuple_type = ::std::remove_cvref_t<decltype(tuple_data)>;
                try {
                    if constexpr (std::is_same_v<tuple_type, std::monostate>) {
                        ::beman::execution::detail::unreachable();
                    } else {
                        ::std::apply(
                            [&](const auto tag, auto&&... args) noexcept {
                                tag(::std::forward<Receiver>(receiver), ::std::forward<decltype(args)>(args)...);
                            },
                            // Make a copy, in case the tuple is destroyed by the completion call.
                            tuple_type{::std::move(tuple_data)});
                    }
                } catch (...) {
                    if constexpr (!std::is_nothrow_constructible_v<tuple_type, tuple_type&&>) {
                        ::beman::execution::set_error(::std::forward<Receiver>(receiver), ::std::current_exception());
                    } else {
                        ::beman::execution::detail::unreachable();
                    }
                }
            },
            ::std::move(storage));
    }

    /// Helper to create an overload set to be able to select the right tuple from a set of arguments.
    using ::beman::execution::detail::tuple_for_signature<Sigs>::select_tuple...;
};

/// Storage for a set of completions.
template <typename Signatures>
struct completion_storage {
    completion_storage() noexcept = default;

    /// Stores the completion with tag `t` and arguments `args...`.
    template <typename Tag, typename... Args>
    void store(Tag t, Args&&... args) noexcept {
        variant_impl::store_into_variant(storage, t, ::std::forward<Args>(args)...);
    }

    /// Completes `receiver` with the completion stored in this storage.
    template <::beman::execution::receiver_of<Signatures> Receiver>
    void complete(Receiver&& receiver) && noexcept {
        variant_impl::complete_from_variant(::std::move(storage), ::std::forward<Receiver>(receiver));
    }

  private:
    using variant_impl = ::beman::execution::detail::variant_for_signatures<Signatures>;
    typename variant_impl::type storage;
};

} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_COMPLETION_STORAGE
