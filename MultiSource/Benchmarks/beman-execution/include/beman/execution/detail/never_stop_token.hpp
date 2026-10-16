// include/beman/execution/detail/never_stop_token.hpp              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_NEVER_STOP_TOKEN
#define INCLUDED_BEMAN_EXECUTION_DETAIL_NEVER_STOP_TOKEN

#include <beman/execution/detail/common.hpp>

// ----------------------------------------------------------------------------

namespace beman::execution {
class never_stop_token;
}

// ----------------------------------------------------------------------------

class beman::execution::never_stop_token {
    struct private_callback_type {
        explicit private_callback_type(never_stop_token, auto&&) noexcept {}
    };

  public:
    template <typename>
    using callback_type = private_callback_type;

    static constexpr auto stop_requested() noexcept -> bool { return {}; }
    static constexpr auto stop_possible() noexcept -> bool { return {}; }
    auto                  operator==(const never_stop_token&) const -> bool = default;
};

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_NEVER_STOP_TOKEN
