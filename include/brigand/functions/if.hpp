/*==================================================================================================
Copyright (c) 2015 Edouard Alligand and Joel Falcou

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <type_traits>

namespace brigand
{

  template <typename Condition, typename A, typename B>
  struct if_ : std::conditional<Condition::value, A, B> {};

  template <bool Condition, typename A, typename B>
  struct if_c : std::conditional<Condition, A, B> {};

}
