/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/type.hpp>
#include <utility>
#include <type_traits>

namespace brigand
{
namespace detail {
  template<class Ints, class...T>
  struct unique_impl
  {
    template<class U>
    static std::true_type unique(U);

    static std::true_type unique();
  };

  template<std::size_t, class T>
  struct indexed_type
  { operator type_<T> (); };

  template<class... T>
  struct unique_set : T... {};

  template<std::size_t Int, std::size_t... Ints, class L, class... R>
  struct unique_impl<std::integer_sequence<std::size_t, Int, Ints...>, L, R...>
  {
    template<class U, class = decltype(static_cast<type_<U>>(unique_set<indexed_type<Int, L>, indexed_type<Ints, R>...>()))>
    static std::false_type unique(type_<U>);

    template<class U>
    static decltype(unique_impl<std::integer_sequence<std::size_t, Ints...>, R...>::unique(type_<L>()))
    unique(U);

    static decltype(unique_impl<std::integer_sequence<std::size_t, Ints...>, R...>::unique(type_<L>()))
    unique();
  };
}

  template <class... T>
  using unique = decltype(detail::unique_impl<std::make_index_sequence<sizeof...(T)>, T...>::unique());
}
