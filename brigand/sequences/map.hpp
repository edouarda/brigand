/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <type_traits>
#include <brigand/types/type.hpp>
#include <brigand/types/bool.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/pair.hpp>
#include <brigand/sequences/erase.hpp>
#include <brigand/algorithms/apply.hpp>
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

    template<class K>
    struct is_same_first
    {
        template<class P>
        using type = std::is_same<K, first<P>>;
    };

    template<class... T>
    struct map_impl
    {
        template<class K>
        static decltype(map_at_impl<K>::at(make_map<T...>{})) at(type_<K>);

        template <typename K>
        static bool_<!std::is_same<decltype(map_at_impl<K>::at(make_map<T...>{})), no_such_type_>::value> has_key(type_<K>);

        template<class K>
        static apply<typename erase_if_impl<list<T...>, is_same_first<K>::template type, list<>>::type, detail::map_impl> erase(type_<K>);

    private:
        template<class P>
        static map_impl<typename std::conditional<
            std::is_same<first<T>, first<P>>::value, P, T
        >::type...> insert_impl(true_);

        template<class P>
        static map_impl<T..., P> insert_impl(false_);

    public:
        template<class P>
        static decltype(insert_impl<P>(has_key(type_<first<P>>{}))) insert(type_<P>);
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
}
