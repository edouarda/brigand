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
    template<class T, class If = void>
    struct quote_impl
    {
      using type = T;
    };

    template<class T>
    struct quote_impl<T, typename has_type<typename T::type>::type>
    {
      using type = typename T::type;
    };

  }

  template<template<class ...> class Metafunction> struct quote
  {
    template<typename... Us> struct apply : detail::quote_impl<Metafunction<Us...>> {};
  };
}
