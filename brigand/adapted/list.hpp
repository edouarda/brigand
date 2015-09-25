/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/wrap.hpp>
#include <brigand/sequences/list.hpp>

namespace brigand
{
  template <typename... T>
  using list_wrapper = typename brigand::list<T...>;

  template <typename L>
  using as_list = wrap<L, list_wrapper>;
}
