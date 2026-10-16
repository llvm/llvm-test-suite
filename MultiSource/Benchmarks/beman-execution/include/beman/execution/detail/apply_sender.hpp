// include/beman/execution/detail/apply_sender.hpp                  -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_APPLY_SENDER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_APPLY_SENDER

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <utility>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.default_domain;
import beman.execution.detail.sender;
#else
#include <beman/execution/detail/default_domain.hpp>
#include <beman/execution/detail/sender.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
/*!
 * \brief Function used to transform a sender and its arguments for a domain.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
template <typename Domain, typename Tag, ::beman::execution::sender Sender, typename... Args>
    requires requires(Domain domain, Tag tag, Sender&& sender, Args&&... args) {
        domain.apply_sender(Tag(), ::std::forward<Sender>(sender), ::std::forward<Args>(args)...);
    }
constexpr auto apply_sender(Domain domain, Tag, Sender&& sender, Args&&... args) noexcept(noexcept(
    domain.apply_sender(Tag(), ::std::forward<Sender>(sender), ::std::forward<Args>(args)...))) -> decltype(auto) {
    return domain.apply_sender(Tag(), ::std::forward<Sender>(sender), ::std::forward<Args>(args)...);
}

/*!
 * \brief Default function used to transform a second and its arguments.
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
template <typename Domain, typename Tag, ::beman::execution::sender Sender, typename... Args>
    requires(not requires(Domain domain, Tag tag, Sender&& sender, Args&&... args) {
                domain.apply_sender(Tag(), ::std::forward<Sender>(sender), ::std::forward<Args>(args)...);
            }) && requires(Tag tag, Sender&& sender, Args&&... args) {
        beman::execution::default_domain().apply_sender(
            Tag(), ::std::forward<Sender>(sender), ::std::forward<Args>(args)...);
    }
constexpr auto apply_sender(Domain, Tag, Sender&& sender, Args&&... args) noexcept(
    noexcept(beman::execution::default_domain().apply_sender(Tag(),
                                                             ::std::forward<Sender>(sender),
                                                             ::std::forward<Args>(args)...))) -> decltype(auto) {
    return beman::execution::default_domain().apply_sender(
        Tag(), ::std::forward<Sender>(sender), ::std::forward<Args>(args)...);
}

} // namespace beman::execution

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_APPLY_SENDER
