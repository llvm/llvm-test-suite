// include/beman/execution/detail/parallel_scheduler.hpp            -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_PARALLEL_SCHEDULER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_PARALLEL_SCHEDULER

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
import beman.execution.detail.bulk;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.env_of_t;
import beman.execution.detail.execution_policy;
import beman.execution.detail.forward_like;
import beman.execution.detail.get_completion_domain;
import beman.execution.detail.get_completion_scheduler;
import beman.execution.detail.get_env;
import beman.execution.detail.get_forward_progress_guarantee;
import beman.execution.detail.get_stop_token;
import beman.execution.detail.inplace_stop_source;
import beman.execution.detail.operation_state;
import beman.execution.detail.psched_bulk_sender;
import beman.execution.detail.parallel_scheduler_replacement;
import beman.execution.detail.receiver;
import beman.execution.detail.scheduler_tag;
import beman.execution.detail.sender;
import beman.execution.detail.tag_of_t;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.stop_propagator;
import beman.execution.detail.stop_token_of_t;
#else
#include <beman/execution/detail/bulk.hpp>
#include <beman/execution/detail/completion_signatures.hpp>
#include <beman/execution/detail/default_parallel_scheduler_backend.hpp> // IWYU pragma: keep
#include <beman/execution/detail/env_of_t.hpp>
#include <beman/execution/detail/execution_policy.hpp>
#include <beman/execution/detail/forward_like.hpp>
#include <beman/execution/detail/get_completion_domain.hpp>
#include <beman/execution/detail/get_completion_scheduler.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/get_forward_progress_guarantee.hpp>
#include <beman/execution/detail/get_stop_token.hpp>
#include <beman/execution/detail/inplace_stop_source.hpp>
#include <beman/execution/detail/operation_state.hpp>
#include <beman/execution/detail/psched_bulk_sender.hpp>
#include <beman/execution/detail/parallel_scheduler_replacement.hpp>
#include <beman/execution/detail/receiver.hpp>
#include <beman/execution/detail/scheduler_tag.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/stop_propagator.hpp>
#include <beman/execution/detail/stop_token_of_t.hpp>
#include <beman/execution/detail/tag_of_t.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct parallel_scheduler_domain {
    template <typename Sndr>
        requires ::std::same_as<::beman::execution::tag_of_t<Sndr>, ::beman::execution::bulk_chunked_t> ||
                 ::std::same_as<::beman::execution::tag_of_t<Sndr>, ::beman::execution::bulk_unchunked_t>
    static auto transform_sender(::beman::execution::set_value_t, Sndr&& sndr, const auto&) noexcept {
        auto&& [_, data, child]  = ::std::forward<Sndr>(sndr);
        auto [policy, shape, fn] = ::beman::execution::detail::forward_like<Sndr>(data);
        return ::beman::execution::detail::psched_bulk_sender{
            ::std::bool_constant<
                ::std::same_as<::beman::execution::tag_of_t<Sndr>, ::beman::execution::bulk_chunked_t>>{},
            ::beman::execution::parallel_scheduler_replacement::query_parallel_scheduler_backend(),
            ::std::move(policy),
            ::std::move(shape),
            ::std::move(fn),
            ::beman::execution::detail::forward_like<Sndr>(child)};
    }
};
} // namespace beman::execution::detail

namespace beman::execution {

class parallel_scheduler {
    using backend_type = ::beman::execution::parallel_scheduler_replacement::parallel_scheduler_backend;

  public:
    using scheduler_concept = ::beman::execution::scheduler_tag;

    class sender;

    parallel_scheduler()  = delete;
    ~parallel_scheduler() = default;

    parallel_scheduler(const parallel_scheduler&) noexcept                    = default;
    parallel_scheduler(parallel_scheduler&&) noexcept                         = default;
    auto operator=(const parallel_scheduler&) noexcept -> parallel_scheduler& = default;
    auto operator=(parallel_scheduler&&) noexcept -> parallel_scheduler&      = default;

    auto operator==(const parallel_scheduler& other) const noexcept -> bool {
        return this->backend_ == other.backend_;
    }

    static constexpr auto query(::beman::execution::get_forward_progress_guarantee_t) noexcept
        -> ::beman::execution::forward_progress_guarantee {
        return ::beman::execution::forward_progress_guarantee::parallel;
    }

    static constexpr auto query(::beman::execution::get_completion_domain_t<::beman::execution::set_value_t>) noexcept
        -> ::beman::execution::detail::parallel_scheduler_domain {
        return {};
    }

    auto schedule() const noexcept -> sender;

  private:
    explicit parallel_scheduler(::std::shared_ptr<backend_type> backend) noexcept : backend_(::std::move(backend)) {}

    ::std::shared_ptr<backend_type> backend_;

    friend auto get_parallel_scheduler() -> parallel_scheduler;
};

class parallel_scheduler::sender {
    using backend_type = ::beman::execution::parallel_scheduler_replacement::parallel_scheduler_backend;

  public:
    using sender_concept = ::beman::execution::sender_tag;
    using completion_signatures =
        ::beman::execution::completion_signatures<::beman::execution::set_value_t(),
                                                  ::beman::execution::set_error_t(::std::exception_ptr),
                                                  ::beman::execution::set_stopped_t()>;

    class env {
      public:
        explicit env(::std::shared_ptr<backend_type> backend) noexcept : backend_(::std::move(backend)) {}

        auto
        query(const ::beman::execution::get_completion_scheduler_t<::beman::execution::set_value_t>&) const noexcept
            -> ::beman::execution::parallel_scheduler {
            return ::beman::execution::parallel_scheduler{this->backend_};
        }

      private:
        ::std::shared_ptr<backend_type> backend_;
    };

    template <typename Rcvr>
    struct rcvr_proxy : ::beman::execution::parallel_scheduler_replacement::receiver_proxy {
        using stop_token_t = ::beman::execution::stop_token_of_t<::beman::execution::env_of_t<Rcvr>>;

        explicit rcvr_proxy(Rcvr rcvr) noexcept
            : sp_(::beman::execution::get_stop_token(::beman::execution::get_env(rcvr))), rcvr_(::std::move(rcvr)) {}

        auto set_value() noexcept -> void final { ::beman::execution::set_value(::std::move(this->rcvr_)); }

        auto set_error(::std::exception_ptr error) noexcept -> void final {
            ::beman::execution::set_error(::std::move(this->rcvr_), ::std::move(error));
        }

        auto set_stopped() noexcept -> void final { ::beman::execution::set_stopped(::std::move(this->rcvr_)); }

      private:
        auto query_stop_token() const noexcept -> ::std::optional<::beman::execution::inplace_stop_token> final {
            return sp_.get_token();
        }

        [[no_unique_address]] ::beman::execution::detail::stop_propagator<stop_token_t> sp_;
        Rcvr                                                                            rcvr_;
    };

    template <::beman::execution::receiver Rcvr>
    class operation {
      public:
        using operation_state_concept = ::beman::execution::operation_state_tag;
        using stop_token_t            = ::beman::execution::stop_token_of_t<::beman::execution::env_of_t<Rcvr>>;

        operation(::std::shared_ptr<backend_type> backend,
                  Rcvr&& rcvr) noexcept(::std::is_nothrow_constructible_v<::std::remove_cvref_t<Rcvr>, Rcvr>)
            : backend_(::std::move(backend)), proxy_(::std::forward<Rcvr>(rcvr)) {}

        auto start() & noexcept -> void {
            auto stop_token =
                proxy_.template try_query<::beman::execution::inplace_stop_token>(::beman::execution::get_stop_token);
            if (stop_token.has_value() && stop_token->stop_requested()) {
                proxy_.set_stopped();
                return;
            }
            this->backend_->schedule(proxy_, ::std::span<::std::byte>{this->storage_});
        }

      private:
        ::std::shared_ptr<backend_type>         backend_;
        rcvr_proxy<::std::remove_cvref_t<Rcvr>> proxy_;
        alignas(::beman::execution::detail::psched_storage_alignment)::std::byte
            storage_[::beman::execution::detail::psched_storage_size];
    };

    explicit sender(::std::shared_ptr<backend_type> backend) noexcept : backend_(::std::move(backend)) {}

    template <typename...>
    static consteval auto get_completion_signatures() noexcept -> completion_signatures {
        return {};
    }

    auto get_env() const noexcept -> env { return env{this->backend_}; }

    template <::beman::execution::receiver Rcvr>
    auto connect(Rcvr&& rcvr) & noexcept(::std::is_nothrow_constructible_v<::std::remove_cvref_t<Rcvr>, Rcvr>)
        -> operation<Rcvr> {
        return operation<Rcvr>{this->backend_, ::std::forward<Rcvr>(rcvr)};
    }

    template <::beman::execution::receiver Rcvr>
    auto connect(Rcvr&& rcvr) && noexcept(::std::is_nothrow_constructible_v<::std::remove_cvref_t<Rcvr>, Rcvr>)
        -> operation<Rcvr> {
        return operation<Rcvr>{::std::move(this->backend_), ::std::forward<Rcvr>(rcvr)};
    }

  private:
    ::std::shared_ptr<backend_type> backend_;
};

inline auto parallel_scheduler::schedule() const noexcept -> sender { return sender{this->backend_}; }

[[nodiscard]] inline auto get_parallel_scheduler() -> parallel_scheduler {
    auto backend = ::beman::execution::parallel_scheduler_replacement::query_parallel_scheduler_backend();
    if (backend == nullptr) [[unlikely]] {
        ::std::terminate();
    }
    return parallel_scheduler{::std::move(backend)};
}

} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_PARALLEL_SCHEDULER
