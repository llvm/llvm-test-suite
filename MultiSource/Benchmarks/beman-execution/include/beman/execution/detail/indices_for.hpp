// include/beman/execution/detail/indices_for.hpp                   -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_INDICES_FOR
#define INCLUDED_BEMAN_EXECUTION_DETAIL_INDICES_FOR

#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <type_traits>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
//-dk:TODO the export below shouldn't be needed, but MSVC++ seems to require it (2026-02-01)
template <typename Sender> //-dk:TODO detail export
using indices_for = typename ::std::remove_reference_t<Sender>::indices_for;
} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_INDICES_FOR
