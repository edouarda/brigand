/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/range.hpp>
#include <brigand/types/type.hpp>
#include <brigand/types/bool.hpp>

namespace brigand
{
namespace detail
{
  template<class, class T> struct unique_x_t
  : type_<T>
  {};

  template<class Ints, class... Ts>
  struct is_set_cont;

  template<>
  struct is_set_cont<list<>>
  {
    using type = std::true_type;
  };

  template<class... Ints, class... Ts>
  struct is_set_cont<list<Ints...>, Ts...>
  : unique_x_t<Ints, Ts>...
  {
  };
}

  template<class... Ts>
  using is_set = bool_<sizeof(detail::is_set_cont<range<int, 0, sizeof...(Ts)>, Ts...>) == 1>;
}
