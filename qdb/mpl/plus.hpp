
#pragma once

#include <type_traits>

namespace brigand
{
  template <typename A, typename B>
  using plus = std::integral_constant<typename A::value_type, A::value + B::value>;
}
