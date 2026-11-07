// include/beman/execution/detail/default_parallel_scheduler_backend.hpp            -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_DEFAULT_PARALLEL_SCHEDULER_BACKEND
#define INCLUDED_BEMAN_EXECUTION_DETAIL_DEFAULT_PARALLEL_SCHEDULER_BACKEND
#if BEMAN_EXECUTION_WITH_DEFAULT_PARALLEL_SCHEDULER_BACKEND

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <memory>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.parallel_scheduler_replacement;
import beman.execution.detail.thread_pool_backend;
#else
#include <beman/execution/detail/parallel_scheduler_replacement.hpp>
#include <beman/execution/detail/thread_pool_backend.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::parallel_scheduler_replacement {
inline auto query_parallel_scheduler_backend() -> ::std::shared_ptr<parallel_scheduler_backend> {
    static auto backend = ::std::make_shared<::beman::execution::detail::thread_pool_backend>();
    return backend;
}
} // namespace beman::execution::parallel_scheduler_replacement

// ----------------------------------------------------------------------------

#endif // BEMAN_EXECUTION_WITH_DEFAULT_PARALLEL_SCHEDULER_BACKEND
#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_DEFAULT_PARALLEL_SCHEDULER_BACKEND
