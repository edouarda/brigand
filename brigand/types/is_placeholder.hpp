/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/bool.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/placeholders.hpp>

namespace brigand
{
  template<typename... T> struct is_placeholder;

  template<typename T> struct is_placeholder<T> : brigand::false_ {};

  template<std::size_t I>
  struct is_placeholder< brigand::placeholders<I>> : brigand::true_ {};

  template <bool...> struct checks_ {};

  template<typename T, typename U, typename... Ts>
  struct is_placeholder<T,U,Ts...>
        : bool_ < !std::is_same < checks_ < true
                                          , !is_placeholder<T>::value, !is_placeholder<U>::value
                                          , !is_placeholder<Ts>::value...
                                          >
                                , checks_ < !is_placeholder<T>::value, !is_placeholder<U>::value
                                          , !is_placeholder<Ts>::value...
                                          , true
                                          >
                                >::value
                >
  {};
}

