/*==================================================================================================
  Copyright (c) 2015 QuasarDB
  Copyright (c) 2015 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <initializer_list>
#include <functional>

namespace brigand
{
  template<class F, class...Ts> F for_each_args(F f, Ts&&...a)
  {
    return (void)std::initializer_list<int>{(std::ref(f)((Ts&&)a),0)...}, f;
  }
}
