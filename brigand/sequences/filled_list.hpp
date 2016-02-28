/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/list.hpp>
#include <brigand/sequences/append.hpp>

namespace brigand
{
namespace detail
{
  template<unsigned N, class List, bool>
  struct filled_list_impl;

  template<class T, template<class...> class, class List>
  struct filled_list_adapted;

  template<class T, class U>
  struct type_adapt
  {
    using type = U;
  };

  template<class T, template<class...> class List, class... Ts>
  struct filled_list_adapted<T, List, list<Ts...>>
  {
    using type = List<typename type_adapt<Ts,T>::type...>;
  };

  template<template<class...> class List, class... Ts>
  struct filled_list_adapted<int, List, list<Ts...>>
  {
    using type = List<Ts...>;
  };

  template<class T, unsigned N, template<class...> class List>
  struct filled_list
  {
    using type = typename filled_list_adapted<
      T, List,
      typename filled_list_impl<
        N, list<int,int,int,int,int,int,int,int>, (8*2 <= N-8)
      >::type
    >::type;
  };

  template<unsigned N>
  struct filled_list<int, N, list>
  {
    using type = typename filled_list_impl<
      N, list<int,int,int,int,int,int,int,int>, (8*2 <= N-8)
    >::type;
  };

  template<class T, template<class...> class List>
  struct filled_list<T, 0, List>
  {
    using type = List<>;
  };

  template<class T, template<class...> class List>
  struct filled_list<T, 1, List>
  {
    using type = List<T>;
  };

  template<class T, template<class...> class List>
  struct filled_list<T, 2, List>
  {
    using type = List<T, T>;
  };

  template<class T, template<class...> class List>
  struct filled_list<T, 3, List>
  {
    using type = List<T, T, T>;
  };

  template<class T, template<class...> class List>
  struct filled_list<T, 4, List>
  {
    using type = List<T, T, T, T>;
  };

  template<class T, template<class...> class List>
  struct filled_list<T, 5, List>
  {
    using type = List<T, T, T, T, T>;
  };

  template<class T, template<class...> class List>
  struct filled_list<T, 6, List>
  {
    using type = List<T, T, T, T, T, T>;
  };

  template<class T, template<class...> class List>
  struct filled_list<T, 7, List>
  {
    using type = List<T, T, T, T, T, T, T>;
  };

  template<class T, template<class...> class List>
  struct filled_list<T, 8, List>
  {
    using type = List<T, T, T, T, T, T, T, T>;
  };

  template<>
  struct filled_list<int, 0, list>
  {
    using type = list<>;
  };

  template<>
  struct filled_list<int, 1, list>
  {
    using type = list<int>;
  };

  template<>
  struct filled_list<int, 2, list>
  {
    using type = list<int, int>;
  };

  template<>
  struct filled_list<int, 3, list>
  {
    using type = list<int, int, int>;
  };

  template<>
  struct filled_list<int, 4, list>
  {
    using type = list<int, int, int, int>;
  };

  template<>
  struct filled_list<int, 5, list>
  {
    using type = list<int, int, int, int, int>;
  };

  template<>
  struct filled_list<int, 6, list>
  {
    using type = list<int, int, int, int, int, int>;
  };

  template<>
  struct filled_list<int, 7, list>
  {
    using type = list<int, int, int, int, int, int, int>;
  };

  template<>
  struct filled_list<int, 8, list>
  {
    using type = list<int, int, int, int, int, int, int, int>;
  };


  template<class... E>
  struct filled_list_impl<0, list<E...>, false>
  {
    using type = list<E...>;
  };

  template<class... E>
  struct filled_list_impl<1, list<E...>, false>
  {
    using type = list<int, E...>;
  };

  template<class... E>
  struct filled_list_impl<2, list<E...>, false>
  {
    using type = list<int, int, E...>;
  };

  template<class... E>
  struct filled_list_impl<3, list<E...>, false>
  {
    using type = list<int, int, int, E...>;
  };

  template<class... E>
  struct filled_list_impl<4, list<E...>, false>
  {
    using type = list<int, int, int, int, E...>;
  };

  template<class... E>
  struct filled_list_impl<5, list<E...>, false>
  {
    using type = list<int, int, int, int, int, E...>;
  };

  template<class... E>
  struct filled_list_impl<6, list<E...>, false>
  {
    using type = list<int, int, int, int, int, int, E...>;
  };

  template<class... E>
  struct filled_list_impl<7, list<E...>, false>
  {
    using type = list<int, int, int, int, int, int, int, E...>;
  };

  template<class... E>
  struct filled_list_impl<8, list<E...>, false>
  {
    using type = list<int, int, int, int, int, int, int, int, E...>;
  };

  template<unsigned N, class... E>
  struct filled_list_impl<N, list<E...>, false>
  {
    using type = typename append_impl<
      list<E...>,
      typename filled_list_impl<
        N-8,
        list<int, int, int, int, int, int, int, int>,
        (8*2 <= N-8)
      >::type
    >::type;
  };

  template<unsigned N, class... E>
  struct filled_list_impl<N, list<E...>, true>
  {
    using type = typename filled_list_impl<
      N-sizeof...(E),
      list<E..., E...>,
      (sizeof...(E)*2 <= N-sizeof...(E))
    >::type;
  };
}

  template<class T, unsigned N, template<class...> class List = list>
  using filled_list = typename detail::filled_list<T, N, List>::type;
}
