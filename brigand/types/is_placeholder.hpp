/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/bool.hpp>
#include <brigand/types/placeholders.hpp>

namespace brigand
{
  template<typename T> struct is_placeholder : brigand::false_ {};

  //template<typename T> struct is_placeholder<protect<T>> : brigand::false_ {};

  template<std::size_t I>
  struct is_placeholder< brigand::placeholders<I>> : brigand::true_ {};
}
