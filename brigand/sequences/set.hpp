/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <type_traits>
#include <brigand/types/type.hpp>
#include <brigand/types/bool.hpp>
#include <brigand/algorithms/apply.hpp>
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
        static true_ contains(type_<U>);

        template <typename U>
        static false_ contains(U);

        template <typename U>
        static decltype(set_impl::contains(type_<U>())) has_key(type_<U>);

        template<class K>
        static apply<typename erase_if_impl<list<T...>, unary_compose<std::is_same, K>::template type, list<>>::type, detail::set_impl> erase(type_<K>);
    
    private:
        template<class K>
        static set_impl<T..., K> insert_impl(false_);

        template<class K>
        static set_impl insert_impl(true_);

    public:
        template<class K>
        static decltype(insert_impl<K>(contains(type_<K>{}))) insert(type_<K>);
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
