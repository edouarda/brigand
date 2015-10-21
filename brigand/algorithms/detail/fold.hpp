/*==================================================================================================
  Copyright (c) 2015 QuasarDB
  Copyright (c) 2015 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/lambda/apply.hpp>

namespace brigand { namespace detail
{

  template <class Functor, class State, class Sequence>
  struct fold_impl
  {
    using type = State;
  };

  template <class Functor, class State, template <class...> class Sequence,
            typename T0>
  struct fold_impl<Functor, State, Sequence<T0>>
  {
    using type = typename brigand::apply<Functor, State, T0>;
  };

  template <class Functor, class State, template <class...> class Sequence,
            typename T0, typename T1>
  struct fold_impl<Functor, State, Sequence<T0, T1>>
  {
      using state0 = typename brigand::apply<Functor, State, T0>;

      using type = typename brigand::apply<Functor, state0, T1>;
  };

  template <class Functor, class State, template <class...> class Sequence,
            typename T0, typename T1, typename T2>
  struct fold_impl<Functor, State, Sequence<T0, T1, T2>>
  {
      using state0 = typename brigand::apply<Functor, State, T0>;
      using state1 = typename brigand::apply<Functor, state0, T1>;

      using type = typename brigand::apply<Functor, state1, T2>;
  };

  template <class Functor, class State, template <class...> class Sequence,
            typename T0, typename T1, typename T2, typename T3>
  struct fold_impl<Functor, State, Sequence<T0, T1, T2, T3>>
  {
      using state0 = typename brigand::apply<Functor, State, T0>;
      using state1 = typename brigand::apply<Functor, state0, T1>;
      using state2 = typename brigand::apply<Functor, state1, T2>;

      using type = typename brigand::apply<Functor, state2, T3>;
  };

  template <class Functor, class State, template <class...> class Sequence,
            typename T0, typename T1, typename T2, typename T3, typename T4>
  struct fold_impl<Functor, State, Sequence<T0, T1, T2, T3, T4>>
  {
      using state0 = typename brigand::apply<Functor, State, T0>;
      using state1 = typename brigand::apply<Functor, state0, T1>;
      using state2 = typename brigand::apply<Functor, state1, T2>;
      using state3 = typename brigand::apply<Functor, state2, T3>;

      using type = typename brigand::apply<Functor, state3, T4>;
  };

  template <class Functor, class State, template <class...> class Sequence,
            typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
  struct fold_impl<Functor, State, Sequence<T0, T1, T2, T3, T4, T5>>
  {
      using state0 = typename brigand::apply<Functor, State, T0>;
      using state1 = typename brigand::apply<Functor, state0, T1>;
      using state2 = typename brigand::apply<Functor, state1, T2>;
      using state3 = typename brigand::apply<Functor, state2, T3>;
      using state4 = typename brigand::apply<Functor, state3, T4>;

      using type = typename brigand::apply<Functor, state4, T5>;
  };

  template <class Functor, class State, template <class...> class Sequence,
      typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
  struct fold_impl<Functor, State, Sequence<T0, T1, T2, T3, T4, T5, T6>>
  {
      using state0 = typename brigand::apply<Functor, State, T0>;
      using state1 = typename brigand::apply<Functor, state0, T1>;
      using state2 = typename brigand::apply<Functor, state1, T2>;
      using state3 = typename brigand::apply<Functor, state2, T3>;
      using state4 = typename brigand::apply<Functor, state3, T4>;
      using state5 = typename brigand::apply<Functor, state4, T5>;

      using type = typename brigand::apply<Functor, state5, T6>;
  };

  template <class Functor, class State, template <class...> class Sequence,
      typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
  struct fold_impl<Functor, State, Sequence<T0, T1, T2, T3, T4, T5, T6, T7>>
  {
      using state0 = typename brigand::apply<Functor, State, T0>;
      using state1 = typename brigand::apply<Functor, state0, T1>;
      using state2 = typename brigand::apply<Functor, state1, T2>;
      using state3 = typename brigand::apply<Functor, state2, T3>;
      using state4 = typename brigand::apply<Functor, state3, T4>;
      using state5 = typename brigand::apply<Functor, state4, T5>;
      using state6 = typename brigand::apply<Functor, state5, T6>;

      using type = typename brigand::apply<Functor, state6, T7>;
  };

  template <class Functor, class State, template <class...> class Sequence,
      typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename... T>
  struct fold_impl<Functor, State, Sequence<T0, T1, T2, T3, T4, T5, T6, T7, T...>>
  {
      using state0 = typename brigand::apply<Functor, State, T0>;
      using state1 = typename brigand::apply<Functor, state0, T1>;
      using state2 = typename brigand::apply<Functor, state1, T2>;
      using state3 = typename brigand::apply<Functor, state2, T3>;
      using state4 = typename brigand::apply<Functor, state3, T4>;
      using state5 = typename brigand::apply<Functor, state4, T5>;
      using state6 = typename brigand::apply<Functor, state5, T6>;
      using state7 = typename brigand::apply<Functor, state6, T7>;

      using type = typename fold_impl<Functor, state7, Sequence<T...>>::type;
  };

} }
