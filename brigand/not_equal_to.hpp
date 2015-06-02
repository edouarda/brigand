
#pragma once

#include <brigand/bool.hpp>

namespace brigand
{
  template <typename A, typename B>
  using not_equal_to = bool_<(A::value != B::value)>;
}
