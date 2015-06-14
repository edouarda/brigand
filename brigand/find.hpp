/*==================================================================================================
  Copyright (c) 2015 QuasarDB
  Copyright (c) 2015 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/detail/find.hpp>
#include <brigand/bool.hpp>
#include <brigand/list.hpp>

namespace brigand
{
  namespace detail
  {
    // Default find predicate
    template<typename T> using non_null = bool_< T::value != 0 >;
  }

  // find uses Predicate, it's very effective
  template< typename Sequence
          , template<class> class Predicate = detail::non_null
          >
  using find = typename detail::find_if_impl<Predicate, Sequence>::type;

  // Utility meta-function to check if nothing was found
  template< typename Sequence
          , template<class> class Predicate = detail::non_null
          >
  using not_found = typename std::is_same<find<Sequence,Predicate>,empty_list>::type;

  // Utility meta-function to check if something was found
  // Note: MSVC doesn't like the factoring with not found
  template< typename Sequence
          , template<class> class Predicate = detail::non_null
          >
  using found = bool_<!std::is_same<find<Sequence,Predicate>,empty_list>::value>;
}
