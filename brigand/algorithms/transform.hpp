/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/lambda/apply.hpp>

namespace brigand
{
  namespace detail
  {
    template<std::size_t, class Seq1, class FuncOrSeq2, class FuncOrvoid = void>
    struct transform_selector;

    template<template<class...> class Seq, class... T, class Func>
    struct transform_selector<0, Seq<T...>, Func, void>
    {
      using type = Seq<brigand::apply<Func, T>...>;
    };

    template<template<class...> class Seq1, class... T1, template<class...> class Seq2, class... T2, class Func>
    struct transform_selector<1, Seq1<T1...>, Seq2<T2...>, Func>
    {
      using type = Seq1<brigand::apply<Func, T1, T2>...>;
    };
  }

  namespace lazy
  {
    template<typename Sequence1, typename OpSeq1, typename... OpSeq2>
    using transform = typename detail::transform_selector<sizeof...(OpSeq2), Sequence1, OpSeq1, OpSeq2...>;
  }

  // Main transform entry point
  template<typename Sequence1, typename OpSeq1, typename... OpSeq2>
  using transform = typename detail::transform_selector<sizeof...(OpSeq2), Sequence1, OpSeq1, OpSeq2...>::type;

}
