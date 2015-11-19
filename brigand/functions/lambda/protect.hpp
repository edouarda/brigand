/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/lambda/lambda.hpp>
#include <brigand/types/has_placeholders.hpp>

namespace brigand
{
  template<class T> struct protect
  {
    using type = T;
  };

  template<class F> struct lambda<protect<F>>
  {
    template<class... X> struct apply { using type = F; };
  };

  template<class T>
  struct has_placeholders<protect<T>>
  : std::false_type
  {};
}
