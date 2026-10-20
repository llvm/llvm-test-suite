// include/beman/execution/detail/default_domain.hpp                -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_DEFAULT_DOMAIN
#define INCLUDED_BEMAN_EXECUTION_DETAIL_DEFAULT_DOMAIN

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.queryable;
import beman.execution.detail.sender;
import beman.execution.detail.tag_of_t;
#else
#include <beman/execution/detail/queryable.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/tag_of_t.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {

struct default_domain {
    template <typename Tag, ::beman::execution::sender Sender, ::beman::execution::detail::queryable... Env>
        requires(sizeof...(Env) <= 1) && requires(Sender&& sender, const Env&... env) {
            ::beman::execution::tag_of_t<Sender>().transform_sender(Tag(), ::std::forward<Sender>(sender), env...);
        }
    static constexpr auto transform_sender(Tag, Sender&& sender, const Env&... env) noexcept(noexcept(
        ::beman::execution::tag_of_t<Sender>().transform_sender(Tag(), ::std::forward<Sender>(sender), env...)))
        -> ::beman::execution::sender decltype(auto) {
        return ::beman::execution::tag_of_t<Sender>().transform_sender(Tag(), ::std::forward<Sender>(sender), env...);
    }

    template <typename Tag, ::beman::execution::sender Sender, ::beman::execution::detail::queryable... Env>
        requires(sizeof...(Env) <= 1) && (not requires(Sender&& sender, const Env&... env) {
                    ::beman::execution::tag_of_t<Sender>().transform_sender(
                        Tag(), ::std::forward<Sender>(sender), env...);
                })
    static constexpr auto
    transform_sender(Tag, Sender&& sender, const Env&...) noexcept(::std::is_nothrow_constructible_v<Sender, Sender>)
        -> Sender {
        return static_cast<Sender&&>(sender);
    }

    template <typename Tag, ::beman::execution::sender Sender, typename... Args>
        requires requires(Tag tag, Sender&& sender, Args&&... args) {
            tag.apply_sender(::std::forward<Sender>(sender), ::std::forward<Args>(args)...);
        }
    static constexpr auto apply_sender(Tag tag, Sender&& sender, Args&&... args) noexcept(
        noexcept(tag.apply_sender(::std::forward<Sender>(sender), ::std::forward<Args>(args)...))) -> decltype(auto) {
        return tag.apply_sender(::std::forward<Sender>(sender), ::std::forward<Args>(args)...);
    }
};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_DEFAULT_DOMAIN
