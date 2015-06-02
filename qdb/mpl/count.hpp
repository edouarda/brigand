
#pragma once

#include <type_traits>

namespace brigand
{
  template<class... T>
  using count = std::integral_constant<std::size_t, sizeof...(T)>;
}
