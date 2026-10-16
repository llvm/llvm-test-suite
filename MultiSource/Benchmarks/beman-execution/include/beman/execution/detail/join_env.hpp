// include/beman/execution/detail/join_env.hpp                      -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_JOIN_ENV
#define INCLUDED_BEMAN_EXECUTION_DETAIL_JOIN_ENV

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#include <utility>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename Env1, typename Env2>
class join_env {
  private:
    Env1 env1;
    Env2 env2;

  public:
    template <typename E1, typename E2>
    join_env(E1&& e1, E2&& e2) : env1(::std::forward<E1>(e1)), env2(::std::forward<E2>(e2)) {}

    template <typename Query, typename... Args>
        requires requires(Env1&, const Query& query, Args&&... args) {
            env1.query(query, ::std::forward<Args>(args)...);
        }
    auto query(const Query& query, Args&&... args) noexcept -> decltype(auto) {
        return this->env1.query(query, ::std::forward<Args>(args)...);
    }
    template <typename Query, typename... Args>
        requires(
            not requires(Env1&, const Query& query, Args&&... args) {
                env1.query(query, ::std::forward<Args>(args)...);
            } &&
            requires(Env2& e2, const Query& query, Args&&... args) { e2.query(query, ::std::forward<Args>(args)...); })
    auto query(const Query& query, Args&&... args) noexcept -> decltype(auto) {
        return this->env2.query(query, ::std::forward<Args>(args)...);
    }
    template <typename Query, typename... Args>
        requires requires(const Env1& e1, const Query& query, Args&&... args) {
            { e1.query(query, ::std::forward<Args>(args)...) } noexcept;
        }
    auto query(const Query& query, Args&&... args) const noexcept -> decltype(auto) {
        return this->env1.query(query, ::std::forward<Args>(args)...);
    }
    template <typename Query, typename... Args>
        requires(
            not requires(const Env1& e1, const Query& query, Args&&... args) {
                { e1.query(query, ::std::forward<Args>(args)...) } noexcept;
            } &&
            requires(const Env2& e2, const Query& query, Args&&... args) {
                { e2.query(query, ::std::forward<Args>(args)...) } noexcept;
            })
    auto query(const Query& query, Args&&... args) const noexcept -> decltype(auto) {
        return this->env2.query(query, ::std::forward<Args>(args)...);
    }
};

template <typename Env1, typename Env2>
join_env(Env1&&, Env2&&) -> join_env<::std::remove_cvref_t<Env1>, ::std::remove_cvref_t<Env2>>;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_JOIN_ENV
