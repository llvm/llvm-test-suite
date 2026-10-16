// include/beman/execution/detail/dependent_sender_error.hpp          -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_DEPENDENT_SENDER_ERROR
#define INCLUDED_INCLUDE_BEMAN_EXECUTION_DETAIL_DEPENDENT_SENDER_ERROR

// ----------------------------------------------------------------------------

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <exception>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution {
struct dependent_sender_error : std::exception {};
} // namespace beman::execution

namespace beman::execution::detail {
template <typename Sender>
struct dependent_sender_error : ::beman::execution::dependent_sender_error {
    auto what() const noexcept -> const char* override {
        return "Sender requires an environment to determine the completion signatures, but no environment was "
               "provided";
    }
};
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif
