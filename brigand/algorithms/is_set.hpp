/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/range.hpp>
#include <brigand/types/type.hpp>

namespace brigand
{
namespace detail
{
  template<class, class T> struct unique_x_t
  // :type_<T> // better with gcc, very bad with clang when the list contains many same elements
  { operator type_<T> (); };

  template<class Ints, class... Ts>
  struct is_set_impl;

  template<>
  struct is_set_impl<list<>>
  {
    using type = std::true_type;
  };

  inline std::true_type true_fn(...);

  template<class... Ints, class... Ts>
  struct is_set_impl<list<Ints...>, Ts...>
  {
    struct Pack : unique_x_t<Ints, Ts>... {};

    template<class... Us>
    static auto is_set(Us...) -> decltype(true_fn(static_cast<Us>(Pack())...));
    static std::false_type is_set(...);

    using type = decltype(is_set(type_<Ts>()...));
  };
}

  template<class... Ts>
  using is_set = typename detail::is_set_impl<range<int, 0, sizeof...(Ts)>, Ts...>::type;
}
