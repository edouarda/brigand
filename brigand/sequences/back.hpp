/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/voidp.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/last_element.hpp>

namespace brigand
{
  // push_back
  namespace detail
  {
    template<class L, class... T> struct push_back_impl;

    template<template<class...> class L, class... U, class... T>
    struct push_back_impl<L<U...>, T...>
    {
        using type = L<U..., T...>;
    };
  }

  template<class L, class... T>
  using push_back = typename detail::push_back_impl<L, T...>::type;

  // back
  namespace detail
  {
    template<class L> struct back_impl;

    template<template<class...> class L, class T, class... Ts>
    struct back_impl<L<T, Ts...>>
    {
      template<class U> static U back(typename voidp<Ts>::type..., U*);
      using type = decltype(back(nullptr, static_cast<Ts*>(nullptr)...));
    };

  }

  template <class L>
  using back = typename detail::back_impl<L>::type;

  // pop back
  namespace detail
  {
    template <class L> struct pop_back_impl;

    template<template<class...> class L, class... U>
    struct pop_back_impl<L<U...>>
    {
        using type = typename without_last_element<L, U...>::type;
    };
  }

  template <class L>
  using pop_back = typename detail::pop_back_impl<L>::type;
}
