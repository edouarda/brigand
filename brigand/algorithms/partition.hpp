/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/fold.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/pair.hpp>
#include <brigand/functions/lambda/protect.hpp>

namespace brigand
{
  namespace detail
  {
    template<class Pred, class T, class P, bool = brigand::apply<Pred, T>::value>
    struct partition_test_impl;

    template<class Pred, class T, class... L, class... R>
    struct partition_test_impl<Pred, T, pair<list<L...>, list<R...>>, true>
    {
      using type = pair<list<L..., T>, list<R...>>;
    };

    template<class Pred, class T, class... L, class... R>
    struct partition_test_impl<Pred, T, pair<list<L...>, list<R...>>, false>
    {
      using type = pair<list<L...>, list<R..., T>>;
    };

    template<class Protect>
    struct partition_test
    {
      template<class S, class E>
      struct apply
      {
        using type = typename partition_test_impl<typename Protect::type, E, S>::type;
      };
    };
  }

  template<class Seq, class Pred>
  using partition = fold<
    Seq,
    pair<list<>, list<>>,
    detail::partition_test<protect<Pred>>
  >;
}
