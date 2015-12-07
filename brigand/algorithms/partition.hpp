/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/fold.hpp>
#include <brigand/sequences/clear.hpp>
#include <brigand/sequences/pair.hpp>
#include <brigand/functions/lambda/protect.hpp>
#include <brigand/functions/lambda/apply.hpp>

namespace brigand
{
  namespace detail
  {
    template<bool, class T, class P>
    struct partition_impl;

    template<class T, template<class...> class Seq, class... L, class... R>
    struct partition_impl<true, T, pair<Seq<L...>, Seq<R...>>>
    {
      using type = pair<Seq<L..., T>, Seq<R...>>;
    };

    template<class T, template<class...> class Seq, class... L, class... R>
    struct partition_impl<false, T, pair<Seq<L...>, Seq<R...>>>
    {
      using type = pair<Seq<L...>, Seq<R..., T>>;
    };

    template<class ProtectedPred>
    struct partition_test
    {
      template<class State, class Element>
      struct apply
      {
        using bool_ = brigand::apply<typename ProtectedPred::type, Element>;
        using type = typename partition_impl<bool_::value, Element, State>::type;
      };
    };
  }

  template<class Seq, class Pred>
  using partition = fold<
    Seq,
    pair<clear<Seq>, clear<Seq>>,
    detail::partition_test<protect<Pred>>
  >;
}
