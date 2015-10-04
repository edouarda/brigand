/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/apply.hpp>
#include <brigand/functions/lambda.hpp>

namespace brigand
{
  template<typename Functor> struct unpack {};

  // Special casing so we dont overwrap
  template<class F> struct lambda<unpack<F>>
  {
    template<typename X> struct apply;

    template<template<class...> class List, typename... Types>
    struct apply<List<Types...>> : brigand::apply<F,Types...>
    {};
  };
}
