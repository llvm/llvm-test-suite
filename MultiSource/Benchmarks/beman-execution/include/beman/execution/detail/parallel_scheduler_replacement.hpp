// include/beman/execution/detail/parallel_scheduler_replacement.hpp              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_PARALLEL_SCHEDULER_REPLACEMENT
#define INCLUDED_BEMAN_EXECUTION_DETAIL_PARALLEL_SCHEDULER_REPLACEMENT

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
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.get_stop_token;
import beman.execution.detail.inplace_stop_source;
#else
#include <beman/execution/detail/get_stop_token.hpp>
#include <beman/execution/detail/inplace_stop_source.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::parallel_scheduler_replacement {

struct receiver_proxy {
    virtual ~receiver_proxy() = default;

    virtual auto set_value() noexcept -> void                     = 0;
    virtual auto set_error(::std::exception_ptr) noexcept -> void = 0;
    virtual auto set_stopped() noexcept -> void                   = 0;

    template <class P, class Query>
        requires(::std::same_as<P, ::std::remove_cv_t<P>> && ::std::is_object_v<P> && !::std::is_array_v<P>)
    auto try_query(Query) const noexcept -> ::std::optional<P> {
        if constexpr (::std::same_as<Query, ::beman::execution::get_stop_token_t> &&
                      ::std::same_as<P, ::beman::execution::inplace_stop_token>) {
            return query_stop_token();
        }
        // TODO: support more queries
        return ::std::nullopt;
    }

  private:
    virtual auto query_stop_token() const noexcept -> ::std::optional<::beman::execution::inplace_stop_token> {
        return std::nullopt;
    }
};

struct bulk_item_receiver_proxy : receiver_proxy {
    virtual auto execute(::std::size_t, ::std::size_t) noexcept -> void = 0;
};

struct parallel_scheduler_backend {
    virtual ~parallel_scheduler_backend() = default;

    virtual auto schedule(receiver_proxy&, ::std::span<::std::byte>) noexcept -> void = 0;
    virtual auto schedule_bulk_chunked(::std::size_t, bulk_item_receiver_proxy&, ::std::span<::std::byte>) noexcept
        -> void = 0;
    virtual auto schedule_bulk_unchunked(::std::size_t, bulk_item_receiver_proxy&, ::std::span<::std::byte>) noexcept
        -> void = 0;
};

auto query_parallel_scheduler_backend() -> ::std::shared_ptr<parallel_scheduler_backend>;

} // namespace beman::execution::parallel_scheduler_replacement

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_PARALLEL_SCHEDULER_REPLACEMENT
