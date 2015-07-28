/*==================================================================================================
  Copyright (c) 2015 Edouard Alligan and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/bool.hpp>
#include <brigand/sequences/contains.hpp>

namespace brigand
{
namespace detail
{
    template <class M, class T>
    struct insert_impl;

    template <class L, class T, class>
    struct insert_default_impl
    {
        using type = L;
    };

    template <template<class...> class L, class T, class... Ts>
    struct insert_default_impl<L<Ts...>, T, false_>
    {
        using type = L<Ts..., T>;
    };

    template <template<class...> class L, class T, class... Ts>
    struct insert_impl<L<Ts...>, T>
    {
        using type = typename insert_default_impl<L<Ts...>, T, typename contains_impl<L<Ts...>, T>::type>::type;
    };
}
    template<class M, class K>
    using insert = typename detail::insert_impl<M, K>::type;
}
