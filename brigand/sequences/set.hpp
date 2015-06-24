/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <type_traits>
#include <brigand/types/type.hpp>
#include <brigand/types/bool.hpp>

namespace brigand
{
namespace detail
{
    template <class... T>
    struct set_impl;

    template <>
    struct set_impl<>
    {
        template <typename U>
        static false_ contains(U) {}
    };

    // fastlane for constant amortized time
    template <class T0>
    struct set_impl<T0>
    {
        static true_ contains(type_<T0>);

        template <typename U>
        static false_ contains(U) {}
    };

    template <class T0, class T1>
    struct set_impl<T0, T1>
    {
        static true_ contains(type_<T0>);
        static true_ contains(type_<T1>);

        template <typename U>
        static false_ contains(U) {}
    };

    template <class T0, class T1, class T2>
    struct set_impl<T0, T1, T2>
    {
        static true_ contains(type_<T0>);
        static true_ contains(type_<T1>);
        static true_ contains(type_<T2>);

        template <typename U>
        static false_ contains(U) {}
    };

    template <class T0, class T1, class T2, class T3>
    struct set_impl<T0, T1, T2, T3>
    {
        static true_ contains(type_<T0>);
        static true_ contains(type_<T1>);
        static true_ contains(type_<T2>);
        static true_ contains(type_<T3>);

        template <typename U>
        static false_ contains(U) {}
    };

    template <class T0, class T1, class T2, class T3, class T4>
    struct set_impl<T0, T1, T2, T3, T4>
    {
        static true_ contains(type_<T0>);
        static true_ contains(type_<T1>);
        static true_ contains(type_<T2>);
        static true_ contains(type_<T3>);
        static true_ contains(type_<T4>);

        template <typename U>
        static false_ contains(U) {}
    };

    template <class T0, class T1, class T2, class T3, class T4, class T5>
    struct set_impl<T0, T1, T2, T3, T4, T5>
    {
        static true_ contains(type_<T0>);
        static true_ contains(type_<T1>);
        static true_ contains(type_<T2>);
        static true_ contains(type_<T3>);
        static true_ contains(type_<T4>);
        static true_ contains(type_<T5>);

        template <typename U>
        static false_ contains(U) {}
    };

    template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
    struct set_impl<T0, T1, T2, T3, T4, T5, T6>
    {
        static true_ contains(type_<T0>);
        static true_ contains(type_<T1>);
        static true_ contains(type_<T2>);
        static true_ contains(type_<T3>);
        static true_ contains(type_<T4>);
        static true_ contains(type_<T5>);
        static true_ contains(type_<T6>);

        template <typename U>
        static false_ contains(U) {}
    };

    template <class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    struct set_impl<T0, T1, T2, T3, T4, T5, T6, T7>
    {
        static true_ contains(type_<T0>);
        static true_ contains(type_<T1>);
        static true_ contains(type_<T2>);
        static true_ contains(type_<T3>);
        static true_ contains(type_<T4>);
        static true_ contains(type_<T5>);
        static true_ contains(type_<T6>);
        static true_ contains(type_<T7>);

        template <typename U>
        static false_ contains(U) {}
    };


    template <class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class... T>
    struct set_impl<T0, T1, T2, T3, T4, T5, T6, T7, T...>
    {
        static true_ contains(type_<T0>);
        static true_ contains(type_<T1>);
        static true_ contains(type_<T2>);
        static true_ contains(type_<T3>);
        static true_ contains(type_<T4>);
        static true_ contains(type_<T5>);
        static true_ contains(type_<T6>);
        static true_ contains(type_<T7>);

        template <typename U>
        static decltype(set_impl<T...>::contains(U{})) contains(U);
    };

    // if you have a "class already a base" error message, it means you have defined a set with the same key present more
    // than once, which is an error
    template<class... Ts>
    struct make_set : type_<Ts>...
    {
      using type = set_impl<Ts...>;
    };
}
    template<class... Ts>
    using set = typename detail::make_set<Ts...>::type;

    template <typename M, typename K>
    using contains = decltype(M::contains(type_<K>{}));
}
