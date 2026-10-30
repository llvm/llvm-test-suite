// include/beman/execution/detail/set_stopped.hpp                   -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SET_STOPPED
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SET_STOPPED

#include <beman/execution/detail/common.hpp>
#include <beman/execution/detail/suppress_push.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
/*!
 * \brief Type of the customization point object for cancellation completions.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
struct set_stopped_t {
    template <typename Receiver>
    auto operator()(Receiver&) const
        -> void = BEMAN_EXECUTION_DELETE("set_stopped requires the receiver to be passed as non-const rvalue");
    template <typename Receiver>
    auto operator()(const Receiver&&) const
        -> void = BEMAN_EXECUTION_DELETE("set_stopped requires the receiver to be passed as non-const rvalue");
    template <typename Receiver>
    auto operator()(Receiver&&) const -> void
        requires(not requires(Receiver&& receiver) { ::std::forward<Receiver>(receiver).set_stopped(); })
    = BEMAN_EXECUTION_DELETE("set_stopped requires a suitable member overload on the receiver");

    template <typename Receiver>
    auto operator()(Receiver&& receiver) const noexcept -> void {
        static_assert(noexcept(::std::forward<Receiver>(receiver).set_stopped()),
                      "the call to receiver.set_stopped() has to be noexcept");
        ::std::forward<Receiver>(receiver).set_stopped();
    }
};

/*!
 * \brief Customization point object for cancellation completions.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
inline constexpr set_stopped_t set_stopped{};
} // namespace beman::execution

// ----------------------------------------------------------------------------

#include <beman/execution/detail/suppress_pop.hpp>

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SET_STOPPED
