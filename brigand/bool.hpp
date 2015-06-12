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
  template <bool B>
  using bool_ = std::integral_constant<bool, B>;

  using true_ = bool_<true>;
  using false_ = bool_<false>;
}
