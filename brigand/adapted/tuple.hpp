
#pragma once

#include <brigand/apply.hpp>

namespace brigand
{
  template <typename... T>
  struct tuple_wrapper
  {
      using type = typename std::tuple<T...>;
  };

  template <typename L>
  using as_tuple = apply<L, tuple_wrapper>;
}
