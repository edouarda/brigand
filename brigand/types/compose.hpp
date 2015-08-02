/*==================================================================================================
  Copyright (c) 2015 Edouard Alligan and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

namespace brigand
{
  template<template<class...> class Tpl, class... Ts>
  struct compose
  {
    template<class... Us>
    using type = Tpl<Ts..., Us...>;
  };

  template<template<class...> class Tpl, class... Ts>
  struct unary_compose
  {
    template<class T>
    using type = Tpl<Ts..., T>;
  };

  template<template<class...> class Tpl, class... Ts>
  struct binary_compose
  {
    template<class T, class U>
    using type = Tpl<Ts..., T, U>;
  };
}
