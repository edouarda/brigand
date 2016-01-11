/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <type_traits>
#include <brigand/types/type.hpp>
#include <brigand/sequences/pair.hpp>
#include <brigand/types/no_such_type.hpp>

namespace brigand
{

    template <typename M, typename K>
    using lookup = decltype(M::at(type_<K>{}));

namespace detail
{
    template <class... T>
    struct map_impl;

    template <class K, class... T>
    struct map_inserter_impl
    {
        using index_type = typename K::first_type;
        using map_type = map_impl<T...>;
        using find_result = lookup<map_type, index_type>;
        using type = decltype(map_type::template insert_impl<K>(find_result{}));
    };

    template <class... T>
    struct map_inserter
    {
        template <class K, typename U>
        static map_impl<T...> insert_impl(U);

        template <class K>
        static map_impl<T..., K> insert_impl(no_such_type_);

        template <class K>
        static typename map_inserter_impl<K, T...>::type insert(type_<K>);
    };

    template <>
    struct map_impl<>
    {
        template <typename U>
        static no_such_type_ at(U);

        template <class K>
        static map_impl<K> insert(type_<K>);
    };

    // fastlane for constant amortized time
    template <class T0>
    struct map_impl<T0> : map_inserter<T0>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1>
    struct map_impl<T0, T1> : map_inserter<T0, T1>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2>
    struct map_impl<T0, T1, T2> : map_inserter<T0, T1, T2>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3>
    struct map_impl<T0, T1, T2, T3> : map_inserter<T0, T1, T2, T3>
    {
        static typename T0::second_type at(type_<typename T0::first_type>);
        static typename T1::second_type at(type_<typename T1::first_type>);
        static typename T2::second_type at(type_<typename T2::first_type>);
        static typename T3::second_type at(type_<typename T3::first_type>);

        template <typename U>
        static no_such_type_ at(U);
    };

    template <class T0, class T1, class T2, class T3, class T4>
    struct map_impl<T0, T1, T2, T3, T4> : map_inserter<T0, T1, T2, T3, T4>
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
    struct map_impl<T0, T1, T2, T3, T4, T5> : map_inserter<T0, T1, T2, T3, T4, T5>
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
    struct map_impl<T0, T1, T2, T3, T4, T5, T6> : map_inserter<T0, T1, T2, T3, T4, T5, T6>
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
    struct map_impl<T0, T1, T2, T3, T4, T5, T6, T7> : map_inserter<T0, T1, T2, T3, T4, T5, T6, T7>
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
    struct map_impl<T0, T1, T2, T3, T4, T5, T6, T7, T...> : map_inserter<T0, T1, T2, T3, T4, T5, T6, T7, T...>
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
    struct make_map : type_<typename Ts::first_type>... {
      using type = map_impl<Ts...>;
    };
}
    template<class... Ts>
    using map = typename detail::make_map<Ts...>::type;
}
