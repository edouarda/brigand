/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/at.hpp>

namespace brigand
{
  template<std::size_t Index> struct args;

  namespace detail
  {
    template<typename T, typename List>
    struct substitute_impl
    {
      using type = T;
    };

    template<template<class...> class T, typename... Ts, typename List>
    struct substitute_impl<T<Ts...>,List>
    {
      using type = T<typename substitute_impl<Ts,List>::type...>;
    };

    template<std::size_t Index, typename List>
    struct substitute_impl<args<Index>,List>
    {
      using type = brigand::at_c<List,Index>;
    };
  }

  template<typename T, typename List>
  using substitute = typename detail::substitute_impl<T,List>::type;
}
