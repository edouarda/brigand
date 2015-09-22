/*==================================================================================================
  Copyright (c) 2015 Edouard Alligan and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/at.hpp>

namespace brigand
{
  template<std::size_t Index> struct placeholders {};

  namespace detail
  {
    template<typename T, typename List> struct substitute
    {
      using type = T;
    };

    template<std::size_t Index, typename List>
    struct substitute<placeholders<Index>,List>
    {
      using type = brigand::at_c<List,Index>;
    };
  }

  template<typename T, typename List>
  using substitute = typename detail::substitute<T,List>::type;

  using _  = placeholders<0>;
  using _1 = placeholders<0>;
  using _2 = placeholders<1>;
  using _3 = placeholders<2>;
  using _4 = placeholders<3>;
  using _5 = placeholders<4>;
  using _6 = placeholders<5>;
  using _7 = placeholders<6>;
  using _8 = placeholders<7>;
  using _9 = placeholders<8>;
}
