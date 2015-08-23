/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/detail/non_null.hpp>
#include <type_traits>

namespace brigand
{
  namespace detail
  {
    template<typename Sequence> struct empty_sequence_for_impl;

    template<template<class...> class Sequence, typename... Ts>
    struct empty_sequence_for_impl<Sequence<Ts...>>
    {
      using type = Sequence<>;
    };

    template<typename Sequence>
    using empty_sequence_for = typename empty_sequence_for_impl<Sequence>::type;

    template<typename Sequence, typename State, template<class> class Predicate>
    struct filter_impl;

    template< template<class...> class Sequence
            , typename T
            , typename... Ts
            , template<class...> class State
            , typename... FilteredTs
            , template<class> class Predicate
            >
    struct  filter_impl<Sequence<T, Ts...>, State<FilteredTs...>, Predicate>
         :  std::conditional< Predicate<T>::value
                            , filter_impl<Sequence<Ts...>, State<FilteredTs..., T>, Predicate>
                            , filter_impl<Sequence<Ts...>, State<FilteredTs...   >, Predicate>
                            >::type
    {};

    template< template<class...> class Sequence
            , template<class...> class State
            , typename... FilteredTs
            , template<class> class Predicate
            >
    struct  filter_impl<Sequence<>, State<FilteredTs...>, Predicate>
    {
      using type = State<FilteredTs...>;
    };

    template<typename Sequence, template<class> class Predicate>
    using filter = typename filter_impl< Sequence
                                       , empty_sequence_for<Sequence>
                                       , Predicate
                                       >::type;
  }

  // return Sequence with elements for which Predicate returns false removed
  template< typename Sequence
          , template<class> class Predicate = detail::non_null
          >
  using filter = typename detail::filter<Sequence, Predicate>;
}
