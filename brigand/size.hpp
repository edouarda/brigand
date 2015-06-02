
#pragma once

#include <brigand/apply.hpp>
#include <brigand/count.hpp>

namespace brigand
{
  template<class L>
  using size = apply<L, count>;
}
