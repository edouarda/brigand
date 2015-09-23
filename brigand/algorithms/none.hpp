/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/bool.hpp>
#include <brigand/algorithms/detail/non_null.hpp>
#include <brigand/algorithms/all.hpp>

namespace brigand
{
  namespace detail
  {
    template<typename Sequence, template<class> class Predicate> 
	struct none
    {
      template<typename T> struct nope : bool_< !Predicate<T>::value > {};
      using type = all<Sequence, nope>;
    };
  }

  // Is a predicate true for no type ?
  template< typename Sequence
          , template<class> class Predicate = detail::non_null
          >
  using none = typename detail::none<Sequence,Predicate>::type;
}
