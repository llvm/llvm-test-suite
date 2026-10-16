// include/beman/execution/detail/product_type.hpp                  -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION_DETAIL_PRODUCT_TYPE
#define INCLUDED_BEMAN_EXECUTION_DETAIL_PRODUCT_TYPE

#include <beman/execution/detail/common.hpp>
#include <beman/execution/detail/suppress_push.hpp>
#ifdef BEMAN_HAS_IMPORT_STD
import std;
#else
#include <cstddef>
#include <memory>
#include <tuple>
#endif

// ----------------------------------------------------------------------------

namespace beman::execution::detail {

template <::std::size_t I, typename T>
struct product_type_element {
    T    value;
    auto operator==(const product_type_element&) const -> bool = default;
};

template <typename, typename...>
struct product_type_base;

template <::std::size_t... I, typename... T>
struct product_type_base<::std::index_sequence<I...>, T...>
    : ::beman::execution::detail::product_type_element<I, T>... {
    static constexpr ::std::size_t size() noexcept { return sizeof...(T); }
    static constexpr bool          is_product_type{true};

    template <::std::size_t J, typename S>
    static auto element_get(::beman::execution::detail::product_type_element<J, S>& self) noexcept -> S& {
        return self.value;
    }
    template <::std::size_t J, typename S>
    static auto element_get(::beman::execution::detail::product_type_element<J, S>&& self) noexcept -> S&& {
        return ::std::move(self.value);
    }
    template <::std::size_t J, typename S>
    static auto element_get(const ::beman::execution::detail::product_type_element<J, S>& self) noexcept -> const S& {
        return self.value;
    }

    template <::std::size_t J>
    auto get() & noexcept -> decltype(auto) {
        return this->element_get<J>(*this);
    }
    template <::std::size_t J>
    auto get() && noexcept -> decltype(auto) {
        return this->element_get<J>(::std::move(*this));
    }
    template <::std::size_t J>
    auto get() const& noexcept -> decltype(auto) {
        return this->element_get<J>(*this);
    }

    template <::std::size_t J, typename Allocator, typename Self>
    static auto make_element(Allocator&& alloc, Self&& self) -> decltype(auto) {
        using type = ::std::remove_cvref_t<decltype(product_type_base::element_get<J>(std::forward<Self>(self)))>;
        if constexpr (::std::uses_allocator_v<type, Allocator>)
            return ::std::make_obj_using_allocator<type>(alloc,
                                                         product_type_base::element_get<J>(std::forward<Self>(self)));
        else
            return product_type_base::element_get<J>(std::forward<Self>(self));
    }

    auto operator==(const product_type_base&) const -> bool = default;
};

template <typename T>
concept is_product_type_c = requires(const T& t) { T::is_product_type; };

template <typename... T>
struct product_type : ::beman::execution::detail::product_type_base<::std::index_sequence_for<T...>, T...> {
    template <typename Allocator, typename Product, std::size_t... I>
    static auto make_from(Allocator&& allocator, Product&& product, std::index_sequence<I...>) -> product_type {
        return {product_type::template make_element<I>(allocator, ::std::forward<Product>(product))...};
    }

    template <typename Allocator, typename Product>
    static auto make_from(Allocator&& allocator, Product&& product) -> product_type {
        return product_type::make_from(
            ::std::forward<Allocator>(allocator), ::std::forward<Product>(product), ::std::index_sequence_for<T...>{});
    }

    template <typename Fun, ::std::size_t... I>
    constexpr auto apply_elements(::std::index_sequence<I...>, Fun&& fun) const -> decltype(auto) {
        return ::std::forward<Fun>(fun)(this->template get<I>()...);
    }
    template <typename Fun>
    constexpr auto apply(Fun&& fun) const -> decltype(auto) {
        return apply_elements(::std::index_sequence_for<T...>{}, ::std::forward<Fun>(fun));
    }
    template <typename Fun, ::std::size_t... I>
    constexpr auto apply_elements(::std::index_sequence<I...>, Fun&& fun) -> decltype(auto) {
        //-dk:TODO provide rvalue, lvalue, const lvalue overloads?
        return ::std::forward<Fun>(fun)(std::move(this->template get<I>())...);
    }
    template <typename Fun>
    constexpr auto apply(Fun&& fun) -> decltype(auto) {
        return apply_elements(::std::index_sequence_for<T...>{}, ::std::forward<Fun>(fun));
    }
};
template <typename... T>
product_type(T&&...) -> product_type<::std::decay_t<T>...>;

template <typename T>
constexpr auto is_product_type(const T&) -> ::std::false_type {
    return {};
}
template <typename... T>
constexpr auto is_product_type(const ::beman::execution::detail::product_type<T...>&) -> ::std::true_type {
    return {};
}

} // namespace beman::execution::detail

#ifndef BEMAN_EXECUTION_DETAIL_PRODUCT_TYPE_CPPM
namespace std {
template <typename... T>
struct tuple_size<::beman::execution::detail::product_type<T...>>
    : ::std::integral_constant<std::size_t, ::beman::execution::detail::product_type<T...>::size()> {};

template <::std::size_t I, typename... T>
struct tuple_element<I, ::beman::execution::detail::product_type<T...>> {
    using type =
        ::std::decay_t<decltype(::std::declval<::beman::execution::detail::product_type<T...>>().template get<I>())>;
};
} // namespace std
#endif

// ----------------------------------------------------------------------------

#include <beman/execution/detail/suppress_pop.hpp>

#endif // INCLUDED_BEMAN_EXECUTION_DETAIL_PRODUCT_TYPE
