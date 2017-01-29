/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/fold.hpp>
#include <brigand/functions/eval_if.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/sequences/has_key.hpp>
#include <brigand/sequences/set.hpp>
#include <brigand/types/type.hpp>

namespace brigand
{
  template <class L>
  using unique = fold<
    L,
    list<>,
    bind<
      join,
      bind<
        list,
        _1,
        bind<
          type_from,
          bind<
            eval_if,
            bind<has_key, bind<as_set, _1>, _2>,
            bind<type_, bind<list>>,
            bind<type_, bind<list, _2>>
          >
        >
      >
    >
  >;
}
