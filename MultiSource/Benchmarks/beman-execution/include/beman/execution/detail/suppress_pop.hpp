// include/beman/execution/detail/suppress_pop.hpp                  -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

// ----------------------------------------------------------------------------

#ifdef BEMAN_EXECUTION_DIAGNOSTIC_PUSHED
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // #if defined(__GNUC__)
#if defined(__clang__)
#pragma clang diagnostic pop
#endif // #if defined(__clang__)
#undef BEMAN_EXECUTION_DIAGNOSTIC_PUSHED
#endif // #ifdef BEMAN_EXECUTION_DIAGNOSTIC_PUSHED
#include <beman/execution/detail/common.hpp>
