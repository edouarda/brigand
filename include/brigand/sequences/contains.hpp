/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/type.hpp>

namespace brigand
{
namespace detail
{
    template <class L, class K>
    struct contains_impl
    {
        using type = decltype(L::contains(type_<K>{}));
    };
}
    template <class L, class K>
    using contains = typename detail::contains_impl<L, K>::type;
}
