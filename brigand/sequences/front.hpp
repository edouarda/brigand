/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

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
    template <class L> struct pop_front_impl;

    template<template<class...> class L, class T, class... U>
    struct pop_front_impl<L<T, U...>>
    {
      using type = L<U...>;
    };
  }

  template <class L>
  using pop_front = typename detail::pop_front_impl<L>::type;
}
