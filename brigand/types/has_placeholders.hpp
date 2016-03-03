/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/bool.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/is_placeholder.hpp>

namespace brigand
{
	template<typename... T> struct has_placeholders : std::false_type {};

  template<typename T> struct has_placeholders<T> : is_placeholder<T> {};

  template<template<class...>class T,typename... Ts>
  struct has_placeholders<T<Ts...>> : has_placeholders<Ts...> {};

  template<typename F, typename... T> struct bind;

  template<typename F, typename... T>
  struct has_placeholders<bind<F,T...>> : std::false_type {};

  template <bool...> struct checks_ {};

  template<typename T, typename U, typename... Ts>
  struct has_placeholders<T,U,Ts...>
        : bool_ < !std::is_same < checks_ < true
                                          , !has_placeholders<T>::value, !has_placeholders<U>::value
                                          , !has_placeholders<Ts>::value...
                                          >
                                , checks_ < !has_placeholders<T>::value, !has_placeholders<U>::value
                                          , !has_placeholders<Ts>::value...
                                          , true
                                          >
                                >::value
                >
  {};
}
