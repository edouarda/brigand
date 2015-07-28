/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <type_traits>
#include <brigand/types/type.hpp>
#include <brigand/sequences/pair.hpp>
#include <brigand/sequences/insert.hpp>
#include <brigand/sequences/contains.hpp>
#include <brigand/types/no_such_type.hpp>

namespace brigand
{
namespace detail
{
    template <class... T>
    struct map_impl;

    template <>
    struct map_impl<>
    {
        template <typename U>
        static no_such_type_ at(U);
    };

    // fastlane for constant amortized time
    template <class T0>
    struct map_impl<T0>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1>
    struct map_impl<T0, T1>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2>
    struct map_impl<T0, T1, T2>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3>
    struct map_impl<T0, T1, T2, T3>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3, class T4>
    struct map_impl<T0, T1, T2, T3, T4>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);
        static typename T4::second_type at(type_<typename T4::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3, class T4, class T5>
    struct map_impl<T0, T1, T2, T3, T4, T5>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);
        static typename T4::second_type at(type_<typename T4::first_type>);
        static typename T5::second_type at(type_<typename T5::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
    struct map_impl<T0, T1, T2, T3, T4, T5, T6>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);
        static typename T4::second_type at(type_<typename T4::first_type>);
        static typename T5::second_type at(type_<typename T5::first_type>);
        static typename T6::second_type at(type_<typename T6::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    struct map_impl<T0, T1, T2, T3, T4, T5, T6, T7>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);
        static typename T4::second_type at(type_<typename T4::first_type>);
        static typename T5::second_type at(type_<typename T5::first_type>);
        static typename T6::second_type at(type_<typename T6::first_type>);
        static typename T7::second_type at(type_<typename T7::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };


    template <class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class... T>
    struct map_impl<T0, T1, T2, T3, T4, T5, T6, T7, T...>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);
        static typename T4::second_type at(type_<typename T4::first_type>);
        static typename T5::second_type at(type_<typename T5::first_type>);
        static typename T6::second_type at(type_<typename T6::first_type>);
        static typename T7::second_type at(type_<typename T7::first_type>);

        template <typename U>
        static decltype(map_impl<T...>::at(U{})) at(U);
    };

    // if you have a "class already a base" error message, it means you have defined a map with the same key present more
    // than once, which is an error
    template<class... Ts>
    struct make_map : type_<typename Ts::first_type>...
    {
        using type = map_impl<Ts...>;
    };
}
    template<class... Ts>
    using map = typename detail::make_map<Ts...>::type;

    template <typename M, typename K>
    using lookup = decltype(M::at(type_<K>{}));

namespace detail
{
    template<class... Ts, class T>
    struct contains_impl<map_impl<Ts...>, T>
    {
        using type = bool_<!std::is_same<lookup<map_impl<Ts...>, T>, no_such_type_>::value>;
    };

    template <class T, class... Ts>
    struct insert_impl<map_impl<Ts...>, T>
    {
        using type = typename insert_default_impl<map_impl<Ts...>, T, contains<map_impl<Ts...>, typename T::first_type>>::type;
    };
}

}
