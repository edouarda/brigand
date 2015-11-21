/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/comparison/less.hpp>
#include <brigand/functions/lambda/quote.hpp>
#include <brigand/algorithms/partition.hpp>
#include <brigand/sequences/append.hpp>

namespace brigand
{
  namespace detail
  {
    template<class Comp, class Seq>
    struct sort_impl;

    template<class Comp, template<class...> class Seq, class... T>
    struct sort_impl<Comp, Seq<T...>>
    {
      using type = Seq<T...>;
    };

    template<class Comp, template<class...> class Seq, class Pivot, class T, class... Ts>
    struct sort_impl<Comp, Seq<Pivot, T, Ts...>>
    {
      template<class U> struct Pred { using type = brigand::apply<Comp, U, Pivot>; };
      using p = brigand::partition<Seq<T, Ts...>, Pred<brigand::_1>>;
      using type = brigand::append<
        typename sort_impl<Comp, typename p::first_type>::type,
        brigand::list<Pivot>,
        typename sort_impl<Comp, typename p::second_type>::type
      >;
    };
  }

  template<class Seq, class Comp = quote<less>>
  using sort = typename detail::sort_impl<Comp, Seq>::type;
}
