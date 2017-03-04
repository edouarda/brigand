/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/fold.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/sequences/append.hpp>
#include <brigand/sequences/front.hpp>

namespace brigand
{
  namespace lazy
  {
    template<class L1, class L2>
    using product = reverse_fold<
      list<L1, L2>,
      list<list<>>,
      lazy::join<
        lazy::transform<
          _2,
          defer<
            lazy::join<
              lazy::transform<
                parent<_1>,
                defer<
                  bind<
                    list,
                    lazy::push_front<_1, parent<_1>>
                  >
                >
              >
            >
          >
        >
      >
    >;
  }

  template<class L1, class L2>
  using product = reverse_fold<
    list<L1, L2>,
    list<list<>>,
    bind<
      join,
      bind<
        transform,
        _2,
        defer<
          bind<
            join,
            bind<
              transform,
              parent<_1>,
              defer<
                bind<
                  list,
                  bind<push_front, _1, parent<_1>>
                >
              >
            >
          >
        >
      >
    >
  >;
}
