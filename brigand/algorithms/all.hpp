/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/detail/non_null.hpp>
#include <brigand/functions/invoke.hpp>
#include <type_traits>

namespace brigand
{
  namespace detail
  {
    template <bool...> struct bools_ {};
    template< typename Sequence, typename Predicate, typename... Ts> struct all;

    template<typename P, typename T> using invoked = brigand::invoke<P,T>;

    template< template<class...> class Sequence, typename Predicate, typename... Ts>
    struct  all<Sequence<Ts...>,Predicate>
          : std::is_same< bools_<true, invoked<Predicate,Ts>::value...>
                        , bools_<invoked<Predicate,Ts>::value..., true>
                        >
    {};
  }

  // Is a predicate true for every type ?
  template<typename Sequence, typename Predicate = detail::non_null>
  using all = typename detail::all<Sequence,Predicate>::type;
}
