/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <type_traits>

namespace brigand
{
  // Types list
  template <class... T> struct list {};

  // Values list
  template<typename T, T... Values>
  using integral_list = brigand::list< std::integral_constant<T,Values>...>;

  // Empty list
  using empty_sequence = brigand::list<>;
}
