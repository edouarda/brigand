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
    template<class... Ts>
    struct make_map;

    template<class K>
    struct map_at_impl
    {
        template<class U>
        static U at(pair<K, U>);

        static no_such_type_ at(...);
    };

    template<class... T>
    struct map_impl
    {
        template<class K>
        static decltype(map_at_impl<K>::at(make_map<T...>{})) at(type_<K>);
    };

    // if you have a "class already a base" error message, it means you have defined a map with the same key present more
    // than once, which is an error
    template<class... Ts>
    struct make_map : type_<typename Ts::first_type>...
    , pair<typename Ts::first_type, typename Ts::second_type>...
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
    template <class... Ts, class T>
    struct contains_impl<map_impl<Ts...>, T>
    {
        using type = bool_<!std::is_same<lookup<map_impl<Ts...>, T>, no_such_type_>::value>;
    };

    template <class T, class... Ts>
    struct insert_impl<map_impl<Ts...>, T>
    {
	//TODO if_<contain<>, nothing, replace>::type
	// struct nothing { using type = map_impl<Ts...>; };
	// struct replace { using pair = slice_when<map_impl<Ts...>, pred<is_same, T::first_type>::type>; using type = merge<first_<pair>, replace_value<second_<pair>>; };
        using type = typename insert_default_impl<map_impl<Ts...>, T, contains<map_impl<Ts...>, typename T::first_type>>::type;
    };
}

}
