
#pragma once

namespace brigand
{
  template <class A, template<class...> class B> struct apply_impl;

  template<template<class...> class A, class... T, template<class...> class B>
  struct apply_impl<A<T...>, B>
  {
    using type = B<T...>;
  };

  template<class A, template<class...> class B>
  using apply = typename apply_impl<A, B>::type;
}
