// include/beman/execution/detail/common.hpp                        -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_COMMON
#define INCLUDED_BEMAN_EXECUTION_DETAIL_COMMON

// ----------------------------------------------------------------------------

#if defined(disabled__cpp_deleted_function)
#define BEMAN_EXECUTION_DELETE(msg) delete (msg)
#else
#define BEMAN_EXECUTION_DELETE(msg) delete
#endif
#if defined(__GNUC__) && !defined(__clang__)
#define BEMAN_SPECIALIZE_EXPORT
#else
#define BEMAN_SPECIALIZE_EXPORT template <>
#endif

#ifndef BEMAN_EXECUTION_WITH_DEFAULT_PARALLEL_SCHEDULER_BACKEND
#define BEMAN_EXECUTION_WITH_DEFAULT_PARALLEL_SCHEDULER_BACKEND 1
#endif

#define BEMAN_EXECUTION_TRY_EVAL(rcvr, expr)                                                    \
    do {                                                                                        \
        try {                                                                                   \
            (expr);                                                                             \
        } catch (...) {                                                                         \
            if constexpr (!noexcept((expr))) {                                                  \
                ::beman::execution::set_error(::std::move((rcvr)), ::std::current_exception()); \
            }                                                                                   \
        }                                                                                       \
    } while (false)

// ----------------------------------------------------------------------------
/*!
 * \mainpage Asynchronous Operation Support
 *
 * This project implements the C++ support for asynchronous operations,
 * knows as _sender/receiver_ or `std::execution`.
 *
 * There are a few ingredients to using `std::execution`:
 *
 * - Sender algorithms to composes work into an asynchronous workflow.
 * - Something holding and starting senders like `sync_wait()`
 *   or `counting_scope`.
 * - A coroutine binding like `task` to make sender composition
 *   easier for typical use cases.
 * - Some tools like a sender-aware `concurrent_queue`.
 * - Senders describing some asynchronous work. Sadly, there are
 *   currently no such senders are proposed.
 */

/*!
 * \namespace beman
 * \brief Namespace for Beman projects http://github.com/bemanproject/beman
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
namespace beman {
/*!
 * \namespace beman::execution
 * \brief Namespace for asynchronous operations and their vocabulary.
 *
 * \details
 * The beman::execution namespace contains various components for
 * accessing asynchronous operations.
 *
 * \headerfile beman/execution.hpp <beman/execution.hpp>
 */
namespace execution {

/*!
 * \namespace beman::execution::detail
 * \brief Namespace for implementation details related to beman::execution
 * \internal
 */
namespace detail {

/*!
 * \namespace beman::execution::detail::pipeable
 * \brief Namespace for ADL isolation of sender adaptor closure pipe operators.
 *
 * \details
 * The operator| overloads for sender adaptor closures are placed in this
 * namespace so they are only found via argument-dependent lookup when one
 * of the arguments derives from sender_adaptor_closure.
 * \internal
 */
namespace pipeable {}
} // namespace detail
} // namespace execution
} // namespace beman

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_COMMON
