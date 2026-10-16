// include/beman/execution/detail/gather_signatures.hpp             -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_GATHER_SIGNATURES
#define INCLUDED_BEMAN_EXECUTION_DETAIL_GATHER_SIGNATURES

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.completion_signatures;
import beman.execution.detail.indirect_meta_apply;
import beman.execution.detail.meta.filter;
import beman.execution.detail.valid_completion_signatures;
#else
#include <beman/execution/detail/indirect_meta_apply.hpp>
#include <beman/execution/detail/meta_filter.hpp>
#include <beman/execution/detail/valid_completion_signatures.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename...>
concept always_true = true;

template <typename, typename>
struct same_tag;
template <typename Tag, typename R, typename... A>
struct same_tag<Tag, R(A...)> {
    static constexpr bool value = ::std::same_as<Tag, R>;
};
template <typename Tag>
struct bound_tag {
    using type = Tag;
    template <typename T>
    using predicate = ::beman::execution::detail::same_tag<Tag, T>;
};

template <typename, template <typename...> class>
struct gather_signatures_apply;
template <typename R, typename... A, template <typename...> class Transform>
    requires requires {
        typename ::beman::execution::detail::indirect_meta_apply<
            ::beman::execution::detail::always_true<R>>::template meta_apply<Transform, A...>;
    }
struct gather_signatures_apply<R(A...), Transform> {
    using type = typename ::beman::execution::detail::indirect_meta_apply<
        ::beman::execution::detail::always_true<R>>::template meta_apply<Transform, A...>;
};

template <::beman::execution::detail::valid_completion_signatures,
          template <typename...> class,
          template <typename...> class>
struct gather_signatures_helper;

template <typename... Signatures, template <typename...> class Tuple, template <typename...> class Variant>
    requires requires {
        requires always_true<typename ::beman::execution::detail::gather_signatures_apply<Signatures, Tuple>::type...>;
    } && requires {
        typename ::beman::execution::detail::indirect_meta_apply<
            always_true<typename ::beman::execution::detail::gather_signatures_apply<Signatures, Tuple>::type...>>::
            template meta_apply<
                Variant,
                typename ::beman::execution::detail::gather_signatures_apply<Signatures, Tuple>::type...>;
    }
struct gather_signatures_helper<::beman::execution::completion_signatures<Signatures...>, Tuple, Variant> {
    using type = typename ::beman::execution::detail::indirect_meta_apply<
        always_true<typename ::beman::execution::detail::gather_signatures_apply<Signatures, Tuple>::type...>>::
        template meta_apply<Variant,
                            typename ::beman::execution::detail::gather_signatures_apply<Signatures, Tuple>::type...>;
};

template <typename Tag,
          ::beman::execution::detail::valid_completion_signatures signatures,
          template <typename...> class Tuple,
          template <typename...> class Variant>
    requires requires {
        typename ::beman::execution::detail::gather_signatures_helper<
            ::beman::execution::detail::meta::filter_tag<::beman::execution::detail::same_tag, Tag, signatures>,
            Tuple,
            Variant>::type;
    }
using gather_signatures = typename ::beman::execution::detail::gather_signatures_helper<
    ::beman::execution::detail::meta::filter_tag<::beman::execution::detail::same_tag, Tag, signatures>,
    Tuple,
    Variant>::type;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_GATHER_SIGNATURES
