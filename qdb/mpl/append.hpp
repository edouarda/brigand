
#pragma once

#include <qdb/mpl/list.hpp>

namespace brigand
{
  template <class... L> struct append_impl;

  template <class... L> using append = typename append_impl<L...>::type;

  template <> struct append_impl<>
  {
    using type = brigand::empty_list;
  };

  template<template<class...> class L, class... T>
  struct append_impl<L<T...>>
  {
    using type = L<T...>;
  };

  template<template<class...> class L1, class... T1, template<class...> class L2, class... T2, class... Lr>
  struct append_impl<L1<T1...>, L2<T2...>, Lr...>
  {
    using type = append<L1<T1..., T2...>, Lr...>;
  };
}
