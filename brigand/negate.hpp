
#pragma once

#include <type_traits>

namespace brigand
{
  template <typename A>
  using negate = std::integral_constant<typename A::value_type, -A::value>;
}
