/*==================================================================================================
  Copyright (c) 2015 QuasarDB
  Copyright (c) 2015 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

namespace brigand { namespace detail
{
  // fold implementation - Basic case return state
  template<template<class,class> class Functor, class State, class Sequence>
  struct fold_impl
  {
    using type = State;
  };

  // fold implementation - lane 1
  template<template<class,class> class Functor, class State
          , template<class...> class Sequence, typename T
          >
  struct fold_impl<Functor, State, Sequence<T>>
  {
    using type = Functor<State,T>;
  };

  // fold implementation - lane 2
  template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1
          >
  struct fold_impl<Functor, State, Sequence<T0,T1>>
  {
    using state0 = Functor<State,T0>;
    using type   = Functor<state0, T1>;
  };

  // fold implementation - lane 3
  template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using type   = Functor<state1, T2>;
  };

  // fold implementation - lane 4
  template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2, typename T3
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using type   = Functor<state2, T3>;
  };

  // fold implementation - lane 5
  template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2, typename T3, typename T4
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3,T4>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using state3 = Functor<state2, T3>;
    using type   = Functor<state3, T4>;
  };

  // fold implementation - lane 6
  template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2
          , typename T3, typename T4, typename T5
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3,T4,T5>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using state3 = Functor<state2, T3>;
    using state4 = Functor<state3, T4>;
    using type   = Functor<state4, T5>;
  };

  // fold implementation - lane 7
  template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2
          , typename T3, typename T4, typename T5
          , typename T6
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3,T4,T5,T6>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using state3 = Functor<state2, T3>;
    using state4 = Functor<state3, T4>;
    using state5 = Functor<state4, T5>;
    using type   = Functor<state5, T6>;
  };

  // fold implementation - lane 8
  template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2
          , typename T3, typename T4, typename T5
          , typename T6, typename T7
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3,T4,T5,T6,T7>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using state3 = Functor<state2, T3>;
    using state4 = Functor<state3, T4>;
    using state5 = Functor<state4, T5>;
    using state6 = Functor<state5, T6>;
    using type   = Functor<state6, T7>;
  };

  // fold implementation - lane 8+
  template<template<class,class> class Functor, class State
          , template<class...> class Sequence
          , typename T0, typename T1, typename T2, typename T3
          , typename T4, typename T5, typename T6, typename T7
          , class... T
          >
  struct fold_impl<Functor, State, Sequence<T0,T1,T2,T3,T4,T5,T6,T7,T...>>
  {
    using state0 = Functor<State,T0>;
    using state1 = Functor<state0, T1>;
    using state2 = Functor<state1, T2>;
    using state3 = Functor<state2, T3>;
    using state4 = Functor<state3, T4>;
    using state5 = Functor<state4, T5>;
    using state6 = Functor<state5, T6>;
    using state7 = Functor<state6, T7>;
    using type = typename fold_impl<Functor,state7, Sequence<T...>>::type;
  };
} }
