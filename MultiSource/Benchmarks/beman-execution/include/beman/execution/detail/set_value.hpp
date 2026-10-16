// include/beman/execution/detail/set_value.hpp -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SET_VALUE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SET_VALUE

#include <beman/execution/detail/common.hpp>
#include <beman/execution/detail/suppress_push.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif

namespace beman::execution {
/*!
 * \brief Type of the customization point object for successful completions.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
struct set_value_t {
    template <typename Receiver, typename... Args>
    auto operator()(Receiver&, Args&&...) const
        -> void = BEMAN_EXECUTION_DELETE("set_value requires the receiver to be passed as non-const rvalue");
    template <typename Receiver, typename... Args>
    auto operator()(const Receiver&&, Args&&...) const
        -> void = BEMAN_EXECUTION_DELETE("set_value requires the receiver to be passed as non-const rvalue");
    template <typename Receiver, typename... Args>
    auto operator()(Receiver&&, Args&&...) const -> void
        requires(not requires(Receiver&& receiver, Args&&... args) {
                    ::std::forward<Receiver>(receiver).set_value(::std::forward<Args>(args)...);
                })
    = BEMAN_EXECUTION_DELETE("set_value requires a suitable member overload on the receiver");
    template <typename Receiver, typename... Args>
        requires(not noexcept(::std::declval<Receiver>().set_value(::std::declval<Args>()...)))
    auto operator()(Receiver&&, Args&&...) const
        -> void = BEMAN_EXECUTION_DELETE("the call to receiver.set_value(args...) has to be noexcept");

    template <typename Receiver, typename... Args>
    auto operator()(Receiver&& receiver, Args&&... args) const noexcept -> void {
        static_assert(noexcept(::std::forward<Receiver>(receiver).set_value(::std::forward<Args>(args)...)),
                      "the call to receiver.set_value(args...) has to be noexcept");

        ::std::forward<Receiver>(receiver).set_value(::std::forward<Args>(args)...);
    }
};
/*!
 * \var set_value
 * \brief Customization point object for successful completions.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
inline constexpr set_value_t set_value{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#include <beman/execution/detail/suppress_pop.hpp>

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SET_VALUE
