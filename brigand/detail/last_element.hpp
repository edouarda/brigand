#pragma once

#include <brigand/append.hpp>

namespace brigand { namespace detail
{
  template <template <class...> class L, class First, class... R>
  struct without_last_element
  {
    using type = append<L<First>, typename without_last_element<L, R...>::type>;
  };

  template <template <class...> class L, class Last>
  struct without_last_element<L, Last>
  {
    using type = empty_list;
  };

  // Provides fast-lane for 1-8 elements
  template <class... R> struct last_element;

  template <class T0>
  struct last_element<T0>
  {
    using type = T0;
  };

  template <class T0,class T1>
  struct last_element<T0,T1>
  {
    using type = T1;
  };

  template <class T0,class T1,class T2>
  struct last_element<T0,T1,T2>
  {
    using type = T2;
  };

  template <class T0,class T1,class T2,class T3>
  struct last_element<T0,T1,T2,T3>
  {
    using type = T3;
  };

  template <class T0,class T1,class T2,class T3,class T4>
  struct last_element<T0,T1,T2,T3,T4>
  {
    using type = T4;
  };

  template <class T0,class T1,class T2,class T3,class T4,class T5>
  struct last_element<T0,T1,T2,T3,T4,T5>
  {
    using type = T5;
  };

  template <class T0,class T1,class T2,class T3,class T4,class T5,class T6>
  struct last_element<T0,T1,T2,T3,T4,T5,T6>
  {
    using type = T6;
  };

  template <class T0,class T1,class T2,class T3,class T4,class T5,class T6,class T7>
  struct last_element<T0,T1,T2,T3,T4,T5,T6,T7>
  {
    using type = T7;
  };

  template <class T0,class T1,class T2,class T3,class T4,class T5,class T6,class T7,class... R>
  struct last_element<T0,T1,T2,T3,T4,T5,T6,T7,R...>
  {
    using type = typename last_element<R...>::type;
  };
} }
