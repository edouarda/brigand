/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

namespace brigand
{
  template <class A, template<class...> class B> struct apply_impl;

  template<template<class...> class A, class... T, template<class...> class B>
  struct apply_impl<A<T...>, B>
  {
    using type = B<T...>;
  };

  template<class A, template<class...> class B>
  using apply = typename apply_impl<A, B>::type;
}
