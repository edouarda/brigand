/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/list.hpp>
#include <brigand/sequences/pair.hpp>
#include <brigand/algorithms/detail/lazy_identity.hpp>

namespace brigand
{
  namespace detail
  {
    template<typename State, typename Us, bool... PredResults> struct update_state_impl;

    template<template<class...> class Seq, typename... Ts, typename... Fs, typename U0>
    struct update_state_impl<pair<Seq<Ts...>, Seq<Fs...> >, list<U0        >, true >
         : lazy_identity<pair<Seq<Ts..., U0        >, Seq<Fs...            > > >
    {};

    template<template<class...> class Seq, typename... Ts, typename... Fs, typename U0>
    struct update_state_impl<pair<Seq<Ts...>, Seq<Fs...> >, list<U0        >, false>
         : lazy_identity<pair<Seq<Ts...            >, Seq<Fs..., U0        > > >
    {};

    template<template<class...> class Seq, typename... Ts, typename... Fs, typename U0, typename U1>
    struct update_state_impl<pair<Seq<Ts...>, Seq<Fs...> >, list<U0, U1    >, true,  true >
         : lazy_identity<pair<Seq<Ts..., U0, U1    >, Seq<Fs...            > > >
    {};

    template<template<class...> class Seq, typename... Ts, typename... Fs, typename U0, typename U1>
    struct update_state_impl<pair<Seq<Ts...>, Seq<Fs...> >, list<U0, U1    >, true,  false>
         : lazy_identity<pair<Seq<Ts..., U0        >, Seq<Fs..., U1        > > >
    {};

    template<template<class...> class Seq, typename... Ts, typename... Fs, typename U0, typename U1>
    struct update_state_impl<pair<Seq<Ts...>, Seq<Fs...> >, list<U0, U1    >, false, false>
         : lazy_identity<pair<Seq<Ts...            >, Seq<Fs..., U0, U1    > > >
    {};

    template<template<class...> class Seq, typename... Ts, typename... Fs, typename U0, typename U1>
    struct update_state_impl<pair<Seq<Ts...>, Seq<Fs...> >, list<U0, U1    >, false, true >
         : lazy_identity<pair<Seq<Ts..., U1        >, Seq<Fs..., U0        > > >
    {};

    template<template<class...> class Seq, typename... Ts, typename... Fs, typename U0, typename U1, typename U2>
    struct update_state_impl<pair<Seq<Ts...>, Seq<Fs...> >, list<U0, U1, U2>, true,  true,  true >
         : lazy_identity<pair<Seq<Ts..., U0, U1, U2>, Seq<Fs...            > > >
    {};

    template<template<class...> class Seq, typename... Ts, typename... Fs, typename U0, typename U1, typename U2>
    struct update_state_impl<pair<Seq<Ts...>, Seq<Fs...> >, list<U0, U1, U2>, true,  true,  false>
         : lazy_identity<pair<Seq<Ts..., U0, U1    >, Seq<Fs..., U2        > > >
    {};

    template<template<class...> class Seq, typename... Ts, typename... Fs, typename U0, typename U1, typename U2>
    struct update_state_impl<pair<Seq<Ts...>, Seq<Fs...> >, list<U0, U1, U2>, true,  false, false>
         : lazy_identity<pair<Seq<Ts..., U0        >, Seq<Fs..., U1, U2    > > >
    {};

    template<template<class...> class Seq, typename... Ts, typename... Fs, typename U0, typename U1, typename U2>
    struct update_state_impl<pair<Seq<Ts...>, Seq<Fs...> >, list<U0, U1, U2>, false, false, false>
         : lazy_identity<pair<Seq<Ts...            >, Seq<Fs..., U0, U1, U2> > >
    {};

    template<template<class...> class Seq, typename... Ts, typename... Fs, typename U0, typename U1, typename U2>
    struct update_state_impl<pair<Seq<Ts...>, Seq<Fs...> >, list<U0, U1, U2>, false, false, true >
         : lazy_identity<pair<Seq<Ts..., U2        >, Seq<Fs..., U0, U1    > > >
    {};

    template<template<class...> class Seq, typename... Ts, typename... Fs, typename U0, typename U1, typename U2>
    struct update_state_impl<pair<Seq<Ts...>, Seq<Fs...> >, list<U0, U1, U2>, false, true,  true >
         : lazy_identity<pair<Seq<Ts..., U1, U2    >, Seq<Fs..., U0        > > >
    {};

    template<template<class...> class Seq, typename... Ts, typename... Fs, typename U0, typename U1, typename U2>
    struct update_state_impl<pair<Seq<Ts...>, Seq<Fs...> >, list<U0, U1, U2>, true,  false, true >
         : lazy_identity<pair<Seq<Ts..., U0, U2    >, Seq<Fs..., U1        > > >
    {};

    template<template<class...> class Seq, typename... Ts, typename... Fs, typename U0, typename U1, typename U2>
    struct update_state_impl<pair<Seq<Ts...>, Seq<Fs...> >, list<U0, U1, U2>, false, true,  false>
         : lazy_identity<pair<Seq<Ts..., U1        >, Seq<Fs..., U0, U2    > > >
    {};

    template<template<class> class Predicate, typename State, typename... Us>
    using update_state = typename update_state_impl< State
                                                   , list<Us...>
                                                   , !!Predicate<Us>::value...>::type;

    template<template<class> class Predicate, typename State, typename Sequence>
    struct partition_impl;

    template< template<class> class Predicate
            , typename State
            , template<class...> class Sequence
            >
    struct  partition_impl<Predicate, State, Sequence<> >
    {
      using type = State;
    };

    template< template<class> class Predicate
            , typename State
            , template<class...> class Sequence
            , typename U0, typename... Us
            >
    struct  partition_impl<Predicate, State, Sequence<U0, Us...> >
         :  partition_impl<Predicate, update_state<Predicate, State, U0>, Sequence<Us...> >
    {};

    template< template<class> class Predicate
            , typename State
            , template<class...> class Sequence
            , typename U0, typename U1, typename... Us
            >
    struct  partition_impl<Predicate, State, Sequence<U0, U1, Us...> >
         :  partition_impl<Predicate, update_state<Predicate, State, U0, U1>, Sequence<Us...> >
    {};

    template< template<class> class Predicate
            , typename State
            , template<class...> class Sequence
            , typename U0, typename U1, typename U2, typename... Us
            >
    struct  partition_impl<Predicate, State, Sequence<U0, U1, U2, Us...> >
         :  partition_impl<Predicate, update_state<Predicate, State, U0, U1, U2>, Sequence<Us...> >
    {};
  }

  // return a pair:
  //  - first contains elements from Sequence for which Predicate returns true
  //  - second contains elements from Sequence for which Predicate returns false
  template< typename Sequence
          , template<class> class Predicate
          >
  using partition = typename detail::partition_impl<Predicate, pair<empty_list, empty_list>, Sequence>::type;

  // naive implementation is already stable
  template< typename Sequence
          , template<class> class Predicate
          >
  using stable_partition = partition<Sequence, Predicate>;
}
