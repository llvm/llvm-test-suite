// include/beman/execution/detail/schedule_result_t.hpp             -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SCHEDULE_RESULT
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SCHEDULE_RESULT

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.schedule;
import beman.execution.detail.scheduler;
#else
#include <beman/execution/detail/schedule.hpp>
#include <beman/execution/detail/scheduler.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
template <::beman::execution::scheduler Scheduler>
using schedule_result_t = decltype(::beman::execution::schedule(::std::declval<Scheduler>()));
}

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SCHEDULE_RESULT
