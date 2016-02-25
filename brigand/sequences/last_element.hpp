/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/append.hpp>

namespace brigand { namespace detail
{
  template <template <class...> class L, class First, class... R>
  struct without_last_element
  {
    using type = append<L<First>, typename without_last_element<L, R...>::type>;
  };

  template <template <class...> class L, class Last>
  struct without_last_element<L, Last>
  {
    using type = empty_sequence;
  };

  template<class> using voidp = void const *;

  template<class T, class... Ts>
  struct last_element
  {
    template<class Us>
    static Us last(voidp<Ts>..., Us*);

    using type = decltype(last(nullptr, static_cast<Ts*>(nullptr)...));
  };

  // fix msvc 2013
  template<class T>
  struct last_element<T>
  {
    using type = T;
  };

  // fix msvc 2013
  template<class T, class U>
  struct last_element<T, U>
  {
    using type = U;
  };
} }
