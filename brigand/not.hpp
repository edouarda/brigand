
#pragma once

#include <type_traits>

namespace brigand
{
  template <typename T>
  using not_ = std::integral_constant<typename T::value_type, !T::value>;
}
