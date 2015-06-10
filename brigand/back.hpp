
#pragma once

#include <brigand/list.hpp>
#include <brigand/detail/last_element.hpp>

namespace brigand
{
  // push_back
  namespace detail
  {
    template<class L, class... T> struct push_back_impl;

    template<template<class...> class L, class... U, class... T>
    struct push_back_impl<L<U...>, T...>
    {
        using type = L<U..., T...>;
    };
  }

  template<class L, class... T>
  using push_back = typename detail::push_back_impl<L, T...>::type;

  // back
  namespace detail
  {
    template<class L> struct back_impl;

    template<template<class...> class L, class... U>
    struct back_impl<L<U...>>
    {
      using type = typename last_element<U...>::type;
    };

  }

  template <class L>
  using back = typename detail::back_impl<L>::type;

  // pop back
  namespace detail
  {
    template <class L> struct pop_back_impl;

    template<template<class...> class L, class... U>
    struct pop_back_impl<L<U...>>
    {
        using type = typename without_last_element<L, U...>::type;
    };
  }

  template <class L>
  using pop_back = typename detail::pop_back_impl<L>::type;
}
