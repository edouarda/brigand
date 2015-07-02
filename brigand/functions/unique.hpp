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
  struct unique_impl
  {
    template<class U>
    static std::true_type unique(U);

    static std::true_type unique();
  };

  template<class, class T>
  struct unique_x_t
  { operator type_<T> (); };

  template<class... T>
  struct unique_set : T... {};

  template<class Int, class... Ints, class L, class... R>
  struct unique_impl<list<Int, Ints...>, L, R...>
  {
    template<class U, class = decltype(static_cast<type_<U>>(unique_set<unique_x_t<Int, L>, unique_x_t<Ints, R>...>()))>
    static std::false_type unique(type_<U>);

    template<class U>
    static decltype(unique_impl<list<Ints...>, R...>::unique(type_<L>()))
    unique(U);

    static decltype(unique_impl<list<Ints...>, R...>::unique(type_<L>()))
    unique();
  };
}

  template <class... T>
  using unique = decltype(detail::unique_impl<make_sequence<uint_<0>, sizeof...(T)>, T...>::unique());
}
