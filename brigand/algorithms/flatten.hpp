/*==================================================================================================
Copyright (c) 2015 Edouard Alligand and Joel Falcou

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/list.hpp>
#include <brigand/sequences/append.hpp>

namespace brigand
{
namespace detail
{

    template <class L>
    struct flatten_impl
    {
        using type = L;
    };

    template <template<class...> class L, class Head, class... Tail>
    struct flatten_impl<L<Head, Tail...>>
    {
        using tail_type = L<Tail...>;
        using flattened_tail_type = typename flatten_impl<tail_type>::type;
        using type = typename brigand::append<L<Head>, flattened_tail_type>;
    };

    template <template<class...> class L, template <class...> class Head, class... HeadElements, class... Tail>
    struct flatten_impl<L<Head<HeadElements...>, Tail...>>
    {
        using head_type = L<HeadElements...>;
        using flattened_head_type = typename flatten_impl<head_type>::type;
        using tail_type = L<Tail...>;
        using flattened_tail_type = typename flatten_impl<tail_type>::type;
        using type = typename brigand::append<flattened_head_type, flattened_tail_type>;
    };

}

namespace lazy
{
    template <typename Sequence>
    using flatten = typename detail::flatten_impl<Sequence>;
}

template <typename Sequence>
using flatten = typename lazy::flatten<Sequence>::type;

}
