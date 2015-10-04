/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <type_traits>

#include <brigand/types/args.hpp>

namespace brigand
{
  template <typename A>
  struct complement : std::integral_constant< typename A::value_type
                                            , typename A::value_type(~A::value)
                                            > {};
}
