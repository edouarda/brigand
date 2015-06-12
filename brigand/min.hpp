/*==================================================================================================
  Copyright (c) 2015 QuasarDB
  Copyright (c) 2015 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  using min = std::integral_constant< typename A::value_type
                                    , (A::value < B::value) ? A::value : B::value
                                    >;
}
