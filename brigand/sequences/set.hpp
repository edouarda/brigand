/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <type_traits>

#include <brigand/types/type.hpp>
#include <brigand/types/bool.hpp>

#include <brigand/algorithms/wrap.hpp>
#include <brigand/algorithms/remove.hpp>

#include <brigand/sequences/append.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/erase.hpp>
#include <brigand/sequences/insert.hpp>
#include <brigand/sequences/contains.hpp>

namespace brigand
{
namespace detail
{

    template<class... Ts>
    struct make_set;

    template <class... T>
    struct set_impl
    {
        template <typename U, typename = decltype(static_cast<type_<U>>(make_set<T...>()))>
        static std::true_type contains(type_<U>);

        template <typename U>
        static std::false_type contains(U);

    private:
        // Visual Studio helper
        template <class K>
        struct contains_predicate_impl
        {
            using type = decltype(set_impl<T...>::contains(K{}));
        };

        template <typename K>
        using contains_predicate = typename contains_predicate_impl<K>::type;

    public:
        template <typename U>
        static contains_predicate<type_<U>> has_key(type_<U>);

    private:
        template<class U, class K>
        struct erase_pred_impl
        : std::conditional<std::is_same<U, K>::value, list<>, list<U>>
        {
        };

    public:
        template <class K>
        static typename detail::append_impl<set_impl<>, typename erase_pred_impl<T, K>::type...>::type erase(type_<K>);

    private:
        template<class K>
        static set_impl<T..., K> insert_impl(std::false_type);

        template<class K>
        static set_impl insert_impl(std::true_type);

    public:
        template<class K>
        static decltype(set_impl<T...>::insert_impl<K>(contains_predicate<type_<K>>())) insert(type_<K>);

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

}
