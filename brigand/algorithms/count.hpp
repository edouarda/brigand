/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <brigand/config.hpp>
#include <brigand/functions/lambda.hpp>
#include <brigand/types/integer.hpp>
#include <type_traits>

namespace brigand
{
namespace detail
{
#if defined(BRIGAND_COMP_GCC) || defined(BRIGAND_COMP_CLANG) // not MSVC
    constexpr std::size_t count_bools(bool const * const begin, bool const * const end,
                                      std::size_t n)
    {
        return begin == end ? n : detail::count_bools(begin + 1, end, n + *begin);
    }
#endif

    template <bool... Bs>
    struct template_count_bools
    {
        using type = ::brigand::size_t<0>;
    };
    template <bool B, bool... Bs>
    struct template_count_bools<B, Bs...>
    {
        using type = ::brigand::size_t<B + template_count_bools<Bs...>::type::value>;
    };
    template <bool B1, bool B2, bool B3, bool B4, bool B5, bool B6, bool B7, bool B8, bool B9,
              bool B10, bool B11, bool B12, bool B13, bool B14, bool B15, bool B16, bool... Bs>
    struct template_count_bools<B1, B2, B3, B4, B5, B6, B7, B8, B9, B10, B11, B12, B13, B14, B15,
                                B16, Bs...>
    {
        using type =
            ::brigand::size_t<B1 + B2 + B3 + B4 + B5 + B6 + B7 + B8 + B9 + B10 + B11 + B12 + B13 +
                              B14 + B15 + B16 + template_count_bools<Bs...>::type::value>;
    };
}
namespace lazy
{
    template <typename List, typename Pred>
    struct count_if
    {
    };

    template <template <typename...> class S, typename Pred>
    struct count_if<S<>, Pred>
    {
        using type = ::brigand::size_t<0>;
    };

#if defined(BRIGAND_COMP_GCC) || defined(BRIGAND_COMP_CLANG) // not MSVC

    template <template <typename...> class S, template <typename...> class F>
    struct count_if<S<>, bind<F, _1>>
    {
        using type = ::brigand::size_t<0>;
    };

    template <template <typename...> class S, template <typename...> class F>
    struct count_if<S<>, F<_1>>
    {
        using type = ::brigand::size_t<0>;
    };

    template <template <typename...> class S, typename... Ts, typename Pred>
    struct count_if<S<Ts...>, Pred>
    {
        static constexpr bool s_v[] = {::brigand::apply<Pred, Ts>::type::value...};
        using type = brigand::size_t< ::brigand::detail::count_bools(s_v, s_v + sizeof...(Ts), 0u)>;
    };

    template <template <typename...> class S, typename... Ts, template <typename...> class F>
    struct count_if<S<Ts...>, bind<F, _1>>
    {
        static constexpr bool s_v[] = {F<Ts>::value...};
        using type = brigand::size_t< ::brigand::detail::count_bools(s_v, s_v + sizeof...(Ts), 0u)>;
    };

    template <template <typename...> class S, typename... Ts, template <typename...> class F>
    struct count_if<S<Ts...>, F<_1>>
    {
        static constexpr bool s_v[] = {F<Ts>::type::value...};
        using type = brigand::size_t< ::brigand::detail::count_bools(s_v, s_v + sizeof...(Ts), 0u)>;
    };
#else
#if defined(BRIGAND_COMP_MSVC_2015)
    template <template <typename...> class S, typename... Ts, typename Pred>
    struct count_if<S<Ts...>, Pred>
        : ::brigand::detail::template_count_bools< ::brigand::apply<Pred, Ts>::value...>
    {
    };
#else
    template <template <typename...> class S, typename... Ts, typename Pred>
    struct count_if<S<Ts...>, Pred>
    {
        template <typename T>
        using val_t = brigand::apply<Pred, T>;
        using type = typename ::brigand::detail::template_count_bools<val_t<Ts>::value...>::type;
    };
#endif
#endif
}

template <typename List, typename Pred>
using count_if = typename lazy::count_if<List, Pred>::type;
template <class... T>
using count = std::integral_constant<std::size_t, sizeof...(T)>;
}
