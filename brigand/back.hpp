
#pragma once

#include <brigand/list.hpp>
#include <brigand/append.hpp>

namespace brigand
{
  // push_back
  template<class L, class... T> struct push_back_impl;

  template<template<class...> class L, class... U, class... T>
  struct push_back_impl<L<U...>, T...>
  {
      using type = L<U..., T...>;
  };

  template<class L, class... T>
  using push_back = typename push_back_impl<L, T...>::type;

  // back

  // mmm no other way than recursion to get the last? I think there must...
  template <class First, class... R>
  struct last_element
  {
      using type = typename last_element<R...>::type;
  };

  template <class Last>
  struct last_element<Last>
  {
      using type = Last;
  };

  template<class L> struct back_impl;

  template<template<class...> class L, class... U>
  struct back_impl<L<U...>>
  {
      using type = typename last_element<U...>::type;
  };

  template <class L>
  using back = typename back_impl<L>::type;

  // pop back
  template <template <class...> class L, class First, class... R>
  struct without_last_element
  {
      using type = append<L<First>, typename  without_last_element<L, R...>::type>;
  };

  template <template <class...> class L, class Last>
  struct without_last_element<L, Last>
  {
      using type = empty_list;
  };

  template <class L> struct pop_back_impl;

  template<template<class...> class L, class... U>
  struct pop_back_impl<L<U...>>
  {
      using type = typename without_last_element<L, U...>::type;
  };

  template <class L>
  using pop_back = typename pop_back_impl<L>::type;
}
