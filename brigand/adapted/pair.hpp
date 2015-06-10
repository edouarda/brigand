
#pragma once

#include <brigand/apply.hpp>

namespace brigand
{
  template <typename T, typename U>
  struct pair_wrapper
  {
      using type = typename std::pair<T,U>;
  };

  template <typename L>
  using as_pair = apply<L, pair_wrapper>;
}
