// include/beman/execution/detail/on_stop_request.hpp               -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_ON_STOP_REQUEST
#define INCLUDED_BEMAN_EXECUTION_DETAIL_ON_STOP_REQUEST

#include <beman/execution/detail/common.hpp>

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <typename St>
struct on_stop_request {
    St&  st;
    auto operator()() const -> void { this->st.request_stop(); }
};
template <typename T>
on_stop_request(T&) -> on_stop_request<T>;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_ON_STOP_REQUEST
