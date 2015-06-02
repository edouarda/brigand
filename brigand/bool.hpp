
#pragma once

#include <type_traits>

namespace brigand
{
  template <bool B>
  using bool_ = std::integral_constant<bool, B>;

  using true_ = bool_<true>;
  using false_ = bool_<false>;
}
