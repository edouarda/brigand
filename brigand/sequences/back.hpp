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

  template <class L, class N = std::integral_constant<std::size_t, 1>>
  using pop_back = front<split_at<L, std::integral_constant<std::size_t, size<L>::value - N::value>>>;
}
