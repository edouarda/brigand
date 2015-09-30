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
    template<class C, class K>
    struct has_key_impl
    {
        using type = decltype(C::has_key(type_<K>{}));
    };
}

    template<class L, class K>
    using has_key = typename detail::has_key_impl<L, K>::type;
}
