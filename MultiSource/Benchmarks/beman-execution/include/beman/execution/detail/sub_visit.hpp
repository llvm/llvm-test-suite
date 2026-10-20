// include/beman/execution/detail/sub_visit.hpp                            -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_SUB_VISIT
#define INCLUDED_BEMAN_EXECUTION_DETAIL_SUB_VISIT
#include <beman/execution/detail/common.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <cstddef>
#include <utility>
#include <variant>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {
template <::std::size_t Start, typename Fun, typename Var, ::std::size_t... I>
auto sub_visit_thunks(Fun& fun, Var& var, ::std::index_sequence<I...>) -> void {
    using thunk_t = void (*)(Fun&, Var&);
    static constexpr thunk_t thunks[]{(+[](Fun& f, Var& v) { f(::std::get<Start + I>(v)); })...};
    thunks[var.index() - Start](fun, var);
}

template <::std::size_t Start, typename... T>
auto sub_visit(const auto& fun, std::variant<T...>& v) -> void {
    if (v.index() < Start)
        return;
    sub_visit_thunks<Start>(fun, v, std::make_index_sequence<sizeof...(T) - Start>{});
}

} // namespace beman::execution::detail

// ----------------------------------------------------------------------------

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_SUB_VISIT
