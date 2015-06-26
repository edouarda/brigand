/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/find.hpp>
#include <brigand/sequences/list.hpp>

namespace brigand
{
  // Is a predicate true for at least one type ?
  template< typename Sequence
          , template<class> class Predicate = detail::non_null
          >
  using any = bool_<!std::is_same<find<Sequence,Predicate>,empty_list>::value>;
}
