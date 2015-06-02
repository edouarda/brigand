
#pragma once

#include <type_traits>

namespace brigand
{
  template <typename A>
  using next = std::integral_constant<typename A::value_type, A::value+1>;
}
