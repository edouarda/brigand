
#include <brigand/types/real.hpp>
#include <cassert>
#include <limits>
#include <iostream>

template<typename T> bool is_nan(T v)
{
  return v!=v;
}

// integral constant tests
using single_zero = brigand::single_<0x00000000U>;
using single_one  = brigand::single_<0x3F800000U>;
using single_nan  = brigand::single_<0xFFFFFFFFU>;

using double_zero = brigand::double_<0x0000000000000000ULL>;
using double_one  = brigand::double_<0x3FF0000000000000ULL>;
using double_nan  = brigand::double_<0xFFFFFFFFFFFFFFFFULL>;

void real_test()
{
  // test single cases
  assert( static_cast<float>(single_zero()) == 0.f);
  assert( static_cast<float>(single_one())  == 1.f);
  assert( is_nan(static_cast<float>(single_nan())) );

  // test double
  assert( static_cast<double>(double_zero()) == 0.);
  assert( static_cast<double>(double_one())  == 1.);
  assert( is_nan(static_cast<double>(double_nan())) );
}
