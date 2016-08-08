/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/filled_list.hpp>

namespace brigand
{
  // push_front
  namespace detail
  {
    template<class L, class... T> struct push_front_impl;

    template<template<class...> class L, class... U, class... T>
    struct push_front_impl<L<U...>, T...>
    {
      using type = L<T..., U...>;
    };
  }

  namespace lazy {
	  template<class L, class... T>
	  struct push_front : detail::push_front_impl<L, T...>{};
  }

  template<class L, class... T>
  using push_front = typename detail::push_front_impl<L, T...>::type;

  // front
  namespace detail
  {
    template<class L> struct front_impl;

    template<template<class...> class L, class T, class... U>
    struct front_impl<L<T, U...>>
    {
      using type = T;
    };
  }

  template <class L>
  using front = typename detail::front_impl<L>::type;

  // pop front
  namespace detail
  {
    template <class L, std::size_t N> struct pop_front_impl;

    template<template<class...> class L, class T, class... U>
    struct pop_front_impl<L<T, U...>, 1>
    {
      using type = L<U...>;
    };

    template<template<class...> class L, class> struct pop_front_element;

    template<template<class...> class L, class... Ts>
    struct pop_front_element<L, list<Ts...>>
    {
      template<class... Us>
      static L<Us...> impl(Ts..., type_<Us>*...);
    };

    template<template<class...> class L, class... Ts, std::size_t N>
    struct pop_front_impl<L<Ts...>, N>
    {
      using type = decltype(pop_front_element<L, filled_list<
        void const *, N
      >>::impl(static_cast<type_<Ts>*>(nullptr)...));
    };
  }
  namespace lazy {
	  template <class L, class N = std::integral_constant<std::size_t, 1>>
	  struct pop_front : detail::pop_front_impl<L, N::value> {};
  }
  template <class L, class N = std::integral_constant<std::size_t, 1>>
  using pop_front = typename detail::pop_front_impl<L, N::value>::type;
}
