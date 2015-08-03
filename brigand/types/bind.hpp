/*==================================================================================================
  Copyright (c) 2015 Edouard Alligan and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

namespace brigand
{
namespace detail
{
  template<template<class...> class Tpl, class... T>
  struct bind_impl
  {
    using type = Tpl<T...>;
  };
}

  template<template<class...> class Tpl, class... First>
  struct bind
  {
    template<class... Us>
    using type = typename detail::bind_impl<Tpl, First..., Us...>::type;
  };

  template<template<class...> class Tpl, class... First>
  struct unary_bind
  {
    template<class T>
    using type = Tpl<First..., T>;
  };

  template<template<class...> class Tpl, class... First>
  struct binary_bind
  {
    template<class T, class U>
    using type = Tpl<First..., T, U>;
  };
}
