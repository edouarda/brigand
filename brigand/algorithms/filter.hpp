/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/clear.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/algorithms/detail/non_null.hpp>

namespace brigand
{
  namespace detail
  {
    template<typename State, typename, bool...>
    struct update_state_impl
    {
      using type = State;
    };

    template< template<class...> class State, typename... KeptTs
            , typename T0
            >
    struct  update_state_impl< State<KeptTs...>, list<T0>
                             , true
                             >
    {
      using type = State<KeptTs..., T0>;
    };

    template< template<class...> class State, typename... KeptTs
            , typename T0, typename T1
            >
    struct  update_state_impl< State<KeptTs...>, list<T0, T1>
                             , true,  true
                             >
    {
      using type = State<KeptTs..., T0, T1>;
    };

    template< template<class...> class State, typename... KeptTs
            , typename T0, typename T1
            >
    struct  update_state_impl< State<KeptTs...>, list<T0, T1>
                             , true,  false
                             >
    {
      using type = State<KeptTs..., T0>;
    };

    template< template<class...> class State, typename... KeptTs
            , typename T0, typename T1
            >
    struct  update_state_impl< State<KeptTs...>, list<T0, T1>
                             , false, true
                             >
    {
      using type = State<KeptTs..., T1>;
    };

    template< template<class...> class State, typename... KeptTs
            , typename T0, typename T1, typename T2
            >
    struct  update_state_impl< State<KeptTs...>, list<T0, T1, T2>
                             , true,  true,  true
                             >
    {
      using type = State<KeptTs..., T0, T1, T2>;
    };

    template< template<class...> class State, typename... KeptTs
            , typename T0, typename T1, typename T2
            >
    struct  update_state_impl< State<KeptTs...>, list<T0, T1, T2>
                             , true,  true,  false
                             >
    {
      using type = State<KeptTs..., T0, T1>;
    };

    template< template<class...> class State, typename... KeptTs
            , typename T0, typename T1, typename T2
            >
    struct  update_state_impl< State<KeptTs...>, list<T0, T1, T2>
                             , true,  false, false
                             >
    {
      using type = State<KeptTs..., T0>;
    };

    template< template<class...> class State, typename... KeptTs
            , typename T0, typename T1, typename T2
            >
    struct  update_state_impl< State<KeptTs...>, list<T0, T1, T2>
                             , false, false, true
                             >
    {
      using type = State<KeptTs..., T2>;
    };

    template< template<class...> class State, typename... KeptTs
            , typename T0, typename T1, typename T2
            >
    struct  update_state_impl< State<KeptTs...>, list<T0, T1, T2>
                             , false, true,  true
                             >
    {
      using type = State<KeptTs..., T1, T2>;
    };

    template< template<class...> class State, typename... KeptTs
            , typename T0, typename T1, typename T2
            >
    struct  update_state_impl< State<KeptTs...>, list<T0, T1, T2>
                             , true,  false, true
                             >
    {
      using type = State<KeptTs..., T0, T2>;
    };

    template< template<class...> class State, typename... KeptTs
            , typename T0, typename T1, typename T2
            >
    struct  update_state_impl< State<KeptTs...>, list<T0, T1, T2>
                             , false, true,  false
                             >
    {
      using type = State<KeptTs..., T1>;
    };

    template<template<class> class Predicate, typename State, typename... Ts>
    using update_state = typename update_state_impl< State
                                                   , list<Ts...>
                                                   , !!Predicate<Ts>::value...
                                                   >::type;

    template<template<class> class Predicate, typename State, typename Sequence>
    struct filter_impl;

    template< template<class> class Predicate
            , typename State
            , template<class...> class Sequence
            >
    struct  filter_impl<Predicate, State, Sequence<> >
    {
      using type = State;
    };

    template< template<class> class Predicate
            , typename State
            , template<class...> class Sequence, typename T0, typename... Ts
            >
    struct  filter_impl<Predicate, State, Sequence<T0, Ts...> >
    {
      using type = typename filter_impl< Predicate
                                       , update_state<Predicate, State, T0>
                                       , Sequence<Ts...>
                                       >::type;
    };

    template< template<class> class Predicate
            , typename State
            , template<class...> class Sequence, typename T0, typename T1, typename... Ts
            >
    struct  filter_impl<Predicate, State, Sequence<T0, T1, Ts...> >
    {
      using type = typename filter_impl< Predicate
                                       , update_state<Predicate, State, T0, T1>
                                       , Sequence<Ts...>
                                       >::type;
    };

    template< template<class> class Predicate
            , typename State
            , template<class...> class Sequence, typename T0, typename T1, typename T2, typename... Ts
            >
    struct  filter_impl<Predicate, State, Sequence<T0, T1, T2, Ts...> >
    {
      using type = typename filter_impl< Predicate
                                       , update_state<Predicate, State, T0, T1, T2>
                                       , Sequence<Ts...>
                                       >::type;
    };
  }

  // return Sequence with elements for which Predicate returns false removed
  template< typename Sequence
          , template<class> class Predicate = detail::non_null
          >
  using filter = typename detail::filter_impl<Predicate, clear<Sequence>, Sequence>::type;
}
