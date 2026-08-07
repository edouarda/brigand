/*!
@file

@copyright Edouard Alligand and Joel Falcou 2015-2017
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_BRIGAND_ALGORITHMS_FOR_EACH_ARGS_HPP
#define BOOST_BRIGAND_ALGORITHMS_FOR_EACH_ARGS_HPP

#include <initializer_list>

namespace brigand
{
  template<class F, class...Ts> constexpr F for_each_args(F f, Ts&&...a)
  {
    (void)std::initializer_list<int>{((void)f(static_cast<Ts&&>(a)),0)...};
    return f;
  }
}
#endif
