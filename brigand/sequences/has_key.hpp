/*==================================================================================================
  Copyright (c) 2015 Edouard Alligan and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <brigand/types/type.hpp>

namespace brigand
{
namespace detail
{
  template<class L, class K>
  struct has_key_impl;

  template <class C, class K>
  decltype(C::has_key(type_<K>{})) has_key_dispatch(K *);

  template <class L, class I>
  typename has_key_impl<L, I>::type has_key_dispatch(...);
}

  template<class L, class K>
  using has_key = decltype(detail::has_key_dispatch<L, K>(nullptr));
}
