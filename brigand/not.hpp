
#pragma once

#include <type_traits>

namespace brigand
{
  template <typename T>
  using not = std::integral_constant<typename T::value_type, !T::value>;
}
