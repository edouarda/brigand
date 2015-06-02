
#pragma once

#include <brigand/bool.hpp>

namespace brigand
{
  template <typename A, typename B>
  using greater = bool_<(A::value > B::value)>;
}
