/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/wrap.hpp>
#include <brigand/sequences/list.hpp>

namespace brigand
{
namespace detail
{
    template <typename L, template <class...> class Sequence>
    struct as_sequence_impl
    {
        using type = wrap<L, Sequence>;
    };
} // namespace detail

template <typename L, template <class...> class Sequence>
using as_sequence = typename detail::as_sequence_impl<L, Sequence>::type;

template <typename L>
using as_list = as_sequence<L, brigand::list>;

} // namespace brigand
