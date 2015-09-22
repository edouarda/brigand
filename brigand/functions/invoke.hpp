/*==================================================================================================
  Copyright (c) 2015 Edouard Alligan and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/placeholders.hpp>
#include <brigand/sequences/list.hpp>

namespace brigand
{
  template<typename T, typename R = void> struct enable_if_type
  {
    using type = R;
  };

  namespace detail
  {
    template<typename Lambda, typename Args, typename OnlyIf = void>
    struct invoke;

    // By default, just substitute the types
    template<template<class...> class Lambda, typename... Types, typename Args,typename OnlyIf>
    struct invoke< Lambda<Types...>, Args,OnlyIf>
    {
      using type = Lambda< brigand::substitute<Types,Args>... >;
    };

    // Try to find a ::invoke<...>
    template<typename Lambda, template<class...> class List, typename... Args>
    struct invoke < Lambda, List<Args...>
                  , typename enable_if_type<typename Lambda::template invoke<Args...>>::type
                  >
    {
      using type = typename Lambda::template invoke<Args...>::type;
    };

    template< template<class...> class Lambda, typename... Types
            , template<class...> class List, typename... Args
            >
    struct invoke < Lambda<Types...>, List<Args...>
                  , typename enable_if_type<typename Lambda<Types...>::template invoke<Args...>>::type
                  >
    {
      using type = typename Lambda<Types...>::template invoke<Args...>::type;
    };

    // Try to find a ::type
    template<template<class...> class Lambda, typename... Types, typename Args>
    struct invoke < Lambda<Types...>, Args
                  , typename enable_if_type<typename Lambda<Types...>::type>::type
                  >
    {
      using type = typename Lambda< brigand::substitute<Types,Args>...>::type;
    };
  }

  template<typename Lambda, typename... Args>
  using invoke = typename detail::invoke<Lambda,brigand::list<Args...>>::type;
}
