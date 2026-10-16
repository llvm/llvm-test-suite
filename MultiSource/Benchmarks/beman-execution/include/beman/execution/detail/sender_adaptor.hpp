// include/beman/execution/detail/sender_adaptor.hpp                -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_ADAPTOR
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_ADAPTOR

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.forward_like;
import beman.execution.detail.product_type;
import beman.execution.detail.sender;
import beman.execution.detail.sender_adaptor_closure;
import beman.execution.detail.sender_decompose;
#else
#include <beman/execution/detail/forward_like.hpp>
#include <beman/execution/detail/product_type.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/sender_adaptor_closure.hpp>
#include <beman/execution/detail/sender_decompose.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {

template <typename... T>
using sender_adaptor
    [[deprecated("sender_adaptor is deprecated and layout incompatible with previous versions."
                 " Use make_sender_adaptor(adaptor, args...) instead. "
                 "The implementation now uses bound_sender_adaptor_closure, which stores the adaptor with "
                 "[[no_unique_address]] and keeps bound arguments in product_type.")]] =
        bound_sender_adaptor_closure<std::decay_t<T>...>;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SENDER_ADAPTOR
