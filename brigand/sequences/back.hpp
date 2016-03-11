/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/at.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/size.hpp>
#include <brigand/sequences/front.hpp>
#include <brigand/algorithms/split_at.hpp>

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

  template <class L>
  using back = at_c<L, size<L>::value-1>;

  // pop back
  namespace detail
  {
    template<class L, class N>
    struct pop_back_impl;

    template<template<class...> class L, class... Ts>
    struct pop_back_impl<L<Ts...>, void>
    {
      using type = front<split_at<L<Ts...>, std::integral_constant<std::size_t, sizeof...(Ts)-1>>>;
    };

    template<template<class...> class L, class... Ts, class N>
    struct pop_back_impl<L<Ts...>, N>
    {
      using type = front<split_at<L<Ts...>, std::integral_constant<std::size_t, (N::value < sizeof...(Ts) ? sizeof...(Ts) - N::value : 0)>>>;
    };
  }

  // pop back
  template <class L, class N = void>
  using pop_back = typename detail::pop_back_impl<L, N>::type;
}
