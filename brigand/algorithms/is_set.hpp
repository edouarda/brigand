/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/make_sequence.hpp>
#include <brigand/types/integer.hpp>
#include <brigand/types/type.hpp>

namespace brigand
{
namespace detail
{
  template<class Ints, class...T>
  struct is_set_impl
  {
    template<class U>
    static std::true_type is_set(U);

    static std::true_type is_set();
  };

  template<class, class T>
  struct unique_x_t
  { operator type_<T> (); };

  template<class... T>
  struct unique_set : T... {};

  template<class Int, class... Ints, class L, class... R>
  struct is_set_impl<list<Int, Ints...>, L, R...>
  {
    template<class U, class = decltype(static_cast<type_<U>>(unique_set<unique_x_t<Int, L>, unique_x_t<Ints, R>...>()))>
    static std::false_type is_set(type_<U>);

    template<class U>
    static decltype(is_set_impl<list<Ints...>, R...>::is_set(type_<L>()))
    is_set(U);

    static decltype(is_set_impl<list<Ints...>, R...>::is_set(type_<L>()))
    is_set(...);
  };
}

  template <class... T>
  using is_set = decltype(detail::is_set_impl<make_sequence<uint32_t<0>, sizeof...(T)>, T...>::is_set());
}
