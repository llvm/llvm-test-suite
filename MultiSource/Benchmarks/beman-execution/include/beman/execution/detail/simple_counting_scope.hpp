// include/beman/execution/detail/simple_counting_scope.hpp         -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SIMPLE_COUNTING_SCOPE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SIMPLE_COUNTING_SCOPE

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <cstdlib>
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.counting_scope_base;
import beman.execution.detail.counting_scope_join;
import beman.execution.detail.sender;
#else
#include <beman/execution/detail/counting_scope_base.hpp>
#include <beman/execution/detail/counting_scope_join.hpp>
#include <beman/execution/detail/sender.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
class simple_counting_scope;
}

// ----------------------------------------------------------------------------

class beman::execution::simple_counting_scope : public ::beman::execution::detail::counting_scope_base {
  public:
    class token;

    auto get_token() noexcept -> token;
    auto join() noexcept -> ::beman::execution::sender auto {
        return ::beman::execution::detail::counting_scope_join(this);
    }
};

// ----------------------------------------------------------------------------

class beman::execution::simple_counting_scope::token : public beman::execution::simple_counting_scope::token_base {
  public:
    template <::beman::execution::sender Sender>
    auto wrap(Sender&& sender) const noexcept -> Sender&& {
        return ::std::forward<Sender>(sender);
    }

  private:
    friend class beman::execution::simple_counting_scope;
    explicit token(::beman::execution::detail::counting_scope_base* s) : token_base(s) {}
};

// ----------------------------------------------------------------------------

inline auto beman::execution::simple_counting_scope::get_token() noexcept
    -> beman::execution::simple_counting_scope::token {
    return beman::execution::simple_counting_scope::token(this);
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SIMPLE_COUNTING_SCOPE
