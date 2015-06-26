/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/none.hpp>
#include <brigand/sequences/list.hpp>

namespace brigand
{
  namespace detail
  {
    template< typename Sequence
            , template<class> class Predicate = detail::non_null
            >
    struct all
    {
      template<typename T> using pred = bool_< !Predicate<T>::value >;
      using type = none<Sequence, pred>;
    };
  }

  // Is a predicate true for every type ?
  template< typename Sequence
          , template<class> class Predicate = detail::non_null
          >
  using all = typename detail::all<Sequence,Predicate>::type;
}
