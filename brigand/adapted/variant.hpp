/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/wrap.hpp>
#include <boost/variant.hpp>

namespace brigand
{
  template <typename... T>
  using variant_wrapper = typename boost::variant<T...>;

  template <typename L>
  using as_variant = wrap<L, variant_wrapper>;
}
