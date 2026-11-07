// include/beman/execution/detail/infallible_scheduler.hpp                   -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_INFALLIBLE_SCHEDULER
#define INCLUDED_BEMAN_EXECUTION_DETAIL_INFALLIBLE_SCHEDULER

#include <beman/execution/detail/common.hpp>

#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <concepts>
#include <exception>
#endif
#ifdef BEMAN_HAS_MODULES
import beman.execution.detail.completion_signatures;
import beman.execution.detail.completion_signatures_of_t;
import beman.execution.detail.scheduler;
import beman.execution.detail.schedule_result_t;
import beman.execution.detail.set_stopped;
import beman.execution.detail.set_value;
import beman.execution.detail.stop_token_of_t;
import beman.execution.detail.unstoppable_token;
#else
#include <beman/execution/detail/completion_signatures.hpp>
#include <beman/execution/detail/completion_signatures_of_t.hpp>
#include <beman/execution/detail/scheduler.hpp>
#include <beman/execution/detail/schedule_result_t.hpp>
#include <beman/execution/detail/set_stopped.hpp>
#include <beman/execution/detail/set_value.hpp>
#include <beman/execution/detail/stop_token_of_t.hpp>
#include <beman/execution/detail/unstoppable_token.hpp>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {

template <typename Env>
struct infallible_scheduler_error : ::std::exception {
    auto what() const noexcept -> const char* override {
        using _ [[maybe_unused]] = Env;
        return "the result type of querying `get_start_scheduler` on an `Env` shall be a scheduler type whose "
               "schedule "
               "asynchronous operation can only complete with set_value unless stop can be requested";
    }
};

template <typename Sched, typename Env>
concept infallible_scheduler =
    ::beman::execution::scheduler<Sched> &&
    (::std::same_as<
         ::beman::execution::completion_signatures<::beman::execution::set_value_t()>,
         ::beman::execution::completion_signatures_of_t<::beman::execution::schedule_result_t<Sched>, Env>> ||
     (!::beman::execution::unstoppable_token<::beman::execution::stop_token_of_t<Env>> &&
      (::std::same_as<
           ::beman::execution::completion_signatures<::beman::execution::set_value_t(),
                                                     ::beman::execution::set_stopped_t()>,
           ::beman::execution::completion_signatures_of_t<::beman::execution::schedule_result_t<Sched>, Env>> ||
       ::std::same_as<
           ::beman::execution::completion_signatures<::beman::execution::set_stopped_t(),
                                                     ::beman::execution::set_value_t()>,
           ::beman::execution::completion_signatures_of_t<::beman::execution::schedule_result_t<Sched>, Env>>)));

} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_INFALLIBLE_SCHEDULER
