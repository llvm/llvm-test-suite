// include/beman/execution/detail/task_scheduler.hpp                -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_TASK_SCHEDULER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_TASK_SCHEDULER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <algorithm>
#include <concepts>
#include <exception>
#include <memory>
#include <optional>
#include <span>
#include <type_traits>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.bulk;
import beman.execution.detail.call_with_default;
import beman.execution.detail.completion_signatures;
import beman.execution.detail.connect;
import beman.execution.detail.connect_result_t;
import beman.execution.detail.env;
import beman.execution.detail.env_of_t;
import beman.execution.detail.execution_policy;
import beman.execution.detail.fwd_env;
import beman.execution.detail.forward_like;
import beman.execution.detail.get_completion_domain;
import beman.execution.detail.get_completion_scheduler;
import beman.execution.detail.get_env;
import beman.execution.detail.get_forward_progress_guarantee;
import beman.execution.detail.get_stop_token;
import beman.execution.detail.infallible_scheduler;
import beman.execution.detail.inplace_stop_source;
import beman.execution.detail.new_object;
import beman.execution.detail.operation_state;
import beman.execution.detail.psched_bulk_sender;
import beman.execution.detail.parallel_scheduler_replacement;
import beman.execution.detail.prop;
import beman.execution.detail.query_with_default;
import beman.execution.detail.receiver;
import beman.execution.detail.schedule;
import beman.execution.detail.schedule_result_t;
import beman.execution.detail.scheduler;
import beman.execution.detail.scheduler_tag;
import beman.execution.detail.sender;
import beman.execution.detail.set_error;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.simple_allocator;
import beman.execution.detail.start;
import beman.execution.detail.stop_propagator;
import beman.execution.detail.stop_token_of_t;
import beman.execution.detail.tag_of_t;
import beman.execution.detail.unreachable;
import beman.execution.detail.unstoppable_token;
#else
#include <beman/execution/detail/bulk.hpp>
#include <beman/execution/detail/call_with_default.hpp>
#include <beman/execution/detail/completion_signatures.hpp>
#include <beman/execution/detail/connect.hpp>
#include <beman/execution/detail/connect_result_t.hpp>
#include <beman/execution/detail/env.hpp>
#include <beman/execution/detail/env_of_t.hpp>
#include <beman/execution/detail/execution_policy.hpp>
#include <beman/execution/detail/fwd_env.hpp>
#include <beman/execution/detail/forward_like.hpp>
#include <beman/execution/detail/get_completion_domain.hpp>
#include <beman/execution/detail/get_completion_scheduler.hpp>
#include <beman/execution/detail/get_env.hpp>
#include <beman/execution/detail/get_forward_progress_guarantee.hpp>
#include <beman/execution/detail/get_stop_token.hpp>
#include <beman/execution/detail/infallible_scheduler.hpp>
#include <beman/execution/detail/inplace_stop_source.hpp>
#include <beman/execution/detail/new_object.hpp>
#include <beman/execution/detail/operation_state.hpp>
#include <beman/execution/detail/psched_bulk_sender.hpp>
#include <beman/execution/detail/parallel_scheduler_replacement.hpp>
#include <beman/execution/detail/prop.hpp>
#include <beman/execution/detail/query_with_default.hpp>
#include <beman/execution/detail/receiver.hpp>
#include <beman/execution/detail/schedule.hpp>
#include <beman/execution/detail/schedule_result_t.hpp>
#include <beman/execution/detail/scheduler.hpp>
#include <beman/execution/detail/scheduler_tag.hpp>
#include <beman/execution/detail/sender.hpp>
#include <beman/execution/detail/set_error.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/start.hpp>
#include <beman/execution/detail/simple_allocator.hpp>
#include <beman/execution/detail/stop_propagator.hpp>
#include <beman/execution/detail/stop_token_of_t.hpp>
#include <beman/execution/detail/tag_of_t.hpp>
#include <beman/execution/detail/unreachable.hpp>
#include <beman/execution/detail/unstoppable_token.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
struct task_scheduler_backend : ::beman::execution::parallel_scheduler_replacement::parallel_scheduler_backend {
    // ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
    struct state_holder_base {
        virtual ~state_holder_base()            = default;
        virtual auto destroy() noexcept -> void = 0;
    };

    struct rcvr_wrapper {
        using receiver_concept = ::beman::execution::receiver_tag;

        auto set_value() noexcept -> void {
            auto& proxy_ref = proxy;
            holder.destroy();
            proxy_ref.set_value();
        }

        auto set_error(::std::exception_ptr error) noexcept -> void {
            auto& proxy_ref = proxy;
            holder.destroy();
            proxy_ref.set_error(::std::move(error));
        }

        auto set_stopped() noexcept -> void {
            auto& proxy_ref = proxy;
            holder.destroy();
            proxy_ref.set_stopped();
        }

        auto get_env() const noexcept {
            return ::beman::execution::prop{
                ::beman::execution::get_stop_token,
                proxy.try_query<::beman::execution::inplace_stop_token>(::beman::execution::get_stop_token)
                    .value_or(::beman::execution::inplace_stop_token{})};
        }

        ::beman::execution::parallel_scheduler_replacement::receiver_proxy& proxy;
        state_holder_base&                                                  holder;
    };

    template <typename Sndr, typename Alloc>
    // ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
    struct allocated_state_holder : state_holder_base {
        using op_t = ::beman::execution::connect_result_t<Sndr, rcvr_wrapper>;

        allocated_state_holder(Sndr                                                                sndr,
                               ::beman::execution::parallel_scheduler_replacement::receiver_proxy& proxy,
                               Alloc                                                               alloc)
            : alloc(std::move(alloc)),
              op(::beman::execution::connect(::std::move(sndr), rcvr_wrapper{proxy, *this})) {}

        auto destroy() noexcept -> void override { ::beman::execution::detail::delete_object(alloc, this); }

        auto do_start() noexcept -> void { ::beman::execution::start(op); }

        [[no_unique_address]] Alloc alloc;
        op_t                        op;
    };

    template <typename Sndr>
    // ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
    struct inlined_state_holder : state_holder_base {
        using op_t = ::beman::execution::connect_result_t<Sndr, rcvr_wrapper>;

        inlined_state_holder(Sndr sndr, ::beman::execution::parallel_scheduler_replacement::receiver_proxy& proxy)
            : op(::beman::execution::connect(::std::move(sndr), rcvr_wrapper{proxy, *this})) {}

        auto destroy() noexcept -> void override { ::std::destroy_at(this); }

        auto do_start() noexcept -> void { ::beman::execution::start(op); }

        op_t op;
    };

    virtual auto get_forward_progress_guarantee() const noexcept -> ::beman::execution::forward_progress_guarantee = 0;

    virtual auto do_equals(const task_scheduler_backend&) const noexcept -> bool = 0;
};

template <typename Sched>
struct task_scheduler_backend_sched : task_scheduler_backend {
    struct just_sndr_like {
        using sender_concept        = ::beman::execution::sender_tag;
        using completion_signatures = ::beman::execution::completion_signatures<::beman::execution::set_value_t()>;
        struct attr {
            template <typename... Args>
            auto query(::beman::execution::get_completion_scheduler_t<::beman::execution::set_value_t>,
                       const Args&... args) const noexcept {
                return ::beman::execution::get_completion_scheduler<::beman::execution::set_value_t>(sched, args...);
            }

            Sched sched;
        };

        template <typename Rcvr>
        struct state {
            using operation_state_concept = ::beman::execution::operation_state_tag;

            auto start() & noexcept -> void { ::beman::execution::set_value(::std::move(rcvr)); }

            Rcvr rcvr;
        };

        template <typename...>
        static consteval auto get_completion_signatures() noexcept {
            return completion_signatures{};
        }

        auto get_env() const noexcept -> attr { return attr{sched}; }

        template <::beman::execution::receiver Rcvr>
        auto connect(Rcvr rcvr) noexcept -> state<Rcvr> {
            return state<Rcvr>(::std::move(rcvr));
        }

        Sched sched;
    };

    explicit task_scheduler_backend_sched(Sched sched) noexcept : sched(::std::move(sched)) {}

    auto get_forward_progress_guarantee() const noexcept -> ::beman::execution::forward_progress_guarantee override {
        return ::beman::execution::get_forward_progress_guarantee(sched);
    }

    auto do_equals(const task_scheduler_backend& other) const noexcept -> bool override {
        if (auto o = dynamic_cast<const task_scheduler_backend_sched*>(&other)) {
            return o->sched == sched;
        }
        return false;
    }

    Sched sched;
};

template <typename Sched, typename Alloc>
struct task_scheduler_backend_for : task_scheduler_backend_sched<Sched> {
    using base = task_scheduler_backend_sched<Sched>;
    using typename base::just_sndr_like;

    task_scheduler_backend_for(Sched sched, Alloc alloc) noexcept
        : base(::std::move(sched)), alloc(::std::move(alloc)) {}

    task_scheduler_backend_for(const task_scheduler_backend_for&) = delete;

    ~task_scheduler_backend_for() override = default;

    auto operator=(const task_scheduler_backend_for&) -> task_scheduler_backend_for& = delete;

    auto schedule(::beman::execution::parallel_scheduler_replacement::receiver_proxy& proxy,
                  ::std::span<::std::byte> storage) noexcept -> void override {
        this->fire_and_forget(storage, ::beman::execution::schedule(this->sched), proxy);
    }

    auto schedule_bulk_chunked(::std::size_t                                                                 shape,
                               ::beman::execution::parallel_scheduler_replacement::bulk_item_receiver_proxy& proxy,
                               ::std::span<::std::byte> storage) noexcept -> void override {
        this->fire_and_forget(storage,
                              ::beman::execution::bulk_chunked(
                                  just_sndr_like{this->sched},
                                  ::beman::execution::par,
                                  shape,
                                  [&proxy](::std::size_t i, ::std::size_t j) noexcept { proxy.execute(i, j); }),
                              proxy);
    }

    auto schedule_bulk_unchunked(::std::size_t                                                                 shape,
                                 ::beman::execution::parallel_scheduler_replacement::bulk_item_receiver_proxy& proxy,
                                 ::std::span<::std::byte> storage) noexcept -> void override {
        this->fire_and_forget(
            storage,
            ::beman::execution::bulk_unchunked(just_sndr_like{this->sched},
                                               ::beman::execution::par,
                                               shape,
                                               [&proxy](::std::size_t i) noexcept { proxy.execute(i, i + 1uz); }),
            proxy);
    }

    template <typename Sndr>
    auto fire_and_forget(::std::span<::std::byte>                                            storage,
                         Sndr                                                                sndr,
                         ::beman::execution::parallel_scheduler_replacement::receiver_proxy& proxy) const noexcept
        -> void {
        using inlined_holder   = typename base::template inlined_state_holder<Sndr>;
        using allocated_holder = typename base::template allocated_state_holder<Sndr, Alloc>;
        constexpr bool inlined =
            sizeof(inlined_holder) <= psched_storage_size && alignof(inlined_holder) <= psched_storage_alignment;
        try {
            if constexpr (inlined) {
                auto holder = ::new (static_cast<void*>(storage.data())) inlined_holder(::std::move(sndr), proxy);
                holder->do_start();
            } else {
                auto holder =
                    ::beman::execution::detail::new_object<allocated_holder>(alloc, ::std::move(sndr), proxy, alloc);
                holder->do_start();
            }
        } catch (...) {
            proxy.set_error(::std::current_exception());
        }
    }

    [[no_unique_address]] Alloc alloc;
};
} // namespace beman::execution::detail

namespace beman::execution {
class task_scheduler {
  public:
    using scheduler_concept = ::beman::execution::scheduler_tag;
    class sender;
    struct domain {
        struct not_a_scheduler {};
        template <typename Sndr>
            requires ::std::same_as<::beman::execution::tag_of_t<Sndr>, ::beman::execution::bulk_chunked_t> ||
                     ::std::same_as<::beman::execution::tag_of_t<Sndr>, ::beman::execution::bulk_unchunked_t>
        static auto transform_sender(::beman::execution::set_value_t, Sndr&& sndr, const auto& env) noexcept {
            auto&& [_, data, child]  = ::std::forward<Sndr>(sndr);
            auto [policy, shape, fn] = ::beman::execution::detail::forward_like<Sndr>(data);
            auto sch                 = ::beman::execution::detail::call_with_default(
                ::beman::execution::get_completion_scheduler<::beman::execution::set_value_t>,
                not_a_scheduler{},
                ::beman::execution::get_env(child),
                ::beman::execution::detail::fwd_env(env));

            static_assert(::std::same_as<decltype(sch), task_scheduler>,
                          "the completion scheduler of `sndr` shall be a `task_scheduler`.");

            return ::beman::execution::detail::psched_bulk_sender{
                ::std::bool_constant<
                    ::std::same_as<::beman::execution::tag_of_t<Sndr>, ::beman::execution::bulk_chunked_t>>{},
                sch.backend_,
                ::std::move(policy),
                ::std::move(shape),
                ::std::move(fn),
                ::beman::execution::detail::forward_like<Sndr>(child)};
        }
    };

    template <typename Sched, ::beman::execution::detail::simple_allocator Alloc = ::std::allocator<::std::byte>>
        requires(!::std::same_as<task_scheduler, ::std::remove_cvref_t<Sched>>) &&
                ::beman::execution::detail::infallible_scheduler<Sched, ::beman::execution::env<>>
    explicit task_scheduler(Sched&& sched, Alloc alloc = {})
        : backend_(::std::allocate_shared<
                   ::beman::execution::detail::task_scheduler_backend_for<::std::remove_cvref_t<Sched>, Alloc>>(
              alloc, ::std::forward<Sched>(sched), ::std::move(alloc))) {}

    template <::beman::execution::detail::simple_allocator Alloc>
    explicit task_scheduler(task_scheduler sched, const Alloc&) noexcept : task_scheduler(::std::move(sched)) {}

    auto schedule() const noexcept -> sender;

    auto query(::beman::execution::get_forward_progress_guarantee_t) const noexcept {
        return backend_->get_forward_progress_guarantee();
    }

    static auto query(::beman::execution::get_completion_domain_t<::beman::execution::set_value_t>) noexcept {
        return domain{};
    }

    friend auto operator==(const task_scheduler& lhs, const task_scheduler& rhs) noexcept -> bool {
        if (lhs.backend_ == nullptr) {
            return rhs.backend_ == nullptr;
        }
        if (rhs.backend_ == nullptr) {
            return false;
        }
        return lhs.backend_->do_equals(*rhs.backend_);
    }

    template <typename Sched>
        requires(!::std::same_as<Sched, task_scheduler>) && ::beman::execution::scheduler<Sched>
    auto operator==(const Sched& other) const noexcept -> bool {
        auto b = dynamic_cast<const ::beman::execution::detail::task_scheduler_backend_sched<Sched>*>(backend_.get());
        return b && b->sched == other;
    }

  private:
    explicit task_scheduler(::std::shared_ptr<::beman::execution::detail::task_scheduler_backend> backend) noexcept
        : backend_(std::move(backend)) {}

    ::std::shared_ptr<::beman::execution::detail::task_scheduler_backend> backend_;
};

class task_scheduler::sender {
    using backend_type = ::beman::execution::detail::task_scheduler_backend;

  public:
    using sender_concept = ::beman::execution::sender_tag;

    class env {
      public:
        explicit env(::std::shared_ptr<backend_type> backend) noexcept : backend_(::std::move(backend)) {}

        auto
        query(const ::beman::execution::get_completion_scheduler_t<::beman::execution::set_value_t>&) const noexcept
            -> ::beman::execution::task_scheduler {
            return ::beman::execution::task_scheduler{this->backend_};
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

        auto set_error(::std::exception_ptr) noexcept -> void final { ::beman::execution::detail::unreachable(); }

        auto set_stopped() noexcept -> void final {
            if constexpr (::beman::execution::unstoppable_token<stop_token_t>) {
                ::beman::execution::detail::unreachable();
            } else {
                ::beman::execution::set_stopped(::std::move(this->rcvr_));
            }
        }

      private:
        auto query_stop_token() const noexcept -> ::std::optional<::beman::execution::inplace_stop_token> final {
            return sp_.get_token();
        }

        [[no_unique_address]] ::beman::execution::detail::stop_propagator<stop_token_t> sp_;
        Rcvr                                                                            rcvr_;
    };

    template <::beman::execution::receiver Rcvr>
    class state {
      public:
        using operation_state_concept = ::beman::execution::operation_state_tag;
        using stop_token_t            = ::beman::execution::stop_token_of_t<::beman::execution::env_of_t<Rcvr>>;

        state(::std::shared_ptr<backend_type> backend,
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

    template <typename, typename Env>
    static consteval auto get_completion_signatures() noexcept {
        if constexpr (::beman::execution::unstoppable_token<::beman::execution::stop_token_of_t<Env>>) {
            return ::beman::execution::completion_signatures<::beman::execution::set_value_t()>{};
        } else {
            return ::beman::execution::completion_signatures<::beman::execution::set_value_t(),
                                                             ::beman::execution::set_stopped_t()>{};
        }
    }

    auto get_env() const noexcept -> env { return env{this->backend_}; }

    template <::beman::execution::receiver Rcvr>
    auto connect(Rcvr&& rcvr) && noexcept(::std::is_nothrow_constructible_v<::std::remove_cvref_t<Rcvr>, Rcvr>)
        -> state<Rcvr> {
        return state<Rcvr>{::std::move(this->backend_), ::std::forward<Rcvr>(rcvr)};
    }

  private:
    ::std::shared_ptr<backend_type> backend_;
};

inline auto task_scheduler::schedule() const noexcept -> sender { return sender{this->backend_}; }

} // namespace beman::execution

#ifndef BEMAN_HAS_MODULES
template <typename Alloc>
struct std::uses_allocator<::beman::execution::task_scheduler, Alloc> : ::std::true_type {};
#endif

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_TASK_SCHEDULER
