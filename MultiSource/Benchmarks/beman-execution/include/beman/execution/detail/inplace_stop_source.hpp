// include/beman/execution/detail/inplace_stop_source.hpp           -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_INPLACE_STOP_SOURCE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_INPLACE_STOP_SOURCE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <atomic>
#include <memory>
#include <mutex>
#include <thread>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.immovable;
#else
#include <beman/execution/detail/immovable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
class inplace_stop_token;
class inplace_stop_source;
template <typename CallbackFun>
class inplace_stop_callback;
template <typename CallbackFun>
inplace_stop_callback(::beman::execution::inplace_stop_token, CallbackFun) -> inplace_stop_callback<CallbackFun>;
} // namespace beman::execution

// ----------------------------------------------------------------------------

class beman::execution::inplace_stop_token {
  public:
    template <typename CallbackFun>
    using callback_type = ::beman::execution::inplace_stop_callback<CallbackFun>;

    inplace_stop_token() = default;

    constexpr auto stop_requested() const noexcept -> bool;
    constexpr auto stop_possible() const noexcept -> bool;
    auto           operator==(const inplace_stop_token&) const -> bool = default;

    auto swap(inplace_stop_token&) noexcept -> void;

  private:
    friend class ::beman::execution::inplace_stop_source;
    template <typename CallbackFun>
    friend class ::beman::execution::inplace_stop_callback;
    explicit inplace_stop_token(::beman::execution::inplace_stop_source* src) : source(src) {}

    ::beman::execution::inplace_stop_source* source{};
};

// ----------------------------------------------------------------------------

class beman::execution::inplace_stop_source {
    struct callback_base : public ::beman::execution::detail::virtual_immovable {
        callback_base* next{};
        virtual auto   call() -> void = 0;
    };

  public:
    auto                  stop_requested() const noexcept -> bool;
    static constexpr auto stop_possible() noexcept -> bool;
    auto                  get_token() const -> ::beman::execution::inplace_stop_token;

    auto request_stop() -> bool;

  private:
    template <typename CallbackFun>
    friend class ::beman::execution::inplace_stop_callback;
    ::std::atomic<bool>           stopped{};
    ::std::atomic<callback_base*> running{};
    ::std::thread::id             id{};
    ::std::mutex                  lock;
    callback_base*                callbacks{};

    auto add(callback_base* cb) -> void;
    auto deregister(callback_base* cb) -> void;
};

// ----------------------------------------------------------------------------

template <typename CallbackFun>
class beman::execution::inplace_stop_callback final : public ::beman::execution::inplace_stop_source::callback_base {
  public:
    using callback_type = CallbackFun;

    template <typename Init>
    inplace_stop_callback(::beman::execution::inplace_stop_token, Init&&);
    inplace_stop_callback(const inplace_stop_callback&) = delete;
    inplace_stop_callback(inplace_stop_callback&&)      = delete;
    ~inplace_stop_callback() override {
        if (this->source) {
            this->source->deregister(this);
        }
    }
    auto operator=(const inplace_stop_callback&) -> inplace_stop_callback& = delete;
    auto operator=(inplace_stop_callback&&) -> inplace_stop_callback&      = delete;

  private:
    auto call() -> void override;

    CallbackFun                              fun;
    ::beman::execution::inplace_stop_source* source;
};

// ----------------------------------------------------------------------------

inline constexpr auto beman::execution::inplace_stop_token::stop_requested() const noexcept -> bool {
    return this->source && this->source->stop_requested();
}

inline constexpr auto beman::execution::inplace_stop_token::stop_possible() const noexcept -> bool {
    return this->source;
}

inline auto beman::execution::inplace_stop_token::swap(inplace_stop_token& other) noexcept -> void {
    ::std::swap(this->source, other.source);
}

inline auto beman::execution::inplace_stop_source::stop_requested() const noexcept -> bool { return this->stopped; }

inline constexpr auto beman::execution::inplace_stop_source::stop_possible() noexcept -> bool { return true; }

inline auto beman::execution::inplace_stop_source::get_token() const -> ::beman::execution::inplace_stop_token {
    return ::beman::execution::inplace_stop_token(const_cast<::beman::execution::inplace_stop_source*>(this));
}

inline auto beman::execution::inplace_stop_source::request_stop() -> bool {
    using relock = ::std::unique_ptr<::std::unique_lock<::std::mutex>, decltype([](auto p) { p->lock(); })>;
    if (false == this->stopped.exchange(true)) {
        ::std::unique_lock guard(this->lock);
        for (auto it = this->callbacks; it != nullptr; it = this->callbacks) {
            this->running   = it;
            this->id        = ::std::this_thread::get_id();
            this->callbacks = it->next;
            {
                relock r(&guard);
                guard.unlock();
                it->call();
            }
            this->running = nullptr;
        }
        return true;
    }
    return false;
}

inline auto beman::execution::inplace_stop_source::add(callback_base* cb) -> void {
    if (this->stopped) {
        cb->call();
    } else {
        ::std::lock_guard guard(this->lock);
        cb->next = ::std::exchange(this->callbacks, cb);
    }
}

inline auto beman::execution::inplace_stop_source::deregister(callback_base* cb) -> void {
    ::std::unique_lock guard(this->lock);
    if (this->running == cb) {
        if (this->id == ::std::this_thread::get_id()) {
            return;
        }
        guard.unlock();
        while (this->running == cb) {
        }
        return;
    }

    for (callback_base** it{&this->callbacks}; *it; it = &(*it)->next) {
        if (*it == cb) {
            *it = cb->next;
            break;
        }
    }
}

template <typename CallbackFun>
template <typename Init>
inline beman::execution::inplace_stop_callback<CallbackFun>::inplace_stop_callback(
    ::beman::execution::inplace_stop_token token, Init&& init)
    : fun(::std::forward<Init>(init)), source(token.source) {
    if (this->source) {
        this->source->add(this);
    }
}

template <typename CallbackFun>
inline auto beman::execution::inplace_stop_callback<CallbackFun>::call() -> void {
    this->fun();
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_INPLACE_STOP_SOURCE
