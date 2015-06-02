
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
