// include/beman/execution/detail/counting_scope_base.hpp             -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_COUNTING_SCOPE_BASE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_COUNTING_SCOPE_BASE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <cstddef>
#include <exception>
#include <limits>
#include <mutex>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.immovable;
import beman.execution.detail.unreachable;
#else
#include <beman/execution/detail/immovable.hpp>
#include <beman/execution/detail/unreachable.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
class counting_scope_base;
}

// ----------------------------------------------------------------------------

class beman::execution::detail::counting_scope_base : ::beman::execution::detail::immovable {
  public:
    counting_scope_base()                      = default;
    counting_scope_base(counting_scope_base&&) = delete;
    ~counting_scope_base();

    static constexpr ::std::size_t max_associations = ::std::numeric_limits<::std::size_t>::max();

    auto close() noexcept -> void;

    struct node {
        virtual auto complete() noexcept -> void        = 0;
        virtual auto complete_inline() noexcept -> void = 0;
        node*        next{};
    };
    auto start_node(node*) -> void;

  protected:
    class assoc_t {
      public:
        assoc_t() = default;

        explicit assoc_t(counting_scope_base& scope) noexcept : scope(&scope) {}

        assoc_t(const assoc_t&) = delete;

        assoc_t(assoc_t&& other) noexcept : scope(::std::exchange(other.scope, nullptr)) {}

        ~assoc_t() {
            if (this->scope) {
                this->scope->disassociate();
            }
        }

        auto operator=(assoc_t other) noexcept -> assoc_t& {
            ::std::swap(scope, other.scope);
            return *this;
        }

        explicit operator bool() const noexcept { return this->scope != nullptr; }

        auto try_associate() const noexcept -> assoc_t {
            if (this->scope) {
                return this->scope->try_associate();
            }
            return assoc_t{};
        }

      private:
        counting_scope_base* scope = nullptr;
    };

    class token_base {
      public:
        auto try_associate() const noexcept -> assoc_t { return this->scope->try_associate(); }

      protected:
        explicit token_base(counting_scope_base* s) : scope(s) {}
        counting_scope_base* scope;
    };

  public:
    enum class state_t : unsigned char {
        unused,
        open,
        open_and_joining,
        closed,
        closed_and_joining,
        unused_and_closed,
        joined
    };

  private:
    auto try_associate() noexcept -> assoc_t;

    auto disassociate() noexcept -> void;

    auto add_node(node* n) noexcept -> void;

    ::std::mutex mutex;
    //-dk:TODO fuse state and count and use atomic accesses
    ::std::size_t count{};
    state_t       state{state_t::unused};
    node*         head{};
};

// ----------------------------------------------------------------------------

inline beman::execution::detail::counting_scope_base::~counting_scope_base() {
    ::std::lock_guard kerberos(this->mutex);
    switch (this->state) {
    default:
        ::std::terminate();
    case state_t::unused:
    case state_t::unused_and_closed:
    case state_t::joined:
        break;
    }
}

inline auto beman::execution::detail::counting_scope_base::close() noexcept -> void {
    switch (this->state) {
    default:
        break;
    case state_t::unused:
        this->state = state_t::unused_and_closed;
        break;
    case state_t::open:
        this->state = state_t::closed;
        break;
    case state_t::open_and_joining:
        this->state = state_t::closed_and_joining;
        break;
    }
}

inline auto beman::execution::detail::counting_scope_base::add_node(node* n) noexcept -> void {
    n->next = ::std::exchange(this->head, n);
}

inline auto beman::execution::detail::counting_scope_base::try_associate() noexcept -> assoc_t {
    ::std::lock_guard lock(this->mutex);
    if (this->count == max_associations) {
        return assoc_t{};
    }

    switch (this->state) {
    default:
        return assoc_t{};
    case state_t::unused:
        this->state = state_t::open; // fall-through!
        [[fallthrough]];
    case state_t::open:
    case state_t::open_and_joining:
        ++this->count;
        return assoc_t{*this};
    }
}

inline auto beman::execution::detail::counting_scope_base::disassociate() noexcept -> void {
    ::std::unique_lock guard(this->mutex);
    if (--this->count > 0u || (this->state != state_t::open_and_joining && this->state != state_t::closed_and_joining))
        return;

    this->state   = state_t::joined;
    node* current = ::std::exchange(this->head, nullptr);
    guard.unlock();

    while (current) {
        ::std::exchange(current, current->next)->complete();
    }
}

inline auto beman::execution::detail::counting_scope_base::start_node(node* n) -> void {
    ::std::unique_lock guard(this->mutex);
    if (this->count == 0u) {
        this->state = state_t::joined;
        guard.unlock();
        n->complete_inline();
        return;
    }

    switch (this->state) {
    case state_t::open:
        this->state = state_t::open_and_joining;
        break;
    case state_t::open_and_joining:
        break;
    case state_t::closed:
        this->state = state_t::closed_and_joining;
        break;
    case state_t::closed_and_joining:
        break;
    default:
        ::beman::execution::detail::unreachable();
    }
    this->add_node(n);
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_COUNTING_SCOPE_BASE
