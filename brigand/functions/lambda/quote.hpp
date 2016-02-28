/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/has_type.hpp>

namespace brigand
{
  namespace detail
  {
    template<template<class ...> class Metafunction, typename If, typename... Us>
    struct quote_impl
    {
      using type = Metafunction<Us...>;
    };

    template< template<class ...> class Metafunction
            , typename... Us
            >
    struct quote_impl < Metafunction
                , typename has_type<typename Metafunction<Us...>::type>::type
                , Us...
                >
    {
      using type = typename Metafunction<Us...>::type;
    };

  }

  template<template<class ...> class Metafunction> struct quote
  {
    template<typename... Us> struct apply : detail::quote_impl<Metafunction, void, Us...> {};
  };
}
