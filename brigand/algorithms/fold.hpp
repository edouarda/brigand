/*==================================================================================================
  Copyright (c) 2015 QuasarDB
  Copyright (c) 2015 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/detail/fold.hpp>

namespace brigand
{
  // Main fold entry point
  template <class Sequence, class State, class Functor>
  using fold = typename detail::fold_impl<Functor, State, Sequence>::type;
}
