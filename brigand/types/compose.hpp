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
  template<template<class...> class Unary, template<class...> class Gen, class... Ts>
  struct compose_impl
  {
    using type = Unary<Gen<Ts...>>;
  };

  template<template<class...> class Gen, template<class...> class Unary, class... Ts>
  struct compose2_impl
  {
    using type = Gen<Unary<Ts>...>;
  };
}

  template<template<class> class Unary, template<class...> class Gen, class... First>
  struct compose
  {
    template<class... Ts>
    using type = typename detail::compose_impl<Unary, Gen, First..., Ts...>::type;
  };

  template<template<class...> class Gen, template<class> class Unary, class... First>
  struct compose2
  {
    template<class... Ts>
    using type = typename detail::compose2_impl<Gen, Unary, First..., Ts...>::type;
  };

  template<template<class> class Unary, template<class...> class Gen, class... First>
  struct unary_compose
  {
    template<class T>
    using type = Unary<Gen<First..., T>>;
  };

  template<template<class...> class Gen, template<class> class Unary, class... First>
  struct unary_compose2
  {
    template<class T>
    using type = Gen<Unary<First>..., Unary<T>>;
  };

  template<template<class> class Unary, template<class...> class Gen, class... First>
  struct binary_compose
  {
    template<class T, class U>
    using type = Unary<Gen<First..., T, U>>;
  };

  template<template<class...> class Gen, template<class> class Unary, class... First>
  struct binary_compose2
  {
    template<class T, class U>
    using type = Gen<Unary<First>..., Unary<T>, Unary<U>>;
  };
}
