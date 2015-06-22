/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/integer.hpp>
#include <brigand/sequences/size.hpp>
#include <brigand/sequences/append.hpp>

namespace brigand
{
namespace detail
{

    template <template <class...> class L, class First, class... R>
    struct reverse_elements
    {
        using head = L<First>;
        using tail = typename reverse_elements<L, R...>::type;
        using type = typename brigand::append<tail, head>;
    };

    template <template <class...> class L, class T0>
    struct reverse_elements<L, T0>
    {
        using type = L<T0>;
    };

    // fast lanes
    template <template <class...> class L, class T0, class T1>
    struct reverse_elements<L, T0, T1>
    {
        using type = L<T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2>
    struct reverse_elements<L, T0, T1, T2>
    {
        using type = L<T2, T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2, class T3>
    struct reverse_elements<L, T0, T1, T2, T3>
    {
        using type = L<T3, T2, T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2, class T3, class T4>
    struct reverse_elements<L, T0, T1, T2, T3, T4>
    {
        using type = L<T4, T3, T2, T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2, class T3, class T4, class T5>
    struct reverse_elements<L, T0, T1, T2, T3, T4, T5>
    {
        using type = L<T5, T4, T3, T2, T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2, class T3, class T4, class T5, class T6>
    struct reverse_elements<L, T0, T1, T2, T3, T4, T5, T6>
    {
        using type = L<T6, T5, T4, T3, T2, T1, T0>;
    };

    template <template <class...> class L, class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    struct reverse_elements<L, T0, T1, T2, T3, T4, T5, T6, T7>
    {
        using type = L<T7, T6, T5, T4, T3, T2, T1, T0>;
    };

    template <class L, class Count = brigand::size<L>> struct reverse_impl;

    template<template<class...> class L, class... U, class Count>
    struct reverse_impl<L<U...>,Count>
    {
        using type = typename reverse_elements<L, U...>::type;
    };

    template<template<class...> class L, class... U>
    struct reverse_impl<L<U...>, brigand::size_t<0>>
    {
        using type = L<U...>;
    };

}

    template <typename L>
    using reverse = typename detail::reverse_impl<L>::type;
}
