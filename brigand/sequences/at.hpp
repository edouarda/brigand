/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <brigand/sequences/map.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/range.hpp>
#include <brigand/types/type.hpp>

namespace brigand
{
  namespace detail
  {
    template<class> struct voidp { using type = void const *; };

    template<class T> struct element_at;

    template<template<typename...> class L, class... N>
    struct element_at<L<N...>>
    {
      template<typename T> T static at(typename voidp<N>::type..., T*, ...);
    };

    template<int N, typename Seq> struct at_impl;

    template<int N, template<typename...> class L, class... Ts >
    struct at_impl<N,L<Ts...>>
    {
      using type = decltype(element_at<range<int,0,N>>::at(static_cast<Ts*>(nullptr)...));
    };
  }

  template <class L, int Index>
  using at_c = typename detail::at_impl<Index, L>::type;

namespace detail
{
    template <typename T>
    struct has_at_method
    {
        struct dummy {};
        template <typename C, typename P>
        static auto test(P * p) -> decltype(C::at(*p), std::true_type());

        template <typename, typename>
        static std::false_type test(...);

        static const bool value = std::is_same<std::true_type, decltype(test<T, dummy>(nullptr))>::value;
    };

    template <class L, typename Index, bool>
    struct at_dispatch
    {
        using type = at_c<L, Index::value>;
    };

    template <class L, typename Index>
    struct at_dispatch<L, Index, true>
    {
        using type = lookup<L, Index>;
    };
}

    template <class Seq, typename K>
    using at = typename detail::at_dispatch<Seq, K, detail::has_at_method<Seq>::value>::type;
}
