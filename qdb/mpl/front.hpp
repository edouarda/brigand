
#pragma once

namespace brigand
{
  // push_front
  template<class L, class... T> struct push_front_impl;

  template<template<class...> class L, class... U, class... T>
  struct push_front_impl<L<U...>, T...>
  {
      using type = L<T..., U...>;
  };

  template<class L, class... T>
  using push_front = typename push_front_impl<L, T...>::type;

  // front
  template <class First, class...>
  struct first_element
  {
      using type = First;
  };

  template<class L> struct front_impl;

  template<template<class...> class L, class... U>
  struct front_impl<L<U...>>
  {
      using type = typename first_element<U...>::type;
  };

  template <class L>
  using front = typename front_impl<L>::type;

  // pop front
  template <template <class...> class L, class First, class... R>
  struct without_first_element
  {
      using type = L<R...>;
  };

  template <class L> struct pop_front_impl;

  template<template<class...> class L, class... U>
  struct pop_front_impl<L<U...>>
  {
      using type = typename without_first_element<L, U...>::type;
  };

  template <class L>
  using pop_front = typename pop_front_impl<L>::type;
}
